#include<iostream>
#include<vector>
#include<queue>
#include<bitset>

using namespace std;

void getInput(vector<vector<int>>&grid);
void checkInput(vector<vector<int>>&grid);
void printOutput(vector<vector<int>>&grid);
bool solveSudoku(vector<vector<int>>&grid); //giai bang backtracking + heuristic || bitmask || Dancing links
bool checkValidCell(vector<vector<int>>&grid, int row,int column,int num);
bool checkValidSudoku(vector<vector<int>>&grid);


void checkInput(vector<vector<int>>&grid){
    cout<<"ENTER 0 0 0 IF YOU DON'T WANT TO CHANGE ANY CELLS\n";

    int row, column, val;
    while(1){
        cout<<"PLEASE ENTER YOUR ROW, COLUMN AND THE VALUE OF THE CELL:";
        cin>> row >> column;
        if(row == 0) return;
        --row;--column;
        while(1){
            cin >> val;
            int prev = grid[row][column];
            grid[row][column] = val;
            if(val >= 10 || val < 0 || !checkValidSudoku(grid)){
                cout << "\nYOUR NUMBER IS NOT VALID. PLEASE ENTER AGAIN:";
                grid[row][column] = prev;
                continue;
            }
            else break;
        }
    }
}

void getInput(vector<vector<int>>&grid){

    queue<pair<int,int>>WrongNum;

    cout << "SUDOKU TABLE:\n";
    for(int row = 0; row < 9; row++)
        cout << ' ' << '_';
    cout<<'\n';
    for(int row = 0; row < 9; row++){
        for(int column = 0; column < 9; column++)
            cout << '|' << '_' ;
        cout << "|\n";
    }

    cout<<"\nPLEASE ENTER YOUR SUDOKU PROBLEM, BETWEEN EVERY NUMBER MUST HAS A SPACE\n";
    cout<<"\nNOTE: THE MISSING PLACE MUST BE EQUAL TO ZERO\n\n";

    for( int row = 0; row < 9; row++){
        cout << "LINE " << row + 1 << " :";
        for( int column = 0; column < 9; column++){
            int cell;
            cin >> cell;
            if( cell >= 10 || cell < 0){
                WrongNum.push({row+1,column+1});
            }
            else
                grid[row][column]=cell;
        }
        cout<<'\n';
    }

    if(!WrongNum.empty()){
        cout << "THERE ARE SOME WRONG NUMBERS THAT YOU SHOULD ENTER AGAIN\n";
        while(!WrongNum.empty()){
            pair <int,int> u = WrongNum.front();
            WrongNum.pop();
            cout << '(' << u.first << ',' << u.second << "):";
            while(1){
                int x;
                cin >> x;
                if(x >= 10 || x < 0){
                    cout << "WRONG! PLEASE ENTER AGAIN\n";
                    cout << '(' << u.first << ',' << u.second << "):";
                    continue;
                }
                else{
                    grid[u.first - 1][u.second - 1] = x;
                    break;
                }
            }
        }
    }
    while(!checkValidSudoku(grid)){
        cout<<"YOUR SUDOKU PROBLEM VIOLATE THE RULES! PLEASE ENTER AGAIN\n";
        getInput(grid);
    }
    cout << "DO YOU WANT TO CHANGE ANY CELLS? y/n ";
    char c;cin >> c;
    if(c == 'y')
        checkInput(grid);
    else{
        cout<<"\nTHIS IS YOUR SUDOKU TABLE\n";
        printOutput(grid);
    }
}

void printOutput(vector<vector<int>>&grid){
    cout<<'\n';
    for(int row = 0; row < 9; row++){
        for(int column = 0; column < 9; column++)
            cout << '|' << grid[row][column] ;
        cout << "|\n";
    }
}

bool checkValidSudoku(vector<vector<int>>&grid){
    bitset<9>rowHashVct[9], colHashVct[9], boxHashVct[9];

    for(int row = 0 ; row < 9; row++){

        for(int column = 0; column < 9; column++){

            if(grid[row][column] == 0)    continue;
            int val = grid[row][column] - 1;
            int boxIdx = (row/3)*3 + column/3;

            if( rowHashVct[row][val] || colHashVct[column][val] || boxHashVct[boxIdx][val])
                return false;

            rowHashVct[row][val] = 1;
            colHashVct[column][val] = 1;
            boxHashVct[boxIdx][val] = 1;
        }
    }

    return true;
}

bool checkValidCell(vector<vector<int>>&grid, int column, int row, int num){
    for(int i = 0;i < 9; i++){
        if(grid[row][i] == num)
            return false;
        if(grid[i][column] == num)
            return false;
        if(grid[row - row%3 + i/3][column - column%3 + i%3] == num)
            return false;
    }
    return true;
}

bool solveSudoku(vector<vector<int>>&grid){
    if(!checkValidSudoku(grid))
        return false;

    int row=-1,column=-1;
    bool isValid=true;
    for(int i=0;i<9;i++){
        for(int j=0;j<9;j++){
            if(grid[i][j]==0){
                row=i;
                column=j;
                isValid=false;
                break;
            }
        }
        if(!isValid) break;
    }
    if(isValid) return true;

    for(int num = 1;num <= 9; num++){
        if(checkValidCell(grid,column,row,num)){
            grid[row][column]=num;
            if(solveSudoku(grid))
                return true;
            grid[row][column]=0;
        }
    }
    return false;
}

int main(){
    vector<vector<int>>grid(9,vector<int>(9,0));
    cout<<"SUDOKU SOLVER!\n\n";
    getInput(grid);
    if(solveSudoku(grid)){
        cout<<"SUDOKU PROBLEM AFTER SOLVED:\n";
        printOutput(grid);
    }
    else{
        cout<<"SUDOKU PROBLEM HAS NO SOLUTION!";
    }
    return 0;
}

/*
5 3 0 0 7 0 0 0 0
6 0 0 1 9 5 0 0 0
0 9 8 0 0 0 0 6 0
8 0 0 0 6 0 0 0 3
4 0 0 8 0 3 0 0 1
7 0 0 0 2 0 0 0 6
0 6 0 0 0 0 2 8 0
0 0 0 4 1 9 0 0 5
0 0 0 0 8 0 0 7 9
1 2 3 4 5 6 7 8 10
*/
