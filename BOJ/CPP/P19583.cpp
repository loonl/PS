#include <iostream>
#include <string>
#include <set>
#include <vector>
#include <algorithm>
using namespace std;

class Time {
public:
    int min;
    int hr;
    Time(int hr, int min) : hr(hr), min(min) {}
    Time(string a) : hr(stoi(a.substr(0, 2))), min(stoi(a.substr(3, 2))) {}
};

bool Same_Earlier(Time a, Time b) {
    if (a.hr == b.hr)
        return a.min <= b.min;
    return a.hr < b.hr;
}

int main()
{
    string a, b, c; cin >> a >> b >> c;
    Time start(a), end(b), stream_end(c);
    set<string> attendA; // 출첵 1번 만족하는 애들
    set<string> attendB; // 출첵 2번 만족하는 애들

    cin.ignore(); string str;
    int count = 0;
    while (getline(cin, str)) {
        string _time = str.substr(0, 5);
        Time t(_time);
        string id = str.substr(6);

        if (Same_Earlier(t, start)) { attendA.insert(id); }
        else if (Same_Earlier(end, t) && Same_Earlier(t, stream_end))
            attendB.insert(id);
        count++;
    }
    
    //cout << "debug : attendA" << endl;
    //for (auto it = attendA.begin(); it != attendA.end(); it++) {
    //    cout << *it << " ";
    //}
    //cout << endl << endl;
    //for (auto it = attendB.begin(); it != attendB.end(); it++) {
    //    cout << *it << " ";
    //}
    //cout << endl << endl;

    // 그것들의 교집합
    vector<string> attended; attended.resize(count);
    set_intersection(attendA.begin(), attendA.end(), attendB.begin(), attendB.end(), attended.begin());

    int answer = 0;
    for (int i = 0; i < attended.size(); i++) {
        if (attended[i] == "")
            break;
        answer++;
    }

    cout << answer << endl;
    return 0;
}