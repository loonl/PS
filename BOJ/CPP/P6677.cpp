#include <bits/stdc++.h>
#define FASTI cin.tie(0)->sync_with_stdio(false)
#define endl "\n"
#define P pair<int64_t, int64_t>
using namespace std;
typedef long long int ll;
typedef __int128_t lll;
ll MAX = pow(10, 17);

int main()
{
    FASTI;
    #ifndef ONLINE_JUDGE
    freopen("a.in", "r", stdin);
    #endif // ONLINE_JUDGE
    string result = "";
    while (1) {
        ll rows, cols; cin >> cols >> rows; if (cols == 0 && rows == 0) break;
        vector<vector<set<char>>> assigned(rows + 2, vector<set<char>>(cols + 2, set<char>()));

        assigned[0][0].emplace('+');
        assigned[0][cols +1].emplace('+');
        assigned[rows + 1][0].emplace('+');
        assigned[rows + 1][cols + 1].emplace('+');

        for (ll i = 1; i <= rows; i++) {
            assigned[i][0].emplace('|');
            assigned[i][cols + 1].emplace('|');
        }

        for (ll i = 1; i <= cols; i++) {
            assigned[0][i].emplace('-');
            assigned[rows + 1][i].emplace('-');
        }

        string cmd;
        while (1) {
            cin >> cmd;
            if (cmd == "PRINT")
                break;

            if (cmd == "POINT") {
                ll c, r; cin >> c >> r;
                assigned[r][c].emplace('o');
            }

            if (cmd == "TEXT") {
                ll c, r; string str;
                cin >> c >> r >> str;

                ll temp = min((ll) (c + str.length() - 1), cols);
                for (ll i = c; i <= temp; i++)
                    assigned[r][i].emplace(str[i - c]);
            }

            if (cmd == "LINE") {
                ll stC, stR, edC, edR; cin >> stC >> stR >> edC >> edR;
                if (stC == edC) {
                    if (stR > edR)
                        swap(stR, edR);

                    for (ll i = stR; i <= edR; i++)
                        assigned[i][stC].emplace('|');
                }
                else if (stR == edR) {
                    if (stC > edC)
                        swap(stC, edC);

                    for (ll i = stC; i <= edC; i++)
                        assigned[stR][i].emplace('-');
                }
                else {
                    if (stR > edR) {
                        swap(stR, edR);
                        swap(stC, edC);
                    }

                    if (stC < edC) {
                        for (ll i = stC; i <= edC; i++)
                            assigned[stR + i - stC][i].emplace('\\');
                    }
                    else {
                        for (ll i = stC; i >= edC; i--)
                            assigned[stR + stC - i][i].emplace('/');
                    }
                }
            }
            else if (cmd == "CLEAR") {
                ll stC, stR, edC, edR; cin >> stC >> stR >> edC >> edR;
                if (stC > edC)
                    swap(stC, edC);
                if (stR > edR)
                    swap(stR, edR);
                for (ll i = stR; i <= edR; i++) {
                    for (ll j = stC; j <= edC; j++)
                        assigned[i][j].clear();
                }
            }

        }


        // print
        for (ll i = 0; i <= rows + 1; i++) {
            for (ll j = 0; j <= cols + 1; j++) {
                auto& temp = assigned[i][j];
                if (temp.empty()) {
                    result += " ";
                }
                else if (temp.size() == 1)
                    result += *temp.begin();
                else {
                    if (temp.size() == 2) {
                        if (temp.count('-') == 1 && temp.count('|') == 1)
                            result += "+";
                        else if (temp.count('\\') == 1 && temp.count('/') == 1)
                            result += "x";
                        else
                            result += "*";
                    }
                    else
                        result += "*";
                }
            }
            result += endl;
        }
        result += endl;
    }

    cout << result.substr(0, result.length() - 2);
    return 0;
}
