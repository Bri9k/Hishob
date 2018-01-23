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
	t->tm_mon += 1;
}


// TODO: Optional entry of date.
		
//int optional_date_entry(FILE * f
