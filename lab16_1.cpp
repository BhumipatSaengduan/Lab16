#include<iostream>
#include<cstdlib>
#include<ctime>
#include<iomanip>
using namespace std;

void showData(double *,int,int);

void randData(double *,int,int);

void findRowSum(const double *,double *,int,int);

void findColSum(const double *,double *,int,int);

int main(){
	srand(time(0));
	const int N = 6, M = 8;
	double data[N][M] = {};
	double sum1[N] = {};
	double sum2[M] = {};
	double *dPtr = data[0];
	randData(dPtr,N,M);
	showData(dPtr,N,M);
	
	cout << "---------------------------------------------\n";
	
	findRowSum(dPtr,sum1,N,M);
	showData(sum1,N,1);
	
	cout << "---------------------------------------------\n";
	
	findColSum(dPtr,sum2,N,M); 
	showData(sum2,1,M);
}

void showData(double* p, int N, int M){
    cout << fixed << setprecision(2);
    for (int i = 0; i < N*M; i++){
        cout << *(p+i);
        if (i % M == M - 1) cout << endl;
        else cout << " ";
    }
}

void randData(double* p, int N, int M){
    for(int i = 0; i < N*M; i++){
        *(p+i) = (rand() % 101) * 0.01;
    }
}

void findRowSum(const double* p, double* b, int N, int M) {
    double sum1 = 0;
    for (int i = 0; i < N; i++){
        for (int j = 0; j < M; j++){
            sum1 += *(p+i*M+j);
        }
        *(b+i) = sum1;
        sum1 = 0;
    }
}

void findColSum(const double* p, double* b, int N, int M) {
    double sum2 = 0;
    for (int i = 0; i < M; i++){
        for (int j = 0; j < N; j++){
            sum2 += *(p+i+j*M);
        }
        *(b+i) = sum2;
        sum2 = 0;
    }
}
