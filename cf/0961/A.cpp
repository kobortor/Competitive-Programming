#include<bits/stdc++.h>

using namespace std;

#define allof(x) (x).begin(), (x).end()

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

const int MAXN = 1005;

int N, M;
int filled[MAXN];

int main(){
    cin.tie(0);
    cin.sync_with_stdio(0);

    cin >> N >> M;

    int cnt = 0;
    int ans = 0;
    while(M--){
        int x;
        cin >> x;
        if(!filled[x]){
            cnt++;
        }
        filled[x]++;
        if(cnt == N){
            for(int a = 1; a <= N; a++){
                if(! --filled[a]){
                    cnt--;
                }
            }
            ans++;
        }
    }
    cout << ans;
}
