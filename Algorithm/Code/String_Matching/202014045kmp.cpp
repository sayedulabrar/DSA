
#include <bits/stdc++.h>
using namespace std;
void computeLPSArray(string pat, int m, int* lps)
{

	int len = 0;

	lps[0] = 0;


	int i = 1;
	while (i < m) {
		if (pat[i] == pat[len]) {
			len++;
			lps[i] = len;
			i++;
		}
		else
		{

			if (len != 0) {
				len = lps[len - 1];


			}
			else
			{
				lps[i] = 0;
				i++;
			}
		}
	}
}



void kmp(string pat, string txt)
{
	int m =pat.size();
	int n = txt.size();
	int no=0,num=0;

	int lps[m];

	computeLPSArray(pat, m, lps);

	int i = 0;
	int j = 0;
	while (i < n) {
		if (pat[j] == txt[i]) {
			j++;
			i++;
		}

		if (j == m) {
                cout<<"Found pattern at index "<<i-j<<endl;
			    j = lps[j - 1];
			    no+=1;
		}


		else if (i < n && pat[j] != txt[i]) {

			if (j != 0)
				j = lps[j - 1];
			else
				i = i + 1;
		}
	}
	if(no==0)
    {
        cout<<"Not Found"<<endl;
        cout<<"0 times"<<endl;
    }else{
    cout<<no<<" times"<<endl;
    }
}





int main()
{
    int a;
    string txt,pat;

    cin>>a;
    while(a--)
    {
        cin>>txt>>pat;
        kmp(pat,txt);

    }

	return 0;
}
