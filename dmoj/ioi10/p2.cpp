#include <bits/stdc++.h>

using namespace std;

/*
Gets 79/100 points. Since the last subtask is based on heuristics, getting 100 is not designed to be possible
*/

int HC(int N){
    int lo = 1, hi = N;

    int prv = -1;

    while(lo + 2 <= hi){
        int res;

        if(prv == lo){
            res = Guess(hi);
            prv = hi;
            if(res == 0){
                return (lo + hi) / 2;
            } else if (res == 1){
                lo = (lo + hi) / 2 + 1;
            } else {
                hi = (lo + hi - 1) / 2;
            }
        } else if (prv == hi){
            res = Guess(lo);
            prv = lo;
            if(res == 0){
                return (lo + hi) / 2;
            } else if (res == 1){
                hi = (lo + hi - 1) / 2;
            } else {
                lo = (lo + hi) / 2 + 1;
            }
        } else {
            int mid = (lo + hi) / 2 - 1;

            Guess(mid);
            int res = Guess(mid + 2);

            prv = mid + 2;

            if(res == 0){
                return mid + 1;
            } else if (res == 1){
                lo = mid + 2;
            } else {
                hi = mid;
            }
        }
    }

    if(lo != hi){
        if(prv == lo){
            return Guess(hi) == 1 ? hi : lo;
        } else if (prv == hi){
            return Guess(lo) == 1 ? lo : hi;
        } else {
            Guess(lo);
            int res = Guess(hi);

            if(res == 1){
                lo = hi;
            } else {
                hi = lo;
            }
        }
    }

    return lo;
}
