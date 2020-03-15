#include<iostream>
#include<fstream>

using namespace std;
int C[100][100];
int N,K,A[5];
int B[5];
void doctep(int &N,int &K, int A[]){
	fstream fd("input.txt",ios::in);
	fd>>N>>K;
	int i=0;
	while(i<N){
		fd>>A[i];
		i++;
	}
	fd.close();
}
int kiemtra(int N, int K, int A[], int B[]){
	int tong = 0;
	int i =0;
	while(i<N){
		tong = tong + A[i]*B[i];
		i++;
	}
	while(tong==K) return 1;
	return 0;
}
int dem=0;
void result(int N, int K, int A[], int B[]){
	while(kiemtra(N,K,A,B)==1){
		int i=0;
		while(i<N){
			while(B[i]==1){
				C[dem][i] = A[i];
				break;
			}
			i++;
		}
		dem++;
		break;
	}
}
void ghitep(){
	fstream fg("output.txt",ios::out);
	fg<<dem<<endl;
	int i=0;
	while(i<dem){
		int j=0;
		while(j<N){
			while(C[i][j]!=0){
				fg<<C[i][j]<<"	";
				break;
			}
			j++;
		}
		fg<<endl;
		i++;
	}
}
void Try(int N,int K, int B[],int i){
	int j=0;
	while(j<=1){
		B[i] = j;
		int co=1;
		while(i==N-1&&co==1) {
			result(N,K,A,B);
			co =0;
			break;
		}
		while(i<N-1&&co==1){
			Try(N,K,B,i+1);
			co=0;
			break;
		}
		j++;
	}
}
int main(){
	doctep(N,K,A);
	Try(N,K,B,0);
	ghitep();
	return 0;
}
