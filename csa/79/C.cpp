#include<bits/stdc++.h>

using namespace std;

#define allof(x) (x).begin(), (x).end()

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

const int MAXN = 1e5 + 5;

ll N, K;

struct BIT {
    int data[MAXN];
    void update(int pos, int val){
        while(pos < MAXN){
            data[pos] += val;
            pos += pos & -pos;
        }
    }
    int query(int pos){
        int ans = 0;
        while(pos){
            ans += data[pos];
            pos -= pos & -pos;
        }
        return ans;
    }
} ds;

int main(){
    cin.tie(0);
    cin.sync_with_stdio(0);

    cin >> N >> K;
    for(int a = 1; a <= N; a++){
        ds.update(a, 1);
    }

    for(int a = 1; a <= N; a++){
        //cout << "At step " << a << endl;
        int lo = 1, hi = N;
        while(lo <= hi){
            int mid = (lo + hi) / 2;
            ll blw = ds.query(mid) - 1;
            ll rem = N - a;
            //cout << mid << " gets " << blw << " sum " << blw + rem * (rem - 1) / 2 << endl;
            if(blw < rem && (blw < 0 || blw + rem * (rem - 1) / 2 < K)){
                lo = mid + 1;
            } else {
                hi = mid - 1;
            }
        }
        ds.update(lo, -1);
        cout << lo << " ";
    }
}
