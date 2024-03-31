// Font generated by stb_font_inl_generator.c (4/1 bpp)
//
// Following instructions show how to use the only included font, whatever it is, in
// a generic way so you can replace it with any other font by changing the include.
// To use multiple fonts, replace STB_SOMEFONT_* below with STB_FONT_times_12_usascii_*,
// and separately install each font. Note that the CREATE function call has a
// totally different name; it's just 'stb_font_times_12_usascii'.
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

#define STB_FONT_times_12_usascii_BITMAP_WIDTH         128
#define STB_FONT_times_12_usascii_BITMAP_HEIGHT         50
#define STB_FONT_times_12_usascii_BITMAP_HEIGHT_POW2    64

#define STB_FONT_times_12_usascii_FIRST_CHAR            32
#define STB_FONT_times_12_usascii_NUM_CHARS             95

#define STB_FONT_times_12_usascii_LINE_SPACING           8

static unsigned int stb__times_12_usascii_pixels[]={
    0x88110208,0x13330140,0x0aa80440,0x11002353,0x4c086620,0x8404c199,
    0x204c0a80,0x204c0608,0x14418098,0x41414431,0x730260a9,0x82441733,
    0x53730515,0x361f8817,0x64b99d12,0x223941b8,0x19733abc,0x17440a1c,
    0x89a090b1,0x06600ae1,0x24983a14,0x20d4b048,0x83a12a0e,0x489c431d,
    0x2a28cc73,0x4ae7232b,0xfc804c0a,0x12c120e1,0x71a61543,0x9844ecdc,
    0x20910f86,0xf88d32c5,0x70390740,0x5951dec1,0x513a2177,0x0a051195,
    0x4c38755c,0x150c4703,0xd1b944d0,0x97425c62,0x2e68b048,0x70741e84,
    0x44e98901,0xa89b1053,0x2050a671,0x0770eb73,0x20331894,0xac5622a6,
    0x21f11aa1,0x30e8b048,0x20e8788d,0x6d223882,0x81595953,0xc88a84ca,
    0xd8e0262a,0x2482543c,0x99a06a18,0x88a79398,0x04896a0e,0x9507468b,
    0x20b80684,0x18729239,0x2ea51165,0x3a1c1449,0x22682c44,0x151a0ea1,
    0x4315735b,0x2443bac9,0x55112258,0x21de4155,0x54dc241c,0x7950a131,
    0x2f223835,0x88766141,0x0c4b0384,0x00a8b057,0x9103ee05,0x8001a960,
    0x02001000,0x404400a0,0x22140000,0x2e288622,0x9889a829,0x88b2600a,
    0x0456621d,0x00000000,0x00000000,0x10101000,0x00310022,0x02621980,
    0x0000eea8,0x00000000,0x00000000,0x00000000,0x00000000,0x00000000,
    0x02200000,0x54404660,0x8980c408,0x30510180,0x20300a20,0x31188098,
    0x19984c43,0x444c4262,0x01033099,0x1aaa82a6,0x49713930,0x225b8ae8,
    0x26720e8a,0xc8970286,0x882540b8,0x1774c6cc,0x6c2f88ae,0x12c43f10,
    0x4299723f,0x26a60c8b,0x2206a363,0x40e89c0e,0x498e4aa2,0x9260510a,
    0x04987349,0x15c0e2c1,0x0e8511dc,0x534cb21c,0x0e4733a8,0x50e44ee4,
    0xb003540b,0x41406f44,0x44ee4caa,0x40f56cc5,0xd1176c28,0x02a78853,
    0x9acc381d,0xd14b871f,0xfb986f66,0x7025c488,0x0d41fc89,0x9850bf62,
    0x8f1dc934,0xec88b359,0x74a8ec40,0x1d072d89,0xbbb8f838,0x2d4f4418,
    0x3dca4c39,0x11a60598,0x8fcc030d,0x24995c28,0x2498d14a,0x27307706,
    0x9e98d13a,0x641c0e81,0x3103e8ab,0x4970e477,0x0c1e814e,0x2043443d,
    0x54147219,0x49ac4934,0x35048a4c,0xd0b24350,0x8388760b,0x4409b0f9,
    0x79d10e44,0xbd987bd5,0x5cde442a,0x2b662c44,0x666c0a4a,0x220ea60e,
    0x272a0aad,0x570af6a1,0x22055013,0xb9203aad,0xbe887301,0x00802040,
    0x40880008,0x08000200,0x00000000,0x00400002,0x00000000,0x00000000,
    0x00000000,0x00000000,0x98866228,0x26613310,0x179370a0,0x88666662,
    0x20133102,0x01331028,0xaa83d795,0x4c40624c,0x31013310,0x30106623,
    0x89e23333,0x7c89663e,0xbac450ea,0x2e7aaae2,0x2ba20b51,0x882cc1ea,
    0x5660ebbe,0x124ce25a,0x3e89d07d,0x106c4ba0,0x5c99c889,0xe81cd31a,
    0xbb44038a,0x22134421,0x22dc7605,0x1e476058,0x26573c93,0x0b6a3644,
    0x1c4ec03b,0x7441175c,0x066f21a0,0x234c1f44,0x10d100ab,0xb1d83b5b,
    0xd8575887,0x48acc5b1,0x32e24d2a,0x03b0b2e3,0x0588256c,0x7d10d0ba,
    0x44d05c80,0x86883cee,0xebd89368,0xd81ad882,0x54f4c3bb,0x712f7a21,
    0xb0b266d1,0x882eec03,0x20d09705,0x0b66602c,0x1071199a,0xb126b10d,
    0x1dd10b53,0x032603b0,0x75b38930,0x6c03b0b2,0x985885c9,0x0590680e,
    0x9a07c4a2,0x6882aadb,0x1d893588,0x859d887b,0x300b301d,0x325d3389,
    0x6c310ec2,0xe85d0b91,0x107e2621,0x10e9819d,0x887e23dd,0xd507ee01,
    0x4fe61b71,0xb1d50be8,0x540fe619,0x9855400a,0x433a290d,0x265bace9,
    0x403df13f,0x00ebaaec,0x00000000,0x00000000,0x00000000,0x22000000,
    0x22133119,0x33331099,0x82666621,0x82200998,0x80401998,0x030190ca,
    0x00040006,0x4cadcd1a,0x06436a55,0x1f45c8ba,0xae8ea6ba,0x26fa2499,
    0x883a60dd,0x5904c9ae,0x0f8829a0,0x0ba87664,0x2b880620,0x29368102,
    0x1d828742,0x1d83b12e,0x3b021d82,0x3b03635c,0xb82ec074,0x20db80ab,
    0x03730b21,0x00373031,0x851b5390,0x5c3b02bb,0x14760ec4,0x87604c76,
    0x3b0320f8,0x1d1503a2,0x362a0fa0,0x4ee03700,0x772abbaa,0x54e4c000,
    0xd817440c,0x0ec4caab,0x59b0eef6,0x1741d819,0x3ebcd819,0x06e09738,
    0x42403633,0x881880aa,0x683e20aa,0x03209158,0x1d8970ec,0x10ec08ec,
    0x191e21d8,0xb98ba1d8,0x9b0707ba,0x541709f9,0x2a00c402,0x00000262,
    0x3625c3b0,0x21d80f41,0x44c87608,0x47b0ec0d,0x03971643,0x0a83d331,
    0x40008001,0x4c000001,0x261bb13f,0x107f30ce,0x7ccb559d,0x17443cbc,
    0x549959f3,0x0447b20d,0xddd706c0,0x00000009,0x00000000,0x00000000,
    0x00000000,0x00000000,0x2ae20000,0x2aa254c3,0x11dd2a0b,0x42554555,
    0x50dc7540,0x56d43b59,0x2ea1daad,0x32a0c2da,0x0880423a,0x55555406,
    0x11043712,0x68cc1111,0x9cc76ae6,0x51cd6249,0x20a94c67,0x2165c0c8,
    0x9b449358,0x25984935,0x8d119ca8,0x5cd34ad9,0x18058922,0x55543773,
    0x734d40aa,0xb13c5703,0x15cb90e6,0x881d0738,0x2b158935,0x2a074448,
    0x171160bd,0x80835147,0x002aaaaa,0x499a5700,0xac4b2542,0x4aa54649,
    0x2a198cc2,0x449ac459,0x3b122b15,0x895dec42,0x88223185,0x00000000,
    0xdb0f5ed4,0x740bbb89,0x53750dbb,0x51831f6c,0xb8ea9367,0x1d51d30d,
    0x2ab6e1b7,0x003aa1c2,0x00000000,0x00000000,0x00000000,0x00000000,
    0x00000000,0x00000000,0x00000000,0x00000000,0x00000000,0x00000000,
    0x00000000,0x00000000,0x00000000,
};

static signed short stb__times_12_usascii_x[95]={ 0,1,0,0,0,0,0,0,0,0,0,0,0,0,
0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
0,0,-1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,-1,0,0,-1,0,0,0,0,0,0,0,
-1,0,0,0,0,0,-1,0,0,0,0,0,0,0,0,0,0,1,0,0,0, };
static signed short stb__times_12_usascii_y[95]={ 9,1,1,1,1,1,1,1,1,1,1,2,7,6,
7,1,1,1,1,1,1,1,1,1,1,1,4,4,2,4,2,1,1,1,1,1,1,1,1,1,1,1,1,1,
1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,10,1,4,1,4,1,4,1,4,1,1,
1,1,1,4,4,4,4,4,4,4,2,4,4,4,4,4,4,1,1,1,5, };
static unsigned short stb__times_12_usascii_w[95]={ 0,2,4,6,5,9,9,2,4,4,5,6,3,4,
2,4,6,4,5,5,6,5,5,5,5,5,3,3,6,6,6,5,10,8,7,7,8,7,6,8,8,4,5,8,
7,10,9,8,6,8,8,6,7,8,8,11,8,8,7,4,4,3,5,7,3,5,7,5,6,5,5,6,6,3,
4,6,3,9,6,6,7,6,4,4,4,6,6,8,6,6,5,4,2,4,6, };
static unsigned short stb__times_12_usascii_h[95]={ 0,9,4,9,9,9,9,4,11,11,5,7,4,1,
3,9,9,8,8,9,8,9,9,9,9,9,6,7,7,3,7,9,11,8,8,9,8,8,8,9,8,8,9,8,
8,8,9,9,8,11,8,9,8,9,9,9,8,8,8,11,9,11,5,2,3,6,9,6,9,6,8,8,8,8,
11,8,8,5,5,6,8,8,5,6,8,6,6,6,5,8,5,11,11,11,2, };
static unsigned short stb__times_12_usascii_s[95]={ 126,73,85,88,95,101,1,94,1,53,74,
88,90,58,101,41,53,39,75,68,68,74,80,76,82,116,106,102,95,104,81,
28,24,52,44,11,30,22,15,19,1,10,67,106,98,87,116,58,65,35,49,
34,34,95,86,104,14,5,120,44,111,49,38,118,97,1,60,32,46,7,122,
27,42,23,19,58,1,58,51,13,72,80,80,27,115,20,119,110,44,61,68,
14,11,6,111, };
static unsigned short stb__times_12_usascii_t[95]={ 1,1,41,1,1,1,13,41,1,1,41,
32,41,11,41,13,13,32,32,13,32,13,13,1,1,13,32,32,32,41,32,
13,1,32,32,13,32,32,32,13,32,32,1,23,23,23,1,1,23,1,23,
13,23,13,13,13,23,23,23,1,1,1,41,41,41,41,13,41,13,41,13,
23,23,23,1,23,23,41,41,41,23,23,41,41,23,41,32,32,41,32,41,
1,1,1,41, };
static unsigned short stb__times_12_usascii_a[95]={ 43,58,71,87,87,144,135,31,
58,58,87,98,43,58,43,48,87,87,87,87,87,87,87,87,
87,87,48,48,98,98,98,77,160,125,116,116,125,106,96,125,
125,58,67,125,106,154,125,125,96,125,116,96,106,125,125,164,
125,125,106,58,48,58,81,87,58,77,87,77,87,77,58,87,
87,48,48,87,48,135,87,87,87,87,58,67,48,87,87,125,
87,87,77,83,35,83,94, };

// Call this function with
//    font: NULL or array length
//    data: NULL or specified size
//    height: STB_FONT_times_12_usascii_BITMAP_HEIGHT or STB_FONT_times_12_usascii_BITMAP_HEIGHT_POW2
//    return value: spacing between lines
static void stb_font_times_12_usascii(stb_fontchar font[STB_FONT_times_12_usascii_NUM_CHARS],
                unsigned char data[STB_FONT_times_12_usascii_BITMAP_HEIGHT][STB_FONT_times_12_usascii_BITMAP_WIDTH],
                int height)
{
    int i,j;
    if (data != 0) {
        unsigned int *bits = stb__times_12_usascii_pixels;
        unsigned int bitpack = *bits++, numbits = 32;
        for (i=0; i < STB_FONT_times_12_usascii_BITMAP_WIDTH*height; ++i)
            data[0][i] = 0;  // zero entire bitmap
        for (j=1; j < STB_FONT_times_12_usascii_BITMAP_HEIGHT-1; ++j) {
            for (i=1; i < STB_FONT_times_12_usascii_BITMAP_WIDTH-1; ++i) {
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
        float recip_width = 1.0f / STB_FONT_times_12_usascii_BITMAP_WIDTH;
        float recip_height = 1.0f / height;
        for (i=0; i < STB_FONT_times_12_usascii_NUM_CHARS; ++i) {
            // pad characters so they bilerp from empty space around each character
            font[i].s0 = (stb__times_12_usascii_s[i]) * recip_width;
            font[i].t0 = (stb__times_12_usascii_t[i]) * recip_height;
            font[i].s1 = (stb__times_12_usascii_s[i] + stb__times_12_usascii_w[i]) * recip_width;
            font[i].t1 = (stb__times_12_usascii_t[i] + stb__times_12_usascii_h[i]) * recip_height;
            font[i].x0 = stb__times_12_usascii_x[i];
            font[i].y0 = stb__times_12_usascii_y[i];
            font[i].x1 = stb__times_12_usascii_x[i] + stb__times_12_usascii_w[i];
            font[i].y1 = stb__times_12_usascii_y[i] + stb__times_12_usascii_h[i];
            font[i].advance_int = (stb__times_12_usascii_a[i]+8)>>4;
            font[i].s0f = (stb__times_12_usascii_s[i] - 0.5f) * recip_width;
            font[i].t0f = (stb__times_12_usascii_t[i] - 0.5f) * recip_height;
            font[i].s1f = (stb__times_12_usascii_s[i] + stb__times_12_usascii_w[i] + 0.5f) * recip_width;
            font[i].t1f = (stb__times_12_usascii_t[i] + stb__times_12_usascii_h[i] + 0.5f) * recip_height;
            font[i].x0f = stb__times_12_usascii_x[i] - 0.5f;
            font[i].y0f = stb__times_12_usascii_y[i] - 0.5f;
            font[i].x1f = stb__times_12_usascii_x[i] + stb__times_12_usascii_w[i] + 0.5f;
            font[i].y1f = stb__times_12_usascii_y[i] + stb__times_12_usascii_h[i] + 0.5f;
            font[i].advance = stb__times_12_usascii_a[i]/16.0f;
        }
    }
}

#ifndef STB_SOMEFONT_CREATE
#define STB_SOMEFONT_CREATE              stb_font_times_12_usascii
#define STB_SOMEFONT_BITMAP_WIDTH        STB_FONT_times_12_usascii_BITMAP_WIDTH
#define STB_SOMEFONT_BITMAP_HEIGHT       STB_FONT_times_12_usascii_BITMAP_HEIGHT
#define STB_SOMEFONT_BITMAP_HEIGHT_POW2  STB_FONT_times_12_usascii_BITMAP_HEIGHT_POW2
#define STB_SOMEFONT_FIRST_CHAR          STB_FONT_times_12_usascii_FIRST_CHAR
#define STB_SOMEFONT_NUM_CHARS           STB_FONT_times_12_usascii_NUM_CHARS
#define STB_SOMEFONT_LINE_SPACING        STB_FONT_times_12_usascii_LINE_SPACING
#endif
