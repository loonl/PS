#include <iostream>
#include <stack>
#include <vector>
#define endl '\n'
using namespace std;

int main()
{
    cin.tie(0)->sync_with_stdio(false);
    int n; cin >> n;
    int x;
    stack<int> st;
    vector<int> vec(n + 1, 0);
    vector<pair<int, int>> nge(n + 1, make_pair(-1, 0)); // 값, 인덱스 

    for (int i = 0; i < n; i++)
    {
        cin >> x;
        st.push(x);
    }

    int now, ex;
    int index = n;
    while (!st.empty())
    {
        index--;
        now = st.top();
        st.pop();

        // 마지막 원소라면 밑의 연산 할 필요가 없음...
        if (st.empty())
            break;

        ex = st.top();
        if (ex < now)
        {
            nge[index] = make_pair(now, index + 1);
        }
        else
        {
            if (ex < nge[index + 1].first)
            {
                nge[index] = nge[index + 1];
                continue;
            }
            else
            {
                int num = nge[index + 1].second;
                while (nge[num].first != -1)
                {
                    if (ex < nge[num].first)
                    {
                        nge[index] = nge[num];
                        break;
                    }
                    
                    num = nge[num].second;
                }
            }
        }
    }

    for (int i = 1; i <= n; i++)
    {
        cout << nge[i].first << " ";
    }

    return 0;
}