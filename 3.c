#include <stdio.h>
#include <string.h>
// r "`./exp 256`"
int main(int argc, char* argv[]) {
 char buf[256]; /* [1] */
 memset(buf, 0, sizeof(buf));
 strcpy(buf,argv[1]); /* [2] */
 printf("%s\n",buf); /* [3] */
 fflush(stdout);  /* [4] */
 return 0;
}
