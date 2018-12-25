#include<bits/stdc++.h>

using namespace std;

#define allof(x) (x).begin(), (x).end()

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;



int main(){
    cin.tie(0);
    cin.sync_with_stdio(0);

    vector<string> v;
    string s;
    while(getline(cin, s)){
        v.push_back(s);
    }

    sort(allof(v), [](string s1, string s2){
        for(char &c : s1) c = tolower(c);
        for(char &c : s2) c = tolower(c);

        return s1 < s2;
    });

    for(int a = 0; a < (int)v.size(); a++){
        int b = a;
        while(b + 1 < (int)v.size() && v[b + 1] == v[a]){
            b++;
        }

        int num = b - a + 1;
        if(v[a].substr(v[a].size() - 4) == "sock"){
            if(num >= 2){
                cout << num / 2 << "|" << v[a] << endl;
            }
            if(num % 2){
                cout << 0 << "|" << v[a] << endl;
            }
        } else {
            cout << num << "|" << v[a] << endl;
        }
        a = b;
    }
}
