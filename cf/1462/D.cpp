#include<bits/stdc++.h>

// Created by kobortor On 23:36:34 on 19-12-2020

using namespace std;

#define allof(x) (x).begin(), (x).end()

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;



int main(){
    cin.tie(0);
    cin.sync_with_stdio(0);

    int t;
    cin >> t;

    while (t--) {
        int n;
        cin >> n;

        vector<int> v(n);
        for (int &vi : v) cin >> vi;

        int tot = accumulate(allof(v), 0);

        // have k blocks in total

        int block = 0;
        for (int vi : v) {
            block += vi;

            if (tot % block != 0) {
                continue;
            }

            int tmp = 0;
            for (int vj : v) {
                tmp += vj;
                if (tmp == block) {
                    tmp = 0;
                } else if (tmp > block) {
                    tmp = -1;
                    break;
                }
            }

            // need `tot / block` pieces
            if (tmp == 0) {
                cout << n - (tot / block) << endl;
                break;
            }
        }
    }
}
