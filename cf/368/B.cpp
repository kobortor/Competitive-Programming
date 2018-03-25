#include<bits/stdc++.h>

using namespace std;

#define allof(x) (x).begin(), (x).end()

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

const int MAXN = 1e5 + 5;

int N, M;

bool vis[MAXN];
int arr[MAXN];

int main(){
    cin.tie(0);
    cin.sync_with_stdio(0);

    cin >> N >> M;
    for(int a = 1; a <= N; a++){
        cin >> arr[a];
    }
    for(int a = N; a >= 1; a--){
        if(!vis[arr[a]]){
            vis[arr[a]] = true;
            arr[a] = arr[a + 1] + 1;
        } else {
            arr[a] = arr[a + 1];
        }
    }
    while(M--){
        int x;
        cin >> x;
        cout << arr[x] << "\n";
    }
}
