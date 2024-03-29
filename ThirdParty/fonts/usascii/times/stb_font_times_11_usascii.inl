// Font generated by stb_font_inl_generator.c (4/1 bpp)
//
// Following instructions show how to use the only included font, whatever it is, in
// a generic way so you can replace it with any other font by changing the include.
// To use multiple fonts, replace STB_SOMEFONT_* below with STB_FONT_times_11_usascii_*,
// and separately install each font. Note that the CREATE function call has a
// totally different name; it's just 'stb_font_times_11_usascii'.
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

#define STB_FONT_times_11_usascii_BITMAP_WIDTH         128
#define STB_FONT_times_11_usascii_BITMAP_HEIGHT         44
#define STB_FONT_times_11_usascii_BITMAP_HEIGHT_POW2    64

#define STB_FONT_times_11_usascii_FIRST_CHAR            32
#define STB_FONT_times_11_usascii_NUM_CHARS             95

#define STB_FONT_times_11_usascii_LINE_SPACING           7

static unsigned int stb__times_11_usascii_pixels[]={
    0x06666224,0x40c41106,0xa9800260,0x2b996441,0x55306253,0x4cc15510,
    0x46310e2a,0x303141a8,0x20353033,0x305101ca,0x83826388,0x21dcc382,
    0x21c4b10d,0xd866b139,0x1c9c4b10,0x0747676a,0x966e1313,0x05ce2142,
    0x226881d6,0x432998e2,0x40c82649,0x33532984,0x22591621,0x47191cc3,
    0x91b96458,0x4b3a9cc3,0x9192caca,0x74431066,0x19aae848,0xb8c5a268,
    0x31c433a8,0x220e61c1,0x43b85b35,0x2398715a,0x950ee2d8,0x2730e4ae,
    0x4452892a,0xa850652a,0x1ca6c41f,0x2732ac68,0x1318831c,0x9a057026,
    0x7716e0ea,0x458730e2,0xce89dc5a,0x28e7661d,0x4a0b2b2a,0x9b88a49b,
    0x73f1910e,0x4dcab1a0,0x04c70568,0x44882a87,0x1d8f10eb,0x41439871,
    0x30e406c6,0x30518807,0x26312d63,0x7d4ee352,0x33158b00,0x4c315919,
    0x260c8264,0x2a632983,0x886e72a2,0x80cb9cc3,0x5901aaa9,0x8986c254,
    0x126e2809,0x7d314dc5,0x2f619d77,0x83015242,0x38482648,0x077750b8,
    0x39871176,0x98660000,0x80808401,0x00100080,0x26a60d5c,0x1304c099,
    0x088620cc,0x8854c018,0x0007732d,0x00000000,0x00000000,0x00000000,
    0x00000000,0x00000000,0x00000000,0x00000000,0x00000000,0x00000000,
    0xaa800000,0x504ccc3a,0xc8182b87,0x05702661,0x1991032a,0x33320a88,
    0x305ddd41,0x2a615c39,0x5306622a,0x4750e543,0x711c98c9,0xea4490e4,
    0x88151f40,0x12911c81,0x8b331073,0x2a1d419a,0xa8b21b99,0x3882a3c1,
    0x3524e671,0x20541d1a,0x5a944766,0x2e16b304,0x4428152e,0x86e551d9,
    0x218819b9,0x202c42e8,0x8f021663,0xb843a60a,0x22c22552,0x64b20e4a,
    0x700ee153,0x51d15013,0x8ece2281,0x4e4c752c,0x710f621d,0x406d654b,
    0x42b88f23,0x8fee0547,0x81a85749,0x2eb30316,0xd1025456,0x5d328199,
    0x32370c41,0x398ee571,0x4320d075,0x21a8772b,0x51a1644a,0x554bb101,
    0x3ac80c0e,0x8ab667a0,0x26130468,0x141f5142,0x7398e4ee,0x381a9cc3,
    0x42a9c470,0x83907443,0x34130e0e,0x74402126,0x43556e02,0x32e1aada,
    0xc83660ab,0x7b7b10a0,0x27621d54,0xca866ea3,0x1c14dc1b,0x206cd64c,
    0x64c2aac9,0x260e62a9,0x38803603,0x00000812,0x00000008,0x10020000,
    0x02040080,0x00000000,0x00000000,0x00000000,0x00000000,0x24000000,
    0x3bbbba8a,0x986e2793,0x41d40bac,0x5440bbc9,0x3260750c,0x2c9864c0,
    0x41751c98,0x2eaae248,0x47263931,0xc98ae1ca,0x2ab264aa,0x463b500b,
    0x28b5433a,0x2441f168,0x4148d368,0xb90fa048,0x81cd00e8,0x1a344266,
    0x9a0e2d8d,0x11446341,0x2f207509,0x91074d03,0xe99e6855,0x20d5220a,
    0x0d12e26b,0x6c1603b4,0x2d11a341,0x4d026809,0xa8489a20,0x57407a03,
    0x06c6c42c,0x8858773d,0x72ba819c,0x37a06893,0x212e1601,0xcb87aaae,
    0xe8395d02,0x0912c4aa,0x416e6075,0x374883b6,0x9b10b034,0x26a3a2a0,
    0x1d3d0344,0x1a0d3160,0x02681e0d,0x1e89604d,0x3c9441d4,0x7488d168,
    0x910b0343,0x4d725059,0xd3686344,0x861e8b01,0x1a068346,0x00e88468,
    0x0d983722,0xa97cc5f3,0x25b1b51d,0x42e882f9,0x3662e8da,0x261d7388,
    0x3f32babf,0x70e88fee,0x3e67755b,0x1f983f31,0xaf881f98,0x000002ba,
    0x00000000,0x00000000,0x00000000,0x155e4c00,0xbac98b22,0x21c40a01,
    0x2380e542,0x9413000a,0x226a512a,0x0a02a20a,0x7155054c,0x40a98513,
    0xa854c0a8,0x1d06d4d0,0x3e20ee68,0x33146880,0xaa8b70d3,0x12815501,
    0x0c9cc26b,0x260a1251,0x865261b2,0x988e66a2,0x5c222a58,0x0363d8d1,
    0x1d54254d,0x998b0058,0x0ea19305,0x27314640,0x9550170c,0x1d46e155,
    0x2a606eeb,0xe8866ae4,0x96a342a2,0x075d740d,0x100b0694,0xa9858c47,
    0x26005541,0xa865261c,0x27505013,0x0b62ea2a,0x09d49137,0x2e340e42,
    0x2d4d0363,0x960b6ae6,0x5d5c2868,0x9801551e,0x5d0b160a,0x20b7625b,
    0x483ac882,0x0dada837,0x555c5bb1,0x1b074680,0x4471e268,0x02a14585,
    0x0001b533,0x04000000,0x00000000,0x43b75f30,0x2abe62e8,0x3f892a2c,
    0x3ae083a2,0x000581dd,0x00000000,0x00000000,0x00000000,0x00000000,
    0x00000000,0x80000000,0x70373aa9,0x2a629a98,0x21755309,0x2140a8b9,
    0x26b31aa8,0x40609999,0x244713ca,0x00033333,0x80000000,0x268ac8d9,
    0x1b30cbc8,0x8c27661b,0x2a14ec49,0x286ee60a,0x4cc11111,0x41110abb,
    0x02222202,0x00000000,0x2c6e9100,0x52217971,0x0b10911b,0x445288d1,
    0x2aa1109a,0x00000aaa,0x00000000,0x74880000,0x44191163,0x36122374,
    0x88a3ba81,0x00000000,0x00000000,0x6d400000,0x400e8bc8,0x1b52d8da,
    0x2a85d6dc,0x0000003d,0x00000000,0x00000000,0x00000000,0x00000000,
    0x00000000,0x00000000,
};

static signed short stb__times_11_usascii_x[95]={ 0,1,0,0,0,0,0,0,0,0,0,0,0,0,
0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
0,0,-1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,-1,0,0,-1,0,0,0,0,0,0,0,
-1,0,0,0,0,0,-1,0,0,0,0,0,0,0,0,0,0,1,0,0,0, };
static signed short stb__times_11_usascii_y[95]={ 8,1,1,1,0,1,1,1,1,1,1,2,7,5,
7,1,1,1,1,1,1,1,1,1,1,1,3,3,2,3,2,1,1,1,1,1,1,1,1,1,1,1,1,1,
1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,9,1,3,1,3,1,3,1,3,1,1,
1,1,1,3,3,3,3,3,3,3,2,3,3,3,3,3,3,1,1,1,4, };
static unsigned short stb__times_11_usascii_w[95]={ 0,2,4,5,5,8,8,2,4,3,5,6,2,3,
2,3,5,3,5,5,5,5,5,5,5,5,2,3,6,6,6,5,9,8,7,7,7,6,6,8,7,4,4,8,
6,9,9,7,6,7,7,5,6,8,8,10,8,8,6,3,3,3,5,7,3,5,6,5,5,5,5,5,5,3,
3,6,3,8,5,5,6,5,4,4,3,5,5,8,5,5,5,4,2,4,6, };
static unsigned short stb__times_11_usascii_h[95]={ 0,8,4,8,9,8,8,4,10,10,5,6,3,2,
2,8,8,7,7,8,7,8,8,8,8,8,6,7,6,3,6,8,10,7,7,8,7,7,7,8,7,7,8,7,
7,7,8,8,7,9,7,8,7,8,8,8,7,7,7,9,8,9,4,2,2,6,8,6,8,6,7,8,7,7,
10,7,7,5,5,6,8,8,5,6,7,6,6,6,5,8,5,10,10,10,3, };
static unsigned short stb__times_11_usascii_s[95]={ 59,86,45,89,37,95,114,125,28,33,10,
86,50,67,75,25,35,31,39,48,45,54,60,66,108,96,65,35,58,53,51,
102,5,22,14,1,1,120,113,72,96,9,123,76,69,59,15,65,39,43,25,
90,9,81,108,117,16,104,89,51,104,55,39,78,71,108,41,80,29,114,46,
9,33,1,1,52,85,1,16,93,79,73,22,120,5,74,68,99,33,59,27,
23,20,15,60, };
static unsigned short stb__times_11_usascii_t[95]={ 10,1,37,1,1,1,1,29,1,1,37,
29,37,37,37,12,12,29,29,12,29,12,12,12,1,12,29,29,29,37,29,
12,1,29,29,12,29,21,21,12,21,29,1,21,21,21,12,1,21,1,21,
12,21,12,12,12,21,21,21,1,1,1,37,37,37,29,12,29,12,29,21,
12,21,21,1,21,21,37,37,29,1,1,37,29,21,29,29,29,37,1,37,
1,1,1,37, };
static unsigned short stb__times_11_usascii_a[95]={ 40,53,65,79,79,132,124,29,
53,53,79,90,40,53,40,44,79,79,79,79,79,79,79,79,
79,79,44,44,90,90,90,71,146,115,106,106,115,97,88,115,
115,53,62,115,97,141,115,115,88,115,106,88,97,115,115,150,
115,115,97,53,44,53,75,79,53,71,79,71,79,71,53,79,
79,44,44,79,44,124,79,79,79,79,53,62,44,79,79,115,
79,79,71,76,32,76,86, };

// Call this function with
//    font: NULL or array length
//    data: NULL or specified size
//    height: STB_FONT_times_11_usascii_BITMAP_HEIGHT or STB_FONT_times_11_usascii_BITMAP_HEIGHT_POW2
//    return value: spacing between lines
static void stb_font_times_11_usascii(stb_fontchar font[STB_FONT_times_11_usascii_NUM_CHARS],
                unsigned char data[STB_FONT_times_11_usascii_BITMAP_HEIGHT][STB_FONT_times_11_usascii_BITMAP_WIDTH],
                int height)
{
    int i,j;
    if (data != 0) {
        unsigned int *bits = stb__times_11_usascii_pixels;
        unsigned int bitpack = *bits++, numbits = 32;
        for (i=0; i < STB_FONT_times_11_usascii_BITMAP_WIDTH*height; ++i)
            data[0][i] = 0;  // zero entire bitmap
        for (j=1; j < STB_FONT_times_11_usascii_BITMAP_HEIGHT-1; ++j) {
            for (i=1; i < STB_FONT_times_11_usascii_BITMAP_WIDTH-1; ++i) {
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
        float recip_width = 1.0f / STB_FONT_times_11_usascii_BITMAP_WIDTH;
        float recip_height = 1.0f / height;
        for (i=0; i < STB_FONT_times_11_usascii_NUM_CHARS; ++i) {
            // pad characters so they bilerp from empty space around each character
            font[i].s0 = (stb__times_11_usascii_s[i]) * recip_width;
            font[i].t0 = (stb__times_11_usascii_t[i]) * recip_height;
            font[i].s1 = (stb__times_11_usascii_s[i] + stb__times_11_usascii_w[i]) * recip_width;
            font[i].t1 = (stb__times_11_usascii_t[i] + stb__times_11_usascii_h[i]) * recip_height;
            font[i].x0 = stb__times_11_usascii_x[i];
            font[i].y0 = stb__times_11_usascii_y[i];
            font[i].x1 = stb__times_11_usascii_x[i] + stb__times_11_usascii_w[i];
            font[i].y1 = stb__times_11_usascii_y[i] + stb__times_11_usascii_h[i];
            font[i].advance_int = (stb__times_11_usascii_a[i]+8)>>4;
            font[i].s0f = (stb__times_11_usascii_s[i] - 0.5f) * recip_width;
            font[i].t0f = (stb__times_11_usascii_t[i] - 0.5f) * recip_height;
            font[i].s1f = (stb__times_11_usascii_s[i] + stb__times_11_usascii_w[i] + 0.5f) * recip_width;
            font[i].t1f = (stb__times_11_usascii_t[i] + stb__times_11_usascii_h[i] + 0.5f) * recip_height;
            font[i].x0f = stb__times_11_usascii_x[i] - 0.5f;
            font[i].y0f = stb__times_11_usascii_y[i] - 0.5f;
            font[i].x1f = stb__times_11_usascii_x[i] + stb__times_11_usascii_w[i] + 0.5f;
            font[i].y1f = stb__times_11_usascii_y[i] + stb__times_11_usascii_h[i] + 0.5f;
            font[i].advance = stb__times_11_usascii_a[i]/16.0f;
        }
    }
}

#ifndef STB_SOMEFONT_CREATE
#define STB_SOMEFONT_CREATE              stb_font_times_11_usascii
#define STB_SOMEFONT_BITMAP_WIDTH        STB_FONT_times_11_usascii_BITMAP_WIDTH
#define STB_SOMEFONT_BITMAP_HEIGHT       STB_FONT_times_11_usascii_BITMAP_HEIGHT
#define STB_SOMEFONT_BITMAP_HEIGHT_POW2  STB_FONT_times_11_usascii_BITMAP_HEIGHT_POW2
#define STB_SOMEFONT_FIRST_CHAR          STB_FONT_times_11_usascii_FIRST_CHAR
#define STB_SOMEFONT_NUM_CHARS           STB_FONT_times_11_usascii_NUM_CHARS
#define STB_SOMEFONT_LINE_SPACING        STB_FONT_times_11_usascii_LINE_SPACING
#endif

