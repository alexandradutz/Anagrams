
#ifndef CONSOLE_H
#define CONSOLE_H


#include "controller.h"

class Console {
	AnagramController *ctrl;

public:
	Console(AnagramController* ctrl) { this->ctrl = ctrl; };
	~Console();
	void options();
	void printLine();
	DynVect<string> anagramsUsingHash(string word);
	DynVect<string> anagramsUsingDynamicVector(string word);
	void printResult(DynVect<string>, string);

	void run();
};

#endif //CONSOLE_H