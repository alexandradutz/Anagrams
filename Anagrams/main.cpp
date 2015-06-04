#include <string>
#include "testMapDVector.h"
#include "controller.h"
#include "FileRepository.h"
#include "testDLList.h"
#include "ui.h"

using namespace std;
int main(){
	test_all();
	test_sorteddll();
	FileRepository *repo = new FileRepository();
	AnagramController *ctrl = new AnagramController(repo);
	Console *console = new Console(ctrl);
	console->run();
	return 0;
}