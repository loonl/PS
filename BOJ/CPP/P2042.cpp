#include <iostream>
#include <vector>
#define endl '\n'
#define int long long
using namespace std;
typedef long long ll;
vector<ll> arr;
int n, m, k;

ll initSegment(vector<ll>& segmentTree, int node, int start, int end)
{
    if (start == end)
        return segmentTree[node] = arr[start];

    int mid = (start + end) / 2;

    return segmentTree[node] = initSegment(segmentTree, node * 2, start, mid) + initSegment(segmentTree, node * 2 + 1, mid + 1, end);
}

ll sum(vector<ll>& tree, int node, int start, int end, int left, int right) // 합을 구해야 하는 게 left, right && node가 담당하고 있는 구간이 start, end
{
    if (left > end || right < start)
    {
        return 0;
    }
    if (left <= start && end <= right)
    {
        return tree[node];
    }
    // 좌우로 찢으면서 sum 더해주기
    return sum(tree, node * 2, start, (start + end) / 2, left, right) + sum(tree, node * 2 + 1, (start + end) / 2 + 1, end, left, right);
}

void update(vector<ll>& tree, int node, int start, int end, int index, ll diff)
{
    if (index < start || index > end)
        return;

    // update
    tree[node] += diff;

    // 최하위 노드가 아니라면 좌우로 찢어주면서 업데이트 이어나가기
    if (start != end)
    {
        update(tree, node * 2, start, (start + end) / 2, index, diff);
        update(tree, node * 2 + 1, (start + end) / 2 + 1, end, index, diff);
    }
}

signed main()
{
    cin.tie(0)->sync_with_stdio(false);
    cin >> n >> m >> k;
    arr.assign(n + 1, 0);
    for (int i = 1; i <= n; i++)
    {
        cin >> arr[i];
    }

    // 세그먼트 트리 size 맞추기
    vector<ll> segmentTree(4 * n);
    initSegment(segmentTree, 1, 1, n);
    int cmd; int inp1, inp2;
    for (int i = n + 2; i <= n + m + k + 1; i++)
    {
        cin >> cmd;
        if (cmd == 1)
        {
            cin >> inp1 >> inp2;
            ll diff = inp2 - arr[inp1];
            arr[inp1] = inp2;
            update(segmentTree, 1, 1, n, inp1, diff);
        }
        else
        {
            cin >> inp1 >> inp2;
            cout << sum(segmentTree, 1, 1, n, inp1, inp2) << endl;
        }
    }
    return 0;
}