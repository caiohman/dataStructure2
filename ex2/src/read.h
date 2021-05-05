#ifndef READ_H_
#define READ_H_

#include <stdlib.h>
#include <stdio.h>

typedef struct read{
  int uspNumber;
  char name[50];
  char class[50];
  float grade;
}READ;


/*@Description:  read all registers from stdin and send to binary file        */
/*@Param:        none                                                         */
/*@Return:       none                                                         */

void _read_all_send_binary();

/*@Description:  read last 10 registers from binary.bin                       */
/*@Param:    none                                                             */
/*@Return:   none                                                             */
void _read_binary();




#endif
