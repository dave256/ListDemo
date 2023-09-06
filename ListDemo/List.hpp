//
//  List.hpp
//  ListDemo
//
//  Created by David Reed on 9/6/23.
//

#ifndef List_hpp
#define List_hpp

#include <cstdlib>

class List {

public:
    // default parameter only in header file/declaration
    List(size_t capacity=10); // constructor - allocates dynamic array
    ~List(); // destructor - deallocates dynamic memory

    List(const List &src); // think about why parameter needs to be passed by reference
    List& operator=(const List &src); // assignment operator

    int operator[](size_t pos) const; // bracket operator for rhs (needed for const List parameters)
    int& operator[](size_t pos); // bracket operator for lhs

    void append(int item);
    size_t size() const { return _size; }

private:
    void copy(const List &src);
    void resize(size_t new_size); // allocate new larger array
    int *_data; // dynamic array
    size_t _size; // size of dynamic array
    size_t _capacity; // capacity of dynamic array
};

inline int List::operator[](size_t pos) const
{
    return _data[pos];
}

inline int& List::operator[](size_t pos)
{
    return _data[pos];
}

#endif /* List_hpp */
