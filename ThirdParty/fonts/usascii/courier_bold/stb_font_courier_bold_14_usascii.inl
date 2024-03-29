// Font generated by stb_font_inl_generator.c (4/1 bpp)
//
// Following instructions show how to use the only included font, whatever it is, in
// a generic way so you can replace it with any other font by changing the include.
// To use multiple fonts, replace STB_SOMEFONT_* below with STB_FONT_courier_bold_14_usascii_*,
// and separately install each font. Note that the CREATE function call has a
// totally different name; it's just 'stb_font_courier_bold_14_usascii'.
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

#define STB_FONT_courier_bold_14_usascii_BITMAP_WIDTH         128
#define STB_FONT_courier_bold_14_usascii_BITMAP_HEIGHT         60
#define STB_FONT_courier_bold_14_usascii_BITMAP_HEIGHT_POW2    64

#define STB_FONT_courier_bold_14_usascii_FIRST_CHAR            32
#define STB_FONT_courier_bold_14_usascii_NUM_CHARS             95

#define STB_FONT_courier_bold_14_usascii_LINE_SPACING           7

static unsigned int stb__courier_bold_14_usascii_pixels[]={
    0x00032054,0x30b506e0,0x3c864311,0x06cc2540,0xd30f74c0,0x00000000,
    0x5276c054,0x4d86fe21,0x4403baa0,0x5ec14c0f,0x0fd4ba4c,0xb07e65d1,
    0x220eea89,0x911762fa,0x7fd703bf,0xd5077f22,0xdfefb83b,0x5fc473e0,
    0xf30ffef9,0x416ab501,0x06aaa65c,0xf174997b,0x8bb27cc3,0x1b6baa2e,
    0x320fccba,0x5fe47b9d,0x4d95d719,0xf30ecafa,0x42f97a25,0x0fa24990,
    0x7c434c72,0xb93bbae1,0x45d1eedf,0x7a8fe61f,0x3e27b174,0x406b9740,
    0xb01f31f8,0xd2647e27,0x7cf51725,0x817bf502,0x0dbb687a,0xf72640b9,
    0xe8ba5bfb,0x7cc7f10d,0xd0fc3f70,0x20b92e85,0x37ae5fd8,0x9bb3ea2e,
    0x1369f36a,0x150be1f1,0x0fa1fae2,0x5f11ab1d,0x3a7e2640,0x20de8ba2,
    0x7dc3e62f,0x742e87e1,0x76dc0b92,0x23f7bf90,0x7746fefa,0x5b8d74ff,
    0x0dbf88be,0xd68d507e,0x6406b8f9,0x3fffff14,0x0641f8ba,0x4fa2e8f5,
    0x6b9740f8,0x64d73e80,0x50be27d4,0x273e27f5,0x210be2fa,0x5f07dcef,
    0x17c2a96c,0xf9fa9320,0x401f8ba2,0x3d71745d,0x3e65d0d7,0x97cc4541,
    0x9d2e89f9,0x2a223f31,0x177f446d,0x67dd40be,0x32d4d700,0x32640354,
    0x99741f1f,0x1f997c0f,0x077f6274,0x362ec5f5,0x7fdc4fff,0xb93ffa65,
    0x7fc40cef,0x8033e5bd,0xc87e202e,0x5c0fa2ee,0x23e61fdc,0x41ec760f,
    0x07a612a0,0x445ff301,0x10080105,0xccda8020,0xa817fe3d,0x01800c00,
    0x04206f2a,0x00000000,0x00000000,0x00000000,0x00000000,0x00000000,
    0x00000000,0x32600000,0x004c0aab,0x98179355,0x9505532a,0x01501555,
    0x3c885d70,0x00001db0,0x12f775c0,0x883ddddd,0x361440aa,0x742ffedf,
    0x37bff602,0x7d57ee1f,0x3ff7ba0e,0x37fbee0e,0x390fa200,0x401f5075,
    0xfd882db9,0x1557641d,0xa87eeafe,0x3ee2feef,0x13a21f30,0xf01559d5,
    0x4d362dc7,0x1f99e60f,0x983d897c,0x54e43dac,0x0bcaf883,0x6f417ef4,
    0x04ee46ca,0x745d1aa0,0x4e8d5042,0x40ef77ec,0x1f31aa2f,0x3e25b89b,
    0xd8d516a1,0x6443ffdf,0x3fe21dbc,0x82e81fee,0xffc87e24,0xdb13604f,
    0x7bd00115,0x805d09fb,0xd82fbbff,0x457c40fe,0xf11361fc,0x43f89e61,
    0x3f884ddb,0x900ba16e,0x03f1288d,0xfec883f1,0xd710f20d,0x805d09bb,
    0xf302decf,0x3fbfaa09,0x5cb71ae1,0x66c61f45,0x0f30fc45,0x007ec05d,
    0x8a1ea0f6,0x801f13e8,0xb98cd84c,0x7cc007c0,0x221f8400,0x222fa9cf,
    0x884fa8af,0x4efcc194,0x882e84d9,0xa89b80ee,0x7cc4d80f,0x0753e98b,
    0x7d41eec8,0x33f20dff,0x03fd9502,0x261bb322,0xfeb82efd,0x4dd82fff,
    0x067ff7fc,0x74437d31,0x7fe4299e,0xe883d03e,0x20024ffe,0x20101ccb,
    0x99301ccb,0x2f322039,0x00200200,0x7f402004,0xfff51fff,0x000103ff,
    0x00000008,0x00000000,0x00000000,0x00000000,0x5510dc00,0x2aa206a6,
    0x04d54408,0x554406a6,0x0074c0aa,0x8d449db5,0x446a21a8,0x880bb21a,
    0x4ea80aaa,0xa80d54c0,0x8be0aaaa,0x0ffd9ffc,0xb97fbbee,0x3f25feef,
    0xfffa86fe,0xf301442f,0xbb7dc777,0x2edf90ef,0x407d30ef,0x445ffffc,
    0x3ffa205d,0x7fff42ff,0x0f887a1f,0x321f98f6,0x92dc3f15,0x87980fc5,
    0xeda80aa9,0xebb640aa,0x07647dc0,0x3a03333a,0x8db85d13,0xd73cc0aa,
    0x0c8bb2e8,0x2e3d83e2,0x400b5185,0x50f300fa,0xdfd905fd,0x03fbd03b,
    0x3fa07ff6,0xf53e87dd,0x1efbdb85,0x8a8f53cc,0x07c400fb,0x9902647b,
    0xfd02f2e2,0x40f30c45,0x980b702e,0x417ea04f,0xffd07e4e,0x07ff709f,
    0x20ffbbe6,0x0f8801fa,0x2e06b8f6,0xc81fdb36,0x40f33540,0xd00b702e,
    0x0ff3e205,0x5f41f8fa,0x3ffb86e9,0x10355f30,0x40a8b27f,0x220fa8de,
    0xf36b89cf,0x200d9137,0x886c89fa,0x6e441bf9,0x817f3019,0x445f55e8,
    0x7445f13e,0x320ce88b,0x7d40cf9d,0xb33dd009,0xfd10fe27,0xdffd305d,
    0x1ffffd45,0x3ff221fc,0x7fffc40e,0x3ffffe3f,0x237ffd40,0x0ffc8ffd,
    0x1ff93ff7,0x9fccfff2,0x44ffd5fa,0xff886fff,0x08023fff,0x00440100,
    0x00000801,0x00000000,0x00000000,0x00000000,0x00000000,0x00000000,
    0x00000000,0x5530a980,0x8854c298,0xaa880aaa,0x8d4c1a88,0x55530aa8,
    0x83532a85,0x415511aa,0x10aaaaaa,0x22355555,0x554c0aaa,0x55512aaa,
    0x80554c01,0x43ffb4fe,0x54bfe2fe,0xffc83fff,0x3fe0efcb,0xfb2ffb8e,
    0x3fea3fff,0x3fa25fd9,0x3e67ff56,0xf91fffff,0x3f29ffff,0x3fee4fff,
    0xfff96fff,0x17ffa0df,0xb8991ff8,0x1f0ff56f,0x42f4d740,0xd0d5155b,
    0x20fc5d05,0xd51360f8,0x227b0fc2,0x97cc3e3c,0x74d53f5b,0x7f6c0ba2,
    0x132dbf00,0x0fdd5fd7,0x27ef401f,0x5bdf9ea8,0x99be82e8,0x1f14d81f,
    0x418f9ea8,0x3e08dbbd,0x9f9d5720,0x3ee6fa49,0x03e9f882,0xb8999d3f,
    0xf87afecd,0x1bffd020,0xb9fd9f30,0xfffd05d0,0x172f503f,0x3603ffea,
    0x2a0f85ff,0xffe81f86,0xb9eb81ff,0x9df31f06,0x79cf8db8,0x3e8f10f8,
    0xf5ff109d,0x5d05d09f,0x2fbe80fc,0x7b01b6a8,0x907c7173,0x25d03f0b,
    0xfffe87c8,0xfc97c42f,0x5c4475c4,0x2a6be60f,0xf317d10f,0x7f91ff03,
    0xd10dfcc4,0x7dc0be27,0x1013d706,0x22d7337d,0x4c2fb9af,0x26fa20bf,
    0xb0fd47c9,0x44ffec1b,0x55bfe24f,0xffff73ff,0x4fff21ff,0xf9af42fd,
    0x47ffffa2,0x0ffe9ffc,0xff983f88,0xffffc85f,0x5dfff96f,0x326fffa8,
    0x222effff,0x07ff76ff,0x00000000,0x00000000,0x00000000,0x70000000,
    0x9b9103dd,0x0174c000,0x565cc000,0x50579300,0xa8dcc179,0x1acb880b,
    0x5d40bc98,0x4ee21ca9,0x2eeea1b9,0x417d440b,0x0baa2bdc,0x2201ff40,
    0xdc81d85c,0xdceb85ec,0x3bb7f21f,0x07f65f70,0xd89fbbf7,0x3f20fece,
    0x3fe66dfe,0x37b64fd8,0xb05d01ff,0x807bee09,0xf9103dfb,0x2605d03b,
    0x9bec87cc,0x24d83e62,0x43d07a2d,0x2aabe63b,0x88076c4e,0x54542fee,
    0x360ba02f,0x7e441b9f,0x1ed7c40d,0x4c4177dc,0x6ef741bf,0x0efda887,
    0x8b66a8d5,0xf701e21e,0x2d89dddd,0x54077e40,0x2e17402f,0xf503fecf,
    0x43db643f,0xfff506fd,0x223e6dff,0x4c57c0fc,0xd517f12e,0x17d466c7,
    0x89262336,0x261a88af,0x7ec409ce,0x33ea1fd9,0xb85d01c9,0x6c40fe8d,
    0x7fffc0cf,0x4177540f,0x7ec1bf98,0x7ff46fef,0x27ff4c5f,0x31bfbfe6,
    0xda87dffd,0xfff33fff,0xd8ffc8df,0x3ffffa7f,0x10dfcc42,0x7e49fffd,
    0xbd53301d,0x740f7dc0,0x01001102,0x44004008,0x00004400,0xfff88000,
    0x2a0443ff,0x1ffd001e,0x0ec2e440,0x00000000,0x00000000,0x00000000,
    0x00000000,0x00000000,0x00000000,0x446ea000,0x267750bb,0x2aeaa0bb,
    0x440c80ba,0x2000bbab,0x41aaaaa8,0x1154e24b,0x6cc04111,0x2eee2112,
    0x0002bbbb,0x4dfec000,0x1df91fe9,0x6ff43df7,0x3a265dff,0x377fe619,
    0xffb83b07,0x31746fff,0x7fff536f,0x3e21b31f,0xbb33ecfc,0x007bbbbb,
    0x9f880000,0x9ae44cbf,0x9aeb540f,0x87ffffa7,0xff907e3d,0x44688001,
    0x04444776,0x079118e2,0x00000000,0x42eefde8,0x5a84d9f8,0xefc8f35d,
    0x5c3d16c0,0x3ff26d8f,0x20aa7fff,0x00000354,0x00000000,0x03febf60,
    0x5ae03fb2,0x5f10f9be,0xe89f445d,0x311d8762,0x00033333,0x00000000,
    0x2e000000,0x9f106c8f,0x3fd5ff10,0x2e088c7f,0x006fb9ff,0x00000000,
    0x00000000,0x00000000,0x00000000,0x00000000,0x00000000,0x00000000,
    0x00000000,0x00000000,0x00000000,0x00000000,
};

static signed short stb__courier_bold_14_usascii_x[95]={ 0,2,1,0,1,0,1,2,3,1,1,0,2,1,
2,1,1,1,0,0,0,0,1,0,1,1,2,2,-1,0,0,1,1,-1,0,0,0,0,0,0,0,1,0,0,
0,-1,-1,0,0,0,0,0,0,0,-1,-1,0,0,0,3,1,1,1,-1,2,0,-1,0,0,0,0,0,0,0,
1,0,0,-1,0,0,-1,0,0,0,0,0,0,-1,0,0,1,2,3,2,0, };
static signed short stb__courier_bold_14_usascii_y[95]={ 10,1,2,1,1,2,3,2,2,2,2,2,8,5,
8,1,1,1,1,1,2,2,1,2,1,1,4,4,2,4,2,2,1,2,2,2,2,2,2,2,2,2,2,2,
2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,1,2,1,12,1,4,2,4,2,4,2,4,2,2,
2,2,2,4,4,4,4,4,4,4,2,4,4,4,4,4,4,2,2,2,5, };
static unsigned short stb__courier_bold_14_usascii_w[95]={ 0,3,5,7,6,7,6,3,4,4,6,7,4,6,
3,6,6,6,7,7,7,7,6,7,6,6,3,4,8,8,8,6,6,9,8,7,7,7,8,8,8,6,8,8,
8,9,9,8,8,8,8,7,7,8,9,9,8,8,7,3,6,4,6,9,3,8,9,8,8,7,8,8,8,7,
5,8,7,9,8,7,9,8,8,7,8,8,8,9,8,8,6,4,2,4,7, };
static unsigned short stb__courier_bold_14_usascii_h[95]={ 0,10,4,11,11,9,8,5,10,10,6,8,4,3,
3,11,10,9,9,10,8,9,10,9,10,10,7,8,8,5,8,9,11,8,8,9,8,8,8,9,8,8,9,8,
8,8,8,9,8,10,8,9,8,9,8,8,8,8,8,10,11,10,5,2,3,7,9,7,9,7,8,9,8,8,
11,8,8,6,6,7,9,9,6,7,9,7,6,6,6,9,6,10,10,10,3, };
static unsigned short stb__courier_bold_14_usascii_s[95]={ 124,51,67,35,1,65,9,122,77,55,30,
42,62,73,122,22,65,83,90,82,25,98,90,106,97,104,124,122,33,53,16,
27,15,117,108,10,92,84,75,18,56,49,34,30,21,11,1,47,105,111,87,
114,100,1,65,39,69,60,114,120,8,72,46,92,80,50,73,84,56,93,51,
38,78,43,29,96,1,20,37,67,19,1,101,59,10,75,11,1,110,29,119,
60,43,46,84, };
static unsigned short stb__courier_bold_14_usascii_t[95]={ 9,1,51,1,1,13,42,22,1,1,51,
42,51,51,28,1,1,13,13,1,42,13,1,13,1,1,1,13,42,51,42,
23,1,33,33,23,33,33,33,23,33,33,23,33,33,33,33,13,23,1,23,
13,33,23,33,33,23,23,23,1,1,1,51,51,51,42,13,42,13,42,23,
13,23,23,1,23,42,51,51,42,13,13,42,42,13,42,51,51,42,13,42,
1,1,1,51, };
static unsigned short stb__courier_bold_14_usascii_a[95]={ 119,119,119,119,119,119,119,119,
119,119,119,119,119,119,119,119,119,119,119,119,119,119,119,119,
119,119,119,119,119,119,119,119,119,119,119,119,119,119,119,119,
119,119,119,119,119,119,119,119,119,119,119,119,119,119,119,119,
119,119,119,119,119,119,119,119,119,119,119,119,119,119,119,119,
119,119,119,119,119,119,119,119,119,119,119,119,119,119,119,119,
119,119,119,119,119,119,119, };

// Call this function with
//    font: NULL or array length
//    data: NULL or specified size
//    height: STB_FONT_courier_bold_14_usascii_BITMAP_HEIGHT or STB_FONT_courier_bold_14_usascii_BITMAP_HEIGHT_POW2
//    return value: spacing between lines
static void stb_font_courier_bold_14_usascii(stb_fontchar font[STB_FONT_courier_bold_14_usascii_NUM_CHARS],
                unsigned char data[STB_FONT_courier_bold_14_usascii_BITMAP_HEIGHT][STB_FONT_courier_bold_14_usascii_BITMAP_WIDTH],
                int height)
{
    int i,j;
    if (data != 0) {
        unsigned int *bits = stb__courier_bold_14_usascii_pixels;
        unsigned int bitpack = *bits++, numbits = 32;
        for (i=0; i < STB_FONT_courier_bold_14_usascii_BITMAP_WIDTH*height; ++i)
            data[0][i] = 0;  // zero entire bitmap
        for (j=1; j < STB_FONT_courier_bold_14_usascii_BITMAP_HEIGHT-1; ++j) {
            for (i=1; i < STB_FONT_courier_bold_14_usascii_BITMAP_WIDTH-1; ++i) {
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
        float recip_width = 1.0f / STB_FONT_courier_bold_14_usascii_BITMAP_WIDTH;
        float recip_height = 1.0f / height;
        for (i=0; i < STB_FONT_courier_bold_14_usascii_NUM_CHARS; ++i) {
            // pad characters so they bilerp from empty space around each character
            font[i].s0 = (stb__courier_bold_14_usascii_s[i]) * recip_width;
            font[i].t0 = (stb__courier_bold_14_usascii_t[i]) * recip_height;
            font[i].s1 = (stb__courier_bold_14_usascii_s[i] + stb__courier_bold_14_usascii_w[i]) * recip_width;
            font[i].t1 = (stb__courier_bold_14_usascii_t[i] + stb__courier_bold_14_usascii_h[i]) * recip_height;
            font[i].x0 = stb__courier_bold_14_usascii_x[i];
            font[i].y0 = stb__courier_bold_14_usascii_y[i];
            font[i].x1 = stb__courier_bold_14_usascii_x[i] + stb__courier_bold_14_usascii_w[i];
            font[i].y1 = stb__courier_bold_14_usascii_y[i] + stb__courier_bold_14_usascii_h[i];
            font[i].advance_int = (stb__courier_bold_14_usascii_a[i]+8)>>4;
            font[i].s0f = (stb__courier_bold_14_usascii_s[i] - 0.5f) * recip_width;
            font[i].t0f = (stb__courier_bold_14_usascii_t[i] - 0.5f) * recip_height;
            font[i].s1f = (stb__courier_bold_14_usascii_s[i] + stb__courier_bold_14_usascii_w[i] + 0.5f) * recip_width;
            font[i].t1f = (stb__courier_bold_14_usascii_t[i] + stb__courier_bold_14_usascii_h[i] + 0.5f) * recip_height;
            font[i].x0f = stb__courier_bold_14_usascii_x[i] - 0.5f;
            font[i].y0f = stb__courier_bold_14_usascii_y[i] - 0.5f;
            font[i].x1f = stb__courier_bold_14_usascii_x[i] + stb__courier_bold_14_usascii_w[i] + 0.5f;
            font[i].y1f = stb__courier_bold_14_usascii_y[i] + stb__courier_bold_14_usascii_h[i] + 0.5f;
            font[i].advance = stb__courier_bold_14_usascii_a[i]/16.0f;
        }
    }
}

#ifndef STB_SOMEFONT_CREATE
#define STB_SOMEFONT_CREATE              stb_font_courier_bold_14_usascii
#define STB_SOMEFONT_BITMAP_WIDTH        STB_FONT_courier_bold_14_usascii_BITMAP_WIDTH
#define STB_SOMEFONT_BITMAP_HEIGHT       STB_FONT_courier_bold_14_usascii_BITMAP_HEIGHT
#define STB_SOMEFONT_BITMAP_HEIGHT_POW2  STB_FONT_courier_bold_14_usascii_BITMAP_HEIGHT_POW2
#define STB_SOMEFONT_FIRST_CHAR          STB_FONT_courier_bold_14_usascii_FIRST_CHAR
#define STB_SOMEFONT_NUM_CHARS           STB_FONT_courier_bold_14_usascii_NUM_CHARS
#define STB_SOMEFONT_LINE_SPACING        STB_FONT_courier_bold_14_usascii_LINE_SPACING
#endif

