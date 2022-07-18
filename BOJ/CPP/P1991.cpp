#include <iostream>
#include <vector>
#define endl '\n'
using namespace std;
typedef long long ll;

struct node
{
    char name;
    char left, right;
};
vector<node> vec(100);


void pre(char nde)
{
    if (nde == '.')
        return;

    cout << nde;
    pre(vec[nde].left);
    pre(vec[nde].right);
}

void in(char nde)
{
    if (nde == '.')
        return;
    
    in(vec[nde].left);
    cout << nde;
    in(vec[nde].right);
}

void post(char nde)
{
    if (nde == '.')
        return;

    post(vec[nde].left);
    post(vec[nde].right);
    cout << nde;
}


int main()
{
    cin.tie(0)->sync_with_stdio(false);
    int n; cin >> n;
    char now, right, left;
    for (int i = 1; i <= n; i++)
    {
        cin >> now >> left >> right;
        vec[now].left = left;
        vec[now].right = right;
    }
    pre('A'); cout << endl;
    in('A'); cout << endl;
    post('A'); cout << endl;
    return 0;
}