const unsigned char win_screen[32*30]={
0x00,0x00,0x00,0x00,
0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
0x00,0x00,0x00,0x00,0x00,0xbc,0x00,0x00,0x00,0x00,0x00,0xbc,0x00,0xad,0xad,0xad,
0xad,0xad,0xad,0xad,0x00,0x00,0xc5,0x00,0x00,0x00,0xc5,0x00,0x00,0x00,0x00,0x00,
0x00,0x00,0x00,0x00,0x00,0xbc,0x00,0x00,0x00,0x00,0x00,0xbc,0x00,0xad,0x00,0x00,
0x00,0x00,0x00,0xad,0x00,0x00,0xc5,0x00,0x00,0x00,0xc5,0x00,0x00,0x00,0x00,0x00,
0x00,0x00,0x00,0x00,0x00,0xbc,0x00,0x00,0x00,0x00,0x00,0xbc,0x00,0xad,0x00,0x00,
0x00,0x00,0x00,0xad,0x00,0x00,0xc5,0x00,0x00,0x00,0xc5,0x00,0x00,0x00,0x00,0x00,
0x00,0x00,0x00,0x00,0x00,0xbc,0xbc,0xbc,0x00,0xbc,0xbc,0xbc,0x00,0xad,0x00,0x00,
0x00,0x00,0x00,0xad,0x00,0x00,0xc5,0x00,0x00,0x00,0xc5,0x00,0x00,0x00,0x00,0x00,
0x00,0x00,0x00,0x00,0x00,0x00,0x00,0xbc,0xbc,0xbc,0x00,0x00,0x00,0xad,0x00,0x00,
0x00,0x00,0x00,0xad,0x00,0x00,0xc5,0x00,0x00,0x00,0xc5,0x00,0x00,0x00,0x00,0x00,
0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0xbc,0x00,0x00,0x00,0x00,0xad,0x00,0x00,
0x00,0x00,0x00,0xad,0x00,0x00,0xc5,0x00,0x00,0x00,0xc5,0x00,0x00,0x00,0x00,0x00,
0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0xbc,0x00,0x00,0x00,0x00,0xad,0x00,0x00,
0x00,0x00,0x00,0xad,0x00,0x00,0xc5,0x00,0x00,0x00,0xc5,0x00,0x00,0x00,0x00,0x00,
0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0xbc,0x00,0x00,0x00,0x00,0xad,0x00,0x00,
0x00,0x00,0x00,0xad,0x00,0x00,0xc5,0x00,0x00,0x00,0xc5,0x00,0x00,0x00,0x00,0x00,
0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0xbc,0x00,0x00,0x00,0x00,0xad,0xad,0xad,
0xad,0xad,0xad,0xad,0x00,0x00,0xc5,0x00,0x00,0x00,0xc5,0x00,0x00,0x00,0x00,0x00,
0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0xbc,0x00,0x00,0x00,0x00,0xad,0xad,0xad,
0xad,0xad,0xad,0xad,0x00,0x00,0xc5,0xc5,0xc5,0xc5,0xc5,0x00,0x00,0x00,0x00,0x00,
0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
0x00,0x00,0x00,0xbb,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0xbb,0x00,0x00,0xb4,0xb4,
0xb4,0xb4,0xb4,0xb4,0xb4,0x00,0x0c,0x0c,0x00,0x00,0x00,0x00,0x00,0x0c,0x00,0x00,
0x00,0x00,0x00,0xbb,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0xbb,0x00,0x00,0x00,0x00,
0x00,0xb4,0x00,0x00,0x00,0x00,0x0c,0x0c,0x0c,0x00,0x00,0x00,0x00,0x0c,0x00,0x00,
0x00,0x00,0x00,0xbb,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0xbb,0x00,0x00,0x00,0x00,
0x00,0xb4,0x00,0x00,0x00,0x00,0x0c,0x00,0x0c,0x00,0x00,0x00,0x00,0x0c,0x00,0x00,
0x00,0x00,0x00,0xbb,0x00,0x00,0x00,0xbb,0x00,0x00,0x00,0xbb,0x00,0x00,0x00,0x00,
0x00,0xb4,0x00,0x00,0x00,0x00,0x0c,0x00,0x0c,0x0c,0x00,0x00,0x00,0x0c,0x00,0x00,
0x00,0x00,0x00,0xbb,0x00,0x00,0x00,0xbb,0x00,0x00,0x00,0xbb,0x00,0x00,0x00,0x00,
0x00,0xb4,0x00,0x00,0x00,0x00,0x0c,0x00,0x00,0x0c,0x0c,0x00,0x00,0x0c,0x00,0x00,
0x00,0x00,0x00,0xbb,0x00,0x00,0x00,0xbb,0x00,0x00,0x00,0xbb,0x00,0x00,0x00,0x00,
0x00,0xb4,0x00,0x00,0x00,0x00,0x0c,0x00,0x00,0x00,0x0c,0x00,0x00,0x0c,0x00,0x00,
0x00,0x00,0x00,0xbb,0x00,0x00,0x00,0xbb,0x00,0x00,0x00,0xbb,0x00,0x00,0x00,0x00,
0x00,0xb4,0x00,0x00,0x00,0x00,0x0c,0x00,0x00,0x00,0x0c,0x0c,0x00,0x0c,0x00,0x00,
0x00,0x00,0x00,0xbb,0x00,0x00,0x00,0xbb,0x00,0x00,0x00,0xbb,0x00,0x00,0x00,0x00,
0x00,0xb4,0x00,0x00,0x00,0x00,0x0c,0x00,0x00,0x00,0x00,0x0c,0x0c,0x0c,0x00,0x00,
0x00,0x00,0x00,0xbb,0xbb,0xbb,0xbb,0xbb,0xbb,0xbb,0xbb,0xbb,0x00,0x00,0xb4,0xb4,
0xb4,0xb4,0xb4,0xb4,0xb4,0x00,0x0c,0x00,0x00,0x00,0x00,0x00,0x0c,0x0c,0x00,0x00,
0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
0x00,0x00,0x00,0x00
};
