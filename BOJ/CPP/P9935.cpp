#include <bits/stdc++.h>
#define FASTIO cin.tie(0)->sync_with_stdio(false)
#define endl "\n"
#define P pair<int64_t, int64_t>
using namespace std;
typedef int64_t ll;
typedef __int128_t lll;
ll MAX = pow(10, 17);

int main()
{
    FASTIO;
    #ifndef ONLINE_JUDGE
    freopen("a.in", "r", stdin);
    #endif // ONLINE_JUDGE

    string str; cin >> str;
    string bomb; cin >> bomb;
    string ans = "";
    for (ll i = 0; i < str.length(); i++) {
        ans += str[i];
        if (ans.back() == bomb.back()) {
            bool bombyes = true;

            if (ans.length() < bomb.length())
                continue;

            if (ans.substr(ans.size() - bomb.size(), bomb.size()) != bomb)
                bombyes = false;

            if (bombyes) {
                for (int j = 0; j < bomb.size(); j++)
                    ans.pop_back();
            }
        }
    }

    if (ans == "")
        cout << "FRULA" << endl;
    else
        cout << ans << endl;

    return 0;
}
