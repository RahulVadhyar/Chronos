// Font generated by stb_font_inl_generator.c (4/1 bpp)
//
// Following instructions show how to use the only included font, whatever it is, in
// a generic way so you can replace it with any other font by changing the include.
// To use multiple fonts, replace STB_SOMEFONT_* below with STB_FONT_courier_7_usascii_*,
// and separately install each font. Note that the CREATE function call has a
// totally different name; it's just 'stb_font_courier_7_usascii'.
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

#define STB_FONT_courier_7_usascii_BITMAP_WIDTH         128
#define STB_FONT_courier_7_usascii_BITMAP_HEIGHT         24
#define STB_FONT_courier_7_usascii_BITMAP_HEIGHT_POW2    32

#define STB_FONT_courier_7_usascii_FIRST_CHAR            32
#define STB_FONT_courier_7_usascii_NUM_CHARS             95

#define STB_FONT_courier_7_usascii_LINE_SPACING           3

static unsigned int stb__courier_7_usascii_pixels[]={
    0x21100000,0x10462261,0x51010262,0x30998861,0x884c4c33,0x20cc0880,
    0x22988c19,0x4c266219,0x22860cc1,0x30d41982,0x83198860,0x86318619,
    0x18a181b8,0x10463143,0x04441831,0x50c18223,0x984428c1,0x30c33128,
    0x3061dc33,0x304c6060,0x20c63143,0x98821841,0x41186662,0x22054198,
    0x18311861,0x214c4351,0x218ca661,0x82b898a1,0x18c060c2,0x5331860c,
    0x986661a8,0x98818440,0x47310c41,0x30662199,0x45035044,0x4cc22218,
    0x30cd431a,0x3060d443,0x40886310,0x40000020,0x00001108,0x00c13500,
    0x80260020,0x40204402,0x00002010,0x00000000,0x00000000,0x00000000,
    0x00000000,0x00000000,0x00000000,0x2a000000,0x198350c1,0x0998330a,
    0x46198266,0x26131308,0x44266188,0x30cc0619,0x886a2131,0x1284c629,
    0x13130a23,0x888a60c6,0x184a0541,0x14c41144,0x44421843,0x43306661,
    0x33031899,0x5310cc45,0x2118c198,0x99982661,0x84311061,0x20610cc1,
    0x43031941,0x1318a620,0xa8854c06,0x15330d43,0x0cc42662,0x20a99861,
    0x260c1a81,0x18626618,0xb9886621,0x14c45330,0x33128331,0x4c410cc4,
    0x4c426661,0x1300a609,0x000a6615,0x37002a26,0x455305c4,0x4a22a28a,
    0x131519b8,0x00a89800,0x000a000c,0x00000000,0x00000000,0x00000000,
    0x00000000,0x00000000,0x00000000,0x40000000,0x1351188a,0x41988666,
    0x44333098,0x10cc0c0a,0x30409a98,0x10ccc261,0x41a88503,0x2310cc40,
    0x26260828,0x4cd43110,0x20c63330,0x20821089,0x983086e1,0x88446141,
    0x4c423109,0x20c20820,0x0c0c0c29,0x54186618,0x4350620b,0x330c2319,
    0x082621a8,0x84cc4186,0x2620c2a8,0x0a830c41,0x0a621524,0x44181817,
    0x2a884c1a,0x21981106,0x51350a99,0x104c2a26,0x53099a87,0x9a86e213,
    0x22331509,0x2e04c01b,0x2a030c41,0x21531188,0x106e21b8,0x44a21a98,
    0x0000001b,0x00000000,0x00000000,0x00000000,0x40000000,0x45310998,
    0x8920150a,0xa8826099,0x21331023,0x000002a8,0x00000000,0x05000000,
    0x20881411,0x44426622,0x01889541,0x00000000,0x00000000,0x86e20000,
    0x000002b8,0x00000000,0x00000000,0x00000000,0x00000000,0x00000000,
    0x00000000,0x00000000,
};

static signed short stb__courier_7_usascii_x[95]={ 0,1,0,0,0,0,0,1,1,0,0,0,0,0,
1,0,0,0,0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,0, };
static signed short stb__courier_7_usascii_y[95]={ 5,1,1,0,0,1,1,1,1,1,1,1,4,3,
4,0,1,1,1,1,1,1,1,1,1,1,2,2,1,2,1,1,1,1,1,1,1,1,1,1,1,1,1,1,
1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,0,1,1,6,0,2,1,2,1,2,1,2,1,1,
1,1,1,2,2,2,2,2,2,2,1,2,2,2,2,2,2,1,1,1,2, };
static unsigned short stb__courier_7_usascii_w[95]={ 0,2,3,4,4,4,4,2,2,2,3,4,3,4,
2,4,4,4,3,4,3,4,4,3,4,4,2,3,3,4,3,3,3,4,4,4,4,4,4,4,4,4,4,4,
4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,2,3,2,4,4,2,4,4,4,4,4,4,4,4,4,
3,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,2,1,2,4, };
static unsigned short stb__courier_7_usascii_h[95]={ 0,5,2,6,6,5,5,3,5,5,3,4,2,1,
2,6,5,4,4,5,4,5,5,5,5,5,4,4,4,2,4,5,5,4,4,5,4,4,4,5,4,4,5,4,
4,4,4,5,4,5,4,5,4,5,4,4,4,4,4,5,6,5,2,1,2,4,5,4,5,4,4,5,4,4,
6,4,4,3,3,4,5,5,3,4,5,4,3,4,3,5,3,5,5,5,2, };
static unsigned short stb__courier_7_usascii_s[95]={ 24,52,34,1,6,70,75,11,90,6,104,
86,20,48,14,15,9,99,91,14,95,1,97,93,22,37,63,59,55,24,46,
107,111,31,26,32,16,11,6,27,122,81,47,107,102,97,92,37,82,85,66,
80,50,65,1,52,47,77,87,120,11,19,29,43,17,72,123,57,115,62,21,
102,67,36,20,71,76,118,123,41,60,55,1,117,42,112,108,42,113,27,6,
32,35,24,38, };
static unsigned short stb__courier_7_usascii_t[95]={ 7,1,19,1,1,1,1,19,1,8,14,
14,19,19,19,1,8,14,14,8,14,8,1,1,8,8,14,14,14,19,14,
1,1,14,14,8,14,14,14,8,8,14,1,8,8,8,8,1,8,1,14,
1,14,1,14,8,8,8,8,1,1,8,19,19,19,8,1,8,1,8,14,
1,8,14,1,14,14,14,14,14,1,1,19,8,1,8,14,8,14,1,19,
1,1,1,19, };
static unsigned short stb__courier_7_usascii_a[95]={ 59,59,59,59,59,59,59,59,
59,59,59,59,59,59,59,59,59,59,59,59,59,59,59,59,
59,59,59,59,59,59,59,59,59,59,59,59,59,59,59,59,
59,59,59,59,59,59,59,59,59,59,59,59,59,59,59,59,
59,59,59,59,59,59,59,59,59,59,59,59,59,59,59,59,
59,59,59,59,59,59,59,59,59,59,59,59,59,59,59,59,
59,59,59,59,59,59,59, };

// Call this function with
//    font: NULL or array length
//    data: NULL or specified size
//    height: STB_FONT_courier_7_usascii_BITMAP_HEIGHT or STB_FONT_courier_7_usascii_BITMAP_HEIGHT_POW2
//    return value: spacing between lines
static void stb_font_courier_7_usascii(stb_fontchar font[STB_FONT_courier_7_usascii_NUM_CHARS],
                unsigned char data[STB_FONT_courier_7_usascii_BITMAP_HEIGHT][STB_FONT_courier_7_usascii_BITMAP_WIDTH],
                int height)
{
    int i,j;
    if (data != 0) {
        unsigned int *bits = stb__courier_7_usascii_pixels;
        unsigned int bitpack = *bits++, numbits = 32;
        for (i=0; i < STB_FONT_courier_7_usascii_BITMAP_WIDTH*height; ++i)
            data[0][i] = 0;  // zero entire bitmap
        for (j=1; j < STB_FONT_courier_7_usascii_BITMAP_HEIGHT-1; ++j) {
            for (i=1; i < STB_FONT_courier_7_usascii_BITMAP_WIDTH-1; ++i) {
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
        float recip_width = 1.0f / STB_FONT_courier_7_usascii_BITMAP_WIDTH;
        float recip_height = 1.0f / height;
        for (i=0; i < STB_FONT_courier_7_usascii_NUM_CHARS; ++i) {
            // pad characters so they bilerp from empty space around each character
            font[i].s0 = (stb__courier_7_usascii_s[i]) * recip_width;
            font[i].t0 = (stb__courier_7_usascii_t[i]) * recip_height;
            font[i].s1 = (stb__courier_7_usascii_s[i] + stb__courier_7_usascii_w[i]) * recip_width;
            font[i].t1 = (stb__courier_7_usascii_t[i] + stb__courier_7_usascii_h[i]) * recip_height;
            font[i].x0 = stb__courier_7_usascii_x[i];
            font[i].y0 = stb__courier_7_usascii_y[i];
            font[i].x1 = stb__courier_7_usascii_x[i] + stb__courier_7_usascii_w[i];
            font[i].y1 = stb__courier_7_usascii_y[i] + stb__courier_7_usascii_h[i];
            font[i].advance_int = (stb__courier_7_usascii_a[i]+8)>>4;
            font[i].s0f = (stb__courier_7_usascii_s[i] - 0.5f) * recip_width;
            font[i].t0f = (stb__courier_7_usascii_t[i] - 0.5f) * recip_height;
            font[i].s1f = (stb__courier_7_usascii_s[i] + stb__courier_7_usascii_w[i] + 0.5f) * recip_width;
            font[i].t1f = (stb__courier_7_usascii_t[i] + stb__courier_7_usascii_h[i] + 0.5f) * recip_height;
            font[i].x0f = stb__courier_7_usascii_x[i] - 0.5f;
            font[i].y0f = stb__courier_7_usascii_y[i] - 0.5f;
            font[i].x1f = stb__courier_7_usascii_x[i] + stb__courier_7_usascii_w[i] + 0.5f;
            font[i].y1f = stb__courier_7_usascii_y[i] + stb__courier_7_usascii_h[i] + 0.5f;
            font[i].advance = stb__courier_7_usascii_a[i]/16.0f;
        }
    }
}

#ifndef STB_SOMEFONT_CREATE
#define STB_SOMEFONT_CREATE              stb_font_courier_7_usascii
#define STB_SOMEFONT_BITMAP_WIDTH        STB_FONT_courier_7_usascii_BITMAP_WIDTH
#define STB_SOMEFONT_BITMAP_HEIGHT       STB_FONT_courier_7_usascii_BITMAP_HEIGHT
#define STB_SOMEFONT_BITMAP_HEIGHT_POW2  STB_FONT_courier_7_usascii_BITMAP_HEIGHT_POW2
#define STB_SOMEFONT_FIRST_CHAR          STB_FONT_courier_7_usascii_FIRST_CHAR
#define STB_SOMEFONT_NUM_CHARS           STB_FONT_courier_7_usascii_NUM_CHARS
#define STB_SOMEFONT_LINE_SPACING        STB_FONT_courier_7_usascii_LINE_SPACING
#endif

