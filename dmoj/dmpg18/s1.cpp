#include<bits/stdc++.h>

using namespace std;

#define allof(x) (x).begin(), (x).end()

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

string str;

int main(){
    cin.tie(0);
    cin.sync_with_stdio(0);

    cin >> str;
    int stk = 1;

    for(int i = 0; i < (int)str.size(); i++){
        stk += str[i] - '0';
        stk--;
        if(stk < 0){
            cout << "Invalid";
            return 0;
        }
    }
    cout << (stk == 0 ? "Valid" : "Invalid");
}
