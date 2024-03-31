// Font generated by stb_font_inl_generator.c (4/1 bpp)
//
// Following instructions show how to use the only included font, whatever it is, in
// a generic way so you can replace it with any other font by changing the include.
// To use multiple fonts, replace STB_SOMEFONT_* below with STB_FONT_consolas_20_latin1_*,
// and separately install each font. Note that the CREATE function call has a
// totally different name; it's just 'stb_font_consolas_20_latin1'.
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

#define STB_FONT_consolas_20_latin1_BITMAP_WIDTH         256
#define STB_FONT_consolas_20_latin1_BITMAP_HEIGHT        126
#define STB_FONT_consolas_20_latin1_BITMAP_HEIGHT_POW2   128

#define STB_FONT_consolas_20_latin1_FIRST_CHAR            32
#define STB_FONT_consolas_20_latin1_NUM_CHARS            224

#define STB_FONT_consolas_20_latin1_LINE_SPACING          13

static unsigned int stb__consolas_20_latin1_pixels[]={
    0x007e63f3,0x4ccc0182,0x03333109,0xb8000218,0x2219304e,0x000f541c,
    0xedb80764,0x883a801c,0x13100009,0x88009880,0x00644001,0x02620790,
    0x88026200,0x80204009,0x8fe40040,0x203f31f9,0x05f35ffa,0x653fffe2,
    0xf700ffff,0x80073f63,0x4ff204fb,0x00fdc4fb,0x360ffe20,0x402fcabe,
    0x01fe984d,0x100f7cc0,0x7dc01dfd,0x5405baef,0x40be2007,0x26001fe9,
    0xdfd101ef,0x7cc7f201,0x9f31fc84,0x3f33ff80,0x3be607e6,0x4c03f60b,
    0x33f94f99,0xb897ea03,0x0591007e,0x2e054288,0x0db8001f,0x01f2076c,
    0x006e407d,0x6c404d88,0x3900dc8c,0x2603df91,0xb502cfec,0xdc801fdf,
    0x204d8800,0x80dc8cd8,0x505b10da,0x500b621b,0x1f98fcc7,0x6f881fc8,
    0x80f94f80,0x2f980ef8,0xb8000000,0xf500001f,0x2605f103,0x0000003f,
    0x6c000000,0xc86effff,0x005fecef,0x00000000,0x4c000000,0xf903f31f,
    0x3e027cc0,0x1fc80f94,0x13a213e0,0x04e88764,0x2a7ee1d9,0x3ba61dfd,
    0x1760eeee,0x7ffe44d8,0x3deda86f,0x01ef6d40,0x500f7b6a,0x7f707bdb,
    0xf27d4136,0x904d87fd,0x25c826cb,0x26cb904d,0xdeda85c8,0x3e67b803,
    0x0d903f31,0x53e00fc8,0x013e207c,0x103fa09f,0x440fe8bf,0x37f3ee5f,
    0x99930ffc,0x47e23fd9,0x25c9efeb,0x43afbcfd,0x0efecefc,0xefecefc8,
    0xfecefc80,0xecefc80e,0x743f60ef,0x47ccfd03,0x7d82fc7e,0xbf3ec17e,
    0xb05f9f60,0xfecefc8f,0xf99f200e,0x0db03f31,0x53e02fa8,0x00bee07c,
    0x50fee0bf,0x543fb85f,0xa87fee2f,0x547ee03f,0x91f97f57,0x43dd3eab,
    0x227dc4fa,0x227dc4fa,0x227dc4fa,0x927dc4fa,0x3e20be7f,0xf07e5b24,
    0x05f9f60b,0x7d82fcfb,0xf53ec17e,0xd504fb89,0x1f98fccf,0x1fcc05e8,
    0xd81f29f0,0x8836c00f,0x2207ec6f,0xf707ec6f,0x7dc0bf05,0xbdd76b91,
    0x1b21f96b,0x3a3f41fa,0x07e8fd07,0xfd07e8fd,0x40ff7fc4,0x7dd3a3f9,
    0xf3ec17e1,0x05f9f60b,0x7d82fcfb,0x263f41fa,0x07e64dff,0x4017e544,
    0x3e53e05f,0x9f500ff0,0xf11fc815,0x7c47f209,0x3740fdc4,0x7d363f70,
    0x3ed72d93,0x904f88bb,0x6413e23f,0x3209f11f,0x3209f11f,0x3fff221f,
    0x1f897d43,0xd82fc5f5,0xf3ec17e7,0x05f9f60b,0x6413e2fb,0x2603f21f,
    0x05ff501f,0x94f81f60,0xa802fc0f,0xba7cc2ff,0x2e9f301f,0x740fdc1f,
    0x6747ee06,0x572bd2f9,0xf989d1fb,0x3e65f703,0x3e65f703,0x3e65f703,
    0xf505f703,0x4fe61dfd,0x5f87ee7b,0xd82fcfb0,0xf3ec17e7,0x1fcdf60b,
    0x41be2fb8,0x3ea201f9,0x3e07e803,0x037c0f94,0x7e8057dc,0xdd7e80dd,
    0x0bf03f70,0xf9be8fdc,0x7ccfa9f2,0x02fa87f4,0x40bea5f5,0x205f52fa,
    0x205f52fa,0xf76c82fa,0x726d3e29,0x7d82fc1f,0xbf3ec17e,0xb05f9f60,
    0x7d40beaf,0x3e603fa2,0x402ec061,0x3e53e06f,0x0bb00fb0,0x403fbfb8,
    0xfb83fbfb,0xf7017dc1,0x7d57d3a3,0x33fa0f9c,0x07f539bf,0x81fd4bea,
    0x207f52fa,0x207f52fa,0xf15d82fa,0xd17c77cb,0x4fb05f8f,0x2fcfb05f,
    0x6c17e7d8,0x3ea07f57,0xf3037ee2,0x1f207e63,0xa7c09f30,0x007ee07c,
    0xfff8809f,0x07ffc400,0x7e4d6fdc,0x4d8fdc05,0x09ff7ffb,0x26dffff7,
    0x261f703f,0x261f703f,0x261f703f,0xd01f703f,0xcfd93ee9,0x6f87f50f,
    0xe837cfd0,0xf3f41be7,0x1fcdfa0d,0x7fe40fb8,0x3e63f34c,0x7dc07c81,
    0x03e53e02,0x04f807f3,0xf9005fc8,0x3fffee0b,0x91fb803e,0x201984cb,
    0x1be209fa,0x20df13f4,0x741be27e,0x3f41be27,0xdfddf9bd,0x6577f441,
    0xbf06e86f,0x3a5f8374,0x8374bf06,0x3a0df15f,0x26fd9307,0xf903f31f,
    0xa7c06e80,0x2037c07c,0x01fd804f,0x3ee03fb0,0x50fd8001,0x0f70001f,
    0x87f50bf2,0x21fd42fc,0x21fd42fc,0x91fd42fc,0x017dfffd,0x209ffff1,
    0xb27d40fd,0x364fa81f,0xfb27d40f,0x3f24fa81,0x3001fd42,0x3207e63f,
    0xf00bf207,0x9f501f29,0x3ea027c0,0x40bf5005,0x6f8001fb,0x2e40027c,
    0xfcacff98,0xcacff986,0xacff986f,0xcff986fc,0x3f306fca,0x4009f980,
    0xffcabef9,0x32afbe60,0x2fbe60ff,0x3e60ffca,0x20ffcabe,0x6fcacff9,
    0xf98fcc00,0xf981fa81,0x0f94f805,0x7f305f90,0x01df9530,0x0077e54c,
    0xacc803f7,0x67d42feb,0x3601ca99,0x3fff6204,0x3fff6204,0x3fff6204,
    0x3fff6204,0x3201ea04,0x3ffa6006,0xffe980df,0xffe980df,0xffe980df,
    0xffd880df,0x1f98004f,0x33be03f3,0x5101df11,0x2bf29f55,0x21fb00aa,
    0xfa80fec9,0x4efa804e,0x5c01fb80,0xb302efff,0x54019dff,0x08001001,
    0x02000400,0x00000a60,0x00040010,0x10004001,0x98fcc000,0x2bd7301f,
    0xfff100e8,0x3ffff29f,0x3f61d100,0x0000001d,0x00000000,0x00000000,
    0x00000000,0x00000000,0x00000000,0x8fcc0000,0x000001f9,0x00000000,
    0x00000000,0x00000000,0x00000000,0x00000000,0x00000000,0x00000000,
    0x00000000,0x00000000,0x00000000,0x00000000,0x00000000,0x00000000,
    0x00000000,0x00000000,0x00000000,0x00000000,0x00000000,0x00000000,
    0x00000000,0x00000000,0x00000000,0x00000000,0x32600131,0x4c04eeed,
    0x00bfb01e,0x02620031,0x88026200,0x001e9809,0x20401310,0x00131000,
    0x09880262,0x01ef6d40,0x3b220102,0x008103ee,0x18800988,0x20009880,
    0x72fa82ca,0x01fe985d,0x7e6fffe4,0xda836c05,0x3fee02d8,0xfd305bae,
    0x0f7cc003,0xe80efe88,0x1ef98005,0x13e63f90,0x3003df30,0x3fa203df,
    0xd9df900e,0x23f901df,0x67fc44f9,0x31fc83cb,0x77f4409f,0x2bbfee00,
    0x01fe985b,0x6c2eaea8,0x3207f75f,0xffff700d,0x3f8817e5,0x403d5d30,
    0x01efc89c,0x6c4006e4,0x32336204,0x0007dc0d,0x0da809b1,0x26c405b1,
    0x2204d880,0x540dc8cd,0x5427e44f,0xfb85b10d,0xb10da801,0x32336205,
    0xf913900d,0x006e403d,0x3221e52e,0x20007f70,0xbf2ffffd,0xb7007e40,
    0x00000007,0xf8800000,0x00000004,0x00000000,0x00fd07e8,0x00017dc0,
    0x00000000,0x07f7e600,0x3b205f70,0x5ffffd04,0x404f817e,0x9d9004ec,
    0xeeeeee80,0x7777740e,0x777740ee,0x03e40eee,0x13a203d9,0x1ddddddd,
    0xe9813b20,0x21eeeeee,0xeeeeeee9,0x3f209f11,0x3bbbba61,0x13fe21ee,
    0xc8027640,0x20fb204e,0x3bbba65c,0x15101eee,0x0bee3f30,0x3603ffe2,
    0x0bf2ffff,0xff8807ea,0x7ffc400f,0x3bbbfe00,0x777fc0ee,0x77fc0eee,
    0x7cc0eeee,0x320bf302,0x7777fc1f,0xfff880ee,0xdfddd300,0x7774c3dd,
    0x7f31eeef,0xee98bee0,0x3a1eeefe,0x2202efdf,0x7c400fff,0x0ffd00ff,
    0x7f774cdb,0x76dc1eee,0x47e60cef,0xfcfa82fa,0x2ffff983,0x5017a0bf,
    0xfa807f9f,0x017e03fc,0x05f802fc,0x2fd81b60,0x02fc2fcc,0x007f9f50,
    0x5f5005f5,0x3ea05f50,0xf705f502,0x540ffa63,0x7d403fcf,0x7ffd03fc,
    0x05f506d8,0x37f5e6f4,0x20bea5f3,0x3aa0bf7d,0xf30bf2ff,0x0bf7d805,
    0x7c0bf7d8,0x200bf005,0x07ea005f,0x03f637c4,0xf7d8017e,0x005f500b,
    0x07f505f5,0x17d40bea,0x07f607e4,0x3602fdf6,0x377a0bf7,0x2fa836c6,
    0xfa8fe400,0x4f885f52,0x854c01fb,0x4407c85f,0x2201fb4f,0x3e01fb4f,
    0x200bf005,0x027c005f,0x413e65f9,0x29f1005f,0x17d400fd,0x7cc17d40,
    0x2a03f703,0x444fa82f,0xfda7c44f,0x3f69f100,0x22fade80,0x005f506d,
    0x25f52fa8,0xa8fd41fa,0x117e003f,0x51fa807f,0x547ea07f,0x555df03f,
    0x555df055,0x555df055,0x807dc055,0x201fb6f8,0x82aaaaef,0x807f51fa,
    0x2fa802fa,0x0fd06f88,0xcfd817d4,0x1fa89f10,0x47ea07f5,0xdd5e83fa,
    0x02fa836c,0x97f76dcc,0xd83f52fa,0xf8017e27,0x36007dc5,0x3ec17e27,
    0x3ffe0bf1,0xfff87fff,0xfff87fff,0x3e207fff,0x0ff7ee03,0x7ffffff8,
    0x017e27d8,0x5f5005f5,0x7f50bf60,0xf7017d40,0x7d81fb5f,0x13ec17e2,
    0x3eebd0bf,0x0bea0db2,0xfdcccfe8,0x10627f52,0x000fd8bf,0x4405e8bf,
    0x2207ec5f,0x7c07ec5f,0xf819999d,0xf819999d,0x4019999d,0x037f406d,
    0x0666677e,0x00fd8bf1,0x3ea00bea,0x959ff302,0x17d401df,0x107ff660,
    0x440fd8bf,0x3a07ec5f,0xa836dbe5,0xa85f302f,0x0a27f52f,0xfb5559f5,
    0x549f1005,0x567d401f,0x7d42fdaa,0x82fdaaac,0x00bf005f,0x3e60017e,
    0xf00fee02,0x559f500b,0x7d405fb5,0x202fa802,0x00cfffd9,0xfc8017d4,
    0x55567d43,0x567d42fd,0x2f42fdaa,0x2a0db3f7,0xc81f902f,0x3f67f72f,
    0x3fffff64,0x3fa805ff,0x3ff601b6,0x6c5fffff,0x5fffffff,0x0bf005f8,
    0x740017e0,0xf00bea05,0xffffb00b,0x7d40bfff,0x802fa802,0x5f5002fa,
    0xfb13e200,0x8bffffff,0xfffffffd,0xbbf12f45,0x5c0bea0d,0x2ffeb9df,
    0x44ff27f7,0xe99999df,0x2e6faa0f,0x807f10ff,0x99999df8,0x33bf10fe,
    0xf81fd333,0x200bf005,0x1f50005f,0xbf00bea0,0x999df880,0xf500fe99,
    0x005f5005,0x40663df1,0x99a882fa,0x37e21fda,0x0fe99999,0x33333bf1,
    0x322f41fd,0x05f506ef,0x7ce7ffe4,0x02fa8202,0x7ff4c5f7,0x201f21ef,
    0x25f702fa,0x85f702fa,0x0aaaaaef,0x5555577c,0x555577c0,0x504f800a,
    0xaaef805f,0x05f50aaa,0xcaa88bee,0x2a20aacf,0x00aacfca,0x897fffea,
    0x0aacfcaa,0x85dffff3,0x25f702fa,0x45f702fa,0x137fc45e,0x1559f955,
    0xfd800020,0x310bf100,0x07ec0001,0x01fb5f88,0xffff17e2,0xfff83fff,
    0x7fc1ffff,0x001fffff,0x3e017d40,0xb1ffffff,0xa97e201f,0x2fffffff,
    0x3fffffea,0x15d4402f,0x3fffffea,0x4066622f,0x2bf100fd,0x4bf100fd,
    0x2a6fd85e,0x2fffffff,0x00000000,0x00000000,0x00000000,0x00000000,
    0x00000000,0x00000000,0x00000000,0x00000000,0x36e00000,0x864c1dee,
    0x1f7541c8,0x21930b62,0x0fae01c8,0xd7003ec8,0x0fb20625,0x2013ae00,
    0x0fae04eb,0x0512dc88,0x2607ddb5,0x6403910c,0x40eeeefe,0x75c003ec,
    0xc8864c03,0x800fae01,0x375104eb,0x512dc880,0xfd10fee0,0xfc8bdb9d,
    0x5fcc9f73,0x321b21fc,0x2e09f73f,0x3f203fcf,0xfeff9803,0x4007f906,
    0x4fb804fb,0x40ff3ee0,0x45fefcdd,0x84fdbdfc,0x209f73fc,0xcefcabfd,
    0x7003fc80,0x7e407f9f,0x3ee09f73,0x4fb803fc,0x07ffff70,0x2ff7e6ec,
    0x17f47ff8,0x4150a20c,0x0fccfe6b,0x2202a144,0x5401931c,0x3fff200c,
    0x032a00af,0x2200b220,0x4c72202c,0x0ae2080c,0x887e87f3,0x1fcc0542,
    0x019501f6,0x01931c88,0x910150a2,0xc8803263,0x3a2bf102,0x15c4100f,
    0x1fdc7f70,0x74f90000,0x000009d3,0xa84c0000,0x0000004f,0x00000000,
    0x00fd07ee,0x7e41fb80,0x00000000,0x80000000,0x007ee3f9,0x00fd8000,
    0x19dfdb70,0x64fe67d4,0x3bf6a00f,0x0fbf6a03,0x203efda8,0xb81ffeda,
    0xb80cefed,0x500cefed,0x36e07dfb,0xdb80cefe,0x3f20cefe,0x6dc0bf60,
    0x89f304ef,0x3bf6e07e,0x277edc04,0x174c1ea8,0x22e983d5,0x1174c1ea,
    0x2e03ec9f,0x74004efd,0x2f37a006,0x56f5c6fe,0x37f202f9,0xdfc86fca,
    0xdfc86fca,0xefc86fca,0xcde85fcc,0xcde86feb,0xdfc86feb,0xcde86fca,
    0xcde86feb,0x43f26feb,0x7bfb02fd,0xbfd01dfb,0x3f605fd9,0xd80efdbd,
    0x40efdbdf,0x71fcc1fb,0x2e3f983f,0x3a1fcc1f,0x3602fdaf,0x00efdbdf,
    0xc8000bf0,0x9817a01f,0xf317d43f,0x3e62fa87,0x9f317d43,0xfc801fc8,
    0x261fc801,0x4017d43f,0x1fc801fc,0x209f11f9,0x227d42fb,0x01cdcbfa,
    0x44fa85f7,0x227d42fb,0x71fcc1fb,0x2e3f983f,0x261fcc1f,0x3ee01eff,
    0x40827d42,0x7d40006f,0x6401f902,0x3f25f80f,0x03f25f80,0xf987d97e,
    0x802fa804,0x203f22fa,0x02fa805f,0x21f92fa8,0xd06e80ef,0x3a007c8d,
    0x06e8dd06,0x4c1fb8dd,0xf307ee3f,0x3e60fdc7,0xb97ffa23,0x86e83744,
    0x001fa4fc,0x05fddb73,0x839915f3,0xfcccccfd,0x33333f66,0x333f66fc,
    0x1ba6fccc,0x76dcc2fc,0xedb982fe,0x333f62fe,0xb986fccc,0xb982feed,
    0x1f92feed,0x0bf07bee,0x9dff71f6,0x20bf0399,0x7d82fc7d,0x8fe60fdc,
    0x71fcc1fb,0x3a3f983f,0x8dd4fc8f,0xfd0fb05f,0xe8017ecf,0x82fdcccf,
    0x1fddf8de,0x333333fa,0x3333fa3c,0x33fa3ccc,0x3e3ccccc,0xcfe8bf05,
    0x7f42fdcc,0x3a2fdccc,0x3ccccccf,0x7ee667f4,0x6e667f42,0x7d41f92f,
    0x3ec17e1f,0x3fbbbfe2,0x7d82fc4f,0x5c7d82fc,0xf71fcc1f,0x3ee3f983,
    0x3f99fcc1,0xbf17ebfa,0x3fe61f60,0x9801df30,0x2e17d42f,0xd8fe7b8f,
    0x01fd801f,0x6e801fd8,0x0be64f88,0x217cc5f5,0x007f62fa,0x45f50be6,
    0xc97d42f9,0xdd2fcc0f,0x81fb1ba0,0x41ba0fe8,0x6e83746e,0x8fe60fd4,
    0x51fcc1fa,0xf53f983f,0x217ffc45,0x3e0dd06e,0x5de7fe46,0xf903f25d,
    0x26c9fc45,0x2013ee4e,0x4fb804fb,0x7dc1fc80,0x5f903f22,0x8bf207e4,
    0x0fc804fb,0x81f917e4,0xd01f92fc,0x3e60fe4d,0x47e837c3,0x21fcc1fc,
    0x21fcc1fc,0x8ffa23f8,0x8ffa23f8,0x4ffa23f8,0x07fd44f9,0x87f307f2,
    0xfea82fc8,0x37ee2dff,0x362ffeb9,0x0beabea6,0x37537dfd,0xba9befe8,
    0x54df7f41,0x2affe21b,0x4efdc5fb,0x3ee2ffeb,0x42ffeb9d,0x1ba9befe,
    0x3fae77ee,0x2e77ee2f,0x11f92ffe,0x7c49f955,0x40efbabf,0xfda9adfd,
    0x5d5ffc43,0x5ffc40ef,0xfe80efba,0x743feeab,0x43feeabf,0x3feeabfe,
    0x3ff2b3fa,0x55ffc45f,0x3ff20efb,0xc80fe202,0x72f9cfff,0x84ffc81f,
    0x1effffc8,0x77fffe44,0x7fffe441,0x7fff441e,0xcfffc80c,0x7ffe42f9,
    0x7e442f9c,0x7e41efff,0x642f9cff,0x92f9cfff,0x09fff31f,0x019fffb1,
    0x5bffff91,0x33fff620,0x9fffb100,0x33ff6601,0x7fecc3f8,0x7ecc3f8c,
    0x3223f8cf,0x4fc8dfff,0x067ffec4,0x07ea0022,0x00000020,0x00620031,
    0x000800c4,0x20004001,0x20008018,0x08004000,0x00400000,0x00880020,
    0x02200110,0x00400040,0x0002dc00,0x00000000,0x00000000,0x00000000,
    0x00000000,0x00000000,0x00000000,0x00000000,0x00000000,0x00000000,
    0x00000000,0x00000000,0x00000000,0x00000000,0x00000000,0x00000000,
    0xfb51d500,0x007d903b,0x83d50be0,0x4eb801e9,0x98000f54,0x6f76541e,
    0x3209d12d,0x802f3a0e,0x980cefeb,0x2e03910c,0x6d403ded,0x02e883de,
    0x236e5c40,0x44eeeeee,0x401defec,0x76d403eb,0x10fd503d,0x803ec85b,
    0x2e4efedb,0x37f3ee3f,0x3fc80ffc,0x2e07d400,0x2017d41f,0x01fb84fb,
    0x7e45f500,0x3a2feccf,0x3a2fc40f,0xdfe82ffe,0x7e40ffdc,0xfd889f73,
    0xc80dfcac,0x20efecef,0x3ee003f9,0x777c6eef,0x66744eee,0x9f702ffd,
    0x33bee07f,0x3f7dc4fd,0x03fc8364,0x9b737bfa,0x87fee7ff,0x019503fa,
    0xb86ffdb8,0x1017d41f,0x007ee059,0x4f997d40,0x87f717d4,0x3fd302fa,
    0x0fee1fd4,0x76c0a851,0x3ea2f440,0x7f327dc4,0x8033ee00,0x6f98004f,
    0x81931c88,0x10fe44f9,0x01f98f91,0x0fee032a,0x17dc7f70,0xfd0002fc,
    0xfb8bff79,0x00017d41,0x2a0003f7,0xfa83f92f,0x1fb1be22,0x3f72fc40,
    0x98002fa8,0xf537931f,0x27e83f43,0x5f8803f9,0xd0004f80,0x07e4000d,
    0xd1f217e2,0x07ec0009,0x740fdc00,0x5d307aa6,0xfbfa97dc,0x5f507ee3,
    0x213bf6e0,0x1dfda9fb,0x2feeeda8,0xc85f50fd,0xd009f11f,0xd8877c4f,
    0x1f776c0f,0x3cefab64,0x6413e29d,0xea87f31f,0x3e007ea4,0x84f88004,
    0xbd03eeed,0x7c86fe88,0x776c03f2,0x004fc83e,0x26f81fb8,0xd1fcc1fb,
    0x2e5eae4d,0x6c17d41f,0x20efdbdf,0xffcdfcfb,0x3b33ff20,0x5f50dd2f,
    0x03f74f98,0xcffa89f0,0xfccc81fe,0xb0bd5d84,0x7dc0fe6b,0x2fd47f32,
    0x33bb2bf2,0x05e677c0,0x80deb988,0x9f04fccc,0x5c3f77d4,0x66405f35,
    0xefe884fc,0x307ee002,0x260fdcbf,0xb2f93e3f,0x3ea0fdcf,0x3ea17dc2,
    0xfa87fee4,0x2fa89f33,0xd05f70dd,0xeca81baf,0x4fffb81f,0xa7427c40,
    0x5f56c83f,0x9fccbea0,0xdffd85fa,0x3ba1ffcc,0xfe83fffe,0x3e200cff,
    0xbf94f884,0x2f401f91,0x3204f880,0xfb803fff,0x3f717dc1,0x553e3f98,
    0x1fdcf90f,0x06e85fd1,0x7c17dcdd,0x2fa83f95,0x17fcc3f9,0xf01fdfdc,
    0x5bf7017f,0x27c40bfd,0x5d84ea6c,0x4bea07f5,0xb05fabf9,0x205f981f,
    0x4cc40ff9,0x9f100efb,0xc8ffb7e0,0x4003f207,0x75c404f8,0xfb8baa6f,
    0x5c5fdaac,0xdd1fcc1f,0x3ee6e972,0x1dfdebbf,0xf73ec17e,0x21fadd03,
    0x95df32fa,0xff105fbf,0xa81fc01f,0x881fe44f,0x9f76c84f,0x1fcd3a57,
    0xfbf30fb8,0x7e83ec0b,0x2a017e40,0x209f103f,0x83ec1eff,0x405972f9,
    0x3f2004f8,0x7fdcfff3,0x1fb83eff,0xf3f91fcc,0xdfb93e65,0x7c7f94ff,
    0x0fdcfb05,0xfa86eb74,0x26bbfea2,0x80bf902f,0xf10f903f,0x2a13e20b,
    0xf15bb51f,0x3f41be25,0x203fd7f3,0x406e80fc,0x1fcc02fa,0x1fb04f88,
    0x557a0bf0,0x13e204ff,0x9f94f880,0x7d400fdc,0xfd11fcc1,0x5c1ff75f,
    0x06e8009f,0x7c0fdcdd,0x05f70fd5,0xfd817d41,0xfd804c01,0xf882fc40,
    0x1b60bd04,0x23fa85f9,0x81fe8bf9,0x027c43f9,0x3f9003f6,0x7d413e20,
    0x7dc17dc3,0x4409d7d0,0x8fea004f,0x4400fdc0,0x10ffa23f,0xb81bfffd,
    0x83f9001f,0x707ee3f9,0xf987f25f,0x417d402f,0x00a805fa,0xfd757df5,
    0x4c13e203,0x1fda9aef,0x7e567fcc,0xff89fcc6,0xea9bfe80,0xd755510f,
    0x55554c5f,0x13e204fd,0x5fcabfe8,0xd3f93f88,0x213e201b,0xefcaaacd,
    0x4007ee00,0x3feeabfe,0x3ee00bf8,0x57ff1001,0x6fdc1df7,0x3e65fc9a,
    0x02fcfcbf,0xfca997d4,0x037d400e,0x83dfffd5,0xaadfbaa8,0x6fffec41,
    0x9fffb100,0x77cc7f30,0x6fffe440,0x37fffe60,0x77fffd41,0xdfbaa882,
    0x7fec41aa,0x7ecdb04f,0x2aa23fff,0xfb1aadfb,0x8019ffff,0xfb3001fb,
    0xfa87f19f,0x000fdc00,0x819fffb1,0x83efffd9,0x2f8aeffa,0xefa97d40,
    0x00df3004,0xffffa806,0x00203fff,0x21fcc010,0x40100efa,0x04c40098,
    0x3ffffea0,0xb80203ff,0xfa89d00f,0x43ffffff,0x00000098,0x00000088,
    0x00001000,0x00000008,0x00000020,0x00000000,0x00000000,0x00000000,
    0x00000000,0x00000000,0x00000000,0x00000000,0x00b50000,0x6cc00baa,
    0xdb500eee,0x400f547b,0x00bcdeeb,0x13a60402,0x7edc0f5c,0x3ba600de,
    0xddd12eee,0x21dddddd,0x80acdeed,0x01cdeee9,0x47dddddd,0x22d887ea,
    0xb2d884fe,0x2e217209,0x6442deed,0x6dc0512d,0x75c01dee,0x41f776c4,
    0x1f2001ea,0x5402fec0,0xc81dcdff,0xf73fccdf,0xdddf9003,0x20dd07ff,
    0x220fec6e,0x66ff445f,0x3ff600ec,0x33d11ccd,0x21d33333,0x2ffeeeff,
    0x7ff777d4,0xfeeeee83,0xd90fdf74,0x3642fb98,0xd31f60bf,0xd8ddb9df,
    0x885fefcd,0x05edcefe,0x333213ee,0x001fb84f,0x0ecc01f2,0x26007f40,
    0xddf7044f,0x41f905bd,0x5fdc1fe8,0x443fbaba,0x3607e46f,0x33e2002f,
    0xbd95882f,0x4c5f86c3,0x88bea1fe,0xa7cc00ff,0x0fcc7c88,0x1f983fae,
    0xf13ec17e,0x2208303f,0x305fd02b,0xf100b220,0x9803f709,0xeeeeffee,
    0x02fc0002,0xbf700fd4,0xfc8dfd99,0x7ec2fc40,0xf705ffff,0x9f113e65,
    0x2fafb800,0x47ea2588,0xbf30bf0d,0x07f217d4,0x47c89f30,0x24fca84e,
    0x7d82fc4e,0x00000bf2,0x000007f7,0x07ee13e2,0x99fd9930,0x7776c399,
    0xb804f803,0x907ee01f,0x6c07e47f,0xbf72fc87,0xa86db740,0x4e7c002f,
    0x5b85882f,0x3ec17e1b,0x00fd85f5,0xc9f227cc,0xa7dcc40f,0xd82fc0fc,
    0x75401be7,0x6c0bfea8,0xdddb000f,0xb84f8807,0x00bfea9f,0xfccc80f9,
    0xdfbaa884,0x1fb82aaa,0x57e07ee0,0x320abfda,0x1fa2fc0f,0xa82fdfa8,
    0x27ea003f,0xb10aacf9,0x2fc36990,0x25f50fc8,0xf9804fb9,0x82f9adc4,
    0x2f98cee8,0x22fb05f8,0x8266624f,0x6fdcfcfb,0x99900374,0x84f8809f,
    0x6fccfdfb,0x3e200f90,0xfffff984,0x3fe27fff,0x2e3fffff,0xfff6f81f,
    0x10fe43ff,0x200fc89f,0x0bf105fd,0xfff9b6c0,0x776cb12f,0x6417e1b0,
    0xfffff51f,0x813e6007,0x417a005e,0x3e6fb05f,0xb9bffee3,0xf83f21ff,
    0x04f88005,0x7fdc27c4,0x1f203f21,0x7c027c40,0x55fed404,0x507ee0aa,
    0x067f669f,0x237c43f9,0xfdcc987d,0x07f41ccd,0x2f997c40,0x1b03a588,
    0xa8fe417e,0x002fdacf,0x03f209f3,0x5f807e40,0x88fe6fb0,0x0bee6eaa,
    0x0037c5f5,0x3e2027c4,0x7d42fb84,0xf1007c82,0x7009f009,0x88fdc03f,
    0x03f20feb,0x25fd03f6,0xeeea85f9,0x7d41eeef,0x640daadf,0x882fb99f,
    0x2fc360e5,0xe8bea7d8,0x84f9800f,0x02cc8af9,0xf8b2e5f3,0x13e2fd06,
    0x983f7374,0x2001fa3f,0x27c404f8,0x0fe60fdc,0x3e2003f2,0xb804f804,
    0x3ffee01f,0x07e41eff,0x3ff217e6,0x7d404fff,0x7ffec402,0x7ffffc0e,
    0x20a5882f,0xbf30bf0d,0x09f517d4,0x2bd07f50,0x5e80fddb,0x83749ff5,
    0x3a03fe5f,0x7f307ee6,0x220017ec,0x427c404f,0x41fcc1fb,0x4f8802fa,
    0xfb804f80,0x2b37ee01,0x7441f901,0x6567d41f,0x664c2fcb,0x101ccdfd,
    0x26bea09f,0x15882fb9,0x8bf0d85f,0x0bea1fe8,0x2fc801fd,0x07e607dc,
    0x93afa1f7,0x527d40fd,0x7dcdd09f,0xdf31fcc1,0x027c4001,0x07ee13e2,
    0x2fbe07f3,0x04f881aa,0x7ed404f8,0xf71aaaab,0xb99f9003,0x20dd07ff,
    0x7ee64c6e,0x3f501ccd,0x59f31b60,0xd8096235,0xffb99ff0,0x7d42fa85,
    0x3f6b3e63,0x3e61fc46,0x9fc9fc45,0x57df30de,0xefd81ff9,0x3ee6fbac,
    0x3f21fcc1,0x105dbacf,0x84f8809f,0x81fcc1fb,0x512fffda,0x0355bf75,
    0xfff8813e,0xf75fffff,0xdfff9003,0x00804039,0x2dc017d4,0x7fcc3f98,
    0xdddf14ff,0x3e1fdddd,0xa80cefff,0x3627e82f,0x36c0cfff,0x6d8277ea,
    0x98fffff6,0x700dfffe,0x5c7dfffd,0x541fcc1f,0x222dfffe,0x1aadfbaa,
    0x55bf7551,0x7f307ee3,0xfffa8100,0x9f03ffff,0x00000000,0x00000000,
    0x00000000,0x08000000,0xffd81f70,0x3a01f73f,0x13000204,0x3f983f70,
    0xfffa8040,0xff53ffff,0x2e7fffff,0x001fcc1f,0x00000000,0x00000000,
    0x00000000,0x00000000,0x00000000,0x00000000,0x00000000,0xb7000000,
    0x41ea85bd,0x3bbb24e9,0x3d94eeee,0x274d3a20,0x01d50ec8,0x200ec974,
    0xb907d94d,0x372201b2,0x41ed82de,0x3bbaa5e9,0x777542cd,0x540201bd,
    0x04ec805d,0x3bbbbbba,0xdddddd10,0x74c01ddd,0x5c826c1e,0x1ddddddb,
    0x3625c970,0x4eeeeeee,0xddddddd3,0xfdbcfe83,0xef887ee3,0x3bbbbb20,
    0x20bf35fe,0x50bf61fc,0xf007dc9f,0x7cc0bee7,0x2db0ffd3,0x6ff4c07d,
    0x27fc2ffc,0xcdfb9ff6,0x3bee5ffe,0xfd84feee,0x01bffa63,0x3e01fff1,
    0x10eeeeef,0xdddfdddd,0x0fff401d,0xffbf41ba,0xd80eeeee,0xdddb1765,
    0x3a6bfddd,0x21eeefee,0xb87ec1fc,0x4003fa1f,0x30bf61fe,0x746f88bf,
    0x4407ea0f,0x320bf32f,0xd87ffd0f,0x41900fb6,0x13f7c6f8,0x10fdcfdf,
    0xb07ee7fb,0xf77fe81f,0xfa80df5d,0x00bf03fc,0xf9002fa8,0xd06e83f9,
    0x4d8017ef,0x1fcc013a,0x86e817d4,0x323f73f9,0x87f7001f,0x407ec6f8,
    0xa85f73fb,0x745f101f,0x6ef4df07,0x007db6c6,0x7dfc1fb0,0x7dcf7f72,
    0x1fbafcc1,0x5fea17d4,0xfb01be38,0x002fc17e,0x3e600bea,0x83741fbb,
    0x9900bf7e,0x59df99df,0x5f507d80,0x53e21be0,0x003fa9fb,0x4bf20df1,
    0x2bfa04f9,0x511f985f,0x2fb87e61,0xf5bd1fcc,0x007db6c5,0x757c4fb0,
    0x2e1f79d5,0x3f76f81f,0x2fc40fc8,0x53e206f8,0x005f80fd,0xb74017d4,
    0xe83741fb,0xee880bf7,0x3eefeeef,0x7d40fe60,0xbf01fd02,0x8013efee,
    0x2df101fd,0x3fe600fd,0xf52f980f,0x4f987e65,0x3abd07e4,0x003edb66,
    0x75f12fc4,0x21f53f3f,0xba7d41fb,0x43fcaacf,0x0df01fd8,0x83fa8fd4,
    0x02aaaaef,0x3f700bea,0x55dd07ee,0x3befd555,0xf8809999,0xfb003f12,
    0xfa817d40,0x75febaae,0x2e001fff,0x7efdc03f,0x105fd803,0x7d57f65f,
    0xd1ba3f40,0xdb6cbeeb,0x21fd8007,0x56ef89f9,0x5cc7ee1f,0xffff70fe,
    0x0f7e43df,0x13ec0df0,0xfffff0bf,0x017d40ff,0x20fdc9f1,0xfffffffe,
    0xdffffff7,0x03e63f30,0x7d407f30,0x3bffaa02,0xdf7f73fb,0x200df100,
    0xff9806fe,0xbf17f01f,0xfb81f51f,0x25e87f31,0x01f6db6f,0x1f987f90,
    0x5c7ea7fb,0x21efffff,0xfea99afb,0x0df00112,0x81fb17e2,0x019999df,
    0x46d80bea,0x4cf741fb,0x5df7e999,0x1f305555,0x03f601ea,0x4c002fa8,
    0x9f53f72f,0x7001fd80,0xf3fd007f,0x23eafe0d,0x4f987bbf,0x2e5e81f7,
    0x00fb6d9f,0x8fcc27e4,0x2e3f50ea,0xfb80aacf,0x2002fc41,0x559f506f,
    0x05f85fb5,0xfa817d40,0xacfcaaac,0x7dfa0dd1,0x77f75c05,0xf306efee,
    0x002fa809,0x91fb87e4,0x00fea07f,0x7dc02fa8,0xb9f07f73,0x741efb69,
    0x44bd0dd7,0x00fb6ddf,0x0fd413f2,0x03f71f98,0xb7c41fb8,0x837c02f9,
    0xfffffffd,0x2a002fc5,0xffff902f,0x3a7fffff,0x017efd06,0xdb55fb53,
    0x003f6055,0x7dc005f5,0x1fe87ee3,0x2a0037c4,0xd1be602f,0x72fde81f,
    0x2fee0dbf,0x7e45e83f,0xf900fb6e,0x980fd407,0xb803f72f,0xfaa7dc1f,
    0x7c437c00,0xfe99999d,0xf50017e0,0x26666205,0xdd09bfb9,0x802fdfa0,
    0xf981726c,0x102fa804,0xb89fd995,0xd83fe21f,0x3cccccdf,0x7f405f50,
    0x3f62fd41,0x4c1bfe27,0x45e80fff,0x55fb6ff8,0x3fee3555,0xf73ccccc,
    0x7dcbe601,0x5d67dc01,0x10b70efe,0x799ff999,0x17dc0bea,0x155555df,
    0x7000bea0,0xfd06e83f,0xb2ec017e,0x8807ec09,0x0aacfcaa,0x2073bbe6,
    0xd2fd41fb,0xdfffffff,0x7dc0bea0,0x7ec5fb04,0xfd02fec4,0x3f617a0d,
    0xffffffb6,0x3fffff29,0x201f76ff,0x803f73f9,0x0beffffb,0xfffff980,
    0x201fb5ff,0x3fffe5f8,0x5f501fff,0x741fb800,0x017efd06,0x2609d26c,
    0x3ffea04f,0x0002ffff,0x00000000,0x00000000,0x00000000,0x00000000,
    0x00000000,0x00000000,0x00000000,0x00000000,0x00000000,0x00000000,
    0x00000000,0x00000000,0x4005f500,0x0000731b,0xb8dfec88,0x307aa1ee,
    0x700a205d,0x5019dfdb,0x6dc07dfb,0x7f540def,0xdfb703ef,0xfd51d509,
    0xbd72e817,0xeeeee985,0x107b20ee,0x3a035cbb,0x3b209d13,0x8877bb20,
    0xed8afc8e,0x216f6cc1,0x54000100,0x1f5c2ded,0x7e400bea,0x54009f94,
    0xf77d102f,0x2e1fb7ff,0xd81fcc1f,0x2f37a04f,0x56fe46fe,0x6ff446fc,
    0x37f20ecc,0xdfd83cbb,0x3ee0efdb,0x7c6fdcfc,0x22fecedc,0xffccccc8,
    0x3fb1be60,0x3f8807dc,0x4bf103fa,0x227eaac8,0xedceddcf,0x3fafbe66,
    0x1fa87f31,0x641f43f3,0x2e4e989e,0x2017d43f,0x6fdc3fd8,0x002fa800,
    0x5cbe67f7,0xc81fcc1f,0x8fe4003f,0xb17d43f9,0x805f805f,0x727d42fb,
    0xf07e43ff,0x5c04f8bf,0xf54fb82f,0x4511f987,0x50bee2f9,0x47ee205f,
    0x76fa8ff8,0xd97e3e4f,0xed8bf53f,0x47543f90,0x3ee5d5ef,0x9bfb999b,
    0x817f4419,0x7d400efa,0x7c3f3002,0x3f983f73,0x3ea00020,0x2bf01f92,
    0x1ef804f8,0x26e83740,0xf17d42fb,0x7cc0db0d,0x17ebf604,0xa97d4be2,
    0xfb17e20f,0x23fffd90,0x2e5f34f8,0x45e8db0f,0xf885fcfd,0x68ad9ba4,
    0x2beab51d,0xffffffff,0x3003be67,0x17d403fd,0xddfdb910,0x307ee9fd,
    0xb980007f,0x9fb2feed,0x2adf9999,0xeffa802f,0xfb05f80b,0x8fe60fdc,
    0x37c4004f,0x403ffa20,0x1eebfb3f,0x227c43f2,0x223f51fa,0x3ee3f33f,
    0xe84f8fb0,0x547ea06f,0x9df13d2f,0x554f4da6,0x52aacfca,0x3a2001df,
    0xfffff12f,0x3e21ffff,0xcccdfdcf,0x3f983f72,0xfffffff1,0x667f41ff,
    0x99fd2fdc,0x3ea79999,0xffd71003,0x4fb05f87,0xf1fcc1fb,0x00fe8009,
    0x33a06fe8,0x86c8fcf8,0xa83f73f9,0xf11feaaf,0x87dc7e67,0x41fdadfa,
    0xdb03fffa,0xe8ad87e4,0xfa80b569,0x2009f902,0x2aaa24fc,0x90aaacfc,
    0x540be61f,0xa89fcc1f,0xaaaaaaaa,0x2fa85f30,0x5f9803fb,0x20fe9800,
    0x7dcdd06e,0x09f1fcc1,0x64017e40,0x5bb04fcf,0x20bb7f1f,0xfb10dd6e,
    0x4fe21d3b,0x541f71f9,0x6fd41dfe,0x8fdc3fd8,0x5a36e3f9,0x7d403ead,
    0x4037ee02,0x7d403fd8,0x27dcf902,0x3fa23f88,0x81f90003,0x809f72fc,
    0xb8000ff8,0xf307f21f,0x3e60fdc7,0x7d4013e3,0xf94fa804,0x369bd905,
    0xf7f704ed,0x27f10005,0x001f71f9,0x23fb17e6,0x361ba4f9,0x500bb31d,
    0x0efa805f,0x54017f44,0xf77f502f,0x741739fd,0x03feeabf,0x37ee03b3,
    0x3a2ffeb9,0x21ba9bef,0x0daadffa,0xdf755591,0xfbabff88,0xf307ee0e,
    0x7c4027c7,0x21aaaaaf,0x20ff46f8,0x7ff51ffb,0x641ffe20,0xf14eeeee,
    0x87dc7e67,0x24eeeeec,0x05428703,0x003efeb8,0xfd300131,0x4007be63,
    0xdfb102fa,0x43fffb13,0x3f8cffd9,0x7e40bfb0,0x222f9cff,0x41effffc,
    0x10efffea,0x01bfffff,0x819fffb1,0xf1fcc1fb,0xffff5009,0x3fa27fff,
    0xf5077cc1,0x3602ff8f,0x9999704f,0x7ccfe279,0x332e1f71,0x00003ccc,
    0x2aa60000,0x201aaaaa,0x001b74d8,0x20200544,0x40022008,0x000801d9,
    0x10040062,0x00040033,0x00000000,0x00000000,0x00000000,0xb0000000,
    0xbfffffff,0x00000000,0x00000000,0x00000000,0x00000000,0x00000000,
    0x00000000,0x00000000,0x00000000,0x1d100000,0x87d70000,0x5c1cefe8,
    0x3b500dfe,0xb8b7b660,0x3ddddddd,0x82222222,0x985d73ea,0xec83910c,
    0x209d5002,0xa8819999,0x2a001000,0xaaaaaaaa,0x0222222a,0x00000000,
    0x00000000,0x7c420000,0x7ccd7010,0x889fff51,0x3e65fbac,0xddd06fcc,
    0x5fb7bf30,0x3333332e,0xfffffd3c,0x653ea7ff,0xfa97e42f,0x5403fc84,
    0x3fffe04f,0x317ffdc7,0x362fec3d,0x3ffffe3f,0xf57fffff,0x0005ffff,
    0x00000000,0x00000000,0xf779fc40,0x5e8a7cc1,0xd013e32a,0x2e07ec0d,
    0x236c3f8e,0x5554005e,0xf53fbaaa,0x8510bee7,0x2017300a,0x444402b8,
    0x3677e208,0x7fc1f73f,0x001ffe27,0x1bbbbb98,0x00000000,0x00000000,
    0x76cc0000,0x93742eef,0x2213e01f,0xdf101fee,0x41f72f88,0xaa9b6c5e,
    0x401aaaaa,0x2e7f33f8,0x0000001f,0x21f98000,0x7e45fffd,0x00027ec4,
    0x00000000,0x00000000,0x88000000,0x97d40efe,0x213e02f9,0x4c0efcc8,
    0x3a2e41fe,0x94f89b65,0x9fffffff,0x5d13f880,0x000003aa,0x40400000,
    0x004003ca,0x00000000,0x00000000,0x00000000,0x7dfdfe44,0x2f49f10c,
    0x2fb809f0,0x3f303bea,0xbdf31fa8,0x444441df,0x01500088,0x00000000,
    0x00000000,0x00000000,0x00000000,0x00000000,0x8bc36200,0x3f98fdc5,
    0x4b3bf326,0x70ffbaa8,0x265999ff,0x65c45702,0x00000003,0x00000000,
    0x00000000,0x00000000,0x00000000,0x00000000,0xe803e200,0x77547f26,
    0xdff33eee,0x77775c3b,0x0000003e,0x00000000,0x00000000,0x00000000,
    0x00000000,0x00000000,0x20000000,0x50a600a8,0x00000000,0x00000000,
    0x00000000,0x00000000,0x00000000,0x00000000,0x00000000,0x00000000,
    0x00000000,0x00000000,0x00000000,0x00000000,0x00000000,0x00000000,
    0x00000000,
};

static signed short stb__consolas_20_latin1_x[224]={ 0,4,2,0,1,0,0,4,2,2,1,0,2,2,
3,1,0,1,1,1,0,1,1,1,1,0,4,2,1,1,2,2,0,0,1,0,1,1,2,0,1,1,1,1,
2,0,1,0,1,0,1,1,0,1,0,0,0,0,1,3,1,2,1,0,0,1,1,1,1,1,0,0,1,1,
1,1,1,0,1,0,1,1,1,1,0,1,0,0,0,0,1,1,4,2,0,0,0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,4,1,0,0,0,
4,1,0,0,2,1,1,2,1,0,2,1,2,2,0,1,1,3,4,2,2,1,0,0,0,1,0,0,0,0,
0,0,-1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,1,1,0,0,
0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,
 };
static signed short stb__consolas_20_latin1_y[224]={ 14,0,0,1,-1,0,0,0,-1,-1,0,3,10,7,
10,0,1,1,1,1,1,1,1,1,1,1,4,4,3,6,3,0,0,1,1,1,1,1,1,1,1,1,1,1,
1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,-1,0,-1,1,16,0,4,0,4,0,4,0,4,0,0,
0,0,0,4,4,4,4,4,4,4,1,4,4,4,4,4,4,-1,-2,-1,6,1,1,1,1,1,1,1,1,1,
1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,14,4,-1,1,1,1,
-2,0,0,1,1,4,7,7,0,0,0,2,0,0,0,4,0,6,14,0,1,4,0,0,0,4,-3,-3,-3,-3,
-3,-3,1,1,-3,-3,-3,-3,-3,-3,-3,-3,1,-3,-3,-3,-3,-3,-3,4,-1,-3,-3,-3,-3,-3,1,0,0,0,
0,0,0,-1,4,4,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,3,2,0,0,0,0,0,0,0,
 };
static unsigned short stb__consolas_20_latin1_w[224]={ 0,3,7,11,9,11,11,3,7,7,9,11,6,7,
5,9,11,9,9,9,11,9,9,9,9,10,4,6,8,9,8,8,11,11,9,10,10,9,8,10,9,9,8,10,
8,11,9,11,9,11,10,9,11,9,11,11,11,11,9,6,9,6,9,11,7,9,9,9,9,9,11,11,9,9,
8,10,9,11,9,11,9,9,10,9,10,9,11,11,11,11,9,8,3,8,11,11,11,11,11,11,11,11,11,11,
11,11,11,11,11,11,11,11,11,11,11,11,11,11,11,11,11,11,11,11,11,11,11,11,0,3,8,10,11,11,
3,9,9,11,7,9,9,7,9,9,7,9,7,7,10,10,9,5,3,7,7,9,11,11,11,8,11,11,11,11,
11,11,12,10,10,10,10,10,10,10,10,10,11,10,11,11,11,11,11,9,11,10,10,10,10,11,9,9,10,10,
10,10,10,10,11,9,10,10,10,10,10,10,10,10,10,10,11,11,11,11,11,11,11,10,10,10,10,11,9,11,
 };
static unsigned short stb__consolas_20_latin1_h[224]={ 0,15,5,13,18,15,15,5,20,20,9,11,8,3,
5,17,14,13,13,14,13,14,14,13,14,13,11,14,12,6,12,15,19,13,13,14,13,13,13,14,13,13,14,13,
13,13,13,14,13,17,13,14,13,14,13,13,13,13,13,20,17,20,7,3,5,11,15,11,15,11,14,15,14,14,
19,14,14,10,10,11,15,15,10,11,14,11,10,10,10,15,10,20,21,20,5,13,13,13,13,13,13,13,13,13,
13,13,13,13,13,13,13,13,13,13,13,13,13,13,13,13,13,13,13,13,13,13,13,13,0,15,18,13,13,13,
21,17,5,14,10,9,6,3,9,5,7,12,8,8,5,15,17,5,3,8,10,9,14,14,14,15,17,17,17,17,
17,17,13,16,17,17,17,17,17,17,17,17,13,17,18,18,18,18,18,9,18,18,18,18,18,17,13,15,15,15,
15,15,15,16,11,13,15,15,15,15,14,14,14,14,15,14,15,15,15,15,15,11,15,15,15,15,15,19,19,19,
 };
static unsigned short stb__consolas_20_latin1_s[224]={ 247,251,111,76,169,23,225,252,40,18,29,
29,249,194,176,23,205,1,207,184,45,174,164,88,108,108,250,249,11,91,20,
99,100,11,239,66,233,23,67,44,57,98,1,119,198,217,188,141,229,157,244,
240,33,34,176,164,152,140,130,33,90,26,73,182,129,75,57,95,67,85,129,
156,98,119,91,153,88,202,127,115,1,77,137,105,108,53,182,170,158,87,148,
9,1,48,158,221,221,221,221,221,221,221,221,221,221,221,221,221,221,221,221,
221,221,221,221,221,221,221,221,221,221,221,221,221,221,221,221,221,247,247,112,
141,174,186,5,180,119,129,194,39,101,194,242,148,83,1,65,57,137,34,13,
170,249,49,214,232,217,10,22,247,1,123,202,45,190,33,208,1,57,68,79,
112,225,135,146,169,162,214,121,133,145,157,235,222,179,191,202,213,224,100,152,
134,79,90,112,123,12,236,41,198,57,101,46,35,229,77,194,118,68,55,168,
45,180,237,144,63,22,11,214,203,192,57,81,69, };
static unsigned short stb__consolas_20_latin1_t[224]={ 17,23,115,89,1,41,41,103,1,1,115,
103,88,115,115,23,58,89,88,58,89,58,58,89,58,88,58,41,103,115,103,
58,1,89,88,74,73,89,89,74,89,89,74,88,88,88,88,58,88,23,73,
58,89,74,88,88,88,88,88,1,23,1,115,115,115,103,58,103,58,103,73,
41,74,73,1,58,74,103,103,103,58,58,103,103,73,103,103,103,103,58,103,
1,1,1,115,73,73,73,73,73,73,73,73,73,73,73,73,73,73,73,73,
73,73,73,73,73,73,73,73,73,73,73,73,73,73,73,73,73,17,23,1,
73,73,73,1,23,115,58,103,115,115,115,103,115,115,103,115,115,115,58,23,
115,97,115,103,103,58,74,74,1,23,23,23,23,23,23,73,41,23,23,23,
23,23,23,23,23,73,23,1,1,1,1,1,103,1,1,1,1,1,23,73,
41,41,41,41,41,41,23,103,73,41,41,41,41,58,74,58,58,41,74,41,
58,41,41,41,103,58,58,41,41,41,1,1,1, };
static unsigned short stb__consolas_20_latin1_a[224]={ 176,176,176,176,176,176,176,176,
176,176,176,176,176,176,176,176,176,176,176,176,176,176,176,176,
176,176,176,176,176,176,176,176,176,176,176,176,176,176,176,176,
176,176,176,176,176,176,176,176,176,176,176,176,176,176,176,176,
176,176,176,176,176,176,176,176,176,176,176,176,176,176,176,176,
176,176,176,176,176,176,176,176,176,176,176,176,176,176,176,176,
176,176,176,176,176,176,176,176,176,176,176,176,176,176,176,176,
176,176,176,176,176,176,176,176,176,176,176,176,176,176,176,176,
176,176,176,176,176,176,176,176,176,176,176,176,176,176,176,176,
176,176,176,176,176,176,176,176,176,176,176,176,176,176,176,176,
176,176,176,176,176,176,176,176,176,176,176,176,176,176,176,176,
176,176,176,176,176,176,176,176,176,176,176,176,176,176,176,176,
176,176,176,176,176,176,176,176,176,176,176,176,176,176,176,176,
176,176,176,176,176,176,176,176,176,176,176,176,176,176,176,176,
176,176,176,176,176,176,176,176, };

// Call this function with
//    font: NULL or array length
//    data: NULL or specified size
//    height: STB_FONT_consolas_20_latin1_BITMAP_HEIGHT or STB_FONT_consolas_20_latin1_BITMAP_HEIGHT_POW2
//    return value: spacing between lines
static void stb_font_consolas_20_latin1(stb_fontchar font[STB_FONT_consolas_20_latin1_NUM_CHARS],
                unsigned char data[STB_FONT_consolas_20_latin1_BITMAP_HEIGHT][STB_FONT_consolas_20_latin1_BITMAP_WIDTH],
                int height)
{
    int i,j;
    if (data != 0) {
        unsigned int *bits = stb__consolas_20_latin1_pixels;
        unsigned int bitpack = *bits++, numbits = 32;
        for (i=0; i < STB_FONT_consolas_20_latin1_BITMAP_WIDTH*height; ++i)
            data[0][i] = 0;  // zero entire bitmap
        for (j=1; j < STB_FONT_consolas_20_latin1_BITMAP_HEIGHT-1; ++j) {
            for (i=1; i < STB_FONT_consolas_20_latin1_BITMAP_WIDTH-1; ++i) {
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
        float recip_width = 1.0f / STB_FONT_consolas_20_latin1_BITMAP_WIDTH;
        float recip_height = 1.0f / height;
        for (i=0; i < STB_FONT_consolas_20_latin1_NUM_CHARS; ++i) {
            // pad characters so they bilerp from empty space around each character
            font[i].s0 = (stb__consolas_20_latin1_s[i]) * recip_width;
            font[i].t0 = (stb__consolas_20_latin1_t[i]) * recip_height;
            font[i].s1 = (stb__consolas_20_latin1_s[i] + stb__consolas_20_latin1_w[i]) * recip_width;
            font[i].t1 = (stb__consolas_20_latin1_t[i] + stb__consolas_20_latin1_h[i]) * recip_height;
            font[i].x0 = stb__consolas_20_latin1_x[i];
            font[i].y0 = stb__consolas_20_latin1_y[i];
            font[i].x1 = stb__consolas_20_latin1_x[i] + stb__consolas_20_latin1_w[i];
            font[i].y1 = stb__consolas_20_latin1_y[i] + stb__consolas_20_latin1_h[i];
            font[i].advance_int = (stb__consolas_20_latin1_a[i]+8)>>4;
            font[i].s0f = (stb__consolas_20_latin1_s[i] - 0.5f) * recip_width;
            font[i].t0f = (stb__consolas_20_latin1_t[i] - 0.5f) * recip_height;
            font[i].s1f = (stb__consolas_20_latin1_s[i] + stb__consolas_20_latin1_w[i] + 0.5f) * recip_width;
            font[i].t1f = (stb__consolas_20_latin1_t[i] + stb__consolas_20_latin1_h[i] + 0.5f) * recip_height;
            font[i].x0f = stb__consolas_20_latin1_x[i] - 0.5f;
            font[i].y0f = stb__consolas_20_latin1_y[i] - 0.5f;
            font[i].x1f = stb__consolas_20_latin1_x[i] + stb__consolas_20_latin1_w[i] + 0.5f;
            font[i].y1f = stb__consolas_20_latin1_y[i] + stb__consolas_20_latin1_h[i] + 0.5f;
            font[i].advance = stb__consolas_20_latin1_a[i]/16.0f;
        }
    }
}

#ifndef STB_SOMEFONT_CREATE
#define STB_SOMEFONT_CREATE              stb_font_consolas_20_latin1
#define STB_SOMEFONT_BITMAP_WIDTH        STB_FONT_consolas_20_latin1_BITMAP_WIDTH
#define STB_SOMEFONT_BITMAP_HEIGHT       STB_FONT_consolas_20_latin1_BITMAP_HEIGHT
#define STB_SOMEFONT_BITMAP_HEIGHT_POW2  STB_FONT_consolas_20_latin1_BITMAP_HEIGHT_POW2
#define STB_SOMEFONT_FIRST_CHAR          STB_FONT_consolas_20_latin1_FIRST_CHAR
#define STB_SOMEFONT_NUM_CHARS           STB_FONT_consolas_20_latin1_NUM_CHARS
#define STB_SOMEFONT_LINE_SPACING        STB_FONT_consolas_20_latin1_LINE_SPACING
#endif
