#include<bits/stdc++.h>

using namespace std;

#define allof(x) (x).begin(), (x).end()

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

int N, C;

bool req0[6];
bool req1[6];

bool vec[1 << 6];
bool tmp[1 << 6];

int main(){
    cin.tie(0);
    cin.sync_with_stdio(0);

    cin >> N;
    cin >> C;

    while(true){
        int x;
        cin >> x;
        if(x == -1){
            break;
        }

        x = (x - 1) % 6;

        req1[x] = true;
    }

    while(true){
        int x;
        cin >> x;
        if(x == -1){
            break;
        }

        x = (x - 1) % 6;

        req0[x] = true;

        if(req1[x]){
            cout << "IMPOSSIBLE\n";
            return 0;
        }
    }

    vec[0b111111] = true;
    while(C--){
        for(int a = 0; a < (1 << 6); a++){
            if(!vec[a]){
                continue;
            }
            tmp[a ^ 0b111111] = true;
            tmp[a ^ 0b010101] = true;
            tmp[a ^ 0b101010] = true;
            tmp[a ^ 0b001001] = true;
        }

        memcpy(vec, tmp, sizeof tmp);
        memset(tmp, 0, sizeof tmp);
    }

    bool printed = false;
    for(int a = 0; a < (1 << 6); a++){
        bool good = vec[a];
        for(int b = 0; b < 6; b++){
            good &= !req1[b] || ((a >> b) & 1);
            good &= !req0[b] || !((a >> b) & 1);
        }

        if(good){
            printed = true;
            for(int b = 0; b < N; b++){
                cout << ((a >> (b % 6)) & 1);
            }
            cout << "\n";
        }
    }

    if(!printed){
        cout << "IMPOSSIBLE\n";
    }
}
