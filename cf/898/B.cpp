#include<bits/stdc++.h>

using namespace std;

int main(){
    int N, A, B;
    cin >> N >> A >> B;
    for(int a = 0; a * A <= N; a++){
        if((N - a * A) % B == 0){
            cout << "YES\n" << a << " " << (N - a * A) / B << "\n";
            return 0;
        }
    }
    cout << "NO\n";
}
