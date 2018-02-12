#include<bits/stdc++.h>

using namespace std;

#define allof(x) (x).begin(), (x).end()

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

set<ll> found;
ll N;

int main(){
    cin.tie(0);
    cin.sync_with_stdio(0);

    cin >> N;
    for(int a = 1; a <= N; a++){
        for(int b = a + 1; b <= N; b++){
            ll c = a ^ b;
            if(c > N){
                continue;
            }
            vector<ll> v = {a, b, c};
            sort(allof(v));
            if(v[0] + v[1] > v[2]){
                found.insert(v[0] + v[1] * 3000ll + v[2] * 3000ll * 3000ll);
            }
        }
    }
    cout << found.size();
}
