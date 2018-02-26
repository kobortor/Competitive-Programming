#include<bits/stdc++.h>

using namespace std;

#define allof(x) (x).begin(), (x).end()

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

int cnt[605];

int main(){
    cin.tie(0);
    cin.sync_with_stdio(0);

    int N;
    cin >> N;
    while(N--){
        int x;
        cin >> x;
        cnt[x]++;
    }
    int ans = 0;
    for(int a = 600; a >= 1; a--){
        if(cnt[a]){
            ans++;
        }
    }
    cout << ans;
}
