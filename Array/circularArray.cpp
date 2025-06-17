#include <iostream>

const int DEFAULT_SIZE = 8;

template <typename T>
class CircularArray
{
private:
    T *data;
    size_t capacity;
    int rear;
    int front;
    void resize();

public:
    CircularArray(size_t size = DEFAULT_SIZE);
    bool isEmpty();
    bool isFull();
    void enqueue(T val);
    void dequeue();
    T peek()
};

template <typename T>
CircularArray<T>::CircularArray(size_t size)
{
    rear = front = -1;
    capacity = size;
    data = new T[capacity + 1];
}

template <typename T>
bool CircularArray<T>::isEmpty()
{
    return rear == -1 && front == -1;
}

template <typename T>
bool CircularArray<T>::isFull()
{
    return rear % capacity == front;
}
