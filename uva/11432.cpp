#include<bits/stdc++.h>

using namespace std;
template<typename T>
using minheap = priority_queue<T, vector<T>, greater<T>>;
template<typename T>
using maxheap = priority_queue<T>;
//typedef long long ll;
typedef unsigned long long llu;
typedef pair<int, int> pii;
//typedef pair<ll, ll> pll;

//[days worked on first project][days worked on second project][0 - first project, 1 - second project][how many days away from other]
llu dp[35][35][2][35];
int incoming[35][35][2][35];
struct quad {
    int a, b, c, d;
    quad(int A, int B, int C, int D) {
        a = A;
        b = B;
        c = C;
        d = D;
    }
};
vector<quad> adj[35][35][2][35];

bool solved[35][35];
llu stored[35][35];

int main() {
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#else
    cin.tie(0);
    cin.sync_with_stdio(0);
#endif
    memset(stored, -1, sizeof(stored));

    for(int test = 1; true; test++) {
        int D, G;
        cin >> D >> G;

        if(D == -1 && G == -1) {
            break;
        }

        if(D == 0 || G == 0) {
            cout << "Case " << test << ": " << 0 << "\n";
            continue;
        }

        if(solved[D][G]) {
            cout << "Case " << test << ": " << stored[D][G] << "\n";
            continue;
        }

        for(int a = 1; a <= D; a++) {               //first project status
            for(int b = 0; b <= D; b++) {           //second project status
                for(int c = 0; c <= 1; c++) {       //which project currently
                    for(int d = 1; d <= G; d++) {   //how many days since last project
                        dp[a][b][c][d] = 0;
                        incoming[a][b][c][d] = 0;
                        adj[a][b][c][d].clear();
                    }
                }
            }
        }

        for(int a = 1; a < D; a++) {               //first project status
            for(int b = 0; b <= D; b++) {           //second project status
                for(int d = 1; d <= G; d++) {   //how many days since last project
                    //continue A
                    if(d != G) {
                        adj[a][b][0][d].push_back({a + 1, b, 0, d + 1});
                    }

                    //switch A -> B
                    if(b != D && b + 1 != D) {
                        adj[a][b][0][d].push_back({a, b + 1, 1, 1});
                    }

                    //switch B -> A
                    adj[a][b][1][d].push_back({a + 1, b, 0, 1});

                    //continue B
                    if(d != G) {
                        adj[a][b][1][d].push_back({a, b + 1, 1, d + 1});
                    }

                    for(const quad &q : adj[a][b][0][d]) {
                        incoming[q.a][q.b][q.c][q.d]++;
                    }

                    for(const quad &q : adj[a][b][1][d]) {
                        incoming[q.a][q.b][q.c][q.d]++;
                    }
                }
            }
        }

        queue<quad> q;

        dp[1][0][0][1] = 1;

        for(int a = 1; a < D; a++) {               //first project status
            for(int b = 0; b < D; b++) {           //second project status
                for(int c = 0; c <= 1; c++) {       //which project currently
                    for(int d = 1; d <= G; d++) {   //how many days since last project
                        if(!incoming[a][b][c][d] && !adj[a][b][c][d].empty()) {
                            q.push({a, b, c, d});
                        }
                    }
                }
            }
        }

        while(!q.empty()) {
            quad qd = q.front();
            q.pop();

            for(const quad &qq : adj[qd.a][qd.b][qd.c][qd.d]) {
                incoming[qq.a][qq.b][qq.c][qq.d]--;
                dp[qq.a][qq.b][qq.c][qq.d] += dp[qd.a][qd.b][qd.c][qd.d];

                if(!incoming[qq.a][qq.b][qq.c][qq.d]) {
                    q.push({qq.a, qq.b, qq.c, qq.d});
                }
            }
        }

        llu ans = 0;

        for(int b = 0; b < D; b++) {
            for(int c = 0; c < 2; c++) {
                for(int d = 1; d <= G; d++) {
                    ans += dp[D][b][c][d];
                }
            }
        }

        cout << "Case " << test << ": " << ans * 2 << "\n";
        solved[D][G] = true;
        stored[D][G] = ans * 2;
    }
}
