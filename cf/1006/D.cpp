#include<bits/stdc++.h>

using namespace std;

#define allof(x) (x).begin(), (x).end()

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

int N;
string A, B;

int main(){
    cin.tie(0);
    cin.sync_with_stdio(0);

    cin >> N >> A >> B;

    int ans = 0;

    for(int l = 0; l <= N - l - 1; l++){
        int r = N - l - 1;

        if(l == r){
            ans += A[l] != B[l];
        } else {
            if(B[l] == B[r]){
                ans += A[l] != A[r];
            } else {
                ans += min((A[l] != B[l]) + (A[r] != B[r]), (A[l] != B[r]) + (A[r] != B[l]));
            }
        }
    }

    cout << ans;
}
