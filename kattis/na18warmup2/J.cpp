#include<bits/stdc++.h>

using namespace std;

#define allof(x) (x).begin(), (x).end()

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

ll A, B, C, D;

ll num0, num1;

int main(){
    cin.tie(0);
    cin.sync_with_stdio(0);

    cin >> A >> B >> C >> D;

    if(A == 0 && D == 0){
        if(B == 0 && C == 0){
            cout << "1" << endl;
            return 0;
        } else if (B == 0 && C == 1){
            cout << "10" << endl;
            return 0;
        } else if (B == 1 && C == 0){
            cout << "01" << endl;
            return 0;
        } else {
            cout << "impossible" << endl;
            return 0;
        }
    }

    if (A == 0){
        num0 = 0;
        num1 = round((1 + sqrt(1 + 8 * D)) / 2.0);
        if(num1 * (num1 - 1) != D * 2){
            cout << "impossible" << endl;
            return 0;
        } else if (B == 0 && C == 0){
            string str = string(num1, '1');
            cout << str << endl;
            return 0;
        }
    } else if (D == 0) {
        num0 = round((1 + sqrt(1 + 8 * A)) / 2.0);
        num1 = 0;
        if(num0 * (num0 - 1) != A * 2){
            cout << "impossible" << endl;
            return 0;
        } else if (B == 0 && C == 0){
            string str = string(num0, '0');
            cout << str << endl;
            return 0;
        }
    }

    num0 = round((1 + sqrt(1 + 8 * A)) / 2.0);
    num1 = round((1 + sqrt(1 + 8 * D)) / 2.0);

    if(num0 * (num0 - 1) == A * 2 && num1 * (num1 - 1) == D * 2 && B + C == num0 * num1){
        //possible
        string str;

        ll used0 = 0, used1 = 0;
        for(int a = 0; a < num0 + num1; a++){
            if(C < (num0 - used0) || num1 == used1){
                str += '0';
                used0++;
            } else {
                str += '1';
                used1++;

                C -= num0 - used0;
            }
        }

        if(used0 != num0 || used1 != num1){
            cout << "impossible" << endl;
        } else {
            cout << str << endl;
        }
    } else {
        cout << "impossible" << endl;
    }
}
