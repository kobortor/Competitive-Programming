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

    int tot = 0;

    for(int a = 1; a <= M; a++){
        int x;
        cin >> x;

        tot += x;

        if(tot * 2 == N){
            cout << -1;
            break;
        } else if (tot * 2 > N){
            cout << a;
            break;
        }
    }
}
