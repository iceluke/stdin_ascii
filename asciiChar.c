#import <stdio.h>


/* NOT WORKING, as only checks if the next int will make the value
go above 255. Go back to char[3] version and add a 'sep' argument*/
int main()
{
  char rawReadChar;
  char chrCode;
  int chrBuffer = 0;
  int charIsDecimal;

  while ((rawReadChar=getchar())!=EOF){
    rawReadChar -= '0';
    charIsDecimal = (rawReadChar>=0 && rawReadChar<=9) ? 1 : 0;
    if (!(charIsDecimal)){
      continue;
    }
    chrBuffer = (chrBuffer*10) + rawReadChar;
    if (chrBuffer>255){
      putchar(chrCode);
      chrBuffer = rawReadChar;
    }
    chrCode = chrBuffer;
  }
  return 0;
}
