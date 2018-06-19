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
    
    for(int a = 0; a < N; a++){
        int x;
        cin >> x;
        st.insert(x);
    }

    st.erase(0);

    cout << st.size();
}
