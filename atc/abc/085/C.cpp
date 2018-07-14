#include<bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;



int main(){
    cin.tie(0);
    cin.sync_with_stdio(0);

    int N, Y;
    cin >> N >> Y;
    for(int tt = 0; tt <= N; tt++){
        if(10000 * tt > Y){
            break;
        }
        int remain = Y - 10000 * tt;
        int bills = N - tt;
        //5000 * F + 1000 * (bills - F) = remain
        //4000 * F + 1000 * bills = remain
        //F = (remain - 1000 * bills) / 4000
        if((remain - 1000 * bills) % 4000){
            continue;
        }
        int F = (remain - 1000 * bills) / 4000;
        if(0 <= F && F <= bills){
            cout << tt << " " << F << " " << bills - F << endl;
            return 0;
        }
    }
    cout << "-1 -1 -1";
}
