#include <stdio.h>
#include <math.h>
void out_bin (unsigned long int c,int len){
for (int i = len-1; i>=0; i--) {
	if ((c & (unsigned int)pow(2,i))/pow(2,i)==1) printf("1");
	else printf("0");
}
printf(" ");
}
unsigned short Crc16(unsigned long a){
	unsigned short crc = 0x0000,b=0;
	unsigned int k=0;
	unsigned long a0=a;
	b=a;
	crc =a>>16;
	for (int i = 0; i <16; i++){
		crc = crc & 0x8000 ? (crc ^ 0xc005) : crc;
		if (b & 0x8000){
			crc<<=1;
			crc+=1;
		}
		else {
			crc<<=1;
		}
		b<<=1;
	}
	return crc;
}
int main (){
	unsigned short c;
	unsigned long a=0;
	a=12<<16;
	c=Crc16(a);
	printf("\n");
	a+=c;
	out_bin(a,32);
	printf("\n");
	c=Crc16(a);
	if(c==0)
		printf("There is no bug");
	printf("\n");

	a|=0x80000000;
	out_bin(a,32);
		c=Crc16(a);
	if(c!=0)
		printf("\nThere is a bug");
}
