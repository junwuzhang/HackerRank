#include <bits/stdc++.h>

using namespace std;

// Complete the sherlockAndAnagrams function below.
int sherlockAndAnagrams(string s) {
    map<string, int>  stringMap;
    // construct list of possibles anagrams by permutations
    // i is the start of substring, starting it from the beginning and iterate until the end
    for (int i = 0; i < s.size(); i++){
        // j is the end of substring, starting from 1 (1 after i) and ending as long as it doesn't iterate outside the string
        for (int j = 1; i + j - 1 < s.size(); j++){
            // take one substring
            string subString = s.substr(i, j);
            // sort it from beginning to end so that it is processed for permuation
            sort(subString.begin(), subString.end());
            // add the processed string into the ordered map
            stringMap[subString]++;
        }
    }

    long long ans = 0;
    // iterate through the key of the map (sorted strings) and extract how many times they have appeared
    for (map<string, int>::iterator it = stringMap.begin(); it != stringMap.end(); ++it){
        // if a sorted string has appeared N times, there are N * (N-1) / 2 ways that the characters in that string can be rearranged 
        ans += (long long)(it->second) * (it->second - 1) / 2;
    }
    
    return ans;
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    int q;
    cin >> q;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    for (int q_itr = 0; q_itr < q; q_itr++) {
        string s;
        getline(cin, s);

        int result = sherlockAndAnagrams(s);

        fout << result << "\n";
    }

    fout.close();

    return 0;
}
