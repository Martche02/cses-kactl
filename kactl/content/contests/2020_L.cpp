/**
 * Author: Team KACTL / Marce
 * Category: contests
 * Source: code/2020/L.cpp
 * Problem: Maratona 2020 - L
 * Description:
 *   Implementation for Maratona 2020 - L
 */
// start 1:36
// finished 00:48
#include <bits/stdc++.h>
//#define dbg(x) (std::cerr << std::format("{}:{} -> {} = {}\n", __FILE__, __LINE__, #x, (x)))
#define dbg(x)
using namespace std;

int main()
{
  int n, x;
  cin >> n >> x;
  // n atividades
  // x periodo
  
  vector<pair<int,int>> activities(n);
  
  // comeca em s e dura d
  for (auto& a: activities)
    cin >> a.first >> a.second;
  
  // comeca em 0
  // 1 minimo de conflitos
  // 2 maximo de tomadas
  // abaixo de 8hrs (0<=t<=480)
  
  // só iterar nos 480 possibilidades e atualizar o best! (0.5*10**3)
  // sobra 2*10**4 para descobrir o C
  // o espaço eh 10**5
  
  vector<pair<int, int>> candidates(481);
  for (auto&& [idx, p] : views::enumerate(candidates))
  {
	auto& [c, t] = p;
	t = idx;
	  
	  dbg(c);
	  dbg(t);
    for (auto a : activities)
    { // 5 * 10**6
      int& s = a.first;
      int& d = a.second;
	  // descobrir quantos valores do tipo
	  // s <= t + bx <= s+d
	  // ||
	  // s - t <= bx <= s + d - t
	  // numero de b tal que bx <= s + d - t
	  // - numero de b tal que bx < s - t
	  // a//k+1 = numero de n tal que  0 <= nk <= a
	  // numero de b tal que 0 <= bx <= s + d - t
	  //  isso vai ser (s+d-t)//x + 1
	  // - numero de b tal que bx < s - t
	  //  isso vai ser - ((s+d-t-1)//x+1)
	  // c = ((s+d-t)/x + 1) - ((s+d-t-1)/x+1)
	  // isso se t < s
	  // mas t pode ser s <= t <= d ou d < t
	  // caso d < t, é 0
	  // caso 
	  
	  
	  //dbg(s-t);
	  //dbg(s+d-t);
	  int blw = 0;
	  int top = 0;
	  blw = max(((s-t-1)/x+1), 0);
	  top = max(((s+d-t)/x+1), 0);
	  
	  if (t > s+d)
	  {
		  c += 0;
	  }
	  else if (t >=s)
	  {
		  c += top;
	  }
	  else
	  {
		  c += top - blw;
	  }
	  
	  //c += top - blw;
      //c = (s+d-t)/x - (s-t)/x;
	  dbg(((s+d-t)/x)*x+1);
	  dbg(((s-t)/x)*x+1);
	  dbg(s);
	  dbg((s-t)/x);
	  dbg(d);
	  dbg((s+d-t)/x);
	  dbg(c);
    }
	
	
      ///c = -c;
  }
  
  dbg(candidates);
  
  ranges::sort(candidates);
  dbg(candidates);
  
  cout << candidates[0].second << ' ' << candidates[0].first << endl;
  
  return 0;
}