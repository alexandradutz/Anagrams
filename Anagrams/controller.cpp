#include "controller.h"
#include <algorithm>
#include "DynamicVector.h"

DynVect<string> AnagramController::anagramsForWordHash(string word) {
	for (int i = 0; i<repo->getAll().getSize(); i++){
		string key = repo->getAll().elementAtIndex(i);
		map.add(key, sortWord(key));
	}

	word = sortWord(word);
	DynVect<string> elements = DynVect<string>();
	Node<string, string> *first = map.getTable(word);
	while (first != NULL && first->getData()->getValue() == word) {
		elements.add(first->getData()->getKey());
		first = first->getNext();
	}
	return elements;
}

string AnagramController::sortWord(string word){
	string smth = word;
	std::sort(smth.begin(), smth.end());
	return smth;
}

DynVect<string> AnagramController::anagramsForWordDynVect(string word)
{
	string val;
	DynVect<string> all = repo->getAll();
	for (int i = 0; i < all.getSize(); i++)
	{
		val = all.elementAtIndex(i);
		mapDVect.add(i, val);
	}
	
	DynVect<string> elements = DynVect<string>();
	string aux;
	for (int i = 0; i < mapDVect.getKeys().getSize(); i++)
	{
		aux = mapDVect.valueForKey(i);
		if (sortWord(word) == sortWord(aux))
		{
			cout << mapDVect.valueForKey(i) << endl;
			elements.add(aux);
		}
	}
	return elements;
}

