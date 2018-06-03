#include<bits/stdc++.h>

using namespace std;

#define allof(x) (x).begin(), (x).end()

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

int digitsum(int x){
    string str = to_string(x);
    int ans = 0;
    for(char c : str){
        ans += c - '0';
    }
    return ans;
}

int main(){
    cin.tie(0);
    cin.sync_with_stdio(0);

    int N;
    cin >> N;

    int ans = 999999;
    for(int A = 1; A + 1 <= N; A++){
        int B = N - A;
        ans = min(ans, digitsum(A) + digitsum(B));
    }
    cout << ans;
}
