#include <bits/stdc++.h>
#define FASTIO cin.tie(0)->sync_with_stdio(false)
#define endl "\n"
#define P pair<int64_t, int64_t>
using namespace std;
typedef int64_t ll;
typedef __int128_t lll;
ll MAX = pow(10, 17);

struct node {
    ll value;
    node* left;
    node* right;
    node(ll val, node* l, node* r) {
        value = val;
        left = l;
        right = r;
    }
};

void insrt(node*& a, ll val) {
    if (a->value > val && a->left == nullptr) {
        a->left = new node(val, nullptr, nullptr);
        return;
    }

    if (a-> value < val && a->right == nullptr) {
        a->right = new node(val, nullptr, nullptr);
        return;
    }

    if (a-> value > val && a->left != nullptr) {
        insrt(a->left, val);
    }

    if (a-> value < val && a->right != nullptr) {
        insrt(a->right, val);
    }
}

void in(node*& a) {
    if (a == nullptr)
        return;

    in(a->left);
    cout << a->value << endl;
    in(a->right);
}

void post(node*& a) {
    if (a == nullptr)
        return;

    post(a->left);
    post(a->right);
    cout << a->value << endl;
}

int main()
{
    FASTIO;
    #ifndef ONLINE_JUDGE
    freopen("a.in", "r", stdin);
    #endif // ONLINE_JUDGE

    ll t1; cin >> t1;
    node* root = new node(t1, nullptr, nullptr);
    while (cin >> t1) {
        insrt(root, t1);
    }

    post(root);
    return 0;
}
