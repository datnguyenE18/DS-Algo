#include<iostream>

using namespace std;
char s[100];
int coso,B=2;
int n=2,K[2];//de can bao chieu chu so thi thay n= bay nhieu
int kiemtra1(int K[],int n){
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
		m=10*m;
		i--;
	}
	int j=2;
	while(j<=so/2){
		while(so%j==0) return 0;
		j++;
	}
	return 1;	
}
int kiemtra3(int K[], int n){
	while(K[0]==0) return 0;
	int i=0;
	int j=n-1;
	while(i<=j){
		while(K[i]!=K[j]) return 0;
		i++;
		j--;
	}
	return 1;
}
int chuyenDoiCoSo(char s[], int n, int B) {
	int soDu = 0;
	int i = 0;
	while (n > 0) {
		soDu = n % B;
		int co =1;
		while(soDu < 10&&co==1) {
			s[i] = '0' + soDu;
			co = 0;
			break;        
		}
		while(soDu>=10&&co==1) {
			s[i] = 'A' + (soDu - 10);
			co = 0;
			break;    
		}
		i++;
		n = n / B;
	}
        s[i] = '\0';
	int a=0,b=i-1;
	while(a<=b){
		if(s[a]!=s[b]) return 0;
		a++;
		b--;
	}
	return 1;
	
}
int kiemtra4(int K[], int n, int B){
	while(K[0]==0) return 0;
	int so=0;
	int m=1;
	int i=n-1;
	while(i>=0){
		so = so+ K[i]*m;
		m =m*10;
		i--;
	}
	while(chuyenDoiCoSo(s,so,B)==1&&kiemtra3(K,n)==1) return 1;
	while(chuyenDoiCoSo(s,so,B)!=1||kiemtra3(K,n)!=1) return 0;
	
}
void result(int K[], int n){
	while(kiemtra4(K,n,B)==1){
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
		while(i==n-1&&co==1) {
			result(K,n);
			co=0;
			break;
		}
		while(i<n-1&&co==1) {
			Try(K,n,i+1);
			co=0;
			break;
		}
		j++;
	}
}
int main(){
	Try(K,n,0);
	return 0;
}
