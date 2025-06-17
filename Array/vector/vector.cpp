#include <iostream>

using namespace std;

const size_t DEFAULT_SIZE = 2;

template <typename T>
class Vector
{
private:
	T *arr;
	int size;
	int capacity;

	void resize();
	bool isEmpty() const;
	bool isFull() const;

public:
	Vector(int len = DEFAULT_SIZE);
	~Vector();

	int length() const;
	void push(T val);
	void remove(int index);
	void pop_back();
	void pop_front();
	void display() const;
	void insert(int index, T val);
};

// ====== Definitions ======

template <typename T>
Vector<T>::Vector(int len)
{
	if (len <= 0)
	{
		throw std::invalid_argument("Vector size must be positive");
	}
	arr = new T[len];
	size = 0;
	capacity = len;
}

template <typename T>
Vector<T>::~Vector()
{
	delete[] arr;
}

template <typename T>
void Vector<T>::resize()
{
	capacity = (capacity == 0) ? DEFAULT_SIZE : capacity * 2;
	T *data = new T[capacity];
	for (int i = 0; i < size; i++)
		data[i] = arr[i];
	delete[] arr;
	arr = data;
}

template <typename T>
bool Vector<T>::isEmpty() const
{
	return size == 0;
}

template <typename T>
bool Vector<T>::isFull() const
{
	return size == capacity;
}

template <typename T>
int Vector<T>::length() const
{
	return size;
}

template <typename T>
void Vector<T>::push(T val)
{
	if (size == capacity)
		resize();
	arr[size++] = val;
}

template <typename T>
void Vector<T>::remove(int index)
{
	if (index >= size || index < 0)
		return;

	for (int i = index; i < size - 1; i++)
	{
		arr[i] = arr[i + 1];
	}
	size--;
}

template <typename T>
void Vector<T>::pop_back()
{
	remove(size - 1);
}

template <typename T>
void Vector<T>::pop_front()
{
	remove(0);
}

template <typename T>
void Vector<T>::display() const
{
	for (int i = 0; i < size; i++)
	{
		cout << arr[i] << ' ';
	}
	cout << '\n';
}

template <typename T>
void Vector<T>::insert(int index, T val)
{
	if (index > size || index < 0)
		return;
	if (size == capacity)
		resize();
	for (int i = size; i > index; i--)
		arr[i] = arr[i - 1];
	arr[index] = val;
	size++;
}

// ====== Main ======

int main()
{
	Vector<int> vec{};
	for (int i = 0; i < 100; i++)
		vec.push(i);

	vec.insert(0, 1000);
	vec.insert(101, 1000);
	vec.display();
}
