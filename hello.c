
/*
A simple "hello world" example.
Set the screen background color and palette colors.
Then write a message to the nametable.
Finally, turn on the PPU to display video.
*/

#include "neslib.h"
#include "vrambuf.h"
//#link "vrambuf.c"
#define TILE 0xd8
#define TILE_D 0xc4
#define ATTR 0
#define ATTRN 0x40
// link the pattern table into CHR ROM
//#link "chr_generic.s"
const unsigned char metaspriteR[]={
        0,      0,      TILE+0,   ATTR, 
        0,      8,      TILE+1,   ATTR, 
        8,      0,      TILE+2,   ATTR, 
        8,      8,      TILE+3,   ATTR, 
        128};
const unsigned char metaspriteL[]={
        0,      0,      TILE+2,   ATTRN, 
        0,      8,      TILE+3,   ATTRN, 
        8,      0,      TILE+0,   ATTRN, 
        8,      8,      TILE+1,   ATTRN, 
        128};
const unsigned char Door[]={
        0,      0,      TILE_D+0,   ATTR, 
        0,      8,      TILE_D+1,   ATTR, 
        8,      0,      TILE_D+2,   ATTR, 
        8,      8,      TILE_D+3,   ATTR, 
        128};
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
// main function, run after console reset
void main(void) {
int i;
int x = 1;
int y = 160;
int play_y = 160;
int dir = 1;

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
  vrambuf_clear();
  set_vram_update(updbuf); 
  ppu_on_all();

  // infinite loop
  while (1) 
  {
    char cur_oam = 0;
    char pad_result = pad_poll(0);
    
    //oam_spr(x,y,0x19,0x0,cur_oam);
    if(pad_result & 0x40)
    {
      	dir = -1;
   	x+= dir;
    }
    else if(pad_result & 0x80)
    {
      	cur_oam | 0x40;
      	dir = 1;
   	x+= dir;
    }
    else if(pad_result & 0x20)
    {
      	dir = 1;
   	play_y+= dir;
    }
    else if(pad_result & 0x10)
    {
      	dir = -1;
   	play_y+= dir;
    }
    /*
    if(x>235)
    {
      dir = -1;
    }
    if(x<5)
    {
      cur_oam | 0x40;
      dir = 1;
    }
    */
    if(x<240 && x>229)
    {
      vrambuf_put(NTADR_A(1, 4), "On The Door!", 13);
    }
    else
    {
      vrambuf_put(NTADR_A(1, 4), "            ", 13);
    }
    if(dir == 1)
    {
    	cur_oam = oam_meta_spr(x, play_y, cur_oam, metaspriteR);
      	cur_oam = oam_meta_spr(x, play_y, cur_oam, Door);
    }
    if(dir == -1)
    {
    	cur_oam = oam_meta_spr(x, play_y, cur_oam, metaspriteL);
      	cur_oam = oam_meta_spr(x, play_y, cur_oam, Door);
    }
    cur_oam = oam_meta_spr(232, y, cur_oam, Door);
    vrambuf_flush();
  }
}
