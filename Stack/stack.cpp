#include <iostream>

using namespace std ; 

const int Default = 10;  

class Stack
{
private:
	int *arr;
	int size; 
	int capacity; 

public: 
	Stack()
	{
		capacity=Default; // default 
		size=0 ; 
		arr=new int [capacity];
	}
	Stack(int len)
	{
		capacity= len ; 
		size=0; 
		arr=new int [capacity];
	}

	// destructor 
	bool isEmpty()
	{
		return size==0; 
	}
	int length()
	{
		return size; 
	}

	void push(int data)
	{
		if(size<capacity)
		{
			arr[size++]=data;
		}
		else 
		{
			cout<<"stack overflow!\n";
		}
	}
	int pop()
	{
		if(!isEmpty())
		{
			return arr[size--];
		}
		else 
		{
			cout<<"Stack is empty\n";
			return -1;
		}
	}

	// test if empty first 
	int top()
	{
		if(!isEmpty())
		{
			return arr[size-1];		

		}
		else 
		{
			return -1; 
		}
	}



	
};

int main()
{
	Stack myStack; 

	for(int i=0;i<10;i++)
	{
		myStack.push(i);
		cout<<myStack.top()<<"\n";
	}
	myStack.push(10);

}