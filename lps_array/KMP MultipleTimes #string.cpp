/*
 * Created by Dipta Das on 09-11-18
*/

#include <bits/stdc++.h>
#include <stdio.h>
#define fin freopen("input", "r", stdin)

using namespace std;

vector<int> constructTempArray(string pattern) {
    vector<int> lps(pattern.length());
    int index = 0;
    int i=1;
    while (i < pattern.length()) {
        if (pattern[i] == pattern[index]) lps[i] = index + 1, ++index, ++i; // as length starts from 1 so common suffix prefix length index+1
        else {
            if (index != 0) index = lps[index - 1]; // if not = then we will see what is the length of suffix-prefix we have already matched .SO we will go to lps[index-1] as this value represent length of suffix-prefix it means upto lps[index-1]-1 is matched and we are checking from lps[index-1].
            else lps[i] = 0 , ++i; //if it reached 0 it means no common suffix-prefix found.so length o and we move to next i.
        }
    }
    return lps;
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
