#include <iostream>
#include <string>
using namespace std;

int main() {
	// Complete the program
    string s1, s2;
    cin >> s1 >> s2;

    int len1 = s1.size();
    int len2 = s2.size();

    string output1 = s2[0] + s1.substr(1, s1.size()-1);
    string output2 = s1[0] + s2.substr(1, s2.size()-1);

    cout << len1 << " " << len2 << endl;
    cout << s1+s2 << endl;
    cout << output1 << " " << output2 << endl;
    return 0;
}
