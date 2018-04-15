#include<bits/stdc++.h>

using namespace std;

#define allof(x) (x).begin(), (x).end()

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

string str;
int cnt[26];

int main(){
    cin.tie(0);
    cin.sync_with_stdio(0);

    cin >> str;
    for(char c : str){
        cnt[c - 'a']++;
    }
    if(cnt[2] != cnt[1] && cnt[2] != cnt[0]){
        cout << "NO";
        return 0;
    }
    if(!cnt[0] || !cnt[1] || !cnt[2]){
        cout << "NO";
        return 0;       
    }

    while(!str.empty() && str.back() == 'c'){
        str.pop_back();
    }
    while(!str.empty() && str.back() == 'b'){
        str.pop_back();
    }
    while(!str.empty() && str.back() == 'a'){
        str.pop_back();
    }

    if(str.empty()){
        cout << "YES";
    } else {
        cout << "NO";
    }
}
