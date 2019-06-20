#include <stdio.h>
#include <stdlib.h>
#include <math.h>

double*
cholesky(double *M, int n){
	double *L = calloc(n*n, sizeof*L);

	if(L == NULL){
		fprintf(stderr, "Memory allocation problem...\n");
		exit(0);
	}

	for(size_t i=0; i<n; i++){
		for(size_t k=0; k<=i; k++){
			double sum = 0;

			for(size_t j=0; j<k; j++)
				sum += L[i*n+j] * L[k*n+j];

			L[i*n+k] = (i!=k) ? (M[i*n+k]-sum)/L[k*n+k]:
				sqrt(M[i*n+i] - sum);

		}
	}

	return L;
}

void
printMatrix(double *M, int n){
	for(size_t i=0; i<n; i++){
		for(size_t j=0; j<n; j++)
			printf("%7.4f ", M[i*n+j]);
		printf("\n");
	}
}

int
main(){
	double M[] = {
		18, 22, 54,  42,
		22, 70, 86,  62,
		54, 86, 174, 134,
		42, 62, 134, 106,
	};

	int n = 4;

	double *L = cholesky(M, n);

	printMatrix(L, n);

	return 0;
}
