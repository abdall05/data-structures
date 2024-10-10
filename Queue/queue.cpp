#include <iostream>

using namespace std ; 

//using circular array 
class queue
{
private: 
	int *arr ;  
	int capacity; 
	int front ; 
	int rear; 
public:
	queue(int size)
	{
		capacity=size; 
		arr=new int[capacity];
		front=rear=-1; 
	}
	bool isEmpty()
	{
		return front ==-1 && rear==-1 ; 
	}
	bool isFull()
	{
		return (rear+1)%capacity==front ; 
	}

	void enqueue(int data )
	{
		if(isEmpty())
		{
			front=0; 
			rear=0;
		}
		else if (isFull())
		{
			return ; 
		}
		else 
		{
			rear=(rear+1)%capacity;
		}
		arr[rear]=data; 
	}

	void pop()
	{
		if(isEmpty())
			return ;
		else if (front==rear) // empty after deletion 
		{
			rear=-1 ; 
			front=-1; 
		}

		else 
			rear=(rear-1)%capacity;
		 


	}

	int getFront()
	{
		return arr[front];

	}

	int getRear()
	{
		return arr[rear];
	}

	
	
};

int main()
{
	queue q(3);
	for(int i=1;i<=3;i++)
	{
		q.enqueue(i);
	}
	cout<<q.isFull(); 
	for(int i=0;i<3;i++)
		q.pop();
	cout<<q.isEmpty();

	return 0 ; 
}