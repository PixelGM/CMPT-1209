#include <iostream>
#include "Queue.h"

using namespace std;


int main()
{
	// int Queue
	Queue<int> iQueue(5);
	int iCatchVar;
	iQueue.enqueue(5);
	iQueue.display();
	iQueue.enqueue(12);
	iQueue.display();
	iQueue.enqueue(8);
	iQueue.display();
	iQueue.enqueue(15);
	iQueue.display();
	iQueue.enqueue(17);
	iQueue.display();
	// Queue is gonna be full:
	iQueue.enqueue(5);
	iQueue.display();

	cout << endl;

	cout << "Dequeue:" << endl;
	iQueue.dequeue(iCatchVar);
	iQueue.display();
	iQueue.dequeue(iCatchVar);
	iQueue.display();
	iQueue.enqueue(99);
	iQueue.display();


	// String Queue
	Queue<string> sQueue(5);
	string sCatchVar;

	sQueue.enqueue("a");
	sQueue.display();
	sQueue.enqueue("b");
	sQueue.display();
	sQueue.enqueue("c");
	sQueue.display();
	sQueue.enqueue("d");
	sQueue.display();
	sQueue.enqueue("e");
	sQueue.display();
	// Queue is gonna be full:
	sQueue.enqueue("f");
	sQueue.display();

	cout << endl;

	sQueue.dequeue(sCatchVar);
	sQueue.display();
	sQueue.dequeue(sCatchVar);
	sQueue.display();
	sQueue.enqueue("z");
	sQueue.display();

	return 0;
}