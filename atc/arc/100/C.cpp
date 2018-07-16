#include<bits/stdc++.h>

using namespace std;

#define allof(x) (x).begin(), (x).end()

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

const int MAXN = 18;

int N;
pii arr[1 << MAXN];

pii merge(pii p1, pii p2){
    if(p1.first > p2.first){
        return pii(p1.first, max(p1.second, p2.first));
    } else {
        return pii(p2.first, max(p1.first, p2.second));
    }
}

int main(){
    cin.tie(0);
    cin.sync_with_stdio(0);

    cin >> N;
    
    for(int a = 0; a < (1 << N); a++){
        cin >> arr[a].first;
    }
    for(int b = 0; b < N; b++){
        for(int a = 0; a < (1 << N); a++){
            if(a & (1 << b)){
                continue;
            }

            arr[a | (1 << b)] = merge(arr[a | (1 << b)], arr[a]);
        }
    }

    int best = 0;
    for(int a = 1; a < (1 << N); a++){
        best = max(best, arr[a].first + arr[a].second);
        cout << best << "\n";
    }
}
