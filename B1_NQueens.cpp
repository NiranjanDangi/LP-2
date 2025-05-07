#include<iostream>
#include<vector>
using namespace std;

void printBoard(vector<vector<int> > &board, int N){
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
        {
            cout << board[i][j] << " ";
        }
        cout << endl;
    }
    
}

bool isSafeBT(vector<vector<int> > &board, int row ,int col, int N){
    for(int i = 0; i < col; i++){
        if(board[row][i] == 1) return false;
    }

    for(int i = row, j = col; i >= 0 && j >= 0; i--,j--){
        if(board[i][j] == 1) return false;
    }

    for (int i = row, j = col; j >= 0 && i < N ; i++, j--)
    {
        if (board[i][j] == 1) return false;
    }
    return true;
}

bool solveNQueensBT(vector<vector<int> > &board, int col, int N)
{
    if(col >= N) return true;

    for (int i = 0; i < N; i++)
    {
        if(isSafeBT(board,i,col,N))
        {
            board[i][col] = 1;
            if (solveNQueensBT(board,col+1,N)) return true;
            board[i][col] = 0;
        }
    }
    return false;   
}

bool solveNQueensBB(vector<vector<int> > &board, int col, int N, vector<bool> &leftRow, vector<bool> &upperDiag, vector<bool> &lowerDiag){
    if(col >= N) return true;

    for(int row = 0; row < N; row++){
        if (!leftRow[row] && !lowerDiag[row + col] && !upperDiag[col - row + N -1]){ //if full
            board[row][col] = 1;
            leftRow[row] = lowerDiag[row + col] = upperDiag[col - row + N - 1] = true; // lowerDiag : row + col and upperDiag : col - row + N - 1

            if (solveNQueensBB(board, col + 1, N, leftRow, upperDiag, lowerDiag)) return true; //here col+1

            board[row][col] = 0;
            leftRow[row] = lowerDiag[row + col] = upperDiag[col - row + N - 1] = false;
    
        }
    }
    return false;
}

int main()
{
    int N;
    int ch,ch1;
    do
    {
        cout << "Enter the value of N " << endl;
        cin >> N;

        vector<vector<int> > board(N, vector<int>(N, 0));

        cout << "Enter your choice !! " << endl;
        cout << "1-Backtracking\n2-Branch and Bound\n";
        cin >> ch;

        bool result = false;

        if(ch == 1){
            result = solveNQueensBT(board,0,N);
        }
        else if(ch == 2){
            vector<bool> leftRow(N,false), upperDiag(2 * N - 1,false), lowerDiag(2 * N - 1,false);
            result = solveNQueensBB(board,0,N,leftRow,upperDiag,lowerDiag);
        }
        else{
            cout << "Enter a valid choice !! " << endl;
        }

        if(result){
            printBoard(board,N);
        }
        else{
            cout << "Solution does not exist.. " << endl;
        }
        
        cout << "Do you want to continue, Press 1 " << endl;
        cin >> ch1;
    } while (ch1 == 1);
    
    return 0;
}