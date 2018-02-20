#include<bits/stdc++.h>

using namespace std;

#define allof(x) (x).begin(), (x).end()

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

const int MAXN = 105;

int N;

int pokemon[MAXN];
int ans[MAXN];

int main(){
    cin.tie(0);
    cin.sync_with_stdio(0);

    cin >> N;

    for(int a = 0; a < N; a++){
        cin >> pokemon[a];
    }

    int cur = 0;
    for(int a = 1; a < N; a++){
        if(pokemon[a] > pokemon[cur]){
            cur = a;
        }
        ans[cur]++;
    }

    for(int a = 0; a < N; a++){
        cout << ans[a] << " ";
    }
}
