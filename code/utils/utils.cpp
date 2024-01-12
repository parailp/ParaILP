#include "header.h"

extern string itos(__int128_t v)
{
  string s;
  s.resize(128);
  char temp;
  int i = 0, j = 0;
  if (v == 0)
  {
    s[0] = '0';
    s[1] = '\0';
    return s;
  }
  if (v < 0)
  {
    v = -v;
    s[0] = '-';
    i = 1;
    j = 1;
  }

  __int128_t temp_v = v;
  while (temp_v < ZoomTimes)
  {
    temp_v *= 10;
    s[i] = '0';
    i++;
    j++;
  }

  while (v > 0)
  {
    s[i++] = v % 10 + '0';
    v /= 10;
  }
  s[i] = '\0';
  int end = i;
  i--;
  while (j < i)
  {
    temp = s[j];
    s[j] = s[i];
    s[i] = temp;
    j++;
    i--;
  }
  for (int i = 0; i < Power; i++)
  {
    s[end - i] = s[end - i - 1];
  }
  s[end - Power] = '.';
  while (s[end] == '0')
  {
    end--;
  }
  if (s[end] == '.')
    end--;
  s[end + 1] = '\0';
  return s;
}