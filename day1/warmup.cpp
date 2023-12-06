#include <iostream>
#include <fstream>


using namespace std;

const string written_nums[] = {
	"zero",
	"one",
	"two",
	"three",
	"four",
	"five",
	"six",
	"seven",
	"eight",
	"nine"
};

int main( int argc, char *argv[]) {
	
	if (argc != 2 ) {
		cout << "Incorrect Usage, please specify filename for input" << endl;
		return 1;
	}
	
	fstream my_file;
	my_file.open(argv[1], ios::in);
	if (!my_file) {
		cout << "File could not be found!" << endl;
		return 1;
	}
	
	
	string input;
	
	int floor = 0;
	int enterpos = 0;
	
	while (my_file >> input) {
		
		int len = input.length();
		
		for (int i = 0; i < len; i++) {
			floor += (input[i] == '(') ? 1 : -1;
			if (floor < 0) {
				if (enterpos == 0) {
					enterpos = i + 1;
				}
			}
		}
		
	}
	
	cout << "Floor: " << floor << endl;
	cout << "Enter Basement Pos: " << enterpos << endl;
	
	my_file.close();
	return 0;
}