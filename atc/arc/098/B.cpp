#include<bits/stdc++.h>

using namespace std;

#define allof(x) (x).begin(), (x).end()

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

const int MAXN = 2e5 + 5;

int N;
int prv[MAXN];
int arr[MAXN];

int main(){
    cin.tie(0);
    cin.sync_with_stdio(0);

    cin >> N;

    arr[0] = -1;

    for(int a = 1, last = 0; a <= N; a++){
        cin >> arr[a];
        prv[a] = last;
        if(arr[a] != 0){
            last = a;
        }
    }

    ll ans = 0;
    for(int a = 1; a <= N; a++){
        int curv = arr[a] | (1 << 30);
        int cur = a;

        int lbnd;
        while(true){
            if(arr[prv[cur]] & curv){
                lbnd = prv[cur] + 1;
                break;
            } else {
                curv |= arr[prv[cur]];
                cur = prv[cur];
            }
        }
        ans += a - lbnd + 1;
    }
    cout << ans;
}
