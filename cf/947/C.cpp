#include<bits/stdc++.h>

using namespace std;

#define allof(x) (x).begin(), (x).end()

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

const int MAXN = 32*(3e5 + 5);

int N;

int cnt = 1;
struct node {
    int child[2];
    int sz = 0;
} tr [MAXN];

int msg[MAXN];

int main(){
    cin.tie(0);
    cin.sync_with_stdio(0);

    cin >> N;
    for(int a = 0; a < N; a++){
        cin >> msg[a];
    }
    for(int a = 0; a < N; a++){
        int x;
        cin >> x;
        int cur = 0;
        for(int b = 31; b >= 0; b--){
            int bit = (x >> b) & 1;
            if(!tr[cur].child[bit]){
                tr[cur].child[bit] = cnt++;
            }
            cur = tr[cur].child[bit];
            tr[cur].sz++;
        }
    }

    for(int a = 0; a < N; a++){
        int x = msg[a];
        int cur = 0;
        int ans = 0;
        for(int b = 31; b >= 0; b--){
            int bit = (x >> b) & 1;
            if(!tr[cur].child[bit] || tr[tr[cur].child[bit]].sz == 0){
                cur = tr[cur].child[!bit];
                ans |= (1 << b);
            } else {
                cur = tr[cur].child[bit];
            }
            tr[cur].sz--;
        }
        cout << ans << " ";
    }
}
