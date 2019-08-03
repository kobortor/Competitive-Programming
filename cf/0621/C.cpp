#include<bits/stdc++.h>

using namespace std;

#define allof(x) (x).begin(), (x).end()

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

const int MAXN = 1e5 + 5;
int n, p;
int l[MAXN], r[MAXN];

double solve(int i, int j) {
    int cnt_i = r[i] / p - (l[i] - 1) / p;
    int cnt_j = r[j] / p - (l[j] - 1) / p;

    double pr_i = (double)cnt_i / (r[i] - l[i] + 1);
    double pr_j = (double)cnt_j / (r[j] - l[j] + 1);

    return (1 - (1 - pr_i) * (1 - pr_j)) * 2000.0;
}

int main(){
    cin.tie(0);
    cin.sync_with_stdio(0);

    cin >> n >> p;
    for (int a = 1; a <= n; a++) cin >> l[a] >> r[a];

    double ans = solve(1, n);
    for (int a = 1; a <= n - 1; a++) ans += solve(a, a + 1);

    cout << fixed << setprecision(10) << ans;
}
