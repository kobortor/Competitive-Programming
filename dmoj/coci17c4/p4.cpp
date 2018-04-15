#include<bits/stdc++.h>

using namespace std;

#define allof(x) (x).begin(), (x).end()

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

const int MAXN = 5005;

int N, M, K;

bool is_goat[MAXN];
int prvlose[MAXN];
int prvwin[MAXN];

int main(){
    cin.tie(0);
    cin.sync_with_stdio(0);

    cin >> N >> M >> K;
    for(int a = 0; a < N; a++){
        cin >> is_goat[a];
        prvlose[a] = M - 1;
        prvwin[a] = 999999999;
    }
    is_goat[N] = is_goat[0];

    for(int b = M - 2; b >= 0; b--){
        prvlose[N] = prvlose[0];
        prvwin[N] = prvwin[0];
        for(int a = 0; a < N; a++){
            int nxt = a + 1;
            if(is_goat[a] == is_goat[nxt]){
                if(prvwin[nxt] - b <= K){
                    prvwin[a] = b;
                } else {
                    prvlose[a] = b;
                }
            } else {
                if(prvlose[nxt] - b <= K){
                    prvwin[a] = b;
                } else {
                    prvlose[a] = b;
                }
            }
        }
    }
    for(int a = 0; a < N; a++){
        cout << (!prvwin[a] == is_goat[a]) << " ";
    }
}
