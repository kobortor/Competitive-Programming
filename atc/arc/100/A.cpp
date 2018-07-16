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

    vector<int> vec;

    for(int a = 1; a <= N; a++){
        int x;
        cin >> x;
        vec.push_back(x - a);
    }

    sort(allof(vec));

    int mid = vec[vec.size() / 2];

    ll ans = 0;
    for(int i : vec){
        ans += abs(i - mid);
    }

    cout << ans;
}
