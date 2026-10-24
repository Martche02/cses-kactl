/**
 * Author: Team KACTL / Marce
 * Category: contests
 * Source: code/2021/I.cpp
 * Problem: Maratona 2021 - I
 * Description:
 *   Implementation for Maratona 2021 - I
 */
// start 2:54
// end 2:09
// restart 20:17
// WA em 20:46
// end 21:00
// finish 01:34 AC
#include <bits/stdc++.h>
//#define dbg(x) std::cerr << __FILE_NAME__ << ":" << __LINE__ << " -> " << #x << " = " << (x) << "\n"
#define dbg(x) 
using namespace std;
int weekday;

bool ehsegunda(int day)
{
	return (7 + weekday + (day%7))%7 == 0;
}

int proxdiautil(int day)
{
	while (((7 + weekday + (day%7))%7) > 4)
		day++;
	return day;
}

int itera(int day)
{
	day += 30;
	return proxdiautil(day);
	
}

int waitfor(int since)
{
	// tem que jogar pra frente, até virar positivo, e dai arredondar seguinte dia util
	
	// enquanto o dia não for segunda, itera até virar segunda
	// e pra verficar isso é se weekday + since for multiplo de 7
	dbg(since);
	do
	{
		since = itera(since);
	}
	while (!ehsegunda(since) && since < 0);
		
	dbg(since);
	
	if (since >=0)
		return proxdiautil(since);
	
	// since é segunda, então itera3(since) = segunda
	// e da pra fazer isso enquanto o resultado for negativo

	//0 - 2 - 4
	
	// 0 - 30 - 60 - 91
	// reduzir isso aqui pra constante
	since = (since %91) - 91;
	dbg(since);
	
	
	while (since < 0)
		since = itera(since);	
	dbg(since);
	
	//arredondar pro dia util seguinte 
	return proxdiautil(since);
}

int main()
{
  string t;
  int n;
  cin >> t >> n;
  
  vector<string> week = {"Mon", "Tue", "Wed", "Thu", "Fri", "Sat", "Sun"};
  
  weekday = ranges::distance(week.begin(), ranges::find(week,t));
  
  int m = 32;
  
  for (const int i : views::iota(0,n))
  {
    int d;
    cin >> d;
	// -d
	// colocar d pra frente, até virar positivo
	// reduzir d enquanto positivo
	// resultado será o waitfor
	
	dbg(-d);
    m = min(m, waitfor(-d));
    
  }
  
  
  cout << m;
  
  return 0;
}