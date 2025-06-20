#include <iostream>

// using circular array

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
    ~CircularArray();
    bool isEmpty();
    bool isFull();
    void addRear(T val);
    void addFront(T val);
    T removeFront();
    T removeRear();
    T peek();
    T peekBack();
};

template <typename T>
CircularArray<T>::CircularArray(size_t size)
{
    rear = front = -1;
    capacity = size;
    data = new T[capacity];
}

template <typename T>
CircularArray<T>::~CircularArray()
{
    delete[] data;
}
template <typename T>
bool CircularArray<T>::isEmpty()
{
    return rear == -1 && front == -1;
}

template <typename T>
bool CircularArray<T>::isFull()
{
    return (rear + 1) % capacity == front;
}

template <typename T>
void CircularArray<T>::addRear(T val)
{
    if (isFull())
        resize();
    if (isEmpty())
    {
        rear = front = 0;
        data[rear] = val;
    }
    else
    {
        rear = (rear + 1) % capacity;
        data[rear] = val;
    }
}

template <typename T>
void CircularArray<T>::addFront(T val)
{
    if (isFull())
        resize();
    if (isEmpty())
    {
        rear = front = 0;
        data[front] = val;
    }
    else
    {
        front = (front - 1 + capacity) % capacity;
        data[front] = val;
    }
}

template <typename T>
T CircularArray<T>::removeFront()
{
    if (isEmpty())
        throw std::runtime_error("Array empty");
    T val = data[front];
    if (rear == front)
    {
        front = rear = -1;
    }
    else
    {
        front = (front + 1) % capacity;
    }
    return val;
}

template <typename T>
T CircularArray<T>::removeRear()
{
    if (isEmpty())
        throw std::runtime_error("Array empty");
    T val = data[rear];
    if (rear == front)
    {
        front = rear = -1;
    }
    else
    {
        rear = (rear - 1 + capacity) % capacity;
    }
    return val;
}
template <typename T>
T CircularArray<T>::peek()
{
    if (isEmpty())
        throw std::runtime_error("Array empty");
    return data[front];
}

template <typename T>
T CircularArray<T>::peekBack()
{
    if (isEmpty())
        throw std::runtime_error("Array empty");
    return data[rear];
}
template <typename T>
void CircularArray<T>::resize()
{
    T *newData = new T[2 * capacity];
    for (int i = 0; i < capacity; i++)
    {
        newData[i] = data[(front + i) % capacity];
    }
    delete[] data;
    data = newData;
    front = 0;
    rear = capacity - 1;
    capacity *= 2;
}

//  Deque implementation
template <typename T>
class Deque
{
private:
    CircularArray<T> arr;

public:
    Deque(size_t size = DEFAULT_SIZE) : arr(size)
    {
    }
    bool isEmpty()
    {
        return arr.isEmpty();
    }
    bool isFull()
    {
        return arr.isFull();
    }

    void enqueueBack(T val)
    {
        arr.addRear(val);
    }

    void dequeueFront()
    {
        arr.removeFront();
    }

    void enqueueFront(T val)
    {
        arr.addFront(val);
    }

    void dequeueBack()
    {
        arr.removeRear();
    }
    T getFront()
    {
        return arr.peek();
    }
    T getBack()
    {
        return arr.peekBack();
    }
};
