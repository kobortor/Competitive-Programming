#include<bits/stdc++.h>

using namespace std;

#define allof(x) (x).begin(), (x).end()

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;



int main(){
    cin.tie(0);
    cin.sync_with_stdio(0);

    int T;
    cin >> T;

    for(int a = 1; a <= T; a++){
        vector<string> v;
        for(int b = 1; b <= 52; b++){
            string s;
            cin >> s;
            v.push_back(s);
        }

        vector<string> tmp;
        for(int b = 1; b <= 25; b++){
            tmp.push_back(v.back());
            v.pop_back();
        }

        int Y = 0;
        for(int b = 1; b <= 3; b++){
            char c = v.back()[0];
            int X = ('2' <= c && c <= '9') ? c - '0' : 10;
            Y += X;

            for(int c = 1; c <= 11 - X; c++){
                v.pop_back();
            }
        }

        while(!tmp.empty()){
            v.push_back(tmp.back());
            tmp.pop_back();
        }

        cout << "Case " << a << ": " << v[Y - 1] << endl;
    }
}
