#include<iostream>
#include<random>
#include<ctime>
#include<cassert>
#include<chrono>

using namespace std;

int main(){
    int T;
    cin >> T;
    for(int test = 1; test <= T; test++){
        long long n, i, k;
        cin >> n >> i >> k;
        long long prv_active = 0;
        long long prv_wake_up = -1e9;
        long long ignored = 0, slept = 0;
        while(n--){
            int x;
            cin >> x;
            if(x - prv_wake_up < k){
                ignored++;
            } else if(x - prv_active >= i){
                prv_active = x + k;
                prv_wake_up = x;
                slept++;
            } else {
                prv_active = x;
            }
        }
        printf("Case %i: %i %i\n", test, slept, ignored);
    }
}