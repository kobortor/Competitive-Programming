#include<bits/stdc++.h>

using namespace std;

#define allof(x) (x).begin(), (x).end()

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

int N, A, B, K;
string str;

int main(){
    cin.tie(0);
    cin.sync_with_stdio(0);

    cin >> N >> A >> B >> K >> str;
    str += "1";

    int spaces = 0;

    int accum = 0;

    for(int i = 0; i < (int)str.size(); i++){
        if(str[i] == '0'){
            accum++;
        } else {
            spaces += accum / B;
            accum = 0;
        }
    }

    cout << max(0, spaces - A + 1) << "\n";

    accum = 0;
    for(int i = 0; i < (int)str.size(); i++){
        if(str[i] == '0'){
            accum++;
        } else {
            int cur = i - B;

            while(i - cur <= accum && spaces >= A){
                cout << cur + 1 << " ";
                cur -= B;

                spaces--;
            }

            accum = 0;
        }
    }
}
