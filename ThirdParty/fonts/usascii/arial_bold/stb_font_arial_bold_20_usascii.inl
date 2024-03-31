// Font generated by stb_font_inl_generator.c (4/1 bpp)
//
// Following instructions show how to use the only included font, whatever it is, in
// a generic way so you can replace it with any other font by changing the include.
// To use multiple fonts, replace STB_SOMEFONT_* below with STB_FONT_arial_bold_20_usascii_*,
// and separately install each font. Note that the CREATE function call has a
// totally different name; it's just 'stb_font_arial_bold_20_usascii'.
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

#define STB_FONT_arial_bold_20_usascii_BITMAP_WIDTH         256
#define STB_FONT_arial_bold_20_usascii_BITMAP_HEIGHT         62
#define STB_FONT_arial_bold_20_usascii_BITMAP_HEIGHT_POW2    64

#define STB_FONT_arial_bold_20_usascii_FIRST_CHAR            32
#define STB_FONT_arial_bold_20_usascii_NUM_CHARS             95

#define STB_FONT_arial_bold_20_usascii_LINE_SPACING          13

static unsigned int stb__arial_bold_20_usascii_pixels[]={
    0x00000000,0xec800000,0x327ddd74,0x05903eee,0x00000000,0x00000000,
    0x00000000,0x00000000,0x21330131,0x20053098,0x5009889a,0x3f982623,
    0xdfd95100,0x3bf20159,0xea83fb82,0x6c0fc83f,0x29fff95f,0x6444fffd,
    0x6dc00cff,0xc8803dff,0xd803dffd,0x2e01fd0f,0x101defed,0x207dffd9,
    0x39f9106e,0xd9300fd0,0x3ae0017d,0x6f802dff,0x2ff88ff9,0x7fffd9fb,
    0x2fbffee0,0x77ffdc6f,0x007f45fc,0x373bfff2,0xffc81ffe,0x261fdc0f,
    0x37c43fff,0x53f20d54,0x3e609dfd,0x980fffff,0xeffffffe,0xfffff301,
    0xbfc03dff,0xfffb07f8,0xe883ffff,0x84ffffff,0xebfc80fc,0x7c01fcc6,
    0x4c06feef,0x4ffffffe,0x7fcd3e60,0xffd9fee2,0x5c3ffecf,0x6fffbeff,
    0x3fef7ff2,0x901fdc5f,0x3fa6039f,0x5c2ff981,0x40f7dc3f,0x409883fc,
    0x909fb4fc,0x87ff9b9f,0xeaaefff8,0x7fc40fff,0x6ffeaaef,0x17e6bf10,
    0x2e6fbff6,0x5ffe46ff,0x540ffd99,0x1f96f82f,0x37dc03f4,0x7ff405fd,
    0x01ffeb9d,0xb27f45f7,0xb07fec9f,0x226ff8ff,0x897fe6ff,0x07fc45ff,
    0x235327e4,0xe80fe899,0x2e1fdc2f,0x80ff885f,0xda7e45fd,0xbd9ff84f,
    0x17fe4099,0x3f227fd4,0x24ffa82f,0xfdcefdcb,0x20ffea3e,0x17f62ffa,
    0x4f885df1,0x52fcafc4,0x3ff5007f,0x3ee05ff1,0x827fc41f,0x45fee0fd,
    0x71bf61ff,0x0ffe21ff,0x0ffe2dfb,0x85fd0bfd,0xfffd14fa,0x05f13ff9,
    0x43fb87fb,0x05fa84fc,0xb4fc8bfb,0x7bbfb09f,0xfd02ff40,0x3a05fe8d,
    0x3ffffa6f,0x3f25ffff,0x3fee0206,0xd0df001c,0x03f43f6d,0x5feeff88,
    0x04417fa0,0xaff88df0,0x22fec6fb,0x5ff11ff9,0x5ff36fc8,0x4fc85fd8,
    0x73bfd364,0x6c274fff,0x321fdc3f,0xb04fb84f,0xfb4fc8bf,0x1bfff509,
    0xfc813fe0,0xf9027fc7,0x55ff554f,0x13fa1bff,0x3ffffe00,0x903f601c,
    0x0feabfdf,0x04fffb80,0x440027fc,0xfdcfd84f,0x3ee3fec3,0xfd13fe0f,
    0x3fe27fcd,0xa745fb85,0xb37f46f9,0xfb8df70d,0x360ffa23,0xc8bfb03f,
    0x2a09fb4f,0x220cffff,0x3fee03ff,0x5c07ff10,0xf8bfc0ff,0x321ffc46,
    0x64c4eeee,0x705fffff,0x7459305f,0xfff70047,0x1ffc409f,0x5417d400,
    0x7ec0ffff,0xe8dfd13f,0x4dff50ef,0xffc8aefc,0x3e26fa85,0x4fd85f93,
    0x3ffe21ba,0x3faa7f71,0xb02fe80e,0xfb4fc8bf,0x4fffe809,0xfc80ffe2,
    0xc813fe27,0x3df510ff,0x7fc13bf5,0x37fffec4,0x4fffdb88,0xfa804f98,
    0xb81bff73,0xdaffdbff,0x0027fc3f,0xfff807e4,0xfefffd86,0x7ffcc2ff,
    0x3e66fffe,0x85feffff,0x747ea7fa,0xf897f41f,0x2e5ff704,0x205ff73f,
    0x8bfb01ff,0x809fb4fc,0x7fc7fbbd,0xf8dfb045,0xe9ff605f,0xffffffff,
    0x3311bf65,0x02a62dfd,0x1be0dfd1,0x56fc5fa0,0xfd27f44f,0x5fe85fff,
    0x0fd01570,0x7ec1ffe4,0x301dffbd,0x8df97ffb,0x5fc9dfd9,0x27e66fa8,
    0x3fe60ff8,0xff303f90,0x6ccfee1b,0x02fe80ff,0xb4fc8bfb,0xd8dd889f,
    0x7fec7f8b,0xbff59f50,0xf981ffd8,0x3bbff25f,0x3ee4eeff,0x22dfb02f,
    0x07fc84ff,0x9fd401fb,0x7c4df3fa,0x1bffe22f,0xff103ff2,0x3205f88b,
    0x24fd80ff,0x37e41000,0x84fd8135,0xfda7c5fb,0x27ddff62,0x1fdc5fc8,
    0x0ff60ffa,0x53f22fec,0xdcfe84fd,0x7fc45fbb,0xffffc9cf,0x4e7ffc40,
    0x6c0fffc9,0xd101fd0f,0x3f663bff,0x22bffa6f,0xf705ffa8,0x5f73f403,
    0x21bfd1fe,0x442fffe8,0xfd98bfff,0x4c1fd40f,0x9fb05ffb,0x26fc8000,
    0xffa9affc,0xb6c3fc83,0xfffedffa,0x0ff604fe,0x84fc87f7,0x8bfb04fc,
    0x709fb4fc,0x03ffffff,0xfffffff7,0xfff501df,0xf05fffff,0xe881be2f,
    0xffffffff,0x3ffffe62,0x7f301fff,0xcf88fea0,0x7ffd44f8,0x2ffffffe,
    0x7fffffd4,0x4c1fc83f,0xfb00ffff,0x6fc80009,0x3fffffe2,0xfb83fd06,
    0xfd37db32,0xfb02625b,0x7e43fb87,0xfd06fa85,0x9fb4fc89,0x037ffaa0,
    0xdffffd88,0xfd882fff,0xf880dfff,0xb880bf35,0x80cefffd,0x0dffffe9,
    0x87e82fc0,0xfa82fffd,0x5e99efff,0x5bfffb30,0x66e41fa0,0x000b2e00,
    0xcc887950,0x0df103cd,0x2a007fd1,0x5c2fe85f,0xe82fdc3f,0x4fff260f,
    0xbfb4fda9,0x00136035,0x007ec411,0x44260022,0x000c0009,0x81880026,
    0x005301a8,0x06002031,0x00000260,0x80000000,0xbff302fa,0x5fda8835,
    0x2e17fdcc,0x0dffdc3f,0xfffc8bee,0x369fff91,0x05904fff,0x00002000,
    0x00000000,0x00000000,0x00000000,0x00000000,0x01ba0000,0xfdffff91,
    0xff909fff,0xf887f70f,0x2e6e83ff,0x3332a1cd,0x00599952,0x00000000,
    0x00000000,0x00000000,0x00000000,0x00000000,0x05d10000,0x666dd440,
    0x017b700a,0x5b9105d5,0x00001d50,0x00000000,0x00000000,0x00000000,
    0x00000000,0x00000000,0x00000000,0x00000000,0x00000000,0x00000000,
    0x00000000,0x00000000,0x00000000,0x00000000,0x00000000,0x13ae0018,
    0xd907bb91,0x17740007,0x0f33332a,0x8805eed4,0x6d402dda,0x33b2202d,
    0xe885ec81,0x3bbbba2e,0x3b21eeee,0x34ee981e,0x3dd907dd,0xddd113b2,
    0x3b64ec81,0x7653b605,0xdddddd74,0x0fb27ddd,0xbddddd90,0x329d9079,
    0x83deeeee,0x3bfaa4ec,0xc801b622,0x7ffff45f,0x00027f45,0xfffe87ff,
    0xfffc86ff,0x7ffc40ff,0xfff986ff,0xfff984ff,0x437ec5ff,0x3ffe3ff8,
    0x22ffffff,0xffd85ff9,0xf987ff60,0xf51ff25f,0x24ff85ff,0xff981ffb,
    0x3ff2bfb3,0x4fffffff,0xffd809fb,0x0effffff,0x7ffed7f6,0x361effff,
    0x3ffff16f,0xf90037e4,0x7dd7fdcb,0x0013fa1f,0x6ffc3ff8,0x7fd43ccc,
    0x7dc4fe9c,0x6c2ff99e,0x41ffc9df,0x1ffb9efd,0x3fe21bf6,0x32aaaaa3,
    0x7fe40fff,0xf10ffea2,0x507ff4df,0x7ffe43ff,0xf88bfe64,0x30ffc84f,
    0x3aaaa635,0xfb1aaaef,0xaaffd809,0x363ffdaa,0x555ffb5f,0xb7ec9ffb,
    0x7ec40ffa,0x3215009e,0xfe93fa5f,0x01453fa5,0x7f98ffe0,0x2e65fd80,
    0x9f91ff42,0xbff0ffc4,0x8ffe1dc8,0x3ff886fd,0x407ffa20,0x41bfa6fe,
    0x2ffbbffb,0xdfd17fc4,0x207fdcdf,0x25fe86fe,0x0bfd0098,0x099893f6,
    0x97fe0dfb,0xb0dfb5fd,0x5c77ecff,0x3ff609ff,0x7ffe43ff,0x8ffe5fdc,
    0x337fa6fc,0xff003fff,0x05d7fd47,0x64033ff8,0x547fd15f,0x2037ec7f,
    0x1bf61ffa,0xfd80ffe2,0x33fe603f,0x3f601ffb,0x9ff05fff,0x43febfe2,
    0x1ffb86fc,0x5fd8bfe6,0x3f60bfd0,0x7ecbff34,0x7ec7ff06,0xff90dfb5,
    0x7ffef7ec,0x33ffae6f,0x3ef7ff22,0x45ff15ff,0x3fffa7fb,0xf804ffdb,
    0x3ffff23f,0x33fe20df,0xfd883efe,0x7fc44fff,0xfe81ffa1,0x4437ec3f,
    0x9ff903ff,0x9ffffb00,0x0ffff880,0x5beadfb0,0x109fd2ff,0x23fe49ff,
    0x0bfd05fd,0x3bfa33f6,0x2aabff60,0x3f60ffeb,0x7d44dfb5,0x36fbf66f,
    0x37e43cff,0xbff12ffc,0x7fb8bfe6,0x7fd83ffa,0x3f63ff80,0x264ffccf,
    0x3ffcefff,0x83ffffc8,0xfffb9dfd,0xd87fff00,0x83ff886f,0xf1006ffa,
    0xfd001dff,0x47fdc0bf,0xf19fb4fd,0xe9ff605f,0xe82fec4f,0xfdbfb05f,
    0xffffd81d,0x7ec2efff,0xffffffb5,0xab7ec5ff,0x88df907f,0x8aff43ff,
    0xe9ff22ff,0x007fdc6f,0x20988ffe,0x9bfe27fb,0x577ec6fb,0x7f4c4fea,
    0x2207feff,0x1bf64fe9,0xff30ffe2,0x7fdc001f,0xffffa802,0xff3ff301,
    0x3fe7bee5,0xf33ff500,0xd05fd85f,0x3fff60bf,0xecffd84f,0x2bfb05ff,
    0xeffffffd,0x7fab7ec2,0xff98df90,0xff8afec1,0x5fe9bf22,0x4110ffd4,
    0x7cc03ff8,0xf993fe1f,0xfb8bfe0f,0xff717507,0x7e4ff700,0x222ff887,
    0x54001fff,0x7fc401ff,0x3fe06fff,0x9ff30ffd,0x67fc40df,0x05fd87fb,
    0x3ff60bfd,0x37ec1fff,0xbfb0bff5,0x80267bf6,0x20ff56fd,0x1ffc46fc,
    0x23ff97fe,0x91bfa5fd,0x99bf21ff,0xa86ea2ff,0x997fe0ff,0x43ff30ff,
    0x7ec187fa,0xfb832e25,0xf303fee7,0x017ff45f,0x200ffd40,0x4ffbaffd,
    0xe8dfffb0,0x7ec04fff,0x5fd84fef,0x3f60bfd0,0x7ec5fe9f,0x361ffe46,
    0x200dfb5f,0x20ff56fd,0x1efe86fc,0xb7e4bff5,0x3ffa3ff8,0x7dcdfd13,
    0x21ffc8bf,0x91bf65fd,0xf17f23ff,0x3a27ec9f,0xe85ff33f,0x549fd14f,
    0xffd31dff,0x2677ff21,0x2a009999,0x3fea01ff,0x2e07ff65,0x7fe44fff,
    0x7ffd402f,0xd05fd81f,0x4d3f60bf,0x21bf62ff,0x57f61ffe,0xdfb006fd,
    0x7fdc1fea,0x3bffea4e,0x3fe65fff,0x7ff47fff,0x222fffef,0x44ffffff,
    0x2ffffff9,0x7fffffc4,0x7ffffdc2,0x7f7fdc1f,0xffffa86f,0x7ffec0ff,
    0x3fa4ffff,0xffffffff,0x407fea04,0x3e20fff8,0x2fff986f,0x4007ffd4,
    0xbfb06fff,0x7ec17fa0,0x6fd9bf64,0x3f66ff98,0x3600dfb5,0x220ff56f,
    0x7ecc4ffe,0x74c5fbbf,0x5ff41eff,0xc981cffb,0xfb504eff,0x3fa205df,
    0xffb701df,0x3fff203b,0x33ff6a04,0xfffff901,0xfffffe87,0x2a04ffff,
    0x7ff901ff,0xff09ff70,0x07ff881f,0x3607ff90,0x20bfd05f,0x4ffe24fd,
    0x7ff906fd,0x037ed7f6,0x0ff56fd8,0x80020088,0x40020008,0x20011000,
    0x00110008,0x40008006,0x00000001,0x00000000,0x00000000,0x00000000,
    0x00000000,0x00000000,0x00000000,0x00000000,0x00000000,0x00000000,
    0x00000000,0x00000000,0xb809d900,0x92ed80de,0xee983ddd,0x700bd73e,
    0x3bdb30bd,0x33333322,0x20bd90cc,0x26e983ee,0xeeeeeeeb,0xddddd90e,
    0x77649ddd,0x4403ceee,0x03302dda,0x2002f744,0x3b2605ea,0x777640ce,
    0xea82deee,0x0000001e,0x4c40554c,0x54c04c40,0x80bfb00a,0x3fe84ffc,
    0xfc87fffb,0x00ff94ff,0xffe88ff9,0x3ffffe62,0x0dfb0fff,0xffd113fe,
    0x7fffffe4,0xffffb0ff,0x7ecbffff,0x1effffff,0xffffff98,0x5c03fe60,
    0xf1001fff,0x3fffa0ff,0x3ff60fff,0x44ffffff,0x17d11ffa,0x226cc000,
    0x42fffffa,0x127ec5fd,0xb07ffffb,0xfffc80bf,0xffd9ff41,0xa7fff45f,
    0x7fc807fc,0x910bffa2,0x4dfd9999,0x49ff06fd,0x3f27ffe9,0x22aaaaaf,
    0xaaaaaffd,0x2abff62a,0xfe86ffca,0x263ffaae,0xfffd00ff,0x1fff6009,
    0x7f4cbfea,0x2aabff63,0x3ea0ffea,0x19fff11f,0x27ff5400,0xfff9fff5,
    0x3f62fec5,0x3f33ff24,0xa9afec2f,0x237ffe41,0xffdfb3fe,0xca7f7fc4,
    0x17fc807f,0x22007ffd,0x41bf61ff,0xffff74ff,0x6c037e4f,0x0dfb006f,
    0x7fc47ff5,0x0331fee2,0x03ff7fe6,0xb0ffff50,0x367fa87f,0x22ff986f,
    0x3fae1ffa,0xf9101dff,0x7f43bfff,0xbfb37f46,0x7ff14fd8,0x37f637e4,
    0xf90efffd,0x9ff47fff,0xf51ffdfd,0x1ff29fbd,0x7fedff20,0xb0ff6003,
    0x653fe0df,0x3f27faae,0x006fd806,0x17fa0dfb,0x400df902,0x03ff8efc,
    0x01ff3fe2,0x1bf66fc8,0xff983fea,0xefffda80,0x7dfffb12,0x5c3ff881,
    0xd8bfb0ff,0x557ff34f,0xeffd8ff9,0xbf93ffcb,0x4ffa1ffb,0xf93fdcfd,
    0x1ff29fb9,0x3ff7ff20,0x0df3000f,0xdddddffb,0x7fa869ff,0x33333ff2,
    0x3bbff60c,0x3f61eeee,0x880dfb06,0xff1004ff,0xfd81bfa7,0xf9007fab,
    0x777fec5f,0x7c42ffee,0xa7fe4407,0x2601eff8,0x8ffd42ff,0xaa7f45fd,
    0xffffffff,0xfe83ff60,0xbff1bf94,0x5e7ecffa,0x9fb5fd6f,0x3f201ff2,
    0x004fffff,0xfffb07fb,0x09ffffff,0x7ffe4ff5,0x3f61ffff,0x2fffffff,
    0x3fe41bf6,0x001ffd10,0x7fdc3fee,0xff56fa81,0xd87ff900,0xefffffff,
    0x36a07f81,0xfff13fff,0x13fe019f,0x17f61ff9,0x07fe29fd,0xbfb1bf60,
    0x4ffdd7f2,0xf19fb3fe,0x9fb1ff3f,0x3f201ff2,0x02ffcbff,0x7ec07fd4,
    0xffaaaaaf,0x3f27fa84,0x20cccccf,0xaaaaaffd,0x6c1bf60a,0x3ffd107f,
    0x5fe82a88,0xff113fe2,0xf301fea1,0x55ffb07f,0xf85ffb95,0x7fffe446,
    0xfffeb81c,0x98f7ec2d,0x99bf25fe,0xc93fa4ff,0x362fec4e,0x7f4bf95f,
    0x29fb3ffe,0x9fb6fdff,0x3f201ff2,0x80dff13f,0x0dfb04fc,0x9fea13fe,
    0x6fd806fc,0x3a0dfb00,0x1ffe885f,0x3e60ff98,0xffffffff,0x3bbbff20,
    0xbf702eff,0x7f41bf60,0xfff12f45,0xfb50017f,0x7ffc49ff,0x3ea0fffe,
    0x24fefdef,0x2ffdeffb,0x57f62fec,0x3ffe65fc,0x3f69fb3f,0x329fb4ff,
    0x47fc807f,0x3fa04ffb,0x3e0dfb02,0x327fa84f,0x06fd806f,0xff30dfb0,
    0x203ffd09,0x3ff20ff9,0x3fffffff,0x3ffffff2,0x059503ff,0x3fec1bf6,
    0x02ef88ae,0x889f9300,0xc80dfffd,0x44fcafff,0xd83efffb,0xfcafec5f,
    0xd9fffe45,0x25fff74f,0x33ff94fd,0x3f213333,0xf01ffe87,0x41bf603f,
    0x27fa84ff,0xefd806fc,0x21999999,0xea999efd,0x5ffe40ff,0x23cc1999,
    0x4dfd04ff,0xffcaaaa9,0x2055301a,0xb9999efd,0x42aa25ff,0x31000018,
    0x000800c0,0x45fd8022,0x88bf95fd,0x29fb3fff,0x9fb0fff8,0x3ffffff2,
    0x50ff92ff,0x0ff30dff,0x4ff837ec,0x1bf27fa8,0x3fffff60,0x3ff67fff,
    0x82ffffff,0x7fffffff,0x1ffa93a2,0x5403ff70,0x82fe407f,0xfffffffd,
    0x03fe61ff,0x00000000,0x7ec00000,0x5fcafec5,0x9fb3ffa8,0x29fb37fc,
    0xfffffffc,0x360ff92f,0x03fd44ff,0x13fe0dfb,0x06fc9fea,0xffffffd8,
    0x3fff67ff,0xfa80ceff,0x27ffffff,0x1037ec39,0x3fd409ff,0x7ec17f20,
    0x1dffffff,0x00007fcc,0x00000000,0x00000000,0x00000000,0x00000000,
    0x00000000,0x00000000,0x00000000,0x00000000,0x00000000,0x13551000,
    0x20055440,0x99880aa8,0x4c426620,0x26621a88,0x26219999,0x13109880,
    0x804c4198,0x443301ed,0x220aa889,0x4c26209a,0x1000002a,0x55555555,
    0x3ee86ea3,0x0bba27dd,0xeeea8000,0x4445752e,0x08888888,0x00000000,
    0xffffe880,0x7fff540e,0xffff905f,0xd2ffcc1d,0x7fe7f4df,0x3ffffea7,
    0x88ff91ff,0x54bf92ff,0x413f62ff,0x1ff982fe,0x5fffd7fd,0x361dfff7,
    0x0efffdcf,0x3ea03ff8,0x7ffffcc0,0x49fb4fff,0x229ff4ff,0x37f663ff,
    0x3fe2910a,0x4bfffea2,0xffff15fd,0x00ffffff,0x00000000,0x9ff97dfb,
    0xffbacfe8,0x75effdc3,0x657fdc5f,0x3fffa1ff,0x3bbba64e,0x5ff11fff,
    0x4ff53fdc,0x0bfe4ffc,0x7fcc17f4,0xfd7bffd1,0x27ff97ff,0xffdbeffd,
    0x4c37fd43,0x3a61579a,0x4eeeeeee,0xfa7fc9fb,0x2a5ff13f,0xfeffffff,
    0xcc997e66,0x22bfb1cc,0xbbbbbbbb,0x0000003b,0x20b98000,0x2ffe25fc,
    0x4bff0330,0x7fec0ce9,0x07ff43ff,0x3617fe40,0xf893fa5f,0x26dffd1f,
    0x3eaaa27f,0x8661aacf,0x8ffea6fe,0x41ffb4fe,0x7fff44fe,0x7ffffe42,
    0x6c7b0003,0x7fc5fd3f,0xff957f51,0x00c987ff,0x00000000,0x30000000,
    0xfc8dffd9,0x7c40beff,0xfff1003f,0x900bfd0b,0x1ff507ff,0xbfd83ff3,
    0xfc8feef8,0x3ffffe65,0x3fa05fff,0xfd87fea4,0x5fd8dfb5,0x21befbea,
    0x2e20dfe8,0x2bbbbbbb,0xb8edc1f7,0x8043720d,0x000000aa,0x00000000,
    0x3fea0000,0x6c46fedf,0x262fffff,0x3f6002ff,0x405fe84f,0x3fe04ffb,
    0xefa86fca,0xfeafccfa,0x3ffbba62,0x3fa04eee,0xfd83fe64,0x5fd8bfb5,
    0x07fe2ffa,0x7cc5f7f9,0x4fffffff,0x00000037,0x00000000,0x00000000,
    0xc867fc40,0xff95106f,0x2e27fc4d,0x7fffdc0a,0xf5027f42,0xedfc80bf,
    0xfdff883f,0x00ffdfaa,0x7f400bfa,0xfd83fe64,0x5fd8bfb5,0x17f21ff3,
    0xdd88b679,0x03dddddd,0x00000000,0x00000000,0x30000000,0x337f43ff,
    0x237dc3fd,0x1ff50efe,0x7ff67fc4,0x7cc13fa0,0x409999ef,0xd00ffff8,
    0xfff11fff,0x882fe80b,0x4c9fd0aa,0x6d7f60ff,0xfdafec5f,0x0007fe65,
    0x00000000,0x00000000,0x00000000,0x7677f400,0x6ffec6ff,0x7fcc2ffd,
    0x7f44ffef,0x3a5ff98e,0xffffb04f,0xffb09fff,0xd37fdc09,0x2fe807ff,
    0x9fd1ff98,0xbfb07fcc,0x0bfb17f6,0x00000000,0x00000000,0x00000000,
    0xa8000000,0x0ffadffd,0x0f7ffb22,0x05f7ff4c,0x7fe45ff7,0x3f609fd2,
    0x84ffffff,0x3e201ffa,0x003ff24f,0x3ff30131,0x0ff993fa,0x22fed7f6,
    0x000005fd,0x00000000,0x00000000,0x00000000,0x08001000,0x00002200,
    0x00000000,0x00000000,0x00000000,0x00000000,0x00000000,0x00000000,
    0x00000000,0x00000000,0x00000000,0x00000000,0x00000000,0x00000000,
    0x00000000,0x00000000,0x00000000,
};

static signed short stb__arial_bold_20_usascii_x[95]={ 0,1,0,0,0,0,0,0,0,0,0,0,1,0,
1,-1,0,1,0,0,0,0,0,0,0,0,1,1,0,0,0,0,0,0,1,0,1,1,1,0,1,1,0,1,
1,1,1,0,1,0,1,0,0,1,-1,0,0,-1,0,1,-1,0,1,-1,0,0,1,0,0,0,0,0,1,1,
-1,1,1,1,1,0,1,0,1,0,0,1,0,0,0,0,0,0,1,0,0, };
static signed short stb__arial_bold_20_usascii_y[95]={ 16,3,3,2,2,2,2,3,2,2,2,5,13,10,
13,2,3,3,3,3,3,3,3,3,3,3,6,6,4,6,4,3,2,3,3,2,3,3,3,2,3,3,3,3,
3,3,3,2,3,2,3,2,3,3,3,3,3,3,3,3,2,3,2,17,2,6,3,6,3,6,2,6,3,3,
3,3,3,6,6,6,6,6,6,6,3,6,6,6,6,6,6,2,2,2,7, };
static unsigned short stb__arial_bold_20_usascii_w[95]={ 0,4,8,10,10,16,13,4,6,6,7,10,3,6,
3,6,10,7,10,10,10,10,10,10,10,10,4,4,10,10,10,11,18,13,12,13,12,11,10,13,11,3,9,12,
10,13,11,14,11,14,12,12,11,11,13,17,12,13,11,5,6,5,9,12,5,10,10,10,10,10,7,10,9,3,
5,9,3,14,9,11,10,10,7,10,6,9,10,14,10,10,9,7,3,7,10, };
static unsigned short stb__arial_bold_20_usascii_h[95]={ 0,13,5,15,16,15,15,5,18,18,8,10,6,3,
3,15,14,13,13,14,13,14,14,13,14,14,10,13,11,7,11,13,18,13,13,15,13,13,13,15,13,13,14,13,
13,13,13,15,13,16,13,15,13,14,13,13,13,13,13,17,15,17,8,3,4,11,14,11,14,11,14,14,13,13,
17,13,13,10,10,11,14,14,10,11,14,11,10,10,10,14,10,18,18,18,5, };
static unsigned short stb__arial_bold_20_usascii_s[95]={ 254,194,163,113,72,158,175,172,47,1,140,
89,159,194,201,203,27,84,128,103,158,59,70,61,81,92,100,139,210,148,199,
169,8,144,181,189,115,103,92,124,72,252,49,48,37,23,11,98,240,83,223,
138,201,114,183,165,152,138,126,66,151,60,130,205,188,1,38,23,16,243,1,
243,1,197,54,213,236,105,120,221,221,232,45,12,9,233,63,74,34,210,53,
39,35,27,177, };
static unsigned short stb__arial_bold_20_usascii_t[95]={ 1,35,49,1,1,1,1,49,1,1,49,
49,49,49,49,1,20,35,35,20,35,20,20,35,20,20,49,35,35,49,35,
35,1,35,35,1,35,35,35,1,35,20,20,35,35,35,35,1,20,1,20,
1,20,20,20,20,20,20,20,1,1,1,49,49,49,49,20,49,20,35,20,
1,35,20,1,20,20,49,49,35,1,1,49,49,20,35,49,49,49,1,49,
1,1,1,49, };
static unsigned short stb__arial_bold_20_usascii_a[95]={ 80,95,136,159,159,255,207,68,
95,95,111,167,80,95,80,80,159,159,159,159,159,159,159,159,
159,159,95,95,167,167,167,175,279,207,207,207,207,191,175,223,
207,80,159,207,175,239,207,223,191,223,207,191,175,207,191,270,
191,191,175,95,80,95,167,159,95,159,175,159,175,159,95,175,
175,80,80,159,80,255,175,175,175,175,111,159,95,175,159,223,
159,159,143,111,80,111,167, };

// Call this function with
//    font: NULL or array length
//    data: NULL or specified size
//    height: STB_FONT_arial_bold_20_usascii_BITMAP_HEIGHT or STB_FONT_arial_bold_20_usascii_BITMAP_HEIGHT_POW2
//    return value: spacing between lines
static void stb_font_arial_bold_20_usascii(stb_fontchar font[STB_FONT_arial_bold_20_usascii_NUM_CHARS],
                unsigned char data[STB_FONT_arial_bold_20_usascii_BITMAP_HEIGHT][STB_FONT_arial_bold_20_usascii_BITMAP_WIDTH],
                int height)
{
    int i,j;
    if (data != 0) {
        unsigned int *bits = stb__arial_bold_20_usascii_pixels;
        unsigned int bitpack = *bits++, numbits = 32;
        for (i=0; i < STB_FONT_arial_bold_20_usascii_BITMAP_WIDTH*height; ++i)
            data[0][i] = 0;  // zero entire bitmap
        for (j=1; j < STB_FONT_arial_bold_20_usascii_BITMAP_HEIGHT-1; ++j) {
            for (i=1; i < STB_FONT_arial_bold_20_usascii_BITMAP_WIDTH-1; ++i) {
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
        float recip_width = 1.0f / STB_FONT_arial_bold_20_usascii_BITMAP_WIDTH;
        float recip_height = 1.0f / height;
        for (i=0; i < STB_FONT_arial_bold_20_usascii_NUM_CHARS; ++i) {
            // pad characters so they bilerp from empty space around each character
            font[i].s0 = (stb__arial_bold_20_usascii_s[i]) * recip_width;
            font[i].t0 = (stb__arial_bold_20_usascii_t[i]) * recip_height;
            font[i].s1 = (stb__arial_bold_20_usascii_s[i] + stb__arial_bold_20_usascii_w[i]) * recip_width;
            font[i].t1 = (stb__arial_bold_20_usascii_t[i] + stb__arial_bold_20_usascii_h[i]) * recip_height;
            font[i].x0 = stb__arial_bold_20_usascii_x[i];
            font[i].y0 = stb__arial_bold_20_usascii_y[i];
            font[i].x1 = stb__arial_bold_20_usascii_x[i] + stb__arial_bold_20_usascii_w[i];
            font[i].y1 = stb__arial_bold_20_usascii_y[i] + stb__arial_bold_20_usascii_h[i];
            font[i].advance_int = (stb__arial_bold_20_usascii_a[i]+8)>>4;
            font[i].s0f = (stb__arial_bold_20_usascii_s[i] - 0.5f) * recip_width;
            font[i].t0f = (stb__arial_bold_20_usascii_t[i] - 0.5f) * recip_height;
            font[i].s1f = (stb__arial_bold_20_usascii_s[i] + stb__arial_bold_20_usascii_w[i] + 0.5f) * recip_width;
            font[i].t1f = (stb__arial_bold_20_usascii_t[i] + stb__arial_bold_20_usascii_h[i] + 0.5f) * recip_height;
            font[i].x0f = stb__arial_bold_20_usascii_x[i] - 0.5f;
            font[i].y0f = stb__arial_bold_20_usascii_y[i] - 0.5f;
            font[i].x1f = stb__arial_bold_20_usascii_x[i] + stb__arial_bold_20_usascii_w[i] + 0.5f;
            font[i].y1f = stb__arial_bold_20_usascii_y[i] + stb__arial_bold_20_usascii_h[i] + 0.5f;
            font[i].advance = stb__arial_bold_20_usascii_a[i]/16.0f;
        }
    }
}

#ifndef STB_SOMEFONT_CREATE
#define STB_SOMEFONT_CREATE              stb_font_arial_bold_20_usascii
#define STB_SOMEFONT_BITMAP_WIDTH        STB_FONT_arial_bold_20_usascii_BITMAP_WIDTH
#define STB_SOMEFONT_BITMAP_HEIGHT       STB_FONT_arial_bold_20_usascii_BITMAP_HEIGHT
#define STB_SOMEFONT_BITMAP_HEIGHT_POW2  STB_FONT_arial_bold_20_usascii_BITMAP_HEIGHT_POW2
#define STB_SOMEFONT_FIRST_CHAR          STB_FONT_arial_bold_20_usascii_FIRST_CHAR
#define STB_SOMEFONT_NUM_CHARS           STB_FONT_arial_bold_20_usascii_NUM_CHARS
#define STB_SOMEFONT_LINE_SPACING        STB_FONT_arial_bold_20_usascii_LINE_SPACING
#endif
