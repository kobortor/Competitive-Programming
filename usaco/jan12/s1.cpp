#include<bits/stdc++.h>

using namespace std;

#define allof(x) (x).begin(), (x).end()

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

const int MAXN = 105;

int N;
pii coords[MAXN];

vector<int> uniqr, uniqc;

bool blocked[3 * MAXN][3 * MAXN];
int dp[3 * MAXN][3 * MAXN];

bool good(int r, int c){
    if(r == 0 || r + 1 == (int)uniqr.size()){
        return false;
    }
    if(c == 0 || c + 1 == (int)uniqc.size()){
        return false;
    }
    return true;
}

int bfs(pii p1, pii p2){
    memset(dp, 0x3f, sizeof dp);

    priority_queue<pair<int, pii>, vector<pair<int, pii>>, greater<pair<int, pii>>> pq;
    pq.push({0, p1});

    dp[p1.first][p1.second] = 0;

    while(!pq.empty()){
        int dist;
        pii pos;
        
        tie(dist, pos) = pq.top();
        pq.pop();

        int r, c;
        tie(r, c) = pos;
        
        if(pos != p1 && blocked[r][c]){
            continue;
        }

        if(good(r - 1, c) && dist + abs(uniqr[r - 1] - uniqr[r]) < dp[r - 1][c]){
            dp[r - 1][c] = dist + abs(uniqr[r - 1] - uniqr[r]);
            pq.push({dp[r - 1][c], {r - 1, c}});
        }
        if(good(r + 1, c) && dist + abs(uniqr[r + 1] - uniqr[r]) < dp[r + 1][c]){
            dp[r + 1][c] = dist + abs(uniqr[r + 1] - uniqr[r]);
            pq.push({dp[r + 1][c], {r + 1, c}});
        }

        if(good(r, c - 1) && dist + abs(uniqc[c - 1] - uniqc[c]) < dp[r][c - 1]){
            dp[r][c - 1] = dist + abs(uniqc[c - 1] - uniqc[c]);
            pq.push({dp[r][c - 1], {r, c - 1}});
        }
        if(good(r, c + 1) && dist + abs(uniqc[c + 1] + uniqc[c]) < dp[r][c + 1]){
            dp[r][c + 1] = dist + abs(uniqc[c + 1] - uniqc[c]);
            pq.push({dp[r][c + 1], {r, c + 1}});
        }
    }

    if(dp[p2.first][p2.second] == 0x3f3f3f3f){
        return -1;
    } else {
        return dp[p2.first][p2.second];
    }
}

int main(){
    cin.tie(0);
    cin.sync_with_stdio(0);

    cin >> N;
    for(int a = 0; a < N; a++){
        int r, c;
        cin >> r >> c;
        coords[a] = {r, c};

        for(int diff = -1; diff <= 1; diff++){
            uniqr.push_back(r + diff);
            uniqc.push_back(c + diff);
        }
    }

    coords[N] = coords[0];

    uniqr.push_back(-999);
    uniqr.push_back(9999999);

    uniqc.push_back(-999);
    uniqc.push_back(9999999);

    sort(allof(uniqr));
    sort(allof(uniqc));

    uniqr.erase(unique(allof(uniqr)), uniqr.end());
    uniqc.erase(unique(allof(uniqc)), uniqc.end());

    for(int a = 0; a <= N; a++){
        int r = lower_bound(allof(uniqr), coords[a].first) - uniqr.begin();
        int c = lower_bound(allof(uniqc), coords[a].second) - uniqc.begin();

        coords[a] = {r, c};

        blocked[r][c] = true;
    }

    int ans = 0;
    for(int a = 0; a < N; a++){
        int tmp = bfs(coords[a], coords[a + 1]);
        if(tmp == -1){
            cout << "-1\n";
            return 0;
        } else {
            ans += tmp;
        }
    }
    cout << ans << "\n";
}
