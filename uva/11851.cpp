#include<bits/stdc++.h>

using namespace std;

#define allof(x) (x).begin(), (x).end()

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

ll pow3[15];

int main(){
    cin.tie(0);
    cin.sync_with_stdio(0);

    pow3[0] = 1;
    for(int a = 1; a < 15; a++){
        pow3[a] = pow3[a - 1] * 3;
    }

    while(1){
        int N;
        cin >> N;
        if(!N) break;
        vector<ll> vec[2];
        ll everything = 0;

        for(int a = 0; a < N; a++){
            ll x;
            cin >> x;
            everything += x;
            vec[a % 2].push_back(x);
        }
        map<ll, ll> found[2];
        for(int i = 0; i < 2; i++){
            for(int a = 0; a < pow3[vec[i].size()]; a++){
                int tmp = a;
                ll val = 0;
                ll tot = 0;
                for(int b = 0; b < (int)vec[i].size(); b++){
                    int op = tmp % 3;
                    tmp /= 3;
                    if(op == 1){
                        val += vec[i][b];
                        tot += vec[i][b];
                    } else if (op == 2){
                        val -= vec[i][b];
                        tot += vec[i][b];
                    }
                }
                found[i][val] = max(found[i][val], tot);
            }
        }

        ll ans = 0;
        for(pll p : found[0]){
            auto iter = found[1].find(p.first);
            if(iter != found[1].end()){
                ans = max(ans, p.second + iter->second);
            }
        }
        cout << everything - ans << endl;
    }
}
