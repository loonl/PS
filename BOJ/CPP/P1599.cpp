#include <bits/stdc++.h>
#define FASTI cin.tie(0)->sync_with_stdio(false)
#define endl "\n"
#define P pair<int64_t, int64_t>
#define T tuple<int64_t, int64_t, int64_t>
using namespace std;
typedef int64_t ll;
typedef __int128_t lll;
typedef long double ld;
ll MAX = 1e+17;
ll MOD = 1e9+7;

int main() {
    FASTI;
#ifndef ONLINE_JUDGE
    freopen("a.in", "r", stdin);
#endif // ONLINE_JUDGE

    ll n; cin >> n; string str;
    vector<vector<string>> vec;
    map<string, ll> dic;
    dic["a"] = 1, dic["b"] = 2, dic["k"] = 3, dic["d"] = 4, dic["e"] = 5, dic["g"] = 6, dic["h"] = 7, dic["i"] = 8, dic["l"] = 9, dic["m"] = 10, dic["n"] = 11, dic["ng"] = 12, dic["o"] = 13,
    dic["p"] = 14, dic["r"] = 15, dic["s"] = 16, dic["t"] = 17, dic["u"] = 18, dic["w"] = 19, dic["y"] = 20;

    for (ll i = 0; i < n; i++) {
        cin >> str;
        vector<string> splits;

        string temp = "";
        for (ll j = 0; j < str.length(); j++) {
            temp += str[j];
            if (temp == "n")
                continue;
            else if (temp.length() == 1 || temp == "ng") {
                splits.emplace_back(temp);
                temp = "";
            }
            else if (temp.length() == 2 && temp != "nn") {
                splits.emplace_back("n");
                splits.emplace_back(temp.substr(1, 1));
                temp = "";
            }
            else if (temp == "nn") {
                splits.emplace_back("n");
                temp = "n";
            }
        }

        if (temp == "n")
            splits.emplace_back(temp);

        vec.emplace_back(splits);
    }
    function<bool(vector<string>&, vector<string>&)> custom_sort = [&](vector<string>& a, vector<string>& b) -> bool {
        for (ll i = 0; i < min(a.size(), b.size()); i++) {
            if (dic[a[i]] == dic[b[i]])
                continue;
            else
                return dic[a[i]] < dic[b[i]];
        }

        return a.size() < b.size();
    };

    sort(vec.begin(), vec.end(), custom_sort);

    for (ll i = 0; i < vec.size(); i++) {
        for (auto ele: vec[i])
            cout << ele;
        cout << endl;
    }
    return 0;
}