//this is the .h file
//define node structure
template <class T>
struct ListNode
{
	T value;  //the "data"
	ListNode* next;  //pointer to the next node
};
#ifndef LINKEDLIST_H
#define LINKEDLIST_H
template <class T>
class LinkedList
{
protected:
	//need to maintain the start of the list
	ListNode<T>* head;


public:
	LinkedList() { head = nullptr; }  //empty list
	~LinkedList();   //destructor
	void displayList();  //to print all values in the list
	void append(T);
	void insertNode(T);
	void remove(T);
	bool search(T);
	T get(T);



};
//ListNode<T>*
#endif



template<class T>
T LinkedList<T>::get(T position)
{
	cout << position << endl;
	ListNode<T> *nodePtr;   // to walk the list
	nodePtr = head; //intilazing 
	T temp = 0; //intilazing 
				//walks you through the list to the position given
	while (nodePtr != nullptr)
	{
		temp++;
		if (temp == position)
		{
			return nodePtr->value;//returns whatevers at that poistion
		}
		nodePtr = nodePtr->next;
	}
	return 0;
}

//insert newValue in correct order
template <class T>
void LinkedList<T>::insertNode(T newValue)
{
	ListNode<T> *newNode;   //a new node
	ListNode<T> *nodePtr;   // to walk the list
	ListNode<T> *previousNode = nullptr; //previous node
										 //allocate a new node and store newValue there
	newNode = new ListNode <T>;
	newNode->value = newValue;

	//have to figure out where to insert it
	//if no nodes in the list make newNode the first node
	if (head == nullptr)
	{
		head = newNode;
		newNode->next = nullptr;
	}
	else  //figure out where to insert newNode
	{
		//position nodePtr to walk the list
		nodePtr = head;

		//initialize previousNode to nullptr
		previousNode = nullptr;

		//skip all nodes whose value is less that newValue
		while (nodePtr != nullptr && nodePtr->value < newValue)
		{
			previousNode = nodePtr;
			nodePtr = nodePtr->next;
		}

		//if it goes at the beginning
		if (previousNode == nullptr)
		{
			head = newNode;
			newNode->next = nodePtr;
		}
		else //insert between previousNode and nodePtr
		{
			previousNode->next = newNode;
			newNode->next = nodePtr;
		}

	}


}
template <class T>
void LinkedList<T>::append(T num)
{
	//add num to the end of the list
	ListNode<T>* newNode;  //to hold the new node
	ListNode<T>* nodePtr;  //to "walk" the list

						   //allocate the new node
	newNode = new ListNode<T>;
	//assign fields
	newNode->value = num;
	newNode->next = nullptr;  //it is the end of the list
							  //figure out where to put it
							  //if empty list it's easy
	if (head == nullptr) //empty list
		head = newNode;
	else //find the end of the list
	{
		//start at head
		nodePtr = head;
		while (nodePtr->next != nullptr)
		{
			nodePtr = nodePtr->next;  //move to next node
		}
		//when this loop ends, nodePtr is pointing to the last node
		//need to make newNode the last node
		nodePtr->next = newNode;
	}
}

template <class T>
LinkedList<T>::~LinkedList()
{
	ListNode<T>* nodePtr;
	ListNode<T>* nextNode;
	//walk the list and delete memory
	nodePtr = head;
	while (nodePtr != nullptr)
	{
		//hold on to where the next one is before I let this one go
		nextNode = nodePtr->next;
		//delete nextNode6
		delete nodePtr;
		nodePtr = nextNode;
	}
}

template <class T>
void LinkedList<T>::displayList()
{
	int i = 1;
	ListNode<T>* nodePtr;
	if (head == nullptr)  //check if list is empty
		cout << "Empty List" << endl;
	else //walk through and print the values
	{
		//start at beginning
		nodePtr = head;
		while (nodePtr != nullptr) //(nodePtr->next != nullptr)
		{
			cout << i++ << ". " << nodePtr->value << endl;
			//move to next node
			nodePtr = nodePtr->next;
		}
	}
}
template<class T>
bool LinkedList<T>::search(T value)
{
	ListNode<T> *nodePtr;   // to walk the list
	nodePtr = head; //intilazing 

					/*counts through the nodes to find specific position*/
	while (nodePtr != nullptr)
	{
		if (!(nodePtr->value != value))
		{
			return 1; //returns temp which is the poisiton of the value if it exists
		}

		nodePtr = nodePtr->next;
	}
	return 0;
}
template<class T>
void LinkedList<T>::remove(T position)
{
	// to make it so 1 becomes 0 AKA the start of the list
	ListNode<T> *nodePtr;   // to walk the list
	ListNode<T> *previousNode; //previous node
							   //allocate a new node and store newValue there
	nodePtr = head; //intilazing 
	previousNode = head;//intilazing
	if (head == NULL) //checks to see if there is anyting in the list
	{
		cout << "Nothing to delete" << endl;
	}

	/*counts through the nodes to find specific position*/
	while ((nodePtr != NULL) && (nodePtr->value != position))
	{
		previousNode = nodePtr;
		nodePtr = nodePtr->next;
	}
	if (nodePtr == NULL) //checks to see if the position is in the list
	{
		cout << "Needs to be in the range of the list" << endl;
		return;
	}
	if (nodePtr == head) //makes the 2nd item in the list the first item
	{
		head = head->next;
		cout << "The character " << position << " was deleted." << endl;
	}
	else //makes the current item in the list the previous item
	{
		previousNode->next = nodePtr->next;
		cout << "The character " << position << " was deleted." << endl;
	}

	delete nodePtr; //deletes the current node
}
