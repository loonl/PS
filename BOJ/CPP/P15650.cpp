#include <iostream>
#include <vector>
using namespace std;

void pick(int range, int length, vector<int> numbers, int target);

int main() {
    int a, b; cin >> a >> b;
    vector<int> vec;

    for (int i = 1; i <= a; i++) {
        pick(a, b, vec, i);
    }

    return 0;
}

void pick(int range, int length, vector<int> numbers, int target) {
    numbers.push_back(target);

    if (numbers.size() == length) { // 반환 조건
        for (int i = 0; i < numbers.size(); i++) {
            cout << numbers[i] << " ";
        }
        cout << "\n"; return;
    }

    for (int i = target + 1; i <= range; i++) {
        pick(range, length, numbers, i);
    }
}