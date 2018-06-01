#include<bits/stdc++.h>

using namespace std;

#define allof(x) (x).begin(), (x).end()

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

const int MAXN = 1e5 + 5;

int N, C;
int stall[MAXN];

bool good(int len){
    int prvv = -1e9;
    int remain = C;

    for(int a = 0; a < N; a++){
        if(stall[a] - prvv >= len){
            remain--;
            prvv = stall[a];
            if(!remain) {
                return true;
            }
        }
    }

    return false;
}

int main(){
    cin.tie(0);
    cin.sync_with_stdio(0);

    int T;
    cin >> T;
    while(T--){
        cin >> N >> C;
        for(int a = 0; a < N; a++) {
            cin >> stall[a];
        }
        sort(stall, stall + N);

        int lo = 0, hi = 1e9;
        while(lo <= hi){
            int mid = (lo + hi) / 2;
            if(good(mid)){
                lo = mid + 1;
            } else {
                hi = mid - 1;
            }
        }
        cout << hi << "\n";
    }
}
