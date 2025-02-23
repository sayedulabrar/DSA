#include <bits/stdc++.h>
#include <stdio.h>
#define fin freopen("input", "r", stdin)

using namespace std;

vector<int> constructTempArray(string pattern) {
    vector<int> lps(pattern.length());
    int index = 0;
    for (int i = 1; i < (int) pattern.length(); ) {
        if (pattern[i] == pattern[index]) lps[i] = index + 1, ++index, ++i;
        else {
            if (index != 0) index = lps[index - 1];//abbcx here x doesn't match and it will look for the prefix that is also suffix till before x 
            else lps[i] = 0, ++i;
        }
    }
    return lps;
    // return pattern.substr(0,lps[pattern.length()-1]); this tells us if there are prefix and suffix of certain length as at the end if it's 0 it means the pattern 
    // didn't match till end .so it will be considered 0 size.But if there is a value then it means that there were serially match and it's size.
}

void KMPMultipleTimes (string text, string pattern) {
    bool found = false;
    vector<int> lps = constructTempArray(pattern);
    int j = 0, i = 0;

    // i --> text, j --> pattern
    while (i < (int) text.length()) {
        if (text[i] == pattern[j]) ++i, ++j;
        else {
            if (j != 0) j = lps[j - 1];
            else ++i;
        }

        if (j == (int) pattern.length()) {
            cout << "found match at : " << (i - pattern.length()) << endl;
            j = lps[j-1];
            found = true;
        }
    }

    if (!found) cout << "not found" << endl;
}

int main() {
    string text, pattern;
    getline(cin, text);
    getline(cin, pattern);
    KMPMultipleTimes(text, pattern);

    return 0;
}
