#ifndef ANAGRAMCONTROLLER_H
#define ANAGRAMCONTROLLER_H


#include "hashTable.h"
#include "DynV.h"
#include "AbstractRepository.h"
#include "DynamicVector.h"

using namespace std;

class AnagramController {
	HashTableMap<string, string> map;
	DynamicVector<int, string> mapDVect;
	AbstractRepository<string> *repo;

public:
	AnagramController(AbstractRepository<string> *repo) { this->repo = repo; };
	DynVect<string> anagramsForWordHash(string word);
	DynVect<string> anagramsForWordDynVect(string word);
	string sortWord(string word);
};


#endif //ANAGRAMCONTROLLER_H