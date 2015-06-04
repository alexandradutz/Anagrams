#pragma once
#include "mapADT.h"
#include "DLList.h"
#include "DynV.h"

using namespace std;
#define TABLE_SIZE 222

template <typename Key, typename Value>
class HashTableMap : Map<Key, Value> {
	SortedDLList<Key, Value> lst[TABLE_SIZE];
public:
	int hash_function(string key);

	int hash_value(string key);

	DynVect<Key> keysAndValuesForHash(int has);

	void add(Key key, Value value);

	void updateValueForKey(Key key, Value value);

	Value valueForKey(Key key);

	Key keyForValue(Value value);

	void remove(Key key);

	void removeValue(Value value);

	bool doesKeyExist(Key key);

	bool doesValueExist(Value value);

	DynVect<Key> getKeys();

	DynVect<Value> getValues();

	Node<Key, Value>* getTable(Value value);
};

template <typename Key, typename Value>
int HashTableMap<Key, Value>::hash_function(string key) {
	int sum = 0;
	for (auto k : key) {
		sum += (int)k;
	}
	return sum;
}

template <typename Key, typename Value>
int HashTableMap<Key, Value>::hash_value(string key) {
	return hash_function(key) % TABLE_SIZE;
}

template <typename Key, typename Value>
void HashTableMap<Key, Value>::add(Key key, Value value) {
	Pair<Key, Value> *pair = new Pair<Key, Value>(key, value);
	int hash_int = hash_value(key);
	this->lst[hash_int].addPair(pair);
}

template <typename Key, typename Value>
void HashTableMap<Key, Value>::updateValueForKey(Key key, Value value) {
	long int hash_int = hash_value(key);
	this->lst[hash_int].updateValueForKey(key, value);
}

template <typename Key, typename Value>
Value HashTableMap<Key, Value>::valueForKey(Key key) {
	long int hash_int = hash_value(key);
	return this->lst[hash_int].findValueForKey(key);
}

template <typename Key, typename Value>
Key HashTableMap<Key, Value>::keyForValue(Value value) {
	//not working
	return lst->findKeyForValue(value);
}

template <typename Key, typename Value>
void HashTableMap<Key, Value>::remove(Key key) {
	Value val = this->lst->findValueForKey(key);
	Pair<Key, Value> *p = new Pair<Key, Value>(key, val);
	this->lst->removePair(p);
}

template <typename Key, typename Value>
void HashTableMap<Key, Value>::removeValue(Value value) {
	Key key = this->lst->findKeyForValue(value);
	Pair<Key, Value> *p = new Pair<Key, Value>(key, value);
	this->lst->removePair(p);
}

template <typename Key, typename Value>
bool HashTableMap<Key, Value>::doesKeyExist(Key key) {
	bool ok = this->lst->doesKeyExist(key);
	return ok;
}

template <typename Key, typename Value>
bool HashTableMap<Key, Value>::doesValueExist(Value value) {
	//not working
	bool ok = lst->doesValueExist(value);
	return ok;
}

template <typename Key, typename Value>
DynVect<Key> HashTableMap<Key, Value>::getKeys() {
	return DynVect<Key>();

}

template <typename Key, typename Value>
DynVect<Value> HashTableMap<Key, Value>::getValues() {
	DynVect<Value> new_values = DynVect<Value>();
	//  for(int i = 0; i < keys.getSize(); i++) {
	//    new_values.add(lst->findValueForKey(keys.elementAtIndex(i)));
	//  }
	return new_values;
}

template <typename Key, typename Value>
DynVect<Key> HashTableMap<Key, Value>::keysAndValuesForHash(int hash) {
	//  DynamicVector<Key> values = keys;
	return DynVect<Key>();
}

template <typename Key, typename Value>
Node<Key, Value>* HashTableMap<Key, Value>::getTable(Value value) {
	return lst[hash_value(value)].findFirstNode(value);
}
