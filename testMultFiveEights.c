#include <stdio.h>
#include <stdlib.h>

extern int multFiveEights(int x);

int main () {
  int x, y, z;
  int status = 0;

  if (sizeof(int) != 4) {
    printf("Error: please make sure sizeof(int) == 4.");
    return 1;
  }

  for (x = (1 << 29) - 1; x > -(1 << 29); x--) {
    y = multFiveEights(x);
    z = 5./8 * x;
    if (y != z) {
      printf("Tried %d [0x%x], got %d [0x%x], should have gotten %d [0x%x]\n",
             x, x, y, y, z, z);
      status = 1;
    }
  }

  return status;
}
