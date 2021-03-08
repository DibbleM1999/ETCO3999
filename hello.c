
/*
A simple "hello world" example.
Set the screen background color and palette colors.
Then write a message to the nametable.
Finally, turn on the PPU to display video.
*/

#include "neslib.h"

// link the pattern table into CHR ROM
//#link "chr_generic.s"

// main function, run after console reset
void main(void) {
int i;
const char PALETTE[32] =
{
0x03, // screen color
0x24, 0x16, 0x20, 0x0, // background palette 0
0x1c, 0x20, 0x2c, 0x0, // background palette 1
0x00, 0x1a, 0x20, 0x0, // background palette 2
0x23, 0x31, 0x41, 0x0, // sprite palette 0
0x00, 0x37, 0x25, 0x0, // sprite palette 1
0x36, 0x21, 0x19, 0x0, // sprite palette 2
0x1d, 0x37, 0x2b, // sprite palette 3
};
pal_all(PALETTE);

  // set palette colors
  pal_col(0,0x15);	// set screen to dark blue
  pal_col(1,0x14);	// fuchsia
  pal_col(2,0x20);	// grey
  pal_col(3,0x2c);	// white
  

  // write text to name table
  vram_adr(NTADR_A(1,1));		// set address
  vram_write("This is", 7);
  vram_adr(NTADR_A(1,2));       // write bytes to video RAM
  vram_write("Mike Dibble's", 13);
  vram_adr(NTADR_A(1,3));
  vram_write("first NES 'Game'!", 17);
  // enable PPU rendering (turn on screen)
  for(i = 0; i < 32; i++)
  {
    vram_adr(NTADR_A(i,150));
    vram_put(0xC0);
  }
  for(i = 0; i < 32; i++)
  {
    vram_adr(NTADR_A(i,151));
    vram_put(0xC0);
  }
  ppu_on_all();

  // infinite loop
  while (1) 
  {
    char cur_oam = 0;
    
    oam_spr(30,120,0x19,0x0,cur_oam);
  }
}
