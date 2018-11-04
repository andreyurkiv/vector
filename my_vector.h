//
// Created by dinamic on 11/4/18.
//

#ifndef PROJECT_MY_VECTOR_H
#define PROJECT_MY_VECTOR_H


#include <iostream>

template <typename T>
class my_vector {
public:

    typedef unsigned int size_t;
    typedef T * iterator;

    // constructors
    my_vector();
    my_vector(size_t n, const T&  value);
    my_vector(typename my_vector<T>::iterator begin, typename my_vector<T>::iterator end);
    my_vector(std::initializer_list<T> list);
    explicit my_vector(size_t n);

    ~my_vector();

    my_vector(const my_vector<T>& obj);
    my_vector(my_vector<T>&& obj) noexcept;

    // TODO: assignment and assignment with move


    // assignment operations
    // indexing
    T& operator[](size_t index) noexcept;
    const T& operator[](size_t index) const noexcept;
    T& at(size_t index);
    const T& at(size_t index) const;
    T& front();
    const T& front() const;
    T& back();
    const T& back() const;


    // iterators
    iterator begin();
    const iterator cbegin();
    iterator end();
    const iterator cend();
    std::reverse_iterator<T> rbegin();
    std::reverse_iterator<T> rend();
    std::reverse_iterator<const iterator> rcbegin();
    std::reverse_iterator<const iterator> rcend();

    // sizing methods
    bool is_empty() const;
    size_t size() const;
    size_t capacity() const;
    void shrink_to_fit();

    void reserve(size_t n);

    // swap
    void swap(my_vector<T>& that);
    void resize(size_t new_size);

    void clear();

    // insert()/erase() methods
    iterator insert(const iterator target, const T& value);
    iterator insert(const iterator target, iterator begin, iterator end);
    iterator erase(const iterator target, const T& value);
    iterator erase(iterator begin, iterator end);

    // push/pop methods
    void pop_back();
    void push_back(const T& elem);

    // TODO: emplace_back()

    // operators overloading
    bool operator==(const my_vector<T>&) const;
    bool operator!=(const my_vector<T>&) const;
    bool operator<(const my_vector<T>&) const;
    bool operator<=(const my_vector<T>&) const;
    bool operator>(const my_vector<T>&) const;
    bool operator>=(const my_vector<T>&) const;

    // TODO: lexicographic comparison

private:
    size_t v_size = 0;
    size_t v_capacity = 4;
    T *array;
};

// default constructor
template<typename T>
my_vector<T>::my_vector() {
    array = new T[v_capacity];
}


// TODO: remove this one
// constructor by the given size
template<typename T>
my_vector<T>::my_vector(my_vector::size_t n) {
    v_capacity = 2 * n;
    array = new T[v_capacity];
    for (size_t i = 0; i < n; ++i){
        array[i] = T();
    }
    v_size = n;
}


// filling constructor
template<typename T>
my_vector<T>::my_vector(my_vector::size_t n, const T& value) {
    v_capacity = 2 * n;
    array = new T[v_capacity];
    for (size_t i; i < n; ++i){
        array[i] = value;
    }
    v_size = n;
}

// constructor by iterators
template<typename T>
my_vector<T>::my_vector(my_vector::iterator begin, my_vector::iterator end) {
    size_t n = end - begin;
    v_capacity = 2 * n;
    array = new T[v_capacity];
    for (size_t i = 0; i < n; ++i, ++begin){
        array[i] = *begin;
    }
}


// constructor from initializer list
template<typename T>
my_vector<T>::my_vector(std::initializer_list<T> list) {

}

// destructor
template<typename T>
my_vector<T>::~my_vector() {

}

// copy constructor
template<typename T>
my_vector<T>::my_vector(const my_vector<T> &obj) {
}

// moving constructor
template<typename T>
my_vector<T>::my_vector(my_vector<T> &&obj) noexcept {

}

template<typename T>
T &my_vector<T>::operator[](my_vector::size_t index) noexcept {
    return <#initializer#>;
}

template<typename T>
const T &my_vector<T>::operator[](my_vector::size_t index) const noexcept {
    return <#initializer#>;
}

template<typename T>
T &my_vector<T>::at(my_vector::size_t index) {
    return <#initializer#>;
}

template<typename T>
const T &my_vector<T>::at(my_vector::size_t index) const {
    return <#initializer#>;
}

template<typename T>
T &my_vector<T>::front() {
    return <#initializer#>;
}

template<typename T>
const T &my_vector<T>::front() const {
    return <#initializer#>;
}

template<typename T>
T &my_vector<T>::back() {
    return <#initializer#>;
}

template<typename T>
const T &my_vector<T>::back() const {
    return <#initializer#>;
}

template<typename T>
my_vector::iterator my_vector<T>::begin() {
    return nullptr;
}

template<typename T>
my_vector::iterator const my_vector<T>::cbegin() {
    return nullptr;
}

template<typename T>
my_vector::iterator my_vector<T>::end() {
    return nullptr;
}

template<typename T>
my_vector::iterator const my_vector<T>::cend() {
    return nullptr;
}

template<typename T>
std::reverse_iterator<my_vector::iterator const> my_vector<T>::rcend() {
    return std::reverse_iterator<my_vector::iterator const>();
}

template<typename T>
std::reverse_iterator<T> my_vector<T>::rbegin() {
    return std::reverse_iterator<T>();
}

template<typename T>
std::reverse_iterator<T> my_vector<T>::rend() {
    return std::reverse_iterator<T>();
}

template<typename T>
std::reverse_iterator<my_vector::iterator const> my_vector<T>::rcbegin() {
    return std::reverse_iterator<my_vector::iterator const>();
}

template<typename T>
bool my_vector<T>::is_empty() const {
    return false;
}

template<typename T>
my_vector::size_t my_vector<T>::size() const {
    return 0;
}

template<typename T>
my_vector::size_t my_vector<T>::capacity() const {
    return 0;
}

template<typename T>
void my_vector<T>::shrink_to_fit() {

}

template<typename T>
void my_vector<T>::reserve(my_vector::size_t n) {

}

template<typename T>
void my_vector<T>::swap(my_vector<T> &that) {

}

template<typename T>
void my_vector<T>::resize(my_vector::size_t new_size) {

}

template<typename T>
void my_vector<T>::clear() {

}

template<typename T>
my_vector::iterator my_vector<T>::insert(my_vector::iterator const target, const T &value) {
    return nullptr;
}

template<typename T>
my_vector::iterator
my_vector<T>::insert(my_vector::iterator const target, my_vector::iterator begin, my_vector::iterator end) {
    return nullptr;
}

template<typename T>
my_vector::iterator my_vector<T>::erase(my_vector::iterator const target, const T &value) {
    return nullptr;
}

template<typename T>
my_vector::iterator my_vector<T>::erase(my_vector::iterator begin, my_vector::iterator end) {
    return nullptr;
}

template<typename T>
void my_vector<T>::push_back(const T &elem) {

}

template<typename T>
void my_vector<T>::pop_back() {

}


#endif //PROJECT_MY_VECTOR_H
