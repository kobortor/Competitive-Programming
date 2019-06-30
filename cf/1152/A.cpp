#include<bits/stdc++.h>

using namespace std;

#define allof(x) (x).begin(), (x).end()

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;



int main(){
    cin.tie(0);
    cin.sync_with_stdio(0);

    int N, M;
    cin >> N >> M;

    int A[2] = {0, 0};
    int B[2] = {0, 0};

    while (N--) {
        int x;
        cin >> x;
        A[x % 2]++;
    }

    while (M--) {
        int x;
        cin >> x;
        B[x % 2]++;
    }

    cout << min(A[0], B[1]) + min(A[1], B[0]);
}
