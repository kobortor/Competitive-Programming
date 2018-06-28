#include<bits/stdc++.h>

using namespace std;

#define allof(x) (x).begin(), (x).end()

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

int N;

int main(){
    cin.tie(0);
    cin.sync_with_stdio(0);

    cin >> N;

    int ans = 0;
    int prv = -1;
    int idx = 0;
    for(int a = 0; a < N; a++){
        int x;
        cin >> x;
        if(x < prv){
            ans = max(ans, a - idx);
            idx = a;
        }
        prv = x;
    }
    ans = max(ans, N - idx);
    cout << ans;
}
