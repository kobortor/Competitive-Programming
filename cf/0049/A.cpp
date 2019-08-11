#include<bits/stdc++.h>

using namespace std;

#define allof(x) (x).begin(), (x).end()

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;



int main(){
    cin.tie(0);
    cin.sync_with_stdio(0);

    string s;
    getline(cin, s);

    while (!isalpha(s.back())) s.pop_back();

    set<char> vowel = {'a', 'e', 'i', 'o', 'u', 'y'};
    if (vowel.count(tolower(s.back()))){ 
        cout << "YES";
    } else {
        cout << "NO";
    }
}
