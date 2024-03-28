// Font generated by stb_font_inl_generator.c (4/1 bpp)
//
// Following instructions show how to use the only included font, whatever it is, in
// a generic way so you can replace it with any other font by changing the include.
// To use multiple fonts, replace STB_SOMEFONT_* below with STB_FONT_courier_bold_21_latin1_*,
// and separately install each font. Note that the CREATE function call has a
// totally different name; it's just 'stb_font_courier_bold_21_latin1'.
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

#define STB_FONT_courier_bold_21_latin1_BITMAP_WIDTH         256
#define STB_FONT_courier_bold_21_latin1_BITMAP_HEIGHT        120
#define STB_FONT_courier_bold_21_latin1_BITMAP_HEIGHT_POW2   128

#define STB_FONT_courier_bold_21_latin1_FIRST_CHAR            32
#define STB_FONT_courier_bold_21_latin1_NUM_CHARS            224

#define STB_FONT_courier_bold_21_latin1_LINE_SPACING          10

static unsigned int stb__courier_bold_21_latin1_pixels[]={
    0x00000010,0x00000022,0x00400080,0x10000008,0xeec81cc7,0x40020001,
    0x000202ec,0x00000040,0x044000cc,0x00000080,0x7c400362,0x00baa003,
    0x1f981fa8,0x405f1000,0x5f3002f9,0x2002f980,0x87e402ea,0x03fff07d,
    0x2003ea00,0x03b202fd,0x80274400,0x6d4003e9,0xffc8803c,0x7f106cef,
    0x40175400,0x3e6003fa,0xdfcfd804,0x9817dc00,0x5f90006f,0x5400bee0,
    0x07f5003f,0x01bf9f90,0x7e40110c,0x01fc8001,0xfd801310,0x027cc001,
    0x00eecfb8,0x880b1390,0xfffdcefe,0x900bd301,0x7101bf9f,0x200ddfff,
    0x436600d8,0x006402d8,0xf10007f6,0xb000ec0d,0x40598003,0x105b10d9,
    0xc8198813,0x400aa89f,0x4cc400d8,0x1dc00999,0xd800ee00,0x6c400f21,
    0x227ec01e,0x36201fe8,0x6c436600,0xfedffc82,0x0001801f,0x26204c40,
    0x2002fcc1,0x000c03fc,0x06000000,0xf33fffb8,0xfefc89ff,0x40005fff,
    0x3ffffff9,0x00000000,0x3e000000,0x0000f706,0x3dc6f800,0x1bfffb10,
    0xf95fffb8,0x3ffee9ff,0xe89fff33,0x0ff1000f,0x037fff62,0x3f2bfff7,
    0xbfff74ff,0xb113fff2,0xe881bfff,0x3dfb10df,0xfcceffc8,0x3fffee5f,
    0x65c6ffff,0x7d43fdcc,0xfa805fff,0xfa805fff,0xfa805fff,0x3e605fff,
    0xffff7004,0x7dcdffff,0x6fffffff,0xf88017f4,0x21fffdff,0xfd95effb,
    0x437fa29f,0x7d41efd8,0x107f7004,0x3fffbfff,0xecaf7fdc,0xbdff74ff,
    0xf893ffb2,0x41fffdff,0x417ec6f9,0x51fe86fc,0xfddddffd,0x543fa80d,
    0x400fffee,0x00fffeea,0x07fff754,0x3fffbaa0,0x2007f500,0xeeeeffea,
    0x3bffaa6f,0x7d46feee,0x3f602dff,0xc8df710c,0x7cc5f81f,0xfe817ec6,
    0xd80ff800,0x8df710cf,0x645f81fc,0x7ec5f81f,0xb0df710c,0x641be65f,
    0x263fa82f,0x5406f84f,0x9fdf703f,0x13fbee00,0x027f7dc0,0x504fefb8,
    0x27cc007f,0x213e637c,0xffec886f,0xfd07f986,0x2fc0fe45,0x06f997ec,
    0x9f5013ee,0x3fa0ff30,0x17e07f22,0x4cbf03f9,0x985fd07f,0x3205fb6f,
    0x261fb84f,0x013a954f,0x27fa07f5,0xf3fd007f,0x3e7fa00f,0xff3fd007,
    0x9801fe20,0x313a954f,0x22752a9f,0x2e0fec41,0x649f704f,0xf985f81f,
    0xff805fb6,0x2e03fa00,0x649f704f,0x7e45f81f,0x13ee5f81,0x67ec27dc,
    0x33ff206f,0x7cc6fb89,0x5000fead,0x32bf307f,0xcafcc02f,0xcafcc02f,
    0xcafcc02f,0x819fb02f,0x2b7e61ea,0x5bf300fe,0x85f501fd,0x817e43fa,
    0x207f25f8,0xdf9fb05f,0x2a07f700,0x205f904f,0x207f25f8,0x7c0fe45f,
    0x7c40bf25,0x02fff985,0x3ffffff2,0x7fffcc2f,0x07f5000f,0x017e65f9,
    0x017e65f9,0x017e65f9,0x417e65f9,0xfecdffe8,0x3fffe61f,0xffff300f,
    0x57ff701f,0x4fb81ff9,0x0fe49f70,0xfff982fc,0xd07f8802,0x413ee03f,
    0x207f24fb,0x7c0fe45f,0x7dc13ee5,0xc80dfb04,0x80cddbaf,0x00feadf9,
    0xff887f50,0x100ffeee,0x1ffdddff,0x3bbbfe20,0xdff100ff,0x2201ffdd,
    0x41dfffec,0x00feadf9,0x01fd5bf3,0x7ffffff5,0x3fa0ff30,0x9f107f22,
    0x90037ec0,0x205f987f,0x45fd07f9,0x227c41fc,0x327c41fc,0x40bfa0ff,
    0x0fe402fd,0x2934f980,0x0fea00fa,0xfffffff7,0x3fffee09,0xff704fff,
    0x209fffff,0xfffffffb,0x2603f804,0x83ea934f,0x3ea934f9,0x013f2260,
    0x3ee219fb,0x3f22fd46,0x800bf601,0x00fec6f8,0x7dc433f6,0x3f22fd46,
    0x3f22fd41,0xb8867ec1,0x00df306f,0x3e6003f9,0xd301fc84,0xf80fe83f,
    0xff01fd07,0x1fe03fa0,0x03fc07f4,0x4f9807fc,0x13e61fc8,0x0fea07f2,
    0xffbfff10,0xd9ffd03f,0x037cc0df,0x6f997e40,0xfdfff880,0xcffe81ff,
    0x9ffd06fe,0xfff10dfd,0x7d43fffb,0x3a04ffff,0x2a02ffff,0xfeeeeffe,
    0xffffd31f,0x8effec4b,0xb11effd8,0x3f623bff,0xbffb11ef,0x47bff623,
    0xb11dffd8,0xdf103dff,0xdffd501f,0x2a3ffddd,0xfeeeeffe,0x802f981f,
    0x00efffd8,0x817dff91,0x04fffffa,0x1fa9fc40,0xdfffb100,0x3bff2201,
    0xdff9100b,0x3ff62017,0x7774c0ef,0x3bb603ee,0x3fee01ee,0x1fffffff,
    0x987bddb1,0xfd32fffe,0x3ffa65ff,0x5fffd32f,0x4cbfffa6,0xfd32fffe,
    0x3ffa65ff,0x2035102f,0xfffffffb,0xffff71ff,0x203fffff,0x004c4001,
    0x3ba60188,0x00003eee,0x00131000,0x01880062,0x00002620,0x00000000,
    0x00000000,0x00000000,0x00000000,0x00000000,0x00000000,0x00000000,
    0x00000000,0x00000000,0x00000000,0x00000000,0x00000000,0x00008000,
    0x20a80060,0x04000402,0x4c050540,0x00080324,0x2616e191,0x1dc42eed,
    0x14150191,0x3ba60654,0x4150002d,0x98001802,0x02a1a800,0xc83016e0,
    0x10000184,0xea803ea0,0x2bbfa202,0x2a7f303c,0x007f102f,0x7f3007d4,
    0x4fe40bea,0x5ffd03fa,0x64fea0b7,0x1fffe43f,0x43fa9bfa,0xe85f53f9,
    0x3ffea0ef,0x40f7ecc4,0x205f53f9,0x03caefe8,0x01bfffb1,0x404f8afc,
    0xffd886f9,0xec85fccf,0x7d4fee00,0x1fc8bf92,0x037f3f60,0x006fdca6,
    0x3a601415,0x801fc805,0x9fc80a0a,0xf53883fa,0x44fea03d,0x23fb887f,
    0x41fd44f9,0x17e40a0a,0xdf9819f5,0x20a81fdb,0x6fdca602,0xfdfff880,
    0x541301ff,0x221fec00,0xfffedfff,0x3a03f900,0x3f23d37f,0xd9803625,
    0x01805b10,0x1b1000c0,0x00006c40,0x17dc7ec0,0xb1fd4000,0x547f507f,
    0x001fd43f,0x1fd47f50,0x0013a2e4,0x0cfd8000,0x0000df91,0x33f61fe6,
    0xa80dff10,0x040dfd02,0x36200000,0xb100dfff,0x0001bfff,0x3ffee000,
    0x4c9fff95,0x40cfdbfe,0x205ffffa,0x21be63fa,0x50fea3fa,0x3fffee7f,
    0x7d46ffff,0x0ba0fea3,0x7fff4cd9,0x3ffa2fff,0x4d3fff23,0xa85fd07f,
    0x6405ffff,0x3a3fcc3f,0x82662fef,0x9bfa0998,0xffffd302,0x3ffa65ff,
    0x3e22ffff,0x41fffdff,0xfffdfff8,0x3ffffa61,0x5fff52ff,0x7dcfffa6,
    0x9ffd95ef,0x3fffffea,0x7ff7546f,0xf87f500f,0x3ea3fa87,0xfea9fd43,
    0x46feeeef,0x10fea3fa,0x99bf661f,0x1eeefeed,0x75c3fff6,0x209f74ff,
    0x7f7544fb,0x07f600ff,0x56fe49f5,0x229ff94f,0x57f63fff,0xeed982fa,
    0xdb31eeef,0x6c3dddfd,0x8df710cf,0xdf710cfd,0x777f76cc,0x21ffd31e,
    0x3f22eff9,0x7fdc5f81,0xf701cfec,0x032209fd,0x33fa81fd,0x23fa85fb,
    0x546f84f9,0xa87f51df,0x20dbbf37,0x3ff203fa,0x03f937c5,0x77dc17e2,
    0x903fe04f,0x223bee5f,0x5c9f935f,0x5d3f23fd,0x01fd403f,0x1fe60fea,
    0x07f997f4,0x07f505fd,0x7fc47fe2,0x2fc0fe40,0x200fdb7c,0x4007f9fe,
    0xe9fd41fd,0x31fd40ff,0x42752a9f,0xa87f56ff,0x541aebb7,0x3fff203f,
    0x04fa9be3,0x27fa09f7,0x261fe07f,0xf71ff9bf,0x3ea27c49,0xa7e53ee3,
    0x01fd44fb,0x13ee0fea,0x04fba7dc,0x07f509f7,0x83fdb7d4,0x265f81fc,
    0x0afeaefa,0x05f95f98,0xa83fd02a,0xa85fb33f,0x3ab7e63f,0x23bf500f,
    0x5cbd43fa,0x80fea0d7,0xdf0ffafc,0x2fe83fc4,0x05f95f98,0x3bbe03fe,
    0xf88bfa2f,0x7f51fd44,0x237e57f6,0x1fd403fa,0x5f8817e4,0x17e205f9,
    0xdf900fea,0x207f20bf,0x3ffff65f,0x2fc83fff,0x87f50bf3,0x2a3fa87f,
    0xf31fd43f,0x2a01ffff,0xf30fea3f,0x20fdff31,0x27f203fa,0xfd8df5fb,
    0x20df710c,0x20bf32fc,0x4ffc81fd,0x4f88df71,0x21711fd4,0x3ea066fe,
    0x5c1fd403,0x2e9f704f,0x509f704f,0xffe8807f,0xbf03f900,0x7fd6fdc4,
    0x777fc40a,0x1fd40ffe,0x47f50df3,0x31fd43fa,0x201fd5bf,0x10fea3fa,
    0x40f2e25f,0x47f203fa,0x7446fafe,0x81fffdff,0xffeeeff8,0xfc83fc80,
    0x41fffcef,0x01fe45f8,0x3fa80fff,0x7cc1fd40,0x3e65fd07,0xf505fd07,
    0x407f5007,0x227c41fc,0x2e0df4f9,0x4fffffff,0x07fb1fd4,0x21fd47f5,
    0x4d3e63fa,0x1fd41f54,0x00bf07f5,0x3f901fd4,0x6c1bffe6,0xf701efff,
    0x09ffffff,0xdffa8ff3,0xff01efff,0x23dfffbb,0x80dfd0b8,0x1fd403fa,
    0xf710cfd8,0x710cfd8d,0x00fea0df,0x5fa80fea,0x2fea0fe4,0x01fd05f8,
    0xf13fa8ff,0x547f501f,0xf31fd44f,0x7dc3f909,0x3ee0fea2,0x1fd40aa2,
    0x7fe43f90,0xacffe886,0x407f42c9,0x6c5fb07f,0xf300261f,0x25ffdfff,
    0x803b33fb,0x1fd403fa,0xffdfff88,0x6fffc41f,0x7f501fff,0xe807f500,
    0xa86fecff,0x6c44f8bf,0xffb11dff,0x7e4fea3d,0x11fffd43,0xa9fd4bff,
    0xfeeeeffe,0xfa8ffb1f,0x7f7ec3ff,0x3fbb662f,0x3fea1dee,0xb0dfd14e,
    0x9fffffff,0x4477ff62,0x7cc1effd,0x98000226,0xd9800c01,0x31deefee,
    0x3bddfddb,0x0efffd88,0x1dfffb10,0xeefeed98,0x77f75c1d,0xdff9104e,
    0x32191017,0x97fff4c1,0xd12fffe9,0x3baa16e3,0xd126cc2e,0x3ffffee3,
    0x3b91ffff,0x983eee98,0x7ffcc0ab,0x3ee2ffff,0x21bea6ff,0x2cca9bca,
    0x4cbfffa6,0x4b82fffe,0x00000000,0xffffff30,0x3fffe65f,0x13102fff,
    0x4c026200,0x2fffffff,0x2fffffe4,0x00000620,0x00000000,0x00000000,
    0x00000000,0x00000000,0x00000000,0x00000000,0x00000000,0x00000000,
    0x00000000,0x00000000,0x00000000,0x00000000,0x00000000,0x17300060,
    0x00001800,0x006000c0,0x00000026,0x00000000,0xddb73006,0x2200009d,
    0x002eeeec,0x26003200,0x00000000,0x42f2a000,0x8027c400,0x320059d9,
    0x03fb800f,0x5c003ee0,0x00f5c00f,0x9816fecc,0x32602dfd,0x3b6201df,
    0x203ee001,0xefdfffd8,0x200fee03,0x03fcccee,0x3ea007e2,0x001ec803,
    0x6d4409f5,0x765402df,0xdffd503e,0x06e8803f,0xb0058c98,0xd7fb001d,
    0x01ed801d,0x2e003db0,0x3ffe602f,0x7ffcc1ff,0xfffa83ff,0xcdf984ff,
    0x01ed804f,0x0fabe9f7,0x00eebfd8,0x202e81f3,0x3fa803fa,0xd805f700,
    0xfe80eebf,0xf904ffff,0x3aa0dfff,0x2e003fef,0x801db800,0x41930048,
    0x8006401c,0x154000c8,0x1fe65fb0,0x03fa27f9,0x03fa23fd,0x22024c57,
    0x7c3fa00c,0x419303ea,0x187f901c,0x2201fd40,0xa802cefd,0x2b832202,
    0xfe88e744,0x400f7e40,0x00ff88aa,0x26002aa6,0x351000aa,0x9806a200,
    0x40266209,0x51000aa9,0x3f637c03,0x49f71fa1,0x317e44f9,0x004cc413,
    0x47f60351,0x54403eaf,0x37fbf601,0x407f5000,0x0ffffffa,0x53003510,
    0x2fb80015,0x44003be6,0x884fccdb,0x81efffff,0x1efffff8,0x5ffffb50,
    0x3ffff6a0,0xf8a7fe42,0x7ffc43ff,0xfb501eff,0x4f985fff,0x98fd1fdc,
    0xe887fc5f,0x229ff91f,0xff983fff,0x77d42fff,0xf303eafa,0x7f05ffff,
    0x7640ffea,0x0ceeefee,0x3fa22ffa,0x7ffffcc0,0xfffff882,0x7fd4c01e,
    0x80a67ee0,0xffffffe8,0xcacdd885,0xacdd885f,0xcffb85fc,0x7dc1ffcb,
    0x21ffcbcf,0x3f6e4fc9,0x6566ec43,0xbcffb85f,0x0bee1ffc,0x897dc9f3,
    0x7ffdc6fe,0x93f264ff,0x7fcc3fdb,0x542ffebe,0x983eaffe,0x2ffebeff,
    0x1bf91fdc,0x7fffffc4,0x8bf31fff,0x5f7fcc49,0x6ec42ffe,0x3605fcac,
    0x6ff43fff,0xdfb83eff,0x880dfd31,0x54407e9a,0x07fc47e9,0x0ff89be6,
    0x13e237cc,0x4d4407f5,0x207fc47e,0x30bee6f9,0x7effc49f,0x7ffd47ff,
    0x227c43ff,0x217ec3fa,0xd5f107f9,0xf985fb07,0xd31efb87,0x39f7330d,
    0xd803fa83,0x103fcc2f,0x6d40fd35,0x77ffc6fe,0x0ff41ffc,0x7f5c1fea,
    0xeb80ffff,0x260fffff,0xffffffff,0xfffff30f,0x7c41ffff,0x75c1fd44,
    0x260fffff,0xffffffff,0xfa87f50f,0x7e7fecc3,0x2a2ffe26,0x513e21fe,
    0xd837c47f,0x87d5f01f,0x03fb06f8,0x03ea9fb3,0x1ff01fd4,0x20df11cc,
    0x7ff5c1fd,0xfd800fff,0x4f997fa3,0x437cc3fc,0xfecbcffb,0x65e7fdc0,
    0x3bfe60fe,0x30eeeeee,0xddddddff,0x2a27c41d,0x5e7fdc3f,0x3fe60fec,
    0x0eeeeeee,0x01fc8df1,0x4fa93f61,0x89f11fdc,0x41be23fa,0x7d5f01fd,
    0x3fb06f88,0x037ffd40,0x7fe407f5,0xdf10fffe,0xffb87f60,0x800fecbc,
    0xd07f65f8,0x7e42fc8f,0x3a237c44,0xd11be20f,0x80ffc41f,0x0407fe20,
    0x47f917e2,0x07f446f8,0xd0203ff1,0x881be21f,0x13e60ffb,0x22fc47f7,
    0x21fec3fc,0x3abe07fa,0x7d43fd83,0x13e21c47,0xea805f30,0x1fec2dff,
    0x46f89fea,0x54040fe8,0xf893ee4f,0x7677fc45,0xcdfe80ff,0x3a1efffe,
    0xefffecdf,0x373bfee1,0x3fee0ffe,0x40ffedce,0xefffddff,0x3fb37fa1,
    0x3fee1eff,0x20ffedce,0x43ffdffa,0x81fffddc,0x0ffecefe,0x7ffeeffc,
    0x33ffe61e,0x2be02ffe,0xcfff983e,0x23cc2ffe,0x002803f8,0x3fe607f5,
    0x742ffecf,0xefffecdf,0xfdb9bf91,0xfdefe83f,0xeffea82f,0xfffb300b,
    0x6cc5ffdd,0x2ffeefff,0x77ffffd4,0xfffffa83,0xffff983e,0x3f662ffe,
    0x42ffeeff,0x3efffffa,0xd84fffb8,0xb100bdff,0xf303dfff,0x85ffdfff,
    0x81efffd9,0x4efcfed8,0x1efffd98,0xefeeef98,0x77776c40,0xf980deee,
    0x3fff6603,0xfffd981e,0xfb32ffee,0xb303dfff,0x18807dff,0x40026200,
    0x26200098,0x00331001,0x04c40066,0x20033100,0x20004401,0x00198009,
    0x9991004c,0x09807995,0x2f333220,0xfffff880,0x1701ffff,0x22002600,
    0x00310009,0x00000022,0x00000000,0x00000000,0x00000000,0x00000000,
    0x00000000,0x00000000,0x00000000,0x70000000,0x00002e21,0x00000000,
    0x99882660,0x6f7776c0,0x3ae02203,0x42eeeeee,0x00000001,0x0aa88cc4,
    0x54400c40,0x8801331a,0x1710b800,0x22003100,0x46aa6002,0x5cc00c00,
    0xf53f9800,0x00f6e605,0xca839fb7,0x3f66001e,0x4ffc802d,0xfe87fff1,
    0xf506ffff,0xfffff903,0x00ed87ff,0xec981fd4,0x3bffe000,0x540dffff,
    0xb81cfffd,0xfffeffff,0x77ffe441,0xf53f986c,0x3fff2205,0xdff306df,
    0xffd309b7,0xfb10dfff,0x9d901bff,0x8183005f,0x203ffff9,0x23fffffd,
    0x2a001fbb,0xd9806b8b,0xd0ff6e4f,0x2e03333f,0x333f702f,0x1db03fb3,
    0x03baff60,0x5c001f95,0xfebcfffe,0x3b3bfe24,0x5effcc6f,0x220bfffd,
    0xfffdcefe,0xe880c181,0x1ffeddff,0x819d5298,0xfecbeff8,0x7efffc47,
    0x543e21ff,0x20351005,0x503fcde9,0x21ba61bf,0x7644001f,0xa89f1006,
    0xc803f43f,0x03fc0400,0x64191037,0x4000f881,0x07f40efc,0x361fc8bf,
    0x6c37e41f,0x80ff444f,0x13ee01a8,0x1a8807f6,0x8fd09f90,0xdf710cfd,
    0x405a87c4,0x02ffffda,0x07d40fea,0x203f0bee,0x46eb883b,0x227c40c9,
    0x76ff43fa,0x0133302d,0x26613ea0,0x02666009,0x0e4407c4,0x1fd417e4,
    0xf33fa835,0xdf0df109,0x3fe61ee0,0x06e82fff,0x3ffe6093,0x407f42ff,
    0x741fe618,0x4bf3b22f,0x5e7fdc19,0x7f501ffc,0x7c1fe800,0x1027f4c1,
    0x103bf23f,0x743fa89f,0x7c5fffff,0xf9003fff,0x03ffff85,0x2207ffff,
    0x40ffdc0f,0x03fc84fc,0x37c47fea,0x13e637d4,0xebeff980,0x013e62ff,
    0xfd7dff30,0x4007f45f,0x89f704fb,0x23fecab9,0x37cc0ff8,0x36003fa8,
    0x37bfb25f,0x740aefb8,0x3fe9dfee,0x7e44bf10,0xfd88dd43,0x00ff72e1,
    0x7ee5c3fc,0x07fb9703,0xfd17dfdb,0x33ff201b,0x980ffc99,0x6ff43ffe,
    0x546ffb8a,0x0bf6003f,0x21fd4ff3,0x7ec09999,0x7f93fcc2,0x0bf21710,
    0xff932fc4,0xffff3039,0x501fffff,0xdfb1007f,0xfea99988,0x260eefcc,
    0xfd9efc8a,0x7eeffc42,0x7cc01eff,0xa803fa84,0x00fea04f,0x333107f5,
    0x07f95df9,0xfffffff9,0x2037e605,0xffffffe8,0x8801fd46,0x2a3fb06f,
    0x3ffff23f,0x7ec1be26,0xb9bfff11,0x413ee5ff,0x759d74fb,0xeff9839d,
    0x80eeeeee,0x7f4403fa,0x27bf200d,0xfa8990e8,0x885ff53f,0xffefffff,
    0x542fc402,0x02fc803f,0x7f500fea,0xf9a7f4c0,0xdbafc83f,0x400c802d,
    0x46f9cdc9,0xdf1007f8,0x37c47f60,0x447fd993,0x4c3fb06f,0x23ffffec,
    0x05fd07f9,0xf88d93d5,0x3ea0101f,0x017fe603,0x0fe607f3,0x3efe21bd,
    0x00cefc42,0x509f7031,0x80ff007f,0x1fd403fa,0x76743db0,0x0001fc83,
    0x361be000,0xb0f540cf,0x747fa87f,0x6c1fc82f,0xf03fd43f,0x433f6037,
    0x45b06fb8,0x677fdc1e,0xfa80ffed,0x009ff503,0xd803fb80,0x27c43faf,
    0x76e77e40,0x03fa80ff,0x3ea027d4,0x001fd403,0xf909f7f9,0x01c98003,
    0xfe886f80,0x21ffecdf,0xffecfff9,0x6efffcc2,0x7fcc1ffe,0x302ffecf,
    0x3fe201fb,0x901fffdf,0x7fd41e69,0x3623efff,0x21deefee,0xfeeeefff,
    0x11ed8801,0x45fccc80,0xec8804f8,0x3ae1efff,0x83eeefee,0xeeeb81f9,
    0xdd73eeef,0x807dddfd,0x7f45fccb,0xf9002fff,0x3ffa200b,0x7f6441ef,
    0xfd981dff,0xfb301eff,0x2605dfff,0x101efffd,0x6c401fff,0x2200efff,
    0x4c402ffd,0xfffff301,0x7fffc5ff,0xa803ffff,0xf005ffff,0x8005b0df,
    0xfffc8098,0x4004ffff,0xfffffffc,0xffffff94,0x1ffa009f,0x003ddddb,
    0xddb1000c,0x00c401bd,0x4c400130,0x40026000,0x01310009,0x00000040,
    0x00000000,0x00000000,0x00000000,0x00000000,0x00000000,0x00000000,
    0x00000000,0x22170000,0x1cc7100b,0x13100440,0x79301988,0x003bb201,
    0x00288000,0x06626aa2,0x40276cc0,0x009f7000,0x400cc020,0xa8806e1b,
    0x4400bded,0xa80bdeda,0xaaaaaaaa,0x98009881,0xffd101ee,0x0101dfff,
    0x40bea7f3,0x220fb0fc,0x22eeffeb,0xff33fffb,0xffffb89f,0x00fffc43,
    0x3e600d90,0xf903dbef,0x0dffdfff,0x540dff50,0x75c04ffe,0xf51a9803,
    0xeadffc87,0x09f15f80,0x32a6b7a2,0x35bd100f,0x80181f95,0x027ffe41,
    0x6c407ffa,0x40deffee,0x00c183fd,0xdfb00886,0x7449ffd9,0x3dfb10df,
    0x06e99ef8,0x7ec003fb,0x9d529800,0xf99ff901,0x22005bff,0xd9ff106f,
    0xfa80005f,0x41ffffff,0x102ec88a,0x22e880c1,0x440ea89a,0x3aa2aabe,
    0xfa860060,0x3ee02fdd,0x0fd001ff,0x554c27ec,0x98826600,0xf717e609,
    0x7ec6f989,0x3fb27cc2,0x15513f90,0x2667fa20,0x402aa601,0x1ffc0ff8,
    0x1be35510,0x00c897dc,0x7bff5014,0x89889ffb,0x4ccc02a8,0x33aa9700,
    0x8cb8977e,0x4972eeee,0x03f61801,0x07f7fe20,0x10603f40,0x83dfffff,
    0xfff14ffc,0x0ec27d47,0x86f997ec,0x0ffd9cf9,0xffffefc8,0x3fffee0c,
    0x7fc44fff,0x7d41efff,0xf703fc84,0x20dfdfff,0x3e6001fc,0x3e63ff02,
    0xdff30fff,0xff07dfff,0x747607ff,0x3b1a6b10,0x269ad4f2,0x13ee1801,
    0x07f2ff20,0x22003f40,0x45fcacdd,0x3f6e4fc9,0x06f7fe23,0x0bf6df30,
    0x3bff73e6,0xccfffc80,0x3fb225ff,0x6c41cccc,0x4c5fcacd,0xb83fc85f,
    0x6ffebcff,0x01adfca8,0x7cc1ff4c,0x5f95ff35,0x75df7fe4,0x1fee5c0f,
    0x3e0598f8,0x7eee43e0,0x0c00c3e2,0x30263ff5,0x0107f2df,0xa88001fa,
    0x44f887e9,0x7ff443fa,0x33f603ff,0x519f306f,0x6fc81dfb,0x07ec1fe8,
    0x8fd35100,0x3fe61ff8,0x3607fc43,0x7fffd46f,0x37ff207f,0xff9cf981,
    0x77c45f92,0x7d40bee0,0x20d13d03,0xbdc8f478,0x400cf10e,0xf5dfff51,
    0x3f92fe8f,0x107e85e8,0xffeb81bd,0x27c40fff,0x6dc40fea,0xfff303ff,
    0xfb13e605,0xfb83fc87,0x5c007ec3,0x40fffffe,0xfffdeffb,0x7cc27d43,
    0x1affaa86,0xd803df10,0x8ff33fff,0x81fd44f8,0x327903fa,0xc8b55a9c,
    0x51d51bb3,0xfd8c00cb,0x2a4fffcb,0x43fdaaff,0xf507e86f,0xcbcffb89,
    0x227c40fe,0x220ea3fa,0x81bf606f,0x22fcc4f9,0x43fa82fc,0x7fdc00fd,
    0xb80fecbc,0x43fdffff,0x06f984fa,0x87f501fe,0x677fdc49,0x27c42ffe,
    0x1fd40fea,0x39b50f98,0xcaf985f1,0x0c5f971c,0x3fa7e8c0,0x7ffffe47,
    0xf11be2ff,0xdf11b60d,0x7c40fe88,0x3fd1fe45,0x3f605f98,0x56b3e602,
    0x437e44f8,0x207ec2fe,0xe88df119,0x7dc6600f,0x3207fc42,0x98bf506f,
    0xfd98f7c4,0xfffdff10,0xa89f103d,0x407f503f,0x0baa22f9,0x5d5117cc,
    0xdf718018,0x54cbffd9,0x7c3fdaaa,0x02ffddff,0xd9bfd05f,0xff83dfff,
    0xd1efffdd,0x5ffd9dff,0xea81be60,0x1fedfdff,0x377ffff6,0xcefa85ff,
    0x37fa6ffd,0x01efffec,0x7e407f4c,0xdffffddf,0x3bbfff20,0x3ff20ffe,
    0x7f70ffff,0xffe9804c,0x2e3dfd34,0x3eeefeee,0x2dfefd98,0x6ff7ecc0,
    0x91180182,0x20dfdfff,0x260effd9,0x302efffc,0x3fff6609,0x7cc2ffee,
    0x92ffefff,0x85bfffbd,0x04fffffa,0xffd5fff7,0xffdffe89,0xff900cff,
    0x7ecc39ff,0x42ffeeff,0x04ffffe9,0x3f7fffee,0x3fff60ef,0xc984ffff,
    0x000c0bde,0x3e6bfff5,0xffff92ff,0x01809fff,0x99a80300,0x82999999,
    0xfffa8009,0x0001301e,0x4c001310,0x4c031001,0x003eeeee,0x01988004,
    0x13100660,0x5bddb300,0x00026600,0x00000000,0x00000000,0x00000000,
    0x00000000,0x00000000,0x00000000,0x00000000,0x00000000,0x00000000,
    0x00000000,0x00000000,0x00000000,0x3005ddd7,0x3ee179b7,0x9fff95ff,
    0xdb501db0,0x0dd91007,0x7e5bffa0,0xdfff71ef,0xe87fff53,0x3fff23ff,
    0x225fff54,0xfff33ffe,0x05ffffff,0x3fa20054,0x0fffffff,0xffb802e0,
    0x3502dfff,0x7fffe400,0xffff982f,0xfff52fff,0x54fffa65,0xffd32fff,
    0xa9ffff47,0xfe80efff,0x7fe403ff,0xdff73fff,0x213ffb2b,0x4ffc81ff,
    0x007ff980,0x3fb2bffb,0x3dffd50e,0xfd87fff5,0x9ffd70ff,0x7ccbffaa,
    0xddff33ff,0x205fdddf,0x7ec402f9,0x0ffeeffe,0x7d405f30,0x45fffeef,
    0xb800cff8,0x981eeefe,0x2ffeeeff,0x3e61ffd3,0x3ffd52ef,0xfe8bffe6,
    0xdfdd32ee,0x80fee201,0x0a999ef8,0x417e07f2,0x013e6019,0x9f3007e8,
    0xa7cc3fa8,0xf900efd8,0x7446f8bf,0x4c1ff11f,0x3ee7f54f,0xbf800602,
    0x5403f66f,0x30fe403f,0xffea87fd,0x66fd400c,0x727cc2bc,0x11ff88df,
    0x2fe881ff,0x4f983ff3,0x00bee131,0x3ee207f5,0x1fc8099c,0x099985f8,
    0x15519f30,0x03333f40,0x43fa89f3,0x05fe8cf9,0xdf1fffe4,0x0ff6df30,
    0x5cfea9f3,0xfa80002f,0x07c98ef9,0x3f900fea,0xff707f88,0x7ffd407f,
    0x7f10efff,0x3ea03fe6,0x3e607fb6,0xf882ffaf,0x07f2bf95,0xff507f50,
    0xc87fffff,0x7fc5f81f,0xfff303ff,0x5fa07fff,0x7cc5fffc,0x43fcaaad,
    0x804ffef9,0xdf0ffafc,0x417fbf20,0x3667f51d,0x26666620,0x3ef90099,
    0x4c418fdf,0x4099cfb9,0x361acfda,0xdff9100f,0x6447f505,0x3fa22a3f,
    0x17fbf202,0x407fff50,0xfb1fff6f,0x883fa801,0x0cccefdb,0x22fc0fe4,
    0xf303fdcb,0x01ff77df,0x073ff6fd,0xfffffff3,0xeffff987,0x7dcfe400,
    0xff310df5,0x3fa8015f,0xffffff10,0x29d03fff,0x7c40ffff,0xffffffff,
    0xffffff31,0x3a200fe4,0x0fea0dff,0x09fb09f3,0x800ffe88,0x4ff407fe,
    0x807ebfff,0x0fe603fa,0x0bf03f90,0x77cc0fea,0x3fa0bee0,0xbf300efe,
    0x987f9555,0x00efcaff,0x7d7f47f2,0xadfca986,0x901fd402,0x99999999,
    0xffeef981,0xfb99707d,0x6cc1799b,0x03f61acf,0x41dffd88,0x0bf623fa,
    0xa804cbf9,0xfffb803f,0x2ff7f605,0xfa807fdf,0x900fe603,0x504f883f,
    0x513e607f,0x1fffd07f,0x3ea27cc0,0x9f927cc3,0xff98fe40,0xdfca886f,
    0x01fd401a,0x333ee000,0x201518ef,0x0fe403fa,0xffc883f4,0xffff502e,
    0x7fd41bff,0x1fd417e0,0x3fa3fea0,0x3afffb03,0x3fa806ff,0xf500fe60,
    0xf501fc8b,0xf513e607,0x1dfdfd07,0x7f513e60,0x07f44f98,0x3ff21fc8,
    0xadfca986,0x001fd402,0x26f97a00,0x07f503f9,0x3f621fc8,0x02fffb84,
    0x0d666fd4,0x0df07fe2,0xff980fea,0xf905ff11,0x017fee9f,0x3f980fea,
    0xfecffe80,0x4c0fea06,0x741fd44f,0xe983ff97,0x7dfd75ff,0x5477ffaa,
    0x77fd45ef,0xb30dfd14,0x2e03ddfd,0x403eefee,0xffb101e8,0xfdddffd9,
    0xa80fea07,0xeffeeeff,0x00fffa20,0x077bbfae,0x3bbbbff2,0x77f75c6f,
    0x97ffd44e,0x7dc4ffe9,0x209ff12f,0xeeefeeeb,0xdddfdd33,0xdff9101b,
    0xfeeeb817,0xffd33eee,0x44fbfaa9,0x3bffa7fd,0x32dfff51,0xfff73fff,
    0x7077f45f,0x37d4dfff,0x17ffffcc,0x4fffffc8,0xf880ec40,0xfffffdff,
    0x03d103ff,0x6fffffdc,0x000ce883,0x05fffff9,0xfffffff9,0xfffffc8d,
    0xa9fffdc5,0x3fd45fff,0x7fe40ffa,0xf54fffff,0x03dfffff,0xfff900c4,
    0x3ea9ffff,0x7fff75ff,0xffd9ffa6,0x0000002f,0x00000000,0x00000000,
    0x00000000,0x00000000,0x00000000,0x00000000,0x00000000,0x00000000,
    0x00000000,0x00000000,0x00000000,0x00000000,0x00000000,0x4cbfffa6,
    0xff72fffe,0x2015bfff,0xfffffffd,0x107ffa6f,0x3fa23dff,0x7d405fff,
    0x3f205fff,0x002dffff,0x3ffee288,0x74c0beff,0x72ffffff,0xffffffff,
    0x7ffffdcd,0x30d4c02d,0x00351005,0x44011551,0x0aa9801a,0x811aa980,
    0x02662099,0x51153131,0xffd10003,0x3bff623d,0xfddffd51,0x3bfb60ff,
    0x366feeee,0x77fdc5ff,0xbdffdb10,0xfffeea80,0xdddfd700,0x32200bff,
    0xdffd51ff,0x6cc1fffd,0x51eeefee,0xfddddffd,0x7f77fd4d,0xfff885ff,
    0x80effddf,0x82ffffda,0x1fffffea,0x17ffffcc,0x77ffffc4,0xffffe981,
    0x453ff26f,0x3fe23fff,0x5fffefff,0xe80dfd98,0xf987f80f,0x640bf224,
    0x3e26f81f,0x0bffe1ff,0x3ee002fc,0x8fea04fe,0x7dc01fd8,0x227cc3ff,
    0x07f503fb,0x91be13e6,0x21ff4c3f,0xdffebcd8,0x67fdc4fd,0x7fc1ffcb,
    0x262febac,0x2ffebeff,0x7e566ec4,0x65f7fc45,0x93f267fe,0x7fe43fdb,
    0x1fdcffcc,0x5c2e45f4,0x4c27d43f,0xc82fc44f,0x8936591f,0xfff54fff,
    0xd0017e05,0x7d40ff3f,0xea827cc3,0x4f980cff,0x3fa82fcc,0x752a9f30,
    0x3e20fe44,0x4df95106,0x81ff10fe,0x2bbe26f9,0x17ec1911,0x9a881fe6,
    0x7427e47e,0x3ea27c47,0x4f9afc43,0x176087f5,0x01fd1fe2,0x3faa29f3,
    0xbf59f903,0x23fb7e20,0xbf02fcfe,0xfcafcc00,0xfd87f502,0x067ff4c3,
    0xfb55bf30,0x40fea05f,0x00feadf9,0x41fb03f9,0xffffffe9,0xfff31fff,
    0x41ffffff,0x21dffffc,0x83fb06f8,0x0fffffeb,0x106203fa,0x443fa89f,
    0x3ea9f35f,0x900ee883,0x4c17e65f,0x04ffffff,0x417ffff2,0xdfefbcf8,
    0x00bf02fb,0x05f997e4,0xdffb9bf5,0x00fffe41,0x7fffffcc,0x207f501f,
    0x00fffff9,0x23f903f9,0xffdbdff8,0xff31eeee,0x1ddddddd,0x2ffecb98,
    0x87f60df1,0xfecbcffb,0x44003fa0,0x221fd44f,0x3ea9f35f,0x26027d43,
    0x2605f96f,0x00ffeeff,0x417eb3f2,0x9fff8cf8,0xb0bf02fb,0xeeeff883,
    0xfffa80ff,0x7ec40dff,0x6fcc01ef,0x80ffebaa,0x5bf303fa,0x07f201fd,
    0x727cc3f6,0x3fe208df,0x207dc101,0x50ff65f9,0x2237c4ff,0x20ff20fe,
    0x917e20b8,0xf35f887f,0xff98fea9,0x27fa06ee,0xc93e606f,0x23f900ef,
    0x329f102c,0x3e05f76f,0x3ee27c45,0x84ffffff,0x98019cfa,0xf300dffe,
    0xf507f909,0xa4d3e607,0x207f20fa,0x7eeffc7f,0x21ffddff,0xfedceffb,
    0xb9bff90f,0x7ffcc5ff,0x7f42ffec,0x1efffecd,0xfb9bfff1,0xfddff85f,
    0xffb11eff,0xdf55ff37,0x00ccccc3,0x4c07fff5,0xc82fe44f,0x14f8801f,
    0x7c0bee35,0x3fa27cc5,0x3fa87f80,0xcffea800,0x7dc27cc0,0xf303fa83,
    0x7e43f909,0xd113f621,0xfffdddff,0xffffa819,0x3ffea3ef,0xfd983dff,
    0xfd981eff,0x22ffeeff,0x3ffffec9,0xfeffff98,0x39ffd12f,0x05ff57ff,
    0x807ffc00,0x3a1dffea,0x3bfb21ef,0xffd880de,0x3dfdb11d,0x3bbffb62,
    0xffb14fee,0x3bff623b,0x3bddfd71,0x0fffb800,0xfdddffd5,0x3bb663ff,
    0xfd51deef,0x3ffddddf,0x3fbbbfea,0x883100ef,0x80198801,0x01300099,
    0x44001310,0x00198019,0xf7000000,0x7fffdc0b,0xfd87fe22,0xe881efff,
    0xffd12fff,0x3fffa65f,0xd34fffff,0x3fa65fff,0xffff92ff,0xd910005f,
    0x3ffffee1,0x3fe61dff,0xf72fffff,0xffffffff,0x3ffffee3,0x0000003d,
    0x00000000,0x00000000,0x00000000,0x00000000,0x00000000,0x00000000,
    0x00000000,0x00000000,0x00000000,0x00000000,0x13300000,0x864c1330,
    0x43310b21,0xa8898829,0x26666602,0x30662099,0x4c199813,0x01910099,
    0x360c8910,0x000075c4,0x100ae1d8,0x4c400015,0x99999999,0x35300000,
    0x3fffffaa,0x21313eff,0x20ddc098,0x80400003,0x07fff401,0x77dcffff,
    0x2e4fefff,0xfffebfff,0xfffdff31,0xffff987d,0xfff13fff,0x747fff6d,
    0xfffb6fff,0x807f501f,0xe8bd13f9,0x4c1ff74f,0x3b2a1dfd,0x9f32fb81,
    0x40fffee0,0xfff980e8,0x2fffffff,0xd7073f66,0xaa7dc3bf,0xeeeeeeee,
    0x3f29f72e,0x3f03fe23,0x8a63ffb8,0xb89f73fa,0x2ffea00f,0x43feb9a8,
    0x0effdffe,0x37fffb22,0x3bff22fb,0x3e60febb,0x21ffecce,0x9ff74ffc,
    0x4cbbf6a1,0x54543efe,0x7d40a8bf,0xfd10dd34,0x8aa83ffd,0x407eee6c,
    0xd0bf33fb,0xfd01f719,0x9999701d,0x225fd999,0x260fa9bf,0x0fea5c99,
    0xfb9fd400,0xfb30fea2,0x33ffbea1,0x65bf26fa,0x2007b65f,0xff5fc8fd,
    0x1fe23fd0,0xf1017fe4,0x3e17dc1d,0xf303ff52,0xf105ffbf,0x7d41fe8f,
    0x23ffffff,0x01df54fc,0x4407ffe2,0x00fc44ec,0x43be69f9,0xd83f11f9,
    0xb8005fef,0x23c8b52f,0x3e66ffec,0x77777512,0x4be61777,0xf11f61fa,
    0x744764ff,0x82a21fff,0xfb800641,0x85f9fffa,0x6407ec6f,0x227c401f,
    0x3ff503fa,0x00fffcc0,0x417ea7f9,0x23efffeb,0x0bf93fd8,0x8827ffdc,
    0x00fc45ec,0x83bea9f9,0x7dc7dade,0xb8009fb5,0x3a23f12f,0x89b21d51,
    0xfffff71f,0x3e29ffff,0x81fc1f31,0x001cb801,0x7f7d4000,0xfe83feff,
    0x3f20ff11,0x2a27c400,0x01ffa83f,0x806fffec,0x403fd6f8,0xf902fffa,
    0x3ee17ea7,0x2604fe9f,0x6c07e20f,0xd309f52f,0x077cc5df,0x7dc005fd,
    0x88fbfae2,0x3e5ffffe,0x55555510,0xb06c1555,0x000002c4,0xff880000,
    0xe81fffaf,0x80effeff,0x27c400fc,0x3ff50fea,0x1dfb116c,0x3f201dfb,
    0x3fe205fd,0x7f500ffa,0x1ff897a2,0x777c1fd1,0x17bfb24f,0x00bea3d9,
    0xd883b301,0x203a6001,0x00042200,0x00000000,0xd0000000,0x2e1ff2df,
    0x5fefffef,0x3bbbffb2,0x9a7ff4c4,0xfff31efe,0x3a69fddd,0x5fff74ff,
    0x403fff10,0x403f53f8,0x81305c38,0x440a9828,0x30540999,0x00000001,
    0x00000000,0x00000000,0x90000000,0x2617e67f,0xfb16410c,0xa8bfffff,
    0xfff35fff,0x3ffffea5,0x9fff54ff,0x640fffee,0x0000006f,0x00000000,
    0x00000000,0x00000000,0x00000000,0x00000000,0x00000000,0x00000000,
    0x00000000,0x00000000,0x00000000,0x00000000,0x00000000,0x01800000,
    0x8882e217,0x88888888,0x4cccccc0,0x22099999,0x00088888,0x00000000,
    0x00000000,0x00000000,0x00000000,0x00000000,0x00000000,0x53f989d0,
    0x3ffff25f,0x5fffffff,0xfffffff9,0x3e6bffff,0x02ffffff,0x00000000,
    0x00000000,0x00000000,0x00000000,0x00000000,0x00000000,0x20c5e880,
    0x33333261,0x12cccccc,0x99999997,0x33223999,0x001ccccc,0x00000000,
    0x00000000,0x00000000,0x00000000,0x00000000,0x00000000,0x000002e0,
    0x00000000,0x00000000,0x00000000,0x00000000,0x00000000,0x00000000,
    0x00000000,0x00000000,0x00000000,0x00000000,0x00000000,0x00000000,
    0x00000000,0x00000000,0x00000000,0x00000000,
};

static signed short stb__courier_bold_21_latin1_x[224]={ 0,4,2,1,1,1,2,4,4,2,1,0,3,1,
4,1,1,1,0,1,1,1,1,1,1,1,4,3,-1,0,0,1,1,-1,0,0,0,0,0,0,0,1,0,0,
0,-1,-1,0,1,0,0,1,0,0,-1,-1,0,0,1,4,1,2,1,-1,3,0,-1,1,0,0,1,0,0,1,
1,0,1,-1,0,0,-1,0,0,1,1,0,0,-1,0,0,1,3,4,3,1,2,2,2,2,2,2,2,2,2,
2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,0,4,1,0,1,0,
4,0,2,-1,2,0,-1,1,-1,-1,2,0,2,2,3,0,1,4,3,3,2,0,0,-1,0,1,-1,-1,-1,-1,
-1,-1,-1,0,0,0,0,0,1,1,1,1,-1,-1,0,0,0,0,0,1,0,0,0,0,0,0,1,0,0,0,
0,0,0,0,-1,1,0,0,0,0,1,1,1,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,-1,0,
 };
static signed short stb__courier_bold_21_latin1_y[224]={ 15,2,3,2,2,3,4,3,3,3,3,4,12,8,
12,1,2,2,2,2,3,3,2,3,2,2,6,6,4,7,4,3,2,4,4,3,4,4,4,3,4,4,4,4,
4,4,4,3,4,3,4,3,4,4,4,4,4,4,4,3,1,3,2,18,2,6,3,6,3,6,3,6,3,3,
3,3,3,6,6,6,6,6,6,6,3,6,6,6,6,6,6,3,3,3,7,3,3,3,3,3,3,3,3,3,
3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,15,6,2,3,5,4,
3,3,3,4,2,7,8,8,4,0,1,1,2,2,2,6,3,7,14,2,2,7,2,2,2,7,-1,-1,-1,0,
0,-1,4,3,-1,-1,-1,0,-1,-1,-1,0,4,0,-1,-1,-1,0,0,6,3,-1,-1,-1,0,-1,4,3,2,2,
2,3,3,2,6,6,2,2,2,3,2,2,2,3,3,3,2,2,2,3,3,4,5,2,2,2,3,2,3,3,
 };
static unsigned short stb__courier_bold_21_latin1_w[224]={ 0,3,7,9,9,9,9,3,6,5,9,11,5,9,
3,9,9,9,10,9,9,9,10,9,9,10,3,5,12,11,12,9,9,13,11,11,11,11,11,12,11,9,12,12,
11,13,12,11,10,11,12,10,11,11,13,13,11,11,9,5,9,5,9,13,5,11,12,10,12,11,10,12,11,9,
8,11,9,13,11,11,12,12,11,9,10,11,12,13,11,11,9,6,3,5,10,10,10,10,10,10,10,10,10,10,
10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,0,3,9,11,9,11,
3,11,7,13,7,11,12,9,13,13,7,11,6,7,5,11,10,3,5,6,7,11,12,13,12,9,13,13,13,13,
13,13,13,11,11,11,11,11,9,9,9,9,12,12,11,11,11,11,11,9,11,11,11,11,11,11,10,10,11,11,
11,11,11,11,13,10,11,11,11,11,9,9,9,9,11,11,11,11,11,11,11,11,11,11,11,11,11,11,12,11,
 };
static unsigned short stb__courier_bold_21_latin1_h[224]={ 0,14,6,15,16,13,12,7,15,15,9,11,6,3,
4,17,14,13,13,14,12,13,14,13,14,14,10,11,11,6,11,13,15,11,11,13,11,11,11,13,11,11,12,11,
11,11,11,13,11,15,11,13,11,12,11,11,11,11,11,15,17,15,7,3,4,10,13,10,13,10,12,13,12,12,
16,12,12,9,9,10,13,13,9,10,13,10,9,9,9,13,9,15,15,15,5,12,12,12,12,12,12,12,12,12,
12,12,12,12,12,12,12,12,12,12,12,12,12,12,12,12,12,12,12,12,12,12,12,12,0,13,14,12,9,11,
15,14,3,12,7,8,7,3,12,3,7,14,8,8,4,13,14,4,5,8,7,8,13,13,13,12,16,16,16,15,
15,16,11,16,16,16,16,15,16,16,16,15,11,15,17,17,17,16,16,8,14,17,17,17,16,16,11,13,14,14,
14,13,13,14,10,13,14,14,14,13,13,13,13,12,13,12,14,14,14,13,13,11,12,14,14,14,13,17,16,16,
 };
static unsigned short stb__courier_bold_21_latin1_s[224]={ 253,244,206,79,243,244,216,190,213,107,84,
156,214,43,241,47,85,13,23,221,226,73,231,93,106,95,252,249,91,194,181,
149,154,66,104,172,138,126,28,196,68,116,236,80,54,40,93,232,80,187,15,
25,118,22,1,239,227,215,205,148,37,113,151,29,1,198,59,210,108,164,11,
95,44,34,142,56,1,233,37,186,136,159,25,176,72,221,71,1,59,36,49,
119,126,142,226,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,
205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,253,248,187,
121,15,106,103,163,7,177,182,94,161,43,191,15,143,175,247,116,245,61,140,
237,220,124,174,131,123,34,48,133,151,165,179,89,199,193,142,207,219,130,231,
130,45,1,11,164,168,174,1,57,93,21,33,106,220,81,69,13,67,55,194,
48,1,61,209,83,1,13,150,221,73,25,37,1,103,83,113,167,242,155,197,
128,151,209,184,130,143,232,49,116,13,25,117,105, };
static unsigned short stb__courier_bold_21_latin1_t[224]={ 1,19,104,19,1,51,65,104,19,19,104,
79,104,114,104,1,36,51,51,36,65,51,36,51,36,36,19,65,92,104,79,
51,19,92,92,51,92,92,92,51,79,92,65,79,92,92,79,51,92,19,92,
65,79,79,92,79,79,79,79,19,1,19,104,114,114,92,65,92,65,92,79,
65,79,79,1,79,79,92,104,92,51,51,104,92,65,92,104,104,104,65,104,
19,19,19,104,65,65,65,65,65,65,65,65,65,65,65,65,65,65,65,65,
65,65,65,65,65,65,65,65,65,65,65,65,65,65,65,65,65,1,19,36,
65,104,79,19,36,114,65,104,104,104,114,65,114,104,36,92,104,104,51,36,
104,104,104,104,104,51,51,51,65,1,1,1,19,19,1,79,1,1,1,1,
19,19,19,19,19,79,19,1,1,1,19,19,104,19,1,1,1,19,19,79,
65,36,36,36,65,65,36,92,51,36,36,36,51,51,51,51,65,36,65,36,
36,36,51,51,79,65,19,36,36,65,1,1,1, };
static unsigned short stb__courier_bold_21_latin1_a[224]={ 178,178,178,178,178,178,178,178,
178,178,178,178,178,178,178,178,178,178,178,178,178,178,178,178,
178,178,178,178,178,178,178,178,178,178,178,178,178,178,178,178,
178,178,178,178,178,178,178,178,178,178,178,178,178,178,178,178,
178,178,178,178,178,178,178,178,178,178,178,178,178,178,178,178,
178,178,178,178,178,178,178,178,178,178,178,178,178,178,178,178,
178,178,178,178,178,178,178,178,178,178,178,178,178,178,178,178,
178,178,178,178,178,178,178,178,178,178,178,178,178,178,178,178,
178,178,178,178,178,178,178,178,178,178,178,178,178,178,178,178,
178,178,178,178,178,178,178,178,178,178,178,178,178,178,178,178,
178,178,178,178,178,178,178,178,178,178,178,178,178,178,178,178,
178,178,178,178,178,178,178,178,178,178,178,178,178,178,178,178,
178,178,178,178,178,178,178,178,178,178,178,178,178,178,178,178,
178,178,178,178,178,178,178,178,178,178,178,178,178,178,178,178,
178,178,178,178,178,178,178,178, };

// Call this function with
//    font: NULL or array length
//    data: NULL or specified size
//    height: STB_FONT_courier_bold_21_latin1_BITMAP_HEIGHT or STB_FONT_courier_bold_21_latin1_BITMAP_HEIGHT_POW2
//    return value: spacing between lines
static void stb_font_courier_bold_21_latin1(stb_fontchar font[STB_FONT_courier_bold_21_latin1_NUM_CHARS],
                unsigned char data[STB_FONT_courier_bold_21_latin1_BITMAP_HEIGHT][STB_FONT_courier_bold_21_latin1_BITMAP_WIDTH],
                int height)
{
    int i,j;
    if (data != 0) {
        unsigned int *bits = stb__courier_bold_21_latin1_pixels;
        unsigned int bitpack = *bits++, numbits = 32;
        for (i=0; i < STB_FONT_courier_bold_21_latin1_BITMAP_WIDTH*height; ++i)
            data[0][i] = 0;  // zero entire bitmap
        for (j=1; j < STB_FONT_courier_bold_21_latin1_BITMAP_HEIGHT-1; ++j) {
            for (i=1; i < STB_FONT_courier_bold_21_latin1_BITMAP_WIDTH-1; ++i) {
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
        float recip_width = 1.0f / STB_FONT_courier_bold_21_latin1_BITMAP_WIDTH;
        float recip_height = 1.0f / height;
        for (i=0; i < STB_FONT_courier_bold_21_latin1_NUM_CHARS; ++i) {
            // pad characters so they bilerp from empty space around each character
            font[i].s0 = (stb__courier_bold_21_latin1_s[i]) * recip_width;
            font[i].t0 = (stb__courier_bold_21_latin1_t[i]) * recip_height;
            font[i].s1 = (stb__courier_bold_21_latin1_s[i] + stb__courier_bold_21_latin1_w[i]) * recip_width;
            font[i].t1 = (stb__courier_bold_21_latin1_t[i] + stb__courier_bold_21_latin1_h[i]) * recip_height;
            font[i].x0 = stb__courier_bold_21_latin1_x[i];
            font[i].y0 = stb__courier_bold_21_latin1_y[i];
            font[i].x1 = stb__courier_bold_21_latin1_x[i] + stb__courier_bold_21_latin1_w[i];
            font[i].y1 = stb__courier_bold_21_latin1_y[i] + stb__courier_bold_21_latin1_h[i];
            font[i].advance_int = (stb__courier_bold_21_latin1_a[i]+8)>>4;
            font[i].s0f = (stb__courier_bold_21_latin1_s[i] - 0.5f) * recip_width;
            font[i].t0f = (stb__courier_bold_21_latin1_t[i] - 0.5f) * recip_height;
            font[i].s1f = (stb__courier_bold_21_latin1_s[i] + stb__courier_bold_21_latin1_w[i] + 0.5f) * recip_width;
            font[i].t1f = (stb__courier_bold_21_latin1_t[i] + stb__courier_bold_21_latin1_h[i] + 0.5f) * recip_height;
            font[i].x0f = stb__courier_bold_21_latin1_x[i] - 0.5f;
            font[i].y0f = stb__courier_bold_21_latin1_y[i] - 0.5f;
            font[i].x1f = stb__courier_bold_21_latin1_x[i] + stb__courier_bold_21_latin1_w[i] + 0.5f;
            font[i].y1f = stb__courier_bold_21_latin1_y[i] + stb__courier_bold_21_latin1_h[i] + 0.5f;
            font[i].advance = stb__courier_bold_21_latin1_a[i]/16.0f;
        }
    }
}

#ifndef STB_SOMEFONT_CREATE
#define STB_SOMEFONT_CREATE              stb_font_courier_bold_21_latin1
#define STB_SOMEFONT_BITMAP_WIDTH        STB_FONT_courier_bold_21_latin1_BITMAP_WIDTH
#define STB_SOMEFONT_BITMAP_HEIGHT       STB_FONT_courier_bold_21_latin1_BITMAP_HEIGHT
#define STB_SOMEFONT_BITMAP_HEIGHT_POW2  STB_FONT_courier_bold_21_latin1_BITMAP_HEIGHT_POW2
#define STB_SOMEFONT_FIRST_CHAR          STB_FONT_courier_bold_21_latin1_FIRST_CHAR
#define STB_SOMEFONT_NUM_CHARS           STB_FONT_courier_bold_21_latin1_NUM_CHARS
#define STB_SOMEFONT_LINE_SPACING        STB_FONT_courier_bold_21_latin1_LINE_SPACING
#endif
