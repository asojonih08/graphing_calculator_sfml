#ifndef STACK_H
#define STACK_H

#include "linked_lists.h"
#include <iostream>

using namespace std;

void test_stack_push_pop();

template <typename T>
class Stack
{
public:

    Stack();

    ~Stack();
    Stack(const Stack<T> &copy_this);
    Stack& operator =(const Stack &rhs);

    template <typename U>
    friend ostream& operator <<(ostream& outs, const Stack<U>& l){
        return _print_list(l._top, outs);
    }

    class Iterator
    {

    public:

        friend class Stack;

        Iterator(node<T>* _ptr = nullptr): _ptr(_ptr){}

        friend Iterator operator ++(Iterator& it, int unused) // it++
        {
            assert(it._ptr != nullptr);
            Iterator hold;
            it = it._ptr -> _next;
            return hold;
        }

        Iterator& operator ++()
        {
            assert(_ptr != nullptr);
            _ptr = _ptr -> _next;
            return *this;
        }

        T& operator *()
        {
            assert(_ptr);
            return _ptr -> _item;
        }

        const node<T>* operator ->()const
        {
            assert(_ptr);
            return _ptr;

        }

        operator bool()
        {
            if(_ptr != nullptr)
                return true;
            return false;
        }

        bool is_null()
        {
            if(_ptr == nullptr)
                return true;
            else
                return false;
        }

        friend bool operator ==(const Iterator& left, const Iterator& right)
        {
            if (left._ptr == right._ptr)
                return true;
            else
                return false;
        }

    private:

        node<T>* _ptr;

    };


    void push(const T& item);
    T pop();
    void print() const;
    int size();
    bool empty();
    Iterator top() const;


private:
    node<T>* _top;
    int _size;
};

template <typename T>
Stack<T>::Stack():_top(nullptr),_size(0)
{

}

template <typename T>
Stack<T>::Stack(const Stack<T> &copy_this)
{
    if(copy_this._top == nullptr)
    {
        _top = nullptr;
        _size = 0;
    }
    else
    {
        _top = _copy_list(copy_this._top);
        _size = copy_this._size;
    }

}

template <typename T>
Stack<T>& Stack<T>::operator =(const Stack &rhs)
{
    if(this == &rhs)
        return *this;

    _clear_list(_top);

    if(rhs._top == nullptr)
    {
        _top = nullptr;
        _size = 0;
    }
    else
    {
        _top = _copy_list(rhs -> _top);
        _size = rhs._size;
    }

    return *this;

}

template <typename T>
Stack<T>::~Stack()
{
    _clear_list(_top);
}

template <typename T>
void Stack<T>::push(const T& item)
{
    bool debug = false;
    if (debug) cout << "\npush into Stack: item: " << item << endl;
    _size++;
     _top = _insert_head(_top, item);
}

template <typename T>
T Stack<T>::pop()
{
    bool debug = false;
    if (debug) cout << "\npop out of Stack: " << endl;
    assert(_top != nullptr);

    _size --;
    return _remove_head( _top);
}

template <typename T>
void Stack<T>::print()const
{
    _print_list(_top);
}

template <typename T>
int Stack<T>::size()
{
    return _size;
}

template <typename T>
bool Stack<T>::empty()
{
    if(_top == nullptr)
        return true;
    else
        return false;
}

template <typename T>
typename Stack<T>::Iterator Stack<T>::top()const
{
    node<T>* mark_ptr = _top;
    return Iterator (mark_ptr);
}

//===================================== T E S T  F U N C T I O N S =====================================


//void test_stack_push_pop()
//{
//    Stack<int> s;

//    s.push(1);
//    cout << s << endl;
//    s.push(2);
//    cout << s << endl;
//    s.push(3);
//    cout << s << endl;
//    s.push(4);
//    cout << s << endl;
//    s.push(5);
//    cout << s << endl;
//    s.push(6);

//     cout << endl << endl << "Size of Stack: "<< s.size() << endl << endl;

//    cout << endl << endl;
//    cout << s;

//    for(int i = 0; i < 6; i++)
//    {
//        cout << s.pop();
//        cout << endl << endl;
//        cout << s;
//    }

//    if(s.empty())
//        cout << "\n\nStack is empty!\n\n";
//    else
//        cout << "\n\nStack is */not empty!\n\n";
//}

#endif // STACK_H
