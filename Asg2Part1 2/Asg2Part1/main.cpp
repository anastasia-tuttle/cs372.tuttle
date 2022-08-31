#include <iostream>
#include <vector>
#include "Header.h"
#include "vector.h"
using namespace std;
void timer();
int main()
{
    Vector<int> aVect;
    cout <<"Vector size: "<<aVect.size()<<endl;
    cout<<"Vector capacity: "<<aVect.capacity()<<endl;
    
    cout<<"Vector elements: ";
    aVect.print();
    
    aVect.push(1);
    timer();
    
}
void timer ()
{
    auto start = std::chrono::steady_clock::now();
    auto end = std::chrono::steady_clock::now();
    std::chrono::duration<double> elapsed_seconds = end - start;
    std::cout<<"Time measured: "<<elapsed_seconds.count()<<"s\n";
}
/*void resize( int newSize, int theCapacity )
{
    int newSize;
    if( newSize > theCapacity )
        reserve( newSize * 2 );
        theSize = newSize;
}
void reserve( int newCapacity )
{
    if( newCapacity < theSize )
        return;
        
    Object *newArray = new Object[ newCapacity ]; for(intk=0;k<theSize;++k)
        newArray[ k ] = std::move( objects[ k ] );
        
    theCapacity = newCapacity;
    std::swap( objects, newArray );
    delete [ ] newArray;
        
    Object & operator[]( int index)
    {
        return objects[ index ];
            
    }
    const Object & operator[]( int index) const
    {
        return objects[ index ];
    }
    bool empty( ) const
    {
        return size( ) == 0;
    }
    int size( ) const
    {
        return theSize;
    }
    int capacity( ) const
    {
        return theCapacity;
    }
void push_back( const Object & x)
{
    if ( theSize == theCapacity)
    {
        reserve( 2 * theCapacity + 1);
        objects[ theSize++ ] = x;
    }
}
void push_back( Object && x )
{
    if( theSize == theCapacity )
    {
        reserve( 2 * theCapacity + 1 );
        objects[ theSize++ ] = std::move( x );
    }
}
void pop_back()
{
    --theSize;
}
const Object & back () const
{
    return objects[theSize - 1];
)
    typedef Object * iterator;
    typedef const Object * const_iterator;
    iterator begin( )
    {
        return &objects[ 0 ];
    }
    const_iterator begin( ) const
    {
        return &objects[ 0 ];
    }
    iterator end( )
    {
        return &objects[ size( ) ];
    }
    const_iterator end( ) const
    {
        return &objects[ size( ) ];
    }
};
void push (T data)//function to add an element at the last
{
        if (current == capacity)
        {
            T* temp = new T [2 * capacity];

            for (int i = 0; i < capacity; i++)
            {
                temp [i] = arr[i];
            }
        }
    delete[] arr;
    capacity *= 2;
    arr = temp;
}
*/

