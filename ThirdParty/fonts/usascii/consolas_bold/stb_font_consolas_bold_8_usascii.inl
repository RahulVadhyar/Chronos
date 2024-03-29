// Font generated by stb_font_inl_generator.c (4/1 bpp)
//
// Following instructions show how to use the only included font, whatever it is, in
// a generic way so you can replace it with any other font by changing the include.
// To use multiple fonts, replace STB_SOMEFONT_* below with STB_FONT_consolas_bold_8_usascii_*,
// and separately install each font. Note that the CREATE function call has a
// totally different name; it's just 'stb_font_consolas_bold_8_usascii'.
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

#define STB_FONT_consolas_bold_8_usascii_BITMAP_WIDTH         128
#define STB_FONT_consolas_bold_8_usascii_BITMAP_HEIGHT         34
#define STB_FONT_consolas_bold_8_usascii_BITMAP_HEIGHT_POW2    64

#define STB_FONT_consolas_bold_8_usascii_FIRST_CHAR            32
#define STB_FONT_consolas_bold_8_usascii_NUM_CHARS             95

#define STB_FONT_consolas_bold_8_usascii_LINE_SPACING           5

static unsigned int stb__consolas_bold_8_usascii_pixels[]={
    0x0c88d431,0x930d42b8,0x90cb8103,0x10200389,0x48080005,0x037099cc,
    0x44415411,0x88800330,0x498d3498,0xd88d4254,0x47dd30d8,0x321dc586,
    0x598fba61,0x3b6adbb1,0xdd31eec4,0xb524dec7,0x65577a27,0x44fbe62c,
    0x10edd885,0x0b2937d9,0x7754751a,0x363b9593,0x342c34d1,0x34769df9,
    0x4ab4b293,0x3320654f,0x2a066544,0x0dd98774,0xa8390326,0x49ba849b,
    0x3a67b01d,0x99bb3b81,0x868ec7a5,0xd8721c85,0x565261b0,0xec9e7568,
    0x30ff625d,0x2c86dc37,0xd911df54,0x336a24c9,0x1d49ba80,0x20b221d0,
    0x2399bb3b,0x161a1d2c,0x4b21c876,0x37a6310e,0x9d47bd56,0x3763d546,
    0x225c130c,0x46986d8e,0x20f7aa0d,0xb05949bb,0x9b3b83a8,0xd1f74c99,
    0x4ea8d0b0,0x22cc7db3,0xbb107568,0x191f75c9,0xd88f21b9,0x21dbd75e,
    0x91d42ed9,0x476ccf15,0x2d41d149,0x96cc4366,0x5f4408ac,0x3234c3d0,
    0x99c00003,0x00024001,0x12c01000,0x324c0399,0x4aa02e21,0x4065c3c9,
    0x321970a9,0x00000144,0x00000000,0x10000000,0x00000005,0x00000000,
    0x00000000,0x00000000,0x00000000,0x00000000,0x00000000,0x00000000,
    0x0cc104e0,0x1010a010,0x00880881,0x41012e00,0x8208ae20,0x11c40888,
    0x80883301,0xd116a019,0x30753472,0xd33a879d,0x99f64c9b,0x4dbd14ce,
    0x7bb13dd8,0x53b60e54,0xb2cc69bb,0x276dc763,0x23eeb8a2,0x52775c3a,
    0xdd88c407,0xeea9a396,0x43a036e4,0x54a8799c,0x2e0b2b39,0x4dae67ad,
    0x3a12a2cd,0x2772c42d,0x97a624c6,0x3baa59ab,0xbba9e774,0x5a591884,
    0x27a54d1c,0xd9263fc8,0x4bb20edc,0xf93b2fe8,0xacb8ce5c,0x25459b36,
    0xb32c43e4,0x58849895,0x8ca87fae,0x6d4b9b76,0x22b2d305,0xf3a9a596,
    0x990e4d10,0x45dda21a,0xde89a596,0x15cdbd54,0x3ce8a76c,0x30b7a2c4,
    0x655cb109,0x1cbb4ea3,0xa5407654,0x7bd36de9,0xdd71ef54,0x7bd11627,
    0xde99f6d4,0x010ddd14,0x15900570,0xc97f661f,0x7ecc4987,0x9d4d1575,
    0xb5750776,0x00000030,0x00040055,0x00000000,0x00000000,0x00000000,
    0x00000000,0x00000000,0x00000000,0x44108800,0x08440810,0x20802222,
    0x44111000,0x04101108,0x3b022011,0x8081043a,0x20080088,0xae408408,
    0x589e7325,0xdb52d5dc,0x8e4b7a2d,0xe98fba26,0x329bd33d,0x71b9a3ed,
    0x4c7c87bd,0x074b259c,0x11f6cc5b,0x5a9b663d,0x246c7bd5,0xcdc967b2,
    0x1d971625,0xc8ba65b0,0x33cb268a,0x78e44989,0x55c32a36,0x3a167459,
    0x20efa22c,0x1e99263d,0x59189a22,0x90777dda,0x2ede4bb7,0xa84eb8b1,
    0xeecae4c5,0xdf334b27,0x8e4fbe67,0x219d5b0e,0x2b264eeb,0x076435c4,
    0x224987a2,0x5422683d,0x90ab67de,0x64c6cdb3,0x1ebb8b10,0x3dd983a2,
    0x3ee99a39,0x9c893126,0x43737678,0x3775cf2b,0xb0930591,0x42c84981,
    0x32b316a6,0x3d4e45ee,0x5ef8864b,0x77e4d377,0x40347206,0xca77cc49,
    0x9e7321ee,0x6c363deb,0x01260571,0xea813faa,0x30dea86f,0x00000177,
    0x00000000,0x00000000,0x00000000,0x44408000,0x9d400408,0x40800006,
    0x232e1d1d,0x8621b9a6,0x457faa18,0x89440199,0x219b8623,0x011111bb,
    0xdd517cc0,0x6ecfba6f,0xdab4ea6d,0x98bdd34e,0x4e4c5b84,0x95b0f6c5,
    0xdc9b5419,0x5dcc7a23,0x26175d72,0x5d35c6a4,0xccc84cc5,0x057b001c,
    0x93b59897,0x55a2ea19,0xa8eb368c,0x0eb223ec,0x21ed859d,0x8a546ddc,
    0xda8b62ed,0x1893254d,0x00011500,0xe82aba80,0xcc8d96c0,0x4eadbd30,
    0x3b710936,0x23dc284c,0x2bae69cb,0x542e20c6,0x000004ef,0xdb000000,
    0x322541dd,0x80332363,0x4c126d3a,0x00000003,0x00000000,0x5c000000,
    0xddf70742,0x00000000,0x00000000,0x00000000,0x00000000,0x00000000,
    0x00000000,0x00000000,0x00000000,
};

static signed short stb__consolas_bold_8_usascii_x[95]={ 0,1,0,0,0,0,0,1,1,0,0,0,0,0,
1,0,0,0,0,0,0,0,0,0,0,0,1,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,1,0,0,0,0,0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,0, };
static signed short stb__consolas_bold_8_usascii_y[95]={ 5,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,0,3,2,
3,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,0,0,0,1,0,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,
-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,5,-1,0,-1,0,-1,0,-1,0,-1,-1,
-1,-1,-1,0,0,0,0,0,0,0,-1,1,1,1,1,1,1,-1,-2,-1,1, };
static unsigned short stb__consolas_bold_8_usascii_w[95]={ 0,2,4,5,5,5,5,2,3,4,4,5,3,4,
2,4,5,4,4,4,5,4,5,4,4,4,2,3,4,4,4,3,5,5,5,4,5,4,4,5,5,4,4,5,
4,5,5,5,5,5,5,4,5,5,5,5,5,5,4,3,5,3,5,5,3,4,5,4,4,4,5,5,4,4,
4,5,4,5,4,5,5,4,5,4,4,4,5,5,5,5,4,4,2,4,5, };
static unsigned short stb__consolas_bold_8_usascii_h[95]={ 0,7,3,6,7,7,7,3,8,8,4,5,4,2,
3,7,7,6,6,7,6,7,7,6,7,6,6,7,6,4,6,7,8,6,6,7,6,6,6,7,6,6,7,6,
6,6,6,7,6,8,6,7,6,7,6,6,6,6,6,8,7,8,4,2,3,6,7,6,7,6,6,7,6,6,
8,6,6,5,5,6,7,7,5,6,7,5,4,4,4,6,4,8,9,8,3, };
static unsigned short stb__consolas_bold_8_usascii_s[95]={ 48,59,104,120,79,85,100,94,4,43,73,
39,69,109,101,27,32,107,12,38,1,106,73,7,43,115,112,1,102,83,92,
91,23,74,68,95,56,51,46,48,34,97,123,18,13,7,1,53,114,29,103,
22,92,10,86,62,75,86,24,35,111,39,45,114,97,59,16,70,5,54,64,
117,109,98,18,120,81,17,28,40,67,62,33,29,48,23,51,63,57,80,78,
13,1,8,88, };
static unsigned short stb__consolas_bold_8_usascii_t[95]={ 9,1,26,19,1,1,1,26,1,1,26,
26,26,26,26,11,11,19,26,11,26,1,1,26,11,19,19,11,19,26,19,
1,1,19,19,1,19,19,19,11,19,19,1,19,19,19,19,1,11,1,11,
11,11,11,11,19,11,19,19,1,1,1,26,26,26,11,11,11,11,11,11,
1,11,11,1,11,11,26,26,19,1,1,26,19,1,26,26,26,26,19,26,
1,1,1,26, };
static unsigned short stb__consolas_bold_8_usascii_a[95]={ 70,70,70,70,70,70,70,70,
70,70,70,70,70,70,70,70,70,70,70,70,70,70,70,70,
70,70,70,70,70,70,70,70,70,70,70,70,70,70,70,70,
70,70,70,70,70,70,70,70,70,70,70,70,70,70,70,70,
70,70,70,70,70,70,70,70,70,70,70,70,70,70,70,70,
70,70,70,70,70,70,70,70,70,70,70,70,70,70,70,70,
70,70,70,70,70,70,70, };

// Call this function with
//    font: NULL or array length
//    data: NULL or specified size
//    height: STB_FONT_consolas_bold_8_usascii_BITMAP_HEIGHT or STB_FONT_consolas_bold_8_usascii_BITMAP_HEIGHT_POW2
//    return value: spacing between lines
static void stb_font_consolas_bold_8_usascii(stb_fontchar font[STB_FONT_consolas_bold_8_usascii_NUM_CHARS],
                unsigned char data[STB_FONT_consolas_bold_8_usascii_BITMAP_HEIGHT][STB_FONT_consolas_bold_8_usascii_BITMAP_WIDTH],
                int height)
{
    int i,j;
    if (data != 0) {
        unsigned int *bits = stb__consolas_bold_8_usascii_pixels;
        unsigned int bitpack = *bits++, numbits = 32;
        for (i=0; i < STB_FONT_consolas_bold_8_usascii_BITMAP_WIDTH*height; ++i)
            data[0][i] = 0;  // zero entire bitmap
        for (j=1; j < STB_FONT_consolas_bold_8_usascii_BITMAP_HEIGHT-1; ++j) {
            for (i=1; i < STB_FONT_consolas_bold_8_usascii_BITMAP_WIDTH-1; ++i) {
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
        float recip_width = 1.0f / STB_FONT_consolas_bold_8_usascii_BITMAP_WIDTH;
        float recip_height = 1.0f / height;
        for (i=0; i < STB_FONT_consolas_bold_8_usascii_NUM_CHARS; ++i) {
            // pad characters so they bilerp from empty space around each character
            font[i].s0 = (stb__consolas_bold_8_usascii_s[i]) * recip_width;
            font[i].t0 = (stb__consolas_bold_8_usascii_t[i]) * recip_height;
            font[i].s1 = (stb__consolas_bold_8_usascii_s[i] + stb__consolas_bold_8_usascii_w[i]) * recip_width;
            font[i].t1 = (stb__consolas_bold_8_usascii_t[i] + stb__consolas_bold_8_usascii_h[i]) * recip_height;
            font[i].x0 = stb__consolas_bold_8_usascii_x[i];
            font[i].y0 = stb__consolas_bold_8_usascii_y[i];
            font[i].x1 = stb__consolas_bold_8_usascii_x[i] + stb__consolas_bold_8_usascii_w[i];
            font[i].y1 = stb__consolas_bold_8_usascii_y[i] + stb__consolas_bold_8_usascii_h[i];
            font[i].advance_int = (stb__consolas_bold_8_usascii_a[i]+8)>>4;
            font[i].s0f = (stb__consolas_bold_8_usascii_s[i] - 0.5f) * recip_width;
            font[i].t0f = (stb__consolas_bold_8_usascii_t[i] - 0.5f) * recip_height;
            font[i].s1f = (stb__consolas_bold_8_usascii_s[i] + stb__consolas_bold_8_usascii_w[i] + 0.5f) * recip_width;
            font[i].t1f = (stb__consolas_bold_8_usascii_t[i] + stb__consolas_bold_8_usascii_h[i] + 0.5f) * recip_height;
            font[i].x0f = stb__consolas_bold_8_usascii_x[i] - 0.5f;
            font[i].y0f = stb__consolas_bold_8_usascii_y[i] - 0.5f;
            font[i].x1f = stb__consolas_bold_8_usascii_x[i] + stb__consolas_bold_8_usascii_w[i] + 0.5f;
            font[i].y1f = stb__consolas_bold_8_usascii_y[i] + stb__consolas_bold_8_usascii_h[i] + 0.5f;
            font[i].advance = stb__consolas_bold_8_usascii_a[i]/16.0f;
        }
    }
}

#ifndef STB_SOMEFONT_CREATE
#define STB_SOMEFONT_CREATE              stb_font_consolas_bold_8_usascii
#define STB_SOMEFONT_BITMAP_WIDTH        STB_FONT_consolas_bold_8_usascii_BITMAP_WIDTH
#define STB_SOMEFONT_BITMAP_HEIGHT       STB_FONT_consolas_bold_8_usascii_BITMAP_HEIGHT
#define STB_SOMEFONT_BITMAP_HEIGHT_POW2  STB_FONT_consolas_bold_8_usascii_BITMAP_HEIGHT_POW2
#define STB_SOMEFONT_FIRST_CHAR          STB_FONT_consolas_bold_8_usascii_FIRST_CHAR
#define STB_SOMEFONT_NUM_CHARS           STB_FONT_consolas_bold_8_usascii_NUM_CHARS
#define STB_SOMEFONT_LINE_SPACING        STB_FONT_consolas_bold_8_usascii_LINE_SPACING
#endif

