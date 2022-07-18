#include <iostream>
#include <vector>
#define endl '\n'
using namespace std;

double max(double a, double b)
{
	if (a > b)
		return a;
	return b;
}

int main()
{
	cin.tie(0)->sync_with_stdio(false);
	cout << fixed;
	cout.precision(3);
	int n; cin >> n;
	vector<double> arr(n + 1, 0);
	vector<double> dp(n + 1, 0);
	for (int i = 1; i <= n; i++)
	{
		cin >> arr[i];
		dp[i] = arr[i];
	}

	for (int i = 2; i <= n; i++)
	{
		dp[i] = max(dp[i], dp[i - 1] * arr[i]);
	}

	double maxval = 0;
	for (int i = 1; i <= n; i++)
	{
		if (maxval < dp[i])
			maxval = dp[i];
	}

	cout << maxval << endl;
	return 0;
}