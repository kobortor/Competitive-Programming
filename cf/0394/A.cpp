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
    
    int i1 = str.find('+');
    int i2 = str.find('=');

    int A = i1;
    int B = i2 - i1 - 1;
    int C = str.size() - A - B - 2;

    if(A + B < C){
        if(A < B){
            A++;
        } else {
            B++;
        }
        C--;
    } else if (A + B > C){
        if(A > B){
            A--;
        } else {
            B--;
        }
        C++;
    }

    if(A + B == C && A && B && C){
        cout << string(A, '|') << "+" << string(B, '|') << "=" << string(C, '|');
    } else {
        cout << "Impossible\n";
    }
}
