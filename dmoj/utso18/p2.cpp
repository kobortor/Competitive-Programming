#include<bits/stdc++.h>

using namespace std;

#define allof(x) (x).begin(), (x).end()

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

int A[3];
int B[3];
int C[3];

int main(){
    cin.tie(0);
    cin.sync_with_stdio(0);

    for(int a = 0; a < 3; a++){
        cin >> A[a];
    }

    for(int a = 0; a < 3; a++){
        cin >> B[a];
    }

    int ans = 0;
    for(int a = 0; a < 3; a++){
        cin >> C[a];
        if(A[(a + 2) % 3] == B[a]){
            ans += max(0, C[a]);
        }
    }
    cout << ans;
}
