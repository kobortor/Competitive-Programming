#include<bits/stdc++.h>

using namespace std;

#define allof(x) (x).begin(), (x).end()

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

const int MAXN = 1e5 + 5;

int arr[MAXN];

unsigned mergesort(int l, int r) {
    if (l + 1 >= r) {
        return 0;
    }

    int mid = (l + r) / 2;
    unsigned ans = mergesort(l, mid) + mergesort(mid, r);

    vector<int> v;
    int i1 = l, i2 = mid;
    while (i1 < mid || i2 < r) {
        if (i1 == mid) {
            ans += mid - i1;
            v.push_back(arr[i2++]);
        } else if (i2 == r) {
            v.push_back(arr[i1++]);
        } else if (arr[i1] <= arr[i2]) {
            v.push_back(arr[i1++]);
        } else {
            ans += mid - i1;
            v.push_back(arr[i2++]);
        }
    }

    for (int a = l; a < r; a++) {
        arr[a] = v[a - l];
    }
    return ans;
}

int main(){
    cin.tie(0);
    cin.sync_with_stdio(0);

    int n;
    cin >> n;
    for (int a = 0; a < n; a++) {
        cin >> arr[a];
    }

    cout << mergesort(0, n);
}
