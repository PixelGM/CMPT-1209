#pragma once

template <class T>
class Queue
{
private:
	T* queueArray;
	int capacity;
	int numItems;
public:
	Queue(int);
	~Queue();
	void enqueue(T);
	void dequeue(T&);
	bool isEmpty() const;
	bool isFull() const;
	void display() const;
	Queue<T>& operator=(const Queue<T>&);
};


using namespace std;

template <class T>
Queue<T>::Queue(int s)
{
	queueArray = new T[s];
	capacity = s;
	numItems = 0;
}

template <class T>
Queue<T>::~Queue()
{
	delete[] queueArray;
}

template <class T>
void Queue<T>::enqueue(T num)
{
	if (isFull())
		cout << "The queue is full.\n";
	else
	{
		queueArray[numItems] = num;
		numItems++;
	}
}

template <class T>
void Queue<T>::dequeue(T& num)
{
	if (isEmpty())
		cout << "The queue is empty.\n";
	else
	{
		num = queueArray[0];
		for (int i = 0; i < numItems - 1; i++)
			queueArray[i] = queueArray[i + 1];
		numItems--;
	}
}

template <class T>
bool Queue<T>::isEmpty() const
{
	return numItems == 0;
}

template <class T>
bool Queue<T>::isFull() const
{
	return numItems == capacity;
}

template <class T>
void Queue<T>::display() const
{
	if (isEmpty())
	{
		cout << "The queue is empty.\n";
		return;
	}
	cout << "\nThese are elements of the Queue.\n";
	for (int i = 0; i < numItems; i++)
	{
		cout << queueArray[i] << endl;
	}
}

template <class T>
Queue<T>& Queue<T>::operator=(const Queue<T>& right)
{
	queueArray.right = queueArray;
	capacity.right = capacity;
	numItems.right = numItems;
}