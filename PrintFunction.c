#include <stdio.h>


typedef unsigned int u32;

char *ctable = "0123456789ABCDEF";
int BASE;

void prints(char *s)
{
  while (*s != '\0')
    {
      putchar(*s);
      ++s;
    }
}

void rpu(u32 x)
{
  char c;
  if (x)
    {
      c = ctable[x % BASE];
      rpu(x / BASE);
      putchar(c);
    }
}

void printu(u32 x)
{
  BASE = 10;
  (x == 0) ? putchar('0') : rpu(x);
  putchar(' ');
}

void rps(int x)
{
  char c;
  if(x)
    {
      c = ctable[x % BASE];
      rps(x / BASE);
      putchar(c);
    }
}

void printd(int x)
{
  BASE = 10;
  if (x < 0)
    {
      putchar('-');
      x = -x;
    }

  (x == 0) ? putchar('0') : rps(x);
  putchar(' ');
}

void printx(u32 x)
{
  BASE = 16;

  putchar('0');
  putchar('x');

  (x == 0) ? putchar('0') : rpu(x);
  putchar(' ');
}

void printo(u32 x)
{
  BASE = 8;

  putchar('0');

  (x == 0) ? putchar('0') : rpu(x);
  putchar(' ');
}


void myprintf(char *fmt, ...)
{
  int *ip = &fmt;
  ++ip;           // Increments ip to next parameter
  char *cp = fmt;

  while(*cp)
    {
      if (*cp == '%')
	{
	  ++cp;
	  switch(*cp)
	    {
	    case 'c' :
	      putchar(*ip);
	      ++ip;
	      break;
	    case 's' :
	      prints(*ip);
	      ++ip;
	      break;
	    case 'u' :
	      printu(*ip);
	      ++ip;
	      break;
	    case 'd' :
	      printd(*ip);
	      ++ip;
	      break;
	    case 'o' :
	      printo(*ip);
	      ++ip;
	      break;
	    case 'x' :
	      printx(*ip);
	      ++ip;
	      break;
	    case '%' :
	      putchar('%');
	      break;
	    default :
	      prints("Invalid character.");
	    }
	}
      else
	{
	  putchar(*cp);
	  if (*cp == '\n')
	    {
	      putchar('\r');
	    }
	}
      ++cp;
    }
}


int main(int argc, char *argv[], char *env[])
{
  myprintf("argc = %d\n", argc);
  for (int i = 0; i < argc; ++i)
    {
      myprintf("argv[%d] = %s \n", i, argv[i]);
    }
	
  myprintf("cha=%c string=%s    dec=%d hex=%x oct=%o neg=%d \n \n", 'A', "this is a test", 100, 100, 100, -100);

  return 0;
}
