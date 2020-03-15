#include<iostream>
#include<fstream>

using namespace std;
int C[100][100];
int N,K,A[100];
int D[100],B[100];
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
int kiemtra(int N,int K,int A[], int D[]){
	int dem1 = 0;
	int i=0;
	while(i<N){
		while(D[i]==1){
			B[dem1]=A[i];
			dem1++;
			break;
		}
		i++;
	}
	int j=0;
	while(j<dem1-1){
		while(B[j]>=B[j+1]) return 0;
		j++;
	}
	while(dem1==K ) return 1;
	return 0;
}
int dem=0;
void result(int N, int K,int A[], int D[]){
	while(kiemtra(N,K,A,D)==1){
		int i=0;
		while(i<N){
			while(D[i]==1){
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
	fg.close();
}
void Try(int N,int K,int D[],int i){
	int j=1;
	while(j>=0){
		D[i] = j;
		int co=1;
		while(i==N-1&&co==1){
			result(N,K,A,D);
			co =0;
			break;
		}
		while(i<N-1&&co==1){
			 Try(N,K,D,i+1);
			 co =0;
			 break;
		}
		j--;
	}
}
int main(){
	doctep(N,K,A);
	Try(N,K,D,0);
	ghitep();
	return 0;
}
