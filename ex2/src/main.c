#include "read.h"

int main(int argc, char const *argv[]) {

  _read_all_send_binary(); //read entire stdin
  _read_binary(); //read last 10 regs

  return 0;
}
