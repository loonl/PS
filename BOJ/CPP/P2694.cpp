#include <iostream>
using namespace std;
typedef long long ll;

void solve() {
    int N; cin >> N;
    int arr[N];
    for (int i = 0; i < N; i++) {
        cin >> arr[i];
        if (i) arr[i] += arr[i - 1];
    }

    for (int start_length = 0; start_length < N; start_length++) {
        int value = arr[start_length];
        if (arr[N - 1] % value) continue;

        int l = start_length + 1;
        int cnt = 0;
        bool yes = true;
        while (l + cnt < N) {
            int cur = arr[l + cnt] - arr[l - 1];
            if (cur > value) {
                yes = false;
                break;
            }
            if (cur == value) {
                l += cnt + 1;
                cnt = 0;
            }
            else {
                cnt++;
                if (l + cnt == N) yes = false;
            }
        }

        if (yes) {
            cout << value;
            return;
        }
    }
}

int main()
{
    cin.tie(0)->sync_with_stdio(false);
    int T; cin >> T; while (T--) {
        solve();
        cout << '\n';
    }
    return 0;
}