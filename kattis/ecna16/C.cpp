#include<bits/stdc++.h>

using namespace std;

#define allof(x) (x).begin(), (x).end()

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;



int main(){
    cin.tie(0);
    cin.sync_with_stdio(0);

    string code, key;
    cin >> code >> key;

    string soln;
    for (int a = 0; a < (int)code.size(); a++) {
        soln += code[a] - (key[a] - 'A');
        if (soln.back() < 'A') {
            soln.back() += 26;
        }
        key += soln.back();
    }

    cout << soln;
}
