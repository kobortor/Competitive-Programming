#include<bits/stdc++.h>

using namespace std;

#define allof(x) (x).begin(), (x).end()

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;



int main(){
    cin.tie(0);
    cin.sync_with_stdio(0);

    string str;
    cin >> str;

    bool good = false;
    good |= str[0] == 'U' && str[2] == 'D';
    good |= str[0] == 'D' && str[2] == 'U';
    good |= str[0] == 'L' && str[2] == 'R';
    good |= str[0] == 'R' && str[2] == 'L';

    good &= str[0] != str[1];
    good &= str[0] != str[2];
    good &= str[1] != str[2];

    if(good){
        if(str[0] == 'U' || str[0] == 'D'){
            cout << "Candle\n";
        } else {
            cout << "Crossover\n";
        }
    } else {
        cout << "Neither\n";
    }
}
