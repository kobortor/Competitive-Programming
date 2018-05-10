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

    int sum = 0;
    for(int a = 0; a < N; a++){
        int x;
        cin >> x;
        sum += x;
    }
    cout << (sum & 1);
}
