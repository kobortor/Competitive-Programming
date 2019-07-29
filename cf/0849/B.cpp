#include<bits/stdc++.h>

using namespace std;

#define allof(x) (x).begin(), (x).end()

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

const int MAXN = 1005;
ll Y[MAXN];

int N;
bool check (ll dx, ll dy) {
    set<ll> st;
    for (int a = 1; a <= N; a++) {
        st.insert(Y[a] * dx - dy * a);
    }
    return st.size() == 2;
}

int main(){
    cin.tie(0);
    cin.sync_with_stdio(0);

    cin >> N;
    for (int a = 1; a <= N; a++) {
        cin >> Y[a];
    }

    if (check(1, Y[2] - Y[1]) ||
        check(1, Y[3] - Y[2]) ||
        check(2, Y[3] - Y[1])) {
        cout << "Yes";
    } else {
        cout << "No";
    }
}
