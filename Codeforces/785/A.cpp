#include <iostream>
#include <string>
#define endl '\n'
using namespace std;

int max(int a, int b)
{
	if (a < b) return b;
	return a;
}

int main()
{
	cin.tie(0)->sync_with_stdio(false);
	int tc; cin >> tc;
	while (tc--)
	{
		string s; cin >> s;
		int len = s.length();

		if (len == 1) // Bob earns all
		{
			cout << "Bob " << (int)s[0] - 96 << endl;
		}
		else
		{
			if (len % 2 == 0) // Alice earns all
			{
				int value = 0;
				for (int i = 0; i < len; i++)
				{
					value += (int) s[i] - 96;
				}

				cout << "Alice " << value << endl;
			}
			else // if len % 2  == 1
			{
				int same = 0; int val1, val2;
				for (int i = 1; i < len - 1; i++)
				{
					same += (int)s[i] - 96;
				}
				val1 = same + ((int)s[0] - 96) - ((int)s[len - 1] - 96);
				val2 = same + ((int)s[len - 1] - 96) - ((int)s[0] - 96);

				cout << "Alice " << max(val1, val2) << endl;
			}
		}
	}
	return 0;
}