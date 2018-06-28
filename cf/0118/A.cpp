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
    for(char c : str){
        c = tolower(c);
        if(c == 'a' || c == 'o' || c == 'y' || c == 'e' || c == 'u' || c == 'i'){
            continue;
        }
        cout << "." << c;
    }
}
