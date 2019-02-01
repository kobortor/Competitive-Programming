#include<bits/stdc++.h>

using namespace std;

#define allof(x) (x).begin(), (x).end()

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;



int main(){
    cin.tie(0);
    cin.sync_with_stdio(0);

    int N;
    cin >> N;

    vector<int> v(N);
    for(int a = 0; a < N; a++){
        cin >> v[a];
    }

    sort(allof(v));

    int x = v.back();

    int ans = 1;
    for(int a = 2; a < N; a++){
        if(x % v[a] != 0 || v[a] == v[a - 1]){
            ans = v[a];
        }
    }
    cout << x << " " << ans;
}
