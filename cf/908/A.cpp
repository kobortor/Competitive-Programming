#include<bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

bool good(char c){
    return c == '1' || c == '3' || c == '5' || c == '7' || c == '9' || c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u';
}

int main(){
    cin.tie(0);
    cin.sync_with_stdio(0);

    string str;
    cin >> str;
    int ans = 0;
    for(char c : str){
        ans += good(c);
    }
    cout << ans;
}