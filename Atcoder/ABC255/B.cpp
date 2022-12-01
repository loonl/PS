#include <iostream>
#include <vector>
#include <algorithm>
#include <math.h>
#define endl '\n'
typedef long long ll;
typedef double db;
using namespace std;
db maxi(vector<db>& vec)
{
    db k = -100;
    for (int i = 0; i < vec.size(); i++)
    {
        if (k < vec[i])
            k = vec[i];
    }
    return k;
}

db mini(vector<db>& vec)
{
    db k = 1000001;
    for (int i = 0; i < vec.size(); i++)
    {
        if (k > vec[i])
            k = vec[i];
    }
    return k;
}

int main()
{
    cin.tie(0)->sync_with_stdio(false);
    int n, k; cin >> n >> k;
    vector<db> vec(k + 1);
    vector<bool> haslight(n + 1, false);
    for (int i = 1; i <= k; i++)
    {
        cin >> vec[i];
        haslight[(int)vec[i]] = true;
    }

    vector<pair<db, db>> coord(n + 1);
    for (int i = 1; i <= n; i++)
    {
        db a, b;
        cin >> a >> b;
        coord[i] = make_pair(a, b);
    }

    vector<vector<db>> dist(n + 1, vector<db>());

    for (int i = 1; i <= n; i++)
    {
        if (!haslight[i])
            continue;
        for (int j = 1; j <= n; j++)
        {
            if (haslight[j])
                continue;

            db distance = sqrt((coord[i].first - coord[j].first) * (coord[i].first - coord[j].first) +
                                (coord[i].second - coord[j].second) * (coord[i].second - coord[j].second));
            dist[j].emplace_back(distance);
        }
    }

    vector<db> temp;
    for (int i = 1; i <= n; i++)
    {
        auto tmp = mini(dist[i]);
        if (tmp != 1000001)
            temp.push_back(tmp);
    }

    cout << fixed;
    cout.precision(10);
    cout << maxi(temp) << endl;
    return 0;
}