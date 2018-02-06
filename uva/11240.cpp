#include<bits/stdc++.h>

using namespace std;

#define allof(x) (x).begin(), (x).end()

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

const int MAXN = 30005;

int T;

struct BIT {
    int data[MAXN];
    void update(int pos, int val){
        while(pos < MAXN){
            data[pos] = max(data[pos], val);
            pos += pos & -pos;
        }
    }
    int query(int pos){
        int ans = -99999;
        while(pos){
            ans = max(ans, data[pos]);
            pos -= pos & -pos;
        }
        return ans;
    }
}ds1, ds2;

int main(){
    cin.tie(0);
    cin.sync_with_stdio(0);

    cin >> T;
    while(T--){
        for(int a = 0; a < MAXN; a++){
            ds1.data[a] = 0;
            ds2.data[a] = -99999;
        }

        int N;
        cin >> N;

        int best = 0;

        for(int a = 0; a < N; a++) {
            int x;
            cin >> x;
            int q1 = ds1.query(x);
            int q2 = ds2.query(30001 - x);

            best = max(q1, q2) + 1;

            ds1.update(x, q2 + 1);
            ds2.update(30001 - x, q1 + 1);
        }
        cout << best << "\n";
    }
}
