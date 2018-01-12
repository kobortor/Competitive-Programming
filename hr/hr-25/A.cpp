#include<bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;



int main(){
    cin.tie(0);
    cin.sync_with_stdio(0);

    int T;
    cin >> T;
    while(T--){
        int N, sum = 0;
        cin >> N;
        while(N--){
            int x;
            cin >> x;
            while(x){
                sum += x % 10;
                x /= 10;
            }
        }
        cout << (sum % 3 == 0 ? "Yes\n" : "No\n");
    }
}