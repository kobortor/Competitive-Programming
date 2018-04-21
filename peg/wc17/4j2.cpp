#include<bits/stdc++.h>

using namespace std;

#define allof(x) (x).begin(), (x).end()

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;



int main(){
    cin.tie(0);
    cin.sync_with_stdio(0);

    int N, cnt = 0, ans = 0;
    cin >> N;
    while(N--){
        int x;
        cin >> x;
        if(cnt < 10 && 10 <= cnt + x){
            ans++;
        }
        cnt += x;
    }
    cout << ans;
}
