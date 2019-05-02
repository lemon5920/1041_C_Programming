#include<stdio.h>
int main()
{
  int people, i;
  scanf("%d", &people);
  int time[people];
  for (i = 0; i < people; i++) {
    scanf("%d", &time[i]);
  }
  comb(people, time, );
  return 0;
}
