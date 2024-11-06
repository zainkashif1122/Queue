#include <iostream>
using namespace std;

template <class T>
class Queue
{
protected:
	T* array;
	int front;
	int rear;
	int maxSize;

public:
	Queue(int s);
	~Queue();

	virtual bool isFull() = 0;
	virtual bool isEmpty() = 0;

	virtual void enQueue(T value) = 0;
	virtual T deQueue() = 0;

	virtual void display() = 0;

};

template<class T>
Queue<T>::Queue(int s)
{
	maxSize = s;
	front = rear = -1;
	array = new T[maxSize];
}

template<class T>
Queue<T>::~Queue()
{
	delete[]array;
}