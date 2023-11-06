// Font generated by stb_font_inl_generator.c (4/1 bpp)
//
// Following instructions show how to use the only included font, whatever it is, in
// a generic way so you can replace it with any other font by changing the include.
// To use multiple fonts, replace STB_SOMEFONT_* below with STB_FONT_courier_6_usascii_*,
// and separately install each font. Note that the CREATE function call has a
// totally different name; it's just 'stb_font_courier_6_usascii'.
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

#define STB_FONT_courier_6_usascii_BITMAP_WIDTH         128
#define STB_FONT_courier_6_usascii_BITMAP_HEIGHT         18
#define STB_FONT_courier_6_usascii_BITMAP_HEIGHT_POW2    32

#define STB_FONT_courier_6_usascii_FIRST_CHAR            32
#define STB_FONT_courier_6_usascii_NUM_CHARS             95

#define STB_FONT_courier_6_usascii_LINE_SPACING           3

static unsigned int stb__courier_6_usascii_pixels[]={
    0x86081010,0x10040860,0x40008013,0x00410200,0x40818022,0x08026020,
    0x426620c0,0x842a0420,0x08621088,0x22102a23,0x18886330,0x23110886,
    0x2228a230,0x183310c2,0x82230822,0x2308c440,0x4c331289,0x44308630,
    0x1084c10b,0x4086a213,0x08844308,0x8630c303,0x30418429,0x23104213,
    0x3184c451,0x842110c4,0x9a8a2610,0x14084109,0x11042621,0x82098222,
    0x33318261,0x30ccc10c,0x02263083,0x4c466233,0x844c5130,0x2613118a,
    0x26213118,0x10820200,0x00608608,0x40100800,0x01880010,0x30006a00,
    0x00000000,0x00000000,0x00000000,0x00000000,0x42600000,0x04418220,
    0x01000011,0x08080220,0x08000004,0x00026200,0x26200084,0x19984630,
    0x13146151,0x8528a2a5,0x28c6a618,0x060c4133,0x45294541,0x318a2628,
    0x18c4c2a2,0x8ccc6663,0x4cc21199,0x51898510,0x10444222,0xa88a14c4,
    0x10502221,0x20a98c44,0x98820431,0x26083510,0x4c10c442,0x8a231319,
    0x29884219,0x00662333,0x4502a200,0x28513289,0x982a0cc4,0x128c3131,
    0x44c2a215,0x32a88a52,0x98544031,0x30cc1528,0x4c066633,0x0000a519,
    0x00000000,0x00000000,0x00000000,0x18000000,0x04001843,0x02608306,
    0x44221841,0x1310c608,0x4410404c,0x01383108,0x51099894,0x40002623,
    0x44131289,0x4c466618,0x21098311,0x31098261,0x954c2621,0x110c2099,
    0x44e330a1,0x22318a0a,0x0015d410,0x22280000,0x30604c19,0x44351043,
    0x80263310,0x83330299,0x2130d442,0x15104108,0x000000c6,0x802a0000,
    0x188ccc28,0x04cc02a2,0x00000031,0x00000000,0x00000000,0x00000000,
    0x00000000,0x00000000,0x00000000,
};

static signed short stb__courier_6_usascii_x[95]={ 0,1,0,0,0,0,0,1,1,0,0,0,0,0,
1,0,0,0,0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,0, };
static signed short stb__courier_6_usascii_y[95]={ 4,0,0,0,0,0,1,0,0,0,0,1,3,2,
3,0,0,0,0,0,0,0,0,0,0,0,1,1,1,1,1,0,0,0,0,0,0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,5,0,1,0,1,0,1,0,1,0,0,
0,0,0,1,1,1,1,1,1,1,0,1,1,1,1,1,1,0,0,0,2, };
static unsigned short stb__courier_6_usascii_w[95]={ 0,1,3,3,3,3,3,1,2,2,2,3,2,3,
1,3,3,3,3,3,3,3,3,3,3,3,1,2,3,3,3,2,3,4,3,3,3,3,3,3,3,3,4,4,
3,4,3,3,3,3,4,3,3,3,4,4,3,3,3,1,2,1,3,4,2,3,3,3,4,3,3,3,3,3,
3,4,3,4,3,3,3,4,3,3,3,3,4,4,3,4,3,2,1,2,3, };
static unsigned short stb__courier_6_usascii_h[95]={ 0,5,3,5,5,5,4,3,5,5,3,3,2,1,
2,5,5,4,4,5,4,5,5,5,5,5,4,4,3,2,3,5,5,4,4,5,4,4,4,5,4,4,5,4,
4,4,4,5,4,5,4,5,4,5,4,4,4,4,4,5,5,5,3,1,2,4,5,4,5,4,4,4,4,4,
5,4,4,3,3,4,4,4,3,4,5,4,3,4,3,4,3,5,5,5,1, };
static unsigned short stb__courier_6_usascii_s[95]={ 127,73,51,13,19,25,27,76,41,54,73,
78,90,107,100,57,113,23,31,88,35,105,80,37,29,65,125,125,69,96,39,
44,97,116,112,50,104,100,96,61,88,84,75,75,71,66,62,1,19,84,45,
109,37,117,27,22,18,1,15,23,47,17,43,102,93,121,101,1,92,5,9,
41,50,54,69,32,58,55,86,80,92,13,82,121,33,108,60,5,47,10,65,
10,8,5,111, };
static unsigned short stb__courier_6_usascii_t[95]={ 6,1,12,1,1,1,12,12,1,1,12,
12,12,12,12,1,1,12,12,1,12,1,1,1,1,1,6,1,12,12,12,
1,1,7,7,1,7,7,7,1,7,7,1,7,7,7,7,1,12,1,7,
1,7,1,7,7,7,12,12,1,1,1,12,12,12,1,1,7,1,7,7,
7,7,7,1,7,7,12,12,7,7,7,12,6,1,7,12,12,12,12,12,
1,1,1,12, };
static unsigned short stb__courier_6_usascii_a[95]={ 51,51,51,51,51,51,51,51,
51,51,51,51,51,51,51,51,51,51,51,51,51,51,51,51,
51,51,51,51,51,51,51,51,51,51,51,51,51,51,51,51,
51,51,51,51,51,51,51,51,51,51,51,51,51,51,51,51,
51,51,51,51,51,51,51,51,51,51,51,51,51,51,51,51,
51,51,51,51,51,51,51,51,51,51,51,51,51,51,51,51,
51,51,51,51,51,51,51, };

// Call this function with
//    font: NULL or array length
//    data: NULL or specified size
//    height: STB_FONT_courier_6_usascii_BITMAP_HEIGHT or STB_FONT_courier_6_usascii_BITMAP_HEIGHT_POW2
//    return value: spacing between lines
static void stb_font_courier_6_usascii(stb_fontchar font[STB_FONT_courier_6_usascii_NUM_CHARS],
                unsigned char data[STB_FONT_courier_6_usascii_BITMAP_HEIGHT][STB_FONT_courier_6_usascii_BITMAP_WIDTH],
                int height)
{
    int i,j;
    if (data != 0) {
        unsigned int *bits = stb__courier_6_usascii_pixels;
        unsigned int bitpack = *bits++, numbits = 32;
        for (i=0; i < STB_FONT_courier_6_usascii_BITMAP_WIDTH*height; ++i)
            data[0][i] = 0;  // zero entire bitmap
        for (j=1; j < STB_FONT_courier_6_usascii_BITMAP_HEIGHT-1; ++j) {
            for (i=1; i < STB_FONT_courier_6_usascii_BITMAP_WIDTH-1; ++i) {
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
        float recip_width = 1.0f / STB_FONT_courier_6_usascii_BITMAP_WIDTH;
        float recip_height = 1.0f / height;
        for (i=0; i < STB_FONT_courier_6_usascii_NUM_CHARS; ++i) {
            // pad characters so they bilerp from empty space around each character
            font[i].s0 = (stb__courier_6_usascii_s[i]) * recip_width;
            font[i].t0 = (stb__courier_6_usascii_t[i]) * recip_height;
            font[i].s1 = (stb__courier_6_usascii_s[i] + stb__courier_6_usascii_w[i]) * recip_width;
            font[i].t1 = (stb__courier_6_usascii_t[i] + stb__courier_6_usascii_h[i]) * recip_height;
            font[i].x0 = stb__courier_6_usascii_x[i];
            font[i].y0 = stb__courier_6_usascii_y[i];
            font[i].x1 = stb__courier_6_usascii_x[i] + stb__courier_6_usascii_w[i];
            font[i].y1 = stb__courier_6_usascii_y[i] + stb__courier_6_usascii_h[i];
            font[i].advance_int = (stb__courier_6_usascii_a[i]+8)>>4;
            font[i].s0f = (stb__courier_6_usascii_s[i] - 0.5f) * recip_width;
            font[i].t0f = (stb__courier_6_usascii_t[i] - 0.5f) * recip_height;
            font[i].s1f = (stb__courier_6_usascii_s[i] + stb__courier_6_usascii_w[i] + 0.5f) * recip_width;
            font[i].t1f = (stb__courier_6_usascii_t[i] + stb__courier_6_usascii_h[i] + 0.5f) * recip_height;
            font[i].x0f = stb__courier_6_usascii_x[i] - 0.5f;
            font[i].y0f = stb__courier_6_usascii_y[i] - 0.5f;
            font[i].x1f = stb__courier_6_usascii_x[i] + stb__courier_6_usascii_w[i] + 0.5f;
            font[i].y1f = stb__courier_6_usascii_y[i] + stb__courier_6_usascii_h[i] + 0.5f;
            font[i].advance = stb__courier_6_usascii_a[i]/16.0f;
        }
    }
}

#ifndef STB_SOMEFONT_CREATE
#define STB_SOMEFONT_CREATE              stb_font_courier_6_usascii
#define STB_SOMEFONT_BITMAP_WIDTH        STB_FONT_courier_6_usascii_BITMAP_WIDTH
#define STB_SOMEFONT_BITMAP_HEIGHT       STB_FONT_courier_6_usascii_BITMAP_HEIGHT
#define STB_SOMEFONT_BITMAP_HEIGHT_POW2  STB_FONT_courier_6_usascii_BITMAP_HEIGHT_POW2
#define STB_SOMEFONT_FIRST_CHAR          STB_FONT_courier_6_usascii_FIRST_CHAR
#define STB_SOMEFONT_NUM_CHARS           STB_FONT_courier_6_usascii_NUM_CHARS
#define STB_SOMEFONT_LINE_SPACING        STB_FONT_courier_6_usascii_LINE_SPACING
#endif

