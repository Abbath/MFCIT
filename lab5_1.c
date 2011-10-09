#include <stdio.h>
#include <math.h>
unsigned char d[4]={0,0,0,0};
void shift(unsigned char a[8]){
	unsigned char tmp=0;
 tmp=a[0];
 for (int i = 0; i <6; i++) {
	 a[i]=a[i+1];
 }
	a[6]=tmp;
}
void out(unsigned char *e){
for (int j = 1; j < 4; j++) {
	printf("%i",*(e+j));
	}
printf("\n");
}
void ololo(){
for (int i = 0; i < 4; i++) {
	d[i]=0;
}
}
unsigned char *cicod(unsigned char ar[8],unsigned char b[4]){
int k=4,l=0;
for (int i = 0; i < 7; i++) {
	if (ar[i]==1){
	l=i;
	k+=l;
	break;
	}
}
for (int i = l; i < l+4; i++) {
	d[i-l]=ar[i];
}
while(1){
	for (int i = 0;  i < 4;  i++) {
		d[i]^=b[i];
	}	
	if(k>=7 && d[0]==0)return &d[0];
	if (d[0]==0 && k<7 ) {
		while(d[0]!=1){
			for (int i = 0; i < 3; i++) {
				d[i]=d[i+1];
			}
			d[3]=ar[k];
			k++;
			if(k==7 && d[0]==0)return &d[0];
		}
	}
}
}
int main (){
unsigned char a0[8],a[8]={1,1,0,0,0,0,0,0};
unsigned char b[4]={1,1,0,1};
unsigned char *e=cicod(a,b);
out(e);
a[6]=*(e+3);
a[5]=*(e+2);
a[4]=*(e+1);
printf("Data=      ");
for (int i = 0; i < 7; i++) {
	printf("%d",a[i]);
}
printf("\n");
ololo();
e=cicod(a,b);
/*out(e);*/
a[1]=0;
printf("Spoiled=   ");
for(int i=0;i<8;i++)a0[i]=a[i];
	for (int i = 0; i < 7; i++) {
		printf("%i",a0[i]);
	}
printf("\n");
for(int i = 0; i < 7;  i++) {
	ololo();
	shift(a0);
	e=cicod(a0,b);
	if (d[3]==1 && d[2]==0 && d[1]==0){
		a[i]^=1;
		break;
	}

}
printf("Corrected= ");
	for (int i = 0; i < 7; i++) {
		printf("%i",a[i]);
	}
return 0;
}
