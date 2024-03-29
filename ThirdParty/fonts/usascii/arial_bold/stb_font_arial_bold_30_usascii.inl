// Font generated by stb_font_inl_generator.c (4/1 bpp)
//
// Following instructions show how to use the only included font, whatever it is, in
// a generic way so you can replace it with any other font by changing the include.
// To use multiple fonts, replace STB_SOMEFONT_* below with STB_FONT_arial_bold_30_usascii_*,
// and separately install each font. Note that the CREATE function call has a
// totally different name; it's just 'stb_font_arial_bold_30_usascii'.
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

#define STB_FONT_arial_bold_30_usascii_BITMAP_WIDTH         256
#define STB_FONT_arial_bold_30_usascii_BITMAP_HEIGHT        122
#define STB_FONT_arial_bold_30_usascii_BITMAP_HEIGHT_POW2   128

#define STB_FONT_arial_bold_30_usascii_FIRST_CHAR            32
#define STB_FONT_arial_bold_30_usascii_NUM_CHARS             95

#define STB_FONT_arial_bold_30_usascii_LINE_SPACING          19

static unsigned int stb__arial_bold_30_usascii_pixels[]={
    0x564c0732,0x00665402,0x6540eea6,0x44266604,0x00199999,0xaacba988,
    0x4cccc000,0x0f5c0099,0x1aba9800,0xaba98000,0x47990001,0x04403cc8,
    0x8800c000,0x64c00aba,0x2ea2000c,0x930000ab,0x541bf639,0xfb02ffff,
    0x3ff6203f,0x209ff05f,0xff73fff8,0x5400ffff,0xfffffffd,0x7c400bef,
    0x203fffff,0x22003fd9,0xfffffffd,0x3f66000d,0x0dffffff,0x54bff300,
    0xffd704ff,0x457ff29d,0xffd89fff,0xfff501ef,0x37f403ff,0xfffff900,
    0xff70007f,0x2a0bfe63,0xd80fffff,0xfffb01ff,0x03ff70bf,0x7dcfffe2,
    0xa807ffff,0xefffffff,0x02ffffff,0x3fffffe2,0xfffff983,0x3fee00bf,
    0xffffffff,0xfffb803f,0xffffffff,0x23ffa802,0x7ec43ffc,0xfdcfffff,
    0xd5fff15f,0x87ffffff,0x6ffcfff8,0x2005ff50,0xfffffffc,0x3fec003f,
    0x3b261bfa,0xffd83fff,0xdffff881,0x1037fc43,0x33267fff,0x7e407ffd,
    0xa981adff,0xf103fffd,0xa8399bff,0xffffffff,0xfffff906,0xffffffdf,
    0x7fffdc07,0xfffffeff,0x17fe403f,0xffc83ffb,0xffffeeff,0xfffff15f,
    0x1fffffdf,0xffc97fe4,0x1006fe82,0xfb33bfff,0x5ff800ff,0xfd01ffdc,
    0x03ffb07f,0x3203fff3,0x4ccc03ff,0x207ffb80,0x2000effd,0xf882ffea,
    0xfff102ff,0x5fffdfdf,0x0dffff88,0x07fffecc,0x06ffffcc,0x03ffff62,
    0x3fe0ffd8,0x17fffc47,0x22bfffd5,0x911dffff,0x7fecbfff,0xfa87ff71,
    0xfff5002f,0x007ffc43,0x7c43ff98,0x13ff607f,0x3e607ff6,0xfff880ff,
    0x7fdc0000,0x209ff707,0x3ffa2008,0x817ffc40,0xafc8fffa,0x7fec6ffe,
    0x7ffec04f,0x04fffe85,0x532fffe4,0x755fff55,0x3ee35fff,0xfffa83ff,
    0x01ffff15,0x7fecfffd,0xfe89ff50,0x3ffe2006,0x003ffee5,0x7f40ffdc,
    0x0bffb02f,0xff503ffb,0x01bfea0f,0xf707fff1,0x8bff30ff,0xa9effec8,
    0x87ff35ee,0xf702fff8,0x2a27f2df,0x3fffe61a,0x7fffc400,0x03fffe21,
    0x23ffff10,0xfffffffd,0x94ffffff,0x3fe01fff,0x0dfff15f,0x7ec7ffee,
    0x547ff71f,0x7f4002ff,0x5fff9aff,0x641ff600,0xbffb04ff,0xf503ffb0,
    0x13ff20ff,0x707fff10,0x1ffb0fff,0x7fffffcc,0x3f25ffef,0x817ffc46,
    0x03f97ffa,0x8027ffd4,0x3e62fffc,0xff9004ff,0x3ffff65f,0xffffffff,
    0x40fffb4f,0xfff15ffe,0x4bffea09,0x5ff92ffc,0x540037f4,0xffffffff,
    0x417fe001,0xff906ffb,0x503ffb0b,0x3ff60fff,0x1fffc403,0x3e23ffdc,
    0x3bffe63f,0x4ffffdaa,0xff883fea,0x37ffe02f,0x3fee01fd,0xfff7002f,
    0x017ffdc7,0x533fffa8,0xd559ffb5,0x3f6357ff,0x57ffe07f,0xf503fff8,
    0x3ffe25ff,0x3fea7ffc,0xfffb0002,0x4c003dff,0xfff504ff,0x361ffee0,
    0x6ffc81ff,0x8805fff0,0xffb83fff,0xfd07fdc7,0x5ffff0bf,0xff10ffc4,
    0x7ffec05f,0x3ff603ff,0xfff5001f,0x00fffe49,0xe84fff98,0x21ffe0ff,
    0xff00fffc,0x13ffe2bf,0xf70fffdc,0x7f43ffff,0xfff50006,0xb8001fff,
    0xfff302ff,0x87fff101,0x7fc41ffd,0x1fff884f,0x41fffc40,0x3ff47ffb,
    0xf903fff5,0x22ff81ff,0x2602fff8,0xcfffffff,0x00fffec0,0x365fff98,
    0xf3001fff,0x4fff0bff,0xffb86ff8,0x5fffa82f,0x360ffff1,0xaca987ff,
    0x530bfea0,0x7fffdc03,0x20024fff,0xff100ffd,0x3fff605f,0x223ffb2e,
    0xa80ffffc,0x7c400fff,0x7ffb83ff,0x9ffb2ffc,0xf31ffee0,0x17ffc43f,
    0x3ffffa60,0x3ff21fff,0xfff5001f,0x00fffec9,0x4c4fffa8,0x13fea5ff,
    0xa87bffe2,0xff15ffff,0x7fdc1bff,0x37f4005f,0x81dfffd3,0xffbefffc,
    0x03bff2ff,0xfff01bfe,0x3fffa207,0x3e63ffb4,0xff702fff,0x7fff100f,
    0xff8fff70,0x640fffe3,0x07fdc5ff,0x2005fff1,0x6fffffe9,0x400bffee,
    0x3ee3fffb,0xff7002ff,0x3ff72e7f,0xcdffecce,0x3ffff22c,0x5fffffee,
    0xbffffff1,0x003fffff,0xff897fd4,0x3e26ffef,0xfff70eff,0x103fff7f,
    0xfff809ff,0x9fffb103,0x7fcc7ff6,0xfff701ff,0x07fff100,0x7fc4fff7,
    0x203fff11,0x37ec3ffe,0x800bffe2,0x0fffecfc,0x1309fff5,0x2a1fffd8,
    0xfb005fff,0x3fff65ff,0xffffffff,0x3ffa24ff,0xfffdffff,0xffbfff15,
    0x007fffff,0x3fee6fe8,0x3ea3ffb2,0x7ffe42ff,0xff506fff,0x01fff805,
    0x365dfffb,0xfffd11ff,0x0fff501f,0x707fff10,0x8ffc4fff,0xf881fff9,
    0x0ffe61ff,0x4005fff1,0x27ffd1fc,0x740ffff8,0xffff98cf,0x07fffe20,
    0x21ffff30,0xfffffffd,0x84ffffff,0xff3ffffc,0x2fffe2bf,0x01efffe8,
    0xfb17fd40,0x6cffee3f,0xfffd07ff,0x3ff207ff,0x03ffe200,0xfb0fffe6,
    0x4fff983f,0x400fff98,0xfb83fff8,0xf897fc7f,0xfffc82ff,0xf10dff10,
    0x332a05ff,0x3ff23f92,0x997fff25,0xfffeffff,0x0efffc84,0x49fffd10,
    0xa99fff98,0x00999eff,0x2bfff026,0x2623fff8,0x8dfd0000,0x53fea7fe,
    0xf881fffd,0xfd00ffff,0x07ff980d,0xffb0fff5,0x20bff903,0x7c401fff,
    0x7ffb83ff,0xbfff27f4,0xd17fff98,0xfff105ff,0x65bffa05,0x447ffb1f,
    0x889effff,0x0ffffffd,0xbfffff88,0xfffff731,0x2a5ff981,0x7c0004ff,
    0x7fff15ff,0x3fea0000,0xfb87fec2,0x1bfff73f,0x7ffffec4,0x027fc41f,
    0x7e41bfea,0x81ffd85f,0xffd07ffa,0x3fff8805,0x7e47ffb8,0x2fbffee7,
    0xfefffffd,0xfff102ff,0x33ffee05,0x1fffa9fc,0x7fffffd4,0x5fffffff,
    0x3ffffea0,0xffffffff,0x323ffb82,0x7c0002ff,0x7fff15ff,0x1bfa0000,
    0x7fe4bff2,0x3bffffa2,0xfffffffe,0x0bfea4ff,0x320bff90,0x1ffd85ff,
    0xfb07ffa8,0xfff8809f,0x4c7ffb83,0x3fff62ff,0xffffdfff,0x3fe201ff,
    0xffff102f,0x0bfffdff,0x3fffffa6,0xefffffff,0xffffd302,0x03dfffff,
    0xffd8bff2,0x7ffc0000,0x007fff15,0x305ff500,0x1fff7dff,0x7fffff4c,
    0xffebefff,0x003ff21f,0x3f605ffd,0x81ffd85f,0xff707ffa,0x3fff880d,
    0xfe87ffb8,0x33bf6a0f,0x0acefd88,0xfff88662,0x3fffea02,0x400effff,
    0xdfffffeb,0x02ffffec,0x3fffffae,0x07ff403e,0xf0000fff,0x3ffe2bff,
    0x6fe80003,0x3fffff20,0xfffff902,0x743fc89f,0x37fc407f,0xfb09ffb0,
    0x1fff303f,0x9803ffe0,0xffb83fff,0x00eff987,0x127fec00,0xd8805fff,
    0x003effff,0xffc80988,0x00262006,0x15542aa8,0x04ccc000,0x80001333,
    0x65402ee9,0x998801cd,0x06aa0600,0x7405ff50,0x1ffd84ff,0x701fff98,
    0x7fd405ff,0x07ffb83f,0x0005fff5,0xf88dffd3,0xfb1002ff,0x4c000005,
    0x0000002c,0x00000000,0x00000000,0x00000000,0x37261bf6,0xffd83fff,
    0xcefff881,0x642ffc43,0x532ffffe,0x5c0fffb5,0x09bcefff,0x7ffe54c4,
    0x67ffc40e,0x0fe400aa,0x00000000,0x00000000,0x00000000,0x00000000,
    0x7ff10000,0x1fffff50,0x3603ffb0,0xfb85ffff,0x7ffff40f,0xfffff70f,
    0xfffe980f,0xfffeefff,0xf104ffff,0x807fffff,0x000000ca,0x00000000,
    0x00000000,0x00000000,0x20000000,0xfff507fc,0x07ff607f,0x42ffff44,
    0x3fe23ff8,0x3fee1fff,0xb5007fff,0xffffffff,0x44017dff,0x03ffffff,
    0x00000000,0x00000000,0x00000000,0x00000000,0xcc800000,0x01599302,
    0x2a006654,0x879503cb,0x54c0accb,0x8002aaaa,0xaacccba9,0x2aaaa001,
    0x000000aa,0x00000000,0x00000000,0x00000000,0x00000000,0x00000000,
    0x00000000,0x00000000,0x00000000,0x00000000,0x00000000,0x00000000,
    0x00000000,0x00026200,0x26600066,0x004ccc00,0x04ccc000,0x44000110,
    0x02620009,0x02666000,0x03557510,0x44009998,0x01e64199,0x1abb9880,
    0x2aea6000,0x00999801,0x57310071,0x304ccc13,0x7fec4133,0x6c401eff,
    0x200dffff,0x3fffffd8,0x003fff98,0x2fffc400,0xd9f7ffe4,0xffd884ff,
    0x3ee01eff,0x0001efff,0x7dc17ffe,0x1effffff,0xc80dfff0,0x1ff61fff,
    0xfffec880,0x1003ffff,0xfffffffb,0x427ffc05,0x7fd405fb,0x3ffe4fff,
    0x26bfff14,0xfffffffe,0xfffff503,0xff303fff,0x8dffffff,0x0003fff9,
    0x12fffc40,0x9ffffffd,0xff989ffb,0x81ffffff,0xfffffffd,0xbfff0003,
    0xfffffd88,0xf83fffff,0x7fe406ff,0x003fee1f,0x3fffffea,0x00efffff,
    0x3fffffea,0xff05ffff,0x05ffe89f,0x3fffffe6,0x7c53ffe2,0xffffd5ff,
    0xf10ffffd,0xffffdfff,0xffffe81f,0x264ffffd,0x00003fff,0xfb2fffc4,
    0xfffdbfff,0x7ffc49ff,0x46ffffff,0xffeffffa,0xff8000ff,0x7fffe45f,
    0xfffffedf,0x2037ffc1,0x3e61fffc,0x7ffd402f,0xffffefff,0xfff706ff,
    0xffffddff,0x89fff07f,0x3ea05ffe,0x3e0aadff,0xbfff14ff,0x7d49fff3,
    0x7ffe42ff,0x47fff912,0x3a24fff9,0x3ffe66ff,0x7c400003,0xdfff35ff,
    0x27fff543,0x7e47fff9,0x3fffa1ff,0x007fff50,0xff8bfff0,0x7ff441ef,
    0x037ffc4f,0xf887fff2,0x3ffe204f,0x7fe4c1ef,0x7ffc42ff,0x3ff260cf,
    0x04ccc0ff,0xfc817ffa,0x9fff00ff,0x3ef7ffe2,0x46ffe87f,0xfff86ffe,
    0x707ffea7,0x7ffccfff,0x220000c3,0xfff95fff,0x29fff507,0x7444fff8,
    0x7fff31cd,0x4407ffd8,0xf32fffc0,0x3fe607ff,0x037ffc6f,0xfd07fff2,
    0x2fffe40d,0x917fff60,0x7ec07fff,0xffc804ff,0x641fffff,0x3ffe07ff,
    0x44bfff14,0x227ffc40,0xffd84fff,0x83fff31f,0x3fe66ffc,0xefffd8bf,
    0xfff88001,0x103fffb5,0x3fea9fff,0xfff7002f,0x81fffb83,0xff3efffc,
    0x77ffccbf,0xf8355500,0x7fe406ff,0x807fe41f,0x4400ffff,0x3fe21acd,
    0x5e74c07f,0xfca7ffc0,0x91ffffff,0xbfffffff,0xff14fff8,0x7fe440bf,
    0x13ffe22f,0xfe8bffee,0x9ffd10df,0x7fefffcc,0x003fffff,0xfeafffc4,
    0x53ffe07f,0xa988fffb,0x81fff901,0x3a21fffa,0xfdffffff,0x7fffc5ff,
    0x3fe001cf,0x7ffe406f,0x5417fd41,0x40004fff,0x0004fff9,0xffca7ffc,
    0xf91fffff,0x8bffffff,0xfff14fff,0x3ffff60b,0xd86fff83,0x3fa63fff,
    0x0dfffeff,0x3fffffe6,0x01fffffd,0x757ffe20,0xfff107ff,0x3ebfff29,
    0x7e42ffff,0x2fff987f,0x3b7ffff6,0x5c5fffff,0xdfffffff,0x1bffe00b,
    0x883fff90,0xfffb84ff,0x7fd40003,0x7fc0003f,0x42fff44f,0xfffffffc,
    0xf8a7ffc5,0xffff05ff,0x03fff607,0xf889ffff,0x985fffff,0x910cffff,
    0x4400bfff,0xfffb5fff,0x29fff501,0xfffffffd,0x3ff63fff,0x33fff987,
    0x7543dfff,0xffc85fff,0x4fffffff,0xc80dfff0,0x6fe81fff,0x502fffc8,
    0x15555555,0x000bfff2,0xfe89fff0,0x1fff205f,0xff14fff8,0xffff10bf,
    0xdfff307f,0x9ffffd57,0xffffffd8,0x7fffcc4f,0x007ffe80,0x7dd7ffe2,
    0xfffd83ff,0x5dffffd4,0x3a1ffff9,0xfff987ff,0x707fff94,0x3aa0bfff,
    0xffffffff,0x037ffc0e,0x3207fff2,0x7ffe40ff,0xfffff882,0xfffb1fff,
    0xfff80003,0x902fff44,0x7ffc0fff,0x10bfff14,0x0dfff713,0xfffffff9,
    0x3fa29fff,0xfffcacff,0x417ffe65,0x1000fffc,0x3fe2bfff,0xffd98cff,
    0xdfffb4ff,0xfb4fff98,0x7fff30ff,0x2207fff6,0x5c405fff,0x6ffffffd,
    0x32037ffc,0xffa81fff,0x41fffdc2,0xfffffff8,0x05fff91f,0x44fff800,
    0x3f205ffe,0x53ffe07f,0xb805fff8,0xffb81fff,0x3fffaeff,0xfb83fff5,
    0x7fff30ff,0x007ffee0,0xf92fffc4,0xffffffff,0x3fff29ff,0xfb5fff84,
    0x5fff30ff,0xff81fffa,0x7ecc005f,0x3ffe0fff,0x0fffec06,0x3e61ffc4,
    0xfff884ff,0xf71fffff,0xf80007ff,0x2fff44ff,0x7c0fff90,0xbfff14ff,
    0x07fff300,0x3ea26aa2,0x0fff92ff,0x3e67fff1,0xfff704ff,0xff881983,
    0x7fffe45f,0x94fff9ff,0xffb05fff,0x503fff2d,0x3ffa5fff,0x4bfff107,
    0x7e403baa,0x1bffe2ff,0x201fffb0,0x6fff85fe,0x23fff900,0x4404fff9,
    0x4fff82de,0xf902fff4,0xa7ffc0ff,0xa99dfff8,0x05fff882,0x747ffee0,
    0x9fff06ff,0x6417ffe6,0xfff70fff,0x84fff983,0xff0cefda,0x13ffee9f,
    0x7fddbff6,0x8fffdc1f,0xfa81fffd,0x3fffa5ff,0x8fffea01,0x3a00fffe,
    0xffb00fff,0x005fffb0,0x3e23fff9,0x3ee00fff,0x27ffc6ff,0xfc81bffa,
    0x53ffe07f,0xffedfff8,0x1fffdc0f,0xffd0bb95,0x207ffecd,0xff33fffa,
    0x9fffa0ff,0x7d43fffa,0x7fc003ff,0x0dfff33f,0x3fe6bfff,0x73ffec3f,
    0xff905fff,0x2fffe4bf,0x6c3fffd0,0xff304fff,0x0ffdc0ff,0x807bffee,
    0x321fffe8,0xff105fff,0x4fff87ff,0xf9037ff4,0xa7ffc0ff,0xffbdfff8,
    0xfffd30cf,0x897ffdc3,0x3ee3fffc,0xffb10cff,0x3fffe65f,0x97fff224,
    0xa8bffff8,0xdf51fffe,0x5fff309b,0xf71fffec,0x7fff47ff,0x4c9fff30,
    0x3ea0efff,0x3fe65fff,0xda88adff,0x7fd47fff,0xfd732cff,0x7fcc09ff,
    0xbffffe83,0xffff9511,0x7fffc43f,0xffeb889e,0x44fff87f,0x42eefffd,
    0x3fe07ffc,0x1bfff14f,0xffdfffff,0xfff889ff,0x47ffffef,0xfdfffff8,
    0x3fe65fff,0xfffdefff,0x7ffec0ff,0x24ffffff,0x99cffff8,0x260fffeb,
    0xffffffff,0x7fffdc6f,0x6c0ffffe,0xffedffff,0x7fe45fff,0xffffffff,
    0xfffe84ff,0xffffffff,0x42ffc00f,0xfffffff9,0xefffffff,0x7ffffd40,
    0x2fffffff,0x7dc4fff8,0x7e43ffff,0x53ffe07f,0xff35fff8,0x1dffffff,
    0xffffff70,0xfff303df,0x41ffffff,0xfffafff9,0xf883ffff,0x6fffffff,
    0xffffffd8,0xfb83ffff,0x1fffffff,0xffffffd8,0xfffe883f,0x5ffdcfff,
    0xffffffd8,0xd103ffff,0xffffffff,0xffb005ff,0x3ffffa20,0x2fffffff,
    0x3ffffa60,0xf02fffff,0xfffb09ff,0x07ffc87f,0x7fc53ffe,0x3fff625f,
    0x7fd403ff,0x2200dfff,0x0cfffffc,0x6c47ffcc,0x2201efff,0x0bdffffd,
    0xffffff90,0x7f4c07ff,0x2e00dfff,0x402effff,0xfb3ffffc,0x3ffa60bf,
    0x801defff,0xeffffffc,0x3ff7000d,0x7fffed40,0x32003cef,0x0cfffffe,
    0x4413ffe0,0x0fff9009,0xff8a7ffc,0x0013305f,0x98000998,0x1310001a,
    0x20019800,0x0abccba8,0x10006600,0x00980013,0x004ccc00,0x001a9880,
    0x20015510,0x30000199,0x00000013,0x00000000,0x00000000,0x00000000,
    0x00000000,0x00000000,0x00000000,0x00000000,0x00000000,0x26600000,
    0x4cc40009,0x99999999,0x26660999,0x99988009,0x20066660,0x26621999,
    0x06666201,0x4cc19988,0x26660019,0x80026660,0x99999998,0x09999999,
    0x26666666,0x33000999,0x13333333,0x304ccc40,0x99880133,0x04ccccc1,
    0x13333310,0xfff70000,0x027ffc43,0x3fffff20,0xffffffff,0x01bfff23,
    0xfe8ffffa,0x3ff204ff,0x07fff66f,0x80ffffec,0x3f60fffd,0xffb803ff,
    0x07fff34f,0x7ffffd40,0xffffffff,0x3ffffe6f,0xdfffffff,0x3ffffe00,
    0x83ffffff,0x3fe2fffc,0x3fea01ff,0xfffff11f,0x7fffdc0d,0x00ffff3f,
    0x221fffb8,0x64004fff,0xffffffff,0x743fffff,0x3ee03fff,0x7ffcc6ff,
    0xffff981f,0x40bffee1,0xf03fffff,0xfffa8dff,0x1fffd805,0x4007fff3,
    0xfffffffa,0x6fffffff,0x3ffffffe,0x0effffff,0xfffffff0,0x41bfffff,
    0x3fe2fffc,0x3fea06ff,0xfffff11f,0x3fffa01f,0x0ffff3ff,0x21fffb80,
    0x4004fff8,0xfffffffc,0x43ffffff,0x880ffffa,0xfc81ffff,0xfffe86ff,
    0x427ffcc3,0x85fffff9,0x7c44fff8,0x3e200fff,0x3ffe66ff,0x3ffea003,
    0xffffffff,0x3ffe6fff,0xffffffff,0xfff07fff,0xffffffff,0x7ffe4dff,
    0x0bffffe2,0xf88fffd4,0x882fffff,0xf3ffffff,0xea800fff,0x3ffe20ee,
    0x74400004,0xfd80efff,0xfffd85ff,0x7fffd104,0xf837ffdc,0xfffb86ff,
    0xfffa87ff,0x03fffd82,0xf993ffee,0xd80003ff,0x7fc00fff,0x3ffee06f,
    0x86fff81f,0x92ffffd9,0x7ffc5fff,0xffa80fff,0xfffff11f,0xffff50bf,
    0x1fffe7ff,0xfff88000,0xb0000444,0x2201ffff,0x3e61ffff,0x7fd406ff,
    0xffff88ff,0x81fffd01,0x1ffffffd,0x5407ffe4,0x3f606fff,0x3ffe61ff,
    0xffd80003,0x37ffc00f,0x20ffff20,0x3f606fff,0x5fff73ff,0x27fffffc,
    0xf88fffd4,0xc87ffeff,0xf3fffeff,0x40000fff,0xff94fff8,0xfc8007df,
    0x7dc01fff,0x3fffa6ff,0xdfffd802,0x3204fffd,0x7ffc1fff,0x7f43fffb,
    0x3fffe07f,0x46fff880,0x7e43fff9,0x7ec00eff,0x7ffc00ff,0x27ffd406,
    0xf5037ffc,0x3ffee9ff,0x3fffffe1,0x8fffd41f,0xfffcfff8,0x7fe7ff41,
    0x00ffff3f,0x6fffc400,0x4ffffffe,0x7ffff500,0x2ffff600,0x1005fffb,
    0xdfffffff,0x1fffd401,0xffd3fff3,0x02fffc4b,0xf507fff9,0xfff987ff,
    0x03bffee3,0x003fff60,0xfc80dfff,0x6fff83ff,0x54fffee0,0x3ffe0fff,
    0x7d46fffe,0x7fff11ff,0x7fc47ffd,0xff3fffaf,0x440000ff,0xecefffff,
    0x4c00ffff,0x2005ffff,0xfffffff8,0x3fea000f,0x4402ffff,0x3ff25fff,
    0x7ccfff77,0x3fe603ff,0x0fffd86f,0xfa9fffcc,0xfb000fff,0xfff801ff,
    0x7fe4ccc6,0x6fff80ff,0x23ffff30,0x3fe0fff9,0x23fffdcf,0xff11fffa,
    0x54bff97f,0x3fff8fff,0x0000ffff,0x227fffc4,0x2202fffc,0x8006fffe,
    0x3ffffffb,0xffffd800,0x4fffd005,0xfff35ffe,0x007ffee3,0x7c41fffd,
    0xfff985ff,0x01ffff9b,0x003fff60,0xffffffff,0x07ffffff,0x3333fffe,
    0x0fffffdc,0xfff8fff1,0x50ffff8c,0x3fe23fff,0x327ffabf,0x3fff8dff,
    0x0000ffff,0x4c3fffc4,0x3fa03fff,0xd0000fff,0x000dffff,0x013ffff6,
    0x7c47ffe4,0x4fffe2ff,0xfb807ffd,0x3ffea3ff,0xfcfff982,0x6c001fff,
    0x7fc00fff,0xffffffff,0x3fe02fff,0xffffffff,0x3fe22fff,0xfba7ffc6,
    0x3fff55ff,0x3e2fffe2,0x17ffd1ff,0x3ffe7fff,0x6664c007,0x217ffe20,
    0xf904fff8,0x40003fff,0x001ffff9,0xffffffa8,0xafffa801,0x3f60fffa,
    0x00bfff5f,0x7ecdfff3,0xfff980ff,0x8005ffff,0x7c00fffd,0xffffffff,
    0xfff801ef,0xffffffff,0x7c6ff82f,0x3fffa4ff,0xf11fffa9,0x2fffa7ff,
    0xff89fff8,0x00ffff3f,0x221fffb8,0xff884fff,0xffffb84f,0xfff80003,
    0xfff88006,0x8806ffff,0x6ffccfff,0x7fcfffdc,0xfffd003f,0x20bfff13,
    0xfffffff9,0x7fec002f,0x37ffc00f,0x01bfffd3,0xeeeffff8,0x3fa02ccc,
    0xf327ffc5,0x3fff5dff,0x7e4fffe2,0xf17ffaef,0x1fffe7ff,0x43fff700,
    0xf884fff8,0x7ffcc4ff,0xff00004f,0xffb000df,0x07fffddf,0xffdbfff0,
    0xfcfff989,0xff7001ff,0x05fff57f,0x3fffffe6,0x7ec006ff,0x7ffc00ff,
    0x0efffe86,0x001bffe0,0x3ffe27ec,0x7f7ffec4,0x7fff11ff,0x3ff7ffea,
    0x3e7fff15,0x7dc007ff,0x3ffe20ff,0x24fff884,0x005ffff8,0x01bffe00,
    0x53ffff50,0xd803ffff,0x82ffffff,0x07ffffff,0x37bffe20,0x3fe607ff,
    0x3fffabff,0x03fff600,0xf10dfff0,0x7fc0bfff,0x7fb0006f,0x7c44fff8,
    0x11ffffff,0x3fe27fff,0xff13ffff,0x01fffe7f,0x3fe23f40,0x4fff884f,
    0x003bfffa,0x06fff800,0x8ffffe20,0x5c06fffd,0x80ffffff,0x05fffffd,
    0x7ffffec0,0x3ffe604f,0x003fffa4,0x2007ffec,0xff506fff,0x3ffe05ff,
    0x7fc00006,0xffffb84f,0x7fff11ff,0x8ffffff4,0xfff3fff8,0x8df1000f,
    0xf884fff8,0xffff94ff,0x33333335,0x3fe00133,0x3ff6006f,0x7fffc46f,
    0x3fffe603,0xffff506f,0xffa8007f,0x2601ffff,0x3fe63fff,0xfffb004f,
    0x06fff801,0x203ffff6,0x98006fff,0x3ffe0ccc,0xfffffd04,0xc8fffe23,
    0x3e27ffff,0x3ffff3ff,0x33333333,0xf107fea1,0xfff109ff,0x3fffff69,
    0xffffffff,0xdfff006f,0x3fffea00,0x1ffffa81,0x13ffffe0,0x17ffffc4,
    0x3fffe200,0x7ffcc06f,0x00fffec3,0x2007ffec,0x3e206fff,0xfff85fff,
    0xfffa8006,0x4c13ffe1,0xf11fffff,0x7ffd47ff,0x4fffe25f,0xffffffff,
    0xd54fffff,0x09fff105,0x3f69fff1,0xffffffff,0x006fffff,0xf100dfff,
    0x7ec09fff,0x3ff606ff,0x3ffa01ff,0xfd8000ff,0x7cc04fff,0x7ffc43ff,
    0x0fffd805,0x2037ffc0,0x7c1ffffa,0xfa8006ff,0x13ffe1ff,0x11ffffc8,
    0x7fc47fff,0x3ffe23ff,0xfffffff3,0x09ffffff,0x109fff10,0x3ff69fff,
    0xffffffff,0xf006ffff,0xff900dff,0x7fc401ff,0xfff703ff,0x6fffc80f,
    0xffff5000,0x3fff9803,0x402fffc8,0x7c00fffd,0xffd806ff,0x037ffc6f,
    0xf0fffd40,0x7fc409ff,0x7fff11ff,0x221fffe8,0xffff3fff,0xffffffff,
    0x0000009f,0x00000000,0x00000000,0x00000000,0x00000000,0x00000000,
    0x00000000,0x00000000,0x04ccc000,0x82666620,0xf701fffc,0x554c05ff,
    0x026aa201,0x30026600,0x33333333,0x99983333,0x99999999,0x4cccc199,
    0x00001999,0x4cc0aaa2,0x09999999,0x4ccc4000,0x7ffe4000,0x41ffffff,
    0x4c400999,0xffffd099,0xbfffffff,0x2a009980,0x7ffc2fff,0x3fffa206,
    0x13ffe61f,0xf103ffec,0xfff509ff,0x8803bfff,0x0cfffffc,0xfffffff8,
    0x20ffffff,0xffffffff,0x21ffffff,0xffffffff,0x20002eff,0xfff07ffd,
    0xffffffff,0xffb0007d,0xffd800df,0x1fffffff,0x2e037ffc,0xfffd2fff,
    0xffffffff,0xfffff70b,0xfffa819f,0xd037ffc2,0xfd03ffff,0x9fff10df,
    0x227ffec0,0xfffffffd,0xfff303ff,0x81ffffff,0xffffffff,0x3e0fffff,
    0xffffffff,0x3e1fffff,0xffffffff,0x4000dfff,0xff07fffa,0xffffffff,
    0x4400bfff,0x001fffff,0x3ffffffe,0x7ffc1fff,0x97ffdc06,0xfffffffe,
    0x7f45ffff,0x5fffffff,0x3e17ffd4,0xfffb06ff,0x3ffee05f,0x80fffd41,
    0x324ffffb,0xfdbdffff,0x7f441fff,0xffffefff,0x7fffffc6,0x0fffffff,
    0x3ffffffe,0x1fffffff,0x3ffffffe,0x06ffffff,0x1ffffe20,0x7ffffffc,
    0x3fffffff,0xfffff900,0x3ffe2009,0x0aaaaaac,0x2e037ffc,0x55552fff,
    0xfffb5555,0x5efffdc3,0x263fffdb,0x7ffc1eee,0x2ffffd86,0xb13ffe20,
    0xffb30dff,0x3fe29fff,0x7ffc40ef,0x867ffd46,0x3e1fffe8,0xff8006ff,
    0xfff0006f,0xffff930d,0x3fff6007,0x0dfff07f,0x01bfff22,0x7ffffffc,
    0x0fff9800,0x01bffe00,0x1005fff7,0xffd87fff,0x004dfd85,0xff91bffe,
    0xffb005ff,0x21fffc4d,0xfffffffc,0x205fff54,0x7fe47ffc,0x1fffd41f,
    0xf000dfff,0x3e000dff,0x3fe606ff,0x7fd400ff,0xfff07fff,0x07ffe80d,
    0xffdfffa8,0x7ffb803f,0x037ffc00,0x200bffee,0xffd85ffc,0xf80001bf,
    0x3ffee6ff,0xfff5003f,0xd03ffea3,0x9fff7dff,0xfc812ea2,0x1732a0ff,
    0xff8fffe6,0xfff8006f,0xdfff0006,0x03fffc80,0x3ffbffe2,0x80dfff07,
    0xfd806ffd,0x06fff8ff,0xedbeffc8,0x1bffe02c,0x805fff70,0xfb80fff8,
    0x0adfffff,0x76fff800,0x8007ffff,0xbffb4fff,0x3fe27fd0,0x3fe2004f,
    0x7fdc005f,0x01bffe1f,0x001bffe0,0x26037ffc,0x3f604fff,0xf07ffccf,
    0x7fcc0dff,0x7ffc404f,0x803fff95,0xfffffffe,0x6fff80df,0x017ffdc0,
    0xfd80bff6,0xcfffffff,0x3bffe000,0x006ffffa,0xff8effc8,0x3e20c82f,
    0xfd1004ff,0xfe8005ff,0x3bffe0ff,0x2aaaaaaa,0xeeeffff8,0x42eeeeee,
    0x7c406fff,0xdff705ff,0x7fc1fff2,0xdcccccff,0x5c00efff,0xfff32fff,
    0xfffff809,0xf85fffff,0xcccccfff,0x02fffecc,0x2e01ffe6,0xfffffffe,
    0x3fffe005,0x03ffffff,0x7e7ffcc0,0xff8800ff,0xfff9804f,0x7fec004f,
    0x7ffffc3f,0x86ffffff,0xffffffff,0x7c3fffff,0xfff806ff,0x91fff886,
    0x3ffe0fff,0xffffffff,0xfffd005f,0x300fffe8,0xf713bfff,0xfff85fff,
    0xffffffff,0x3a02ffff,0x2e6004ff,0x00fffffd,0xfffffff0,0x8001ffff,
    0x05fffffe,0x809fff10,0x003ffff8,0x7c37ffe4,0xffffffff,0xffff86ff,
    0xffffffff,0x037ffc3f,0x7ec3fffc,0x41fff24f,0xffffffff,0x403fffff,
    0x7e44fff9,0x0aa603ff,0xff17ffe6,0xffffffff,0x205fffff,0x2201fffa,
    0xfffb81a9,0xf8399933,0xfcbfffff,0x7dc005ff,0x1002ffff,0xfe809fff,
    0x7ec003ff,0xfff81fff,0xeeeeeeef,0xccffff85,0x1ccccccc,0x22037ffc,
    0x7fdc7fff,0xf83ffe46,0xcccccfff,0x00effffd,0xf983fff9,0x3e0006ff,
    0x7fffc7ff,0xeccccccc,0xffd02fff,0x37ffc40d,0xfa9fffcc,0x7fffc2ff,
    0x7ffff13f,0x7fffc400,0x3ffe2007,0x0fffe204,0x3ffffb00,0x001bffe0,
    0x4001bffe,0x7c406fff,0x3ffe25ff,0xfffd999b,0x1bffe099,0x02fffd88,
    0x9999ffff,0x003ffff9,0xf83fff60,0x7fdc06ff,0x2fff882f,0x5f7ffec0,
    0x50fffeca,0xfff85fff,0x7fffdc4f,0x3fff6000,0x3ffe2004,0x01ffea04,
    0x03ffffb0,0x40037ffc,0xf0006fff,0xff980dff,0x3fffee4f,0xffffffff,
    0x01bffe2f,0xf50bfff1,0xffffffff,0x4c0bffff,0xf8fffd01,0x7fdc06ff,
    0x0fffa82f,0x7ffff440,0x2a2fffff,0x7ffc2fff,0x0bfffd06,0x00fffec0,
    0x409fff10,0x32006ffb,0x7c00efff,0xff8006ff,0xfff0006f,0x3fffc80d,
    0x3fffffee,0x2fffffff,0x3e01bffe,0xfffe87ff,0xffffffff,0x7fe40fff,
    0x37ffcc1f,0xf701bffe,0xfff905ff,0x7fff5c00,0x7c001dff,0xfff506ff,
    0xfff3005f,0xfff8800d,0x7d400004,0xff800fff,0xfff8006f,0xdfff0006,
    0x237ffcc0,0xfffffffb,0x22ffffff,0x7d406fff,0x7ffc46ff,0xccccccce,
    0x7d43fffe,0xff910dff,0x06fff85f,0x7417ffdc,0x988005ff,0x3fe00019,
    0x3fff606f,0xffcaa80f,0x7c4002ff,0x332604ff,0x7ffc400c,0xaaaaaadf,
    0x001bffe1,0x2667bffe,0x09999999,0x2667bffe,0x2ffffca9,0x4cccccc4,
    0x099fffd9,0x2667bffe,0xffffc999,0x017ffe44,0x3a1bffe6,0xfffdffff,
    0x06fff86f,0x7c17ffdc,0x000004ff,0x81bffe00,0xe85ffff8,0x006fffff,
    0x204fff88,0x5c00fffb,0xffffffff,0x3ffe4fff,0xffff8006,0xffffffff,
    0x3fffe4ff,0xffffffff,0xffc8005f,0xffffff07,0xffffffff,0x07fff81d,
    0x883fffd0,0xffffffff,0x06fff80e,0x2217ffdc,0x00003fff,0x1bffe000,
    0x85ffff90,0x00effffd,0x04fff880,0xd003ffee,0xffffffff,0x7ffc9fff,
    0xffff8006,0xffffffff,0x3fffe4ff,0xffffffff,0xffc8000c,0xffffff07,
    0xffffffff,0x04fffa83,0x10bfff70,0x09dffff9,0x2e037ffc,0x7fcc2fff,
    0x0000002f,0x101bffe0,0x4c1fffff,0x20002ccc,0x2e04fff8,0x3e200fff,
    0xffffffff,0x3ffe4fff,0xffff8006,0xffffffff,0x3fffe4ff,0x0cdeffff,
    0x1fff2000,0x7ffffffc,0x80adffff,0x1001fffd,0x4c01ffff,0x6fff8009,
    0x017ffdc0,0x00000000,0x00000000,0x00000000,0x00000000,0x00000000,
    0x00000000,0x00000000,0x36000000,0xfffa86ff,0x205ffe82,0x88001cca,
    0x00620001,0x30000cc0,0x40180003,0x00010001,0x266201a8,0x40220000,
    0xff10001b,0x7fff107f,0x7ffffffc,0xff53ffff,0xfffa81ff,0x403fff66,
    0xff73fffa,0x4fffc81f,0x8817ffc4,0x93006fff,0x007dfffd,0x0bbfffb2,
    0xdffffb50,0xffea803b,0xffa82eff,0x1bfffb37,0x077fff62,0xff71fff3,
    0x7dc4007d,0x0fffa02f,0xd92fff88,0xdfd87fff,0x7ffc4002,0x23fff883,
    0xffffffff,0x3ff23fff,0x3fffe25f,0x40fffe61,0xff10fffd,0x6fffe85f,
    0xb807ffdc,0x4c01ffff,0xffffffff,0xfffd100d,0x2609ffff,0xffffffff,
    0xffffb02f,0xfa87ffff,0xfffffbff,0xffffe9ef,0x3ffe60ff,0x802ffffb,
    0x02ffffc9,0xf880fffa,0xffffebff,0x3fff65ff,0xff8800be,0x3fff883f,
    0x3ffffffe,0x7f42ffff,0x7fffb2ff,0xf10dffd0,0x4ffe89ff,0x83ffffe2,
    0x3fe05ffd,0x3e605fff,0xfffeffff,0xffffb06f,0xd07ffffb,0xffdbbfff,
    0xffff70ff,0x43ffffdd,0xddfffffa,0xdeffffff,0x3e65ffff,0x0fffffff,
    0x3ffffaa0,0x3ffa02ff,0x3fffe203,0xffffecff,0xffffffb1,0x7ffc4039,
    0x23fff883,0xffb19999,0xffff30bf,0x2e0bfff7,0x7fdc1fff,0x73ffdc1f,
    0x7c5fffff,0xdff703ff,0xff103fff,0x3faa19ff,0x7ffd43ff,0x51fff624,
    0xffd83fff,0x3bffe20f,0xa97ffe61,0x3ea1ffff,0x3fa25fff,0x3fffe66f,
    0xfb88399d,0x1dffffff,0x101fff40,0xfd89ffff,0x3ff6a3ff,0x882dffff,
    0xff883fff,0x7ffec03f,0x3fffee06,0xff100fff,0x86ffe89f,0xffb1fff8,
    0x3fea9ffb,0xb7ffd00f,0xfff509ff,0x8ffff109,0x7cc0fffd,0xb81883ff,
    0x3fee0fff,0x21bcc81f,0xff84fffa,0x3ffe40ff,0x201ffff3,0xffffffc9,
    0x999880be,0x999cffe9,0x0dfff109,0x9107fff3,0x7dffffff,0x20fffe21,
    0x3203fff8,0x6c00efff,0x402fffff,0x3fe67ffd,0x27ffd03f,0x96ff9fff,
    0x3fea0dff,0x40fffa8f,0xfd02fffc,0x77ff41ff,0xfff99999,0x7fedcc04,
    0x1fff21ff,0x07fff500,0xff90ffff,0x17ffe61f,0xcfffffd8,0x7ffff401,
    0xffffffff,0x10bfff14,0xda809fff,0xf13fffff,0xfff107ff,0x3fffee07,
    0xffff8801,0x2fff9805,0x3201fff9,0xd6ff9dff,0x07ffd1ff,0xfff93ffa,
    0x703fff44,0x7ffc5fff,0xffffffff,0xfffdb84f,0x361fffff,0x7d4007ff,
    0x6fff82ff,0xf30fffc8,0x7fec09ff,0xffd000df,0xffffffff,0x3ffe29ff,
    0x04fff884,0x27fffd30,0xf983fff8,0xfffa83ff,0xfff3002f,0xffd001ff,
    0x9813ffeb,0x94ffcfff,0x03fff9ff,0x7e43fff5,0x03ffec7f,0x3e25fff5,
    0xffffffff,0x7fec5fff,0xfffcceff,0x001fffa1,0xff05fff5,0x1fff90bf,
    0xd80fffe6,0x01cfffff,0x7ffffff4,0x14ffffff,0xff109fff,0xffda809f,
    0xfff13fff,0x87fff309,0x003ffff9,0xbfffffd1,0xf5fff700,0xfff803ff,
    0xfff51fff,0x3ffa0dff,0x91fffc46,0x3ee03fff,0x17ffe0ff,0x19fff900,
    0xf90fffd4,0x2a0620ff,0xfff82fff,0x30fffc85,0x64c07fff,0xbeffffff,
    0xe9999880,0x09999cff,0xf109fff1,0xff9109ff,0x417dffff,0xffa84fff,
    0x3fffe23f,0x3fff6003,0x4403ffff,0x06ffefff,0x27ffffc8,0x84fffff8,
    0xfd83fff9,0x13ffea6f,0x3fa3fff4,0xe81a80ff,0xfffb86ff,0x20bffee1,
    0xff50effd,0x0bfff05f,0x3e61fff9,0xfb8803ff,0x1cffffff,0x101fff40,
    0xff109fff,0x7ffed49f,0xfd02efff,0x7ffc41ff,0xbfffd13f,0x81333333,
    0xff8dfffa,0x7fe401ff,0xf9803fff,0x7ff45fff,0x400001ff,0x30bffff8,
    0xfb87fffb,0x7ffe44ff,0xd11bffa2,0x7fcc3fff,0x3ffe62ef,0x20bffea5,
    0xffc85fff,0x07fff30f,0xffffea80,0x3ffa02ff,0x13ffe203,0x7ed3ffe2,
    0x01cfffff,0x6e77ffec,0xf73fffff,0xffffffff,0x7ffc4dff,0x0dfff70f,
    0x0fffff98,0x87ffff00,0x0006fffc,0xfffff500,0x20dffffd,0xfdbeffff,
    0x7ffdc5ff,0xffffecad,0x77fffe41,0x2a2ffffe,0xfff82fff,0x30fffc85,
    0x20007fff,0x02ffffc9,0xf880fffa,0xfff884ff,0x17ffffb4,0x3fffe600,
    0x3ffeafff,0xfffffff9,0x7ecdffff,0x7fff43ff,0x2ffff404,0x83fffb00,
    0x0004fff9,0x3fffea00,0x300effff,0xfffffffd,0xffff881d,0x3fffdfff,
    0x7ffffec4,0x7fd43fff,0x85fff82f,0xff30fffc,0xc880007f,0x3ffa02ff,
    0x13ffe203,0x7ed3ffe2,0xfd30002e,0x3ffa3dff,0xffffff93,0x2edfffff,
    0xff986fff,0x3fee01ff,0x0000001f,0x32600000,0x803efffe,0xbdffffd8,
    0xffffd500,0x5c1bff67,0x82effffe,0xff82fffa,0x0fffc85f,0x0007fff3,
    0x33100d40,0x27ffc401,0x1ba7ffc4,0x01310000,0x00000000,0x00000000,
    0x20000000,0x31000098,0x004c4001,0x00133100,0x00000000,0x00000000,
    0x00000000,0x00000000,0x00000000,0x00000000,0x00000000,0x00000000,
    0x00000000,0x00000000,0x00000000,0x00000000,0x00000000,0x00000000,
    0x80cc8000,0x3312ccc8,0x42666213,0x00001998,0xd10aeee2,0xc8dddddd,
    0x222222cc,0x88888888,0x00000088,0x00000000,0x00000000,0x00000000,
    0x80000000,0xfffffffe,0xf04fffff,0x7fff101f,0x7e4fffee,0x3fffb2ff,
    0x02dffda8,0x07ffdc91,0xfffffff1,0xff34fff8,0xffffffff,0x000fffff,
    0x00000000,0x00000000,0x00000000,0x00000000,0xfffffd00,0x9fffffff,
    0x8844ff14,0xfff73fff,0x6cbfff27,0x3ff21fff,0xabdfffff,0x27fdc5fc,
    0xfffffff1,0xff34fff8,0xffffffff,0x000fffff,0x00000000,0x00000000,
    0x00000000,0x00000000,0xfffffd00,0x9fffffff,0x2bfabbe6,0x7fff13fd,
    0x7e4fffee,0x3fffb2ff,0x3fffffe2,0x5fffffff,0xdd10ffc8,0xff8ddddd,
    0x5555514f,0x55555555,0x00000055,0x00000000,0x00000000,0x00000000,
    0x50000000,0x55555555,0x3ea35555,0x5fffffff,0xfffb97dc,0x365fff72,
    0x9df10fff,0xffffff97,0x02aa07ff,0x00000000,0x00000000,0x00000000,
    0x00000000,0x00000000,0x00000000,0x0aeffd98,0xfff30fe8,0x5c3ffea3,
    0x4c1627ff,0x002dfffc,0x00000000,0x00000000,0x00000000,0x00000000,
    0x00000000,0x26200000,0x99999999,0x7fcc0999,0x27f442ff,0x7fc4fff1,
    0x001bfea7,0x00000002,0x00000000,0x00000000,0x00000000,0x00000000,
    0x00000000,0x7fffff40,0x4fffffff,0x3feaffe6,0x32e0fe21,0x9911e644,
    0x00000005,0x00000000,0x00000000,0x00000000,0x00000000,0x00000000,
    0x7ff40000,0xffffffff,0xe9be64ff,0x0000042f,0x00000000,0x00000000,
    0x00000000,0x00000000,0x00000000,0x00000000,0xfffd0000,0xffffffff,
    0x0221889f,0x00000000,0x00000000,0x00000000,0x00000000,0x00000000,
    0x00000000,0x00000000,0x33333310,0x01333333,0x00000000,0x00000000,
    0x00000000,0x00000000,0x00000000,0x00000000,0x00000000,0x00000000,
    0x00000000,0x00000000,0x00000000,0x00000000,0x00000000,0x00000000,
    0x00000000,0x00000000,
};

static signed short stb__arial_bold_30_usascii_x[95]={ 0,2,1,0,0,1,1,1,1,0,0,1,1,0,
1,-1,1,2,0,1,0,1,1,1,1,0,2,2,1,1,1,1,0,0,1,1,1,1,1,1,1,1,0,2,
2,1,1,1,1,1,1,0,0,1,-1,0,0,-1,0,1,-1,0,1,-1,0,0,1,1,1,0,0,1,1,1,
-2,1,1,1,1,1,1,1,1,0,0,1,0,0,0,0,0,0,2,0,0, };
static signed short stb__arial_bold_30_usascii_y[95]={ 24,4,4,4,3,4,4,4,4,4,4,7,20,15,
20,4,4,4,4,4,4,5,4,5,4,4,10,10,7,9,7,4,4,4,4,4,4,4,4,4,4,4,4,4,
4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,26,4,9,4,9,4,9,4,9,4,4,
4,4,4,9,9,9,9,9,9,9,5,10,10,10,10,10,10,4,4,4,11, };
static unsigned short stb__arial_bold_30_usascii_w[95]={ 0,5,11,15,14,22,18,5,8,8,10,14,5,9,
5,9,13,9,14,13,15,14,13,13,13,14,5,5,14,14,14,15,27,20,18,18,18,16,15,19,17,5,13,18,
14,20,17,19,16,20,19,17,16,17,19,26,18,19,16,8,9,8,14,17,7,15,15,14,14,14,10,14,14,5,
8,14,5,22,14,15,15,14,10,14,9,14,15,21,15,15,13,10,4,10,15, };
static unsigned short stb__arial_bold_30_usascii_h[95]={ 0,20,8,21,24,21,21,8,26,26,10,15,9,4,
4,21,21,20,20,21,20,20,21,19,21,21,14,19,15,11,15,20,26,20,20,21,20,20,20,21,20,20,21,20,
20,20,20,21,20,22,20,21,20,21,20,20,20,20,20,26,21,26,11,4,5,16,21,16,21,16,20,21,20,20,
26,20,20,15,15,16,21,21,15,16,20,15,14,14,14,20,14,26,26,26,7, };
static unsigned short stb__arial_bold_30_usascii_s[95]={ 137,188,33,157,101,204,227,45,37,1,16,
112,27,75,85,246,103,36,62,1,129,185,89,218,30,15,247,248,97,1,142,
46,64,164,145,198,110,93,77,178,200,250,60,1,233,212,194,137,171,116,151,
132,134,150,99,72,53,33,16,92,168,55,240,91,67,32,44,48,117,17,233,
74,1,217,46,119,244,63,127,1,188,173,86,232,223,157,202,218,186,20,172,
26,21,10,51, };
static unsigned short stb__arial_bold_30_usascii_t[95]={ 23,50,109,1,1,1,1,109,1,1,109,
92,109,109,109,1,28,71,71,28,71,71,28,71,28,28,71,50,92,109,92,
71,1,71,71,28,71,71,71,28,71,28,28,71,50,50,50,1,50,1,50,
28,50,28,50,50,50,50,50,1,28,1,91,109,109,92,28,92,28,92,28,
28,50,28,1,50,28,92,92,92,1,1,92,71,28,92,92,91,92,71,92,
1,1,1,109, };
static unsigned short stb__arial_bold_30_usascii_a[95]={ 119,143,204,239,239,382,310,102,
143,143,167,251,119,143,119,119,239,239,239,239,239,239,239,239,
239,239,143,143,251,251,251,262,419,310,310,310,310,287,262,334,
310,119,239,310,262,358,310,334,287,334,310,287,262,310,287,406,
287,287,262,143,119,143,251,239,143,239,262,239,262,239,143,262,
262,119,119,239,119,382,262,262,262,262,167,239,143,262,239,334,
239,239,215,167,120,167,251, };

// Call this function with
//    font: NULL or array length
//    data: NULL or specified size
//    height: STB_FONT_arial_bold_30_usascii_BITMAP_HEIGHT or STB_FONT_arial_bold_30_usascii_BITMAP_HEIGHT_POW2
//    return value: spacing between lines
static void stb_font_arial_bold_30_usascii(stb_fontchar font[STB_FONT_arial_bold_30_usascii_NUM_CHARS],
                unsigned char data[STB_FONT_arial_bold_30_usascii_BITMAP_HEIGHT][STB_FONT_arial_bold_30_usascii_BITMAP_WIDTH],
                int height)
{
    int i,j;
    if (data != 0) {
        unsigned int *bits = stb__arial_bold_30_usascii_pixels;
        unsigned int bitpack = *bits++, numbits = 32;
        for (i=0; i < STB_FONT_arial_bold_30_usascii_BITMAP_WIDTH*height; ++i)
            data[0][i] = 0;  // zero entire bitmap
        for (j=1; j < STB_FONT_arial_bold_30_usascii_BITMAP_HEIGHT-1; ++j) {
            for (i=1; i < STB_FONT_arial_bold_30_usascii_BITMAP_WIDTH-1; ++i) {
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
        float recip_width = 1.0f / STB_FONT_arial_bold_30_usascii_BITMAP_WIDTH;
        float recip_height = 1.0f / height;
        for (i=0; i < STB_FONT_arial_bold_30_usascii_NUM_CHARS; ++i) {
            // pad characters so they bilerp from empty space around each character
            font[i].s0 = (stb__arial_bold_30_usascii_s[i]) * recip_width;
            font[i].t0 = (stb__arial_bold_30_usascii_t[i]) * recip_height;
            font[i].s1 = (stb__arial_bold_30_usascii_s[i] + stb__arial_bold_30_usascii_w[i]) * recip_width;
            font[i].t1 = (stb__arial_bold_30_usascii_t[i] + stb__arial_bold_30_usascii_h[i]) * recip_height;
            font[i].x0 = stb__arial_bold_30_usascii_x[i];
            font[i].y0 = stb__arial_bold_30_usascii_y[i];
            font[i].x1 = stb__arial_bold_30_usascii_x[i] + stb__arial_bold_30_usascii_w[i];
            font[i].y1 = stb__arial_bold_30_usascii_y[i] + stb__arial_bold_30_usascii_h[i];
            font[i].advance_int = (stb__arial_bold_30_usascii_a[i]+8)>>4;
            font[i].s0f = (stb__arial_bold_30_usascii_s[i] - 0.5f) * recip_width;
            font[i].t0f = (stb__arial_bold_30_usascii_t[i] - 0.5f) * recip_height;
            font[i].s1f = (stb__arial_bold_30_usascii_s[i] + stb__arial_bold_30_usascii_w[i] + 0.5f) * recip_width;
            font[i].t1f = (stb__arial_bold_30_usascii_t[i] + stb__arial_bold_30_usascii_h[i] + 0.5f) * recip_height;
            font[i].x0f = stb__arial_bold_30_usascii_x[i] - 0.5f;
            font[i].y0f = stb__arial_bold_30_usascii_y[i] - 0.5f;
            font[i].x1f = stb__arial_bold_30_usascii_x[i] + stb__arial_bold_30_usascii_w[i] + 0.5f;
            font[i].y1f = stb__arial_bold_30_usascii_y[i] + stb__arial_bold_30_usascii_h[i] + 0.5f;
            font[i].advance = stb__arial_bold_30_usascii_a[i]/16.0f;
        }
    }
}

#ifndef STB_SOMEFONT_CREATE
#define STB_SOMEFONT_CREATE              stb_font_arial_bold_30_usascii
#define STB_SOMEFONT_BITMAP_WIDTH        STB_FONT_arial_bold_30_usascii_BITMAP_WIDTH
#define STB_SOMEFONT_BITMAP_HEIGHT       STB_FONT_arial_bold_30_usascii_BITMAP_HEIGHT
#define STB_SOMEFONT_BITMAP_HEIGHT_POW2  STB_FONT_arial_bold_30_usascii_BITMAP_HEIGHT_POW2
#define STB_SOMEFONT_FIRST_CHAR          STB_FONT_arial_bold_30_usascii_FIRST_CHAR
#define STB_SOMEFONT_NUM_CHARS           STB_FONT_arial_bold_30_usascii_NUM_CHARS
#define STB_SOMEFONT_LINE_SPACING        STB_FONT_arial_bold_30_usascii_LINE_SPACING
#endif

