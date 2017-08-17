#include<iostream>
#include<random>
#include<ctime>
#include<cassert>
#include<chrono>

using namespace std;

void testcase(){
    string input;
    int fish_req = 0, turn_req = 0;
    int bait = 0, caught = 0;

    while(getline(cin, input)){
        turn_req--;
        if(input == "lunch"){
            //do nothing
        } else if (input == "bait"){
            bait = min(6, bait + 1);
			} else if(input == "fish"){
            if(bait >= 2){
                fish_req--;
                //printf("Try catching with %i %i\n", turn_req, fish_req);
                if(fish_req <= 0 && turn_req <= 0){
                    turn_req = 7, fish_req = 3;
                    caught++;
                    bait -= 2;
                }
            }
        } else if(input == ""){
            break;
        }
    }
    cout << caught << "\n";
}

int main(){
    string input;
    getline(cin, input);
    cin.ignore();
    int T = stoi(input);
    while(T--){
        testcase();
        if(T) printf("\n");
    }
}