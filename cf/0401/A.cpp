#include<bits/stdc++.h>

using namespace std;

#define allof(x) (x).begin(), (x).end()

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;



int main(){
    cin.tie(0);
    cin.sync_with_stdio(0);

    int n, x;
    cin >> n >> x;

    int sum = 0;
    while (n--) {
        int tmp;
        cin >> tmp;
        sum += tmp;
    }

    cout << (abs(sum) + x - 1) / x;
}
