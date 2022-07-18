#include <iostream>
#include <vector>
#include <cstdlib>
#include <climits>
using namespace std;
int all;
vector<vector<int>> chart;
vector<int> team1;
vector<int> team2;
vector<int> interval;

void back_track(int n, int whatTeam) {
	// return 
	if (n == all && team1.size() == all / 2 && team2.size() == all / 2) {
		int abil1 = 0; int abil2 = 0;

		// add ability for team 1
		for (int i = 0; i < team1.size(); i++) {
			for (int j = 0; j < team1.size(); j++) {
				abil1 += chart[team1[i]][team1[j]];
			}
		}

		// add ability for temam 2
		for (int i = 0; i < team2.size(); i++) {
			for (int j = 0; j < team2.size(); j++) {
				abil2 += chart[team2[i]][team2[j]];
			}
		}

		// add interval between two and return
		int temp = abs(abil1 - abil2);
		interval.push_back(temp); 
		return;
	}

	// back-track to team1
	if (team1.size() < all/2) {
		if (whatTeam == 1) { team1.push_back(n); }
		else if (whatTeam == 2) { team2.push_back(n); }
		back_track(n+1, 1);
		if (whatTeam == 1) { team1.pop_back(); }
		else if (whatTeam == 2) { team2.pop_back(); }
	}

	// back-track to team2
	if (team2.size() < all / 2) {
		if (whatTeam == 1) { team1.push_back(n); }
		else if (whatTeam == 2) { team2.push_back(n); }
		back_track(n+1, 2);
		if (whatTeam == 1) { team1.pop_back(); }
		else if (whatTeam == 2) { team2.pop_back(); }
	}
}

int main()
{
	cin >> all; int a;
	for (int i = 0; i < all; i++) {
		vector<int> temp;
		for (int j = 0; j < all; j++) {
		    cin >> a;
			temp.push_back(a);
		}
		chart.push_back(temp);
	}

	back_track(0, 1);

	int min = INT_MAX;
	for (int i = 0; i < interval.size(); i++) {
		if (interval[i] < min) { min = interval[i]; }
	}
	
	cout << min << "\n";
	return 0;
}

