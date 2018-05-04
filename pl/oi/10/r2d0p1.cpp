#include<bits/stdc++.h>

using namespace std;

#define allof(x) (x).begin(), (x).end()

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

const int MAXN = 10;

int C;
int A[MAXN], B[MAXN];
int num[MAXN][MAXN];
bool has[MAXN][MAXN];

int tmpA[MAXN], tmpB[MAXN];
int gen[MAXN];
bool used[MAXN];
void recur(int pos){
    if(pos == C){
        bool good = true;
        for(int a = 0; a < C; a++){
            good &= A[a] == tmpA[a];
            good &= B[a] == tmpB[a];
        }
        if(good){
            for(int a = 0; a < C; a++){
                cout << gen[a] << " ";
            }
            exit(0);
        }
    }

    for(int a = 1; a <= 9; a++){
        if(!used[a]){
            used[a] = true;

            gen[pos] = a;
            for(int b = 0; b < C; b++){
                if(num[b][pos] == a){
                    tmpA[b] += a;
                } else if (has[b][a]){
                    tmpB[b] += a;
                }
            }
            recur(pos + 1);
            for(int b = 0; b < C; b++){
                if(num[b][pos] == a){
                    tmpA[b] -= a;
                } else if (has[b][a]){
                    tmpB[b] -= a;
                }
            }

            used[a] = false;
        }
    }
}

int main(){
    cin.tie(0);
    cin.sync_with_stdio(0);

    cin >> C;
    for(int a = 0; a < C; a++){
        cin >> A[a] >> B[a];
        for(int b = 0; b < C; b++){
            cin >> num[a][b];
            has[a][num[a][b]] = true;
        }
    }

    recur(0);
}
