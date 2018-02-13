#include<bits/stdc++.h>

using namespace std;

#define allof(x) (x).begin(), (x).end()

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

int N, best;

int main(){
    cin.tie(0);
    cin.sync_with_stdio(0);

    cin >> N;
    while(N--){
        int x;
        cin >> x;
        best = max(best, x);
    }
    if(best > 10000){
        cout << "Something is wrong with these cuteness values";
    } else if (best > 1000){
        cout << "Cuteness by definition is similarity to Cactus";
    } else {
        cout << "Cuteness by definition is similarity to Carol";
    }
}
