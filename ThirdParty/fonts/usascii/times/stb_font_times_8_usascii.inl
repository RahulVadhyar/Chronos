// Font generated by stb_font_inl_generator.c (4/1 bpp)
//
// Following instructions show how to use the only included font, whatever it is, in
// a generic way so you can replace it with any other font by changing the include.
// To use multiple fonts, replace STB_SOMEFONT_* below with STB_FONT_times_8_usascii_*,
// and separately install each font. Note that the CREATE function call has a
// totally different name; it's just 'stb_font_times_8_usascii'.
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

#define STB_FONT_times_8_usascii_BITMAP_WIDTH         128
#define STB_FONT_times_8_usascii_BITMAP_HEIGHT         30
#define STB_FONT_times_8_usascii_BITMAP_HEIGHT_POW2    32

#define STB_FONT_times_8_usascii_FIRST_CHAR            32
#define STB_FONT_times_8_usascii_NUM_CHARS             95

#define STB_FONT_times_8_usascii_LINE_SPACING           5

static unsigned int stb__times_8_usascii_pixels[]={
    0x00000000,0x00666000,0x113980aa,0x22044411,0x44000001,0x2219a800,
    0x4cc42263,0x0c302609,0x030c4086,0x253154c9,0x182a0e38,0x5c133538,
    0x547150ca,0x221b8171,0x0c8a8171,0x271298ea,0x31177338,0x24870666,
    0x220cc661,0x55c71060,0x22e58320,0x238182a0,0x48d4541c,0x208a8cc7,
    0x0c54220a,0x32244553,0x94662960,0x8a241192,0x9541c261,0x39122a08,
    0x26e488dc,0x2044150c,0x455506a3,0x4d4664ba,0x351a82a1,0x50e1dd49,
    0x73509223,0x83535151,0x48618444,0x87483298,0x82a6e0c8,0x8302a333,
    0x20150513,0x50654663,0x238a8cc5,0x4d41c312,0x1318ca0a,0x21c11537,
    0x81719863,0x0cba8329,0xa8770555,0x38302a2a,0x2a015015,0x0366e550,
    0x10c9b954,0x00024c35,0x47060c18,0x04c18661,0x00880200,0x005300c4,
    0x00000000,0x4cc00000,0x08104040,0x00001982,0x00000000,0x00000000,
    0x00000000,0x00000000,0x00000000,0x00000000,0x22550000,0x15433263,
    0x1a81a883,0x22b88a62,0x110cc298,0xa4554a66,0x751c7519,0x544970e2,
    0x50aaaa1a,0xb98e4353,0x846b2a1a,0x18ec4221,0x03137142,0x229c1337,
    0x54e2829a,0x25088510,0x8ac1ad24,0x0e218a61,0x41154237,0x4e24861a,
    0x45d22e25,0x46c44223,0x26266281,0x48e32a08,0x8ea16c35,0x09370b9b,
    0x067290c4,0x06298317,0x4324c893,0x12403238,0x8d644399,0xb111038a,
    0xa8981885,0x53879173,0x10e122a1,0x4331a9c9,0x441c9d40,0x70314c1c,
    0x22373a84,0x712406e3,0x2e61c437,0x4c66330c,0x3a88c142,0x2217b577,
    0x998a6629,0x1a882621,0x09382862,0x3054dc12,0x50ccd435,0x4cd44531,
    0x1ca54770,0x00000095,0x00000008,0x00000000,0x00000000,0x00000000,
    0x00000000,0x00000000,0x00000000,0x2498ea11,0x32aa2ab9,0x30e2950a,
    0x1d4e6498,0x5cc531b3,0x4c537329,0x0104c3ac,0x4c22220a,0x801804aa,
    0x41739839,0x25432252,0x83883271,0x10c9418c,0x54299c47,0x4e21c42a,
    0x8aa4ce20,0x1c889351,0x30dc0cd4,0x4c439413,0x15710711,0x4c5cc438,
    0x7116b224,0x35481910,0x2a9c88e2,0x11e440d8,0x2b1c4539,0x226070c8,
    0x81cc1c84,0x0d473329,0x20b620e2,0x24b211c9,0x03886e71,0x1c455309,
    0x9330a671,0x441c4388,0x4ca6a913,0x5c24d42c,0x70cc42c0,0x71099895,
    0xa8039710,0x32a59999,0x221260c9,0x2a49800e,0x3c94c774,0x4739312a,
    0x2000a9ca,0xbc80950b,0x42000239,0x6d2a3ad9,0x00000003,0x00000000,
    0x00000000,0x00000000,0x44000000,0x0b870118,0x00444571,0x44c44111,
    0x43310c21,0x4e11110a,0x2130a29a,0x43a83119,0x00000999,0x26a08000,
    0x85c39834,0xa884dc90,0xcab87221,0x88926e49,0x84cc4224,0x06223152,
    0x0006a220,0x20000000,0x2eae1aa9,0x8150e220,0x43c882a2,0x8e2a2a1c,
    0x3302438a,0x00118033,0x00000000,0x24e04000,0x20a836ee,0x41510dc2,
    0x37370d8a,0x5c326e19,0x0000002b,0x00000000,0x80010000,0x0ccb8dc3,
    0x00000000,0x00000000,0x00000000,0x00000000,0x00000000,0x00000000,
    0x00000000,0x00000000,
};

static signed short stb__times_8_usascii_x[95]={ 0,0,0,0,0,0,0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
0,0,-1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,-1,0,0,-1,0,0,0,0,0,0,0,
-1,0,0,0,0,0,-1,0,0,0,0,0,0,0,0,0,0,0,0,0,0, };
static signed short stb__times_8_usascii_y[95]={ 6,1,1,1,0,1,1,1,0,0,0,1,5,4,
5,0,1,1,1,1,1,1,1,1,1,1,2,2,1,2,1,1,0,1,1,1,1,1,1,1,1,1,1,1,
1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,0,1,1,7,1,2,0,2,0,2,0,2,0,0,
0,0,0,2,2,2,2,2,2,2,1,2,2,2,2,2,2,0,0,0,3, };
static unsigned short stb__times_8_usascii_w[95]={ 0,2,3,4,4,6,6,1,3,3,4,4,2,3,
2,3,4,3,4,4,4,4,4,4,4,4,2,2,4,4,4,3,7,6,5,5,5,5,4,6,6,3,3,6,
5,7,7,5,4,5,5,4,5,6,6,7,6,6,5,3,3,2,4,5,2,4,5,3,4,4,4,4,4,2,
3,4,2,6,4,4,5,4,3,3,3,4,4,6,4,4,4,3,1,3,4, };
static unsigned short stb__times_8_usascii_h[95]={ 0,6,3,6,7,6,6,3,8,8,4,5,3,1,
2,7,6,5,5,6,5,6,6,6,6,6,5,6,5,3,5,6,8,5,5,6,5,5,5,6,5,5,6,5,
5,5,6,6,5,7,5,6,5,6,6,6,5,5,5,7,7,7,3,1,2,5,7,5,7,5,6,6,6,6,
8,6,6,4,4,5,6,6,4,5,6,5,5,5,4,6,4,8,8,8,2, };
static unsigned short stb__times_8_usascii_s[95]={ 68,120,68,123,40,14,21,66,23,9,31,
1,58,88,77,31,28,18,22,38,13,82,48,9,33,43,125,53,91,61,81,
56,1,63,121,99,48,42,37,92,23,19,105,102,96,113,1,114,115,45,109,
87,1,75,68,60,30,7,75,57,61,65,72,92,80,86,51,109,35,58,109,
104,99,96,27,87,84,41,48,14,73,79,27,54,92,120,70,6,36,68,53,
19,17,13,83, };
static unsigned short stb__times_8_usascii_t[95]={ 8,1,23,1,1,10,10,23,1,1,23,
23,23,23,23,1,10,23,23,10,23,10,10,10,10,10,10,10,17,23,17,
10,1,17,16,10,17,17,17,10,17,17,10,17,17,16,10,1,10,1,10,
10,17,10,10,10,17,17,17,1,1,1,23,23,23,17,1,16,1,17,1,
1,1,1,1,1,1,23,23,17,1,1,23,17,1,10,17,23,23,1,23,
1,1,1,23, };
static unsigned short stb__times_8_usascii_a[95]={ 29,38,47,58,58,96,90,21,
38,38,58,65,29,38,29,32,58,58,58,58,58,58,58,58,
58,58,32,32,65,65,65,51,106,83,77,77,83,71,64,83,
83,38,45,83,71,103,83,83,64,83,77,64,71,83,83,109,
83,83,71,38,32,38,54,58,38,51,58,51,58,51,38,58,
58,32,32,58,32,90,58,58,58,58,38,45,32,58,58,83,
58,58,51,55,23,55,63, };

// Call this function with
//    font: NULL or array length
//    data: NULL or specified size
//    height: STB_FONT_times_8_usascii_BITMAP_HEIGHT or STB_FONT_times_8_usascii_BITMAP_HEIGHT_POW2
//    return value: spacing between lines
static void stb_font_times_8_usascii(stb_fontchar font[STB_FONT_times_8_usascii_NUM_CHARS],
                unsigned char data[STB_FONT_times_8_usascii_BITMAP_HEIGHT][STB_FONT_times_8_usascii_BITMAP_WIDTH],
                int height)
{
    int i,j;
    if (data != 0) {
        unsigned int *bits = stb__times_8_usascii_pixels;
        unsigned int bitpack = *bits++, numbits = 32;
        for (i=0; i < STB_FONT_times_8_usascii_BITMAP_WIDTH*height; ++i)
            data[0][i] = 0;  // zero entire bitmap
        for (j=1; j < STB_FONT_times_8_usascii_BITMAP_HEIGHT-1; ++j) {
            for (i=1; i < STB_FONT_times_8_usascii_BITMAP_WIDTH-1; ++i) {
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
        float recip_width = 1.0f / STB_FONT_times_8_usascii_BITMAP_WIDTH;
        float recip_height = 1.0f / height;
        for (i=0; i < STB_FONT_times_8_usascii_NUM_CHARS; ++i) {
            // pad characters so they bilerp from empty space around each character
            font[i].s0 = (stb__times_8_usascii_s[i]) * recip_width;
            font[i].t0 = (stb__times_8_usascii_t[i]) * recip_height;
            font[i].s1 = (stb__times_8_usascii_s[i] + stb__times_8_usascii_w[i]) * recip_width;
            font[i].t1 = (stb__times_8_usascii_t[i] + stb__times_8_usascii_h[i]) * recip_height;
            font[i].x0 = stb__times_8_usascii_x[i];
            font[i].y0 = stb__times_8_usascii_y[i];
            font[i].x1 = stb__times_8_usascii_x[i] + stb__times_8_usascii_w[i];
            font[i].y1 = stb__times_8_usascii_y[i] + stb__times_8_usascii_h[i];
            font[i].advance_int = (stb__times_8_usascii_a[i]+8)>>4;
            font[i].s0f = (stb__times_8_usascii_s[i] - 0.5f) * recip_width;
            font[i].t0f = (stb__times_8_usascii_t[i] - 0.5f) * recip_height;
            font[i].s1f = (stb__times_8_usascii_s[i] + stb__times_8_usascii_w[i] + 0.5f) * recip_width;
            font[i].t1f = (stb__times_8_usascii_t[i] + stb__times_8_usascii_h[i] + 0.5f) * recip_height;
            font[i].x0f = stb__times_8_usascii_x[i] - 0.5f;
            font[i].y0f = stb__times_8_usascii_y[i] - 0.5f;
            font[i].x1f = stb__times_8_usascii_x[i] + stb__times_8_usascii_w[i] + 0.5f;
            font[i].y1f = stb__times_8_usascii_y[i] + stb__times_8_usascii_h[i] + 0.5f;
            font[i].advance = stb__times_8_usascii_a[i]/16.0f;
        }
    }
}

#ifndef STB_SOMEFONT_CREATE
#define STB_SOMEFONT_CREATE              stb_font_times_8_usascii
#define STB_SOMEFONT_BITMAP_WIDTH        STB_FONT_times_8_usascii_BITMAP_WIDTH
#define STB_SOMEFONT_BITMAP_HEIGHT       STB_FONT_times_8_usascii_BITMAP_HEIGHT
#define STB_SOMEFONT_BITMAP_HEIGHT_POW2  STB_FONT_times_8_usascii_BITMAP_HEIGHT_POW2
#define STB_SOMEFONT_FIRST_CHAR          STB_FONT_times_8_usascii_FIRST_CHAR
#define STB_SOMEFONT_NUM_CHARS           STB_FONT_times_8_usascii_NUM_CHARS
#define STB_SOMEFONT_LINE_SPACING        STB_FONT_times_8_usascii_LINE_SPACING
#endif

