#ifndef READ_H_
#define READ_H_

typedef struct read{
  int uspNumber;
  char name[50];
  char class[50];
  float grade;
}READ;

/*@Description: Read from file and print          */
/*@Param: pointer to file, check the end of list  */
/*@Return: none                                   */
void _read_regs(FILE *, int);

#endif
