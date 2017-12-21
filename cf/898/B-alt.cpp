#include<bits/stdc++.h>

using namespace std;

long long ext_gcd(long long a, long long b, long long &x, long long &y){
    if(b % a == 0){
        x = 1;
        y = 0;
        return a;
    } else {
        long long res = ext_gcd(b % a, a, y, x);
        //res = (b % a) * y + a * x
        //res = (b - b / a * a) * y + a * x
        //res = b * y - (b / a) * a * y + a * x
        //res = b * y - a * *((b / a) * y + x)
        
        x -= b / a * y;
        assert(a * x + b * y == res);
        return res;
    }
}

int main(){
    long long N, A, B;
    cin >> N >> A >> B;
    
    long long x, y;
    long long gcd = ext_gcd(A, B, x, y);
    if(N % gcd != 0){
        cout << "NO\n";
        return 0;
    }
    
    long long modv = B / gcd;
    long long x_amnt = (x * (N / gcd) % modv + modv) % modv;
    long long y_amnt = (N - x_amnt * A) / B;
    if(0 <= y_amnt){
        cout << "YES\n";
        cout << x_amnt << " " << y_amnt << "\n";
    } else {
        cout << "NO";
    }
}
