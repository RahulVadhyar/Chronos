// Font generated by stb_font_inl_generator.c (4/1 bpp)
//
// Following instructions show how to use the only included font, whatever it is, in
// a generic way so you can replace it with any other font by changing the include.
// To use multiple fonts, replace STB_SOMEFONT_* below with STB_FONT_arial_9_usascii_*,
// and separately install each font. Note that the CREATE function call has a
// totally different name; it's just 'stb_font_arial_9_usascii'.
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

#define STB_FONT_arial_9_usascii_BITMAP_WIDTH         128
#define STB_FONT_arial_9_usascii_BITMAP_HEIGHT         34
#define STB_FONT_arial_9_usascii_BITMAP_HEIGHT_POW2    64

#define STB_FONT_arial_9_usascii_FIRST_CHAR            32
#define STB_FONT_arial_9_usascii_NUM_CHARS             95

#define STB_FONT_arial_9_usascii_LINE_SPACING           6

static unsigned int stb__arial_9_usascii_pixels[]={
    0x21986e04,0x9854971b,0x20ccca81,0x20884c4a,0x42cc8820,0x38311088,
    0x4ae238a8,0x2e065c09,0x21664c1c,0x1e64c1ca,0x0b722222,0x258914c9,
    0x2226e240,0x238370c8,0x1b24323a,0xaad64cae,0x3910e4ad,0x21d22a1b,
    0x2594cb19,0x394c3248,0x79339922,0x2485537d,0x0dcb1229,0x332ae217,
    0x14c3738d,0xa955cc97,0x2ab0cac2,0x7b50d491,0x06aee61b,0x4779115c,
    0x4397701b,0x2761902a,0x2531b83d,0x54372c2b,0x9d22b152,0x42986e1b,
    0x2eb06e4d,0x8e2c6ab0,0x9b8439c8,0x5752cc0b,0xb2c80dc9,0x174cb8dc,
    0x4322ec5a,0x2e585529,0xaac5c6e1,0x154370ab,0x9264b853,0x2ad9913a,
    0xb971c3cd,0x2748a817,0x2485cb09,0x58546e39,0x2f22b126,0x3245a8ae,
    0x21b96245,0xb997530e,0x44b30dc5,0x376e05c5,0x1c06ab04,0x55ce0917,
    0x64479912,0x11e65c3b,0xdcda8799,0x37676131,0x12299223,0x645885cb,
    0x20dcae22,0x4000ea05,0x10000132,0x00000004,0x14197100,0x46a1886e,
    0x404c712b,0x1260bcc9,0x00000013,0x00000000,0x00000000,0x00000000,
    0x00000000,0x00000000,0x32000000,0x81664c4c,0x054336e3,0x2a072a08,
    0x197072e0,0x198170cc,0x09822062,0x205c3841,0x89e6e5c0,0x4799931d,
    0x07109809,0x888ae191,0x45ce2734,0x212b0c41,0x2352caa3,0x540c8aa5,
    0x6ccb5952,0xac2e113b,0x3bc8961b,0x4551d458,0x5dc3350d,0x2e1ccaac,
    0x16bc9ac2,0x25e5c17b,0x5c701d70,0x2a585cb0,0x54550322,0x1a84326b,
    0x29a45617,0x71616eee,0x9666ea19,0x25b55aca,0xb10dcb08,0x4f2a2c32,
    0x3326091b,0x90c8662a,0x4552e644,0x8ac9540c,0x71a942e5,0x5c194963,
    0x14c58189,0x8d41d795,0x21395135,0xc9dd5264,0x37586eb0,0x3a172992,
    0x896350e2,0x9cb1cc90,0x44b7952a,0x366352cc,0x9112aa5b,0x2298b079,
    0x58d4b32a,0x57915993,0xb12eddb8,0x4b7362b7,0x44622ccb,0x910e5ccc,
    0x21664459,0x372a3dcc,0x801a8000,0x262c001e,0x352b8aa2,0x00600016,
    0x00000000,0x00000000,0x00000000,0x00000000,0x00000000,0xccd98000,
    0x4cf732a1,0x40c80ccd,0x2cc8920b,0x1b8e38a6,0x3366a233,0x51cc081c,
    0x0ccb1261,0x026488cc,0x30a85c33,0x3366599b,0x4162553c,0x3126350d,
    0x45558877,0x1c8d8b1a,0x30ba642e,0x7912c557,0x50b8f547,0x81a9aa1d,
    0x46a0d89a,0x0b864550,0x55055053,0xba8b20dc,0x42c641ca,0x889104bb,
    0xa54d4c3e,0x2c4aae64,0x75aa9217,0x5264eea1,0xa81d5503,0xb55951c9,
    0x1564c2e1,0x8aa35595,0x5750ea2b,0x81dae877,0x7b10b00e,0x49171790,
    0x20bcdab9,0x5ccd4b0b,0x92e9350b,0x43bda81a,0x266ea2ea,0x2b26170d,
    0x546ab2a2,0x5424c362,0x499ba961,0x2360a058,0x2c9a641c,0x6440aae6,
    0x86e46a3c,0x2a49bb9a,0x54391a81,0x70c8aa5a,0x20aa0a61,0x3762ddda,
    0x5b9b53cc,0x20b0322c,0x4588dc38,0xab983e3b,0xe88d4002,0xa92d1350,
    0x22350ccd,0x2a93350d,0x2985c322,0x004ccda8,0x00000000,0x00000000,
    0x00000000,0x00000000,0x00000000,0x072e0000,0x52986a12,0x44154999,
    0x41082108,0x998841c0,0x10108410,0x04462217,0x4411106e,0x5c2e530a,
    0x46ea5329,0x2aa610a8,0x6c46c8b1,0xa8910e61,0xcacb2e3c,0x4521938a,
    0x54ca21d9,0x2a57753c,0x439915ac,0x645adbca,0x4c3332a4,0x5c32312e,
    0xa84cc62a,0x11600dca,0x0e61ac8b,0x2e1b701b,0x46b322e1,0x7d731aa9,
    0x49912201,0x50b6ab1a,0xb9a85d63,0x22155511,0x00420818,0x580d8800,
    0x22886a2e,0x2e0e5448,0xb132f220,0x42c40909,0x2a2c6a5d,0x85d6350c,
    0x05554420,0x10000000,0xdcb9601b,0x000b8625,0x44a8e817,0xbb29804b,
    0x55266e79,0x2b1a80b1,0xbb88000b,0x000001bb,0x42c266e4,0x0058a61a,
    0x00000000,0x00000000,0x00000000,0x00000000,0x00000000,0x00000000,
    0x00000000,0x00000000,0x00000000,0x00000000,0x00000000,
};

static signed short stb__arial_9_usascii_x[95]={ 0,0,0,0,0,0,0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,-1,0,0,0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,-1,0,0,0,0,0,0,0,0,0,0,
-1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0, };
static signed short stb__arial_9_usascii_y[95]={ 7,1,1,1,0,1,1,1,1,1,1,2,6,4,
6,1,1,1,1,1,1,1,1,1,1,1,2,2,2,2,2,1,1,1,1,1,1,1,1,1,1,1,1,1,
1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,8,1,2,1,2,1,2,1,2,1,1,
1,1,1,2,2,2,2,2,2,2,1,2,2,2,2,2,2,1,1,1,3, };
static unsigned short stb__arial_9_usascii_w[95]={ 0,2,3,5,5,7,6,2,3,3,3,5,2,3,
2,3,5,4,5,5,5,5,5,5,5,5,2,2,5,5,5,5,8,7,5,6,6,5,5,6,6,2,4,6,
5,7,6,6,6,6,6,5,5,6,6,8,6,6,5,3,3,2,4,6,2,5,5,4,4,5,3,4,4,2,
3,4,2,7,4,5,5,4,3,4,3,4,4,6,4,4,4,3,2,3,5, };
static unsigned short stb__arial_9_usascii_h[95]={ 0,6,3,7,8,7,7,3,8,8,3,5,3,2,
1,7,7,6,6,7,6,7,7,6,7,7,5,7,5,4,5,6,8,6,6,7,6,6,6,7,6,6,7,6,
6,6,6,7,6,7,6,7,6,7,6,6,6,6,6,8,7,8,4,1,2,6,7,6,7,6,6,7,6,6,
8,6,6,5,5,6,7,7,5,6,7,6,5,5,5,7,5,8,8,8,2, };
static unsigned short stb__arial_9_usascii_s[95]={ 46,18,108,77,1,83,34,105,42,25,98,
49,102,115,125,41,45,7,1,91,12,1,110,21,97,51,55,31,73,92,27,
103,29,88,82,103,69,63,57,116,47,125,64,35,29,21,14,55,1,7,111,
19,101,57,88,116,109,96,76,38,73,18,87,98,112,69,25,75,14,95,107,
123,118,80,21,42,54,79,68,8,67,62,33,123,46,83,44,37,63,50,58,
14,11,7,119, };
static unsigned short stb__arial_9_usascii_t[95]={ 9,25,25,1,1,1,10,25,1,1,25,
25,25,25,25,10,10,25,25,1,25,10,1,25,1,10,25,10,25,25,25,
17,1,17,17,1,17,18,18,1,18,17,10,18,18,18,18,1,18,10,10,
10,10,10,10,17,17,17,17,1,1,1,25,29,25,10,10,10,10,10,10,
1,10,10,1,18,18,25,25,18,1,1,25,10,1,10,25,25,25,1,25,
1,1,1,25, };
static unsigned short stb__arial_9_usascii_a[95]={ 36,36,46,72,72,115,86,25,
43,43,50,75,36,43,36,36,72,72,72,72,72,72,72,72,
72,72,36,36,75,75,75,72,131,86,86,93,93,86,79,100,
93,36,64,86,72,107,93,100,86,100,93,86,79,93,86,122,
86,86,79,36,36,36,60,72,43,72,72,64,72,72,36,72,
72,29,29,64,29,107,72,72,72,72,43,64,36,72,64,93,
64,64,64,43,33,43,75, };

// Call this function with
//    font: NULL or array length
//    data: NULL or specified size
//    height: STB_FONT_arial_9_usascii_BITMAP_HEIGHT or STB_FONT_arial_9_usascii_BITMAP_HEIGHT_POW2
//    return value: spacing between lines
static void stb_font_arial_9_usascii(stb_fontchar font[STB_FONT_arial_9_usascii_NUM_CHARS],
                unsigned char data[STB_FONT_arial_9_usascii_BITMAP_HEIGHT][STB_FONT_arial_9_usascii_BITMAP_WIDTH],
                int height)
{
    int i,j;
    if (data != 0) {
        unsigned int *bits = stb__arial_9_usascii_pixels;
        unsigned int bitpack = *bits++, numbits = 32;
        for (i=0; i < STB_FONT_arial_9_usascii_BITMAP_WIDTH*height; ++i)
            data[0][i] = 0;  // zero entire bitmap
        for (j=1; j < STB_FONT_arial_9_usascii_BITMAP_HEIGHT-1; ++j) {
            for (i=1; i < STB_FONT_arial_9_usascii_BITMAP_WIDTH-1; ++i) {
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
        float recip_width = 1.0f / STB_FONT_arial_9_usascii_BITMAP_WIDTH;
        float recip_height = 1.0f / height;
        for (i=0; i < STB_FONT_arial_9_usascii_NUM_CHARS; ++i) {
            // pad characters so they bilerp from empty space around each character
            font[i].s0 = (stb__arial_9_usascii_s[i]) * recip_width;
            font[i].t0 = (stb__arial_9_usascii_t[i]) * recip_height;
            font[i].s1 = (stb__arial_9_usascii_s[i] + stb__arial_9_usascii_w[i]) * recip_width;
            font[i].t1 = (stb__arial_9_usascii_t[i] + stb__arial_9_usascii_h[i]) * recip_height;
            font[i].x0 = stb__arial_9_usascii_x[i];
            font[i].y0 = stb__arial_9_usascii_y[i];
            font[i].x1 = stb__arial_9_usascii_x[i] + stb__arial_9_usascii_w[i];
            font[i].y1 = stb__arial_9_usascii_y[i] + stb__arial_9_usascii_h[i];
            font[i].advance_int = (stb__arial_9_usascii_a[i]+8)>>4;
            font[i].s0f = (stb__arial_9_usascii_s[i] - 0.5f) * recip_width;
            font[i].t0f = (stb__arial_9_usascii_t[i] - 0.5f) * recip_height;
            font[i].s1f = (stb__arial_9_usascii_s[i] + stb__arial_9_usascii_w[i] + 0.5f) * recip_width;
            font[i].t1f = (stb__arial_9_usascii_t[i] + stb__arial_9_usascii_h[i] + 0.5f) * recip_height;
            font[i].x0f = stb__arial_9_usascii_x[i] - 0.5f;
            font[i].y0f = stb__arial_9_usascii_y[i] - 0.5f;
            font[i].x1f = stb__arial_9_usascii_x[i] + stb__arial_9_usascii_w[i] + 0.5f;
            font[i].y1f = stb__arial_9_usascii_y[i] + stb__arial_9_usascii_h[i] + 0.5f;
            font[i].advance = stb__arial_9_usascii_a[i]/16.0f;
        }
    }
}

#ifndef STB_SOMEFONT_CREATE
#define STB_SOMEFONT_CREATE              stb_font_arial_9_usascii
#define STB_SOMEFONT_BITMAP_WIDTH        STB_FONT_arial_9_usascii_BITMAP_WIDTH
#define STB_SOMEFONT_BITMAP_HEIGHT       STB_FONT_arial_9_usascii_BITMAP_HEIGHT
#define STB_SOMEFONT_BITMAP_HEIGHT_POW2  STB_FONT_arial_9_usascii_BITMAP_HEIGHT_POW2
#define STB_SOMEFONT_FIRST_CHAR          STB_FONT_arial_9_usascii_FIRST_CHAR
#define STB_SOMEFONT_NUM_CHARS           STB_FONT_arial_9_usascii_NUM_CHARS
#define STB_SOMEFONT_LINE_SPACING        STB_FONT_arial_9_usascii_LINE_SPACING
#endif

