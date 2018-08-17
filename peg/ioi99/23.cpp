#include<bits/stdc++.h>

using namespace std;

#define allof(x) (x).begin(), (x).end()

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

const int MAXN = 705;
const int MAXL = 10;

int U, V, C;

int grid[MAXN][MAXN];
int mn[MAXN][MAXN];
int mx[MAXN][MAXN];

struct mydeque {
    int L = 0, R = 0;
    pii data[MAXN];
    void push_back(const pii &p){
        data[R++] = p;
    }
    void pop_front(){
        L++;
    }
    void pop_back(){
        R--;
    }
    pii front(){
        return data[L];
    }
    pii back(){
        return data[R - 1];
    }
    bool empty(){
        return L == R;
    }
    void clear(){
        L = R = 0;
    }
};

int main(){
    cin.tie(0);
    cin.sync_with_stdio(0);

    cin >> U >> V >> C;

    for(int a = V; a >= 1; a--){
        for(int b = 1; b <= U; b++){
            cin >> grid[a][b];
        }
    }

    memset(mn, 0x3f, sizeof mn);
    memset(mx, 0xaf, sizeof mx);

    int best = 0;
    pair<pii, pii> out;

    for(int wid = 1; wid <= min(100, U); wid++){
        for(int a = 1; a <= V; a++){
            for(int b = 1; b + wid - 1 <= U; b++){
                if(b + wid - 1 <= U){
                    mn[a][b] = min(mn[a][b], grid[a][b + wid - 1]);
                    mx[a][b] = max(mx[a][b], grid[a][b + wid - 1]);
                }
            }
        }

        for(int b = 1; b + wid - 1 <= U; b++){
            mydeque dqmn, dqmx;
            for(int a = 1, back = 1; a <= V; a++){
                if(mx[a][b] - mn[a][b] > C){
                    back = a + 1;
                    dqmn.clear();
                    dqmx.clear();
                    continue;
                }
                while(!dqmn.empty() && dqmn.back().first >= mn[a][b]){
                    dqmn.pop_back();
                }
                while(!dqmx.empty() && dqmx.back().first <= mx[a][b]){
                    dqmx.pop_back();
                }

                dqmn.push_back({mn[a][b], a});
                dqmx.push_back({mx[a][b], a});

                while(dqmx.front().first - dqmn.front().first > C){
                    back++;
                    if(dqmn.front().second < back){
                        dqmn.pop_front();
                    }
                    if(dqmx.front().second < back){
                        dqmx.pop_front();
                    }
                }

                int size = (a - back + 1) * wid;
                if(size > best){
                    best = size;
                    out = make_pair(pii(b, back), pii(b + wid - 1, a));
                }
            }
        }
    }

    cout << out.first.first << " " << out.first.second << " " << out.second.first << " " << out.second.second << endl;
}
