#include <iostream>
#include <string>
using namespace std;

string hanoi(int start, int dest, int n, int& sum) {
    if (n == 1) {
        sum++;
        return to_string(start) + " " + to_string(dest) + "\n";
    }
    string temp;
    temp = hanoi(start, 6 - dest - start, n - 1, sum);
    temp += to_string(start) + " " + to_string(dest) + "\n";
    sum++;
    return temp + hanoi(6 - dest - start, dest, n - 1, sum);
}

int main(){
    int sum = 0; int a; cin >> a; 
    string ans = hanoi(1, 3, a, sum);
    cout << sum << endl;
    cout << ans << endl;
    return 0;
}