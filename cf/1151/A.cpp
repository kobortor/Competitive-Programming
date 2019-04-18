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
    string S;
    cin >> N >> S;

    int ans = 9999;
    for (int a = 0; a + 3 < N; a++) {
        int cost = 0;
        cost += min(abs(S[a + 0] - 'A'), 26 - abs(S[a + 0] - 'A'));
        cost += min(abs(S[a + 1] - 'C'), 26 - abs(S[a + 1] - 'C'));
        cost += min(abs(S[a + 2] - 'T'), 26 - abs(S[a + 2] - 'T'));
        cost += min(abs(S[a + 3] - 'G'), 26 - abs(S[a + 3] - 'G'));
        ans = min(ans, cost);
    }

    cout << ans;
}
