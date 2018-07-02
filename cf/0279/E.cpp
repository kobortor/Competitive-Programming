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

    str += "0";

    int cnt = 0;
    vector<int> vec;

    for(int a = 0; a < (int)str.size(); a++){
        if(str[a] == '0'){
            vec.push_back(cnt);
            cnt = 0;
        } else {
            cnt++;
        }
    }
    
    int ans = 0;
    for(int a = 0; a < (int)vec.size(); a++){
        if(vec[a] == 0){
            continue;
        }

        ans++;
        if(vec[a] > 1){
            bool found2 = false;
            int b = a;
            found2 |= vec[b] >= 2;

            while(b + 1 < (int)vec.size() && vec[b + 1] >= 1){
                ans++;
                b++;
                found2 |= vec[b] >= 2;
            }
            ans++;

            if(!found2){
                ans--;
            }

            a = b;
        }
    }
    cout << ans;
}
