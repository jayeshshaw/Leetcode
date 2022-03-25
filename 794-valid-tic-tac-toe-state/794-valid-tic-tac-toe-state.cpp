class Solution {
public:
    bool validTicTacToe(vector<string>& board) {
        int x=0,o=0;
        for(auto r : board)
            for(auto c : r){
                x+=('X'==c);
                o+=('O'==c);
            }
        if(x==o)return !will_win(board,'X');
        else if(x==o+1)return !will_win(board,'O');
        return false;
    }
    
    bool will_win(vector<string>& b, char c){
        for(int i=0;i<3;i++)
            if(b[i][0]==c && b[i][1]==c && b[i][2]==c)return true;
        
        for(int j=0;j<3;j++)
            if(b[0][j]==c && b[1][j]==c && b[2][j]==c)return true;
        
        //for diagonal check
        if(b[0][0]==c && b[1][1]==c && b[2][2]==c) return true;
        if(b[2][0]==c && b[1][1]==c && b[0][2]==c) return true;
        
        return false;
    }
};

