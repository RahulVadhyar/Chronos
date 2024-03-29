// Font generated by stb_font_inl_generator.c (4/1 bpp)
//
// Following instructions show how to use the only included font, whatever it is, in
// a generic way so you can replace it with any other font by changing the include.
// To use multiple fonts, replace STB_SOMEFONT_* below with STB_FONT_consolas_19_usascii_*,
// and separately install each font. Note that the CREATE function call has a
// totally different name; it's just 'stb_font_consolas_19_usascii'.
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

#define STB_FONT_consolas_19_usascii_BITMAP_WIDTH         128
#define STB_FONT_consolas_19_usascii_BITMAP_HEIGHT        108
#define STB_FONT_consolas_19_usascii_BITMAP_HEIGHT_POW2   128

#define STB_FONT_consolas_19_usascii_FIRST_CHAR            32
#define STB_FONT_consolas_19_usascii_NUM_CHARS             95

#define STB_FONT_consolas_19_usascii_LINE_SPACING          12

static unsigned int stb__consolas_19_usascii_pixels[]={
    0x38806a31,0x53002200,0xa8804401,0x55550aaa,0x4b80a605,0x88001880,
    0x00000311,0xefdbdc44,0x9802fa82,0x3ffd106f,0x83dffd30,0xfb1feee9,
    0x0bf109dd,0xffd3026c,0x9af400bf,0x6ffc401f,0x4f7db001,0x01f906d8,
    0x5f907fa8,0x7dc4fea0,0x1763f301,0xfd981fd0,0x77cc2fff,0x9806fc9a,
    0x51017a1f,0xdb005ff7,0xd00fa8f7,0x3a01300d,0x9b05f105,0x02ec7e60,
    0xbef985f9,0x07ec1bcf,0x8d9007ee,0x3fa000fa,0x23df6c00,0x49f302f8,
    0x02aaaaa8,0x5417209d,0x1763f307,0x47ec27c4,0x84f881f8,0x0fe204f8,
    0x3fa800fe,0x7bedaa98,0x4db017c4,0x05fffffa,0x265f109d,0x980f8bbb,
    0x3ee0bb1f,0x0f98fd81,0x0bd02f98,0x03e407dc,0x7f4c5f30,0x447befff,
    0x803f202f,0xf507f05e,0x0fdbf7e6,0xd05d8fcc,0x1f3bea0f,0x06e80fd4,
    0x017c413a,0xdf89f666,0x3a1efb61,0x403f500e,0xc81fa85e,0x0fd369d5,
    0xf05d8fcc,0x1fffdc0b,0x06e80fdc,0x036c03f5,0x7e45bff3,0x443df6c1,
    0x03f887fd,0x01ffb97a,0x4fe5f19b,0xbb1f981f,0xfb009f10,0x817d43df,
    0xa80bb05f,0xd05f301f,0x70f7db0d,0x09f1057f,0x1db532f4,0xf11f37d0,
    0x3f301f15,0x00fe2176,0xf89fe736,0xf883f984,0xf304e802,0x7db0bf03,
    0x7cc07f0f,0x1fc17a03,0x7cc7d5f4,0x23f30799,0xd00bd05d,0x0fe87ee7,
    0x036407ec,0x0a880fb8,0x7bed86e8,0x5f7017c4,0x84e82f40,0x8fc8f9be,
    0x363f305c,0x5f00f905,0xbef983f6,0x07f03fda,0x80c0fe20,0x3df7dc7d,
    0x07d80be2,0xd84e82f4,0x1fdbbdf3,0x82ec7e60,0xfbce81fb,0xfea84fec,
    0x01f702ef,0x27e43640,0x6fe577d4,0x817c47be,0x82f404f8,0x44a5c84e,
    0x6c7e600a,0xd909f305,0xc805bdff,0x0013a00f,0x03fb85f3,0x7d73dff7,
    0xfd02f98f,0xbd05f801,0x26000f50,0x7dc0bb1f,0x4c00f501,0x3e6399df,
    0x085e8001,0x5c7b8080,0x403fb81f,0x20f703fa,0x1f98004f,0x80fd80bb,
    0x7fdc005c,0x000db0ef,0x400003ea,0x30bfb57b,0xfb79b09f,0x0677c40d,
    0x0b755bf5,0x363f9551,0x5f882aae,0x98800088,0x2a000001,0x2005eeee,
    0x2207bb7b,0x07ddb504,0xc983b710,0xee981cee,0x9ddd91ee,0x00000a60,
    0xb5000000,0x5c00bbbb,0x00000007,0x00000000,0x00000000,0x80000000,
    0x0000005a,0x00000000,0x00000000,0x00000000,0x00000000,0x00000000,
    0x00000000,0x00000000,0x180440c4,0x4ccc0062,0x02000601,0x51298040,
    0x55544015,0x208801aa,0x223501a8,0xfb053001,0x3227fec1,0xf1003ee6,
    0x3f303fff,0x74036c00,0xff9fb81f,0xeefb82ff,0xd7104fff,0x217e2bff,
    0x801f73f9,0x87ec3ff8,0xf50fa8fb,0x4c007dc3,0x1f981fb9,0x3a01ba00,
    0x13ffb82f,0x2a3f98dd,0x26ff203f,0xf903f219,0xf1003ee1,0xb90fd87f,
    0x713a27e2,0x0fd4001f,0x2a200fcc,0x82aaaeea,0xb85f7018,0xbf03ee1f,
    0x7f302740,0x003ee5f8,0x5c3f60a2,0x86c8f98f,0x00aa88fb,0x07e607ea,
    0x3ffea353,0x2aa7ffff,0x40fb80aa,0x887ee2f9,0x805f304f,0xfb8bea6e,
    0x64001a88,0x26fffa27,0xff9fb81f,0x03f502ff,0x82fd43f3,0xffff106e,
    0xf981f703,0x3aabbe22,0x805f300f,0xfb8fb1fb,0x000efffa,0x13a130f9,
    0x6e89ffdc,0x3f303f50,0x06e817ea,0x0fb81fa8,0xdbf50fdc,0xfff981bd,
    0x443fffff,0x7dc4f8cf,0x2007f32f,0x403b207c,0x40fdc2fb,0x99f981fa,
    0x4037405f,0x40fb81fa,0x44036c7e,0xaaacfcaa,0x41fbfd80,0x3636c2fb,
    0xf983e41e,0x07dc1a8a,0x07ea0be6,0x2017f3e6,0x81fa806e,0x2fea9bfb,
    0x56666fe4,0x3005f300,0x81f70dff,0x322ffc7c,0xfdf39d07,0x3e607dc7,
    0xf981fa82,0x06e805fc,0xffb81fa8,0xef881eff,0x980fffee,0x05fd002f,
    0x5c7c81f7,0x7dc14c5f,0x7dcf75d8,0x7d40fd40,0x4fa9f981,0x2a007e40,
    0x800fb81f,0x984fa86e,0x20dd002f,0x263e40fb,0x3e20443f,0xfb9e67d2,
    0x1fa836c0,0x09f71f98,0x414d6fcc,0x00fb81fa,0x83f985f8,0x2fc802f9,
    0x17c81f70,0x1fe81dd3,0x6c8ed97a,0x3f266fee,0x33f2aa22,0xfc87e62a,
    0x5fff6e03,0x2acfcaa8,0x3f6003ee,0x80efcabd,0xfd9302f9,0x3207dc09,
    0xfd019f97,0xfe883ee3,0x3fff661e,0x7fffd41e,0xb07e67ff,0x7d40805f,
    0x2a7fffff,0xddb7000e,0x817cc07b,0x7dc02dea,0x0800be40,0x00000100,
    0x00000000,0x00000000,0x00000000,0x00000000,0x00000000,0x00000000,
    0x40000000,0x31029aa9,0x02deb880,0x19980310,0x26666660,0x33008800,
    0x02601301,0x22002662,0x01988009,0x8dffffd3,0xd05fffe9,0x4407fd9f,
    0x7c44fffe,0x7c43ffff,0x882fffff,0x7d44ffec,0x13e0efff,0xffea8fe6,
    0xfff703ff,0xfff701df,0x0efc43ff,0x4d77ccdb,0xf17cc6fb,0x227be20b,
    0x266e24fb,0x2fe21fea,0x7cc09999,0x3e609acf,0x3e6fa89d,0xbf33f984,
    0xf9035335,0xd839535b,0x21ca9adf,0xfb36c0fc,0x3ea1fb81,0x07dc17a2,
    0x3fa803f6,0x3ba00be2,0xfb03f200,0xd9fcc27c,0x04f9800f,0x6e803fb8,
    0x109f16d8,0xfcafc49f,0xfd88bd02,0xf887e602,0x200fd402,0x9f2f42fa,
    0x03f67f30,0x3e003f60,0xdb0bf006,0x22f40be6,0x3e02fefc,0x40fffa64,
    0x567c46d8,0x2aa6f901,0x6cdff440,0x3e613e1f,0xe805df53,0x003f8805,
    0x3eadb0bd,0xffc8dd01,0x73f886a2,0xff89f1df,0x7ffc40ef,0x7ffec4ff,
    0xffd82ffe,0x7cc27c1f,0x40fbfea3,0x22f9804f,0x1f61eeec,0x407eadf7,
    0x3febf66e,0x2fe22f98,0x5513e4fd,0x2a203fd9,0x88bfa4fd,0x37bea0fd,
    0x2613e1ef,0x1efeb83f,0x3ea013e2,0xa8bf72a2,0x36efc9df,0x7cd7e05f,
    0x83f5df33,0x0fe22fff,0x6f880dd0,0x54be61b6,0x4f9be64f,0x3ea03f98,
    0x7cc02fc6,0x7dc2f983,0x9f16c9ef,0x87ea7f30,0x0fe87ffb,0x1f200fd4,
    0x987c9f60,0x3f70f92f,0x00bea17e,0x007f41f9,0x817cc37c,0x40fd9b60,
    0xd87f50fd,0x6c1fb85f,0x4406e806,0xf707ee5f,0x47ee1fa3,0x400fc87d,
    0x013ea0fc,0x05f30bf2,0x5f7ccdb0,0x3fa23fda,0x41fffdab,0x2fd9aef8,
    0x3fae66a6,0x3ae66a21,0x5cd77c0e,0x2677ee5f,0x2b7ea6fb,0x2af64fda,
    0xfd84fcaa,0x221dbabe,0x2fcaadfe,0x7f4c6d80,0xffd882ef,0x440ff9cf,
    0x7dc2effd,0x7d41dfff,0xd880cfff,0xffb83fff,0x7f540cff,0x7fff43ff,
    0x3fae03ef,0xfec80def,0x5c801dff,0x00040020,0x80131004,0x00200098,
    0x20040022,0x00080018,0x00000031,0x00000000,0x00000000,0x00000000,
    0x33333000,0x83100c43,0x99999999,0x33333310,0x300ccc43,0x9884c403,
    0x40262019,0x04c06209,0x22131033,0x4c40c400,0xffffff10,0x27b81ee1,
    0xfffffff9,0xfffffb4f,0x3ffea3ff,0x817e43ff,0xffff70fd,0xa86f887f,
    0xf10ffa3f,0x3fa0ffc5,0x0fc80dd3,0xaaa83ba2,0x40f70fda,0x7ecccc7b,
    0x55550999,0x3ea1ff55,0x222feb9a,0x2e3f986f,0x45fdb99f,0xd1ba22fb,
    0x3e2f88ff,0x74ffe64f,0xfb07e406,0xf50fb803,0x7c81b201,0xfa8bee00,
    0x5f717e21,0x207dc6e8,0xc87f40fd,0x11fef41f,0xc9f7e25f,0xc80dd3fd,
    0x7005f70f,0x6403ea1f,0x4401f205,0x3e0fd45f,0x0bea6e85,0x42fa81f7,
    0xe84f9cf9,0x44be26dc,0x9d5f1faf,0x31f901ba,0x43ee007f,0x2ecf71f9,
    0x3f600f90,0x7f70fd40,0x21ba7f50,0x40fe40fb,0xce80eefc,0x225f12f9,
    0x9d7acd9f,0xf3f901ba,0x987dc009,0x1363fd1f,0x2fb807c8,0x4feeefa8,
    0x207effa0,0x41be60fb,0x29d02ff8,0x3e65f16e,0x29d4dfa9,0x377e406e,
    0x7c43ee00,0x09d4ef8a,0x17e203e4,0x02fe6fd4,0x7dc17fe6,0x300effee,
    0x553a0bff,0x1f32f8af,0x6eaf47fe,0x017e7e40,0x5d7c1f70,0x6407d7bd,
    0xa807ec07,0xd807f51f,0x799f700f,0x2fcee805,0x3e37a4e8,0xd9b21f52,
    0x8fc80dd5,0x1f9001fd,0x57c5f5fc,0xb81f203e,0xd87ea02f,0xb81f200f,
    0x25f7000f,0x3ee4e86e,0x201f52fa,0xfc80dd5d,0xe800ef88,0xde87e7c7,
    0x441f202f,0x30fd405f,0x703e407f,0x4bf3001f,0x3e2744fa,0x201f52fe,
    0xfc80dd6d,0xbd98bf30,0x37f43fdb,0x3e405ff7,0xccccdfd8,0xfe83f51c,
    0x7dc0f900,0x6c0fe800,0xff713a1f,0xb6c03ee5,0x22aaaaee,0x88fee0fc,
    0xfd83fffe,0xc807fe23,0xffffff07,0x507ea5ff,0xb81f207f,0x41fdc00f,
    0xf113a6f8,0x6c81ee5f,0x1ffffffd,0x03fb03f2,0x00000001,0x00000000,
    0x00000000,0x00000000,0x00000000,0x00000000,0x00000000,0x30000000,
    0x9884c401,0x13099999,0x04c40260,0x13333330,0x84cccccc,0x98800199,
    0x800ccc40,0x00130018,0x7ec22033,0x3ea3f700,0x9f6fffff,0xff105f30,
    0x3fffe209,0xffff15ff,0x3fffebff,0x6fe801df,0x1effffdc,0x817fffdc,
    0x3ea03fea,0x4fec3fff,0x44dd02fa,0xf099fd99,0xf505f309,0x277e20dd,
    0x39f10999,0x277e1333,0x2e02feba,0x4cfdc6ef,0x2fea2fca,0x3a61fe99,
    0x9f503fef,0x7ec5f911,0x3f885f88,0x309f0f90,0x3f7db05f,0x7c409f10,
    0x3fa13e03,0x46dbf880,0x023740fb,0x4d75c9f3,0xdd0dd03f,0x40fd87e4,
    0xf0f900fb,0xf885f309,0x4f884f8b,0x4f80fe20,0xb6d83fa8,0x3740fb8d,
    0x7cc13e20,0x1f709f03,0x742fa9f2,0x13e1f206,0x23f50be6,0x204f886e,
    0x213e03f8,0xd8fd44f8,0x5f707dc6,0xf303f980,0x3ee17e07,0x12fc4311,
    0x7c3e407f,0x2fffffff,0x883f736c,0x12eeeeff,0x29ffffff,0x7c4bf04f,
    0xfff71b64,0x1fb007ff,0x7e40fe60,0xd807f662,0x7c803ee7,0xbaaaaef8,
    0xf993e22f,0x66677c43,0x555bf11c,0x2fc13e35,0x7dc6d8d9,0x204fdbab,
    0x0fe602fc,0x77fffec4,0x6cbea00f,0x27c3e406,0x37f517cc,0x4f88df33,
    0x4f80fe20,0x37f54f88,0x2e33dd33,0x640fe40f,0x01fcc03f,0x01ee26a2,
    0x807f19f1,0xf984f87c,0x3fffff62,0x813e21ff,0x213e03f8,0xffff92fb,
    0x3eefffff,0x3f217d40,0x003f9803,0x5fec02f4,0x7c3e400f,0xbf12f984,
    0x47f75555,0x0fe204f8,0x337cc4f8,0x5fd55555,0x1fb03ee5,0xf9801fe4,
    0x003f2003,0x5441bfea,0x9f2aafda,0x07ea5f30,0x409f1374,0x1aaaadf8,
    0x1dfb75bf,0xbfb8db00,0x3ee4feba,0x31ccccce,0x199dfb99,0x17fe5d44,
    0x503ff880,0x2dffffff,0xfb2f984f,0x4f887e40,0x3ffffe20,0x7bffff5f,
    0xf71b6001,0xfc85bdff,0x52ffffff,0x3fffffff,0x005ef7d4,0x00000000,
    0x00000000,0x00000000,0x80000000,0x19999998,0x0004c110,0x2aa20200,
    0xa8814c2a,0x1aa880aa,0x44298298,0x2aa601a9,0x41a894c2,0x80545328,
    0xfffffffe,0x207e4d81,0x7d4000dd,0x3ffbfea1,0xfc87ff11,0x7fdc5fff,
    0x03ee1eff,0x7f7fccf9,0x7ffffc0e,0xfff5f70e,0x3febe23d,0xaa81ffdb,
    0x80fdaaaa,0xf303f13e,0x13f2001d,0x3fe208bf,0x0c42ff23,0x9be619f3,
    0xf8be40fb,0x41517e24,0x25ff75fa,0x91df14f9,0xe800febd,0x03e65f05,
    0x3600ff44,0x2027c42f,0xd013e228,0x3ee5f50d,0x40fcbe40,0xbb7400fb,
    0x4f8b6c2f,0x4013a3f7,0x3ffe21fa,0x207fffff,0x1fe883fd,0x0017bfb0,
    0x84f803f5,0xc81f73f8,0x95555db7,0xdd55303f,0x22f903ee,0x0274f72f,
    0xafa985e8,0x64019ec9,0x003be64f,0xb809ffd7,0x20fe201f,0xc81f73f8,
    0xdddddfd7,0x7777e43d,0x7c81f76f,0x4e9ee5f1,0xf301fa80,0x3fc802e4,
    0x4c007fa2,0x0fea04fc,0x25f309f0,0x7dbe40fb,0xb6c2f980,0xf8be40fb,
    0x40274f72,0x5c9ea06e,0x4417ec40,0x9ba002fd,0x80df10ca,0x987e40fd,
    0x7e5fe61f,0x3a23ec02,0x17c81f76,0x04e9ee5f,0x765417d4,0x82ceeccf,
    0x7e401ee9,0x64cd5c43,0x649ff14f,0x263b9bef,0x44fc9aef,0x17efaaef,
    0x453339ff,0x6ffb9bfc,0xf17c81f7,0x404e9ee5,0x9dd9506e,0xfa859bf9,
    0x4bf7000e,0x43fffff9,0x7ff5c2fe,0x77ff4c3f,0xbaffea83,0x3ffff627,
    0x2bbff625,0x7c81f76b,0x4e9ee5f1,0x9b00bea0,0x005d817c,0x04c41ea8,
    0x08008010,0x01100080,0x00000008,0x93a01ba0,0x0000001f,0x00000000,
    0x70000000,0x77777777,0x3ea00037,0x3f13e803,0x00000000,0x00000000,
    0x3ba00000,0xeeeeeeee,0x00000002,0x00000000,0x00000000,0x00000000,
    0x812a0000,0xa881510a,0x541aaaaa,0x0531a882,0x2035114c,0x3a00881a,
    0x1100880e,0x55553044,0x20110555,0x414c4fe9,0xf95f107c,0x7ffd49ff,
    0x1fe45fff,0x903dc3f6,0x7cc2fc4f,0xff106a83,0xf703fd07,0xfffd9fe5,
    0x7dc0ffff,0x0dfcef83,0x220f90bb,0x01f90eef,0x87f40fe4,0x403ea2fb,
    0x3207e46d,0x29ad4a0f,0x37aa27e4,0x0fd2fb85,0x263f9800,0x5fddf31f,
    0x3be20f90,0x7d40be60,0x9f1bf103,0x6cf71f98,0x93e1fcc5,0x4fbdade9,
    0x22ba17d4,0x6e8fd42f,0x22222222,0x41882200,0xddd12dc8,0x227dddff,
    0xf880983f,0x437fd405,0x3a3fd2f8,0x07ea6e84,0xa8833fea,0x1f735c6e,
    0x366d8fd4,0x0fffffff,0x66440000,0x12cccfec,0x0774007f,0xbf81ff40,
    0x705f4df8,0x3661b63f,0x33f63eee,0x49d07e20,0x99986618,0x40019999,
    0x1f2001ed,0xfc801fc4,0x0fefc801,0x8fadbce8,0xf8cf881f,0x46cd7cc3,
    0x212e015d,0x000000da,0x0027fd40,0x00fe20f9,0x3ea00fea,0xedd86f8b,
    0xb00fcf8a,0x2a101f7f,0x00000026,0xff100000,0x883e4005,0x577cc03f,
    0x2fcc2aaa,0x0ffb8bf5,0x7fd40ffb,0x0002d405,0x00000000,0x40a60004,
    0x7fdc03f8,0x3a27ffff,0xf51fe40f,0x3e037d4b,0x0000002f,0x00000000,
    0x00000000,0x00000000,0x00000000,0x00000000,0x00000000,
};

static signed short stb__consolas_19_usascii_x[95]={ 0,3,2,0,1,0,0,4,2,2,1,0,2,2,
3,1,0,1,1,1,0,1,1,1,1,0,3,2,1,1,1,2,0,0,1,0,1,1,1,0,1,1,1,1,
2,0,1,0,1,0,1,1,0,1,0,0,0,0,1,3,1,2,1,0,0,1,1,1,1,1,0,0,1,1,
1,1,1,0,1,0,1,1,1,1,0,1,0,0,0,0,1,1,4,2,0, };
static signed short stb__consolas_19_usascii_y[95]={ 14,0,0,1,0,0,1,0,0,0,0,4,11,8,
11,0,1,1,1,1,1,1,1,1,1,1,4,4,3,6,3,0,0,1,1,1,1,1,1,1,1,1,1,1,
1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,0,0,0,1,16,0,4,0,4,0,4,0,4,0,0,
0,0,0,4,4,4,4,4,4,4,1,4,4,4,4,4,4,0,-2,0,7, };
static unsigned short stb__consolas_19_usascii_w[95]={ 0,4,7,11,9,11,11,3,7,6,8,10,5,6,
4,8,10,9,9,9,10,9,9,9,9,10,4,5,8,9,9,7,11,11,9,10,9,8,8,10,9,8,8,9,
8,10,9,10,9,11,9,9,10,9,11,11,11,11,9,5,9,6,9,11,7,8,9,8,8,9,10,10,8,9,
8,9,9,10,8,10,9,8,9,8,9,8,10,11,10,10,9,8,2,7,10, };
static unsigned short stb__consolas_19_usascii_h[95]={ 0,15,6,13,17,15,14,6,18,18,9,10,7,2,
4,16,14,13,13,14,13,14,14,13,14,13,11,14,12,6,12,15,18,13,13,14,13,13,13,14,13,13,14,13,
13,13,13,14,13,17,13,14,13,14,13,13,13,13,13,18,16,18,7,2,5,11,15,11,15,11,14,14,14,14,
18,14,14,10,10,11,14,14,10,11,14,11,10,10,10,14,10,18,20,18,4, };
static unsigned short stb__consolas_19_usascii_s[95]={ 118,1,91,11,70,6,21,124,62,12,66,
1,75,111,117,92,33,103,93,44,72,54,64,1,74,113,51,120,33,99,23,
111,37,32,83,104,62,53,44,115,22,13,1,117,108,97,87,10,65,80,43,
94,22,84,1,10,75,53,33,56,101,49,81,104,109,95,18,56,119,85,89,
78,111,58,19,38,28,113,104,65,68,1,12,42,48,76,55,43,32,100,22,
28,1,4,117, };
static unsigned short stb__consolas_19_usascii_t[95]={ 17,22,96,82,1,22,38,68,1,1,96,
96,96,17,101,1,38,68,68,38,68,38,38,82,38,68,82,22,82,96,82,
1,1,68,68,38,68,68,68,38,68,68,53,53,53,53,53,38,53,1,53,
38,53,38,68,53,53,53,53,1,1,1,96,93,96,82,22,82,1,82,22,
22,22,22,1,22,22,82,82,82,22,38,96,82,22,82,96,96,96,22,96,
1,1,1,96, };
static unsigned short stb__consolas_19_usascii_a[95]={ 167,167,167,167,167,167,167,167,
167,167,167,167,167,167,167,167,167,167,167,167,167,167,167,167,
167,167,167,167,167,167,167,167,167,167,167,167,167,167,167,167,
167,167,167,167,167,167,167,167,167,167,167,167,167,167,167,167,
167,167,167,167,167,167,167,167,167,167,167,167,167,167,167,167,
167,167,167,167,167,167,167,167,167,167,167,167,167,167,167,167,
167,167,167,167,167,167,167, };

// Call this function with
//    font: NULL or array length
//    data: NULL or specified size
//    height: STB_FONT_consolas_19_usascii_BITMAP_HEIGHT or STB_FONT_consolas_19_usascii_BITMAP_HEIGHT_POW2
//    return value: spacing between lines
static void stb_font_consolas_19_usascii(stb_fontchar font[STB_FONT_consolas_19_usascii_NUM_CHARS],
                unsigned char data[STB_FONT_consolas_19_usascii_BITMAP_HEIGHT][STB_FONT_consolas_19_usascii_BITMAP_WIDTH],
                int height)
{
    int i,j;
    if (data != 0) {
        unsigned int *bits = stb__consolas_19_usascii_pixels;
        unsigned int bitpack = *bits++, numbits = 32;
        for (i=0; i < STB_FONT_consolas_19_usascii_BITMAP_WIDTH*height; ++i)
            data[0][i] = 0;  // zero entire bitmap
        for (j=1; j < STB_FONT_consolas_19_usascii_BITMAP_HEIGHT-1; ++j) {
            for (i=1; i < STB_FONT_consolas_19_usascii_BITMAP_WIDTH-1; ++i) {
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
        float recip_width = 1.0f / STB_FONT_consolas_19_usascii_BITMAP_WIDTH;
        float recip_height = 1.0f / height;
        for (i=0; i < STB_FONT_consolas_19_usascii_NUM_CHARS; ++i) {
            // pad characters so they bilerp from empty space around each character
            font[i].s0 = (stb__consolas_19_usascii_s[i]) * recip_width;
            font[i].t0 = (stb__consolas_19_usascii_t[i]) * recip_height;
            font[i].s1 = (stb__consolas_19_usascii_s[i] + stb__consolas_19_usascii_w[i]) * recip_width;
            font[i].t1 = (stb__consolas_19_usascii_t[i] + stb__consolas_19_usascii_h[i]) * recip_height;
            font[i].x0 = stb__consolas_19_usascii_x[i];
            font[i].y0 = stb__consolas_19_usascii_y[i];
            font[i].x1 = stb__consolas_19_usascii_x[i] + stb__consolas_19_usascii_w[i];
            font[i].y1 = stb__consolas_19_usascii_y[i] + stb__consolas_19_usascii_h[i];
            font[i].advance_int = (stb__consolas_19_usascii_a[i]+8)>>4;
            font[i].s0f = (stb__consolas_19_usascii_s[i] - 0.5f) * recip_width;
            font[i].t0f = (stb__consolas_19_usascii_t[i] - 0.5f) * recip_height;
            font[i].s1f = (stb__consolas_19_usascii_s[i] + stb__consolas_19_usascii_w[i] + 0.5f) * recip_width;
            font[i].t1f = (stb__consolas_19_usascii_t[i] + stb__consolas_19_usascii_h[i] + 0.5f) * recip_height;
            font[i].x0f = stb__consolas_19_usascii_x[i] - 0.5f;
            font[i].y0f = stb__consolas_19_usascii_y[i] - 0.5f;
            font[i].x1f = stb__consolas_19_usascii_x[i] + stb__consolas_19_usascii_w[i] + 0.5f;
            font[i].y1f = stb__consolas_19_usascii_y[i] + stb__consolas_19_usascii_h[i] + 0.5f;
            font[i].advance = stb__consolas_19_usascii_a[i]/16.0f;
        }
    }
}

#ifndef STB_SOMEFONT_CREATE
#define STB_SOMEFONT_CREATE              stb_font_consolas_19_usascii
#define STB_SOMEFONT_BITMAP_WIDTH        STB_FONT_consolas_19_usascii_BITMAP_WIDTH
#define STB_SOMEFONT_BITMAP_HEIGHT       STB_FONT_consolas_19_usascii_BITMAP_HEIGHT
#define STB_SOMEFONT_BITMAP_HEIGHT_POW2  STB_FONT_consolas_19_usascii_BITMAP_HEIGHT_POW2
#define STB_SOMEFONT_FIRST_CHAR          STB_FONT_consolas_19_usascii_FIRST_CHAR
#define STB_SOMEFONT_NUM_CHARS           STB_FONT_consolas_19_usascii_NUM_CHARS
#define STB_SOMEFONT_LINE_SPACING        STB_FONT_consolas_19_usascii_LINE_SPACING
#endif

