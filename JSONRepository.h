#pragma once

#include "Repository.h"
#include <QFile>
#include <QJsonDocument>
#include <QJsonObject>
#include <QJsonArray>
#include <QString>
#include <QTextStream>
#include <QIODevice>
#include <stdexcept>
#include <vector>

// T must implement:
// - QJsonObject toJson() const;
// - static T fromJson(const QJsonObject&);
// - int getId() const;
template <typename T>
class JSONRepository : public IRepository<T> {
private:
    QString filePath;
    std::vector<T> items;

public:
    explicit JSONRepository(const QString& filePath) : filePath(filePath) {
        loadFromFile();
    }

    void loadFromFile() override {
        items.clear();
        QFile file(filePath);
        if (!file.open(QIODevice::ReadOnly)) return;

        QByteArray data = file.readAll();
        file.close();

        QJsonDocument doc = QJsonDocument::fromJson(data);
        if (!doc.isArray()) return;

        QJsonArray array = doc.array();
        for (const auto& value : array) {
            if (value.isObject()) {
                T item = T::fromJson(value.toObject());
                items.push_back(item);
            }
        }
    }

    void saveToFile() const override {
        QJsonArray array;
        for (const auto& item : items) {
            array.append(item.toJson());
        }

        QJsonDocument doc(array);
        QFile file(filePath);
        if (!file.open(QIODevice::WriteOnly)) {
            throw std::runtime_error("Cannot open file for writing");
        }
        file.write(doc.toJson());
        file.close();
    }

    void add(const T& item) override {
        for (const auto& i : items) {
            if (i.getId() == item.getId())
                throw std::runtime_error("Item with this ID already exists.");
        }
        items.push_back(item);
        saveToFile();
    }

    void remove(int id) override {
        auto it = std::remove_if(items.begin(), items.end(), [&](const T& i) { return i.getId() == id; });
        if (it == items.end())
            throw std::runtime_error("Item not found.");
        items.erase(it, items.end());
        saveToFile();
    }

    void update(const T& item) override {
        for (auto& i : items) {
            if (i.getId() == item.getId()) {
                i = item;
                saveToFile();
                return;
            }
        }
        throw std::runtime_error("Item not found.");
    }

    std::vector<T> getAll() const override {
        return items;
    }

    T findById(int id) const override {
        for (const auto& i : items) {
            if (i.getId() == id)
                return i;
        }
        throw std::runtime_error("Item not found.");
    }
};

