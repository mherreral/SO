#include <pthread.h>
#include <stdio.h>
#include "iostream"

using namespace std;

int *matrixA;
int *matrixB;

int main(){
	int rowsA, colsA, rowsB, colsB;

	// read matrix sizes
	cout << "MATRIX A" << "\n";
	cout << "Number of rows" << "\n";
	cin >> rowsA;
	cout << "Number of colums" << "\n";
	cin >> colsA;
	cout << "\n";

	cout << "MATRIX B" << "\n";
	cout << "Number of rows" << "\n";  
	cin >> rowsB;
	cout << "Number of colums" << "\n";
	cin >> colsB;
	cout << "\n";

	// inform error in dimensions
	if(colsA != rowsB){
		cout << "\n" << "You can't multiply those matrix";
		exit(0);
	}

	else{
		// Allocate memory for each matrix
		matrixA = malloc( sizeof(int) * rowsA * colsA );
		matrixB = malloc( sizeof(int) * rowsB * colsB ); 
		cout << "Write matrix A" << "\n";

		// read each matrix[i,j] value
		for(int i = 0; i<rowsA; i++){
			for(int j = 0; j<colsA; j++){
				 cout<<"Enter the "<<i<<", "<<j<<" entry" << "\n";
				 cin>>matrixA[i*colsA+j];
			}
		}

		// read each matrix[i,j] value
		for(int i = 0; i<rowsB; i++){
			for(int j = 0; j<colsB; j++){
				 cout<<"Enter the "<<i<<", "<<j<<" entry" << "\n";
				 cin>>matrixB[i*colsB+j];
			}
		}

//		for(int i = 0; i<rowsA; i++){
//			for(int j = 0; j<colsA; j++){
//				 cout<<matrixA[i*colsA+j];
//			}                                              	
//			
//		}
	}
	return 0;
}
