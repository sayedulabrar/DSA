#include<bits/stdc++.h>
using namespace std;

class Node{
public:
    int key, level;
    Node *left, *right, *parent;
};


class BST{
private:
    Node *root;

public:
    BST(){
        root = NULL;
    }

    Node* getRoot() {return root;}


public:
    void insert(int val){
        Node *x,*y,*z;
        z=(Node*)malloc(sizeof(Node));
        z->key=val;
        z->left=NULL;
        z->right=NULL;
        z->parent=NULL;
        if(root==NULL)
        {
            root=z;
            return;
        }
        x=root;
        y=NULL;
        while(x!=NULL)
        {
            if(val<x->key){
                y=x;
                x=x->left;
            }else
            {
                y=x;
                x=x->right;
            }

        }
        z->parent=y;
        if(z->key<y->key)
        {
            y->left=z;
        }else
        {
            y->right=z;
        }


    }

    Node* findNode(int val){
         Node *n;
        n=root;
        while(n!=NULL && n->key!=val)
        {
            if(val<n->key){

                n=n->left;
            }else
            {
                n=n->right;
            }

            }
              return n;

        }



    Node* findMaximum(Node *node){
    if node->right==NULL return node;
    return findMaximum(node->right);

    }

    Node* findMinimum(Node *node){
    if node->left==NULL return node;
    return findMinimum(node->left);
    }

    void inOrder(Node *node){
        if(node==NULL) return;
        inOrder(node->left);
        cout<<node->key<<" ";
        inOrder(node->right);

    }


public:


Node* deleteNode(Node* root, int key) {
    // Base case: If the tree is empty or key not found
    if (root == NULL) 
        return root;

    if (key < root->key)
        root->left = deleteNode(root->left, key);
    else if (key > root->key)
        root->right = deleteNode(root->right, key);
    else {
        // Node with only one child or no child
        if (root->left == NULL) {
            Node* temp = root->right;
            if (temp)
                temp->parent = root->parent; // Update the parent pointer of the child
            free(root);
            return temp;
        }
        else if (root->right == NULL) {
            Node* temp = root->left;
            if (temp)
                temp->parent = root->parent; // Update the parent pointer of the child
            free(root);
            return temp;
        }

        Node* temp = minValueNode(root->right);   
        root->key = temp->key;
        root->right = deleteNode(temp, temp->key);
    }
    return root;//  delete er por return else block korbe but uporer baki nodes er jonneto else kaj korbe na so oder jonne ei return .
}
 
    int height(Node *node){
        if(node==NULL)
        {
            return -1;
        }else
        {
            return max(height(node->left),height(node->right)) + 1;
        }
    }


void bfs(){
    queue<Node*> q;
    root->level = 0;
    int level = root->level;
    q.push(root);

    while(!q.empty()){
        Node *temp = q.front();
        q.pop();
        if(temp->level > level){
            cout<<endl;
            level++;
        }
        cout<<temp->key<<" ";
        if(temp->left != NULL) {
            temp->left->level = temp->level + 1;
            q.push(temp->left);
        }
        if(temp->right != NULL) {
            temp->right->level = temp->level + 1;
            q.push(temp->right);
        }
    }
}

};




##To access levelwise elements
q.push(root);
while(!q.empty()){
level_size=q.size();
vector<int>level_elements;
for(i=0 to level_size) { get front ,push it in level_elements ,push it's children ,pop it }

}




Sorted array'to bst.
TreeNode* helper(int l, int r, vector<int>& nums) {
        if (l > r) return nullptr;
        int mid = (l + r) / 2;
        TreeNode* root = new TreeNode(nums[mid]);
        root->left = helper(l, mid - 1, nums);
        root->right = helper(mid + 1, r, nums);
        return root;
    }

//Take the 1st child that we can see at each depth from the right.If a single left child then take that.
// That's why we maintained that depth So only 1 number can enter at each depth.
class Solution {
public:
    vector<int> rightSideView(TreeNode* root) {
        vector<int> result;
        rightView(root, 0, result);
        return result;
    }

private:
    void rightView(TreeNode* node, int depth, vector<int>& result) {
        if (!node) return;
        if (depth == result.size()) {
            result.push_back(node->val);
        }
        if (node->right) {
            rightView(node->right, depth + 1, result);
        } 
        if (node->left) {
            rightView(node->left, depth + 1, result);
        }
    }

   vector<int> rightView(TreeNode *root) {
    if (root == nullptr) return {}; // Handle the case where the root is null
    
    queue<TreeNode*> q;
    vector<int> result;
    q.push(root);

    while (!q.empty()) {
        int size = q.size();
        for (int i = 0; i < size; i++) {
            TreeNode* node = q.front();
            q.pop();
            if (i == 0) { // This is the first node at this level
                result.push_back(node->val);
            }
            if (node->right) {
                q.push(node->right);
            }
            if (node->left) {
                q.push(node->left);
            }
        }
    }

    return result;
}

};




Input:
[
  ["1","1","0","0","0"],
  ["1","1","0","0","0"],
  ["0","0","1","0","0"],
  ["0","0","0","1","1"]
]
We start traversing from the top-left corner. We find the first '1' at position (0,0). Then, we explore all its adjacent land cells 
(either horizontally or vertically). So, we'll explore (0,1) and (1,0), both of which are '1's. Then, we'll explore (1,1), also a '1'. 
At this point, we've explored all connected land cells, and we mark this as the first island.

Now, we need to find the next unexplored '1' that can potentially belong to another island. We continue traversing the grid row by row. So, we move to position (2,2), which is a '1' and start exploring from there. This becomes the second island.

After that, we explore further and find the next island, which consists of the '1's at positions (3,3) and (3,4).
class Solution {
public:
    int m,n;
    int numIslands(vector<vector<char>>& grid) {
        if (grid.empty() || grid[0].empty()) return 0;
        
        m = grid.size();
        n = grid[0].size();
        int numIslands = 0;
        
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                if (grid[i][j] == '1') {
                    ++numIslands;
                    dfs(grid, i, j);
                }
            }
        }
        
        return numIslands;
    }
    
    void dfs(vector<vector<char>>& grid, int i, int j) {

        
        if (i < 0 || j < 0 || i >= m || j >= n || grid[i][j] != '1') return;
        
        grid[i][j] = '0'; // Mark current cell as visited
        
        // Explore neighbors
        dfs(grid, i + 1, j);
        dfs(grid, i - 1, j);
        dfs(grid, i, j + 1);
        dfs(grid, i, j - 1);
    }
};




symmetric tree check.
class Solution {
public:
    bool isSymmetric(TreeNode* root) {
        if (!root) return true; // An empty tree is symmetric by definition
        
        queue<TreeNode*> q;
        q.push(root);
        
        while (!q.empty()) {
            int levelSize = q.size();
            vector<int> levelElements;
            
            for (int i = 0; i < levelSize; ++i) {
                TreeNode* curr = q.front();
                q.pop();
                
                if (curr) {
                    levelElements.push_back(curr->val);
                    q.push(curr->left);
                    q.push(curr->right);
                } else {
                    levelElements.push_back(INT_MIN); // Placeholder for null nodes
                }
            }
            
            // Check if the level elements are symmetric
            if (!isSymmetricLevel(levelElements)) {
                return false;
            }
        }
        
        return true;
    }
    
    bool isSymmetricLevel(const vector<int>& levelElements) {
        int n = levelElements.size();
        for (int i = 0; i < n / 2; ++i) {
            if (levelElements[i] != levelElements[n - 1 - i]) {
                return false;
            }
        }
        return true;
    }
};








Given an m x n integers matrix, return the length of the longest increasing path in matrix.

From each cell, you can either move in four directions: left, right, up, or down. You may not move diagonally or
 move outside the boundary (i.e., wrap-around is not allowed).

 

Example 1:


Input: matrix = [[9,9,4],[6,6,8],[2,1,1]]
Output: 4
Explanation: The longest increasing path is [1, 2, 6, 9].
Example 2:


Input: matrix = [[3,4,5],[3,2,6],[2,2,1]]
Output: 4
Explanation: The longest increasing path is [3, 4, 5, 6]. Moving diagonally is not allowed.
Example 3:

Input: matrix = [[1]]
Output: 1



class Solution {
public:
    int m,n;
    int dirs[4][2] = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};

    int longestIncreasingPath(vector<vector<int>>& matrix) {
        if (matrix.empty()) return 0;

         m = matrix.size();
         n = matrix[0].size();
        vector<vector<int>> memo(m, vector<int>(n, 0));
        int maxPath = 0;

        // Loop through each cell in the matrix
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                maxPath = max(maxPath, dfs(matrix, i, j, memo));
            }
        }

        return maxPath;
    }

    int dfs(vector<vector<int>>& matrix, int i, int j, vector<vector<int>>& memo) {
        if (memo[i][j] != 0) return memo[i][j];
        int currPath = 1;

        for (auto dir : dirs) {
            int x = i + dir[0];
            int y = j + dir[1];

            if (x >= 0 && x < m && y >= 0 && y < n && matrix[x][y] > matrix[i][j]) {
                currPath = max(currPath, 1 + dfs(matrix, x, y, memo));
            }
        }

        memo[i][j] = currPath;
        return currPath;
    }
};





Two binary trees are considered the same if they are structurally identical, and the nodes have the same value.
class Solution {
public:
    bool isSameTree(TreeNode* p, TreeNode* q) {
 
        if (!p && !q)
            return true;
        
        if (!p || !q)
            return false;

        if (p->val != q->val)
            return false;
 
        return isSameTree(p->left, q->left) && isSameTree(p->right, q->right);
    }
};



find the path with target as pathsum. WE can only call a node end of the path if its both choldren null.So we did this way.
class Solution {
public:

    bool hasPathSum(TreeNode* root, int targetSum) {
if(root==NULL) return false;
return  hasPathSum2(root, targetSum);
        
    }
    bool hasPathSum2(TreeNode* root, int targetSum) {
        if (!root->left&&!root->right)
        {
            if(targetSum!=root->val) return false;
            else return true;
        }
        bool ans=false;
        if(root->left) ans+=hasPathSum2(root->left, targetSum - root->val) ; 
        if(root->right) ans+=hasPathSum2(root->right, targetSum - root->val);
        return ans;
               
    }
};





class Solution {
public:
    TreeNode* invertTree(TreeNode* root) {
        if (!root) return nullptr;//important 

        TreeNode* left = invertTree(root->left);
        TreeNode* right = invertTree(root->right);

        root->left = right;
        root->right = left;

        return root;
    }
};


class Solution {
public:
    bool isValidBST(TreeNode* root) {
        return isValidBST(root, nullptr, nullptr); 
    }

private:
    bool isValidBST(TreeNode* root, TreeNode* minNode, TreeNode* maxNode) {
        if (!root) return true;

        // if minnode,maxnode is set check valid range 
        if ((minNode && root->val <= minNode->val) || (maxNode && root->val >= maxNode->val))
            return false;

        // left subtree all<root  
        // riht subtree all>root
        return isValidBST(root->left, minNode, root) && isValidBST(root->right, root, maxNode);
    }
};




Input
root =
[1,2,5,3,4,null,6]
Output
[1,2,5,3,4,null,6]
Expected
[1,null,2,null,3,null,4,null,5,null,6]

class Solution {
public:
    void flatten(TreeNode* root) {
        // Base case: Empty tree
        if (!root) {
            return;
        }

        // Handle the left subtree recursively
        flatten(root->left);

        // Store the right subtree (important for in-place modification)
        TreeNode* rightSubtree = root->right;

        // Set the right child to the flattened left subtree
        root->right = root->left;

        // Null out the left child (essential for linked list structure)
        root->left = nullptr;
        //see the example below
        TreeNode* tail = root;
        while (tail->right) {
            tail = tail->right;
        }

        // Append the stored right subtree and flatten it recursively
        tail->right = rightSubtree;
        flatten(root->right);  // here instead of 5 there can be a subtree and we need to flatten it
    }
};

AT THE END LEFT THERE COULD BE RIGHT SUBTREE WITH HIGHER HEIGHT.So we latten right subtree at the end.

i
    1                   
   / \
  2   5
 / \
3   4

ii
    1
     \
      2
       \
        3
         \
          4
iii
    1
     \
      2
       \
        3
         \
          4
           \
            5



124. Binary Tree Maximum Path Sum.Path can be start and end at any connecting points.
as connecting root ust be included.

class Solution {
public:
    int path(int &maxi,TreeNode* root){
        if(!root)
        return 0;
        int l=max(path(maxi,root->left),0);
        int r=max(path(maxi,root->right),0);
        maxi=max(maxi,l+r+root->val);//keep a track of if current node,l,r is a complete path then is it maximum sum.
        return root->val+max(l,r);  // we are taking only one of l,r because if we take both then that would be a complete path but the solution has only 1 complete path .  
    }
    int maxPathSum(TreeNode* root) {
        int maxi=INT_MIN;
        path(maxi,root);
        return maxi;
    }
};











































#### Given two integer arrays preorder and inorder where preorder is the preorder traversal of a binary tree and inorder is the inorder 
traversal of the same tree.Now prepare level order traversal.


In preorder there is root ,[root of left subtree,remaining of the left subtree],[root of right subtree ,remaining of right subtree].


Inorder left subtree,root,right subtree.

It means if there are preorder 0 1 5 2 15 4 .Inorder 1 5 2 0 15 4 .(just for Example not perfect.)
Here root 0 .left 1,5,2.right 15,4 .so index 1 to 3 of preorder is of left and 0 to 2 for inorder.And index 4 to 5 of preorder is of right 
and 4 to 5 for inorder.
                                     



So if we go serially in preorder we will get roots in the level order.And if we search that root index in inorder then we will be able to 
get the elements of left subtree and right subtree.
                    

class Solution {
public:
TreeNode* constructTree(vector < int > & preorder, int preStart, int preEnd, vector 
 < int > & inorder, int inStart, int inEnd, map < int, int > & mp) {
  if (preStart > preEnd || inStart > inEnd) return NULL;

  TreeNode* root = new TreeNode(preorder[preStart]);
  int elem = mp[root -> val];
  int nElem = elem - inStart;

  root -> left = constructTree(preorder, preStart + 1, preStart + nElem, inorder,
  inStart, elem - 1, mp); //karon ekta rangete 3 ta element thakle oi 3 ta same subtree er but orientation alada preorder er inorder er.
  //So amra nelem paoa mane root shoho oi subtree er size jana.So prestart+nelem use hoise.
  root -> right = constructTree(preorder, preStart + nElem + 1, preEnd, inorder, 
  elem + 1, inEnd, mp);

  return root; //after preparing root and it's left ,right child it's returned.
}

TreeNode* buildTree(vector < int > & preorder, vector < int > & inorder) {
  int preStart = 0, preEnd = preorder.size() - 1;
  int inStart = 0, inEnd = inorder.size() - 1;

  map < int, int > mp;
  for (int i = inStart; i <= inEnd; i++) {
    mp[inorder[i]] = i;
  }

  return constructTree(preorder, preStart, preEnd, inorder, inStart, inEnd, mp);
}
};






class Solution {
public:
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        unordered_map<int, int> index;
        for (int i = 0; i < inorder.size(); i++) {
            index[inorder[i]] = i;
        }
        return buildTreeHelper(inorder, postorder, 0, inorder.size() - 1, 0, postorder.size() - 1, index);
    }
    
    TreeNode* buildTreeHelper(vector<int>& inorder, vector<int>& postorder, int inorderStart, int inorderEnd, int postorderStart, int postorderEnd, unordered_map<int, int>& index) {
        if (inorderStart > inorderEnd || postorderStart > postorderEnd) {
            return nullptr;
        }
        int rootVal = postorder[postorderEnd];
        TreeNode* root = new TreeNode(rootVal);
        int inorderRootIndex = index[rootVal];
        int leftSubtreeSize = inorderRootIndex - inorderStart;
        root->left = buildTreeHelper(inorder, postorder, inorderStart, inorderRootIndex - 1, postorderStart, postorderStart + leftSubtreeSize - 1, index);
        root->right = buildTreeHelper(inorder, postorder, inorderRootIndex + 1, inorderEnd, postorderStart + leftSubtreeSize, postorderEnd - 1, index);
        return root;
    }
};

postorder : left ,right,root.So we have postorderStart, postorderStart + leftSubtreeSize - 1 left and rest is right.





Given an m x n matrix board containing 'X' and 'O', capture all regions that are 4-directionally surrounded by 'X'.

A region is captured by flipping all 'O's into 'X's in that surrounded region.

 

Example 1:


Input: board = [["X","X","X","X"],["X","O","O","X"],["X","X","O","X"],["X","O","X","X"]]
Output: [["X","X","X","X"],["X","X","X","X"],["X","X","X","X"],["X","O","X","X"]]
Explanation: Notice that an 'O' should not be flipped if:
- It is on the border, or
- It is adjacent to an 'O' that should not be flipped.
The bottom 'O' is on the border, so it is not flipped.
The other three 'O' form a surrounded region, so they are flipped.
Example 2:

Input: board = [["X"]]
Output: [["X"]]

class Solution {
public:
    void DFS(vector<vector<char>>& board, int i, int j, int m, int n) {
        if(i<0 or j<0 or i>=m or j>=n or board[i][j] != 'O') return;
        board[i][j] = '#';
        DFS(board, i-1, j, m, n);
        DFS(board, i+1, j, m, n);
        DFS(board, i, j-1, m, n);
        DFS(board, i, j+1, m, n);
    }
    
    void solve(vector<vector<char>>& board) {
      
      //We will use boundary DFS to solve this problem
        
      // Let's analyze when an 'O' cannot be flipped,
      // if it has atleast one 'O' in it's adjacent, AND ultimately this chain of adjacent 'O's is connected to some 'O' which lies on boundary of board
        
      //consider these two cases for clarity :
      /*
        O's won't be flipped          O's will be flipped
        [X O X X X]                   [X X X X X]     
        [X O O O X]                   [X O O O X]
        [X O X X X]                   [X O X X X] 
        [X X X X X]                   [X X X X X]
      
      So we can conclude if a chain of adjacent O's is connected some O on boundary then they cannot be flipped
      
      */
        
      //Steps to Solve :
      //1. Move over the boundary of board, and find O's 
      //2. Every time we find an O, perform DFS from it's position
      //3. In DFS convert all 'O' to '#'      (why?? so that we can differentiate which 'O' can be flipped and which cannot be)   
      //4. After all DFSs have been performed, board contains three elements,#,O and X
      //5. 'O' are left over elements which are not connected to any boundary O, so flip them to 'X'
      //6. '#' are elements which cannot be flipped to 'X', so flip them back to 'O'
      //7. finally, Upvote the solution😊   
        
      
     int m = board.size();
        
      if(m == 0) return;  
        
     int n = board[0].size();
     
     //Moving over firts and last column   
     for(int i=0; i<m; i++) {
         if(board[i][0] == 'O')
             DFS(board, i, 0, m, n);
         if(board[i][n-1] == 'O')
             DFS(board, i, n-1, m, n);
     }
        
        
     //Moving over first and last row   
     for(int j=0; j<n; j++) {
         if(board[0][j] == 'O')
             DFS(board, 0, j, m, n);
         if(board[m-1][j] == 'O')
             DFS(board, m-1, j, m, n);
     }
        
     for(int i=0; i<m; i++)
         for(int j=0; j<n; j++)
         {
             if(board[i][j] == 'O')
                 board[i][j] = 'X';
             if(board[i][j] == '#')
                 board[i][j] = 'O';
         }
    }
};