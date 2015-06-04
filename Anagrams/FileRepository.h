#ifndef FILEREPOSITORY_H
#define FILEREPOSITORY_H

#include <fstream>
#include "repository.h"
#include <iostream>

using namespace std;

class FileRepository : public Repository<string>{
public:
	FileRepository() : Repository<string>() {
		loadEntities();
	}
private:
	void loadEntities();
};

void FileRepository::loadEntities() {
	std::string a;
	int i;

	i = 0;
	ifstream fin("words.txt");
	if (!fin.is_open()) {
		cout << "error" << endl;
	}
	i = 0;
	while (/*fin.good()*/ fin>>a) {
		cout << "Loaded entry: " << i << "\n";
		i++;
		this->store.add(a);
	}
	fin.close();
}


#endif //FILEREPOSITORY_H