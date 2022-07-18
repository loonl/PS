#include <iostream>
#include <vector>
#include <tuple>
#define endl '\n'
using namespace std;
typedef long long ll;

int main()
{
    cin.tie(0)->sync_with_stdio(false);
    int tc; cin >> tc;
    while (tc--)
    {
        int x1, y1, x2, y2;
        cin >> x1 >> y1 >> x2 >> y2;
        int n; cin >> n;
        vector<tuple<int, int, int>> planets;
        int x, y, r;
        for (int i = 0; i < n; i++)
        {
            cin >> x >> y >> r;
            planets.emplace_back(make_tuple(x, y, r));
        }

        int answer = 0;
        vector<pair<bool, bool>> vec;
        for (int i = 0; i < n; i++)
        {
            int x, y, r;
            bool start, end;
            x = get<0>(planets[i]); y = get<1>(planets[i]); r = get<2>(planets[i]);
            if ((x - x1) * (x - x1) + (y - y1) * (y - y1) < r * r)
                start = true;
            else
                start = false;

            if ((x - x2) * (x - x2) + (y - y2) * (y - y2) < r * r)
                end = true;
            else
                end = false;

            vec.emplace_back(make_pair(start, end));
        }
        
        for (int i = 0; i < n; i++)
        {
            if (vec[i].first != vec[i].second)
                answer++;
        }
        cout << answer << endl;
    }
    return 0;
}