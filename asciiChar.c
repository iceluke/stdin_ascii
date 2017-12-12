#include <stdio.h>

#define ASCII_MAX 256
#define DECIMAL_LEN 3
#define DECIMAL_BASE 10

char getASCII(int length, int base, int (*approveChar)(char));
int approveDecimal(char c);

int main(int argc, char **argv)
{
  char ascii;
  while ((ascii=getASCII(DECIMAL_LEN,DECIMAL_BASE,&approveDecimal))!=EOF){
    putchar(ascii);
  }
  putchar('\n');
  return 0;
}

char getASCII(int length, int base, int (*approveChar)(char))
{
  int i=0;
  char ascii = 0;
  char c;
  for(;;){
    c = getchar();
    if (c==EOF){
      return EOF;
    }
    if (!(approveChar(c))){
      continue;
    }
    ascii = ascii*base + (c-'0');
    if (++i == length){
      break;
    }
  }
  return (ascii%ASCII_MAX);
}

int approveDecimal(char c)
{
  if (c>='0' && c<='9'){
    return 1;
  }
  return 0;
}
