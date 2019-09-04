#include<bits/stdc++.h>

using namespace std;

#define allof(x) (x).begin(), (x).end()

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

bool seen[10];

int main(){
    cin.tie(0);
    cin.sync_with_stdio(0);

    int K, N;
    cin >> K >> N;

    vector<int> v(N);
    for (int &i : v) cin >> i;

    int ans = 0;

    sort(allof(v));

    for (int a = 0; a < N; a++) {
        seen[v[a] / 1000] = true;
        int b = a;
        while ( b + 1 < N && b - a + 2 <= K && 
                v[b] < v[b + 1] && seen[v[b + 1] / 1000]) b++;

        ans++;

        a = b;
    }

    cout << ans + 2;
}
