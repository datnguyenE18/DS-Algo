#include<stdio.h>
#include<conio.h>
void selectsort(float a[],int n){
	for(int i = 1;i <= n;i++){
		int vt = i,j;
		float tmp;
		for(j = i + 1;j <= n;j++){
			if (a[j] < a[vt]) vt = j;
		}
		tmp = a[i];a[i] = a[vt];a[vt] = tmp;
	}
}
void doctep(float a[],int &n){
	FILE *f = fopen("input.txt","r");
	fscanf(f,"%d",&n);
	for(int i = 1;i <= n;i++)
		fscanf(f,"%f",&a[i]);
	fclose(f);
}
void ghitep(float a[],int n){
	FILE *f = fopen("output.txt","w");
	fprintf(f,"%d\n",n);
	for(int i = 1;i <= n;i++)
		fprintf(f,"%f ",a[i]);
	fclose(f);
}
main(){
	float a[100];
	int n;
	doctep(a,n);
	selectsort(a,n);
	ghitep(a,n);
}
