#include <iostream>
#include <stdexcept>

template <typename T>
class Node
{
public:
    T data;
    Node<T> *next;
    Node<T> *prev;
    Node(const T &value) : data{value}, next{nullptr}, prev{nullptr} {}
};

template <typename T>
class DoublyLinkedList
{
private:
    Node<T> *head;
    Node<T> *tail;
    bool unlinkAndDelete(Node<T> *tmp); // helper to be used by remove

public:
    DoublyLinkedList();
    ~DoublyLinkedList();

    // Core operations
    void addFront(const T &value);
    void addBack(const T &value);
    bool remove(const T &value);
    bool removeAt(size_t index);
    bool removeFront();
    bool removeBack();

    T getFront() const;
    T getBack() const;
    bool isEmpty() const;
    size_t size() const;
};

template <typename T>
DoublyLinkedList<T>::DoublyLinkedList() : head{nullptr}, tail{nullptr} {}
template <typename T>
DoublyLinkedList<T>::~DoublyLinkedList()
{
    while (removeFront())
    {
    }
}

template <typename T>
void DoublyLinkedList<T>::addFront(const T &value)
{
    Node<T> *node = new Node(value);
    if (head == nullptr)
    {
        head = tail = node;
        return;
    }
    node->next = head;
    head->prev = node;
    head = node;
}

template <typename T>
void DoublyLinkedList<T>::addBack(const T &value)
{
    Node<T> *node = new Node(value);
    if (head == nullptr)
    {
        head = tail = node;
        return;
    }
    node->prev = tail;
    tail->next = node;
    tail = node;
}

template <typename T>
bool DoublyLinkedList<T>::remove(const T &value)
{
    Node<T> *tmp = head;
    while (tmp != nullptr && tmp->data != value)
    {
        tmp = tmp->next;
    }
    return unlinkAndDelete(tmp);
}

template <typename T>
bool DoublyLinkedList<T>::removeAt(size_t index)
{
    Node<T> *tmp = head;
    while (tmp != nullptr && index > 0)
    {
        tmp = tmp->next;
        index--;
    }
    return unlinkAndDelete(tmp);
}
template <typename T>
bool DoublyLinkedList<T>::unlinkAndDelete(Node<T> *tmp)
{
    if (tmp == nullptr)
        return false;

    if (tmp->prev == nullptr && tmp->next == nullptr) // tmp=head=tail
    {
        head = tail = nullptr;
    }
    else if (tmp->prev != nullptr && tmp->next == nullptr) // node | tmp=tail
    {
        tail = tmp->prev;
        tail->next = nullptr;
    }
    else if (tmp->prev == nullptr && tmp->next != nullptr) // tmp=head | node
    {
        head = tmp->next;
        head->prev = nullptr;
    }
    else
    { // node | tmp | node
        tmp->prev->next = tmp->next;
        tmp->next->prev = tmp->prev;
    }

    delete tmp;
    return true;
}

template <typename T>
bool DoublyLinkedList<T>::removeFront()
{
    return unlinkAndDelete(head);
}

template <typename T>
bool DoublyLinkedList<T>::removeBack()
{
    return unlinkAndDelete(tail);
}

template <typename T>
T DoublyLinkedList<T>::getFront() const
{
    if (head == nullptr)
        throw std::out_of_range("List is empty");
    return head->data;
}
template <typename T>
T DoublyLinkedList<T>::getBack() const
{
    if (tail == nullptr)
        throw std::out_of_range("List is empty");
    return tail->data;
}

template <typename T>
bool DoublyLinkedList<T>::isEmpty() const
{
    return head == nullptr;
}

template <typename T>
size_t DoublyLinkedList<T>::size() const
{
    size_t counter = 0;
    Node<T> *tmp = head;
    while (tmp)
    {
        counter++;
        tmp = tmp->next;
    }
}