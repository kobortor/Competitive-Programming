#include<bits/stdc++.h>


using namespace std;

#define allof(x) (x).begin(), (x).end()

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

const int MAXN = 1e6 + 6;

int N, M;

pii tele[MAXN * 4];
pii pos[MAXN];
bool vis[MAXN * 4];

int main(){ cin.tie(0);
    cin.sync_with_stdio(0);

    memset(pos, -1, sizeof pos);

    cin >> N >> M;

    for(int a = 1; a <= N; a++){
        int x, y;
        cin >> x >> y;

        tele[4 * a - 4] = {x, -a};
        tele[4 * a - 3] = {x, a};

        tele[4 * a - 2] = {y, -a};
        tele[4 * a - 1] = {y, a};
    }

    sort(tele, tele + 4 * N);

    for(int i = 0; i < 4 * N; i++){
        if(tele[i].second < 0){
            if(pos[-tele[i].second].first == -1){
                pos[-tele[i].second].first = i;
            } else {
                pos[-tele[i].second].second = i;
            }
        }
    }

    for(int i = 0; i < 4 * N; i++){
        if(tele[i].second < 0){
            tele[i].second = pos[-tele[i].second].first + pos[-tele[i].second].second - i + 1;
        } else {
            tele[i].second = i + 1;
        }
    }

    int cur = 0;
    int ans = 0;
    while(cur < 4 * N){
        vis[cur] = true;
        if(tele[cur].second != cur + 1){
            ans++;
        }
        cur = tele[cur].second;
    }

    vector<int> cycles;

    for(int i = 0; i < 4 * N; i++){
        if(!vis[i]){
            cur = i;
            int cyc = 0;

            do {
                vis[cur] = true;
                if(tele[cur].second != cur + 1){
                    cyc++;
                }
                cur = tele[cur].second;
            } while (!vis[cur]);

            cycles.push_back(cyc);
        }
    }

    sort(allof(cycles));

    while(M--){
        if(!cycles.empty()){
            ans += cycles.back() + 2;
            cycles.pop_back();
        } else {
            ans++;
            cycles.push_back(1);
        }
    }

    cout << ans;
}
