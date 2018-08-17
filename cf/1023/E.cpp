#include<bits/stdc++.h>

using namespace std;

#define allof(x) (x).begin(), (x).end()

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

const int MAXN = 505;

char grid[MAXN][MAXN];
bool vis[MAXN][MAXN];

bool ask(int r1, int c1, int r2, int c2){
    cout << "? " << r1 << " " << c1 << " " << r2 << " " << c2 << endl;

    string ans;
    cin >> ans;
    return ans == "YES";
}

int main(){
    cin.tie(0);
    cin.sync_with_stdio(0);

    int N;
    cin >> N;

    vector<pii> pos1;
    pos1.push_back(pii(1, 1));
    int r1 = 1, c1 = 1;
    for(int a = 1; a <= N - 2; a++){
        if(ask(r1, c1 + 1, N, N)){
            c1++;
        } else {
            r1++;
        }
        pos1.push_back(pii(r1, c1));
    }

    vector<pii> pos2;
    int r2 = N, c2 = N;
    for(int a = 1; a <= N - 1; a++){
        pii prv = pos1[pos1.size() - a];

        if(ask(prv.first, prv.second, r2 - 1, c2)){
            r2--;
        } else {
            c2--;
        }
        pos2.push_back({r2, c2});
    }

    pos1.insert(pos1.end(), pos2.rbegin(), pos2.rend());

    pos1.push_back({N, N});

    cout << "! ";
    for(int a = 1; a < (int)pos1.size(); a++){
        if(pos1[a].first != pos1[a - 1].first){
            cout << "D";
        } else {
            cout << "R";
        }
    }
}

