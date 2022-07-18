#include <iostream>
#include <string>
#include <vector>
using namespace std;
int limit;

void recur(int n);
int main()
{
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin >> limit;
    cout << "어느 한 컴퓨터공학과 학생이 유명한 교수님을 찾아가 물었다." << endl;
    recur(0);
    return 0;
}

void recur(int n)
{
    string first = "";
    for (int i = 0; i < n; i++)
    {
        first += "____";
    }
    if (n == limit)
    {
        string line1 = first + "\"재귀함수가 뭔가요?\"";
        string line2 = first + "\"재귀함수는 자기 자신을 호출하는 함수라네\"";
        string line3 = first + "라고 답변하였지.";
        cout << line1 << endl << line2 << endl << line3 << endl;
        return;
    }

    vector<string> serifu = { "\"재귀함수가 뭔가요?\"",
                          "\"잘 들어보게. 옛날옛날 한 산 꼭대기에 이세상 모든 지식을 통달한 선인이 있었어.",
                          "마을 사람들은 모두 그 선인에게 수많은 질문을 했고, 모두 지혜롭게 대답해 주었지.",
                          "그의 답은 대부분 옳았다고 하네. 그런데 어느 날, 그 선인에게 한 선비가 찾아와서 물었어.\"",
                          "라고 답변하였지." };

    for (auto it = serifu.begin(); it != serifu.end(); it++)
    {
        *it = first + *it;
    }

    cout << serifu[0] << endl << serifu[1] << endl << serifu[2] << endl << serifu[3] << endl;
    recur(n + 1);
    cout << serifu[4] << endl;
}