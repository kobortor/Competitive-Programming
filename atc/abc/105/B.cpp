#include<bits/stdc++.h>

using namespace std;

#define allof(x) (x).begin(), (x).end()

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;



int main(){
    cin.tie(0);
    cin.sync_with_stdio(0);

    int N;
    cin >> N;
    for(int a = 0; a * 4 <= N; a++){
        if((N - a * 4) % 7 == 0){
            cout << "Yes\n";
            return 0;
        }
    }

    cout << "No\n";
}
