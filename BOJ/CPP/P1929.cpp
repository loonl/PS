#include <iostream>
using namespace std;

int main() {
    int m, n; cin >> m >> n; bool sosu;
    bool* go = new bool[n+1];
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

    // 에라토스테네스의 체
    for (int i = 2; i <= n; i++) {
        go[i] = true;
    }
    for (int i = 2; i * i <= n; i++)
	{
		if (go[i])
			for (int j = i * i; j <= n; j += i)
			    go[j] = false;
	}
    
    for (int i = m; i <= n; i++) {
        if (go[i])
            cout << i << "\n";
    }
    return 0;
}