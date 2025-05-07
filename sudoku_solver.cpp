// File: sudoku_hill_climbing.cpp
// Purpose: Solve a 9×9 Sudoku via hill-climbing minimizing conflicts.

#include <bits/stdc++.h>
using namespace std;

static const int N = 9;
int puzzle[N][N] = {
    {5,3,0, 0,7,0, 0,0,0},
    {6,0,0, 1,9,5, 0,0,0},
    {0,9,8, 0,0,0, 0,6,0},
    {8,0,0, 0,6,0, 0,0,3},
    {4,0,0, 8,0,3, 0,0,1},
    {7,0,0, 0,2,0, 0,0,6},
    {0,6,0, 0,0,0, 2,8,0},
    {0,0,0, 4,1,9, 0,0,5},
    {0,0,0, 0,8,0, 0,7,9}
};
int board[N][N];

int heuristic() {
    int c = 0;
    // row/col conflicts
    for(int i=0;i<N;i++){
        vector<int> r(N+1), col(N+1);
        for(int j=0;j<N;j++){
            r[board[i][j]]++;
            col[board[j][i]]++;
        }
        for(int v=1;v<=N;v++){
            if(r[v]>1) c += r[v]-1;
            if(col[v]>1) c += col[v]-1;
        }
    }
    // block conflicts
    for(int bi=0;bi<3;bi++) for(int bj=0;bj<3;bj++){
        vector<int> cnt(N+1);
        for(int i=0;i<3;i++) for(int j=0;j<3;j++){
            cnt[ board[bi*3+i][bj*3+j] ]++;
        }
        for(int v=1;v<=N;v++) if(cnt[v]>1) c += cnt[v]-1;
    }
    return c;
}

void initialize() {
    memcpy(board, puzzle, sizeof(board));
    for(int bi=0;bi<3;bi++) for(int bj=0;bj<3;bj++){
        vector<bool> seen(N+1);
        for(int i=0;i<3;i++) for(int j=0;j<3;j++){
            int v = board[bi*3+i][bj*3+j];
            if(v) seen[v] = true;
        }
        vector<int> miss;
        for(int v=1;v<=N;v++) if(!seen[v]) miss.push_back(v);
        random_shuffle(miss.begin(), miss.end());
        int idx = 0;
        for(int i=0;i<3;i++) for(int j=0;j<3;j++){
            if(board[bi*3+i][bj*3+j]==0)
                board[bi*3+i][bj*3+j] = miss[idx++];
        }
    }
}

void solve() {
    initialize();
    int h = heuristic(), steps = 0;
    while(h > 0 && steps < 100000) {
        int bi = rand()%3, bj = rand()%3;
        vector<pair<int,int>> empties;
        for(int i=0;i<3;i++) for(int j=0;j<3;j++){
            if(puzzle[bi*3+i][bj*3+j]==0)
                empties.emplace_back(bi*3+i, bj*3+j);
        }
        if(empties.size()<2){ steps++; continue; }
        int bestΔ = 0;
        pair<int,int> A,B;
        for(int i=0;i<empties.size();i++){
            for(int j=i+1;j<empties.size();j++){
                auto [x1,y1]=empties[i], [x2,y2]=empties[j];
                swap(board[x1][y1], board[x2][y2]);
                int nh = heuristic(), Δ = h - nh;
                if(Δ > bestΔ){ bestΔ=Δ; A=empties[i]; B=empties[j]; }
                swap(board[x1][y1], board[x2][y2]);
            }
        }
        if(bestΔ>0){
            swap(board[A.first][A.second], board[B.first][B.second]);
            h -= bestΔ;
        }
        steps++;
    }
    if(heuristic()==0) cout<<"Solved in "<<steps<<" steps\n";
    else cout<<"Stuck with conflicts: "<<heuristic()<<"\n";
    for(int i=0;i<N;i++){
        for(int j=0;j<N;j++) cout<<board[i][j]<<" ";
        cout<<"\n";
    }
}

int main(){
    srand(time(nullptr));
    cout<<"--- Sudoku Hill Climbing ---\n";
    solve();
    return 0;
}
