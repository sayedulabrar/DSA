#include<bits/stdc++.h>
using namespace std;

struct Node{
    int count;
    Node *children[28];
};

Node *root;

Node *createNode(){
    Node *n = (Node*)malloc(sizeof(Node));
    n->count = 0;
    for(int i=0; i<28; i++) n->children[i]=NULL;
    return n;
}
bool isleaf(Node *as)
{
    for(int i=0;i<28;i++)
    {
        if(as->children[i]!=NULL)
        {
            return false;
        }
    }
    return true;
}


void createEdge(Node *u, Node *v, int c){

    u->children[c]=v;
}
void deledge(Node *u,char c,int d)
{
    int rp;
    if(d==0) return;
    if(c=='@') rp=26;
    else if(c=='.') rp=27;
    else  rp = (int)c - 65;

    Node *v=u->children[rp];
    u->children[rp]=NULL;
    free(v);
}

bool isjun(Node *u)
{
    if(u->count>0) return true;
    if(isleaf(u)) return false;

    return true;
}

void init(){
    root = createNode();
}

void insert(string s){

    Node *u = root;
    int len = s.size();

    for(int i=0; i<len; i++){
        char c = (int)s[i];
        int ki;
        if(c=='@') ki=26;
        else if(c=='.') ki=27;
        else  ki = (int)c - 65;
        Node *v = createNode();
        if(u->children[ki]==NULL)    createEdge(u, v, ki);
        u = u->children[ki];
    }
 u->count++;

}


/*ONLY for 26 alphadet.@ and . is not handled here*/
int Delete(Node *p, int d, string key)
{
    if (d == key.length()) {
        // Handle the base case when we reach the end of the key
        if (p->count < 1) return 0; // Word not present as no count
        
        // Word is present and count >= 1
        if (isleaf(p) == false) {
            p->count--; // Junction node, decrement count
            return 0; // Don't delete the junction node
        }
        
        if (p->count > 1) {
            p->count--; // Multiple instances of the same word, decrement count
            return 0; // Don't delete the node as there are still other instances
        }
        
        // Single instance of the word and it's a leaf node
        return 1; // Delete the leaf node
    }

    if (p == NULL) {
        return 0; // Key not found in the Trie
    }

    int a = Delete(p->children[key[d] - 'A'], d + 1, key);
    if (a == 1) {
        deledge(p, key[d], a);
        if (isjun(p)) return 0; // Don't delete junction nodes
        else return 1; // Delete the node
    }

    return 0; // Key not found in the Trie
}




Node *search( Node *root, string key)
{
    Node *pCrawl = root;

	for (int i = 0; i < key.length(); i++)
	{
		int ki;
		if(key[i]=='@') ki=26;
        else if(key[i]=='.') ki=27;
        else  ki = key[i]-'A';
		if (!pCrawl->children[ki])
			return  NULL;

		pCrawl = pCrawl->children[ki];
	}

	return (pCrawl);
}

void printLexicographic(Node *cur, string s,string g=""){
    if (cur->count>0){
     for(int i=0; i<cur->count; i++)   cout<<s<<g<<endl;
    }
    
    for(int i=0; i<28; i++){
        char cc;
        if(i<26)
        {
            cc = (char)(i+65);
        }
        if(i==26) cc='@';
        if(i==27) cc='.';


        if(cur->children[i]!=NULL)
        {   cur=cur->children[i];

            printLexicographic(cur, s+cc,g);
            // s.pop_back();
            //return;
        }

    }

}


int main()
{
    init();

    int a,b,k;
    string ff,fff;
    string d="";
    cin>>a;

	for(int i=0;i<a;i++)
    {
        cin>>ff;
        for(k=0;k<ff.length();k++)
        {
            d=d+ff[k];
            if(ff[k]=='@')
            break;

        }
        if(ff[k+1]=='G')
        {
            d="GMAIL.COM"+d;

            insert(d);
        }else if(ff[k+1]=='H')
        {
            d="HOTMAIL.COM"+d;

            insert(d);
        }else if(ff[k+1]=='Y')
        {
            d="YAHOO.COM"+d;

            insert(d);
        }
        d.clear();


    }


    cin>>b;
    for(int j=0;j<b;j++)
    {
        cin>>fff;
        cout<<"Query "<<j+1<<" :";
        Node *x=search(root,fff);
        if(x==NULL)
        {
            cout<<"No result found"<<endl;
        }else
        {
          printLexicographic(x,"",fff);


        }
        cout<<endl;
        cout<<endl;



    }





}
/*
10
THE@GMAIL.COM
THEIR@YAHOO.COM
A@HOTMAIL.COM
ANY@GMAIL.COM
ABAR@YAHOO.COM
THEY@GMAIL.COM
BY@YAHOO.COM
BYE@GMAIL.COM
AIUB@HOTMAIL.COM
CU@GMAIL.COM
3
HOTMAIL.COM
YAHOO.COM
GMAIL.COM
*/
