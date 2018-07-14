#include<bits/stdc++.h>

using namespace std;

#define allof(x) (x).begin(), (x).end()

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

bool vowel(char c){
    return c == 'a' || c == 'o' || c == 'u' || c == 'i' || c == 'e';
}

int main(){
    cin.tie(0);
    cin.sync_with_stdio(0);

    string str;
    cin >> str;

    char prv = 'n';
    for(char c : str){
        if(!vowel(prv) && prv != 'n' && !vowel(c)){
            cout << "NO\n";
            return 0;
        }
        prv = c;
    }

    cout << (vowel(prv) || prv == 'n' ? "YES\n" : "NO\n");
}
