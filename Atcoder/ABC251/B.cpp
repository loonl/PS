#include <iostream>
#include <vector>
#include <set>
#include <algorithm>
#define endl '\n'
using namespace std;

int main()
{
    cin.tie(0)->sync_with_stdio(false);
    int n, w; cin >> n >> w;
    vector<int> vec(n, 0);
    for (int i = 0; i < n; i++) 
    {
        cin >> vec[i];
    }

    set<int> s;
    int hap;
    for (int i = 0; i < n; i++) {
        hap = vec[i];
        if (hap <= w)
            s.insert(hap);
    }

    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            hap = vec[i] + vec[j];
            if (hap <= w)
                s.insert(hap);
        }
    }

    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            for (int k = j + 1; k < n; k++) {
                hap = vec[i] + vec[j] + vec[k];
                if (hap <= w)
                    s.insert(hap);
            }
        }
    }

    cout << s.size() << endl;
    return 0;
}