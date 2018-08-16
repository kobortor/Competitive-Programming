#include<bits/stdc++.h>

using namespace std;

#define allof(x) (x).begin(), (x).end()

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;



int main(){
    cin.tie(0);
    cin.sync_with_stdio(0);

    string S;
    cin >> S;

    if((int)S.size() >= 3 && S[0] == 'A' && count(S.begin() + 2, S.end() - 1, 'C') == 1 && count_if(allof(S), [](char c){return c == toupper(c);}) == 2){
        cout << "AC";
    } else {
        cout << "WA";
    }
}
