#include<bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

int best = -1e9;

int main(){
    cin.tie(0);
    cin.sync_with_stdio(0);
    int N;

    cin >> N;
    while(N--){
        int x;
        cin >> x;
        if(x < 0){
            best = max(best, x);
        } else {
            int sq = sqrt(x);
            if(sq * sq != x){
                best = max(best, x);
            }
        }
    }
    cout << best;
}
