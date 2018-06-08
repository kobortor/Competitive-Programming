#include<bits/stdc++.h>

using namespace std;

#define allof(x) (x).begin(), (x).end()

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

const int MAXN = 2005;

int N;
int val[MAXN];

int main(){
    cin.tie(0);
    cin.sync_with_stdio(0);

    cin >> N;
    for(int a = 0; a < N; a++){
        cin >> val[a];
    }
    for(int a = 0; a < N; a++){
        int ans = 1;
        for(int b = 0; b < N; b++){
            if(val[b] > val[a]){
                ans++;
            }
        }
        cout << ans << " ";
    }
}
