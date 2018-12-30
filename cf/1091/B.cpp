#include<bits/stdc++.h>

using namespace std;

#define allof(x) (x).begin(), (x).end()

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

const int MAXN = 1005;

int N;
pii coord[MAXN], dir[MAXN];

int main(){
    cin.tie(0);
    cin.sync_with_stdio(0);

    cin >> N;
    for(int a = 1; a <= N; a++){
        cin >> coord[a].first >> coord[a].second;
    }

    for(int a = 1; a <= N; a++){
        cin >> dir[a].first >> dir[a].second;
    }

    map<pii, int> soln;
    for(int a = 1; a <= N; a++){
        for(int b = 1; b <= N; b++){
            pii pos = pii(coord[a].first + dir[b].first, coord[a].second + dir[b].second);
            soln[pos]++;
        }
    }

    for(auto au : soln){
        if(au.second == N){
            cout << au.first.first << " " << au.first.second << endl;
            return 0;
        }
    }
}
