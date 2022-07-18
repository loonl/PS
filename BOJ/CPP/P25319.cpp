#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <map>
#include <queue>
#define endl '\n'
using namespace std;
typedef long long ll;

int main()
{
	cin.tie(0)->sync_with_stdio(false);
	int n, m, len; cin >> n >> m >> len;
	map<char, int> alphas;
	vector<vector<char>> MAP(n, vector<char>(m)); // 맵
	//vector<vector<bool>> zoop(n, vector<bool>(m, false)); // 주운 곳 체크 (visited 대신)
	map<char, queue<pair<int, int>>> LOC; // 알파벳별 좌표 넣어두는 곳
	vector<char> vec;

	// map 초기세팅
	for (int i = 97; i <= 122; i++)
	{
		alphas[(char)i] = 0;
		LOC[(char)i] = queue<pair<int, int>>();
	}

	// 맵 입력받기
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			cin >> MAP[i][j];
			alphas[MAP[i][j]]++;
			LOC[MAP[i][j]].emplace(make_pair(i, j));
		}
	}

	// 닉넴 입력받기
	map<char, int> need; char t1;
	string str;

	cin >> str;
	for (int i = 0; i < len; i++)
	{
		t1 = str[i];
		need[t1]++;
		vec.emplace_back(t1);
	}

	// 횟수 구하기
	int c, l = 0; string cmd = "";
	c = alphas[need.begin()->first] / need[need.begin()->first];
	for (auto it = need.begin(); it != need.end(); it++)
	{
		c = min(alphas[it->first] / need[it->first], c);
	}

	// 줍기
	int tgIDX = 0, rf = 0; // 강화한 횟수
	int curR = 0, curC = 0;
	while (rf < c) // true
	{
		char tgAlpha = vec[tgIDX];
		auto [tgR, tgC] = LOC[tgAlpha].front();
		LOC[tgAlpha].pop();
		tgIDX++;

		if (tgIDX == len)
		{
			tgIDX = 0;
			rf++;
		}

		// l 갱신
		l += (abs(tgR - curR) + abs(tgC - curC));

		// cmd 갱신
		if (tgR > curR)
		{
			for (int i = 0; i < tgR - curR; i++)
			{
				cmd += "D";
			}
		}
		else
		{
			for (int i = 0; i < curR - tgR; i++)
			{
				cmd += "U";
			}
		}

		if (tgC > curC)
		{
			for (int i = 0; i < tgC - curC; i++)
			{
				cmd += "R";
			}
		}
		else
		{
			for (int i = 0; i < curC - tgC; i++)
			{
				cmd += "L";
			}
		}

		// 줍기
		l++;
		cmd += "P";
		
		curR = tgR, curC = tgC;
	}

	// 끝으로 이동하기
	int tgR, tgC; tgR = n - 1, tgC = m - 1;

	// 걍 복붙
	// l 갱신
	l += (abs(tgR - curR) + abs(tgC - curC));

	// cmd 갱신
	if (tgR > curR)
	{
		for (int i = 0; i < tgR - curR; i++)
		{
			cmd += "D";
		}
	}
	else
	{
		for (int i = 0; i < curR - tgR; i++)
		{
			cmd += "U";
		}
	}

	if (tgC > curC)
	{
		for (int i = 0; i < tgC - curC; i++)
		{
			cmd += "R";
		}
	}
	else
	{
		for (int i = 0; i < curC - tgC; i++)
		{
			cmd += "L";
		}
	}

	// print 
	cout << c << " " << l << endl;
	cout << cmd << endl;
	return 0;
}