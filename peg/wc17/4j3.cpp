#include<bits/stdc++.h>

using namespace std;

#define allof(x) (x).begin(), (x).end()

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

set<string> st = {"Mind", "Power", "Reality", "Soul", "Space", "Time"};

int main(){
    cin.tie(0);
    cin.sync_with_stdio(0);

    int N;
    cin >> N;
    while(N--){
        string str;
        cin >> str;
        st.erase(str);
    }
    for(string s : st){
        cout << s << "\n";
    }
}
