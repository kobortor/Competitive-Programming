#include<bits/stdc++.h>

using namespace std;

#define allof(x) (x).begin(), (x).end()

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

const int MAXN = 1e4 + 4;

int N, M, T;

bitset<MAXN> trees[MAXN];

int high[MAXN];

int main(){
    cin.tie(0);
    cin.sync_with_stdio(0);

    cin >> N >> M >> T;
    for(int a = 0; a < T; a++){
        int r, c;
        cin >> r >> c;
        if(r == 0 || c == 0 || r == N || c == M){
            continue;
        } else {
            trees[r][c] = true;
        }
    }

    ll ans = 0;
    for(int a = 1; a <= N; a++){
        //<pos, ht>
        stack<pii> stk;
        stk.push(pii(0, 0));
        for(int b = 0; b < M; b++){
            high[b]++;

            while(stk.top().second >= high[b] && stk.top().second){
                ll ht = stk.top().second;
                stk.pop();
                ll wid = b - stk.top().first;
                ans = max(ans, ht * wid);
            }
            stk.push(pii(b, high[b]));

            if(trees[a][b]){
                high[b] = 0;
            }
        }
        while(stk.top().second != 0){
            ll ht = stk.top().second;
            stk.pop();
            ll wid = M - stk.top().first;
            ans = max(ans, ht * wid);
        }
    }
    cout << ans;
}
