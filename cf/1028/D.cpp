#include<bits/stdc++.h>

using namespace std;

#define allof(x) (x).begin(), (x).end()

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

const ll mod = 1e9 + 7;

set<int> st;

int main(){
    cin.tie(0);
    cin.sync_with_stdio(0);

    st.insert(0);
    st.insert(4e8);

    pii gap = pii(0, 4e8);

    int N;
    cin >> N;

    ll ans = 1;
    for(int a = 1; a <= N; a++){
        string str;
        int val;
        cin >> str >> val;
        if(str == "ADD"){
            st.insert(val);
        } else {
            auto iter = st.find(val);

            pii newgap = pii(*prev(iter), *next(iter));

            if(gap.first <= val && val <= gap.second){
                if(val != gap.first && val != gap.second){
                    ans = ans * 2 % mod;
                }

                gap = newgap;
                st.erase(iter);
            } else {
                cout << "0\n";
                return 0;
            }
        }
    }

    ll mult = 1;
    for(int i : st){
        if(gap.first < i && i < gap.second){
            mult++;
        }
    }

    cout << ans * mult % mod;
}
