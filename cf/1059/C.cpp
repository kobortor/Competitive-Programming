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

    int rem = N;

    int prod = 1;
    
    while(rem > 3) {
        int nxt = rem / 2;
        while(rem > nxt){
            rem--;
            cout << prod << " ";
        }
        prod *= 2;
    }

    if(rem == 3){
        cout << prod << " " << prod << " " << prod * 3 << " ";
    } else if(rem == 2){
        cout << prod << " " << prod * 2 << " ";
    } else {
        cout << prod;
    }
}
