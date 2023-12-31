// Font generated by stb_font_inl_generator.c (4/1 bpp)
//
// Following instructions show how to use the only included font, whatever it is, in
// a generic way so you can replace it with any other font by changing the include.
// To use multiple fonts, replace STB_SOMEFONT_* below with STB_FONT_courier_34_usascii_*,
// and separately install each font. Note that the CREATE function call has a
// totally different name; it's just 'stb_font_courier_34_usascii'.
//
/* // Example usage:

static stb_fontchar fontdata[STB_SOMEFONT_NUM_CHARS];

static void init(void)
{
    // optionally replace both STB_SOMEFONT_BITMAP_HEIGHT with STB_SOMEFONT_BITMAP_HEIGHT_POW2
    static unsigned char fontpixels[STB_SOMEFONT_BITMAP_HEIGHT][STB_SOMEFONT_BITMAP_WIDTH];
    STB_SOMEFONT_CREATE(fontdata, fontpixels, STB_SOMEFONT_BITMAP_HEIGHT);
    ... create texture ...
    // for best results rendering 1:1 pixels texels, use nearest-neighbor sampling
    // if allowed to scale up, use bilerp
}

// This function positions characters on integer coordinates, and assumes 1:1 texels to pixels
// Appropriate if nearest-neighbor sampling is used
static void draw_string_integer(int x, int y, char *str) // draw with top-left point x,y
{
    ... use texture ...
    ... turn on alpha blending and gamma-correct alpha blending ...
    glBegin(GL_QUADS);
    while (*str) {
        int char_codepoint = *str++;
        stb_fontchar *cd = &fontdata[char_codepoint - STB_SOMEFONT_FIRST_CHAR];
        glTexCoord2f(cd->s0, cd->t0); glVertex2i(x + cd->x0, y + cd->y0);
        glTexCoord2f(cd->s1, cd->t0); glVertex2i(x + cd->x1, y + cd->y0);
        glTexCoord2f(cd->s1, cd->t1); glVertex2i(x + cd->x1, y + cd->y1);
        glTexCoord2f(cd->s0, cd->t1); glVertex2i(x + cd->x0, y + cd->y1);
        // if bilerping, in D3D9 you'll need a half-pixel offset here for 1:1 to behave correct
        x += cd->advance_int;
    }
    glEnd();
}

// This function positions characters on float coordinates, and doesn't require 1:1 texels to pixels
// Appropriate if bilinear filtering is used
static void draw_string_float(float x, float y, char *str) // draw with top-left point x,y
{
    ... use texture ...
    ... turn on alpha blending and gamma-correct alpha blending ...
    glBegin(GL_QUADS);
    while (*str) {
        int char_codepoint = *str++;
        stb_fontchar *cd = &fontdata[char_codepoint - STB_SOMEFONT_FIRST_CHAR];
        glTexCoord2f(cd->s0f, cd->t0f); glVertex2f(x + cd->x0f, y + cd->y0f);
        glTexCoord2f(cd->s1f, cd->t0f); glVertex2f(x + cd->x1f, y + cd->y0f);
        glTexCoord2f(cd->s1f, cd->t1f); glVertex2f(x + cd->x1f, y + cd->y1f);
        glTexCoord2f(cd->s0f, cd->t1f); glVertex2f(x + cd->x0f, y + cd->y1f);
        // if bilerping, in D3D9 you'll need a half-pixel offset here for 1:1 to behave correct
        x += cd->advance;
    }
    glEnd();
}
*/

#ifndef STB_FONTCHAR__TYPEDEF
#define STB_FONTCHAR__TYPEDEF
typedef struct
{
    // coordinates if using integer positioning
    float s0,t0,s1,t1;
    signed short x0,y0,x1,y1;
    int   advance_int;
    // coordinates if using floating positioning
    float s0f,t0f,s1f,t1f;
    float x0f,y0f,x1f,y1f;
    float advance;
} stb_fontchar;
#endif

#define STB_FONT_courier_34_usascii_BITMAP_WIDTH         256
#define STB_FONT_courier_34_usascii_BITMAP_HEIGHT        114
#define STB_FONT_courier_34_usascii_BITMAP_HEIGHT_POW2   128

#define STB_FONT_courier_34_usascii_FIRST_CHAR            32
#define STB_FONT_courier_34_usascii_NUM_CHARS             95

#define STB_FONT_courier_34_usascii_LINE_SPACING          16

static unsigned int stb__courier_34_usascii_pixels[]={
    0x00001000,0x00098440,0x2aa6110c,0x0015c02a,0xaaa80446,0x1bb9801a,
    0x02e0b800,0x36e20000,0x000000bd,0x2a600000,0x1aaaaaaa,0x02ea04c8,
    0x3376a200,0x36e62001,0x745f803d,0x9b000002,0x3ee013f6,0x7776d326,
    0xb0026407,0x3be03aeb,0x3fea05ee,0x2002ffee,0x93007e1f,0x74c03bdd,
    0x441febbe,0xfd931ccc,0x36a007bf,0x9912deff,0xeeefc839,0x7c43eeee,
    0x6d5f540f,0x7bfb1004,0xf5009fd9,0x801b97bf,0x00035c5f,0x1f307cc0,
    0x13217c40,0xaee881e6,0xf88fd400,0xfc801f83,0xf004fa82,0xbf500fc1,
    0xf105fd55,0x5c41f709,0x9acfaafc,0x36205eb9,0xbfba99bf,0x2640ccf9,
    0xd03fe200,0xde880390,0x3203f980,0x8bf0003f,0x400001f8,0x2a04c85c,
    0x87984c86,0xcffdefd9,0x0fc8dd07,0x07ee00fc,0x7c404e98,0x3e601f10,
    0x35c0fa82,0x3fba09d0,0x360bb101,0x0fdd100d,0x3e200264,0x1260ea0f,
    0x01f700a0,0x4c0003d9,0x00005c80,0x816e07e2,0x7984c85c,0x3ea067c4,
    0x7cc3f987,0x3f100fc3,0x4401f300,0x04d81e27,0x203f88be,0x005fd07a,
    0x400fa87d,0x013207f9,0x10571fe0,0x3f10000b,0x00001fa8,0x00003f10,
    0x902dc172,0x8f30990b,0x321ea06b,0x0fc6e80f,0x2ec00bb0,0x983ccf30,
    0xf997200f,0x2f417c01,0x01ec6a80,0x013207c8,0x90b11fe0,0x1f100003,
    0x000003f8,0x440002e4,0x640b702f,0x47984c85,0x3e20c02e,0x0fc3f504,
    0x3cc003f0,0xb83ccd50,0x0f535405,0x007d07d0,0x001f83e2,0x002640f5,
    0x44e643f4,0xd900006c,0x32200698,0x4ccccccc,0x40000f98,0xc816e06b,
    0x47984c85,0x17dc004d,0x407e5f88,0x01f80078,0x4c8354d5,0x35cdb750,
    0x017426c0,0x003e23f0,0xb5b903cc,0x3a019dfd,0x105b9306,0x3f260017,
    0x710025c2,0xf9999999,0xf0001360,0xb902dc05,0x98f30990,0x03f6001f,
    0x5407e7f8,0x2e2e8006,0xffffffff,0x987b0fff,0x1326defe,0x013a1320,
    0x400ba3cc,0x37ff207b,0xe81fda9b,0x3bae2006,0x77f74c03,0xfd713d81,
    0x0788007d,0x2e0001f3,0x9b035c06,0x70f30990,0x740159df,0x1f87f407,
    0x7b000b70,0xc99dc998,0x88ba099d,0x264d51de,0x03742640,0x802ec6b8,
    0xb806207d,0x2202ec0f,0x1000bdeb,0x3d03ffb7,0xbfb37fd1,0x7d03c400,
    0x100fa000,0x905f507f,0x2a20f309,0x6f83efec,0x01f8fe40,0x05d000d5,
    0x5d04c932,0x64d507dc,0xfe84c804,0x220fcc04,0x03fdc02f,0x0bb13600,
    0x0017bd73,0xae85f700,0x003f884e,0x003d40f1,0xefb803d4,0x13209fd0,
    0x7d4401e6,0xf7017e25,0x03cc07e5,0x24c80fc0,0x26c5d04c,0xc804c9aa,
    0x80debe84,0x07f704fa,0x0001eff2,0x3a24c8b7,0x000040ad,0x0bfb0fcc,
    0x078803e4,0x0fa001f4,0xd98bba20,0x7984c80f,0xdf0fc400,0x03f1fc80,
    0x1f3000fc,0xd03d8f60,0xb9aa3545,0xae83e805,0xfedcdfd8,0x66f74c02,
    0x00798efd,0x00663cc0,0x0033b726,0x03ee4c80,0x78801f98,0xf3003540,
    0x740f5001,0x07984c83,0x01fa3d80,0xc807e1fb,0xf8976005,0xffffffff,
    0x7f0ba3ff,0x880f5354,0x2e62e82f,0x2a000acc,0x01e61bcb,0x2000d500,
    0x80016a1e,0x3e016a6a,0xf8078802,0x2009b002,0x3217205b,0x00ee7984,
    0x200fd8ba,0xf8807e7e,0x4c0f9802,0xbe99be99,0xd50f6099,0x3e61fddf,
    0x3a07ea00,0x30000002,0x05b8000f,0x01c83a80,0x03c4d500,0x1e2007e2,
    0x3e601ae0,0x640b7000,0x27984c85,0x91aa01fc,0x3f37c03f,0x2601fb80,
    0x3f0fc04f,0x5dcc1320,0x6c813a0c,0x000005d0,0xd0001e60,0x501b0007,
    0xd1320009,0x4007dc05,0x02f88078,0x0b7002ec,0x4c2642e4,0xa86fbf27,
    0x81fcc3fc,0x2007e3f9,0x3ea20bfb,0x07e1f804,0x7d4002dc,0x5d02f880,
    0x26000000,0x6b807f07,0x57005dc4,0x401c8390,0x8074c0fa,0x00f1004e,
    0x01f881b2,0x85c816e0,0x2ee7984c,0x2effffc9,0x83f20dd0,0xdfd5001f,
    0xf1005ffd,0x7cc03e21,0x21ee8000,0x00ba05e9,0x83cc0000,0x7e441efa,
    0x1027fe42,0x7e434c1d,0x817e441c,0x1dd50beb,0x4401e200,0x800b901f,
    0x3217205b,0x6ec07984,0x220fdc00,0x1000fc5f,0x440015dd,0x4d803e27,
    0xffff9000,0x9bf99109,0xb8000079,0x40ccfdcc,0xeffefec8,0x404ffc80,
    0x301dddd9,0x3dffdffb,0xefffeb80,0x801e2000,0x001f885c,0x90b702dc,
    0x4c80f309,0x7dc5f880,0xe9800fc1,0x2e20abbf,0x01e67981,0x806a07f3,
    0x99100aa8,0x00099999,0xcccccb80,0x02aa201c,0x04400550,0x00155100,
    0x88000a98,0x707e2007,0x405d000d,0x7984c878,0xfb802640,0x007e17a0,
    0x3bbbffea,0x980efeff,0x3ea01e67,0x01fdbabd,0x00000000,0x00000000,
    0x00000000,0x0d500000,0x017c4d80,0xdb00fd50,0xbaa9a645,0x88026407,
    0x7f03f53f,0x02a20555,0x49806a62,0x764c0122,0x00000abd,0x00000000,
    0x00000000,0x00000000,0x30013600,0xb001ae1f,0x4b710017,0x0dddd92a,
    0x4e6002a8,0xbdddd03a,0x00000000,0x00000000,0x00000000,0x00000000,
    0x00000000,0x0005f710,0x00002615,0x00000000,0x00000000,0x00000000,
    0x00000000,0x00000000,0x00000000,0x99100000,0x005ff999,0x00000000,
    0x00000000,0x00000000,0x00000000,0x00000000,0x00000000,0x00000000,
    0x33322000,0x00000acc,0x00000000,0x00000000,0x00000000,0x00000000,
    0x00000000,0x00000000,0x00000000,0x00000000,0x00000000,0x00000000,
    0x00000000,0x00000000,0x00000000,0x00000000,0x00000000,0x00000000,
    0x00015550,0x2aaaaaaa,0x4000aaaa,0x64402aa8,0x6dc00cdd,0x555100ad,
    0xa9880000,0x1aaa809a,0x2aaa6000,0x2000001a,0x9504cccb,0x54401999,
    0xdb98001b,0x554000bd,0x400bb881,0x75c004f9,0x9970bdff,0x00bfba27,
    0x77777740,0x002feeee,0xf703f75c,0x107ff99f,0x05ff7bfd,0x0000fdd7,
    0x7fff7fd4,0x07fdb11f,0x7f776c00,0x800b6004,0x9303cfea,0x3f6209fb,
    0x800cefdf,0x2ffdbefd,0xd07ff700,0x4f980dff,0x337dd100,0x59bd1dd5,
    0x3a0005d0,0x0002e802,0x20bea0f3,0x20ef42fa,0x00f300fa,0x102fe200,
    0x0000f603,0x0f6004c8,0xb001f100,0x1037a609,0x076c01db,0xf1007ee2,
    0xfff887b3,0x013e600f,0xfeb806f4,0x4000ba02,0x007c400b,0x0bd07980,
    0x201f53ec,0x000f306a,0x36001320,0x13200003,0xc8003d80,0x4407cc04,
    0xa82e404f,0xb01b600f,0x3ff20f6b,0xb8009805,0x017ec00e,0x4000005d,
    0x1e60005b,0x0f9807e2,0x982e807b,0x03f00007,0x00007b00,0x07b00264,
    0x6c01f100,0x3600b904,0x7cc02d84,0x0f61f301,0x20000044,0x02f9802e,
    0x800000ba,0x1e60003e,0x1f8803e6,0x984b805d,0x01f00007,0x00007b00,
    0x332e0264,0xccccccde,0x7cc13203,0x3001f980,0x5f00081f,0x003d8fa0,
    0x007e0000,0x225d017c,0x003dffec,0x65401f10,0x0f31cefe,0x3a6b80fa,
    0xbcc2cc02,0x01dffec8,0x99bf9993,0x1ec05999,0x00f3332a,0x332a0264,
    0xccccccde,0x3603e202,0xd800b704,0x81f88002,0x4001ec6a,0x402ccccb,
    0x05d000f8,0x4d6fcd74,0x4000dfb9,0x26ff206a,0x079afca9,0x49f101f9,
    0x4c36c05c,0xdb9adf9f,0xfccc881f,0x01cccccd,0x9bfd30f6,0x80132005,
    0x1320003d,0x00f601f3,0xb9000970,0x03d85f10,0x4eccca80,0xf8801f80,
    0x40bf7a02,0x1ec005d8,0x9d300eb8,0x556fe40f,0x807d44fd,0x7fcc0ffa,
    0x1f00d902,0xfa87b000,0x004c8003,0xf88000f6,0x02e81360,0x2e002d40,
    0x3d86c80f,0x804c8000,0x02fa804d,0x7f100ffa,0x7cc0fc00,0x203fcc00,
    0x886ffffd,0x74fd40ce,0xf1017cc1,0x8000f803,0x000bf23d,0x07b00264,
    0x1f14c800,0x26000fc0,0x207ea007,0x883d81f8,0x0099003a,0x7fc403f3,
    0x5401ba02,0x320d5006,0x6c0f9003,0x85fc99cf,0x2fcacfe8,0xe807983f,
    0x40007c02,0x0003db3d,0x07b00264,0x4c8f8800,0x2a001740,0x203f5005,
    0xfd07b04d,0x009900df,0x33a60bee,0x4013a02e,0x04c800f8,0x41ea003d,
    0x2217605d,0x1f11beeb,0x02e80798,0x66c0007c,0x640000fe,0x000f6004,
    0xb003f720,0x804b8007,0x01f302fb,0xffff10f6,0x2004c801,0x3feccefa,
    0x001f405d,0x103f003f,0x21e6001f,0x03e602f8,0x07986980,0x007c02e8,
    0x02f6fec0,0xd8013200,0x5f880003,0x6c005b80,0xd00fdc02,0xd555555b,
    0x06ffd85b,0x544004c8,0x80ba0acc,0x01f1003e,0x007e0798,0x4035c3d4,
    0x216e003e,0x402e8079,0x14d8000f,0x264000bd,0x00007b00,0x3f3003f1,
    0xc803e600,0x7776c01f,0x1eefeeee,0x04c80154,0xd0174000,0x201e600b,
    0x400b604c,0xd805b87b,0x305f1004,0xf805d00f,0x223d8000,0x0990004e,
    0x40001ec0,0x01b2005c,0x03f9026c,0x0007b000,0x80000990,0x007fa01f,
    0x80ba0136,0x87f8806a,0x0be601fa,0x07982f40,0x007c02e8,0x13a21ec0,
    0xc8013200,0x0fc40006,0xc809f100,0x0007b205,0x40001ec0,0x2a00004c,
    0x00777407,0x078801d7,0x3f6c04e8,0x01b204e8,0x3cc03b62,0x03e01740,
    0x3a20f600,0x00264004,0xeb8817f3,0x20017205,0x76cc1ee8,0xa801db00,
    0x0007b000,0x20000990,0x5d3303fa,0x1fd885d9,0xe8805b80,0x7cef4c0d,
    0x516fcc19,0x2e2043fb,0x3f5300df,0x437d3101,0x99af9998,0x7b310199,
    0x10273ea0,0x33bb3333,0x7ed40333,0x262effee,0x3cdfcccc,0xfeffc800,
    0x33f700be,0xd3333333,0x66ccc405,0x26662001,0x19999dc9,0x3b3332a0,
    0x5fff303f,0x37fbbfee,0x2005b000,0x4ffeffd8,0xe885fff3,0x6c0effff,
    0x203dffef,0xe87ffffa,0xffb3ffff,0xffffffff,0x83fff883,0x227ffffa,
    0xffffffff,0x4400ffff,0xcca809aa,0x003ccccc,0x2e002a60,0xffffffff,
    0x3f202fff,0x8801ffff,0xffffffff,0x9701ffff,0x00017999,0x00005544,
    0x001a9800,0x44015510,0x0000001a,0x00000000,0x00000000,0x00000000,
    0x00000000,0x00000000,0x00000000,0x00000000,0x00000000,0x00000000,
    0x00000000,0x00000000,0x00000000,0x220014c0,0x99999999,0x03573000,
    0x01375100,0x88099998,0xba881999,0xba8800ac,0x3331009b,0x33333333,
    0x4ccccc13,0x26600099,0x26660199,0x004cc419,0x99881331,0x10266200,
    0x03333333,0x02666660,0x26206666,0x26660199,0x20aaaa09,0x4004ffda,
    0xffffffff,0xffb503ff,0x0975fffb,0x7ff77f54,0x3ff64b8d,0x3fe61fff,
    0xdfb55fff,0x5c07ffbb,0xbbffeeff,0x3fffffa4,0x6fffffff,0xfffffff9,
    0x7e403bff,0xfa82ffff,0xff75ffff,0xfff505ff,0x3fffee5f,0x2ffffa82,
    0x3ffffffe,0x7ffe403f,0x7ffe47ff,0x3fffea3f,0xffffd84f,0x54dffd1f,
    0x004cacff,0xfa806a80,0x2ff5440b,0x2e20afa8,0x01f84efe,0x2067c798,
    0xbfc84fb8,0xe93fee20,0x46a84c82,0x3feb8879,0xd5001f40,0x17601760,
    0x1b2013a2,0x26000d50,0x882f4407,0x83e2000f,0x90625ffd,0x0d500009,
    0x74403f98,0x6400fa85,0x9801f84f,0x3f700fc7,0x9f5017cc,0x54264174,
    0x3ea03cc6,0xe801ae02,0x5405f103,0x405f300f,0x035400fa,0x3a207980,
    0x3000fc04,0x404ffc8f,0x6a80004c,0x5c013e20,0x44017c44,0x9801f84f,
    0x7f100647,0xd274035c,0x8d509905,0x205d8079,0x0f8801f8,0x3e203ea0,
    0x4407d402,0x006a802f,0x13e60f30,0x20aa0ba0,0x017fdc6a,0x2a000132,
    0x8801aa06,0x75002dc0,0x0f3003f0,0x02649b00,0x9905d0cc,0x80798d50,
    0x4026407a,0xc85d805c,0x9d0d9005,0x4001aa00,0x003fa879,0x40ff985b,
    0x00ffcc5b,0x2a000132,0x00013206,0x3f00005b,0xd000f300,0x74003545,
    0x46984c81,0x404c8079,0x802f8079,0x003e62f8,0x801b64e8,0x8f30006a,
    0x0f6002fa,0x44c85db7,0x26400ff8,0xd0354000,0x01f80005,0x9801f800,
    0x743e4007,0x6402000d,0x40798104,0x02e801fa,0x0fa801ea,0xaf88007d,
    0x1aa000fb,0x3f73cc00,0x5ec4c800,0x3fc1e45b,0x40002640,0x001f106a,
    0x00007c40,0x03cc00fc,0xc881ee98,0x8000acdf,0x10f3004c,0x2e005f95,
    0xb0013605,0x2a000b99,0x354001ff,0xdf979800,0x7c5b8003,0x7416c799,
    0x0004c806,0x01f106a8,0x0007c400,0x3cc00fc0,0x0033fa60,0x19ffd951,
    0x4c013200,0xcffeeeef,0x203e2000,0x7c4000f8,0xff10000f,0x006a8001,
    0xfb3dbf30,0xf5354009,0x1105d0fc,0x14409900,0x0f883540,0x99999930,
    0x00003e27,0x01e6007e,0x4c0001b9,0x04c800ed,0xb5555f30,0x07b0005f,
    0x172000d7,0x05ddd800,0x98003540,0x013ea0ef,0x26cb93cc,0x2640003f,
    0x0d500b70,0xccc980fc,0x007e3eec,0x26007e00,0x00026407,0x04c805c8,
    0x0bee0f30,0x05d0d500,0x40013200,0x003f88eb,0x303601aa,0x200be20f,
    0x16a8ba78,0x9001881f,0x5402dc09,0xc800b606,0x40001f45,0x407a802e,
    0xf1000019,0x26009900,0x000bea07,0x0007cc3f,0xf98004c8,0x54007e61,
    0x3cc1f806,0x1f001f70,0x4c7c41f1,0xc803f987,0x32016e04,0xc8017205,
    0x400035c5,0x005c803c,0x3f0034c0,0xf3004c80,0x2000fb80,0x8001325c,
    0x1fc4004c,0x354007dc,0x01e60fc0,0xd73d007d,0x260d35d0,0x7026404f,
    0x4407d00b,0xd0b9002f,0x2a162009,0x0004e806,0x3cc017cc,0x79802640,
    0x26004d80,0x40003f0f,0x02ec004c,0x00d500bb,0x5407983f,0x84dad806,
    0x3a605adc,0xfb813205,0x7003ea01,0x30b9003f,0x84f9807f,0x03f203f8,
    0xf301cc98,0x805d801f,0x00f3004c,0x5f4003f1,0x2640006a,0x4401d900,
    0x4035404e,0x7c03cc1f,0x40fde402,0x74404bf9,0xfb809902,0x00bee20c,
    0x5c4067dc,0x83bf305e,0x3e603fb8,0x2017e444,0xdf307fff,0x01db303d,
    0x26776666,0x99fa9881,0x0027b200,0x2000f7aa,0x999dd999,0x09afa880,
    0x20afa988,0x999eb998,0x11f99999,0x20133f53,0xfd9009dc,0x200277c0,
    0x99dd9999,0xeefe9819,0x74c001ef,0x2efeeeff,0x7f7fec40,0xfe9801ef,
    0xe801efee,0x2eb106ff,0x0cffeeff,0xffffff70,0xfffb87ff,0x27f407ff,
    0x0007fc40,0x3fffffee,0xfffc83ff,0xffffb84f,0x3fffffe5,0xffffffff,
    0xffffff71,0x203ffe20,0x0ff605fb,0xfffffb80,0x103fffff,0x30000355,
    0x30001355,0x51000155,0x55440035,0x26aa6000,0x00000000,0x00000000,
    0x00000000,0x00000000,0x00000000,0x00000000,0x00000000,0x00000000,
    0x00000000,0x00000000,0x00000000,0x00000000,0x26000000,0x99999999,
    0x88099981,0x4cc40999,0x98009999,0x99999999,0x26609999,0x99999999,
    0x4cccc199,0x99880199,0x19999999,0x4ccccccc,0x01331001,0x220cccc4,
    0x99880099,0x33333100,0x36e20003,0x0000019b,0x00000000,0xfb801771,
    0xffffffff,0x3ffff64f,0x9bfffe22,0xfffffff9,0xffc82eff,0xffffffff,
    0xfff95fff,0xffffffff,0x7fffe4ff,0x503dffff,0xffffffff,0x3fff23ff,
    0x3effffff,0x01ffff30,0x2bfffff1,0xc805fff9,0xffe83fff,0x4001ffff,
    0x42fdbefa,0x400001de,0x5c00004b,0x06ffe81f,0x79804c80,0x0ba02e80,
    0x3c417f6a,0x03cc5b80,0x4c1743c4,0x03d40eeb,0x20f307e2,0x7f405fc9,
    0xcd83c405,0x03dfc00f,0x800999b0,0x7e44043e,0x9900000c,0x3baa0000,
    0x0ffff882,0x4c026400,0x3a02e807,0x2213e202,0x798b7007,0x02e87880,
    0xb01ea36c,0xf880f309,0x807efa03,0x09b7b078,0x8803cf54,0x2600799f,
    0x1fecc007,0x00264000,0xb00ffa60,0x99000bff,0x5d00f300,0x1ee01740,
    0x22dc01e2,0xe8788079,0x1ea3e802,0x07980eb8,0x2eba06c8,0x5ec1e206,
    0xf35d00f9,0x02e9aa00,0x2a000f30,0x320002ee,0x9fb10004,0x00022001,
    0x03cc0264,0x805d0174,0x803c41f8,0x4403cc3a,0xfa802e85,0x07e60d30,
    0x03d403cc,0x3c40fa5d,0xf307d3d8,0x71ec01e6,0x0017400b,0x0003df70,
    0xfc880099,0x0000000d,0x01e60132,0x402e80ba,0x4c3c40f8,0x29879802,
    0x5d002e80,0x301f40a2,0x7409900f,0x0f101f52,0xa6c354f6,0x20f88079,
    0x0d5000f8,0x0dfc8800,0xb8013200,0x000001ef,0x79804c80,0x0ba02e80,
    0x90f10f70,0x990f300b,0x32005d00,0x26036404,0xd00fe407,0x83c426c5,
    0x0f88ba3d,0xb0b700f3,0x00fea007,0x833f6200,0xdd999998,0x2a099999,
    0x000002ee,0x26013200,0xcccccccf,0x80ba02fc,0xccf882fb,0xf9805ecc,
    0x804ecccc,0x40b7002e,0x67cc00fa,0x1efdcccc,0x83f11740,0x2dc7b078,
    0x7403ccb9,0x64406a82,0x0f220fcf,0x6c3bee00,0xffffffff,0xdf75ffff,
    0x554c0001,0x04c8000a,0xeeeeef98,0x3a02feee,0xfeca999b,0xddddf103,
    0xddf300bd,0x5d009fdd,0x7c416e00,0xeeef9802,0x403ffeee,0x1e23642e,
    0x3e3f11ec,0x0f301e61,0x21b900fc,0x800fea5c,0x99003fd9,0x005fd300,
    0x001bff60,0x03cc0264,0xfffd0174,0x44019dff,0x79805c87,0x02e804c8,
    0x01760970,0x3ba603cc,0x2f885d00,0x321ec1e2,0x203cc6bc,0xe813204c,
    0x01ecbe22,0x000cfc88,0xefa80132,0x0fffc002,0x9804c800,0x3a02e807,
    0x50f10002,0x750f3007,0x36005d00,0x8300eb83,0x209b0079,0xf10fa82e,
    0x5df10f60,0x7ffc0798,0x07ffffff,0x1f3f50f3,0x003bf700,0xf7000990,
    0xbff3003b,0x40264000,0x202e8079,0x0f10002e,0x9803cc00,0x1f801742,
    0x47980fcc,0x20f30079,0x1e29b02e,0x4c2e41ec,0x2667aa07,0x82e99999,
    0x05fd81f8,0x000177d4,0x32200099,0x3ff200cf,0x01320000,0x80ba01e6,
    0x0f10002e,0xb803cc00,0x3d401745,0x98f30274,0x3a07e007,0x0f13f302,
    0x079800f6,0x416e00f6,0x502fa84e,0x900005fd,0xfd980009,0x0007fd03,
    0x079804c8,0x00ba02e8,0x30003c40,0x5d16e00f,0x3642f980,0x00f31e60,
    0x901741e6,0x00f60f1b,0x01f10798,0x7f501f10,0x427bbe61,0x00003fd8,
    0x54000132,0x01be62fe,0x26013200,0x3a02e807,0x00f10002,0x5b803cc0,
    0x87d10174,0x23cc00f9,0x04e88079,0x3dfc405d,0x1e6003d8,0x07b002dc,
    0x753fbfea,0x00019d6f,0x00003b80,0x01fa8fd4,0xdd999980,0x2a609999,
    0xbe99819f,0x4cdf4cc1,0x7d4c4019,0x44009999,0x99999fa9,0x315c9999,
    0xd733337d,0x3339d09f,0x2f533333,0x9999fa98,0x885eb999,0xf7019be9,
    0x0337d30f,0x884fd4cc,0x26019ce9,0xa8809eb9,0x0000000a,0x00000000,
    0x7fffdc00,0x33ffffff,0x445fffff,0xf33fffff,0x3fffffff,0x7ffffdc0,
    0x7fdc06ff,0xffffffff,0xfff75fff,0x037bffff,0x3ffffffa,0xff97ffff,
    0xffffffff,0x3ffee05b,0xb8fd02ff,0x982fffff,0xf94fffff,0xf305ffff,
    0x0009ffff,0x00000000,0x00000000,0x00000000,0x00000000,0x00000000,
    0x00000000,0x00000000,0x00000000,0x00000000,0x00000000,0x00800008,
    0x00000400,0x00000000,0x40799990,0x0004cccb,0x20999500,0xca81cccb,
    0x67edc2cc,0x426665c0,0x6643cccc,0xccc84ccc,0x333224cc,0x1ccccccc,
    0x80000060,0x1540aaa9,0xeffedb98,0x3ffae003,0x4c0172ef,0x00ceffed,
    0x677ff644,0x3ff6e600,0x3320b8cf,0x3bffd914,0x016775c0,0x6547dd95,
    0x11efea9c,0xb9305dfb,0x0fb32a0f,0x74cfb326,0x2a0ed9be,0xfcb83cfe,
    0x66fe5c2e,0x3cfdcb83,0x333333e6,0x3e01fecc,0xb2fffc01,0xfffb0fff,
    0x2a37ff41,0xec999bdf,0x4df74c05,0x02fefdb9,0xd5337df9,0x2b7ea03d,
    0xb82fda99,0xfdb99bdf,0x3a7f6e2f,0x02fda9ad,0x43c8012e,0xc9bfefc9,
    0x1fa9cfaf,0x07b00f10,0xa84fabd8,0x3b605d80,0x32017200,0x3e607984,
    0x3a00fc02,0x1bff24ff,0xff88fffe,0x3e2000ff,0xe809d101,0x201ec82f,
    0x017cc0fb,0x01fc43f5,0x3ff985f7,0x43540d90,0xfd02e82a,0x2644fe85,
    0x03d80788,0x40017f6c,0x402ec0ed,0x07e200f9,0x01fc41a2,0x3ff600fc,
    0xf317fee2,0x0dffb0ff,0x1720b900,0x1f50be60,0x1f44b900,0x0f9875c0,
    0x0fe60f40,0x1f101f88,0x1f107fc4,0x21b213a0,0xb00f1079,0x001fd807,
    0x17a23b60,0x16e04d80,0x7909d100,0x0ca88fc1,0xff987ff2,0xa81ffdc4,
    0x10b70002,0xb02e003f,0x6b8fc009,0x05f8fa00,0x2e807980,0x2eea8ba0,
    0xb82e81a6,0x0f107985,0x03d807b0,0x05eed800,0x05f03d40,0xfd505d80,
    0x9dfb9f7d,0x3e20ffb8,0x0037f43f,0x9bddb950,0x000f30bb,0x99999af8,
    0x92d99999,0xd1264009,0x401359df,0x202e8079,0xb96ef63c,0x16e0ba05,
    0x403c41e6,0x001ec03d,0x0007fc40,0x003541f4,0x3ae201b6,0xff301bff,
    0x7fc43ff0,0xcfe98002,0x85ecbaac,0x3e20005a,0xffffffff,0x05d4ffff,
    0x654c3540,0x7980dffe,0x56e02e80,0x7b0f89f8,0x42dc1740,0xb00f1079,
    0x0003d807,0x00766744,0x00fa1ae0,0x3a000ec8,0x1be200fe,0x06fa83fa,
    0x200cf880,0x0006a85b,0x3d8000f4,0x22016e00,0x03cc1fda,0x2af30174,
    0xd00fcfa6,0x0f30b705,0x00f601e2,0x7440007b,0xf0003b24,0xb8007cc5,
    0x6db2000f,0x3641f406,0x320007ee,0x7885b806,0x0026c000,0x4f6005b8,
    0x7989d000,0x4fc02e80,0x01e36e3d,0xf30b705d,0x7d003e20,0x10003d80,
    0x003f909d,0x200992e4,0x985301fa,0x0009d11f,0x74000620,0x7d05c803,
    0x03ea0400,0x2007e600,0x5003d1f9,0x2e80798d,0xf107dec0,0xb82e80d7,
    0x0b607985,0x3601ff44,0x04f98003,0x7c4007ee,0xf9800f88,0x87d16e02,
    0x000001f9,0x3202dc00,0x803f505f,0x006c87d8,0x10075c55,0x74027c7d,
    0x17403cc5,0x3f61bf20,0x2dc17404,0x43d503cc,0x41becfb8,0x999cd999,
    0x3bf50099,0x05fb3101,0x20173360,0x99999cf9,0x180c5c99,0x80000000,
    0x3aa20bf8,0xfc809ece,0x01efa883,0xfd5105fb,0xfa82fd85,0x440effc5,
    0x27ea60fd,0x01be9880,0x0bee0fea,0x2e05f4c4,0x804fcc1d,0xb2effefd,
    0x3ffea1ff,0x4fffffff,0x87ffffa8,0x802ffffe,0xfb802ff9,0xffffffff,
    0x0000005f,0x7fd40000,0xff73ffee,0xddfd301f,0xf5007dff,0x19fffddf,
    0x3fbbfea0,0xffcae82f,0x261dffee,0x5c0fffff,0x0000ffff,0x0ffffb80,
    0xff98bfee,0x00055404,0x00000000,0x00000000,0x00000000,0x0554c400,
    0x35551000,0x13551000,0x00d54c00,0x00aaa988,0x00000000,0x00000000,
    0x00000000,0x00000000,0x00000000,0x00000000,0x00000000,0x00000000,
    0x555100cc,0x55555555,0xdb881555,0x55551002,0x55555555,0x00000001,
    0x00000000,0x00000000,0x00000000,0x00000000,0x00000000,0x00ee8800,
    0xddddddb3,0x3ddddddd,0x06f5ef44,0xffff9864,0xffffffff,0xffffffb1,
    0xffffffff,0x00000fff,0x00000000,0x00000000,0x00000000,0x00000000,
    0x00000000,0x0000bbbb,0x3b624e80,0xaaa89b60,0xaaaaaaaa,0x3333310a,
    0x33333333,0x00001333,0x00000000,0x00000000,0x00000000,0x00000000,
    0x00000000,0x04e88ec8,0x20710000,0x000decfc,0x00000000,0x00000000,
    0x00000000,0x00000000,0x00000000,0x00000000,0x4c3f5000,0x0000002f,
    0x00001ca8,0x00000000,0x00000000,0x00000000,0x00000000,0x00000000,
    0x00000000,0x3ea0be20,0x3ffffea1,0xffffffff,0x0000002f,0x00000000,
    0x00000000,0x00000000,0x00000000,0x00000000,0x00000000,0x6409d100,
    0x2666660e,0x99999999,0x00000001,0x00000000,0x00000000,0x00000000,
    0x00000000,0x00000000,0x00000000,0x0f6016e0,0x00000000,0x00000000,
    0x00000000,0x00000000,0x00000000,0x00000000,0x00000000,0x00008000,
    0x00000000,0x00000000,0x00000000,0x00000000,0x00000000,0x00000000,
    0x00000000,0x00000000,0x00000000,0x00000000,0x00000000,0x00000000,
    0x00000000,0x00000000,
};

static signed short stb__courier_34_usascii_x[95]={ 0,7,3,2,3,2,3,7,8,4,0,2,4,2,
6,3,3,3,2,2,3,2,4,3,3,4,6,4,0,1,0,0,3,0,1,1,2,1,2,1,1,3,2,1,
1,0,0,0,2,1,1,2,2,1,0,0,1,1,3,0,0,0,3,1,6,2,0,2,1,1,3,1,1,2,
2,2,2,0,1,2,0,1,2,3,2,1,0,0,1,2,3,0,8,0,2, };
static signed short stb__courier_34_usascii_y[95]={ 24,5,5,4,4,5,8,5,5,5,5,7,19,14,
20,3,5,5,5,5,5,5,5,5,5,5,11,11,7,12,7,6,4,6,6,6,6,6,6,6,6,6,6,6,
6,6,6,6,6,6,6,6,6,6,6,6,6,6,6,5,3,5,5,30,4,10,5,10,5,10,5,10,5,4,
4,5,5,10,10,10,10,10,11,10,6,11,11,11,11,11,11,5,5,5,13, };
static unsigned short stb__courier_34_usascii_w[95]={ 0,4,12,14,12,14,12,4,6,6,12,14,7,14,
6,12,12,12,13,14,12,14,12,12,12,12,6,8,15,16,15,11,12,18,16,16,15,15,15,16,16,12,16,17,
16,18,17,16,15,16,17,14,14,16,18,18,16,16,12,6,12,6,12,19,6,15,17,15,17,15,14,16,16,14,
11,16,14,18,16,14,17,17,15,12,14,16,18,18,16,16,12,7,2,7,14, };
static unsigned short stb__courier_34_usascii_h[95]={ 0,20,10,22,23,20,17,10,23,23,12,17,10,3,
5,24,20,19,19,20,19,20,20,20,20,20,14,17,17,7,17,19,22,18,18,19,18,18,18,19,18,18,19,18,
18,18,18,19,18,22,18,19,18,19,18,18,18,18,18,23,24,23,9,3,6,15,20,15,20,15,19,20,19,20,
26,19,19,14,14,15,20,20,13,15,19,14,13,14,13,19,13,23,23,23,5, };
static unsigned short stb__courier_34_usascii_s[95]={ 144,208,227,116,65,213,181,249,78,85,214,
210,240,122,248,26,144,1,221,228,235,193,243,51,82,95,248,241,225,90,194,
82,131,162,108,48,79,63,47,31,14,1,14,212,195,143,125,204,31,99,124,
94,109,65,142,230,178,161,95,92,13,58,77,137,249,1,33,17,64,33,125,
16,108,1,1,140,157,113,77,49,157,175,149,64,172,132,182,94,165,187,201,
47,55,39,107, };
static unsigned short stb__courier_34_usascii_t[95]={ 22,1,88,1,1,1,69,49,1,1,88,
69,88,103,88,1,1,49,28,1,28,1,1,28,28,28,28,69,69,103,69,
49,1,69,69,49,69,69,69,49,69,69,49,49,49,69,69,28,69,1,49,
49,49,49,49,49,49,49,69,1,1,1,103,103,60,88,28,88,28,88,28,
28,28,28,1,28,28,88,88,88,1,1,88,88,28,88,88,88,88,28,88,
1,1,1,103, };
static unsigned short stb__courier_34_usascii_a[95]={ 288,288,288,288,288,288,288,288,
288,288,288,288,288,288,288,288,288,288,288,288,288,288,288,288,
288,288,288,288,288,288,288,288,288,288,288,288,288,288,288,288,
288,288,288,288,288,288,288,288,288,288,288,288,288,288,288,288,
288,288,288,288,288,288,288,288,288,288,288,288,288,288,288,288,
288,288,288,288,288,288,288,288,288,288,288,288,288,288,288,288,
288,288,288,288,288,288,288, };

// Call this function with
//    font: NULL or array length
//    data: NULL or specified size
//    height: STB_FONT_courier_34_usascii_BITMAP_HEIGHT or STB_FONT_courier_34_usascii_BITMAP_HEIGHT_POW2
//    return value: spacing between lines
static void stb_font_courier_34_usascii(stb_fontchar font[STB_FONT_courier_34_usascii_NUM_CHARS],
                unsigned char data[STB_FONT_courier_34_usascii_BITMAP_HEIGHT][STB_FONT_courier_34_usascii_BITMAP_WIDTH],
                int height)
{
    int i,j;
    if (data != 0) {
        unsigned int *bits = stb__courier_34_usascii_pixels;
        unsigned int bitpack = *bits++, numbits = 32;
        for (i=0; i < STB_FONT_courier_34_usascii_BITMAP_WIDTH*height; ++i)
            data[0][i] = 0;  // zero entire bitmap
        for (j=1; j < STB_FONT_courier_34_usascii_BITMAP_HEIGHT-1; ++j) {
            for (i=1; i < STB_FONT_courier_34_usascii_BITMAP_WIDTH-1; ++i) {
                unsigned int value;
                if (numbits==0) bitpack = *bits++, numbits=32;
                value = bitpack & 1;
                bitpack >>= 1, --numbits;
                if (value) {
                    if (numbits < 3) bitpack = *bits++, numbits = 32;
                    data[j][i] = (bitpack & 7) * 0x20 + 0x1f;
                    bitpack >>= 3, numbits -= 3;
                } else {
                    data[j][i] = 0;
                }
            }
        }
    }

    // build font description
    if (font != 0) {
        float recip_width = 1.0f / STB_FONT_courier_34_usascii_BITMAP_WIDTH;
        float recip_height = 1.0f / height;
        for (i=0; i < STB_FONT_courier_34_usascii_NUM_CHARS; ++i) {
            // pad characters so they bilerp from empty space around each character
            font[i].s0 = (stb__courier_34_usascii_s[i]) * recip_width;
            font[i].t0 = (stb__courier_34_usascii_t[i]) * recip_height;
            font[i].s1 = (stb__courier_34_usascii_s[i] + stb__courier_34_usascii_w[i]) * recip_width;
            font[i].t1 = (stb__courier_34_usascii_t[i] + stb__courier_34_usascii_h[i]) * recip_height;
            font[i].x0 = stb__courier_34_usascii_x[i];
            font[i].y0 = stb__courier_34_usascii_y[i];
            font[i].x1 = stb__courier_34_usascii_x[i] + stb__courier_34_usascii_w[i];
            font[i].y1 = stb__courier_34_usascii_y[i] + stb__courier_34_usascii_h[i];
            font[i].advance_int = (stb__courier_34_usascii_a[i]+8)>>4;
            font[i].s0f = (stb__courier_34_usascii_s[i] - 0.5f) * recip_width;
            font[i].t0f = (stb__courier_34_usascii_t[i] - 0.5f) * recip_height;
            font[i].s1f = (stb__courier_34_usascii_s[i] + stb__courier_34_usascii_w[i] + 0.5f) * recip_width;
            font[i].t1f = (stb__courier_34_usascii_t[i] + stb__courier_34_usascii_h[i] + 0.5f) * recip_height;
            font[i].x0f = stb__courier_34_usascii_x[i] - 0.5f;
            font[i].y0f = stb__courier_34_usascii_y[i] - 0.5f;
            font[i].x1f = stb__courier_34_usascii_x[i] + stb__courier_34_usascii_w[i] + 0.5f;
            font[i].y1f = stb__courier_34_usascii_y[i] + stb__courier_34_usascii_h[i] + 0.5f;
            font[i].advance = stb__courier_34_usascii_a[i]/16.0f;
        }
    }
}

#ifndef STB_SOMEFONT_CREATE
#define STB_SOMEFONT_CREATE              stb_font_courier_34_usascii
#define STB_SOMEFONT_BITMAP_WIDTH        STB_FONT_courier_34_usascii_BITMAP_WIDTH
#define STB_SOMEFONT_BITMAP_HEIGHT       STB_FONT_courier_34_usascii_BITMAP_HEIGHT
#define STB_SOMEFONT_BITMAP_HEIGHT_POW2  STB_FONT_courier_34_usascii_BITMAP_HEIGHT_POW2
#define STB_SOMEFONT_FIRST_CHAR          STB_FONT_courier_34_usascii_FIRST_CHAR
#define STB_SOMEFONT_NUM_CHARS           STB_FONT_courier_34_usascii_NUM_CHARS
#define STB_SOMEFONT_LINE_SPACING        STB_FONT_courier_34_usascii_LINE_SPACING
#endif
