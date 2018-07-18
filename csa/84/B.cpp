#include<bits/stdc++.h>

using namespace std;

#define allof(x) (x).begin(), (x).end()

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

int N;
string str;
bool good(int K){
    int tot = 0;
    for(int a = 0; a < N; a++){
        tot += (str[a] == '1');
        if(a >= K){
            tot -= (str[a - K] == '1');
        }

        if(a >= K - 1 && tot < 3){
            return false;
        }
    }

    return true;
}

int main(){
    cin.tie(0);
    cin.sync_with_stdio(0);

    cin >> N >> str;

    int lo = 3, hi = N;
    while(lo <= hi){
        int mid = (lo + hi) / 2;
        if(!good(mid)){
            lo = mid + 1;
        } else {
            hi = mid - 1;
        }
    }

    cout << lo;
}
