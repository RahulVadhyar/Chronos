// Font generated by stb_font_inl_generator.c (4/1 bpp)
//
// Following instructions show how to use the only included font, whatever it is, in
// a generic way so you can replace it with any other font by changing the include.
// To use multiple fonts, replace STB_SOMEFONT_* below with STB_FONT_arial_8_usascii_*,
// and separately install each font. Note that the CREATE function call has a
// totally different name; it's just 'stb_font_arial_8_usascii'.
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

#define STB_FONT_arial_8_usascii_BITMAP_WIDTH         128
#define STB_FONT_arial_8_usascii_BITMAP_HEIGHT         32
#define STB_FONT_arial_8_usascii_BITMAP_HEIGHT_POW2    32

#define STB_FONT_arial_8_usascii_FIRST_CHAR            32
#define STB_FONT_arial_8_usascii_NUM_CHARS             95

#define STB_FONT_arial_8_usascii_LINE_SPACING           5

static unsigned int stb__arial_8_usascii_pixels[]={
    0x10204082,0x44220220,0x04002010,0x81100842,0x01010419,0x80400400,
    0x1c102200,0x41b0d457,0x225d64c2,0x9066752b,0x12054597,0x5ec41ca7,
    0x2aa39751,0x10de428a,0x83326397,0x32219933,0x2165e45b,0x14ce3bbc,
    0x4388d471,0x3773710a,0x923885c7,0x243c9229,0x32ee99b7,0x055c3550,
    0x87b07715,0x8e29088a,0x4ea35553,0x86a486e0,0xa9205ce1,0x150b8551,
    0x10b8e369,0x85c17247,0x4751240a,0x5733489b,0x55150edc,0xbc833221,
    0x2697751b,0x65419931,0x42e17124,0x817330cc,0x702e350c,0x1464a6e1,
    0x2a48e217,0x9230a962,0x4e173dcc,0x21c45521,0x9a693a8b,0x39c444e3,
    0xa8d45492,0x17154b12,0x54711cdc,0x350b8711,0x85c17b79,0x3b991638,
    0x4e4caa4c,0x5cc32ee3,0x4439b50b,0x33326772,0x2e639712,0x8ddcc70c,
    0x3320ccd8,0x22665c4e,0x43514c93,0x22272244,0x99c42e3a,0x00000003,
    0x00208110,0x20000000,0x150c0008,0x0a21504c,0x25306aa6,0x0000031a,
    0x00000000,0x00000000,0x00000000,0x00000000,0x00000000,0x00000000,
    0x80000200,0x00865d40,0xc895e441,0x0411111a,0x41042042,0x44410810,
    0x40440208,0x21000440,0x32290d40,0xcb99440c,0x4dc72f20,0xa4930738,
    0x5cca6939,0x98dc6e6b,0x8b452173,0x2a19c493,0x95070bdb,0x7951c597,
    0x7254661b,0x5d21a82e,0x25991388,0x7186a370,0xc8655d21,0x5149c524,
    0x21c6c1b8,0x2ae2e2bc,0x42e551a9,0x2e2e1c42,0x238e2350,0x5466550a,
    0x1a82e71c,0x14d29252,0x2e032393,0x271171cc,0x4ceee61a,0x260ea2cb,
    0x5d4c6885,0x0e4a44b8,0x2a1cb871,0xda8e0cdd,0x6cd4664c,0x98d41738,
    0x45271173,0x70d4e232,0x54e2702e,0x510aa261,0x9c848122,0x5c4c9dc4,
    0xb8710e2a,0x70646a3a,0x8a8cc054,0xcc8173c8,0x2619910d,0x419732bc,
    0x27031cbc,0x15443538,0x81999b08,0x322b8dc4,0x1c688571,0x546e70e2,
    0x0151cb11,0xb9dc2a33,0x000002cd,0x00000000,0x00000000,0x00000000,
    0x00000000,0x00000000,0x00000000,0x00000000,0x08104100,0x40088822,
    0x88811100,0x00800440,0x86271981,0x103b9800,0x1032e202,0x17711e44,
    0x25a82ee2,0x5432172c,0x497973cb,0xca95521a,0x42ef2a3b,0x92a0dbca,
    0x2a059868,0x237730b9,0x83571cc9,0x4c5932c9,0x8c8a23a8,0x2e733708,
    0x6432a388,0x49019372,0x290d490b,0x0350352a,0x25452215,0x20359097,
    0x19c424b8,0x5c36a271,0x2aee9704,0x0925b953,0x24925559,0xb72aaaaa,
    0x66dc530b,0x4d3336a4,0x6d459b51,0xa4582a4c,0x248c849a,0x0910b219,
    0x9832ea19,0x5dc3952c,0xcb98a23b,0x2e639730,0x22f22a1c,0x44893372,
    0x486a350b,0x06a06a11,0x6522442a,0x36eea2ec,0x26122110,0x00003221,
    0x80000200,0x1728bb8a,0x66dc48ae,0x19a4350c,0x399b5035,0x8903336a,
    0x330712c4,0x166e4330,0x00000000,0x00000000,0x00000000,0x00000000,
    0x00000000,0x51518940,0x65d46ea1,0xa8c4e330,0x739750ca,0x22a4e041,
    0x10023cca,0x862088cc,0x00033000,0x13800000,0x40b8f625,0x5c717038,
    0x15537389,0x3b190ec7,0x472a0889,0x84494dca,0x0c4750bc,0x00005555,
    0x13800000,0x48871ec5,0x71392e20,0x9a9c4cce,0xa8b26e64,0x280732bb,
    0x00000350,0x00000000,0x5c5cab26,0x31bcd870,0x4e270ec3,0x14a71333,
    0x0000075a,0x00000000,0x00000000,0x00000000,0x00000000,0x00000000,
    0x00000000,0x00000000,0x00000000,0x00000000,0x00000000,
};

static signed short stb__arial_8_usascii_x[95]={ 0,0,0,0,0,0,0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,-1,0,0,0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,-1,0,0,0,0,0,0,0,0,0,0,
-1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0, };
static signed short stb__arial_8_usascii_y[95]={ 6,0,0,0,0,0,0,0,0,0,0,1,5,3,
5,0,0,0,0,0,0,0,0,0,0,0,2,2,1,2,1,0,0,0,0,0,0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,6,0,2,0,2,0,2,0,2,0,0,
0,0,0,2,2,2,2,2,2,2,0,2,2,2,2,2,2,0,0,0,2, };
static unsigned short stb__arial_8_usascii_w[95]={ 0,2,3,4,4,6,5,2,3,3,3,4,2,3,
2,2,4,3,4,4,4,4,4,4,4,4,2,2,4,4,4,4,8,6,5,5,5,5,5,6,5,2,4,5,
4,6,5,6,5,6,6,5,5,5,5,7,5,5,5,2,2,2,4,6,2,4,4,4,4,4,3,4,4,2,
3,4,2,6,4,4,4,4,3,4,2,4,4,6,4,4,4,3,2,3,4, };
static unsigned short stb__arial_8_usascii_h[95]={ 0,6,3,7,7,7,7,3,8,8,3,5,3,2,
1,7,7,6,6,7,6,7,7,6,7,7,4,6,5,3,5,6,8,6,6,7,6,6,6,7,6,6,7,6,
6,6,6,7,6,7,6,7,6,7,6,6,6,6,6,8,7,8,4,2,2,5,7,5,7,5,6,6,6,6,
8,6,6,4,4,5,6,6,4,5,7,5,4,4,4,6,4,8,8,8,3, };
static unsigned short stb__arial_8_usascii_s[95]={ 39,31,72,54,69,74,81,66,1,35,57,
106,69,76,90,97,7,52,81,17,56,64,87,14,100,92,20,68,91,52,96,
76,20,61,19,22,46,40,34,118,25,114,49,8,123,1,117,39,108,111,98,
105,87,1,78,70,64,58,52,29,125,32,40,83,80,101,59,111,12,116,38,
42,33,84,16,93,105,33,28,121,28,47,11,86,46,1,23,45,6,71,15,
12,9,5,61, };
static unsigned short stb__arial_8_usascii_t[95]={ 9,18,25,1,1,1,1,25,1,1,25,
18,25,25,25,1,10,18,18,10,18,1,1,18,1,1,25,18,18,25,18,
18,1,18,18,10,18,18,18,1,18,10,1,18,10,18,10,1,10,1,10,
1,10,10,10,10,10,10,10,1,1,1,25,25,25,18,1,18,10,18,10,
10,10,10,1,10,10,25,25,18,10,10,25,18,1,25,25,25,25,18,25,
1,1,1,25, };
static unsigned short stb__arial_8_usascii_a[95]={ 32,32,41,64,64,102,76,22,
38,38,45,67,32,38,32,32,64,64,64,64,64,64,64,64,
64,64,32,32,67,67,67,64,116,76,76,83,83,76,70,89,
83,32,57,76,64,95,83,89,76,89,83,76,70,83,76,108,
76,76,70,32,32,32,54,64,38,64,64,57,64,64,32,64,
64,25,25,57,25,95,64,64,64,64,38,57,32,64,57,83,
57,57,57,38,30,38,67, };

// Call this function with
//    font: NULL or array length
//    data: NULL or specified size
//    height: STB_FONT_arial_8_usascii_BITMAP_HEIGHT or STB_FONT_arial_8_usascii_BITMAP_HEIGHT_POW2
//    return value: spacing between lines
static void stb_font_arial_8_usascii(stb_fontchar font[STB_FONT_arial_8_usascii_NUM_CHARS],
                unsigned char data[STB_FONT_arial_8_usascii_BITMAP_HEIGHT][STB_FONT_arial_8_usascii_BITMAP_WIDTH],
                int height)
{
    int i,j;
    if (data != 0) {
        unsigned int *bits = stb__arial_8_usascii_pixels;
        unsigned int bitpack = *bits++, numbits = 32;
        for (i=0; i < STB_FONT_arial_8_usascii_BITMAP_WIDTH*height; ++i)
            data[0][i] = 0;  // zero entire bitmap
        for (j=1; j < STB_FONT_arial_8_usascii_BITMAP_HEIGHT-1; ++j) {
            for (i=1; i < STB_FONT_arial_8_usascii_BITMAP_WIDTH-1; ++i) {
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
        float recip_width = 1.0f / STB_FONT_arial_8_usascii_BITMAP_WIDTH;
        float recip_height = 1.0f / height;
        for (i=0; i < STB_FONT_arial_8_usascii_NUM_CHARS; ++i) {
            // pad characters so they bilerp from empty space around each character
            font[i].s0 = (stb__arial_8_usascii_s[i]) * recip_width;
            font[i].t0 = (stb__arial_8_usascii_t[i]) * recip_height;
            font[i].s1 = (stb__arial_8_usascii_s[i] + stb__arial_8_usascii_w[i]) * recip_width;
            font[i].t1 = (stb__arial_8_usascii_t[i] + stb__arial_8_usascii_h[i]) * recip_height;
            font[i].x0 = stb__arial_8_usascii_x[i];
            font[i].y0 = stb__arial_8_usascii_y[i];
            font[i].x1 = stb__arial_8_usascii_x[i] + stb__arial_8_usascii_w[i];
            font[i].y1 = stb__arial_8_usascii_y[i] + stb__arial_8_usascii_h[i];
            font[i].advance_int = (stb__arial_8_usascii_a[i]+8)>>4;
            font[i].s0f = (stb__arial_8_usascii_s[i] - 0.5f) * recip_width;
            font[i].t0f = (stb__arial_8_usascii_t[i] - 0.5f) * recip_height;
            font[i].s1f = (stb__arial_8_usascii_s[i] + stb__arial_8_usascii_w[i] + 0.5f) * recip_width;
            font[i].t1f = (stb__arial_8_usascii_t[i] + stb__arial_8_usascii_h[i] + 0.5f) * recip_height;
            font[i].x0f = stb__arial_8_usascii_x[i] - 0.5f;
            font[i].y0f = stb__arial_8_usascii_y[i] - 0.5f;
            font[i].x1f = stb__arial_8_usascii_x[i] + stb__arial_8_usascii_w[i] + 0.5f;
            font[i].y1f = stb__arial_8_usascii_y[i] + stb__arial_8_usascii_h[i] + 0.5f;
            font[i].advance = stb__arial_8_usascii_a[i]/16.0f;
        }
    }
}

#ifndef STB_SOMEFONT_CREATE
#define STB_SOMEFONT_CREATE              stb_font_arial_8_usascii
#define STB_SOMEFONT_BITMAP_WIDTH        STB_FONT_arial_8_usascii_BITMAP_WIDTH
#define STB_SOMEFONT_BITMAP_HEIGHT       STB_FONT_arial_8_usascii_BITMAP_HEIGHT
#define STB_SOMEFONT_BITMAP_HEIGHT_POW2  STB_FONT_arial_8_usascii_BITMAP_HEIGHT_POW2
#define STB_SOMEFONT_FIRST_CHAR          STB_FONT_arial_8_usascii_FIRST_CHAR
#define STB_SOMEFONT_NUM_CHARS           STB_FONT_arial_8_usascii_NUM_CHARS
#define STB_SOMEFONT_LINE_SPACING        STB_FONT_arial_8_usascii_LINE_SPACING
#endif

