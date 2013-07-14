#include <stdio.h>
#include <stdint.h>

uint16_t mem[65535];
 
uint16_t i8toi16(uint8_t *a, uint16_t i) {
  return a[i] | a[i+1] << 8;
}

#define HALT  = 0000000
#define WAIT  = 0000001
#define RTI   = 0000002
#define BPT   = 0000003
#define IOT   = 0000004
#define RESET = 0000005
#define RTT   = 0000006
#define JMP   = 00001
#define JMP   = 00002
#define JMP   = 000023
#define JMP   = 0000240
/* unused
#define JMP   = 0000241
#define JMP   = 0000277
*/
#define JMP   = 00003
#define JMP   = 00004
#define JMP   = 00010
#define JMP   = 00014
#define JMP   = 00020
#define JMP   = 00024
#define JMP   = 00030
#define JMP   = 00034
#define JMP   = 0004
#define JMP   = 00050
#define JMP   = 00051
#define JMP   = 00052
#define JMP   = 00053
#define JMP   = 00054
#define JMP   = 00055
#define JMP   = 00056
#define JMP   = 00057
#define JMP   = 00060
#define JMP   = 00061
#define JMP   = 00062
#define JMP   = 00063
#define JMP   = 00064
#define JMP   = 00065
#define JMP   = 00066
#define JMP   = 00067
/* unused
#define JMP   = 0007000
#define JMP   = 0007777
*/
#define JMP   = 001
#define JMP   = 002
#define JMP   = 003
#define JMP   = 004
#define JMP   = 005
#define JMP   = 006
#define JMP   = 0070
#define JMP   = 0071
#define JMP   = 0072
#define JMP   = 0073
#define JMP   = 0074
#define JMP   = 007500
#define JMP   = 007501
#define JMP   = 007502
#define JMP   = 007503
/* unused
#define JMP   = 0075040
#define JMP   = 0076777
*/
#define JMP   = 0077
#define JMP   = 01000
#define JMP   = 01004
#define JMP   = 01010
#define JMP   = 0
#define JMP   = 00004
#define JMP   = 00010
#define JMP   = 00014
#define JMP   = 00020
#define JMP   = 00024
#define JMP   = 00003
#define JMP   = 00004
#define JMP   = 00010
#define JMP   = 00014
#define JMP   = 00020
#define JMP   = 00024
#define JMP   = 00003
#define JMP   = 00004
#define JMP   = 00010
#define JMP   = 00014
#define JMP   = 00020
#define JMP   = 00024
#define JMP   = 00003
#define JMP   = 00004
#define JMP   = 00010
#define JMP   = 00014
#define JMP   = 00020
#define JMP   = 00024
#define JMP   = 00003
#define JMP   = 00004
#define JMP   = 00010
#define JMP   = 00014
#define JMP   = 00020
#define JMP   = 00024
#define JMP   = 00003
#define JMP   = 00004
#define JMP   = 00010
#define JMP   = 00014
#define JMP   = 00020
#define JMP   = 00024
#define JMP   = 00003
#define JMP   = 00004
#define JMP   = 00010
#define JMP   = 00014
#define JMP   = 00020
#define JMP   = 00024
#define JMP   = 00003
#define JMP   = 00004
#define JMP   = 00010
#define JMP   = 00014
#define JMP   = 00020
#define JMP   = 00024








uint16_t opcode(uint16_t d) {
  return 0;
}

uint16_t operate(uint16_t pc) {
  printf("%04x\n",mem[pc]);

  // 1111111111111111
  // |opcode   |  | 
  //           |mode
  //              |reg
  o = opcode(mem[pc]);

  return 0;
}

int main(int argc, char *argv[]) {
  FILE *fp;
  uint8_t c;
  uint8_t h[16];
  uint16_t a;
  fp = fopen("write","rb");
  fread(&h, 1, 16, fp);
  fclose(fp);

  uint16_t magic;
  uint16_t tsize;
  uint16_t dsize;
  uint16_t bsize;
  uint16_t ssize;
  uint16_t entry;
  uint16_t pad;
  uint16_t relflg;
  uint16_t image_size;

  magic = i8toi16(h,0);
  tsize = i8toi16(h,2);
  dsize = i8toi16(h,4);
  bsize = i8toi16(h,6);
  ssize = i8toi16(h,8);
  entry = i8toi16(h,10);
  pad = i8toi16(h,12);
  relflg = i8toi16(h,14);

  image_size = tsize + dsize;

  printf("magic: %04x\n", magic);
  printf("tsize: %04x\n", tsize);
  printf("dsize: %04x\n", dsize);
  printf("bsize: %04x\n", bsize);
  printf("ssize: %04x\n", ssize);
  printf("entry: %04x\n", entry);
  printf("pad: %04x\n", pad);
  printf("relflg: %04x\n", relflg);
  printf("image_size: %d\n", image_size);

  fp = fopen("write","rb");
  fseek(fp,16,SEEK_SET);
  fread(&mem, sizeof(uint16_t), image_size/2, fp);
  fclose(fp);
  
  for (int pc=0;pc<image_size/2;pc++) {
    pc += operate(pc);
  }
  
  return 0;
}

