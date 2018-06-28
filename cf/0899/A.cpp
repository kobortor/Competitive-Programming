#include<bits/stdc++.h>

using namespace std;

typedef long long ll;

int main(){
    int N;
    cin >> N;

    int sz1 = 0, sz2 = 0;
    while(N--){
        int x;
        cin >> x;
        if(x == 1) sz1++;
        if(x == 2) sz2++;
    }
    cout << min(sz1, sz2) + max(0, sz1 - min(sz1, sz2)) / 3;
}