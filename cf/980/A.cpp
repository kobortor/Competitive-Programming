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
    int dash = 0, pearl = 0;
    for(char c : str){
        if(c == '-') dash++;
        if(c == 'o') pearl++;
    }

    if(pearl == 0 || dash % pearl == 0){
        cout << "YES";
    } else {
        cout << "NO";
    }

}
