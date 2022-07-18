#include <iostream>
#include <cmath>
#include <vector>
using namespace std;
int main()
{
    cin.tie(NULL); ios::sync_with_stdio(false); cout.tie(NULL);
    // 에라토스테네스의 체
    vector<int> sosus; bool* go = new bool[10001];
    for (int i = 2; i < 10000; i++) {
        go[i] = true;
    }
    for (int i = 2; i < 10000; i++) {
        if (go[i])
            for (int j = i * i; j <= 10000; j += i)
                go[j] = false;
    }
    for (int i = 2; i < 10000; i++) {
        if (go[i])
            sosus.push_back(i);
    }

    // 골드바흐 파티션 
    int n; cin >> n; int ans1, ans2;
    for (int i = 0; i < n; i++) {
        int a; cin >> a; int cha = 10001;
        for (int j = 0; j < sosus.size(); j++) {
            for (int k = j; k < sosus.size(); k++) {
                if (a == sosus[j] + sosus[k]) { 
                    if (cha > abs(sosus[j] - sosus[k])) { cha = abs(sosus[j] - sosus[k]); ans1 = sosus[j]; ans2 = sosus[k]; } break; 
                }
            }
        }

        cout << ans1 << " " << ans2 << "\n";
    }
    return 0;
}