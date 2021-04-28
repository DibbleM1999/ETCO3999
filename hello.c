
/*
A simple "hello world" example.
Set the screen background color and palette colors.
Then write a message to the nametable.
Finally, turn on the PPU to display video.
*/
#define NES_MIRRORING 1 
#include "neslib.h"
#include "vrambuf.h"
#include "apu.h"
//#link "apu.c"
//#link "vrambuf.c"
#define TILE 0xd8
#define TILE_D 0xc4
#define ATTR 0
#define ATTRN 0x40
// link the pattern table into CHR ROM
//#link "chr_generic.s"
const unsigned char nametable[32*24]={
	0x05,0x05,0x05,0x05,0x05,0x05,0x05,0x05,0x05,0x05,0x05,0x05,0x05,0x05,0x05,0x05,0x05,0x05,0x05,0x05,0x05,0x05,0x05,0x05,0x05,0x05,0x05,0x05,0x05,0x05,0x05,0x05,
	0x05,0x05,0x05,0x05,0x05,0x05,0x05,0x05,0x05,0x05,0x05,0x05,0x05,0x05,0x05,0x05,0x05,0x05,0x05,0x05,0x05,0x05,0x05,0x05,0x05,0x05,0x05,0x05,0x05,0x05,0x05,0x05,
	0x05,0x05,0xb2,0xb2,0xb2,0xb2,0xb2,0xb2,0x05,0x05,0x05,0x05,0x05,0x05,0x05,0x05,0x05,0x05,0x05,0x05,0x05,0x05,0x05,0x05,0xb2,0xb2,0xb2,0xb2,0xb2,0xb2,0x05,0x05,
	0x05,0x05,0xb2,0xb2,0xb2,0xb2,0xb2,0xb2,0x05,0x05,0x05,0x05,0x05,0x05,0x05,0x05,0x05,0x05,0x05,0x05,0x05,0x05,0x05,0x05,0xb2,0xb2,0xb2,0xb2,0xb2,0xb2,0x05,0x05,
	0xb2,0xb2,0xb2,0xb2,0xb2,0xb2,0xb2,0xb2,0xb2,0xb2,0x05,0x05,0x05,0x05,0x05,0x05,0x05,0x05,0x05,0x05,0x05,0x05,0xb2,0xb2,0xb2,0xb2,0xb2,0xb2,0xb2,0xb2,0xb2,0xb2,
	0xb5,0xb5,0xb5,0xb5,0xb5,0xb5,0xb5,0xb5,0xb5,0xb5,0x05,0x05,0x05,0x05,0x05,0x05,0x05,0x05,0x05,0x05,0x05,0x05,0xb5,0xb5,0xb5,0xb5,0xb5,0xb5,0xb5,0xb5,0xb5,0xb5,
	0x05,0x05,0xb5,0xc1,0xc1,0xc1,0xc1,0xb5,0x05,0x05,0x05,0x05,0x05,0x05,0x05,0x05,0x05,0x05,0x05,0x05,0x05,0x05,0x05,0x05,0xb5,0xc1,0xc1,0xc1,0xc1,0xb5,0x05,0x05,
	0x05,0x05,0xb5,0xc1,0xc1,0xc1,0xc1,0xb5,0x05,0x05,0x05,0x05,0x05,0x05,0x05,0x05,0x05,0x05,0x05,0x05,0x05,0x05,0x05,0x05,0xb5,0xc1,0xc1,0xc1,0xc1,0xb5,0x05,0x05,
	0x05,0x05,0xb5,0xc1,0xc1,0xc1,0xc1,0xb5,0x05,0x05,0x05,0x05,0x05,0x05,0x05,0x05,0x05,0x05,0x05,0x05,0x05,0x05,0x05,0x05,0xb5,0xc1,0xc1,0xc1,0xc1,0xb5,0x05,0x05,
	0x05,0x05,0xb5,0xc1,0xc1,0xc1,0xc1,0xb5,0x05,0x05,0x05,0x05,0x05,0x05,0x05,0x05,0x05,0x05,0x05,0x05,0x05,0x05,0x05,0x05,0xb5,0xc1,0xc1,0xc1,0xc1,0xb5,0x05,0x05,
	0x97,0x97,0x97,0x97,0x97,0x97,0x97,0x97,0x97,0x97,0x97,0x97,0x97,0x97,0x97,0x97,0x97,0x97,0x97,0x97,0x97,0x97,0x97,0x97,0x97,0x97,0x97,0x97,0x97,0x97,0x97,0x97,
	0x97,0x97,0x97,0x97,0x97,0x97,0x97,0x97,0x97,0x97,0x97,0x97,0x97,0x97,0x97,0x97,0x97,0x97,0x97,0x97,0x97,0x97,0x97,0x97,0x97,0x97,0x97,0x97,0x97,0x97,0x97,0x97,
	0x97,0x97,0x97,0x97,0x97,0x97,0x97,0x97,0x97,0x97,0x97,0x97,0x97,0x97,0x97,0x97,0x97,0x97,0x97,0x97,0x97,0x97,0x97,0x97,0x97,0x97,0x97,0x97,0x97,0x97,0x97,0x97,
	0x97,0x97,0x97,0x97,0x97,0x97,0x97,0x97,0x97,0x97,0x97,0x97,0x97,0x97,0x97,0x97,0x97,0x97,0x97,0x97,0x97,0x97,0x48,0x61,0x72,0x64,0x00,0x50,0x61,0x74,0x68,0x00,
	0x05,0x05,0x05,0x05,0x05,0x05,0x05,0x05,0x05,0x05,0x05,0x05,0x05,0x05,0x05,0x05,0x05,0x05,0x97,0x97,0x97,0x97,0x00,0x00,0x00,0x00,0x00,0x80,0x00,0x00,0x00,0x00,
	0x05,0x05,0x05,0x05,0x05,0x05,0x05,0x05,0x05,0x05,0x05,0x05,0x05,0x05,0x05,0x05,0x05,0x05,0x97,0x97,0x97,0x97,0x00,0x1f,0x1f,0x1f,0x1f,0x1f,0x1f,0x1f,0x00,0x00,
	0x05,0x05,0x05,0x05,0x05,0x05,0x05,0x05,0x05,0x05,0x05,0x05,0x05,0x05,0x05,0x05,0x05,0x05,0x97,0x97,0x97,0x97,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
	0x05,0x05,0x05,0x05,0x05,0x05,0x05,0x05,0x05,0x05,0x05,0x05,0x05,0x05,0x05,0x05,0x05,0x05,0x97,0x97,0x97,0x97,0x45,0x61,0x73,0x79,0x00,0x50,0x61,0x74,0x68,0x00,
	0x05,0x05,0x05,0x05,0x05,0x05,0x05,0x05,0x05,0x05,0x05,0x05,0x05,0x05,0x05,0x05,0x05,0x05,0x97,0x97,0x97,0x97,0x97,0x97,0x97,0x97,0x97,0x97,0x97,0x97,0x97,0x97,
	0x05,0x05,0x05,0x05,0x05,0x05,0x05,0x05,0x05,0x05,0x05,0x05,0x05,0x05,0x05,0x05,0x05,0x05,0x97,0x97,0x97,0x97,0x97,0x97,0x97,0x97,0x97,0x97,0x97,0x97,0x97,0x97,
	0x05,0x05,0x05,0x05,0x05,0x05,0x05,0x05,0x05,0x05,0x05,0x05,0x05,0x05,0x05,0x05,0x05,0x05,0x97,0x97,0x97,0x97,0x97,0x97,0x97,0x97,0x97,0x97,0x97,0x97,0x97,0x97,
	0x05,0x05,0x05,0x05,0x05,0x05,0x05,0x05,0x05,0x05,0x05,0x05,0x05,0x05,0x05,0x05,0x05,0x05,0x97,0x97,0x97,0x97,0x97,0x97,0x97,0x97,0x97,0x97,0x97,0x97,0x97,0x97,
	0x05,0x05,0x05,0x05,0x05,0x05,0x05,0x05,0x05,0x05,0x05,0x05,0x05,0x05,0x05,0x05,0x05,0x05,0x05,0x05,0x05,0x05,0x05,0x05,0x05,0x05,0x05,0x05,0x05,0x05,0x05,0x05,
	0x05,0x05,0x05,0x05,0x05,0x05,0x05,0x05,0x05,0x05,0x05,0x05,0x05,0x05,0x05,0x05,0x05,0x05,0x05,0x05,0x05,0x05,0x05,0x05,0x05,0x05,0x05,0x05,0x05,0x05,0x05,0x05
};


const unsigned char nametable2[32*24]={
	0x0f,0x0f,0x0f,0x0f,0x0f,0x0f,0x0f,0x0f,0x0f,0x0f,0x0f,0x0f,0x0f,0x0f,0x0f,0x0f,0x0f,0x0f,0x0f,0x0f,0x0f,0x0f,0x0f,0x0f,0x0f,0x0f,0x0f,0x0f,0x0f,0x0f,0x0f,0x0f,
	0x0f,0x0f,0x0f,0x0f,0x0f,0x0f,0x0f,0x0f,0x0f,0x0f,0x0f,0x0f,0x0f,0x0f,0x0f,0x0f,0x0f,0x0f,0x0f,0x0f,0x0f,0x0f,0x0f,0x0f,0x0f,0x0f,0x0f,0x0f,0x0f,0x0f,0x0f,0x0f,
	0x0f,0x0f,0x0f,0x0f,0x0f,0x0f,0x0f,0x0f,0x0f,0x0f,0x0f,0x0f,0x0f,0x0f,0x0f,0x0f,0x0f,0x0f,0x0f,0x0f,0x0f,0x0f,0x0f,0x0f,0x0f,0x0f,0x0f,0x0f,0x0f,0x0f,0x0f,0x0f,
	0x0f,0x0f,0x0f,0x0f,0x0f,0x0f,0x0f,0x0f,0x0f,0x0f,0x0f,0x0f,0x0f,0x0f,0x0f,0x0f,0x0f,0x0f,0x0f,0x0f,0x0f,0x0f,0x0f,0x0f,0x0f,0x0f,0x0f,0x0f,0x0f,0x0f,0x0f,0x0f,
	0x0f,0x0f,0x0f,0x0f,0x0f,0x0f,0x0f,0x0f,0x0f,0x0f,0x0f,0x0f,0x0f,0x0f,0x0f,0x0f,0x0f,0x0f,0x0f,0x0f,0x0f,0x0f,0x0f,0x0f,0x0f,0x0f,0x0f,0x0f,0x0f,0x0f,0x0f,0x0f,
	0x0f,0x0f,0x0f,0x0f,0x0f,0x0f,0x0f,0x0f,0x0f,0x0f,0x0f,0x0f,0x0f,0x0f,0x0f,0x0f,0x0f,0x0f,0x0f,0x0f,0x0f,0x0f,0x0f,0x0f,0x0f,0x0f,0x0f,0x0f,0x0f,0x0f,0x0f,0x0f,
	0x0f,0x0f,0x0f,0x0f,0x0f,0x0f,0x0f,0x0f,0x0f,0x0f,0x0f,0x0f,0x0f,0x0f,0x0f,0x0f,0x0f,0x0f,0x0f,0x0f,0x0f,0x0f,0x0f,0x0f,0x0f,0x0f,0x0f,0x0f,0x0f,0x0f,0x0f,0x0f,
	0x0f,0x0f,0x0f,0x0f,0x0f,0x0f,0x0f,0x0f,0x0f,0x0f,0x0f,0x0f,0x0f,0x0f,0x0f,0x0f,0x0f,0x0f,0x0f,0x0f,0x0f,0x0f,0x0f,0x0f,0x0f,0x0f,0x0f,0x0f,0x0f,0x0f,0x0f,0x0f,
	0x0f,0x0f,0x0f,0x0f,0x0f,0x0f,0x0f,0x0f,0x0f,0x0f,0x0f,0x0f,0x0f,0x0f,0x0f,0x0f,0x0f,0x0f,0x0f,0x0f,0x0f,0x0f,0x0f,0x0f,0x0f,0x0f,0x0f,0x0f,0x0f,0x0f,0x0f,0x0f,
	0x0f,0x0f,0x0f,0x0f,0x0f,0x0f,0x0f,0x0f,0x0f,0x0f,0x0f,0x0f,0x0f,0x0f,0x0f,0x0f,0x0f,0x0f,0x0f,0x0f,0x0f,0x0f,0x0f,0x0f,0x0f,0x0f,0x0f,0x0f,0x0f,0x0f,0x0f,0x0f,
	0x97,0x97,0x97,0x97,0x97,0x97,0x97,0x97,0x97,0x97,0x97,0x97,0x97,0x97,0x97,0x97,0x97,0x97,0x97,0x97,0x97,0x97,0x97,0x97,0x97,0x97,0x97,0x97,0x97,0x97,0x97,0x97,
	0x97,0x97,0x97,0x97,0x97,0x97,0x97,0x97,0x97,0x97,0x97,0x97,0x97,0x97,0x97,0x97,0x97,0x97,0x97,0x97,0x97,0x97,0x97,0x97,0x97,0x97,0x97,0x97,0x97,0x97,0x97,0x97,
	0x97,0x97,0x97,0x97,0x97,0x97,0x97,0x97,0x97,0x97,0x97,0x97,0x97,0x97,0x97,0x97,0x97,0x97,0x97,0x97,0x97,0x97,0x97,0x97,0x97,0x97,0x97,0x97,0x97,0x97,0x97,0x97,
	0xb9,0xb9,0xb9,0xb9,0xb9,0xb9,0xb9,0xb9,0xb9,0xb9,0xb9,0xb9,0xb9,0xb9,0xb9,0xb9,0xb9,0xb9,0xb9,0xb9,0xb9,0xb9,0xb9,0xb9,0xb9,0xb9,0xb9,0xb9,0xb9,0xb9,0xb9,0xb9,
	0xb9,0xb9,0xb9,0xb9,0xb9,0xb9,0xb9,0xb9,0xb9,0xb9,0xb9,0xb9,0xb9,0xb9,0xb9,0xb9,0xb9,0xb9,0xb9,0xb9,0xb9,0xb9,0xb9,0xb9,0xb9,0xb9,0xb9,0xb9,0xb9,0xb9,0xb9,0xb9,
	0xb9,0xb9,0xb9,0xb9,0xb9,0xb9,0xb9,0xb9,0xb9,0xb9,0xb9,0xb9,0xb9,0xb9,0xb9,0xb9,0xb9,0xb9,0xb9,0xb9,0xb9,0xb9,0xb9,0xb9,0xb9,0xb9,0xb9,0xb9,0xb9,0xb9,0xb9,0xb9,
	0xb9,0xb9,0xb9,0xb9,0xb9,0xb9,0xb9,0xb9,0xb9,0xb9,0xb9,0xb9,0xb9,0xb9,0xb9,0xb9,0xb9,0xb9,0xb9,0xb9,0xb9,0xb9,0xb9,0xb9,0xb9,0xb9,0xb9,0xb9,0xb9,0xb9,0xb9,0xb9,
	0xb9,0xb9,0xb9,0xb9,0xb9,0xb9,0xb9,0xb9,0xb9,0xb9,0xb9,0xb9,0xb9,0xb9,0xb9,0xb9,0xb9,0xb9,0xb9,0xb9,0xb9,0xb9,0xb9,0xb9,0xb9,0xb9,0xb9,0xb9,0xb9,0xb9,0xb9,0xb9,
	0x97,0x97,0x97,0x97,0x97,0x97,0x97,0x97,0x97,0x97,0x97,0x97,0x97,0x97,0x97,0x97,0x97,0x97,0x97,0x97,0x97,0x97,0x97,0x97,0x97,0x97,0x97,0x97,0x97,0x97,0x97,0x97,
	0x97,0x97,0x97,0x97,0x97,0x97,0x97,0x97,0x97,0x97,0x97,0x97,0x97,0x97,0x97,0x97,0x97,0x97,0x97,0x97,0x97,0x97,0x97,0x97,0x97,0x97,0x97,0x97,0x97,0x97,0x97,0x97,
	0x97,0x97,0x97,0x97,0x97,0x97,0x97,0x97,0x97,0x97,0x97,0x97,0x97,0x97,0x97,0x97,0x97,0x97,0x97,0x97,0x97,0x97,0x97,0x97,0x97,0x97,0x97,0x97,0x97,0x97,0x97,0x97,
	0x97,0x97,0x97,0x97,0x97,0x97,0x97,0x97,0x97,0x97,0x97,0x97,0x97,0x97,0x97,0x97,0x97,0x97,0x97,0x97,0x97,0x97,0x97,0x97,0x97,0x97,0x97,0x97,0x97,0x97,0x97,0x97,
	0x05,0x05,0x05,0x05,0x05,0x05,0x05,0x05,0x05,0x05,0x05,0x05,0x05,0x05,0x05,0x05,0x05,0x05,0x05,0x05,0x05,0x05,0x05,0x05,0x05,0x05,0x05,0x05,0x05,0x05,0x05,0x05,
	0x05,0x05,0x05,0x05,0x05,0x05,0x05,0x05,0x05,0x05,0x05,0x05,0x05,0x05,0x05,0x05,0x05,0x05,0x05,0x05,0x05,0x05,0x05,0x05,0x05,0x05,0x05,0x05,0x05,0x05,0x05,0x05
};




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
int health = 5;
int x = 1;
int y = 160;
int play_y = 160;
int dir = 1;
int cam_x = 0;
int cam_y = 0;
int enem_x = 400;
int enem_y = 110;
int enem_dir = 1;

pal_all(PALETTE);

  // set palette colors
  pal_col(0,0x15);	// set screen to dark blue
  pal_col(1,0x14);	// fuchsia
  pal_col(2,0x20);	// grey
  pal_col(3,0x2c);	// white
  

  // write text to name table
  vram_adr(NTADR_A(1,1));		// set address
  vram_write("Health:",7);
  for(i = 1; i <= health; i++)
  {
  vram_adr(NTADR_A(i,2));		// set address
  vram_put(0x15);
  }
  vram_adr(NTADR_A(0,4));		// set address
  vram_write(nametable, 768);
  vram_adr(NTADR_B(0,4));		// set address
  vram_write(nametable2, 768);
  // enable PPU rendering (turn on screen)

  vrambuf_clear();
  set_vram_update(updbuf); 
  ppu_on_all();

  // infinite loop
  while (1) 
  {
    char cur_oam = 0;
    char pad_result = pad_poll(0);
    
    cur_oam = oam_spr(1, 22,0xA0,0x00, cur_oam);
    //cur_oam = oam_meta_spr(450, 115, cur_oam, Door);
    //oam_spr(x,y,0x19,0x0,cur_oam);
    if(pad_result & 0x40)
    {
      	dir = -1;
   	x+= dir;
      	//cam_x++;
    }
    else if(pad_result & 0x80)
    {
      	cur_oam | 0x40;
      	dir = 1;
   	x+= dir;
      	//cam_x--;
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
    
    if(dir == 1)
    {
      if( cam_x>256)
        cam_x = 256;
      	pal_bright(4);
      if( x > 200)
        cam_x++;
      if(x >200)
      	pal_bright(0);
      if(x + cam_x >300)
      	pal_bright(4);
      if( x > 232)
        x = 232;
      	
    	cur_oam = oam_meta_spr(x, play_y, cur_oam, metaspriteR);
      	cur_oam = oam_meta_spr(x, play_y, cur_oam, Door);
    }
    if(dir == -1)
    {
      if( cam_x<0)
        cam_x = 0;
      	pal_bright(4);
      if( x<100)
        cam_x--;
      if(x - cam_x >140)
      	pal_bright(0);
      if(cam_x >35)
        pal_bright(4);
      if( x < 8)
        x = 8;
    	cur_oam = oam_meta_spr(x, play_y, cur_oam, metaspriteL);
      	cur_oam = oam_meta_spr(x, play_y, cur_oam, Door);
    }
    
    if(enem_dir == 1){
      	enem_x+= enem_dir;
      	if(enem_x >425){
          enem_dir = -1;
        }
      if(enem_x- cam_x >= 0&& enem_x- cam_x<256){
    	cur_oam = oam_meta_spr(enem_x- cam_x, enem_y, cur_oam, metaspriteR);
        cur_oam = oam_meta_spr(480-cam_x, 115, cur_oam, Door);
      }
    }
    if(enem_dir == -1){
      	enem_x+= enem_dir;
      	if(enem_x <375){
          enem_dir = 1;
        }
      	if(enem_x- cam_x >= 0&& enem_x- cam_x<256){
    	cur_oam = oam_meta_spr(enem_x - cam_x, enem_y, cur_oam, metaspriteL);
          cur_oam = oam_meta_spr(480-cam_x, 115, cur_oam, Door);
        }
    }
    if(play_y == 115 && x==480-cam_x)
    {
      vram_adr(NTADR_A(50,50));		// set address
      vram_write("YOU WIN",7);
    }
    
    //cur_oam = oam_meta_spr(232, y, cur_oam, Door);
    //cam_x++;
    oam_hide_rest(cur_oam);
    split(cam_x,cam_y);
    //scroll(cam_x,cam_y);
    //ppu_wait_frame();
    //vrambuf_flush();
  }

}
