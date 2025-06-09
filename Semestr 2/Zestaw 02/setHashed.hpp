#ifndef SET_HASHED_H
#define SET_HASHED_H

#include <iostream>
#include "SortedList.hpp"

#define SIZE 500

template<typename T>
class setHashed{
private:
    int hashFunction(T newElement){
        return newElement % SIZE;
    }


public:
    SortedList<T> *table;

    setHashed(){
        table = new SortedList<T>[SIZE];
    }

    ~setHashed(){
        delete[] table;
    }

    setHashed(const setHashed& other) {
        table = new SortedList<T>[SIZE];
        for(int i=0;i<SIZE;i++){
            table[i] = other.table[i];
        }
    }

    setHashed& operator=(const setHashed& other) {
        if (this != &other) {
            delete[] table;
            table = new SortedList<T>[SIZE];
            for (int i = 0; i < SIZE; i++) {
                table[i] = other.table[i];
            }
        }
        return *this;
    }

    void insertElement(const T& newElement){
        int index = hashFunction(newElement);
        SortedList<T>& currentBucket = table[index];

        if(!currentBucket.contains(newElement)){
            currentBucket.insert(newElement);
        }
    }

    void deleteElement(const T& newElement){
        int index = hashFunction(newElement);
        SortedList<T>& currentBucket = table[index];

        currentBucket.remove(newElement);
    }

    bool contains(const T& newElement){
        int index = hashFunction(newElement);
        SortedList<T>& currentBucket = table[index];

        return currentBucket.contains(newElement);
    }

    bool operator==(const setHashed<T>& other) const{
        for(int i=0; i< SIZE; i++){
            if(!(this->table[i] == other.table[i])){
                return false;
            }
        }
        return true;
    }

    setHashed<T> operator+(setHashed<T> &otherSet){
        setHashed<T> resultSet = *this;
        for(int i=0; i< SIZE ; i++){
            typename SortedList<T>::Iterator it = otherSet.table[i].begin();
            typename SortedList<T>::Iterator end = otherSet.table[i].end();

            while (it != end){
                resultSet.insertElement(*it);
                ++it;
            }
        }
        return resultSet;
    }

    setHashed<T> operator-(setHashed<T> &otherSet){
        setHashed<T> resultSet = *this;
        for(int i=0; i< SIZE ; i++){
            typename SortedList<T>::Iterator it = otherSet.table[i].begin();
            typename SortedList<T>::Iterator end = otherSet.table[i].end();

            while (it != end){
                resultSet.deleteElement(*it);
                ++it;
            }
        }
        return resultSet;
    }

    setHashed<T> operator*(setHashed<int> otherSet) const {
        setHashed<T> resultSet;
        for (int i = 0; i < SIZE; i++) {
            typename SortedList<T>::Iterator it = this->table[i].begin();
            typename SortedList<T>::Iterator end = this->table[i].end();

            while (it != end) {
                if (otherSet.contains(*it)) {
                    resultSet.insertElement(*it);
                }
                ++it;
            }
        }
        return resultSet;
    }

    void show(int index){
        table[index]->show();
    }

};

#endif // SET_HASHED_H