#include<bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

int digit_sum(int x){
    int ans = 0;
    while(x){
        ans += x % 10;
        x /= 10;
    }
    return ans;
}

int main(){
    cin.tie(0);
    cin.sync_with_stdio(0);

    int N, A, B;
    cin >> N >> A >> B;

    int ans = 0;
    for(int a = 1; a <= N; a++){
        int dsum = digit_sum(a);
        if(A <= dsum && dsum <= B){
            ans += a;
        }
    }
    cout << ans;
}