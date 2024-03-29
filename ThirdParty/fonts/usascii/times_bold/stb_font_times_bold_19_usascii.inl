// Font generated by stb_font_inl_generator.c (4/1 bpp)
//
// Following instructions show how to use the only included font, whatever it is, in
// a generic way so you can replace it with any other font by changing the include.
// To use multiple fonts, replace STB_SOMEFONT_* below with STB_FONT_times_bold_19_usascii_*,
// and separately install each font. Note that the CREATE function call has a
// totally different name; it's just 'stb_font_times_bold_19_usascii'.
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

#define STB_FONT_times_bold_19_usascii_BITMAP_WIDTH         128
#define STB_FONT_times_bold_19_usascii_BITMAP_HEIGHT        106
#define STB_FONT_times_bold_19_usascii_BITMAP_HEIGHT_POW2   128

#define STB_FONT_times_bold_19_usascii_FIRST_CHAR            32
#define STB_FONT_times_bold_19_usascii_NUM_CHARS             95

#define STB_FONT_times_bold_19_usascii_LINE_SPACING          12

static unsigned int stb__times_bold_19_usascii_pixels[]={
    0x540dc403,0x06203981,0x02aa88aa,0x2001bb98,0x5101bca8,0x01710155,
    0x40357510,0x0170002b,0x0fe203b1,0x500dc859,0x441ff109,0x1599507f,
    0xfc880ee2,0x4c1ed98b,0xcebc886f,0x8afc881d,0x7fd41ed9,0x6d6e6d40,
    0x074c0b20,0xf31647c8,0x5d81aa07,0x405a87f8,0x887fd028,0x213e62ff,
    0x3a12eb4e,0x517fc43f,0xa9fcc1ff,0xe816a0ff,0x1641fb05,0x07f109f5,
    0x05a8ff00,0x1ffc8350,0x9f30efc8,0x21cb5f98,0xefc81ffc,0x1fe8ff30,
    0x20781ff3,0x647f81fb,0x3f217e22,0xf81dd901,0x59b11a67,0x1ffe149d,
    0x4f997fd4,0x3e05eff8,0x45ff707f,0x443fe25f,0xb816c0ff,0x1646f84f,
    0x403fe17e,0x73fc0ff9,0x3fea7c47,0x506ff88e,0x213e69ff,0xf883fffb,
    0x49ff506f,0x443fe63e,0xa82540ff,0x1647b86f,0x0ff883f3,0x7f81ff10,
    0xff0fd836,0x0bff31c3,0x27cd7fe6,0x20dfffb8,0xff505ff9,0x4bfe1649,
    0x83c40ff8,0x219507f9,0xf303932c,0x207fc40f,0x16f99a7f,0x37f428ff,
    0x9f33ffa8,0x11fffc40,0x3fea0dff,0x27fb02e2,0x81d80ffa,0x219907f9,
    0xf305932c,0x207fc40f,0x9fe4b17f,0xf90a24fc,0x4c7fee0d,0x37eec04f,
    0x3fe41bfa,0x33bfa202,0xa84b80ff,0x1647c86f,0x0ff885f1,0x7f81ff10,
    0xfe99fe96,0x07fe60e2,0x44f997f6,0x2a37d628,0x44fd81ff,0x3fe2101a,
    0x4fb86880,0x3e1646f8,0xf100fe85,0xe9a7f81f,0x171fdbdf,0xf98bf506,
    0xd113e60e,0x5fc82fac,0xff5077d4,0x807fc401,0x740fe41e,0x0bf31647,
    0x3fe203f7,0x2a373fc0,0x2159d54f,0xdbfc880c,0x227cc0cf,0x03cebee8,
    0x13b2ffaa,0xff301be6,0x0bd0ee03,0x2a2c83f6,0x2209f03f,0x163fc0ff,
    0x7d403a80,0x209f303f,0x04c00598,0x99710020,0x0e982207,0x262c8f90,
    0x441f303f,0x47f87f8b,0x00498049,0x9f303ff9,0x00000080,0x19300000,
    0x8590be60,0x219300eb,0x2624f8fa,0x20ac887f,0x5c002cb8,0xdf30cffd,
    0x00000003,0x40100000,0x882b80a8,0x85750402,0x2a601998,0x00002bbb,
    0x00003330,0x00000000,0x00000000,0x00000000,0x00000000,0x00000000,
    0x0730c800,0x00244055,0x2e600175,0x00175101,0x30613773,0x00355555,
    0x540aaa98,0x202982aa,0x1efcbed9,0xf892e788,0x02d80fbb,0x01fd9ea8,
    0x83b62fe6,0x703faaf9,0x7dd737df,0x881fff10,0x21eeecdb,0x3220effc,
    0xbd13c80d,0xff9affd8,0x5c5b34c0,0x2d43faaf,0x07f35e80,0x23fa87f4,
    0xb83fd0ff,0x3a07d06f,0xff1fd86f,0x45fff883,0x3ea1d038,0xff93f60f,
    0x6c1d25c3,0x3a25f99f,0xf37f8800,0x4cffe201,0x7ecff34f,0x5407fea4,
    0xf98dfd03,0xc885fb0f,0x20e23ffe,0xfb0ae269,0xffcafec9,0xf71fffff,
    0x01ec5f55,0x01ccff88,0x8fddfff4,0xd9bf27fa,0xfe80407f,0xfe87fc46,
    0x7ffc5c42,0x00770712,0x8afec9fb,0x21eb9af9,0xb50ebbe8,0x87ffc400,
    0x3e60cec8,0x3fe20fff,0x37fcdf91,0xb86fe800,0x3885f8af,0x0711fff3,
    0x49fb003d,0x4b9e23fe,0x50744330,0xff595015,0xffa8354b,0x6c6fec5f,
    0x00bff34f,0x6641bfa0,0x7dc7102b,0x234438ef,0x877ec1b8,0x55f731ff,
    0x3d80159d,0xfb87eb3a,0x07a7ff91,0x13ff67ee,0x225ffbb7,0xfd0006ff,
    0x7100990d,0x5c3dffc8,0xfb07fe44,0x7545fddb,0x00ccfcce,0xf9bfa96a,
    0xffe87fe4,0x3a6f883c,0x41ff306f,0x451007fe,0xeeff86fe,0x741c41ce,
    0x2a0ec3ff,0x053f62ff,0x100f12d8,0x7c5fe41d,0x7c4bff16,0x2fcc22ff,
    0x07f20bf7,0x42207ff5,0x50bfd3fc,0x88dfffff,0x223ff883,0x4fd83607,
    0x805a8f40,0x7cdfcc3c,0x2233ff63,0x20dcfffd,0x2e07ee6e,0x81ff701f,
    0x3e5f70d8,0x4cdf443f,0x41660fb9,0x4412a3f9,0xf1027f44,0x416a025c,
    0x3660eadd,0xfe99dfff,0x65e6cc2f,0x2005dd43,0x84dcefda,0xf884fccc,
    0x7fb52643,0x416c7501,0x0e664c28,0x2a004410,0x1880a600,0x01010030,
    0x0c004400,0x0aef2e20,0x00010400,0x00000000,0x00000000,0x00000000,
    0x00000000,0x26015551,0x00d54c0b,0x55100ba8,0x42980555,0x02aaaaa9,
    0x0c2f2ea2,0x2aa0dd44,0x2aa61aaa,0x5555530a,0xa98aaaa1,0x0ffa801a,
    0x742f8ce8,0x7ffc404f,0xffffd83f,0xe81dd884,0x706fffff,0xddb515bf,
    0x44df7598,0x2f982ffe,0x2dc2ffd4,0x7c4027f4,0xfd8fdc0f,0x5b013f60,
    0xee88dfd3,0x2f441eee,0x9fdddff0,0x1b60dfb0,0xa8bfe2fb,0x884983ff,
    0xd83984ff,0x0ff8804f,0x23fc8ffc,0xf50404fd,0x74402a8d,0xf882e607,
    0x880ffdc1,0x87ff3645,0x880c86fe,0xd83984ff,0xf7dd904f,0xc87fc41f,
    0x3af3f64f,0xb07ee02e,0x9f903bdf,0x0d501011,0x20080fff,0x7fdc0ff8,
    0x7fc41222,0x4fd83984,0x1ffb3fb8,0x6fc87fcc,0x3fe63bf6,0x221efa81,
    0x744fffff,0x400cfeef,0x037fc44d,0xf101d900,0xf880dcbf,0xfd83984f,
    0xff11ff84,0xfc87fd41,0x3ff93f66,0x887fff4c,0x10ffffdb,0x80ffa3ff,
    0x2ffcc1f8,0x6401b000,0x7c4091ff,0xfd83984f,0xf887fcc4,0x643fe60f,
    0xfd93f65f,0x207ff705,0x3ff34fd8,0x86a817ee,0x75c46ff8,0x00cc0bee,
    0x806b3fe2,0x83984ff8,0x87fcc4fd,0x3fe20ff8,0x27ec9f90,0x17ec09fb,
    0x8ffc57a0,0x413607fa,0x0dff07fe,0x05ffd800,0x82a84ff8,0x11ff84fd,
    0x91fe81ff,0xfd27ec5f,0x64035405,0x2fd4bfe3,0x3fea03f0,0x3306fe81,
    0x005ff500,0xb0370bfd,0x329fb09f,0xe97d41ff,0x1df2fec6,0x263c87ee,
    0xfb8360df,0x1ea05f74,0xfe81df70,0x800ff986,0x1ff9006e,0x84fd8244,
    0x4efbefe8,0x6c1ebeb8,0x2a0ecbdc,0x6c43ceff,0xeb80ccff,0x013603eb,
    0x3eeb3b66,0x00ff882d,0x3ee003b8,0xf980ccdf,0x004101ff,0x80220804,
    0x30008008,0x88001100,0x00008009,0x00008800,0x00000000,0x00000000,
    0x00000000,0x00000000,0x55045e4c,0x2aaaa555,0x440aaa1a,0x544280bb,
    0xaaaaaaaa,0x25555532,0x2a62aaa8,0x0099aaaa,0x13555553,0x8802aa88,
    0x2aaaa60b,0x8ae8800a,0xfff10fea,0x2227fe43,0x6f8fb81e,0x273ea254,
    0x26ea9ffd,0x1fc46ffc,0x7e4e7fd4,0x7bff303f,0x05fd89fd,0x7fcc4fd8,
    0xf11b2006,0xf117fdc1,0x5fe090bf,0x7513ea1a,0xfd163fe4,0xf882545f,
    0x40bfea4f,0x45ff14ff,0x2ea805fc,0xf0027fc4,0x3e20b83f,0x507fec5f,
    0xf50ff305,0xc8265dff,0x3fe6147f,0x3e20588f,0x413fe24f,0xc9bfa4ff,
    0x3e20005f,0x3ffa004f,0x83ff600c,0x2a123ffc,0x7e40effe,0x403fe404,
    0x200cdffb,0x3fe24ff8,0x7fc9ff03,0x3feb7f24,0x221f6cc2,0x3ea004ff,
    0xff302fff,0x45bfb227,0x320ff304,0x03fe404f,0x4403ffe8,0x03ff24ff,
    0x1ffba7fc,0x1feabff2,0x9ff113f6,0xffffa800,0x26effd04,0x301b9ffb,
    0x013f20ff,0x3e600ff9,0x3fe200ff,0x200cffde,0x40bddeff,0x81ff15fc,
    0x27fc44fd,0x7ffe4400,0x14affb82,0x7cc099ff,0xc809f907,0xffb5007f,
    0x4e7fc40b,0x27fc06ff,0x7fc57f20,0x3e227ec1,0x8871004f,0xeff885fe,
    0x980fff62,0x80bf907f,0xd49807fc,0x3fe205ff,0x7c09ff74,0x8afe404f,
    0x227ec1ff,0x88704ff8,0xf903f987,0x200ffa8d,0x1bf907f9,0x101ff203,
    0x407ffc4b,0x3ff64ff8,0xc809ff01,0xd83ff15f,0x427fc44f,0x261fc448,
    0xf07f300f,0x107fa80b,0x7fec09fd,0xfb83d100,0x24ff885f,0xff80eff8,
    0xf8b7e404,0x2227ec1f,0x444d85ff,0x01cbbede,0x10164074,0x80019ffb,
    0x41cfffa8,0xf911bfea,0x3f261bff,0x3bfea2ef,0x15fff931,0xf93ffd10,
    0x8f7fcc9f,0xdccfffc9,0x026083ff,0x00008040,0x00000000,0x00000000,
    0x00000000,0x00000000,0x00000000,0x00000000,0x26000000,0x2aa02aaa,
    0x555532aa,0x11555445,0x55300355,0x41555555,0xa8aaaaa9,0x2aa2aaaa,
    0x2aa21aaa,0x5555530a,0x2aa65555,0x22aaaaaa,0x00aaaaaa,0x82fff980,
    0x7cc3fff8,0x40cfa86f,0xbfc805fd,0x986ffa99,0x27fdc6ff,0x2613ff62,
    0x4effcc1f,0x3fe67eba,0x546fba9d,0x0dfcadff,0x3f222f44,0x1ffcb85f,
    0x0f445ff8,0x1c805fc8,0xff817fec,0x441ffd45,0xf03a87ff,0x4ff8d0bf,
    0x93fe2344,0x3fea0efb,0x20ffe640,0xff81ffbc,0xfc803625,0x7fd43805,
    0xf317fe05,0x0ffee07f,0x212ffc0b,0x0e327fc2,0x6ff89ff1,0x3e720f22,
    0x3feeaa4f,0x0955ff81,0x3762bf90,0x03ffe203,0x7fcc5ff8,0x1b9ffe03,
    0xf0497fe0,0x7c40a69f,0x007fec4f,0x290ffea4,0xdff81ffb,0x5fc804fb,
    0x7ff90076,0x999dff80,0x3ee03ffb,0x7fc048bf,0xbff06b8d,0x3fe205d5,
    0x401ffdc4,0x2717ff54,0xfff81ffb,0x7e402ffe,0xff980395,0xcceff806,
    0x7403ffdc,0x7fc00dff,0xdff06fde,0x3fe205fb,0x3727fd44,0x85f7f490,
    0xdff81ffb,0x3200fff9,0x7401fcdf,0x5ff801ff,0x2a01ffcc,0x5ff804ff,
    0x5d3fe0d3,0xb89ff102,0x81ff53ff,0xfb93fee4,0xf55ff81f,0x3ff201df,
    0x3fee06fd,0x2ffc0b84,0xf100ffe6,0x4bff007f,0x8a29ff04,0xf913fe21,
    0x921be63f,0x3fee1ff8,0x3f25ff81,0xd1bf905f,0x1dff109f,0x98bff0d0,
    0x7fc403ff,0x025ff803,0x8ea127fc,0x2ff44ff8,0x8d912202,0x5ff82ffb,
    0x7e427ff4,0xfd85ff35,0x2236c42f,0x1ffd45ff,0x2013fe60,0x7fc405ff,
    0xff3174c5,0x003bf229,0x8a617fb3,0x932dffea,0x3f627fff,0xffd11dff,
    0x2a5fff13,0xfecccfff,0x3fff265f,0x2effda8a,0x15dff950,0x17fff930,
    0x9bfff930,0x3f2a3fff,0x002dfdff,0x00000000,0x00000000,0x00000000,
    0x40000000,0x30aaaaa9,0x01355555,0x053000c0,0x6775c730,0xba80dc88,
    0x10000001,0x00000001,0x261bfe60,0x1ffdadff,0x6d4034c0,0x2374404f,
    0xf30ea5fe,0xbb705fff,0x3b9d703b,0x99101e40,0xb9b503dd,0x10799307,
    0x9ff10bff,0x3f603fec,0x13feea01,0xffa8dfb0,0xff979090,0x5f99fb8f,
    0x00fd97dc,0xf8b6c079,0x44a9fc0f,0xff07f1fa,0xfb93fe09,0x0bff301f,
    0x6dc09fd0,0x873fe86f,0xe83fee08,0x21fd1367,0x407904fc,0x21ff88fe,
    0x7d833ff9,0x413fe17a,0x81bf64ff,0x7400ffdc,0xdf79304f,0x8035ff70,
    0x81fe26f9,0x2df70ff8,0x99cd9998,0x3f262209,0x227ff41f,0x0edccff8,
    0xdff827fc,0x9100cfda,0xfe809ff3,0x21beeb04,0xfb805ff8,0x4c03fe63,
    0x2edf70ff,0xeeeefeee,0x3fe37622,0x327ff441,0x4ff801ff,0xbfb7bff0,
    0x3ff42e03,0x43213fa0,0x07f906fb,0x09fd0db0,0x03fb87f4,0x447ec079,
    0x7e4221ff,0xf011ffc7,0xc93fe09f,0x3ee480ff,0x513fa03f,0x01df9339,
    0x0f9801f1,0x439affc8,0x203f91fc,0x99ff103c,0xdd2c45ff,0x838aefd8,
    0x49ff04ff,0x66d44ff9,0x3a06ffcc,0x7fffe44f,0xd00906ff,0x3bfee043,
    0x17deec40,0x5fec0790,0x37a25fd8,0x7ff441fb,0xf04ff80d,0x21ffcc9f,
    0xd02ffb85,0xdaaa989f,0x351b12ef,0x3999bd80,0x80188010,0x3080002b,
    0xff100880,0x6c9ff10b,0x220ee0ff,0x09fd06ff,0x33ea6fb8,0x7fffdc04,
    0x0000002f,0x00000000,0x215fff93,0xeedfffc9,0x88bbee0c,0x730cfffb,
    0x2e015fff,0x2601dc6f,0x01ffffff,0x00000000,0x00000000,0x00000000,
    0x00000000,0x00000000,0x00000000,0x775caa00,0x992eec8c,0x000d4001,
    0xca76c400,0x1bdd70ee,0x776cc372,0x33a63da9,0x1980eeca,0x9db10550,
    0x3bf29fd5,0x0f75c401,0x47fe69fd,0x233b621a,0x17dd50fd,0x75676c40,
    0xf35fd82f,0x552ff41f,0x42a9ffa8,0x209ff139,0x82ff986e,0xdff8affc,
    0xfb306fc8,0x2aff7039,0xdf7094fe,0xfda83fd9,0x57ff901c,0x26bf90ff,
    0x43fea0ff,0x109dfb04,0x6dc07fe4,0x427fc43e,0x54bfe6fb,0x2fbae27f,
    0x32bfe200,0xfb838ffa,0x7dc4010f,0xf8afe42e,0xf9afe40f,0x1c5ffc0f,
    0x2602ff98,0x98f883ff,0xfb82a80f,0x3fd4bfe6,0x36003df9,0x0dff8bdf,
    0x4c007fb8,0x457f22ff,0x9afe40ff,0x5f7dc0ff,0xe81bf600,0x26c9906f,
    0x3e6fb824,0xc98ff52f,0x7fd402df,0x3ee0bfb0,0xbeeb8806,0xff8afe40,
    0xff9afe40,0x1027fc40,0xff505ff9,0x107cc223,0xdf70141f,0x07fa97fc,
    0x7c02ffaa,0x7dc0fe65,0x0b7f2606,0x1ff15fc8,0x1ff96fb8,0xcac03f90,
    0x93fe20ff,0x0330330d,0x3ff9bee0,0xf9300ff5,0x00e85905,0x33f20df7,
    0xf16fc800,0xbffe883f,0x306984ff,0x1bff93db,0x1fb77ff2,0xffe88000,
    0xfd9dffaa,0x1011003f,0x3ffa2010,0x3a200182,0x04ffc9ff,0x00004003,
    0x00000000,0x00000000,0x00000000,0x00000000,0x88000000,0x88dc3703,
    0x9999950b,0x17663999,0x42deb853,0x2aaaaa19,0xddd51aaa,0x0000003d,
    0x00000000,0x56fa87b8,0x5d4ff6df,0x1bbbbbbb,0x97fc47ee,0xbcffcac9,
    0x37777625,0xfff73ddd,0x0000003f,0x00000000,0x472362b2,0x32df55fa,
    0x8ee0003f,0x995051fe,0x00000001,0x00000000,0x99fb0000,0x44fe25dd,
    0x3b23f74f,0x2eeeeeee,0x00000408,0x00000000,0x00000000,0x1e81bb80,
    0x3313c4ba,0x01333333,0x00000000,0x00000000,0x20000000,0x2242f8de,
    0x0000120c,0x00000000,0x00000000,0x6c000000,0x00000591,0x00000000,
    0x00000000,0x00000000,0x00000000,0x00000000,0x00000000,0x00000000,
    0x00000000,0x00000000,0x00000000,0x00000000,
};

static signed short stb__times_bold_19_usascii_x[95]={ 0,1,1,0,0,1,0,1,0,0,0,0,0,0,
0,0,0,1,0,0,0,0,0,0,0,0,1,1,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,0,1,-1,0,0,0,0,0,0,0,0,0,0,
-1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,1,0,0, };
static signed short stb__times_bold_19_usascii_y[95]={ 15,3,3,3,3,3,3,3,3,3,3,4,12,10,
12,3,3,3,3,3,3,3,3,3,3,3,6,6,5,7,5,3,3,3,3,3,3,3,3,3,3,3,3,3,
3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,17,3,6,3,6,3,6,3,6,3,3,
3,3,3,6,6,6,6,6,6,6,4,7,7,7,7,7,7,3,3,3,9, };
static unsigned short stb__times_bold_19_usascii_w[95]={ 0,4,7,9,9,15,14,3,6,6,8,10,4,6,
4,5,8,7,8,8,8,8,9,9,8,8,4,4,10,10,10,7,16,13,11,12,12,11,10,14,14,7,9,14,
11,16,12,13,10,13,13,9,11,13,13,18,13,13,12,5,5,4,8,10,4,9,9,8,10,8,7,9,10,5,
6,10,5,14,10,8,9,10,8,7,6,9,9,13,9,9,8,6,2,6,10, };
static unsigned short stb__times_bold_19_usascii_h[95]={ 0,13,6,13,14,13,13,6,16,16,7,10,7,2,
4,13,13,12,12,13,12,13,13,13,13,13,10,13,9,5,9,13,16,12,12,13,12,12,12,13,12,12,13,12,
12,12,13,13,12,16,12,13,12,13,13,13,12,12,12,16,13,16,7,2,4,10,13,10,13,10,12,13,12,12,
16,12,12,9,9,10,13,13,9,10,12,9,9,9,8,12,8,16,16,16,3, };
static unsigned short stb__times_bold_19_usascii_s[95]={ 127,105,10,11,81,21,37,18,25,1,1,
89,120,65,38,116,12,35,62,31,43,40,49,59,52,61,122,122,16,22,50,
84,44,21,9,70,109,97,86,69,57,1,83,18,113,1,103,91,85,61,71,
1,45,106,92,11,57,72,44,75,121,39,111,54,33,100,21,71,1,118,30,
93,96,107,32,33,120,1,61,80,1,110,41,110,38,72,82,27,92,52,102,
18,15,8,43, };
static unsigned short stb__times_bold_19_usascii_t[95]={ 1,1,96,18,1,18,18,96,1,1,96,
73,86,96,96,18,32,73,73,32,73,32,32,32,18,18,60,18,86,96,86,
32,1,73,73,18,60,60,60,32,60,73,18,60,46,60,18,1,46,1,46,
46,46,32,32,46,46,60,60,1,1,1,86,96,96,73,32,73,32,73,46,
18,46,46,1,60,32,86,86,73,18,1,86,73,46,86,86,86,86,73,86,
1,1,1,96, };
static unsigned short stb__times_bold_19_usascii_a[95]={ 69,91,152,137,137,275,229,76,
91,91,137,156,69,91,69,76,137,137,137,137,137,137,137,137,
137,137,91,91,156,156,156,137,255,198,183,198,198,183,168,214,
214,107,137,214,183,259,198,214,168,214,198,153,183,198,198,275,
198,198,183,91,76,91,160,137,91,137,153,122,153,122,91,137,
153,76,91,153,76,229,153,137,153,153,122,107,91,153,137,198,
137,137,122,108,60,108,143, };

// Call this function with
//    font: NULL or array length
//    data: NULL or specified size
//    height: STB_FONT_times_bold_19_usascii_BITMAP_HEIGHT or STB_FONT_times_bold_19_usascii_BITMAP_HEIGHT_POW2
//    return value: spacing between lines
static void stb_font_times_bold_19_usascii(stb_fontchar font[STB_FONT_times_bold_19_usascii_NUM_CHARS],
                unsigned char data[STB_FONT_times_bold_19_usascii_BITMAP_HEIGHT][STB_FONT_times_bold_19_usascii_BITMAP_WIDTH],
                int height)
{
    int i,j;
    if (data != 0) {
        unsigned int *bits = stb__times_bold_19_usascii_pixels;
        unsigned int bitpack = *bits++, numbits = 32;
        for (i=0; i < STB_FONT_times_bold_19_usascii_BITMAP_WIDTH*height; ++i)
            data[0][i] = 0;  // zero entire bitmap
        for (j=1; j < STB_FONT_times_bold_19_usascii_BITMAP_HEIGHT-1; ++j) {
            for (i=1; i < STB_FONT_times_bold_19_usascii_BITMAP_WIDTH-1; ++i) {
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
        float recip_width = 1.0f / STB_FONT_times_bold_19_usascii_BITMAP_WIDTH;
        float recip_height = 1.0f / height;
        for (i=0; i < STB_FONT_times_bold_19_usascii_NUM_CHARS; ++i) {
            // pad characters so they bilerp from empty space around each character
            font[i].s0 = (stb__times_bold_19_usascii_s[i]) * recip_width;
            font[i].t0 = (stb__times_bold_19_usascii_t[i]) * recip_height;
            font[i].s1 = (stb__times_bold_19_usascii_s[i] + stb__times_bold_19_usascii_w[i]) * recip_width;
            font[i].t1 = (stb__times_bold_19_usascii_t[i] + stb__times_bold_19_usascii_h[i]) * recip_height;
            font[i].x0 = stb__times_bold_19_usascii_x[i];
            font[i].y0 = stb__times_bold_19_usascii_y[i];
            font[i].x1 = stb__times_bold_19_usascii_x[i] + stb__times_bold_19_usascii_w[i];
            font[i].y1 = stb__times_bold_19_usascii_y[i] + stb__times_bold_19_usascii_h[i];
            font[i].advance_int = (stb__times_bold_19_usascii_a[i]+8)>>4;
            font[i].s0f = (stb__times_bold_19_usascii_s[i] - 0.5f) * recip_width;
            font[i].t0f = (stb__times_bold_19_usascii_t[i] - 0.5f) * recip_height;
            font[i].s1f = (stb__times_bold_19_usascii_s[i] + stb__times_bold_19_usascii_w[i] + 0.5f) * recip_width;
            font[i].t1f = (stb__times_bold_19_usascii_t[i] + stb__times_bold_19_usascii_h[i] + 0.5f) * recip_height;
            font[i].x0f = stb__times_bold_19_usascii_x[i] - 0.5f;
            font[i].y0f = stb__times_bold_19_usascii_y[i] - 0.5f;
            font[i].x1f = stb__times_bold_19_usascii_x[i] + stb__times_bold_19_usascii_w[i] + 0.5f;
            font[i].y1f = stb__times_bold_19_usascii_y[i] + stb__times_bold_19_usascii_h[i] + 0.5f;
            font[i].advance = stb__times_bold_19_usascii_a[i]/16.0f;
        }
    }
}

#ifndef STB_SOMEFONT_CREATE
#define STB_SOMEFONT_CREATE              stb_font_times_bold_19_usascii
#define STB_SOMEFONT_BITMAP_WIDTH        STB_FONT_times_bold_19_usascii_BITMAP_WIDTH
#define STB_SOMEFONT_BITMAP_HEIGHT       STB_FONT_times_bold_19_usascii_BITMAP_HEIGHT
#define STB_SOMEFONT_BITMAP_HEIGHT_POW2  STB_FONT_times_bold_19_usascii_BITMAP_HEIGHT_POW2
#define STB_SOMEFONT_FIRST_CHAR          STB_FONT_times_bold_19_usascii_FIRST_CHAR
#define STB_SOMEFONT_NUM_CHARS           STB_FONT_times_bold_19_usascii_NUM_CHARS
#define STB_SOMEFONT_LINE_SPACING        STB_FONT_times_bold_19_usascii_LINE_SPACING
#endif

