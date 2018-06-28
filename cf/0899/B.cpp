#include<bits/stdc++.h>

using namespace std;

typedef long long ll;

set<int> day31 = {1, 3, 5, 7, 8, 10, 12};

int days_in_month(int year, int month){
    if(month == 2){
        if(year % 4 == 0){
            if(year % 100 == 0){
                if(year % 400 == 0){
                    return 29;
                } else {
                    return 28;
                }
            } else {
                return 29;
            }
        } else {
            return 28;
        }
    } else {
        return 30 + day31.count(month);
    }
}

basic_string<int> days, seq;

int main() {
    for(int yr = 0; yr < 801; yr++){
        for(int mon = 1; mon <= 12; mon++){
            days.push_back(days_in_month(yr, mon));
        }
    }

    int N;
    cin >> N;

    while(N--){
        int x;
        cin >> x;
        seq.push_back(x);
    }

    cout << (days.find(seq) != basic_string<int>::npos ? "Yes" : "No");
}