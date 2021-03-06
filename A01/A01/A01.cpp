// A01.cpp : Defines the entry point for the console application.
// Kyle Fasanella DSA 2 Templated Queue

#include "stdafx.h"
using namespace std;

int main()
{
	//try out with ints
	Queue<int> intQueue;
	
	//push some ints
	intQueue.Push(1);
	intQueue.Print();
	cout << "Size of queue: " << intQueue.GetSize() << endl;
	intQueue.Push(2);
	intQueue.Print();
	cout << "Size of queue: " << intQueue.GetSize() << endl;
	intQueue.Push(3);
	cout << "Size of queue: " << intQueue.GetSize() << endl;
	intQueue.Push(4);
	intQueue.Print();
	intQueue.Push(5);
	intQueue.Print();
	cout << "Size of queue: " << intQueue.GetSize() << endl;

	//copy queue
	Queue<int> copiedQueue(intQueue);
	
	//assigned queue
	Queue<int> assignQueue;
	assignQueue = intQueue;

	cout << "Assigned Queue:\n";
	assignQueue.Print();

	cout << "Copied Queue:\n";
	copiedQueue.Print();

	//pop
	intQueue.Pop();
	intQueue.Pop();
	intQueue.Print();
	intQueue.Pop();

	//assign queue again
	assignQueue = intQueue;
	cout << "Assigned Queue:\n";
	assignQueue.Print();
	intQueue.Print();
	cout << "Size of queue: " << intQueue.GetSize() << endl;
	
	cout << "Copied Queue:\n";
	copiedQueue.Print();

	//prevent leaks
	intQueue.~Queue();
	copiedQueue.~Queue();
	assignQueue.~Queue();

	//check for leaks
	_CrtDumpMemoryLeaks();
    return 0;
}

