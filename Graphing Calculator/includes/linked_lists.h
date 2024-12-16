#ifndef LINKED_LISTS_H
#define LINKED_LISTS_H
#include <iostream>
#include <iomanip>
#include <cassert>

using namespace std;

void test_linked_sorted();

template <typename T>
struct node
{

public:
    node(const T& item = T(), node* next = nullptr):_item(item), _next(next){
        //this one ctor acts as a default ctor (zero args) AND as
        //  one and two arg constructors
        //node n;
        //node n(5);
        //node n(5, node_address);
      }


    friend ostream& operator <<(ostream& outs, const node &print_me)
    {

        //always define templated friend operators inline
        outs<<"["<<print_me._item<<"]->";
        return outs;    //don't forget to return outs. you'll CRASH if you don't

    }

    T _item; // content in crate
    node* _next; // address of next crate
};

template <typename T>
node<T>* _insert_head(node<T>* &head_ptr, const T& item);

template <typename T>
T _remove_head(node<T>* &head_ptr);

template <typename T>
ostream& _print_list(node<T>* head_ptr, ostream& outs = cout);

template <typename T>
node<T>* _search(node<T>* head_ptr, const T& key);

template <typename T>
node<T>* _insert_after(node<T>* &head_ptr, node<T>* after_this, const T& item);

template <typename T>
node<T>* _previous_node(node<T>* head_ptr, node<T>* prev_to_this);

template <typename T>
node<T>* _insert_before(node<T>* &head_ptr, node<T>* before_this, const T& item);

template <typename T>
T _delete_node(node<T>* &head_ptr, node<T>* delete_this);

template <typename T>
node<T>* _copy_list(node<T>* head_ptr);

template <typename T>
node<T>* _copy_list_queue(node<T>* head_ptr, node<T>* &_back);

template <typename T>
void _clear_list(node<T>* &head_ptr);

template <typename T>
T& _at(node<T>* head_ptr, int pos);

template <typename T>
node<T>* _insert_sorted(node<T>* &head_ptr, T item, bool ascending = true);

template <typename T>
node<T>* _insert_sorted_and_add(node<T>* &head_ptr, T item, bool ascending = true); //insert or add

template <typename T>
node<T>* _where_this_goes(node<T>* head_ptr, T item, bool ascending = true);

template <typename T>
node<T>*  _last_node(node<T>* head_ptr);

//--------------------------------- DEFINITIONS --------------------------------



template <typename T>
node<T>* _insert_head(node<T>* &head_ptr, const T& item)
{
    bool debug = false;
    if(debug) cout << "\n_insert_head(): item: " << item << endl;



    node<T>* temp = new node <T>(item);
    temp -> _next = head_ptr;
    head_ptr = temp;

    return head_ptr;
}

template <typename T>
T _remove_head(node<T>* &head_ptr)
{
    assert(head_ptr != nullptr);

    node<T>* remove = head_ptr;

    if(head_ptr -> _next)
        head_ptr = head_ptr -> _next;
    else
        head_ptr = nullptr;

    T item = remove -> _item;
    delete remove;
    return item;
}

template <typename T>
ostream& _print_list(node<T>* head_ptr, ostream& outs)
{
    node<T>* walker = head_ptr;
    outs << "H->";

    while (walker)
    {
        outs << *walker;
        walker = walker -> _next ; //walker hop to the next node

    }
    outs << "|||";

    return outs;
}

template <typename T>
node<T>* _search(node<T>* head_ptr, const T& key)
{
    node<T>* walker = head_ptr;
    while (walker)
    {
        if (walker -> _item == key) return walker;
        walker = walker -> _next;
    }

    return nullptr;
}

template <typename T>
node<T>* _insert_after(node<T>* &head_ptr, node<T>* after_this, const T& item)
{
    if (head_ptr == nullptr)
        return _insert_head(head_ptr, item);

    node<T>* new_node = new node<T> (item);
    new_node -> _next = after_this -> _next;
    after_this -> _next = new_node;

    return new_node;
}

template <typename T>
node<T>* _previous_node(node<T>* head_ptr, node<T>* prev_to_this)
{
    node<T>* walker = head_ptr;
    if (walker == prev_to_this) return nullptr;

    while (walker)
    {
        if(walker -> _next == prev_to_this) return walker;

        walker = walker -> _next;
    }
    assert(walker == nullptr);
}

template <typename T>
node<T>* _insert_before(node<T>* &head_ptr, node<T>* before_this, const T& item)
{

    node<T>* previous_node = _previous_node(head_ptr, before_this);

    return _insert_after(head_ptr, previous_node, item);

}

template <typename T>
T _delete_node(node<T>* &head_ptr, node<T>* delete_this)
{
    node<T>* prev = _previous_node(head_ptr, delete_this);

    if(prev == nullptr)
    {
        T item = _remove_head(head_ptr);
        return item;
    }

    else
    {
       T item = delete_this -> _item;
       prev -> _next = delete_this -> _next;
       delete delete_this;
       return item;
    }
}

template <typename T>
node<T>* _copy_list(node<T>* head_ptr)
{
    if(!head_ptr) return nullptr;

    node<T>* copy = new node<T>(head_ptr -> _item);

    bool debug = false;
    if (debug) cout << "\n_copy_list ():  head_ptr: " << head_ptr << endl;

    node<T>* w_copy = copy;
    node<T>* w_head = head_ptr -> _next;

    while(w_head)
    {
       _insert_after(copy, w_copy, w_head -> _item);

       w_head = w_head -> _next;
       w_copy = w_copy -> _next;
    }

    if (debug) cout << "\n_copy_list ():  head_ptr: " << head_ptr << endl;

    if (debug) cout << "\n_copy_list ():  copy: " << copy << endl;
    return copy;
}

template <typename T>
node<T>* _copy_list_queue(node<T>* _front, node<T>* &_back)
{
    bool debug = false;
    if(debug)cout << "\ncopy_list---------\n\n";

    if(!_front) return nullptr;

    node<T>* copy = new node<T>(_front -> _item);

    node<T>* copy_w = copy;
    node<T>* front_w = _front -> _next;

    while(front_w)
    {
        _insert_after(copy, copy_w, front_w -> _item);

        front_w = front_w -> _next;
        copy_w = copy_w -> _next;
    }

    _back = copy_w;
    return copy;


}

template <typename T>
void _clear_list(node<T>* &head_ptr)
{

    while(head_ptr)
    {
        _remove_head(head_ptr);
    }
}

template <typename T>
T& _at(node<T>* head_ptr, int pos)
{
    node<T>* walker = head_ptr;

    for (int i = 0; i < pos; i++)
    {
        walker = walker -> _next;
    }

    return walker -> _item;
}

template <typename T>
node<T>* _where_this_goes(node<T>* head_ptr, T item, bool ascending)
{
     node<T>* back_walker = head_ptr;
     node<T>* walker = head_ptr -> _next;


     if (head_ptr -> _item >= item  && ascending == true) return nullptr;

     if (head_ptr -> _item <= item  && ascending == false) return nullptr;

     while(walker)
     {
         if(walker -> _item > item && ascending == true)
             return back_walker;

         if(walker -> _item <= item && ascending == false)
             return back_walker;

         walker = walker -> _next;
         back_walker = back_walker -> _next;
     }

     return back_walker;
}

template <typename T>
node<T>* _insert_sorted(node<T>* &head_ptr, T item, bool ascending)
{

    if(head_ptr == nullptr)
        return _insert_head(head_ptr, item);

    node<T>* location = _where_this_goes(head_ptr, item, ascending);



    if (location == nullptr)
        return _insert_head(head_ptr, item);

    if(location -> _next == nullptr)
        return _insert_after(head_ptr, location, item);

    return _insert_after(head_ptr, location, item);
}

template <typename T>
node<T>* _insert_sorted_and_add(node<T>* &head_ptr, T item, bool ascending)
{

    if(head_ptr == nullptr)
        return _insert_head(head_ptr, item);


    node<T>* location = _where_this_goes(head_ptr, item, ascending);


    if (location == nullptr)
    {
          if(head_ptr -> _item == item)
          {
              head_ptr -> _item += item;
              return head_ptr;
          }
        return _insert_head(head_ptr, item);
    }

    if(location -> _next == nullptr)
    {
        if(location -> _item == item)
        {
            location -> _item;
            return head_ptr;
        }
        return _insert_after(head_ptr, location, item);
    }

    if(location -> _item == item)
    {
      location -> _item += item;
      return head_ptr;
    }

    if(location->_next -> _item == item)
    {
        location->_next->_item += item;
        return head_ptr;
    }

    return _insert_after(head_ptr, location, item);
}

template <typename T>
node<T>*  _last_node(node<T>* head_ptr)
{
    node<T>* walker = head_ptr;

    while(walker)
    {
        if (walker -> _next == nullptr) return walker;
        walker = walker -> _next;
    }
}



//void test_linked_sorted()
//{
//    node<int>* head_ptr = nullptr;


//    _insert_sorted(head_ptr,15,true);
//    _insert_sorted(head_ptr,55,true);

//    _insert_sorted(head_ptr,5,true);


//    _print_list(head_ptr);
//}


#endif // LINKED_LISTS_H
