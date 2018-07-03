#include<bits/stdc++.h>

using namespace std;

#define allof(x) (x).begin(), (x).end()

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

int main(){
    cin.tie(0);
    cin.sync_with_stdio(0);

    int A, B, X;
    cin >> A >> B >> X;

    char chA = '0';
    char chB = '1';

    if(A > B){
        swap(A, B);
        swap(chA, chB);
    }

    string str = string(A, chA) + string(B, chB);
    for(int a = (X % 2); a < X; a += 2){
        swap(str[a], str[A + a / 2]);
    }

    cout << str;
}
