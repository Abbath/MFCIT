#include <stdio.h>
#include <string.h>
#include <stdlib.h>
int freqs[7] = {25, 20, 10, 5, 5, 3, 2};
char code[7]={0,0,0,0,0,0,0},symb[7] = {'a', 'b', 'c', 'd', 'e' ,'f' ,'g'};
struct Sym 
{
	char sym,code[7];
	int freq;
	struct Sym *left,*right,*next,*prev;
};
struct Sym *first,*run,*last,*root;

void out1 (){
	struct Sym *run1=first ;
	while (run1){
	printf("%d\n",run1->freq);
	run1=run1->next;
}
	return;
	
	}
void sort()
{
	
	for (int i = 0; i < 7; i++)
	{
		run=first;
		struct Sym *tmp = malloc(sizeof (struct  Sym));
		while (run->next)
		{
			if (run->freq < run->next->freq || (run->prev!=NULL && run->prev->freq < run->freq))
			{
				tmp->freq=run->freq;
				tmp->sym=run->sym;
				tmp->right=run->right;
				tmp->left=run->left;
				run->freq=run->next->freq;
				run->sym=run->next->sym;
				run->right=run->next->right;
				run->left=run->next->left;
				run->next->freq=tmp->freq;
				run->next->sym=tmp->sym;
				run->next->right=tmp->right;
				run->next->left=tmp->left;
			}
			
			run=run->next;
			
		}
		last=run;
	}
	/*out1();*/
}
void ololo ()//Init
{
	run = malloc(sizeof (struct Sym));
	first=run;
	run->prev=NULL;
	for (int i = 0; i < 7 ; i++)
	{
		run->sym=symb[i];
		run->freq=freqs[i];
		for (int j = 0; j <7 ; j++)
		run->code[j]=0;
		run->next=malloc(sizeof (struct Sym));		
		run->next->prev=run;
		run->left=run->right=NULL;
		run=run->next;	
	}
	last=run->prev;
}
void huff()
{
	run=malloc(sizeof (struct Sym));
	run->freq=last->freq+last->prev->freq;
	run->sym=0;
	run->left=last->prev;
	run->right=last;
//	if (last->prev->prev)
	last->prev->prev->next=run;
	run->prev=last->prev->prev;
	run->left->next=run->right->next=run->left->prev=run->right->prev=run->next=NULL;
	last=run;
	sort();
	//sort();
	//sort();
	//out (last);
}
void out(struct Sym *a,int b)
{
	if(a==NULL) return;
	out(a->right,b+1);
	//if(a->sym!=0)
	/*for (int i = 0; i <b ; i++)
	{
		printf("   ");
	}*/
	if (a->sym)
	printf( "Symbol: %1c Frequency: %2d Code: %7s\n",a->sym,a->freq,a->code);
	out(a->left,b+1);
}

void drop(struct Sym *run)
{
	if (run->left==NULL || run->right==NULL) return;
	strcat(run->left->code,run->code);
	strcat(run->left->code,"1");
	strcat(run->right->code,run->code);
	strcat(run->right->code,"0");
	drop(run->left);
	drop(run->right);
}
int main(int argv,char ** argc)
{	
	printf("The list of codes:\n");
	ololo();
	for (int i = 0; i < 5; i++)
	huff();
	run=first;
	root=malloc(sizeof (struct Sym));
	root->left=first;
	root->right=last;
	drop(root);
	out(root,0);
	return 0;
}
