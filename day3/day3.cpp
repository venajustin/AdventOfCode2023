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

    vector<int> part_nums = vector<int>();
    string lines[3] ;
    lines[0] = "";
    lines[1] = "";
    lines[2] = "";

    my_file >> lines[0];
    int len = lines[0].length();
    lines[1] = lines[0];

    int sum = 0;

    vector<gear> possible_gears = vector<gear>();
    int y_loc = 0;

    while (my_file >> lines[0]) {

        cout << "Curr contents: " << endl;
        cout << "            \"" << lines[0] << "\"" << endl;
        cout << "            \"" << lines[1] << "\"" << endl;
        cout << "            \"" << lines[2] << "\"" << endl;
        
        for (int i = 0; i < len; i++) {
            int curr_num = 0;
            int left_pos = i - 1;
            while (lines[1][i] >= '0' && lines[1][i] <= '9') {
                curr_num *= 10;
                curr_num += lines[1][i] - '0';
                i++;
            }
            int right_pos = i;
            
            if (curr_num == 0) {
                continue;
            }

            cout << "num: " << curr_num << " l: " << left_pos << " r: " << right_pos << " ";

            for (int k = 0; k < 3; k++) {
                if (lines[k] == "" ){
                    continue;
                }
                for (int j = left_pos; j <= right_pos; j++) {
                    if (j < 0 || j >= len) {
                        continue;
                    }
                    if ((lines[k][j] < '0' || 
                            lines[k][j] > '9') && 
                            lines[k][j] != '.') {
                        sum += curr_num;
                        cout << "part! ";

                        if (lines[k][j] == '*') {

                            cout << " possible gear x: " << j << " y: " << y_loc -k + 1 << " ";

                            bool modified = false;
                            for (int l = 0; l < possible_gears.size(); l++) {
                                if (possible_gears[l].x_pos == j && possible_gears[l].y_pos == y_loc - k + 1) {
                                    possible_gears[l].ratio *= curr_num;
                                    possible_gears[l].nums++;
                                    modified = true;
                                    cout << "ratio: " << possible_gears[l].ratio << " ";
                                }
                            }
                            if (!modified) {
                                gear new_gear;
                                new_gear.x_pos = j;
                                new_gear.y_pos = y_loc - k + 1;
                                new_gear.nums = 1;
                                new_gear.ratio = curr_num;
                                possible_gears.push_back(new_gear);
                                cout << "new ";
                            }
                        }

                        break;
                    }
                }

            }
            cout << endl;

        }
        cout << endl << endl << endl;

        lines[2] = lines[1];
        lines[1] = lines[0];
        y_loc++;
    }

    lines[0] = "";

    cout << "Curr contents: " << endl;
    cout << "            \"" << lines[0] << "\"" << endl;
    cout << "            \"" << lines[1] << "\"" << endl;
    cout << "            \"" << lines[2] << "\"" << endl;
    
    for (int i = 0; i < len; i++) {
        int curr_num = 0;
        int left_pos = i - 1;
        while (lines[1][i] >= '0' && lines[1][i] <= '9') {
            curr_num *= 10;
            curr_num += lines[1][i] - '0';
            i++;
        }
        int right_pos = i;

        if (curr_num == 0) {
            continue;
        }

        cout << "num: " << curr_num << " l: " << left_pos << " r: " << right_pos << " ";

        for (int k = 0; k < 3; k++) {
            if (lines[k] == "" ){
                continue;
            }
            for (int j = left_pos; j <= right_pos; j++) {
                if (j < 0 || j >= len) {
                    continue;
                }
                if ((lines[k][j] < '0' || 
                        lines[k][j] > '9') && 
                        lines[k][j] != '.') {
                    sum += curr_num;
                    cout << "part! ";

                    if (lines[k][j] == '*') {

                        cout << " possible gear x: " << j << " y: " << y_loc -k + 1 << " ";

                        bool modified = false;
                        for (int l = 0; l < possible_gears.size(); l++) {
                            if (possible_gears[l].x_pos == j && possible_gears[l].y_pos == y_loc - k + 1) {
                                possible_gears[l].ratio *= curr_num;
                                possible_gears[l].nums++;
                                modified = true;
                                cout << "ratio: " << possible_gears[l].ratio << " ";
                            }
                        }
                        if (!modified) {
                            gear new_gear;
                            new_gear.x_pos = j;
                            new_gear.y_pos = y_loc - k + 1;
                            new_gear.nums = 1;
                            new_gear.ratio = curr_num;
                            possible_gears.push_back(new_gear);
                            cout << "new ";
                        }
                    }

                    break;
                }
            }

        }
        cout << endl;

    }
    cout << endl << endl;


    int sum2 = 0;
    for (int i = 0; i < possible_gears.size(); i++) {
        if (possible_gears[i].nums == 2) {
            sum2 += possible_gears[i].ratio;
        }
    }


    cout << "Answer for Part 1: " << sum << endl;
    cout << "Answer for Part 2: " << sum2 << endl;

	my_file.close();
	return 0;
} 
