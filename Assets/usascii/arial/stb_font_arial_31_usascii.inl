// Font generated by stb_font_inl_generator.c (4/1 bpp)
//
// Following instructions show how to use the only included font, whatever it is, in
// a generic way so you can replace it with any other font by changing the include.
// To use multiple fonts, replace STB_SOMEFONT_* below with STB_FONT_arial_31_usascii_*,
// and separately install each font. Note that the CREATE function call has a
// totally different name; it's just 'stb_font_arial_31_usascii'.
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

#define STB_FONT_arial_31_usascii_BITMAP_WIDTH         256
#define STB_FONT_arial_31_usascii_BITMAP_HEIGHT        120
#define STB_FONT_arial_31_usascii_BITMAP_HEIGHT_POW2   128

#define STB_FONT_arial_31_usascii_FIRST_CHAR            32
#define STB_FONT_arial_31_usascii_NUM_CHARS             95

#define STB_FONT_arial_31_usascii_LINE_SPACING          20

static unsigned int stb__arial_31_usascii_pixels[]={
    0x30000026,0x00620003,0x13100262,0xee880c40,0x2bdddd51,0x01eeeee8,
    0x880001c8,0x04400000,0x20262000,0x01880009,0x20022000,0x00040019,
    0x09800131,0x06e81dd1,0x3ffb2200,0x002dffff,0x2e01dff5,0x9ffb104f,
    0xff883740,0x2dffff71,0x01fffff8,0x00033ee6,0xbfffd951,0xfb910005,
    0x0017dfff,0x2fcc3fc8,0x7fff5c40,0x22002cef,0x2dfffeca,0xf5001fd0,
    0xfc801dff,0x4cfee002,0x017d41ff,0x3ffff660,0xfffffeef,0x3fffd403,
    0xffb04fb8,0x407ee09f,0x93311ff8,0x26ffe2df,0xffffd501,0xfd8805bf,
    0xffffffff,0xfff7001e,0x5fffffff,0x2e0fec00,0x7ffdc04f,0x4fffffff,
    0xfffffc80,0x5c0effff,0x6ffd403f,0xdf100ffe,0xf31fd800,0x400dd03f,
    0x881cfffa,0x00dffeca,0x7dc17fcc,0x00bff884,0xfb80017e,0x4c05ff16,
    0xffefdfff,0xdffd102f,0xffd73137,0xfffd805f,0xffdb989b,0x90ff003f,
    0x7ffec05f,0xfeb989ac,0xffe880ef,0xfec98adf,0x017e60ef,0x827e43f9,
    0x3fc002fc,0x7f503ff3,0x019ff700,0x4037fdc0,0x84fb83fd,0x3ee00ffa,
    0x5bee0001,0xfd102ff8,0xfd15f13d,0x09ffb01f,0x700fffa8,0x7cc01bff,
    0x37c401ff,0xffb807f4,0x1ffdc00e,0x36027fec,0x203fc4ff,0x4437d46f,
    0x27cc006f,0x3fa03ff3,0x00bfea00,0x2027fd40,0x84fb84fc,0x1be206fa,
    0xf7015510,0x4c0bfe2d,0x2a5f12ff,0x27fdc2ff,0x886ffb80,0xff5005ff,
    0x227d401d,0xdff107f8,0x2a3fec00,0xff8806ff,0x4c07f60f,0x6c3fc45f,
    0x17dc001f,0x3f203ff3,0x205ff103,0x42620bc9,0x3f201ffa,0xfa84fb84,
    0x100ff206,0x2df703ff,0xff702ff8,0x837917c4,0x32000ffd,0x07fec0ff,
    0x4c5ff700,0xaadfdaaa,0x5c2aefba,0x3e6001ff,0x003ff62f,0x7f50f7d4,
    0x1fe1bea0,0xfd000bf3,0x980ffcc1,0x84fc80ff,0xf3fffffb,0x901fdc7f,
    0x509f70bf,0x03fe20df,0xf703ff10,0x5c0bfe2d,0x005f10ff,0xf98007ff,
    0x013fe22f,0x7ec7ff10,0xffffffff,0x360fffff,0x4418006f,0x404004ff,
    0x8ff306f8,0x00fec6f8,0xff31be20,0x2217fc03,0xbdffa87f,0x21ffcffc,
    0x17f205f9,0x1bee13ee,0x7c4037d4,0xf16fb81f,0x4bfe605f,0x7fcc02f8,
    0x24ff8001,0xe8002ff9,0x3f332a5f,0xdfeccccf,0x0027f44c,0x001ffd40,
    0xff00fe80,0xbf327dc3,0x989f5000,0x0ff601ff,0x3ff989f5,0x207fff44,
    0x217ee07f,0x05fc84fb,0xff100bf9,0x3e2df703,0x2fffe02f,0x7fdc02f8,
    0x26fe8000,0xc8001ffa,0xd0df107f,0x07ff101f,0x05ff7000,0x40bf2000,
    0x0ffdcffb,0x320007f6,0x00ffcc1f,0x21fc89f9,0xff704ff8,0x2a03fb0d,
    0xc84fb86f,0x009fb04f,0xdf703ff1,0xf880bfe2,0x200cffff,0xf90007fc,
    0x003fee1f,0x2a03fee0,0xa83fc44f,0x266201ff,0xf9099999,0x2600001f,
    0x3ffee04f,0x0017e61e,0x0ffcc3fc,0x46e8df70,0xff300ffb,0x2207f909,
    0x227dc2ff,0x7fd01ff8,0x703ff100,0x00bfe2df,0xdfffffb1,0x000ffb03,
    0x7fe43ff2,0x1ffa8000,0x2fcc3fc8,0x3201ffb8,0x6fffffff,0x00001ff7,
    0x404c03fc,0x336e21fe,0xf30bf301,0x23fd403f,0x2027ec5f,0x01fd83ff,
    0x7dc73fe6,0x20bfd714,0xf8802ff8,0xf16fb81f,0x3ee2005f,0x7dc3ffff,
    0x7fd8000f,0x20007fea,0x83fb07fc,0x7ff303fb,0x7ffffe40,0x05ff36ff,
    0x00fec000,0xff32fd40,0x7f709fff,0x5403ff30,0xf89f30ff,0x07fe603f,
    0xff3003fe,0x7fcd3ee7,0x007fe603,0x3ee07fe2,0x4005ff16,0x1fffcaf8,
    0x20007fe6,0x0bfe25fe,0xa997f600,0xeaaabffa,0x7fc2aacf,0x26666205,
    0x7ff16fd9,0x1fdc0000,0xfb0ff400,0xd83fd519,0x01ff980f,0x1fdc3fea,
    0x7d403ff3,0xc806f987,0x269f73ff,0x3fe605ff,0x81ff8801,0x05ff16fb,
    0xff897c40,0x40017fc5,0x01ffc4ff,0xffb27f40,0xffffffff,0x7ec1ffff,
    0x26fd8006,0x6ec004fe,0x4005f882,0x3237c5fa,0xf9837c5f,0xa9fee01f,
    0x807fe64f,0x03fd86fd,0x9f70efec,0x44077e44,0xff8803ff,0xff16fb81,
    0xb17c4005,0x206fe8ff,0x6c2ffc81,0x3ee000ff,0x3bf72a2f,0xccffdccc,
    0x00ffdc4c,0xefd9bf60,0x09ff3000,0x1fd001fa,0x9bea27cc,0x3ff304fa,
    0xbf13fe40,0xff504ff8,0x4406fc89,0x427dc1ff,0x09ff02fe,0xf703ff10,
    0x640bfe2d,0xfb8be24e,0x40ffee0f,0x0bff32ee,0x22009ff5,0x2fc80fff,
    0x3e602fd4,0x3f6001ff,0x4017fea6,0x5f901ffd,0xf713ea00,0x3f27f989,
    0x403ff302,0x363746fe,0x2ffe886f,0xf5007fee,0xf909f70d,0x2017fe0b,
    0x6fb81ff8,0x3f605ff1,0x7fd8be27,0x6c43ffe8,0x00ffeeff,0xe8809ffb,
    0x83fd02ff,0xffc803fb,0x7fe4401f,0x2027ff46,0x3ea05ffb,0xa81fd004,
    0xfd37cc5f,0x807fe601,0x50fec4ff,0xff513bff,0x7ffb5bff,0xf70df700,
    0x320bf709,0x1ff8806f,0x5ff16fb8,0x7c47fea0,0xd10bff12,0x2e215bff,
    0x2203ffff,0x260aeffe,0x3e04fffb,0xb002fd87,0x3137bfff,0x85ffff95,
    0x20bdfff9,0x200effd9,0x4fa806f8,0xa7dc7f98,0x3fe605f8,0xb83ff101,
    0x7fffdc4f,0xfffff9df,0x0bf9001f,0x0df709f7,0x3e201fea,0xf16fb81f,
    0x3ffe205f,0xffd9af8b,0xffffd101,0xffffffff,0xffffd805,0x03ffffff,
    0x03fe1be6,0xfffffb80,0x0cffffff,0xfffffd30,0x001dffff,0x0fe801fb,
    0xfd519fd0,0xf980fee3,0x10ff501f,0xdfda83ff,0x82f7fae3,0x0bf90198,
    0x0df509f7,0x3e200ffc,0xf16fb81f,0x7ffcc05f,0x03fffefe,0xefffdb98,
    0x1effc9ac,0x3ffff660,0x7d400adf,0x40037c44,0xffffeca8,0xeb8801ce,
    0x02ffffff,0xfb80fee0,0x3fffe604,0x0007f63f,0x3ea07fd0,0xf980000f,
    0x709f903f,0x40df509f,0x7fcc05fc,0xff16fb81,0xfffd9805,0x30001eff,
    0x007fa601,0x260004cc,0x0015441a,0x0000cc40,0x00026a62,0x0ed806a2,
    0x20e65c40,0x7cc0002a,0x00f7e406,0x40bff700,0x84fb84fd,0x3fe206fa,
    0x203fea01,0x05ff16fb,0x00067d40,0x00014000,0x00000000,0x00000000,
    0x00000000,0x17ec0000,0x00effec0,0x01bff910,0x27dc1ffc,0xf5007fcc,
    0x4dfd7509,0xf16fecc9,0x880199bf,0x0000002f,0x00000000,0x00000000,
    0x00000000,0x00000000,0x75400bf3,0x99bcefff,0x2fffeba9,0x03ffb510,
    0x37fe09f7,0xf81fd00b,0x3fee3fff,0xffff16ff,0x01e8803f,0x00000000,
    0x00000000,0x00000000,0x00000000,0x3fb00000,0xffff7000,0xffffffff,
    0x5fffa809,0x3ee09f70,0x49f304ff,0x64c2ded8,0x33323ccc,0x000000cc,
    0x00000000,0x00000000,0x00000000,0x00000000,0x01362000,0xdb975300,
    0x26003579,0x0faa03ee,0x3203eda8,0x00000005,0x00000000,0x00000000,
    0x00000000,0x00000000,0x00000000,0x00000000,0x00000000,0x00000000,
    0x00000000,0x00000000,0x00000000,0x00000000,0x00000000,0x0880000c,
    0x50055300,0xba8aa235,0x2e6000ac,0x401530ac,0x3530acb9,0x00200980,
    0x2605db00,0xd101bdec,0x64c0003d,0x5400bdee,0xcccccccc,0x3bb2a01c,
    0x3b60003d,0x2cedc984,0x9ddb9100,0x807ba203,0x01efffd8,0x7fffedc0,
    0x5ff300cd,0xf88ffc40,0xfffffe8f,0x7fffd404,0xa83fd9ff,0xcaffffff,
    0xfffd984f,0x0002ec44,0xfff10bfe,0xf105ffff,0x3ee0003f,0x01ffffff,
    0x3ffffff6,0xffb02fff,0x001dffff,0xffb8bfd0,0x201fffff,0xfffffffa,
    0x301ff884,0x1fffdfff,0xffffd100,0x203dffff,0x9bee05fe,0xaacfeff8,
    0xff303ffc,0xfdff735d,0xabeff987,0x444ffffc,0x6c2ffffe,0x7fc0005f,
    0x4c577ec2,0x7fc41ffd,0xdffa8001,0x01ffeb8a,0xddddddfd,0x7ffd03dd,
    0x00dffb33,0x7fdcbfd0,0x0ffeb9cf,0xa8beff98,0x7fc43ffe,0x263dfd01,
    0x7fc404fe,0xfc9999cf,0x0ffb82ff,0x7fc49fd0,0x41ffb83f,0xff985fe8,
    0x217fa23f,0x7d44fff9,0x7ec088bf,0x17fc0005,0xdfb01df7,0x8001ff88,
    0x0bff06ff,0xa8003ff1,0x2ffa82ff,0xf8aff400,0x86fc80ef,0x7fe80ffd,
    0x217fc400,0x7fdc07fb,0x217fe602,0xff983ff8,0xe81bfe20,0x807fd45f,
    0x3fee3ffb,0xb89ff500,0x02fec07f,0x7c4bfe00,0x43ff303f,0x54001ff8,
    0x0ff902ff,0xe8001ff3,0x013fa04f,0x3feebfd0,0xff0ffa01,0x007fea09,
    0x7d41ff98,0x01bf600f,0x3f603ff6,0x7c46fc86,0x91bee02f,0x1ffc40bf,
    0x4ff809f9,0xea9837e4,0x5cc02aef,0x2a5ff0ac,0x93fa01ff,0x79951ff8,
    0xa812a201,0x037dc0ff,0x8803fe60,0x95fe8000,0x45fc80df,0x3ff304ff,
    0xff805544,0x3a02fec5,0x1ee9805f,0x7fc0ffa8,0x300ffc43,0x027ec1ff,
    0x03fe8ffe,0xfda9a7f4,0x3fee1aae,0xfa80ffff,0xff9effff,0xfc80ff72,
    0x3f6bfe25,0x0004ffff,0x8bf90df9,0x0037dc00,0xfb5fe800,0x6c7fb80b,
    0x88ff907f,0x7ff901ff,0xf9007ff6,0xff00001f,0x2207fd47,0x3fe600ff,
    0xfd00ffe1,0x3601ffc7,0xfffffb4f,0x77f6549f,0x77fcc0cc,0x2ffffcab,
    0x6fc80dfb,0x2b7fffe2,0x2005ffda,0xfe82ffb8,0x0dfffc9b,0xdb714fc8,
    0x7f400059,0xfc80dfb5,0x5067fd47,0x1ff889ff,0x3ffbffa0,0xbfffa801,
    0x9bf20001,0x0ff885fd,0xfe83fe60,0xff1ff404,0x974fe807,0xb0599ffd,
    0x17fa20bf,0x7ecbffe6,0xf13fdc05,0x3ff707ff,0x2fffdb80,0xfffffff0,
    0xcfd85fff,0xdffffff9,0x95fe8000,0x7ff403ff,0x7f7ff4c0,0x1ff883ff,
    0x03bffea0,0xfffffb80,0x3e6000ac,0xf105ff1f,0x23fd403f,0x1ffc05fd,
    0x4fe809fd,0x3f6037e4,0x201ff705,0x0bfd2ffb,0x3fe27fb8,0xd017fa05,
    0xf101dfff,0x3ee237ff,0x3f7fa0ff,0x5fffcaef,0xf55fe800,0x3ffea09f,
    0xfffffc81,0x01ff880e,0x01dffff5,0xffffea80,0xfd003eff,0x3e20ff57,
    0x917f202f,0x1ffc40df,0x7fcc0df9,0x36037e44,0x40bf905f,0x0bfd2ff8,
    0xff10ffa8,0x203fdc05,0x43fffcab,0xff302ed9,0x40ffff4b,0x74002ffb,
    0x4b7ff65f,0x20ffffd9,0xfcadffe9,0x0ffc42ff,0x7fe6ffe4,0xdb9800c5,
    0x00dfffff,0x827e77dc,0xff106ff8,0x902ff987,0x1ffc47ff,0x7e44ffd8,
    0xd82fec06,0xd97fc04f,0x13fdc05f,0x7fd403ff,0x5ff91000,0x74ff9000,
    0x1bfa04ff,0x744bfd00,0xaeffffff,0x037fe0ff,0x7c45ff91,0xb27fec1f,
    0x07fe67ff,0xdfff9300,0x7fffc401,0x1bfff101,0xfc82ff44,0x3fff662f,
    0x44e7fe43,0x644ffffc,0x82fec06f,0x97f403ff,0x3fe406fc,0x7cc01ff1,
    0x3fe2001f,0x0ffa8004,0x7dc03ffb,0x42ff4007,0xf54efffc,0xf017fd4f,
    0x10ffc49f,0xffe887ff,0x20007fca,0x6c03ffc8,0x3fe206ff,0xeffedffe,
    0xbdffb100,0x907ffdff,0xf9ffffff,0x406fc87f,0x07fd05fd,0x0df72fe8,
    0x3fe26fc8,0x003fe600,0x3000ffb0,0x01ff23ff,0x74001ff5,0xf702205f,
    0x3203fe4d,0xb87fe27f,0xfff980ff,0x01dcc4ff,0xfa80bfd0,0x27fe203f,
    0x00cefffb,0xf4ffffb8,0x3fb6a07f,0xfc87ff2d,0xd82fec06,0xa97fc04f,
    0x12fec07f,0x3fd401ff,0xffb80553,0xfa805510,0xb80ff70f,0x407b627f,
    0x7ec004ff,0xf5017fa5,0xd87fe21f,0x3ffea06f,0x007fdc0f,0x7cc07fc8,
    0x87fe200f,0x83100019,0xff8003ff,0x36037e42,0x40df705f,0x5ff12ff8,
    0xf88ffe20,0xc9bf202f,0x9bfa00ff,0x3f200ffc,0xc807fe67,0x20bfe25f,
    0x0b932ff8,0xff917fc4,0x3e27fd80,0x807ff21f,0xff886ffc,0x80bfb002,
    0x7fc404fc,0x3e000001,0x980f2e3f,0x037e41ff,0x7fcc17f6,0x6c5ff902,
    0x41df705f,0xff106ff8,0xa827fd47,0x13fea4ff,0x3fa1ffcc,0xf87ff105,
    0x11ffa85f,0x1bf207ff,0x3e205ff5,0xa87fe25f,0xfff304ff,0x05ffd0bf,
    0x2602ffa8,0x7fc401ff,0x3e000001,0x407fea3f,0x06fc87fe,0x6404ffe4,
    0x3ff662ff,0x513fe62f,0xfff885ff,0x7437f445,0x3fae22ff,0x057ff40f,
    0xff50ffd3,0x077f5419,0x2a273ff2,0x3bfa0fff,0x7407fe41,0x7ff542ff,
    0xfd07fe21,0x7ffd447f,0x7fd45ffe,0xf9531adf,0xfcca81df,0x1ff8805f,
    0x3fe00000,0x2b3bfe23,0xc81ffeb9,0x7ffd406f,0xeeffd81f,0x642fedff,
    0x5ffedfff,0xdffcff88,0xf881fffe,0xffffdfff,0xdffff881,0xf700effe,
    0x1dfffbff,0xffffff10,0xfff883ff,0x102fffde,0xfffbfffd,0x41ff887f,
    0xffefffe8,0x4ffe89ef,0x7fffff4c,0xa80dffff,0x8800efff,0x000001ff,
    0xfff30ffe,0x203fffff,0xffc806fc,0xffeb882f,0xd505fd4f,0x2205bfff,
    0xbffff77f,0x7ffe4401,0x32200cff,0x804fffff,0x0cffffe9,0x3ffff620,
    0xfffb101d,0xff90039d,0xf101bfff,0x3fff203f,0x07ec0cef,0x7ffff644,
    0x376203df,0x1991000b,0x66400000,0x37bd9701,0x0037e401,0x00310011,
    0x20001310,0x1a980018,0x00099800,0x98800130,0x00662001,0x0000cc40,
    0x00801310,0x00001310,0x00000000,0x00000000,0x00000000,0x00000000,
    0x00000000,0x00000000,0x00000000,0x00000000,0x00000000,0x00000000,
    0x00000000,0x00000000,0x00000000,0x00000000,0x09d90000,0x26027640,
    0xeeee9800,0xeeeeeeee,0x00fbae5e,0x75c5ed88,0x5dd5002e,0x2e007754,
    0x4ed805ee,0xb8001dd9,0xdddd30ee,0xdddddddd,0x3ba25ddd,0x3bbb2001,
    0xbceeeeee,0x03dd100a,0x777776c0,0xb02ceeee,0x3b2001bd,0xa8007db4,
    0x006fe8ee,0x3fae17fa,0xf300cfff,0xffffffff,0x7c4fffff,0xff9000ff,
    0x00fff885,0x3e62ffc4,0x7fff402f,0x54ffe200,0x7f4003ff,0x3ffffea5,
    0xffffffff,0x03ff12ff,0x7fffff40,0xefffffff,0x001ff880,0x3ffffffa,
    0x41ffffff,0xfb005ffe,0x50013feb,0x00dfd3ff,0xffd12ff4,0x05ffffdf,
    0x55555551,0x8dff9555,0xfa806ffa,0x0dff304f,0xff80ffe8,0x3fffe204,
    0xf87fea02,0x3fe6006f,0x2aaaaa22,0xaaaaefea,0x03ff10aa,0x55577f40,
    0xffebaaaa,0x00ffc40f,0x5555dfd0,0x1fffd995,0x4017fff4,0x009ff5fd,
    0x6fe9ffa8,0xfd97fa00,0xfff711cf,0x3fe20001,0x03ffd80f,0xc803bfa2,
    0x3ff903ff,0xfa81bf60,0x3f204fce,0x8007fe47,0x3fa007fc,0x01ff8806,
    0x6401bfa0,0x0ffc43ff,0x700bfd00,0x7fff4bff,0xfafec00f,0x7fd4004f,
    0x3a006fe9,0x20bff35f,0x88004ff9,0xff101ffe,0x07ff201f,0xf507ffa0,
    0x03fdc07f,0x40ff59f9,0x1ffcc5fe,0x2004ff80,0xff8806fe,0x01bfa001,
    0x3e22ffc4,0x17fa001f,0xdfd3ff40,0x5fd80bff,0xfa8009ff,0x2006fe9f,
    0x05ff75fe,0x6c0037f4,0x7fd403ff,0x004ff985,0x7fc4dff3,0x80ffcc05,
    0x81ff8afe,0x6fe82ff8,0x000ffa80,0x3e201bfa,0x0379731f,0x7ec00dfd,
    0xa80ffc47,0x4017fa2a,0x99fd1ffb,0xafec05ff,0x7d4004ff,0x2006fe9f,
    0x80b955fe,0x7e4007fb,0x5ffb005f,0x5c006fe8,0x01ffd4ff,0xff307ff0,
    0x7fd41ff4,0x401ffa80,0x7f4006fd,0xdaff8806,0x20efffff,0x3fe006fe,
    0x6c0ffc46,0x017fa2ff,0xcfe8ffe4,0xfb00ffe8,0x50013feb,0x00dfd3ff,
    0x36002ff4,0x3fea005f,0x3ffe2006,0x0003ff70,0x05ffbffb,0x3ee17f60,
    0x3f217f25,0x8813fe06,0x7f4002ff,0xffff8806,0x26ffebbe,0xff7006fe,
    0x6c1ff889,0x02ff41ff,0x53fa7ff8,0xbfb05ff9,0xf50013fe,0x400dfd3f,
    0x3ee005fe,0xfff3002f,0xcffa8001,0x10003ff8,0x4009ffff,0x23fd87fb,
    0x27f40ff9,0x7dc0ff90,0x06fe8007,0xc83fff88,0x20dfd0ff,0x0fffca98,
    0xffb0ffc4,0x700bfd03,0x927f4bff,0x2bfb05ff,0x7d4004ff,0x2006fe9f,
    0xff5005fe,0x3ffa2009,0xdffb0001,0xfa8000df,0x7fcc007f,0x3fe0ffc0,
    0xf3017fc2,0x013fa03f,0x2201bfa0,0x5ff305ff,0x3ffffffa,0x1effffff,
    0xffb1ff88,0x2abbfa03,0xffecbaaa,0xe893fa0f,0xfafec0ff,0x7fd4004f,
    0x3a006fe9,0x5ffa805f,0x00fff600,0x0ffff880,0x7fff4000,0x517fc003,
    0x4c9fb0ff,0x84fe807f,0xe8001ff9,0x3ff8806f,0x7ff4ffe0,0xffffffff,
    0x27fe203d,0x3fa01ffd,0xffffffff,0x27f41eff,0xbfb17fe6,0xf50013fe,
    0x400dfd3f,0x7fd405fe,0x13ff2005,0x0ffea000,0xfdff9000,0x27e4003f,
    0x4df709f9,0x7fb805fb,0xd0006fc8,0x5ff100df,0xefe9ff40,0xffea9999,
    0x7f7fc402,0x3ffa00ff,0xcdefffff,0xf909fd02,0xffafec5f,0x4ffd4004,
    0x3fa006fd,0x002ff405,0x0000dff5,0x8000bfe6,0xeff9cff9,0x74df5000,
    0xb0ff982f,0x5ff1007f,0xd0003ff8,0x3ff100df,0x6fe9ff40,0x880fff60,
    0x05ffffff,0xe80017fa,0x0ffe884f,0x013febfb,0xdfb3ff50,0x302ffc00,
    0x3e6001ff,0x300000ff,0x220005ff,0x9ff70eff,0x223fe200,0x23ff00ff,
    0xbfb001ff,0x80007fd4,0xff8806fe,0x7f4ffa01,0x817ff406,0xffb9fff8,
    0x000bfd02,0xffa827f4,0x13febfb5,0xf93ff500,0x9ff1001f,0x88037dc0,
    0x00001ffe,0x4000bfe6,0x7fec1ffd,0xf75fd002,0x7cdfe40d,0x43fea007,
    0x3a0004fd,0x1ff8806f,0x37f4ffa0,0x203ffe60,0x3ff62ff8,0x0005fe80,
    0xffc813fa,0x09ff5fda,0xfa9ffa80,0x2ffb802f,0x6c017f20,0x400003ff,
    0xb8002ff9,0xfff883ff,0xfdbfc800,0x3ef7ea03,0x457fc004,0x3a0001ff,
    0x1ff8806f,0x37f4ffa0,0x442ffdc0,0x17fe21ff,0xe80017fa,0x3ffa204f,
    0x009ff5fe,0xff89ffa8,0x3bfe201f,0x20026200,0x00004ffb,0x4002ff98,
    0x3ea05ff9,0xfdfa805f,0x37fe201f,0x6fe4002f,0x740006fa,0x1ff8806f,
    0x37f4ffa0,0x443ffe80,0x17fdc1ff,0xe80017fa,0x7ffd404f,0x8009ff5f,
    0xfff31ffa,0xff731159,0x2600003f,0xaaaaafff,0x0aaaaaaa,0x002ff980,
    0xb003ffa2,0xff8807ff,0xfffe807f,0x6ffc4000,0x7f40003f,0x01ff8806,
    0x037f4ffa,0x220fff98,0x0ffe81ff,0xe80017fa,0xfffc804f,0x5555bff5,
    0x2a155555,0x3ffea1ff,0x2fffffff,0x5c06ec80,0xffffffff,0x1fffffff,
    0x002ff980,0x2200bff6,0x7f401ffe,0x6ffc805f,0x1fffb000,0x06fe8000,
    0x3a01ff88,0x400dfd3f,0x3fe25ffc,0x3a5ff981,0x3fa0005f,0x5fff8804,
    0xffffffff,0x3ea7ffff,0x7ff64c1f,0xb001dfff,0xfffb80ff,0xffffffff,
    0x9801ffff,0xff7002ff,0x37fcc009,0x200bfee0,0x50004ff9,0xd0000bff,
    0x3ff100df,0x6fe9ff40,0x897ff400,0x5ff901ff,0xe80017fa,0xbff5004f,
    0x3ffffffe,0xf53fffff,0x0199803f,0x0007fd80,0x00000000,0x00000000,
    0x00000000,0x00000000,0x00000000,0x00000000,0x00000000,0x00000000,
    0x00000000,0x00000000,0x00000000,0x00000000,0x00000000,0x00000000,
    0x76c00000,0x3ae000ee,0x400fb66e,0x17b23eed,0x2004ec80,0xeeec82ed,
    0xeeeeeeee,0xddddd93e,0xdddddddd,0x777776c7,0x200bceee,0xdddb2eeb,
    0x057bdddd,0x66666654,0x00cccccc,0x0007dd70,0xdc8817e4,0xaa982cee,
    0xbccba880,0x59973002,0x3332a001,0x7ffff00a,0xf3fffc00,0x9ffb009f,
    0x3a006fd8,0x5ff7005f,0xffffffb0,0x29ffffff,0xfffffffe,0x24ffffff,
    0xfffffffe,0xc80cffff,0xfffff2ff,0x1dffffff,0xffffffb0,0x01ffffff,
    0x001fffa0,0x7e417fd4,0x0effffff,0xff507fee,0x03dfffff,0x3fffffa2,
    0x3ffe602f,0xff83ffff,0xff5006ff,0x2027fcff,0x6fd84ffd,0x2017fa00,
    0xfd82fff9,0xaaaaaaaf,0x5dfd1aaa,0x55555555,0x577f4355,0xffeccaaa,
    0xf2ffc86f,0x997555bf,0xec81fffd,0xeeeeeeee,0xf9800fff,0x4c002ffe,
    0x7fdc2fff,0x6ffda9be,0xffc87fee,0x6ffecabe,0xbbdfff98,0xff884ffd,
    0x4ffdbace,0x007ff7fc,0xff3fffe4,0x827fec09,0x3fa006fd,0x2fffe805,
    0xe8006fd8,0x3fa0006f,0x27ff4405,0x27fcbff2,0x000ffea0,0x6c00bfee,
    0x2005fccf,0x222ffffc,0x7ff505ff,0x7fc42aa6,0xe85ff905,0x0ffb81ef,
    0x7fd83fdc,0x01ffe7fc,0xff3fe7fc,0x813ff609,0x3fa006fd,0x7fe7e405,
    0x8006fd82,0x3a0006fe,0xffe8805f,0x7fcbff21,0x006fe804,0x88027fc4,
    0x00ff99ff,0x7fefff4c,0xf80bfea2,0x03faa05f,0xff517fcc,0x322ffc07,
    0x4159305f,0x405fccff,0x3e7fbdfa,0x03ffd84f,0xfd0037ec,0x7c77d40b,
    0x006fd82f,0x20006fe8,0xff1005fe,0xff97fdcd,0x007fc804,0xf70037f4,
    0x3e027fcf,0x22ff8bff,0x37e407fb,0x91ffc000,0x3fe401ff,0x40033fee,
    0x00ff9cff,0xf9feebf6,0x01ffec4f,0xfd0037ec,0x7c7fe20b,0x006fd82f,
    0x20006fe8,0x3f2005fe,0x7fc7fee7,0x005fe804,0xe8007fee,0xf01ff25f,
    0x00bfe219,0x88017fe0,0x3fffdca9,0x33333bf6,0x20ffdccc,0x1cefffe8,
    0x1ff53fe0,0x4ff71ff0,0x0fff64ff,0xd0037ec0,0xf93f60bf,0x006fd82f,
    0x20006fe8,0x3ea005fe,0x3e3ff50f,0x17fdc04f,0x003ff880,0xff98bfe6,
    0x5ff10202,0x03ffa800,0xfffffeb8,0x3ffa3ffe,0xffffffff,0x7fec41ff,
    0xff84ffff,0x3ea0bf94,0xa7fcff75,0xb000fffd,0xddddddff,0x0bffdddd,
    0x82ff8df7,0xaaaaaffd,0x3fa0aaaa,0xaaaaaaae,0x2ff42aaa,0x2a5ff300,
    0x99dff0ff,0x5ffd9999,0x007fe400,0xdfd0ff90,0x017fc400,0xb003ff60,
    0x2159dfff,0x2b7fa3ff,0xaaaaaaaa,0xffb7100a,0xa7fc1dff,0x2fd80ff9,
    0x6effcff7,0xb005ffff,0xffffffff,0x8bffffff,0x17fc1ff8,0x7fffffec,
    0x3a1fffff,0xffffffff,0x7f46ffff,0x4ffe2005,0xffff0ff9,0x9fffffff,
    0x027fc400,0x3ee13fe0,0x5ff1001f,0x017fe400,0x7c40ffee,0x0017f63f,
    0x8fff6600,0x10ffa4ff,0xff3fdcff,0x7ffb5fff,0x999ffb00,0xf9999999,
    0xf83fe8bf,0xffffd82f,0x1fffffff,0x3bbbbffa,0x44eeeeee,0x3e6005fe,
    0x7fcff33f,0xffeeeeef,0xfb800dff,0x3fea001f,0x004ff881,0x32005ff1,
    0x5fe804ff,0xfc8ffe60,0x2a165407,0x4bff101c,0x517f24ff,0xff3fdc9f,
    0x3ffa25ff,0x0037ec01,0x82fe4bfd,0x06fd82ff,0x0006fe80,0xfa8017fa,
    0x7fcff12f,0x3ffea204,0x0037f400,0x26667bf6,0x1007fe99,0xffb005ff,
    0x817fe009,0x3fe63ffd,0xe8dff103,0xf93fa06f,0xd83fe64f,0xff9fee2f,
    0x037fcc2f,0xfe801bf6,0x3e01ff35,0x006fd82f,0x20006fe8,0x3ee005fe,
    0x7fcdf11f,0x03ff9804,0x8800bfe6,0xffffffff,0x8802ffff,0x3fa202ff,
    0x23dd504f,0x7ec41ffd,0x6ffe44ff,0x70bff621,0x7dc417ff,0xfd13fe1f,
    0xff71fe27,0xffc827fc,0x801bf604,0xffff95fe,0xffffffff,0x001bf61f,
    0xe8001bfa,0x3ff2005f,0x04ff9be0,0x7e40bfd0,0x7ffdc007,0xffffffff,
    0x2ff8806f,0x407ffd10,0xfff31ffb,0xfb9ffd9d,0xefffe88b,0xfb03fffe,
    0x7fffddff,0xb7e44ff8,0xf3fdc4fb,0x17ff409f,0x3a006fd8,0xfffff95f,
    0xffffffff,0x2001bf61,0x3a0006fe,0xbff1005f,0x013fe5f8,0x9ff03fec,
    0x805fe800,0x7c401ffc,0x2ffe882f,0xd30ffdc0,0x2a3dffff,0xfffb80ff,
    0x2e202eff,0x82efffff,0x47fcc4ff,0xf3fdc1fd,0x7ffcc09f,0x2006fd80,
    0x333315fe,0x37ff3333,0x40037ec3,0x3a0006fe,0x5ffb005f,0xf004ff80,
    0x0bfe20bf,0x802ff980,0x7c404ff8,0x0fff442f,0x9880f980,0x26620001,
    0x00cc4000,0x33fa13fe,0x3e7fb86f,0x37fdc04f,0xfd0037ec,0x417fc00b,
    0xfe8006fd,0x17fa0006,0x201bfee0,0xffc804ff,0x003ff503,0xfd003fe4,
    0x17fc401f,0xb8007ff6,0x00000006,0x27fc0000,0x5c27ffdc,0x2013fe7f,
    0x37ec4ffd,0x400bfd00,0x06fd82ff,0xaaaefe80,0xaaaaaaaa,0x2aabbfa2,
    0xeffecbaa,0xff8f7540,0xbaaaaaad,0x3ee06ffe,0x027fc007,0x4407ff50,
    0x37fea2ff,0xaaaaaaaa,0x00009f32,0x80000000,0xfff984ff,0x3fe7fb81,
    0x1fff8804,0xfe801bf6,0x20bfe005,0xfe8006fd,0xffffffff,0x3fa7ffff,
    0xffffffff,0xffb80eff,0xfffffff1,0x01dfffff,0xf50037e4,0x7fc4003f,
    0xe8bfe206,0xffffffff,0x00737fff,0x00000000,0x3a09ff00,0x7cff706f,
    0xfff5004f,0xe801bf61,0x0bfe005f,0x3a001bf6,0xffffffff,0x3a7fffff,
    0xefffffff,0x3fee01ce,0xfffffff1,0xd005bdff,0x3fec00bf,0x80ffe400,
    0xfff12ff8,0xffffffff,0x000000ff,0x00000000,0x00000000,0x00000000,
    0x00000000,0x00000000,0x00000000,0x00000000,0x00000000,0x40000000,
    0x100accba,0x05540155,0x80bccb88,0x439712a8,0x2f2e62a8,0x550aa982,
    0x402aa203,0x005531a9,0x06aa2355,0x8aa22a98,0x5440bcb9,0x555503cc,
    0x55555555,0x0000004c,0x00aa8030,0x10004c40,0x3fffee03,0xffffffff,
    0x3ba2dd94,0x7ffff542,0x1ff983ff,0xfd10ffe0,0x985fffff,0x3fffe8ff,
    0x3fff6ff1,0x3fee0eff,0x3ee0df91,0x267fd03f,0x3fe601ff,0x2607ff61,
    0x6dfe24ff,0xf32fffff,0xe81dffff,0xffffffff,0x077ee6ff,0x7e440000,
    0x000ffc04,0xfc8017f6,0xfffffb81,0x4fffffff,0x8ffe6ffb,0xdbabfff9,
    0x0ffcc4ff,0x7f447ff0,0x2ffecabf,0x3fff7fe6,0xffbff10f,0x5cdffb79,
    0x01ff51ff,0xff10bffb,0xf9027f43,0x446ff88d,0x6ffc46fe,0xbfffdbdf,
    0x5ffdbdff,0x6666665c,0x3ee4ffec,0x00002eff,0x809fffb5,0x3e6001ff,
    0x1f7001ff,0x55555510,0x23555555,0x47ff37fd,0xffc80efe,0xf807fe61,
    0x203bfa3f,0x3ffe66fe,0x3fff8863,0x5531ffc8,0x7fc17fc1,0x646fa87f,
    0x20ffe07f,0x3ff63ffa,0x21fffc41,0x640dfff9,0xff3000ff,0xffffb50b,
    0xeb880019,0xf802efff,0x3ff2001f,0x2e77604f,0x0002eb8f,0x7ff37fd8,
    0xfe807fee,0xf807fe66,0x203ff33f,0xbff30ffa,0x882ffc40,0x27ec02ff,
    0xb07ff7e6,0x81ff889f,0xff900ffa,0xf107ff51,0x07ffa0bf,0x22007fe6,
    0x2e200efe,0x401dffff,0x1cffffc9,0x4007fe00,0x00ff9ff8,0xfffffffd,
    0xdf700009,0x05fd97fc,0xff987fd4,0x7dcffe01,0x3fe60406,0x80ffe203,
    0x3fdc03ff,0xf0ff6fee,0xb09fd03f,0x77f440bf,0x7ff105ff,0x7c41ff20,
    0x0ffe802f,0x3fff6a00,0x3ffaa0be,0xf8000bef,0x2bf7001f,0x3ea203fd,
    0x000009ef,0xe87f4bf5,0x8ffcc04f,0x3fe01ff9,0x9800bf93,0x3fe202ff,
    0x100ffa02,0x5cff43ff,0x541fe65f,0x017fc47f,0x403bffe6,0xdf902ff8,
    0xb00bfe20,0x260003ff,0xff74fffc,0x3ee003bf,0xffffffff,0x1ff84fff,
    0xdfd80ff3,0x7fffdc2f,0xffffffff,0xf3ec7f14,0x2ff8807f,0x7fc03ff3,
    0x98009fd3,0x3fe201ff,0x200ffa01,0x26ff13fe,0x4413f27f,0x01fee2ff,
    0xf101ffec,0x41bf203f,0x3f202ff8,0x6cc0002f,0x3bff74ff,0x7fffdc00,
    0xffffffff,0x3fa37d44,0x3fa9f702,0x3ffffee1,0x4fffffff,0x3fe08826,
    0x997fcc03,0x4ffe01ff,0x7cc004fe,0x07fe201f,0xfb803fe8,0x8ffcbf55,
    0x97f602fe,0xff9804fe,0x3ff100ff,0x7c41bf20,0x07ff702f,0x7fff5400,
    0xdfffb32e,0xaaa88017,0xaaabffaa,0x2e1ff41a,0x2a1d706f,0x2aaaa21f,
    0xaaaaaaaa,0x013fa001,0x3fe63ff5,0x367ff101,0xf304405f,0x0ffc403f,
    0xf3007fd0,0xcfc8ff2f,0x7fcc07f8,0xe801ff88,0xf105feef,0x41bf203f,
    0xffa82ff8,0xffc88004,0xf9101cff,0x80039fff,0x7fcc01ff,0x080ffc40,
    0xd9000004,0x7ec7baab,0x887fe406,0x7ff302ff,0xff881fee,0x4403ff33,
    0x0ffa01ff,0x0ff57f40,0x00bf7df5,0x00df75fd,0x7ff31ff9,0x3203ff10,
    0x85ff106f,0x4c005ff9,0x00bffffd,0x3bfffae0,0x803ff002,0x0bf905fd,
    0xfb000000,0x7d47feef,0x4bff102f,0xffb04ff8,0x640ffe67,0x03ff30ff,
    0xfd00ffc4,0x3f7f2007,0x17f7fc47,0x1ff6fdc0,0xfc8ffea0,0x80ffc41f,
    0x5ff106fc,0x80077fc4,0x02efffe9,0x7ffecc00,0x00ffc02f,0x264c0732,
    0x6c000000,0x6c3ff77f,0x77f442ff,0x9117fec0,0x7fe47fff,0xf32ffd42,
    0x0ffc403f,0x3baa7fd0,0x85fffa81,0x8800fffe,0x2200ffff,0x37f446ff,
    0x7e407fe2,0x225ff106,0x33310efe,0x67fdc333,0x64400001,0x0ffc04ff,
    0x00000000,0x4cffb000,0x3fffa20f,0xa80effed,0xcffeffff,0x3ffa23fd,
    0x20efffde,0x3e201ff9,0x5cffa01f,0x7fff01ff,0x400bff90,0x7ec05ffe,
    0x24ffa80f,0xdf901ff8,0x7dcbfe20,0xffffffff,0x01751fff,0x07700000,
    0x00001ee8,0x20000000,0x5c1ae6fc,0x00ceffff,0x4fbfffa6,0xfffb83fd,
    0x1ff984ff,0xe807fe20,0x203ff73f,0xffa81ffd,0x0bfea003,0x3203ffa8,
    0x03ff11ff,0x7fc41bf2,0xffffff72,0x03ffffff,0x00000000,0x00000000,
    0xa7dc0000,0x04c404f9,0x00026200,0x00000662,0x00000000,0x00000000,
    0x00000000,0x00000000,0x00000000,0x20000000,0x000733f9,0x00000000,
    0x00000000,0x00000000,0x00000000,0x00000000,0x00000000,0x00000000,
    0x00026000,0x00000000,0x00000000,0x00000000,0x00000000,0x00000000,
    0x00000000,0x00000000,0x26000000,0x0e02deec,0x15555555,0x33113fea,
    0x33333333,0x2a333333,0x000001ee,0x00000000,0x00000000,0x00000000,
    0x00000000,0x00000000,0x7fdc0000,0x8acfffff,0x3ffe27da,0x3f22ffff,
    0x3fffea0f,0xffffffff,0x3ff75fff,0x00000000,0x00000000,0x00000000,
    0x00000000,0x00000000,0x00000000,0xfedefd80,0x7fffffff,0x3fffffe2,
    0x7327ec2f,0x77777777,0x25777777,0x00001ffb,0x00000000,0x00000000,
    0x00000000,0x00000000,0x00000000,0x16c00000,0x3ffff6a2,0x4444441e,
    0x000bb008,0x00000000,0x00000000,0x00000000,0x00000000,0x00000000,
    0x00000000,0x40080000,0x00001aa8,0x00000000,0x00000000,0x00000000,
    0x00000000,0x00000000,0x00000000,0x00000000,0x00000000,0x00000000,
    0x00000000,0x00000000,0x00000000,0x00000000,0x00000000,0x00000000,
};

static signed short stb__arial_31_usascii_x[95]={ 0,2,1,0,0,1,1,1,1,1,0,1,2,0,
2,0,1,3,0,1,0,1,1,1,1,1,2,2,1,1,1,1,1,-1,2,1,2,2,2,1,2,2,0,2,
2,2,2,1,2,1,2,1,0,2,0,0,0,0,0,1,0,0,0,-1,1,1,1,1,0,1,0,0,1,1,
-2,1,1,1,1,0,1,0,1,0,0,1,0,0,0,0,0,0,2,0,1, };
static signed short stb__arial_31_usascii_y[95]={ 25,5,5,4,3,4,4,5,4,4,4,8,22,16,
22,4,5,5,5,5,5,5,5,5,5,5,10,10,8,11,8,4,4,5,5,4,5,5,5,4,5,5,5,5,
5,5,5,4,5,4,5,4,5,5,5,5,5,5,5,5,4,5,4,28,5,10,5,10,5,10,4,10,5,5,
5,5,5,10,10,10,10,10,10,10,5,10,10,10,10,10,10,4,4,4,13, };
static unsigned short stb__arial_31_usascii_w[95]={ 0,4,8,16,15,22,17,3,8,8,10,14,4,9,
4,8,14,8,14,14,15,14,14,14,14,14,4,4,14,14,14,14,27,20,16,18,17,16,14,19,16,4,12,17,
13,20,16,20,16,20,18,17,17,16,19,26,19,19,17,7,8,6,13,17,6,14,14,13,14,14,9,14,13,4,
7,13,4,21,13,15,14,14,9,13,8,13,14,20,14,14,14,9,3,9,15, };
static unsigned short stb__arial_31_usascii_h[95]={ 0,20,8,22,25,22,22,8,27,27,10,14,7,4,
3,22,21,20,20,21,20,21,21,20,21,21,15,19,14,9,14,21,27,20,20,22,20,20,20,22,20,20,21,20,
20,20,20,22,20,23,20,22,20,21,20,20,20,20,20,26,22,26,12,3,4,16,21,16,21,16,21,21,20,20,
26,20,20,15,15,16,21,21,15,16,21,16,15,15,15,21,15,27,27,27,5, };
static unsigned short stb__arial_31_usascii_s[95]={ 254,123,247,152,94,217,1,247,62,1,221,
192,251,17,52,240,131,181,190,161,57,176,191,145,234,219,69,205,177,232,162,
18,10,160,128,189,105,88,73,169,40,251,206,22,237,1,220,131,203,110,170,
19,138,1,118,91,71,51,33,86,208,79,207,34,27,210,146,31,116,225,97,
82,156,249,71,189,249,125,55,1,52,67,45,240,107,17,95,74,110,37,147,
52,48,38,1, };
static unsigned short stb__arial_31_usascii_t[95]={ 1,74,95,1,1,1,29,104,1,1,95,
95,104,113,113,1,29,74,74,29,74,29,29,74,29,29,95,74,95,95,95,
52,1,74,74,1,74,74,74,1,74,52,29,74,52,74,52,1,52,1,52,
29,52,52,52,52,52,52,52,1,1,1,95,113,113,74,29,95,29,74,29,
29,52,29,1,52,1,95,95,95,29,29,95,74,29,95,95,95,95,29,95,
1,1,1,113, };
static unsigned short stb__arial_31_usascii_a[95]={ 123,123,158,247,247,395,296,85,
148,148,173,259,123,148,123,123,247,247,247,247,247,247,247,247,
247,247,123,123,259,259,259,247,451,296,296,321,321,296,271,345,
321,123,222,296,247,370,321,345,296,345,321,296,271,321,296,419,
296,296,271,123,123,123,208,247,148,247,247,222,247,247,123,247,
247,99,99,222,99,370,247,247,247,247,148,222,123,247,222,321,
222,222,222,148,115,148,259, };

// Call this function with
//    font: NULL or array length
//    data: NULL or specified size
//    height: STB_FONT_arial_31_usascii_BITMAP_HEIGHT or STB_FONT_arial_31_usascii_BITMAP_HEIGHT_POW2
//    return value: spacing between lines
static void stb_font_arial_31_usascii(stb_fontchar font[STB_FONT_arial_31_usascii_NUM_CHARS],
                unsigned char data[STB_FONT_arial_31_usascii_BITMAP_HEIGHT][STB_FONT_arial_31_usascii_BITMAP_WIDTH],
                int height)
{
    int i,j;
    if (data != 0) {
        unsigned int *bits = stb__arial_31_usascii_pixels;
        unsigned int bitpack = *bits++, numbits = 32;
        for (i=0; i < STB_FONT_arial_31_usascii_BITMAP_WIDTH*height; ++i)
            data[0][i] = 0;  // zero entire bitmap
        for (j=1; j < STB_FONT_arial_31_usascii_BITMAP_HEIGHT-1; ++j) {
            for (i=1; i < STB_FONT_arial_31_usascii_BITMAP_WIDTH-1; ++i) {
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
        float recip_width = 1.0f / STB_FONT_arial_31_usascii_BITMAP_WIDTH;
        float recip_height = 1.0f / height;
        for (i=0; i < STB_FONT_arial_31_usascii_NUM_CHARS; ++i) {
            // pad characters so they bilerp from empty space around each character
            font[i].s0 = (stb__arial_31_usascii_s[i]) * recip_width;
            font[i].t0 = (stb__arial_31_usascii_t[i]) * recip_height;
            font[i].s1 = (stb__arial_31_usascii_s[i] + stb__arial_31_usascii_w[i]) * recip_width;
            font[i].t1 = (stb__arial_31_usascii_t[i] + stb__arial_31_usascii_h[i]) * recip_height;
            font[i].x0 = stb__arial_31_usascii_x[i];
            font[i].y0 = stb__arial_31_usascii_y[i];
            font[i].x1 = stb__arial_31_usascii_x[i] + stb__arial_31_usascii_w[i];
            font[i].y1 = stb__arial_31_usascii_y[i] + stb__arial_31_usascii_h[i];
            font[i].advance_int = (stb__arial_31_usascii_a[i]+8)>>4;
            font[i].s0f = (stb__arial_31_usascii_s[i] - 0.5f) * recip_width;
            font[i].t0f = (stb__arial_31_usascii_t[i] - 0.5f) * recip_height;
            font[i].s1f = (stb__arial_31_usascii_s[i] + stb__arial_31_usascii_w[i] + 0.5f) * recip_width;
            font[i].t1f = (stb__arial_31_usascii_t[i] + stb__arial_31_usascii_h[i] + 0.5f) * recip_height;
            font[i].x0f = stb__arial_31_usascii_x[i] - 0.5f;
            font[i].y0f = stb__arial_31_usascii_y[i] - 0.5f;
            font[i].x1f = stb__arial_31_usascii_x[i] + stb__arial_31_usascii_w[i] + 0.5f;
            font[i].y1f = stb__arial_31_usascii_y[i] + stb__arial_31_usascii_h[i] + 0.5f;
            font[i].advance = stb__arial_31_usascii_a[i]/16.0f;
        }
    }
}

#ifndef STB_SOMEFONT_CREATE
#define STB_SOMEFONT_CREATE              stb_font_arial_31_usascii
#define STB_SOMEFONT_BITMAP_WIDTH        STB_FONT_arial_31_usascii_BITMAP_WIDTH
#define STB_SOMEFONT_BITMAP_HEIGHT       STB_FONT_arial_31_usascii_BITMAP_HEIGHT
#define STB_SOMEFONT_BITMAP_HEIGHT_POW2  STB_FONT_arial_31_usascii_BITMAP_HEIGHT_POW2
#define STB_SOMEFONT_FIRST_CHAR          STB_FONT_arial_31_usascii_FIRST_CHAR
#define STB_SOMEFONT_NUM_CHARS           STB_FONT_arial_31_usascii_NUM_CHARS
#define STB_SOMEFONT_LINE_SPACING        STB_FONT_arial_31_usascii_LINE_SPACING
#endif
