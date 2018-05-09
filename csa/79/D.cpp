#include<bits/stdc++.h>

using namespace std;

#define allof(x) (x).begin(), (x).end()

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

const int MAXN = 1e5 + 5;

int N, K, Q;

set<int> groups[MAXN];
int rep[MAXN];

int main(){
    cin.tie(0);
    cin.sync_with_stdio(0);

    memset(rep, -1, sizeof rep);

    cin >> N >> K >> Q;
    for(int a = 1; a <= K; a++){
        int Si;
        cin >> Si;
        for(int b = 1; b <= Si; b++){
            int x;
            cin >> x;
            if(b == 1) {
                rep[x] = a;
            }

            groups[a].insert(x);
        }
    }

    while(Q--){
        set<int> rem;
        
        int Pi;
        cin >> Pi;
        for(int a = 1; a <= Pi; a++){
            int x;
            cin >> x;
            rem.insert(x);
        }

        int ans = 0;
        for(int i : rem){
            if(rep[i] != -1 && groups[rep[i]].size() <= rem.size()){
                bool good = true;
                for(int j : groups[rep[i]]){
                    if(!rem.count(j)){
                        good = false;
                        break;
                    }
                }
                if(good){
                    ans++;
                }
            }
        }
        cout << ans << "\n";
    }
}
