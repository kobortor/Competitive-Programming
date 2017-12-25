#include<bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

const int MAXN = 1e5 + 5;

int N;
int ans[MAXN];
int lft[MAXN];
int rht[MAXN];

int main(){
    cin.tie(0);
    cin.sync_with_stdio(0);

    cin >> N;
    for(int a = 1; a <= N; a++) {
        cin >> lft[a];
    }
    for(int a = 1; a <= N; a++) {
        cin >> rht[a];
    }
    for(int a = 1; a < N; a++){
        if(lft[a] == lft[a + 1]){
            ans[a] = 1;
        }
        if(rht[a] == rht[a + 1]){
            ans[a + 1] = 1;
        }
    }
    for(int a = 1; a <= N; a++){
        cout << ans[a];
    }
}