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
    for(int a = 2; a <= N; a++){
        int ans = 0;
        do {
            cout << "Q 1 " << a << endl;
            cin >> ans;
        } while(!ans);
    }
    cout << "A" << endl;
}
