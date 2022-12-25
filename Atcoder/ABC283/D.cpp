#include <bits/stdc++.h>
#define FASTI cin.tie(0)->sync_with_stdio(false)
#define endl "\n"
#define P pair<int64_t, int64_t>
#define T tuple<int64_t, int64_t, int64_t>
using namespace std;
typedef int64_t ll;
typedef __int128_t lll;
typedef long double ld;
typedef double d;
ll MAX = 1e+17;
ll MOD = 1e9+7;

int main() {
    FASTI;
#ifndef ONLINE_JUDGE
    freopen("a.in", "r", stdin);
#endif // ONLINE_JUDGE
    set<char> sets; stack<char> stacks;
    string str; cin >> str;
    for (ll i = 0; i < str.length(); i++) {
        char cur = str[i];
        if (cur == '(')
            stacks.emplace(cur);
        else if (isalpha(cur)) {
            auto found = sets.find(cur);
            if (found != sets.end()) {
                cout << "No" << endl;
                exit(0);
            }
            else {
                sets.emplace(cur);
                stacks.emplace(cur);
            }
        }
        else if (cur == ')') {
            while (!stacks.empty() && stacks.top() != '(') {
                char temp = stacks.top();
                stacks.pop();

                if (isalpha(temp))
                    sets.erase(temp);
            }

            if (stacks.empty()) {
                cout << "No" << endl;
                exit(0);
            }
            else {
                assert(stacks.top() == '(');
                stacks.pop();
            }
        }
    }
  
    cout << "Yes" << endl;
    return 0;
}