#include<bits/stdc++.h>

using namespace std;

#define allof(x) (x).begin(), (x).end()

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

const int MAXN = 1005;

int M, N, A, B, C, D;

int prefix[MAXN][MAXN];
pair<int, pii> best[MAXN][MAXN];
pair<int, pii> dq[MAXN];

int main(){
    cin.tie(0);
    cin.sync_with_stdio(0);

    cin >> M >> N >> A >> B >> C >> D;

    for(int a = 1; a <= N; a++){
        for(int b = 1; b <= M; b++){
            cin >> prefix[a][b];
            prefix[a][b] += prefix[a][b - 1];
        }

        for(int b = 1; b <= M; b++){
            prefix[a][b] += prefix[a - 1][b];
        }
    }

    for(int a = 1; a + D <= N; a++){
        int idl = 0, idr = -1;
        for(int b = M - C; b >= 1; b--){
            int tot = prefix[a + D][b + C] - prefix[a + D][b] - prefix[a][b + C] + prefix[a][b];
            while(idl <= idr && dq[idr].first >= tot){
                idr--;
            }

            dq[++idr] = {tot, {a, b}};
            while(idl <= idr && dq[idl].second.second - b > A - C - 2){
                idl++;
            }

            best[a][b] = dq[idl];
        }
    }

    for(int b = 1; b + C <= M; b++){
        int idl = 0, idr = -1;
        for(int a = N - D; a >= 1; a--){
            int tot = best[a][b].first;
            pii pos = best[a][b].second;

            while(idl <= idr && dq[idr].first >= tot){
                idr--;
            }

            dq[++idr] = {tot, pos};
            while(idl <= idr && dq[idl].second.first - a > B - D - 2){
                idl++;
            }

            best[a][b] = dq[idl];
        }
    }

    int best_tot = 0;
    pii pos1, pos2;

    for(int a = 1; a + B - 1 <= N; a++){
        for(int b = 1; b + A - 1 <= M; b++){
            int tot = prefix[a + B - 1][b + A - 1] - prefix[a + B - 1][b - 1] - prefix[a - 1][b + A - 1] + prefix[a - 1][b - 1] - best[a][b].first;

            if(tot > best_tot){
                best_tot = tot;

                pos1 = {a, b};
                pos2 = best[a][b].second;
            }
        }
    }

    cout << pos1.second << " " << pos1.first << "\n";
    cout << pos2.second + 1 << " " << pos2.first + 1 << "\n";
}
