#include "Queue.h"

template <class T>
class MyQueue :public Queue <T>
{
public:
	MyQueue(int s);

	bool isFull();
	bool isEmpty();

	void enQueue(T value);
	T deQueue();

	void display();

};

template<class T>
MyQueue<T>::MyQueue(int s) :Queue<T>(s) {}

template<class T>
bool MyQueue<T>::isFull()
{
	return (this->rear + 1) % this->maxSize == this->front;
	//return this->rear == this->maxSize - 1;
}

template<class T>
bool MyQueue<T>::isEmpty()
{
	return this->front == -1;
	//return (this->front == this->rear && this->rear == -1);
}

template<class T>
void MyQueue<T>::enQueue(T value)
{
	/*if (isFull())
	{
		cout << "Queue is full!!!" << endl;
	}
	else if (isEmpty())
	{
		this->front++;
		this->rear++;
		this->array[this->rear] = value;
	}
	else
	{
		this->rear++;
		this->array[this->rear] = value;
	}*/

	if (isFull()) 
	{
		cout << "Queue is full!!!" << endl;
	}
	else 
	{
		if (isEmpty()) 
		{
			this->front = this->rear = 0;
		}
		else 
		{
			this->rear = (this->rear + 1) % this->maxSize;
		}
		this->array[this->rear] = value;
	}
}

template<class T>
T MyQueue<T>::deQueue()
{
	/*if (isEmpty())
	{
		cout << "Queue is empty!!!" << endl;
		return T();
	}
	else
	{
		return this->array[this->front++];
	}*/

	if (isEmpty()) 
	{
		cout << "Queue is empty!!!" << endl;
		return T();
	}
	else 
	{
		T value = this->array[this->front];
		if (this->front == this->rear) 
		{
			// Queue is now empty
			this->front = this->rear = -1;
		}
		else 
		{
			this->front = (this->front + 1) % this->maxSize;
		}
		return value;
	}
}

template<class T>
void MyQueue<T>::display()
{
	/*if (isEmpty())
	{
		cout << "Queue is empty!!!" << endl;
	}
	else
	{
		cout << "Queue: ";
		for (int i = this->front; i <= this->rear; i++)
		{
			cout << this->array[i] << " ";
		}
		cout << endl;
	}*/

	if (isEmpty())
	{
		cout << "Queue is empty!!!" << endl;
	}
	else
	{
		cout << "Queue: ";
		int i = this->front;
		while (true)
		{
			cout << this->array[i] << " ";
			if (i == this->rear) // Stop when we reach the rear
				break;
			i = (i + 1) % this->maxSize; // Wrap around using modulo
		}
		cout << endl;
	}
}