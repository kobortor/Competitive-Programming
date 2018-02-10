#include<bits/stdc++.h>

using namespace std;

#define allof(x) (x).begin(), (x).end()

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

const int MAXN = 1e8 + 8;

int N;

int main(){
    cin.tie(0);
    cin.sync_with_stdio(0);

    cin >> N;

    int prvstep = N - 1;
    int steps = 0;
    while(steps < 500 && N != 0){
        if(N & 1){
            cout << 1 << endl;
            N--;
        } else {
            int tmp = 1;
            while(1){
                int bit1 = N & -N;
                int bit2 = (N - tmp) & -(N - tmp);
                if(bit1 <= bit2){
                    cout << tmp << endl;
                    N -= tmp;
                    break;
                } else {
                    tmp *= 2;
                }
            }
        }

        if(N == 0){
            break;
        }
        int ai;
        cin >> ai;
        N -= ai;
    }
    
}
