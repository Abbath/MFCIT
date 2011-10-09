#include <stdio.h>
#include <math.h>
int freq[8] = {0, 30, 20, 10, 5, 5, 3, 2};
char code[8][5],sym[7] = {'a', 'b', 'c', 'd', 'e' ,'f' ,'g'};
int sum (int start,int end)//Sum (c)C.O.
{	
	unsigned int summ = 0;
	for (int i = start; i <= end ; i++)
	{
		summ += freq[i];
	}
	return summ;
}
int compare (int start,int i,int end)//Approximately equal half of sum
{
	unsigned int sum1 = sum(start,i);//Sum from begin to [i] element
	unsigned int sum2 = sum(start,end)/2;//Half sum
	if ((fabs(sum(start,i-1)-sum2) >= fabs(sum1-sum2)) && (fabs(sum(start,i+1)-sum2) >= fabs(sum1-sum2))) return 1;
	if (fabs(sum(start,i-1)-sum2) == fabs(sum(start,i+1)-sum2)) return 1;
	return 0;
}	
void ololo (int start,int end,int count)//Shannon-Fano method
{
	if (start == end) return;//If we have only one element
	if (start == end-1) //If we have 2 elements
	{
		code[start][count] = '1';
		code[end][count] = '0';
		return;
	}
	if(start==end-2){
		code[start][count] = '1';
		code[start+1][count] = '0';
		code[end][count] = '0';
		ololo(start+1,end,count+1);
		return;
	}
	for (int i = start; i <= end ; i++) //In other case
	{
		
		if (compare(start,i,end))  //This is comparing
		{
			for (int j = start; j <=i ; j++)//1st group
			{
				code[j][count] = '1';
			}
			for (int k = i+1; k <= end ; k++)//2nd group
			{
				code[k][count] = '0';
			}
			ololo(start,i,count+1);//Recursive
			ololo(i+1,end,count+1);
			return;
		}
	}	
}
int main(int argv,char ** argc)
{		
	printf("The list of codes:\n");
	ololo(1,7,0);
	for (int i = 1; i <= 7  ; i++)
	{
		printf("Symbol: %c Frequency: %2d Code: %s\n",sym[i-1],freq[i],code[i]);
	}
}       
