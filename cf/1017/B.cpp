#include<bits/stdc++.h>

using namespace std;

#define allof(x) (x).begin(), (x).end()

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

ll cnt[2][2];

int main(){
    cin.tie(0);
    cin.sync_with_stdio(0);

    int N;
    string A, B;
    cin >> N >> A >> B;

    for(int a = 0; a < N; a++){
        cnt[A[a] - '0'][B[a] - '0']++;
    }

    cout << cnt[0][0] * (cnt[1][0] + cnt[1][1]) + cnt[1][0] * (cnt[0][1]);
}
