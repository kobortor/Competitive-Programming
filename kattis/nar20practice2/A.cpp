#include<bits/stdc++.h>

// Created by $%U%$ On $%h%$:$%m%$:$%s%$ on $%D%$-$%M%$-$%Y%$

using namespace std;

#define allof(x) (x).begin(), (x).end()

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

const int MAXN = 105;

int M, N;
double R;

vector<pair<pii, double>> adj[MAXN][MAXN];

double dist[MAXN][MAXN];

int main(){
    cin.tie(0);
    cin.sync_with_stdio(0);

    // M = number of pie slices
    // N = number of half rings

    cin >> M >> N >> R;

    double circum = R * 2 * 3.14159265359;

    for (int i = 0; i <= M; i++) {     // half rings
        for (int j = 0; j <= N; j++) { // slices
            dist[i][j] = 1e18;
            if (i != 0) {
                // change a slice
                double tmp_r = (circum * ((double)j / N)) / (2 * M);
                // cout << i - 1 << " " << j << " to " << i << " " << j << " is " << tmp_r << endl;
                adj[i][j].push_back(make_pair(pii(i - 1, j), tmp_r));
                adj[i - 1][j].push_back(make_pair(pii(i, j), tmp_r));
            } 
            if (j != 0) {
                // drop down a ring
                // cout << i << " " << j - 1 << " to " << i << " " << j << " is " << R / N << endl;
                adj[i][j].push_back(make_pair(pii(i, j - 1), R / N));
                adj[i][j - 1].push_back(make_pair(pii(i, j), R / N));
            }
        }
    }

    int ax, ay, bx, by;
    cin >> ax >> ay >> bx >> by;

    dist[ax][ay] = 0;
    priority_queue<pair<double, pii>, vector<pair<double, pii>>, greater<pair<double, pii>>> pq;

    pq.push(make_pair(0, pii(ax, ay)));

    while (!pq.empty()) {
        double d = pq.top().first;
        int x = pq.top().second.first;
        int y = pq.top().second.second;
        pq.pop();

        for (auto au : adj[x][y]) {
            if (d + au.second < dist[au.first.first][au.first.second]) {
                dist[au.first.first][au.first.second] = d + au.second;
                pq.push(make_pair(d + au.second, au.first));
            }
        }
    }

    cout << fixed << setprecision(15) << dist[bx][by] << endl;
}
