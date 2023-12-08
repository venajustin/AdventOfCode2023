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

int rec_card_compute(int card_pos, vector<int>& card_nums, vector<int>& memo);

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
    long sum = 0;
    
    vector<int> card_values = vector<int>();

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
        card_values.push_back(card_val);
        
    }



    cout << endl << endl << endl << "Sum part 1: " << sum << endl;

    vector<int> memo = vector<int>();
    long res = rec_card_compute(0, card_values, memo);
    cout << endl << "Sum part 2: " << res << endl;
	my_file.close();
	return 0;
}


int rec_card_compute(int card_pos, vector<int>& card_nums, vector<int>& memo) {
    if (card_pos > card_nums.size()) {
        return 0;
    }
    if (memo[card_pos] != 0) {
        return memo[card_pos];
    }

    int sum = 1;
    for (int i = 1; i <= card_nums[card_pos]; i++) {
        sum += rec_card_compute(card_pos + i, card_nums, memo);
    }
    cout << sum << " ";
    memo[card_pos] = sum;
    return sum;

}
