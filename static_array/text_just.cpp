Input: words = ["This", "is", "an", "example", "of", "text", "justification."], maxWidth = 16
Output:
[
   "This    is    an",
   "example  of text",
   "justification.  "
]

left side space more if spce remains after distribution.But in last one only single space between words and right side all remaining space.


class Solution {
public:
    vector<string>result;

    string fix(vector<string>& l,int maxwidth){
        string final="";
        int tl=0;
        int tlw=l.size()-1;// if there are 3 words space will be for 2 place.
        for(int k=0;k<l.size();k++){
          tl+=l[k].length();
        }
        int space_available=maxwidth-tl;


        final+=l[0];
        if(tlw==0||tlw==1) //0 or 1 means 1 or 2 words.So it will have all the space after 1st word.
        {
            for(int j=0;j<space_available;j++){
                final+=" ";
            }
            if(tlw==1){
                final+=l[1];
            }
        }else{

        int extra=space_available % tlw;// extra space after distributing
        int dist=space_available / tlw;//distributed space for places.

            for(int j=1;j<=tlw;j++){
                for(int m=0;m<dist;m++){
                    final+=" ";
                }
                if(extra>0){
                    final+=" ";
                    extra--;// we need to use extra in the left places.
                }
                final+=l[j];
            }
        }
        return final;

    }

string fixlast(vector<string>& l,int maxwidth){
    
    string final="";
    int tl=0;
    int tlw=l.size()-1;
    for(int k=0;k<l.size();k++){
          tl+=l[k].length();
        }

    int space_available=maxwidth-tl;
    final+=l[0];
    // For the last line of text, it should be left-justified, and no extra space is inserted between words.
    if(tlw==0){
        for(int j=0;j<space_available;j++){
                final+=" ";
        }
    }else{
        for(int i=1;i<=tlw;i++){
            final=final+" "+l[i];
            space_available=space_available-1;

        }
        for(int j=0;j<space_available;j++){
            final+=" ";
        }
    }
    return final;
    }


    vector<string> fullJustify(vector<string>& words, int maxWidth) {
        
        int available=maxWidth;
        vector<string> line;
        for(int i=0;i<words.size();i++){
          if(words[i].length() + 1 >available + 1 ) // if last word in line was last word then it won't need a space.So available + 1.And if words[i] is last word then the last word in line wasn't actual last.So it will need a space .So we add it's space 1 to words[i].length() to balance it.
          {

            string ans=fix(line,maxWidth);
            result.push_back(ans);
            available=maxWidth;
            line={};

          }
          line.push_back(words[i]);
          available-=(words[i].length()+1); // for each word 1 must space.
        }


        // last line will not fall in previous condition and loop breaks.So for it we did this.
        string ans=fixlast(line,maxWidth);
        result.push_back(ans);

        return result;
    }
};