// Font generated by stb_font_inl_generator.c (4/1 bpp)
//
// Following instructions show how to use the only included font, whatever it is, in
// a generic way so you can replace it with any other font by changing the include.
// To use multiple fonts, replace STB_SOMEFONT_* below with STB_FONT_consolas_bold_25_usascii_*,
// and separately install each font. Note that the CREATE function call has a
// totally different name; it's just 'stb_font_consolas_bold_25_usascii'.
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

#define STB_FONT_consolas_bold_25_usascii_BITMAP_WIDTH         256
#define STB_FONT_consolas_bold_25_usascii_BITMAP_HEIGHT         96
#define STB_FONT_consolas_bold_25_usascii_BITMAP_HEIGHT_POW2   128

#define STB_FONT_consolas_bold_25_usascii_FIRST_CHAR            32
#define STB_FONT_consolas_bold_25_usascii_NUM_CHARS             95

#define STB_FONT_consolas_bold_25_usascii_LINE_SPACING          16

static unsigned int stb__consolas_bold_25_usascii_pixels[]={
    0x00003ff7,0x00cc8800,0xd300ab98,0x5500019b,0x76e4c001,0x7ddddd90,
    0x3bbbbba6,0x22004400,0x20000099,0x00262198,0x33066200,0x06aa6001,
    0x0400aaa8,0xbccb9800,0x0d442aaa,0x4cc41310,0xff713330,0x26075403,
    0xffd8001e,0x3fffa606,0x7ffd40ef,0x07fc002f,0x0ffffc80,0x29fffffb,
    0x0ffffff9,0xdffffd88,0x004ff980,0xfc9ffa00,0xd0002dff,0x027fccff,
    0x3e06ffa8,0xffea80ff,0xffb000cf,0x4fffffff,0x440efffb,0x53ffa1ff,
    0x1ffbbffd,0xff8dff50,0x7ff4001f,0xdbfff507,0x6dc41dff,0xf1000fff,
    0x3ffea00f,0x3f332e3c,0x99bff34f,0xffff9819,0xfe81ffff,0xfa80000f,
    0x3ffff24f,0x7f4000ef,0x8013fe67,0xffa81fff,0xfffffb85,0xdffc806f,
    0x35efffdb,0xe87fd7ff,0xc9ffec4f,0x81ffbaff,0x7dc1fffa,0x3ea001ff,
    0x0dff883f,0x7dc0ffe6,0x3b6e203f,0x3600cdff,0x7fc401ff,0x4407ff34,
    0xfeccefff,0x03ffa87f,0x20ffd800,0x5fffecca,0xf33ff400,0x7fe4009f,
    0x442ffd84,0xffd99eff,0x3237fc02,0x4d7ee2ff,0x361bee6f,0x75ff93ff,
    0xfff883ff,0x00dffb03,0xb837ec00,0x09ff106f,0x3fffffea,0x1bfa02ff,
    0x7cd3fe20,0x17fee03f,0xff07ffd1,0xff98000d,0x17ffdc05,0x7ccffd00,
    0x3fe2004f,0x543ffc47,0x13fe63ff,0x7cc3ff98,0x7c53ee4f,0xfb03ff17,
    0x2e7ff27f,0x2ffec1ff,0x507ffd10,0x55555555,0xf301ff98,0x217fe03f,
    0xefeefff9,0x17fe02fd,0x7cd3fe20,0x07ffe03f,0x3ee1bfea,0x3f20002f,
    0x4ffd801f,0xff797510,0xb9a7fccf,0x5ffb00ac,0x7d427fdc,0x80ffe63f,
    0x7fd45ff8,0xb7ddbe63,0x7ffb04fd,0x3fee7fee,0x003bfe61,0x7c41fff3,
    0x5fffffff,0xaca8b7e4,0xff02ff9b,0x369ff90b,0x5ff8022f,0xf34ff880,
    0x1bfe207f,0x7c43ffc4,0xff10005f,0x17fee00d,0x3fffffee,0x333fe67f,
    0xa80effff,0x03ffa5ff,0x7f45bfe2,0x67ff401f,0x740ffea9,0xefaaffff,
    0x2a5ff900,0x21ffb8ee,0xf9002ffc,0x7fffc47f,0x7fc5ffff,0xaffffe8b,
    0x0bff03fe,0x07fa5ffd,0x4402ffc0,0x07ff34ff,0xff817fea,0x01ffd80f,
    0x002ffb80,0xffc87ffd,0x27ffeeef,0xfffffff9,0x1fff06ff,0x7ec0dff3,
    0x803fffdf,0xfffffffa,0x8aeeb883,0x3ff202ff,0x7c3ff702,0xff5000ff,
    0x4bff300d,0xdffd8ff9,0xb03fe9ff,0x5dff90ff,0xff1001ff,0x29ff1009,
    0xff703ff9,0x40fffc09,0xe8004ff9,0x3b32a07f,0x3fe60fff,0xf33ff42f,
    0x3fe65fff,0xcbffc82f,0x3fe202ff,0xf8802fff,0x00ceeddf,0xf9013f60,
    0x47fee05f,0x22006ff9,0x7cc00fff,0x3e3fee5f,0xfd9ff9bf,0x15bff704,
    0x3fffffe6,0x3ff66601,0x34ff8802,0x3fee07ff,0x407ffa04,0x2a000ffe,
    0x3fee04ff,0x7fe41fff,0x3e67fe84,0x27fe41ff,0x3ff77fcc,0x87fffee0,
    0x1ffa81aa,0x03fea000,0x2e03ff70,0x09ff51ff,0x401ffe80,0x37f25ff9,
    0x8ffa8ffa,0x3fee03fd,0x3fffee6f,0x7fc41eff,0xff1003ef,0x540ffe69,
    0x3ffe05ff,0x007ff500,0xf7007fec,0xffd017bf,0x7ccffd03,0x05ffa85f,
    0x409ffffb,0x0efffffb,0xdff509ff,0x10035557,0x5c0225ff,0x3ff701ff,
    0x9000ffee,0xff9805ff,0x5fef3f65,0x407fd7fb,0x6446fffc,0x23ffffff,
    0x001efff8,0x3fe69ff1,0x20dff503,0x7fc07ff8,0x0bff1006,0x3e01ffa8,
    0x27fe80ff,0xff984ff9,0x3ffff506,0x363ffe20,0x83ff8dff,0xffffffe8,
    0x37f603ff,0x5c1dffe8,0x3ff701ff,0x70007ff2,0xff9807ff,0x5fef3f65,
    0x205fd7fc,0x9009cffc,0x43ffffdf,0x801ffeb9,0x7ff34ff8,0x203ffe20,
    0x7e405ffa,0x1ffc802f,0xf00ffd40,0x4ffd01ff,0xffa84ff9,0x817ffe05,
    0xffd13ffb,0x3f605ffd,0xffffeeef,0xfd8ffa82,0x7fdc5fee,0x323ff701,
    0x7e4003ff,0x2ffcc02f,0x32ff77fd,0x3a03ff6f,0x9afd806f,0xff983fff,
    0x34ff8803,0x7fec07ff,0x017ff445,0x3e017fe2,0x3a00006f,0x3ffc40ff,
    0xff709ff3,0x07ffe207,0x3e22ffc8,0xfc80ffff,0x45ffc82f,0x0ff8aff8,
    0xfb8001ff,0x00bff71f,0x4c01ffe8,0x2f3fa5ff,0xfaeff8ff,0x2017fe07,
    0x07ffb1fe,0x3e2017fe,0x407ff34f,0xecbefffa,0xffb006ff,0x01ffdc01,
    0x3f601dc4,0x33ffec3f,0xfff889ff,0x80bffb02,0x7fcc4ffb,0x20fff04f,
    0xafe45ff9,0x707fa6f9,0xa8ffdc05,0x3e2007ff,0x7fcc00ff,0x3fe73f65,
    0x04ffffff,0xf82617fe,0x01ffe88f,0xff100bff,0x900ffe69,0xdfffffff,
    0x13fe6001,0xd800ffe8,0x3fea05ff,0x7fffeabf,0x2a67bfe6,0x2ea25ffe,
    0x4c00fffd,0xfc99bfff,0xfff80eff,0x8fffa60c,0x43fe0ffa,0x0fff60ff,
    0xfff0ffdc,0x17fe6001,0xfc97fe60,0xffb7ffd5,0xe85ff80d,0xffdffdef,
    0x017fe06f,0x7fcd3fe2,0xfffea803,0x7f4000cf,0x04ff980f,0xe80dfff0,
    0xfdffffff,0x3ffffe67,0x3ea0efff,0x9001ffff,0xffffffff,0xfff70dff,
    0x49ffffff,0x77ec3fe8,0x2fffc6fe,0x3f21ffb8,0x5ff7002f,0x5cbff300,
    0x0d446a7f,0x7f42ffc0,0xefffffff,0x2017fe00,0x7ff34ff8,0x017fe400,
    0xd83ffa80,0xff7000ff,0xfffd8807,0x3627fb8e,0x83efffff,0x000ceffa,
    0x67ffffdc,0xd985ffe8,0x41deffff,0xffc985fc,0x817fe40e,0x3fe61ffb,
    0x3ffc400f,0x264ffb80,0x220002ff,0xfeca84ff,0xe802ceff,0x4ff8806f,
    0x54007ff3,0x00730eff,0x3fe237fc,0x00044005,0x03300026,0x22000010,
    0x00400009,0x13004400,0x360ffdc0,0x7ff406ff,0x87ffb003,0x50000efe,
    0x3fc807ff,0x007fec00,0x7fcd3fe2,0x3ffe2003,0x9001ffff,0x17fe43ff,
    0x00000000,0x00000000,0x00000000,0x7fdc0000,0x827ffc41,0xbdb85ffd,
    0x40fffea9,0xb312effa,0xfff97109,0x002fd801,0x5167ffd4,0x269ff755,
    0x802aadff,0x2ffffff9,0x5c599100,0x0000004c,0x00000000,0x00000000,
    0x70000000,0xfff503ff,0x80fffb85,0xfffffffb,0xfffff702,0xfff509ff,
    0x03ff007f,0x1ffffb00,0x53fffff6,0x0ffffff9,0x01597500,0x00000000,
    0x00000000,0x00000000,0x00000000,0x2a03ff70,0x0fffc5ff,0xdffffea8,
    0x7ffed400,0xcde980be,0x50000001,0x3bb21dd9,0xddd33eee,0x00001ddd,
    0x00000000,0x00000000,0x00000000,0x00000000,0x500ffdc0,0x001e981d,
    0x00040001,0x00000000,0x00000000,0x00000000,0x00000000,0x00000000,
    0x00000000,0x003ff700,0x00000000,0x00000000,0x00000000,0x00000000,
    0x00000000,0x00000000,0x00000000,0x00000000,0x00000000,0x00000000,
    0x00000000,0x00000000,0x00000000,0x00000000,0x00000000,0x00000000,
    0x00000000,0x00000000,0x00000000,0x00000000,0x00000000,0x00000000,
    0x00000000,0x00300000,0x33006644,0x004cc001,0xaaa98800,0x26666620,
    0x79731000,0x85544735,0x1000acc9,0x004c0001,0x31000110,0x00571003,
    0x06620033,0x00098800,0x00026000,0x3f200026,0xdffb000f,0x4013fe60,
    0x80005ff8,0x26fffffc,0x05fffffd,0xffffffb8,0x36bfe67f,0x100effff,
    0x01bffffb,0xffffec88,0xffec880e,0x3f6600df,0xd01effff,0xffd509ff,
    0xff905dff,0x3007ffff,0x5bffffdb,0x80fff710,0x03ffffda,0x1fffff54,
    0x001fff00,0x7cc1fffa,0xbff1004f,0xfffb8000,0x3ff66fff,0x7e405fff,
    0x7ffeeeff,0x3fffbfe6,0xffa86fff,0x01ffffff,0xfffffff5,0xfffe983f,
    0xfb81efff,0x1fffffff,0x5c7fff98,0xffffffff,0x7fffff42,0x3ff205ff,
    0x44ffffff,0x107ffffb,0xfffffffb,0x3ffff20b,0xff006fff,0x3fea001f,
    0x009ff302,0x80017fe2,0x8042fff8,0x3e605ff9,0x33ff42ff,0x3e65ffff,
    0x3ffe22ff,0x87fffcce,0xcbdffff9,0x6fff41fd,0x4c5ffeba,0xcaabdfff,
    0x6fff881d,0x262bffe2,0x566c7ffb,0x82fffdba,0xcbcefffc,0xffff34fd,
    0x3fe20fff,0x2fffdbce,0x5d5fffd4,0xaa883fff,0xaaabfffa,0x3fe60002,
    0x0bff1004,0x02ffcc00,0x640bff30,0x27fe84ff,0x7e41fff9,0x117ff24f,
    0xffe87ffd,0x3ea0880e,0x0fffc45f,0x5000bff7,0x27fd41bd,0x74007ff4,
    0x7ffcc3ff,0x3fe63103,0x2607ffae,0x744ffd84,0x3ffd42ff,0x7fffffcc,
    0x2aa7ffff,0xf301aaaa,0x20f3269f,0xaaa85ff8,0x013fea01,0x3a05ff98,
    0x27fe81ff,0xffa85ff9,0x2e03ffe5,0x3ffea6ff,0x03ffd000,0x7fe49ff9,
    0x3ea00005,0x007fe85f,0xffd85ff7,0x7c4b6004,0xffb8007f,0xff83ffc5,
    0x7fffcc0f,0x27ffffff,0x05fffffd,0xfffb9ff3,0x2ffc41df,0xa803bff2,
    0x3e6004ff,0x03ffe05f,0x4ff99ffa,0xff36ff98,0xc9ffe20d,0x3fe004ff,
    0x25fffc86,0x000cfffb,0x24fff880,0xfd004ffc,0x01fff81f,0x00fff100,
    0xff8bff70,0x01ffd80f,0xfb007ffc,0x260bffff,0xffffffff,0xb97fe24f,
    0xccc81fff,0xcccceffd,0x40bff301,0x7fe80fff,0x3ea13fe6,0x40bff55f,
    0x7ffb0fff,0x897fe200,0x226ffffe,0x01dfffff,0x77ffdc00,0x55105ffe,
    0xf887ffd7,0x4ccccc7f,0x00fff100,0xfe87ffd0,0x02ffd83f,0x98007ffc,
    0xfff305ff,0x89bfea5f,0x3fff35ff,0x3fffffe0,0x303fffff,0x7ff40bff,
    0xf33ffc40,0x27ff709f,0x3fe04ffb,0x005ffd1f,0x7fd57fe6,0x7cc7ffcf,
    0x01efffff,0x7fd40ae2,0x3ea06fff,0x4c0bffff,0x7fffc6ff,0x0fff104f,
    0xc87ffb80,0xfecbefff,0x7ffc03ff,0x0bff3000,0xff07ffe6,0x7c6ffc4f,
    0x333202ff,0xcccceffd,0x40bff301,0x7fec3ffd,0xf113fe67,0x13fee5ff,
    0xfff1ffe8,0x37fe6005,0xfff2fffd,0xfffff910,0x13ffa05f,0x3ffffff2,
    0xffee980d,0x3fea1fff,0x27ffffc6,0x2007ff88,0xfd01fff9,0xffffffff,
    0x00fff805,0x260bff30,0x27fe85ff,0x3ffeeff8,0x013fea00,0x2a05ff98,
    0xffeabfff,0x27bfe67f,0x2a5ffea9,0x3ffe05ff,0x2007ffd0,0x0dfffff8,
    0xfd501bfe,0xff881fff,0x37ff60ff,0x805fffc9,0xf30fffd9,0xffb998df,
    0x00fff104,0x700fffe6,0xffd7dffd,0x00fff803,0x260bff30,0x27fe84ff,
    0x0ffffff8,0x013fea00,0x7405ff98,0xfeffffff,0x3ffffe67,0x3e60efff,
    0x4fff106f,0xf1004ffd,0xff887fff,0x3fff7005,0x2a3fffd0,0x7ffcc5ff,
    0x25ffd001,0xfa80fff8,0x0fff104f,0x007fff30,0x2007ffc0,0xf3000fff,
    0x13fe60bf,0xdff89ffa,0x2a006ffd,0x3e6004ff,0x7fec405f,0x267fe8df,
    0x3effffff,0xa80fff88,0x3ffee5ff,0x05fff000,0x7c009ff7,0xfff882ff,
    0xf905ff91,0x3ff6005f,0x2a0fffe2,0xfff104ff,0x03fff980,0x017fea00,
    0x4c00bffa,0x9ff305ff,0x7fc4ffd0,0x004ffe8d,0x4c009ff5,0x826005ff,
    0x33fe67fe,0x5ffd8018,0xf117ff44,0x41101bff,0x7f445ffc,0xff88020f,
    0x6cffd00f,0x2ffc83ff,0x20fff880,0x7d41fffb,0x0fff104f,0x001fffc4,
    0x005fff50,0x5335dffb,0x4c17fe60,0x27fe84ff,0xfff35ff8,0x09ff5007,
    0x002ffcc0,0x7fccffd0,0x3ffe6004,0x86ffecbe,0xcbdffffb,0x3ffe21fe,
    0x45ffea9c,0xfcaabdfd,0x7ff506ff,0x445fffdc,0x5710fffb,0xbfff9533,
    0x57bfffd0,0x33229ffb,0xcccfffcc,0xddffff11,0x6445dddd,0x4fffedcc,
    0xfffff300,0x32aaa2ff,0x30aaaeff,0x4ffd09ff,0x3fee5ff8,0x27fd401f,
    0xff955510,0x4001555d,0x13fe67fe,0xfffff900,0x3f203dff,0x1fffffff,
    0x7fffffd4,0x7ffec0ef,0x20ffffff,0xe85ffed8,0xffffffff,0x3ffffe62,
    0xe980efff,0xffffffff,0xffffff14,0x3ea7ffff,0xffffffff,0x3fffe22f,
    0x54004fff,0xf36ffffe,0xffffffff,0x213fe65f,0x17fe27fe,0x5401fffb,
    0x3fe604ff,0xffffffff,0x99ffa002,0xea8004ff,0xa804ffff,0x0ceffffd,
    0x4efffe98,0xffffff90,0xeff9819f,0xffff9102,0xfff983bf,0xc802efff,
    0x1cfffffe,0xfffffff1,0x3fea7fff,0xffffffff,0x37bffe22,0x2620000b,
    0x3fffe609,0x32ffffff,0x4ffd09ff,0x7f445ff8,0x13fea06f,0xffffff98,
    0x2002ffff,0x0fba66ed,0x00013000,0x09800262,0x01333100,0x0cc40018,
    0x00266620,0x0004cc40,0x00000000,0x00000000,0x00000000,0x00000000,
    0x00000000,0x00000000,0x00000000,0x00000000,0x00000000,0xffffffd8,
    0x36e202ff,0x1ffe3ffe,0xffda7fd4,0x7c7fffff,0xffffffff,0xffff55ff,
    0x3ea05bdf,0x6ffc80ff,0xff301ff2,0x203fffa5,0x1bff65ff,0x7ec5fff3,
    0xffffffff,0x407ffd2f,0x9ff94ffc,0xf897ff40,0xffffffff,0xf501ffd6,
    0x3fffee9f,0xb2ffffff,0xffffffff,0x3fffff69,0xffff6fff,0xd8019bdf,
    0xffffffff,0xffffd882,0x41ffe3ff,0xfffb4ffa,0xff8fffff,0xffffffff,
    0xfffff55f,0x3f60dfff,0x17ffc45f,0x7cc01ff7,0x07fffd1f,0x7ffecbff,
    0xd8fffee0,0xffffffff,0x0dff92ff,0xff88fff4,0x26ffa80f,0xfffffff8,
    0x01ffd6ff,0x3fee9ff5,0xffffffff,0xffffffb2,0x3fff69ff,0xff6fffff,
    0x7fffffff,0x7777fec0,0x7f442eee,0x21ccceff,0x9ff507ff,0x3f33332e,
    0x7666647f,0x53cccdff,0xfffb9dff,0x3fff309f,0x3ee2ffe4,0x47fe600f,
    0xff86fffe,0xe8ffff65,0x3ff63fff,0xffffffff,0x101fff32,0x4ffc8fff,
    0x2a22ffe8,0xaacffdaa,0xf501ffd2,0x3bbbaa9f,0xb1fffeee,0x99999bff,
    0x3337ff65,0x9fff3ccc,0x09fffdb9,0xfc801ff6,0x3ffc01ef,0x7c04ffa8,
    0x17fe407f,0x7ec4ffa8,0x2bffb06f,0x7d41fff8,0x43fea00f,0x7c2ffffe,
    0x57fffa5f,0x004ffff8,0xfff8fff5,0x445ffa82,0x3fea0fff,0x417fe406,
    0xffa80ffe,0x25ffe804,0x7ec01ffd,0x43ffc01f,0xfd80fffc,0x1fff1007,
    0x2a0fff00,0x3ffc04ff,0x540bff20,0x3ffcc4ff,0xfc9fff88,0x01ffa85f,
    0x7ff43fea,0xd2ffc6ff,0xbf71ff9f,0x3fa009fd,0x427fe43f,0xffc82ffd,
    0x900bffa4,0x1ffd05ff,0xc809ff50,0x3ff60fff,0x00ffec01,0x7ff41ffe,
    0x5007fd84,0x3fe00bff,0x809ff507,0x7fe407ff,0x989ff502,0x3ff206ff,
    0xf980fffe,0x2a1ff11f,0x3f3bfa7f,0xff97fe1f,0xdbfdaffa,0x7ff9804f,
    0xff86ffa8,0x8fff880f,0xfc806ff9,0x80ffe82f,0x3e604ffa,0x0ffec2ff,
    0xf007ff60,0x17fee0ff,0x33bbbff6,0xecdffc81,0x3ffc1cef,0x7c04ffa8,
    0x17fe407f,0x3a64ffa8,0x3fe203ff,0xff304fff,0x7d4bfee3,0x3fe7bfa7,
    0xaff97fe5,0xfd8ffcfc,0x03ffd805,0x7fcc3fff,0x36fff205,0xffc802ff,
    0xcccffe82,0x204ffdcc,0xffd84ffe,0x567fec01,0xfff1aaaa,0x361bfe60,
    0x5fffffff,0x7fffffec,0x1ffe3fff,0x3e027fd4,0x17fe407f,0xffffffa8,
    0xffb804ff,0x3ff300ff,0x3fdd7ff6,0x47ff6dfd,0x2abfe5ff,0x0bfb6fff,
    0xb00fff98,0x1ffe47ff,0xdfffff10,0x20bff200,0xfffffffe,0xff904fff,
    0xffffb01d,0x3f65ffff,0x3fffffff,0x3fe20fff,0xfdcccb87,0x3ff64fff,
    0xfffeccef,0x3ea0fff1,0x03ffc04f,0x7d40bff2,0x00ffffff,0x03ffffb0,
    0x3fe2bfe2,0x7f4df77f,0x3fe9ff56,0xff15ff15,0xb01bf67f,0x7fdc09ff,
    0x9003ffa5,0x2003ffff,0xffe82ffc,0xffffffff,0x01fff984,0xfffffffb,
    0x3ffff65f,0xfff3ffff,0x801ffe20,0x3ff67ffc,0xff4ffd83,0x013fea0f,
    0xffc80fff,0xd7bff502,0xff300dff,0x3e20dfff,0x9ffdfaaf,0xe9bfa6fb,
    0xf15ff8ff,0x643ff63f,0x3ffe606f,0x45ffe200,0xff8806ff,0x3ff2005f,
    0xa80ffe82,0x4ffe84ff,0x2ab3ff60,0x3ffb0aaa,0xf307ff80,0x7fc400df,
    0x507ff90f,0x03ffebff,0xff013fea,0x02ffc80f,0x3fa29ff5,0x67ff403f,
    0x5ff02fff,0xf99fd5fb,0xff737f4b,0x3fe2bff9,0x37e4df71,0xd009ffb0,
    0x09ff55ff,0x800bff60,0xffe82ffc,0x644ffa80,0x7fec06ff,0x00ffec01,
    0x7fdc1ffe,0x3ffe2005,0xf509ff70,0x203ffabf,0x3e203ffb,0x17fe407f,
    0x3ea4ffa8,0x3ffea07f,0xf80fffb8,0xefb8ffbf,0xf1bfa5fc,0x3e6bffff,
    0x7e41311f,0x01fff307,0xff99ff70,0x0bff6003,0xe82ffc80,0x4ffa80ff,
    0xb007ffe6,0xffd803ff,0xe83ffc01,0x3f2003ff,0x21ffea6f,0x7ffb3ffd,
    0x2023ffb0,0x7e406ffa,0x89ff502f,0xffd03ffe,0x213ffe27,0xff35feff,
    0x237f4bfd,0xf35ffffc,0x83fe403f,0xf3004ffc,0x400fffdf,0x32002ffd,
    0x0ffe82ff,0x3fa4ffa8,0x1ffd804f,0x200ffec0,0x7fec47ff,0xd7555906,
    0xffe87fff,0x0fffc9ad,0x9337fff5,0x4d6f4dff,0x6403fffb,0x9ff502ff,
    0xfb86ffb8,0x3ffee0ff,0xd1ffff40,0x37f49fff,0x557fffe2,0x1fee00ff,
    0x8003ffe2,0x004fffff,0xa880bff6,0xaacffdaa,0xf501ffd2,0x3bffee9f,
    0xb2eeeeee,0xffd803ff,0xf3cccccd,0xfffb99ff,0xffff105f,0xf309ffff,
    0x5fffffff,0xffffffd8,0x3fffa1ff,0xfc806fff,0x89ff502f,0x3e22fff8,
    0x5ffe83ff,0xf907fff4,0x437f49ff,0xff55fffc,0x207fdc01,0x64005ffc,
    0x2002ffff,0x3e202ffd,0xffffffff,0xf501ffd6,0x3ffff69f,0xb3ffffff,
    0xffd803ff,0xf6ffffff,0xdfffffff,0x3fffe203,0x36201cff,0x701dffff,
    0x81bfffff,0x04fffffb,0x2a05ff90,0x6ffc84ff,0x7dc1fff2,0x1bff62ff,
    0x7f47fff3,0x55fff986,0x7fdc01ff,0x007ffe20,0x01ffff50,0x1017fec0,
    0xffffffff,0x203ffadf,0xfffb4ffa,0x7fffffff,0xfb007ff6,0xdfffffff,
    0x33bffffe,0x01333003,0x44003300,0x00988009,0x00000000,0x00000000,
    0x00000000,0x00000000,0x00000000,0x00000000,0x00000000,0x00000000,
    0x00000000,0x00000000,0x00000000,0x00000000,0x00000000,0x00000000,
    0x07fcc000,0xfffa85ff,0x400ceeff,0x500ffffa,0xbffd09ff,0x77ffffd4,
    0x3ff2002d,0x03ffc85f,0x140000a0,0x1bccca98,0x54405710,0xa8800acc,
    0x5100abcb,0xa8801599,0x2a22bccc,0x2a2aa81a,0x8379712a,0x79930aa8,
    0x872a5510,0x06e200bb,0xff10ff98,0xfffffa83,0x3201ffff,0xf502ffff,
    0x0effb89f,0x3fffffea,0x7cc01eff,0xffc85fff,0x007fb003,0x321fec40,
    0x5fffffff,0xfa84ffe8,0x203fffff,0x4ffffffb,0xffffffb8,0xfffff904,
    0x427fd4ff,0x27ff67ff,0x263fffff,0xffffdaff,0x3effe60e,0x2fffdaff,
    0x503fff88,0x20ffc4ff,0xfcaadffa,0x3ffe06ff,0x9ff505ff,0x2a0fffcc,
    0xffdcceff,0x3ff600ef,0x3ffc85ff,0x05fffa80,0x0fffe880,0x3f737bf6,
    0x3ffe63ff,0x66fffd47,0xffd83fff,0x6c4fffff,0xffffffff,0x66fffe44,
    0x13fea7dc,0xfffd9ffe,0x30fffeff,0xfffffdff,0x7fffcc9f,0x4ffefeff,
    0x447fff98,0xfa99ffc9,0x13fea19f,0xf301fff3,0x2a0fffbf,0x13ffa4ff,
    0xff313fea,0x33fea05f,0x3ffc85ff,0x1dfff300,0x3bffe600,0x7fcc04c0,
    0xd1bffe26,0x7ffc43ff,0x42fffea0,0x3ffe62a8,0x43fff912,0x7d401fff,
    0x367ff84f,0xffb0dfff,0x4bfffe67,0x3fe66ffa,0xf96ffb8f,0x1ffff10d,
    0x7ffffff4,0xf51fffff,0x01fff09f,0x3ffd5ff7,0x3ee9ff50,0x09ff506f,
    0xff109ff9,0xf90bff1d,0x7f44007f,0x7fd401ef,0x7ff8005f,0xff506f54,
    0x7c3ff90b,0xffd803ff,0x3e3ffe83,0x7fd403ff,0x3f67ff84,0x9a7fd45f,
    0x3ffc1fff,0x3fea7ff3,0x3e60ff92,0x3fffa0ff,0xffffffff,0xf989ff51,
    0x2effd06f,0xcffa84ff,0xf500fff8,0x09ff709f,0x17fe3ff9,0x1000fff2,
    0x2e05fffb,0xa9803fff,0x007ffccb,0x9999bff7,0x3fe27ffd,0x01ffd007,
    0x7fecbff9,0xffa81cef,0x3f67ff84,0x98d5441f,0x27fe85ff,0x1ff51ff9,
    0x6ff81ff2,0x4ce7f4c4,0x3ea19efd,0xfffbaadf,0xf35ff881,0xd9ff50df,
    0x7fd407ff,0x4c3ffc84,0x217fe5ff,0x90003ffc,0xffd87fff,0x7fec402f,
    0x007fffff,0xfffffff9,0x3fe67fff,0x20fff006,0x3fa26ffa,0x2a2effff,
    0x27ff84ff,0xf9801ffd,0x267fe84f,0x21ff51ff,0x5ff707fc,0x5fd8ffa0,
    0xffffffa8,0x7ff502ff,0x3ea07ffc,0x5406ffff,0x7ffd44ff,0xff07ff41,
    0x007ff90b,0xa8ffff40,0x74404fff,0xffccceff,0x9bffb007,0x23999999,
    0xff007ff9,0x0bff301f,0x5fffffb5,0x3fe13fea,0x2007ff67,0x7fe84ff9,
    0x7fd47fe6,0x76ccff90,0x8bfe04ff,0xfffa84fd,0x85ffffff,0x3ff61ffd,
    0x7ff7fd43,0x3bfea01f,0x44fffecc,0x2ffc2ffb,0x4001ffe4,0x541effe8,
    0x3ee05fff,0x007ff85f,0x22005ff7,0xfe800fff,0x04ffb82f,0x557ffea2,
    0x3ffc44ff,0xf3003ffb,0x4cffd09f,0x21ff51ff,0x3bfea7fc,0xcffba981,
    0x21adffaa,0x3ee64ffa,0x23ffc2ff,0x7fd45ffa,0x2a06ffcc,0xffffffff,
    0x7c2ffc44,0x03ffc85f,0x077ffcc0,0x80efff98,0x7fd43ffc,0xf517fe47,
    0x7ffc00df,0x85ffd805,0xfa802ffe,0xe8dff36f,0x07ff67ff,0x3a13fe60,
    0x547fe67f,0x44ff90ff,0x7fffdc00,0x4fffffff,0x3f613fea,0x33bfe65f,
    0x547ffdcc,0x3fff8cff,0x9ddfff50,0xddff7017,0xddfffddd,0x800fff21,
    0x8805fffa,0x7dc1effe,0xfffb89ef,0xd1fffe67,0x53333dff,0xbefffa87,
    0x3fe65dba,0x6ffebbff,0x74c26b62,0x9fff14ff,0x6cffffd5,0xff9801ff,
    0x3e67fe84,0x321ff51f,0x7754007f,0xeffeeeff,0x213fea3e,0x3ff25ffb,
    0xffffffff,0x7d53fea2,0x4ffa81ff,0xfffff700,0x3fffffff,0x6400fff2,
    0x22004fff,0x3e22fffd,0xfeffffff,0x31fffe67,0xffffffff,0xfffffb0d,
    0xfffc8bff,0x221effff,0xffffffff,0x3ffff60f,0x3f67fdff,0x4ff9801f,
    0x3fe67fe8,0x3f21ff51,0x4ff50007,0xffa80ff9,0x3a3ffe84,0xeeeeeeff,
    0x93fea4ff,0xffa86ffd,0xdddd5004,0xddfffddd,0x200fff21,0x0002fffa,
    0x7541fff9,0x7fb9dfff,0x6c41ffec,0x04ffffff,0x7dffffd5,0x9ffffd50,
    0xffffe881,0x7ec40cff,0x27fb8eff,0xf9801ffd,0x267fe84f,0x21ff51ff,
    0xf70007fc,0x5407fccd,0xffcaadff,0x0bff11ff,0xffa9bfea,0x513ffe24,
    0x100009ff,0xbff90bff,0x41999999,0x5c0001fb,0x0013101f,0x26620026,
    0x00262000,0x26200262,0x09880199,0x00000000,0x32000000,0x541fea5f,
    0xffffffff,0x80ffee2f,0x9ff51fff,0x2a1fffb8,0x880004ff,0xfffc85ff,
    0x40ffffff,0x00100000,0x00000000,0x00000000,0x00000000,0x00000000,
    0x0df727ec,0x3bffffea,0x07fec0be,0x3ea7ffb0,0x26ffe84f,0x80004ffa,
    0xffc85ff8,0x0fffffff,0x00000000,0x00000000,0x00000000,0x00000000,
    0x00000000,0x00000000,0x00000000,0x00000000,0x5300cc98,0x85554035,
    0x1aa802aa,0x2aaaaaaa,0x155512aa,0x44055510,0x3ff20019,0x33333101,
    0x51033333,0x0ccc0037,0x4cccc333,0x00055100,0x00000000,0x00000000,
    0x00000000,0xfa80ffdc,0x43ffe06f,0x7fc407fd,0x3fffffe3,0x3ff66fff,
    0x203ffd86,0xf9800ffa,0xfff506ff,0x1fffffff,0x22ffffcc,0xdff10cc9,
    0xfd89bfe2,0x7ffc40ef,0x00000004,0x00000000,0x00000000,0x3ff70000,
    0x540fffc0,0x03ff25ff,0x3fe2ff98,0x6fffffff,0xfb93ffa2,0xff31986f,
    0xff9fb014,0xfffff505,0x741fffff,0x70efffff,0x8b7fc4ff,0xeffb86ff,
    0x03fffee0,0x00000000,0x00000000,0x00000000,0x807fee00,0xffd84ffc,
    0xa807fee2,0x266661ff,0x4c1fffc9,0xfff89fff,0xef8bfd80,0xffa83fd8,
    0x4c40ffb8,0x99999999,0x3633fe61,0x46ffceff,0x417fe5ff,0x3fea5fe9,
    0x000000ff,0x00000000,0x00000000,0xfb800000,0x1ffe201f,0xffa8fff1,
    0x3ee3ff52,0x3ffe200f,0xfddff903,0xdffd107f,0xd0bffdff,0x0027f47f,
    0xf907fd40,0xff85ffff,0x20017fe5,0x00003ffd,0x00000000,0x00000000,
    0xdd000000,0xdddffddd,0x22ffd89d,0x7fcc4ffb,0x3f29ffb3,0x13ffa207,
    0x0bffffd0,0xcffffd98,0x7d46fc81,0x2aaaa21f,0x222aaaaa,0x2efeb819,
    0x13fe4ff8,0x00004c00,0x00000000,0x00000000,0xf0000000,0xffffffff,
    0x5ffa8dff,0x3fe03ffa,0x3f2dfff5,0x01bff606,0x003fffe2,0x19ffffb3,
    0xfe82ff88,0x3ffffea6,0x000fffff,0x76c7db00,0x00000003,0x00000000,
    0x00000000,0x90000000,0x9bffd999,0x1fff0799,0x3fe0dff3,0xd9ffffae,
    0x1fff705f,0x5ffff700,0x3fbff620,0x3ae4ffff,0x2a5dd305,0xffffffff,
    0x000000ff,0x00000000,0x00000000,0x00000000,0x00000000,0x32007fee,
    0x02ffcbff,0xfd9f9dfb,0xff307ff9,0xfff3005f,0x3fa01fff,0x4fd8ef8c,
    0x00000000,0x00000000,0x00000000,0x00000000,0x00000000,0x3ff70000,
    0xfddff300,0x7fffe40f,0x42ffffca,0x8804fff8,0x6ffdaffe,0xb9fe6330,
    0x2aaaaaa0,0x1aaaaaaa,0x9ffffffd,0x00000000,0x00000000,0x00000000,
    0x00000000,0xf7000000,0x3ff6003f,0x3fee04ff,0x3ffff37f,0xcccfffd8,
    0xaffec4cc,0x5404fff8,0x3fffe07f,0xffffffff,0xfffffd5f,0x0000009f,
    0x00000000,0x00000000,0x00000000,0x00000000,0x2a003ff7,0x2a01ffff,
    0x3ffe4fff,0x3fffe20f,0x2e7fffff,0x3fea0fff,0x8066201f,0xffffffff,
    0x995fffff,0x00799999,0x00000000,0x00000000,0x00000000,0x00000000,
    0x15530000,0x037ffc00,0xfc8bffe6,0x7fffc47f,0xf37fffff,0xfff905ff,
    0x00000001,0x00000000,0x00000000,0x00000000,0x00000000,0x00000000,
    0x00000000,0x00000000,0x00000000,0x00000000,0x00000000,
};

static signed short stb__consolas_bold_25_usascii_x[95]={ 0,4,2,0,1,0,0,5,3,2,1,0,2,3,
4,0,0,1,1,1,0,1,1,1,1,0,4,2,1,1,2,3,0,0,1,1,1,2,2,0,1,1,2,1,
2,0,1,0,1,0,1,1,0,1,0,0,0,0,1,3,1,3,1,0,0,1,1,1,0,1,0,0,1,1,
1,1,1,0,1,0,1,0,2,1,0,1,0,0,0,0,1,1,5,2,0, };
static signed short stb__consolas_bold_25_usascii_y[95]={ 18,0,0,2,-1,0,0,0,-1,-1,0,5,13,10,
13,0,1,1,1,1,2,2,2,2,1,1,5,5,4,7,4,0,0,2,2,1,2,2,2,1,2,2,2,2,
2,2,2,1,2,1,2,1,2,2,2,2,2,2,2,0,0,0,2,20,0,5,0,5,0,5,0,5,0,0,
0,0,0,5,5,5,5,5,5,5,1,5,5,5,5,5,5,0,-2,0,8, };
static unsigned short stb__consolas_bold_25_usascii_w[95]={ 0,5,9,14,12,14,15,4,9,9,12,13,8,8,
6,13,14,12,12,12,14,12,12,12,12,13,6,8,11,12,11,9,14,14,12,12,13,10,10,13,12,11,10,13,
11,14,12,14,12,14,13,12,13,12,14,14,14,14,12,8,12,7,12,14,9,12,12,11,13,12,13,13,12,12,
11,13,12,14,12,13,12,13,11,11,12,12,14,14,14,14,11,11,4,10,14, };
static unsigned short stb__consolas_bold_25_usascii_h[95]={ 0,19,7,16,23,19,19,7,25,25,12,13,10,3,
6,21,18,17,17,18,16,17,17,16,18,17,14,18,15,8,15,19,24,16,16,18,16,16,16,18,16,16,17,16,
16,16,16,18,16,22,16,18,16,17,16,16,16,16,16,23,21,23,8,4,6,14,19,14,19,14,18,19,18,18,
24,18,18,13,13,14,18,18,13,14,18,14,13,13,13,19,13,23,26,23,7, };
static unsigned short stb__consolas_bold_25_usascii_s[95]={ 251,245,223,1,64,230,200,251,6,16,169,
98,246,197,243,134,136,213,226,186,71,1,14,137,173,239,135,164,110,195,98,
148,38,29,16,123,240,229,218,199,192,180,40,44,86,122,109,108,58,106,65,
151,51,27,150,94,79,165,205,97,121,89,182,182,233,122,172,155,158,142,54,
216,27,14,26,40,68,231,218,167,95,81,206,181,1,193,112,127,154,185,142,
77,1,53,208, };
static unsigned short stb__consolas_bold_25_usascii_t[95]={ 9,1,81,65,1,1,1,1,1,1,81,
81,65,90,81,1,28,28,28,28,65,47,47,47,28,28,65,28,65,81,65,
1,1,65,65,28,47,47,47,28,47,47,47,65,65,47,47,28,65,1,47,
28,47,47,47,47,47,47,47,1,1,1,81,90,81,65,1,65,1,65,28,
1,28,28,1,28,28,65,65,65,28,28,65,65,28,65,81,81,81,1,81,
1,1,1,81, };
static unsigned short stb__consolas_bold_25_usascii_a[95]={ 220,220,220,220,220,220,220,220,
220,220,220,220,220,220,220,220,220,220,220,220,220,220,220,220,
220,220,220,220,220,220,220,220,220,220,220,220,220,220,220,220,
220,220,220,220,220,220,220,220,220,220,220,220,220,220,220,220,
220,220,220,220,220,220,220,220,220,220,220,220,220,220,220,220,
220,220,220,220,220,220,220,220,220,220,220,220,220,220,220,220,
220,220,220,220,220,220,220, };

// Call this function with
//    font: NULL or array length
//    data: NULL or specified size
//    height: STB_FONT_consolas_bold_25_usascii_BITMAP_HEIGHT or STB_FONT_consolas_bold_25_usascii_BITMAP_HEIGHT_POW2
//    return value: spacing between lines
static void stb_font_consolas_bold_25_usascii(stb_fontchar font[STB_FONT_consolas_bold_25_usascii_NUM_CHARS],
                unsigned char data[STB_FONT_consolas_bold_25_usascii_BITMAP_HEIGHT][STB_FONT_consolas_bold_25_usascii_BITMAP_WIDTH],
                int height)
{
    int i,j;
    if (data != 0) {
        unsigned int *bits = stb__consolas_bold_25_usascii_pixels;
        unsigned int bitpack = *bits++, numbits = 32;
        for (i=0; i < STB_FONT_consolas_bold_25_usascii_BITMAP_WIDTH*height; ++i)
            data[0][i] = 0;  // zero entire bitmap
        for (j=1; j < STB_FONT_consolas_bold_25_usascii_BITMAP_HEIGHT-1; ++j) {
            for (i=1; i < STB_FONT_consolas_bold_25_usascii_BITMAP_WIDTH-1; ++i) {
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
        float recip_width = 1.0f / STB_FONT_consolas_bold_25_usascii_BITMAP_WIDTH;
        float recip_height = 1.0f / height;
        for (i=0; i < STB_FONT_consolas_bold_25_usascii_NUM_CHARS; ++i) {
            // pad characters so they bilerp from empty space around each character
            font[i].s0 = (stb__consolas_bold_25_usascii_s[i]) * recip_width;
            font[i].t0 = (stb__consolas_bold_25_usascii_t[i]) * recip_height;
            font[i].s1 = (stb__consolas_bold_25_usascii_s[i] + stb__consolas_bold_25_usascii_w[i]) * recip_width;
            font[i].t1 = (stb__consolas_bold_25_usascii_t[i] + stb__consolas_bold_25_usascii_h[i]) * recip_height;
            font[i].x0 = stb__consolas_bold_25_usascii_x[i];
            font[i].y0 = stb__consolas_bold_25_usascii_y[i];
            font[i].x1 = stb__consolas_bold_25_usascii_x[i] + stb__consolas_bold_25_usascii_w[i];
            font[i].y1 = stb__consolas_bold_25_usascii_y[i] + stb__consolas_bold_25_usascii_h[i];
            font[i].advance_int = (stb__consolas_bold_25_usascii_a[i]+8)>>4;
            font[i].s0f = (stb__consolas_bold_25_usascii_s[i] - 0.5f) * recip_width;
            font[i].t0f = (stb__consolas_bold_25_usascii_t[i] - 0.5f) * recip_height;
            font[i].s1f = (stb__consolas_bold_25_usascii_s[i] + stb__consolas_bold_25_usascii_w[i] + 0.5f) * recip_width;
            font[i].t1f = (stb__consolas_bold_25_usascii_t[i] + stb__consolas_bold_25_usascii_h[i] + 0.5f) * recip_height;
            font[i].x0f = stb__consolas_bold_25_usascii_x[i] - 0.5f;
            font[i].y0f = stb__consolas_bold_25_usascii_y[i] - 0.5f;
            font[i].x1f = stb__consolas_bold_25_usascii_x[i] + stb__consolas_bold_25_usascii_w[i] + 0.5f;
            font[i].y1f = stb__consolas_bold_25_usascii_y[i] + stb__consolas_bold_25_usascii_h[i] + 0.5f;
            font[i].advance = stb__consolas_bold_25_usascii_a[i]/16.0f;
        }
    }
}

#ifndef STB_SOMEFONT_CREATE
#define STB_SOMEFONT_CREATE              stb_font_consolas_bold_25_usascii
#define STB_SOMEFONT_BITMAP_WIDTH        STB_FONT_consolas_bold_25_usascii_BITMAP_WIDTH
#define STB_SOMEFONT_BITMAP_HEIGHT       STB_FONT_consolas_bold_25_usascii_BITMAP_HEIGHT
#define STB_SOMEFONT_BITMAP_HEIGHT_POW2  STB_FONT_consolas_bold_25_usascii_BITMAP_HEIGHT_POW2
#define STB_SOMEFONT_FIRST_CHAR          STB_FONT_consolas_bold_25_usascii_FIRST_CHAR
#define STB_SOMEFONT_NUM_CHARS           STB_FONT_consolas_bold_25_usascii_NUM_CHARS
#define STB_SOMEFONT_LINE_SPACING        STB_FONT_consolas_bold_25_usascii_LINE_SPACING
#endif
