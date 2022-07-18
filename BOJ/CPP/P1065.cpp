#include <iostream>
#include <string>
#include <vector>
using namespace std;
int main()
{
    int a; cin >> a;
    int ans, d; string st,cut;
    vector<int> vec;
    if (a < 100) { ans = a; } else {
        ans = 99;
        for (int i = 100; i < a + 1; i++) {
            st = to_string(i);
            vec.clear();
            for (int j = 0; j < st.length(); j++) {
                cut = st.substr(j,1);
                vec.push_back(stoi(cut));
            }
            d = vec[1] - vec[0];
            bool hansu = true;
            for (int j = 2; j < vec.size(); j++) {
                if (vec[j] - vec[j-1] != d) { hansu = false; break; }
            }
            if (hansu) { ans++; }
        }
    }
    cout << ans << endl;
    return 0;
}