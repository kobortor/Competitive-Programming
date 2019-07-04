#include<bits/stdc++.h>

using namespace std;

#define allof(x) (x).begin(), (x).end()

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

const int MAXN = 1e5 + 5;

ll N;
ll A[MAXN], B[MAXN];

int main(){
    cin.tie(0);
    cin.sync_with_stdio(0);

    cin >> N;
    for (int a = 1; a <= N; a++) {
        cin >> A[a];
    }

    for (int a = 1; a <= N; a++) {
        cout << A[a] + A[a + 1] << " ";
    }
}
