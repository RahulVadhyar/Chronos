// Font generated by stb_font_inl_generator.c (4/1 bpp)
//
// Following instructions show how to use the only included font, whatever it is, in
// a generic way so you can replace it with any other font by changing the include.
// To use multiple fonts, replace STB_SOMEFONT_* below with STB_FONT_times_16_usascii_*,
// and separately install each font. Note that the CREATE function call has a
// totally different name; it's just 'stb_font_times_16_usascii'.
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

#define STB_FONT_times_16_usascii_BITMAP_WIDTH         128
#define STB_FONT_times_16_usascii_BITMAP_HEIGHT         78
#define STB_FONT_times_16_usascii_BITMAP_HEIGHT_POW2   128

#define STB_FONT_times_16_usascii_FIRST_CHAR            32
#define STB_FONT_times_16_usascii_NUM_CHARS             95

#define STB_FONT_times_16_usascii_LINE_SPACING          10

static unsigned int stb__times_16_usascii_pixels[]={
    0x00000000,0x332a0000,0xc9ee4c0b,0x000080cc,0x2aa00000,0x51710a62,
    0xa9824417,0x0cc0aaaa,0x0cc240cc,0xb125c044,0x2a07a617,0x336a03d4,
    0x0483ae01,0x880f5c48,0x9f50aa2f,0x03ea1fb7,0x3502e037,0x1cc48530,
    0x3218804c,0xa540fa85,0x68b8d81e,0x801707c0,0x96e01f83,0x997c3f04,
    0x07006e0f,0x6448b30b,0xf88024c2,0xa544f882,0x053bc41e,0xa80a20f8,
    0x4fc01f81,0xa6c3f038,0x5550aa78,0xa87702a9,0x59132245,0x01fa94c0,
    0x03d4a8bd,0x5544079f,0x2090240f,0xdb80b89f,0x1643f00b,0xa6c3224d,
    0x12a35418,0x80743b89,0x201f55d8,0x81ea545d,0x52b80ee9,0x3880b81f,
    0x81fb57f0,0xe87e04f8,0xe8ee4960,0x48798331,0x07882e24,0xd01f9adc,
    0x203d4a87,0xf07c1fe8,0x00a83881,0x0e41743f,0x38575bf0,0x14f13c73,
    0x486407c4,0xb80f5032,0x03e20fe5,0xcb807a95,0x80f8d50f,0xc87e0484,
    0x04fc0484,0xc96a7108,0x121e60e5,0x01e60b89,0x3207ccb7,0x083d4a84,
    0x20fa96ce,0x0e20b80f,0x4c4b21f8,0x300fc02a,0x3ca8eaa4,0x498b5027,
    0x01f0ee24,0x2b3a62dc,0x07a9501d,0x5f06ce53,0x151c40fc,0x7dcd0fc0,
    0x405fcc04,0x4f2290f9,0x5c288ac9,0x99122d42,0x416e01d8,0x752a05fc,
    0x15e67441,0x413f37aa,0x75b90124,0x82000003,0x0d838038,0x8791234c,
    0xa80ee048,0x07a9503e,0x00420244,0x00080041,0x81c40000,0x4c04c0b8,
    0x2e0e6243,0xa801b840,0x3279531b,0x000080ab,0x00000000,0x2aaa2000,
    0x980881aa,0x981a8482,0x0000b3e0,0x00000000,0x00000000,0x20000000,
    0x00000000,0x00000000,0x00000000,0x00000000,0x00000000,0x00000000,
    0x00000000,0x0055dc40,0x2f2e2000,0x54c00000,0x8c40019a,0x2206ea18,
    0x00b2e202,0x39710375,0x44333220,0x26570bcb,0xea93220f,0xa85ec402,
    0x5d525c2e,0x85d92b80,0x50a84da8,0x1206da21,0x4c036390,0xfbac8954,
    0x543ccc81,0xc81f1a0f,0x17201744,0x741883ea,0x8798fc02,0x9248190d,
    0x00d4795a,0x43d02c3e,0x442d820f,0x2cc3e602,0x2e89703e,0x27c0be20,
    0x27d00ba0,0xcb83c45a,0x2b54ecce,0x7f00712c,0x22133157,0xc8381f47,
    0x2a1f303f,0xd12e07c7,0x1fa86a65,0x3a14cbd0,0xad881c9a,0x06bee20b,
    0x6c6c471c,0x43f60090,0xd8f50bf9,0x54c26444,0x887cc1fe,0x4b81f12f,
    0x7dc1c974,0x1362db00,0x190d759d,0x25303c40,0x2350c429,0x4fac82ba,
    0x26c7a893,0x4c813ee6,0x5df707cc,0x5744b81f,0xd01f981b,0xf8ba25c9,
    0x0efffec0,0x3376e0f1,0x267104dd,0xfb96c3d6,0x3a3c40c9,0x3c40d503,
    0x40f803e6,0xd036f44b,0x25c3f107,0x89c0f8ba,0x481e2499,0xca5c9012,
    0x17741f33,0x4407e1f8,0x03e63405,0x3a25c0f8,0x81f504da,0x8ba25c4c,
    0x45112e0f,0x20492078,0x996d6a0b,0x1437ee2f,0x2a81a259,0x0f985504,
    0x45b87f30,0xd303e8ae,0x8b707d79,0xec883e2e,0x703cc2cd,0x6c43881c,
    0x4eefe468,0x3620efe8,0x2f3e60cb,0x21e6fc43,0x1000bfd8,0x237e63db,
    0x402203fc,0x1bf31ed8,0x644007f5,0x402080bf,0x40403101,0x40080200,
    0x00000000,0x00000000,0x00000000,0x00000000,0x21aa8000,0x542cccca,
    0x2732a0aa,0x9710bcb8,0x5c42b983,0x443ca82c,0x777301b9,0x21e65453,
    0x79930cc9,0xcca83ca8,0x5997302a,0x0ec42a85,0x91766674,0x44d91623,
    0x4721543f,0x681fb84a,0x4990fa48,0x407e45c8,0x8683e41d,0x12e1323b,
    0x0f43b8f5,0x41f1604c,0x5c83e60e,0x30d1a224,0x34c481fd,0x4582e4b7,
    0x6b8482f8,0x4481f090,0x4c80706b,0x35d89100,0x07dc7d09,0x216c7a89,
    0x0c246ea9,0x8081fc79,0x35c0d45d,0x060ee848,0x33e0009f,0x10ae03ea,
    0xc9b207dd,0x1f88533f,0xbd1330f6,0x7ccd1024,0x483e6001,0x26120d70,
    0x41f983ff,0x1f301998,0xb82c07e6,0x98f980ed,0x376095ca,0x98cc1fa9,
    0x50dc093f,0x34e8001f,0x8241ae07,0x3ea1efd8,0x4263fb81,0x2441f47a,
    0x7d06d964,0x4091f317,0x21987aa9,0x10a04afa,0x8fa8005f,0x0241ae04,
    0x82f89ba6,0x7c5ba0f9,0x20ae0b20,0x275c0f47,0x07b005bd,0x205fc833,
    0x40104e81,0x41ea04bf,0xb07cc284,0x1c41f30b,0x82c0745b,0x3e20361e,
    0x0ee01ee2,0x8836c154,0x1441fa81,0x7c403f70,0x22341541,0x3e61fcc6,
    0x9ac88a60,0x57304881,0x1262c055,0xbb103a98,0x0b905881,0x00aef7a6,
    0x77b300d1,0x2ef7a079,0xaacd881c,0x4400044d,0x40400400,0x10000200,
    0x00220040,0x00220008,0x00880044,0x00000000,0x00000000,0x00000000,
    0x00000000,0xca85e5c4,0x931e5c3c,0x0f2e2399,0x19999997,0x33333326,
    0x4409931c,0x379930bc,0x5c2f2e60,0x333260bc,0xbcb980ab,0x81059950,
    0x1cccccc9,0x0fe41f98,0x71be2166,0x27c41907,0x1543e657,0x07f207f7,
    0x47b801f7,0x322f704b,0x6c87b80e,0x547b82b8,0x5e80f882,0x12f98064,
    0x18db0609,0x36a183e6,0x540fd886,0x0ea7a807,0x213e27a8,0x7d45c87a,
    0x40c3d42c,0x32f980f8,0x048fb805,0x7cc01f50,0xb85f3500,0x403d40f9,
    0x7a80757a,0x21ea0fe2,0x7a82e85c,0x807c4022,0xfd0048fb,0x807f1001,
    0xd93500f9,0x3d40f8c8,0x4025fd40,0x501bb37a,0x0b93333f,0x933f505d,
    0xe803e203,0x05f7000e,0x1f300bb0,0x5c7e26a0,0x03d40f89,0x200fefd4,
    0x2a04fcfa,0x85daaaaf,0xcaafa82e,0x5c01f101,0x1f773006,0x4c007dc0,
    0x5763500f,0x07a81f14,0x403fb7a8,0x2a03f57a,0x82e85c87,0x7c40227a,
    0x2201ae00,0x17cc17a4,0xa807cc0c,0x3e239f31,0x2a183d40,0x3d407f67,
    0x321ea0d9,0x07a82e85,0x2e034ccc,0x3e60d806,0x81a84e83,0x6c3500f9,
    0x0f507e66,0x3f63d415,0x42f47a81,0xeb85c87a,0x3ee03d42,0x0bfa601b,
    0xff306f54,0x3337f217,0xcfd887dc,0x2a866cc0,0x36619f91,0x266eccdf,
    0x9ff70bfd,0x442ff663,0x17fb31df,0x2600bfa6,0x00200bfd,0x00000000,
    0x00000000,0x00000000,0x00000000,0x00000000,0x00000000,0x00000000,
    0xcc980000,0x6664c2bc,0xccc981ab,0x33262ccc,0x14401acc,0x2b806e20,
    0x3100e5c4,0x50010800,0x41542a65,0x2b882ba9,0x2e2f45ee,0xa81dd50f,
    0x99ee2447,0x881ae04d,0x87f301fa,0x5303fcbc,0x654f2600,0x11f92e01,
    0xc891481f,0xf99ea7b1,0x83f21ea2,0x23d4187a,0x03fb01f9,0x47b901f8,
    0x14c1ae08,0x6540b2a0,0x83e1e802,0x226831e8,0x517ccf51,0x3d47f50f,
    0x3f31ea06,0xe809b550,0x203d8b81,0x71053069,0x2f260039,0x207c3d00,
    0x416a0cfb,0x0f51f27a,0xa99fa97e,0xea99fa85,0x803ea904,0x03d9541e,
    0xcbaa98f2,0x003b52aa,0x43d03c98,0x266e980f,0xacafa847,0x25e83d40,
    0xa85a99fa,0x983ecaaf,0x21e80fa3,0x0580f638,0x02ca80a6,0xe8221654,
    0x894c1f33,0xa94c67c7,0x7c43d407,0xf5031ea2,0x66643f88,0xc87a06ec,
    0xb82deccc,0x2600a600,0x039710bc,0xf9dfb972,0x50eaba63,0x203d4bfd,
    0x2a0fb87a,0x743d4107,0x05f11225,0xeaaaa87a,0x2600d41c,0x054e2002,
    0x02010400,0x5407a810,0x1ea1f547,0x7cc7a82a,0x41b606e3,0x350f601f,
    0x000000cc,0x80000000,0xd980bfd9,0x441ddccf,0x26ccccfd,0x3ecccfd9,
    0x9fb10fea,0xd8067d41,0x3ffffea3,0x00000000,0x00000000,0x00000000,
    0x00000000,0x00000000,0xa8800000,0x53154c1b,0x2ea03730,0x1aa8d541,
    0x64cd4153,0x13703951,0x25535037,0x263bbbb8,0x0001753b,0x93190607,
    0x4cccc522,0x03e2d099,0x4320d47d,0x25b8e43d,0x244f51f8,0x55f559f3,
    0xbacf98f7,0x99de7cc6,0x2ed91361,0x2ee01d02,0x53f27c41,0x5554daad,
    0x3e389aaa,0x5b073541,0x3e344db5,0x171f9322,0x0f87a2e8,0x2e81f174,
    0x33a0d704,0x0d8d9c82,0xd1c424e2,0x80166b31,0x9f81eab8,0xd502d428,
    0x655e64d8,0x0f45b075,0x03e1e81f,0x403e603b,0xcdc980f9,0x4c298642,
    0x2a91c521,0x8bcccccc,0x79903d0e,0x3e608f30,0x175d0f20,0x745b035f,
    0x7c3d03e1,0x17440ec0,0x9b70b970,0x03214c99,0x50008208,0x3e207e2d,
    0x85119d03,0x3d707a2f,0x3d16c1b6,0x0f8ba0fc,0x8326c16c,0xd8b87d1a,
    0x00220238,0xbee88000,0x300d80cd,0xcc881bfd,0x0ea5882b,0x33ea33e6,
    0x33e63fa8,0x37e63fa8,0x9aeefee0,0x907f90ea,0x00000000,0x01001000,
    0x00004008,0x00000000,0x00000000,0x00000000,0x00000000,0x00000000,
    0x00000000,0x2cb82600,0xbbb8590c,0xdd50bbbb,0x0000001d,0x00000000,
    0x00000000,0x950a9f40,0x222c4379,0x22088888,0x00000199,0x00000000,
    0x00000000,0x40200400,0x00000001,0x00000000,0x00000000,0x00000000,
    0x00000000,0x00000000,0x00000000,0x00000000,
};

static signed short stb__times_16_usascii_x[95]={ 0,1,0,0,0,0,0,0,0,0,1,0,0,0,
1,0,0,1,0,0,0,0,0,0,0,0,1,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
0,0,-1,0,0,0,0,0,0,0,0,0,0,0,0,1,0,0,0,-1,0,0,-1,0,0,0,0,0,0,0,
-2,0,0,0,0,0,-1,0,0,0,0,0,0,0,0,0,0,1,1,1,0, };
static signed short stb__times_16_usascii_y[95]={ 12,2,2,2,1,2,2,2,1,1,1,3,10,8,
10,1,2,2,2,2,2,2,2,2,2,2,5,5,3,5,3,2,1,2,2,2,2,2,2,2,2,2,2,2,
2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,1,2,2,14,2,5,1,5,1,5,1,5,1,1,
1,1,1,5,5,5,5,5,5,5,3,5,5,5,5,5,5,1,1,1,7, };
static unsigned short stb__times_16_usascii_w[95]={ 0,3,5,7,7,12,11,2,5,5,6,8,3,5,
2,5,7,5,7,7,7,7,7,7,7,7,2,3,8,8,8,6,13,11,9,10,10,9,8,11,11,5,6,11,
9,13,12,10,8,10,10,8,9,11,11,14,11,11,9,4,5,4,7,9,4,7,8,6,8,7,7,7,8,4,
5,8,4,12,8,7,8,8,5,6,5,8,8,11,8,8,7,5,1,5,8, };
static unsigned short stb__times_16_usascii_h[95]={ 0,11,5,11,13,11,11,5,15,15,7,9,5,2,
3,12,11,10,10,11,10,11,11,11,11,11,8,10,8,4,8,11,15,10,10,11,10,10,10,11,10,10,11,10,
10,10,11,11,10,13,10,11,10,11,11,11,10,10,10,13,12,13,6,2,3,8,12,8,12,8,11,11,11,11,
15,11,11,7,7,8,11,11,7,8,10,8,8,8,7,11,7,15,15,15,3, };
static unsigned short stb__times_16_usascii_s[95]={ 106,124,110,65,68,73,86,116,35,15,91,
75,106,28,1,91,98,53,67,106,59,114,1,9,17,40,102,124,84,119,93,
61,1,41,31,68,10,21,117,112,99,122,1,76,66,52,48,24,1,47,88,
103,42,91,79,25,20,8,32,63,85,58,98,18,13,1,97,121,76,18,57,
49,40,35,41,15,10,46,59,26,115,1,68,114,111,105,9,34,82,106,74,
29,27,21,4, };
static unsigned short stb__times_16_usascii_t[95]={ 13,1,64,17,1,17,17,64,1,1,64,
53,64,73,73,1,17,53,53,17,53,17,29,29,29,29,53,29,53,64,53,
29,1,53,53,29,53,53,41,29,41,17,41,41,41,41,29,17,53,1,41,
29,41,29,29,29,41,41,41,1,1,1,64,73,73,64,1,53,1,64,17,
17,17,17,1,17,17,64,64,64,1,17,64,53,41,53,64,64,64,1,64,
1,1,1,73, };
static unsigned short stb__times_16_usascii_a[95]={ 58,77,94,116,116,193,180,42,
77,77,116,130,58,77,58,64,116,116,116,116,116,116,116,116,
116,116,64,64,130,130,130,103,213,167,154,154,167,141,129,167,
167,77,90,167,141,206,167,167,129,167,154,129,141,167,167,218,
167,167,141,77,64,77,108,116,77,103,116,103,116,103,77,116,
116,64,64,116,64,180,116,116,116,116,77,90,64,116,116,167,
116,116,103,111,46,111,125, };

// Call this function with
//    font: NULL or array length
//    data: NULL or specified size
//    height: STB_FONT_times_16_usascii_BITMAP_HEIGHT or STB_FONT_times_16_usascii_BITMAP_HEIGHT_POW2
//    return value: spacing between lines
static void stb_font_times_16_usascii(stb_fontchar font[STB_FONT_times_16_usascii_NUM_CHARS],
                unsigned char data[STB_FONT_times_16_usascii_BITMAP_HEIGHT][STB_FONT_times_16_usascii_BITMAP_WIDTH],
                int height)
{
    int i,j;
    if (data != 0) {
        unsigned int *bits = stb__times_16_usascii_pixels;
        unsigned int bitpack = *bits++, numbits = 32;
        for (i=0; i < STB_FONT_times_16_usascii_BITMAP_WIDTH*height; ++i)
            data[0][i] = 0;  // zero entire bitmap
        for (j=1; j < STB_FONT_times_16_usascii_BITMAP_HEIGHT-1; ++j) {
            for (i=1; i < STB_FONT_times_16_usascii_BITMAP_WIDTH-1; ++i) {
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
        float recip_width = 1.0f / STB_FONT_times_16_usascii_BITMAP_WIDTH;
        float recip_height = 1.0f / height;
        for (i=0; i < STB_FONT_times_16_usascii_NUM_CHARS; ++i) {
            // pad characters so they bilerp from empty space around each character
            font[i].s0 = (stb__times_16_usascii_s[i]) * recip_width;
            font[i].t0 = (stb__times_16_usascii_t[i]) * recip_height;
            font[i].s1 = (stb__times_16_usascii_s[i] + stb__times_16_usascii_w[i]) * recip_width;
            font[i].t1 = (stb__times_16_usascii_t[i] + stb__times_16_usascii_h[i]) * recip_height;
            font[i].x0 = stb__times_16_usascii_x[i];
            font[i].y0 = stb__times_16_usascii_y[i];
            font[i].x1 = stb__times_16_usascii_x[i] + stb__times_16_usascii_w[i];
            font[i].y1 = stb__times_16_usascii_y[i] + stb__times_16_usascii_h[i];
            font[i].advance_int = (stb__times_16_usascii_a[i]+8)>>4;
            font[i].s0f = (stb__times_16_usascii_s[i] - 0.5f) * recip_width;
            font[i].t0f = (stb__times_16_usascii_t[i] - 0.5f) * recip_height;
            font[i].s1f = (stb__times_16_usascii_s[i] + stb__times_16_usascii_w[i] + 0.5f) * recip_width;
            font[i].t1f = (stb__times_16_usascii_t[i] + stb__times_16_usascii_h[i] + 0.5f) * recip_height;
            font[i].x0f = stb__times_16_usascii_x[i] - 0.5f;
            font[i].y0f = stb__times_16_usascii_y[i] - 0.5f;
            font[i].x1f = stb__times_16_usascii_x[i] + stb__times_16_usascii_w[i] + 0.5f;
            font[i].y1f = stb__times_16_usascii_y[i] + stb__times_16_usascii_h[i] + 0.5f;
            font[i].advance = stb__times_16_usascii_a[i]/16.0f;
        }
    }
}

#ifndef STB_SOMEFONT_CREATE
#define STB_SOMEFONT_CREATE              stb_font_times_16_usascii
#define STB_SOMEFONT_BITMAP_WIDTH        STB_FONT_times_16_usascii_BITMAP_WIDTH
#define STB_SOMEFONT_BITMAP_HEIGHT       STB_FONT_times_16_usascii_BITMAP_HEIGHT
#define STB_SOMEFONT_BITMAP_HEIGHT_POW2  STB_FONT_times_16_usascii_BITMAP_HEIGHT_POW2
#define STB_SOMEFONT_FIRST_CHAR          STB_FONT_times_16_usascii_FIRST_CHAR
#define STB_SOMEFONT_NUM_CHARS           STB_FONT_times_16_usascii_NUM_CHARS
#define STB_SOMEFONT_LINE_SPACING        STB_FONT_times_16_usascii_LINE_SPACING
#endif

