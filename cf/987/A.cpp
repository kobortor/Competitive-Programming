#include<bits/stdc++.h>

using namespace std;

#define allof(x) (x).begin(), (x).end()

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

map<string, string> mp;

int main(){
    cin.tie(0);
    cin.sync_with_stdio(0);

    mp["purple"] = "Power";
    mp["green"] = "Time";
    mp["blue"] = "Space";
    mp["orange"] = "Soul";
    mp["red"] = "Reality";
    mp["yellow"] = "Mind";

    int N;
    cin >> N;
    while(N--){
        string str;
        cin >> str;
        mp.erase(str);
    }

    cout << mp.size() << "\n";
    for(auto au : mp){
        cout << au.second << "\n";
    }
}
