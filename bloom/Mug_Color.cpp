#include<bits/stdc++.h>

using namespace std;

#define allof(x) (x).begin(), (x).end()

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;



int main(){
    cin.tie(0);
    cin.sync_with_stdio(0);

    vector<string> v = {"White", "Black", "Blue", "Red", "Yellow"};

    int N;
    cin >> N;

    while(N--){
        string s;
        cin >> s;

        auto it = find(v.begin(), v.end(), s);
        if(it != v.end()) v.erase(it);
    }

    cout << v[0];
}
