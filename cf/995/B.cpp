#include<bits/stdc++.h>

using namespace std;

#define allof(x) (x).begin(), (x).end()

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

const int MAXN = 205;

int N;
int arr[MAXN];
bool vis[MAXN];

int res[MAXN];

int main(){
    cin.tie(0);
    cin.sync_with_stdio(0);

    cin >> N;

    int seen = 1;

    for(int a = 1; a <= 2 * N; a++){
        int x;
        cin >> x;
        arr[a] = x;
        if(!vis[x]){
            res[seen] = x;
            res[seen + 1] = x;
            seen += 2;
            vis[x] = true;
        }
    }

    for(int a = 1; a <= 2 * N; a++){
        arr[a] = find(res + 1, res + 2 * N + 1, arr[a]) - res;
        res[arr[a]] = -1;
        //cout << arr[a] << " ";
    }
    //cout << endl;

    int ans = 0;
    for(int a = 1; a <= 2 * N; a++){
        for(int b = 1; b < a; b++){
            if(arr[a] < arr[b]){
                ans++;
            }
        }
    }
    cout << ans;
}
