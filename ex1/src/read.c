#include "read.h"
#include <assert.h>

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
