#include <iostream>
#include <queue>
#include <vector>
using namespace std;

int ans=0;

int R, C;
char board[1001][1001];
int visited[1001][1001] = {0};

int dy[4] = {-1, 0, 1, 0};
int dx[4] = {0, 1, 0, -1};

struct Pos{
    int y, x;
};
Pos J;
vector<Pos> Fire;

struct Node{
    char ch;
    Pos now;
    int turn;
};

void BFS(){
    queue<Node> q;
    for(int i=0; i<Fire.size(); i++){
        q.push({'F', Fire[i], 1});
    }
    q.push({'J', J, 1});
    visited[J.y][J.x] = 1;

    while(!q.empty()){
        Node now = q.front(); q.pop();
        
        if(now.ch == 'F'){
            Pos pos = now.now;
            for(int d=0; d<4; d++){
                int ny = pos.y + dy[d];
                int nx = pos.x + dx[d];
                
                if(ny >= R || ny<0 || nx>=C||nx<0) continue;
                if(board[ny][nx] == '#' || board[ny][nx] == 'F') continue;

                board[ny][nx] = 'F';
                q.push({'F', {ny, nx}, now.turn + 1});
                
            }
    
        }
        else if (now.ch == 'J'){
            Pos pos = now.now;
            if(pos.y == 0 || pos.y == R-1 || pos.x == 0 || pos.x == C-1){
                ans = now.turn;
                return;
            }

            for(int d=0; d<4; d++){
                int ny = pos.y + dy[d];
                int nx = pos.x + dx[d];

                if(ny >= R || ny<0 || nx>=C||nx<0) continue;
                if(board[ny][nx] == '#' || board[ny][nx] == 'F') continue;
                if(visited[ny][nx] == 1) continue;

                visited[ny][nx] = 1;
                q.push({'J', {ny, nx}, now.turn+1});
            }
        }
    }
    ans = -1;
}



int main() {
    cin >> R >> C;
    for(int i=0; i<R; i++){
        for(int j=0; j<C; j++){
            cin >> board[i][j];
            if(board[i][j] == 'J') J = {i, j};
            if(board[i][j] == 'F'){
                Fire.push_back({i, j});
            }
        }
    }

    BFS();

    if(ans == -1){
        cout << "IMPOSSIBLE";
    }
    else{
        cout << ans;
    }
    return 0;
}