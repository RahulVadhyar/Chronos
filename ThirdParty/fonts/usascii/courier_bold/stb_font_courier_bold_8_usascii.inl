// Font generated by stb_font_inl_generator.c (4/1 bpp)
//
// Following instructions show how to use the only included font, whatever it is, in
// a generic way so you can replace it with any other font by changing the include.
// To use multiple fonts, replace STB_SOMEFONT_* below with STB_FONT_courier_bold_8_usascii_*,
// and separately install each font. Note that the CREATE function call has a
// totally different name; it's just 'stb_font_courier_bold_8_usascii'.
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

#define STB_FONT_courier_bold_8_usascii_BITMAP_WIDTH         128
#define STB_FONT_courier_bold_8_usascii_BITMAP_HEIGHT         30
#define STB_FONT_courier_bold_8_usascii_BITMAP_HEIGHT_POW2    32

#define STB_FONT_courier_bold_8_usascii_FIRST_CHAR            32
#define STB_FONT_courier_bold_8_usascii_NUM_CHARS             95

#define STB_FONT_courier_bold_8_usascii_LINE_SPACING           4

static unsigned int stb__courier_bold_8_usascii_pixels[]={
    0x05041422,0x020dc185,0x20422171,0x88310200,0x04404440,0x4c3982ae,
    0x02604c42,0x44414c55,0x3202ee20,0x489c4550,0x27516144,0xc9262cd9,
    0x3046c69b,0xd9a5479b,0x8f3b60ec,0x47362cd9,0x33512cd8,0x5e4daf26,
    0x458eb266,0x27226dca,0x44732d20,0x0ee44733,0x9249c437,0x986f6229,
    0x2a4922ce,0x25516193,0xee89dc45,0x64d43362,0x88248492,0x3486e2de,
    0x2c0ef449,0x82b9c4b1,0x9388aa1a,0x85b8532c,0x11892485,0x2dea8bbb,
    0x25df5144,0x59553989,0x43b2b032,0xb32c3ab9,0x59cd209b,0x071388a6,
    0x27106435,0x88a62dd9,0x225cb82c,0xb10622dd,0xd85102b8,0x5c437664,
    0x2699b308,0x0b7625cd,0x931d4c37,0x371a863b,0x64c589c4,0x6f479160,
    0x0dd43664,0x05d40000,0x21540077,0x0001d428,0x00571440,0x06e20000,
    0x00100110,0x00000000,0x00000000,0x00000000,0x26000000,0x11111d43,
    0x41cc1988,0x104c0440,0x99881037,0x81311541,0x9809880a,0x98377309,
    0x802e0c42,0x4e202a2a,0x75512ac8,0xb931aaf2,0x64ceb221,0x9839913c,
    0xb9b11d40,0x57736e6c,0x155166e4,0x3664ce98,0x9877533d,0x9c92f625,
    0x53309d80,0x3246a190,0x4c2c2e5d,0x6e56f222,0x445bb34d,0x2371cc2d,
    0x744aa6a0,0x98ef262c,0x12cec2ce,0x326190b3,0xb82b665d,0x877a23ce,
    0xaa9221cc,0x91ba4438,0x9e4c299c,0xbb973cc9,0xb11cc298,0x42429899,
    0x24a61dc9,0x851b06fa,0x2a225925,0x2b12cae4,0x0dc37514,0x96e4c336,
    0x372e1cd8,0x00037220,0x774cfba6,0xd31ed803,0x86c6e45b,0x0fea6acc,
    0x31c4bbd7,0x336e1db9,0x990f3b62,0x00b154c7,0x00000000,0x00000000,
    0x00000000,0x03300000,0x00000000,0x00000000,0x00000000,0x00000000,
    0x00000000,0x00000000,0x88400000,0x04c41040,0x40330422,0x10822220,
    0x310ccc41,0x11026213,0x809804c4,0x04221888,0x80008440,0xcda44308,
    0x87cdf469,0x2e6e42ea,0x66c41173,0x564b5973,0x436faa4b,0x5b995bdc,
    0x66e4f366,0x5742f4c3,0x4b5970e9,0x2d65c0cb,0x56c534b8,0x36e150e9,
    0x2366e459,0x6444d985,0x4cb6e22e,0x224a64bc,0x433260dd,0x9ac32b1a,
    0x40cd84cc,0x42ec5dbc,0x542e43d9,0x0e6e602d,0x2b22ecdc,0x2e63ac5c,
    0xb50fe20c,0x892ae679,0x261ec6dd,0x4d6351bb,0x8b5733dd,0x675c3dea,
    0x1ecc1cc5,0x45b30376,0xd8066c29,0x7cd7459c,0x6e4dbf70,0x0b9770e8,
    0xa806adc8,0xcb6f643e,0x37b201de,0x507cdf44,0x21ed8959,0x356640cb,
    0x012a04a8,0x00000000,0x00000000,0x00000000,0x20000000,0x5506a099,
    0x4281b500,0x44108820,0x44410810,0x00088880,0x0c411102,0xc8844226,
    0x44a61318,0x5511cccc,0x11dc8803,0x31555477,0x07d40c85,0x3321d57b,
    0x499d50ea,0x33ae4de9,0x972f6742,0x99664c99,0xc83763ed,0x3226730b,
    0x04444061,0x73003551,0x731c8388,0xd9376239,0xb137aa0c,0x8586d837,
    0x5b8c8929,0x1db1776e,0x451331dc,0x00000c19,0x710e6000,0x872e62c8,
    0x45dd54ed,0x22dc2be8,0x37ea6bdc,0x5d1a7321,0x433003bb,0x00004df9,
    0x4c000000,0x25db32ee,0x00a62deb,0x00000ba2,0x00000000,0x00000000,
    0x00000000,0x00000000,0x00000000,0x00000000,0x00000000,0x00000000,
    0x00000000,0x00000000,0x00000000,
};

static signed short stb__courier_bold_8_usascii_x[95]={ 0,1,0,0,0,0,0,1,1,0,0,0,1,0,
1,0,0,0,0,0,0,0,0,0,0,0,1,1,-1,0,0,0,0,-1,0,0,0,0,0,0,0,0,0,0,
0,-1,-1,0,0,0,0,0,0,0,-1,-1,0,0,0,1,0,0,0,-1,1,0,-1,0,0,0,0,0,0,0,
0,0,0,-1,0,0,-1,0,0,0,0,0,0,-1,0,0,0,1,1,1,0, };
static signed short stb__courier_bold_8_usascii_y[95]={ 5,0,0,0,0,0,1,0,0,0,0,0,4,2,
4,0,0,0,0,0,0,0,0,0,0,0,1,1,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,6,0,1,0,1,0,1,0,1,0,0,
0,0,0,1,1,1,1,1,1,1,0,1,1,1,1,1,1,0,0,0,2, };
static unsigned short stb__courier_bold_8_usascii_w[95]={ 0,2,4,4,4,4,4,2,3,3,4,4,2,4,
2,4,4,4,4,4,4,4,4,4,4,4,2,2,5,5,5,4,4,6,5,4,4,4,5,5,5,4,5,5,
5,6,6,5,5,5,5,4,4,5,6,6,5,5,4,3,4,3,4,6,2,5,6,5,5,4,5,5,5,4,
4,5,4,6,5,4,6,5,5,4,5,5,5,6,5,5,4,3,2,3,4, };
static unsigned short stb__courier_bold_8_usascii_h[95]={ 0,6,3,6,6,6,5,3,7,7,4,5,3,2,
2,6,6,5,5,6,5,6,6,6,6,6,5,5,5,4,5,6,6,5,5,6,5,5,5,6,5,5,6,5,
5,5,5,6,5,7,5,6,5,6,5,5,5,5,5,7,6,7,3,2,2,5,6,5,6,5,5,6,5,5,
7,5,5,4,4,5,6,6,4,5,6,5,4,4,4,6,4,7,7,7,2, };
static unsigned short stb__courier_bold_8_usascii_s[95]={ 125,57,90,78,83,29,21,95,1,21,75,
16,125,116,106,34,39,6,11,44,26,120,24,1,104,61,115,125,109,69,97,
73,88,77,71,93,61,56,50,98,38,1,55,21,15,8,1,51,116,29,104,
12,93,49,118,84,103,91,122,35,109,25,85,109,103,71,17,87,6,66,98,
114,110,77,16,27,82,62,56,66,66,60,50,33,45,44,38,31,44,39,80,
12,9,5,98, };
static unsigned short stb__courier_bold_8_usascii_t[95]={ 7,1,22,1,1,9,22,22,1,1,22,
22,16,22,22,9,8,22,22,8,22,1,9,9,1,8,16,1,16,22,16,
1,1,16,16,1,16,16,16,1,16,22,8,16,16,16,16,1,8,1,8,
9,8,8,16,16,16,16,8,1,1,1,22,22,22,8,9,8,9,8,8,
1,8,8,1,16,8,22,22,16,1,1,22,16,1,16,22,22,22,1,22,
1,1,1,22, };
static unsigned short stb__courier_bold_8_usascii_a[95]={ 68,68,68,68,68,68,68,68,
68,68,68,68,68,68,68,68,68,68,68,68,68,68,68,68,
68,68,68,68,68,68,68,68,68,68,68,68,68,68,68,68,
68,68,68,68,68,68,68,68,68,68,68,68,68,68,68,68,
68,68,68,68,68,68,68,68,68,68,68,68,68,68,68,68,
68,68,68,68,68,68,68,68,68,68,68,68,68,68,68,68,
68,68,68,68,68,68,68, };

// Call this function with
//    font: NULL or array length
//    data: NULL or specified size
//    height: STB_FONT_courier_bold_8_usascii_BITMAP_HEIGHT or STB_FONT_courier_bold_8_usascii_BITMAP_HEIGHT_POW2
//    return value: spacing between lines
static void stb_font_courier_bold_8_usascii(stb_fontchar font[STB_FONT_courier_bold_8_usascii_NUM_CHARS],
                unsigned char data[STB_FONT_courier_bold_8_usascii_BITMAP_HEIGHT][STB_FONT_courier_bold_8_usascii_BITMAP_WIDTH],
                int height)
{
    int i,j;
    if (data != 0) {
        unsigned int *bits = stb__courier_bold_8_usascii_pixels;
        unsigned int bitpack = *bits++, numbits = 32;
        for (i=0; i < STB_FONT_courier_bold_8_usascii_BITMAP_WIDTH*height; ++i)
            data[0][i] = 0;  // zero entire bitmap
        for (j=1; j < STB_FONT_courier_bold_8_usascii_BITMAP_HEIGHT-1; ++j) {
            for (i=1; i < STB_FONT_courier_bold_8_usascii_BITMAP_WIDTH-1; ++i) {
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
        float recip_width = 1.0f / STB_FONT_courier_bold_8_usascii_BITMAP_WIDTH;
        float recip_height = 1.0f / height;
        for (i=0; i < STB_FONT_courier_bold_8_usascii_NUM_CHARS; ++i) {
            // pad characters so they bilerp from empty space around each character
            font[i].s0 = (stb__courier_bold_8_usascii_s[i]) * recip_width;
            font[i].t0 = (stb__courier_bold_8_usascii_t[i]) * recip_height;
            font[i].s1 = (stb__courier_bold_8_usascii_s[i] + stb__courier_bold_8_usascii_w[i]) * recip_width;
            font[i].t1 = (stb__courier_bold_8_usascii_t[i] + stb__courier_bold_8_usascii_h[i]) * recip_height;
            font[i].x0 = stb__courier_bold_8_usascii_x[i];
            font[i].y0 = stb__courier_bold_8_usascii_y[i];
            font[i].x1 = stb__courier_bold_8_usascii_x[i] + stb__courier_bold_8_usascii_w[i];
            font[i].y1 = stb__courier_bold_8_usascii_y[i] + stb__courier_bold_8_usascii_h[i];
            font[i].advance_int = (stb__courier_bold_8_usascii_a[i]+8)>>4;
            font[i].s0f = (stb__courier_bold_8_usascii_s[i] - 0.5f) * recip_width;
            font[i].t0f = (stb__courier_bold_8_usascii_t[i] - 0.5f) * recip_height;
            font[i].s1f = (stb__courier_bold_8_usascii_s[i] + stb__courier_bold_8_usascii_w[i] + 0.5f) * recip_width;
            font[i].t1f = (stb__courier_bold_8_usascii_t[i] + stb__courier_bold_8_usascii_h[i] + 0.5f) * recip_height;
            font[i].x0f = stb__courier_bold_8_usascii_x[i] - 0.5f;
            font[i].y0f = stb__courier_bold_8_usascii_y[i] - 0.5f;
            font[i].x1f = stb__courier_bold_8_usascii_x[i] + stb__courier_bold_8_usascii_w[i] + 0.5f;
            font[i].y1f = stb__courier_bold_8_usascii_y[i] + stb__courier_bold_8_usascii_h[i] + 0.5f;
            font[i].advance = stb__courier_bold_8_usascii_a[i]/16.0f;
        }
    }
}

#ifndef STB_SOMEFONT_CREATE
#define STB_SOMEFONT_CREATE              stb_font_courier_bold_8_usascii
#define STB_SOMEFONT_BITMAP_WIDTH        STB_FONT_courier_bold_8_usascii_BITMAP_WIDTH
#define STB_SOMEFONT_BITMAP_HEIGHT       STB_FONT_courier_bold_8_usascii_BITMAP_HEIGHT
#define STB_SOMEFONT_BITMAP_HEIGHT_POW2  STB_FONT_courier_bold_8_usascii_BITMAP_HEIGHT_POW2
#define STB_SOMEFONT_FIRST_CHAR          STB_FONT_courier_bold_8_usascii_FIRST_CHAR
#define STB_SOMEFONT_NUM_CHARS           STB_FONT_courier_bold_8_usascii_NUM_CHARS
#define STB_SOMEFONT_LINE_SPACING        STB_FONT_courier_bold_8_usascii_LINE_SPACING
#endif

