#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */
    int size, num;
    cin >> size;
    int arrayList[size];
    for (int i=0; i<size; i++){
        cin >> num;
        arrayList[i] = num;
    }

    for (int i=size-1; i>=0; i--){
        cout << arrayList[i] << " ";
    }

    return 0;
}
