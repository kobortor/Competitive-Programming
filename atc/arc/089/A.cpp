#include<bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

const int MAXN = 1e5 + 5;

int N;
int pt, px, py;
int t, x, y;

int main(){
    cin.tie(0);
    cin.sync_with_stdio(0);

    cin >> N;
    for(int a = 0; a < N; a++){
        cin >> t >> x >> y;
        int dist = abs(x - px) + abs(y - py);
        int tm = t - pt;
        if(dist > tm || dist % 2 != tm % 2){
            cout << "No";
            return 0;
        }
        pt = t;
        px = x;
        py = y;
    }
    cout << "Yes";
}
