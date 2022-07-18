#include <iostream>
#include <vector>
#include <string>
#include <climits>
using namespace std;

int main() {
	vector<vector<string>> board; int row, col;
	vector<vector<string>> seikai1, seikai2;
	cin >> row >> col; string temp;
	vector<int> edit;

	// input 
	for (int i = 0; i < row; i++) {
		vector<string> vec; string line, one;
		cin >> line; // getline(cin, line) 쓰면 안되던데...
		for (int j = 0; j < line.length(); j++) {
			one = line.substr(j, 1);
			vec.push_back(one);
		}
		board.push_back(vec);
	}

	// make answer
	for (int i = 0; i < row; i++) {
		vector<string> vec;
		for (int j = 0; j < col; j++) {
			if ((i + j) % 2 == 1) { vec.push_back("W"); }
			else if ((i + j) % 2 == 0) { vec.push_back("B"); }
		}
		seikai1.push_back(vec);
	}

	for (int i = 0; i < row; i++) {
		vector<string> vec;
		for (int j = 0; j < col; j++) {
			if ((i + j) % 2 == 1) { vec.push_back("B"); }
			else if ((i + j) % 2 == 0) { vec.push_back("W"); }
		}
		seikai2.push_back(vec);
	}
	
	// check by brute-force
	for (int i = 0; i <= row - 8; i++) {
		for (int j = 0; j <= col - 8; j++) {
			// check seikai1 & seikai2
			int count1 = 0; int count2 = 0;
			for (int r = i; r < i + 8; r++) {
				for (int c = j; c < j + 8; c++) {
					if (board[r][c] != seikai1[r][c]) { count1++; }
					if (board[r][c] != seikai2[r][c]) { count2++; }
				}
			}
			edit.push_back(count1);
			edit.push_back(count2);
		}
	}

	// find min value 
	int min = INT_MAX;
	for (int i = 0; i < edit.size(); i++) {
		if (min > edit[i]) { min = edit[i]; }
	}

	cout << min << endl;
	return 0;
}

