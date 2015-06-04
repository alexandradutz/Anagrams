
#ifndef TESTDynamicVector_H
#define TESTDynamicVector_H
#include <assert.h>
#include "DynamicVector.h"

using namespace std;

void test_add() {
	DynamicVector<int, string> map = DynamicVector<int, string>();
	map.add(1, "ana");
	map.add(2, "una");
	map.add(3, "yna");
	map.add(4, "tna");
	assert(map.getKeys().getSize() == 4);
}
//void add(Key key, Value value);

void test_updateValueForKey() {
	DynamicVector<int, string> map = DynamicVector<int, string>();
	map.add(1, "ana");
	map.add(2, "una");
	map.add(3, "yna");
	map.add(4, "tna");
	map.updateValueForKey(2, "iii");

	assert(map.valueForKey(2) == "iii");
}
//void updateValueForKey(Key key, Value value);

void test_UpdateKeyForValue() {
	DynamicVector<int, string> map = DynamicVector<int, string>();
	map.add(1, "ana");
	map.add(2, "una");
	map.add(3, "yna");
	map.add(4, "tna");
	map.updateKeyForValue("una", 8);
	assert(map.valueForKey(8) == "una");
}
//void updateKeyForValue(Value value, Key key);

void test_valueForKey() {
	DynamicVector<int, string> map = DynamicVector<int, string>();
	map.add(1, "ana");
	map.add(2, "una");
	map.add(3, "yna");
	map.add(4, "tna");
	assert(map.valueForKey(2) == "una");
}
//Value valueForKey(Key key);

void test_keyForValue() {
	DynamicVector<int, string> map = DynamicVector<int, string>();
	map.add(1, "ana");
	map.add(2, "una");
	map.add(3, "yna");
	map.add(4, "tna");
	assert(map.keyForValue("ana") == 1);
}
//Key keyForValue(Value value);

void test_remove() {
	DynamicVector<int, string> map = DynamicVector<int, string>();
	map.add(1, "ana");
	map.add(2, "una");
	map.add(3, "yna");
	map.add(4, "tna");
	map.remove(3);
	assert(map.getKeys().getSize() == 3);
}
//void removeKey(Key key);


void test_doesKeyExist() {
	DynamicVector<int, string> map = DynamicVector<int, string>();
	map.add(1, "ana");
	map.add(2, "una");
	map.add(3, "yna");
	map.add(4, "tna");
	assert(map.doesKeyExist(3));
}
//bool doesKeyExist(Key key);

void test_doesValueExist() {
	DynamicVector<int, string> map = DynamicVector<int, string>();
	map.add(1, "ana");
	map.add(2, "una");
	map.add(3, "yna");
	map.add(4, "tna");
	assert(map.doesValueExist("ana"));
}
//bool doesValueExist(Value value);

void test_getKeys() {
	DynamicVector<int, string> map = DynamicVector<int, string>();
	map.add(1, "ana");
	map.add(2, "una");
	map.add(3, "yna");
	map.add(4, "tna");
	assert(map.getKeys().elementAtIndex(3));
}
//DynamicVector<Key> getKeys();

void test_getValues() {
	DynamicVector<int, string> map = DynamicVector<int, string>();
	map.add(1, "ana");
	map.add(2, "una");
	map.add(3, "yna");
	map.add(4, "tna");
	assert(map.getValues().getSize() == 4);
}
//DynamicVector<Value> getValues();

void test_all() {
	test_add();
	test_doesKeyExist();
	test_doesValueExist();
	test_getKeys();
	test_getValues();
	test_remove();
	test_updateValueForKey();
	test_UpdateKeyForValue();
	test_keyForValue();
	test_valueForKey();
}

#endif 