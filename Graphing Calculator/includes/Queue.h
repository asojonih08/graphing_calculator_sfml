#ifndef QUEUE_H
#define QUEUE_H
#include "linked_lists.h"
#include <iostream>

using namespace std;

//void test_push_pop();

template <typename T>

class Queue
{
public:
    Queue();

    ~Queue();
    Queue(const Queue<T> &copy_this);
    Queue& operator =(const Queue &rhs);

    class Iterator
    {

    public:

        friend class Queue;

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



    friend ostream& operator <<(ostream& outs, const Queue<T>& l){
        return _print_list(l._front, outs);
    }

    Iterator front() const;

    void push(const T& item);
    T pop();
    void print() const;
    node<T>* copy_list(node<T>* &_back, node<T>* &_front);
    bool empty();
    int size();
private:
    node<T>* _front;
    node<T>* _back;
    int _size;
};

template <typename T>
Queue<T>::Queue():_front(nullptr),_back(nullptr),_size(0)
{
    bool debug = false;
    if(debug)cout << "\nQueue const initial---------\n\n";

}

template <typename T>
Queue<T>::Queue(const Queue<T> &copy_this)
{
    if(copy_this._front == nullptr)
    {
        _front = _back = nullptr;
        _size = 0;
    }
    else
    {
//        node<T>* old = copy_this._front;
//        node<T>* temp_new;
//        _back = new node<T>;
//        _back -> _item = old -> _item;
//        _back -> _next = nullptr;
//        _front = _back;
//        old = old -> _next;
//        while(old)
//        {
//            temp_new = new node<T>;
//            temp_new -> _item = old -> _item;
//            temp_new -> _next = nullptr;
//            _back -> _next = temp_new;
//            _back = temp_new;
//            old = old -> _next;
//        }
        _front = _copy_list_queue(copy_this._front,_back);
        _size = copy_this._size;
    }


}

template <typename T>
Queue<T>& Queue<T>::operator =(const Queue &rhs)
{

    if(this == &rhs)
        return *this;

    _clear_list(_front);



    if(rhs._front == nullptr)
    {
        _front = _back = nullptr;
        _size = rhs._size;
    }
    else
    {
//        node<T>* old = rhs._front;
//        node<T>* temp_new;
//        _back = new node<T>;
//        _back -> _item = old -> _item;
//        _back -> _next = nullptr;
//        _front = _back;
//        old = old -> _next;

//        while(old)
//        {
//            temp_new = new node<T>;
//            temp_new -> _item = old -> _item;
//            temp_new -> _next = nullptr;
//            _back -> _next = temp_new;
//            _back = temp_new;
//            old = old -> _next;
//        }

        _front = _copy_list_queue(rhs._front,_back);
        _size = rhs._size;
    }

    return *this;
}

template <typename T>
Queue<T>::~Queue()
{
    _clear_list(_front);
    _back = _front;
}

template <typename T>
void Queue<T>::push(const T& item)
{
    bool debug = false;
    if (debug) cout << "push into Queue: item: \n" << item << endl;


    _insert_after(_front, _back, item);

    if(_front -> _next == nullptr)
    {
       _back =  _front;
    }
   else
        _back = _back ->_next;

    _size++;

}

template <typename T>
T Queue<T>::pop()
{
    bool debug = false;
    if(debug) cout << "\npop out of Queue: " << endl;


    assert(_front != nullptr);

    T item = _remove_head(_front);

    if(_front == nullptr)
        _back = nullptr;

    _size --;
    return item;

}

template <typename T>
void Queue<T>::print()const
{
    _print_list(_front);
}

template <typename T>
bool Queue<T>::empty()
{
    if(_back == nullptr && _front == nullptr)
        return true;
    else
        return false;
}

template <typename T>
int Queue<T>::size()
{
    return _size;
}

template <typename T>
typename Queue<T>::Iterator Queue<T>::front()const
{
    node<T>* mark_ptr = _front;
    return Iterator (mark_ptr);
}
//===================================== T E S T  F U N C T I O N S =====================================

//void test_push_pop()
//{
//    Queue<int> q;

//    q.push(1);
//    cout << q << endl;
//    q.push(2);
//    cout << q << endl;
//    q.push(3);
//    cout << q << endl;
//    q.push(4);
//    cout << q << endl;
//    q.push(5);
//    cout << q << endl;
//    q.push(6);
//    cout << q << endl;

//    cout << endl << endl << "Size of Queue: "<< q.size() << endl << endl;
//    cout << endl << endl;
//    cout << q;

//    for(int i = 0; i < 6; i++)
//    {
//        cout << q.pop();
//        cout << endl << endl;
//        cout << q;
//    }

//    if(q.empty())
//        cout << "\n\nQueue is empty!\n\n";
//    else
//        cout << "\n\nQueue is not empty!\n\n";

//    cout << q.pop();
//}
#endif // QUEUE_H

