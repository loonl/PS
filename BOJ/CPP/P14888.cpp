#include <iostream>
#include <string>
#include <vector>
#include <climits>
using namespace std;
vector<long long> operands;
vector<long long> result;

void solv(int plus, int minus, int mul, int div);

int main() {
	int a; cin >> a; long long num;
	for (int i = 0; i < a; i++) {
		cin >> num; operands.push_back(num);
	}
	int plus, minus, mul, div; cin >> plus >> minus >> mul >> div;
	solv(plus, minus, mul, div);

	// print max and min value in result vector
	long long max = LLONG_MIN; long long min = LLONG_MAX;
	for (int i = 0; i < result.size(); i++) {
		long long temp = result[i];
		if (max < temp) { max = temp; }
		if (min > temp) { min = temp; }
	}
	cout << max << "\n" << min << "\n";
	return 0;
}

void solv(int plus, int minus, int mul, int div) {
	// return
	if (plus == 0 && minus == 0 && mul == 0 && div == 0) {
		result.push_back(operands[0]);
		return;
	}

	int temp1, temp2; temp1 = operands[0]; temp2 = operands[1]; // backup
	// go to next recursive functions by backtracking
	if (plus != 0) {
		operands[0] += operands[1];
		operands.erase(operands.begin() + 1);
		solv(plus - 1, minus, mul, div);
		operands.insert(operands.begin() + 1, temp2);
		operands[0] = temp1;
	}
	
	if (minus != 0) {
		operands[0] -= operands[1];
		operands.erase(operands.begin() + 1);
		solv(plus, minus - 1, mul, div);
		operands.insert(operands.begin() + 1, temp2);
		operands[0] = temp1;
	}

	if (mul != 0) {
		operands[0] *= operands[1];
		operands.erase(operands.begin() + 1);
		solv(plus, minus, mul - 1, div);
		operands.insert(operands.begin() + 1, temp2);
		operands[0] = temp1;
	}

	if (div != 0) {
		bool isSpecial = false;
		if (operands[0] < 0 && operands[1] > 0) { isSpecial = true; operands[0] = -operands[0]; }
		operands[0] /= operands[1];
		if (isSpecial) { operands[0] = -operands[0]; }
		operands.erase(operands.begin() + 1);
		solv(plus, minus, mul, div - 1);
		operands.insert(operands.begin() + 1, temp2);
		operands[0] = temp1;
	}
}