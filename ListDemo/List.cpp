//
//  List.cpp
//  ListDemo
//
//  Created by David Reed on 9/6/23.
//

#include "List.hpp"

// default value does not go in implementation/definition
List::List(size_t capacity) {
    _data = new int[capacity];
    _capacity = capacity;
    _size = 0;
}

List::~List() {
    delete [] _data;
}

List& List::operator=(const List &src) {
    if (this != &src) {
        // deallocate existing dynamic array
        delete [] _data;
        // copy the data
        copy(src);
    }
    return *this;
}

void List::append(int item) {
    if (_size == _capacity) {
        resize(2 * _capacity);
    }
    _data[_size++] = item;
}

void List::copy(const List &src) {
    size_t i;

    _size = src._size;
    _capacity = src._capacity;
    _data = new int[src._capacity];
    for (i=0; i<src._capacity; ++i) {
        _data[i] = src._data[i];
    }
}

// should this method have a precondition? see end of chapter exercises
void List::resize(size_t new_size) {
    int *temp;
    size_t i;

    _capacity = new_size;
    temp = new int[_capacity];
    for (i=0; i<_size; ++i) {
        temp[i] = _data[i];
    }
     delete [] _data;
    _data = temp;
}
