#include <pthread.h>
#include <stdio.h>
#include "iostream"

using namespace std;

int *matrixA;
int *matrixB;
int *matrixC;
int *colsA;
int *colsB;
int *colsC;

typedef struct{
	int row; //row
	int col; //col
} threadStruct;

void matrixMultiplication(void *threadArg){
	threadStruct *threadS;
	int pos = 0;
	int row = threadS->row;
	int col = threadS->col;
	int j = 0;
	cout << "help";

	for(int i=0; i<row; i++){
		pos = pos + (matrixA[row* *colsA +i] * matrixB[i* *colsB +col]);
	}
	matrixC[row* *colsB +col];
}

int main(){
		
	//int rowsA, colsA, rowsB, colsB;
	int auxA, auxB, rowsA, rowsB;

	// read matrix sizes
	cout << "MATRIX A" << "\n";
	cout << "Number of rows" << "\n";
	cin >> rowsA;
	cout << "Number of colums" << "\n";
	cin >> auxA;
	colsA = &auxA;
	cout << "\n";

	cout << "MATRIX B" << "\n";
	cout << "Number of rows" << "\n";  
	cin >> rowsB;
	cout << "Number of colums" << "\n";
	cin >> auxB;
	colsB = &auxB;
	cout << "\n";

	// inform error in dimensions
//	cout << "colsA " << *colsA << "\n";
//	cout << "rowsB " << rowsB << "\n";
	if( *colsA != rowsB){
		cout << "\n" << "You can't multiply those matrix";
		exit(0);
	}

	else{
		// Allocate memory for each matrix
		// Given matrixes
		matrixA = malloc( sizeof(int) * rowsA * *colsA );
		matrixB = malloc( sizeof(int) * rowsB * *colsB ); 

		//Resultant matrix
		matrixC = malloc( sizeof(int) * rowsA * *colsB );
		colsC = &*colsB;

		cout << "Write matrix A" << "\n";

		// read each matrix[i,j] value
		for(int i = 0; i<rowsA; i++){
			for(int j = 0; j<*colsA; j++){
				 cout<<"Enter the "<<i<<", "<<j<<" entry" << "\n";
				 cin>>matrixA[i* *colsA + j];
			}
		}

		cout << "\nWrite matrix B" << "\n";

		// read each matrix[i,j] value
		for(int i = 0; i<rowsB; i++){
			for(int j = 0; j<*colsB; j++){
				 cout<<"Enter the "<<i<<", "<<j<<" entry" << "\n";
				 cin>>matrixB[i* *colsB + j];
			}
		}

		for(int i = 0; i<rowsB; i++){
			for(int j = 0; j<*colsB; j++){
				cout << "\n" << matrixB[i* *colsB + j];
			}
		}

		//Define a thread array of size M*N
		int numThreads = rowsA* *colsB;
		int rc;
		long t;
		pthread_t threads[numThreads];

		threadStruct tStruct[numThreads];

		for(t=0; t<numThreads; t++){
			for(int i=0; i<rowsA; i++){
				for(int j=0; j< *colsB; j++){
					//Assign row and col to each thread
					tStruct[t].row = i;
					tStruct[t].col = j;

					//create thread
					rc = pthread_create(&threads[t], NULL, (void *)matrixMultiplication,
							(void *)&tStruct[t]);

					//if an error occurs
					if(rc){
						printf("ERROR; return code from pthread_create() is %d\n", rc);
					}
				}
			}
			pthread_join(threads[t], NULL);
		}

		//PRINT MATRIX C

		for(int i = 0; i<rowsA; i++){
			for(int j = 0; j<*colsA; j++){
				 cout<<matrixC[i* *colsB+j];
			}                                              	
			
		}
      }
	pthread_exit(NULL);
	return 0;
}
