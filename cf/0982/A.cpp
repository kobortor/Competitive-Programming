#include<bits/stdc++.h>

using namespace std;

#define allof(x) (x).begin(), (x).end()

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;



int main(){
    cin.tie(0);
    cin.sync_with_stdio(0);

    int N;
    string str;
    cin >> N >> str;

    for(int a = 1; a < (int)str.size(); a++){
        if(str[a] == '1' && str[a - 1] == '1'){
            cout << "No";
            return 0;
        }
    }

    for(int a = 0; a < N; a++){
        if(str[a] == '0'){
            bool ok = true;
            ok &= a == 0 || str[a - 1] == '0';
            ok &= a == N - 1 || str[a + 1] == '0';
            if(ok){
                cout << "No";
                return 0;
            }
        }
    }

    cout << "Yes";
}
