#include <iostream>
#include <vector>
#define endl '\n'
typedef unsigned long long ull;
using namespace std;
ull a, c;

ull solve(ull b)
{
    if (b == 1)
        return a % c;

    if (a > c)
        a = a % c;
    ull temp = solve(b / 2);

    if (b % 2 == 0)
        return (temp * temp) % c;
    else
        return (((temp * temp) % c) * a) % c;
}

int main()
{
    cin.tie(0)->sync_with_stdio(false);
    ull b; cin >> a >> b >> c;
    ull d = 1;
    ull answer = solve(b);
    cout << answer << endl;
    return 0;
}

