// Font generated by stb_font_inl_generator.c (4/1 bpp)
//
// Following instructions show how to use the only included font, whatever it is, in
// a generic way so you can replace it with any other font by changing the include.
// To use multiple fonts, replace STB_SOMEFONT_* below with STB_FONT_times_7_usascii_*,
// and separately install each font. Note that the CREATE function call has a
// totally different name; it's just 'stb_font_times_7_usascii'.
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

#define STB_FONT_times_7_usascii_BITMAP_WIDTH         128
#define STB_FONT_times_7_usascii_BITMAP_HEIGHT         26
#define STB_FONT_times_7_usascii_BITMAP_HEIGHT_POW2    32

#define STB_FONT_times_7_usascii_FIRST_CHAR            32
#define STB_FONT_times_7_usascii_NUM_CHARS             95

#define STB_FONT_times_7_usascii_LINE_SPACING           5

static unsigned int stb__times_7_usascii_pixels[]={
    0x22020080,0x11088100,0x2104c040,0x81102098,0x86040221,0x40980408,
    0x10220409,0x82210418,0x10c02862,0x2851ca21,0x90e2a211,0x253a994c,
    0x719a8662,0x33983065,0x1394c1b8,0x2528a8a7,0x28a8e0c2,0x28628515,
    0x11531854,0x22850b92,0x44905c93,0x550c9941,0x115524c7,0x20d54c18,
    0x49090aac,0x064c6609,0x73922611,0x30c10e26,0x27133098,0x2142e190,
    0x20b85ce2,0x9ccc3044,0x261d429a,0x8ee3043a,0x92121c8a,0x21962044,
    0x71339c73,0x84c28628,0x7109b999,0x128a1453,0x11154535,0x02631514,
    0x42b8c555,0x757242a1,0x4426a239,0x53514489,0x4cc9550c,0x31411352,
    0x06183114,0x08942872,0x08000000,0x00000000,0x00000000,0x04404402,
    0x0098c410,0x00000000,0x00000000,0x00000000,0x00000000,0x00000000,
    0x00000000,0x20600000,0x84420440,0x44221108,0x22041088,0x8c422110,
    0x22399821,0x13103099,0xab818818,0x10447332,0x31110221,0x1c133104,
    0x505446a6,0x0c6a294c,0x29465335,0x114e6131,0x314d40a9,0x2a60e335,
    0x32aa0e0b,0x4c739ce0,0x55429963,0x5c4c3209,0x30a8a6e0,0x34866e19,
    0x64e41854,0x5c399d21,0x42a24c0a,0x370541ba,0x1705dcc5,0x170654c3,
    0x8b98eaa5,0x19306649,0x1ce1cc38,0xa8e72871,0x320c6a0a,0x44e621b9,
    0x20c98381,0x0a851509,0xb89531ce,0x381c14c3,0x19926e26,0x486a25cc,
    0x211319a8,0x48333099,0x2660cdc4,0x4298a219,0x86c4d448,0x4570311a,
    0x8e6aa48b,0x060aa39b,0x4367150c,0xb35519ba,0x00535901,0x00000000,
    0x00000000,0x00000000,0x00000000,0x00000000,0x00000000,0x00000000,
    0x42200000,0x86621109,0x01310998,0x21304c41,0x1000418b,0x21308806,
    0x31708b8b,0x98810554,0x31ce5331,0x5410ccc5,0x94c1041a,0x844d4a64,
    0x935308a9,0x20a6a648,0x88ea61a8,0x42662a84,0x39530099,0x23530544,
    0x213709a8,0x4731ce93,0x88b0dcc3,0x249b98e2,0x5cc57319,0x470dc662,
    0x1c132ab9,0x9882e628,0x21988662,0x870a2e09,0x175062ab,0x52554a6a,
    0x5cc2ea15,0x118c7151,0x4c6648cc,0x19826609,0x91331c17,0x20c0c422,
    0x052ee2aa,0x20000020,0x00000000,0x54b2a800,0x19ba8553,0x2a485375,
    0xbb8183ab,0x05106c72,0x00000000,0x00000000,0x00000000,0xb8000000,
    0x2e151ab9,0x72a98221,0x26618053,0x33154109,0x00000003,0x00000000,
    0x29ce0000,0x41570e11,0x13331ce3,0x02213330,0x00000000,0x00000000,
    0x645c0000,0x8220b838,0x0091919b,0x00000000,0x00000000,0x00000000,
    0x00000000,0x00000000,0x00000000,
};

static signed short stb__times_7_usascii_x[95]={ 0,0,0,0,0,0,0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
0,0,-1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,-1,0,0,-1,0,0,0,0,0,0,0,
-1,0,0,0,0,0,-1,0,0,0,0,0,0,0,0,0,0,0,0,0,0, };
static signed short stb__times_7_usascii_y[95]={ 5,0,0,0,0,0,0,0,0,0,0,1,4,3,
4,0,0,0,0,0,0,0,0,0,0,0,2,2,1,2,1,0,0,0,0,0,0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,6,0,2,0,2,0,2,0,2,0,0,
0,0,0,2,2,2,2,2,2,2,1,2,2,2,2,2,2,0,0,0,2, };
static unsigned short stb__times_7_usascii_w[95]={ 0,2,3,4,3,6,5,1,2,2,3,4,2,2,
2,2,3,3,3,3,3,3,3,3,3,3,2,2,4,4,4,3,6,5,4,4,5,4,4,5,5,2,3,5,
4,6,6,5,4,5,5,4,4,5,5,6,5,5,4,2,2,2,3,5,2,3,4,3,4,3,3,4,4,2,
3,4,2,5,4,3,4,4,3,3,2,4,4,5,4,4,3,3,1,3,4, };
static unsigned short stb__times_7_usascii_h[95]={ 0,6,3,6,6,6,6,3,7,7,4,4,3,1,
2,6,6,5,5,6,5,6,6,6,6,6,4,5,4,2,4,6,7,5,5,6,5,5,5,6,5,5,6,5,
5,5,6,6,5,7,5,6,5,6,6,6,5,5,5,7,6,7,3,1,2,4,6,4,6,4,5,5,5,5,
7,5,5,3,3,4,5,5,3,4,5,4,4,4,3,5,3,7,7,7,2, };
static unsigned short stb__times_7_usascii_s[95]={ 125,50,70,61,66,70,87,124,1,37,111,
85,63,99,88,113,121,26,43,6,53,10,14,53,57,37,67,35,62,91,57,
104,18,47,30,93,20,15,10,98,1,7,46,113,108,101,80,40,86,25,75,
108,65,24,18,30,51,45,122,31,77,34,120,102,96,81,1,107,116,90,41,
60,70,57,14,81,125,57,78,94,91,96,66,103,119,98,76,70,115,38,74,
10,8,4,83, };
static unsigned short stb__times_7_usascii_t[95]={ 7,1,21,1,1,1,1,16,1,1,16,
16,21,21,21,1,1,16,16,9,16,9,9,1,1,9,16,16,16,21,16,
1,1,16,16,1,16,16,16,1,16,16,1,9,9,9,1,1,9,1,9,
1,9,9,9,9,9,9,9,1,1,1,16,21,21,16,9,16,1,16,9,
9,9,9,1,9,1,21,21,16,9,9,21,16,9,16,16,16,16,16,21,
1,1,1,21, };
static unsigned short stb__times_7_usascii_a[95]={ 25,34,41,51,51,84,79,18,
34,34,51,57,25,34,25,28,51,51,51,51,51,51,51,51,
51,51,28,28,57,57,57,45,93,73,67,67,73,62,56,73,
73,34,39,73,62,90,73,73,56,73,67,56,62,73,73,95,
73,73,62,34,28,34,47,51,34,45,51,45,51,45,34,51,
51,28,28,51,28,79,51,51,51,51,34,39,28,51,51,73,
51,51,45,49,20,49,55, };

// Call this function with
//    font: NULL or array length
//    data: NULL or specified size
//    height: STB_FONT_times_7_usascii_BITMAP_HEIGHT or STB_FONT_times_7_usascii_BITMAP_HEIGHT_POW2
//    return value: spacing between lines
static void stb_font_times_7_usascii(stb_fontchar font[STB_FONT_times_7_usascii_NUM_CHARS],
                unsigned char data[STB_FONT_times_7_usascii_BITMAP_HEIGHT][STB_FONT_times_7_usascii_BITMAP_WIDTH],
                int height)
{
    int i,j;
    if (data != 0) {
        unsigned int *bits = stb__times_7_usascii_pixels;
        unsigned int bitpack = *bits++, numbits = 32;
        for (i=0; i < STB_FONT_times_7_usascii_BITMAP_WIDTH*height; ++i)
            data[0][i] = 0;  // zero entire bitmap
        for (j=1; j < STB_FONT_times_7_usascii_BITMAP_HEIGHT-1; ++j) {
            for (i=1; i < STB_FONT_times_7_usascii_BITMAP_WIDTH-1; ++i) {
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
        float recip_width = 1.0f / STB_FONT_times_7_usascii_BITMAP_WIDTH;
        float recip_height = 1.0f / height;
        for (i=0; i < STB_FONT_times_7_usascii_NUM_CHARS; ++i) {
            // pad characters so they bilerp from empty space around each character
            font[i].s0 = (stb__times_7_usascii_s[i]) * recip_width;
            font[i].t0 = (stb__times_7_usascii_t[i]) * recip_height;
            font[i].s1 = (stb__times_7_usascii_s[i] + stb__times_7_usascii_w[i]) * recip_width;
            font[i].t1 = (stb__times_7_usascii_t[i] + stb__times_7_usascii_h[i]) * recip_height;
            font[i].x0 = stb__times_7_usascii_x[i];
            font[i].y0 = stb__times_7_usascii_y[i];
            font[i].x1 = stb__times_7_usascii_x[i] + stb__times_7_usascii_w[i];
            font[i].y1 = stb__times_7_usascii_y[i] + stb__times_7_usascii_h[i];
            font[i].advance_int = (stb__times_7_usascii_a[i]+8)>>4;
            font[i].s0f = (stb__times_7_usascii_s[i] - 0.5f) * recip_width;
            font[i].t0f = (stb__times_7_usascii_t[i] - 0.5f) * recip_height;
            font[i].s1f = (stb__times_7_usascii_s[i] + stb__times_7_usascii_w[i] + 0.5f) * recip_width;
            font[i].t1f = (stb__times_7_usascii_t[i] + stb__times_7_usascii_h[i] + 0.5f) * recip_height;
            font[i].x0f = stb__times_7_usascii_x[i] - 0.5f;
            font[i].y0f = stb__times_7_usascii_y[i] - 0.5f;
            font[i].x1f = stb__times_7_usascii_x[i] + stb__times_7_usascii_w[i] + 0.5f;
            font[i].y1f = stb__times_7_usascii_y[i] + stb__times_7_usascii_h[i] + 0.5f;
            font[i].advance = stb__times_7_usascii_a[i]/16.0f;
        }
    }
}

#ifndef STB_SOMEFONT_CREATE
#define STB_SOMEFONT_CREATE              stb_font_times_7_usascii
#define STB_SOMEFONT_BITMAP_WIDTH        STB_FONT_times_7_usascii_BITMAP_WIDTH
#define STB_SOMEFONT_BITMAP_HEIGHT       STB_FONT_times_7_usascii_BITMAP_HEIGHT
#define STB_SOMEFONT_BITMAP_HEIGHT_POW2  STB_FONT_times_7_usascii_BITMAP_HEIGHT_POW2
#define STB_SOMEFONT_FIRST_CHAR          STB_FONT_times_7_usascii_FIRST_CHAR
#define STB_SOMEFONT_NUM_CHARS           STB_FONT_times_7_usascii_NUM_CHARS
#define STB_SOMEFONT_LINE_SPACING        STB_FONT_times_7_usascii_LINE_SPACING
#endif

