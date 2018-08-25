#include<bits/stdc++.h>

using namespace std;

#define allof(x) (x).begin(), (x).end()

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

const int MAXN = 1e5 + 5;

int N;
int arr[MAXN];

int _[2 * MAXN];
int *back = _ + MAXN;

int main(){
    cin.tie(0);
    cin.sync_with_stdio(0);

    cin >> N;

    for(int a = 1; a <= N; a++){
        cin >> arr[a];
    }

    int lo = 1, hi = 1e9;
    while(lo <= hi){
        ll cnt = 0;
        memset(_, 0, sizeof _);
        back[0]++;

        int before = 0;
        int mid = (lo + hi) / 2;
        for(int i = 1, cur = 0; i <= N; i++){
            if(arr[i] <= mid){
                cur++;
                before += back[cur - 1];
            } else {
                before -= back[cur - 1];
                cur--;
            }

            cnt += before;
            back[cur]++;
        }

        if(cnt > (ll)N * (N + 1) / 2 - cnt){
            hi = mid - 1;
        } else {
            lo = mid + 1;
        }
    }
    cout << lo;
}
