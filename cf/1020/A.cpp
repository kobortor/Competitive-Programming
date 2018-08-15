#include<bits/stdc++.h>

using namespace std;

#define allof(x) (x).begin(), (x).end()

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

int N, H, A, B, K;

int main(){
    cin.tie(0);
    cin.sync_with_stdio(0);

    cin >> N >> H >> A >> B >> K;
    while(K--){
        int ta, tb, fa, fb;
        cin >> ta >> fa >> tb >> fb;
        if(ta == tb) {
            cout << abs(fa - fb) << "\n";
        } else if(A <= fa && fa <= B && A <= fb && fb <= B){
            cout << abs(ta - tb) + abs(fa - fb) << "\n";
        } else {
            cout << abs(ta - tb) + min(abs(fa - A) + abs(fb - A), abs(fa - B) + abs(fb - B)) << "\n";
        }
    }
}
