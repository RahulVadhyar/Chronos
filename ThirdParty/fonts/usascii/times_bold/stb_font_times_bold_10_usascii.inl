// Font generated by stb_font_inl_generator.c (4/1 bpp)
//
// Following instructions show how to use the only included font, whatever it is, in
// a generic way so you can replace it with any other font by changing the include.
// To use multiple fonts, replace STB_SOMEFONT_* below with STB_FONT_times_bold_10_usascii_*,
// and separately install each font. Note that the CREATE function call has a
// totally different name; it's just 'stb_font_times_bold_10_usascii'.
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

#define STB_FONT_times_bold_10_usascii_BITMAP_WIDTH         128
#define STB_FONT_times_bold_10_usascii_BITMAP_HEIGHT         42
#define STB_FONT_times_bold_10_usascii_BITMAP_HEIGHT_POW2    64

#define STB_FONT_times_bold_10_usascii_FIRST_CHAR            32
#define STB_FONT_times_bold_10_usascii_NUM_CHARS             95

#define STB_FONT_times_bold_10_usascii_LINE_SPACING           6

static unsigned int stb__times_bold_10_usascii_pixels[]={
    0x00000000,0x02000000,0x00000000,0x00002021,0x8c41f000,0x23986658,
    0x2a9aa809,0x4c2cac98,0x0dc41aac,0x224ac889,0x2e0af20f,0x42bc886a,
    0x8f2a248b,0x56cc4cb8,0x6dd5cc5a,0x0e8b0a21,0x71616433,0x3f114421,
    0x88fc43e2,0x41703a0f,0xa87c4f6b,0x858f878d,0x272279cc,0x4c35770c,
    0x287e27ab,0x7c4330fc,0x86668930,0xb188e43b,0x23dc51f5,0x53f8f73f,
    0xf114459d,0x2332585d,0x22aafc0f,0x5b50f8db,0x6417e61b,0x07a81ee1,
    0x298970f8,0x7902e233,0x21b565ce,0x47b9fc7b,0x41f3b93f,0x451bf224,
    0x3910f8cc,0x6644175f,0x9832f6a6,0x03dc186f,0x3e1654f7,0x331b8970,
    0xd94f20dc,0x8fc433da,0x223f10f9,0x41f1b71f,0x183eaf23,0x76b9e36e,
    0xaa8b207f,0x83ae10ab,0x410fcc08,0xf83f31f9,0x86668b10,0x99506c3b,
    0xac981377,0x0d4dcc2c,0x329895b1,0x887c4939,0x2fba62bd,0x70aa24fc,
    0x43cab891,0x2aada85b,0x10754ed4,0x4c36241f,0x82890b21,0x0009d008,
    0x40000080,0x20108000,0x04008001,0x398c2644,0x40638866,0x22019999,
    0x000000bb,0x00000000,0x00000000,0x00000000,0x00000000,0x00000000,
    0x20000000,0x0f808078,0x44440004,0x0d51f880,0x440840c0,0x6453e600,
    0x43269f30,0x7ffd4108,0x29f33f70,0x3625f738,0x239b1a00,0x894c7838,
    0x395712fd,0x8883afea,0x7902d31e,0x4ec43a27,0x21d5b31e,0xc8517c69,
    0x23bdc32f,0xc9fc599a,0x43274136,0xbd99a6b8,0x8471e093,0x4c62b54c,
    0x3eba27b6,0x223d5f31,0xadc7ee0f,0x44d3971e,0xc98517c1,0x40cfc19f,
    0x9fcb6438,0x6a82bdc1,0x03519b1a,0x31e9891e,0x3db4c3df,0xdb4c7a97,
    0x734c3f33,0x0d6447ab,0x30a2f8d5,0x01d70bb6,0xe8af8817,0x4157c41c,
    0x45c41a69,0x88513c4b,0x4cbf626d,0x3ab70eaf,0x478f6d31,0x47eb6269,
    0xd1a61bca,0x1f446147,0x5d824162,0x4c1b20f7,0xdcba41a6,0x5880b9e1,
    0x88699e47,0xb3b32fbd,0x74074478,0x263d9b31,0x26157546,0x10308e24,
    0x8244aa07,0x434d3039,0x3c1b931a,0x9719cd89,0x003ae173,0x801f9810,
    0x453752e8,0x800080fb,0x0000003b,0x10911f70,0x0010c808,0x00000004,
    0x00000000,0x00000000,0x00000000,0x00000000,0x00000000,0x00000000,
    0x06f44080,0x3f600100,0x036f3e67,0x1b14fa82,0x1dd7ea08,0x799f30f5,
    0x567cc088,0x1b59f31d,0xf512f3e6,0x41733e60,0x0704d84a,0x8bfa21f1,
    0xe97c08a8,0x6d86b223,0x71de4411,0x8179851f,0x7930f9af,0x7c113f89,
    0x6cbe088a,0x3e045e64,0x26c42f8a,0x407d426c,0xfb976260,0x0fcd7c2e,
    0x57c477b7,0x3a0465c2,0x20faf986,0x32a25cbf,0x67c1e7c5,0x4cf72f84,
    0x4ccf8197,0x84d84ca8,0x2c8183fa,0x3f3e364c,0x0fc82dc4,0x43fa82dc,
    0x0e7c3d79,0x99f16b66,0x25f097f0,0x206fe67b,0x26e1f9af,0x30fa725d,
    0x383f31b2,0x3f55f160,0x1ea0e6c4,0xb89873a2,0xf0f5e60f,0x41d7d505,
    0x50af80bf,0x3e65d97c,0x47d2f86b,0xd570eecb,0x42fa9a83,0xdb8a2e09,
    0x7653e61a,0x800fc800,0x50ef88da,0x13e25f1f,0xf884f880,0x79f32dad,
    0x2747d419,0x901979f3,0x3a277009,0x6ffa820e,0x00000000,0x00000000,
    0x00000000,0x00000000,0x00000000,0x00000000,0x80000000,0xf31fdad9,
    0x6b867ccd,0x000cf980,0x01010211,0x1127cc11,0xfc8cf982,0x41111111,
    0xf34aeebc,0x10607a29,0x11100111,0xf713e231,0x2698faa3,0x202f80bb,
    0x88ef74b8,0x5493910f,0x2f517c4b,0x73d4be1f,0xd8c55f1d,0x2029fc15,
    0x741d7cc3,0x6c8fa6a0,0x3e98ce98,0xf8b2e1a6,0x7c0bc982,0xf1970419,
    0x45f0bea1,0x4e7c3f79,0x0e657c7c,0x82e7c2ec,0x1b219c99,0x4cd7126a,
    0xd3fa982f,0x165434c7,0x8179305f,0x1970c0eb,0x5f07dc4f,0x2fe1fbcc,
    0x7cee47b8,0xecf85d80,0x22ada985,0x8d5221f9,0x14bd0af8,0xd31f4fe3,
    0x517c0e5c,0x11223b88,0xb8eb221f,0x7f117c5a,0x47a97c5f,0x21760b29,
    0x8703f9bf,0x6400ecb9,0xcabfbcae,0x3e22e934,0xf3003ee4,0x0000795b,
    0x009f1000,0x03f919f1,0xf1077440,0x0060ff69,0x00000000,0x00000000,
    0x00000000,0x00000000,0x81084400,0x10880108,0x20200044,0x665c1108,
    0xbb8aea4c,0x000002bb,0x00000000,0x32fabe60,0x4896fe64,0x6b87dfd4,
    0xa87de2d3,0x26b72adc,0xa8eeeee4,0x0000002a,0x00000000,0x2ab6f100,
    0xbb983e26,0x250f5e64,0x0c135a58,0x00000010,0x00000000,0x5e200000,
    0x21e26aad,0x8f5e61ac,0x000a5140,0x00000000,0x00000000,0xe8fa8000,
    0x103ea6bb,0x02f8fa82,0x00000000,0x00000000,0x00000000,0x00000000,
    0x00000000,0x00000000,0x00000000,
};

static signed short stb__times_bold_10_usascii_x[95]={ 0,0,0,0,0,0,0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,-1,0,0,0,0,0,0,0,0,0,0,
-1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0, };
static signed short stb__times_bold_10_usascii_y[95]={ 8,1,1,1,1,1,1,1,1,1,1,2,6,5,
6,1,1,1,1,1,1,2,1,2,1,1,3,3,2,4,2,1,1,1,2,1,2,2,2,1,2,2,2,2,
2,2,2,1,2,1,2,1,2,2,2,2,2,2,2,2,1,2,1,9,1,3,2,3,2,3,1,3,2,1,
1,2,2,3,3,3,3,3,3,3,2,3,3,3,3,3,3,1,1,1,4, };
static unsigned short stb__times_bold_10_usascii_w[95]={ 0,3,5,5,5,9,8,2,3,3,5,5,2,3,
2,3,5,4,5,4,5,5,5,5,5,5,3,3,5,6,5,5,9,7,6,7,7,6,6,7,7,4,5,8,
6,9,7,7,6,7,7,5,6,7,7,9,7,7,6,3,3,3,5,6,3,5,5,4,5,4,4,5,5,3,
4,6,3,8,5,5,5,5,4,4,3,5,5,7,5,5,4,4,2,3,5, };
static unsigned short stb__times_bold_10_usascii_h[95]={ 0,8,4,8,8,8,8,4,9,9,5,6,4,2,
3,8,8,7,7,8,7,7,8,7,8,8,6,7,6,3,6,8,9,7,6,8,6,6,6,8,6,6,7,6,
6,6,7,8,6,9,6,8,6,7,7,7,6,6,6,8,8,8,5,1,3,6,7,6,7,6,7,7,6,7,
9,6,6,5,5,6,7,7,5,6,7,6,6,6,5,7,5,9,9,9,3, };
static unsigned short stb__times_bold_10_usascii_s[95]={ 127,68,33,93,99,5,78,30,6,22,15,
105,27,59,45,19,72,123,25,23,1,31,52,99,62,87,47,21,35,52,22,
105,26,13,119,111,104,97,90,119,73,62,7,96,28,8,85,44,77,36,37,
28,89,77,115,105,63,50,1,15,58,1,117,63,48,84,46,58,40,45,52,
67,71,73,1,112,18,1,21,51,34,61,10,57,57,67,41,81,111,93,123,
17,14,10,39, };
static unsigned short stb__times_bold_10_usascii_t[95]={ 1,1,35,1,1,11,1,35,1,1,35,
28,35,35,35,11,1,11,20,11,20,20,1,11,1,1,28,20,28,35,28,
1,1,20,20,1,20,20,20,1,28,28,20,28,28,28,11,1,20,1,20,
11,28,11,11,11,20,20,28,11,1,11,28,35,35,20,11,20,11,20,11,
11,20,11,1,20,28,35,35,28,11,11,35,28,11,28,28,28,28,11,28,
1,1,1,35, };
static unsigned short stb__times_bold_10_usascii_a[95]={ 36,48,80,72,72,144,120,40,
48,48,72,82,36,48,36,40,72,72,72,72,72,72,72,72,
72,72,48,48,82,82,82,72,134,104,96,104,104,96,88,112,
112,56,72,112,96,136,104,112,88,112,104,80,96,104,104,144,
104,104,96,48,40,48,84,72,48,72,80,64,80,64,48,72,
80,40,48,80,40,120,80,72,80,80,64,56,48,80,72,104,
72,72,64,57,32,57,75, };

// Call this function with
//    font: NULL or array length
//    data: NULL or specified size
//    height: STB_FONT_times_bold_10_usascii_BITMAP_HEIGHT or STB_FONT_times_bold_10_usascii_BITMAP_HEIGHT_POW2
//    return value: spacing between lines
static void stb_font_times_bold_10_usascii(stb_fontchar font[STB_FONT_times_bold_10_usascii_NUM_CHARS],
                unsigned char data[STB_FONT_times_bold_10_usascii_BITMAP_HEIGHT][STB_FONT_times_bold_10_usascii_BITMAP_WIDTH],
                int height)
{
    int i,j;
    if (data != 0) {
        unsigned int *bits = stb__times_bold_10_usascii_pixels;
        unsigned int bitpack = *bits++, numbits = 32;
        for (i=0; i < STB_FONT_times_bold_10_usascii_BITMAP_WIDTH*height; ++i)
            data[0][i] = 0;  // zero entire bitmap
        for (j=1; j < STB_FONT_times_bold_10_usascii_BITMAP_HEIGHT-1; ++j) {
            for (i=1; i < STB_FONT_times_bold_10_usascii_BITMAP_WIDTH-1; ++i) {
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
        float recip_width = 1.0f / STB_FONT_times_bold_10_usascii_BITMAP_WIDTH;
        float recip_height = 1.0f / height;
        for (i=0; i < STB_FONT_times_bold_10_usascii_NUM_CHARS; ++i) {
            // pad characters so they bilerp from empty space around each character
            font[i].s0 = (stb__times_bold_10_usascii_s[i]) * recip_width;
            font[i].t0 = (stb__times_bold_10_usascii_t[i]) * recip_height;
            font[i].s1 = (stb__times_bold_10_usascii_s[i] + stb__times_bold_10_usascii_w[i]) * recip_width;
            font[i].t1 = (stb__times_bold_10_usascii_t[i] + stb__times_bold_10_usascii_h[i]) * recip_height;
            font[i].x0 = stb__times_bold_10_usascii_x[i];
            font[i].y0 = stb__times_bold_10_usascii_y[i];
            font[i].x1 = stb__times_bold_10_usascii_x[i] + stb__times_bold_10_usascii_w[i];
            font[i].y1 = stb__times_bold_10_usascii_y[i] + stb__times_bold_10_usascii_h[i];
            font[i].advance_int = (stb__times_bold_10_usascii_a[i]+8)>>4;
            font[i].s0f = (stb__times_bold_10_usascii_s[i] - 0.5f) * recip_width;
            font[i].t0f = (stb__times_bold_10_usascii_t[i] - 0.5f) * recip_height;
            font[i].s1f = (stb__times_bold_10_usascii_s[i] + stb__times_bold_10_usascii_w[i] + 0.5f) * recip_width;
            font[i].t1f = (stb__times_bold_10_usascii_t[i] + stb__times_bold_10_usascii_h[i] + 0.5f) * recip_height;
            font[i].x0f = stb__times_bold_10_usascii_x[i] - 0.5f;
            font[i].y0f = stb__times_bold_10_usascii_y[i] - 0.5f;
            font[i].x1f = stb__times_bold_10_usascii_x[i] + stb__times_bold_10_usascii_w[i] + 0.5f;
            font[i].y1f = stb__times_bold_10_usascii_y[i] + stb__times_bold_10_usascii_h[i] + 0.5f;
            font[i].advance = stb__times_bold_10_usascii_a[i]/16.0f;
        }
    }
}

#ifndef STB_SOMEFONT_CREATE
#define STB_SOMEFONT_CREATE              stb_font_times_bold_10_usascii
#define STB_SOMEFONT_BITMAP_WIDTH        STB_FONT_times_bold_10_usascii_BITMAP_WIDTH
#define STB_SOMEFONT_BITMAP_HEIGHT       STB_FONT_times_bold_10_usascii_BITMAP_HEIGHT
#define STB_SOMEFONT_BITMAP_HEIGHT_POW2  STB_FONT_times_bold_10_usascii_BITMAP_HEIGHT_POW2
#define STB_SOMEFONT_FIRST_CHAR          STB_FONT_times_bold_10_usascii_FIRST_CHAR
#define STB_SOMEFONT_NUM_CHARS           STB_FONT_times_bold_10_usascii_NUM_CHARS
#define STB_SOMEFONT_LINE_SPACING        STB_FONT_times_bold_10_usascii_LINE_SPACING
#endif

