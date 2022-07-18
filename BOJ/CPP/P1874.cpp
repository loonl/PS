#include <iostream>
#include <stack>
#include <vector>
using namespace std;
int main() {
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    vector<char> vec;
    stack<int> st;
    int n; cin >> n;
    int temp;

    int count = 1;
    for (int i = 0; i < n; i++) {
        cin >> temp;
        while (count <= temp) {
            st.push(count);
            count++;
            vec.push_back('+');
        }

        if (st.top() == temp) {
            st.pop();
            vec.push_back('-');
        } else {
            cout << "NO";
            exit(0);
        }
    }

    for (int i = 0; i < vec.size(); i++) {
        cout << vec[i] << "\n";
    }
    return 0;
}