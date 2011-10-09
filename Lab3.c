#include <stdio.h>
#include <unistd.h>
#include <math.h>
/*#include <types.h>*/
double pi=3.14159265358979323846;
double ololo(double n,double a[4],double N,char c){
	double sum=0;
	if (c=='c'){
		for(int i=0;i<4;i++){
			sum+=a[i]*cos(2*pi*i*n/N);
		}}
	if(c=='s'){
		for(int i=0;i<4;i++){
			sum+=a[i]*sin(2*pi*i*n/N);
			}
		sum*=-1;
	}
double  g=sum/N;
/*printf("Sum=%f\n",g);*/
/*printf("G=%f\n",g);*/
return g;
}
void ololo2(double n,double a[4],double N){
double	a1=ololo(n,a,N,'c');
double	a2=ololo(n,a,N,'s');
	double a3=sqrt(pow(a1,2.0)+pow(a2,2.0));
printf("A=%f\n",a3);
	double b=atan(a2/a1);
printf("F=%f\n",b);
}
int main (){
double a[4]={3.0,-1,0,7.0};
ololo2(0,a,4);
ololo2(1,a,4);
ololo2(2,a,4);
ololo2(3,a,4);


return 0;
}
