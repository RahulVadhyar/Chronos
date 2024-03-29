// Font generated by stb_font_inl_generator.c (4/1 bpp)
//
// Following instructions show how to use the only included font, whatever it is, in
// a generic way so you can replace it with any other font by changing the include.
// To use multiple fonts, replace STB_SOMEFONT_* below with STB_FONT_times_9_usascii_*,
// and separately install each font. Note that the CREATE function call has a
// totally different name; it's just 'stb_font_times_9_usascii'.
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

#define STB_FONT_times_9_usascii_BITMAP_WIDTH         128
#define STB_FONT_times_9_usascii_BITMAP_HEIGHT         32
#define STB_FONT_times_9_usascii_BITMAP_HEIGHT_POW2    32

#define STB_FONT_times_9_usascii_FIRST_CHAR            32
#define STB_FONT_times_9_usascii_NUM_CHARS             95

#define STB_FONT_times_9_usascii_LINE_SPACING           6

static unsigned int stb__times_9_usascii_pixels[]={
    0x8810c104,0x9804cc42,0x23985cc1,0x85503300,0x0cc35511,0x22153042,
    0x43303041,0x9880cc09,0x441aa819,0x838a2850,0x24188260,0x85120d49,
    0xac2a8914,0x51333999,0x2313518c,0xd018528c,0x105530a1,0x21c321c9,
    0x450b8331,0x351894c4,0x23715435,0x2a8e241a,0x2241a872,0x26159109,
    0x5c1b32ab,0xb80c08a8,0x1a9c9835,0x3015c0ae,0x44a1302e,0x51729c41,
    0x2750e433,0x646e241a,0x141a8aa1,0x0cc1b70e,0x5351836a,0x41c99818,
    0x80e438da,0xc8c4761c,0x81328c40,0x21ad2538,0x20d4323a,0x32398d44,
    0x238106a0,0x3755398a,0x3250e622,0x2dc60628,0x2a83b137,0x21864750,
    0x12285c1a,0x4dce4671,0x351555c0,0x266a1c48,0x4c702f22,0x18c66a20,
    0x70886aaa,0x48e60c33,0x50b6eb2a,0xc99a8335,0x28542830,0x0c14510e,
    0x483506cc,0x00000014,0x00408080,0x04000000,0x08608220,0x0666606a,
    0x44266130,0x00000022,0x00000000,0x00000000,0x00000000,0x00000000,
    0x00000000,0x98000000,0x0cc0d4c1,0x35015026,0x984c0a98,0x3314c662,
    0x04c6a2a6,0x330a8831,0x531a854c,0x260c42a1,0x2355532a,0x80aa9819,
    0x71985ce1,0x0cd4c710,0x54589835,0x25882e09,0x9114910a,0x3315146e,
    0x3447109c,0x54051c87,0xa8d631a9,0x5c1b4881,0x0d985c23,0x1c2e3a98,
    0x22281755,0x1906e62d,0x2b06388a,0x3486434a,0x2ea1c43b,0x14c2d809,
    0xa98b0571,0x260da40b,0x5174c181,0x25864731,0x0366489a,0x98ea6e17,
    0x428e208c,0x2608d9aa,0x071123ac,0x7112a059,0x3160de4c,0x41dd8535,
    0x25820419,0x226a388c,0x0661c6a3,0x36242a51,0xd8852442,0x241704b9,
    0x2606e0e2,0x128e21c8,0x1c4cc585,0xa8931632,0xc98e6aa0,0x982aa24b,
    0x5433509b,0x2a0cdc2a,0x4829ab82,0x6c433071,0x30f21260,0x324c7e27,
    0x70744137,0x4c6cc935,0x0000000c,0x00000000,0x00000000,0x00000000,
    0x00000000,0x00000000,0x00000000,0x00000000,0x55303300,0x260caa81,
    0x4330662a,0x4c54c0a9,0x4c6aaa22,0x1510a88a,0xaa98aaa6,0x1035530a,
    0x510d54c1,0x206a146e,0x50098600,0x35169103,0x88e62a91,0x8588760e,
    0x1b0c1548,0x912c5922,0x22124422,0x222a8b54,0x31710754,0x0ae0e4cc,
    0x98153162,0x20da41a9,0x21c5291a,0x0483733b,0x90ae0159,0x9069162c,
    0x53164906,0x0b207348,0x2616a0d4,0x2e60b884,0x5d41ad81,0x98759319,
    0xb0483555,0x3b09301b,0x156c58b3,0x1d490e76,0x32cad853,0x54281c45,
    0x532460c8,0x09077303,0x261c406a,0x1241a8ca,0x43606ce4,0x122c5920,
    0x41b24124,0x30cd2429,0x93350501,0x2009f65c,0x03662cbb,0x531cc0aa,
    0x55d31e52,0x47aa3665,0x1b33aacc,0x4c3a61d1,0x954f4c0d,0x1d41a9d9,
    0xb82575b3,0x352cdb81,0x000120f4,0x00000000,0x00000000,0x00000000,
    0x98000000,0x2aa6e510,0x4c4a5528,0x4c298182,0x4433150a,0xaaa8a629,
    0x23753020,0x8175529a,0x2e6eaa08,0x3110caa1,0x54c2aaa6,0x10446611,
    0x5c402a63,0x317108b9,0x25061626,0x4d4e6709,0x4d42ae28,0x4550b60b,
    0xaa8aa488,0x4c6ee639,0x4918948a,0x1333149a,0x0b981442,0x27200aa6,
    0x9350e41c,0x0c855d4c,0x51354864,0xa82193b8,0x0c826264,0x23899866,
    0x4e331bb9,0x88c21824,0x40000088,0x454510aa,0xb7714c1a,0x31ecc181,
    0x92b26357,0x547b329b,0xbb8412c8,0x4d5c7719,0x93750444,0xa80000b1,
    0x020002aa,0x00100000,0x00000000,0x00000000,0x00000000,0x00000000,
    0x00000000,0x00000000,0x00000000,
};

static signed short stb__times_9_usascii_x[95]={ 0,0,0,0,0,0,0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
0,0,-1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,-1,0,0,-1,0,0,0,0,0,0,0,
-1,0,0,0,0,0,-1,0,0,0,0,0,0,0,0,0,0,1,0,0,0, };
static signed short stb__times_9_usascii_y[95]={ 7,1,1,1,1,1,1,1,1,1,1,2,6,4,
6,1,1,1,1,1,1,1,1,1,1,1,3,3,2,3,2,1,1,1,1,1,1,1,1,1,1,1,1,1,
1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,8,1,3,1,3,1,3,1,3,1,1,
1,1,1,3,3,3,3,3,3,3,2,3,3,3,3,3,3,1,1,1,4, };
static unsigned short stb__times_9_usascii_w[95]={ 0,2,3,4,4,7,7,2,3,3,4,5,2,3,
2,3,4,4,4,4,4,4,4,4,4,4,2,2,5,5,5,4,8,6,5,6,6,5,5,6,6,3,4,6,
5,8,7,6,5,6,6,5,5,6,6,8,6,6,5,3,3,3,4,6,2,4,5,4,5,4,4,4,5,3,
3,5,3,7,5,4,5,5,3,3,3,5,4,6,4,5,4,3,1,3,5, };
static unsigned short stb__times_9_usascii_h[95]={ 0,7,3,7,7,7,7,3,8,8,4,5,3,2,
2,7,7,6,6,7,6,7,7,7,7,7,5,6,5,3,5,7,8,6,6,7,6,6,6,7,6,6,7,6,
6,6,7,7,6,8,6,7,6,7,7,7,6,6,6,8,7,8,4,1,2,5,7,5,7,5,6,6,6,6,
8,6,6,4,4,5,6,6,4,5,6,5,5,5,4,6,4,8,8,8,2, };
static unsigned short stb__times_9_usascii_s[95]={ 47,59,102,72,77,82,102,99,1,43,83,
27,96,121,118,124,18,83,103,29,115,34,39,62,67,67,7,94,1,106,120,
1,19,108,88,110,76,70,64,117,53,60,54,40,34,25,94,47,7,28,116,
6,104,51,44,58,88,81,47,35,90,39,63,112,125,22,23,33,12,53,72,
99,110,95,15,1,77,88,77,38,13,19,73,49,123,43,17,10,58,97,68,
11,9,5,112, };
static unsigned short stb__times_9_usascii_t[95]={ 9,1,25,1,1,1,1,25,1,1,25,
25,25,25,25,1,10,18,18,10,18,10,10,1,1,10,25,18,25,25,18,
10,1,18,18,1,18,18,18,1,18,18,1,18,18,18,1,1,18,1,10,
10,10,10,10,10,10,10,18,1,1,1,25,28,25,25,10,25,10,25,10,
10,10,10,1,18,10,25,25,25,18,18,25,25,10,25,25,25,25,18,25,
1,1,1,25, };
static unsigned short stb__times_9_usascii_a[95]={ 33,43,53,65,65,108,101,23,
43,43,65,73,33,43,33,36,65,65,65,65,65,65,65,65,
65,65,36,36,73,73,73,58,120,94,87,87,94,79,72,94,
94,43,51,94,79,116,94,94,72,94,87,72,79,94,94,123,
94,94,79,43,36,43,61,65,43,58,65,58,65,58,43,65,
65,36,36,65,36,101,65,65,65,65,43,51,36,65,65,94,
65,65,58,62,26,62,70, };

// Call this function with
//    font: NULL or array length
//    data: NULL or specified size
//    height: STB_FONT_times_9_usascii_BITMAP_HEIGHT or STB_FONT_times_9_usascii_BITMAP_HEIGHT_POW2
//    return value: spacing between lines
static void stb_font_times_9_usascii(stb_fontchar font[STB_FONT_times_9_usascii_NUM_CHARS],
                unsigned char data[STB_FONT_times_9_usascii_BITMAP_HEIGHT][STB_FONT_times_9_usascii_BITMAP_WIDTH],
                int height)
{
    int i,j;
    if (data != 0) {
        unsigned int *bits = stb__times_9_usascii_pixels;
        unsigned int bitpack = *bits++, numbits = 32;
        for (i=0; i < STB_FONT_times_9_usascii_BITMAP_WIDTH*height; ++i)
            data[0][i] = 0;  // zero entire bitmap
        for (j=1; j < STB_FONT_times_9_usascii_BITMAP_HEIGHT-1; ++j) {
            for (i=1; i < STB_FONT_times_9_usascii_BITMAP_WIDTH-1; ++i) {
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
        float recip_width = 1.0f / STB_FONT_times_9_usascii_BITMAP_WIDTH;
        float recip_height = 1.0f / height;
        for (i=0; i < STB_FONT_times_9_usascii_NUM_CHARS; ++i) {
            // pad characters so they bilerp from empty space around each character
            font[i].s0 = (stb__times_9_usascii_s[i]) * recip_width;
            font[i].t0 = (stb__times_9_usascii_t[i]) * recip_height;
            font[i].s1 = (stb__times_9_usascii_s[i] + stb__times_9_usascii_w[i]) * recip_width;
            font[i].t1 = (stb__times_9_usascii_t[i] + stb__times_9_usascii_h[i]) * recip_height;
            font[i].x0 = stb__times_9_usascii_x[i];
            font[i].y0 = stb__times_9_usascii_y[i];
            font[i].x1 = stb__times_9_usascii_x[i] + stb__times_9_usascii_w[i];
            font[i].y1 = stb__times_9_usascii_y[i] + stb__times_9_usascii_h[i];
            font[i].advance_int = (stb__times_9_usascii_a[i]+8)>>4;
            font[i].s0f = (stb__times_9_usascii_s[i] - 0.5f) * recip_width;
            font[i].t0f = (stb__times_9_usascii_t[i] - 0.5f) * recip_height;
            font[i].s1f = (stb__times_9_usascii_s[i] + stb__times_9_usascii_w[i] + 0.5f) * recip_width;
            font[i].t1f = (stb__times_9_usascii_t[i] + stb__times_9_usascii_h[i] + 0.5f) * recip_height;
            font[i].x0f = stb__times_9_usascii_x[i] - 0.5f;
            font[i].y0f = stb__times_9_usascii_y[i] - 0.5f;
            font[i].x1f = stb__times_9_usascii_x[i] + stb__times_9_usascii_w[i] + 0.5f;
            font[i].y1f = stb__times_9_usascii_y[i] + stb__times_9_usascii_h[i] + 0.5f;
            font[i].advance = stb__times_9_usascii_a[i]/16.0f;
        }
    }
}

#ifndef STB_SOMEFONT_CREATE
#define STB_SOMEFONT_CREATE              stb_font_times_9_usascii
#define STB_SOMEFONT_BITMAP_WIDTH        STB_FONT_times_9_usascii_BITMAP_WIDTH
#define STB_SOMEFONT_BITMAP_HEIGHT       STB_FONT_times_9_usascii_BITMAP_HEIGHT
#define STB_SOMEFONT_BITMAP_HEIGHT_POW2  STB_FONT_times_9_usascii_BITMAP_HEIGHT_POW2
#define STB_SOMEFONT_FIRST_CHAR          STB_FONT_times_9_usascii_FIRST_CHAR
#define STB_SOMEFONT_NUM_CHARS           STB_FONT_times_9_usascii_NUM_CHARS
#define STB_SOMEFONT_LINE_SPACING        STB_FONT_times_9_usascii_LINE_SPACING
#endif

