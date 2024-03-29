// Font generated by stb_font_inl_generator.c (4/1 bpp)
//
// Following instructions show how to use the only included font, whatever it is, in
// a generic way so you can replace it with any other font by changing the include.
// To use multiple fonts, replace STB_SOMEFONT_* below with STB_FONT_times_25_usascii_*,
// and separately install each font. Note that the CREATE function call has a
// totally different name; it's just 'stb_font_times_25_usascii'.
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

#define STB_FONT_times_25_usascii_BITMAP_WIDTH         256
#define STB_FONT_times_25_usascii_BITMAP_HEIGHT         84
#define STB_FONT_times_25_usascii_BITMAP_HEIGHT_POW2   128

#define STB_FONT_times_25_usascii_FIRST_CHAR            32
#define STB_FONT_times_25_usascii_NUM_CHARS             95

#define STB_FONT_times_25_usascii_LINE_SPACING          16

static unsigned int stb__times_25_usascii_pixels[]={
    0x44028013,0x05002602,0x266661cc,0xbcca9800,0x00c40001,0x10099998,
    0x40062000,0x18006200,0x20102200,0x00010008,0x00080002,0x08180054,
    0xc8001b88,0x4c0ae201,0x2200b985,0x447f601c,0x2a04fccc,0x12ea21bd,
    0xfdded880,0x99df102e,0x44003605,0x02eecced,0xdabb8bf3,0x3f3b203f,
    0x4341d804,0x2cc05ccd,0x5d9db100,0x26e75400,0x36e20680,0x44abdece,
    0x90003ffb,0x5981e805,0x00ec00f8,0x904f80e6,0x70091007,0x109f507f,
    0x3b6e207f,0x7f700cee,0xff709f50,0x20ff2254,0x1a037c4d,0x0fe6c8b3,
    0xbd1000d8,0x1f88034c,0x2093017a,0x7dc40df9,0x0003fb85,0x426401d1,
    0x36035459,0x44f80003,0x322002e8,0x5c09f500,0xf81fc44f,0x2a0fa6b2,
    0x513ea04f,0x3e62ecdf,0x3ea0fcc6,0x43b8d102,0x1dc17a4f,0x7c47f500,
    0x7d46e801,0x3e207201,0x2a16e00e,0x16e0003f,0x6c5987d8,0x0003ea07,
    0x007b13e0,0x1ff10710,0x3e21fe80,0x3c967a83,0x3a007fc4,0x7d9be61f,
    0xf83e47f8,0x21c89306,0x261f24f8,0x51fdc005,0x887f700d,0x3a21a05f,
    0xfa85800f,0x0be60003,0x362cc3f4,0x400bd00f,0x2d49f009,0x43513730,
    0xd805fc84,0x360fe26f,0x321ccb0f,0x26fb805f,0xf10e65f8,0x1fd06e8d,
    0x266f2662,0x49f109e9,0x4000e86d,0x005d36fa,0x01ff03f9,0x00df5093,
    0x018fea0a,0x0df06f80,0x981fc8b3,0x1feb803f,0x440f49f0,0x243f953d,
    0x7dc027f4,0xf707f10f,0x07fd016b,0x27c1ff50,0x0ff07ee0,0x7e6547fa,
    0x23cfcccc,0x05913a5e,0x1b9ff100,0xfd133326,0x3903fd01,0x4000bf90,
    0x3fffabfa,0x26c1fa00,0x641ee2cc,0x1fe8802f,0x6c1e69f0,0xf06a37c3,
    0x3ff5007f,0x3fe20fe2,0x01ffc05d,0x07f0ffcc,0x82fc84e8,0x24c680fe,
    0x30fc47cc,0x37ec000b,0x07fc1fe4,0xe83417ec,0x3ea0003f,0x04ffc9ce,
    0x0b503fb0,0xfd04c8b3,0x407f2003,0x8d90d94f,0xf10dc4f8,0x5ff1005f,
    0x7fcc0fe2,0x05ff102f,0x1745ff10,0x3be60d50,0x1621be20,0x82f26077,
    0x200d40e8,0x642ffcd8,0xfb07f885,0xff884987,0x0fea0002,0xf9001ff3,
    0x4b30ae05,0x003fe039,0xb4f80fe4,0x7d41fa89,0x01ffc242,0x3f88ffc4,
    0x413ff620,0xff8803ff,0x00d80761,0x3f6f3ff2,0x00e44a84,0xcae88b20,
    0x3f27f505,0x3e207a0f,0x1c83fb07,0x0003ff88,0x0bfa0fea,0x6980ff20,
    0x3e016d66,0x03f9000f,0x1761753e,0x3fa121f6,0x10ff9803,0xbffd007f,
    0xf3009fd0,0x3880641f,0x8bf23500,0xfcccddca,0x44a803cc,0xf987f15e,
    0x1d57fe24,0x1fb03ff0,0x013fe068,0xfc83fa80,0x303fc803,0x0552cc17,
    0xfc8007f4,0x883a9f01,0x222fcc3f,0xa805fc83,0x200fe26f,0x7ec3fe8d,
    0x1c6fa805,0xf8800330,0x26ba620f,0x40099e99,0xf8fe20e8,0x3ea0fe45,
    0x17f405bf,0xd812a3f4,0x3ea0006f,0xd802fb83,0x5986982f,0x01fd81e4,
    0x53e03f90,0xfb07ea2c,0xff980d87,0xf117ec00,0x1be2b007,0xfd801ff1,
    0x20002001,0x498d01fb,0x7f307600,0x207fe3ec,0x7dc02ffd,0x00e45f83,
    0x13003ff3,0x0fd83fa8,0x4d81fd80,0xb8354598,0x03f9002f,0x7f52553e,
    0x1c87eb22,0xf9813ea0,0x2141fc45,0x13ee1f65,0x00004f98,0x5880fd40,
    0x84a801dc,0xff17a4f8,0x83fff309,0x3f513e23,0x0efc8068,0x0fea0a60,
    0x8374017e,0x7e45985f,0x9002fa81,0x3453e03f,0xf31bbff1,0xc81c5b57,
    0x885e982f,0xd960e83f,0xf307f904,0xf109f309,0x80bea00d,0x4400e44a,
    0x17c57a06,0x2e233fee,0xdacffeae,0x87d07d41,0x3df9003a,0x17ea0750,
    0x7f1001d7,0xb1661fa0,0x4013a01f,0x749f01fc,0x3950b260,0x37a60398,
    0xf102edbb,0xf9ac9d07,0x2f3ba601,0x0bf302ed,0x5dc40df3,0x1a15c00b,
    0x3f300ec0,0xfec881d7,0x3ff624ff,0x7b7b503f,0x75400390,0x402dddff,
    0x00decefb,0x1f601f70,0x4c0fd166,0x201f9007,0x80016a4f,0xfffb800d,
    0x2e0fe201,0x00ccecfe,0x00400660,0x0004c011,0x28802813,0x9802b880,
    0x0c006201,0x0cc00050,0x0004c400,0x985c80ba,0x0b2035c5,0x44f81f20,
    0x01c8005c,0x403ffe60,0x166203f8,0x00000000,0x00000000,0x00000000,
    0x00000000,0x3b800000,0x22cc0ec0,0x40744078,0x84f81760,0x03b1005c,
    0x01df9100,0x009007f1,0x00000000,0x00000000,0x00000000,0x00000000,
    0x00ee0000,0x2e166095,0xf9064403,0x55441d17,0x59b504fa,0x000cc981,
    0x10e75c40,0x000355bf,0x00000000,0x00000000,0x00000000,0x00000000,
    0x00cc0000,0x2048802a,0xdb31400a,0xaaaa8819,0x6e654401,0x800000bc,
    0x2aaaa098,0x00000001,0x00000000,0x00000000,0x00000000,0x00000000,
    0x00000000,0x00000000,0x00000000,0x00000000,0x00000000,0x00000000,
    0x00000000,0x00000000,0x26001880,0x80070209,0x00100408,0x00600aa0,
    0x2a80bb98,0x0002a000,0xa8044000,0xfffd8002,0x2001cc4f,0x26188000,
    0x2effea80,0x417fffb3,0x3ae4ffc8,0xe980dfff,0x400205ff,0x2e201bdb,
    0x5bddccdd,0x3ae200e4,0x442ccedd,0x801ccbcb,0xfb104fea,0x9ac805ff,
    0x09fd52fe,0xed9bc880,0x5dff53cc,0xf9804fb8,0x002ff543,0x03ffffe6,
    0x12e003fb,0xf9bfd980,0x7fc40cff,0x3605fe83,0x880bfd03,0x809d503f,
    0xee8804e8,0x24c7e980,0x5fb03b20,0x803544c8,0xb57b04f9,0x896e01ff,
    0x0013e64e,0x21aff8bb,0x006985fa,0x0bf307fd,0x39800d80,0x9801fa00,
    0xffb9ccfc,0xfa84fc84,0x7d403e06,0x5c434c07,0x13e604fe,0x3e602f40,
    0x05f10340,0x441f88ba,0x84f9802f,0xe81fe40b,0x0027cc05,0x81fd87f1,
    0x401640fe,0x5f883fdc,0x00012600,0x800bfe60,0x07fcc5fa,0x3fe21fe6,
    0x7fc05980,0xf980b201,0x6c01ba04,0x640c801f,0x2e05f702,0x0fe0bea2,
    0x4c013e20,0x8809f03f,0x13ea004f,0x89f505f7,0x3faca806,0x36005f88,
    0x00000bdf,0x5400dfbb,0xe82fd83f,0xc83fe82f,0xd02fdc02,0xf904f980,
    0x00bf5003,0x2a093022,0x221881ef,0x403ea0ff,0x004f88a8,0x09f101f5,
    0x80664f88,0xd036c6f8,0xd1012a1f,0xbf107f51,0x3fffe600,0x1002a01f,
    0x54007fed,0xb83fc83f,0x437fc44f,0x80ff8806,0x427c404a,0x201516f9,
    0x340003fc,0x803ffe88,0x80e99efc,0x4fdcadd8,0xcc883b00,0xf880ccef,
    0x205ffe8c,0x405f32fb,0xd801b3fa,0xbf107f51,0x4c15ff44,0x2e22ffea,
    0xb9e400fe,0x07f5005f,0x8ff105f7,0x1661ffbb,0x0f427ec0,0x3ee13e20,
    0x40cfdcbd,0x266202fe,0x9815c199,0x6402efff,0x89d00eff,0x76c404fc,
    0x8809f101,0x05fb0cef,0x4005666c,0x254059fe,0x4bf107f5,0xffb000e9,
    0x2007f441,0x001ff10e,0x03fb07f5,0xfc8e8bfa,0x7cc00b24,0x7c4034c7,
    0x7e43fd84,0x980bfe23,0x24c2effc,0x1bfff910,0x5c1fff40,0x3027cc0f,
    0xf105fffb,0x545f8809,0x0003b03f,0x2c405ff7,0x57e20fea,0x7ec000d9,
    0x95007ec2,0xfa803fd8,0x3ee06f84,0x69be6d15,0x591ff400,0xfd09f100,
    0x3e26f881,0x03ff804f,0xfffd300d,0x9ff75b01,0x04f886f8,0x9f10ff90,
    0x7cc4f880,0xaccdf984,0x407f802a,0x441fd40d,0x8000dadf,0x007e43fa,
    0x806f981d,0x00fcc6fa,0x74771ff1,0x5400499f,0x7c401a6f,0xff80ff84,
    0x3a017fe1,0x2005702f,0x526c6ffb,0x217e23ff,0x3f6004f8,0x22027c41,
    0x4427c44f,0xeffffffd,0xeb813200,0xcefdcccc,0x03bf7e21,0x3f217c00,
    0xddddf300,0xfa805ffd,0x801fcbdd,0x3f20eafd,0xff8002cc,0x9f1004a9,
    0x3fb01fb0,0x7f403fe4,0x00a8b301,0x07e61ff5,0x21be69f5,0x3ea004f8,
    0x22027c41,0x4827c44f,0x8136a666,0x3fff200e,0x23ffffff,0x005fadf8,
    0x07e40f88,0x0bf702d8,0x0198bfa8,0xf317bea0,0x3ee000df,0x9f1000ed,
    0x8d905f90,0x7f402ff8,0x40571a01,0xd01f71fd,0xf103fe2d,0x44354009,
    0x227c404f,0x202d84f8,0x000b3039,0x57e20fea,0x264004fc,0x034407e4,
    0x7d401ff1,0x0bfe0003,0x440013fa,0x3e2005ff,0x4f84f884,0x3a01ffb8,
    0x5b8ae01f,0x17cc3fa0,0x887fd1e4,0x20f2005f,0x27c405f8,0x09f313e2,
    0x03a2662c,0x441fd400,0x360bfa5f,0x320b912e,0x6403c80f,0x00fea05f,
    0xfb80fc80,0x0bf60001,0xf704f880,0xfa807cc3,0x403fd01f,0x2a13ee58,
    0x3e22f43f,0x2633fe60,0x2f209efd,0x3e603aa0,0x262fcc06,0xcdffd85f,
    0x3fe61edb,0x3ea0002f,0x3e25f983,0x77ffdc1f,0xf307f603,0x01ffa803,
    0x540009f5,0x8000f105,0x2fcc0079,0x01d97b50,0xcbceed88,0x2e6802df,
    0x3fecdfdc,0x1bbbed88,0xfaefffa8,0x76ffec2e,0x59ffd704,0x517ffb50,
    0xb7107ffb,0x0b72079d,0xa87f5000,0xff98bffd,0x1004c0bf,0x3ee3dff7,
    0xffd703ef,0xbdedb89f,0x0c030000,0x7000c000,0x44039ffd,0x03330000,
    0xa9810980,0x26003001,0x04c40310,0x00000000,0x00000000,0x00000000,
    0x00000000,0x00000000,0x00000000,0x00000000,0x00000000,0x00000000,
    0x00000000,0x00000000,0x00000000,0x00000000,0x3ff6a000,0x7f5c41df,
    0x400b983f,0x18a62000,0x3bfff950,0x403fff22,0x743efeb8,0x1fffffff,
    0xbdffffb3,0x6ffca839,0x477ffa00,0x0cdfffc9,0x67ffe4c0,0x077ffae2,
    0xddffffb3,0xffc98079,0x3ff262df,0x3ffe22df,0x4fffffff,0x3bbfff26,
    0xf933fffe,0xffddddff,0xffffd98f,0x000bdeef,0x1f3013fe,0x980ffc88,
    0x6402dffc,0x404efcbe,0xdfd105fd,0x7cc3cc01,0x87eeeeef,0x7ff515fd,
    0x3003ffb0,0x1bf209ff,0x6c17f200,0x527e401e,0xfc801dfb,0x221bee05,
    0x01df701e,0x87b109f9,0x20d105fc,0x3ee60dfc,0x07fb002f,0x03f60788,
    0x0fffaf7e,0x013ee274,0x7fd409f9,0x0b61a205,0x227dc26c,0x7fdc0ff9,
    0x03ffd805,0xf7000bf7,0x7001d709,0x807ff09f,0x17ee04fb,0x0ffcc0a6,
    0x89104fb8,0x202e05fb,0x7fd104fb,0x8805fb00,0x5503f606,0x0fb86fa8,
    0x3f2027cc,0x0fff6a03,0x3f014344,0x7ff09f70,0x200ffbb8,0xf503fce9,
    0x89f7000b,0x9f7000ea,0xfb80df90,0x2617ea04,0x5c09fd00,0xbf50204f,
    0x04fb8040,0xfb00bfe6,0x32068805,0x2fe81c0f,0x027c437c,0xaca80ff2,
    0x006882ff,0x427dc1ea,0x7e5dc4fe,0x0ff2b204,0x5c002fd4,0x8003aa4f,
    0x06fc84fb,0xbf5027dc,0x2037e400,0xf50084fb,0x4fb8060b,0x36027ec0,
    0x9034402f,0x87ee001f,0x04f885f8,0x29501fe4,0x03441ffb,0x13ee0990,
    0x8bb83ff1,0xf96880ff,0x0017ea07,0x0075d3ee,0xff113ee0,0x204fb807,
    0xff3005fa,0x484fb803,0x8160bf50,0x3fd404fb,0xd100bf60,0xc8007e40,
    0x7c437cc7,0x501fe404,0xd1077ec9,0xfb80fc00,0x9dc37e44,0xf93c84fc,
    0x0017ea07,0x003ef3ee,0xfd893ee0,0x027dc00c,0xff100bf5,0x33bf7007,
    0x37ea0b93,0x205ca999,0x7fcc04fb,0x100bf600,0x8007e40d,0x207fc43e,
    0x1fe404f8,0x25fe8950,0x40f50068,0xdfebbefb,0x1ff33b80,0x207f90f8,
    0xfb8005fa,0xb8003ffe,0x00dfedef,0xddddff70,0xb00bfddd,0x3bee00bf,
    0xf505edcc,0x0bd9999d,0x3e2027dc,0x00bf602f,0x007e40d1,0x43fe82d4,
    0x1fe404f9,0x4ff88950,0x813200d1,0x00998cfb,0x2e3fd8ee,0x7d40ff24,
    0xacfb8005,0x7dc003ff,0x5c00df74,0x017ea04f,0x2e001ff5,0xfa82444f,
    0x3ee05885,0x00ffcc04,0x068805f9,0x03a003f2,0x65d77fd4,0x01fe404f,
    0x15ff3095,0xb807e00d,0x98ee004f,0x3fc83a6f,0x7000bf50,0x00ffea9f,
    0x13f64fb8,0xf5027dc0,0x017fc40b,0x20509f70,0x5c0505fa,0x07fd404f,
    0x58807f90,0x59003f20,0x8bffd980,0x01fe404f,0x2bfea095,0x5c079806,
    0xd0ee004f,0x3fc8b55f,0x7000bf50,0x01ffd49f,0x3fa24fb8,0x204fb802,
    0x17f605fa,0x4009f700,0xfb8005fa,0x2037e404,0x025404fb,0x01dc01f9,
    0x2027c430,0x812a01fc,0x4c806ffc,0x70027dc0,0x41eefa87,0x0bf503fc,
    0x227dc0a8,0xfb804ffa,0x2007fcc4,0x17ea04fb,0x170077dc,0x2a004fb8,
    0x2e05405f,0x07fe604f,0x1e80ff10,0x25403f20,0x509f1000,0x4a803f21,
    0x7c037ec0,0x0027dc01,0x90bfd077,0x017ea07f,0xf509f70b,0x84fb809f,
    0x3ee00efb,0x2617ee04,0x21a201ff,0x3ea004fb,0x3ee16205,0x009fd104,
    0x0f6217ea,0x09501f90,0x13e2002a,0x701369f7,0x406e880d,0x06fc8079,
    0x0bee1320,0x37e413f6,0x7e41f4c4,0x01bff905,0x2ff41bf2,0x7e40bf90,
    0x2604fe86,0x005fc85d,0x1ec41bee,0x7fd427e4,0x6ffdc002,0xfd803dec,
    0x66667d41,0xbf3006ed,0x204cff88,0x201cffc9,0x30264069,0x405bfff9,
    0x341cffc9,0x473fff66,0xffffffc9,0x3260ffff,0x3a61cfff,0x931dffff,
    0xf885bfff,0xff930cff,0x7fe4c59f,0xffff72cf,0x7fffffff,0x167ffe4c,
    0xddfff730,0x4c1fffdd,0xeeeffffc,0x260000bc,0x3fee0019,0xfffff52e,
    0xb5007fff,0x009817dd,0x54008000,0x00000000,0x00000000,0x00000000,
    0x00000000,0x00000000,0x00000000,0x00000000,0x00000000,0x00000000,
    0x00000000,0x00000000,0x00000000,0x00000000,0x6cc04000,0xdeeeffff,
    0xfffff881,0x0fffffff,0x3bffffb3,0x516ffecc,0x883bfffd,0xf913effc,
    0x00c47dff,0x02a20014,0x013300c4,0xa8803510,0x00530088,0x00000000,
    0x43118800,0x8620003b,0x00029819,0x27ec0910,0x4c1bfb51,0xa89fe21e,
    0x83ffcc0f,0xffd103f8,0xfb80de80,0x2200ff87,0xd79d1005,0x6c1fe81b,
    0xb103fcad,0xd885ff79,0x74c1fdab,0x3ea0cfcb,0xdffb88df,0xfea9bee1,
    0xa8fee22f,0x13faa4fd,0x7ff39fb3,0x40033b22,0xffe8dfd9,0x0fffd88f,
    0xfcccdee8,0xfb81363f,0x14c7fd04,0x202e1fe2,0x04c82ffa,0xf8817fcc,
    0xdb0df500,0x4402c401,0xd913ea2f,0x1fd07dc1,0x22fd87b0,0x1f10f43b,
    0x0fee27d4,0x986885f9,0xfa85986f,0x2e227d44,0xb81dabdf,0x7d4401de,
    0x199f90ce,0x2e1613ee,0xb813f25f,0x44df504f,0x0443fc40,0x16a0ffb8,
    0x2c837dc0,0x4001be60,0xd87c8058,0x7e47d805,0x3e207e40,0x643517a5,
    0x46f86f84,0xd815c4f9,0x7cc0e40f,0x7c427cc4,0x0bb6a006,0x37c45f88,
    0x3e61437c,0x99dfb50e,0x3ea09f70,0x003fc407,0x00e9afec,0x0b313fa0,
    0x10006f98,0x000bf00b,0xd07faa08,0x7e43fa0d,0xddddf01e,0x1fc83ddd,
    0x20683fea,0xf982c4fa,0x7c427cc4,0xbec98004,0x37c2fc40,0x3fa203f4,
    0xf7027c41,0x1013f609,0xff1000ff,0xf98003d7,0xf3003a1f,0x0162000d,
    0x70000bf1,0x7c43f95b,0x3625fb06,0x0fe20dff,0x2f64f980,0xfe80933f,
    0x13e60550,0x09f109f3,0x107f4400,0xfd0df0bf,0xf883fd80,0x4c37ee04,
    0x4400dfda,0xff50007f,0x5bee0007,0x06f9803c,0xffffffc8,0xf11fffff,
    0x1f44000f,0x07fc43f9,0x3fea17e4,0x8009f11f,0x65be937e,0x059fdc00,
    0x09f313e6,0x710009f1,0x85f8819d,0x2e07e86f,0x409f105f,0xffedeffb,
    0x07f8800e,0x0017fa00,0x3006dfe8,0x162000df,0x02a07fe0,0x41fc8dd0,
    0x30fc82fd,0x1ff2fe44,0xb5f70130,0x20167f21,0x26049ef8,0x4427cc4f,
    0x3b26004f,0x3e17e203,0xdf307e86,0xb813e201,0x04ffa84f,0x98003fc4,
    0x30002ffe,0x3e6003ff,0x00b10006,0x40388bfb,0x20fe46f8,0x165d84fb,
    0x41efc9ba,0x4c9df104,0xdf9002ef,0x2a2fc401,0x804f884f,0xf8801dda,
    0x87e86f85,0xf1381fe8,0x9827dc09,0x1fe201ff,0x3ea3a200,0x1ff0000f,
    0xf11be600,0x402c403f,0x0fcbeff8,0x35fd07ec,0x74477fdb,0x3e83a61f,
    0xbfff1174,0x0fec05f9,0x5f9801fa,0xcb8aff80,0x82fcc1ef,0x2000ceb8,
    0xf86f85f9,0x2a83fd87,0x27dc09f1,0x7c409fd0,0x361e8007,0x1ff0005f,
    0xf31be600,0x802c409f,0xe81dffe9,0x27bfaa1f,0x7ec40ef9,0x77f41ddc,
    0xffe984cb,0x5c2d402d,0x40174004,0xdf99fffa,0x033ffaa2,0xd9800177,
    0xffd98bff,0x0dffc99c,0xdddddff5,0xb817e25f,0x813fa04f,0x1e4007f8,
    0x2000bfe2,0xdf3000ff,0x2c40b310,0x08802200,0x0c400810,0x22006210,
    0x02202000,0x0c400300,0x00000031,0x00000000,0x2e05cf7c,0x03ff504f,
    0xb7003fc4,0x0003fee0,0x3ea001ff,0x02805706,0x00000000,0x00000000,
    0x00000000,0x00000000,0x40000000,0x4fc81efc,0x201ff5c4,0xfb800ff9,
    0x003bfe00,0xb8017fc4,0x0003a87f,0x00198620,0x1c880000,0x00200170,
    0x02044083,0x6eedc351,0xdddddddd,0x110054c1,0x88888880,0x77408888,
    0x00003eee,0x3fff2602,0x01cdeeef,0x0fbffee2,0x20efff54,0x04ffffc8,
    0x05f7ff5c,0x2dfffc88,0x26000033,0x5ffe8cfd,0xd34ffd98,0xed98007f,
    0x3007f102,0xfa9fd40d,0x25fb9fe4,0x266627e8,0x19999999,0x056feee4,
    0x3a25f88e,0xeeeeeeee,0x3bbba2ee,0x0000003e,0x00000000,0x00000000,
    0x44000000,0xfd88cefb,0x3a27fd02,0x077aa001,0x6457c722,0x2e079d01,
    0x3fc9f74f,0x0fc43ff9,0xb50e2000,0x7cc7b7bf,0x00000006,0x00000000,
    0x00000000,0x00000000,0x22fcc000,0x1ff103fa,0x9d710059,0x6d7fc401,
    0xd3b83fe9,0x3ea7f501,0x85731ba3,0x11111139,0x0c111111,0x01037710,
    0x00000000,0x00000000,0x00000000,0x00000000,0xf989f100,0x013bea04,
    0x44005d93,0x880bceda,0x47e216a6,0x161762f8,0xdddddb8c,0x01dddddd,
    0x00000000,0x00000000,0x00000000,0x00000000,0xf1000000,0x6c04f889,
    0x013ee03f,0x3377b260,0x40ec2d81,0x43c87e0f,0x0000002b,0x00000000,
    0x00000000,0x00000000,0x00000000,0xf1000000,0x6c04f889,0x3b2600fe,
    0x8ef9800b,0x1663fd8d,0xa8b161a2,0x000000a2,0x00000000,0x00000000,
    0x00000000,0x00000000,0x10000000,0x204f889f,0x8806f9ac,0x2e200ceb,
    0x74372f88,0x04087700,0x00000000,0x00000000,0x00000000,0x00000000,
    0x00000000,0x22000000,0xa827c44f,0xa800ff24,0x1fc401de,0x000e014c,
    0x00000000,0x00000000,0x00000000,0x00000000,0x00000000,0xf3000000,
    0x6985f98b,0x20017fc4,0x02a02ed9,0x00000000,0x00000000,0x00000000,
    0x00000000,0x00000000,0x00000000,0x3ffaa000,0x0bffea8b,0x7fd45ff5,
    0x1c88003f,0x00000000,0x00000000,0x00000000,0x00000000,0x00000000,
    0x00000000,0x00000000,0x00000000,0x00000000,0x00000000,0x00000000,
    0x00000000,
};

static signed short stb__times_25_usascii_x[95]={ 0,2,1,0,1,0,0,0,0,0,1,0,1,0,
1,0,0,2,0,0,0,1,0,0,1,0,1,1,0,0,0,1,1,0,0,0,0,0,0,0,0,0,0,0,
0,0,-1,0,0,0,0,1,0,0,0,0,0,0,0,1,0,0,0,-1,1,0,-1,0,0,0,0,0,0,0,
-2,0,0,0,0,0,-1,0,0,1,0,0,0,0,0,0,0,3,1,1,0, };
static signed short stb__times_25_usascii_y[95]={ 20,4,4,4,3,4,4,4,4,4,4,6,17,14,
17,4,4,4,4,4,4,5,4,5,4,4,9,9,7,10,7,4,4,4,5,4,5,5,5,4,5,5,5,5,
5,5,5,4,5,4,5,4,5,5,5,5,5,5,5,4,4,4,4,23,4,9,4,9,4,9,4,9,4,4,
4,4,4,9,9,9,9,9,9,9,6,9,9,9,9,9,9,4,4,4,12, };
static unsigned short stb__times_25_usascii_w[95]={ 0,4,7,11,10,19,17,4,8,7,9,13,4,7,
4,7,11,7,11,10,11,9,11,11,9,11,4,4,13,13,13,9,20,17,14,15,16,14,12,16,16,7,9,17,
14,20,17,16,12,16,16,11,14,17,17,22,17,16,14,6,7,6,11,13,4,10,12,10,12,10,10,11,12,6,
7,12,6,18,12,11,12,12,8,7,7,12,12,17,12,12,10,7,2,8,13, };
static unsigned short stb__times_25_usascii_h[95]={ 0,17,8,17,19,17,17,8,21,21,10,13,7,2,
4,17,17,16,16,17,16,16,17,16,17,17,12,15,11,5,11,17,21,16,15,17,15,15,15,17,15,15,16,15,
15,15,16,17,15,21,15,17,15,16,16,16,15,15,15,21,17,21,9,2,5,12,17,12,17,12,16,16,16,16,
21,16,16,11,11,12,16,16,11,12,15,12,12,12,11,16,11,21,21,21,4, };
static unsigned short stb__times_25_usascii_s[95]={ 252,126,163,153,98,165,185,171,29,1,141,
87,176,233,214,215,203,247,26,73,133,158,1,79,50,141,112,82,127,186,212,
131,53,175,9,223,235,220,207,13,175,74,51,140,125,104,61,109,91,74,158,
38,24,1,229,206,39,57,192,91,30,46,151,219,181,117,239,101,60,148,84,
108,95,168,38,145,19,226,101,128,193,38,203,140,1,190,177,159,114,120,245,
21,18,9,200, };
static unsigned short stb__times_25_usascii_t[95]={ 1,1,71,1,1,1,1,71,1,1,71,
58,71,71,71,1,1,23,41,23,23,23,23,41,23,1,58,58,71,71,58,
1,1,23,58,1,41,41,41,23,41,58,41,41,41,41,41,1,41,1,41,
23,58,41,23,23,58,58,41,1,23,1,71,71,71,58,1,58,23,58,23,
23,23,23,1,23,41,58,71,58,23,41,58,58,58,58,58,58,71,23,58,
1,1,1,71, };
static unsigned short stb__times_25_usascii_a[95]={ 90,120,147,181,181,301,281,65,
120,120,181,204,90,120,90,100,181,181,181,181,181,181,181,181,
181,181,100,100,204,204,204,160,333,261,241,241,261,221,201,261,
261,120,141,261,221,321,261,261,201,261,241,201,221,261,261,341,
261,261,221,120,100,120,169,181,120,160,181,160,181,160,120,181,
181,100,100,181,100,281,181,181,181,181,120,141,100,181,181,261,
181,181,160,173,72,173,195, };

// Call this function with
//    font: NULL or array length
//    data: NULL or specified size
//    height: STB_FONT_times_25_usascii_BITMAP_HEIGHT or STB_FONT_times_25_usascii_BITMAP_HEIGHT_POW2
//    return value: spacing between lines
static void stb_font_times_25_usascii(stb_fontchar font[STB_FONT_times_25_usascii_NUM_CHARS],
                unsigned char data[STB_FONT_times_25_usascii_BITMAP_HEIGHT][STB_FONT_times_25_usascii_BITMAP_WIDTH],
                int height)
{
    int i,j;
    if (data != 0) {
        unsigned int *bits = stb__times_25_usascii_pixels;
        unsigned int bitpack = *bits++, numbits = 32;
        for (i=0; i < STB_FONT_times_25_usascii_BITMAP_WIDTH*height; ++i)
            data[0][i] = 0;  // zero entire bitmap
        for (j=1; j < STB_FONT_times_25_usascii_BITMAP_HEIGHT-1; ++j) {
            for (i=1; i < STB_FONT_times_25_usascii_BITMAP_WIDTH-1; ++i) {
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
        float recip_width = 1.0f / STB_FONT_times_25_usascii_BITMAP_WIDTH;
        float recip_height = 1.0f / height;
        for (i=0; i < STB_FONT_times_25_usascii_NUM_CHARS; ++i) {
            // pad characters so they bilerp from empty space around each character
            font[i].s0 = (stb__times_25_usascii_s[i]) * recip_width;
            font[i].t0 = (stb__times_25_usascii_t[i]) * recip_height;
            font[i].s1 = (stb__times_25_usascii_s[i] + stb__times_25_usascii_w[i]) * recip_width;
            font[i].t1 = (stb__times_25_usascii_t[i] + stb__times_25_usascii_h[i]) * recip_height;
            font[i].x0 = stb__times_25_usascii_x[i];
            font[i].y0 = stb__times_25_usascii_y[i];
            font[i].x1 = stb__times_25_usascii_x[i] + stb__times_25_usascii_w[i];
            font[i].y1 = stb__times_25_usascii_y[i] + stb__times_25_usascii_h[i];
            font[i].advance_int = (stb__times_25_usascii_a[i]+8)>>4;
            font[i].s0f = (stb__times_25_usascii_s[i] - 0.5f) * recip_width;
            font[i].t0f = (stb__times_25_usascii_t[i] - 0.5f) * recip_height;
            font[i].s1f = (stb__times_25_usascii_s[i] + stb__times_25_usascii_w[i] + 0.5f) * recip_width;
            font[i].t1f = (stb__times_25_usascii_t[i] + stb__times_25_usascii_h[i] + 0.5f) * recip_height;
            font[i].x0f = stb__times_25_usascii_x[i] - 0.5f;
            font[i].y0f = stb__times_25_usascii_y[i] - 0.5f;
            font[i].x1f = stb__times_25_usascii_x[i] + stb__times_25_usascii_w[i] + 0.5f;
            font[i].y1f = stb__times_25_usascii_y[i] + stb__times_25_usascii_h[i] + 0.5f;
            font[i].advance = stb__times_25_usascii_a[i]/16.0f;
        }
    }
}

#ifndef STB_SOMEFONT_CREATE
#define STB_SOMEFONT_CREATE              stb_font_times_25_usascii
#define STB_SOMEFONT_BITMAP_WIDTH        STB_FONT_times_25_usascii_BITMAP_WIDTH
#define STB_SOMEFONT_BITMAP_HEIGHT       STB_FONT_times_25_usascii_BITMAP_HEIGHT
#define STB_SOMEFONT_BITMAP_HEIGHT_POW2  STB_FONT_times_25_usascii_BITMAP_HEIGHT_POW2
#define STB_SOMEFONT_FIRST_CHAR          STB_FONT_times_25_usascii_FIRST_CHAR
#define STB_SOMEFONT_NUM_CHARS           STB_FONT_times_25_usascii_NUM_CHARS
#define STB_SOMEFONT_LINE_SPACING        STB_FONT_times_25_usascii_LINE_SPACING
#endif

