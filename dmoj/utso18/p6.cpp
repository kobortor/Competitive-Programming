#include<bits/stdc++.h>

using namespace std;

#define allof(x) (x).begin(), (x).end()

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

int N, Q;
int pow3[10];
ll ds[1 << 9][19683];
int val[1 << 18];

vector<int> map1[19683]; //pow3 -> pow2
vector<int> map2[1 << 9]; //pow2 -> pow3

void update(int pos, int val){
    int v1 = pos >> 9;
    int v2 = pos & ((1 << 9) - 1);

    for(int i : map2[v2]){
        ds[v1][i] += val;
    }
}

int topow3(int a, int b){
    int ans = 0;
    for(int i = 0; i < 9; i++){
        int bita = (a >> i) & 1;
        int bitb = (b >> i) & 1;
        if(bita == bitb){
            ans += bita * pow3[i];
        } else {
            ans += 2 * pow3[i];
        }
    }
    return ans;
}

int main(){
    cin.tie(0);
    cin.sync_with_stdio(0);

    pow3[0] = 1;
    for(int a = 1; a < 10; a++){
        pow3[a] = pow3[a - 1] * 3;
    }

    for(int i = 0; i < (1 << 9); i++){
        for(int j = 0; j < (1 << 9); j++){
            int tmp = 0;
            for(int k = 0; k < 9; k++){
                if(j & (1 << k)){
                    tmp += 2 * pow3[k];
                } else {
                    tmp += ((i >> k) & 1) * pow3[k];
                }
            }
            map1[tmp].push_back(i);
            map2[i].push_back(tmp);
        }
    }

    cin >> N >> Q;
    for(int a = 0; a < (1 << N); a++){
        cin >> val[a];
        update(a, val[a]);
    }

    while(Q--){
        int tp;
        cin >> tp;
        if(tp == 1){
            int s, v;
            cin >> s >> v;
            update(s, v - val[s]);
            val[s] = v;
        } else {
            int a, b;
            cin >> a >> b;

            if((a & b) != a){
                cout << "0\n";
                continue;
            }

            int v1 = topow3(a >> 9, b >> 9);
            int v2 = topow3(a & ((1 << 9) - 1), b & ((1 << 9) - 1));
            
            ll ans = 0;
            for(int i : map1[v1]){
                ans += ds[i][v2];
            }

            cout << ans << "\n";
        }
    }
}
