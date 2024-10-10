#include <iostream>

using namespace std; 


class Vector
{

private: 
	int* arr; 
	int size;
	int capacity; 
public:
	Vector(int len=2)
	{
		arr=new int[len]; 
		size=0 ; 
		capacity=len;
	}

	int length()
	{
		return size;
	}
	void push(int val)
	{
		if(size==capacity)
		{
			resize(2*capacity);
		}
        arr[size++]=val;
	}
	void resize(int n)
	{
		int* data = new int[n]; 
		for(int i=0;i<size;i++)
			data[i]=arr[i];
		delete[] arr; 
		arr=data; 
		capacity=n;

	}

	void remove(int index)
	{
		if(size!=0 && index <=size-1 )
		{
			for(int i=index+1;i<size;i++)
			{
				arr[i-1]=arr[i];
			}
			size--;
		}

	}

	void display()
	{
		for(int i=0;i<size;i++)
		{
			cout<<arr[i]<<' '; 
		}
		cout<<'\n';
	}

	void insert(int index, int val)
	{
		if(size==capacity)
		{
			resize(2*capacity);
		}
		for(int i=size-1;i>=index;i--)
			arr[i+1]=arr[i];
		arr[index]=val;
		size++; 

	}
	
	
	
};


int main()
{
	Vector vec=Vector(2); 
	for(int i=0;i<100;i++)
		vec.push(i);

	vec.insert(0,1000);
	vec.insert(20,3333);
	vec.display();

}