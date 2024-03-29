// Font generated by stb_font_inl_generator.c (4/1 bpp)
//
// Following instructions show how to use the only included font, whatever it is, in
// a generic way so you can replace it with any other font by changing the include.
// To use multiple fonts, replace STB_SOMEFONT_* below with STB_FONT_consolas_27_usascii_*,
// and separately install each font. Note that the CREATE function call has a
// totally different name; it's just 'stb_font_consolas_27_usascii'.
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

#define STB_FONT_consolas_27_usascii_BITMAP_WIDTH         256
#define STB_FONT_consolas_27_usascii_BITMAP_HEIGHT        104
#define STB_FONT_consolas_27_usascii_BITMAP_HEIGHT_POW2   128

#define STB_FONT_consolas_27_usascii_FIRST_CHAR            32
#define STB_FONT_consolas_27_usascii_NUM_CHARS             95

#define STB_FONT_consolas_27_usascii_LINE_SPACING          18

static unsigned int stb__consolas_27_usascii_pixels[]={
    0x26000395,0x00000000,0x20000188,0xdca803d9,0x1f44002c,0x0006a600,
    0x0e5cb2a0,0x100f3200,0x65c62355,0x00980001,0xb80f76a0,0x1002661c,
    0x0055e413,0x00aa8831,0x3e7f9799,0x3e600cef,0x3fffe606,0x3b6201ff,
    0x43fa206f,0x07fffffb,0x2205fff0,0x0effeffd,0x2009f500,0x0dfffffc,
    0x2a3fd000,0x2ffc005f,0xffffffb8,0x0005fd4f,0x0fffff62,0x0bffff90,
    0x05fe8df5,0xffff27f4,0xd13fd03b,0xff05ffff,0x3ff67f9d,0xbff100ff,
    0x3fbbba20,0xffff301f,0xf737f409,0x200ddddf,0xff882fff,0x01df710b,
    0xe8807f90,0xeffeceff,0x237d4000,0x3fe001ff,0xcbdffd85,0x05fd4ffd,
    0x3f7ffa00,0x2df103ff,0x3fa21fe8,0x9807fdc1,0x3f72a1ff,0x7dff42ff,
    0x41ffecdf,0x543fcdff,0x3fea04ff,0x203fd004,0x7ec01efd,0x0017ee0f,
    0x2fe82754,0x3ae07f90,0x906fffff,0x5ff983ff,0x3217ec00,0x17fe004f,
    0x9f903ff7,0x2e000bfa,0x41ff60ff,0xc8fee3fa,0x03ff883f,0x7ec40df9,
    0x07bffa1f,0xcdfe8bfd,0x406fc83f,0xfe801ffc,0xa805ff01,0x02fdc2ff,
    0x027e4000,0xfffd11be,0xf10ffdff,0x07fea05f,0x7c43fc40,0x8bfd000f,
    0x29f903fe,0xfc8002fe,0x5c07fcc5,0x7ccfea3f,0x7c1bf206,0x2ff4403f,
    0xff501ffd,0x1fe67f41,0x7f403fcc,0x881fe806,0x2ff400ff,0x26202fdc,
    0x41999999,0x1fd806f8,0x33f4bbfa,0xff80df90,0x209f9004,0x9fd003fd,
    0x9f903fcc,0x0aa88bfa,0xff317f60,0x1fd97ea0,0x7fcc03fd,0x4007fcc1,
    0x40ffa7fc,0x33f61ff8,0x07f883fc,0x7402ff98,0x407f881f,0x5fb80efb,
    0x7ffffec0,0x41fdc7ff,0x7ccbee20,0xfd01be2f,0x006fc807,0x1bea01ff,
    0xdf527f40,0xafea7e40,0x02ffffe8,0x27f41ff7,0x2dfbdfd0,0x4fe804fc,
    0xfa802fe4,0x7c05fd0f,0x3f26ea2f,0x9007f883,0x81fe80bf,0x1ffc07f8,
    0x65c05fb8,0x47fdcccc,0xdffb10fe,0x3ea7f53f,0xf80bf11f,0x03fdc02f,
    0x3fa02fd4,0x2e4fe801,0x753f206f,0xfecdffcf,0x9cff881f,0x36200efe,
    0x06f98cff,0x7fc1ff70,0x74ff7002,0x40bfe02f,0x07f883fc,0x7401ff70,
    0x207f881f,0xbf701ff9,0x89fe6000,0x3f77fa5f,0xff13f98f,0xf8813e69,
    0x03fd401f,0x3ee017f4,0x2e4fe805,0x753f206f,0x2ff41eff,0x0dffffb8,
    0x003fd000,0x3fd4bfe2,0xd27fdcc0,0x07fe205f,0x0ff81fe4,0x203ff980,
    0x05f981fe,0x5fb81ff2,0x54ff3000,0x3e2bf54f,0x7fec9f37,0x3e603fce,
    0x07fd401f,0xf100df30,0x23fd801f,0x9fd107fa,0x3ea03ffa,0x3fffb80f,
    0x013ee000,0x13f6df90,0x45ffffd8,0x0ff302fe,0x3fd81fe4,0x7409ff00,
    0x203fc81f,0x17ee06fd,0xf93fcc00,0xafccbf65,0x7ffe44f9,0x3ff100cf,
    0x6c07fa80,0x07f9003f,0x3fe63fd8,0xfd4ffd81,0x907fe207,0x741dffff,
    0x07fcc03f,0x3e7fe600,0x2fbf201f,0xfb02fe81,0x981fe40b,0x3a02cdfe,
    0x5c7fa05f,0x3a00dfdc,0x017ee04f,0x3f93fcc0,0x9a7dc3fe,0xfffd983f,
    0x805ff04f,0x3fe206fb,0x80ff3000,0x137f43fd,0x3fa9fdfb,0xfa8bfe02,
    0x3e5ff99f,0xa97f402f,0xefe801cc,0x01fe406f,0x1ff907fd,0x3a01fe40,
    0x1bf205ff,0xbffd1fe8,0x5c05ff00,0xff30005f,0x937c47ec,0xe80fea7f,
    0x7c0effff,0x02fec04f,0xfd8009f7,0xf30ff602,0xf77ffdff,0xff80bfa9,
    0xffa8ffa2,0x2e01ff8c,0x7ffffb5f,0x02fffb80,0xffd01fe4,0x05fffddd,
    0xff303fc8,0x37e40357,0x36aa3fd0,0x0bfe01ef,0x30005fb8,0x7cc7f4ff,
    0x17dcbf66,0x17feeff0,0x7fc40dfb,0x0007fe02,0x1fec0df5,0xc977ff4c,
    0x2205fd4f,0x83ff11ff,0x207fdffc,0x8dfa8ff8,0x3e200ff9,0x03fc807f,
    0x3bfffffa,0x03fc800d,0x3f6005fb,0x3207fa05,0x813fa04f,0xf30005fb,
    0x26f9bf4f,0x201fb1fe,0x31fee6f8,0x1bf205ff,0xf0006fa8,0x0440003f,
    0x817f53f2,0x07fe67f9,0xd813fff6,0x7ec5f92f,0x00ffe201,0x0197f400,
    0xff03fc80,0xd027fc00,0x40df303f,0x17ee06fd,0xfb3fcc00,0x47fd5be1,
    0x97e605f8,0x7ff40ffa,0x05ff910a,0xb80017ec,0x2000604f,0x205fd4fc,
    0x41ffc5fd,0xf502ffe8,0x3f90fe4b,0x8007fec0,0x0017f401,0xff107f90,
    0x80bfe600,0x07f881fe,0x7dc03ff2,0x4ff30005,0x9fbfd0fc,0x5403fdbf,
    0x221ff64f,0xfffefffe,0x001fe603,0x7440ff88,0xa7e4005f,0x0ffb83fe,
    0xfb317fec,0x1ff10dff,0x01fd1fdc,0x7400bfee,0x00bfa05f,0xf883fc80,
    0x01ff5007,0x3fc40ff4,0x2e03ff30,0xff30005f,0x4fe98fe4,0x9ba87ffb,
    0xffdabfb9,0xfffd9103,0x03fc805b,0x2a1fec00,0x7e4007ff,0xfddfffd4,
    0xfff105ff,0xffbfffdf,0x7c43fd89,0x3225fdcf,0x3004ffec,0x3fa01fff,
    0x0ff20002,0x7e401fe2,0x440ff405,0x81ff407f,0xf30005fb,0x1021fdcf,
    0x3ffffee0,0xb004ffff,0x1ff1007f,0x46f98000,0x64005fe8,0xffff934f,
    0x7e4401bd,0xff91dfff,0x7d417ea7,0x3fe60dff,0x7f4002ff,0x000bfa05,
    0x7f883fc8,0x401ff980,0x07f881fe,0x7dc07fdc,0x4ff70005,0x930006f8,
    0x19bfffdd,0x403fdc00,0xd00005fb,0x3000305f,0x40002035,0x04000008,
    0x0001aa88,0x00155006,0x7c41fe40,0x805fe807,0x07f881fe,0x5fb85fe8,
    0xe8dfb000,0x7e80000f,0x3bfe2000,0x3fa1fbab,0xbf700001,0x00000000,
    0x00000000,0x00000000,0x20ff2000,0x7fe406fb,0xf01fe800,0x3ffa805f,
    0x4c002fdc,0x077d43ff,0x001be000,0xffffff50,0x00017a67,0xed981db0,
    0x9103302d,0x2ee04079,0xbbbbbbbb,0x3312bbbb,0x00133333,0x00000000,
    0x741fe400,0x0ffea05f,0xfe80ff40,0x21ffd805,0x37e605fb,0x906ffebb,
    0xf95337df,0x005f8801,0x1bdcb880,0x30000000,0x989fffff,0x8bff306f,
    0x3ffe5fe9,0xffffffff,0xfff76fff,0x0005ffff,0x00000000,0xfda9fe40,
    0x9ff101ff,0x3eaaaa20,0x9fff501f,0xb877f405,0x262aaaef,0x0dffffff,
    0x3ffffee0,0x009800df,0x00000000,0x4efec000,0x17ee4ffb,0x3f65fd88,
    0x555552ff,0x55555555,0x3bbbaa55,0x00002eee,0x00000000,0x77ffcff2,
    0x9817e602,0x01ffffff,0x881bffee,0xffff70ee,0xabaa88ff,0x26aa6000,
    0x00000000,0x00000000,0xdff50ffc,0x77005ffb,0x00bfff63,0x00000000,
    0x00000000,0x0d54ff20,0x55440180,0x4400aaaa,0x104402a9,0x00555555,
    0x00000000,0x00000000,0x985d8000,0x0004fffe,0x0000dff3,0x00000000,
    0x20000000,0x000003fc,0x00000000,0x00000000,0x00000000,0x00000000,
    0x80003550,0x00000008,0x00000000,0x2a600000,0x00000001,0x00000000,
    0x00000000,0x00000000,0x00000000,0x00000000,0x00000000,0x00000000,
    0x00000000,0x00000000,0x00000000,0x00000000,0x00000000,0x00000000,
    0x00000000,0x00000000,0x54c0b2a0,0x509999aa,0x1cb80059,0xbb950000,
    0x33332279,0x05b7004c,0x98000c40,0x4ccc401a,0x40199999,0x220001a9,
    0x5554c019,0x800a9801,0x44009aa8,0x4409aaa9,0x99999999,0x99801310,
    0x0aaa9800,0x113f2000,0xfffffffb,0x0017f2bf,0x980005fd,0x36fffffe,
    0x00ffffff,0x7001fff3,0xffc800df,0xfa80dfff,0x7fffffff,0x9fffff90,
    0xfffd7100,0xfffd301f,0x3e605dff,0xfff900ff,0xfb10dfff,0xa8ffffff,
    0xffffffff,0xff80bf94,0xffff9102,0x90001dff,0x577fc49f,0x93ceffc9,
    0x2fe800bf,0x677f4000,0x26662a99,0xff9807fb,0x06fb800f,0xd9dffd10,
    0xffa81dff,0x85eeeeee,0xffdcdffd,0x3fffea05,0x7fc40eee,0x1fffdbde,
    0x442fffb8,0xfeddfffe,0x3bffe60f,0x74c7eccd,0x4ffeeeee,0x2ff80bf9,
    0xddffffa8,0xc8001ffe,0x2a1bf24f,0x017f20ff,0x40005fd0,0x2a001ffa,
    0x05d7007f,0x6401bee0,0x2ffcc1ff,0xfb801bea,0x417fd41f,0xd801dffa,
    0x84ff886f,0x7fc0fff9,0x7f43882f,0xfe80000e,0xff80bf94,0x80f7fcc2,
    0x4fc8000a,0x17fc0ffa,0xfe800bf9,0x1bee0002,0x000ff500,0x77e4ccc0,
    0x22099999,0x3ff502ff,0xfd0037d4,0x3e1bf207,0x0bfe003f,0x1b9837e4,
    0x88007fdc,0xd00002ff,0xf017f29f,0x00efd85f,0xc9aa8800,0x7c0ffa4f,
    0x4417f22f,0xa8bfa099,0x4fc800aa,0x303fd400,0x22033333,0xffffffff,
    0x1bf25fff,0x37d49ff0,0x500ff980,0x02fdc3ff,0x7ec0ffa0,0x13fe2004,
    0x001ff980,0x3f29fd00,0xf517fc05,0xfa80003f,0x24ffffff,0x0ff985fd,
    0x3fe217f2,0x3e6bfa0e,0x6c02ffff,0x3fd4004f,0x7fffff98,0xffb99910,
    0x74799999,0x537e403f,0x17ee00df,0xfd17ffdc,0x1ffb8005,0x5000ffcc,
    0x7c4001ff,0xfd00005f,0xff017f29,0x00037e45,0x37337ff6,0x33fe64ff,
    0x644ffa89,0x077f445f,0x333ff7fa,0x2aaa0fff,0xaaaadfea,0x20ff500a,
    0x07fdccc8,0xff00df70,0x2a6fb805,0x9009aaef,0xfffd889f,0x511ff13f,
    0x3a201597,0x4ffc8cff,0x003fdc00,0x00177fe4,0x2fe53fa0,0x4fe8bfe0,
    0x07fea000,0xfff993f2,0xfc84ffff,0x203bfa25,0x3e20effe,0x3ffffe3f,
    0x3fffffff,0x2a00ff50,0x0df7007f,0x5401ff88,0x3fffea7f,0x27ec3eff,
    0x9fb3ffd3,0x3fff7fe6,0x3f204fff,0x8002ffff,0xf90006fc,0x00017fff,
    0x017f29fd,0x21ffc5ff,0x81ccccc9,0x49f903ff,0x1bccaafe,0x3fa2bf90,
    0x01dfd00e,0x666649fd,0xcccccefe,0x200ff501,0xdf7007fa,0x401ff980,
    0x99930ffa,0x749ffffb,0x21bff73f,0xbfff34fc,0x09ff9537,0x0fffffe6,
    0x05fd8310,0x3fff6600,0xa7f4004f,0x97fc05fc,0x7fdc2ff8,0x3fcc2fff,
    0x1fe29f90,0xfd1bf900,0x817f401b,0x13f605fc,0x200ff500,0xdf7007fa,
    0x401ff880,0xfc8807fa,0xffb9fb2f,0xff54fd87,0x703fee01,0xbffd59ff,
    0x64bff101,0xb880006f,0xd000efff,0xf017f29f,0x261ffc5f,0x542ffaaa,
    0x453f206f,0x199abdff,0x0dfdbf90,0x3ee05fd0,0x0013f605,0x3ea00ff5,
    0x00df7007,0x6fb805ff,0x7e53fa00,0x3fe81eff,0x3e201ff3,0x707ff22f,
    0xfff509ff,0x0001fee5,0x004ffc88,0x017f29fd,0x01ff45ff,0x0df70bfe,
    0xfff927e4,0x43bfffff,0x00efddfc,0x5fb817f4,0x50013f60,0x1fea00ff,
    0x7c037dc0,0x027ec03f,0x3feebf90,0x225ff00d,0x8ffe00ff,0x1ff902ff,
    0xf54fff88,0xc800001f,0x27fd007f,0x17fc06fb,0x2ff80bfb,0x9f903fdc,
    0x77667fd4,0xbf90ffff,0x7401dfd1,0x40bf702f,0x7d4004fd,0x00ff5007,
    0x3f601bee,0x00ffe206,0x1ff54fd8,0xff83fe60,0x7ccbfe02,0x03ff300f,
    0x3fe69ff7,0x7d400004,0x9ffc400f,0x3fea06fa,0xf807fee0,0x407fd42f,
    0x3ff34fe8,0x7e4ffea0,0x740dff15,0x40bf702f,0x7d4004fd,0x00ff5007,
    0xf3007fea,0x01bf205f,0x3fa2ff98,0xfd89fb04,0x2a1ff505,0x1ff501ff,
    0x7e45ff30,0x3200001f,0x1ffa806f,0x3f203ff3,0xf00dfe87,0x82ff985f,
    0x0bf94ffd,0x4bf94fe8,0x5fd05ff9,0xfd817ee0,0x03fd4004,0xf1007fa8,
    0xffe801bf,0x00bff222,0x3ee2ff54,0x20ffe42f,0x7f4c2ff9,0x103bfe24,
    0x1bf20dfd,0x9817fff1,0x7101550c,0x506647ff,0x0efe8dfd,0x7d41ffd4,
    0x17fc09ef,0xfd88f7f4,0x01ff94fe,0x2fe4bfe6,0x3fa17fea,0x6c0bf702,
    0x3fd4004f,0x2007fa80,0x5eeefffc,0x7f7fff44,0xeeec83ff,0xf905fffe,
    0x05fffddf,0x3fb7bff2,0xefffa85f,0x260fffee,0xe981ffdb,0xffffffff,
    0xfdffff70,0xffc8bfff,0x4c1fffff,0xffeeefff,0x3fffee05,0x982fffee,
    0xbbffefff,0x59dff54f,0x64bff955,0x44ffb85f,0x0bf702fe,0x3f6027ec,
    0xffffffff,0xffffffb6,0xfb80dfff,0xd905ffff,0x3203bfff,0x01dfffff,
    0x0effff5c,0x3bfffae0,0x3fff6603,0x7fec0cff,0x7ff6400d,0x3faa3def,
    0x82dfffff,0x0dffffd9,0xdffffb10,0xffdb1007,0x26017dff,0x9f52effe,
    0x7fffff54,0x82fe43ff,0x0bfa3ffc,0x9fb02fdc,0xfffffd80,0xffb6ffff,
    0xdfffffff,0x8800cc00,0x01331001,0x20001100,0x00988001,0x220002a6,
    0x00998800,0x31000260,0x00198000,0x75300044,0x00000357,0x00000000,
    0x00000000,0x00000000,0x00000000,0x00000000,0x00000000,0x00000000,
    0x00000000,0x00000000,0x00000000,0x00000000,0x00000000,0x00000000,
    0x00000000,0x55300000,0x4cccc035,0x41999999,0x0cc40099,0x26200133,
    0x01355100,0x4c400262,0x22001310,0x100aa801,0x20c40133,0x33100998,
    0x4ccccc41,0x26199999,0x21331009,0x99999998,0x33109999,0x13333333,
    0x13300262,0x00266662,0x26666666,0x33331099,0x98133333,0x2effffff,
    0x7fffffcc,0x3a1fffff,0x93fe206f,0x7cc01ffc,0x7fff4c2f,0x07fd82ff,
    0x1bea7ff0,0xea80ff40,0xdff701ff,0xff70ff40,0xb8bff607,0xffffffff,
    0x05ff1fff,0xfffe9bfa,0xffffffff,0xffffffb5,0x1bee9fff,0x3ff65ff0,
    0x982effff,0xffffffff,0xfffff52f,0xfa87ffff,0x2fffeccd,0x3fffffe6,
    0x260fffff,0x1ff903ff,0x3602ffc4,0x677fdc6f,0x7d42fffc,0x8ffcc01f,
    0x1ff006f9,0x1ffffea8,0x205fff70,0x1bff21fe,0xfb8fffe2,0xffffffff,
    0x905ff1ff,0x7776c1ff,0xeeeefffe,0xfffddd94,0x1bee7ddd,0x3ff65ff0,
    0x43ffffee,0xeeeeeff9,0xddff52ee,0x085ddddd,0x400dff10,0xffc84ff8,
    0x5c17fcc0,0x3ff302ff,0x7f442fa8,0x6404ff87,0x401fe66f,0x3fffa0ff,
    0xff701ffc,0xc87fa0df,0x77dc1fef,0x37dc003f,0x1ffa85ff,0x2004fd80,
    0x0df704fd,0x89fb2ff8,0x3e60ffd9,0x07fa800f,0x01ff2000,0x3fa06fd8,
    0xfd02ff45,0x0417fa0d,0x7ec0ffa8,0xf11ff406,0xfd1fe00f,0x5c07fe67,
    0xfe82ffdf,0xd13f3f61,0xe8007f7f,0xf98bfe2f,0x09fb002f,0xfb827ec0,
    0xfd97fc06,0x262ffa84,0x7fa800ff,0x1bea0000,0x500ffd40,0x03fee5ff,
    0x7d42ffa8,0x7fc4001f,0x980ffd42,0x01fe21ff,0x4c131fe2,0x7bf701ff,
    0x6c3fd0df,0x33e67f9f,0x3ea004fb,0xfe897fc6,0x013f6004,0xdf704fd8,
    0x9fb2ff80,0xff98ffe0,0x007fa800,0x2013f200,0xfd804ff8,0xd803ff8e,
    0x0027f46f,0x3e20ffc4,0xf0df703f,0xf1054c1f,0x01ff980d,0x83ff1bf7,
    0x363f61fe,0x9f73f91f,0x3e1ff400,0x800bfb2f,0x3f6004fd,0xf80df704,
    0xf109fb2f,0x007fcc5f,0x80003fd4,0xfd800efb,0xffff1006,0x4ffe600d,
    0xb8000ffa,0x20dfb07f,0x20ff83fe,0x01be63fd,0x3ee03ff3,0x1fe8bfb5,
    0x7d3ea3fa,0x2a009f56,0xfcaff87f,0x04fd8006,0x7dc13f60,0xfd97fc06,
    0x7cc6fd84,0x07fa800f,0xbffdd900,0x03ff5001,0x00fffdc0,0x7fd1ff90,
    0x09fd1000,0xff103fea,0x7fc3fd01,0xf3017e66,0x4d7ee03f,0xe87fa1ff,
    0x27f5ff0f,0x7fd005fa,0x01ffbff0,0x4009fb00,0xfff704fd,0xffffffff,
    0x3733bf65,0x7fcc1fff,0x24cccccc,0xfffffffa,0xfffb00ff,0x7c401bff,
    0x7fcc004f,0x3fe2000f,0xfb0006fe,0x0ffe201d,0x47fa0df7,0xbf51fffa,
    0x701ff980,0xfd2fecbf,0xffc87fc3,0x500bf50f,0xffff01ff,0x9fb0001f,
    0xb827ec00,0xffffffff,0xfffb2fff,0xf3017fff,0xffffffff,0x7fffffd4,
    0x4c400fff,0xfb00ffeb,0xfffd000d,0xfffb800b,0x1ffc8002,0x3fa2fec0,
    0x3f25fb03,0x809f54fc,0xbf701ff9,0x1fe87fcc,0x2ffcc3fe,0x9fd00bf5,
    0x1bfaffe0,0x8013f600,0x0df704fd,0x5bfb2ff8,0xf301bfd7,0x5555557f,
    0x00003fd4,0xff509fd1,0xbffb8003,0x7f4002ff,0x1ffc8006,0xf10ffa80,
    0x7cbf201f,0x09f56f9e,0xf701ff98,0x3fd4fe8b,0xa8bfa3fc,0x07fd406f,
    0x4ff8aff8,0x0027ec00,0x1bee09fb,0x93f65ff0,0xff984fe8,0x007fa800,
    0x2237dc00,0x7cc004ff,0x001dfb3f,0x320027ec,0xff1002ff,0xfc81bee7,
    0x73fd3fab,0x1ff9807f,0xffa8bf70,0x8ff11fe8,0x2037cc29,0x4bfe04fe,
    0x36003ffa,0x13f6004f,0x3fe037dc,0xffa89fb2,0x4007fcc1,0x400007fa,
    0x077e46fb,0xf89bfa00,0x13f6004f,0x002ffc80,0x03fdafec,0x5c7f2fee,
    0x4c03fbcf,0x0bf701ff,0x223fd7fd,0x07f9807f,0xff803fea,0x4007ff22,
    0x3f6004fd,0xf80df704,0xfd09fb2f,0x800ff98b,0x400007fa,0x07fea4fe,
    0xb83ff700,0x9fb001ff,0x007ff200,0x3fe3fea0,0x9bf3ee00,0x402fcff8,
    0xbf701ff9,0x23fddf50,0x7f9807f8,0xff013fa0,0x800ffe85,0x3f6004fd,
    0xf80df704,0xf509fb2f,0x007fcc1f,0x80003fd4,0xfd10ffd9,0x3333333b,
    0x82ffc413,0x9fb006fe,0x337ff900,0x44033333,0x5406fdff,0x77f44fef,
    0x54ccc42f,0x2e199aff,0x3ffff05f,0x3e601fe6,0x801ff507,0x2ffc42ff,
    0xb0027ec0,0x01bee09f,0x413f65ff,0x03fe64ff,0xd001fea0,0xffffdddd,
    0x7ffffdc3,0x22ffffff,0xff500ffd,0x009fb007,0xffffffff,0x7ec03fff,
    0x7fd403ff,0x0fffdc1f,0x3ffffff2,0xbf70ffff,0x4c7ffee0,0x07f8807f,
    0x5ff00bfd,0xd809ff30,0x3fff604f,0x74ffffff,0xb2ff80df,0x43fee09f,
    0xfa800ff9,0xffffffff,0x7fffff43,0xffffb83e,0x2fffffff,0xfd807ff5,
    0x027ec01f,0x7ffffffc,0x2a01ffff,0x7cc00fff,0x0fff886f,0x7fffffe4,
    0xbf70ffff,0x547ffe20,0x0ff8806f,0x7c00ffd4,0x05ff702f,0xffb027ec,
    0x9fffffff,0x5ff01bee,0x7fc413f6,0x5001ff34,0xffffffff,0x0133307f,
    0x00000000,0x00000000,0x00000000,0x00000000,0x00000000,0x00000000,
    0x00000000,0x00000000,0x00000000,0x00000000,0x00000000,0x00000000,
    0x00000000,0x00000000,0x00000000,0x99880000,0x98800099,0x4cc404c0,
    0x33000199,0x19980003,0x03333310,0x88000998,0x062009aa,0x30050000,
    0x054c0155,0x00aaa988,0x88035530,0x98800aa9,0x26209aaa,0x26213100,
    0x0c40d4c0,0x08802aaa,0x3ffffff2,0x3fb800ce,0x3ffa1be2,0x00bfffff,
    0x001fffa8,0xd03fff90,0x7dffffff,0x44007ff0,0x02fffffd,0x200007fd,
    0xfff705fc,0xff981bff,0x3fffa20f,0xf701efff,0x885fffff,0x0dfffffd,
    0xfffffc88,0x5c0bfa5f,0x3e6bf55f,0x3fa1efff,0x2fffffa8,0xff94ff98,
    0x5ffffddd,0x3e62fb80,0xeeeefe85,0xfd806fff,0xf98004ff,0xefe81fff,
    0x0efffeee,0x7cc00ffe,0x3ffdbbef,0x0004ffb8,0x360bff62,0x6ffcacff,
    0xf117ffdc,0xdffd799d,0x677ff441,0x3fa22fdc,0x0fffdcdf,0x65de7fec,
    0x5c0bfa4d,0xff5bf55f,0x7f4dffb9,0xfffdcffc,0x64fffe40,0x1ffe985f,
    0x4fa87f20,0xffb82fe8,0x3f3fe203,0xfcfe8007,0x4c2fe81f,0x0ffe5ffb,
    0x7d427f40,0x0dffa80f,0x0f7f4400,0x3a207fd4,0x03ffe63f,0xd8bfea03,
    0x360882ff,0x2ff440ef,0xfd001ff3,0x7d57ee05,0x3fea0dff,0x441dffd1,
    0x7ffcc3ff,0x3fa05fcb,0xfa87f606,0xfd02fe83,0x7c77d409,0x3bee001f,
    0x2fe81ff8,0x1ffcffb0,0xe807fd40,0x1dfd304f,0x03bfe600,0x7fa817f4,
    0x3a000dcc,0x005ff34f,0x3ea03ff3,0x200ff51f,0x2bf702fe,0xff885ffa,
    0xfd01dfd2,0xf95ffb09,0x917fd40b,0xddddffdd,0x3fa3dddf,0x6c09fb02,
    0x2009fd4f,0x1ff89ff8,0xff502fe8,0x2e00ffe3,0x81bee06f,0x5401ffd8,
    0x3fe204ff,0x001ff100,0x3f29f900,0x80df7006,0x1bff12ff,0xf702fe80,
    0x6c03feab,0x3205fd2e,0xc9ffb85f,0x91ff405f,0xfdddffdd,0x3fa3dddf,
    0x2205ff02,0x00ff71ff,0x0ffc53f6,0xff8817f4,0xf9007ff1,0x403fd40b,
    0xff903ffc,0xccffa807,0x1ffccccc,0x3bb32600,0x09fb4ffe,0xfd013f20,
    0x5f7ffdc7,0xf702fe80,0xe801feab,0xb0bf702f,0xb017f2bf,0xfb1be09f,
    0xd885fd03,0x99fea05f,0x37d401ff,0x5fd03ff1,0x7fc3fe60,0x207fb803,
    0xfb800ff9,0x017fec4f,0x7fffffd4,0x001fffff,0xfffffffb,0x400ffa9f,
    0x27ec04fd,0x37ffff66,0x7dc0bfa0,0x7400ff55,0x2abf702f,0xbf90ffeb,
    0xf885fd80,0x7f407f45,0x03fffeee,0x13fa27ec,0x3e21ff88,0xd02fe81f,
    0x401ffcbf,0xff703ff9,0x1ffd8801,0x5402ffd4,0x999999ff,0xffb00199,
    0xfb4fc815,0x017f2009,0x3ae207fd,0x05fd0eff,0x03fd57ee,0x3ee05fd0,
    0x641bffd5,0x437e405f,0xe83fc5f9,0xffffffff,0xc85ff103,0x113f206f,
    0x37fd03ff,0x41fffb73,0xff9003ff,0xffffb79b,0x00efe880,0x4c01dff3,
    0xf00000ff,0x653f205f,0x0df7006f,0x5400ffc4,0x207fd3ff,0x00ff55fc,
    0x5fb817f4,0x0bf90135,0x4fa85fd8,0x22fe837c,0xa84ffd99,0x81ff987f,
    0x7fc40efa,0xfffffe81,0x1ffc0dff,0xfffff700,0x7d40df9d,0x7f4400df,
    0x013fe01f,0x7fcc5b70,0xf54fe881,0x3ff3005f,0xe801bee0,0xf50bfb3f,
    0x801feabf,0x0bf702fe,0xfe80bf90,0x9dfb9934,0x4599ff99,0x1ff902fe,
    0x9ff05fd8,0xff105fd0,0x9dddfd03,0x00ffe057,0x7d426a60,0x009ff705,
    0xf702ffd8,0xff50407f,0x513fe23f,0x7ff49fff,0x3bf61982,0x1317fd41,
    0x7e4bfea0,0x57ffee1f,0x3fa007fa,0x900bf702,0x97fc40bf,0xfffffffb,
    0x3a4fffff,0x85ff302f,0xeeeeeeff,0x77fd46ff,0xeffeeeee,0x005fd0ee,
    0x80001ffc,0x3ffc84fc,0x09ff9000,0x373bfff6,0x3ffee4fe,0x3f7bff22,
    0x3a64fcef,0x2ffeefff,0x3fbbffa2,0x77fe44ff,0x225fffee,0xbefeefff,
    0x400ff55f,0x0bf702fe,0x7e40bf90,0x5fb3310f,0x1339f733,0xffa817f4,
    0x3ffffea1,0x21ffffff,0xfffffffb,0xd0ffffff,0x1ffc005f,0x07fc4000,
    0x00007ffa,0x3aa0bff5,0x22efffff,0xffc86fe8,0x909f54ff,0x03bffffd,
    0x05dffff9,0xdffffff7,0x9fffd307,0x1feabf51,0xf702fe80,0x20bf900b,
    0x1fb04ffa,0x2fe81fdc,0xdfd8ffb0,0xf9999999,0x2666624f,0x9affa999,
    0xf800bfa1,0x7440003f,0x000eb83f,0x1005f300,0x44018033,0x00130000,
    0x4cc40062,0x00988009,0x00000000,0xfda997f2,0xb83fa06f,0x445fd02f,
    0x7fc3ffca,0x0037e402,0x5fd03ff1,0x001ffc00,0x037fe4cc,0x00000000,
    0x00000000,0x00000000,0x00000000,0xffffc800,0x7c04ffff,0xfe80fe47,
    0x4fffffff,0x2a007fd4,0xff1001ff,0x4005fd03,0xffffffff,0x3ffff27f,
    0x000003ff,0x00000000,0x00000000,0x00000000,0x20000000,0xbeeffffc,
    0x7ec6f800,0xdffffd01,0x0bfb017d,0x4400ffe0,0x02fe81ff,0x3fffffe0,
    0x3bf27fff,0x86200bce,0x5400d41a,0x004cc02c,0x004c4262,0x33310988,
    0x41333333,0x04cc0198,0x44003930,0x2aaa2009,0x2aaaaaaa,0x664c332a,
    0x00000001,0x00000000,0x00000000,0x3a000000,0x3f69ffd7,0x027ec05f,
    0x9fd017fa,0x7fc01bea,0xffffff91,0x7fcc5fff,0x403ff704,0xff1001fa,
    0x7fffcc0b,0x0fffffff,0x3fea3ff7,0x00000002,0x00000000,0x00000000,
    0x3a000000,0xfaefbfbf,0x3f601feb,0x807fdc04,0x0ff31ff9,0x32a1ff10,
    0xffdccccc,0x220ffe42,0xf51443ff,0xfdf90143,0x2aaaa205,0x22aaaaaa,
    0x3ff50ffb,0x00000000,0x00000000,0x00000000,0x7f400000,0x2e7ffb2f,
    0x013f603f,0x3f207ff1,0x2601fe26,0x4fe8807f,0x7f41dfb0,0xf98cfc85,
    0xf882fd88,0x00006f9d,0xff987fd4,0x00000001,0x00000000,0x00000000,
    0x3a000000,0xfb9ff25f,0x2013f604,0x85ff06fc,0xa8bf20ff,0x06fd806f,
    0x7fdd3fe2,0xfbefc880,0xfd80cffb,0x00007f91,0x1ff33fd4,0x00000000,
    0x00000000,0x00000000,0x7f400000,0x4fb8ff22,0x9fb33331,0xf9813333,
    0x743fd41f,0xfa97fa1f,0x007fdc05,0x07feffea,0x19fff910,0xff897e60,
    0x777774c0,0x30eeeeee,0x007fc4ff,0x00000000,0x00000000,0x00000000,
    0x43fd0000,0x753ee3fc,0xffffffff,0x4fe85fff,0x97ec27ec,0x7f70fff9,
    0x8017fcc0,0x9803fffc,0xd00cfffd,0x4c5fb81f,0xffffffff,0x87710fff,
    0x0000003b,0x00000000,0x00000000,0x40000000,0xb8ff21fe,0xfddddb4f,
    0x09dddddf,0x0ffc4ff7,0xfdfb9fe4,0x3e205f92,0x3fe2004f,0x3bf6600f,
    0x20cfeafb,0x05fd04fa,0x00000000,0x00000000,0x00000000,0x00000000,
    0x321fe800,0xd813ee3f,0x3ff1004f,0xa7d41bee,0x3fb5f9fe,0xd0017fa0,
    0x7dc0bfff,0x5f911f53,0x7d403fe2,0x00000006,0x00000000,0x00000000,
    0x00000000,0x0ff40000,0x027dc7f9,0x7ec009fb,0x3e607fd5,0xd1fd4f8d,
    0x01ff901f,0x7fcffe40,0x0fd41103,0x26004c43,0x00000001,0x00000000,
    0x00000000,0x00000000,0x0ff40000,0x027dc7f9,0x7d4009fb,0xf100ff9f,
    0x2fee3f7f,0x01ffa87f,0x7dcbfea0,0x01fb801f,0x00000000,0x00000000,
    0x00000000,0x00000000,0xe8000000,0xfb8ff21f,0x0013f604,0xf80bfdfd,
    0x3fbe67ef,0x001ffcc6,0xffd89ff1,0x000e4c00,0x00000000,0x00000000,
    0x00000000,0x00000000,0x7f400000,0x4fb8ff21,0x70013f60,0xfe803fff,
    0x22fff44f,0xfffffffd,0x437f46ff,0x00006ff8,0x00000000,0x00000000,
    0x00000000,0x00000000,0x3a000000,0xfb8ff21f,0x00026204,0xfb00dff1,
    0x44ffb83f,0xfffffffe,0x07ff66ff,0x00027fd4,0x00000000,0x00000000,
    0x00000000,0x00000000,0x00000000,0x00000000,0x00000000,0x00000000,
    0x00000000,0x00000000,
};

static signed short stb__consolas_27_usascii_x[95]={ 0,5,3,0,1,0,0,5,3,3,2,1,3,3,
5,1,1,1,1,2,0,2,1,1,1,1,5,3,1,1,2,3,0,0,2,1,1,2,2,0,1,2,2,2,
3,0,1,0,2,0,2,1,1,1,0,0,0,0,1,4,2,3,1,0,0,1,2,2,1,1,0,1,2,2,
1,2,2,1,2,1,2,1,2,2,0,2,0,0,0,0,2,2,6,3,0, };
static signed short stb__consolas_27_usascii_y[95]={ 20,1,1,2,0,1,1,1,0,0,1,6,15,11,
15,1,2,2,2,2,2,2,2,2,2,2,6,6,5,9,5,1,1,2,2,2,2,2,2,2,2,2,2,2,
2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,0,1,0,2,23,1,6,1,6,1,6,1,6,1,1,
1,1,1,6,6,6,6,6,6,6,2,6,6,6,6,6,6,0,-2,0,10, };
static unsigned short stb__consolas_27_usascii_w[95]={ 0,5,9,15,13,15,15,4,9,8,11,13,7,9,
5,12,13,13,13,11,15,11,13,13,13,13,5,7,12,13,12,10,15,15,12,13,13,11,11,14,13,11,10,12,
10,15,13,15,12,15,12,13,13,13,15,15,15,15,13,8,12,8,13,15,9,12,12,11,12,13,14,13,11,11,
11,13,11,13,11,13,12,12,12,11,13,11,14,15,15,14,11,10,3,10,15, };
static unsigned short stb__consolas_27_usascii_h[95]={ 0,20,7,18,24,20,20,7,26,26,12,14,10,3,
6,22,19,18,18,19,18,19,19,18,19,18,15,19,16,8,16,20,25,18,18,19,18,18,18,19,18,18,19,18,
18,18,18,19,18,23,18,19,18,19,18,18,18,18,18,26,22,26,10,3,6,15,20,15,20,15,19,20,19,19,
25,19,19,14,14,15,20,20,14,15,19,15,14,14,14,20,14,26,28,26,6, };
static unsigned short stb__consolas_27_usascii_s[95]={ 251,148,241,15,92,196,180,251,45,16,201,
128,248,196,174,122,135,105,59,1,60,123,149,149,163,100,154,177,127,227,114,
227,76,44,31,185,1,241,229,238,202,190,213,163,89,133,119,107,76,106,216,
199,176,224,73,89,27,43,13,55,135,25,213,180,164,160,167,173,1,140,54,
14,42,81,64,28,69,114,236,185,238,154,223,199,93,211,142,157,185,212,173,
34,1,5,148, };
static unsigned short stb__consolas_27_usascii_t[95]={ 9,1,88,71,1,1,1,1,1,1,88,
88,71,22,22,1,30,51,51,51,71,30,30,51,30,71,71,30,71,88,71,
1,1,71,71,30,71,51,51,30,51,51,30,51,71,51,51,30,71,1,51,
30,51,30,51,51,51,51,51,1,1,1,88,22,22,71,1,71,30,71,30,
30,30,30,1,30,30,88,71,71,1,1,71,71,30,71,88,88,88,1,88,
1,1,1,22, };
static unsigned short stb__consolas_27_usascii_a[95]={ 238,238,238,238,238,238,238,238,
238,238,238,238,238,238,238,238,238,238,238,238,238,238,238,238,
238,238,238,238,238,238,238,238,238,238,238,238,238,238,238,238,
238,238,238,238,238,238,238,238,238,238,238,238,238,238,238,238,
238,238,238,238,238,238,238,238,238,238,238,238,238,238,238,238,
238,238,238,238,238,238,238,238,238,238,238,238,238,238,238,238,
238,238,238,238,238,238,238, };

// Call this function with
//    font: NULL or array length
//    data: NULL or specified size
//    height: STB_FONT_consolas_27_usascii_BITMAP_HEIGHT or STB_FONT_consolas_27_usascii_BITMAP_HEIGHT_POW2
//    return value: spacing between lines
static void stb_font_consolas_27_usascii(stb_fontchar font[STB_FONT_consolas_27_usascii_NUM_CHARS],
                unsigned char data[STB_FONT_consolas_27_usascii_BITMAP_HEIGHT][STB_FONT_consolas_27_usascii_BITMAP_WIDTH],
                int height)
{
    int i,j;
    if (data != 0) {
        unsigned int *bits = stb__consolas_27_usascii_pixels;
        unsigned int bitpack = *bits++, numbits = 32;
        for (i=0; i < STB_FONT_consolas_27_usascii_BITMAP_WIDTH*height; ++i)
            data[0][i] = 0;  // zero entire bitmap
        for (j=1; j < STB_FONT_consolas_27_usascii_BITMAP_HEIGHT-1; ++j) {
            for (i=1; i < STB_FONT_consolas_27_usascii_BITMAP_WIDTH-1; ++i) {
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
        float recip_width = 1.0f / STB_FONT_consolas_27_usascii_BITMAP_WIDTH;
        float recip_height = 1.0f / height;
        for (i=0; i < STB_FONT_consolas_27_usascii_NUM_CHARS; ++i) {
            // pad characters so they bilerp from empty space around each character
            font[i].s0 = (stb__consolas_27_usascii_s[i]) * recip_width;
            font[i].t0 = (stb__consolas_27_usascii_t[i]) * recip_height;
            font[i].s1 = (stb__consolas_27_usascii_s[i] + stb__consolas_27_usascii_w[i]) * recip_width;
            font[i].t1 = (stb__consolas_27_usascii_t[i] + stb__consolas_27_usascii_h[i]) * recip_height;
            font[i].x0 = stb__consolas_27_usascii_x[i];
            font[i].y0 = stb__consolas_27_usascii_y[i];
            font[i].x1 = stb__consolas_27_usascii_x[i] + stb__consolas_27_usascii_w[i];
            font[i].y1 = stb__consolas_27_usascii_y[i] + stb__consolas_27_usascii_h[i];
            font[i].advance_int = (stb__consolas_27_usascii_a[i]+8)>>4;
            font[i].s0f = (stb__consolas_27_usascii_s[i] - 0.5f) * recip_width;
            font[i].t0f = (stb__consolas_27_usascii_t[i] - 0.5f) * recip_height;
            font[i].s1f = (stb__consolas_27_usascii_s[i] + stb__consolas_27_usascii_w[i] + 0.5f) * recip_width;
            font[i].t1f = (stb__consolas_27_usascii_t[i] + stb__consolas_27_usascii_h[i] + 0.5f) * recip_height;
            font[i].x0f = stb__consolas_27_usascii_x[i] - 0.5f;
            font[i].y0f = stb__consolas_27_usascii_y[i] - 0.5f;
            font[i].x1f = stb__consolas_27_usascii_x[i] + stb__consolas_27_usascii_w[i] + 0.5f;
            font[i].y1f = stb__consolas_27_usascii_y[i] + stb__consolas_27_usascii_h[i] + 0.5f;
            font[i].advance = stb__consolas_27_usascii_a[i]/16.0f;
        }
    }
}

#ifndef STB_SOMEFONT_CREATE
#define STB_SOMEFONT_CREATE              stb_font_consolas_27_usascii
#define STB_SOMEFONT_BITMAP_WIDTH        STB_FONT_consolas_27_usascii_BITMAP_WIDTH
#define STB_SOMEFONT_BITMAP_HEIGHT       STB_FONT_consolas_27_usascii_BITMAP_HEIGHT
#define STB_SOMEFONT_BITMAP_HEIGHT_POW2  STB_FONT_consolas_27_usascii_BITMAP_HEIGHT_POW2
#define STB_SOMEFONT_FIRST_CHAR          STB_FONT_consolas_27_usascii_FIRST_CHAR
#define STB_SOMEFONT_NUM_CHARS           STB_FONT_consolas_27_usascii_NUM_CHARS
#define STB_SOMEFONT_LINE_SPACING        STB_FONT_consolas_27_usascii_LINE_SPACING
#endif

