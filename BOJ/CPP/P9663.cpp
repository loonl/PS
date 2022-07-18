#include <iostream>
#include <vector>
using namespace std;
int global_count = 0;
void recur(vector<int> vec, int x, int n);

int main()
{
    cin.sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    int n;  cin >> n; vector<int> vec; vec.clear();
    for (int i = 0; i < n; i++) {
        recur(vec, i, n);
    }

    cout << global_count << endl;
    return 0;
}

// add & due to timeout error
bool isable(vector<int>& vec, int x) { 
    int y = vec.size();
    for (int i = 0; i < vec.size(); i++) {
        if (x == vec[i]) { return false; }
        if (i - y == vec[i] - x) { return false; }
        if (i - y == x - vec[i]) { return false; }
    }
    return true;
}

void recur(vector<int> vec, int x, int n) {

    // todo
    vec.emplace_back(x);

    // return 
    if (vec.size() == n) { global_count++; return; }

    // to next recursive function
    for (int i = 0; i < n; i++) {
        if (isable(vec, i)) {
            recur(vec, i, n);
        }
    }
}