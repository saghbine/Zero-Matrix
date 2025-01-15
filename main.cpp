//
//  main.cpp
//  CTCI 1.8 Zero Matrix
//
//  Created by daniel saghbine on 1/8/25.
//

#include <iostream>
#include <cstdlib>
using namespace std;

const int N=5;
const int M=4;

void print_matrix(int mtrx[][M]);
void Zero_Matrix(int mtrx[][M]);

int main()
{
    cout<<"problem\n-------\n\tWrite an algorithm such that if an element in an M x N matrix is 0, its entire row and column are set to 0.\n\n";
    
    cout<<"input\n-----\n";
    int matrix[N][M];
    srand(int(time(0)));
    
    for(int r=0; r < M; r++)
        for(int c=0; c < N; c++)
            matrix[c][r]=rand()%10;

    print_matrix(matrix);
    
    cout<<"output\n------\n";
    Zero_Matrix(matrix);
    
    cout<<"solution\n--------\n\tAuxiliary space complexity: O(m + n); time complexity: O(m n (m + n)).\n\n";
    
    return 0;
}

void print_matrix(int mtrx[][M])
{
    for(int r=0; r < M; r++)
    {
        cout<<'\t';
        
        for(int c=0; c < N; c++)
            cout<<mtrx[c][r]<<' ';
        
        cout<<endl;
    }
    
    cout<<endl;
}

void Zero_Matrix(int mtrx[][M]) // mtrx is an M x N matrix
{
    int row[M]; // temporary row, int array of size M
    int col[N]; // temporary col, int array of size N
    int counter=0; // counter mechanism for indexing into row and col
    
    for(int m=0; m < M; m++) // check int at indices 0...M-1 in row portion of mtrx
    {
        for(int n=0; n < N; n++) // check int at indices 0...N-1 in column portion of mtrx
        {
            if(mtrx[n][m] == 0) // if select int in mtrx is 0
            {
                row[counter]=m; // save row index m in row
                col[counter++]=n; // save col index n in col
            }
        }
    }
    
    for(int c=0; c < counter; c++) // check int at indices 0...counter-1 in row and col
    {
        for(int i=0; i < N; i++) // check saved col indices while row index is constant
        {
            if(mtrx[i][row[c]] != 0) // if select int in mtrx isn't 0
                mtrx[i][row[c]]=0; // set select int in mtrx to 0
        }
        
        for(int i=0; i < M; i++) // check saved row indices while col index is constant
        {
            if(mtrx[col[c]][i] != 0) // if select int in mtrx isn't 0
                mtrx[col[c]][i]=0; // set select int in mtrx to 0
        }
    }
    
    print_matrix(mtrx); // print out mtrx
}
