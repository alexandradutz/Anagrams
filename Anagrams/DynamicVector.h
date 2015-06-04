#pragma once
#include "mapADT.h"
#include <iostream>
#include "DynV.h"

template<typename Key, typename Value>
class DynamicVector : Map<Key, Value> {
private:
	DynVect<Key> keys;
	DynVect<Value> values;
public:
	DynamicVector();

	void add(Key key, Value value);

	void updateValueForKey(Key key, Value value);

	void updateKeyForValue(Value value, Key key);

	Value valueForKey(Key key);

	Key keyForValue(Value value);

	void remove(Key key);

	bool doesKeyExist(Key key);

	bool doesValueExist(Value value);

	DynVect<Key> getKeys();

	DynVect<Value> getValues();

};

template<typename Key, typename Value>
DynamicVector<Key, Value>::DynamicVector() {
	keys = DynVect<Key>();
	values = DynVect<Value>();
}

template<typename Key, typename Value>
void DynamicVector<Key, Value>::add(Key key, Value value) {
	if (!doesKeyExist(key)) {
		keys.add(key);
		values.add(value);
	}
	else {
	}
}

template<typename Key, typename Value>
void DynamicVector<Key, Value>::updateValueForKey(Key key, Value value) {
	if (doesKeyExist(key)) {
		int i = keys.indexForElement(key);
		values.updateElement(i, value);
	}
}

template<typename Key, typename Value>
void DynamicVector<Key, Value>::updateKeyForValue(Value value, Key key) {
	if (doesValueExist(value)) {
		int i = values.indexForElement(value);
		keys.updateElement(i, key);
	}
}

template<typename Key, typename Value>
Value DynamicVector<Key, Value>::valueForKey(Key key) {
	int i;
	i = keys.indexForElement(key);
	return values.elementAtIndex(i);
}

template<typename Key, typename Value>
Key DynamicVector<Key, Value>::keyForValue(Value value) {
	int i;
	i = values.indexForElement(value);
	return keys.elementAtIndex(i);
}

template<typename Key, typename Value>
void DynamicVector<Key, Value>::remove(Key key) {
	if (keys.doesContainElement(key)) {
		int i = keys.indexForElement(key);
		keys.removeAtIndex(i);
		values.removeAtIndex(i);
	}
	else {
	}
}


template<typename Key, typename Value>
bool DynamicVector<Key, Value>::doesKeyExist(Key key) {
	return keys.doesContainElement(key);
}

template<typename Key, typename Value>
bool DynamicVector<Key, Value>::doesValueExist(Value value) {
	return values.doesContainElement(value);
}

template<typename Key, typename Value>
DynVect<Key> DynamicVector<Key, Value>::getKeys() {
	return keys;
}

template<typename Key, typename Value>
DynVect<Value> DynamicVector<Key, Value>::getValues() {
	return values;
}