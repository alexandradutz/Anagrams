#include "ui.h"
#include "controller.h"
#include "DynV.h"

using namespace std;

Console::~Console() {

};

void Console::options() {
	cout << "Menu\n____\n";
	cout << "1. Add word" << endl;
	cout << "2. Find anagrams (using Rep - Dynamic Vector)" << endl;
	cout << "3. Find Anagrams (using Rep - Hash Table)" << endl;
	cout << "0. Exit" << endl;
}

void Console::printLine()
{
	cout << "______________________________________________________ " << endl;

}

DynVect<string> Console::anagramsUsingHash(string word)
{
	return ctrl->anagramsForWordHash(word);
}

DynVect<string> Console::anagramsUsingDynamicVector(string word)
{
	return ctrl->anagramsForWordDynVect(word);
}

void Console::printResult(DynVect<string> elements, string word)
{
	if (elements.getSize() != 0)
	{
		cout << "Anagrams for the word " << word << endl;
		for (int i = 0; i < elements.getSize(); i++) {
			cout << elements.elementAtIndex(i) << endl;
		}
		printLine();
	}
	else
	{
		cout << "Could not find any anagrams..." << endl;
		printLine();
	}
}

void Console::run() {
	int o;
	string word;

	while (true) {
		DynVect<string> elements;
		options();
		cout << "Option: ";
		cin >> o;
		printLine();
		switch (o) {
		case 0:
			return;
			break;
		case 1:
			cout << "Your word: " << endl;
			cin >> word;
			printLine();
			break;
		case 2:
			elements = anagramsUsingDynamicVector(word);
			printResult(elements, word);
			break;
		case 3:
			elements = anagramsUsingHash(word);
			printResult(elements, word);
			break;
		default:
			break;
		}

	}
}