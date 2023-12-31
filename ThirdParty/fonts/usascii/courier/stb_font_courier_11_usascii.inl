// Font generated by stb_font_inl_generator.c (4/1 bpp)
//
// Following instructions show how to use the only included font, whatever it is, in
// a generic way so you can replace it with any other font by changing the include.
// To use multiple fonts, replace STB_SOMEFONT_* below with STB_FONT_courier_11_usascii_*,
// and separately install each font. Note that the CREATE function call has a
// totally different name; it's just 'stb_font_courier_11_usascii'.
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

#define STB_FONT_courier_11_usascii_BITMAP_WIDTH         128
#define STB_FONT_courier_11_usascii_BITMAP_HEIGHT         38
#define STB_FONT_courier_11_usascii_BITMAP_HEIGHT_POW2    64

#define STB_FONT_courier_11_usascii_FIRST_CHAR            32
#define STB_FONT_courier_11_usascii_NUM_CHARS             95

#define STB_FONT_courier_11_usascii_LINE_SPACING           5

static unsigned int stb__courier_11_usascii_pixels[]={
    0x38263808,0x88002044,0x18c00151,0x000003a8,0x21c85500,0x04420400,
    0x72880108,0x0984c663,0x43771154,0x4711c099,0x39440bb9,0xa82ea250,
    0x4caea1aa,0x417530aa,0x26a14713,0x9ac98500,0xb0654dc3,0x98d42627,
    0x55026131,0x2418c314,0x4450e292,0x28145281,0x50ca2833,0x44509826,
    0x404409ab,0x8704c263,0x9054e660,0x332a2426,0x9a883532,0x28a48711,
    0x91ca0e14,0x15370c88,0x54d46ea6,0x18518852,0x14902e20,0x502a2431,
    0x3098c426,0x2205dcc1,0x489066a2,0x0660a28a,0x9441d5c5,0x4aa6a51b,
    0x228a252a,0x702600c2,0x29aa8355,0x4660a162,0x5dcc1309,0x8630a290,
    0x051471c3,0x4a09050e,0x22e514a2,0x286aaa2a,0x04c14dc4,0x0351400a,
    0x09854ae5,0x7114c451,0x8cc33305,0x542ea60a,0x4ce61300,0x86aae0ba,
    0x235532ab,0x556cc10b,0x75010170,0x4406e657,0x082800ba,0x4c188820,
    0x40042000,0x02099402,0x15700004,0x00001300,0x03750000,0x00000000,
    0x00000000,0x00000000,0x00000000,0x00000000,0x00000000,0x00000000,
    0x08200000,0x42210710,0x006a6029,0x21555000,0x2aa23aac,0x2a60aaa1,
    0x886aa21b,0x262e62aa,0x42e2710b,0x4aa3712a,0x22aa61a8,0x508170c8,
    0x4a0c99a8,0x2e198cc0,0x2aaa0ea2,0x914500a0,0x2850188c,0x1450a38e,
    0x1431144e,0x5c426225,0x2e142608,0x43826399,0x270a299c,0x8a181828,
    0x184c0aba,0xa8501980,0x145004c0,0x4c5141dc,0x26e62aa8,0x41304d41,
    0x32448624,0x0ce650a1,0x4280cc03,0x441500a2,0x14aa20a0,0x70514155,
    0x44131305,0x98142aa9,0xaa8904c3,0x21432429,0x30186e53,0x288a1405,
    0x0c282200,0x51418a65,0x2a809898,0x8142a9b8,0x1c9ab809,0x154e4c50,
    0x5d4c7551,0x2e066062,0x750261aa,0x4dc0d875,0x51555c42,0x1aaa8737,
    0x2a064526,0x65491582,0x2019511a,0x000dcc00,0x23775001,0x0002aac8,
    0x00080404,0x00000010,0x00000000,0x00000000,0x00000000,0x00000000,
    0x2155cc00,0x710baba8,0x510102e2,0xb89b9815,0x2aea0530,0xb8711711,
    0x5555c0aa,0xb8555731,0x46aaa0aa,0x5d40aab9,0x00401100,0x1318c514,
    0x54d42894,0x33280441,0x281808a8,0x50a1430a,0x28e28514,0x55051433,
    0xaa835330,0x2250f649,0x2a808c22,0x221d55cc,0x59015500,0x88a81853,
    0x454130c2,0x42818a81,0x31150a11,0xaa882988,0x5c041142,0x0d40304a,
    0x11022262,0x28a0e720,0x21d55c0c,0x1d541aa9,0x8a14155c,0x5c2aab82,
    0x428a22a9,0x4144a002,0x2aa02601,0x2188442a,0x30a28312,0x28061450,
    0x131418a0,0x04451426,0x4dc45115,0x8a6aa0ca,0x0d47263d,0xbb981773,
    0xabb88100,0x46e3931b,0x750c88c8,0x32232237,0x2b206b20,0x125564c1,
    0x55645559,0x5c555933,0x00003913,0x00000000,0x00000000,0x00000000,
    0x00000000,0x0350d402,0x20b894c2,0x41103839,0x42044000,0x80424408,
    0x20888820,0x81044088,0x00210820,0x8e60aa2a,0x1905440c,0x0446060a,
    0x40605c55,0x2251399a,0x2a6a0d43,0xb8e63221,0x535912a9,0x30644644,
    0x2eae1357,0x8d10d42b,0x26a6262a,0x25503510,0x85718182,0x501829aa,
    0x988a2855,0x2b828621,0x28514288,0x26307051,0x21333098,0x518dc42a,
    0x540aa135,0xc9818298,0x222aaa80,0x38842bba,0x88a2e28a,0x707510a1,
    0x0a621450,0x09898c14,0x215408c3,0x54413111,0x8182a941,0x2a9b8389,
    0x45539018,0x7550cbaa,0xb30d5543,0x2ab21b11,0x81911913,0x20aca82b,
    0x0029a99b,0x15c77015,0x890c98cc,0x644e2bba,0x00002000,0x00001c88,
    0x00000000,0x00000000,0x00000000,0x21400000,0x12c82bac,0x30555544,
    0x2aaa6003,0x0000002a,0x00000000,0x2a000000,0x257571ac,0x4466573d,
    0x22609999,0x0777712b,0x00000000,0x00000000,0x15c00000,0x01501313,
    0x00002222,0x00000000,0x00000000,0x30800000,0x00000000,0x00000000,
    0x00000000,0x00000000,0x00000000,0x00000000,
};

static signed short stb__courier_11_usascii_x[95]={ 0,2,1,0,1,0,1,2,2,1,0,0,1,0,
2,1,1,1,0,0,1,0,1,1,1,1,2,1,0,0,0,0,1,0,0,0,0,0,0,0,0,1,0,0,
0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,0,0,1,0,2,0,0,0,0,0,1,0,0,0,
0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,2,0,0, };
static signed short stb__courier_11_usascii_y[95]={ 8,1,2,1,1,1,2,2,2,2,2,2,6,4,
6,1,1,1,1,1,2,2,1,2,1,1,3,3,2,4,2,2,1,2,2,2,2,2,2,2,2,2,2,2,
2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,1,2,1,10,1,3,2,3,2,3,2,3,2,1,
1,2,2,3,3,3,3,3,3,3,2,3,3,3,3,3,3,2,2,2,4, };
static unsigned short stb__courier_11_usascii_w[95]={ 0,2,4,5,4,5,4,2,3,3,4,6,3,5,
2,4,4,4,5,5,4,5,4,4,4,4,2,3,5,6,5,4,4,6,6,6,6,6,6,6,6,4,6,6,
6,6,6,5,6,6,6,5,6,6,6,6,6,6,4,2,4,2,4,7,2,6,6,6,6,6,5,6,6,5,
4,6,5,6,6,6,6,6,6,5,6,6,6,6,6,6,4,2,2,2,5, };
static unsigned short stb__courier_11_usascii_h[95]={ 0,8,3,8,8,8,7,3,8,8,4,6,4,2,
3,8,8,7,7,8,6,7,8,7,8,8,6,7,6,3,6,7,8,6,6,7,6,6,6,7,6,6,7,6,
6,6,6,7,6,8,6,7,6,7,6,6,6,6,6,8,8,8,4,1,3,6,7,6,7,6,6,7,6,7,
9,6,6,5,5,6,7,7,5,6,7,6,5,6,5,7,5,8,8,8,2, };
static unsigned short stb__courier_11_usascii_s[95]={ 97,6,84,18,24,29,35,92,35,39,79,
47,124,111,89,48,43,40,45,66,67,51,72,57,77,61,123,124,14,98,1,
69,82,102,95,62,83,76,69,87,55,50,74,36,29,7,20,29,62,87,1,
81,8,94,108,115,101,15,90,94,53,58,119,117,95,109,22,116,8,22,122,
117,43,104,1,33,27,112,91,72,110,15,105,54,97,60,98,40,79,1,86,
15,12,9,105, };
static unsigned short stb__courier_11_usascii_t[95]={ 9,1,32,1,1,1,11,32,1,1,32,
26,26,32,32,1,1,11,11,1,26,11,1,11,1,1,19,1,26,32,26,
11,1,19,19,11,19,19,19,11,19,19,11,19,19,26,26,11,19,1,19,
11,19,11,11,11,11,19,19,1,1,1,26,32,32,19,11,19,11,19,11,
1,19,1,1,26,26,26,26,26,1,11,26,26,1,26,26,26,26,11,26,
1,1,1,32, };
static unsigned short stb__courier_11_usascii_a[95]={ 93,93,93,93,93,93,93,93,
93,93,93,93,93,93,93,93,93,93,93,93,93,93,93,93,
93,93,93,93,93,93,93,93,93,93,93,93,93,93,93,93,
93,93,93,93,93,93,93,93,93,93,93,93,93,93,93,93,
93,93,93,93,93,93,93,93,93,93,93,93,93,93,93,93,
93,93,93,93,93,93,93,93,93,93,93,93,93,93,93,93,
93,93,93,93,93,93,93, };

// Call this function with
//    font: NULL or array length
//    data: NULL or specified size
//    height: STB_FONT_courier_11_usascii_BITMAP_HEIGHT or STB_FONT_courier_11_usascii_BITMAP_HEIGHT_POW2
//    return value: spacing between lines
static void stb_font_courier_11_usascii(stb_fontchar font[STB_FONT_courier_11_usascii_NUM_CHARS],
                unsigned char data[STB_FONT_courier_11_usascii_BITMAP_HEIGHT][STB_FONT_courier_11_usascii_BITMAP_WIDTH],
                int height)
{
    int i,j;
    if (data != 0) {
        unsigned int *bits = stb__courier_11_usascii_pixels;
        unsigned int bitpack = *bits++, numbits = 32;
        for (i=0; i < STB_FONT_courier_11_usascii_BITMAP_WIDTH*height; ++i)
            data[0][i] = 0;  // zero entire bitmap
        for (j=1; j < STB_FONT_courier_11_usascii_BITMAP_HEIGHT-1; ++j) {
            for (i=1; i < STB_FONT_courier_11_usascii_BITMAP_WIDTH-1; ++i) {
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
        float recip_width = 1.0f / STB_FONT_courier_11_usascii_BITMAP_WIDTH;
        float recip_height = 1.0f / height;
        for (i=0; i < STB_FONT_courier_11_usascii_NUM_CHARS; ++i) {
            // pad characters so they bilerp from empty space around each character
            font[i].s0 = (stb__courier_11_usascii_s[i]) * recip_width;
            font[i].t0 = (stb__courier_11_usascii_t[i]) * recip_height;
            font[i].s1 = (stb__courier_11_usascii_s[i] + stb__courier_11_usascii_w[i]) * recip_width;
            font[i].t1 = (stb__courier_11_usascii_t[i] + stb__courier_11_usascii_h[i]) * recip_height;
            font[i].x0 = stb__courier_11_usascii_x[i];
            font[i].y0 = stb__courier_11_usascii_y[i];
            font[i].x1 = stb__courier_11_usascii_x[i] + stb__courier_11_usascii_w[i];
            font[i].y1 = stb__courier_11_usascii_y[i] + stb__courier_11_usascii_h[i];
            font[i].advance_int = (stb__courier_11_usascii_a[i]+8)>>4;
            font[i].s0f = (stb__courier_11_usascii_s[i] - 0.5f) * recip_width;
            font[i].t0f = (stb__courier_11_usascii_t[i] - 0.5f) * recip_height;
            font[i].s1f = (stb__courier_11_usascii_s[i] + stb__courier_11_usascii_w[i] + 0.5f) * recip_width;
            font[i].t1f = (stb__courier_11_usascii_t[i] + stb__courier_11_usascii_h[i] + 0.5f) * recip_height;
            font[i].x0f = stb__courier_11_usascii_x[i] - 0.5f;
            font[i].y0f = stb__courier_11_usascii_y[i] - 0.5f;
            font[i].x1f = stb__courier_11_usascii_x[i] + stb__courier_11_usascii_w[i] + 0.5f;
            font[i].y1f = stb__courier_11_usascii_y[i] + stb__courier_11_usascii_h[i] + 0.5f;
            font[i].advance = stb__courier_11_usascii_a[i]/16.0f;
        }
    }
}

#ifndef STB_SOMEFONT_CREATE
#define STB_SOMEFONT_CREATE              stb_font_courier_11_usascii
#define STB_SOMEFONT_BITMAP_WIDTH        STB_FONT_courier_11_usascii_BITMAP_WIDTH
#define STB_SOMEFONT_BITMAP_HEIGHT       STB_FONT_courier_11_usascii_BITMAP_HEIGHT
#define STB_SOMEFONT_BITMAP_HEIGHT_POW2  STB_FONT_courier_11_usascii_BITMAP_HEIGHT_POW2
#define STB_SOMEFONT_FIRST_CHAR          STB_FONT_courier_11_usascii_FIRST_CHAR
#define STB_SOMEFONT_NUM_CHARS           STB_FONT_courier_11_usascii_NUM_CHARS
#define STB_SOMEFONT_LINE_SPACING        STB_FONT_courier_11_usascii_LINE_SPACING
#endif
