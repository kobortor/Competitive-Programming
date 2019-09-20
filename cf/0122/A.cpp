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
    cin >> n;

    if (n % 4 && n % 7 && 
        n % 44 && n % 47 && n % 74 && n % 77 && 
        n % 444 && n % 447 && n % 474 && n % 477 &&
        n % 744 && n % 747 && n % 774 && n % 777) {
        cout << "NO";
    } else {
        cout << "YES";
    }
}
