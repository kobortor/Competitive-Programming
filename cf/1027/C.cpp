#include<bits/stdc++.h>

using namespace std;

#define allof(x) (x).begin(), (x).end()

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

const int MAXA = 1e4 + 4;

int T, N;
int prv[MAXA];

int main(){
    cin.tie(0);
    cin.sync_with_stdio(0);

    memset(prv, -1, sizeof prv);

    cin >> T;

    while(T--){
        cin >> N;
        
        vector<int> pairs;
        while(N--){
            int x;
            cin >> x;
            if(prv[x] == T){
                pairs.push_back(x);
                prv[x] = -1;
            } else {
                prv[x] = T;
            }
        }

        sort(allof(pairs));

        double best = 1e9;
        pii ans = pii(-1, -1);

        for(int a = 1; a < (int)pairs.size(); a++){
            double val = 8 + (double)pairs[a] / pairs[a - 1] + (double)pairs[a - 1] / pairs[a];
            if(val < best){
                best = val;
                ans = pii(pairs[a - 1], pairs[a]);
            }
        }

        cout << ans.first << " " << ans.first << " " << ans.second << " " << ans.second << "\n";
    }
}
