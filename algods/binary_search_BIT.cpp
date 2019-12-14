#include<bits/stdc++.h>

using namespace std;

const int MAXN = 2e5 + 5; //example
const int LOGN = log2(MAXN);
const int ERROR = 0x3f3f3f3f;

struct b_search_BIT {
    int data[MAXN];
    b_search_BIT(){
        fill(data, data + MAXN, 0);
    }
    void update(int pos, int val){
        assert(pos != 0); //pos = 0 would cause an infinite loop
        
        while(pos < MAXN){
            data[pos] += val;
            pos += pos & -pos;
        }
    }

    //return the first index whose sum is >= x
    int lower_bound(int x){
        int idx = 0;
        int sum = 0;
        for(int a = LOGN; a >= 0; a--){
            int tidx = idx | (1 << a);
            if(tidx >= MAXN){ //x is greater than the total! return an error of some sort
                return ERROR;
            }
            if(sum + data[tidx] < x){
                idx = tidx;
                sum += data[tidx];
            }
        }
        return idx + 1;
    }

    //return the first index whose sum is > x
    int upper_bound(int x){
        int idx = 0;
        int sum = 0;
        for(int a = LOGN; a >= 0; a--){
            int tidx = idx | (1 << a);
            if(tidx >= MAXN){ //x is greater than the total! return an error of some sort
                return ERROR;
            }
            if(sum + data[tidx] <= x){
                idx = tidx;
                sum += data[tidx];
            }
        }
        return idx + 1;
    }
};

b_search_BIT ds;

int main() {
    ds.update(2, 1);
    ds.update(8, 2);
    ds.update(14, 4);

    //-1-----2-----4------
    printf("%-12s%-15s%-15s\n", "Find Sum", "Lower Bound", "Upper Bound");
    for(int a = 0; a <= 8; a++){
        printf("%-12i%-15i%-15i\n", a, ds.lower_bound(a), ds.upper_bound(a));
    }
}

/*
RESULTS:

Find Sum    Lower Bound    Upper Bound
0           1              2
1           2              8
2           8              8
3           8              14
4           14             14
5           14             14
6           14             14
7           14             1061109567
8           1061109567     1061109567
*/
