#include <bits/stdc++.h>
using namespace std;

struct Move {
    int x, y;
    
    Move(int _x, int _y) : x(_x), y(_y) {}
    Move() : x(0), y(0) {}

    bool operator<(const Move& other) const {
        return (x != other.x) ? x < other.x : y < other.y;
    }
};

// Memoization map
map<Move, int> memo;

// Possible moves for a knight
vector<vector<int>> dirs = {
    {2, 1}, {2, -1}, {-2, 1}, {-2, -1},
    {1, 2}, {1, -2}, {-1, 2}, {-1, -2}
};

// BFS to find shortest knight moves
int bfs(int si, int sj, int di, int dj) {
    queue<Move> q;
    map<Move, int> dis;
    map<Move, Move> parent;
    
    Move start(si, sj);
    q.push(start);
    dis[start] = 0;
    parent[start] = Move(-1, -1); // Mark the root
    
    while (!q.empty()) {
        Move u = q.front();
        q.pop();
        
        if (u.x == di && u.y == dj) break;
        
        for (const auto& d : dirs) {
            int nx = u.x + d[0];
            int ny = u.y + d[1];
            Move v(nx, ny);
            
            if (nx >= 0 && nx < 8 && ny >= 0 && ny < 8 && !dis.count(v)) {
                dis[v] = dis[u] + 1;
                parent[v] = u;
                q.push(v);
            }
        }
    }
    
    // Memoize the result
    memo[{si, sj}] = dis[{di, dj}];

    return dis[{di, dj}];
}

int main() {
    int t;
    string start, end;
    cin >> t;
    
    while (t--) {
        cin >> start >> end;
        
        int si = start[0] - 'a';
        int sj = start[1] - '1';
        int di = end[0] - 'a';
        int dj = end[1] - '1';

        // Check memoized results
        if (memo.count({si, sj})) {
            cout << "To get from " << start << " to " << end << " takes " 
                 << memo[{si, sj}] << " knight moves." << endl;
        } else {
            int moves = bfs(si, sj, di, dj);
            cout << "To get from " << start << " to " << end << " takes " 
                 << moves << " knight moves." << endl;
        }
    }

    return 0;
}

*********************************************************************************************************************************
**************************************************Final Approach*****************************************************************
*********************************************************************************************************************************
#include <bits/stdc++.h>
using namespace std;

struct Move {
    int x, y;

    //todo Define comparison operator for std::map.It's needed whenever we use other structure as key instead of default one.
    bool operator<(const Move& other) const {
        if (x != other.x) return x < other.x;
        return y < other.y;
    }
};

map<Move, int> memo;

// Possible moves for a knight
vector<vector<int>> dirs = {
    {2, 1}, {2, -1}, {-2, 1}, {-2, -1},
    {1, 2}, {1, -2}, {-1, 2}, {-1, -2}
};
// todo TIER2:Here they can also add condition on path like increasing path or something.that condition will go to for->if() 
int dfs(int si, int sj, int di, int dj) {
    if (si == di && sj == dj) return 0;

    if (memo.count({si, sj})) return memo[{si, sj}];

    int ans = INT_MAX; 

    for (auto dir : dirs) {
        int newx = si + dir[0];
        int newy = sj + dir[1];

        if (newx >= 0 && newy >= 0 && newx < 8 && newy < 8) {
            ans = min(ans, 1 + dfs(newx, newy, di, dj));
        }
    }

    return memo[{si, sj}] = ans;
}

int main() {
    int si, sj, di, dj;
    cin >> si >> sj >> di >> dj;

    int result = dfs(si, sj, di, dj);
    cout << "Minimum moves: " << result << endl;

    return 0;
}


// todo TIER1: DFS function to explore all possible paths 
void dfs(int x, int y, int moveCount, vector<vector<bool>>& visited) {
    maxMoves = max(maxMoves, moveCount); // Update maxMoves

    for (auto [dx, dy] : dirs) {
        int nx = x + dx;
        int ny = y + dy;

        if (nx >= 0 && ny >= 0 && nx < 8 && ny < 8 && !visited[nx][ny]) {
            visited[nx][ny] = true;  // Mark as visited
            dfs(nx, ny, moveCount + 1, visited);
            visited[nx][ny] = false; // Backtrack
        }
    }
}