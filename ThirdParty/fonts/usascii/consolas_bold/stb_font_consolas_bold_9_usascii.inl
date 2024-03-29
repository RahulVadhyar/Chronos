// Font generated by stb_font_inl_generator.c (4/1 bpp)
//
// Following instructions show how to use the only included font, whatever it is, in
// a generic way so you can replace it with any other font by changing the include.
// To use multiple fonts, replace STB_SOMEFONT_* below with STB_FONT_consolas_bold_9_usascii_*,
// and separately install each font. Note that the CREATE function call has a
// totally different name; it's just 'stb_font_consolas_bold_9_usascii'.
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

#define STB_FONT_consolas_bold_9_usascii_BITMAP_WIDTH         128
#define STB_FONT_consolas_bold_9_usascii_BITMAP_HEIGHT         38
#define STB_FONT_consolas_bold_9_usascii_BITMAP_HEIGHT_POW2    64

#define STB_FONT_consolas_bold_9_usascii_FIRST_CHAR            32
#define STB_FONT_consolas_bold_9_usascii_NUM_CHARS             95

#define STB_FONT_consolas_bold_9_usascii_LINE_SPACING           6

static unsigned int stb__consolas_bold_9_usascii_pixels[]={
    0x40aa8286,0x8c404c28,0x0260d4c1,0x10820106,0x20304401,0x088b6e08,
    0x10330088,0x050a2150,0xda8d73c7,0x0bd71f43,0x1cc8f6d5,0x14c87736,
    0xaadd89bd,0x4b609f93,0xb70e80f8,0x2212a5d3,0x260fc886,0x44794b85,
    0x23c3e60f,0x4d11dc0e,0x2aa21edb,0x951647a2,0xca9a6b31,0x22de6c59,
    0x4bae60f8,0x4b65a878,0xd855b54b,0xaacc1f01,0x221f1f11,0x0763c03b,
    0xdf52cc77,0x7735d441,0x6debd8b2,0x2077c479,0x3ee21da8,0x3c5d5d30,
    0x56a5b0ec,0x16a2ebfa,0x8b7b307c,0x03ea25dd,0xb87ea3c5,0xff985f33,
    0x32b534c1,0x6db2f7a2,0x50efb6e1,0xc836a399,0x1a63c5b3,0xbad4f297,
    0x307c0744,0x81f981fd,0x23c3e60f,0x4b31dc1e,0x34c3dc88,0xbde8b297,
    0x54f4795c,0x56ef621f,0x22ea6418,0x3f621642,0x70f2950d,0x6ecc1f09,
    0x00f82dc3,0x23b81d1e,0x037fee58,0x22c96cd3,0x4b51ccbe,0x2724eeea,
    0xf98b73ea,0x221f12ee,0x7cc6be06,0x3aa6885e,0x5d1b32ef,0xdfd50332,
    0xb8789e05,0x08370743,0x22c9aab7,0x002d812c,0x09700000,0x5900164c,
    0x20000000,0x85d90b67,0x86f5405a,0x644fae0c,0x0001c43e,0x00000000,
    0x00000000,0x00000058,0x00000000,0x00000000,0x00000000,0x00000000,
    0x00000000,0x00000000,0x00000000,0x0ddd41d4,0x98044262,0x857310bb,
    0x11edc2db,0x2eec47db,0x5ec8aa37,0xdd886e4c,0xec8b76a5,0x8e0eecc4,
    0x4c72573b,0xb50e6374,0x3e76617b,0x254b3a21,0xfa8f574c,0x5d3b72eb,
    0x444b636a,0x433d10f8,0x236a772c,0x3102ba21,0x54667aaf,0x267e63b5,
    0x4fc43e60,0x552e790f,0xadd983d6,0x598d3d30,0x27915e54,0x6d2e951d,
    0x3eab2972,0xbe896e64,0xf99dcb21,0x20af6e0c,0x21517978,0x0970ece8,
    0x2d51fe40,0x5c173a1e,0xd70decc3,0x3efea5df,0xa547a791,0x6d6a5b3c,
    0x3ae64ace,0x9647eea1,0x5c7f663b,0xdbc42ead,0xd9d13d9a,0x22441321,
    0x23cfc2fb,0x989701fa,0x51661def,0x777c4769,0xa5cbdf51,0x20f2b73c,
    0x2772e82d,0x2b32d83c,0x75bb4c3c,0xea9e52e7,0x5f11f880,0x3c26ec1f,
    0x4f23bf30,0x2951663c,0x0951d81d,0x3a21bfb1,0x997baa5e,0x3bba24fe,
    0x6c1bdf70,0x27fd30ee,0xbd33ffd8,0x317fe41d,0x726d321d,0x9800f05f,
    0x51660cdd,0x4c6e0769,0x20100003,0x00000000,0x01700040,0x00000000,
    0x00000000,0x00000000,0x00000000,0x86e60000,0x1eecd224,0x52a3bbb3,
    0x44b29529,0x44393985,0x1bbb30bb,0xddb954aa,0x21bbb13d,0xbb70ddd8,
    0xb31eecc5,0x5c1d987b,0x320dcc2b,0xd8f57440,0x3a76ab10,0x2e3f5312,
    0xd3f73a9f,0x2b2a1e27,0x982efa25,0x89dcee0f,0x33d108f9,0x3790cf44,
    0x47e76a5d,0x3b21e8ca,0x547a6a24,0x87aa1ebe,0xd1b3edeb,0x21e52ab1,
    0x4eb72e3d,0x0f13cdcc,0x02d41db5,0x43dbdb8f,0xf10cfc47,0x54b96455,
    0x2b6a1d3b,0xb71a7a0e,0x225cf23f,0x411b50f9,0xbd54bebd,0x2ae3541d,
    0x93f593ce,0x83faa1e2,0x7b71e069,0x67c4787b,0x2c8efe24,0xa8fbaa97,
    0x3eb32ebd,0xa6476b50,0xd88ba23c,0x9d5d91ee,0x81d1036a,0x31b3faab,
    0x32a1e293,0x2077e45b,0x3c3b9dc7,0x321a21a2,0xf1952e8a,0xdf73ca54,
    0x47b7e67f,0x0760dee8,0x953fb640,0x2e7fff70,0xa4c367f2,0x2952fff8,
    0x77f4c02e,0x8f0ee771,0x1fff8868,0xda547df9,0x361bdf53,0x00000b51,
    0x00000000,0x00000000,0x00000000,0x40000000,0x5c4883b9,0x2a1f6448,
    0xa8fb220d,0x12641ddd,0x5cd542a3,0x0a177710,0x988eaa25,0x8854382b,
    0x01066532,0x260d8871,0x27e61ccc,0x5d10f4c2,0x47a32e3d,0x26a20ed9,
    0x43f3310f,0x8ed2a6ea,0x9714cfcd,0x56223a1f,0x7f52dcf8,0xca5c783f,
    0x221d5f13,0x90fc42d9,0x44088897,0x307e62de,0x23325d7d,0x7c40742d,
    0x9a7a3540,0x3a363b4a,0xad8ba249,0x422d14af,0x3fb23b4a,0x41f1f13e,
    0x13f222fa,0x8ed261d3,0xf981eeea,0x9e983ae1,0x85dbb10e,0x2e83d80e,
    0xad43a72e,0x493d1b1e,0x9f6f5c3d,0x43b4a868,0x22eec0f8,0x377225ed,
    0x300002e0,0x5cb50dbd,0x07441ece,0xd309b03a,0xf14feec8,0x27a363dd,
    0x2a3fff34,0x50d12f8f,0xf30b0769,0x1c3eadc5,0x00200000,0xdf324ec4,
    0xa9fffcc5,0x40b62fff,0x00000068,0x00000000,0x00000000,0x00000000,
    0x86062000,0x3042a238,0x888af6c6,0x00000008,0x00000000,0x00000000,
    0x7ccf0f20,0x7c97d991,0xeeee8269,0x00000005,0x00000000,0x00000000,
    0x2e6303c0,0x0001a3a0,0x00000000,0x00000000,0x00000000,0x00000000,
    0x00000000,
};

static signed short stb__consolas_bold_9_usascii_x[95]={ 0,1,0,0,0,0,0,1,1,1,0,0,0,1,
1,0,0,0,0,0,0,0,0,0,0,0,1,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,1,0,0,0,0,0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,0, };
static signed short stb__consolas_bold_9_usascii_y[95]={ 6,-1,-1,0,-1,-1,-1,-1,-1,-1,-1,1,4,3,
4,-1,0,0,0,0,0,0,0,0,0,0,1,1,1,2,1,-1,-1,0,0,0,0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,-1,-1,-1,0,6,-1,1,-1,1,-1,1,-1,1,-1,-1,
-1,-1,-1,1,1,1,1,1,1,1,0,1,1,1,1,1,1,-1,-2,-1,2, };
static unsigned short stb__consolas_bold_9_usascii_w[95]={ 0,3,4,5,5,5,6,3,3,3,5,5,4,3,
3,5,5,5,5,5,5,5,5,5,5,5,3,4,5,5,5,4,5,5,5,5,5,5,5,5,5,5,4,5,
5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,3,5,3,5,5,4,5,5,5,5,5,5,5,5,5,
4,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,4,2,5,5, };
static unsigned short stb__consolas_bold_9_usascii_h[95]={ 0,8,3,6,9,8,8,3,9,9,5,5,4,2,
3,8,7,6,6,7,6,7,7,6,7,6,6,7,6,3,6,8,9,6,6,7,6,6,6,7,6,6,7,6,
6,6,6,7,6,8,6,7,6,7,6,6,6,6,6,9,8,9,4,2,3,6,8,6,8,6,7,7,7,7,
9,7,7,5,5,6,7,7,5,6,7,6,5,5,5,7,5,9,10,9,3, };
static unsigned short stb__consolas_bold_9_usascii_s[95]={ 124,72,74,13,19,55,48,60,44,30,103,
85,109,79,64,76,43,25,31,49,43,55,73,37,90,19,124,102,7,120,121,
61,38,103,97,96,85,79,73,84,61,55,79,43,37,31,25,37,13,82,91,
67,67,61,113,7,107,119,19,34,94,10,114,83,55,109,88,49,66,1,13,
7,19,118,25,106,100,55,79,115,31,25,73,1,1,49,91,67,97,112,61,
14,1,4,68, };
static unsigned short stb__consolas_bold_9_usascii_t[95]={ 8,1,33,27,1,1,1,33,1,1,27,
27,27,33,33,1,12,27,27,12,27,12,12,27,12,27,1,12,27,27,20,
1,1,20,20,12,20,20,20,12,20,20,12,20,20,20,20,12,20,1,20,
12,20,12,12,20,12,12,20,1,1,1,27,33,33,20,1,20,1,20,12,
12,12,1,1,1,1,27,27,20,12,12,27,27,12,27,27,27,27,1,27,
1,1,1,33, };
static unsigned short stb__consolas_bold_9_usascii_a[95]={ 79,79,79,79,79,79,79,79,
79,79,79,79,79,79,79,79,79,79,79,79,79,79,79,79,
79,79,79,79,79,79,79,79,79,79,79,79,79,79,79,79,
79,79,79,79,79,79,79,79,79,79,79,79,79,79,79,79,
79,79,79,79,79,79,79,79,79,79,79,79,79,79,79,79,
79,79,79,79,79,79,79,79,79,79,79,79,79,79,79,79,
79,79,79,79,79,79,79, };

// Call this function with
//    font: NULL or array length
//    data: NULL or specified size
//    height: STB_FONT_consolas_bold_9_usascii_BITMAP_HEIGHT or STB_FONT_consolas_bold_9_usascii_BITMAP_HEIGHT_POW2
//    return value: spacing between lines
static void stb_font_consolas_bold_9_usascii(stb_fontchar font[STB_FONT_consolas_bold_9_usascii_NUM_CHARS],
                unsigned char data[STB_FONT_consolas_bold_9_usascii_BITMAP_HEIGHT][STB_FONT_consolas_bold_9_usascii_BITMAP_WIDTH],
                int height)
{
    int i,j;
    if (data != 0) {
        unsigned int *bits = stb__consolas_bold_9_usascii_pixels;
        unsigned int bitpack = *bits++, numbits = 32;
        for (i=0; i < STB_FONT_consolas_bold_9_usascii_BITMAP_WIDTH*height; ++i)
            data[0][i] = 0;  // zero entire bitmap
        for (j=1; j < STB_FONT_consolas_bold_9_usascii_BITMAP_HEIGHT-1; ++j) {
            for (i=1; i < STB_FONT_consolas_bold_9_usascii_BITMAP_WIDTH-1; ++i) {
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
        float recip_width = 1.0f / STB_FONT_consolas_bold_9_usascii_BITMAP_WIDTH;
        float recip_height = 1.0f / height;
        for (i=0; i < STB_FONT_consolas_bold_9_usascii_NUM_CHARS; ++i) {
            // pad characters so they bilerp from empty space around each character
            font[i].s0 = (stb__consolas_bold_9_usascii_s[i]) * recip_width;
            font[i].t0 = (stb__consolas_bold_9_usascii_t[i]) * recip_height;
            font[i].s1 = (stb__consolas_bold_9_usascii_s[i] + stb__consolas_bold_9_usascii_w[i]) * recip_width;
            font[i].t1 = (stb__consolas_bold_9_usascii_t[i] + stb__consolas_bold_9_usascii_h[i]) * recip_height;
            font[i].x0 = stb__consolas_bold_9_usascii_x[i];
            font[i].y0 = stb__consolas_bold_9_usascii_y[i];
            font[i].x1 = stb__consolas_bold_9_usascii_x[i] + stb__consolas_bold_9_usascii_w[i];
            font[i].y1 = stb__consolas_bold_9_usascii_y[i] + stb__consolas_bold_9_usascii_h[i];
            font[i].advance_int = (stb__consolas_bold_9_usascii_a[i]+8)>>4;
            font[i].s0f = (stb__consolas_bold_9_usascii_s[i] - 0.5f) * recip_width;
            font[i].t0f = (stb__consolas_bold_9_usascii_t[i] - 0.5f) * recip_height;
            font[i].s1f = (stb__consolas_bold_9_usascii_s[i] + stb__consolas_bold_9_usascii_w[i] + 0.5f) * recip_width;
            font[i].t1f = (stb__consolas_bold_9_usascii_t[i] + stb__consolas_bold_9_usascii_h[i] + 0.5f) * recip_height;
            font[i].x0f = stb__consolas_bold_9_usascii_x[i] - 0.5f;
            font[i].y0f = stb__consolas_bold_9_usascii_y[i] - 0.5f;
            font[i].x1f = stb__consolas_bold_9_usascii_x[i] + stb__consolas_bold_9_usascii_w[i] + 0.5f;
            font[i].y1f = stb__consolas_bold_9_usascii_y[i] + stb__consolas_bold_9_usascii_h[i] + 0.5f;
            font[i].advance = stb__consolas_bold_9_usascii_a[i]/16.0f;
        }
    }
}

#ifndef STB_SOMEFONT_CREATE
#define STB_SOMEFONT_CREATE              stb_font_consolas_bold_9_usascii
#define STB_SOMEFONT_BITMAP_WIDTH        STB_FONT_consolas_bold_9_usascii_BITMAP_WIDTH
#define STB_SOMEFONT_BITMAP_HEIGHT       STB_FONT_consolas_bold_9_usascii_BITMAP_HEIGHT
#define STB_SOMEFONT_BITMAP_HEIGHT_POW2  STB_FONT_consolas_bold_9_usascii_BITMAP_HEIGHT_POW2
#define STB_SOMEFONT_FIRST_CHAR          STB_FONT_consolas_bold_9_usascii_FIRST_CHAR
#define STB_SOMEFONT_NUM_CHARS           STB_FONT_consolas_bold_9_usascii_NUM_CHARS
#define STB_SOMEFONT_LINE_SPACING        STB_FONT_consolas_bold_9_usascii_LINE_SPACING
#endif

