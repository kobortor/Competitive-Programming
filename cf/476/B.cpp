#include<bits/stdc++.h>

using namespace std;

#define allof(x) (x).begin(), (x).end()

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

string orig, input;

double nck(int n, int k) {
    double ans = 1;
    for(int a = 1; a <= n; a++){
        ans *= a;
    }
    for(int a = 1; a <= k; a++){
        ans /= a;
    }
    for(int a = 1; a <= n - k; a++){
        ans /= a;
    }
    return ans;
}

int main(){
    cin.tie(0);
    cin.sync_with_stdio(0);

    cin >> orig >> input;

    int origpos = 0;
    for(char c : orig){
        if(c == '+') origpos++;
        else origpos--;
    }
    int unknown = 0;
    for(char c : input){
        if(c == '+') origpos--;
        else if(c == '-') origpos++;
        else unknown++;
    }

    origpos = abs(origpos);

    if(unknown < origpos || unknown % 2 != origpos % 2){
        cout << 0;
    } else {
        cout << fixed << setprecision(15) << nck(unknown, (unknown - origpos) / 2) / pow(2, unknown);
    }
}
