#include <cstdlib>
#include <iostream>
#include <fstream>
#include <string>

const int MAX_RED = 12;
const int MAX_GREEN = 13;
const int MAX_BLUE = 14;

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

    int sum_part1 = 0;
    int sum_part2 = 0;
    int gameid = 0;
    int game_state = 0;

    int rmax = 0;
    int gmax = 0;
    int bmax = 0;

    while (my_file >> input) {

        cout << input << endl;

        if (input == "Game") {
            // checking the last game for errors (part 1 only)
            if (rmax > MAX_RED  || gmax > MAX_GREEN || bmax > MAX_BLUE) {
                sum_part1 -= gameid;
            }
            int power = rmax * gmax * bmax;
            sum_part2 += power;

            gameid++;
            sum_part1 += gameid;
            my_file >> input;
            rmax = 0;
            gmax = 0;
            bmax = 0;
            continue;
        }

        char* endptr;
        int num = stoi(input);
        my_file >> input;
        char color = input[0];

        switch (color) {
            case 'r':
                if (num > rmax) {
                    rmax = num;
                }
                break;
            case 'g':
                if (num > gmax) {
                    gmax = num;
                }
                break;
            case 'b':
                if (num > bmax) {
                    bmax = num;
                }
                break;
            default:
                break;
        }

    }

    if (rmax > MAX_RED  || gmax > MAX_GREEN || bmax > MAX_BLUE) {
        sum_part1 -= gameid; 
    }
    int power = rmax * gmax * bmax;
    sum_part2 += power;



    cout << "Final Sum of valid game ids: " << sum_part1 << endl;

    cout << "Final Sum of power sets: " << sum_part2 << endl;


	my_file.close();
	return 0;
}
