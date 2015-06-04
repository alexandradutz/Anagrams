#ifndef DLList_h
#define DLList_h

#include <iostream>
#include <string>
using namespace std;

/****************************************************************************************************************\
* Pair class
\****************************************************************************************************************/
template <typename Key, typename Value>
class Pair {
	Key key;
	Value value;
public:
	// Value sortValue(Value v) {return v;};
	Pair(Key key, Value value) { this->key = key; this->value = value; };
	Key getKey() { return key; };
	Value getValue() { return value; };
	void setKey(Key key) { this->key = key; };
	void setValue(Value value) {
		this->value = value;
	};
};


/****************************************************************************************************************\
* Node class - a node for a Double Linked List  which has: data, next, prev and their corresponding setter & getters
\****************************************************************************************************************/

template <typename Key, typename Value>
class Node {
	Pair<Key, Value> *pair;
	Node<Key, Value> *next;
	Node<Key, Value> *prev;
public:
	Node() {};
	void setData(Pair<Key, Value> * aData) { pair = aData; };
	void setNext(Node<Key, Value> * aNext) { next = aNext; };
	void setPrev(Node<Key, Value> * aPrev) { prev = aPrev; };
	Pair<Key, Value> * getData() { return pair; };
	Node<Key, Value> * getNext() { return next; };
	Node<Key, Value> * getPrev() { return prev; };
};

/****************************************************************************************************************\
* Map ADT implementation over Sorted Doubly Linked List
	- ^head: Node
	- ^tail: Node
	- length: int
\****************************************************************************************************************/

template <typename Key, typename Value>
class SortedDLList {
	Node<Key, Value> *head;
	Node<Key, Value> *tail;
	int length;

public:
	SortedDLList() { head = NULL; length = 0; tail = NULL; };
	void removePair(Pair<Key, Value> *data);
	void addPair(Pair<Key, Value> *data);
	Value findValueForKey(Key key);
	Key findKeyForValue(Value value);
	void updateKeyForValue(Value value, Key key);
	void updateValueForKey(Key key, Value value);
	bool doesKeyExist(Key key);
	bool doesValueExist(Value value);
	Node<Key, Value>* findFirstNode(Value value);
};


/****************************************************************************************************************\
* Map ADT operations over Sorted Doubly Linked List
\****************************************************************************************************************/

template <typename Key, typename Value>
void SortedDLList<Key, Value>::removePair(Pair<Key, Value> *data) {
	if (head == NULL) {
		return;
	}
	length--;
	if (head->getData()->getValue() == data->getValue() && length == 1) {
		head = NULL;
		return;
	}
	if (head->getData()->getValue() == data->getValue() && length > 1) {
		head = head->getNext();
		return;
	}
	Node<Key, Value> *tmp = head;
	while (tmp->getNext() != NULL) {
		if (tmp->getNext()->getData()->getValue() == data->getValue()) {
			tmp->setNext(tmp->getNext()->getNext());
			return;
		}
		tmp = tmp->getNext();
	}
}

template <typename Key, typename Value>
void SortedDLList<Key, Value>::addPair(Pair<Key, Value> *data) {
	length++;
	if (head == NULL) {
		head = new Node<Key, Value>();
		head->setData(data);
		head->setNext(NULL);
		return;
	}
	Node<Key, Value> *tmp = head;
	if (tmp->getData()->getValue() >= data->getValue()) {
		Node<Key, Value> *newNode = new Node<Key, Value>();
		newNode->setData(head->getData());
		newNode->setNext(head->getNext());
		head->setData(data);
		head->setNext(newNode);
		return;
	}
	while (tmp->getNext() != NULL) {
		if (tmp->getData()->getValue() <= data->getValue()) {
			Node<Key, Value> *aux = tmp->getNext();
			Node<Key, Value> *newNode = new Node<Key, Value>();
			newNode->setData(data);
			newNode->setNext(aux);
			tmp->setNext(newNode);
			return;
		}
		tmp = tmp->getNext();
	}
	Node<Key, Value> *newNode = new Node<Key, Value>();
	newNode->setData(data);
	newNode->setNext(NULL);
	tmp->setNext(newNode);
	return;
}

template <typename Key, typename Value>
Value SortedDLList<Key, Value>::findValueForKey(Key key) {
	Node<Key, Value> *tmp = head;
	while (head != NULL) {
		if (tmp->getData()->getKey() == key) {
			return tmp->getData()->getValue();
		}
		tmp = tmp->getNext();
	}
	return 0;
}

template <typename Key, typename Value>
Key SortedDLList<Key, Value>::findKeyForValue(Value value) {
	Node<Key, Value> *tmp = head;
	while (head != NULL) {
		if (tmp->getData()->getValue() == value) {
			return tmp->getData()->getKey();
		}
		tmp = tmp->getNext();
	}
	return 0;
}

template <typename Key, typename Value>
void SortedDLList<Key, Value>::updateKeyForValue(Value value, Key key) {
	Node<Key, Value> *tmp = head;
	while (head != NULL) {
		if (tmp->getData()->getValue() == value) {
			tmp->getData()->setKey(key);
			return;
		}
		tmp = tmp->getNext();
	}
}

template <typename Key, typename Value>
void SortedDLList<Key, Value>::updateValueForKey(Key key, Value value) {
	Node<Key, Value> *tmp = head;
	while (head != NULL) {
		if (tmp->getData()->getKey() == key) {
			tmp->getData()->setValue(value);
			return;
		}
		tmp = tmp->getNext();
	}
}

template <typename Key, typename Value>
bool SortedDLList<Key, Value>::doesKeyExist(Key key) {
	Node<Key, Value> *tmp = head;
	while (head != NULL) {
		if (tmp->getData()->getKey() == key) {
			return 1;
		}
		tmp = tmp->getNext();
	}
	return 0;
}

template <typename Key, typename Value>
bool SortedDLList<Key, Value>::doesValueExist(Value value) {
	Node<Key, Value> *tmp = head;
	while (head != NULL) {
		if (tmp->getData()->getValue() == value) {
			return 1;
		}
		tmp = tmp->getNext();
	}
	return 0;
}

template <typename Key, typename Value>
Node<Key, Value>* SortedDLList<Key, Value>::findFirstNode(Value value){
	Node<Key, Value> *node = head;
	while (node != NULL){
		if (node->getData()->getValue() == value){
			return node;
		}
		node = node->getNext();
	}
	return node;
}

#endif