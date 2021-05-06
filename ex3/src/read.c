#include <assert.h>
#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#include "read.h"

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
        strcpy(read->first_name, token);
        break;

      case 3:
      strcpy(read->last_name, token);

      case 4:
        strcpy(read->class, token);
        break;

      case 5:
        read->grade = atof(token);
        break;
    }

    token = strtok(NULL, ",\n");
  }

  free(lineptr);
  free(token);
}

void _read_line_send_binary(INDEX **index, int space_alloc){

  FILE *write_filename = fopen("binary.bin", "ab+"); //open in append mode
  assert(write_filename);

  READ *read = (READ *)calloc(1, sizeof(READ));
  assert(read);

  _read_line_to_struct(read);

  fseek(write_filename, 0, SEEK_END);
  int actual_pos = ftell(write_filename);
  insert_array(index, space_alloc, &read->uspNumber, &actual_pos);

  fwrite(read, sizeof(*read), 1, write_filename);

  fclose(write_filename);
}

void _read_regs(FILE *filename){

  READ *read = (READ *)calloc(1, sizeof(READ));
  assert(read);

  //read struct elements
  int numRs = fread(&read->uspNumber, sizeof(int), 1, filename);
  int first_nameRs = fread(&read->first_name, sizeof(char), 25, filename);
  int last_nameRs = fread(&read->last_name, sizeof(char), 25, filename);
  int classRs = fread(&read->class, sizeof(char), 50, filename);
  int gradeRs = fread(&read->grade, sizeof(float), 1, filename);

  //print if succeed
  printf("%s\n", "-------------------------------");
  if(numRs == 1){printf("USP number: %d\n", read->uspNumber);}
  if(first_nameRs == 25){printf("Name: %s\n", read->first_name);}
  if(last_nameRs == 25){printf("Surname: %s\n", read->last_name);}
  if(classRs == 50){printf("Course: %s\n", read->class);}
  if(gradeRs == 1){printf("Teste grade: %.2f\n", read->grade);}
  printf("%s\n", "-------------------------------");

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

  fseek(filename, 0, SEEK_SET);

  _read_regs(filename);

  fclose(filename);
}
