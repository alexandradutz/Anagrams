
#ifndef ABSTRACTREPOSITOY_H
#define ABSTRACTREPOSITOY_H

#include "DynV.h"

template<typename Entity>
class AbstractRepository {
public:
	virtual void save(Entity e) = 0;
	virtual void remove(int id) = 0;
	virtual DynVect<Entity> getAll() = 0;
	virtual int size() = 0;
	virtual ~AbstractRepository() {
	}
};
#endif //ABSTRACTREPOSITOY_H