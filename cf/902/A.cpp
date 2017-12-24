#include<bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

const int MAXN = 105;
int teleport[MAXN];

int main(){
    cin.tie(0);
    cin.sync_with_stdio(0);

    int N, M;
    cin >> N >> M;

    while(N--){
        int ai, bi;
        cin >> ai >> bi;
        teleport[ai] = max(teleport[ai], bi);
    }

    int limit = 0;
    for(int a = 0; a <= limit; a++){
        if(a == M){
            cout << "YES\n";
            return 0;
        }
        limit = max(limit, teleport[a]);
    }
    cout << "NO\n";
}