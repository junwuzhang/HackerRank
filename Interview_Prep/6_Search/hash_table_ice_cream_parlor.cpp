#include <bits/stdc++.h>

using namespace std;

vector<string> split_string(string);

map<int, int>::iterator it;

// Complete the whatFlavors function below.
void whatFlavors(vector<int> cost, int money) {
    // construct cost vectors into a map
    // find the two flavors adding up to total money amount (check if (totalMoney - cost[i]) is also in the map)
    // print out the two flavors according to 1-based index storing in the map
    map<int, int> costMap;
    for (int i=0; i<cost.size(); i++){
        if (costMap.count(cost[i]) == 0){
            costMap[cost[i]] = i;
        }
        else if (cost[i] == money/2){
            costMap[cost[i]] = i;
        }
    }

    for (int i=0; i<cost.size(); i++) {
        it = costMap.find(money - cost[i]);
        // if a match is found in the map
        if (it != costMap.end()){
            // first index is the index corresponding to that iterator
            int idx1 = it->second;
            // second index is i, which is where we are currently at in the dictionary
            int idx2 = i;
            // if there is only one value of money/2, then we cannot use this so continue
            if (idx1 == idx2) {
                continue;
            }
            // print out the item indices sequentially
            if (idx1 > idx2){
                cout << idx2 + 1 << " " << idx1 + 1 << endl;
            } else{
                cout << idx1 + 1 << " " << idx2 + 1 << endl;
            }
            break;
        }
    }
    

}

int main()
{
    int t;
    cin >> t;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    for (int t_itr = 0; t_itr < t; t_itr++) {
        int money;
        cin >> money;
        cin.ignore(numeric_limits<streamsize>::max(), '\n');

        int n;
        cin >> n;
        cin.ignore(numeric_limits<streamsize>::max(), '\n');

        string cost_temp_temp;
        getline(cin, cost_temp_temp);

        vector<string> cost_temp = split_string(cost_temp_temp);

        vector<int> cost(n);

        for (int i = 0; i < n; i++) {
            int cost_item = stoi(cost_temp[i]);

            cost[i] = cost_item;
        }

        whatFlavors(cost, money);
    }

    return 0;
}

vector<string> split_string(string input_string) {
    string::iterator new_end = unique(input_string.begin(), input_string.end(), [] (const char &x, const char &y) {
        return x == y and x == ' ';
    });

    input_string.erase(new_end, input_string.end());

    while (input_string[input_string.length() - 1] == ' ') {
        input_string.pop_back();
    }

    vector<string> splits;
    char delimiter = ' ';

    size_t i = 0;
    size_t pos = input_string.find(delimiter);

    while (pos != string::npos) {
        splits.push_back(input_string.substr(i, pos - i));

        i = pos + 1;
        pos = input_string.find(delimiter, i);
    }

    splits.push_back(input_string.substr(i, min(pos, input_string.length()) - i + 1));

    return splits;
}
