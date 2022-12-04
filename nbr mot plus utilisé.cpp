#include<stdio.h>
#include<stdlib.h>
#include<string.h>
int nbr_mot(FILE* fs)
{
	char* m;
	int cpt=0;
	m=(char*)malloc(30+1);
	while(fscanf(fs,"%s",m)!=EOF)
	{
		cpt++;
	}
	return cpt;
}
char**  copie_file(FILE* f, int* n)
{
	char**ch,*m;
	int i;
	*n=nbr_mot(f);
	rewind(f);
	ch=(char**)malloc(*n*sizeof(char*));
	for(i=0;i<*n;i++)
		ch[i]=(char*)malloc(30+1);
	m=(char*)malloc(30+1);
	while(fscanf(f,"%s",m)!=EOF)
	strcpy(ch[i++],m);
	return ch;
	
}
int nbr_occ(char**t,int n,char*m)
{
	int i,cpt=0;
	for(i=0;i<n;i++)
	{
		if(strcmp(t[i],m)==0)
		{
			cpt++;
		}
	}
	return cpt;
}
char* mot(FILE*f)
{
	char*m,**t;
	int nbr,n,i;
	t=copie_file(f,&n);
	nbr=nbr_occ(t,n,t[0]);
	for(i=1;i<n;i++){
		if(nbr<nbr_occ(t,n,t[i]))
		{
			nbr=nbr_occ(t,n,t[i]);
			m=t[i];
		}
		
	}
	return m;
}
int main()
{
	char *m=(char*)malloc(400+1);
	FILE*f;
	f=fopen("fichier.txt","r");
	m=mot(f);
	printf("le mot le plus utilisée est %s:\n",*m);
	return 0;
}
