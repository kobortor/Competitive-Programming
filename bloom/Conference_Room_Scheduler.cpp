#include<bits/stdc++.h>

using namespace std;

#define allof(x) (x).begin(), (x).end()

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

bool booking[101][33];

int main(){
    cin.tie(0);
    cin.sync_with_stdio(0);

    string s;
    getline(cin, s);
    int N = stoi(s);

    while(getline(cin, s)){
        int num_dash = 0;
        for(char &c : s){
            if(c == '-'){
                num_dash++;
                c = ' ';
            }
        }
        stringstream ss(s);

        if(num_dash == 1){
            int ts, os;
            ss >> ts >> os;

            bool found = false;
            for(int a = 1; a <= N; a++){
                if(count(booking[a] + ts, booking[a] + ts + os, false) == os){
                    cout << a << " ";
                    found = true;
                }
            }

            if(!found){
                cout << "None";
            }
            cout << endl;
        } else {
            int ri, ts, os;
            ss >> ri >> ts >> os;

            if (count(booking[ri] + ts, booking[ri] + ts + os, false) == os){
                fill(booking[ri] + ts, booking[ri] + ts + os, true);
                cout << "Y\n";
            } else {
                cout << "N\n";
            }
        }
    }

}
