// https://www.learning.algozenith.com/problems/WeekDay-616

/*

Description

You are given a date and you have to print the corresponding day of the week for that date.
You have to take in three numbers d, m, and y representing the day, month, and year respectively.
Return the answer as one of the following values {"Sunday", "Monday", "Tuesday", "Wednesday", "Thursday", "Friday", "Saturday"}.

Can you solve this problem in O(1) time complexity?


Input Format

Implement the WeekDay function that takes in the date. (d,m and y)


Output Format

Return the string representing the day of the week for the date given.


Constraints

The given dates are valid dates between the years 1971 and 2100.

Sample Input 1

25 11 2095

Sample Output 1

Friday

*/



#include <bits/stdc++.h>
using namespace std;

string WeekDay(int day, int month, int year)
{
	// 1 jan 1968 -> Monday

    int days=365*(year-1968)+(year-1968+3)/4;
    vector<int>months={31,28,31,30,31,30,31,31,30,31,30,31};
    for(int i=0;i<month-1;i++) days+=months[i];
    days+=day;
    if(year%4==0 and year!=2100 and month>2) days+=1;
    vector<string>v={"Sunday","Monday","Tuesday","Wednesday","Thursday","Friday","Saturday"};
    return v[days%7];
}

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	int day, month, year;
	cin >> day >> month >> year;
	
	cout << WeekDay(day, month, year);
}
