#include <iostream>
using namespace std;

int db[21][21][21];


int recur(int a, int b, int c) {
    if (a <= 0 or b <= 0 or c <= 0) {
        return 1;
    }

    if (a > 20 or b > 20 or c > 20) {
        return recur(20, 20, 20);
    }

    if (db[a][b][c] != 0) { return db[a][b][c]; }
    if (a < b and b < c) {
        db[a][b][c] =  recur(a, b, c - 1) + recur(a, b - 1, c - 1) - recur(a, b - 1, c);
        return db[a][b][c];
    }
    else {
        db[a][b][c] = recur(a - 1, b, c) + recur(a - 1, b - 1, c) + recur(a - 1, b, c - 1) - recur(a - 1, b - 1, c - 1);
        return db[a][b][c];
    }
}

int main()
{
    cin.tie(0); cout.tie(0);
    ios::sync_with_stdio(false);
    int a, b, c;
    while (true) {
        cin >> a >> b >> c;
        if (a == -1 && b == -1 && c == -1)
            break;

        cout << "w(" << a << ", " << b << ", " << c << ") = " << recur(a, b, c) << "\n";
    }

    return 0;
}