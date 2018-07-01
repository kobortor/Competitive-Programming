#include<bits/stdc++.h>

using namespace std;

#define allof(x) (x).begin(), (x).end()

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;



int main(){
    cin.tie(0);
    cin.sync_with_stdio(0);

    int A, B, C, N;
    cin >> A >> B >> C >> N;

    if(A + B - C > N - 1 || C > min(A, B)){
        cout << -1;
    } else {
        cout << N - (A + B - C);
    }
}
