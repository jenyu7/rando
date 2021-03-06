#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <fcntl.h>
#include <unistd.h>
/*--------
  Adeebur Rahman and Jen Yu
  Period 10 Systems
  HW #/dev(ise a )/random( plan)
  2017-10-28
  --------*/

//returns a random number acquired from /dev/random.
int rand_num()
{
  int fd = open("/dev/random", O_RDONLY);
  int num;
  read(fd, &num, sizeof(num));
  close(fd);
  return num;
}

int main()
{
  int randnums[10], copy[10];
  int i, tmp, fd;
  printf("Generating random numbers:\n");
  //generates random #s and places them in an array
  for (i = 0; i < 10; i++) {
    printf("\trandom %d: %d\n", i, tmp = rand_num());
    randnums[i] = tmp;
  }

  printf("\nWriting numbers to file...\n");
  fd = open("rando", O_CREAT | O_WRONLY, 0644);
  //write the array to the file
  write(fd, randnums, sizeof(randnums));
  close(fd);

  printf("\nReading numbers from file...\n\n");
  fd = open("rando", O_RDONLY);
  //copy contents of a file into a new array
  read(fd, copy, sizeof(randnums));
  close(fd);

  //print out copied array for verification
  printf("Verification that written values were the same:\n");
  for (i = 0; i < 10; i++) {
    printf("\trandom %d: %d\n", i, copy[i]);
  }

  return 0;
}
