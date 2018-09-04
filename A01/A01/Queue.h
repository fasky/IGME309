#pragma once
using namespace std;
//queue template

template <class T>
class Queue
{
private:
	//elements
	struct Element {
		T elementData;
		Element * after;

		//constructer
		Element(const T& data, Element * next) {
			after = next;
			elementData = data;
		}
	};

	//front pointer
	Element * front;
	Element * back; //back pointer

public:
	//Constructor
	Queue();

	//copy constructor
	Queue(const Queue& queue);

	//copy assignment operator - old stack goes, copy in new stuff
	void operator = (const Queue &qu) {
		while (!IsEmpty()) {
			Pop(); //empty
		}
		//then assign
		Element * assign = qu.front;
		if (assign == nullptr) {
			return;
		}

		for (int i = 1; i <= const_cast<Queue&>(qu).GetSize(); i++) {

			Push(assign->elementData);
			assign = assign->after;

		}
	}

	//Push
	void Push(const T& newElemData);

	//Pop
	void Pop();

	//Print
	void Print();

	//GetSize
	int GetSize();

	//Is it empty?
	bool IsEmpty();

	//Destructor - deallocate
	~Queue();
};

//constructor
template <class T>
Queue<T> :: Queue() {
	front = nullptr;
	back = nullptr;
}

//Push
template <class T>
void Queue<T> :: Push(const T& newElemData) {
	if (front == nullptr) {
		Element * elem = new Element(newElemData, front);
		front = elem;
		back = elem;
	}
	else {
		Element * elem = new Element(newElemData, back);

		if (back == front) {
			front->after = elem;
			back = elem;
		}
		else {
			back->after = elem;
			back = elem;
		}
	}
}

//Pop
template <class T>
void Queue<T>::Pop() {
	if (IsEmpty()) {
		cout << "Nothing to Pop!\n";
	}
	else {

		Element * popped = front;

		if (back == front) {
			front = nullptr;
			back = nullptr;
		}

		else {
			front = front->after;
		}

		delete popped;
	}
}

//Print
template <class T>
void Queue<T>::Print() {
	if (!IsEmpty()) {
		int count = GetSize();
		cout << "From front to back:\n";
		Element * temp = front;
		for (int i = 0; i < count; i++) {
			cout << temp->elementData << endl;
			temp = temp->after;
		}
		temp = nullptr;
	}
}

//GetSize
template <class T>
int Queue<T>::GetSize() {
	int count = 0;
	if (!IsEmpty()) {
		Element * temp = front;
		if (temp->after == nullptr) {
			return 1;
		}
		while (temp != back) {
			count++;
			temp = temp->after;
		}		
		temp = nullptr;
		return count + 1; //account for back
	}
	else {
		return count;
	}
}

//IsEmpty
template <class T>
bool Queue<T>::IsEmpty() {
	if (front == nullptr) {
		return true;
	}
	return false;
}

//copy constructor
template <class T>
Queue<T>::Queue(const Queue& queue) {
	front = nullptr;
	back = nullptr;

	Element * copying = queue.front;
	if (copying == nullptr) {
		return;
	}

	for (int i = 1; i <= const_cast<Queue&>(queue).GetSize(); i++) {

		Push(copying->elementData);
		copying = copying->after;

	}

}


//destructor
template <class T>
Queue<T>::~Queue() {
	while (!IsEmpty()) {
		Pop();
	}
	delete front;
	delete back;
}