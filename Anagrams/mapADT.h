#ifndef MAP_H_
#define MAP_H_
#include "DynV.h"

template<typename Key, typename Value>
class Map
{
protected:
	int count_;

public:
	virtual void add(Key key, Value value) = 0;

	virtual void updateValueForKey(Key key, Value value) = 0;

	virtual Value valueForKey(Key key) = 0;

	virtual Key keyForValue(Value value) = 0;

	virtual void remove(Key key) = 0;

	virtual bool doesKeyExist(Key key) = 0;

	virtual bool doesValueExist(Value value) = 0;

	virtual DynVect<Key> getKeys() = 0;

	virtual DynVect<Value> getValues() = 0;
};

#endif // MAP_H_