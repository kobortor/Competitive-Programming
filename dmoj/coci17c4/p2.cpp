#include<bits/stdc++.h>

using namespace std;

#define allof(x) (x).begin(), (x).end()

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

const int MAXN = 100;
const int MAXM = 15;

int N, M, K;

int ord[MAXN][MAXM];
int votes[MAXM];

int main(){
    cin.tie(0);
    cin.sync_with_stdio(0);

    cin >> N >> M >> K;
    K--;

    for(int a = 0; a < N; a++){
        for(int b = 0; b < M; b++){
            cin >> ord[a][b];
            ord[a][b]--;
        }
        votes[ord[a][0]]++;
    }

    cout << max_element(votes, votes + M) - votes + 1 << "\n";

    int best = 999;
    for(int st = 1; st < (1 << M); st++){
        memset(votes, 0, sizeof votes);
        for(int a = 0; a < N; a++){
            for(int b = 0; b < M; b++){
                if(st & (1 << ord[a][b])){
                    votes[ord[a][b]]++;
                    break;
                }
            }
        }
        if(max_element(votes, votes + M) - votes == K){
            int cnt = 0;
            for(int a = 0; a < M; a++){
                if(!(st & (1 << a))){
                    cnt++;
                }
            }
            best = min(best, cnt);
        }
    }
    cout << best;
}
