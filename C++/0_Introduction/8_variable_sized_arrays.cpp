#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;


int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */
    int n, q;
    cin >> n >> q;
    vector<int> arrayList[n];

    for (int it=0; it<n; it++){
        int k;
        cin >> k;
        // vector<int> arrayList[k];
        for (int cnt = 0; cnt <k; cnt++){
            int num;
            cin >> num;
            arrayList[it].push_back(num);
        }
    }

    int i, j;
    for (int it=0; it<q; it++) {
        cin >> i >> j;
        int outNumber = arrayList[i][j];
        cout << outNumber << endl;
    }

    return 0;
}
