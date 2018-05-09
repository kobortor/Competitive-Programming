#include<bits/stdc++.h>

using namespace std;

#define allof(x) (x).begin(), (x).end()

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;



int main(){
    cin.tie(0);
    cin.sync_with_stdio(0);

    set<int> st;
    int N;
    cin >> N;
    while(N--){
        int val = 0;
        string str;
        cin >> str;
        for(char c : str){
            val |= 1 << (c - 'a');
        }
        st.insert(val);
    }
    cout << st.size();
}
