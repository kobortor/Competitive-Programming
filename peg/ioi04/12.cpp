#include<bits/stdc++.h>

using namespace std;

#define allof(x) (x).begin(), (x).end()

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

const int MAXN = 20005;

int N, T;

struct tree {
    int x, y, id;
} tr[MAXN];

int num_blw[MAXN];
int num_abv[MAXN];

int main(){
    cin.tie(0);
    cin.sync_with_stdio(0);

    cin >> N;
    cin >> T;

    for(int a = 1; a <= N; a++){
        cin >> tr[a].x >> tr[a].y;
        tr[a].id = a;
    }

    sort(tr + 1, tr + N + 1, [](const tree &t1, const tree &t2){
        return t1.x < t2.x;
    });

    int ans = 1e9;
    pii soln;

    for(int a = 1; a <= N; a++){
        int cur_abv = 0, cur_blw = 0;
        for(int b = a - 1; b >= 1; b--){
            if(tr[b].y < tr[a].y){
                int real_abv = num_abv[b] - cur_abv;

                if(2 + real_abv >= T && 2 + real_abv < ans){
                    ans = 2 + real_abv;
                    soln = pii(tr[a].id, tr[b].id);
                }

                cur_blw++;
                num_abv[b]++;
            } else {
                int real_blw = num_blw[b] - cur_blw;

                if(2 + real_blw >= T && 2 + real_blw < ans){
                    ans = 2 + real_blw;
                    soln = pii(tr[a].id, tr[b].id);
                }

                cur_abv++;
                num_blw[b]++;
            }
        }
    }

    cout << soln.first << " " << soln.second;
}
