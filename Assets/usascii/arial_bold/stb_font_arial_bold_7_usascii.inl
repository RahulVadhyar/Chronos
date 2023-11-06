// Font generated by stb_font_inl_generator.c (4/1 bpp)
//
// Following instructions show how to use the only included font, whatever it is, in
// a generic way so you can replace it with any other font by changing the include.
// To use multiple fonts, replace STB_SOMEFONT_* below with STB_FONT_arial_bold_7_usascii_*,
// and separately install each font. Note that the CREATE function call has a
// totally different name; it's just 'stb_font_arial_bold_7_usascii'.
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

#define STB_FONT_arial_bold_7_usascii_BITMAP_WIDTH         128
#define STB_FONT_arial_bold_7_usascii_BITMAP_HEIGHT         28
#define STB_FONT_arial_bold_7_usascii_BITMAP_HEIGHT_POW2    32

#define STB_FONT_arial_bold_7_usascii_FIRST_CHAR            32
#define STB_FONT_arial_bold_7_usascii_NUM_CHARS             95

#define STB_FONT_arial_bold_7_usascii_LINE_SPACING           5

static unsigned int stb__arial_bold_7_usascii_pixels[]={
    0x541305ca,0x43514260,0x19cc1ba8,0x02ea0411,0x8844c135,0x0e442208,
    0x85510651,0x502e20b9,0x1044c198,0x4c0ab817,0x0a8ea731,0x2350a8b1,
    0x5933914a,0x90d8c95c,0xa86d6d47,0x25b950dd,0x2e331dcb,0x5122f23c,
    0x52cecc59,0x8eea48b5,0xd5b32dcb,0xb98aaee1,0x0a922372,0x2911b893,
    0x97993748,0x325c98dc,0xcb9d4724,0x2e57390d,0x22e983aa,0x36e09ab9,
    0x225c0725,0x4e49990b,0x4cea392b,0x25b971de,0xd8543a0c,0x522b0dc2,
    0x2e3ab8bb,0x2e2b8ba1,0x47b76572,0x1bb72ed9,0x206dccaa,0x43210cbc,
    0x20d8472b,0x26193729,0x773572dd,0x5c65662a,0x0a922372,0x2711b891,
    0x17b95748,0x2d4698dc,0x14e49bb1,0x8c41b954,0x65cd44ea,0x6ec49b50,
    0x4ce136a4,0x4476ea5d,0x7db32fec,0xb9c4b766,0x887442a3,0x452e151d,
    0x4ee3b9ac,0x88000009,0x08180110,0x00000002,0x80018066,0x884c0831,
    0x0c409861,0x000000c4,0x00000000,0x00000000,0x00000000,0x7302a200,
    0x20260983,0x104c0c08,0x4c6eea17,0x130ddcc0,0x44442ee6,0x3298a330,
    0x2e130265,0x404c5098,0x40aa281a,0x25ac82a2,0xd750d9d9,0x49950cdc,
    0x4772a5bb,0x5c2f264b,0xa9a6ee1a,0x26eb5770,0x6b96d72b,0x9570aebb,
    0x13734ae7,0x9d342d5c,0x4b753883,0x51390eac,0x4cb9b2a3,0x0ccd8232,
    0x71327539,0xdb8ee5c5,0x665c6e5c,0x36e57375,0x576b2e5b,0x57375c2b,
    0xd31dcb9a,0x217a2d0b,0x221b191a,0x4f22ee6a,0x47d70ecb,0x9972a5d9,
    0x2b8550dd,0x65dcaa6e,0x50e5c6e3,0x9b66e5bb,0x8575beab,0x9a573bcb,
    0x1b393a9b,0x46d9cb4a,0x3da96724,0x3700f6ec,0x5500001b,0x4aa6e2b8,
    0x5c6e1d2b,0x2799b802,0xbd759f9b,0x74c74ae7,0x54376e4d,0x6d536e5d,
    0x4d9920ed,0x00000000,0x00000000,0x00000000,0x00000000,0x00000000,
    0x00000000,0x00000000,0x40000000,0x0ddcc70a,0x146650a2,0x8a8a2855,
    0x0d442628,0x98cc5066,0x318570aa,0x0446318c,0x304c3773,0x773098a1,
    0x5ccaee63,0x71d6540b,0x20ec8d37,0x5549dd8d,0x3344e457,0xab8dc59b,
    0x25c8ba65,0xea8d533a,0x7cecbb51,0x441b1949,0x5c7792e9,0x9bb8dcd2,
    0x2ee33770,0x75c6d86a,0x571d744d,0x20d857bb,0x23643ac9,0x2a89a21b,
    0x55154b73,0x45f05ed4,0xb931dcda,0x72e4c970,0xdb8dcfbd,0x2e7bd70c,
    0x5c3a81b2,0xddf50e8a,0x5075df4c,0x7441bd05,0x06c46e0e,0x98fef4aa,
    0xd5903161,0x3d1e3e21,0x72e5c5a8,0xab8dcd15,0x3a570ae0,0x37ae1d40,
    0x3f0e4365,0x5c82a8f3,0x2372cd64,0x88aa0eec,0x00058aa5,0x07bdd000,
    0x5c6e695c,0xeba6f5c2,0x0000003d,0x00000000,0x00000000,0x00000000,
    0x00000000,0x00000000,0x00000000,0x330c4c44,0x44150443,0x4446e208,
    0x0c370541,0x4c2a1333,0x2f6e1319,0x2e155501,0x00000001,0xd9900000,
    0x9976a1d7,0x32e3bd51,0x6e5c3b71,0xb7099361,0x8646eea1,0x544424ac,
    0x04cccb90,0x00000000,0x64e40000,0x440b10c9,0x64c370ac,0x2a55370d,
    0x321980ca,0x008411ee,0x00000000,0x00000000,0x3a191939,0x5c08aa5e,
    0x55370881,0x00000000,0x00000000,0x00000000,0x00000000,0x00000000,
    0x00000000,0x00000000,
};

static signed short stb__arial_bold_7_usascii_x[95]={ 0,0,0,0,0,0,0,0,0,0,0,0,0,0,
0,-1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,0,0,-1,0,0,-1,0,0,-1,0,0,-1,0,0,0,0,0,0,0,0,0,0,
-1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0, };
static signed short stb__arial_bold_7_usascii_y[95]={ 5,0,0,0,0,0,0,0,0,0,0,1,4,2,
4,0,0,0,0,0,0,0,0,0,0,0,1,1,1,1,1,0,0,0,0,0,0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,5,0,1,0,1,0,1,0,1,0,0,
0,0,0,1,1,1,1,1,1,1,0,1,1,1,1,1,1,0,0,0,2, };
static unsigned short stb__arial_bold_7_usascii_w[95]={ 0,2,3,4,4,6,5,2,2,2,3,4,2,2,
2,3,4,3,4,4,4,4,4,4,4,4,2,2,4,4,4,4,7,5,5,5,5,4,4,5,5,2,3,5,
4,5,5,5,4,5,5,4,4,5,6,6,5,6,4,2,3,2,4,5,2,4,4,4,4,4,3,4,4,2,
3,4,2,6,4,4,4,4,3,4,3,4,4,5,4,4,4,3,2,3,4, };
static unsigned short stb__arial_bold_7_usascii_h[95]={ 0,5,3,6,6,6,6,3,7,7,3,4,3,2,
1,6,6,5,5,6,5,6,6,5,6,6,4,6,4,3,4,5,7,5,5,6,5,5,5,6,5,5,6,5,
5,5,5,6,5,6,5,6,5,6,5,5,5,5,5,7,6,7,3,2,2,5,6,5,6,5,5,6,5,5,
7,5,5,4,4,5,6,6,4,5,6,5,4,4,4,6,4,7,7,7,2, };
static unsigned short stb__arial_bold_7_usascii_s[95]={ 127,97,55,51,69,74,21,52,1,19,43,
16,40,67,76,27,31,88,83,92,92,81,101,100,12,36,13,66,25,47,105,
62,25,49,43,86,30,25,20,41,11,80,17,122,117,111,105,45,95,111,86,
117,76,1,67,55,74,36,1,33,97,22,35,70,59,47,7,57,122,62,72,
106,81,92,15,52,17,1,30,67,61,56,21,6,41,100,121,115,110,36,8,
11,8,4,62, };
static unsigned short stb__arial_bold_7_usascii_t[95]={ 1,15,22,1,1,1,9,22,1,1,22,
22,22,22,22,9,9,15,15,1,15,1,1,15,9,8,22,1,22,22,15,
15,1,15,15,1,16,16,16,8,16,15,9,8,8,8,8,1,8,1,8,
1,8,9,15,15,15,15,16,1,1,1,22,22,22,8,9,8,1,8,8,
1,8,8,1,8,16,22,22,8,1,1,22,16,1,8,15,15,15,1,22,
1,1,1,22, };
static unsigned short stb__arial_bold_7_usascii_a[95]={ 28,33,48,56,56,89,72,24,
33,33,39,59,28,33,28,28,56,56,56,56,56,56,56,56,
56,56,33,33,59,59,59,61,98,72,72,72,72,67,61,78,
72,28,56,72,61,84,72,78,67,78,72,67,61,72,67,95,
67,67,61,33,28,33,59,56,33,56,61,56,61,56,33,61,
61,28,28,56,28,89,61,61,61,61,39,56,33,61,56,78,
56,56,50,39,28,39,59, };

// Call this function with
//    font: NULL or array length
//    data: NULL or specified size
//    height: STB_FONT_arial_bold_7_usascii_BITMAP_HEIGHT or STB_FONT_arial_bold_7_usascii_BITMAP_HEIGHT_POW2
//    return value: spacing between lines
static void stb_font_arial_bold_7_usascii(stb_fontchar font[STB_FONT_arial_bold_7_usascii_NUM_CHARS],
                unsigned char data[STB_FONT_arial_bold_7_usascii_BITMAP_HEIGHT][STB_FONT_arial_bold_7_usascii_BITMAP_WIDTH],
                int height)
{
    int i,j;
    if (data != 0) {
        unsigned int *bits = stb__arial_bold_7_usascii_pixels;
        unsigned int bitpack = *bits++, numbits = 32;
        for (i=0; i < STB_FONT_arial_bold_7_usascii_BITMAP_WIDTH*height; ++i)
            data[0][i] = 0;  // zero entire bitmap
        for (j=1; j < STB_FONT_arial_bold_7_usascii_BITMAP_HEIGHT-1; ++j) {
            for (i=1; i < STB_FONT_arial_bold_7_usascii_BITMAP_WIDTH-1; ++i) {
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
        float recip_width = 1.0f / STB_FONT_arial_bold_7_usascii_BITMAP_WIDTH;
        float recip_height = 1.0f / height;
        for (i=0; i < STB_FONT_arial_bold_7_usascii_NUM_CHARS; ++i) {
            // pad characters so they bilerp from empty space around each character
            font[i].s0 = (stb__arial_bold_7_usascii_s[i]) * recip_width;
            font[i].t0 = (stb__arial_bold_7_usascii_t[i]) * recip_height;
            font[i].s1 = (stb__arial_bold_7_usascii_s[i] + stb__arial_bold_7_usascii_w[i]) * recip_width;
            font[i].t1 = (stb__arial_bold_7_usascii_t[i] + stb__arial_bold_7_usascii_h[i]) * recip_height;
            font[i].x0 = stb__arial_bold_7_usascii_x[i];
            font[i].y0 = stb__arial_bold_7_usascii_y[i];
            font[i].x1 = stb__arial_bold_7_usascii_x[i] + stb__arial_bold_7_usascii_w[i];
            font[i].y1 = stb__arial_bold_7_usascii_y[i] + stb__arial_bold_7_usascii_h[i];
            font[i].advance_int = (stb__arial_bold_7_usascii_a[i]+8)>>4;
            font[i].s0f = (stb__arial_bold_7_usascii_s[i] - 0.5f) * recip_width;
            font[i].t0f = (stb__arial_bold_7_usascii_t[i] - 0.5f) * recip_height;
            font[i].s1f = (stb__arial_bold_7_usascii_s[i] + stb__arial_bold_7_usascii_w[i] + 0.5f) * recip_width;
            font[i].t1f = (stb__arial_bold_7_usascii_t[i] + stb__arial_bold_7_usascii_h[i] + 0.5f) * recip_height;
            font[i].x0f = stb__arial_bold_7_usascii_x[i] - 0.5f;
            font[i].y0f = stb__arial_bold_7_usascii_y[i] - 0.5f;
            font[i].x1f = stb__arial_bold_7_usascii_x[i] + stb__arial_bold_7_usascii_w[i] + 0.5f;
            font[i].y1f = stb__arial_bold_7_usascii_y[i] + stb__arial_bold_7_usascii_h[i] + 0.5f;
            font[i].advance = stb__arial_bold_7_usascii_a[i]/16.0f;
        }
    }
}

#ifndef STB_SOMEFONT_CREATE
#define STB_SOMEFONT_CREATE              stb_font_arial_bold_7_usascii
#define STB_SOMEFONT_BITMAP_WIDTH        STB_FONT_arial_bold_7_usascii_BITMAP_WIDTH
#define STB_SOMEFONT_BITMAP_HEIGHT       STB_FONT_arial_bold_7_usascii_BITMAP_HEIGHT
#define STB_SOMEFONT_BITMAP_HEIGHT_POW2  STB_FONT_arial_bold_7_usascii_BITMAP_HEIGHT_POW2
#define STB_SOMEFONT_FIRST_CHAR          STB_FONT_arial_bold_7_usascii_FIRST_CHAR
#define STB_SOMEFONT_NUM_CHARS           STB_FONT_arial_bold_7_usascii_NUM_CHARS
#define STB_SOMEFONT_LINE_SPACING        STB_FONT_arial_bold_7_usascii_LINE_SPACING
#endif

