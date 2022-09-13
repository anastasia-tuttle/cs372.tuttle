//
//  main.cpp
//  Asg4P2Tuttle
//
//  Created by Anastasia Tuttle  on 9/13/22.
//
#pragma once
#include <functional>
template <typename T>
class CircularList {
private:
    class Node{
    public:
        T data;
        Node *prev;
        Node *next;
        bool isHiddenNode = false;
    };
    int theSize;
    Node *head;
    Node *tail;

public:
    class const_iterator {
        protected:
            Node *current;
            T & retrieve() const {return current->data; }
            const_iterator( Node* p) : current(p) { }
            friend class CircularList<T>;
        
        public:
            const_iterator(): current(nullptr) { }

            T & operator*() const {
                return retrieve();
            }

            const_iterator & operator++() {
                current = current->next;
                return *this;
            }

            const_iterator  operator++( int ) {
                const_iterator old = *this;
                ++( *this );
                return old;
            }

            bool operator==(const const_iterator & rhs) const {
                return current == rhs.current;
            }
            bool operator!=(const const_iterator & rhs) const  {
                return !(*this == rhs);
            }
    };

    class iterator: public const_iterator {
        protected:
            iterator(Node *p) : const_iterator(p) { }
            friend class CircularList<T>;
        
        public:
            iterator() { }

            T & operator *() {
                return const_iterator::retrieve();
            }

            const T & operator* () const {
                return const_iterator::operator*( );
            }

            iterator & operator++ () {
                this->current = const_iterator::current->next;
                return *this;
            }

            iterator operator++ ( int ) {
                iterator old = *this;
                ++( *this);
                return old;
            }
    };

private:
    void setupList() {
        Node *newNode = new Node();
        newNode->next = tail;
        newNode->prev = head;
        head->next = newNode;
        tail->prev = newNode;
    }
    void deleteListContents() {
        Node *current = head->next;
        Node *temp = nullptr;
        while (current != tail->prev) {
            temp = current->next;
            delete current;
            current = temp;
        }
    }

public:
    CircularList() {
        head = new Node();
        head->isHiddenNode = true;
        tail = new Node();
        tail->isHiddenNode = true;
        head->prev = nullptr;
        head->next = tail;
        tail->prev = head;
        tail->next = nullptr;

    };
    
    Circle(T data) {
        head = new CircularList;
        head->next = head;
        head->data = std::move(data);
        tail = head;
    };

    CircularList(T newData) {
        setupList();
        (head->next)->data = newData;
    }
    CircularList(CircularList &rhs) {
        // copy constructor
        deleteListContents();
        head = rhs.head;
        tail = rhs.tail;
    }
    ~CircularList(){
        // And a destructor
        deleteListContents();
        delete head;
        delete tail;
    }
    bool empty() {
        return (head->next == tail);
    }

    // iterator related methods
    iterator begin()
    {
        return { head->next};
    }
    iterator end()
    {
        return tail;
    }
    iterator rbegin()
    {
        return {tail ->prev};
    }
    iterator rend()
    {
        return {++head->next};
    }
    iterator crbegin()
    {
        return {tail ->prev};
    }
    iterator crend()
    {
        return {++head->next};
    }
    // And the methods for the rest
    void push_front(T data) {
        if (this->empty()){
            setupList();
            Node * actualHead = head->next;
            actualHead->data = data;
        }
        else {
            Node *actualHead = head->next;
            Node *newNode = new Node();
            newNode->data = data;
            newNode->next = actualHead;
            actualHead->prev = newNode;
            newNode->prev = head;
            head->next = newNode;
        }
    }
    void push_back(T data) {
        if (this->empty()) {
            setupList();
            Node *actualTail = tail->prev;
            actualTail->data = data;
        }
        else {
            Node *actualTail = tail->prev;
            Node *newNode = new Node();
            newNode->data = data;
            newNode->prev = actualTail;
            actualTail->next = newNode;
            newNode->next = tail;
            tail->prev = newNode;
        }
    }
    T &front() {
        Node *actualHead = head->next;
        return (actualHead->data);
    }
    T back() {
        Node *actualTail = tail->prev;
        return (actualTail->data);
    }
    void pop_back() {
        Node *lastNode = tail->prev;
        tail->prev = lastNode->prev;
        Node *newLastNode = tail->prev;
        newLastNode->next = tail;
        delete lastNode;
        lastNode = nullptr;
    }
    void pop_front() {
        Node *firstNode = head->next;
        head->next = firstNode->next;
        Node *newFirstNode = head->next;
        newFirstNode->prev = head;
        delete firstNode;
        firstNode = nullptr;
    }
    void traverse(std::function<void(T &data)> doIt) {
        Node *current = head->next;
        while (current != tail) {
            doIt(current->data);
            current = current->next;
        }
    }
    //iterator
    iterator insert (iterator itr, T && x)
    {
        Node *p = itr.current;
        theSize++;
        return {p->prev = p->next = new Node{std::move(x), p->prev, p}};
    }
    iterator erase(iterator itr)
    {
        Node *p = itr.current;
        iterator retVal {p->next};
        p->prev->next = p->next;
        p->next->prev = p->prev;
        delete p;
        theSize--;
        
        return retVal;
    }
    iterator erase(iterator from, iterator to)
    {
        for (iterator itr = from; itr != to;)
            itr = erase(itr);
        
        return to;
    }
};

