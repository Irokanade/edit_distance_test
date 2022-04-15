//
//  main.cpp
//  edit_distance_test
//
//  Created by Michael Leong on 13/04/2022.
//

#include <iostream>
#include <cstring>
using namespace std;

int main(int argc, const char * argv[]) {
    char oriString[1024] = {0};
    char newString[1024] = {0};
    
    cin >> oriString;
    cin >> newString;
    
    int oriStringLen = (int)strlen(oriString);
    int newStringLen = (int)strlen(newString);
    
    //dyanamic programming approach
    int d[newStringLen+1][oriStringLen+1]; //tablular approach
    
    //fill table
    for(int i = 0; i <= newStringLen; i++) {
        for(int j = 0; j <= oriStringLen; j++) {
            if(j == 0) {
                d[i][j] = i;
            } else if(i == 0) {
                d[i][j] = j;
            } else {
                d[i][j] = std::min({d[i-1][j-1]+(oriString[j-1]!=newString[i-1]), d[i-1][j]+1, d[i][j-1]+1}); //min
            }
        }
    }
    
    //print table
    for(int i = 0; i <= newStringLen; i++) {
        for(int j = 0; j <= oriStringLen; j++) {
            cout << d[i][j] << ' ';
        }
        cout << '\n';
    }
    
    cout << "least amount of operations: " << d[newStringLen][oriStringLen] << '\n';
    
    return 0;
}
