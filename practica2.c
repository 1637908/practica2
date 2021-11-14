#include <stdio.h>
#include <stdlib.h>

void initMats(){
	int i, j;
	srand(8824553);
	for( i=0; i < N; i++ )
		for( j = 0; j < N; j++ ){
			Mat1[i][j] = rand()%100;
			Mat2[i][j] = rand()%100;
		}
	for( i=0; i < N; i++ ){
		Vect1[i] = rand()%100;
		Vect2[i] = rand()%100;
	}
}

void mulMat(){
	int i, j;
	for( i=0; i < N; i++ ){
		for( j = 0; j < N; j++ ){
			Mat3[i][j] = Mat1[i][j]*Mat2[i][j];
		}
	}	
}

void Saxpy(){
	int i;
	for( i=0; i < N; i++ ){
		Vect3[i] = k*Vect1[i]+Vect2[i];
	}
}

void transMat(){
	int i, j;
	for( i=0; i < N; i++ ){
		for( j = 0; j < N; j++ ){
			Mat2[i][j] = Mat1[j][i];
		}
	}
}

void sumDiagonal(){
	int i, j, suma=0;
	for( i=0; i < N; i++ ){
		for( j = 0; j < N; j++ ){
			if(i==j){
				Vector[i] = Mat1[i][j];
				suma+=Vector[i];
			}
		}
	}
}

void sumElement(){
	int i, j;
	for( i=0; i < N; i++ ){
		int suma=0;
		for( j = 0; j < N; j++){
			suma+=Mat1[j][i];
		}
	Vector[i]=suma;
	}
}
	
void PermutaF(){
	int i, j, vect[N];
	for( i=0; i < N; i++ ){
		for( j = 0; j < N; j++ ){
			vect[i]=Mat1[f1][i];
			Mat1[f1][i]=Mat1[f2][i];
			Mat1[f2][i]=vect[i];
		}
	}
}	
			
