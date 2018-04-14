#include<bits/stdc++.h>

using namespace std;

#define allof(x) (x).begin(), (x).end()

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

int A, B, C;

int main(){
    cin.tie(0);
    cin.sync_with_stdio(0);

    cin >> A >> B >> C;
    for(int a = 0; a <= C; a += A){
        if((C - a) % B == 0){
            cout << "YES";
            return 0;
        }
    }
    cout << "NO";
}