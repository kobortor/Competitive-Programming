#include<bits/stdc++.h>

using namespace std; 

bool areTheyEqual(vector<int>& array_a, vector<int>& array_b){
    sort(array_a.begin(), array_a.end());
    sort(array_b.begin(), array_b.end());

    return array_a == array_b;
}
