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

    map<string, ll> pr;
    map<ll, string> rom;
    pr["I"] = 1, pr["V"] = 5, pr["X"] = 10, pr["L"] = 50, pr["C"] = 100, pr["D"] = 500, pr["M"] = 1000,
        pr["IV"] = 4,pr["IX"] = 9, pr["XL"] = 40, pr["XC"] = 90, pr["CD"] = 400, pr["CM"] = 900;

    for (auto it = pr.begin(); it != pr.end(); it++)
        rom[it->second] = it->first;

    vector<string> two = {"IV", "IX", "XL", "XC", "CD", "CM"};

    function<bool(string&)> istwo = [&](string& string1) -> bool {
        for (ll i = 0; i < two.size(); i++) {
            if (string1 == two[i])
                return true;
        }
        return false;
    };

    string str1, str2; cin >> str1 >> str2;

    ll num1 = 0, num2 = 0;

    // num1
    ll ptr1 = 1, ptr2 = 1;
    while (ptr1 < str1.length()) {
        auto str = str1.substr(ptr1 - 1, 2);
        if (istwo(str)) {
            ptr1 += 2;
            num1 += pr[str];
        }
        else {
            ptr1++;
            num1 += pr[str.substr(0, 1)];
        }
    }
    if (ptr1 == str1.length())
        num1 += pr[str1.substr(str1.length() - 1, 1)];


    // num2
    while (ptr2 < str2.length()) {
        auto str = str2.substr(ptr2 - 1, 2);
        if (istwo(str)) {
            ptr2 += 2;
            num2 += pr[str];
        }
        else {
            ptr2++;
            num2 += pr[str.substr(0, 1)];
        }
    }
    if (ptr2 == str2.length())
        num2 += pr[str2.substr(str2.length() - 1, 1)];

    ll lans = num1 + num2;
    cout << lans << endl;
    string ans = "";

    if (lans / 1 > 0) {
        switch (lans % 10) {
            case 1:
            case 4:
            case 5:
            case 9:
                ans = rom[lans % 10];
                break;
            case 2:
                ans = "II";
                break;
            case 3:
                ans = "III";
                break;
            case 6:
                ans = "VI";
                break;
            case 7:
                ans = "VII";
                break;
            case 8:
                ans = "VIII";
                break;
        }
    }

    if (lans / 10 > 0) {
        ll temp = lans % 100 - lans % 10;
        switch (temp) {
            case 10:
            case 40:
            case 50:
            case 90:
                ans = rom[temp] + ans;
                break;
            case 20:
                ans = "XX" + ans;
                break;
            case 30:
                ans = "XXX" + ans;
                break;
            case 60:
                ans = "LX" + ans;
                break;
            case 70:
                ans = "LXX" + ans;
                break;
            case 80:
                ans = "LXXX" + ans;
                break;
        }
    }

    if (lans / 100 > 0) {
        ll temp = lans % 1000 - lans % 100;
        switch (temp) {
            case 100:
            case 400:
            case 500:
            case 900:
                ans = rom[temp] + ans;
                break;
            case 200:
                ans = "CC" + ans;
                break;
            case 300:
                ans = "CCC" + ans;
                break;
            case 600:
                ans = "DC" + ans;
                break;
            case 700:
                ans = "DCC" + ans;
                break;
            case 800:
                ans = "DCCC" + ans;
                break;
        }
    }

    if (lans / 1000 > 0) {
        ll temp = lans % 10000 - lans % 1000;
        switch (temp) {
            case 1000:
                ans = rom[temp] + ans;
                break;
            case 2000:
                ans = "MM" + ans;
                break;
            case 3000:
                ans = "MMM" + ans;
                break;
        }
    }

    cout << ans << endl;
    return 0;
}
