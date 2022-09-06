#include <vector>
using namespace std;
template<typename T>  // Vector<int> aVect;
class Vector
{
    T* arr;
    int capacity;
    int current;
    
    public :
    class const_iterator {
        protected:
            Vector *current;
            T & retrieve() const {return current->data; }
            const_iterator( Vector* p) : current(p) { }
            friend class std::vector<T>;
        
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
            iterator(Vector *p) : const_iterator(p) { }
            friend class std::vector<T>;
        
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
    private :
        Vector()
        {
            arr = new T[1];
            capacity = 1;
            current = 0;
        }
        ~Vector()
        {
            delete [] arr;
            arr = nullptr;
        }
   
    };
void push (T data)
{
        //if the number of elements is equal to the capacity
    if (current == capacity)
    {
        T* temp = new T[2 * capacity];
        for (int i = 0; i < capacity; i++)
        {
            temp[i] = arr[i];
        }
        delete[] arr;
        capacity *=2;
        arr = temp;
    }
    arr[current] = data;
    current++;
}
void push(T data, int index)
{
    if (index == capacity)
        push(data);
    else
        arr[index] = data;
}
T get(int index)
{
    if (index < current)
        return arr[index];
}
void pop()
{
    current --;
}
int size()
{
    return current;
}
int getcapacity()
{
    return capacity;
}
void print()
{
    for (int i = 0; i < current; i++)
    {
        cout<<arr[i]<<" ";
    }
    cout<<endl;
}
};
