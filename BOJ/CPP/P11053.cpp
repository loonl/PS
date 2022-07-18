#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector<pair<int, int>> vec;

int max_index(int value) {
    int result = -1;
    for (int i = 0; i < vec.size(); i++) {
        if (value > vec[i].first && result < vec[i].second) {
            result = vec[i].second;
        }
    }
    return result;
}

int max_value() {
    int result = -1;
    for (int i = 0; i < vec.size(); i++) {
        if (result < vec[i].second) {
            result = vec[i].second;
        }
    }
    return result;
}

int main()
{
    int n, ip;
    cin >> n;
    vector<int> inputs;
    for (int i = 0; i < n; i++) {
        cin >> ip;
        inputs.push_back(ip);
    }

    // n이 2 이하면 바로 종료
    if (n == 1) {
        cout << n << endl;
        exit(0);
    }

    if (n == 2) {
        if (vec[0] < vec[1])
            cout << n << endl;
        else
            cout << 1 << endl;
        exit(0);
    }

    vec.push_back(make_pair(inputs[0], 1));
    // n이 3 이상일 때
    for (int i = 1; i < n; i++) {
        int val1 = inputs[i];
        int val2 = max_index(val1) + 1;
        if (val2 == 0)
            val2 = 1;
        vec.push_back(make_pair(val1, val2));
    }

    cout << max_value() << "\n";
    return 0;
}