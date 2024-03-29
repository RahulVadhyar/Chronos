// Font generated by stb_font_inl_generator.c (4/1 bpp)
//
// Following instructions show how to use the only included font, whatever it is, in
// a generic way so you can replace it with any other font by changing the include.
// To use multiple fonts, replace STB_SOMEFONT_* below with STB_FONT_consolas_28_usascii_*,
// and separately install each font. Note that the CREATE function call has a
// totally different name; it's just 'stb_font_consolas_28_usascii'.
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

#define STB_FONT_consolas_28_usascii_BITMAP_WIDTH         256
#define STB_FONT_consolas_28_usascii_BITMAP_HEIGHT        108
#define STB_FONT_consolas_28_usascii_BITMAP_HEIGHT_POW2   128

#define STB_FONT_consolas_28_usascii_FIRST_CHAR            32
#define STB_FONT_consolas_28_usascii_NUM_CHARS             95

#define STB_FONT_consolas_28_usascii_LINE_SPACING          18

static unsigned int stb__consolas_28_usascii_pixels[]={
    0x00004551,0x3db93001,0x40155100,0xdd002cdd,0x2007dddd,0x3bbba62a,
    0x02a802ee,0xa8000000,0x4003530a,0x88000099,0x01aa882a,0x45550aa2,
    0x2a2001aa,0x300aaaaa,0x00000055,0x00bb37d4,0x7e405f50,0x3a601fff,
    0xe80effff,0x7c00efff,0x804fffff,0xfff34ffb,0xff007fff,0x3ffb2200,
    0x2a0000cd,0x801bee6f,0x000beffe,0x7cc1ff30,0x9fb05fff,0x9fd0ffd8,
    0x7fffcc00,0x0df701ff,0x00fd8800,0x5ff8b7d4,0x40ffe600,0x201bdffa,
    0xfda9bffc,0x7fe4c40e,0x6ccccc05,0x6ffd804f,0x13333ff3,0xa806f880,
    0xefffffff,0x47fd0000,0xfb001ff8,0x0005ffff,0x5ff41ff3,0x37d42fea,
    0x09fd3fec,0x7e666440,0x00df701f,0x400ff980,0x13fee6fa,0xd817fe60,
    0x0efb806f,0x3ee06fb8,0x13f2000f,0x7ccffea0,0xfd951007,0xff30379f,
    0xfff7315d,0x0ff98001,0x5c0027e4,0x4c002ffe,0x5cbf30ff,0x207fa25f,
    0x013fa7fd,0x701ff880,0xf98000df,0x237d400f,0x7f401ffd,0x00ffa00f,
    0x7ec01ff3,0x003ff100,0x088027e4,0x3ee01fe6,0x3fffffff,0xff506fe8,
    0x84fc8007,0x88000ff9,0x7cc007fe,0x7cc7f70f,0x7ec13f25,0x80013fa7,
    0xdf701ff8,0x0ff98000,0x3e237d40,0x0bfee06f,0xfd803ff0,0xf027d402,
    0x27e4005f,0x407f9800,0xbfdbeffa,0x0ffd42ca,0x4400dfb0,0x07fb01ff,
    0x00bfea00,0xbf50ff98,0x0ef9afd4,0x27f4ff90,0x03ff1000,0xd1001bee,
    0xdddffddd,0x1bea3ddd,0x3e20ffe6,0x01ff804f,0x3e201be2,0x800bfa06,
    0x3bbae4fc,0xf32eeeee,0x365ff80f,0x01bf601f,0x2e003ff5,0x01bea05f,
    0xa81ffc40,0x0ffdeedc,0x5fd15ff1,0x7fc80bfa,0x7764cffa,0x0ffc401c,
    0xdd306fb8,0x7ffffc49,0x1fffffff,0x1ff20df5,0x7fc01bf2,0xb88ff201,
    0x40ff2abc,0x3f2002fe,0x3fffff24,0x0ff33fff,0x1fd17fcc,0x2201ff40,
    0x5fd002ff,0x0002ff80,0xffd887ff,0x20ffffff,0xf95ffffb,0x3a7fc80b,
    0xfffffabf,0x07fe201f,0x7fcc37dc,0x7dcccc0e,0x2199999f,0x3ff306fa,
    0xff004fe8,0xe987fc03,0x0fd4ffff,0xf90017f4,0x4ccccc49,0x0ff33ff9,
    0x0ff1ffcc,0xff803ff8,0x806fa803,0xfa8005fb,0x4577f41f,0x4c0ffc98,
    0x01ff32cc,0x3bfa6fc8,0x7fea9aef,0x5c07fe20,0x077fcc6f,0x5003fe60,
    0x93fe20df,0xf8803ff9,0xfe9be207,0x1fd2fe9b,0xc800ff20,0x27ff004f,
    0x7ffc07f9,0x3e206f8a,0x04ff802f,0xf8803fd8,0x6dd4c00f,0x077dc5ff,
    0x74007fcc,0x26fc802f,0x7cc0effe,0x03ff102f,0xeff99bee,0x00ff9800,
    0xffd037d4,0x2200ffdc,0x53ea05fc,0x6c7fa6fa,0x03ff500f,0x7c013f20,
    0x980ff33f,0x205fefff,0xfe802ff9,0x007fc404,0x7dc04fd8,0x7fc0cfff,
    0x801ff302,0xdf7005fb,0xfe8077f4,0x203ff104,0x1dff16fb,0x003fe600,
    0x3fe40df5,0x7f640ff9,0x4bf200cf,0x6c3fe3fc,0x3ffaa00f,0x013f200e,
    0x07f99ffc,0xcffffe98,0x803ff880,0x27e403ff,0xb80ff300,0xff9809ef,
    0x401ff300,0xf7000ff9,0xf9027f4d,0x407fe20b,0x0eff8efb,0x003fe600,
    0x7fdc0df5,0x7ec0dfb0,0x8fe402ef,0x74ff11fe,0x7ffe4407,0x4013f200,
    0x00ff33ff,0x1fffff54,0x3e201ffc,0x00ffc02f,0xfa80bfa0,0x981fea05,
    0x4ffa00ff,0xfb81dfeb,0xfc813fa6,0x203ff106,0x007feefb,0x5400ff98,
    0x47fe606f,0x754c04fe,0x7c7f604f,0x3f4df30f,0x0137ff30,0xff004fc8,
    0x9001fe67,0xe89fffbf,0x0ffd405f,0x5000df50,0x02fd40df,0x7fcc0ff7,
    0x3f2bf700,0x7dc0ffef,0xfc813fa5,0x203ff106,0x04ffaefb,0x2007fcc0,
    0x3fe606fa,0x2600bfd1,0x223fa07f,0x7c53ee7f,0x8013ee06,0x7ff004fc,
    0xfb001fe6,0xfc8bff63,0x01bf600f,0x3e0005fd,0x409d301f,0x3fe607fa,
    0xf88ff880,0xea89f90f,0xfd813fa4,0x203ff104,0x07ff76fb,0x2007fcc0,
    0x3fee06fa,0x7c00ffb0,0xf11fd01f,0x3f9a7e4f,0xc800bf60,0x27ff004f,
    0x7f4007f9,0xff993fe0,0x405ff504,0x320007f9,0x3e60005f,0x01ffb00f,
    0x993ea7fb,0x04fe806f,0x7fc40ffa,0x7e4df701,0x7ff1002f,0x3606fa80,
    0x003ff27f,0x0fd80ffc,0x29ff11fd,0x0bfa01fd,0xf004fc80,0x001fe67f,
    0x6c4ff8ff,0xff711cff,0x004fd80d,0x5403fe20,0x20ffe200,0x7d40fffc,
    0x6f893ea6,0x413fa0a8,0xff100ffa,0xfb1bee03,0x3bfe005f,0x40df5042,
    0x0bfea5ff,0xfc80ffc0,0xfdbddf91,0x2fe80bfb,0x4013f200,0x00ff33ff,
    0x5ff537c4,0xffffffb0,0x7fc401bf,0x1fec0000,0xfb007fec,0x3fbf227f,
    0x987fe20f,0xfd13ea6f,0x5037fa1f,0x7fc407ff,0xe88df701,0xffa801ff,
    0xf51ffeff,0x88bfe20d,0x3ff004ff,0x7ec4bf20,0x805ffa8d,0x3f2002fe,
    0x267ff004,0x26b2a07f,0xeffdadfa,0xdfffd700,0x00bf7007,0xf88df500,
    0x3fe602ff,0xff8dffef,0x3fa0ff60,0x3e20ffce,0xdfffd2ff,0xfc89fffd,
    0xffffffff,0xd10df72f,0xfd5003ff,0x3ea3ffff,0xd81ff506,0x03ff006f,
    0x80000fee,0x3f2002fe,0x267ff004,0x3ffee07f,0x0effffff,0x2006fc80,
    0xd00002ff,0x00ffd85f,0xf277ff4c,0x441bea1f,0xfd81effe,0xfffd930f,
    0xfff905bf,0x5fffffff,0x7fcc1bee,0x0262000f,0x9fd10df5,0xf005ff50,
    0x01be205f,0x002fe800,0x3e2013f2,0x4c0ff32f,0xcefffedc,0x07fe6001,
    0x0001bea0,0x00985fb8,0x80000220,0x1004c008,0x00000001,0x3ea00000,
    0xb00ffc86,0x4fe801ff,0x00007f60,0xc8007fe2,0x1ffa804f,0x7ec00ff3,
    0x3ffa0001,0x7ec5c99c,0x3e200003,0x0000001f,0x00000000,0x00000000,
    0x237d4000,0x3e203ffa,0x03fec06f,0x80001df5,0x32000ffb,0x26fd804f,
    0x3fa007f9,0x3fe60000,0xf30fffff,0xc800001f,0x0000004f,0x00000000,
    0x00000000,0x137d4000,0xff700bff,0x67ffcc09,0x8577ec0a,0xd7504d99,
    0xaaa809ff,0x59d34fda,0x4c5fff95,0x00aaaaff,0x710000ff,0x00017bdb,
    0x00000000,0x00000000,0x00000000,0xfa800000,0x4003bfa6,0x3ea01ffc,
    0xffc81fff,0xd03fffff,0xf801bfff,0xf34fffff,0x85ffffff,0x3ffffff9,
    0x00000330,0x00000000,0x00000000,0x00000000,0x00000000,0xef9b7d40,
    0x027ec000,0x44032ea2,0x5c02bcca,0x999001ac,0x65cc5999,0xcc880acd,
    0x0001cccc,0x00000000,0x00000000,0x00000000,0x00000000,0xdf500000,
    0x038000d4,0x00000000,0x00000000,0x00000000,0x00000000,0x00000000,
    0x00000000,0x00000000,0x0000df50,0x00000000,0x00000000,0x00000000,
    0x00000000,0x00000000,0x00000000,0x00000000,0x003c9800,0x00000000,
    0x00000000,0x00000000,0x00000000,0x00000000,0x00000000,0x00000000,
    0x00000000,0x00000000,0x00000000,0x00000000,0x00000000,0x00000000,
    0x00000000,0x00000000,0x35100000,0xec98f640,0x3b2201ce,0x1eeeeeef,
    0x35553100,0x260276c1,0x003551ee,0x66f6e540,0x000000eb,0x005bdd93,
    0x00000000,0x00008000,0x4c000004,0xeeeeeeee,0xedca801e,0x01bf703e,
    0xfe80fff4,0xffffffaa,0xfefffb81,0x801fffff,0x2ffffffa,0xfc803ff2,
    0x20013fa6,0xffffffd8,0xfd9100ff,0xfb8019bf,0x004fffff,0x07bffd91,
    0x3fff6e20,0x372601ce,0x911cffff,0x03bdfffd,0xffffed98,0xfffb501d,
    0xfff9839d,0x02ffffff,0x3fffffee,0x04fff984,0x3a07fff1,0xea9aefef,
    0x227fcc7f,0xb801affc,0x1eccdfff,0xff80ffe6,0x10013fa4,0x93115dff,
    0xfff501ff,0x201dffff,0xfd99dff8,0x7ff4c01f,0x5405ffff,0xffffffff,
    0xfffff704,0x3fe6bfff,0x03ffffff,0xfffffff9,0xffffb07f,0x7cc5ffff,
    0x9999999f,0x57dffb00,0xfff50133,0x807fec0b,0x7cc0effe,0x741bf22f,
    0xdff8804f,0x506fe800,0x027f41ff,0x2603bee0,0x77fd40ff,0x0fffb98a,
    0x7fc47fb8,0x47bfe203,0xf704ffb8,0xb53137df,0x37dffb09,0x2e2bb531,
    0x03ffae21,0x4c15bff7,0x85ffdc1a,0x3e67fea8,0x2ffc8007,0x00ffec00,
    0x0efe8026,0x27ec9fd0,0xf9806fc8,0x3ff5002f,0x4fe8dfb0,0x40ffe200,
    0x37f40ff9,0xfc83ffa8,0x3203fe86,0x0ffb80ef,0x0006ffc4,0x00009ff5,
    0x6ff85ff5,0xa837f400,0x00ff31ff,0x0002ff88,0x3fa00003,0xfe97f204,
    0x500bf904,0x4ff800ff,0x3fa17fc4,0x03fe6004,0xff507fcc,0x5c37ec03,
    0x00ffc47f,0x1ffc05ff,0x88003ff6,0x200005ff,0x0bfe23ff,0x2207fd00,
    0x00ff31ff,0x00005fc8,0x77777744,0x6409fd01,0x103fee6f,0xff7007ff,
    0x547fc800,0xa9ff40ff,0x7d40defd,0xd83fe607,0x0ffd406f,0x7f44ffe6,
    0x403fea05,0x3fe25ffa,0x0ffdc003,0x1ff88000,0x90013fe2,0x99bee0df,
    0x1ff4007f,0x3fe60000,0xfd01ffff,0xf137e409,0xdff757ff,0x001fee00,
    0x27ec5ff3,0x7ffe5ff4,0x1fee1fff,0x3fa0ff98,0x417fc404,0x0effbffd,
    0x7e41bee0,0x03fea6ff,0x000df900,0x7f437dc0,0x3fe6003f,0x993fee0d,
    0x02cceeff,0xfdb73ff1,0x260003bd,0xd01ff999,0x327ec09f,0x9fffffff,
    0x3bbbb601,0x5eeeeeff,0x7fc57fa0,0xaefefe81,0x3ea5ffb8,0xf83fe607,
    0x83ff803f,0x804ffff8,0x7ff4c5fc,0x01fee7fd,0x40013fa0,0x0efda998,
    0x02efff98,0xfb9fff50,0xffff987f,0x7cc2ffff,0xffffffff,0x7c40003f,
    0x409fd01f,0x22bfa3fe,0x7f400aaa,0xffffffff,0x3fee07ff,0xffd06fb8,
    0x267fc81b,0x1ffb00ff,0x3e00bfe2,0x5fffd84f,0x93f61544,0xff99effa,
    0xf000df90,0xffff987f,0x7fffe46f,0x3ffa201f,0x74c00cff,0x3302ffff,
    0x5fffb953,0x305f7fcc,0x15103ffb,0xd01ff880,0x43fea09f,0x88001ff8,
    0x99ffc999,0x3e201999,0xfd03febf,0x21ff501d,0xffc83ff8,0x005ff10f,
    0xdffd89ff,0xb1bee4ff,0x437ff69f,0x0dfb0ff9,0xf987ff00,0x75c6ffff,
    0x00dfffee,0x0fffff6a,0xffffffb8,0x9bfa2003,0x3fe00ff9,0x201fff85,
    0xbfd01ff8,0x7c3ffa81,0x19aaabef,0x001fee00,0x807ff7e4,0x3ff104fe,
    0xfc88ffec,0x5ff10ffe,0x7dc5ff00,0x325ffb0f,0x7f77e46f,0xf93fd43f,
    0x09ff000f,0x5c406fc8,0xfc8805ff,0x7fec44ff,0x009ffd53,0xff887fd4,
    0xf31bf201,0x7fc40bff,0xddfffd01,0xff70bfff,0x7fffffff,0x000ff700,
    0xe817ffe6,0x43ff104f,0xdffefff9,0x0ffe0ff9,0x7fc3ff10,0x3a7ffa23,
    0x77ffdc5f,0x3ee7fb81,0x2fec000f,0x5401bf20,0xfd1001ff,0x20ffe43f,
    0x3001ffe8,0x0bfe23ff,0xffe87fb8,0x407fe207,0xdffffffe,0xb99ff502,
    0x809fffdd,0x3a0007fb,0x13fa01ff,0x3a60ffc4,0x1ff34eff,0x3ea02ff4,
    0x983ff10f,0x542ffeff,0x9bf205ff,0x64002ffa,0x037e407f,0x2002ff88,
    0x0ffe3ff8,0xb8027fc4,0x901ffc7f,0x0dff30bf,0xfe80ffc4,0xff980134,
    0x80ffd102,0x3a0007fb,0x827f406f,0x81101ff8,0x3ff20ff9,0xf89bf600,
    0xffffa82f,0xf017fcc0,0x037fc47f,0xc80ffea0,0x3ff3006f,0xf33ff800,
    0x02ff403f,0x3f22ff44,0x207ff106,0x3fe205ff,0x4009fd01,0x7fd406fb,
    0x001fee00,0x3a017fdc,0x03ff104f,0xf107fcc0,0x0bfea09f,0x3ff209ff,
    0x2e0bfb05,0x1ffdc0ff,0x407ff600,0xff9006fc,0x32ff9800,0x9ffc05ff,
    0x81ffd500,0x7ec45ff8,0x01ffa80e,0x7f407fe2,0x07ff2004,0x7dc07fd8,
    0x4ff98007,0xf104fe80,0x7fcc003f,0x8867fec0,0xffc86ffa,0x3ffff263,
    0x544ff982,0xbfff04ff,0x30f26213,0xfc837fff,0x17fe4406,0x3faa0373,
    0x10bffe0e,0x3bf23ffb,0x01efffee,0xffddfff7,0x7fe4c43f,0x80ffc404,
    0x3ea004fe,0xdb99abef,0x3fdc02ff,0x7fedd440,0x209fd006,0x26001ff8,
    0xfffd80ff,0x880dffff,0xfffefffe,0xfb81ffee,0x04fffeff,0x3fffff62,
    0xfe984fff,0x6fffffff,0xfffdddfb,0xffffb87f,0x40ffffff,0xfeeffff9,
    0x3fff23ff,0xe9803eff,0x640cffff,0xffc83fff,0xffffffff,0xb8009fd2,
    0xffffffff,0x07fb802e,0x0cffff88,0x2209fd00,0x3e6001ff,0xfffd700f,
    0xfff9007d,0x3bfe65df,0xefffea80,0xfffd7003,0x764037bf,0xb1dfffff,
    0x19dfffff,0xfffffd50,0x322017df,0x81dfffff,0x20000998,0x02aea009,
    0x7fffffe4,0x5972ffff,0xb9951000,0x7dc00579,0x1bcc8807,0x8827f400,
    0x322001ff,0x0001800c,0x00600002,0x20001100,0x13310099,0x00998800,
    0x00009880,0x00000000,0x00000000,0x00000000,0x00000000,0x00000000,
    0x00000000,0x00000000,0x00000000,0x00000000,0xddddd300,0x17aabddd,
    0x8000bd50,0x9d5005e9,0x3bbbbba6,0xd93eeeee,0x1dd7001d,0x37bbbbb2,
    0x80bdb01c,0x3ba61eea,0xea93aa05,0x4bdd303e,0x7db003ec,0xec8fba60,
    0x21dd5005,0xeeeeeeeb,0x017aa6ee,0x3bbb2bd5,0xeeeeeeee,0x5437ee0e,
    0x3fb6e0aa,0xfff981df,0xf77fffff,0x986fb80f,0x981dfffd,0x2bf7007f,
    0xfffffff9,0xff34ffff,0x24ff880b,0xfffffffe,0x1ffd40df,0x7d45ff88,
    0x4bf702ff,0xff906ffb,0xe8027f4f,0x46fe884f,0xfd801ffb,0x3fffff26,
    0x3ee7ffff,0xfeb7dc07,0xffffffff,0xfff31fff,0x3627ffa9,0x3fffffff,
    0xc9999998,0xb80ff77f,0x77ffe46f,0x3fcc4fff,0x5514fb80,0xfb555555,
    0x00ffe45f,0x6ff41ff9,0x6ffec999,0xfc80ffd8,0x37ffd40f,0x3ff25fb8,
    0x27fff81f,0x9fd004fe,0xf881dfb0,0x23ff803f,0x9ffc9998,0x01fee199,
    0x26662df7,0x9999ffc9,0x6d7ffea1,0x0aefc8ff,0x2001ffd3,0x80ff77fb,
    0x0ffee6fb,0x7fc45ff9,0x004fc800,0xff88bff1,0xe87ff105,0x87ff904f,
    0x7fcc4ff8,0x2ffffa83,0x37f25fb8,0x3fe7d44f,0x3fa009fd,0xe80ffdc4,
    0x0ffd406f,0x7dc0ff70,0x7037dc07,0x3ffb00ff,0x40643ff6,0xf7003ff9,
    0xf701feef,0x640ffe2d,0x003fe26f,0x7ec00ff2,0x81ffb80f,0x04fe86fd,
    0xff709ff1,0xfa837f43,0x5fb86fce,0xfb1febf2,0x027f4ff3,0x3fea4fe8,
    0x803fee02,0x3fdc06fc,0xfb80ff70,0x401fee06,0xe803fe41,0x2ff7005f,
    0xb7dc07fb,0x3fe607fa,0x36007fe1,0x2ffa803f,0xff31bfe0,0x6c09fd05,
    0x2edfd06f,0x1df501ff,0x25fb83ff,0xf12fd9fd,0x27f43fed,0xff14fe80,
    0x03ff8807,0xff700ffe,0x2e03fdc0,0x01fee06f,0xd803fe40,0x2ff7005f,
    0xb7dc07fb,0x17fc06fb,0x21f4c3ff,0x7fc402fd,0xb17fd405,0x813fa0df,
    0x9ff305fd,0xb7d409ff,0xb2fdc5fd,0x3eebf53f,0x13fa1ff3,0x5fea7f40,
    0x260dfd00,0x3fdc00ff,0xfb80ff70,0x001fee06,0xfe803fdc,0x2eff7004,
    0xbb7dc07f,0xd1ff407f,0x363fe43f,0x07fec01f,0xff9b7f40,0x2209fd01,
    0x3ff203ff,0x9b7d406f,0xe97ee1ff,0x1fd1ff1f,0x027f43fe,0x06fccfe8,
    0x3203fee0,0x07fb806f,0x2aaabfee,0x206fdaaa,0x000007fb,0x7001ff98,
    0x701feeff,0x807feadf,0xe8bfa4fe,0x807fa2ff,0xf3002ffa,0x740bfb5f,
    0x0ffd984f,0x00bffe20,0x72ff4df5,0xfc8ff4bf,0x747fe5fc,0xfdfd004f,
    0x7fc4001f,0xb803fe83,0x3ffee07f,0xffffffff,0x001fee06,0x01bfa000,
    0x0ff77fb8,0x3bfa6fb8,0xb27fe4c1,0x93ffe65f,0xbff100fe,0xffffd800,
    0x2ab7fa00,0x402ffffd,0x5404fff9,0x5c3fea6f,0x7cc7fa5f,0x747fe2ff,
    0xfbfd004f,0x5fe8009f,0x5c007fcc,0x3bfee07f,0xfeeeeeee,0x001fee06,
    0x01ffb000,0x7fbbfdc0,0xff537dc0,0xfffffdff,0xbfc9fe47,0x6c03fe7f,
    0x7c4000ff,0x7ff404ff,0x00dfffff,0x01ffffe8,0x29fd1bea,0xf87fe5fb,
    0xfe97f47f,0xf79fd004,0x7fdc005f,0x5c01bee0,0x01fee07f,0x3fdc0df7,
    0x0006f5c0,0xb8005ff9,0xb80ff77f,0x7ffec46f,0x322feadf,0x4bfafd3f,
    0x05ff507f,0x003ff200,0x15799dfd,0x3a7fee00,0x71bea06f,0x7cbf71ff,
    0xfd13f20f,0x74013fa5,0x003ffb4f,0x3fe8bfe2,0x5c0ff700,0x037dc07f,
    0xff980ff7,0x5ff9004f,0x2eff7000,0x037e407f,0x7dc3ff01,0x2bf75f9c,
    0x05ff887f,0x201fee00,0xf10004fe,0x40ffea9f,0xbbff86fa,0x9883fe5f,
    0x4fe97f40,0x3a29fd00,0xbfd000ef,0x5c003fe6,0x01fee07f,0x3fdc0df7,
    0x017ffea0,0x4000bff2,0x01ff56fd,0xf30027fc,0x2fbdfb8f,0x90ff3ff1,
    0x5c0001ff,0x04fe807f,0x6c1ffd00,0x86fa80ff,0xf15fbefb,0x27fd001f,
    0x9fd004fe,0xb802ffcc,0x006fb8ff,0x7fb81fee,0xf7037dc0,0x03ffb00f,
    0x0002ffc8,0x3fe29ff1,0x005ff303,0x37ea1ff4,0x3f3fa0fe,0x0017fd46,
    0x3a01fee0,0xffb8004f,0x542ffc42,0xfeff886f,0xb001ff15,0x4013fa7f,
    0x1ffd44fe,0x7f57fc40,0x81fee003,0x37dc07fb,0x2600ff70,0x017fe400,
    0xfda84edc,0x10bff61f,0x36200dfd,0x5fffa86f,0xd137f7dc,0x333333df,
    0x7fb80133,0x4004fe80,0xff706ff8,0xf906fa87,0x03fe6bff,0x27f4ff60,
    0xfc84fe80,0xfefe802f,0x1fee000f,0x7dc07fb8,0x001fee06,0x4cdffe40,
    0xf7099999,0x87ffffff,0xffefffe8,0x953101ff,0xff303fff,0x5fff885f,
    0x3fffffee,0x406fffff,0x4fe807fb,0x00ffec00,0x37d41ffd,0xf35fff88,
    0x753f600f,0xffffffff,0x3a09fd3f,0x7fdc00ff,0x7ffe406f,0x27ffffff,
    0x37dc07fb,0x0000ff70,0x3ffffffe,0xfb15ffff,0x6403bfff,0x80cfffff,
    0xcffffffb,0x01fff300,0x7fdc9ffb,0xffffffff,0x03fdc06f,0xf50027f4,
    0x5ffa809f,0xffc81bea,0x3600ff35,0xfffffd4f,0x3fa7ffff,0x80dff104,
    0x6403fff8,0xffffffff,0x701fee7f,0x03fdc0df,0xfffff800,0x85ffffff,
    0x04c40008,0x2f3bfee0,0x00000001,0x00000000,0x00000000,0x00000000,
    0x00000000,0x00000000,0x00000000,0x00000000,0x00000000,0x00000000,
    0x00000000,0x00000000,0x00000000,0x00000000,0x3ba20000,0x5eeeeeee,
    0xddddddd3,0x3bbaabdd,0x2e02bcee,0x0cdeeeee,0xbddddd90,0x3ba20059,
    0x7775403e,0xeeeeeeee,0x013faa03,0x00fbb620,0x03d913a2,0x70000000,
    0x019dffdb,0x0f7bb6e2,0x16f76dc0,0x67776540,0x3a207d92,0x4c00000e,
    0xffffffff,0xfffff36f,0x3eedffff,0xefffffff,0xfffffc81,0xffe84fff,
    0x0effffff,0x037ffd40,0x3fffffea,0xa84fffff,0x8004fffe,0xa804fffc,
    0x4c0ff44f,0x3200001e,0x7ffffcc4,0xffa80fff,0x00efffff,0xffffffd1,
    0xfffd301b,0x13fadfff,0xf700ffc4,0x57fcc00d,0x30999999,0x333335ff,
    0x267fee13,0x42fffca9,0xec999efc,0x4eff42ff,0x05ffda99,0x007ff7ec,
    0x55555551,0x74c9ff55,0x004fffff,0x027f7fcc,0x03fa27d4,0x0000bffa,
    0x7f43ffb1,0x302a621d,0xf7315bff,0x47bfa0df,0x7cc4ffa8,0x5b999bff,
    0x3fe209fd,0x801bee01,0xf9801ff9,0x07fb800f,0x7e41ffd1,0x745ff885,
    0x40ff904f,0x03ffaff8,0xf07fd400,0x09ff19ff,0x4febfe80,0x3fc3fb80,
    0x003ffd88,0x4c3ffd30,0x3fa000ff,0xb85ff505,0x43ff506f,0x7f400efe,
    0x403ff104,0x3e6006fb,0x0ff9801f,0x2607fb80,0x417f24ff,0x827f47fd,
    0xff500ffa,0xd0001bf6,0x3e0cb89f,0x5bf2004f,0xb55304fe,0x5ff7559f,
    0x09ff9055,0x40effa80,0xf3002ff9,0x22fec03f,0x4ffa03ff,0xfe802ffa,
    0x403ff104,0x3e6006fb,0x0ff9801f,0x6c07fb80,0x6417f27f,0xa827f46f,
    0x553f607f,0xf30000ff,0x09ff001f,0x7f47fe60,0xfffffb04,0xdfffffff,
    0x0037fea0,0xfe817fee,0x37dc01cf,0xff89bee0,0x7dd3f601,0x209fd007,
    0x3ee01ff8,0x07fe6006,0x2003fe60,0x7fdc07fb,0x3fa0bf90,0xfe827f45,
    0x225ff105,0xfb0003ff,0x013fe00b,0x09fd1ff4,0x2affaaa6,0x02aadfca,
    0xc803bfe6,0x7f4c03ff,0xfc80beff,0xf33fd405,0xffffffff,0x017f6bff,
    0xff8827f4,0xfb555551,0x0155555f,0xf3003ff3,0x3333335f,0xf501fee1,
    0xb317f23f,0x9dfe81ff,0x00dfeb99,0x06fd8ff5,0x001ff980,0xdf7009ff,
    0x7f804fe8,0xd10027d4,0xffd883ff,0x3ffae002,0x02fec4ff,0xfffa9fea,
    0xffffffff,0x3a00bfb5,0x23ff104f,0xfffffffe,0x981fffff,0xffffffff,
    0xfffff33f,0x3ee9ffff,0xc97fcc07,0xffffffff,0xfffffe81,0x3f600dff,
    0x0007fdc5,0xff8017f6,0x20ffc404,0x47f804fe,0x7c4003fb,0x0bffa1ff,
    0x7ffdc400,0xf701bf24,0x0007fccd,0x3fa00df9,0x2e3ff104,0xcffdcccc,
    0xf980cccc,0xffffffff,0xddddff33,0x1fee7ddd,0x3f25ff30,0x204fffff,
    0xffeeeffe,0x85ff02ff,0x26003ff8,0x3fe001ff,0x7427ec04,0x237c404f,
    0x362002fc,0x7ff442ff,0x3fec0002,0x7ec01ff5,0x800bfe25,0xfd800ffb,
    0x403ff505,0x3e6006fb,0x0ff9801f,0x5407fb80,0x22bf91ff,0x9fd03ffb,
    0xa83ffd30,0x06fe80ff,0xf0017f60,0x837d409f,0x2fcc04fe,0x744007f6,
    0x3ff601ff,0x9fee0003,0xff103ff8,0x2006fe85,0xfc804ff9,0x01fff887,
    0xf9801bee,0x0ff9801f,0x5c07fb80,0xb8bf90ff,0x04fe80ff,0x5fd8bff1,
    0x3001ff70,0xff8003ff,0x203ff104,0xeeea84fe,0xeffeeeff,0xdff300ee,
    0x09ff9001,0x2ffcc066,0xfd30fff2,0x01bff30d,0x819ff902,0x4c7ff739,
    0x2e01ffff,0x3fe6006f,0x00ff9801,0x7ec07fb8,0x3fa17f26,0x3604fe85,
    0x7ffffc6f,0x03ffffff,0xf8006fd8,0xffff504f,0xffffffff,0x3fffea9f,
    0xffffffff,0x05ffb80f,0x206ffd40,0xffeeeffb,0x7ff441ff,0x00efffef,
    0xddddfff9,0xfffd88ff,0x3fe6ffef,0xffaffeff,0x801bee01,0xf9801ff9,
    0x07fb800f,0x5fc8ffea,0x7f41ffb8,0xfa97fe04,0xffffffff,0x7fcc05ff,
    0x04ff8002,0xfffffff5,0x09ffffff,0x407f87f9,0x30004ffc,0x7f543dff,
    0x00cfffff,0x13bfffae,0x3ffff660,0xffd505ff,0x7f447dff,0x03ff1eff,
    0xf30037dc,0x1ff3003f,0x260ff700,0x82fe46fe,0x827f44ff,0x3bf63ffa,
    0xc9999999,0x1bf600ff,0x0027fc00,0xfc809fd0,0xfd81be22,0x7440002f,
    0x4ccc41ff,0x00098000,0x40013310,0x004c4018,0x30004c40,0xff3003ff,
    0x33ff7001,0x83fff953,0x1ff705fc,0xf95127f4,0x403ff8df,0xff302ff9,
    0x33331005,0x01333bff,0x36027f40,0xa817e61f,0xb100001f,0x0000000b,
    0x00000000,0x98000000,0xff9801ff,0x6fffffff,0xfffffff7,0x0bf901df,
    0xffe93fe2,0x0effffff,0x3a003fea,0x00dfb05f,0x3ffffff2,0x2004ffff,
    0x07f404fe,0x00000bf5,0x00000000,0x00000000,0x00000000,0xf3003ff3,
    0xffffffff,0x3bfffeed,0x17f201ce,0xffd0ffc8,0xb039dfff,0x3ff200df,
    0x8017fcc0,0xfffffffc,0x3a004fff,0x707fc04f,0x0000009f,0x00000000,
    0x00000000,0x00000000,0x00000000,0x00000000,0x00000000,0x00000000,
    0x00000000,0x00000000,0x00000000,0x30000000,0x07ddfdb7,0xdd3013b6,
    0x54017aa3,0x64cbd35e,0x9b640cee,0x87d912ee,0xeeeeeeeb,0x1775c5ee,
    0x3b21bd90,0x01bdfb51,0x51001a88,0x205eb801,0x4aaa1aa9,0xeeeeeee8,
    0x5443eeee,0x0013002a,0x6664c130,0x5553cccc,0x55555555,0x00015555,
    0x3ffffe00,0x7e40efff,0xa9bf200f,0x2bf9007f,0xffff77f9,0x7cfec1df,
    0xfffd8fff,0x3fffff24,0xfe86ffff,0x22ffa80f,0xffffcafe,0x13e601ff,
    0x403ffe20,0xf502fff8,0x45bfe27f,0xffffffff,0xffb83fff,0x3bffee04,
    0xfd11ba81,0x3fffea3f,0xffff5fff,0xffffffff,0x00005fff,0x2a2673a0,
    0x7fcc4ffc,0xf88ffe02,0x34fd800f,0x933df9ff,0x76fec7ff,0xf9afcfc8,
    0x26666626,0xf884ffa9,0x227fc45f,0xb89efefe,0x0fe205ff,0x413ffea0,
    0xa80ffbfd,0x997fe3ff,0x99999999,0x9ff30099,0xffffff50,0xff92fe83,
    0x333326bf,0x99993ccc,0x99999999,0x00003999,0xd0ffb000,0x03fea0bf,
    0x20d443ff,0x9fff33fe,0x7fecdfb0,0x3fc9ff71,0x502ff440,0x437ec7ff,
    0x7fc85ffe,0x89fc4be6,0x5fff884d,0x09f95f98,0x2ffc5ff3,0x7ec40000,
    0xfe8a7ec4,0x323ff32f,0x00005fff,0x00000000,0x2e07fd40,0x85fd80ff,
    0xf1bee2fe,0x417fe63f,0xa97f67fc,0x003fe0ff,0xfd801ffb,0xe81ffa8f,
    0x21ff506f,0xaaf8dffa,0xbff505ff,0x3fe23fd0,0xff17fcc1,0x44444449,
    0x00008888,0xfffb07fe,0x7ff44bff,0x00000001,0x4c000000,0x1ffc40ff,
    0x3f60bfe2,0xff83ff63,0x2601ff30,0xfa8bf64c,0xf7007fc5,0xdfd1003f,
    0x13fa07ff,0x3ee0ffc4,0x201dfeff,0x27d43ff9,0x3ff11bee,0xfff8a7f4,
    0xffffffff,0x01770003,0x301bfff9,0x00000000,0xfda80000,0x80ffffff,
    0x83fdc6fc,0x7fff14fc,0x0ff99fe2,0xfa8bf600,0xf9807fc5,0x3fe6003f,
    0x413fa05f,0xfe881ff8,0x0ffb803f,0x17f407fc,0x9ff43ff1,0xfffffff8,
    0x0003ffff,0x00013100,0x00000000,0xdffd1000,0x01ffdddd,0x27f43ff3,
    0xf9f55fb8,0xff99be6d,0xa8bf6000,0x4407fc5f,0x7c4005ff,0x13fa03ff,
    0xf910ffc4,0x883bfdfd,0x7dc3ffda,0x001ff304,0x00000000,0x00000000,
    0x00000000,0xff303ffb,0x7cd3fa01,0x36df500f,0x5fa9fe8f,0xd8003fe6,
    0xff17ea2f,0x001dfb01,0x01ffffd8,0x3fe209fd,0x5f19ff71,0x7fecbff5,
    0x006ec42e,0x000007d9,0x00000000,0x00000000,0x7ff00000,0x5c03fe60,
    0x440bf97f,0x9f76f8ff,0x07fcc9f7,0x7d45fb00,0x3f207fc5,0x7fe4001f,
    0xfe80efd9,0x263ff104,0x3627f11e,0x00006ee4,0x00000000,0x00000000,
    0x00000000,0x817fc400,0xff100ffc,0xff805ff5,0xf9df13fb,0x0007fcc7,
    0x22fd45fb,0x0bfea0ff,0x227ff500,0x04fe85ff,0x3e203ff1,0x00000003,
    0x00000000,0x00000000,0x00000000,0x3a62ffc0,0x3f600fff,0xefe807fe,
    0x87fbfa0f,0x36000ff9,0xff17ea2f,0x0013fe21,0xffa8bff1,0xf8827f44,
    0x009f301f,0x00000000,0x00000000,0x00000000,0xb8000000,0xbfffeeff,
    0x3fea00ff,0x6ffd804f,0xf307ffdc,0x17ec001f,0xb0ff8bf5,0xffffffff,
    0x0ffe83ff,0x3fa2ffc8,0x403ff104,0x00000009,0x00000000,0x00000000,
    0x00000000,0xffffb800,0xe801ff1d,0xffc801ff,0x263ffc43,0x3f6000ff,
    0x1ff17ea2,0x3ffffff6,0x3f21ffff,0x1ffd102f,0x7fc413fa,0x00000001,
    0x00000000,0x00000000,0x00000000,0x00620000,0x00000000,0x00000000,
    0x00000000,0x00000000,0x00000000,0x00000000,0x00000000,0x00000000,
    0x00000000,0x00000000,0x00000000,0x00000000,0x00000000,0x00000000,
    0x00000000,0x00000000,
};

static signed short stb__consolas_28_usascii_x[95]={ 0,5,3,0,1,0,0,6,4,3,2,1,3,3,
5,1,1,1,2,2,0,2,1,1,1,1,5,3,1,1,2,4,0,0,2,1,1,2,2,0,1,2,2,2,
3,0,1,0,2,0,2,1,1,1,0,0,0,0,1,4,2,3,1,0,0,1,2,2,1,1,0,1,2,2,
1,2,2,1,2,1,2,1,2,2,0,2,0,0,0,0,2,2,6,3,0, };
static signed short stb__consolas_28_usascii_y[95]={ 20,0,0,2,-1,0,1,0,-1,-1,0,5,15,11,
15,0,1,2,1,1,2,2,2,2,1,1,6,6,4,9,4,0,0,2,2,1,2,2,2,1,2,2,2,2,
2,2,2,1,2,1,2,1,2,2,2,2,2,2,2,0,0,0,2,23,0,6,0,6,0,6,0,6,0,0,
0,0,0,6,6,6,6,6,6,6,1,6,6,6,6,6,6,0,-3,0,9, };
static unsigned short stb__consolas_28_usascii_w[95]={ 0,5,9,15,13,16,16,4,8,9,12,14,7,9,
5,13,14,13,12,12,15,12,13,13,13,13,5,8,12,13,12,9,16,16,12,13,14,11,11,14,13,12,10,13,
11,15,13,15,12,16,13,13,14,13,16,15,16,16,13,8,12,8,13,16,10,13,12,11,13,13,15,14,12,12,
11,13,12,14,12,14,12,13,13,12,14,12,15,15,15,15,12,11,3,11,15, };
static unsigned short stb__consolas_28_usascii_h[95]={ 0,21,8,18,25,21,20,8,27,27,13,15,10,3,
6,23,20,18,19,20,18,19,19,18,20,19,15,19,17,7,17,21,26,18,18,20,18,18,18,20,18,18,19,18,
18,18,18,20,18,24,18,20,18,19,18,18,18,18,18,26,23,26,9,3,7,15,21,15,21,15,20,20,20,20,
26,20,20,14,14,15,20,20,14,15,20,15,14,14,14,20,14,26,29,26,7, };
static unsigned short stb__consolas_28_usascii_s[95]={ 255,194,153,128,95,177,117,251,15,5,118,
237,131,210,204,126,134,98,1,178,112,219,232,84,205,39,245,246,157,163,144,
153,36,67,54,149,25,13,1,163,216,203,14,172,160,144,130,101,100,109,40,
191,230,25,186,53,113,83,69,86,140,65,139,220,177,1,200,212,163,198,42,
27,74,1,74,226,213,61,105,183,14,87,47,170,240,224,15,31,89,58,76,
24,1,53,188, };
static unsigned short stb__consolas_28_usascii_t[95]={ 1,1,91,72,1,1,31,52,1,1,91,
72,91,91,91,1,31,72,52,31,72,31,31,72,31,52,52,31,72,91,72,
1,1,72,72,31,72,72,72,31,52,52,52,52,52,52,52,31,52,1,72,
31,52,52,52,52,52,52,52,1,1,1,91,91,91,91,1,72,1,72,31,
31,31,31,1,1,1,91,91,72,31,31,91,72,1,72,91,91,91,31,91,
1,1,1,91, };
static unsigned short stb__consolas_28_usascii_a[95]={ 246,246,246,246,246,246,246,246,
246,246,246,246,246,246,246,246,246,246,246,246,246,246,246,246,
246,246,246,246,246,246,246,246,246,246,246,246,246,246,246,246,
246,246,246,246,246,246,246,246,246,246,246,246,246,246,246,246,
246,246,246,246,246,246,246,246,246,246,246,246,246,246,246,246,
246,246,246,246,246,246,246,246,246,246,246,246,246,246,246,246,
246,246,246,246,246,246,246, };

// Call this function with
//    font: NULL or array length
//    data: NULL or specified size
//    height: STB_FONT_consolas_28_usascii_BITMAP_HEIGHT or STB_FONT_consolas_28_usascii_BITMAP_HEIGHT_POW2
//    return value: spacing between lines
static void stb_font_consolas_28_usascii(stb_fontchar font[STB_FONT_consolas_28_usascii_NUM_CHARS],
                unsigned char data[STB_FONT_consolas_28_usascii_BITMAP_HEIGHT][STB_FONT_consolas_28_usascii_BITMAP_WIDTH],
                int height)
{
    int i,j;
    if (data != 0) {
        unsigned int *bits = stb__consolas_28_usascii_pixels;
        unsigned int bitpack = *bits++, numbits = 32;
        for (i=0; i < STB_FONT_consolas_28_usascii_BITMAP_WIDTH*height; ++i)
            data[0][i] = 0;  // zero entire bitmap
        for (j=1; j < STB_FONT_consolas_28_usascii_BITMAP_HEIGHT-1; ++j) {
            for (i=1; i < STB_FONT_consolas_28_usascii_BITMAP_WIDTH-1; ++i) {
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
        float recip_width = 1.0f / STB_FONT_consolas_28_usascii_BITMAP_WIDTH;
        float recip_height = 1.0f / height;
        for (i=0; i < STB_FONT_consolas_28_usascii_NUM_CHARS; ++i) {
            // pad characters so they bilerp from empty space around each character
            font[i].s0 = (stb__consolas_28_usascii_s[i]) * recip_width;
            font[i].t0 = (stb__consolas_28_usascii_t[i]) * recip_height;
            font[i].s1 = (stb__consolas_28_usascii_s[i] + stb__consolas_28_usascii_w[i]) * recip_width;
            font[i].t1 = (stb__consolas_28_usascii_t[i] + stb__consolas_28_usascii_h[i]) * recip_height;
            font[i].x0 = stb__consolas_28_usascii_x[i];
            font[i].y0 = stb__consolas_28_usascii_y[i];
            font[i].x1 = stb__consolas_28_usascii_x[i] + stb__consolas_28_usascii_w[i];
            font[i].y1 = stb__consolas_28_usascii_y[i] + stb__consolas_28_usascii_h[i];
            font[i].advance_int = (stb__consolas_28_usascii_a[i]+8)>>4;
            font[i].s0f = (stb__consolas_28_usascii_s[i] - 0.5f) * recip_width;
            font[i].t0f = (stb__consolas_28_usascii_t[i] - 0.5f) * recip_height;
            font[i].s1f = (stb__consolas_28_usascii_s[i] + stb__consolas_28_usascii_w[i] + 0.5f) * recip_width;
            font[i].t1f = (stb__consolas_28_usascii_t[i] + stb__consolas_28_usascii_h[i] + 0.5f) * recip_height;
            font[i].x0f = stb__consolas_28_usascii_x[i] - 0.5f;
            font[i].y0f = stb__consolas_28_usascii_y[i] - 0.5f;
            font[i].x1f = stb__consolas_28_usascii_x[i] + stb__consolas_28_usascii_w[i] + 0.5f;
            font[i].y1f = stb__consolas_28_usascii_y[i] + stb__consolas_28_usascii_h[i] + 0.5f;
            font[i].advance = stb__consolas_28_usascii_a[i]/16.0f;
        }
    }
}

#ifndef STB_SOMEFONT_CREATE
#define STB_SOMEFONT_CREATE              stb_font_consolas_28_usascii
#define STB_SOMEFONT_BITMAP_WIDTH        STB_FONT_consolas_28_usascii_BITMAP_WIDTH
#define STB_SOMEFONT_BITMAP_HEIGHT       STB_FONT_consolas_28_usascii_BITMAP_HEIGHT
#define STB_SOMEFONT_BITMAP_HEIGHT_POW2  STB_FONT_consolas_28_usascii_BITMAP_HEIGHT_POW2
#define STB_SOMEFONT_FIRST_CHAR          STB_FONT_consolas_28_usascii_FIRST_CHAR
#define STB_SOMEFONT_NUM_CHARS           STB_FONT_consolas_28_usascii_NUM_CHARS
#define STB_SOMEFONT_LINE_SPACING        STB_FONT_consolas_28_usascii_LINE_SPACING
#endif

