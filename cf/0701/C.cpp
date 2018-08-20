#include<bits/stdc++.h>

using namespace std;

#define allof(x) (x).begin(), (x).end()

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

int N;
string S;
int cnt[128];

int main(){
    cin.tie(0);
    cin.sync_with_stdio(0);

    cin >> N >> S;

    pii start = pii(-1, 0);
    for(int a = 0, tot = 0; a < N; a++){
        if(cnt[(int)S[a]] == 0){
            tot++;
            cnt[(int)S[a]]++;
        }

        if(tot > start.first){
            start = pii(tot, a);
        }
    }

    memset(cnt, 0, sizeof cnt);

    int ans = N;
    for(int a = 0, b = 0; a < N; a++){
        cnt[(int)S[a]]++;
        while(cnt[(int)S[b]] > 1){
            cnt[(int)S[b]]--;
            b++;
        }

        if(a >= start.second){
            ans = min(ans, a - b + 1);
        }
    }
    cout << ans;
}
