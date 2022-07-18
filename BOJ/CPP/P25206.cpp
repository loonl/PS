#include <iostream>
#include <map>
#include <string>
#define endl '\n'
using namespace std;
int n;

int main()
{
    cin.tie(0)->sync_with_stdio(false);
    map<double, double> m;
    double all = 0;
    m[4.5] = 0; m[4] = 0; m[3.5] = 0; m[3] = 0; m[2.5] = 0; m[2] = 0; m[1.5] = 0; m[1] = 0; m[0] = 0;
    string str; double hj; string grade;
    while (true)
    {
        cin >> str >> hj >> grade;
        if (cin.fail())
            break;
        //if (str == "a" && hj == 0 && grade == "a")
        //    break;
        if (grade != "P")
            all += hj;
        if (grade == "A+")
            m[4.5] += hj;
        if (grade == "A0")
            m[4] += hj;
        if (grade == "B+")
            m[3.5] += hj;
        if (grade == "B0")
            m[3] += hj;
        if (grade == "C+")
            m[2.5] += hj;
        if (grade == "C0")
            m[2] += hj;
        if (grade == "D+")
            m[1.5] += hj;
        if (grade == "D0")
            m[1] += hj;
        if (grade == "F")
            m[0] += hj;
    }

    double hap = 0;
    for (auto it = m.begin(); it != m.end(); it++)
    {
        hap += (it->first * it->second);
    }

    cout << hap / all << endl;
    return 0;
}