// Font generated by stb_font_inl_generator.c (4/1 bpp)
//
// Following instructions show how to use the only included font, whatever it is, in
// a generic way so you can replace it with any other font by changing the include.
// To use multiple fonts, replace STB_SOMEFONT_* below with STB_FONT_arial_bold_27_usascii_*,
// and separately install each font. Note that the CREATE function call has a
// totally different name; it's just 'stb_font_arial_bold_27_usascii'.
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

#define STB_FONT_arial_bold_27_usascii_BITMAP_WIDTH         256
#define STB_FONT_arial_bold_27_usascii_BITMAP_HEIGHT        100
#define STB_FONT_arial_bold_27_usascii_BITMAP_HEIGHT_POW2   128

#define STB_FONT_arial_bold_27_usascii_FIRST_CHAR            32
#define STB_FONT_arial_bold_27_usascii_NUM_CHARS             95

#define STB_FONT_arial_bold_27_usascii_LINE_SPACING          18

static unsigned int stb__arial_bold_27_usascii_pixels[]={
    0x33219988,0x202ac980,0x32a202cc,0x000cc883,0x006f2ea2,0x09999988,
    0x80266666,0x4c4001c8,0x5c009aca,0x999303cc,0x03595300,0x40005300,
    0x99500999,0x5c40e64c,0x001cc802,0x00157751,0x98026a60,0x27ffa819,
    0xfffb84fd,0x905ff80e,0xdf90bfff,0xfffd7100,0x039dffff,0x97ffffe4,
    0x04fffff9,0x220037ee,0xfffffffd,0x41ffee04,0xfb104ffd,0x09ffffff,
    0x39ffff90,0x03fff800,0x0ffdcffb,0x40fffff2,0xff5007fa,0x4005ffff,
    0x0cfffffb,0x7d43ffcc,0x703fea7f,0xff09ffff,0xbffff30b,0x5402ff88,
    0xccdeffff,0x903ffffe,0x265fffff,0xb84fffff,0x00cffffe,0xfffffff5,
    0xf103dfff,0xfff885ff,0xfffffa81,0x81efffff,0xffffffd8,0x1fffc007,
    0x1ff25fe8,0x3ff97ff7,0x3e007fd0,0x07ffefff,0xffffff90,0x87ff98df,
    0x27f45ee9,0x21bff2a2,0xeffc85ff,0x203fe40a,0x4c02effc,0x99884ffe,
    0xfff32ffe,0xfffc8355,0xf886ffff,0xecacefff,0xfd80ffff,0x43ffd45f,
    0xaceffff8,0xc86fffec,0xffebdfff,0x0fffe003,0x6fe8ffe2,0x3ff9b7ec,
    0xfb803fd4,0x00ffee5f,0xf95bfff3,0x3774c7ff,0x203ff200,0x5ff86ff8,
    0xf882ffc8,0x0ffee04f,0x405ff700,0xdff32ffe,0x3efbfe20,0x7ec2fffd,
    0xfff903ff,0xd8fff509,0xfffd84ff,0x49fff903,0x3e62fff8,0xfff000ff,
    0x225ff307,0xf2ff44ff,0x003fe89f,0x7fccbff9,0x237fdc05,0x26004ffc,
    0x27fcc4cc,0x5ff87ff8,0xfc82ffd8,0x85ff302f,0x5551cdb9,0xffe81bf2,
    0x2a0dff32,0xebbf9bff,0x13ffe63e,0xf01fffb0,0x0fffc5ff,0xb013ffe6,
    0x3fee1fff,0x7c000986,0xffffb3ff,0xffffffff,0x4ff97fa1,0xfb801fee,
    0x07ffd1ff,0x7d44ffb8,0x2133224f,0x7ff87ffa,0xbff0fff0,0xfb05ffb0,
    0x362ff40f,0xffcfffff,0x3a01fd16,0x0dff32ff,0x0fe6bff2,0x400fffb8,
    0xfc82fff9,0x50dff55f,0xf9801fff,0x4bff92ff,0x3ffe0001,0xffffffb3,
    0x21ffffff,0x47ff36fd,0x7f4003fe,0x00effeef,0x3f63ffcc,0x21ffe62f,
    0xffe87ffa,0x7c0fff80,0x81ffd85f,0x1ff307ff,0x7e5f7fec,0x0bf24fff,
    0xff997ff4,0xf5dff306,0x037fe407,0xf883fff8,0x907ffb7f,0x3fe00dff,
    0xf99ffb3f,0xf8001bff,0xff9973ff,0x99ffd99d,0x3f73fea1,0x000ff70f,
    0x1bfffff3,0x33fff200,0x7fcc5ffe,0xd87ffa87,0x1ffe81ff,0x7ffc2ffc,
    0xc837fc40,0x717fee5f,0x27dc7fff,0xff32ffe8,0x7ffffc0d,0x017ffa04,
    0xfe82fff4,0xd80fffaf,0xffd005ff,0x3fffffab,0x2001ffff,0x7fc43fff,
    0x7e41bfa3,0x0ffa2eff,0x3ffff200,0xfffb8006,0x7ff985ff,0xfc87ffa8,
    0x45ffb83f,0x3ffd45ff,0xff82ffd4,0xf103ffe3,0x837d43ff,0xdff32ffe,
    0x7ffffdc0,0x05ffe83e,0x2e0bffd0,0xd05fffff,0x3fa00bff,0x7dffff5f,
    0x400bffd7,0x7fd43fff,0xa809ff12,0x2a23fdc1,0xffffd100,0x300227ff,
    0x7ffffffd,0xfa87ff98,0x84ffb87f,0xff3ffff8,0x0ffffa6b,0x7fc13fee,
    0x3e09ff72,0xe82fdc7f,0x0dff32ff,0xfffffd88,0x017ff60e,0xf8827ffc,
    0xfb02ffff,0x3ffe00bf,0x4c3fffd4,0xff001fff,0x30ffb87f,0xfd0005ff,
    0x33fff227,0x757fffc0,0x3ffb9fff,0xb9cfff98,0x3fe64ffe,0xa87ffa87,
    0xfff305ff,0x7fcd7fe9,0x07ffb03f,0x3ff21ff1,0x6c6ff983,0x25ffd03f,
    0xf5006ff9,0x7e49ffff,0x7fff006f,0x03fffec0,0x3e00fff9,0x0fffb3ff,
    0x3e005fff,0xffffb3ff,0xffffffff,0x6cff7001,0x2a5ffbff,0xfff10fff,
    0xf907ffdd,0x27ffa89f,0xffa87ff9,0xb04ffa87,0x57fe9fff,0xc80efff9,
    0x27f983ff,0xffb81ffd,0x7407fe24,0x0dff32ff,0x3ff2fe60,0x907ffee6,
    0x017ffd45,0x5c09fff3,0x7d401fff,0x0dff92ff,0x32e67ffb,0xfb2fff83,
    0xffffffff,0xfd001fff,0x7dd3fe27,0xa8bff90f,0x80ffffff,0xfff82ffe,
    0xf50fff31,0x07ff70ff,0x3e15fff5,0x17ffaa5f,0x3e213fee,0xd05ffb0f,
    0x02fec5ff,0x3fe65ffd,0xb3f98406,0x3ffe23ff,0x3abbfe25,0x3e600fff,
    0x3fe201ff,0x7fff406f,0xf81fff70,0x8fff72ff,0xfb71fff8,0x9dff99bf,
    0x7fb80199,0x7fd4bfe6,0xf709ffd1,0x3fe09fff,0x8fffc43f,0xffa87ff9,
    0xd82ffc87,0x22ffc2ff,0xff987ff9,0x3f25ff04,0x8fffd44f,0x3fa01ffc,
    0x20dff32f,0x93f99ffe,0x7ffe43ff,0xffffb88d,0x7fec03ff,0xefffc806,
    0x17fff4c0,0x7cc7fff1,0x7fff51ff,0xf507ffdc,0x0027fc5f,0x2ff98ffe,
    0x3fee3ff5,0xeffffa87,0x5c6ffd80,0xfff30fff,0xfb0fff50,0x81ffd03f,
    0x0ffe85ff,0xfe82ffc4,0x739fff35,0xffd9ffff,0x32ffe805,0x3ff20dff,
    0x1fff3f9d,0xcdffffe8,0x906ffffe,0x007ffff9,0x37bffffa,0xc86ffffe,
    0xfffcefff,0x3bfffe25,0x7dc5ffff,0x005ff30f,0x3fe23fdc,0x3e21ff73,
    0xffdbcfff,0x543fffff,0xffdbefff,0x21ffe65f,0xffe87ffa,0xff87ff80,
    0xf81ffd85,0x64ff707f,0xffefffff,0xe801ffff,0x0dff32ff,0x37fbffe2,
    0xfd884fff,0xffffffff,0x7ff41dff,0x362006ff,0xffffffff,0xfffd104f,
    0xfa81ffff,0x0effffff,0x3ff73fec,0x741ffc00,0x5c6feaef,0xffffffff,
    0xc84fffde,0xefffffff,0x2a1ffe60,0x2ffc47ff,0x5ff87ff8,0xfd82ffd8,
    0x23ff881f,0xdd74efda,0x404cc179,0xdff32ffe,0x7ffffe40,0x3aa00eff,
    0xfddeffff,0x3ff61fff,0xea8000cf,0x01dfffff,0x0dffffc8,0x9dfffd50,
    0x7e4bff01,0x41fee007,0x81efffe9,0x3fffffe9,0xfea817ea,0x7cc0cfff,
    0x47ffa87f,0xfff01ffa,0xff90bff0,0x207ff305,0x10002ffa,0xffd01dfd,
    0x301bfe65,0x007dfffb,0x7fd40988,0x88000006,0x03100009,0x26004c40,
    0x80026209,0x164c02cb,0x11009980,0x00033100,0x3f637fe4,0xf0dff305,
    0x09ff90bf,0xffc817f6,0x3fee000d,0x25ffd01f,0xf3006ff9,0x71000007,
    0x00000003,0x00000000,0x00000000,0x00000000,0xffffc800,0xd50bfe25,
    0xbff0bfff,0x89dfff70,0x3f200ff9,0x98abdeff,0x1fffecba,0x97fff75c,
    0x03eefff9,0x00000fe6,0x00000000,0x00000000,0x00000000,0x00000000,
    0xffffe800,0x3ee1bee1,0x5ff82fff,0xd0bffff0,0xffe9809f,0xffffffff,
    0xffc80cff,0xfff32fff,0x0d4409ff,0x00000000,0x00000000,0x00000000,
    0x00000000,0xd0000000,0x2fe85bff,0xf01dffb8,0x3ff620bf,0x1007fa85,
    0xdffffdb7,0x775c015b,0xddd31eee,0x000007dd,0x00000000,0x00000000,
    0x00000000,0x00000000,0x00000000,0x00000000,0x00000000,0x00000000,
    0x00000000,0x00000000,0x00000000,0x00000000,0x00000000,0x00000000,
    0x00000000,0x00000000,0x00000000,0x00000000,0x00000000,0x00000000,
    0x0a980000,0x20165c00,0x201abba8,0x20000998,0x9971bdcb,0xa9800001,
    0x51001abb,0x33300003,0x4001a880,0x401acb98,0x066601cc,0x26013330,
    0x06660abb,0x8dee5400,0x26620ccb,0x99999999,0x02666219,0xb8099988,
    0x001effff,0x3ff207ff,0x82efffff,0x88006ffa,0xeafffffe,0x7fffc1ff,
    0xf307ffff,0x3dffffff,0x3ffffa60,0xfff10002,0xfffff703,0xfffd8807,
    0xfb01efff,0x07ffe609,0x7443fff8,0xff34ffff,0xffd8800f,0x1ffeafff,
    0x3ffffff6,0x747fffff,0xfe880fff,0x7ffec0ff,0x4c02ffff,0x7ff4c1ff,
    0xffffffff,0x0037fd43,0x7f7ffff4,0x3e21ffff,0x7fffffff,0xffffffa8,
    0x7cc1ffff,0x03ffffff,0x41fff880,0xfffffffc,0xffffd303,0x707fffff,
    0x3ffe60df,0x90fffe01,0x267fffff,0x7ec007ff,0xffffefff,0x3ffff61f,
    0x7fffffff,0x642fffcc,0x7fdc2fff,0x0ffffcdf,0xfd11fee0,0xfd959dff,
    0x7fd43fff,0x7ffd4006,0x3ffff50b,0x7fffffcc,0xefff87ff,0x6fffdbac,
    0x7edf7fec,0x7c4000ff,0x3ffe61ff,0x887ffdbd,0xebbdffff,0x7cc0ffff,
    0x1fff980f,0xfb0fffe0,0x7fcc21bf,0x3ffe6007,0x3fffd50c,0x66666654,
    0xc86ffffc,0x3fe62fff,0x23ffe85f,0x3603fff8,0x27ffe45f,0x2a5fffb8,
    0x7ec006ff,0x1fffc87f,0x4c013fee,0xffd80fff,0x41fff30f,0x44003ffe,
    0x3ff21fff,0x3217ffc5,0xffa82fff,0x982ff84f,0x3fe01fff,0x41fff43f,
    0x32007ff9,0x7fdc0fff,0xfff5001f,0xffff101f,0x203fffa1,0x7fec1fff,
    0xff0ffe06,0x4efd80bf,0x764dbfea,0x09ffd02c,0x7e43fff5,0xfff5002f,
    0x239dd301,0x7fdc5ffc,0x26f72e06,0x2a21fff8,0x11fff41c,0x7ec09fff,
    0x984fe84e,0x3fe01fff,0xbfff953f,0x8bffcc79,0x7ec0bddb,0x1fff986f,
    0x1ffff980,0x2b3ffea0,0xff983fff,0x83ffdc0f,0x3fe21ff9,0xff50001f,
    0xbfffff7d,0x883fff81,0x3ffa1fff,0xf300abaa,0x90015dff,0x7ffa89ff,
    0xfffffe88,0x9801fffb,0x3fea0fff,0xc802200f,0x1fff986f,0x7ecfffe0,
    0x266fffff,0xffffafff,0x0fffa0ef,0x2200fffc,0xd803fffe,0x06ffffff,
    0xfc83fff1,0x47fb80ff,0x20007ffa,0xfefffffa,0x7ff45fff,0x21fffa84,
    0xffffffff,0xfffffd03,0x3ff6017d,0x743ffcc3,0xfffeffff,0x3f6601ff,
    0x3ffdc3ff,0x03fea000,0x7c03fff3,0xffffb3ff,0x7ffccdff,0x4fffeeff,
    0x3e613ffa,0x7fec01ff,0xfff1004f,0x7f403fff,0x0ffff43f,0x3ff22fec,
    0x33333306,0x3bffea13,0x43fff911,0xffc86ffd,0xfffff31f,0xd107ffff,
    0xdfffffff,0x4c3ffe85,0x3fea0fff,0xffff50bf,0x1fffe403,0x00037fec,
    0xff30bfe2,0x1fffc03f,0x3e60fffa,0x3ff20eff,0x2e1bff27,0x3f201fff,
    0x7d4005ff,0x7d404fff,0xfffeacff,0x6c4ff81f,0xfff886ff,0xff52ffff,
    0x47fff07f,0x3ea3fffb,0xfff51fff,0x1fffd539,0x3ffffee0,0x3ffe3fff,
    0xb0fffcc3,0xfff70fff,0x7fffec03,0x002fff43,0x3e627f40,0x3ffe01ff,
    0x4c1fff43,0x7fcc2fff,0x887ffee7,0xf501fffe,0xa8001dff,0xd803ffff,
    0xffffffff,0x217fc41f,0xff886ffc,0xf52fffff,0x9ffb01ff,0x77ffffc4,
    0x221fffff,0x17ffcc09,0x3fffae60,0x87ffd1ff,0x3fa0fff9,0x1fff984f,
    0x27ff5420,0x0000dffb,0xfff98df9,0xd0fffe01,0xfff307ff,0x20fff983,
    0xffbcfffe,0xff981fff,0x7c4001ff,0x800fffff,0xff9dffeb,0x207fd40f,
    0xcc887ffa,0xf52fffdc,0x17ff20ff,0x7ffffff3,0x3e003fff,0x322004ff,
    0x7ffd4fff,0x7fc7ff98,0x1fff883f,0x5cfff500,0x004407ff,0xff983fea,
    0x0fffe01f,0xff307ffd,0x0fff881f,0x3fffffea,0x7441fffe,0xd8002fff,
    0x05ffffff,0x87ffa820,0xfff886fc,0x97ffc403,0xfd80fffa,0xdeec885f,
    0x000fff89,0x776c9ffb,0x6dbff603,0x3ffd44ff,0x3e613ffa,0xff1001ff,
    0x07ffea3f,0xf103efc8,0x0fffc43f,0x743fff88,0x7ff983ff,0x4c0fff88,
    0xff8cffff,0x27ffec1f,0x6fffd400,0x2602fffc,0x437fe409,0xfffd04fe,
    0x97ffcc01,0xff81fffa,0xff10024f,0x7c1ee54f,0x1fffa1ff,0xff95ffe8,
    0x6c6ffb8b,0xfffb85ff,0xf30bbb21,0x3ffe23ff,0x0dfff105,0x3ffe1ff4,
    0x85fff305,0xff983ffe,0x00fff887,0x21fff831,0x8005fffc,0xf88ffff8,
    0xffc80fff,0x10bffe24,0x3fe605ff,0xfffb81ef,0x8bfff52f,0x3ee2fffa,
    0x37fd41ef,0xffa8fff9,0x067ffdc7,0x267fff71,0x3ffa1fff,0x207ffe43,
    0x3f61fffe,0x07ffe45f,0xd989fff7,0x3f203fff,0x217fff45,0x740fffe8,
    0x7ff983ff,0x000fff88,0x7fd47ffe,0xfd8000ef,0x3ffea3ff,0xcdfff885,
    0xffa86fff,0x3fffea00,0xfffffedf,0xbffff51f,0x98dfffb7,0xfdbcffff,
    0x3ffe64ff,0x44fffdbe,0xdeffffe8,0x3a0fffff,0x7ffdbeff,0xbbefff88,
    0x2a1fffff,0xffecefff,0xffffe84f,0x06ffffed,0x3fea3fd4,0xfffedfff,
    0x83ffe84f,0xff887ff9,0x3ffe000f,0xffffffb1,0x3fffffff,0x6c2fffd4,
    0xffc82fff,0xc81fffff,0xfffa806f,0xdfffffff,0x3fb7fea0,0xc81fffff,
    0xffffffff,0xfffffb86,0xff980dff,0xffffffff,0x7ffffcc1,0xfff503ff,
    0x3ffdbfff,0xffffffc8,0xfffb106f,0x01dfffff,0x7e41ff88,0xffffffff,
    0x83ffe80e,0xff887ff9,0x3ffe000f,0xffffffb1,0x3fffffff,0x203fffe2,
    0x440ffff8,0x00dfffeb,0x2e6009fd,0x1ceffffd,0xffb4ffa8,0x7ed403df,
    0x2a03efff,0x404ffffe,0xefffffc8,0xfffd100d,0xffe9805f,0x503ffd4f,
    0x007fffff,0x7fffffd7,0x4c1ffc00,0x3efffffe,0x260fffa0,0xfff887ff,
    0x47bba000,0xfffffffd,0x91ffffff,0x7dc07fff,0x006205ff,0x44000266,
    0x004c0001,0x04c40000,0x000cc400,0x0620004c,0x0004c400,0x88000998,
    0x00cc4009,0x00000000,0x00000000,0x00000000,0x00000000,0x00000000,
    0x00000000,0x00000000,0x00000000,0x00000000,0x00000000,0x80199880,
    0x26621999,0x01333100,0x99982662,0x21998800,0x9b733cc9,0x33333105,
    0x33333333,0x2000ccc4,0x99999999,0x41998009,0x99999999,0x2606e001,
    0x26620099,0x80666660,0x26099998,0x4cc00099,0x04ccc401,0x4cc43331,
    0x31006660,0x5cb32a13,0x3ea03fff,0x1bff64ff,0xe82fffec,0x3fff64ff,
    0x537ff400,0xffff5bff,0x7ffdc1bf,0xffffffff,0x0fff51ff,0x7ffffcc0,
    0x03ffffff,0x7fccfff3,0xffffffff,0x307faa02,0x7ec0bfff,0xfffff33f,
    0x3ffffe01,0x005fff12,0xa80fffc4,0x3ea1ffff,0x2bffd0ff,0x3a01fff9,
    0x49ffb4ff,0xfd00fffe,0x3ffdc1ff,0x887ffff8,0x3fea2fff,0x3ffe602f,
    0x3ffffea3,0x2e5fffff,0xffffffff,0xf51fffff,0x7fcc00ff,0xffffffff,
    0x7ff985ff,0x3fffffe6,0x885fffff,0x7fcc1fff,0x7ffb01ff,0x0bffffe6,
    0x4bffffe6,0x2002fff8,0xf981fff8,0x7fd42fff,0x26bffd0f,0x3fa01fff,
    0x4c9ffb4f,0xffb85fff,0x0fffcc2f,0x07ffffe6,0xff81fff5,0x3ffee05f,
    0x4bbffea0,0x931fffd8,0x9fffb999,0x3ea19999,0x3fe6007f,0xfdccccdf,
    0x7fcc2fff,0x337ffe67,0x1ffffedc,0x260fffc4,0xfb06ffff,0x3fffe67f,
    0xffffb84f,0x05fff12f,0x20fffc40,0xa82ffff9,0xbffd0fff,0xe807ffe6,
    0x87dd94ff,0x3e21fffc,0x7fff05ff,0x3fffffc8,0x7e437fe4,0xbffd00ff,
    0x443fffa8,0x3ea04fff,0x3fea00ff,0x3ffe6007,0x89fff301,0x3fe67ff9,
    0x4fffa81f,0x337fff2a,0x7fffff31,0x3e67ffb0,0xfe87ffff,0xff12ffff,
    0x7fc4005f,0x3fffe61f,0x21fff502,0xfff35ffe,0x027ff403,0xf937ffc4,
    0x3ff601ff,0x7fefff45,0x4c27fec5,0xff882fff,0x0fffd42f,0xf502fff4,
    0x7fd401ff,0x316664c7,0x7ec03fff,0x33ffcc6f,0x3f603fff,0x3ffff26f,
    0xffff33ff,0x3ffd81ff,0x3ffbfff3,0x7ff77fc4,0x005fff12,0xe88fffc4,
    0x3ea02fff,0x2bffb0ff,0x3a01fff9,0xff5004ff,0x07fff37f,0xff137fe4,
    0xff8fff3f,0x0bfff02f,0xff50fff7,0x81bff20f,0x2a00fffa,0x3ffe27ff,
    0x07ffe60e,0x7cc4ffe8,0x07ffe67f,0xff937fec,0x3e67ffff,0x6c5fffff,
    0x7fff33ff,0x67fd47ff,0xfff12ffe,0x7ffc4005,0x03fffe89,0xfc87ffd4,
    0x03fff34f,0xb0027ff4,0x0dffdfff,0xf50fffa8,0x4c7ffabf,0xff900fff,
    0x84ffe81f,0xfc80fffa,0x3ffea05f,0x45ffea00,0x7cc0effe,0xffc881ff,
    0x33ffcc1f,0xff303fff,0x7ffcc4bf,0x7fff309a,0x7fec5fff,0xff3fff33,
    0x7f57fe4b,0x05fff12f,0x757ffc40,0xfa805fff,0x27ff90ff,0xaaacfff9,
    0x04fffaaa,0x3ffffe20,0x7ffc401f,0x3f27ff92,0x40dff73f,0x3e23fff9,
    0xfffa82ff,0x204ffd83,0x2a00fffa,0x1fffd7ff,0xffffff30,0x0dffffff,
    0x7fccfff3,0xffdcbabf,0x7ffc43ff,0xfebffcc1,0x4cfff66f,0x74fff7ff,
    0x12ffe8ff,0x44005fff,0xffffffff,0x7ffd401f,0x3e65ff70,0xffffffff,
    0x4004ffff,0x004ffffb,0x3ffa7ffd,0x3f2bff51,0x2fff405f,0x3ea0fff7,
    0x7ffcc5ff,0x03ffea02,0xffdfffa8,0xffff301f,0x9fffffff,0x4cfff301,
    0xffffffff,0xff885fff,0x9bffcc1f,0x7ffb4fff,0x7fedffe6,0xffd6ff89,
    0x00bffe25,0xffffff88,0x7d406fff,0x25ff50ff,0xfffffff9,0x34ffffff,
    0xffe80355,0x37ff2007,0x3fe27ff8,0xb807ffd7,0x9ffd0fff,0x3ffffea0,
    0x406fffdb,0x2a00fffa,0x06ffffff,0x3fbbffe6,0x7cc05fff,0x3fffe67f,
    0x04ffffff,0xf983fff1,0x23fff27f,0xfff33ffd,0x3feaffee,0x3e25ffd4,
    0x3e2002ff,0xffbbffff,0x3ffea03f,0x3e63ff30,0xaaaaacff,0xffb4fffa,
    0x05ffd809,0x3efffea0,0x7d7ff45f,0x7fc401ff,0x01fff8bf,0xfffdfff5,
    0xfa803fff,0x3fea00ff,0x303fffff,0x7fdc3fff,0xfff300df,0x555fffcc,
    0x3e2009aa,0x3ffcc1ff,0xffbbfff1,0x7cdffe67,0xfd2ffcdf,0x0bffe25f,
    0x3ffff880,0x5407fffa,0x1ff10fff,0xe807ffe6,0x09ffb4ff,0x2005ffd8,
    0x3ffefff8,0x3fff7fe4,0xfbeffe80,0x5ffea06f,0x801efffc,0x2a00fffa,
    0xfffdffff,0x41fff980,0xf305fffc,0x0fffccff,0x0fffc400,0xff51ffe6,
    0x3e67ffff,0x3fbffe7f,0x225ffd0f,0x22002fff,0x7fd44fff,0x1fff506f,
    0x3fff33fc,0xfda7ff40,0x2ffec03f,0x3ffffa00,0x7fffd41f,0xfff7005f,
    0x7d407ffd,0x50004c7f,0x7d401fff,0x09ffd2ff,0xfd03fff3,0xfff305ff,
    0x000fffcc,0x260fffc4,0xfffd87ff,0x4fff33ff,0x3a6ffffd,0x5fff12ff,
    0x0fffc400,0x541fffec,0x99320fff,0x3fa01fff,0xb00fe64f,0xfd800bff,
    0xff887fff,0xf1003fff,0x401fffff,0x40007ffa,0x2a00fffa,0x3ffea7ff,
    0x40fffcc1,0x4c0ffff9,0x3ffe67ff,0xbfff0001,0x21ffe657,0x33fffff8,
    0x7ffdcfff,0x44bffa4f,0x22002fff,0xff981fff,0x7ffd40ff,0x3e635530,
    0x3ffa01ff,0xfb007f24,0xffb800bf,0xfffd05ff,0x7fec003f,0x7fd406ff,
    0x7fd40007,0x1ffea00f,0xff98bffb,0xbfff701f,0x3e67ff98,0xfb0001ff,
    0x3fe69fff,0x7ffff907,0xff99ffe6,0x4bffa2ff,0xfffffff8,0x3e27ffff,
    0xfff901ff,0xb0fffa8b,0x3ffe69ff,0x6d3ffa01,0x5ffd804f,0x7fffcc00,
    0x0ffff702,0x3ffffa80,0x003ffd40,0x803ffea0,0x7fcc7ffa,0x07ffe62f,
    0x262fffe8,0x3ffe67ff,0xffd30001,0x81ffe69f,0xff33fffe,0x20ffff8f,
    0xfff12ffe,0xffffffff,0x80fffc4f,0x2a2ffff8,0x9ffb0fff,0xe807ffe6,
    0x200574ff,0xf8005ffd,0xff300fff,0xfff000bf,0x5ee9801f,0x7ffd4000,
    0x21ffea00,0x3fe66ffc,0x3ffe601f,0x4cfff30f,0x40001fff,0x03ffcc18,
    0x3e67fff5,0x237fec7f,0xfff12ffe,0xffffffff,0x00fffc4f,0x2a1ffff7,
    0x9ffb0fff,0xe807ffe6,0x000004ff,0x00000000,0x00000000,0x00000000,
    0x00000000,0x00000000,0x00000000,0x00000000,0xaa880000,0x26666661,
    0x26099999,0x99999999,0x26660999,0x30019999,0x33333333,0x0d540001,
    0x33100000,0x2a600013,0x55530009,0x00000003,0xc884cc98,0x9db7104c,
    0xedca8057,0x6dcc01cd,0xeca800bd,0x2cc980bc,0xfd0037b7,0x3fffe67f,
    0x4fffffff,0xfffffff3,0x269fffff,0xffffffff,0xfff302ef,0xdfffffff,
    0x5ffc8005,0x7ffffffc,0x6402ffff,0x5c005fff,0x00dfffff,0xdfffffd3,
    0x2d710003,0x3ea000bd,0x87ff987f,0xfffffffa,0xffffd80d,0xfc883fff,
    0x106fffff,0x3dfffffd,0xffddffa8,0x7ffe403f,0xffffff33,0x269fffff,
    0xffffffff,0xff34ffff,0xffffffff,0xffff30bf,0xffffffff,0x3ffea005,
    0x7fffffc5,0x402fffff,0x000fffff,0xfffffffb,0xffffa81f,0x002fffff,
    0x3fafff91,0xffa801cf,0x447ff987,0xfffefffe,0x6fffcc4f,0x6c0fffec,
    0xfffeffff,0xfefffe84,0x3fea0fff,0x200fffff,0xf33ffffb,0x99999bff,
    0x3ffe6599,0xcccccccd,0x9bfff32c,0x7ffffd99,0xccdfff98,0x07fffdcc,
    0x45fffe88,0xffffffff,0x3ea01fff,0xa804ffff,0xffdbefff,0x3bffe25f,
    0x0fffda8a,0x3ffff6a0,0x5bffffd7,0x4c3ffd40,0x2ffdc7ff,0xffb1bff6,
    0x262dfc83,0xff50bfff,0x8fffdc3f,0x3ea4ffd8,0x5039afff,0x27fffffd,
    0x3001fff9,0x4c003fff,0xfe981fff,0x3ffe60ff,0x03fff501,0x05ffffc8,
    0xb00fff60,0x00ffffff,0xffb8dffb,0x203ffee7,0xfeb83fff,0xb52effff,
    0x17dfffff,0xf987ffa8,0xfb81107f,0x577ff46f,0x43ffe400,0x3ffa0acc,
    0xa87ffcc4,0x7c402fff,0x33fffeff,0x26003fff,0x26001fff,0xff301fff,
    0x0fffcc9f,0x201fff88,0x05fffffa,0x880dff30,0x2fffafff,0x261ff6c0,
    0x7db50fff,0x6453ff20,0x1cffffff,0xfffff710,0x1ffea19f,0xa881ffe6,
    0x646fffec,0x1cefffff,0x2004ffe8,0xaaaacfff,0xfff51fff,0xd3ff8801,
    0x3ffe67ff,0x3fff3001,0x0fffcc00,0x7ccdffb0,0xfff501ff,0x7df7fc40,
    0x1ffd005f,0xfd6ffb80,0x7d4000bf,0x7ffc007f,0x5bffffd2,0xfffda800,
    0x30fff57f,0xffd50fff,0xb0dfffff,0xbfffffff,0x801fffc1,0xfffffff8,
    0xff52ffff,0x7419100f,0x5fff33ff,0x41333333,0xcccdfff9,0x3e64cccc,
    0x3ff201ff,0x2b3ffe67,0x3fffcaaa,0x3eebff60,0x3ffa805f,0xf53ffe80,
    0x360001ff,0xfd1006ff,0x3fffa1ff,0x7fcc0002,0x30fff57f,0xfffa8fff,
    0x06ffa9be,0xffffff93,0x801fff49,0xcccdfff8,0xff51cccc,0x3ffa000f,
    0xffffff33,0x7cc7ffff,0xffffffff,0x3ffe67ff,0x43ffee01,0xfffffff9,
    0x2a02ffff,0x0bff74ff,0xf300ffd0,0x3ffe21ff,0xfffb8004,0xfffe8801,
    0x3bffffa1,0x3faa000b,0xfff37fff,0xfe8fff50,0x037fd44f,0xb3fff5c4,
    0x379709ff,0xa801fffc,0xfd0007ff,0x3fffe67f,0x23ffffff,0xfffffff9,
    0x3e67ffff,0x3fea01ff,0xfffff31f,0x3dffffff,0x2e1dff10,0x7fdc05ff,
    0x46ffc804,0x5c007ffd,0xe8805fff,0x75c41fff,0x01dfffff,0xffffff93,
    0x07ffe217,0xfff8fffb,0xb137fe42,0xfff883fd,0x443fff70,0x3ff63fff,
    0xf526f4c5,0x3fa000df,0x9bfff33f,0x4c399999,0xaaaabfff,0x3fe62aaa,
    0x3ffee01f,0x559fff30,0x5fffd975,0x3ee1ffd8,0x3ffe205f,0x1fffc401,
    0x400bffea,0x800efffb,0x5401fffc,0x3efffffd,0xdfffffd5,0x2bbffe05,
    0x6c7fffda,0xffc99eff,0x577fec7f,0x226ffda9,0xfebdffff,0x3ffe60ff,
    0x24ffeaad,0xd0006ffa,0x3ffe67ff,0x3fff3001,0x0fffcc00,0x7ccfff90,
    0x3ffa01ff,0x2abbfea5,0x82aeffda,0xfa806ffa,0xfeeeeeff,0xffb805ff,
    0xffd000ef,0x7fe4c003,0xffffd7ff,0xfffc803b,0x47ffbfff,0xeffffffa,
    0x3fe20fff,0x1fffffff,0x7fffffd4,0xfffb82ff,0x7d46ffff,0xffd0006f,
    0x007ffe67,0x000fffcc,0x6c03fff3,0x3ffe66ff,0x43ffee01,0xfffffffc,
    0xfb86ffff,0xfffe803f,0xffffffff,0x3ffee00f,0xfff1000d,0x3fee2000,
    0x0019ffd7,0xf977ffe4,0xfffda87f,0xd987ffd4,0x01dfffff,0x5dffffb1,
    0x77fff540,0x037fd40b,0xf33ffe80,0x3e6003ff,0x3e6001ff,0xfff301ff,
    0x00fffcc7,0x3f21fff9,0xffffffff,0x1ffd86ff,0x7ffffcc0,0xffffffff,
    0x0bfff504,0x003cc880,0x007b6a80,0x88000880,0x03330001,0x40009980,
    0x40000009,0xfff33ffe,0x3ffe6003,0x3ffe6001,0x46ffea81,0xf501fff9,
    0x66654dff,0xceffdccc,0xc807ff83,0x7fec07ff,0x0efff887,0x00aaa800,
    0x00000000,0x00000000,0x00000000,0x7ffd0000,0x4007ffe6,0xfffffff9,
    0xf36fffff,0xffffffff,0xff985fff,0xffffffff,0xf7003fff,0x1bfe20bf,
    0x5013ffe0,0xffb85fff,0xffffffff,0x01fff101,0x00000000,0x00000000,
    0x00000000,0x3ffa0000,0x003fff33,0x3fffffe6,0x36ffffff,0xffffffff,
    0xff307fff,0xffffffff,0x7dc00bff,0x0bff505f,0x801fffa8,0x7ff45fff,
    0xffffffff,0x01fff101,0x00000000,0x00000000,0x00000000,0x3ffa0000,
    0x003fff33,0x3fffffe6,0x36ffffff,0xdfffffff,0x3fe6017b,0xefffffff,
    0x7fdc002d,0x809ff705,0xf9006ffd,0x3ffe61ff,0xffffffff,0x01fff101,
    0x00000000,0x00000000,0x00000000,0x00000000,0x00000000,0x00000000,
    0x00000000,0x00000000,0x00000000,0x00000000,0x00000000,0x76544000,
    0x3cc880bc,0xa817bb71,0x839972cc,0xcca84cc8,0x88599932,0x332e2ccc,
    0x40999302,0x32a02cc9,0x439b952c,0x6442cdb8,0xcccccccc,0x0599300c,
    0x33333332,0x9304cccc,0x22555105,0x13331199,0xb9502666,0x7c466059,
    0x511fffff,0x0e664455,0x55555551,0x03555555,0xffff5000,0xff985fff,
    0xefffff9d,0x7e57ff21,0x0fffd44f,0xffe8fff6,0x83fff60f,0xff907ffb,
    0x027fdc0b,0xfff99ff7,0xffff35ff,0x7fffc4bf,0x01ffffff,0x3fe0dffb,
    0xffffffff,0x83fa80ff,0xdff97ffa,0x7f47ffea,0x3ffff64f,0x1fc9acff,
    0x3ffffff1,0xff71ffe6,0x7ffffc4b,0xffffffff,0x7fd40003,0x2fffffff,
    0x3bffffe6,0x3f25ffff,0xd8dff35f,0x3fe23fff,0x57ffe60f,0x7c42fffb,
    0x2fff82ff,0xb813fee0,0xffefffff,0xfffeffff,0xfffff13f,0x103fffff,
    0xff05ffff,0xffffffff,0x263221ff,0x3fea352f,0x3eadff97,0x29ffd1ff,
    0xfffffff8,0xf11fffff,0x263fffff,0x0ffb87ff,0xddddddd1,0x05dddddd,
    0x6fffcc00,0x21fffd52,0x360efff9,0x93bae7ff,0x3ffe0fff,0x21bfea6f,
    0xfffbfffb,0xa8bff904,0x7fdc07ff,0x97ffee04,0xd11ffffa,0x4ccccbff,
    0x904fffd9,0x550dffff,0x55555555,0x7effd455,0xdff54ffd,0x7fd5bff2,
    0x229ffd1f,0xfffcaacf,0x5510efff,0x3e615555,0x007f907f,0x7dc00000,
    0x7ffcc0ff,0x985fff33,0xffc807ff,0x4fffff33,0xffb03ffc,0x2601dfff,
    0x3ff60fff,0x027fdc04,0xff81fff7,0x037fe45f,0x220bfff5,0x01ffdeff,
    0xffd73000,0x76e85bdf,0x3ffe2bff,0x0a27ffb0,0x00166e4c,0x00000000,
    0x0bffb000,0x7fcd7ffa,0x07ffcc0f,0x7dd7fea0,0xfff1ffdf,0x3fffe201,
    0x9fff401f,0x7fc0fff8,0xffffffff,0x0fff70ff,0xffb87fff,0x0dfff506,
    0x7fd5ffe4,0x55555545,0x982aaaaa,0x4f982fff,0x3ffc9ff3,0x00005ff7,
    0x00000000,0xfff80000,0x26dff903,0x7fc40fff,0xb7ff800f,0xf39ff3ff,
    0xfffb80df,0x76ffb805,0xffff0bff,0xffffffff,0x3e1bfee1,0x37fd43ff,
    0x8077ffcc,0xfff0fff8,0x7fffffc3,0x20ffffff,0x21ffaff9,0x5dd10efa,
    0x3dd5276c,0x00000000,0x00000000,0xfb04ffe8,0x21ffe6bf,0xd800fff8,
    0xfd5ffaff,0x4407ff7d,0x402fffff,0xffe8fff8,0xffffff82,0x70ffffff,
    0x5fff0bff,0x7c46ffa8,0x3ee01fff,0xf93ff24f,0xffffffff,0x53ee0fff,
    0x001224fb,0x00000000,0x00000000,0x837fe400,0xfff34fff,0x001fff10,
    0x27ffdff5,0x01ffeffc,0x3ffffff6,0x7e7fe400,0x9ff7007f,0x7c2ffdc0,
    0x37fd42ff,0x803fffd1,0x3fe21fff,0x9999990f,0x50999999,0x00000141,
    0x00000000,0x00000000,0xb85fff50,0xfff31fff,0x261fff10,0x7ffc41aa,
    0xffff51ff,0x5fffd40d,0x7cc05fff,0x7004ffff,0x7fdc09ff,0x542fff85,
    0x3fff66ff,0x42f75402,0x00002eec,0x00000000,0x00000000,0x80000000,
    0xebefffe8,0x3fe64fff,0x90fff887,0xfffb0bff,0x27fffc4f,0xf75fff88,
    0xffe807ff,0xff7000ff,0x42ffdc09,0x7fd42fff,0xfdffff76,0x0009ffff,
    0x00000000,0x00000000,0x00000000,0x7f440000,0x0dffffff,0x3e21ffe6,
    0x0bff90ff,0xfe8bfff7,0xfffb01ff,0x007fff41,0x400bfff7,0x3ee04ffb,
    0x42fff85f,0xfff96ffa,0x9fffffff,0x00000000,0x00000000,0x00000000,
    0x80000000,0x3efffec8,0xf887ff98,0x0bff90ff,0xfc87fff1,0x5fff707f,
    0x206fff98,0x2002fff8,0x3ee02cc9,0x42fff85f,0xfff96ffa,0x9fffffff,
    0x00000000,0x00000000,0x00000000,0x00000000,0x000004c4,0x00000000,
    0x00000000,0x00000000,0x00000000,0x00000000,0x00000000,0x00000000,
    0x00000000,0x00000000,0x00000000,0x00000000,0x00000000,0x00000000,
    0x00000000,0x00000000,0x00000000,
};

static signed short stb__arial_bold_27_usascii_x[95]={ 0,2,1,0,0,1,1,1,1,0,0,1,1,0,
1,-1,1,1,0,0,0,1,1,1,0,0,2,2,1,1,1,1,0,0,1,1,1,1,1,1,1,1,0,1,
1,1,1,1,1,1,1,0,0,1,-1,0,0,-1,0,1,-1,0,1,-1,0,0,1,1,0,0,0,0,1,1,
-2,1,1,1,1,0,1,1,1,0,0,1,0,0,0,0,0,0,2,0,0, };
static signed short stb__arial_bold_27_usascii_y[95]={ 21,3,3,3,2,3,3,3,3,3,3,6,17,13,
17,3,3,3,3,3,3,3,3,3,3,3,8,8,5,8,5,3,3,3,3,3,3,3,3,3,3,3,3,3,
3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,23,3,8,3,8,3,8,3,8,3,3,
3,3,3,8,8,8,8,8,8,8,4,8,8,8,8,8,8,3,3,3,10, };
static unsigned short stb__arial_bold_27_usascii_w[95]={ 0,4,10,14,13,20,17,4,7,7,9,13,4,8,
5,8,12,9,13,13,13,12,12,12,13,13,4,4,12,13,12,13,24,18,16,16,16,14,13,17,15,5,12,17,
14,18,15,17,15,18,17,15,15,15,18,23,17,18,15,7,8,7,12,15,6,13,13,12,14,13,9,14,13,5,
7,13,5,19,13,14,13,13,9,13,8,13,14,19,14,14,12,9,3,9,14, };
static unsigned short stb__arial_bold_27_usascii_h[95]={ 0,18,7,19,22,19,19,7,24,24,9,13,8,4,
4,19,19,18,18,19,18,19,19,18,19,19,13,17,15,9,15,18,24,18,18,19,18,18,18,19,18,18,19,18,
18,18,18,19,18,20,18,19,18,19,18,18,18,18,18,23,19,23,10,3,4,14,19,14,19,14,18,19,18,18,
24,18,18,13,13,14,18,18,13,14,18,14,13,13,13,19,13,24,24,24,5, };
static unsigned short stb__arial_bold_27_usascii_s[95]={ 250,230,174,182,90,197,218,185,41,9,159,
85,169,205,214,15,100,1,120,128,74,71,156,88,236,1,30,251,148,145,161,
134,49,101,57,142,40,25,11,24,235,224,169,206,191,172,156,138,131,104,107,
84,77,168,44,20,238,1,222,82,159,74,132,227,220,188,42,216,113,229,184,
56,194,250,1,93,125,99,16,1,63,208,243,202,147,174,70,35,55,123,119,
31,27,17,190, };
static unsigned short stb__arial_bold_27_usascii_t[95]={ 20,46,84,1,1,1,1,84,1,1,84,
84,84,84,84,26,26,65,65,26,65,26,1,65,1,26,84,46,65,84,65,
65,1,65,65,26,65,65,65,26,46,46,1,46,46,46,46,1,46,1,46,
26,46,26,46,46,26,46,26,1,26,1,84,84,84,65,26,65,26,65,26,
26,26,1,1,46,46,84,84,84,46,26,65,65,46,65,84,84,84,1,84,
1,1,1,84, };
static unsigned short stb__arial_bold_27_usascii_a[95]={ 107,129,183,215,215,344,279,92,
129,129,150,226,107,129,107,107,215,215,215,215,215,215,215,215,
215,215,129,129,226,226,226,236,377,279,279,279,279,258,236,301,
279,107,215,279,236,322,279,301,258,301,279,258,236,279,258,365,
258,258,236,129,107,129,226,215,129,215,236,215,236,215,129,236,
236,107,107,215,107,344,236,236,236,236,150,215,129,236,215,301,
215,215,193,150,108,150,226, };

// Call this function with
//    font: NULL or array length
//    data: NULL or specified size
//    height: STB_FONT_arial_bold_27_usascii_BITMAP_HEIGHT or STB_FONT_arial_bold_27_usascii_BITMAP_HEIGHT_POW2
//    return value: spacing between lines
static void stb_font_arial_bold_27_usascii(stb_fontchar font[STB_FONT_arial_bold_27_usascii_NUM_CHARS],
                unsigned char data[STB_FONT_arial_bold_27_usascii_BITMAP_HEIGHT][STB_FONT_arial_bold_27_usascii_BITMAP_WIDTH],
                int height)
{
    int i,j;
    if (data != 0) {
        unsigned int *bits = stb__arial_bold_27_usascii_pixels;
        unsigned int bitpack = *bits++, numbits = 32;
        for (i=0; i < STB_FONT_arial_bold_27_usascii_BITMAP_WIDTH*height; ++i)
            data[0][i] = 0;  // zero entire bitmap
        for (j=1; j < STB_FONT_arial_bold_27_usascii_BITMAP_HEIGHT-1; ++j) {
            for (i=1; i < STB_FONT_arial_bold_27_usascii_BITMAP_WIDTH-1; ++i) {
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
        float recip_width = 1.0f / STB_FONT_arial_bold_27_usascii_BITMAP_WIDTH;
        float recip_height = 1.0f / height;
        for (i=0; i < STB_FONT_arial_bold_27_usascii_NUM_CHARS; ++i) {
            // pad characters so they bilerp from empty space around each character
            font[i].s0 = (stb__arial_bold_27_usascii_s[i]) * recip_width;
            font[i].t0 = (stb__arial_bold_27_usascii_t[i]) * recip_height;
            font[i].s1 = (stb__arial_bold_27_usascii_s[i] + stb__arial_bold_27_usascii_w[i]) * recip_width;
            font[i].t1 = (stb__arial_bold_27_usascii_t[i] + stb__arial_bold_27_usascii_h[i]) * recip_height;
            font[i].x0 = stb__arial_bold_27_usascii_x[i];
            font[i].y0 = stb__arial_bold_27_usascii_y[i];
            font[i].x1 = stb__arial_bold_27_usascii_x[i] + stb__arial_bold_27_usascii_w[i];
            font[i].y1 = stb__arial_bold_27_usascii_y[i] + stb__arial_bold_27_usascii_h[i];
            font[i].advance_int = (stb__arial_bold_27_usascii_a[i]+8)>>4;
            font[i].s0f = (stb__arial_bold_27_usascii_s[i] - 0.5f) * recip_width;
            font[i].t0f = (stb__arial_bold_27_usascii_t[i] - 0.5f) * recip_height;
            font[i].s1f = (stb__arial_bold_27_usascii_s[i] + stb__arial_bold_27_usascii_w[i] + 0.5f) * recip_width;
            font[i].t1f = (stb__arial_bold_27_usascii_t[i] + stb__arial_bold_27_usascii_h[i] + 0.5f) * recip_height;
            font[i].x0f = stb__arial_bold_27_usascii_x[i] - 0.5f;
            font[i].y0f = stb__arial_bold_27_usascii_y[i] - 0.5f;
            font[i].x1f = stb__arial_bold_27_usascii_x[i] + stb__arial_bold_27_usascii_w[i] + 0.5f;
            font[i].y1f = stb__arial_bold_27_usascii_y[i] + stb__arial_bold_27_usascii_h[i] + 0.5f;
            font[i].advance = stb__arial_bold_27_usascii_a[i]/16.0f;
        }
    }
}

#ifndef STB_SOMEFONT_CREATE
#define STB_SOMEFONT_CREATE              stb_font_arial_bold_27_usascii
#define STB_SOMEFONT_BITMAP_WIDTH        STB_FONT_arial_bold_27_usascii_BITMAP_WIDTH
#define STB_SOMEFONT_BITMAP_HEIGHT       STB_FONT_arial_bold_27_usascii_BITMAP_HEIGHT
#define STB_SOMEFONT_BITMAP_HEIGHT_POW2  STB_FONT_arial_bold_27_usascii_BITMAP_HEIGHT_POW2
#define STB_SOMEFONT_FIRST_CHAR          STB_FONT_arial_bold_27_usascii_FIRST_CHAR
#define STB_SOMEFONT_NUM_CHARS           STB_FONT_arial_bold_27_usascii_NUM_CHARS
#define STB_SOMEFONT_LINE_SPACING        STB_FONT_arial_bold_27_usascii_LINE_SPACING
#endif
