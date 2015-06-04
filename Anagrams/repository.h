#ifndef REPOSITORY_H
#define REPOSITORY_H

#include <stdio.h>
#include <sstream>
#include "AbstractRepository.h"

template <typename T>
class Repository : public AbstractRepository<T> {
protected:
	DynVect<T> store;
public:
	Repository();
	~Repository();

	virtual void save(T e);
	virtual void remove(int id);
	virtual DynVect<T> getAll();
	virtual int size();
	virtual T findById(int id);
};

/* 
* Initializes repository
*/
template <typename T>
Repository<T>::Repository() {
	store = DynVect<T>();
}

/* 
* Destroy repository
*/
template <typename T>
Repository<T>::~Repository() {
	//  delete this;
}

/* Get all the elemts
* returns: a vector with all the elements
*/
template <typename T>
DynVect<T> Repository<T>::getAll() {
	return this->store;
}

template <typename T>
void Repository<T>::save(T p) {
	/* Save a element
	param: p - add a element of type T to the repository
	*/
	store.add(p);
}

template <typename T>
void Repository<T>::remove(int id) {
	/* Remove element at position
	param: id - position from where to remove an element
	*/
	store.removeAtIndex(id);
}

template <typename T>
T Repository<T>::findById(int id) {
	/* Find element at position
	param: id - position of the element
	returns: element at the position id
	*/
	return store.elementAtIndex(id);
}

template <class T>
int Repository<T>::size() {
	/* The size of the Repository
	returns: the size of the repository
	*/
	return store.getSize();
}

#endif //REPOSITORY_H