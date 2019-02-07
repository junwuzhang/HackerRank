#include <bits/stdc++.h>

using namespace std;

// Complete the countingValleys function below.
int countingValleys(int n, string s) {
    int valleyCount = 0;
    int levelValuePrev = 0;
    int levelValueCurr = 0;
    // first convert string (steps taken) to integers (value above/below sea level)
    // from the moment that integer value goes from 0 to a negative value, set valley flag to start
    // until the moment that integer value goes back to equal 0, set valley flag to finish and increase valley count by 1
    for (int i=0; i<n; i++){
        if (s[i] == 'U'){
            levelValueCurr += 1;
        } else{
            levelValueCurr -= 1;
        }
        if (levelValuePrev<0 && levelValueCurr==0){
                valleyCount += 1;
        }
        levelValuePrev = levelValueCurr;
    }
    return valleyCount;
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    int n;
    cin >> n;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    string s;
    getline(cin, s);

    int result = countingValleys(n, s);

    fout << result << "\n";

    fout.close();

    return 0;
}
