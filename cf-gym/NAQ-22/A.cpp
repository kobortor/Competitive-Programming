#include<bits/stdc++.h>

using namespace std;

#define allof(x) (x).begin(), (x).end()

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;



int main(){
    cin.tie(0);
    cin.sync_with_stdio(0);

    int N;
    cin >> N;
    vector<ll> A(N);
    for (ll &vi : A) {
        cin >> vi;
    }
    sort(allof(A));
    reverse(allof(A));

    ll tot = accumulate(allof(A), 0ll);

    int ans = 1;
    ll sum = A[0];
    ll bucket = A[0];
    for (int i = 1; i < N; i++) {
        sum += A[i];
        if (sum - bucket >= bucket) {
            bucket = sum;
            ans = i + 1;
        }
    }
    cout << ans << endl;
}
