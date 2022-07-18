#include <iostream>
#include <vector>
#include <algorithm>
#define endl '\n'
using namespace std;

int BSearch(vector<int>& vec, int target) {
    int low = 0;
    int high = vec.size() - 1;
    int mid;
 
    while (low <= high) 
    {
        mid = (low + high) / 2;
 
        if (vec[mid] == target)
            return 1;
        else if (vec[mid] > target)
            high = mid - 1;
        else if (vec[mid] < target)
            low = mid + 1;
    }
    return 0;
}

int main()
{
    cin.tie(0);
    ios::sync_with_stdio(false);
    cout.tie(0);
    int n; cin >> n;
    vector<int> vec(n,0);
    for (int i = 0; i < n; i++) {
        cin >> vec[i];
    }
    
    int tc; cin >> tc; int num;
    sort(vec.begin(), vec.end());
    while (tc--) {
        cin >> num;
        int a = BSearch(vec, num);
        cout << a << endl;
    }
    return 0;
}
