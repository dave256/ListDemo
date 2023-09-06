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

void List::append(int item) {
    if (_size == _capacity) {
        resize(2 * _capacity);
    }
    _data[_size++] = item;
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
