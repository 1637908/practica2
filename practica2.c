//Marta Monsó - 1636465 
//Mercè De la Torre - 1367908
#include <stdio.h>
#include <stdlib.h>

#define N 512

int Mat1[N][N]; //Inicialitzem matrius
int Mat2[N][N];

int Vect1[N]; //Inicialitzem vectors
int Vect2[N];

int tempC[N]; //Inicialitzem vector tmpC, que el farem servir més endavant

int tempTransM1M2[N][N]; //Inicialitzem matriu temporal, que farem servir a PermutaF

void initMats(){
	int i, j;
	srand(8824553);
	for( i=0; i < N; i++ ){ //Bucle per les files
		for( j = 0; j < N; j++ ){ //Bucle per les columnes
			Mat1[i][j] = rand()%100; //Omplim les matrius amb valors semialeatoris
			Mat2[i][j] = rand()%100;
		}
	}
	for( i=0; i < N; i++ ){
		Vect1[i] = rand()%100; //Emplenem els vectors amb valors semialeatoris
		Vect2[i] = rand()%100;
	}
}

void mulMat(int Mat1[N][N], int Mat2[N][N], int tempM1M2[N][N]){
	int i, j;
	for( i=0; i < N; i++ ){
		for( j = 0; j < N; j++ ){
			tempM1M2[i][j] = Mat1[i][j]*Mat2[i][j]; //Multipliquem la posició d'una matriu amb la mateixa de l'altra
		}
	}	
}

void Saxpy(int k,int Vect1[N],int Vect2[N],int tempV1V2[N]){
	int i;
	for( i=0; i < N; i++ ){
		tempV1V2[i] = k*Vect1[i]+Vect2[i]; //Apliquem fórmula de Saxpy
	}
}

void transMat(int tempM1M2[N][N],int tempTransM1M2[N][N]){
	int i, j;
	for( i=0; i < N; i++ ){
		for( j = 0; j < N; j++ ){
			tempTransM1M2[i][j] = tempM1M2[j][i]; //Canviem les files per les columnes de la matriu tempM1M2
		}
	}
}

int sumDiagonal(int tempTransM1M2[N][N]){
	int i, j, suma=0;
	int Vector[N];
	for( i=0; i < N; i++ ){
		for( j = 0; j < N; j++ ){
			if(i==j){ //Quan la fila i la columna tenen el mateix índex, vol dir que es troben a la diagonal
				Vector[i] = tempTransM1M2[i][j]; //Emplenem el vector amb el valor corresponent
				suma+=Vector[i]; //Sumem el valor de la diagonal a la variable suma
			}
		}
	}
	return suma;
}

void sumElement(int tempM1M2[N][N]){
	int i, j;
	
	for( i=0; i < N; i++ ){
		int suma=0;
		for( j = 0; j < N; j++){
			suma+=tempM1M2[j][i]; //Sumem els valors de les columnes, per això capgirem [i][j]
		}
	    	tempC[i]=suma; //Guardem els resultats a la posició corresponent del vector
	}
}
	
int PermutaF(int f1,int f2, int Mat1[N][N]){
	int i;
	int vect[N];
	int vect2[N];
	if((f1>511 || f1<0) || (f2>511 || f2<0)){ 
		return 0; //False
	} 
	else{
	
		for( i=0; i < N; i++ ){
			vect[i]=Mat1[f1][i]; //Guardem la 1a fila a permutar
			vect2[i]=Mat1[f2][i]; //Guardem la 2a fila a permutar
			Mat1[f2][i] = vect[i]; //Intercanviem vectors (files)
			Mat1[f1][i] = vect2[i];
		}
		return 1; //True
	}
}

int main(int argc, char**argv){
	initMats();
	int tempM1M2[N][N];
	mulMat(Mat1, Mat2, tempM1M2);
	for (int i=10; i<20; i++){
		printf("%d ", tempM1M2[10][i]);
	}
	
	int tempV1V2[N];
	Saxpy(4,Vect1,Vect2,tempV1V2);
	for (int i=100; i<120; i++){
		printf("%d ", tempV1V2[i]);
	}
	
	int tempTransM1M2[N][N];
	transMat(tempM1M2,tempTransM1M2);
	for (int i=10; i<20; i++){
		printf("%d ", tempTransM1M2[i][10]);
	}
	int p; 
	int q;
	p = PermutaF(5, 10, Mat1);
	q = PermutaF(100,512, Mat2);
	if(p==1){
		printf("S'ha pogut permutar ");
	}
	else{
		printf("NO s'ha permutat ");
	}
	if(q==1){
		printf("S'ha pogut permutar ");
	}
	else{
		printf("NO s'ha permutat ");
	}
	
	int suma_D;
	suma_D = sumDiagonal(tempTransM1M2);
	printf("%d ", suma_D);
	
	sumElement(tempM1M2);
	for (int i=400; i<420; i++){
		printf("%d ", tempC[i]);
	}
}
