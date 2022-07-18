#include <iostream>
using namespace std;

int k, n, ans;
int line[10001];
int maxi = 0;
long long mid, high, low;

int main()
{
	cin >> k >> n;

	for (int i = 0; i < k; i++)
	{
		cin >> line[i];
		if (maxi < line[i]) 
			maxi = line[i];
	}
	low = 1;
	high = maxi;
	ans = 0;

	while (low <= high)
	{
		mid = (low + high) / 2;
		int cnt = 0;
		for (int i = 0; i < k; i++)
			cnt += line[i] / mid;

		if (cnt >= n)
		{
			low = mid + 1;
			if (ans < mid) ans = mid;
		}
		else 
		{
			high = mid - 1;
		}
	}

	cout << ans;
}