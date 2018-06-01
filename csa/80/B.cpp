#include<bits/stdc++.h>

using namespace std;

#define allof(x) (x).begin(), (x).end()

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

int main(){
    cin.tie(0);
    cin.sync_with_stdio(0);

    string A, B;
    cin >> A >> B;

    while(B.size() < A.size()){
        B = '0' + B;
    }

    string ans;
    for(int a = 0; a < (int)A.size(); a++){
        bool good = false;
        for(int b = 9; b >= 0; b--){
            int id = find(A.begin() + a, A.end(), char(b + '0')) - A.begin();
            if(id != (int)A.size()){
                swap(A[a], A[id]);
                sort(A.begin() + a + 1, A.end());
                
                if(A[0] != '0' && stoi(A) <= stoi(B)){
                    good = true;
                    break;
                }
            }
        }

        if(!good){
            cout << -1;
            return 0;
        }
    }

    cout << A;
}
