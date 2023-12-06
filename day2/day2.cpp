#include <iostream>
#include <fstream>


using namespace std;


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
	
	int r = 12;
	int g = 13;
	int b = 14;
	
	int rmax = 0;
	int gmax = 0;
	int bmax = 0;
	
	int gameid = 0;
	
	int sum = 0;
	
	string temp;
	
	
	cin >> input;
	while (!my_file.eof()) {
		
		if ( input != "Game" ) {
			cout << "error" << endl;
		}
		
		
		cin >> temp;
		gameid = 0;
		for (int i = 0; i < temp.length() - 1; i++) {
			gameid *= 10;
			gameid += temp[i];
		}
		
		int rmax = 0;
		int gmax = 0;
		int bmax = 0;
	
		input = "," ;
		while (input[input.length()] == ',' || input[input.length()] == ';') {
		
			int numin;
			
			cin >> numin;
			cout << numin;
			cin >> input;
			cout << " " << input << endl;
			
			char firstchar = input[0];
			
			switch (firstchar) {
				case 'r':
					if (numin > rmax) {
						rmax = numin;
					}
					break;
				case 'g':
					if (numin > gmax) {
						gmax = numin;
					}
					break;
				case 'b':
					if (numin > bmax) {
						bmax = numin;
					}
					break;
				default:
					return -1;
					break;
			}
		}
		
		cout << "Game " << gameid << ": " << "rmax: " << rmax << " gmax: " << gmax << " bmax: " << bmax << endl;
		if (rmax >= r && gmax >= g && bmax >= b) {
			sum += gameid;
			cout << "Game accepted" << endl;
		}
		
	}
	
	if (rmax >= r && gmax >= g && bmax >= b) {
		sum += gameid;
	}
	
	
	my_file.close();
	return 0;
}