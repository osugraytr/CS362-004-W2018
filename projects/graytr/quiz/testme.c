#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<time.h>

char inputChar()
{
    int  r = rand()%10;
    // TODO: rewrite this function
    if(r==0){ 
    	return '[';
    }
    else if(r==1){ 
    	return '(';
    }
    else if(r==2){ 
    	return '{';
    }
    else if(r==3){ 
    	return ' ';
    }
    else if(r==4){ 
    	return 'a';
    }
    else if(r==5){ 
    	return 'x';
    }
    else if(r==6){ 
    	return '}';
    }
    else if(r==7){ 
    	return ')';
    }
    else if(r==8){ 
    	return ']';
    }
    return ' ';
}

char *inputString()
{
    int r;
    static char p[6];
    for(int i=0;i<6;i++){
    	r = rand()%6;
        if(r==0){ 
    	    p[i] = 'r';
        }
        else if(r==1){ 
    	    p[i] = 'e';
    	}
        else if(r==2){ 
    	    p[i] = 's';
    	}
        else if(r==3){ 
    	    p[i] = 'e';
    	}
        else if(r==4){ 
    	    p[i] = 't';
    	}
        else if(r==5){ 
    	    p[i] = '\0';
    	}
    }
    // TODO: rewrite this function
    return p;
}

void testme()
{
  int tcCount = 0;
  char *s;
  char c;
  int state = 0;
  while (1)
  {
    tcCount++;
    c = inputChar();
    s = inputString();
    printf("Iteration %d: c = %c, s = %s, state = %d\n", tcCount, c, s, state);

    if (c == '[' && state == 0) state = 1;
    if (c == '(' && state == 1) state = 2;
    if (c == '{' && state == 2) state = 3;
    if (c == ' '&& state == 3) state = 4;
    if (c == 'a' && state == 4) state = 5;
    if (c == 'x' && state == 5) state = 6;
    if (c == '}' && state == 6) state = 7;
    if (c == ')' && state == 7) state = 8;
    if (c == ']' && state == 8){
         printf("State = 8!\n");
	 state = 9;
    }
    if (s[0] == 'r' && s[1] == 'e'
       && s[2] == 's' && s[3] == 'e'
       && s[4] == 't' && s[5] == '\0'
       && state == 9)
    {
      printf("error ");
      exit(200);
    }
  }
}


int main(int argc, char *argv[])
{
    srand(time(NULL));
    testme();
    return 0;
}
