#include <iostream>
#include <vector>
#define endl '\n'
using namespace std;
int lotto[6];
vector<int> vec;
int n;

void recur(int idx, int picked)
{
	if (picked == 6)
	{
		for (int i = 0; i < 6; i++)
		{
			cout << lotto[i] << " ";
		}
		cout << endl;
		return;
	}

	for (int i = idx; i < n; i++)
	{
		lotto[picked] = vec[i];
		recur(i + 1, picked + 1);
	}
}

int main()
{
	cin.tie(0)->sync_with_stdio(false);
	while (true)
	{
		cin >> n;
		if (n == 0)
			break;
		
		vec.clear();
		vec.assign(n, 0);

		for (int i = 0; i < n; i++)
		{
			cin >> vec[i];
		}

		recur(0, 0);
		cout << endl;
	}

	return 0;
}