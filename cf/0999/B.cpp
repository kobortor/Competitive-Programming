#include<bits/stdc++.h>

using namespace std;

#define allof(x) (x).begin(), (x).end()

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

int N;
string str;

int main(){
    cin.tie(0);
    cin.sync_with_stdio(0);

    cin >> N >> str;
    for(int a = 1; a <= N; a++){
        if(N % a == 0){
            reverse(str.begin(), str.begin() + a);
        }
    }

    cout << str;
}
