#include<bits/stdc++.h>

using namespace std;

#define allof(x) (x).begin(), (x).end()

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;



int main(){
    cin.tie(0);
    cin.sync_with_stdio(0);

    int N, M;
    cin >> N >> M;

    set<int> s1;
    int ans = 0;
    int sum = 0;

    while(N--){
        int x;
        cin >> x;
        sum += x;

        s1.insert(sum);
    }

    sum = 0;
    while(M--){
        int x;
        cin >> x;
        sum += x;

        if(s1.count(sum)){
            ans++;
        }
    }
    cout << ans;
}
