#include<bits/stdc++.h>

using namespace std;

#define allof(x) (x).begin(), (x).end()

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

int N, X, Y;

int main(){
    cin.tie(0);
    cin.sync_with_stdio(0);

    cin >> N >> X >> Y;

    int sum = 0;
    for(int a = 0; a < 1000; a++){
        sum += max(0, X - a * Y);
        if(2 * sum >= N){
            cout << a + 1;
            return 0;
        }
    }
    cout << "RIP";
}
