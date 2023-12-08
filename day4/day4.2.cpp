#include <cstdlib>
#include <ios>
#include <iostream>
#include <fstream>
#include <string>
#include <vector>

using namespace std;

struct gear {
    int x_pos;
    int y_pos;
    int ratio;
    int nums;
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
    long sum;
    
    my_file >> input; 
    while (my_file >> input) {
        vector<int> winning_nums = vector<int>();


        cout << "winning numbers: ";
        my_file >> input;
        while (input != "|") {
            winning_nums.push_back(stoi(input));
            cout << input << " ";
            my_file >> input;
        }

        cout << endl << endl << "Matches: ";
        int card_val = 0;
        while (my_file >> input && input != "Card") {
            int tmp = stoi(input);
            for (int i = 0; i < winning_nums.size(); i++) {
                if (winning_nums[i] == tmp) {
                    cout << tmp << ", ";
                    if (card_val == 0) {
                        card_val = 1;
                    } else {
                        card_val *= 2;
                    }
                }
            }
        }
        cout << endl << "Card Value: " << card_val << endl << endl;
        sum += card_val;
        

    }


    cout << endl << endl << endl << "Sum part 1: " << sum << endl;

	my_file.close();
	return 0;
}
