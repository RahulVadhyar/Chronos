// Font generated by stb_font_inl_generator.c (4/1 bpp)
//
// Following instructions show how to use the only included font, whatever it is, in
// a generic way so you can replace it with any other font by changing the include.
// To use multiple fonts, replace STB_SOMEFONT_* below with STB_FONT_courier_10_usascii_*,
// and separately install each font. Note that the CREATE function call has a
// totally different name; it's just 'stb_font_courier_10_usascii'.
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

#define STB_FONT_courier_10_usascii_BITMAP_WIDTH         128
#define STB_FONT_courier_10_usascii_BITMAP_HEIGHT         36
#define STB_FONT_courier_10_usascii_BITMAP_HEIGHT_POW2    64

#define STB_FONT_courier_10_usascii_FIRST_CHAR            32
#define STB_FONT_courier_10_usascii_NUM_CHARS             95

#define STB_FONT_courier_10_usascii_LINE_SPACING           5

static unsigned int stb__courier_10_usascii_pixels[]={
    0x4c182182,0x11a85400,0x18220000,0x206a0544,0x41882819,0x50440102,
    0xa8808155,0x432154c1,0x88132863,0x2142aaa0,0x0aaa2152,0x8915cc05,
    0x54099452,0x1305cd42,0x814dc141,0x26a09842,0x40a14639,0x3284c512,
    0x20995541,0x30ce2852,0x0c0ab221,0x8945150e,0x0a832ea2,0x40a08998,
    0x4c501882,0x5c399820,0x221a941a,0x42940e52,0x214e2852,0x438300a2,
    0x8aaa63ba,0x20a98298,0x0d414199,0x33145014,0x84c20d4c,0x28cc3349,
    0x2504ca05,0x098a9142,0x9401860a,0x7570cc18,0x4cc09941,0x06010620,
    0x8e213044,0x51880b9a,0x4ca13144,0x42aaa280,0x55128942,0x511aa985,
    0x14d44833,0x41898573,0x409981b9,0x050142c2,0xb81c5357,0x4a38e02a,
    0x2b2a2828,0x014a6172,0x40000000,0x40018088,0x00060208,0x0006a204,
    0x002aa000,0x00000443,0x00000000,0x00000000,0x00000000,0x00000000,
    0x00000000,0x00000000,0x20350000,0x130d4409,0x10544040,0x21a88040,
    0x755329aa,0x00000141,0x44414040,0xa8040260,0x84280a50,0x399a80c1,
    0x47339851,0x26141a9a,0x1451c150,0x4e255388,0xb926372a,0xaa810912,
    0x3220a3ac,0x31286c2a,0x1c414d54,0x104c2a6a,0x5143022e,0x26159504,
    0x9451c130,0x26144c1b,0x942a4a29,0x9461cc18,0x0c50aae1,0x44263149,
    0x28e0a882,0x1826ae05,0x8282a88a,0x2aaa0aaa,0x05c02aa0,0x53513064,
    0x140a0528,0x0eae1894,0x288a1328,0x04ca2860,0x22314514,0x04c050a0,
    0x14066a03,0x2a71144c,0x02814442,0x52862505,0x26e15540,0x73155c49,
    0x8d55c153,0x8aaa0aa8,0x32a0a9a8,0x15315442,0x5930aa70,0x552399cc,
    0xaca80c81,0x5488b260,0x001c3225,0x00200000,0x00000000,0x00000000,
    0x00000000,0x00000000,0x00000000,0x00000000,0x22000000,0xa8088713,
    0x0800039a,0x880cc010,0x88110040,0x02044408,0x010040c4,0x5106206a,
    0x320c4a01,0x8a2131aa,0x44ae7349,0x1910ae24,0x75705055,0x95155221,
    0x4eab2215,0x5912aac8,0x32214c15,0x3032a0aa,0x0a50aa01,0x251414c4,
    0x51a85109,0x406154a6,0x2305019a,0x41418942,0x20854112,0x225050a2,
    0x2510a261,0x04c0a620,0x1aaa81a8,0x2530a6aa,0x030a6a32,0x281402f2,
    0x4141aab8,0x205dc2aa,0x757050a2,0x26a14541,0x01982943,0x2140140a,
    0x428c6551,0x0a0528a1,0x06250c26,0x218a0505,0x145050a2,0x65543557,
    0x03312aa0,0x05640ea2,0x94ce63a8,0x55c4911b,0x8711913a,0x2ab20aca,
    0xca8ea912,0x4415910a,0x55913aac,0xc9856541,0x0e2571aa,0x55912440,
    0x00000001,0x00000000,0x00000000,0x00000000,0x54a602a0,0x1a864280,
    0x41aa9871,0x5542a981,0x2a6154c2,0x286a710a,0x7571cce6,0xb88d4d41,
    0xab8a262a,0x2a2041aa,0x20a601aa,0x22829862,0x06185398,0x41889885,
    0x2e286239,0x93154c09,0x14441328,0xd8c4a0a2,0x26294a68,0xd022208a,
    0x23144881,0x3555001b,0x565440c4,0x22133331,0x4282628a,0xb86a20a8,
    0x414144c0,0x52312808,0x362294a4,0x806aaa22,0x22baa82a,0x2520e829,
    0x20a0ccd4,0x73511a9a,0x37054d43,0x09552615,0x1aac8370,0x9a445751,
    0x8e2a2e02,0x0a800188,0x00005000,0x00000060,0x00000000,0x00000000,
    0x00000000,0x00000000,0x00000000,0x00000000,0x2e228180,0x555531bb,
    0x00000003,0x00000000,0x00000000,0x220aaa80,0x0000442a,0x00000000,
    0x00000000,0x00000000,0x00026500,0x00000000,0x00000000,0x00000000,
    0x00000000,0x00000000,0x00000000,0x00000000,0x00000000,
};

static signed short stb__courier_10_usascii_x[95]={ 0,2,1,0,0,0,1,2,2,1,0,0,1,0,
1,0,0,0,0,0,0,0,1,0,0,1,1,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,2,0,0, };
static signed short stb__courier_10_usascii_y[95]={ 7,1,1,1,1,1,2,1,1,1,1,2,5,4,
5,1,1,1,1,1,1,1,1,1,1,1,3,3,2,3,2,1,1,1,1,1,1,1,1,1,1,1,1,1,
1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,9,1,3,1,3,1,3,1,3,1,1,
1,1,1,3,3,3,3,3,3,3,1,3,3,3,3,3,3,1,1,1,3, };
static unsigned short stb__courier_10_usascii_w[95]={ 0,2,4,5,5,5,4,2,3,2,4,5,3,5,
3,5,5,5,5,5,5,5,4,5,5,4,3,3,5,5,5,4,5,6,5,5,5,5,5,5,5,5,6,6,
5,6,5,5,5,5,6,5,5,5,6,6,5,5,5,2,4,2,5,6,3,5,5,5,6,5,5,5,5,5,
4,6,5,6,5,5,5,6,5,5,5,5,6,6,5,6,4,2,1,2,5, };
static unsigned short stb__courier_10_usascii_h[95]={ 0,7,4,7,7,7,6,4,8,8,4,5,4,1,
3,7,7,6,6,7,6,7,7,7,7,7,5,5,5,3,5,7,7,6,6,7,6,6,6,7,6,6,7,6,
6,6,6,7,6,8,6,7,6,7,6,6,6,6,6,8,7,8,3,1,2,5,7,5,7,5,6,6,6,6,
8,6,6,4,4,5,6,6,4,5,7,5,4,5,4,6,4,8,8,8,3, };
static unsigned short stb__courier_10_usascii_s[95]={ 124,52,100,66,72,78,108,125,1,30,112,
36,72,17,123,94,1,89,119,14,113,118,32,100,55,61,19,124,13,117,1,
89,112,101,95,26,83,77,71,106,59,65,45,40,34,27,21,33,8,18,118,
43,106,37,93,86,80,74,53,24,84,27,7,23,13,48,20,30,7,42,49,
55,112,100,13,67,47,105,94,54,61,14,88,60,39,7,76,23,66,1,83,
10,8,5,1, };
static unsigned short stb__courier_10_usascii_t[95]={ 7,1,25,1,1,1,18,10,1,1,25,
25,25,31,25,1,10,18,18,10,18,1,10,1,1,1,25,1,25,25,25,
1,1,18,18,10,18,18,18,1,18,18,1,18,18,18,18,1,18,1,10,
10,10,10,10,10,10,10,18,1,1,1,31,31,31,25,10,25,10,25,10,
10,10,10,1,10,18,25,25,25,10,18,25,25,1,25,25,25,25,18,25,
1,1,1,31, };
static unsigned short stb__courier_10_usascii_a[95]={ 85,85,85,85,85,85,85,85,
85,85,85,85,85,85,85,85,85,85,85,85,85,85,85,85,
85,85,85,85,85,85,85,85,85,85,85,85,85,85,85,85,
85,85,85,85,85,85,85,85,85,85,85,85,85,85,85,85,
85,85,85,85,85,85,85,85,85,85,85,85,85,85,85,85,
85,85,85,85,85,85,85,85,85,85,85,85,85,85,85,85,
85,85,85,85,85,85,85, };

// Call this function with
//    font: NULL or array length
//    data: NULL or specified size
//    height: STB_FONT_courier_10_usascii_BITMAP_HEIGHT or STB_FONT_courier_10_usascii_BITMAP_HEIGHT_POW2
//    return value: spacing between lines
static void stb_font_courier_10_usascii(stb_fontchar font[STB_FONT_courier_10_usascii_NUM_CHARS],
                unsigned char data[STB_FONT_courier_10_usascii_BITMAP_HEIGHT][STB_FONT_courier_10_usascii_BITMAP_WIDTH],
                int height)
{
    int i,j;
    if (data != 0) {
        unsigned int *bits = stb__courier_10_usascii_pixels;
        unsigned int bitpack = *bits++, numbits = 32;
        for (i=0; i < STB_FONT_courier_10_usascii_BITMAP_WIDTH*height; ++i)
            data[0][i] = 0;  // zero entire bitmap
        for (j=1; j < STB_FONT_courier_10_usascii_BITMAP_HEIGHT-1; ++j) {
            for (i=1; i < STB_FONT_courier_10_usascii_BITMAP_WIDTH-1; ++i) {
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
        float recip_width = 1.0f / STB_FONT_courier_10_usascii_BITMAP_WIDTH;
        float recip_height = 1.0f / height;
        for (i=0; i < STB_FONT_courier_10_usascii_NUM_CHARS; ++i) {
            // pad characters so they bilerp from empty space around each character
            font[i].s0 = (stb__courier_10_usascii_s[i]) * recip_width;
            font[i].t0 = (stb__courier_10_usascii_t[i]) * recip_height;
            font[i].s1 = (stb__courier_10_usascii_s[i] + stb__courier_10_usascii_w[i]) * recip_width;
            font[i].t1 = (stb__courier_10_usascii_t[i] + stb__courier_10_usascii_h[i]) * recip_height;
            font[i].x0 = stb__courier_10_usascii_x[i];
            font[i].y0 = stb__courier_10_usascii_y[i];
            font[i].x1 = stb__courier_10_usascii_x[i] + stb__courier_10_usascii_w[i];
            font[i].y1 = stb__courier_10_usascii_y[i] + stb__courier_10_usascii_h[i];
            font[i].advance_int = (stb__courier_10_usascii_a[i]+8)>>4;
            font[i].s0f = (stb__courier_10_usascii_s[i] - 0.5f) * recip_width;
            font[i].t0f = (stb__courier_10_usascii_t[i] - 0.5f) * recip_height;
            font[i].s1f = (stb__courier_10_usascii_s[i] + stb__courier_10_usascii_w[i] + 0.5f) * recip_width;
            font[i].t1f = (stb__courier_10_usascii_t[i] + stb__courier_10_usascii_h[i] + 0.5f) * recip_height;
            font[i].x0f = stb__courier_10_usascii_x[i] - 0.5f;
            font[i].y0f = stb__courier_10_usascii_y[i] - 0.5f;
            font[i].x1f = stb__courier_10_usascii_x[i] + stb__courier_10_usascii_w[i] + 0.5f;
            font[i].y1f = stb__courier_10_usascii_y[i] + stb__courier_10_usascii_h[i] + 0.5f;
            font[i].advance = stb__courier_10_usascii_a[i]/16.0f;
        }
    }
}

#ifndef STB_SOMEFONT_CREATE
#define STB_SOMEFONT_CREATE              stb_font_courier_10_usascii
#define STB_SOMEFONT_BITMAP_WIDTH        STB_FONT_courier_10_usascii_BITMAP_WIDTH
#define STB_SOMEFONT_BITMAP_HEIGHT       STB_FONT_courier_10_usascii_BITMAP_HEIGHT
#define STB_SOMEFONT_BITMAP_HEIGHT_POW2  STB_FONT_courier_10_usascii_BITMAP_HEIGHT_POW2
#define STB_SOMEFONT_FIRST_CHAR          STB_FONT_courier_10_usascii_FIRST_CHAR
#define STB_SOMEFONT_NUM_CHARS           STB_FONT_courier_10_usascii_NUM_CHARS
#define STB_SOMEFONT_LINE_SPACING        STB_FONT_courier_10_usascii_LINE_SPACING
#endif

