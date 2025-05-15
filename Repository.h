#pragma once

#include <vector>

using namespace std;

template<typename T>
class IRepository {
public:
    virtual ~IRepository() = default;

    virtual void add(const T& entity) = 0;
    virtual void remove(int id) = 0;
    virtual void update(const T& entity) = 0;
    virtual vector<T> getAll() const = 0;
    virtual T findById(int id) const = 0;

    virtual void loadFromFile() = 0;
    virtual void saveToFile() const = 0;
};


