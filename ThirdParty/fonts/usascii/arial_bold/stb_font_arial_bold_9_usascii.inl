// Font generated by stb_font_inl_generator.c (4/1 bpp)
//
// Following instructions show how to use the only included font, whatever it is, in
// a generic way so you can replace it with any other font by changing the include.
// To use multiple fonts, replace STB_SOMEFONT_* below with STB_FONT_arial_bold_9_usascii_*,
// and separately install each font. Note that the CREATE function call has a
// totally different name; it's just 'stb_font_arial_bold_9_usascii'.
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

#define STB_FONT_arial_bold_9_usascii_BITMAP_WIDTH         128
#define STB_FONT_arial_bold_9_usascii_BITMAP_HEIGHT         36
#define STB_FONT_arial_bold_9_usascii_BITMAP_HEIGHT_POW2    64

#define STB_FONT_arial_bold_9_usascii_FIRST_CHAR            32
#define STB_FONT_arial_bold_9_usascii_NUM_CHARS             95

#define STB_FONT_arial_bold_9_usascii_LINE_SPACING           6

static unsigned int stb__arial_bold_9_usascii_pixels[]={
    0x2398f204,0x9d41db5b,0x0cddb81b,0x8a1b8baa,0x05bb5020,0x20222111,
    0x32659b84,0x06644352,0x5b930772,0x6ecc1da8,0x7887b223,0x83e1e926,
    0x0ac8b318,0x4436a1b7,0xf96436e6,0x25d35f30,0xbd52ede8,0x5d30641d,
    0x22d66e1d,0x272a5bca,0x987cd7c5,0x26be249e,0x7879972e,0x83e0f926,
    0xcbaa9e4b,0x54953aed,0x56ccbf64,0x975a96e5,0x23cad4b6,0x47b3ee2b,
    0xd881bcda,0x5a8f7a22,0x2dc39b70,0xa64274c1,0x20f8b749,0xb4647a4b,
    0x5c9538ca,0x45bd16a3,0xea556a4b,0x498b2d52,0xb08333aa,0x52dc4393,
    0xb825cb7b,0x7e56e69d,0x27b1ba65,0x20f8d549,0xb4e43a4b,0x5c950cbc,
    0x88f916a3,0xdd13d88f,0x037baa5d,0x20e76e4b,0x15549c9b,0x3a279dcf,
    0x9eb30f88,0x2aab71f9,0x7c933c6b,0x9e4b83e0,0x21dedcaa,0x3f992a4a,
    0x9dd70991,0x812a5901,0xbac166e5,0x447dd13c,0x1f75c3ee,0xdfd70fb6,
    0x798ffa25,0x1f12e926,0x3224d362,0x36a3b30b,0x00ca81a0,0x00a63500,
    0x00010400,0x85000000,0x74a8a22b,0x80a8e449,0x3260bcba,0x000002a2,
    0x00000000,0x00000000,0x00000000,0x00000000,0x00000000,0x40000000,
    0x31332088,0x90dc05b9,0x260e619d,0x04da8363,0x02065c19,0x8832e293,
    0x260c4110,0x06126953,0x8f777204,0xce88734d,0x4455d12e,0xc882e9af,
    0x2a791b52,0x41f2d40c,0x26680e9e,0xd31664ad,0xb4a92f2e,0x19977a65,
    0x7445d5d1,0x88f7a66d,0x21d509f9,0x367708ca,0x2d45bf32,0x97674cb5,
    0x33aa2df8,0x707cb50e,0x5dc9109f,0xacb4c068,0x516d2a79,0xbf5254f9,
    0x5ee413b8,0xa97e4786,0x5d4b8fce,0x24b9e2a2,0x116cee69,0x9e56abd7,
    0x6f4c3e5a,0xbb8ea0cd,0x4da60478,0x9752a7de,0xa92a79cc,0x323a5c5f,
    0x2cc7839c,0x3762b6b5,0x443e532d,0x52e4dd8e,0x55aa972e,0x7c5a6595,
    0x391fa970,0x2d32c654,0xb3335a9c,0xea976fc4,0x57452a7d,0x893b622f,
    0x2cc784ed,0x26e6b695,0xb87dd11e,0x3ba24ffe,0x25ffb12e,0x3f60deda,
    0x37bb623f,0x45db1162,0x263fd548,0x2a0001ee,0x003eab94,0x2a598f00,
    0x00f2e5b4,0x00000140,0x00000000,0x00000000,0x00000000,0x00000000,
    0x00000000,0x00000000,0xbb300000,0x0eeecc7b,0x30c9660c,0x24c36e3b,
    0x221d8a4c,0xb1cc1cc0,0x6eecce61,0x269bbb32,0x376a1ddd,0x05bbb33d,
    0x36257079,0x5398f6e0,0x36a1f33b,0x3b7a26b9,0x543a7f50,0x16a1fd4f,
    0xda8fa36a,0xb50d2a4d,0x3b54a87c,0x42676a13,0x310fb9da,0x2676a5f5,
    0x7cc3fcc7,0x3636a4c8,0x2abaab52,0x4d71b50f,0x3faa794c,0xb1db50e8,
    0x3aa16a1f,0x50e7d45e,0x5df54999,0x2baa950f,0x54aefaa2,0x547d07a5,
    0x6de45cbe,0xd106ec82,0x7ef556a3,0xb877bea1,0x32f2a594,0xf77d950e,
    0x33ea16a1,0xa9ee620f,0x7ddf547f,0x2efaa950,0x2a377d50,0x545d8ba5,
    0x2be0ecbe,0x3605f05c,0x5cad56a2,0x2f74416a,0x6543fa95,0x0b50f9fc,
    0xde9972b5,0x5a8f36a4,0x85aa543e,0x1f15a85a,0x2e96a1ae,0xd01f99d5,
    0x2ab51203,0x002d4ba5,0xca87cd2a,0x3fea1f7a,0x0fe2b54f,0x2a1f1950,
    0x5aa543e5,0xf57fffa8,0x7fff45df,0x6cbfff55,0x407a0f22,0x00002d47,
    0x00000000,0x00000000,0x00000000,0xb1c80000,0x87200ae7,0x3b906c0d,
    0x6665c570,0x08446910,0x42208622,0x04cc4308,0x888888b1,0x21022221,
    0x98209998,0x05dc5c46,0x0f5be2f2,0xd34b8726,0x9ca87f44,0x7531fcc6,
    0x6b9db4cd,0x2592f54f,0x5cb7d50f,0x15d534fd,0x4bb7f3ae,0x2d10fcea,
    0x4951eeeb,0x22fee2ed,0x95950ceb,0x16f4cf1f,0xd131e5e2,0x1e6c6981,
    0x32ad106c,0x316a5aed,0x40fd8b5b,0x39fb70ea,0xaa5c7d2e,0x777305b5,
    0x34744e21,0x47f26555,0x26cd9de8,0xeae80beb,0x87e20e81,0x22cc4bbb,
    0x5d7dd158,0x20f74254,0x103aa2fe,0x951f4b8d,0x2a116d2a,0x84411bbb,
    0xff05d701,0x3f7113ea,0x21d06eb8,0x7ff6c1e8,0xce8e0ae1,0x2e12a0f9,
    0xe874e646,0x52e046ff,0x36954a8f,0x80000d12,0x17c57600,0xd03f8810,
    0x2e1fff21,0x01a20ec3,0x00000000,0x00000000,0x00000000,0x57000000,
    0x11d472ea,0x2ae21111,0x00e5c218,0x00000000,0x00000000,0x5c000000,
    0x90c5b973,0x36ee3999,0x06ea951e,0x00000000,0x00000000,0x20000000,
    0x00111108,0x00000000,0x00000000,0x00000000,0x00000000,0x00000000,
    0x00000000,
};

static signed short stb__arial_bold_9_usascii_x[95]={ 0,0,0,0,0,0,0,0,0,0,0,0,0,0,
0,-1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,0,0,-1,0,0,-1,0,0,-1,0,0,-1,0,0,0,0,0,0,0,0,0,0,
-1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0, };
static signed short stb__arial_bold_9_usascii_y[95]={ 7,1,1,1,0,1,1,1,1,1,1,2,5,4,
5,1,1,1,1,1,1,1,1,1,1,1,2,2,1,2,1,1,1,1,1,1,1,1,1,1,1,1,1,1,
1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,7,1,2,1,2,1,2,1,2,1,1,
1,1,1,2,2,2,2,2,2,2,1,2,2,2,2,2,2,1,1,1,3, };
static unsigned short stb__arial_bold_9_usascii_w[95]={ 0,2,4,5,5,7,6,2,3,3,3,5,2,3,
2,4,5,4,5,5,5,5,5,5,5,5,2,2,5,5,5,5,8,6,6,6,6,5,5,6,6,2,4,6,
5,7,6,6,6,7,6,5,5,6,7,8,6,7,5,3,4,3,5,6,2,5,5,5,5,5,3,5,5,2,
3,5,2,7,5,5,5,5,4,5,3,5,5,7,5,5,4,3,2,3,5, };
static unsigned short stb__arial_bold_9_usascii_h[95]={ 0,6,3,7,8,7,7,3,8,8,3,5,4,2,
2,7,7,6,6,7,6,7,7,6,7,7,5,7,6,4,6,6,8,6,6,7,6,6,6,7,6,6,7,6,
6,6,6,7,6,7,6,7,6,7,6,6,6,6,6,8,7,8,4,2,2,6,7,6,7,6,6,7,6,6,
8,6,6,5,5,6,7,7,5,6,7,6,5,5,5,7,5,8,8,8,2, };
static unsigned short stb__arial_bold_9_usascii_s[95]={ 127,53,59,81,1,87,46,56,43,26,124,
86,115,83,80,53,58,30,35,95,41,7,114,47,101,72,106,64,16,109,1,
118,30,103,96,107,83,77,71,120,61,124,67,42,36,28,21,57,8,13,1,
27,112,39,22,7,93,110,90,39,76,18,118,67,64,84,33,100,21,106,118,
1,122,90,22,55,68,92,100,15,70,64,64,49,47,78,69,56,75,51,81,
14,11,7,74, };
static unsigned short stb__arial_bold_9_usascii_t[95]={ 1,25,31,1,1,1,10,31,1,1,25,
25,25,31,31,10,10,25,25,1,25,10,1,25,1,10,25,10,25,25,25,
18,1,18,18,1,18,18,18,1,18,18,10,18,18,18,18,1,18,10,18,
10,10,10,25,25,10,18,18,1,1,1,25,31,31,10,10,10,10,10,10,
10,10,10,1,18,18,25,25,18,1,1,25,18,1,10,25,25,25,1,25,
1,1,1,31, };
static unsigned short stb__arial_bold_9_usascii_a[95]={ 36,43,61,72,72,115,93,31,
43,43,50,75,36,43,36,36,72,72,72,72,72,72,72,72,
72,72,43,43,75,75,75,79,126,93,93,93,93,86,79,100,
93,36,72,93,79,107,93,100,86,100,93,86,79,93,86,122,
86,86,79,43,36,43,75,72,43,72,79,72,79,72,43,79,
79,36,36,72,36,115,79,79,79,79,50,72,43,79,72,100,
72,72,64,50,36,50,75, };

// Call this function with
//    font: NULL or array length
//    data: NULL or specified size
//    height: STB_FONT_arial_bold_9_usascii_BITMAP_HEIGHT or STB_FONT_arial_bold_9_usascii_BITMAP_HEIGHT_POW2
//    return value: spacing between lines
static void stb_font_arial_bold_9_usascii(stb_fontchar font[STB_FONT_arial_bold_9_usascii_NUM_CHARS],
                unsigned char data[STB_FONT_arial_bold_9_usascii_BITMAP_HEIGHT][STB_FONT_arial_bold_9_usascii_BITMAP_WIDTH],
                int height)
{
    int i,j;
    if (data != 0) {
        unsigned int *bits = stb__arial_bold_9_usascii_pixels;
        unsigned int bitpack = *bits++, numbits = 32;
        for (i=0; i < STB_FONT_arial_bold_9_usascii_BITMAP_WIDTH*height; ++i)
            data[0][i] = 0;  // zero entire bitmap
        for (j=1; j < STB_FONT_arial_bold_9_usascii_BITMAP_HEIGHT-1; ++j) {
            for (i=1; i < STB_FONT_arial_bold_9_usascii_BITMAP_WIDTH-1; ++i) {
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
        float recip_width = 1.0f / STB_FONT_arial_bold_9_usascii_BITMAP_WIDTH;
        float recip_height = 1.0f / height;
        for (i=0; i < STB_FONT_arial_bold_9_usascii_NUM_CHARS; ++i) {
            // pad characters so they bilerp from empty space around each character
            font[i].s0 = (stb__arial_bold_9_usascii_s[i]) * recip_width;
            font[i].t0 = (stb__arial_bold_9_usascii_t[i]) * recip_height;
            font[i].s1 = (stb__arial_bold_9_usascii_s[i] + stb__arial_bold_9_usascii_w[i]) * recip_width;
            font[i].t1 = (stb__arial_bold_9_usascii_t[i] + stb__arial_bold_9_usascii_h[i]) * recip_height;
            font[i].x0 = stb__arial_bold_9_usascii_x[i];
            font[i].y0 = stb__arial_bold_9_usascii_y[i];
            font[i].x1 = stb__arial_bold_9_usascii_x[i] + stb__arial_bold_9_usascii_w[i];
            font[i].y1 = stb__arial_bold_9_usascii_y[i] + stb__arial_bold_9_usascii_h[i];
            font[i].advance_int = (stb__arial_bold_9_usascii_a[i]+8)>>4;
            font[i].s0f = (stb__arial_bold_9_usascii_s[i] - 0.5f) * recip_width;
            font[i].t0f = (stb__arial_bold_9_usascii_t[i] - 0.5f) * recip_height;
            font[i].s1f = (stb__arial_bold_9_usascii_s[i] + stb__arial_bold_9_usascii_w[i] + 0.5f) * recip_width;
            font[i].t1f = (stb__arial_bold_9_usascii_t[i] + stb__arial_bold_9_usascii_h[i] + 0.5f) * recip_height;
            font[i].x0f = stb__arial_bold_9_usascii_x[i] - 0.5f;
            font[i].y0f = stb__arial_bold_9_usascii_y[i] - 0.5f;
            font[i].x1f = stb__arial_bold_9_usascii_x[i] + stb__arial_bold_9_usascii_w[i] + 0.5f;
            font[i].y1f = stb__arial_bold_9_usascii_y[i] + stb__arial_bold_9_usascii_h[i] + 0.5f;
            font[i].advance = stb__arial_bold_9_usascii_a[i]/16.0f;
        }
    }
}

#ifndef STB_SOMEFONT_CREATE
#define STB_SOMEFONT_CREATE              stb_font_arial_bold_9_usascii
#define STB_SOMEFONT_BITMAP_WIDTH        STB_FONT_arial_bold_9_usascii_BITMAP_WIDTH
#define STB_SOMEFONT_BITMAP_HEIGHT       STB_FONT_arial_bold_9_usascii_BITMAP_HEIGHT
#define STB_SOMEFONT_BITMAP_HEIGHT_POW2  STB_FONT_arial_bold_9_usascii_BITMAP_HEIGHT_POW2
#define STB_SOMEFONT_FIRST_CHAR          STB_FONT_arial_bold_9_usascii_FIRST_CHAR
#define STB_SOMEFONT_NUM_CHARS           STB_FONT_arial_bold_9_usascii_NUM_CHARS
#define STB_SOMEFONT_LINE_SPACING        STB_FONT_arial_bold_9_usascii_LINE_SPACING
#endif

