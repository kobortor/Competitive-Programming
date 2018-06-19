#include<bits/stdc++.h>

using namespace std;

#define allof(x) (x).begin(), (x).end()

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

const int MAXN = 2e5 + 5;

set<int> not_one;

ll N, K;
int arr[MAXN];
ll prefix[MAXN];
int nxt[MAXN];
float lg2[MAXN];

int main(){
    cin.tie(0);
    cin.sync_with_stdio(0);

    cin >> N >> K;

    for(int a = 1; a <= N; a++){
        cin >> arr[a];
        prefix[a] = arr[a] + prefix[a - 1];
        lg2[a] = log2f(arr[a]);
    }

    nxt[N + 1] = N + 1;
    for(int a = N; a >= 1; a--){
        if(arr[a + 1] != 1){
            nxt[a] = a + 1;
        } else {
            nxt[a] = nxt[a + 1];
        }
    }

    ll ans = 0;

    for(int a = 1; a <= N; a++){
        int idx = a;

        float logsum = 0;
        ll prod = 1;

        while(true){
            logsum += lg2[idx];
            if(logsum > 62){
                break;
            }

            prod *= arr[idx];
            ll sum = prefix[idx] - prefix[a - 1];

            if(prod % K == 0){
                ll req_sum = prod / K;
                ll new_idx = idx + (req_sum - sum);
                if(idx <= new_idx && new_idx < nxt[idx] && prefix[new_idx] - prefix[a - 1] == req_sum){
                    ans++;
                }
            }

            if(nxt[idx] == N + 1){
                break;
            } else {
                idx = nxt[idx];
            }
        }
    }

    cout << ans;
}
