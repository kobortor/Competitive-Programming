#include<bits/stdc++.h>

using namespace std;

#define allof(x) (x).begin(), (x).end()

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

set<string> found;

int main(){
    cin.tie(0);
    cin.sync_with_stdio(0);

    string str;
    cin >> str;

    int K;
    cin >> K;

    for(int a = 0; a < (int)str.size(); a++){
        for(int b = 1; b <= 5 && a + b - 1 < (int)str.size(); b++){
            found.insert(str.substr(a, b));
        }
    }

    auto iter = found.begin();
    advance(iter, K - 1);
    cout << *iter;
}
