#include<iostream>
using namespace std;
int n=2,K[2];
int kiemtra1(int K[], int n){
	while(K[0]==0) return 0;
	while(K[0]!=0) return 1;
}
int kiemtra2(int K[], int n){
	while(K[0]==0) return 0;
	int so=0;
	int m=1;
	int i=n-1;
	while(i>=0){
		so = so + K[i]*m;
		m=m*10;
		i--;
	}
	int j=2;
	while(j<=so/2){
		if(so%j==0) return 0;
		i++;
	}
	return 1;
}
int kiemtra3(int K[], int n){
	while(K[0]==0||K[n-1]==0) return 0;//neu 30 doi ngc thanh 03 ko duoc tinh thi xet them K[n-1]=0
	int so=0;
	int m=1;
	int i=0;
	while(i<n){
		so =so +K[i]*m;
		m = m*10;
		i++;
	}
	int j=2;
	while(j<=so/2){
		if(so%j==0) return 0;
		j++;
	}
	return 1;
}
int nguyento(int x){
	int j=2;
	while(j<=x/2){
		while(x%j==0) return 0;
		j++;
	}
	return 1;
}
int kiemtra4(int K[], int n){
	int tong=0;
	int i=0;
	while(i<n){
		while(K[i]==0) return 0;
		i++;
	}
	i=0;
	while(i<n){
		tong = tong+ K[i];
		i++;
	}
	while(nguyento(tong)==0) return 0;
	return 1;
}
int kiemtra5(int K[], int n){
	int i=0;
	while(i<n){
		while(nguyento(K[i])==0||K[i]==0||K[i]==1) return 0;
		i++;
	}
	return 1;
}
void result(int K[], int n){
	while(kiemtra5(K,n)==1){
		int i=0;
		while(i<n){
			cout<<K[i]<<" ";
			i++;
		}
		cout<<endl;
		break;
	}
}
void Try(int K[], int n,int i){
	int j=0;
	while(j<=9){
		K[i]=j;
		int co=1;
		while(i==n-1&&co==1){
			 result(K,n);
			 co =0;
		 	break;
		}
		while(i<n-1&&co==1) {
			Try(K,n,i+1);
			co = 0;
			break;
		}
		j++;
	}
}
int main(){
	Try(K,n,0);
	return 0;
}
