#include <bits/stdc++.h>
using namespace std;

int reverse_stack(stack<int> &s1)//address pass karne se actual stack pr work hota hai
{
  stack<int> s2;
  while (!s1.empty())
  {
    s2.push(s1.top());
    s1.pop();
  }

  stack<int> &temp = s1;
  s1 = s2;
  s2 = temp;

  return 0;
}

int printthestack(stack<int> &s1)
{
  if (s1.empty())
    return -1;

  cout << s1.top() << " ";
  int temp = s1.top();
  s1.pop();

  printthestack(s1);
  s1.push(temp);

  return 0;
}

int main()
{
  stack<int> s1;
  s1.push(5);
  s1.push(4);
  s1.push(3);
  s1.push(2);
  s1.push(1);

  cout << "Stack before reverse operation: ";
  printthestack(s1);
  cout << endl;

  reverse_stack(s1);
  cout << "Reverse operation Applied" << endl;

  cout << "Stack after reverse operation: ";
  printthestack(s1);
  cout << endl;

  return 0;
}