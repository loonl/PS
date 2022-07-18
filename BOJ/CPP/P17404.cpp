#include <iostream>
using namespace std;

int min(int a, int b) {
    if (a < b)
        return a;
    return b;
}

int min(int a, int b, int c) {
    return min(min(a, b), c);
}

int main()
{
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    int n; cin >> n;
    int r[1001], g[1001], b[1001];
    int x, y, z;
    for (int i = 1; i <= n; i++) {
        cin >> x >> y >> z;
        r[i] = x; g[i] = y; b[i] = z;
    }

    int min_red, min_green, min_blue;
    if (n == 2) {
        min_red = r[1] + min(g[2], b[2]);
        min_green = g[1] + min(r[2], b[2]);
        min_blue = b[1] + min(r[2], g[2]);
        cout << min(min_red, min_green, min_blue) << endl;
        exit(0);
    }

    // red로 시작할 때 
    int hapr[1001][3]; // [][0] = red [][1] = green [][2] = blue
    hapr[2][0] = 0; hapr[2][1] = r[1] + g[2]; hapr[2][2] = r[1] + b[2];
    hapr[3][0] = min(hapr[2][1], hapr[2][2]) + r[3]; 
    hapr[3][1] = hapr[2][2] + g[3]; 
    hapr[3][2] = hapr[2][1] + b[3];
    for (int i = 4; i <= n; i++) {
        hapr[i][0] = min(hapr[i - 1][1], hapr[i - 1][2]) + r[i];
        hapr[i][1] = min(hapr[i - 1][0], hapr[i - 1][2]) + g[i];
        hapr[i][2] = min(hapr[i - 1][0], hapr[i - 1][1]) + b[i];
    }

    // green으로 시작할 때 
    int hapg[1001][3];
    hapg[2][0] = g[1] + r[2]; hapg[2][1] = 0; hapg[2][2] = g[1] + b[2];
    hapg[3][0] = hapg[2][2] + r[3]; // g->b->r
    hapg[3][1] = min(hapg[2][0], hapg[2][2]) + g[3];
    hapg[3][2] = hapg[2][0] + b[3]; // g->r->b
    for (int i = 4; i <= n; i++) {
        hapg[i][0] = min(hapg[i - 1][1], hapg[i - 1][2]) + r[i];
        hapg[i][1] = min(hapg[i - 1][0], hapg[i - 1][2]) + g[i];
        hapg[i][2] = min(hapg[i - 1][0], hapg[i - 1][1]) + b[i];
    }

    // blue로 시작할 때 
    int hapb[1001][3];
    hapb[2][0] = b[1] + r[2]; hapb[2][1] = b[1] + g[2]; hapb[2][2] = 0;
    hapb[3][0] = hapb[2][1] + r[3]; // b->g->r
    hapb[3][1] = hapb[2][0] + g[3]; // b->r->g
    hapb[3][2] = min(hapb[2][0], hapb[2][1]) + b[3];
    for (int i = 4; i <= n; i++) {
        hapb[i][0] = min(hapb[i - 1][1], hapb[i - 1][2]) + r[i];
        hapb[i][1] = min(hapb[i - 1][0], hapb[i - 1][2]) + g[i];
        hapb[i][2] = min(hapb[i - 1][0], hapb[i - 1][1]) + b[i];
    }

    // start 색 != end 색
    min_red = min(hapr[n][1], hapr[n][2]);
    min_green = min(hapg[n][0], hapg[n][2]);
    min_blue = min(hapb[n][0], hapb[n][1]);
    cout << min(min_red, min_green, min_blue) << endl;
    return 0;
}