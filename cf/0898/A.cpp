#include<bits/stdc++.h>

using namespace std;

int main(){
    int x;
    cin >> x;
    if(x % 10 < 5){
        x = x / 10 * 10;
    } else {
        x = x / 10 * 10 + 10;
    }
    cout << x;
}
