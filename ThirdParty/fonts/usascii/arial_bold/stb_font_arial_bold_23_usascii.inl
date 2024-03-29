// Font generated by stb_font_inl_generator.c (4/1 bpp)
//
// Following instructions show how to use the only included font, whatever it is, in
// a generic way so you can replace it with any other font by changing the include.
// To use multiple fonts, replace STB_SOMEFONT_* below with STB_FONT_arial_bold_23_usascii_*,
// and separately install each font. Note that the CREATE function call has a
// totally different name; it's just 'stb_font_arial_bold_23_usascii'.
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

#define STB_FONT_arial_bold_23_usascii_BITMAP_WIDTH         256
#define STB_FONT_arial_bold_23_usascii_BITMAP_HEIGHT         78
#define STB_FONT_arial_bold_23_usascii_BITMAP_HEIGHT_POW2   128

#define STB_FONT_arial_bold_23_usascii_FIRST_CHAR            32
#define STB_FONT_arial_bold_23_usascii_NUM_CHARS             95

#define STB_FONT_arial_bold_23_usascii_LINE_SPACING          15

static unsigned int stb__arial_bold_23_usascii_pixels[]={
    0x7df70df1,0xeb81fe60,0xeb87f83f,0x3dddd71e,0x00bbbbaa,0x2f3bb6e6,
    0x017c4001,0xcdfedc88,0x90199500,0xb5004099,0x2199339d,0x3bdb54ca,
    0xdeedb880,0xd951000c,0x3fa05bdf,0xefdc8800,0x84fb803d,0x40ff67f9,
    0x2002cdc9,0x85fb4ee8,0xf984fffb,0x87fff907,0x1ffc84fb,0x2e5ffff9,
    0x9103ffff,0xffffffff,0xfb3001df,0xfffa807d,0xa83fffff,0x2ffcc3ff,
    0xffc81f54,0x91ffcfff,0xfffff9ff,0x3fffee05,0x4403ffff,0xfffffffe,
    0x2017e40e,0xfffffffa,0x20bf600e,0x20bfe5fb,0x04fffffa,0x3eabff10,
    0x43ffdcc6,0x7dff07f9,0x5c0ffc43,0xff9531ee,0x06affee5,0x82f7bfa6,
    0x200efd98,0x0ffffffd,0xccefffb8,0x7c43fffe,0x217fdc6f,0xffa83ffa,
    0x1fffebcf,0xfb7dfff9,0xfffb81ff,0x3fffecce,0x9bdffd10,0xfb8bfffd,
    0x3fffea04,0x205fffed,0x14fc80ff,0xfff881ff,0x8802ffec,0x05ff15ff,
    0x0ff30ff9,0xdf907ff1,0x25ff3000,0xff100ffb,0x03be600b,0x3fbf3fe6,
    0x1fffc44f,0x3207ffdc,0x21ffa1ff,0xffd83ffa,0xfc8fffc2,0x11ffe45f,
    0xff707fff,0x09ffd01f,0x7cc3fff5,0x82fffa06,0xf981fff9,0x3ea5fd06,
    0xf12ffb86,0xbff100bf,0x7fdc37ec,0x7c43fcc0,0x503ff82f,0x2ff98199,
    0x3f601ff7,0x26b76e66,0xc84fa9cc,0x4ecaf8df,0xf902ffe4,0x13ff989f,
    0xffda89ff,0x03ffe1cd,0x3ff23ffb,0xf727fd43,0x27fe40bf,0xdc817fe6,
    0x5c07fc1b,0x39d704ff,0x7ff49f70,0xffffffff,0xffb1ffa1,0x25ff8801,
    0x7fdc0ffa,0x7cc3fcc0,0x80ffc42f,0x7fcc1ffc,0xf301ff72,0x3fffe61d,
    0x0db0ffef,0x405f1bfb,0x3e201ffd,0xf76fe86f,0xffffd83f,0x2e1bfe2f,
    0x83ff91ff,0x3ff65ff8,0x71bfe201,0x360005ff,0x01ffd82f,0x7f45fb00,
    0xffffffff,0xf91bfa1f,0x5ff8803f,0xff507fe6,0xf987f983,0x807fd41f,
    0x7fcc1ffc,0xf701ff72,0x2233fe63,0x03f27ffd,0x405f9ff7,0x7fc00fff,
    0xfe9ffb87,0xcdffda86,0x3f61ffe1,0x987ff91f,0x03ffa5ff,0xffd8fff0,
    0x09f70000,0x20001ffd,0x3f2620ff,0x41aff99e,0x0ffe46ff,0xf897fe20,
    0x227fc43f,0x0ffc87f9,0xff903fdc,0xf72ff983,0x321fb01f,0x52ffcc6f,
    0xffff885f,0x00fff02d,0xff881fff,0xff503ffc,0xf83ffd07,0x8bff91ff,
    0x1ffe3ffb,0xff83ffe0,0x7fffe40f,0x7c37cc5f,0xff10007f,0x7fc53f20,
    0x2e37fc40,0x7fc402ff,0x7ec27fc5,0x4cff31df,0x6fd85ffd,0xf307ff20,
    0x203fee5f,0xf10bfa6f,0x4c17dc7f,0x41effffd,0x7ff807ff,0x01ffffb0,
    0x3ee0ffea,0xfffd99ef,0x519fff91,0x7ffc3ffd,0x3a3ffc00,0x7ffe40ff,
    0x40ff85ff,0xa8000ffe,0x2a5fd05f,0xb8dff06f,0x7fc402ff,0xfe82ffc5,
    0x7d4ff32f,0x40dfd06f,0x7fcc1ffc,0xf981ff72,0xf983ff34,0xa803f61f,
    0x7f46ffff,0x1bfe200f,0x502fffd4,0x3ffa07ff,0x91ffffff,0xffffffff,
    0x201ffe89,0x7fe46ff8,0x7fee6542,0x7ec2fd85,0x3203101f,0x77ff643f,
    0x20eeffee,0x0ffe46ff,0xff17fe20,0x23fff709,0x3ffea7f9,0x3206fd83,
    0x97fcc1ff,0x9fcc0ffb,0x0ffb87fb,0xbf880df1,0x3ff20ffd,0x7fdcba24,
    0x80bffe05,0xfb103ffa,0x23ff77ff,0xfffd9ffc,0x204ffd83,0x7fd45ffb,
    0x217fe605,0x27fe44fb,0x7f43efb8,0x7fffff41,0x3a1fffff,0xa87fe47f,
    0x13fe61ed,0x5ff887ff,0x3fa23fcc,0x3207fc87,0x97fcc1ff,0x55f80ffb,
    0x16ff83ff,0x115305fd,0x4c7ff15f,0xdff71fff,0x3e205fff,0x1ffd407f,
    0x1ffb8220,0x300c3ff9,0xff303fff,0x2fff883f,0xf30bff70,0x41fff98b,
    0x3e22fff8,0xaaefda87,0x360aabff,0xb9ffa1ff,0x93fee3ff,0x7fcc2ff8,
    0x7d43fcc2,0x903fdc1f,0x2ff983ff,0x4fd01ff7,0x3bff24ff,0xbff05fd9,
    0x83ff15f1,0xfbabfffc,0xf9105fff,0xcffa809f,0x3ff70009,0xc8007ff2,
    0xfcaacfff,0xfff305ff,0xfffd757b,0x3f21fe0b,0xfffcbeff,0xfd82fd46,
    0x2601ff14,0x3ffb9dff,0x3af3ffe6,0x07fea2ff,0x7f981ff5,0x7cc2ff98,
    0x83ff900f,0x1ff72ff9,0x3ff25f90,0xffffffff,0x3f3ff204,0xfd886fdb,
    0xffffffff,0x3fffe21e,0x7ffcc00f,0x3ff7003f,0x88007ff2,0xfffffffd,
    0x3fea00df,0xdfffffff,0xfb03fd00,0x1fffffff,0x5fd03fc8,0xffb01bea,
    0xfd81ffff,0x5c4fffff,0x40ffb86f,0x2ff987f9,0xfc81ffc4,0xb97fcc1f,
    0x0efa80ff,0xdf717db3,0x3e204c59,0x02ffffff,0x37ffffaa,0x3fe3fffd,
    0xff9002ff,0x3fee007f,0x0003ff91,0x5dffffd5,0x3ff6e600,0x7e401def,
    0xffffd503,0x103fd019,0x013f21ff,0x203bfff2,0x84efffc8,0x87fb83fe,
    0x3ff887f9,0xff905fc8,0xf72ff981,0x07bf601f,0x882fe980,0x000cfffc,
    0x41ff5022,0x188001a9,0x00000000,0x0c0000c4,0x20026200,0x300cc009,
    0x30004c43,0x44026001,0x3ff4c47f,0x7fc43fcc,0x263fc41d,0xff987fea,
    0x2201ff72,0x2200affe,0x7c402ffb,0x00c00002,0x00000000,0x00000000,
    0x00000000,0x00000000,0x21fdc000,0xf985fffb,0x87fffd07,0x3fff22fc,
    0x4bffff26,0x903ffffb,0xb99bffff,0x1005ffff,0x0000005f,0x00000000,
    0x00000000,0x00000000,0x00000000,0x81fd0000,0xf981effb,0x87ffd307,
    0x3fffa6f8,0x4bffff21,0x203ffffb,0xfffffec9,0x00000bef,0x00000000,
    0x00000000,0x00000000,0x00000000,0x00000000,0x0ccc0d44,0x99805510,
    0x06622a81,0x44266662,0x10009999,0x00013333,0x00000000,0x00000000,
    0x00000000,0x00000000,0x00000000,0x00000000,0x00000000,0x00000000,
    0x00000000,0x00000000,0x00000000,0x00000000,0x00000000,0x2cdca800,
    0x4ce76dc0,0xceca80cc,0x1eeb8003,0xb81cdca8,0x326000ee,0x40cccccc,
    0xf980beda,0x7bd93006,0x16e5c001,0xec817754,0xefec980e,0x41eea83d,
    0x361efec8,0xeeeeeeee,0x003bae5e,0x3ba03bb6,0x21eeb83e,0x3ae01eed,
    0x80fbb23e,0x7fe42eed,0xffb05fff,0x83ff9fff,0x06fffffd,0x360ffe40,
    0x643fffff,0x3ee000ff,0x20ffffff,0xd84fdefa,0xfffb802f,0x74400fff,
    0x2e1fffff,0x3ffb03ff,0xffffffb8,0x07fee0ef,0x743ffffb,0xffffffff,
    0x007ff26f,0xff30bff2,0x41ffd0df,0x3fa04ffc,0x07ffe61f,0xff51bfea,
    0xa83ffd9d,0xffebbfff,0x2fbfe21f,0x32002ffd,0x3bff21ff,0x3f22fffd,
    0x3ff2000f,0x360fffff,0x7cc7f8af,0x31dfd006,0xffe807fd,0x3ee5ffde,
    0x43ffb03f,0xfdcdfff9,0x07baa5ff,0xed833dff,0xfffeeeee,0x2007ff26,
    0x7fe44ffa,0x1bfe20ff,0x3e20fff3,0x85ffc86f,0x3ff42ffe,0xffe8bff1,
    0xc87ffe21,0x01bfa0ff,0x3fe1ffc8,0xfc97fe66,0x3bfa000f,0x7fc19999,
    0x17ec3fd0,0xfb2ffc40,0x927fd40d,0x0ffee1ff,0xff70ffec,0x00fff985,
    0x20027fc4,0x3f20fffc,0x6ff8801f,0x317ffff4,0x5ffd09ff,0xf109ff70,
    0x2ffe45ff,0xbff10d44,0xffe87ff8,0xdfb1ff21,0x3273b6e0,0x89ff31ff,
    0x1ff90fff,0x3e03bdb5,0xf1ff804f,0x801be63f,0x4ffa9ffe,0x0883ff60,
    0xfd81ffdc,0x20bff21f,0x19950bcb,0x0f3bff6e,0x90bffee0,0x1665c3ff,
    0xdff89ffe,0x0bfee4ff,0x3fa13fee,0x2dff501f,0x8800fff8,0x3fe22ffc,
    0x2a1ffc86,0x4ffa8bff,0xefffffd8,0x87ff31ff,0xbff91ffd,0x985fffff,
    0x81cecdff,0x366f8afc,0x3fea002f,0x3a00dfff,0xf705717f,0x87ff607f,
    0x00bdfffa,0x7fec7fee,0x7cc05fff,0x1ffc83ff,0xfd81dff7,0xfd5ff51f,
    0x4407fecd,0x37fc47ff,0x3f73ff60,0xfffa803f,0xfe87fe83,0x7fffd41f,
    0xbfffa84f,0xf11fffeb,0x92fff8bf,0xffb5bfff,0x7fffd41f,0x7fd42fff,
    0x00df34ff,0x05ffff88,0xfffceff8,0x40ffee0e,0x7fec1ffd,0x5c0befff,
    0xdffb71ff,0x7ffc4079,0xf53ff905,0x7ff701df,0x3ff23ff2,0x7ec0dff0,
    0x00ffee2f,0x0dfffff1,0x20fffee0,0x3fe21ffc,0x7fffcc1f,0x21ffe84f,
    0x3fa1fff8,0x3fffc8bf,0xffc8bff9,0x36ffff23,0x65c40fff,0x4010bf61,
    0x05ffffe9,0x6effffc4,0x0ffee6ff,0x3220ffec,0x1fffffff,0xff887fee,
    0x06ffe804,0x3bfefff2,0x3a9ff300,0xf15ff56f,0x2ffd40bf,0xf7001ffd,
    0x22003fff,0x7d46ffb9,0xffffbbff,0x32b7fea1,0x43ffc5ff,0x3fe61ffe,
    0x92ffffff,0x4ffa85ff,0x9ff90aa2,0x322df300,0x7fcc0cff,0xf9bfffbf,
    0x91fffc1d,0x0ffee5ff,0xa880ffec,0x70fffffd,0x27fc43ff,0x803fff20,
    0x03fffffc,0x9ffc77fc,0x3ffacff8,0x7c5ffe20,0x3ffa005f,0x3ff90004,
    0xdfffffd8,0x91ffa1ff,0x17fe21ff,0xfb107ff2,0x323ff73b,0x2ffc41ff,
    0x402ffcc0,0xf9bf72fd,0xf32ffc8b,0xf81ffdff,0x53fe61ff,0xffb03ffa,
    0x3ffa6003,0x7c43ff72,0x3ffee04f,0x7fffe401,0x3ff600ff,0x3bfa1ffb,
    0x7ec01ffc,0x002ffbaf,0x2200bff2,0x5c1ffd40,0x0ffc8dfe,0xffa8bff1,
    0x3f61ffe3,0x0ffc801f,0xffa85ff9,0x05ff8804,0x13fd37cc,0x5c6fe8ff,
    0xfe85ffff,0x553fe20f,0x1ffd04ff,0x7d41bfa2,0x443ff74f,0xfff304ff,
    0x7fff9007,0x7fdc09ff,0x77fdc7ff,0xdffa807f,0x32000ffd,0x3fe202ff,
    0x1117fec6,0xff83ff20,0xfd17fe47,0x21fff81f,0x937fc3ca,0x3ffc89ff,
    0x5ff71ff6,0xff12fd80,0xffe87fe1,0x417ffec0,0x3fea3ffc,0x981fff33,
    0x17ff47ff,0xffb9ffe4,0x2213fe21,0xf9004fff,0x407ff65f,0x4c5ffff9,
    0xf005ffff,0x800bffff,0x7dc02ffc,0x0fffb9cf,0xfe893ff2,0x5467ff47,
    0x3fee0ffe,0x1fffd9ae,0x3f66bff2,0x33fff23f,0x2a0fffa8,0x7fea8cff,
    0x3fe37cc0,0x7fdc1ff0,0xffffb89d,0x577fc43f,0x3fa1ffe9,0xfffcabef,
    0x56fffdc4,0xf71fffdb,0x427fc43f,0xaaabfffd,0xff90aaaa,0xf817fe63,
    0xfff83fff,0xfff9003f,0xffc8005f,0xfffff802,0x7ffc42ff,0x443fffef,
    0x3fffffff,0x7fffff44,0x3fe21ffe,0x7e46ffff,0x4fffffef,0xffffffe8,
    0x3217ec03,0x7c46fabf,0xefffffff,0x7fe41fff,0x7d44ffff,0xffffffff,
    0xfffffe80,0x3fee3fff,0x3613fe21,0xffffffff,0x3ff90fff,0xfe817fe4,
    0xfffd81ff,0xffff3001,0x05ff9000,0x3dffd710,0x3ffffea0,0xffd7303f,
    0x3ff6207f,0x541ffabf,0xfc84fffd,0x207fffb7,0x02effeb8,0x7fcc37cc,
    0xffd882ff,0x07f71eff,0x40ffffee,0xcfffffd9,0x3fffee00,0x0ffdc2ef,
    0xffb09ff1,0xffffffff,0x887ff21f,0xfff906ff,0x001ffee0,0x90009fff,
    0x088005ff,0x00333300,0x00880044,0x0c000440,0x2a001100,0x002ea01c,
    0x44004062,0x00262000,0x00001310,0x00000000,0x00000000,0x00000000,
    0x00000000,0x00000000,0x00000000,0x00000000,0xdd500000,0x7ddddddd,
    0x3bbbbbaa,0xdd52eeee,0x20799ddd,0xceeeeeea,0xeeea80ac,0x002cceee,
    0x9900bdd3,0x775cf327,0xeeeeeeee,0x01ddd30e,0x7754bdd5,0x51eea801,
    0x99bddddd,0x50eea801,0x3baa07dd,0x20bddd50,0x9934eeed,0x05dd5005,
    0x74437bb2,0x2a3dd75e,0x3dd902ee,0x817bb510,0xfffffffb,0xffff74ff,
    0x25ffffff,0xfffffffb,0x7ffdc2ff,0x1fffffff,0x7fffffdc,0x6c00efff,
    0x7fc02fff,0x3ff2dff5,0xffffffff,0x217ff60f,0x3fee3ffe,0x71ffb801,
    0xffffffff,0x3ffe605f,0x703fff70,0x3ffee3ff,0x7fffc41f,0x7009ff55,
    0xfff907ff,0xfcb7fc45,0x207ff72f,0x7fec1ffd,0x3ee0ffff,0xeeeeeeef,
    0xddddff73,0x3ee5dddd,0xfffeeeef,0x3bbfee1f,0x47fffeee,0xeeeeeffb,
    0x3e205fff,0x7fc05fff,0x3baedff5,0xeeefffee,0x8bffe20e,0x7fdc6ffc,
    0x71ffb801,0xffddddff,0xffe881ff,0x0bfff70f,0x3fee3ff7,0x7ffd43ff,
    0x009ff55f,0xffb87ff7,0xcb7fc42f,0x07ff72ff,0xffb87ff6,0x2e4ffecf,
    0xffb803ff,0x87ff7003,0x3ee6ffc8,0x1ffe883f,0x3e20ffee,0x3ffee07f,
    0x426600ff,0xbff10099,0x22dff700,0x7fdc1fff,0x71ffb801,0xffe887ff,
    0x3fffff22,0x85ffff70,0xfff71ffb,0xffffc8bf,0x7009ff55,0x7ffdc7ff,
    0xf96ff882,0x40ffee5f,0x3ffa1ffd,0x7dc3ff60,0x3ffb803f,0x207ff700,
    0x7ff72ffe,0xfb8fff20,0x40ffd03f,0x04ffbffe,0x17fe2000,0x7ee7fec0,
    0x99ffb83f,0x7fdc2ded,0xf507ff71,0x3bbfeabf,0xffff70ff,0xb8ffdc1f,
    0x7f47fdff,0x9ff55ffd,0x2a7ff700,0x3fe03fff,0x3ee5ff96,0x43ffb03f,
    0x97fdc4dc,0xfb803ffb,0x7ff7003f,0x7dcffee0,0x41ffb03f,0xffa83ffb,
    0xf19ff304,0x440000ff,0xff1005ff,0x3ee0dfff,0x3fffffdf,0x7fdc7fee,
    0xf54ffb83,0x7dc3ff65,0x3ee4ffef,0xff7ff71f,0x3feffe23,0x7009ff55,
    0x7fff37ff,0xff95ff80,0x6c0ffee5,0xffd801ff,0xddddff70,0x7ffdc7dd,
    0x26ffffff,0xff503ffb,0x3337fee9,0x5c6ffecc,0xffeeeeff,0x3ff900df,
    0x0000bff6,0x7002ffc4,0x2e03ffff,0xffbacfff,0x7dc7fee7,0xfff5313f,
    0x21ffb025,0x1fffaffb,0x3fee3ff7,0x3ff53ff9,0x13feabff,0x3ff7fee0,
    0xa7f401ff,0xfff72ffc,0xffffffff,0x26ff9803,0xfffffffb,0x3fffee4f,
    0x2e6fffff,0xbff303ff,0x3fffffee,0x7dc0cfff,0xffffffff,0x4cdff104,
    0x100005ff,0x7c400bff,0x3fee06ff,0xfb87fec5,0xfffff71f,0x201dffff,
    0x3ff70ffd,0x3feedff5,0xdfb3ff71,0xaaffdbf2,0xffb804ff,0x406fffff,
    0x25ff94fd,0xfffffffb,0x2601ffff,0x3fee1fff,0x23eeeeee,0xccccdffb,
    0x0ffee3cc,0xffbaffd4,0x00ffffee,0x9999bff7,0xfb81dffd,0x407ffc3f,
    0x20bdb4ee,0x36005ff8,0xf702ffff,0x70ffd85f,0x3ffee3ff,0x00dfffff,
    0x7fdc3ff6,0xff77ffb1,0x3ee7fee3,0xbff4fe8f,0x2e013fea,0xffebffff,
    0x7e4ff204,0x99bff72f,0x03ffd999,0xf70fffe6,0x7ff7007f,0x40ffee00,
    0x7ff74ffb,0x5c077fec,0x7ff903ff,0xeeeeffe8,0x5ff84fff,0x3fe20dff,
    0xffff5005,0x5ff701ff,0xff70ffc8,0x2ab7fee3,0xffd8009a,0x3e63ff70,
    0xf71ffcff,0xff7ff33f,0x7fd57fe5,0x3fffb804,0x3203fff3,0x2e5ff92f,
    0x3ffb03ff,0x707fff30,0xff7007ff,0x0ffee007,0xffb9ffe4,0x5c2fff43,
    0xbff303ff,0x7fffffcc,0xff87ffff,0x3e20dff5,0xfff8805f,0xfb85ffdb,
    0xb87fe41f,0x07ff71ff,0x5c3ff600,0x3fff21ff,0x23ff71ff,0xff0fffff,
    0x2013feab,0x7fe44ffb,0x3f23f706,0x207ff72f,0x7fcc1ffd,0x07ff703f,
    0x2007ff70,0xff983ffb,0x887ff70f,0x7fdc3fff,0x649ff703,0xcccccdff,
    0x04e82ffe,0xb00bff10,0x3ffe2dff,0x320ffdc2,0x23ff70ff,0xb0003ffb,
    0x07fee1ff,0x2e3ffffd,0xdfffb1ff,0x4ffaaffc,0x443ffb80,0x21883fff,
    0x7ff72ffc,0xe887ff60,0x3fee03ff,0xadffb803,0x71aaaaaa,0xfb955bff,
    0x1ffdc5ff,0xf70fffdc,0xfb9755bf,0x07ffc5ff,0x7d45ffa8,0xf103dd52,
    0xfffa80bf,0xb83ffee1,0x87fe41ff,0x7ff71ffb,0x43ff6000,0x7fd41ffb,
    0x23ff71ff,0x3fe4fffb,0x555bff55,0x3fee5555,0x41fffb83,0x25ff94ee,
    0xffb03ffb,0x667ffe43,0x7ff71ccc,0xfffff700,0x2ebfffff,0xffffffff,
    0x81ffdc4f,0x3fee6ffd,0xffffffff,0xf017fea5,0xb8fe21ff,0x5ff881ff,
    0x20fffe20,0x3fee5ffe,0xfb87fe41,0x007ff71f,0x7dc3ff60,0x1fffd81f,
    0x3fe63ff7,0x7d57fe2f,0xffffffff,0x3a07ff77,0xcaffc6ff,0x07ff72ff,
    0xfff87ff6,0x72ffffff,0xff7007ff,0xffffffff,0x3ffffeeb,0xffb81def,
    0x27fff103,0xfffffffb,0x17fec2df,0x4093ff20,0xff881ffb,0x41bff205,
    0xff72fff9,0xf70ffc83,0x00ffee3f,0xfb87fec0,0x1fff881f,0x7ffc3ff7,
    0x7fd57fe0,0x7fffffff,0x3ea07ff7,0x657fe3ff,0x07ff72ff,0x7fd47ff6,
    0x2fffffff,0x00000000,0x00000000,0x00000000,0x00000000,0x00000000,
    0x00000000,0x00000000,0x00000000,0x00000000,0x00000000,0x00000000,
    0x32203baa,0x6440bded,0xcccccccc,0xca800722,0x2066540c,0x00bdeed9,
    0x059dd951,0x00def64c,0x0007bdb5,0x76dc4126,0x0aa8803d,0xcc989970,
    0x9951e5c1,0x970b7b26,0x4c33b6e7,0x33261ded,0x95166544,0x64433b29,
    0x2ccccccc,0x99701997,0x000bfe60,0xfb81fff1,0x21ffffff,0xfffffff8,
    0x0b7fe3ff,0xfb07ff20,0x7fffcc1f,0xffe80fff,0xfc83ffff,0xd83fffff,
    0x00efffff,0xf30ffb50,0x01dfffff,0xfb80ffcc,0x897ff20f,0x2ffee4ff,
    0x363fffff,0xeffffdef,0x21fffffb,0xfff33ffe,0x7feffe41,0x3ffffe67,
    0x7ff54fff,0xfb05ff88,0xffd800df,0x33ffe60f,0xf10fffca,0xffffffff,
    0x5f7fffc7,0xd83ff900,0x27bf60ff,0x7e45ffa9,0x46ffb9bf,0xfebcfff9,
    0x2b7fee0f,0x2e205ffc,0x7cc7fffe,0x6ffebdff,0x4c07fe60,0x9fffa3ff,
    0x3fee1ffa,0x27ffcacf,0xfeabfffd,0x5ffdadff,0x3fa3ffe6,0x77ffe42f,
    0x3333224d,0x3fe2fffd,0x4c17fdc6,0x7001ffff,0x7ec1ffff,0x01ffdc2f,
    0x3f2237f4,0x640cffff,0x07fec1ff,0x40cc3dff,0x23fec3a9,0x37a61ffd,
    0xff91ffe2,0xffffc883,0x1ffe41cf,0x7cc0bff6,0x457fa01f,0xffb1ffff,
    0x7f45ffb8,0x547ffb0f,0x237fc6ff,0x84fffffb,0xd1005ffc,0x1ffc87ff,
    0x77ec1bfa,0xff8805fe,0x132a0ffe,0xf7013fe6,0x7fed401f,0x07ff25ff,
    0x7ff41ffb,0xb9801cff,0x3fe0fffd,0x9dff8807,0x362ffb99,0x202dffff,
    0x7fd40ffe,0xffb99914,0x7e41999b,0x27fddf57,0x17fdc4ff,0x7fec3ff6,
    0xfd17fea1,0x0dfffb0f,0x2200bff2,0xff984ffe,0xf107ff34,0x803ff77f,
    0x00ffcdfe,0x4403ffb0,0xf91002ff,0x20ffe4ff,0x3fa20ffd,0xc82effff,
    0x0fffffff,0xf300dff1,0xffffffff,0x0067ffc7,0x3e21bfe2,0xfffff15f,
    0x4c1fffff,0xfccfc9ff,0x7dc2ff9d,0xd87fe42f,0x13fe60ff,0xfff30ffd,
    0x007ff207,0xfe817ff6,0xf901ff97,0x409ff11f,0x0ffc8ffb,0x405ffd80,
    0xfb3006fc,0x0ffe4fff,0x32a03ff6,0x7ec7fffe,0x0ffc8adf,0x3e201ffe,
    0xaaaaaadf,0x0b7fffe1,0xff50fff0,0x3ffffe2b,0x7c0fffff,0xffaafecf,
    0x1ffb87fc,0xffd87fe4,0xfd0ffe60,0x1ffffb0f,0xc803ff90,0x3ea00eff,
    0xf885ffaf,0x203ff24f,0x1ff92ff9,0x405ffd80,0x2e203ff8,0x20cffffe,
    0x7ff42ffb,0xfd886a60,0xd8bff12f,0x87ffa0ff,0x1bfa3ef8,0xffc88131,
    0xfd80bfff,0x81ffe41f,0x7e401ff9,0xfff88fff,0x41ffb85f,0x1ffb0ffc,
    0x3fa1ffcc,0x7ffffd47,0x200ffc85,0xf800effb,0xfc82ffef,0x213fe61f,
    0x03ff25fe,0xd805ffb8,0xfffb00ff,0xff5017df,0x1fff911b,0xfc83bfe2,
    0x54dff10f,0x3fee0fff,0x21ffd9ae,0xfe88bffc,0xffeb880f,0x77fdc5ff,
    0x00fffc9b,0xfa803ff3,0x3fffa6ff,0x641ffb82,0x41ffb0ff,0x3ff43ff9,
    0xffd1fff1,0x500ffc87,0x55559fff,0x0ffff905,0x5ffdc000,0x02bffdaa,
    0x3fe00dfd,0x0b7ffe04,0xffffff10,0x7fdc1ffd,0x6c4fffef,0xffffefff,
    0x7fffff41,0x7fffc45f,0xda803fff,0xfffc87ff,0x2602ffff,0xfff801ff,
    0x203fff24,0x7fe41ffb,0x7cc1ffb0,0xfd3ff43f,0x87ffe65f,0xff900ffc,
    0x0dffffff,0x0009fff3,0x7ffffe40,0xff07ffff,0x03ff3009,0xd3000e7c,
    0x1ff73dff,0x4ffffdb8,0x9cfffc88,0xfffc84ff,0xffd880bd,0x64c003df,
    0xbfffd707,0x01ee9803,0x3e62ffd8,0x83ff705f,0x1ffb0ffc,0x3fa1ffcc,
    0xfb8bff77,0x403ff26f,0xfffffffc,0x01ffd06f,0x7ffe4000,0x07ffffff,
    0xff700133,0x10000401,0x00130001,0x00220006,0x04000098,0x000000c0,
    0x00000000,0x00000000,0x00000000,0x03ff2000,0xfc804ee8,0x00000007,
    0x00000000,0x00000000,0x00000000,0x00000000,0x00000000,0x00000000,
    0x803ff200,0x5fe806ff,0x3bbbba20,0xf80eeeee,0xb90eeb85,0x6c7bb31b,
    0x1001105d,0x6eeccbff,0xbbbb10dd,0x5bbbbbbb,0x00000000,0x00000000,
    0x00000000,0x00000000,0x07fe4000,0xff00dff0,0x7fffc409,0x10ffffff,
    0xff9053a1,0x3e63ffa1,0xf51ffe5f,0x32217dff,0x7cc7fe61,0xff10ffff,
    0xffffffff,0x0000007f,0x00000000,0x00000000,0x00000000,0x00000000,
    0xdd100000,0xdddddddd,0x377b3ee1,0x3a1ff91f,0x25ff98ff,0x3ffe67ff,
    0x1ffeffff,0xfff9afcc,0x222220ff,0x00888888,0x00000000,0x00000000,
    0x00000000,0x00000000,0x00000000,0x32600000,0x2a1ceffe,0x3e2ffb0f,
    0xf99bfa4f,0xfffffdbe,0x8888800f,0x00000000,0x00000000,0x00000000,
    0x00000000,0x00000000,0x80000000,0xaaaaaaaa,0x1ffec0aa,0x26fb9762,
    0x997f62ff,0x00bdc982,0x00000000,0x00000000,0x00000000,0x00000000,
    0x00000000,0x00000000,0xffffff10,0x7ec1ffff,0x83b22fca,0x982ee2b9,
    0x0000001b,0x00000000,0x00000000,0x00000000,0x00000000,0x00000000,
    0x20000000,0xfffffff8,0x45660fff,0x0000020d,0x00000000,0x00000000,
    0x00000000,0x00000000,0x00000000,0x00000000,0x26600000,0x19999999,
    0x00000000,0x00000000,0x00000000,0x00000000,0x00000000,0x00000000,
    0x00000000,0x00000000,0x00000000,0x00000000,0x00000000,0x00000000,
    0x00000000,0x00000000,0x00000000,
};

static signed short stb__arial_bold_23_usascii_x[95]={ 0,1,1,0,0,0,0,0,1,0,0,0,1,0,
1,-1,0,1,0,0,0,0,0,0,0,0,2,1,0,0,0,1,0,0,1,0,1,1,1,0,1,1,0,1,
1,1,1,0,1,0,1,0,0,1,-1,0,0,-1,0,1,-1,0,1,-1,0,0,1,0,0,0,0,0,1,1,
-1,1,1,1,1,0,1,0,1,0,0,1,0,0,0,0,0,0,1,0,0, };
static signed short stb__arial_bold_23_usascii_y[95]={ 18,3,3,3,2,3,3,3,3,3,3,5,15,11,
15,3,3,3,3,3,3,3,3,3,3,3,7,7,5,7,5,3,3,3,3,3,3,3,3,3,3,3,3,3,
3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,20,3,7,3,7,3,7,3,7,3,3,
3,3,3,7,7,7,7,7,7,7,3,7,7,7,7,7,7,3,3,3,8, };
static unsigned short stb__arial_bold_23_usascii_w[95]={ 0,4,8,12,11,18,15,5,6,6,8,12,4,7,
4,7,11,8,11,11,11,11,11,11,11,11,3,4,12,12,12,11,21,15,13,14,13,12,11,15,13,4,10,14,
11,15,13,16,12,16,14,13,13,13,15,20,14,15,13,6,7,6,10,13,5,11,11,11,12,11,8,12,11,4,
6,11,4,16,11,12,11,12,8,11,7,11,12,17,12,12,10,8,4,8,12, };
static unsigned short stb__arial_bold_23_usascii_h[95]={ 0,15,6,16,19,16,16,6,20,20,8,11,7,4,
3,16,16,15,15,16,15,16,16,15,16,16,11,15,12,8,12,15,20,15,15,16,15,15,15,16,15,15,16,15,
15,15,15,16,15,17,15,16,15,16,15,15,15,15,15,20,16,20,9,3,4,12,16,12,16,12,15,16,15,15,
20,15,15,11,11,12,16,16,11,12,16,12,11,11,11,16,11,20,20,20,5, };
static unsigned short stb__arial_bold_23_usascii_s[95]={ 110,126,64,220,81,87,106,73,31,1,50,
136,59,98,251,212,233,60,150,1,1,75,122,25,26,51,251,246,110,37,37,
13,59,230,216,197,187,174,162,173,136,131,245,111,99,83,69,156,47,93,201,
148,1,134,223,202,15,239,176,52,189,45,242,106,92,74,63,86,38,98,167,
13,30,162,38,190,42,179,167,123,144,131,209,62,123,50,229,149,196,110,218,
22,17,8,79, };
static unsigned short stb__arial_bold_23_usascii_t[95]={ 18,39,68,1,1,22,22,68,1,1,68,
55,68,68,50,1,1,39,39,22,55,22,22,55,22,22,38,38,55,68,55,
55,1,38,38,1,38,38,38,1,39,39,1,39,39,39,39,1,39,1,38,
22,39,22,22,22,39,22,22,1,1,1,55,68,68,55,22,55,22,55,22,
22,39,22,1,22,39,55,55,55,1,1,55,55,1,55,55,55,55,1,55,
1,1,1,68, };
static unsigned short stb__arial_bold_23_usascii_a[95]={ 92,110,156,183,183,293,238,78,
110,110,128,192,92,110,92,92,183,183,183,183,183,183,183,183,
183,183,110,110,192,192,192,201,321,238,238,238,238,220,201,256,
238,92,183,238,201,274,238,256,220,256,238,220,201,238,220,311,
220,220,201,110,92,110,192,183,110,183,201,183,201,183,110,201,
201,92,92,183,92,293,201,201,201,201,128,183,110,201,183,256,
183,183,165,128,92,128,192, };

// Call this function with
//    font: NULL or array length
//    data: NULL or specified size
//    height: STB_FONT_arial_bold_23_usascii_BITMAP_HEIGHT or STB_FONT_arial_bold_23_usascii_BITMAP_HEIGHT_POW2
//    return value: spacing between lines
static void stb_font_arial_bold_23_usascii(stb_fontchar font[STB_FONT_arial_bold_23_usascii_NUM_CHARS],
                unsigned char data[STB_FONT_arial_bold_23_usascii_BITMAP_HEIGHT][STB_FONT_arial_bold_23_usascii_BITMAP_WIDTH],
                int height)
{
    int i,j;
    if (data != 0) {
        unsigned int *bits = stb__arial_bold_23_usascii_pixels;
        unsigned int bitpack = *bits++, numbits = 32;
        for (i=0; i < STB_FONT_arial_bold_23_usascii_BITMAP_WIDTH*height; ++i)
            data[0][i] = 0;  // zero entire bitmap
        for (j=1; j < STB_FONT_arial_bold_23_usascii_BITMAP_HEIGHT-1; ++j) {
            for (i=1; i < STB_FONT_arial_bold_23_usascii_BITMAP_WIDTH-1; ++i) {
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
        float recip_width = 1.0f / STB_FONT_arial_bold_23_usascii_BITMAP_WIDTH;
        float recip_height = 1.0f / height;
        for (i=0; i < STB_FONT_arial_bold_23_usascii_NUM_CHARS; ++i) {
            // pad characters so they bilerp from empty space around each character
            font[i].s0 = (stb__arial_bold_23_usascii_s[i]) * recip_width;
            font[i].t0 = (stb__arial_bold_23_usascii_t[i]) * recip_height;
            font[i].s1 = (stb__arial_bold_23_usascii_s[i] + stb__arial_bold_23_usascii_w[i]) * recip_width;
            font[i].t1 = (stb__arial_bold_23_usascii_t[i] + stb__arial_bold_23_usascii_h[i]) * recip_height;
            font[i].x0 = stb__arial_bold_23_usascii_x[i];
            font[i].y0 = stb__arial_bold_23_usascii_y[i];
            font[i].x1 = stb__arial_bold_23_usascii_x[i] + stb__arial_bold_23_usascii_w[i];
            font[i].y1 = stb__arial_bold_23_usascii_y[i] + stb__arial_bold_23_usascii_h[i];
            font[i].advance_int = (stb__arial_bold_23_usascii_a[i]+8)>>4;
            font[i].s0f = (stb__arial_bold_23_usascii_s[i] - 0.5f) * recip_width;
            font[i].t0f = (stb__arial_bold_23_usascii_t[i] - 0.5f) * recip_height;
            font[i].s1f = (stb__arial_bold_23_usascii_s[i] + stb__arial_bold_23_usascii_w[i] + 0.5f) * recip_width;
            font[i].t1f = (stb__arial_bold_23_usascii_t[i] + stb__arial_bold_23_usascii_h[i] + 0.5f) * recip_height;
            font[i].x0f = stb__arial_bold_23_usascii_x[i] - 0.5f;
            font[i].y0f = stb__arial_bold_23_usascii_y[i] - 0.5f;
            font[i].x1f = stb__arial_bold_23_usascii_x[i] + stb__arial_bold_23_usascii_w[i] + 0.5f;
            font[i].y1f = stb__arial_bold_23_usascii_y[i] + stb__arial_bold_23_usascii_h[i] + 0.5f;
            font[i].advance = stb__arial_bold_23_usascii_a[i]/16.0f;
        }
    }
}

#ifndef STB_SOMEFONT_CREATE
#define STB_SOMEFONT_CREATE              stb_font_arial_bold_23_usascii
#define STB_SOMEFONT_BITMAP_WIDTH        STB_FONT_arial_bold_23_usascii_BITMAP_WIDTH
#define STB_SOMEFONT_BITMAP_HEIGHT       STB_FONT_arial_bold_23_usascii_BITMAP_HEIGHT
#define STB_SOMEFONT_BITMAP_HEIGHT_POW2  STB_FONT_arial_bold_23_usascii_BITMAP_HEIGHT_POW2
#define STB_SOMEFONT_FIRST_CHAR          STB_FONT_arial_bold_23_usascii_FIRST_CHAR
#define STB_SOMEFONT_NUM_CHARS           STB_FONT_arial_bold_23_usascii_NUM_CHARS
#define STB_SOMEFONT_LINE_SPACING        STB_FONT_arial_bold_23_usascii_LINE_SPACING
#endif

