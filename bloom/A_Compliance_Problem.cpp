#include<bits/stdc++.h>

using namespace std;

#define allof(x) (x).begin(), (x).end()

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

int cnt[256];

int main(){
    cin.tie(0);
    cin.sync_with_stdio(0);

    string s;
    cin >> s;

    for(char c : s){
        cnt[c]++;
    }

    if(count_if(cnt, cnt + 256, [](int x){return x % 2;}) <= 1){
        cout << "yes";
    } else {
        cout << "no";
    }
}
