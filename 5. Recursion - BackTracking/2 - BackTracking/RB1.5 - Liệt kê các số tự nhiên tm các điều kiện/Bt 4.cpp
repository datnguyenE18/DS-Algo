#include<iostream>
using namespace std;
int n=5,K[5];
int kiemtra1(int K[], int n){
	while(K[0]==0) return 0;
	while(K[0]!=0) return 1;
}
int nguyento(int x){
	int j=2;
	while(j<=x/2){
		while(x%j==0) return 0;
		j++;
	}
	return 1;
}
int kiemtra2(int K[], int n){
	int so=0;
	int m=1;
	int i=n-1;
	while(i>=0){
		so = so+K[i]*m;
		m =m*10;
		i--;
	}
	while(nguyento(so)) return 1;
	return 0;
}
int kiemtra3(int K[],int n){
	int i=0;
	while(i<n){
		while(nguyento(K[i])==0||K[i]==0||K[i]==1) return 0;
		i++;
	}
	return 1;
}
int thuannghich(int x){
	int y=x;
	int nghich =0;
	while(y>=10){
		int du = y%10;
		nghich = nghich *10+ du;
		y =y/10;
	}
	nghich = nghich *10 +y;
	while(nghich ==x) return 1;
	return 0;
}
int kiemtra4(int K[], int n){
	int tong=0;
	int i=0;
	while(i<n){
		tong += K[i];
		i++;
	}
	while(tong<10||tong>99) return 0;
	while(thuannghich(tong)==1) return 1;
	return 0;
}
int kiemtra5(int K[], int n){
	int tich=1;
	int i=0;
	while(i<n){
		tich = tich * K[i];
		i++;
	}
	while(tich<100||tich>999) return 0;
	while(thuannghich(tich)==1) return 1;
	return 0;
}
void result(int K[], int n){
	while(kiemtra2(K,n)==1&&kiemtra4(K,n)==1){
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
		while(i==n-1&&co==1) {
			result(K,n);
			co = 0;
			break;
		}
		while(i<n-1&&co==1) {
			Try(K,n,i+1);
			co =0;
			break;
		}
		j++;
	}
}
int main(){
	Try(K,n,0);
	return 0;
}
