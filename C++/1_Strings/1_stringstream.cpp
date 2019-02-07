#include <sstream>
#include <vector>
#include <iostream>
using namespace std;

vector<int> parseInts(string str) {
	// Complete this function
    vector<int> output;
    string numString;
    int num;

    std::istringstream ss(str);
    std::string token;

    while(std::getline(ss, token, ',')) {
        stringstream numStream(token);
        numStream >> num;
        output.push_back(num);
    }

    return output;
}

int main() {
    string str;
    cin >> str;
    vector<int> integers = parseInts(str);
    for(int i = 0; i < integers.size(); i++) {
        cout << integers[i] << "\n";
    }

    return 0;
}
