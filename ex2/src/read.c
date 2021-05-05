#include "read.h"
#include <assert.h>
#include <string.h>
#include <stdlib.h>
#include <stdio.h>

#define DATA 108

void _read_line_to_struct(READ *read){
  char *lineptr, *token;
  long unsigned int len = 0;
  int count = 0;

  getline(&lineptr,&len ,stdin); //read from stdin

  token = strtok(lineptr, ",");

  while(token != NULL){
    switch (++count) {
      case 1:
        read->uspNumber = atoi(token);
        break;

      case 2:
        strcpy(read->name, token);
        break;

      case 3:
        strcpy(read->class, token);
        break;

      case 4:
        read->grade = atof(token);
        break;
    }

    token = strtok(NULL, ",\n");
  }

  free(lineptr);
  free(token);
}

void _read_all_send_binary(){

  FILE *write_filename = fopen("binary.bin", "wb+");
  assert(write_filename);

  READ *read = (READ *)calloc(1, sizeof(READ));
  assert(read);

  while (!feof(stdin)) {
    _read_line_to_struct(read);
    fwrite(read, sizeof(*read), 1, write_filename);
  }

  fclose(write_filename);
}

void _read_regs(FILE *filename, int last_register){

  READ *read = (READ *)calloc(1, sizeof(READ));
  assert(read);

  //read struct elements
  int numRs = fread(&read->uspNumber, sizeof(int), 1, filename);
  int nameRs = fread(&read->name, sizeof(char), 50, filename);
  int classRs = fread(&read->class, sizeof(char), 50, filename);
  int gradeRs = fread(&read->grade, sizeof(float), 1, filename);

  //print if succeed
  if(numRs == 1){printf("nUSP: %d\n", read->uspNumber);}
  if(nameRs == 50){printf("Nome: %s\n", read->name);}
  if(classRs == 50){printf("Curso: %s\n", read->class);}

  if(last_register){
    if(gradeRs == 1){printf("Nota: %.2f\n\n", read->grade);}
  }
  else{
    if(gradeRs == 1){printf("Nota: %.2f\n", read->grade);}
  }

  free(read);
  return;
}

void _read_binary(){
  //open binary file
  FILE *filename = fopen("binary.bin" , "rb");
  assert(filename);

  //go to last position
  fseek(filename, 0, SEEK_END);
  long int regs = ftell(filename);
  regs /= DATA; //total bytes / bytes per register

  fseek(filename, ((regs - 10) * DATA), SEEK_SET);

  for(int i = (regs - 10) ; i < (regs - 1); i++){
    _read_regs(filename, 1);
  }
  _read_regs(filename, 0);

  fclose(filename);
}
