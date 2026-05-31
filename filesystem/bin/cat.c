#include <stdio.h>

int main(int argc, char *argv[]) {
  char input1[256];
  if (argv[1] == NULL) {
     printf("Usage: cat <file>\n");
     return 1;
}
  FILE *ofile = fopen(argv[1], "r");
  if (ofile == NULL) {
     printf("The file you want to read is empty.\n");
     return 1;
}
  while (fgets(input1,256, ofile) != NULL) {
      printf("%s", input1);
}
fclose(ofile);
printf("\n");
}
