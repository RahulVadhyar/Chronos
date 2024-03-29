// Font generated by stb_font_inl_generator.c (4/1 bpp)
//
// Following instructions show how to use the only included font, whatever it is, in
// a generic way so you can replace it with any other font by changing the include.
// To use multiple fonts, replace STB_SOMEFONT_* below with STB_FONT_courier_bold_33_usascii_*,
// and separately install each font. Note that the CREATE function call has a
// totally different name; it's just 'stb_font_courier_bold_33_usascii'.
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

#define STB_FONT_courier_bold_33_usascii_BITMAP_WIDTH         256
#define STB_FONT_courier_bold_33_usascii_BITMAP_HEIGHT        120
#define STB_FONT_courier_bold_33_usascii_BITMAP_HEIGHT_POW2   128

#define STB_FONT_courier_bold_33_usascii_FIRST_CHAR            32
#define STB_FONT_courier_bold_33_usascii_NUM_CHARS             95

#define STB_FONT_courier_bold_33_usascii_LINE_SPACING          16

static unsigned int stb__courier_bold_33_usascii_pixels[]={
    0x000d5540,0x00801b88,0x2a000550,0x22018800,0x3005442c,0xa8835555,
    0x0ee0aaaa,0xbd12f440,0x55e5cc00,0x37b2a000,0x0262000b,0x00988000,
    0x00133100,0xaaaaaa98,0x64c00aaa,0x8002ceed,0xb0004ffe,0x06fa80df,
    0x2000ffd4,0xfb300ffb,0x83ff605f,0xffb03fff,0x3fe29fff,0xff51ffff,
    0x23ff9005,0x74c02ffa,0x03ffffff,0xefffffc8,0x3fff6200,0xdfffbbef,
    0x27fffae2,0x04fffffc,0xbffffd50,0x909dfff3,0xffffffff,0x7ffec0ff,
    0x000dffff,0x20013ffa,0x7e406ff9,0x17fea00f,0x201ff900,0xfb83fffe,
    0x1ffffc7f,0xa7ffffec,0x1ffffff9,0xc801fff3,0x05ff91ff,0x7fffffdc,
    0xf900efff,0x1dff95bf,0xffffff70,0xdfffffff,0x3fffffe2,0xefffffff,
    0x3ffff601,0xffffffff,0x7fffe41f,0x80ffffff,0xfffffffc,0x32e005ff,
    0xffd8002c,0x2fffa203,0x03fff008,0x4c0ffec0,0xffd02eff,0x86ffc987,
    0x20accffd,0x21ffecb9,0x7ec04ffe,0x203ff91f,0xa9befff9,0xf985fffc,
    0x542ff83f,0xffddffff,0x22efffff,0xfffffffc,0x0ffffece,0xedffffc8,
    0x4fffffff,0xcccdffc8,0xff880bcc,0xfff731cf,0x10000005,0xf9101fff,
    0x1fffffff,0x2005ffb8,0xffc81ffd,0x01fff501,0xffb03ffa,0x43ffb001,
    0x3600fffa,0x03ffb0ff,0x260bffd1,0x2fec3fff,0x3fe24fc8,0xffff985f,
    0x3bfff603,0x237ff4c0,0x260cfff9,0x3206fffd,0xdb8001ff,0x009ff701,
    0x9ff90000,0x3fffffe0,0x7c42ffff,0xffb000ff,0x203ffb03,0x3f604ffe,
    0x007fec0f,0x3fa0ffec,0x43ffa03f,0xffc80ffd,0x07ffcc05,0x9be605ff,
    0x3e605ffc,0x3ff603ff,0x87ffa206,0x3fa05ffc,0x07ff206f,0x3fe20000,
    0xffffec85,0x8802ffff,0xffa80fff,0xfffdbbdf,0x004ffc83,0xffb03ffb,
    0x01fff303,0x3f607fec,0x1ffd800f,0xf883ffdc,0x1ffe99ff,0xd800ffe8,
    0x81ff32ff,0x3f66fdb9,0x1ffec01f,0xb807ffb0,0x07ffa3ff,0x3206ffb8,
    0x09ba9aff,0x27fe4000,0x3fffffe6,0xc802ffff,0x3ffb04ff,0xf103ff30,
    0xffb001ff,0x903ffb03,0xffd80bff,0x4007fec0,0xfff81ffd,0x3ffffa61,
    0x1effffff,0x2a00bff1,0xc8ff53ff,0x3fa6ffff,0x1ffdc00f,0xa803ffb0,
    0x01ffe4ff,0x7e40dff1,0x3fffffff,0x3f6aa200,0xfffd81ff,0x02ffffff,
    0xe807ffc4,0x407700ff,0xfd803ffc,0x81ffd81f,0x7ec03ffd,0x007fec0f,
    0x7f40ffec,0x3fffee3f,0xffffffff,0x2009ff34,0x4bf55ff8,0x26fdfffc,
    0x3e203ffd,0x3ff603ff,0xd17ff405,0x7fdc03ff,0x3ffff206,0x805fffff,
    0x3ffffff9,0x02ffb800,0xf702ffdc,0x880015df,0xffd807ff,0xe80ffd81,
    0x7fec02ff,0x4007fec0,0xffc81ffd,0x3fffb224,0x0cefffee,0x7c007ff5,
    0x3e2bf76f,0x7dcdf33f,0xfff901ff,0x17ffec07,0x360fffb8,0x3ffa04ff,
    0x3bffee06,0x03fffebc,0x7fffffd4,0x2ffb8001,0x100fffc0,0x59dfffff,
    0x00fff600,0x7e4c3ffb,0x01fff07f,0x362effc8,0xffd800ff,0x985ffb81,
    0x0bff15ff,0x22009ff3,0x2abf75ff,0xe89be66f,0xfc9befff,0x3603ffff,
    0xc9beffff,0x7d44ffff,0x3f220bff,0x05dc06ff,0x5403ffdc,0x00ffffed,
    0x5017fdc0,0xff500bff,0x05ffffff,0x6c06ff98,0x3fffe1ff,0x807ff984,
    0xfb2ffff9,0x3ffb001f,0xf30dff50,0x217fe69f,0xf5006ff8,0x7cd7ee9f,
    0xfd11be66,0xffffffff,0x7fec07ff,0xffffffff,0xffffb05f,0xdfffffb9,
    0x1fff8000,0x1bffa600,0x405ff700,0x51001ffe,0x3fffffdb,0x202ffd80,
    0x3ffa1ffd,0x07ff985f,0xb2ffff98,0xffb001ff,0x50dff503,0x13fe69ff,
    0x7400fff4,0x74bf72ff,0x886f98bf,0xeffffffc,0x3f603ffd,0xffffffcf,
    0x3ffa203f,0xffffffff,0x7fe40006,0x7ffc4002,0x0bfee000,0x00037fd4,
    0x80bffd71,0x3f606ffa,0x1ffee21f,0x32007ffc,0x3ff61dff,0x81ffd800,
    0x3ff25ffb,0xffffffff,0x037fdc3f,0x5fa9bfee,0x3fffffee,0x57995300,
    0xfd80ffea,0x1599950f,0x3fffee00,0x006ffbef,0x0017fe40,0x70017fe4,
    0x3ffa05ff,0x101e4402,0xffd00fff,0x207ff605,0xffe80ffd,0x207fec02,
    0xfd800ffd,0x14ffc81f,0xffffffff,0xfd0fffff,0xfff701df,0x36637c45,
    0x8002ffff,0x3f603ffa,0x2600000f,0x0dff11aa,0x01fff800,0x001ffd80,
    0x3e60bfee,0x1ffb806f,0x2a01ffe0,0x3ffb06ff,0xfb03ffb0,0x0ffd807f,
    0x6c007fec,0x2ffe81ff,0x3bbfffae,0x982deffe,0xeccdffff,0x07f85fff,
    0x20001331,0x3f603ffa,0x4000000f,0x5b704ffa,0x223ffdc0,0x1ffea00b,
    0xb05ff700,0xff9007ff,0x4ffc883d,0xb03ffd00,0x3ffb03ff,0xd80bff90,
    0x07fec0ff,0x220ffec0,0xffc81fff,0x9805ff71,0xffffffff,0x007fd03f,
    0x0ffea000,0x0000ffd8,0x0bffa600,0x66677ffc,0x743fffec,0xeccbcdff,
    0x5c005fff,0x3ffcc2ff,0xeffffc80,0x00ffffec,0xfb0bff70,0x03ffb03f,
    0x6c01fff3,0x07fec0ff,0x2e0ffec0,0x3ffb06ff,0x22007ff2,0x2dfffffd,
    0x0001bee0,0xeffeeda8,0x3fff6e1d,0x50001cee,0xffffdddb,0x3ffee01d,
    0x5fffffff,0xffffffd8,0x8005ffff,0x7fe42ffb,0xffff7003,0x09ffffff,
    0x6c1fff80,0x1ffd81ff,0x6c09ffb0,0x07fec0ff,0x3e0ffec0,0x1ffb03ff,
    0x22007ff2,0x442efffe,0x5c2fec0b,0x3ffe002f,0xf16fffff,0xbfffffff,
    0x3fffe000,0x400effff,0xffffffea,0xfff9102e,0x007dffff,0xf88bfee0,
    0xbd1000ff,0x5bfffff9,0x89ff7000,0xffd81ffd,0x01fff501,0xffb03ffa,
    0x43ffb001,0xfd00fffb,0x003ff61f,0xffffffd1,0x88bffbbf,0xfffeefff,
    0x3fff2002,0x3f63ffff,0x02ffffff,0xfffff900,0x4c40017b,0x260009aa,
    0x80001aa9,0x3ff20ffe,0x7fec0004,0x3fe20001,0x207ff60f,0xfd01dffb,
    0x5ffb889f,0x41abffd8,0x21ffeaa8,0x3fa04ffe,0x7003ffa7,0xffffffff,
    0xb309ffff,0x007fffff,0x00000000,0x00000000,0x44000000,0x3fe27ffb,
    0x7ec0000f,0x7e40001f,0x203ff24f,0xa82ffff8,0x7fffc7ff,0xfffffd82,
    0xffffff14,0x803ffea3,0x01ff66fe,0x3337ffea,0x403dfffd,0x00001aa8,
    0x00000000,0x00000000,0x77764000,0x2e3ffffe,0xd80004ff,0x440001ff,
    0x03ff27ff,0xc81fffcc,0x13ffe0ff,0xafffffec,0x1ffffff9,0xc9805ff5,
    0x44007261,0x00002600,0xcccccc88,0x443ccccc,0x99999999,0x19999999,
    0x00000000,0xfa800000,0x3fffffff,0x00007fd4,0x80003fdc,0x200dc6fc,
    0x20dc02a8,0x332e00b9,0x32e60acc,0x00aa0ccc,0x00000000,0x7ffcc000,
    0xffffffff,0x3fffff66,0xffffffff,0x002fffff,0x00000000,0x3ffa2000,
    0x1302ceff,0x06e20000,0x00008000,0x00000000,0x00000000,0x00000000,
    0x3fffffe6,0x3e6fffff,0xffffffff,0xffffffff,0x000004ff,0x00000000,
    0x00000000,0x00000000,0x00000000,0x00000000,0x00000000,0x88888880,
    0x65408888,0xdddddddd,0xdddddddd,0x0000000c,0x00000000,0x00000000,
    0x00000000,0x00000000,0x00000000,0x00000000,0x00000000,0x00000000,
    0x80000000,0x7ff64000,0x7ffecc3e,0x402f6a2d,0x000adeca,0x81676544,
    0x201cedb9,0x0002aaa8,0x55555555,0x00055555,0xb8015553,0x8001cdec,
    0x8009aaa9,0xa8802aa9,0x10000aaa,0x01555555,0x20002a20,0x0001aaa9,
    0x033ff660,0xffffff30,0x6fffffc8,0xfb09fff3,0x003fffff,0xffffffd3,
    0xfffffc87,0xffff884f,0xfffd0007,0xffffffff,0xfffd800d,0xfffd303f,
    0x2a009fff,0xeffffffe,0x017ff201,0x00bffffa,0x7ffffec0,0x0bf9001f,
    0x5ffffa80,0xbff30000,0xffb00ffb,0xffe989ff,0xdfff93ff,0xffffffd8,
    0x3fe600ef,0x24ffffff,0xfffffffc,0x7fffc44f,0xfffd0007,0xffffffff,
    0xfffd800d,0xffff983f,0x405fffff,0xfffffff9,0x3ff203ff,0xffffe805,
    0xfffd0002,0x3a003fff,0x7fd4007f,0xb00005ff,0x4017d41f,0xff104ffd,
    0x37ffe41f,0xd539fff5,0x3fe60bff,0xf8531bef,0xffd99dff,0x3ff5441f,
    0xccffd800,0x5ffdcccc,0x7fed4400,0x8beffe83,0x202fffc9,0xdcbceffe,
    0x332a01ee,0xffda8803,0x55510002,0x3a003ffd,0xfb98007f,0xf880005f,
    0xf8806f85,0x4ffc80ff,0xfb37ffdc,0x81ffd05f,0x400efff9,0xffc84ffa,
    0x000ffd05,0xffc813ea,0x7ff70003,0xc80fff88,0xdff104ff,0x90000000,
    0x200005ff,0xfd001ffd,0x3fe2000f,0x8df00005,0xff9005f8,0x40fff889,
    0xff15fffb,0xd0bfea0d,0xf9001bff,0x1fff105f,0x0988ffd0,0x0ffe8000,
    0x3ee09980,0x82ffcc3f,0xff305ff9,0x0000000b,0x00005ff9,0xda807ff6,
    0xffffffff,0x3fe204ef,0x20002665,0x03f913fc,0xc83ffe20,0xfffa84ff,
    0x2207ff54,0x1ffe65ff,0x3607fe80,0x9ffe81ff,0x04fffffc,0x40dff300,
    0xaeffffd9,0x7fc43ffb,0x449ff707,0xfffffffd,0xfd503eff,0x2001ffff,
    0xffb32ffc,0x3f6009ff,0x3fff601f,0xffffffff,0x9dff101f,0x007dffff,
    0x37ffffc4,0x7fe40951,0x301fff14,0x3fee9fff,0xfc9ffe02,0x0159754f,
    0xff103ffb,0xffffd05f,0x3dffffff,0x03ffc800,0xfffffff7,0xfd07ffff,
    0x7ffd419f,0x3ffffea2,0x07ffffff,0x1ffffffd,0x64bff200,0x02ffffff,
    0x2a01ffd8,0xfffffffe,0x3e205fff,0xffffffff,0x6f54004f,0x0fffdb89,
    0xf91fff10,0x3ffe209f,0x7403ff93,0xd7ffb0ff,0xc83dffff,0xfffd84ff,
    0xfffffe83,0x0fffffdf,0x203ffe00,0xfdeffffb,0x983fffff,0xfffeffff,
    0x7ffec45f,0x4fffffff,0xfffffd70,0x4bff2001,0x0dfffffc,0x001ffd80,
    0x22000ffd,0xfcefffff,0x44001fff,0x0befffdb,0x7feffe40,0x4bffe00f,
    0x3fa01ffc,0xfffffd0f,0x4c3fffff,0xfc88bfff,0xffe84fff,0x3fae22ef,
    0xdff3005f,0x43bfff30,0x03ffffc8,0xfffffff9,0x2ffcc01f,0x03ff6000,
    0x7dd7fe40,0x6c001eff,0xffd001ff,0x3ffe2000,0x027fdc1e,0x6ffff5c4,
    0x3fe2000b,0x7fc04fff,0x403ff91f,0xfffd0ffe,0xdfff77ff,0xffffffc8,
    0xfe85ffff,0xfff300ff,0x07ff9003,0x7dc0dff9,0xffe883ff,0x04ffffff,
    0x00017fe6,0x32001ffb,0x0dfffeff,0x01ffd800,0x2000ffd0,0xf880eff8,
    0x7ffdc06f,0x002da8bd,0x007fffe4,0x7fe47ffa,0x6c3ffa02,0x7fc46fff,
    0x7fffec2f,0xe83ffdff,0x7ff404ff,0x80fff803,0x3e202ffe,0xfffe83ff,
    0x2fffeb9d,0x000bff30,0x9000ffd8,0x009fffff,0x800ffec0,0xf10007fe,
    0x037fc0bf,0x7fcc2b6a,0xf1002fff,0xffb009ff,0xff01ffd4,0x407ffe4f,
    0xfda84ffc,0x81ffc9df,0x7d401ffe,0x37fcc04f,0xfc807ff8,0x07ffcc3f,
    0xf982ffe4,0x7ec0005f,0xfff9000f,0x20001bff,0xfd001ffd,0x3fe2000f,
    0x001bfe05,0x1baa2ffa,0x007ffc40,0x9ff10e44,0xfa97fe20,0x0bff304f,
    0x203ffe20,0x7dc02ffe,0x1ffe404f,0x6c00fff8,0x27fdc3ff,0xf307ff88,
    0xfd8000bf,0xfff9000f,0x0001dfff,0x3a003ffb,0xff10007f,0x0037fc0b,
    0x05f713e6,0x0009ffb0,0xfc80ffe8,0x41bfe63f,0xe8804ffb,0xbffd04ff,
    0x402ffe80,0xffb00fff,0x1fffc407,0xff80ffee,0x00bff307,0x000ffd80,
    0xfff35ff9,0xffd8003f,0x03ffd001,0xff105b51,0x0037fc0b,0x09f30bee,
    0x000fff98,0x506ffe40,0xffe81fff,0x01fff443,0xe81bffaa,0x5c40afff,
    0x3e600fff,0x3bfee06f,0x3fffd981,0x5c07ffcc,0xbff305ff,0x0ffd8000,
    0x265ff900,0x2001fffe,0xf9001ffd,0xffdb7bdf,0x5ff881ff,0x1001bfe0,
    0x5c0fc8bf,0xdfffeeed,0x441b8801,0xffecfffe,0xefff984f,0x50ffffdc,
    0xfffd99bd,0xfffd901f,0xffb7bfff,0xffc807ff,0x7ffff403,0xfffffebc,
    0x3fffe1df,0x3ffffdce,0x3fffff6a,0xb81dffff,0xfffffffe,0x3aa0dfff,
    0x3fe62fff,0x3ae1dfff,0xffffffff,0xff980dff,0xffffffff,0x77fff645,
    0x3bfffae1,0x2fbf2002,0x7ffcc5fd,0x05ffffff,0x7cc1ffe8,0x05ffffff,
    0x3fffffee,0x3fff62ff,0x881effff,0xffffffff,0x04ffffff,0x4400ffe8,
    0xfffffffe,0x25ffffff,0xffffffe8,0x7ffec4ff,0xffffffff,0x7ffffc45,
    0xffffffff,0x8bffffa3,0x4ffffffa,0x3ffffffe,0x03ffffff,0xffffffd3,
    0xffff983b,0xffff15ff,0x64400dff,0x7440cfff,0xffffffff,0x80ffe802,
    0x04ffffea,0xeffffdb8,0x7ffff541,0x7ffec02e,0xfffffebf,0x07f5001e,
    0x7ffffe40,0x2efffddf,0x7ffffec4,0xfffea82e,0x1effffff,0xffffffc8,
    0x20dfffff,0x222fffeb,0x21effffd,0xfffffffc,0x401dffff,0x6c00aaa9,
    0x322effff,0x003effff,0x00000150,0xa8801510,0x0aa88001,0x0004d440,
    0x004d54c0,0x55300000,0x2a200013,0x00000001,0x00000000,0x00000000,
    0x00000000,0x00000000,0x00000000,0x00000000,0x00000000,0x00000000,
    0x00000000,0x00000000,0xb9800000,0x22000abc,0x000cdeca,0x44015554,
    0x988000db,0x09999999,0xaccba880,0xcca80010,0x4ccc021b,0x09999809,
    0x0de65d40,0x17997500,0x33333102,0x33333333,0x33333303,0x33300033,
    0x4cccc013,0x20133300,0x93009998,0xffd3005b,0x7007ffff,0x7fffffff,
    0x1fffea00,0x3fffb2a2,0x7fff4001,0x3fffffff,0xfffffd10,0x980bfdff,
    0xeffffffd,0x3ffea4fd,0xfff35fff,0xfc88dfff,0x0cffffff,0x3ffffaa0,
    0x3fa5fdff,0xffffffff,0xf31fffff,0xffffffff,0xffa805df,0x7d46ffff,
    0x226fffff,0x546fffff,0xe84fffff,0x3ee00fff,0xffffffff,0xffff900d,
    0x009fffff,0xf98ffffd,0x01ffffff,0x3ffffe20,0x85ffffff,0xfffffff9,
    0x2607ffff,0xffffffff,0x3fee7fff,0xff56ffff,0x7c1fffff,0xffffffff,
    0xffff506f,0x4fffffff,0xfffffffe,0x1fffffff,0xfffffff7,0x40dfffff,
    0x7ffffffb,0x7fffffdc,0x3ffffe67,0x7ffffe46,0x00fffe85,0x537dfff3,
    0xf30dfff9,0xfb515bff,0x7fdc03ff,0x7ffdc7ff,0x4001ffff,0xffecccc9,
    0x7fcc0bcd,0xfca9bcef,0xff980fff,0xfebaacef,0x3fee27ff,0x3b2e1ccf,
    0x7ffc1dff,0xfffdaace,0x677ffc43,0x0ffffca9,0xfd999ffd,0x3ffd999f,
    0x6677fedc,0x04ffffdc,0x073bffae,0x39fff971,0x41fffda8,0x80bfffe8,
    0xfd103eea,0x3ffe60bf,0xd827fe43,0xfff104ff,0xacc88fff,0x0001ffd8,
    0x3a01ffd8,0x3fe205ff,0x01dfff07,0x3fa1ffee,0x417fdc07,0xdff506ff,
    0xf306ffa8,0x83ffa1ff,0x3ff20ffd,0x442ffc41,0x2600fffb,0x7fd406ff,
    0x13ffa205,0x0007fff1,0x4c05ffc8,0x1bf20fff,0xfb05ff98,0xb00ffdbf,
    0xb00003ff,0x3fea03ff,0x986fc806,0x7fe806ff,0x7dc07fe8,0x204fd82f,
    0x17fdc7ff,0x7ff4ffb0,0xfc83ff60,0x02ffc41f,0xfe805ffb,0x0bff601f,
    0x6c3fff30,0xe80005ff,0xffc801ff,0xfb802a22,0x8fff984f,0xffd807fe,
    0xffd80001,0x005ffb01,0x5ff70171,0xfd09f500,0x02ffb80f,0x237fc403,
    0x36605ffa,0xffb1ff62,0x220ffe41,0x3ff605ff,0x82ffdc01,0xf9007ff9,
    0x03ffeadf,0x01bfe000,0x10027fcc,0xffd07ffd,0x3601ffa7,0xd80001ff,
    0x1ffd01ff,0x0ffd8000,0x03ff4000,0x1000bfee,0xfff07ffd,0xbf70037d,
    0x3ea0ffd8,0x885ff887,0xf8807ffc,0x3ffc80ff,0x3f3ffa00,0x980002ff,
    0xff1004ff,0x7ffec00b,0xfd37fdc0,0x03ffb00f,0x03ffb000,0x20001bfe,
    0xe80006ff,0x17fdc07f,0xffffc980,0xfffffa81,0xb0300bdf,0x880981ff,
    0xfdccceff,0xf9003fff,0x0fff887f,0x3fffe600,0x1333005f,0x4007ff50,
    0xfe8806ff,0x7ffc41ff,0x3601ffa2,0x004401ff,0x7fc07ff6,0x33333106,
    0x006ff883,0x5c07fe80,0xffc802ff,0x3a601fff,0x4fffffff,0x001ffb00,
    0x3fffffe2,0x2003ffff,0x7fdc7ff9,0xfffc8005,0xfffb800f,0x005ff980,
    0xe880bff1,0xffc82fff,0x6c03ff45,0x3fe201ff,0x407ff600,0xfffa86ff,
    0x7fc7ffff,0x7fe80006,0x4017fdc0,0x000cfffd,0xfffffb73,0x01ffb00b,
    0x3ffffe20,0x8003ffff,0x3ffa2ffe,0x5ffd0001,0x80bff600,0xff5006ff,
    0x7fffcc09,0x41fff981,0xffd807fe,0x80bfea01,0xffd01ffd,0xffffff90,
    0x03ff43ff,0x203ff400,0xfb802ffb,0x64c0001f,0x7ec01fff,0xdff1000f,
    0x3ffff755,0x35ffa800,0x6c000dff,0xff8801ff,0x017ff405,0xfa817ff4,
    0xffb01fff,0xffffffff,0x0ffec03d,0x6c07ff70,0x1ffb01ff,0xffcccb88,
    0x00ffdc3f,0x803ff600,0xd8801ffc,0x401db803,0x7ec03ffb,0xbff1000f,
    0x01fffe98,0x7ecfffc0,0x3f60003f,0x1ffa801f,0x2037fdc0,0xff706ffb,
    0x7ff401df,0xffffffff,0x07ff605f,0x3a03ffb8,0x13fee07f,0xf303ffa0,
    0x20ee00df,0x3fa04ffc,0x7c00000f,0x27fd405f,0x4003ff60,0xfe885ff8,
    0x7fdc006f,0x0000fffd,0x36007ff6,0xdffb004f,0x05fff703,0x801bfffb,
    0xfffffffe,0x3601dfff,0x3fee01ff,0x06ffc80d,0x4033ffe2,0xfe80ffe8,
    0xffb101ef,0x82fffa85,0x00006ffd,0x9827ffc4,0x7ec03ffe,0xbff1000f,
    0x013ffe20,0x4fffff88,0x0ffec000,0xf10037c0,0xfd99bfff,0xffe889ff,
    0xe800604f,0x1ffd807f,0x3bfffee0,0x02fffecc,0x66ffffdc,0x0ffffedc,
    0xcefffe88,0x0ffffecc,0xdcffffd8,0x3001ffff,0x7fc40157,0xffdcdfff,
    0x7ec40fff,0x2effffff,0xfffffd88,0x77ffd41d,0xffffb003,0xffd88003,
    0x83efffff,0x74c001f8,0xffffffff,0xfffffb83,0x4fffffff,0x3ffff6a0,
    0xffffb11d,0x47dfffff,0xffffffe9,0xf9001fff,0xffffffff,0x7f440dff,
    0xffffffff,0x3fff602f,0x002fffff,0x4409fff1,0xffffffff,0xfb82ffff,
    0xffffffff,0xfffffb87,0xfffc84ff,0xdfff3007,0xffff7000,0x00ffffff,
    0xffff9000,0x3fee03df,0xffffffff,0x3ffa06ff,0xff75ffff,0xffffffff,
    0xfffb30ff,0x88003bff,0xffffffed,0xfdb8801d,0x00ceffff,0xefffffb8,
    0x3ffe2000,0x7e576404,0x00cfffff,0xffffffb3,0xffb107df,0x3a03dfff,
    0x3fa003ef,0xfd88002f,0x3effffff,0x2a600000,0xffffb801,0xffffffff,
    0x3fffae06,0xfffb11ef,0x7dffffff,0x0001a980,0x0006aa60,0x00013510,
    0x400026a6,0x988001a8,0x000001aa,0x00000000,0x00000000,0x00000000,
    0x00000000,0x00000000,0x00000000,0x00000000,0x00000000,0x00000000,
    0x00000000,0x40133300,0x33100999,0x40013333,0x98819999,0x33330099,
    0x26666203,0x99999980,0x33100999,0x03333013,0x26666662,0x33333001,
    0x33333333,0x33333303,0x13333333,0x33333330,0x4ccccc00,0x80999999,
    0x26601998,0x4cc40099,0x40009999,0x99999999,0x7fffc400,0x7fffd46f,
    0x7fffec3f,0x4c06ffff,0x2fffffff,0x89fffff9,0x0fffffff,0x3ffffff2,
    0xffffff33,0xa8bfffff,0xf15fffff,0x741fffff,0xffffffff,0xfff984ff,
    0xffffffff,0xff30ffff,0xffffffff,0x7cc7ffff,0xffffffff,0x3ffe603e,
    0xffffffff,0x27ffff46,0x3fffffe2,0xfffff906,0x3e6009ff,0xffffffff,
    0xff980cff,0x3f20ffff,0x7f45ffff,0x7fffffff,0x7ffffdc0,0xffffd4ff,
    0x7fffccdf,0x3ffa2fff,0xff75ffff,0xffffffff,0xffffc8ff,0xfffff57f,
    0x3fffe23f,0xffffffff,0x3fffee0e,0xffffffff,0xfff70fff,0xffffffff,
    0x7fdc7fff,0xffffffff,0xfff981ef,0xffffffff,0x3ffffe26,0x3fffea1f,
    0xffd80fff,0x00ffffff,0xffffffb8,0x0effffff,0x42fffea8,0x40cfffe8,
    0xceffdcc9,0x7edc401c,0xff50bcef,0xffb839ff,0x65cc2ccf,0x9710dffe,
    0x99bffd99,0xeffc8839,0x3fff2a1c,0x67ffe542,0x6ffffdcc,0x6677fe5c,
    0xfffccccc,0x33bff2e0,0xffdccccc,0x667ff5c3,0x0fffffdc,0x66677fcc,
    0x545fffcc,0x546ffffc,0x102dffdc,0xfffff997,0xffb71007,0xfffb999d,
    0x3ffa20bf,0x01fffcc5,0x4001ffd4,0x7fcc5ff9,0x3ffa01ff,0x02ffc800,
    0x4c00ffec,0x1bfe05ff,0xff307fe8,0x05ff885f,0x3e207ff4,0x0ffee05f,
    0x3e603ff6,0x27fcc6ff,0xe807ffe4,0xfb83ffff,0xfff5003f,0x7cc00dff,
    0x3fff305f,0x453ffe60,0xf5005fff,0xff30007f,0x077ffd4b,0xfe87ff60,
    0x007ff62f,0xf3003ffb,0x037fc0bf,0x7fdc0ffd,0x022ffc44,0xbff10ffb,
    0x20bfea08,0xff300ffd,0x227fcc3f,0x3a02fffa,0x5c0fffff,0xffb003ff,
    0x2003ffd5,0x3f205ff9,0x3ffea02f,0x2006ffeb,0x98003ffa,0xbfff75ff,
    0x25ff9001,0x3fa5fff9,0x0ffec00f,0xf02ffcc0,0x03ff40df,0xff88bff3,
    0x4fa9bea5,0x3ea5ff88,0xfb01dd16,0x2ffd401f,0x7fc47ff1,0x77ff404f,
    0x1ffdc5ff,0xfbbffc40,0xbff3004f,0x200fff40,0x0ffffffb,0x00ffea00,
    0x3f77fe60,0x3ee005ff,0x1ffff93f,0x3f601ffe,0x5ff9801f,0xfe81bfe0,
    0x10fff607,0x07fe4bff,0x4cf7fc40,0xfd800ffd,0x1bfe200f,0x3ffa2195,
    0xf9ffe805,0x0ffee2ff,0x7c53ff20,0xff9800ff,0x3fff64c5,0x1ffffd80,
    0x01ffd400,0x7ffffcc0,0x3ea001ff,0x5ffffd4f,0x3f601bfe,0xfff9801f,
    0xffffffff,0x2a1ffa06,0x7c41fffc,0x1fffffff,0xfffff880,0xfd801fff,
    0x03ffc00f,0x2003bff6,0xfffb8ffe,0xf007ff70,0x1ffe41ff,0x7ffffcc0,
    0x02ffffff,0x00dfff50,0x0007ff50,0xfffffff3,0x3fe6003f,0xdfffff9d,
    0xfd805ff8,0xfff9801f,0xffffffff,0x3bbffa06,0x84fffffe,0xfffffff8,
    0xfff8801f,0x801fffff,0x7f400ffd,0x3fff700f,0x743ffa00,0x07ff74ff,
    0x7cc5ffa8,0xfff9806f,0xffffffff,0xffff9803,0x7fd4005f,0xf302e603,
    0xfffd7fff,0x9bff1003,0xf5fff7ff,0x3ffb009f,0xddfff300,0x0dffdddd,
    0x7ffffff4,0xff103fff,0x03fffddf,0xfddfff10,0xffb003ff,0x307fe801,
    0x74007fff,0x3fff30ff,0xfd807ff7,0xffccccdf,0x7ffcc01f,0xffffeeee,
    0x3ffa203f,0x2003fffe,0x3fe03ffa,0xb0fffcc3,0x3fe00fff,0xffc8ffef,
    0xfd804ffe,0x5ff9801f,0xfe81bfe0,0x0defffff,0xfc97fe20,0x5ff8800f,
    0x80a83ff2,0x3e200ffd,0x4fff886f,0xffe82f44,0x3efbff20,0x3ffe203f,
    0xffffffff,0x42ffcc04,0x00fffda8,0xff51dffb,0x3fea005f,0x98bff103,
    0x3ffe85ff,0x6fffff80,0x07fffff5,0x3003ffb0,0x37fc0bff,0x2000ffd0,
    0x13a65ff8,0xd32ffc40,0x7ec37dc9,0x17fe600f,0x3ea1bff6,0x40ffe81f,
    0x03fffffe,0x3ffffff2,0x00ffffff,0xfb017fe6,0x1fff907f,0x400fffdc,
    0xff103ffa,0x985ff98b,0x7f400fff,0x3ffe3fff,0xffd802ff,0x05ff9801,
    0x7fe81bfe,0x0bff1000,0x02ffc400,0xffb03ff6,0x0fffa201,0xf701fff9,
    0x81ffd05f,0x03fffffa,0x2aaafffe,0x03ffdaaa,0xf5017fe6,0x2fffb89f,
    0x400effd8,0xff103ffa,0x905ff98b,0xffd809ff,0x3fff21ff,0x1ffd801f,
    0x205ff980,0x1ffa06ff,0x02ffc400,0x80bff100,0x7fec0ffe,0x37ff5440,
    0x5c0bffea,0x0ffe82ff,0x03ffffd8,0xf980bff5,0x17fe606f,0x99ffecc4,
    0x20dffffd,0x44efffea,0xffffffea,0x5fffffff,0xbfffffb1,0x6ffffc43,
    0x46fffc80,0x440ffff9,0xfffffffd,0x7f643eff,0x3ff23eff,0x3fb22eff,
    0x02dfffff,0x3fffff62,0x6c400dff,0xffffffff,0x10ffffff,0xfffffffb,
    0xe83fffff,0xffffffff,0x3622ffff,0x223effff,0x6c43ffff,0x443effff,
    0x23effffd,0xffffffd8,0xffffffff,0xffffff90,0x7fffff45,0x3ffffe0f,
    0xffffffff,0xffff75ff,0xffc89fff,0xfffb83ff,0xb87fff84,0xffffffff,
    0x3fe67fff,0xff57ffff,0x3e2dffff,0xffffffff,0x3fffee06,0x404fffff,
    0xfffffffb,0xffffffff,0xffffff70,0x03dfffff,0xfffffffd,0x5c5fffff,
    0x47ffffff,0x7dc3fffa,0x5c7fffff,0x27ffffff,0xfffffffb,0x2fffffff,
    0x37ffffa6,0x3ffffaa0,0x7ffff5c4,0xffffffff,0xffffb15f,0xfff983df,
    0x1fffa80d,0xd886ffc8,0xffffffff,0x7ffec3ef,0xfffb13ef,0x7ffe47df,
    0x202effff,0xffffffd8,0x7ec401df,0xffffffff,0xb10fffff,0xbfffffff,
    0x7fff4059,0xffffffff,0x3fff662f,0x3ffd83ef,0x7ffffecc,0x7fffecc4,
    0x3fff624f,0xefffffff,0x0000000c,0x00000000,0x00000000,0x00000000,
    0x00000000,0x00000000,0x00000000,0x00000000,0x00ccc400,0x40026662,
    0x006a2009,0x00d44000,0x03510000,0x00019988,0x20001331,0x4c000098,
    0x02600019,0x18813000,0x000cdb80,0xfd880131,0x7fed45ff,0x0220007f,
    0x01ffffe8,0x413ffff2,0x1eefffd8,0x000effe4,0x001fee00,0x07ffdc00,
    0x3ffffb66,0x7e4401df,0x1eceffff,0x3ffff620,0xfd5001de,0x3b7bffff,
    0x3fff6e20,0xff9101ce,0xb3bfff7f,0xf3019fff,0x7fed4bff,0x3ffffead,
    0x8bffff70,0x987ffffe,0xf70ffffd,0xff885bff,0xff104fff,0x3fa0bfff,
    0x645fffff,0x000cffff,0x001ffb00,0x7fff5400,0x3fffe20f,0x01ffffff,
    0xfffffff3,0x3ee09fff,0xffffffff,0x3fff6204,0x4fffffff,0xfffffe88,
    0xffa82fff,0xffffffff,0x985fffff,0x3ffa5fff,0xffffffff,0xfffd885f,
    0x3ffff5c5,0x5fffffe4,0x1ffffffe,0x07ffff54,0x06ffffdc,0x7fefffdc,
    0xffffb82f,0xfd80003f,0xe980001f,0xf81effff,0xffdcefff,0xdffff07f,
    0x0bfffdbb,0xd9dffff7,0x3607ffff,0xffddefff,0x7f445fff,0xfffdceff,
    0x7ffec43f,0xfffffdef,0xeb81fffd,0x3fffaa1d,0xfffeceff,0x40bff102,
    0xffe987ff,0xeeffffff,0xfffd83ff,0xffffe83f,0x223ffd02,0x3ff2200b,
    0x20002fff,0x20001ffd,0x2effffd8,0x7f402620,0x077fcc0f,0x3e627fd4,
    0x7e440dff,0x7ffdc0ff,0x45ffe882,0xfb81effe,0xeffc82ff,0x321dff90,
    0x7c4002ff,0x7fdc1fff,0x40bff105,0x7fec07ff,0x02ea1eff,0x51fffff6,
    0x205fffff,0x98000ffe,0x01effffd,0x001ffd80,0xfffffc88,0x2aa62003,
    0xe81ffd9a,0x5d41acff,0x202ffe40,0x7ffc4ffd,0x893fe203,0x3ee00fff,
    0x21ffc85f,0x3fee2ffc,0x77fc4002,0x220dff00,0x1ffe05ff,0x009fffb0,
    0x3ffeffd8,0x0bffbff6,0x00027fec,0x3bffffd3,0x00ffec00,0x3ffffee0,
    0xff91000c,0x3fffffff,0xffffff70,0x3ffa039d,0xeeeeeeee,0x3fe26ffe,
    0x50edc00f,0xff880bff,0x321ffc87,0x0bfee2ff,0x40bff100,0xbff106ff,
    0x3603ffc0,0xfd8003ff,0xff36ffbf,0x2605ff9d,0x40001fff,0x0cfffffa,
    0x3fbbbb22,0x2deeeeff,0xdffffea8,0x3ffe6000,0xffffffff,0xfffff901,
    0xfff09fff,0xffffffff,0x7fccffff,0x3ffb0005,0xc83ffb00,0x8bff21ff,
    0x44002ffb,0x1bfe05ff,0xff02ffc4,0x00ffd80f,0xfe9ffd80,0xfcbffdaf,
    0xdfff502f,0x64000cc4,0xfb2fffff,0xffffffff,0x221fffff,0x01fffffd,
    0x77fffc40,0x1fffdcbc,0x3fb6ea20,0x7ff45fff,0xffffffff,0x3fe67fff,
    0x7ff90006,0xc81ffd00,0x8bff21ff,0x44002ffb,0x1bfe05ff,0xff037fc4,
    0x00ffd80f,0xfa8ffd80,0xfc8fffef,0xffffb82f,0x007ffb4f,0x3fffff22,
    0x3ffffee3,0xffffffff,0x7fffec46,0x3fee001e,0x83ff900e,0x3fea02d9,
    0x00fff60f,0x001fff80,0x200fff98,0xffc86ffb,0xfb8bff21,0xf101302f,
    0x837fc0bf,0xfd987ff8,0x07fec07f,0xf87fec00,0xff94ffff,0xfdfff885,
    0x05fffaff,0xcfffffb8,0xfb333300,0x4013335f,0x1dffffe9,0x883ffc80,
    0x7ec1fffc,0x8bff602f,0x4c02fffa,0x06fff40a,0x7fc1fd30,0x7fd441df,
    0x21ffc83f,0x3fee2ffc,0x443ffe82,0x1bfe05ff,0xecbeffe8,0x01dfffff,
    0xb0001ffb,0x3ffee1ff,0xb85ff90f,0xffff94ff,0x7f5403df,0x4000dfff,
    0xa8001ffd,0x00cfffff,0x32f7ffee,0xdffffffd,0x79dfffd1,0x81ffffb9,
    0xcbdffffd,0x4c6fffed,0xcaccffff,0x2a2fffec,0xfdbeffff,0x3620dfff,
    0xff92efff,0x8fbfee7d,0x3b26fff9,0x3662efff,0xfa81dfff,0xffffffff,
    0x3ff24fff,0xefffffff,0x887fec03,0x3ff25fff,0xfd0ffec2,0x3a605fff,
    0x001effff,0x0003ffb0,0x1fffffdc,0xffffffd0,0x9fffffff,0x3ffffff6,
    0x882fffff,0xfffffffd,0xfa86ffff,0xffffffff,0xfff985ff,0x85ffffff,
    0x97fffffa,0x3feeffff,0x53ffe0ff,0x6ffffff8,0x13fffff6,0x77ffffd4,
    0xf51efffb,0xffffffff,0x7ec01fff,0xc87ff20f,0x17fe42ff,0xb10ffff3,
    0x005dffff,0x001ffd80,0x7fffe440,0xfffc882f,0xfffdcfff,0xffdbf51e,
    0x803bffff,0xfffffffa,0xfb300bef,0x7dffffff,0x7fffecc0,0xffb103ef,
    0x3fff27df,0x889fff74,0x7fffe41a,0x3fffa62e,0x0554c01e,0x7fffec40,
    0x04ffffff,0x64007fec,0x7ffd42ff,0xeffffdcd,0x7fffff52,0x3ff60000,
    0xfb300001,0x2a20bfff,0x510001aa,0x88001355,0x40019aa9,0x019aaa98,
    0x0000d440,0x00000000,0x00000000,0xfffd8800,0x7fec43ef,0x7ff43eff,
    0xffffffff,0x019fffb6,0x07fe4000,0x3fa60000,0x000001ff,0x00000000,
    0x00000000,0x00000000,0x00000000,0x3fee0000,0x2e0fffff,0x47ffffff,
    0xdfffffc8,0x19d32eff,0x9d300000,0x75400000,0x3ffffe24,0x46ffffff,
    0x21dfffd9,0x544effec,0xb80dfffe,0xb50dfffe,0x643bffff,0x00dffffe,
    0x0000004c,0x732fffc4,0x99999999,0x22159999,0x99911ccc,0x80fbba25,
    0xffb10001,0xfd889fff,0x3104ffff,0x00000155,0x00000000,0xfffff100,
    0x8dffffff,0x14fffffd,0x43ffffff,0x83ffffff,0xd2ffffff,0x29ffffff,
    0xfffffff8,0x001bee03,0x7d400ba2,0xffff31ff,0xffffffff,0x3fe2bfff,
    0xf8fffe2f,0x7fdc43ff,0x0001881f,0x00000000,0x00000000,0x3fe20000,
    0xffffffff,0x7fff545f,0x3ffff61f,0x6ffffdc5,0xfff71988,0x3ffae1df,
    0x3ff21eff,0x3600dfff,0x7ec000ff,0x4ffc801f,0x3fffffe2,0xffffffff,
    0xe87ffe5f,0x8bffa1ff,0x3ffffff8,0x0000ffa2,0x00000000,0x00000000,
    0x27fc4000,0xd817ffea,0xfff35fff,0x93fea03f,0xdff11ffd,0x541bfea0,
    0xffb006ff,0x7ffe4001,0x07ff400e,0x2aaaaaa2,0x1aaaaaaa,0xffb07ff4,
    0xfd0ffec1,0x39fffbdf,0x00007ffd,0x00000000,0x00000000,0x517f4000,
    0xf700bfff,0x1dfffdff,0xf8b7fc40,0x09ff54ff,0x7f417ff4,0x8add883f,
    0x2eb98ffd,0xdfffff50,0x0027fc40,0xc8ff9000,0x887fe47f,0xfff90eff,
    0x0001dfff,0x00000000,0x00000000,0x2a080000,0x2a005fff,0x00dfffff,
    0xffb8ffe8,0x405ff97f,0x7fcc6ffa,0xfffff706,0x0fffffff,0xfff9fff3,
    0x003fee09,0x46fb8000,0x23fdc6fb,0x7ffd40db,0x000000ef,0x00000000,
    0x00000000,0x3ffea000,0xfffd8005,0x5ff9001f,0xfd5ffffd,0x1ffe801f,
    0x7cc0fff6,0xffffffff,0x7ffc44ff,0xb07fff55,0x3fff609f,0xffffffff,
    0x17ea2eff,0x06fa8bf3,0x000b2e20,0x00000000,0x00000000,0xf5000000,
    0xd8800bff,0x02ffffff,0xfffeffa8,0x807ffeff,0xfff35ffb,0xffffb500,
    0xffd017df,0x42fffb8d,0xfff980ff,0xffffffff,0x3e26ffff,0x3e227c43,
    0x00000005,0x00000000,0x00000000,0xffa80000,0xd101a85f,0xfffd7fff,
    0xffff8807,0x5ffffebf,0xfb3fff00,0x3fe2007f,0xff703fff,0x8fff901f,
    0x3ffb201b,0xffffffff,0x980c2dff,0x004c1c80,0x00000026,0x00000000,
    0x00000000,0x2fffd400,0x7f4c3fdc,0x3fff61ff,0x7ffff404,0x03ffffb8,
    0xfffdff70,0x3fff6001,0xffa81fff,0x001bf601,0x00000000,0x3fa05fd0,
    0x0000003f,0x00000000,0x00000000,0x7ffffcc0,0x0fffffff,0x87bffff2,
    0x02effffc,0x3e2bfff9,0x3e001fff,0x5003ffff,0xdffb1fff,0x00600260,
    0x00000000,0x313fe600,0x0000dfff,0x00000000,0x00000000,0xfffb8000,
    0xffffffff,0xfffff31f,0x3fffe2bf,0xfff506ff,0x003ffec5,0x003fffee,
    0xfe897fe4,0x0000000f,0x00000000,0x7c5fe980,0x000003ff,0x00000000,
    0x00000000,0x7fffdc00,0xffffffff,0x3bffff61,0x3bffff21,0x98fff102,
    0x7c4005ff,0x366004ff,0x0001ec43,0x00000000,0xfb100000,0x00001a85,
    0x00000000,0x00000000,0x00000000,0x00000000,0x00000000,0x00000000,
    0x00000000,0x000000c0,0x00000000,0x00000000,0x00000000,0x00000000,
    0x00000000,0x00000000,0x00000000,0x00000000,
};

static signed short stb__courier_bold_33_usascii_x[95]={ 0,6,3,1,2,2,3,6,7,3,2,1,5,2,
6,2,2,2,1,1,2,1,3,2,2,3,6,5,-1,0,1,2,2,-1,0,0,0,0,1,0,0,2,1,0,
0,-1,-1,0,1,0,0,1,1,0,-1,-1,0,0,2,7,2,3,2,-2,5,1,-1,1,0,0,2,0,0,1,
2,0,1,-1,0,1,-1,1,1,2,2,0,0,-1,0,0,2,4,7,4,1, };
static signed short stb__courier_bold_33_usascii_y[95]={ 24,5,6,4,3,5,7,6,5,5,5,7,20,14,
20,3,5,5,5,5,5,5,5,5,5,5,11,11,7,11,7,6,5,6,6,6,6,6,6,6,6,6,6,6,
6,6,6,6,6,6,6,6,6,6,6,6,6,6,6,5,3,5,4,29,4,10,5,10,5,10,5,10,5,5,
5,5,5,10,10,10,10,10,10,10,6,11,11,11,11,11,11,5,5,5,12, };
static unsigned short stb__courier_bold_33_usascii_w[95]={ 0,5,11,15,14,14,13,5,8,7,14,16,7,13,
5,14,14,14,14,15,13,15,13,13,14,13,5,8,18,17,17,14,13,20,17,17,17,17,17,18,17,14,17,18,
17,20,19,17,16,17,19,15,16,18,20,19,18,17,14,7,14,8,14,21,7,16,18,16,18,17,15,18,18,15,
12,17,15,20,17,16,18,17,16,14,16,17,18,19,17,17,14,9,4,9,15, };
static unsigned short stb__courier_bold_33_usascii_h[95]={ 0,20,9,23,25,20,18,9,24,24,13,17,9,4,
5,25,20,19,19,20,19,20,20,20,20,20,14,17,17,9,17,19,22,18,18,19,18,18,18,19,18,18,19,18,
18,18,18,19,18,23,18,19,18,19,18,18,18,18,18,24,25,24,11,4,6,15,20,15,20,15,19,21,19,19,
26,19,19,14,14,15,21,21,14,15,19,14,13,13,13,20,13,24,24,24,7, };
static unsigned short stb__courier_bold_33_usascii_s[95]={ 254,34,218,118,29,1,22,230,74,110,162,
54,192,166,244,14,40,48,19,238,34,222,55,102,135,69,195,244,71,200,36,
137,152,216,237,100,163,145,127,81,92,77,63,38,20,1,196,1,110,134,185,
152,168,118,205,57,1,226,181,93,44,101,177,180,236,90,83,140,116,122,150,
203,233,166,1,182,200,174,201,157,184,166,237,107,216,219,143,123,105,16,90,
64,59,83,236, };
static unsigned short stb__courier_bold_33_usascii_t[95]={ 1,28,104,1,1,28,88,104,1,1,104,
88,104,23,112,1,28,49,49,1,49,1,28,28,28,28,88,49,88,104,88,
49,1,69,69,49,69,69,69,49,69,69,49,69,69,88,69,49,69,1,49,
49,49,49,49,69,69,49,69,1,1,1,104,23,112,88,28,88,28,88,28,
1,28,28,1,28,28,88,88,88,1,1,88,88,28,88,104,104,104,28,104,
1,1,1,104, };
static unsigned short stb__courier_bold_33_usascii_a[95]={ 280,280,280,280,280,280,280,280,
280,280,280,280,280,280,280,280,280,280,280,280,280,280,280,280,
280,280,280,280,280,280,280,280,280,280,280,280,280,280,280,280,
280,280,280,280,280,280,280,280,280,280,280,280,280,280,280,280,
280,280,280,280,280,280,280,280,280,280,280,280,280,280,280,280,
280,280,280,280,280,280,280,280,280,280,280,280,280,280,280,280,
280,280,280,280,280,280,280, };

// Call this function with
//    font: NULL or array length
//    data: NULL or specified size
//    height: STB_FONT_courier_bold_33_usascii_BITMAP_HEIGHT or STB_FONT_courier_bold_33_usascii_BITMAP_HEIGHT_POW2
//    return value: spacing between lines
static void stb_font_courier_bold_33_usascii(stb_fontchar font[STB_FONT_courier_bold_33_usascii_NUM_CHARS],
                unsigned char data[STB_FONT_courier_bold_33_usascii_BITMAP_HEIGHT][STB_FONT_courier_bold_33_usascii_BITMAP_WIDTH],
                int height)
{
    int i,j;
    if (data != 0) {
        unsigned int *bits = stb__courier_bold_33_usascii_pixels;
        unsigned int bitpack = *bits++, numbits = 32;
        for (i=0; i < STB_FONT_courier_bold_33_usascii_BITMAP_WIDTH*height; ++i)
            data[0][i] = 0;  // zero entire bitmap
        for (j=1; j < STB_FONT_courier_bold_33_usascii_BITMAP_HEIGHT-1; ++j) {
            for (i=1; i < STB_FONT_courier_bold_33_usascii_BITMAP_WIDTH-1; ++i) {
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
        float recip_width = 1.0f / STB_FONT_courier_bold_33_usascii_BITMAP_WIDTH;
        float recip_height = 1.0f / height;
        for (i=0; i < STB_FONT_courier_bold_33_usascii_NUM_CHARS; ++i) {
            // pad characters so they bilerp from empty space around each character
            font[i].s0 = (stb__courier_bold_33_usascii_s[i]) * recip_width;
            font[i].t0 = (stb__courier_bold_33_usascii_t[i]) * recip_height;
            font[i].s1 = (stb__courier_bold_33_usascii_s[i] + stb__courier_bold_33_usascii_w[i]) * recip_width;
            font[i].t1 = (stb__courier_bold_33_usascii_t[i] + stb__courier_bold_33_usascii_h[i]) * recip_height;
            font[i].x0 = stb__courier_bold_33_usascii_x[i];
            font[i].y0 = stb__courier_bold_33_usascii_y[i];
            font[i].x1 = stb__courier_bold_33_usascii_x[i] + stb__courier_bold_33_usascii_w[i];
            font[i].y1 = stb__courier_bold_33_usascii_y[i] + stb__courier_bold_33_usascii_h[i];
            font[i].advance_int = (stb__courier_bold_33_usascii_a[i]+8)>>4;
            font[i].s0f = (stb__courier_bold_33_usascii_s[i] - 0.5f) * recip_width;
            font[i].t0f = (stb__courier_bold_33_usascii_t[i] - 0.5f) * recip_height;
            font[i].s1f = (stb__courier_bold_33_usascii_s[i] + stb__courier_bold_33_usascii_w[i] + 0.5f) * recip_width;
            font[i].t1f = (stb__courier_bold_33_usascii_t[i] + stb__courier_bold_33_usascii_h[i] + 0.5f) * recip_height;
            font[i].x0f = stb__courier_bold_33_usascii_x[i] - 0.5f;
            font[i].y0f = stb__courier_bold_33_usascii_y[i] - 0.5f;
            font[i].x1f = stb__courier_bold_33_usascii_x[i] + stb__courier_bold_33_usascii_w[i] + 0.5f;
            font[i].y1f = stb__courier_bold_33_usascii_y[i] + stb__courier_bold_33_usascii_h[i] + 0.5f;
            font[i].advance = stb__courier_bold_33_usascii_a[i]/16.0f;
        }
    }
}

#ifndef STB_SOMEFONT_CREATE
#define STB_SOMEFONT_CREATE              stb_font_courier_bold_33_usascii
#define STB_SOMEFONT_BITMAP_WIDTH        STB_FONT_courier_bold_33_usascii_BITMAP_WIDTH
#define STB_SOMEFONT_BITMAP_HEIGHT       STB_FONT_courier_bold_33_usascii_BITMAP_HEIGHT
#define STB_SOMEFONT_BITMAP_HEIGHT_POW2  STB_FONT_courier_bold_33_usascii_BITMAP_HEIGHT_POW2
#define STB_SOMEFONT_FIRST_CHAR          STB_FONT_courier_bold_33_usascii_FIRST_CHAR
#define STB_SOMEFONT_NUM_CHARS           STB_FONT_courier_bold_33_usascii_NUM_CHARS
#define STB_SOMEFONT_LINE_SPACING        STB_FONT_courier_bold_33_usascii_LINE_SPACING
#endif

