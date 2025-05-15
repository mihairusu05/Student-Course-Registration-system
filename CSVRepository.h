#pragma once

#include "Repository.h"
#include <vector>
#include <string>
#include <fstream>
#include <algorithm>
#include <stdexcept>

template <typename T>
class CSVRepository : public Repository<T> {
private:
    string filePath;
    vector<T> items;

public:
    explicit CSVRepository(const string& filePath) : filePath(filePath) {
        loadFromFile();
    }

    void loadFromFile() override {
        items.clear();
        ifstream in(filePath);
        if (!in.is_open()) return;

        T item;
        while (in >> item) {
            items.push_back(item);
        }

        in.close();
    }

    void saveToFile() const override {
        ofstream out(filePath);
        for (const auto& item : items)
            out << item;
        out.close();
    }

    void add(const T& item) override {
        if (any_of(items.begin(), items.end(), [&](const T& i) { return i.getId() == item.getId(); }))
            throw runtime_error("Item with this ID already exists.");
        items.push_back(item);
        saveToFile();
    }

    void remove(int id) override {
        auto it = remove_if(items.begin(), items.end(), [&](const T& i) { return i.getId() == id; });
        if (it == items.end())
            throw runtime_error("Item not found.");
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
        throw runtime_error("Item not found.");
    }

    vector<T> getAll() const override {
        return items;
    }

    T findById(int id) const override {
        for (const auto& i : items) {
            if (i.getId() == id)
                return i;
        }
        throw runtime_error("Item not found.");
    }
};

