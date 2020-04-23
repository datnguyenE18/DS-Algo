#include<iostream>
#include<fstream>
using namespace std;
int C[100][100];
int N,K,B,A[100];
int D[100];
void doctep(int &N,int &K,int &B, int A[]){
	fstream fd("input.txt",ios::in);
	fd>>N>>K>>B;
	int i=0;
	while(i<N){
		fd>>A[i];
		i++;
	}
	fd.close();
}
int kiemtra(int N,int K, int B, int A[], int D[]){
	int tong = 0;
	int dem1 = 0;
	int i =0;
	while(i<N){
		tong = tong + A[i]*D[i];
		i++;
	}
	i=0;
	while(i<N){
		while(D[i]==1){
			dem1++;
			break;
		}
		i++;
	}
	while(tong==B&&dem1==K) return 1;
	return 0;
}
int dem=0;
void result(int N, int K,int B, int A[], int D[]){
	
	while(kiemtra(N,K,B,A,D)==1){
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
void Try(int N,int K,int B, int D[],int i){
	int j=0;
	while(j<=1){
		D[i] = j;
		int co=1;
		while(i==N-1&&co==1) {
			result(N,K,B,A,D);
			co =0;
			break;
			
		}
		while(i<N-1&&co==1){
			Try(N,K,B,D,i+1);
			co =0;
			break;
		} 
		j++;
	}
}
int main(){
	doctep(N,K,B,A);
	Try(N,K,B,D,0);
	ghitep();
	return 0;
}
