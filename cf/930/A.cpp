#include<bits/stdc++.h>

using namespace std;

#define allof(x) (x).begin(), (x).end()

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

const int MAXN = 1e5 + 5;

int dist[MAXN];
int N;
int dep[MAXN];

int main(){
    cin.tie(0);
    cin.sync_with_stdio(0);

    cin >> N;
    for(int a = 2; a <= N; a++){
        int x;
        cin >> x;
        dep[a] = dep[x] + 1;
        dist[dep[a]]++;
    }
    int ans = 1;
    for(int a = 1; a <= N; a++){
        if(dist[a] & 1){
            ans++;
        }
    }
    cout << ans;
}
