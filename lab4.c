#include <stdio.h>
#include <math.h>
void out_bin (unsigned short c){
for (int i = 11; i>=0; i--) {
	if ((c & (unsigned short)pow(2,i))/pow(2,i)==1) printf("1");
	else printf("0");
}
printf("\n");
}
//It is main!
int main (){
int a[8]={2,4,5,6,8,9,10,11};
int b[4]={0,1,3,7};
int d=0;
unsigned short int c=0,c1[4]={0,0,0,0};
unsigned char data=165,tdata=165;
for(int i=7;i>=0;i--)
{ 
if (tdata & 128){
c+=(unsigned short )pow(2.0,a[i]);
}
tdata<<=1;
}

for (int i=0;i<8;i++){
if(a[i] & 1) c1[0]^=(unsigned short)((c & (unsigned short)pow(2,a[i]))/pow(2,a[i])) ;
else
	if(a[i] & 2) c1[1]^=(unsigned short)((c & (unsigned short)pow(2,a[i]))/pow(2,a[i])) ;
	else
		if(a[i] & 4) c1[2]^=(unsigned short)((c & (unsigned short)pow(2,a[i]))/pow(2,a[i])) ;
		else
			if(a[i] & 8) c1[3]^=(unsigned short)((c & (unsigned short)pow(2,a[i]))/pow(2,a[i])) ;
}
for (int i = 0; i < 4; i++) {
	if (!c1[i]) {
		c|=(unsigned short)pow(2,pow(2,i)-1);
	}
}
/*
if ((((c & 1024)/1024) ^(( c & 256)/256) ^(( c & 64 )/64)^ ((c & 16)/16) ^ ((c & 4)/4) ^ (c & 1) ) ==0 ){
	c = c | 1;
}
if ((((c & 1024)/1024) ^ ((c & 512)/512) ^ ((c & 64)/64) ^ ((c & 32)/32) ^ ((c & 4)/4) ^ ((c & 2)/2) ) ==0 ){
	c = c | 2;
}
if ((((c & 2048)/2048) ^ ((c & 64)/64) ^ ((c & 32)/32) ^ ((c & 16)/16) ^ ((c & 8)/8) ) ==0 ){
	c = c | 8;
}
if ((((c & 2048)/2048) ^ ((c & 1024)/1024) ^ ((c & 512)/512) ^ ((c & 256)/256) ^ ((c & 128)/128) ) ==0 ){
	c = c | 128;
}*/
printf("Data=      ");
out_bin(c);
	c |= 256 ;
if ((((c & 1024)/1024) ^ ((c & 256)/256) ^ ((c & 64)/64) ^ ((c & 16)/16) ^ ((c & 4)/4) ^ ((c & 1)/1) ) !=1 ){
	d += 1;
}
if ((((c & 1024)/1024) ^ ((c & 512)/512) ^ ((c & 64)/64) ^ ((c & 32)/32) ^ ((c & 4)/4) ^ ((c & 2)/2) )  !=1 ){
	d +=2;
}  
if ((((c & 2048)/2048) ^ ((c & 64)/64) ^ ((c & 32)/32) ^ ((c & 16)/16) ^ ((c & 8)/8) ) !=1 ){
	d +=4;
}
if ((((c & 2048)/2048) ^ ((c & 1024)/1024) ^ ((c & 512)/512) ^ ((c & 256)/256) ^ ((c & 128)/128) )!=1 ){
	d+=8;
}
printf("Spoiled=   ");
out_bin(c);
if (d){
	if(c & (unsigned short)pow(2.0,d)){
	c -=pow(2.0,d-1);
	}
	else {
	c+=pow(2.0,d-1);
	}
}
printf("Corrected= ");
out_bin(c);
return 0;
}
