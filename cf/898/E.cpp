#include<bits/stdc++.h>

using namespace std;

int N;
int zero, sq;

vector<int> sq_costs;

int main(){
    cin >> N;
    for(int a = 0; a < N; a++) {
        int x;
        cin >> x;
        if(!x) {
            zero++;
        } else {
            int low_sq = sqrt(x);
            if(low_sq * low_sq == x){
                sq++;
            } else {
                sq_costs.push_back(
                    min(
                        abs(x - low_sq * low_sq), 
                        abs((low_sq + 1) * (low_sq + 1) - x)
                    )
                );
            }
        }
    }

    if((int)sq_costs.size() > N / 2){
        long long ans = 0;
        sort(sq_costs.begin(), sq_costs.end());
        reverse(sq_costs.begin(), sq_costs.end());

        while((int)sq_costs.size() > N / 2){
            ans += sq_costs.back();
            sq_costs.pop_back();
        }
        cout << ans;
    } else {
        long long ans = 0;
        while(zero + sq > N / 2){
            if(sq != 0){
                sq--;
                ans++;
            } else {
                zero--;
                ans += 2;
            }
        }
        cout << ans << "\n";
    }
}
