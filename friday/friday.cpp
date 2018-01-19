/*
ID : ndchiph1
PROG : friday
LANG : C++
*/
#include <stdio.h>

using namespace std;
int day, week_day, thir[10];
int n;

void input()
{
    scanf("%d", &n);
}


void output()
{
    printf("%d %d ", thir[7], thir[8]);
	for (int i=2; i<=6; i++) 
        if (i != 6) printf("%d ", thir[i]);
        else printf("%d\n", thir[i]);
}

main()
{   
	freopen("friday.in", "r", stdin);
	freopen("friday.out", "w", stdout);

	input();
    //init 
    week_day = 2; 
    for (int i=2; i<=8; i++) thir[i] = 0;
    
    for (int year=1900; year<=1900+n-1; year++)
        if ((year % 4 == 0 && year % 100 != 0) || (year % 400 == 0))
        {
            for (int month=1; month<=12; month++)
			{
                if (month == 4 || month == 6 || month == 9 || month == 11)
                {
                    for (int day=1; day<= 30; day++)
                    {
                        if (day == 13) thir[week_day]++;
                        week_day++;
                        if (week_day == 9) week_day = 2;
                    }
                }
                if (month == 2) 
                {
                    for (int day=1; day<=29; day++)
                    {
                        if (day == 13) thir[week_day]++;
                        week_day++;
                        if (week_day == 9) week_day = 2;
                    }
                }
                if (month == 1 || month == 3 || month == 5 || month == 7 
                    || month == 8 || month == 10 || month == 12) 
                    for (int day=1; day<=31; day++)
                    {
                        if (day == 13) thir[week_day]++;
                        week_day++;
                        if (week_day == 9) week_day = 2;
                    }
			}
		}
        else
            for (int month=1; month<=12; month++)
			{
                if (month == 4 || month == 6 || month == 9 || month == 11)
				{
                    for (int day=1; day<= 30; day++)
					{
                        if (day == 13) thir[week_day]++;
                        week_day++;
                        if (week_day == 9) week_day = 2;
                    }
                }
                if (month == 2) 
				{
                    for (int day=1; day<=28; day++)
                    {
                        if (day == 13) thir[week_day]++;
                        week_day++;
                        if (week_day == 9) week_day = 2;
                    }
                }
                if (month == 1 || month == 3 || month == 5 || month == 7 
                    || month == 8 || month == 10 || month == 12) 
                    for (int day=1; day<=31; day++)
                    {
                        if (day == 13) thir[week_day]++;
                        week_day++;
                        if (week_day == 9) week_day = 2;
                    }
			}
		
		output();
		return 0;
}
