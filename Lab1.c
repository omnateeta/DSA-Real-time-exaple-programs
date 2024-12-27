/*Q-1:Develop program in c for the following
a.Decalre a calender as an array of 7 elemets(A dynamically created array)to reprasent
 7 days of week.Eatch elements of the array is a structure having 3 fields.The first
 field is the name of the Day(A dynamically allocated string),the second field is
 the date of the day (A integer) the thirld field is discription of the activity
 for a particular day(A dynamically allocated string)
b.Write functions create(),read(),& display(); to create the calender to read the
 data from the keyboard & to print weeks activity details report on screen*/

#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<conio.h>
typedef struct DAY{
	char *dayName;
	int date;
	char *activity;
}Day;

Day createDay(){
	Day newDay;
	newDay.dayName=(char*)malloc(10*sizeof(char));
	newDay.activity=(char*)malloc(100*sizeof(char));
	fflush(stdin);
	printf("Enter day name:");
	scanf("%s",newDay.dayName);
	fflush(stdin);
	printf("Enter date:");
	scanf("%d",&newDay.date);
	fflush(stdin);
	printf("Enter activity:");
	scanf("%[^\n]s",newDay.activity);
	return newDay;
}

void read(Day calender[])
{
	int i;
	for(i=0;i<7;++i){
		printf("\nEnter details for day %d\n",i+1);
		calender[i]=createDay();
	}
}

void display(Day calender[])
{
	int i;
	printf("\nWeeks activity Details :\n");
	for(i=0;i<7;i++){
		printf("\nDay %d\n",i+1);
		printf("Day Name:%s\n",calender[i].dayName);
		printf("Date:%d\n",calender[i].date);
		printf("Activity:%s\n",calender[i].activity);
	}
}
int main()
{
	int i;
	Day week[7];
	
	printf("Creating the calender..\n");
	read(week);
	
	printf("\nDisplaying the calender..\n");
	display(week);
	
	for(i=0;i<7;++i){
		free(week[i].dayName);
		free(week[i].activity);
	}
	return 0;
}
