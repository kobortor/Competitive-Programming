#include<bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

string best = "zzzzzzzzzzzzzzzzzzzz";
string first, last;

int main(){
    cin.tie(0);
    cin.sync_with_stdio(0);
    cin >> first >> last;
    for(int a = 0; a < (int)first.size(); a++) {
        best = min(best, first.substr(0, a + 1) + last[0]);
    }
    cout << best;
}
