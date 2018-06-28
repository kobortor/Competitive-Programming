#include<bits/stdc++.h>

using namespace std;

#define allof(x) (x).begin(), (x).end()

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

string str;

int main(){
    cin.tie(0);
    cin.sync_with_stdio(0);

    cin >> str;
    
    int ans = 0;
    for(int a = 0; a < (int)str.size(); a++){
        int low = 0, high = 0;

        for(int b = a; b < (int)str.size(); b++){
            if(str[b] == '?'){
                if(low == 0){
                    low = 1;
                } else {
                    low--;
                }

                high++;
            } else if (str[b] == '('){
                low++;
                high++;
            } else {
                if(low == 0){
                    low = 1;
                } else {
                    low--;
                }
                high--;
                if(low > high){
                    break;
                }
            }
            if((b - a + 1) % 2 == 0 && low == 0){
                ans++;
            }
        }
    }
    cout << ans;
}
