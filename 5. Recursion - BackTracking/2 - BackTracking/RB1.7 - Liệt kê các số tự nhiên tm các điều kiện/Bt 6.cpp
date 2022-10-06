#include<iostream>
using namespace std;
int K[100],n;
int P,Q,R;
int kiemtra1(int K[], int n){
	while(K[0]==0) return 0;
	while(K[0]!=0) return 1;	
}
int thuannghich(int y){
	int x = y; 
	int du = 0;
	int nghich =0;
	while(x>=10){
		du = x%10;
		nghich = nghich *10 +du;
		x =x/10;
	}
	nghich = nghich *10 +x;
	while( y == nghich ) return 1;
	return 0;
}
int kiemtra2(int K[], int n){
	int so =0;
	int m=1;
	int i=n-1;
	while(i>=0){
		so = so +K[i]*m;
		m =m*10;
		i--;
	}
	while(thuannghich(so)==1) return 1;
	return 0;
}
int kiemtra3(int K[], int n, int P){
	int tong = 0;
	int i=0;
	while(i<n){
		tong += K[i];
		i++;
	}
	while(tong%P==0) return 1;
	return 0;
}
int kiemtra4(int K[], int n, int Q){
	int tich = 1;
	int i=0;
	while(i<n){
		tich *= K[i];
		i++;
	}
	while(tich%Q==0) return 1;
	return 0;
}
int kiemtra5(int K[], int n, int R){
	int i=0;
	while(i<n){
		while(K[i]==R) return 0;
		i++;
	}
	return 1;
}

void result(int K[], int n){
	while(kiemtra1(K,n)==1&&kiemtra2(K,n)==1){
		int i=0;
		while(i<n){
			cout<<K[i]<<" ";
			i++;
		}
		cout<<endl;
		break;
	}
}
void Try(int K[], int n, int i){
	int j=0;
	while(j<=9){
		K[i]=j;
		int co =1;
		while(i==n-1&&co==1){
			 result(K,n);;
			 co=0;
			 break;
		}
		while(i<n-1&&co==1){
			Try(K,n,i+1);
			co =0;
			break;
		}
		j++;
	}
}
int main(){
	Try(K,2,0);
	Try(K,3,0);
	return 0;
}
