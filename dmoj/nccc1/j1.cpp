#include<bits/stdc++.h>

using namespace std;

#define allof(x) (x).begin(), (x).end()

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

bool has_zero(int x){
    while(x){
        if(x % 10 == 0){
            return true;
        }
        x /= 10;
    }
    return false;
}

int main(){
    cin.tie(0);
    cin.sync_with_stdio(0);

    int N;
    cin >> N;

    while(has_zero(++N)){}
    cout << N;
}
