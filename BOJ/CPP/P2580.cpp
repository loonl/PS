#include <iostream>
#include <vector>
using namespace std;

int sudoku[9][9];
void solve(int r, int c);

int main() {
	int num; cin.tie(NULL); cin.sync_with_stdio(false); cout.tie(NULL);
	for (int i = 0; i < 9; i++) {
		for (int j = 0; j < 9; j++) {
			cin >> num;
			sudoku[i][j] = num;
		}
	}
	solve(0, 0);
}

void solve(int r, int c) {
	if (r == 9) { // print 
		for (int i = 0; i < 9; i++) {
			for (int j = 0; j < 9; j++) {
				cout << sudoku[i][j] << " ";
			}
			cout << "\n";
		}
		exit(0); 
	}

	if (sudoku[r][c] == 0) { // 빈칸 발견
		for (int i = 1; i <= 9; i++) {
			bool possible = true;

			// 행 체크
			for (int j = 0; j < 9; j++) {
				if (sudoku[r][j] == i) {
					possible = false;
					break;
				}
			}
			
			// 열 체크
			for (int j = 0; j < 9; j++) {
				if (sudoku[j][c] == i) {
					possible = false;
					break;
				}
			}

			// square 체크
			for (int j = 0; j < 3; j++) {
				int group_r = (r / 3) * 3 + j; int group_c = (c / 3) * 3;
				bool a = sudoku[group_r][group_c] == i;
				bool b = sudoku[group_r][group_c+1] == i;
				bool c = sudoku[group_r][group_c+2] == i;
				if (a || b || c) { possible = false; break; }
			}

			if (possible) {
				sudoku[r][c] = i; // 바꿔주고

				// 재귀 돌려주고
				if (c == 8) { solve(r + 1, 0); } 
				else { solve(r, c + 1); }

				sudoku[r][c] = 0; // 원래대로
			}
		}
	}
	else {
		if (c == 8) { solve(r + 1, 0); }
		else { solve(r, c + 1); }
	}
}