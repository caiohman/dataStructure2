#ifndef READ_H_
#define READ_H_

#include <stdlib.h>
#include <stdio.h>
#include "indice.h"


typedef struct read{
  int uspNumber;
  char first_name[25];
  char last_name[25];
  char class[50];
  float grade;
}READ;

/*@Description:  read all registers from stdin and send to binary file        */
/*@Param:        none                                                         */
/*@Return:       none                                                         */
int _read_line_send_binary(INDEX **, int );

/*@Description:  search through registers from binary.bin                     */
/*@Param:    none                                                             */
/*@Return:   none                                                             */
void _search_binary(int , INDEX **, int );




#endif
