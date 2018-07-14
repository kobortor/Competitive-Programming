#include<bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;



int main(){
    cin.tie(0);
    cin.sync_with_stdio(0);

    int A, B;
    string S;
    cin >> A >> B >> S;
    int idx = S.find('-');
    for(int a = idx + 1; a < (int)S.size(); a++){
        if(S[a] == '-'){
            cout << "No";
            return 0;
        }
    }

    if(idx == string::npos){
        cout << "No";
    } else {
        cout << (idx == A && (int)S.size() - idx == B + 1 ? "Yes" : "No");
    }
}