#include<bits/stdc++.h>

using namespace std;

#define allof(x) (x).begin(), (x).end()

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

int besthub(int R, int L, int X[], long long B){
    ll totcost = 0;
    int ans = 0;
    for(int a = 0, b = 0, mid = 0; a < R; a++){
        totcost += X[a] - X[mid];
        while(a - mid >= mid - b + 1){
            int diff = X[mid + 1] - X[mid];
            totcost -= (a - mid) * diff;
            totcost += (mid - b + 1) * diff;
            mid++;
        }

        while(totcost > B){
            totcost -= X[mid] - X[b];

            b++;

            while(a - mid >= mid - b + 1){
                int diff = X[mid + 1] - X[mid];
                totcost -= (a - mid) * diff;
                totcost += (mid - b + 1) * diff;
                mid++;
            }
        }

        ans = max(ans, a - b + 1);
    }
    return ans;
}
