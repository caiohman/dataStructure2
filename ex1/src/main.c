#include <stdio.h>
#include <stdlib.h>
#include "read.h"
#include <assert.h>
#include <string.h>

#define DATA 108

int main(int argc, char const *argv[]) {

  FILE *filename;
  char file_name[10];
  int op;

  scanf("%s\n", file_name);
  scanf("%d", &op);

  //open binary file
  filename = fopen(file_name , "rb");
  assert(filename);

  //go to last position
  fseek(filename, 0, SEEK_END);
  long int regs = ftell(filename);
  regs /= DATA; //total bytes / bytes per register

  int start, end, pos;

  switch (op) {
    case 1: //all registers
      //go to position 0
      fseek(filename, 0, SEEK_SET);

      for(int i = 0 ; i < (regs - 1); i++){
        _read_regs(filename, 1);
      }
      _read_regs(filename, 0);
      break;
    case 2: //start to middle
      //go to position 0
      fseek(filename, 0, SEEK_SET);

      for(int i = 0 ; i < ((regs / 2)-1) ; i++){
        _read_regs(filename, 1);
      }
      _read_regs(filename, 0);
      break;
    case 3: //middle to end
      //go to position required
      fseek(filename, ((regs / 2) * DATA), SEEK_SET);

      for(int i = (regs / 2) ; i < (regs - 1); i++){
        _read_regs(filename, 1);
      }
      _read_regs(filename, 0);
      break;
    case 4: //track
      scanf("\n%d %d", &start, &end);
      //go to position required
      fseek(filename, ((start -1) * DATA), SEEK_SET);

      for(int i = start ; i < end && i < regs; i++){
        _read_regs(filename, 1);
      }
      _read_regs(filename, 0);
      break;
    case 5://specific register
      //go to position required
      scanf("%d", &pos); //get position
      fseek(filename, ((pos - 1) * DATA), SEEK_SET);

      _read_regs(filename, 0);
      break;
  }
  fclose(filename);

  return 0;
}
