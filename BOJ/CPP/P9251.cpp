#include <iostream>
#include <string>
#include <vector>
#define endl '\n'
using namespace std;

int max(int a, int b)
{
	if (a > b)
		return a;
	return b;
}

int main()
{
	cin.tie(0)->sync_with_stdio(false);
	string s1, s2; cin >> s1 >> s2;
	int len1, len2;
	len1 = s1.length(); len2 = s2.length();
	if (len1 > len2)
	{
		string temp = s1;
		s1 = s2;
		s2 = temp;
		len1 = s1.length(); len2 = s2.length();
	}

	// 밑에 가면 못걸러서 따로
	if (len2 == 1)
	{
		int count = 0;
		for (int i = 0; i < len1; i++)
		{
			if (s2[0] == s1[i])
			{
				count++;
				break;
			}
		}

		cout << count << endl;
		exit(0);
	}

	vector<vector<int>> dp(len1, vector<int>(len2, 0));

	// set first element
	if (s1[0] == s2[0])
		dp[0][0] = 1;
	else
		dp[0][0] = 0;

	for (int i = 1; i < len2; i++)
	{
		if (s1[0] == s2[i])
			dp[0][i] = 1;
		else
			dp[0][i] = dp[0][i - 1];
	}

	// dp
	for (int i = 1; i < len1; i++)
	{
		if (s1[i] == s2[0])
			dp[i][0] = 1;
		else
			dp[i][0] = dp[i - 1][0];

		for (int j = 1; j < len2; j++)
		{
			if (s1[i] == s2[j])
				dp[i][j] = dp[i - 1][j - 1] + 1;
			else
				dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
		}
	}

	cout << dp[len1 - 1][len2 - 1] << endl;
	return 0;
}