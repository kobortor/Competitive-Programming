#include<bits/stdc++.h>

using namespace std;

#define allof(x) (x).begin(), (x).end()

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;



int main(){
    cin.tie(0);
    cin.sync_with_stdio(0);

    int X;
    cin >> X;
    for(int a = 0; a * 7 <= X; a++){
        for(int b = 0; a * 7 + b * 3 <= X; b++){
            if((X - (a * 7 + b * 3)) % 2 == 0){
                cout << a << " " << b << " " << (X - (a * 7 + b * 3)) / 2 << endl;
            }
        }
    }

}
