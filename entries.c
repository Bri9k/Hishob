#include <time.h>
#include <stdio.h>

#define MAX 25

typedef struct
{	
	struct tm t;
	int amount;
	char particular[MAX];
}entry;

int getentry(entry * ep, FILE * fo,char * c)
{
	printf("Particular:");
	fgets(ep->particular,MAX,stdin);
	printf("Amount:");
	scanf("%d",&(ep->amount));
	fprintf(fo,"%02d/%02d/%02d\t\t%04d\t\t%20s\n",ep->t.tm_mday,ep->t.tm_mon,ep->t.tm_year,ep->amount,ep->particular);
	printf("More Entries ?\n");
	fgetc(stdin);
	scanf("%c",c);
	fgetc(stdin);
}

int gettime(struct tm * t)
{
	time_t tim = time(NULL);
	*t = *localtime(&tim);
	t->tm_year -= 100;
}
	

int writeentries(FILE * log, int n, entry * a)
{
	n *= sizeof(entry);
	int k = fwrite(a,n,1,log);
	k /= n * sizeof(entry);
}

int readentries(char * s, int n, entry * a)
{
	int i = 0;
	FILE * f = fopen("hishob.log","r");
	while(fread(a,sizeof(entry),n,f) == 1)
	{
		i++;
	}
	fclose(f);
	return n - i;
}

int log_entry(FILE * i, FILE * o, int bal)
{
	register int si = sizeof(entry);
	entry e;
	while(fread(&e,si,1,i) == 1)
	{
		fprintf(o,"%02d/%02d/%02d\t\t%04d\t\t%20s\n",e.t.tm_mday,e.t.tm_mon,e.t.tm_year,e.amount,e.particular);
	}
	return 0;
}
		

