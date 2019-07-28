#include<bits/stdc++.h>

using namespace std;

#define allof(x) (x).begin(), (x).end()

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;



int main(){
    cin.tie(0);
    cin.sync_with_stdio(0);

    string s;
    cin >> s;

    int a = stoi(s.substr(0, 2)) % 12;
    int b = stoi(s.substr(3, 2));

    cout << 30 * a + 0.5 * b << " " << 6 * b;
}
