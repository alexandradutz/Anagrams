
#ifndef DYNAMICV_H
#define DYNAMICV_H

#include <stdlib.h>
#include <iostream>

template<typename TElement>
class DynVect {
private:
	TElement *elements;
	int size = 0;
	int capacity = 10;

	void resize();
public:
	DynVect();

	~DynVect();

	void add(TElement e);

	void removeAtIndex(int index);

	void updateElement(int index, TElement element);

	TElement elementAtIndex(int index);

	int indexForElement(TElement e);

	int getSize();

	bool isEmpty();

	bool doesContainElement(TElement e);
};

template<typename TElement>
DynVect<TElement>::DynVect() {
	this->elements = new TElement[capacity]();
}

template<typename TElement>
DynVect<TElement>::~DynVect() {
	// delete[] elements;
}

template<typename TElement>
void DynVect<TElement>::add(TElement e) {
	if (size >= capacity) {
		resize();
	}
	size++;
	this->elements[size - 1] = e;
}

template<typename TElement>
void DynVect<TElement>::removeAtIndex(int index) {
	for (int i = index; i < size; i++) {
		elements[i] = elements[i + 1];
	}
	size--;
}

template<typename TElement>
TElement DynVect<TElement>::elementAtIndex(int index) {
	if (NULL != elements)
		return elements[index];
}

template<typename TElement>
int DynVect<TElement>::getSize() {
	return size;
}

template<typename TElement>
bool DynVect<TElement>::isEmpty() {
	return size == 0;
}

template<typename TElement>
bool DynVect<TElement>::doesContainElement(TElement e) {
	for (int i = 0; i < size; i++) {
		if (elements[i] == e) {
			return 1;
		}
	}
	return 0;
}

template<typename TElement>
void DynVect<TElement>::resize() {
	int i = 0;
	TElement *tmp = elements;
	capacity *= 2;
	elements = new TElement[capacity]();
	for (i = 0; i < size; i++) {
		elements[i] = tmp[i];
	}
	delete[] tmp;
}

template<typename TElement>
int DynVect<TElement>::indexForElement(TElement e) {
	for (int i = 0; i < size; i++) {
		if (elements[i] == e) {
			return i;
		}
	}
	return -1;
}

template<typename TElement>
void DynVect<TElement>::updateElement(int index, TElement element) {
	if (index < size) {
		elements[index] = element;
	}
	else {
		//TO DO:
	}
}
#endif 