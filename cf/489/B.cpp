#include<bits/stdc++.h>

using namespace std;

#define allof(x) (x).begin(), (x).end()

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

const int MAXN = 1e5 + 5;

int N, M;
int boys[MAXN];
int girls[MAXN];

int main(){
    cin.tie(0);
    cin.sync_with_stdio(0);

    cin >> N;
    for(int a = 0; a < N; a++){
        cin >> boys[a];
    }
    cin >> M;
    for(int a = 0; a < M; a++){
        cin >> girls[a];
    }
    sort(boys, boys + N);
    sort(girls, girls + M);

    int ans = 0;
    for(int a = 0, b = 0; a < N; a++){
        while(b < M && girls[b] - boys[a] <= 1){
            if(abs(girls[b] - boys[a]) <= 1){
                ans++;
                b++;
                break;
            }
            b++;
        }
    }
    cout << ans;
}
