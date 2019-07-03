#include<bits/stdc++.h>

using namespace std;

#define allof(x) (x).begin(), (x).end()

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

int sum(int x) {
    string str = to_string(x);
    int ans = 0;
    for (char c : str) {
        ans += c - '0';
    }
    return ans;
}

int main(){
    cin.tie(0);
    cin.sync_with_stdio(0);

    int a;
    cin >> a;
    while (sum(a) % 4) {
        a++;
    }
    cout << a;
}
