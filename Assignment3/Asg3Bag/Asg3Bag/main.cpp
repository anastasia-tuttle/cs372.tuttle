
// File:   bag.h
// Author: Your Glorious Instructor
// Purpose:
// Implement the Bag ADT.
//
#pragma once
#include <iostream>
#include "vector.h"

template <typename Thing>
class Bag {
public:
    class const_iterator {
        protected:
            Bag *current;
            Thing & retrieve() const {return current->data; }
            const_iterator( Bag* p) : current(p) { }
            friend class std::vector<Thing>;
        
        public:
            const_iterator(): current(nullptr) { }

            Thing & operator*() const {
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
            iterator(Bag *p) : const_iterator(p) { }
            friend class std::vector<Thing>;
        
        public:
            iterator() { }

            Thing & operator *() {
                return const_iterator::retrieve();
            }

            const Thing & operator* () const {
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
  void insert(Thing aThing) {
    bagContents.push_back(aThing);
    bagSize++;
  }
  Thing &pop() {
    Thing aThing;
    if (bagContents.size() > 0) {
      aThing = bagContents[bagSize];
      bagSize--;
    }
    else {
      std::cerr << "Can't pop out of an empty bag" << std::endl;
    }
    return aThing;
  }
  int size() {
    return bagSize;
  }
  int count(Thing aThing) {
    int bagCount = 0;
    for (int i = 0 ; i < bagSize; i++) {
      if (bagContents[i] == aThing) {
        bagCount++;
      }
    }
    return bagCount;
  }
private:
  std::vector<Thing> bagContents;
  int bagSize = 0;
}:
