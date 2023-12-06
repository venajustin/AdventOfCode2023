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
	
	int sum = 0;
	
	while (my_file >> input) {
		
		int len = input.length();
		
		int first_digit;
		int second_digit;
		
		first_digit = -1;
		second_digit = -1;
		
		string possible_num;
		
		cout << input << endl;
		
		for ( int i = 0; i < len && first_digit == -1; i++ ) {
			if (input[i] >= 0x30 && input[i] <= 0x39) {
				first_digit = static_cast<int>(input[i] - 0x30);
			}
			
			cout << input.substr(0, i + 1) << endl;
			
			for (int j = 0; j < 10; j++) {
				
				int num_loc = input.substr(0, i + 1).find(written_nums[j]);
				if ( num_loc != string::npos ) {
					cout << "num_loc: " << num_loc << " j: " << j << endl;
					first_digit = j;
				}
			}
			
		}
		
		for (int i = len - 1; i >= 0 && second_digit == -1; i-- ) {
			if (input[i] >= 0x30 && input[i] <= 0x39) {
				second_digit = static_cast<int>(input[i] - 0x30);
				break;
			}
			
			cout << input.substr(i, len - i) << endl;
			
			for (int j = 0; j < 10; j++) {
				int num_loc = input.substr(i, len - i).find(written_nums[j]);
				if ( num_loc != string::npos ) {
					cout << "num_loc: " << num_loc << " j: " << j << endl;
					second_digit = j;
					break;
				}
			}
			
		}
		

		
		if (first_digit == -1 || second_digit == -1) {
			cout << "input error" << endl;
			return 1;
		}
		
		int calibration_value = first_digit * 10;
		calibration_value += second_digit;
		cout << calibration_value << endl << endl;
		sum += calibration_value;
	}
	
	cout << "Total sum: " << sum << endl;
	
	my_file.close();
	return 0;
}