#include<bits/stdc++.h>

using namespace std;

#define allof(x) (x).begin(), (x).end()

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;



int main(){
    cin.tie(0);
    cin.sync_with_stdio(0);

    int n;
    string s;
    cin >> n >> s;

    int anton = 0;
    for (char c : s) {
        if (c == 'A') anton++;
        else anton--;
    }

    if (anton > 0) cout << "Anton";
    else if (anton < 0) cout << "Danik";
    else cout << "Friendship";
}
