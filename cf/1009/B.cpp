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

    string tmp;

    int cnt1 = 0;
    for(int i = 0; i < (int)str.size(); i++){
        if(str[i] == '1'){
            cnt1++;
        } else {
            tmp += str[i];
        }
    }

    tmp += '2';
    int idx = tmp.find("2");

    while(cnt1--){
        tmp.insert(tmp.begin() + idx, '1');
    }

    tmp.pop_back();
    cout << tmp;
}
