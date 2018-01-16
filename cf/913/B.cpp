#include<bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

const int MAXN = 1005;

int N;

bool is_leaf[MAXN];
int par[MAXN];
int cnt[MAXN];

int main(){
    cin.tie(0);
    cin.sync_with_stdio(0);

    cin >> N;
    for(int a = 2; a <= N; a++){
        is_leaf[a] = true;
        cin >> par[a];
        is_leaf[par[a]] = false;
    }
    for(int a = N; a >= 1; a--){
        if(is_leaf[a]){
            cnt[par[a]]++;
        } else if (cnt[a] < 3){
            cout << "No\n";
            return 0;
        }
    }
    cout << "Yes\n";
}
