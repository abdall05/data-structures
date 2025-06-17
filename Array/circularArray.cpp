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
    ~CircularArray();
    bool isEmpty();
    bool isFull();
    void addRear(T val);
    T removeFront();
    T peek();
    void print();
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
T CircularArray<T>::peek()
{
    if (isEmpty())
        throw std::runtime_error("Array empty");
    return data[front];
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

template <typename T>
void CircularArray<T>::print()
{
    std::cout << "Front:" << front << "| Rear:" << rear << '\n';
    for (int i = 0; i < capacity; i++)
    {
        std::cout << data[i] << ' ';
    }
    std::cout << '\n';
}

int main()
{
    CircularArray<int> arr;
    for (int i = 0; i < 8; i++)
        arr.addRear(-1);
    arr.print();
    for (int i = 0; i < 3; i++)
        arr.removeFront();
    arr.print();
}