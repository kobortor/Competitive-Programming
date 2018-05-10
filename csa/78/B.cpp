#include<bits/stdc++.h>

using namespace std;

#define allof(x) (x).begin(), (x).end()

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

int N;
vector<int> vec;

int main(){
    cin.tie(0);
    cin.sync_with_stdio(0);

    cin >> N;
    while(N--){
        int x;
        cin >> x;
        vec.push_back(x);
    }
    sort(allof(vec));

    int ans = 1e9;

    int d1 = 0, d2 = 0;
    for(int a = 1; a < (int)vec.size() - 1; a++){
        int diff = vec[a] - vec[a-1];
        if(diff > d1){
            d2 = d1;
            d1 = diff;
        } else if (diff > d2){
            d2 = diff;
        }
    }

    //take from right
    ans = max((d1 + 1) / 2, d2);

    d1 = 0, d2 = 0;
    for(int a = 2; a < (int)vec.size(); a++){
        int diff = vec[a] - vec[a-1];
        if(diff > d1){
            d2 = d1;
            d1 = diff;
        } else if (diff > d2){
            d2 = diff;
        }
    }   

    ans = min(ans, max((d1 + 1) / 2, d2));
    cout << ans;
}
