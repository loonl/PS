#include <bits/stdc++.h>
#define FASTI cin.tie(0)->sync_with_stdio(false)
#define endl "\n"
#define P pair<int64_t, int64_t>
#define T tuple<int64_t, int64_t, int64_t>
using namespace std;
typedef int64_t ll;
typedef __int128_t lll;
ll MAX = 1e+17;
ll MOD = 1e+9 + 7;

int main()
{
    FASTI;
#ifndef ONLINE_JUDGE
    freopen("a.in", "r", stdin);
#endif // ONLINE_JUDGE

    string str; cin >> str; bool hasUpper = false, hasUnderline = false, isJava = true, isError = false;
    for (ll i = 0; i < str.length(); i++) {
        if (str[i] == '_') {
            hasUnderline = true;
            if (i == 0 || i == str.length() - 1) {
                isError = true;
                break;
            }

            if (str[i - 1] == '_') {
                isError = true;
                break;
            }
        }

        if (isupper(str[i])) {
            hasUpper = true;
            if (i == 0) {
                isError = true;
                break;
            }
        }
    }

    if (hasUnderline && hasUpper)
        isError = true;
    else if (hasUnderline)
        isJava = false;
    else if (hasUpper)
        isJava = true;

    if (isError) {
        cout << "Error!" << endl;
        exit(0);
    }

    string ans = "";
    if (isJava) {
        vector<string> words;
        string temp = "";
        for (ll i = 0; i < str.length(); i++) {
            if (isupper(str[i])) {
                words.emplace_back(temp);
                temp = "";
                temp.push_back(tolower(str[i]));
            }
            else
                temp.push_back(str[i]);

            if (i == str.length() - 1)
                words.emplace_back(temp);
        }

        ans += words[0];
        for (ll i = 1; i < words.size(); i++)
            ans += "_" + words[i];
    }
    else {
        istringstream sstream(str);
        vector<string> splits; string buf;
        while (getline(sstream, buf, '_'))
            splits.emplace_back(buf);

        ans += splits[0];
        for (ll i = 1; i < splits.size(); i++) {
            ans += toupper(splits[i][0]);
            for (ll j = 1; j < splits[i].length(); j++)
                ans.push_back(splits[i][j]);
        }
    }

    cout << ans << endl;
    return 0;
}
