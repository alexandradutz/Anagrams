
#ifndef SDAProject_testSSLL_h
#define SDAProject_testSSLL_h

#include <assert.h>
#include <string>
#include "DLList.h"

using namespace std;

void test_insert() {
	SortedDLList<string, string> lst = SortedDLList<string, string>();
	Pair<string, string> *p2 = new Pair<string, string>("ana2", "are1");
	Pair<string, string> *p1 = new Pair<string, string>("ana", "are");
	Pair<string, string> *p3 = new Pair<string, string>("ana3", "are2");
	lst.addPair(p1);
	lst.addPair(p2);
	lst.addPair(p3);
	assert("are" == lst.findValueForKey("ana"));
	assert("are1" == lst.findValueForKey("ana2"));
	assert("are2" == lst.findValueForKey("ana3"));
}

void test_sorteddll(){
	test_insert();
}


#endif