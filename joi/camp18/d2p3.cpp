#include<bits/stdc++.h>

using namespace std;

#define allof(x) (x).begin(), (x).end()

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

const int MAXN = 5e5 + 5;

int N, Q;
int step[MAXN];

int inter(int l1, int r1, int l2, int r2){
    if(l1 > l2){
        swap(l1, l2);
        swap(r1, r2);
    }

    if(r1 < l2){
        return 0;
    }
    
    return min(r1, r2) - l2 + 1;
}

int main(){
    cin.tie(0);
    cin.sync_with_stdio(0);

    cin >> N >> Q;
    step[0] = 1;
    for(int a = 1; a <= N; a++){
        cin >> step[a];
    }
    for(int a = 1; a <= N; a++){
        step[a] = (step[a] + step[a - 1] - 1) / step[a - 1] * step[a - 1];
        if(step[a] > 1e9){
            while(N >= a){
                N--;
            }
            break;
        }

        //either same or at least double!
    }

    vector<pair<int, pii>> blocks;
    for(int a = 0; a <= N; a++){
        int b = a;
        while(b + 1 <= N && step[b + 1] == step[a]){
            b++;
        }
        blocks.push_back({step[a], {a, b}});

        a = b;
    }

    while(Q--){
        int T, L, R;
        cin >> T >> L >> R;

        int ans = 0;
        for(pair<int, pii> p : blocks){
            int moved = T / p.first * p.first;
            int l = -p.second.second + moved;
            int r = -p.second.first + moved;

            ans += inter(L, R, l, r);
        }
        cout << ans << "\n";
    }
}
