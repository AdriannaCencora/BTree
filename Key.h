//
// Created by flint on 06.06.18.
//

#ifndef BTREE_KEY_H
#define BTREE_KEY_H

template <class T>
class Key {

public:
    T value;
    bool isAssigned;

    explicit Key(T value): value(value), isAssigned(true){};
    Key(): value(), isAssigned(false){};

    void setValue(T value) {
        this->value = value;
        this->isAssigned = true;
    }

    void clearValue() {
        this->value = 0;
        this->isAssigned = false;

    }

    T getValue() {
        return this->value;
    }

    bool operator>(const Key<T> other){
        if(!this->isAssigned)
            return true;
        else if(!other.isAssigned)
            return false;
        else
            return this->value > other.value;
    }

    bool operator<(const Key<T> other)
    {
        if(!this->isAssigned)
            return false;
        else if(!other.isAssigned)
            return true;
        else
            return this->value < other.value;
    }

    bool operator==(const Key<T> other)
    {
        return (!this->isAssigned && !other.isAssigned) || this->value == other.value;
    }

    bool operator>=(const Key<T> other)
    {
        return *this > other or *this == other;
    }
};


#endif //BTREE_KEY_H
