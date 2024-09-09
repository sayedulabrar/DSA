#include<bits/stdc++.h>
using namespace std;

class Node{
private:
    char val;
    Node *next;

public:
    Node(){
        next = NULL;
    }

    char getValue(){
        return val;
    }
    void setvalue(char v)
    {
        val=v;

    }
    void setnext(Node *t)
    {
        next=t;
    }
    Node* getnext()
    {
        return next;
    }
};

class Stack{
private:
    Node *head;
    int SIZE;
public:
    Stack(){
        head = NULL;
        SIZE = 0;
    }

    void push(char n){
        Node *nw;
        nw=(Node*)malloc(sizeof(Node));
        nw->setvalue(n)
 
        nw->setnext(head);
        head=nw;
    
        SIZE++;
    }

    bool isEmpty(){
        if(head==NULL)
        {
            return true;
        }else
        {
            return false;
        }
    }

    char top(){
        if(head==NULL)
        {
            return -1;
        }else
        {
        char x;
        x=head->getValue();
        return x;
        }
    }

    int pop(){
        if(head==NULL)
        {
            return -1;
        }else
        {
        Node *n;
        n=head;
        char x=head->getValue();
        head=head->getnext();
        free(n);
        SIZE--;
        return x;
        }

    }

    int Size(){
        return SIZE;

    }

    void displaystack(){
         if(isEmpty()){
            cout<<"Stack is empty: 0"<<endl;
	    }
	    else{
            Node *ni;
            ni=head;
            while(ni!=NULL)
            {
                cout<<ni->getValue()<<" " ;
                ni=ni->getnext();

            }
            cout<<endl;
	    }
    }
};

void sortstack(Stack st) {
    Stack temp;  // Auxiliary stack for sorting
    int n = st.size();  // Number of elements in the stack

    // Outer loop to iterate through each element except the last one
    for (int i = 0; i < n - 1; i++) {
        int top = st.pop();  // Pop the top element from the stack

        // Inner loop to find the maximum element and push smaller elements to the auxiliary stack
        for (int j = i + 1; j < n; j++) {
            int temp_top = st.top();  // Get the top element of the stack
            if (temp_top > top) {
                temp.push(top);  // Push the current maximum element to the auxiliary stack
                top = temp_top;  // Update the maximum element
            } else {
                temp.push(temp_top);  // Push the smaller element to the auxiliary stack
            }
        }

        st.push(top);  // Push the maximum element back to the original stack

        // Restore the original order by transferring elements from the auxiliary stack to the original stack
        for (int j = i + 1; j < n; j++) {
            int t = temp.top();  // Get the top element from the auxiliary stack
            temp.pop();  // Pop the top element from the auxiliary stack
            st.push(t);  // Push the element to the original stack
        }
    }

    // Display the sorted stack
    cout << "Sorted Stack is :" << endl;
    st.displaystack();
}



bool balance(const std::string& st) {
    std::stack<char> ss;

    for (char ch : st) {
        switch (ch) {
            case '(':
            case '[':
            case '{':
                ss.push(ch);
                break;
            case ')':
                if (ss.empty() || ss.top() != '(') return false;
                ss.pop();
                break;
            case ']':
                if (ss.empty() || ss.top() != '[') return false;
                ss.pop();
                break;
            case '}':
                if (ss.empty() || ss.top() != '{') return false;
                ss.pop();
                break;
            default:
                // Ignore non-parenthesis characters
                break;
        }
    }

    return ss.empty();
}






int main(){
    int choice, n, value,xx,yy;
    Stack stk;
    string sp;
    cin>>sp;
    cout<<sp;

    bool s=balance(sp);
    if(s==true)
     {
         cout<<"balanced"<<endl;
     }else{

     cout<<"not balanced"<<endl;
     }
    //unsigned num_of_disks = 4;

    //Stack src, dest, aux;
    //Iterative(num_of_disks, src, aux, dest);

    while(choice!=0)
    {
        cout<<"0 - Exit."<<endl;
        cout<<"1 - Push Item."<<endl;
        cout<<"2 - Pop Item."<<endl;
        cout<<"3 - View Top Item."<<endl;
        cout<<"4 - Size of Stack."<<endl;
        cout<<"5 - Display Items (Print STACK)."<<endl;

        cout<<"Enter your choice: ";
        cin>>choice;

        switch(choice){
            case 0:
                break;

            case 1:
                 cout<<"Enter Value:\n";
                cin>>value;
                stk.push(value);
                break;

            case 2:
                yy=stk.pop();
                if(yy==-1){
                    cout<<"\nStack is empty!"<<endl;
                }
                else{
                    cout<<"value has been popped "<<yy<<endl;
                }
                break;

            case 3:
                xx=stk.top();
                cout<<"top item is "<<xx<<endl;
                break;

            case 4:
                yy=stk.Size();
                cout<<"Size of Stack is "<<yy<<endl;
                break;

            case 5:
                stk.displaystack();
                break;

            default:
                cout<<"An Invalid choice."<<endl;
        }

        cout<<endl<<endl;
    }


    return 0;
}






71. Simplify Path
class Solution {
public:
    string simplifyPath(string path) {
        string token = "";
        // TOKENIZATION...
        stringstream ss(path);
        stack<string> st;
        
        while(getline(ss, token, '/')) {

            if(token == "" || token == ".") continue;
            
            if (token != "..") 
                st.push(token);
            else if (!st.empty()) 
                st.pop();
        }
        
        string result = "";
        
        while(!st.empty()){ // add all the stack elements
            result="/"+st.top()+result;
            st.pop();
        }
        // BASE CASE...
        if(result.length()==0) // if no directory or file is present
            result="/"; // minimum root directory must be present in result
        
        return result;
    }
};


Example 1:

Input: s = "1 + 1"
Output: 2
Example 2:

Input: s = " 2-1 + 2 "
Output: 3
Example 3:

Input: s = "(1+(4+5+2)-3)+(6+8)"
Output: 23

insights:when there is lare number like 1225 here we need to take digit by digit and convert to number and put it together .That is why the first 
while loop is.i-- because for loop will do i++ in the end.Sign to keep track of negative.We keep the in pair so a nuber and sign are together and 
during pop it becoes easy to handle.When ( is encountered we push the sum that has been calculated and the latest sign for it and reset sum,sign 
as the previous is already in stack.When ) is encountered that means the sum for () is calculated and we will pop and su it with it .We pop once 
because before () there were only one sign and a number before.

parts:
1)handle large number
2)handle sign
3)handle '('
4)handle ')'

class Solution {
public:
    int calculate(string s) {
        long long int sum = 0;
        int sign = 1;
        stack<pair<int,int>> st;

        for(int i=0; i<s.size();i++){
            if(isdigit(s[i])){
                long long int num = 0;
                while(i<s.size() && isdigit(s[i])){
                    num = num * 10 + (s[i] - '0');
                    i++;
                }
                i--;
                sum += num * sign;
                sign = 1;
            }
            else if(s[i] == '-'){
                sign = -1 * sign;
            }
            else if(s[i] == '('){
                st.push({sum, sign});
                sum = 0;
                sign = 1;
            }
            else if(s[i] == ')'){
                sum = st.top().first + (st.top().second * sum);
                st.pop();

            }
            
        }
        return sum;
    }
};

s consists of integers and operators '+', '-', '*', '/' separated by some number of spaces.no bracket.
class Solution {
public:
    int calculate(string s) {
        stack<pair<int, int>> st;
        long long int ans = 0, curr = 0;
        char sign = '+'; // To store the previously encountered sign
        
        for(int i = 0; i < s.size(); i++) {
            if(isdigit(s[i])) {
                curr = curr * 10 + (s[i] - '0'); // Keep forming the number until you encounter an operator
            } else if(s[i] == '+' || s[i] == '-' || s[i] == '*' || s[i] == '/') {
                if(sign == '*' || sign == '/') {//here sign is previous sign.

                    pair<int, int> num = st.top(); st.pop();
                    curr = (sign == '*' ? num.first * curr : num.first / curr);
                    st.push({curr, num.second}); // Push the updated value with the same sign back to stack
                } else {
                    st.push({curr, (sign == '+' ? 1 : -1)}); // Push the current number and sign to stack
                }
                curr = 0; 
                sign = s[i]; 
            }
        }
        
        while(!st.empty()) {
            pair<int, int> num = st.top(); st.pop();
            ans += num.first * num.second; // Adjust the sign and accumulate the result
        }
            
        return ans;    
    }
};
