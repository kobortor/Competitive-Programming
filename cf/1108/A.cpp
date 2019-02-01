#include<bits/stdc++.h>

using namespace std;

#define allof(x) (x).begin(), (x).end()

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;



int main(){
    cin.tie(0);
    cin.sync_with_stdio(0);

    int Q;
    cin >> Q;
    while(Q--){
        int l1, r1, l2, r2;
        cin >> l1 >> r1 >> l2 >> r2;

        if (l1 != l2) {
            cout << l1 << " " << l2 << "\n";
        } else if (l1 != r2) {
            cout << l1 << " " << r2 << "\n";
        } else if (r1 != l2) {
            cout << r1 << " " << l2 << "\n";
        } else if (r1 != r2) {
            cout << r1 << " " << r2 << "\n";
        }
    }
}
