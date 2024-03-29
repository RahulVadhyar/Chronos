// Font generated by stb_font_inl_generator.c (4/1 bpp)
//
// Following instructions show how to use the only included font, whatever it is, in
// a generic way so you can replace it with any other font by changing the include.
// To use multiple fonts, replace STB_SOMEFONT_* below with STB_FONT_consolas_bold_6_usascii_*,
// and separately install each font. Note that the CREATE function call has a
// totally different name; it's just 'stb_font_consolas_bold_6_usascii'.
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

#define STB_FONT_consolas_bold_6_usascii_BITMAP_WIDTH         128
#define STB_FONT_consolas_bold_6_usascii_BITMAP_HEIGHT         26
#define STB_FONT_consolas_bold_6_usascii_BITMAP_HEIGHT_POW2    32

#define STB_FONT_consolas_bold_6_usascii_FIRST_CHAR            32
#define STB_FONT_consolas_bold_6_usascii_NUM_CHARS             95

#define STB_FONT_consolas_bold_6_usascii_LINE_SPACING           4

static unsigned int stb__consolas_bold_6_usascii_pixels[]={
    0x08704426,0x40981022,0x10411040,0x00200040,0x6cc20201,0x80800023,
    0x02008220,0x6492446e,0x22449731,0x32886e0c,0x07792c7b,0x2e6572a9,
    0x350d8597,0x95ac3c88,0xa9b2a064,0x4c70324c,0x20b602e5,0x49242e19,
    0x386a1ccc,0x17279524,0x46a0dd4b,0xca9232b5,0xaacc2401,0x66432b6c,
    0x4b58f2e5,0x248d35cc,0x20faa4ab,0x4aa52a19,0x23987732,0x64710e23,
    0x248990e5,0x649996cb,0x81706c5c,0x24daad64,0xb8b2e48c,0x4496324c,
    0x20b03ae4,0xc9248e19,0x5870d44c,0x924db9c4,0xb0530d9b,0x21d99032,
    0xb921c448,0x66432e5c,0x19016b24,0x9f4cfa6b,0x6442c59b,0x23724b11,
    0x1b1221ab,0x0a2b9954,0x00420500,0x02000a00,0x00000060,0x04080200,
    0x04401003,0x00000000,0x00000000,0x00000000,0x00000000,0x00000000,
    0x00000000,0x00000000,0x4032b1c0,0x4d3223d9,0x64cf6a4c,0x26107483,
    0x3267933c,0x1e4c5913,0x52cdd690,0x739245c3,0x479726dc,0x26f2a48b,
    0x3265954b,0x92ea7d74,0x0c92b3d9,0x40bb8636,0x322561b4,0x774a8792,
    0x68d86f29,0xb95a4322,0x43990d4b,0x2322c4cc,0x9ba8ba25,0x327b35b9,
    0x5c3d124b,0x20d86560,0x9166258d,0x544a92b0,0xcadd56a5,0x9832f659,
    0x8f2eb974,0xbc83721a,0x88b322c5,0x32e6ea2e,0x8f2a9755,0x3d98953d,
    0xaa6cc995,0x64d32a6d,0x5132e1b2,0xa65532e5,0x54b934cb,0x7481224c,
    0x2c64f6a1,0x06458f19,0x03da9632,0x00000800,0x00000000,0x00000000,
    0x00000000,0x00000000,0x00000000,0x00000000,0x64000000,0xb2e5403c,
    0x2201e5c3,0x5385d22a,0x654f6601,0x95cb8e93,0x8ee3ca8e,0x4f2603cb,
    0x320020d9,0x72b98100,0x4245acb5,0x4e47933a,0xddb97765,0x5564b190,
    0x1b2cb990,0x2911676b,0x442aa4c9,0x1b12b24b,0x36617158,0x2454b972,
    0x2b98a21d,0x754b587e,0x25bb9623,0x42f322cc,0xc92e65cc,0x2cb190dd,
    0x916b6d73,0x23750741,0x896b25bd,0x26170e44,0x0001373d,0x25ab8cc4,
    0x372243cd,0x2321b3b4,0x4d42f325,0x4f3b0fc2,0x2a7d558c,0x44892b2c,
    0x4b310d45,0x53ae04cc,0x01b864ea,0x00000000,0x00000000,0x00000000,
    0x00000000,0x86560000,0x6d42a320,0x2a110115,0x005910aa,0x00000000,
    0x00000000,0x97500000,0x0d89b92c,0x9a5ccb99,0x00000019,0x00000000,
    0x00000000,0x32187a00,0x880fae6b,0x00000008,0x00000000,0x00000000,
    0x00000000,0x00000000,0x00000000,0x00000000,0x00000000,0x00000000,
    0x00000000,0x00000000,0x00000000,
};

static signed short stb__consolas_bold_6_usascii_x[95]={ 0,1,0,0,0,0,0,1,0,0,0,0,0,0,
1,0,0,0,0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,0, };
static signed short stb__consolas_bold_6_usascii_y[95]={ 4,-1,-1,0,-1,-1,-1,-1,-1,-1,-1,0,2,2,
2,-1,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,-1,-1,0,0,0,0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,-1,-1,-1,0,4,-1,0,-1,0,-1,0,-1,0,-1,-1,
-1,-1,-1,0,0,0,0,0,0,0,0,1,1,1,1,1,1,-1,-1,-1,1, };
static unsigned short stb__consolas_bold_6_usascii_w[95]={ 0,2,3,4,4,4,4,2,3,3,3,4,3,3,
2,3,4,3,3,3,4,3,4,3,3,3,2,3,3,3,3,3,4,4,4,3,4,3,3,4,4,3,3,4,
3,4,4,4,4,4,4,3,4,4,4,4,4,4,3,3,4,3,4,4,3,3,4,3,3,3,4,4,3,3,
3,4,3,4,3,4,4,3,4,3,3,3,4,4,4,4,3,3,1,3,4, };
static unsigned short stb__consolas_bold_6_usascii_h[95]={ 0,6,3,4,6,6,6,3,7,7,4,4,4,1,
3,6,5,4,4,5,4,5,5,4,5,4,5,6,5,3,5,6,7,4,4,5,4,4,4,5,4,4,5,4,
4,4,4,5,4,6,4,5,4,5,4,4,4,4,4,7,6,7,3,2,3,5,6,5,6,5,5,6,5,5,
7,5,5,4,4,5,6,6,4,5,5,4,3,3,3,5,3,7,7,7,3, };
static unsigned short stb__consolas_bold_6_usascii_s[95]={ 126,41,23,30,36,44,62,6,28,20,97,
6,85,32,111,49,77,93,89,64,75,40,72,62,68,53,48,67,56,118,82,
76,15,15,80,31,1,124,71,35,57,49,44,99,95,90,104,26,114,84,20,
60,109,51,35,40,119,66,11,24,71,1,106,27,114,1,89,22,80,9,121,
94,104,108,32,116,112,25,45,99,57,53,101,5,13,86,1,9,122,17,14,
11,9,5,18, };
static unsigned short stb__consolas_bold_6_usascii_t[95]={ 1,1,20,15,1,1,1,20,1,1,15,
15,15,20,15,1,9,15,15,9,15,9,9,15,9,15,9,1,9,15,9,
1,1,15,15,9,15,9,15,9,15,15,9,9,9,9,9,9,9,1,15,
9,9,9,15,15,9,15,15,1,1,1,15,20,15,9,1,9,1,9,1,
1,1,1,1,1,1,15,15,1,1,1,15,9,9,9,20,20,15,9,20,
1,1,1,20, };
static unsigned short stb__consolas_bold_6_usascii_a[95]={ 53,53,53,53,53,53,53,53,
53,53,53,53,53,53,53,53,53,53,53,53,53,53,53,53,
53,53,53,53,53,53,53,53,53,53,53,53,53,53,53,53,
53,53,53,53,53,53,53,53,53,53,53,53,53,53,53,53,
53,53,53,53,53,53,53,53,53,53,53,53,53,53,53,53,
53,53,53,53,53,53,53,53,53,53,53,53,53,53,53,53,
53,53,53,53,53,53,53, };

// Call this function with
//    font: NULL or array length
//    data: NULL or specified size
//    height: STB_FONT_consolas_bold_6_usascii_BITMAP_HEIGHT or STB_FONT_consolas_bold_6_usascii_BITMAP_HEIGHT_POW2
//    return value: spacing between lines
static void stb_font_consolas_bold_6_usascii(stb_fontchar font[STB_FONT_consolas_bold_6_usascii_NUM_CHARS],
                unsigned char data[STB_FONT_consolas_bold_6_usascii_BITMAP_HEIGHT][STB_FONT_consolas_bold_6_usascii_BITMAP_WIDTH],
                int height)
{
    int i,j;
    if (data != 0) {
        unsigned int *bits = stb__consolas_bold_6_usascii_pixels;
        unsigned int bitpack = *bits++, numbits = 32;
        for (i=0; i < STB_FONT_consolas_bold_6_usascii_BITMAP_WIDTH*height; ++i)
            data[0][i] = 0;  // zero entire bitmap
        for (j=1; j < STB_FONT_consolas_bold_6_usascii_BITMAP_HEIGHT-1; ++j) {
            for (i=1; i < STB_FONT_consolas_bold_6_usascii_BITMAP_WIDTH-1; ++i) {
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
        float recip_width = 1.0f / STB_FONT_consolas_bold_6_usascii_BITMAP_WIDTH;
        float recip_height = 1.0f / height;
        for (i=0; i < STB_FONT_consolas_bold_6_usascii_NUM_CHARS; ++i) {
            // pad characters so they bilerp from empty space around each character
            font[i].s0 = (stb__consolas_bold_6_usascii_s[i]) * recip_width;
            font[i].t0 = (stb__consolas_bold_6_usascii_t[i]) * recip_height;
            font[i].s1 = (stb__consolas_bold_6_usascii_s[i] + stb__consolas_bold_6_usascii_w[i]) * recip_width;
            font[i].t1 = (stb__consolas_bold_6_usascii_t[i] + stb__consolas_bold_6_usascii_h[i]) * recip_height;
            font[i].x0 = stb__consolas_bold_6_usascii_x[i];
            font[i].y0 = stb__consolas_bold_6_usascii_y[i];
            font[i].x1 = stb__consolas_bold_6_usascii_x[i] + stb__consolas_bold_6_usascii_w[i];
            font[i].y1 = stb__consolas_bold_6_usascii_y[i] + stb__consolas_bold_6_usascii_h[i];
            font[i].advance_int = (stb__consolas_bold_6_usascii_a[i]+8)>>4;
            font[i].s0f = (stb__consolas_bold_6_usascii_s[i] - 0.5f) * recip_width;
            font[i].t0f = (stb__consolas_bold_6_usascii_t[i] - 0.5f) * recip_height;
            font[i].s1f = (stb__consolas_bold_6_usascii_s[i] + stb__consolas_bold_6_usascii_w[i] + 0.5f) * recip_width;
            font[i].t1f = (stb__consolas_bold_6_usascii_t[i] + stb__consolas_bold_6_usascii_h[i] + 0.5f) * recip_height;
            font[i].x0f = stb__consolas_bold_6_usascii_x[i] - 0.5f;
            font[i].y0f = stb__consolas_bold_6_usascii_y[i] - 0.5f;
            font[i].x1f = stb__consolas_bold_6_usascii_x[i] + stb__consolas_bold_6_usascii_w[i] + 0.5f;
            font[i].y1f = stb__consolas_bold_6_usascii_y[i] + stb__consolas_bold_6_usascii_h[i] + 0.5f;
            font[i].advance = stb__consolas_bold_6_usascii_a[i]/16.0f;
        }
    }
}

#ifndef STB_SOMEFONT_CREATE
#define STB_SOMEFONT_CREATE              stb_font_consolas_bold_6_usascii
#define STB_SOMEFONT_BITMAP_WIDTH        STB_FONT_consolas_bold_6_usascii_BITMAP_WIDTH
#define STB_SOMEFONT_BITMAP_HEIGHT       STB_FONT_consolas_bold_6_usascii_BITMAP_HEIGHT
#define STB_SOMEFONT_BITMAP_HEIGHT_POW2  STB_FONT_consolas_bold_6_usascii_BITMAP_HEIGHT_POW2
#define STB_SOMEFONT_FIRST_CHAR          STB_FONT_consolas_bold_6_usascii_FIRST_CHAR
#define STB_SOMEFONT_NUM_CHARS           STB_FONT_consolas_bold_6_usascii_NUM_CHARS
#define STB_SOMEFONT_LINE_SPACING        STB_FONT_consolas_bold_6_usascii_LINE_SPACING
#endif

