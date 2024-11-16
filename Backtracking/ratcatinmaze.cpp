#include<iostream>
#include<vector>
using namespace std;

//A function that will handle all the below mentioned properties : 
//possibility hai - 
//path closed
//out of bound
//check if pos is already visited
bool issafe(int srcx,int srcy,int newx ,int newy,int maze[][4],int row,int col,vector<vector<bool> >& visited){
if(newx>=0 && newx<row && newy>=0 && newy<col && maze[newx][newy]==1 && visited[newx][newy]==false ) return true;
else return false;
}

void printallpath(int maze[][4],int row,int col,int srcx,int srcy,string& output,vector<vector<bool> >& visited){
    //destination coordinates are [row-1][col-1]
    if(srcx == row-1 && srcy==col-1){
        //reached destination;]
        cout<<output<<endl;
        return ;
    }
    
    //UP 
    int newx = srcx-1;
    int newy = srcy;
    if(issafe(srcx,srcy,newx,newy,maze,row,col,visited)){
        visited[newx][newy] = true;
        output.push_back('U');
        printallpath(maze,row,col,newx,newy,output,visited);
        output.pop_back();
        visited[newx][newy] = false;
    }

    //Right
    newx = srcx;
    newy = srcy+1;
    if(issafe(srcx,srcy,newx,newy,maze,row,col,visited)){
        visited[newx][newy] = true;
        output.push_back('R');
        printallpath(maze,row,col,newx,newy,output,visited);
        output.pop_back();
        visited[newx][newy] = false;
    }

    //Down
    newx = srcx+1;
    newy = srcy;
    if(issafe(srcx,srcy,newx,newy,maze,row,col,visited)){
        visited[newx][newy] = true;
        output.push_back('D');
        printallpath(maze,row,col,newx,newy,output,visited);
        output.pop_back();
        visited[newx][newy] = false;
    }

    //Left
    newx = srcx;
    newy = srcy-1;
    if(issafe(srcx,srcy,newx,newy,maze,row,col,visited)){
        visited[newx][newy] = true;
        output.push_back('L');
        printallpath(maze,row,col,newx,newy,output,visited);
        output.pop_back();
        visited[newx][newy] = false;
    }

}

int main(){
    int maze[4][4]={
        {1,0,0,0},
        {1,1,0,0},
        {1,1,1,0},
        {1,1,1,1}
    };
    int row = 4;
    int col = 4;
    int srcx = 0;
    int srcy = 0;
    string output = "";

    //create visited 2D array 
    vector<vector<bool> >visited(row,vector<bool> (col,false));
    if(maze[0][0]==0){
        //src position is closed that means rat can't move
        cout<<"No path exist..... "<<endl;
    }
    else{
        visited[srcx][srcy] = true;
        printallpath(maze,row,col,srcx,srcy,output,visited);
    }

    return 0;
}