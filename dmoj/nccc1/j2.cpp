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
    for(int a = 1; a < (int)str.size(); a++){
        if(str[a] == str[a - 1]){
            cout << "Even";
            return 0;
        }
    }
    cout << "Odd";
}
