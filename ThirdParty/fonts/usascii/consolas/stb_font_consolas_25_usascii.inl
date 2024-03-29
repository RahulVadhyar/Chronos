// Font generated by stb_font_inl_generator.c (4/1 bpp)
//
// Following instructions show how to use the only included font, whatever it is, in
// a generic way so you can replace it with any other font by changing the include.
// To use multiple fonts, replace STB_SOMEFONT_* below with STB_FONT_consolas_25_usascii_*,
// and separately install each font. Note that the CREATE function call has a
// totally different name; it's just 'stb_font_consolas_25_usascii'.
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

#define STB_FONT_consolas_25_usascii_BITMAP_WIDTH         256
#define STB_FONT_consolas_25_usascii_BITMAP_HEIGHT         94
#define STB_FONT_consolas_25_usascii_BITMAP_HEIGHT_POW2   128

#define STB_FONT_consolas_25_usascii_FIRST_CHAR            32
#define STB_FONT_consolas_25_usascii_NUM_CHARS             95

#define STB_FONT_consolas_25_usascii_LINE_SPACING          16

static unsigned int stb__consolas_25_usascii_pixels[]={
    0x80000df1,0x10002cc8,0x3332e997,0x999930cc,0x01988059,0x31003300,
    0x00008800,0x00066098,0x00330013,0x02aa2098,0x426200cc,0x01a88198,
    0xaa980262,0x13100188,0x33355310,0xf8835013,0x74c3a606,0x3fffe600,
    0x3ffea001,0x3fffffb7,0x0fffffee,0x27fffec4,0x805ff700,0xffd9006e,
    0x3ee0009d,0x4c007f63,0xff00cfff,0xff96f800,0x07fd09ff,0x0ffaa7ec,
    0x103bffea,0xffd881ff,0x5005ffff,0xffffa8bf,0x7ec5ffff,0x4c1be23f,
    0x01df71ff,0x1006fda8,0x0fec39ff,0xf983fb80,0x05fc99bf,0xf809ff90,
    0x77ff4405,0x4000effe,0x017e60ff,0x17fff6c4,0x3fe003fc,0x3ffcadfc,
    0xff8837dc,0x3e21ff50,0x7e44fb9e,0x55effcc2,0xf5005feb,0x4cdffd4b,
    0x7fc1affd,0x221be25f,0x037f43ff,0x54007fc4,0x001fd86f,0x0ee887f7,
    0xe9802fb8,0xffecb80e,0x41dfb04e,0x2a005fe9,0x000fe84f,0x3e0ffe44,
    0x17ffc007,0x3ff11bee,0x3fd4df70,0xf337c5f5,0xf509fb0b,0xe97ea00b,
    0xc81ff82f,0x21be22ff,0x3ff886fd,0xc801fd80,0x001fd83f,0x01fd87f7,
    0xe980017e,0x0fffffff,0x7c4077cc,0x03fb001f,0x360007f7,0x2003fc6f,
    0x81ff03ff,0x23fd84fd,0xe8bee7fa,0xff303fa7,0x54017ea0,0x3603fe5f,
    0xf881103f,0xa807fd46,0x17e400ff,0x7ec17e40,0x447f7001,0x107e404f,
    0x43333333,0x2fa9dfe8,0x6c09fb03,0x06f9804f,0x26000ff1,0xa89fe0ff,
    0x740ff00a,0x223fcc1f,0xa9fea0ff,0x3f2bf14f,0xf504fb82,0x2eaa620b,
    0x3a07fe5f,0x1be2002f,0x5fd805fd,0x64017e40,0x001fd82f,0x20fe47f7,
    0x21fa8889,0xfffffffe,0x3ee1ff51,0xb807fe01,0x02fc806f,0x22000bf2,
    0x7e5fe1ff,0x07f84fff,0x8bfa0bf6,0x23fcc5fb,0xf99ffefe,0x2a09f905,
    0x7ffec45f,0x17f65fff,0x44001ff5,0x201bea6f,0x3f200ff8,0xd82fc802,
    0x47f7001f,0x3fffee6f,0x332e2f9a,0xf71ffccc,0xf8807e4d,0x01bea00f,
    0x6f980ff1,0x7c7fa800,0xffcadfdf,0x3fd03fc3,0x0ff4bf70,0xbd911fe6,
    0x7e403fa3,0x7c4bf503,0x5febacff,0x3fb3bfe6,0x37c4002f,0x3fe00bf9,
    0x200fee03,0x01fd80fd,0x4fe67f70,0x99feadfa,0x31fe803f,0x981fa7ff,
    0x03fcc07f,0x3f600fee,0xffbaa801,0x2e17ffc4,0xff03fc6f,0xf31ff101,
    0x900ff30d,0x827dc07f,0x033f65fb,0x75ff4bf5,0x88000cef,0x400ffe6f,
    0x3fe205fd,0x6c1be601,0x27f7001f,0x3a1fd2fb,0xfd007f17,0x37f7fe43,
    0xf980ff30,0x4007f407,0x7fc404fa,0x03ff82df,0xa83fc1ff,0x32ff606f,
    0x406f984f,0x37d406f9,0x6f9affcc,0x17e6bf50,0x8837aa00,0x003ff16f,
    0xfb301bf2,0x067ff49f,0xf7001fd8,0x97e23f27,0xd007f36f,0xffffb83f,
    0x00ff880b,0x5fa81bea,0xf003fe00,0xd03fc01f,0x7543fc3f,0x3fbea02f,
    0x406f980f,0x7fc400fe,0x557ffe62,0x2abf504f,0xd0019aff,0x9b7c49ff,
    0x1fea007f,0x749dfd30,0x3fb01dff,0xbecfee00,0x26bf13fa,0x81fe802f,
    0x43ffffc8,0x3ee01ff8,0x8007f605,0x03fc03fb,0x22fd81fe,0xfffcdfff,
    0x05ffe804,0x5fdc0df1,0x640effc8,0xfaefedff,0x3ea09f95,0x3fffffa5,
    0xffc81cff,0x37cdbe26,0x440ff100,0x1bea00ef,0xfb800fec,0x4cbeefb3,
    0xd005f54f,0x373ea03f,0x01ff43ff,0x1be207fb,0xf80df100,0xfd03fc06,
    0x7fffffc3,0x3ff7001d,0x7c41be20,0x0df99f96,0xf51bfff9,0x7d413f2b,
    0x3bb7bf25,0x7c40fffe,0x7cdbe26f,0x0ff3000f,0x7ec01fd4,0x7001fd80,
    0x97ddba7f,0x001f73fb,0x47ee03fd,0x837dc7fb,0x7f900ff9,0x405fb000,
    0xf03fc02a,0x008bfc1f,0x5406fc80,0xbf13fb02,0x541807ec,0x2e0bf75f,
    0x220df55f,0x24fd83ff,0x03ff16f8,0xfc81bee0,0xd82fc802,0x27f7001f,
    0x3f67f56e,0x3fa00dd2,0x3e21f901,0x317fe20f,0x07fc09fd,0x002fcc00,
    0x37d41fe0,0xf88001fe,0x9f70002f,0x01fb93e6,0x1feabf50,0x1fed7fe6,
    0xff989f90,0x3ff9be21,0x640bfb00,0x82fc802f,0x7f7001fd,0x7677c5f6,
    0xd002fcdf,0xfa9f603f,0xeefffa87,0x13ea05ff,0x980fe800,0x21fe00ee,
    0x03fc2fe8,0x404fe980,0x9be20ef9,0x003f25f8,0x3ff8afd4,0x7ed7ffe6,
    0x325ff306,0x37c43ffd,0x3fe00bfb,0x200bf202,0x01fd82fc,0x43f27f70,
    0x4ffb9ffc,0x4d47fa00,0xbfd51dd0,0x3bfff660,0x0007f403,0xff909f50,
    0x66fffc07,0x07f84ffd,0x17ffba60,0xfd8bff60,0x2fde7f41,0x7e4bf500,
    0x5f9efeef,0xd99dfff3,0x0effc9ff,0x0ff537c4,0x6401ff10,0x82fc802f,
    0x7f7001fd,0x044087ee,0x7e47fa00,0x5fffffff,0x9806f980,0x7f80005f,
    0x2e01ffa8,0x02dffffd,0x7fcc00ff,0x1ff7002e,0x3fa213ea,0x3ea000df,
    0x46fffdc5,0x3ff265f9,0x0041deff,0x07ff1be2,0x7ec04fc8,0xd83fc802,
    0x27f7001f,0x200004f9,0xfdb50ff8,0x40059dff,0x3f2042ff,0x2fc80002,
    0x00400088,0x20000000,0x00440008,0x4000c000,0x37c40000,0x7d407fea,
    0x00ffc00f,0x0fec2fdc,0x3fa3fb80,0xff500000,0x4000fe60,0x1fcbeffb,
    0x20000df1,0x000006f8,0x00000000,0x00000000,0x00000000,0x0dfb0df1,
    0xfb807ff1,0x83ff3007,0x7f7001fd,0x044077dc,0x13fa6044,0x900017d4,
    0x263dffff,0x2e00002c,0x0000000c,0x00000000,0x00000000,0x88000000,
    0x44ff886f,0xffd105fe,0x7fec007f,0xddddfb5f,0x3fbbbaa1,0x65677dc3,
    0xdefa82fd,0xd500effe,0xa9880003,0x00000001,0x00000000,0x00000000,
    0x00000000,0x37c40000,0xdf72ff98,0x00ef7cc0,0xfdbff5c0,0xff71ffff,
    0xfb507fff,0xb3017bff,0x0009dfff,0x00000000,0x00000000,0x00000000,
    0x00000000,0x00000000,0x874c0df1,0x000000e9,0x00000000,0x00000200,
    0x00000000,0x00000000,0x00000000,0x00000000,0x10000000,0x000000df,
    0x00000000,0x00000000,0x00000000,0x00000000,0x00000000,0x00000000,
    0x00000000,0x00000000,0x00000000,0x00000000,0x00000000,0x00000000,
    0x00000000,0x00000000,0x00000000,0x00000000,0x00000000,0x00000000,
    0x00000000,0x00000000,0x00000000,0x00000000,0x80000000,0x06600098,
    0x8000d400,0x00009aa9,0x00666662,0xdb800110,0x044002de,0x20002200,
    0x00098009,0x40600010,0xfffffffb,0x3fb6e207,0x0800001f,0xfb01fe40,
    0x3fffff25,0x00bf65ff,0xfc8007f8,0x3faa001f,0x5f906fff,0x7ffffdc0,
    0xeffec801,0x7fff4404,0xfeb803ff,0x3f6603ef,0x9101dfff,0x41dffffd,
    0x2effffea,0x3fffb220,0x3fb2204e,0xff70cfff,0x20ffffff,0x1ffffffb,
    0x3013faa0,0x905dfffb,0xc97ec07f,0x5fffffff,0x7f800bf6,0x03ffd800,
    0x957dff30,0x980bf607,0x201ffaaa,0xffeeffe8,0x21bf900e,0x3f600ffb,
    0x985ffddf,0xfffddfff,0x77fffcc1,0x3bf20fee,0x982fffed,0xfffefffe,
    0xeffffa80,0x07f71fff,0x00e7fdc0,0x027fff54,0xffddfff7,0x3603fc85,
    0xb2fdc02f,0x03fc005f,0x8006f4c0,0x3f6005fd,0x807fa002,0x3fa60efd,
    0xff85fd05,0x4c1df901,0x427f42ff,0x067fc5fe,0x3f620204,0x20f7fc47,
    0x6ffd40b8,0x3fb8dc40,0x001ff300,0x9fdbffd1,0x3f20f640,0xd80ff20f,
    0xb2fdc02f,0x03fc005f,0x2ff80000,0x5ff4ccc0,0xfd009999,0x203fea03,
    0x2fe81ff8,0x7fc407fc,0x3e26fa80,0x266fa80f,0x4c0000ff,0x017f60ff,
    0x2e009fd0,0x05fb003f,0x4fd977c0,0x0ffc4040,0x17ec07f9,0x2fd97ee0,
    0x33fc1330,0x33331035,0x007fc003,0xfffffff3,0x3fa0dfff,0x6c09fb01,
    0x2e5fc84f,0x20bf706f,0x07fe1ff9,0x07fa93ee,0x267f8800,0x3ee001ff,
    0x00fee006,0xb06003fc,0x3fa0009f,0xfd80ff22,0xfb2fdc02,0x20efe885,
    0xefffd8ff,0x3ffffee3,0x00ff8801,0x37ff3322,0xfd03cccc,0xb807fe03,
    0xcaff985f,0x07f900ff,0x7e45fff5,0x88bfe60e,0x540004ff,0x0017ee5f,
    0x7dc007fb,0xf981accd,0x0bdecb8d,0x0004fd80,0x01fe43ff,0x5fb805fb,
    0xefe88bf6,0x567effc0,0x99931ffd,0x2aaa03ff,0xaaaabffb,0x4005fb00,
    0x0ff881fe,0x7e41bea0,0x3f600dff,0x1ff7fec2,0xff99ffb1,0x05dff907,
    0x20efb980,0x7fc004fc,0x3ffee001,0x3ea1efff,0xffffffff,0x0027ec01,
    0x7f907fcc,0x2e017ec0,0xfd8bf65f,0x42fff80d,0x03fd04fd,0x3ffffffe,
    0xfb03ffff,0x40ff4005,0x3fcc07f9,0x307fff4c,0xe98ff435,0xc84fb9ef,
    0x2e02ffff,0x200cffff,0x6c1fffff,0x3fe2003f,0x8f777740,0xfecb9998,
    0x419ff71f,0x7ec06fd8,0x44fe8004,0x0bf603fc,0x97ecbf70,0x0bfe05fd,
    0x0ff417ee,0x9ff99998,0xfb009999,0x40ff4005,0x3fcc07f9,0x97ff3fe6,
    0x2e7fa2fd,0x313ee4ff,0x05fffdfd,0x17fff5c4,0x4ffedcc8,0xf8800ffa,
    0x7ff7740f,0xba7fc402,0x03ff105f,0x320027ec,0x203fc86f,0x2fdc02fd,
    0x80bfb5fb,0x20bf507f,0xff8801fe,0x00bf6000,0xff881fe8,0xfb1bea00,
    0x7f4ffe67,0x0bffbf61,0x9ffd47f9,0xa802ffd8,0xf9802ffe,0x8009fb3f,
    0x0bf601ff,0x37d5bf20,0x7ec05fd0,0x03bf2004,0x2fd80ff2,0xbfb2fdc0,
    0x07f801ff,0x07fa0bf5,0x8003fe20,0x3fa002fd,0x5c01ff01,0xb83fe25f,
    0x320ffaff,0x2fd80eff,0x1ff20bfe,0x5006fd80,0x0017f2df,0x17ec05fd,
    0x7f9afdc0,0xfd80bf60,0x01ff9004,0x1ff813f2,0x5fb27e40,0x3fc01dfb,
    0x3fd05fa8,0x001ff100,0xfd0017ec,0xd80ffa03,0x321fe63f,0x37dc6fff,
    0x1be63ff0,0x9800ffc4,0x6f9800ff,0x6c001ff5,0x00bf605f,0x0ffc4ff6,
    0x3f601ff8,0x00efc804,0x7fcc1bee,0xfb1ff400,0x7f817fa5,0x3fa0bf50,
    0x00ff8801,0xe8013f60,0x20df701f,0x3fe20ff9,0x443ffe80,0x26fa80ff,
    0x1ff106fb,0x401fe600,0x013fe5fb,0xfb01ff98,0x077e4405,0x0bf90bf9,
    0x7e404fd8,0x1ffc400e,0x41b93f66,0x4bf60ffb,0x0ff05fe8,0x0ff417ea,
    0x0007fc40,0x3a001ff9,0x8bff101f,0x5fe84fe8,0x6c2fff54,0x317fcc5f,
    0x4ff905ff,0x0bfd1009,0x7dc3ff50,0x205440df,0x2fd82ffd,0xfffd99bb,
    0xccefe883,0x7ec00ffe,0x003bf204,0x7f677fdc,0x3bff60ef,0x17ec3fff,
    0x0ff09ff1,0x0ff417ea,0x0007fc40,0xbb9dfff1,0xfa807fa0,0x0dffedff,
    0xfedeffa8,0x7443ffef,0x84ffdcff,0xfecceffd,0x3bbbf21f,0x360effed,
    0x3ffedccd,0xeeefffc8,0x7fec40ff,0xd2ffedef,0x407dffff,0x0cffffd8,
    0xffffffe8,0xfff30fff,0x3fffffff,0x4ffffea8,0x2efffea8,0x7fcc2fd8,
    0x5fa83fc4,0xddffdddb,0x03fe20bd,0xffffb300,0x3ffbbb6b,0xfd985eee,
    0x6cc03eff,0xff73efff,0xefffd885,0x3fffee03,0x7ffdc1df,0x7c0befff,
    0x00cfffff,0x37ffff66,0x3fffaa03,0x06660cef,0xfd002200,0xffffffff,
    0x3ffffe61,0x201fffff,0x40188009,0x3ffa82fd,0xeafd41fe,0xffffffff,
    0x001ff107,0x3ffa0c40,0x07ffffff,0x00400044,0x13000100,0x20066600,
    0x11000199,0x00131000,0x00000000,0x00000000,0x00000000,0x00000000,
    0x00000000,0x00000000,0x00000000,0x00000000,0x00000000,0x00000000,
    0xfff00200,0xfb039dff,0x3a7ff00d,0xf3fd804f,0xffffffff,0x0ffe2bff,
    0x13ea5fd8,0x3fc43f60,0xf707f880,0x40ffee1f,0xffffd1fd,0x3f29ffff,
    0x7d4bf603,0xffffffff,0xfffff71f,0x3fee7fff,0x93ffffff,0x079dffff,
    0x7dc07fe4,0x7ffffc2f,0xffff02de,0x06a05bdf,0x0bbfff62,0x3fffbbfe,
    0x017fcc3f,0x03fdcdf7,0x7ffc7fe2,0xffffffff,0x2a03fee5,0x017ea0ff,
    0x03fc43fa,0xff987f88,0x6c1bfee1,0xffdddb1f,0x0ff27ddd,0xfff52fd8,
    0x3fffffff,0x3fffffee,0xddff73ff,0x3f25dddd,0x2efffeee,0xfe83ffd8,
    0x7777fc3f,0xeff86fff,0x6c6fffee,0x3bfe63ff,0x7fc4ffdc,0x907ff261,
    0x8bfe20df,0x3ea01ff8,0x201fe606,0x43fe85fe,0x27e805f9,0xff1007f8,
    0x7dc3fe88,0x81fd82ff,0x07f907f9,0xfd8017ec,0x2e017ee5,0x43fc804f,
    0x7ec1ffd9,0x1ff7cc6f,0x7ff503fe,0x3ee60ff8,0x457ffe5f,0x07fcc2ff,
    0x3ff883ff,0x7e41ffc4,0x3604fe86,0x01fe603f,0x6fc87fe6,0x7f805f98,
    0x7c401fe2,0x7dc27ec7,0x81fd86fd,0x07f907f9,0x7d4017ec,0x2017ee0f,
    0x3fc804fb,0xcfd8df90,0x0feff20f,0x8bf901ff,0x0ffb80ff,0x17ee5ff9,
    0x03ff27e4,0x1ff709fb,0x7dc0ffc4,0x9807fe06,0x2df9007f,0x6f881ff8,
    0x1fe26f80,0xbf93fc40,0x0bfafee0,0x0ff303fb,0x2fd80ff2,0x2e17fc40,
    0x04fb805f,0xff103fc8,0xf1fd7f45,0x0ff89f5d,0x07fc4fb8,0x4110ffc4,
    0x4df303fc,0x02fe81ff,0x82fe49fd,0x6fa81ff8,0xd003fcc0,0x2209fb7f,
    0x9be1646f,0xff1007f8,0x7dc03bea,0x0fec6fab,0x3fc83fcc,0xfb00bf60,
    0x700bf70b,0x07f9009f,0x3efd1fec,0x89f57f56,0x42fd80ff,0x1ff880ff,
    0x7c40ff60,0xfd887fe7,0x223fea06,0x0ffa00ff,0xff300ff2,0x37ffd400,
    0x27f99fe0,0x01fe25f8,0x07fcffc4,0x87fe7f70,0x07f981fd,0x333339f9,
    0x7d405fd3,0x805fb80f,0x99999dfb,0xfc80ff21,0x64fe5fe4,0x7fc4f98f,
    0x84fd9999,0x0ffb80ff,0xff817f20,0xfffddff0,0xccfe801d,0x437dc04f,
    0x3fcc00ff,0x00bff600,0x897fe4ff,0x401fe25f,0x402feff8,0x6cbf73fb,
    0x907f981f,0xffffffff,0x3fe205ff,0xfffff702,0x3fee1fff,0x91ffffff,
    0xf37dc07f,0x4d7f3e6d,0x7ffffc5f,0x81ff04ff,0x7cc04fe9,0x87fe4c3f,
    0x04fffeff,0x01ffff30,0x3e60ff88,0x007f9806,0x3a027ff4,0x7cd3ffa7,
    0x4401fe24,0x5c06fdff,0x363ff13f,0x907f981f,0x999999df,0x17f605fd,
    0xeeeeffb8,0x99df70ee,0x3f219999,0x6f97ee03,0x2fccbffa,0x3fb733fe,
    0x667fc1ef,0x7006fffd,0xffffdfff,0xfe88ffcf,0x05ffb003,0x3fc8ffa0,
    0x2007f980,0x201ffefb,0x7fbf98fe,0x03fc49f3,0x4fe8ff88,0x5fc8fee0,
    0x0ff303fb,0x2fd80ff2,0x2e00ffa8,0x04fb805f,0x3f203fc8,0x3fdcdf15,
    0x40ff8bf3,0x7ffc6fd8,0x5703efff,0x17bdb930,0xf30ffcdf,0x0ff3001f,
    0x1ff37dc0,0x200ff300,0x06fc9ff9,0x327ee3f6,0x3e23f9af,0x22ff1007,
    0x47f703ff,0x81fd8ff8,0x07f907f9,0x3fe217ec,0x402fdc02,0x3fc804fb,
    0x37c4ff60,0x237c47d1,0x1ff880ff,0xb00667fe,0x3e6007ff,0x9fb07fe5,
    0x400ff300,0x06f98ff8,0x3a00ff30,0x207ff14f,0xbf36e9fc,0x03fc47f5,
    0x3fea7f88,0x7e43fb81,0x7f981fdc,0x7ec07f90,0x5c02fec2,0x04fb805f,
    0xff303fc8,0xf101be23,0xff00ff8d,0xf8007fc5,0x7f9005ff,0x3fe60ffc,
    0x003fcc00,0x00ff2ffa,0x7dc03fcc,0x207fea0f,0x3fa3fbfc,0x01fe22fb,
    0x3bf23fc4,0x3e21fdc0,0x7f981fdf,0x7ec07f90,0x2003fea2,0x4fb805fb,
    0xfb03fc80,0x2202fccb,0x5407fc7f,0x003fe0ff,0x5400ffdc,0x6c0ffc6f,
    0x03fcc04f,0x03ff7ee0,0x2203fcc0,0x86fe83ff,0x3f21fefb,0x01fe22fe,
    0x2ff43fc4,0x3ff60fee,0x907f981f,0x897ec07f,0xbf7002ff,0x9009f700,
    0x7ff5447f,0xf1017e61,0x2a20ff8f,0x007fc5fe,0xfd980110,0x540ffc1f,
    0x1fe600ff,0x0dfff100,0x3603fcc0,0x87ff306f,0x7fcc6ffb,0x3bbfe21f,
    0x3e26eeee,0x2e4ff887,0x1fff983f,0xddffdddb,0xd80ff27d,0xfffff92f,
    0x2e5fffff,0xeffb805f,0xf92eeeee,0x1dffffdd,0x7f805fa8,0x7ff777fc,
    0x000ff86f,0x7ffff640,0xd01ff81d,0x03fcc09f,0x001fff40,0x7fdc0ff3,
    0xa83ff201,0x1ffe83ff,0x3fffffe2,0x41fe27ff,0x07f72ffa,0x7ff47ff6,
    0x94ffffff,0xc97ec07f,0xffffffff,0x00bf72ff,0xfffffff7,0x3ffff27f,
    0x0bf502de,0xffff8ff0,0x1ff01def,0xdefd8000,0x0000002c,0x00000000,
    0x00000000,0x00000000,0x00000000,0x00000000,0x00000000,0x00000000,
    0x00000000,0x00000000,0x00000000,0x00000000,0x00000000,0x00000000,
    0x00000000,0x00000000,0x4000fff6,0xffc82ffe,0xffffffff,0x07e8fb01,
    0x26000011,0x15555300,0x000d54c0,0x44015551,0xaa9801aa,0x2203301a,
    0x82a61109,0x4cccc429,0x91009999,0x4004c409,0xa8826218,0x4401980a,
    0xaa982609,0x1013ae00,0x9000dfff,0xff905fff,0xffffffff,0x0df1fa03,
    0x80001df1,0x7ff4c5fa,0xfe986fff,0x2601efff,0x43fffffe,0x1effffe8,
    0xffffff98,0xfa83fc2f,0x1fff3bd5,0x3fa1dff7,0x3fffffff,0x7dc0ff10,
    0xf71fe804,0x3ffffb15,0x3f603fe8,0x3ff63be4,0x7fff04ff,0x0ffefd40,
    0x5fddf300,0x40ff1000,0xfc82fc6f,0xff70001f,0x5567fc47,0x67fd44ba,
    0xa82ffdbb,0x3ecabdff,0x32a73fe2,0x5e7d40ff,0x3e1ffeba,0x3babf507,
    0xdbfbfcce,0x9999971f,0x3e205ffb,0x2017e607,0x3fb3ee7f,0x7dc7febc,
    0x7c1ff106,0xffdacfdf,0x205ffd81,0x003fdafd,0x00bf67fa,0x5f80ff20,
    0xffb813e2,0x0ffec003,0x3e2013ee,0x446fc82f,0x3fd803ff,0xd0045fc8,
    0xfa83fc7f,0x3fe2dfd5,0xfe807f55,0x881fe204,0xdf104c6f,0x3e0f7fdc,
    0x207fe22f,0x17ffc5fb,0x3fe213f6,0xf51ff105,0x6d3ee00d,0x7fc4002f,
    0x7fffff40,0x81ffffff,0xe8804ffa,0x05fb80ef,0x3fe05fb8,0x22017f21,
    0x00ff107f,0x20ff2fdc,0x225fd5fa,0x409f30ff,0x3fc406fc,0x26f89fe0,
    0x07fee5f9,0x09fb0ffa,0x82ff85fd,0x07ff05fb,0x07fc57ea,0x7ec3be20,
    0x427e4002,0xdccefdcb,0xd100ccdf,0x3fa601bf,0x2bbfe605,0x6c07f900,
    0x200bfa2f,0x03fe05fa,0x25fb9988,0x3abf507f,0x4f99be27,0xcc81ff50,
    0xcccffdcc,0x7dc3fa2c,0x7dc9f51f,0xfa835304,0x3fc3fcc7,0xffa85fa8,
    0x7ec5fb00,0xfb17ec03,0x07fc4005,0x17dc7f50,0x40efd880,0xfa803ffa,
    0x7ec1dfff,0xff93f202,0xffffb801,0x41ffffff,0xffffffea,0xafd41fe5,
    0xf99be27e,0xf82ff884,0xffffffff,0x6c7f65ff,0x5c7f73ff,0x2ff8004f,
    0x41fe13f2,0x3ff725fa,0x5c1ff102,0xb17ee06f,0x27e4005f,0x1fb8bee0,
    0x897fe200,0x2a2006ff,0x3fa5fffd,0xff8ff202,0xccefb801,0x20cccccc,
    0xcaabcffb,0x7d41fe5f,0x337c4fd5,0x207fd09f,0x9ffa9999,0x2bf20999,
    0x5f76fcf8,0x640027dc,0x3e07fe5f,0x3e2bf507,0x1bea00de,0xff101ff1,
    0x1002fd81,0x1fc801ff,0x7cc003f2,0x0efe884f,0x97fdc400,0x8bf603fc,
    0x7fa802fe,0x207fe200,0x203fe5fa,0x7c4fd5fa,0xbfb13e66,0x203fc400,
    0xfc9fbbfb,0x13ee1fc9,0x2a3fe200,0x2a0ff06f,0x7ec0025f,0xfd83fe83,
    0x9002fd82,0x41f9009f,0x7ff5007d,0x001ffd80,0x0df74fc8,0x5fc83fe2,
    0x002ff980,0x97ee0df3,0xd5fe81ff,0x9f337c4f,0x100077dc,0xdcf980ff,
    0xb8fb9f36,0x5fb0004f,0x41fe07fb,0x7c4005fa,0xfdaaaabf,0x5557fd46,
    0x02acfeaa,0x7dc03fe2,0xffffffff,0x5ff904ff,0x20bfee00,0x7c4ffa00,
    0x227f443f,0x0441cff8,0xf3003dfb,0x25ffc81f,0x3ff624fe,0x337c4fd5,
    0x007fe69f,0xf880ff10,0x1fbfa4fe,0x2a0009f7,0xff00ffdf,0xcda97ea0,
    0xfffff500,0x5c1fffff,0xffffffff,0xf900ffff,0x7fe64c0b,0x2ccffccc,
    0x4001efd8,0x6fec4ffa,0x20effdcc,0xffdceffa,0xefffb80e,0x3fe23fed,
    0x44ecccff,0xdffdcffe,0x33bfea5f,0x4fd5fbff,0x753e66f8,0xeeeeeeff,
    0xf00ff105,0x2ffe43ff,0xf80013ee,0x41fe04ff,0x9fff15fa,0x33337f60,
    0x263feccc,0xeaaaaaaa,0xff102acf,0xbf1be003,0x003bfa20,0xf92ffcc0,
    0x019fffff,0x07dfffb3,0xeffffd98,0x7fffe441,0x7fec43ef,0x5c5f89ef,
    0x5f89efff,0xf337c4fd,0x3fffffe9,0x06606fff,0xff31bfa0,0x0004fb89,
    0x7f807ff2,0x3fe2bf50,0x00ff885f,0xfd801bee,0x002fe402,0xb027c4bf,
    0x9d100009,0x40013310,0x00880009,0x06003310,0x00001300,0x00000000,
    0x00000000,0x3ff20000,0x4c06fa81,0x5fb000ff,0x800ffc40,0x013e64f8,
    0x00000000,0x00000000,0x00000000,0x04cc0131,0x3ea00130,0x99866606,
    0x99999930,0x26219999,0x004ccc09,0x40220004,0x3fe803fd,0x6405fb00,
    0x8fe6005f,0x000003fa,0x00000000,0x00000000,0x7fd40000,0x201ffa81,
    0x7ffd005f,0x3ff97f60,0xfffffff5,0x3fee1fff,0x8077ec41,0x2b82effc,
    0x00000000,0x00000000,0x00000000,0x00000000,0x00000000,0xd1077e40,
    0x1274087f,0x03fabee0,0x23ff97f6,0x88888888,0x403fea08,0x7fe40efb,
    0x5be22ffe,0x2ccccccb,0x00000000,0x00000000,0x00000000,0x00000000,
    0x40000000,0x217f24fe,0x3ee9d1ec,0x5f9afc42,0x0bfe4fc8,0x00ffa800,
    0x21ff1366,0x4fc9cffa,0x7ffffffb,0x00000000,0x00000000,0x00000000,
    0x00000000,0x80000000,0x0efaaff8,0xdcdcfe98,0x90fe41df,0x3a4fc85f,
    0x5555512f,0x7cc55555,0x46f88007,0x30fffff9,0x01555555,0x00000000,
    0x00000000,0x00000000,0x00000000,0x50000000,0x9803ffff,0xf881dffe,
    0x3ee37c45,0x7fd47fa3,0xffffffff,0x2000ff30,0x0cdc8808,0x00000000,
    0x00000000,0x00000000,0x00000000,0x00000000,0x01ffec00,0x4177ffdc,
    0x24fb80fd,0x442ea1b9,0xaaaaaaaa,0x000ee22a,0x00000000,0x00000000,
    0x00000000,0x00000000,0x00000000,0xfd000000,0x5ffdc09f,0xd31efccd,
    0x0006ec07,0x00000000,0x00000000,0x00000000,0x00000000,0x00000000,
    0x00000000,0x6fe40000,0x21b903ff,0x0003d34e,0x00000000,0x00000000,
    0x00000000,0x00000000,0x00000000,0x00000000,0x70000000,0x03ff31ff,
    0x377609d0,0xdddddddd,0x000003dd,0x00000000,0x00000000,0x00000000,
    0x00000000,0x00000000,0x00000000,0x3f22ff98,0xf82fc00e,0xffffffff,
    0x0005ffff,0x00000000,0x00000000,0x00000000,0x00000000,0x00000000,
    0x00000000,0x427f4400,0x004c05fe,0x00000000,0x00000000,0x00000000,
    0x00000000,0x00000000,0x00000000,0x00000000,0xf301dfb0,0x0000009f,
    0x00000000,0x00000000,0x00000000,0x00000000,0x00000000,0x00000000,
    0x00000000,0x00000000,0x00000000,0x00000000,
};

static signed short stb__consolas_25_usascii_x[95]={ 0,5,3,0,1,0,0,5,3,3,2,1,2,3,
4,1,1,1,1,2,0,2,1,1,1,1,5,3,1,1,2,3,0,0,1,1,1,2,2,0,1,2,2,1,
2,0,1,0,1,0,2,1,1,1,0,0,0,0,1,4,1,3,1,0,0,1,1,1,1,1,0,1,1,2,
1,2,2,1,1,1,1,1,2,2,0,1,0,0,0,0,2,1,5,2,0, };
static signed short stb__consolas_25_usascii_y[95]={ 18,0,0,2,-1,0,1,0,-1,-1,0,5,14,10,
14,0,1,1,1,1,2,2,2,2,1,1,5,5,4,8,4,0,0,2,2,1,2,2,2,1,2,2,2,2,
2,2,2,1,2,1,2,1,2,2,2,2,2,2,2,0,0,0,2,21,0,5,0,5,0,5,0,5,0,0,
0,0,0,5,5,5,5,5,5,5,1,5,5,5,5,5,5,0,-2,0,8, };
static unsigned short stb__consolas_25_usascii_w[95]={ 0,4,8,14,12,14,14,4,8,8,10,12,7,8,
5,11,12,12,12,10,14,10,12,12,12,12,4,6,11,12,11,9,14,14,12,12,12,10,10,13,12,10,9,12,
11,14,12,14,12,14,11,12,12,12,14,14,14,14,12,7,12,7,12,14,9,11,12,11,11,12,13,12,11,10,
10,11,10,12,11,12,12,11,11,10,12,11,13,14,14,13,10,10,3,10,13, };
static unsigned short stb__consolas_25_usascii_h[95]={ 0,19,7,16,22,19,18,7,25,25,12,13,9,3,
5,21,18,17,17,18,16,17,17,16,18,17,14,18,15,7,15,19,24,16,16,18,16,16,16,18,16,16,17,16,
16,16,16,18,16,22,16,18,16,17,16,16,16,16,16,24,21,24,8,3,6,14,19,14,19,14,18,19,18,18,
24,18,18,13,13,14,19,19,13,14,18,14,13,13,13,19,13,24,26,24,6, };
static unsigned short stb__consolas_25_usascii_s[95]={ 254,190,195,44,87,195,89,217,5,14,171,
180,246,246,246,115,104,205,218,143,16,181,192,31,117,1,250,247,71,204,59,
140,61,1,224,154,196,185,174,167,148,137,244,111,99,209,124,74,237,100,14,
130,56,231,41,84,69,26,161,45,127,53,182,182,222,132,150,107,222,119,36,
234,13,25,76,1,63,156,234,94,163,210,208,83,50,144,220,193,156,176,169,
34,1,23,232, };
static unsigned short stb__consolas_25_usascii_t[95]={ 1,1,79,65,1,1,28,79,1,1,79,
65,65,81,75,1,28,28,28,28,65,28,28,65,28,47,47,1,65,79,65,
1,1,65,47,28,47,47,47,28,47,47,28,47,47,47,47,28,47,1,47,
28,47,28,47,47,47,47,47,1,1,1,79,88,79,65,1,65,1,65,28,
1,28,28,1,28,28,65,65,65,1,1,65,65,28,65,65,65,79,1,65,
1,1,1,79, };
static unsigned short stb__consolas_25_usascii_a[95]={ 220,220,220,220,220,220,220,220,
220,220,220,220,220,220,220,220,220,220,220,220,220,220,220,220,
220,220,220,220,220,220,220,220,220,220,220,220,220,220,220,220,
220,220,220,220,220,220,220,220,220,220,220,220,220,220,220,220,
220,220,220,220,220,220,220,220,220,220,220,220,220,220,220,220,
220,220,220,220,220,220,220,220,220,220,220,220,220,220,220,220,
220,220,220,220,220,220,220, };

// Call this function with
//    font: NULL or array length
//    data: NULL or specified size
//    height: STB_FONT_consolas_25_usascii_BITMAP_HEIGHT or STB_FONT_consolas_25_usascii_BITMAP_HEIGHT_POW2
//    return value: spacing between lines
static void stb_font_consolas_25_usascii(stb_fontchar font[STB_FONT_consolas_25_usascii_NUM_CHARS],
                unsigned char data[STB_FONT_consolas_25_usascii_BITMAP_HEIGHT][STB_FONT_consolas_25_usascii_BITMAP_WIDTH],
                int height)
{
    int i,j;
    if (data != 0) {
        unsigned int *bits = stb__consolas_25_usascii_pixels;
        unsigned int bitpack = *bits++, numbits = 32;
        for (i=0; i < STB_FONT_consolas_25_usascii_BITMAP_WIDTH*height; ++i)
            data[0][i] = 0;  // zero entire bitmap
        for (j=1; j < STB_FONT_consolas_25_usascii_BITMAP_HEIGHT-1; ++j) {
            for (i=1; i < STB_FONT_consolas_25_usascii_BITMAP_WIDTH-1; ++i) {
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
        float recip_width = 1.0f / STB_FONT_consolas_25_usascii_BITMAP_WIDTH;
        float recip_height = 1.0f / height;
        for (i=0; i < STB_FONT_consolas_25_usascii_NUM_CHARS; ++i) {
            // pad characters so they bilerp from empty space around each character
            font[i].s0 = (stb__consolas_25_usascii_s[i]) * recip_width;
            font[i].t0 = (stb__consolas_25_usascii_t[i]) * recip_height;
            font[i].s1 = (stb__consolas_25_usascii_s[i] + stb__consolas_25_usascii_w[i]) * recip_width;
            font[i].t1 = (stb__consolas_25_usascii_t[i] + stb__consolas_25_usascii_h[i]) * recip_height;
            font[i].x0 = stb__consolas_25_usascii_x[i];
            font[i].y0 = stb__consolas_25_usascii_y[i];
            font[i].x1 = stb__consolas_25_usascii_x[i] + stb__consolas_25_usascii_w[i];
            font[i].y1 = stb__consolas_25_usascii_y[i] + stb__consolas_25_usascii_h[i];
            font[i].advance_int = (stb__consolas_25_usascii_a[i]+8)>>4;
            font[i].s0f = (stb__consolas_25_usascii_s[i] - 0.5f) * recip_width;
            font[i].t0f = (stb__consolas_25_usascii_t[i] - 0.5f) * recip_height;
            font[i].s1f = (stb__consolas_25_usascii_s[i] + stb__consolas_25_usascii_w[i] + 0.5f) * recip_width;
            font[i].t1f = (stb__consolas_25_usascii_t[i] + stb__consolas_25_usascii_h[i] + 0.5f) * recip_height;
            font[i].x0f = stb__consolas_25_usascii_x[i] - 0.5f;
            font[i].y0f = stb__consolas_25_usascii_y[i] - 0.5f;
            font[i].x1f = stb__consolas_25_usascii_x[i] + stb__consolas_25_usascii_w[i] + 0.5f;
            font[i].y1f = stb__consolas_25_usascii_y[i] + stb__consolas_25_usascii_h[i] + 0.5f;
            font[i].advance = stb__consolas_25_usascii_a[i]/16.0f;
        }
    }
}

#ifndef STB_SOMEFONT_CREATE
#define STB_SOMEFONT_CREATE              stb_font_consolas_25_usascii
#define STB_SOMEFONT_BITMAP_WIDTH        STB_FONT_consolas_25_usascii_BITMAP_WIDTH
#define STB_SOMEFONT_BITMAP_HEIGHT       STB_FONT_consolas_25_usascii_BITMAP_HEIGHT
#define STB_SOMEFONT_BITMAP_HEIGHT_POW2  STB_FONT_consolas_25_usascii_BITMAP_HEIGHT_POW2
#define STB_SOMEFONT_FIRST_CHAR          STB_FONT_consolas_25_usascii_FIRST_CHAR
#define STB_SOMEFONT_NUM_CHARS           STB_FONT_consolas_25_usascii_NUM_CHARS
#define STB_SOMEFONT_LINE_SPACING        STB_FONT_consolas_25_usascii_LINE_SPACING
#endif

