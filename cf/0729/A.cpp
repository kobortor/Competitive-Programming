#include<bits/stdc++.h>

using namespace std;

#define allof(x) (x).begin(), (x).end()

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

int N;
string str;

int main(){
    cin.tie(0);
    cin.sync_with_stdio(0);

    cin >> N >> str;

    string ans;
    for(int a = 0; a < N;){
        if(str[a] == 'o'){
            int b = a + 1;
            while(b + 1 < N && str[b] == 'g' && str[b + 1] == 'o'){
                b += 2;
            }

            if(b != a + 1){
                ans += "***";
            } else {
                ans += "o";
            }

            a = b;
        } else {
            ans += str[a];
            a++;
        }
    }

    cout << ans;
}
