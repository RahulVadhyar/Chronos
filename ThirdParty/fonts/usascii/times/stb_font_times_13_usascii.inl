// Font generated by stb_font_inl_generator.c (4/1 bpp)
//
// Following instructions show how to use the only included font, whatever it is, in
// a generic way so you can replace it with any other font by changing the include.
// To use multiple fonts, replace STB_SOMEFONT_* below with STB_FONT_times_13_usascii_*,
// and separately install each font. Note that the CREATE function call has a
// totally different name; it's just 'stb_font_times_13_usascii'.
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

#define STB_FONT_times_13_usascii_BITMAP_WIDTH         128
#define STB_FONT_times_13_usascii_BITMAP_HEIGHT         56
#define STB_FONT_times_13_usascii_BITMAP_HEIGHT_POW2    64

#define STB_FONT_times_13_usascii_FIRST_CHAR            32
#define STB_FONT_times_13_usascii_NUM_CHARS             95

#define STB_FONT_times_13_usascii_LINE_SPACING           8

static unsigned int stb__times_13_usascii_pixels[]={
    0x00800000,0x0aaa6000,0x01cf9b2a,0x80010101,0x02213300,0x06a20513,
    0x4cd40020,0x260cc199,0x22054281,0x447706c0,0xf3034d06,0x80e3bca8,
    0x3cc1aa0a,0x365f5c17,0x0e89e66e,0x202e01aa,0x21205418,0x00331222,
    0x2682c81f,0x25913c06,0x344380a3,0x4d10e5b0,0x3a3c731e,0x982e0340,
    0x0e8b0529,0x3058b314,0x216a1aa1,0x33ccc1a6,0x8828827d,0xd981b442,
    0x25934428,0x681b1e3b,0x23238131,0x2c1d0559,0x42c49114,0xd50d70e8,
    0x4c6434d0,0x41c0fdc7,0x36d7440a,0x4b3442ec,0x681b1e5a,0x25729855,
    0x4c3b053a,0x25415141,0xc81f30d8,0x4931a684,0x0542fb87,0x41e9a20e,
    0x2aaf8839,0x0363df6c,0x9a15035d,0xa85b051d,0x12e144a0,0x1e85b06c,
    0x3c771a68,0x45107454,0x0b268828,0x080d1015,0x16fc0d8f,0x369b44c4,
    0x14241b01,0x0d82cc71,0x4032b322,0x53cd31a6,0x54703651,0xba966880,
    0x1e00d103,0x81e8e81b,0x266b2993,0x98a1a2c0,0xa80d8345,0xc869a03f,
    0x59932fbd,0x440e1507,0x80a62aad,0x965401cb,0x2a7e62e8,0x2880d41f,
    0x4503614c,0x02c05c49,0x34c41791,0x5010813d,0x00100200,0x00000000,
    0x214c42aa,0x1c283818,0x2009151c,0x1aa8aa61,0x00000000,0x00000000,
    0x0101a980,0x42020601,0x00000029,0x00000000,0x00000000,0x00000000,
    0x00000000,0x00000000,0x00000000,0x02005753,0x15c00330,0x8177054e,
    0x440af203,0x066d40ab,0x055c17b6,0x5543dddb,0x75cfaa1a,0x5d447911,
    0xb0d11e40,0xb7581aa1,0x1325bb83,0x23aab8e7,0x4125700b,0x2d944916,
    0x1b10266a,0x24599a98,0x383e2d8b,0x1f32c562,0x883402d8,0x413a8d16,
    0x3b59753b,0x00cd26ae,0x4b305599,0x816c1706,0x4744801d,0x47b2d448,
    0xd70d92a3,0x5a098b70,0x1154f40a,0x712a8179,0x2ee21933,0xb1fa8071,
    0x41d92e1b,0x10fe544a,0x0aa05b3f,0x6c3e09d5,0x3b34c336,0xe99aa1aa,
    0x3716ebe0,0x540bc881,0x422144e1,0xdaa85533,0x0b64b894,0x549509b3,
    0x30901f14,0x157b05f7,0xf39b073f,0xb0f207c4,0xeee8f341,0x4260ae0c,
    0x982cdcdb,0x566391b1,0xd2cc1bf8,0x9960d103,0xb1120b64,0x64f6a1a6,
    0xd8b5103c,0x68360742,0x4531289e,0x4073802b,0x26b8e5a3,0x0d3410fb,
    0x4b0e20e2,0x96214c0d,0x07e65f04,0x55d440d8,0x79a0d80b,0xb82a672e,
    0x0e333c82,0xe8966e1c,0x21dfbacd,0x276a1ba8,0x2a0efa61,0x5704819b,
    0x05832053,0x10080173,0x3e67e65d,0xbb106e61,0x02010401,0x00000406,
    0x00040000,0x00010100,0x00000000,0x00000000,0x00000000,0x2a000000,
    0x550f221e,0xcbaba817,0x65c19b50,0x32219b30,0x0b2eea0c,0x98399795,
    0x219d50cd,0x4bb663d8,0x555ec3d8,0x99b9972d,0x3a20f669,0x90073663,
    0x2550d41d,0x41912e4b,0x0ba0d44c,0xa8a65835,0x0b60aa0c,0x2f8848d7,
    0x9aa18871,0x0f9143e2,0x803d81f7,0x188665cb,0x8221e295,0x20f41c79,
    0x1187e219,0x05b0101f,0x74c02a5d,0x807c4038,0x223db80f,0x401e40fb,
    0x6c0669b3,0x4b600d50,0x0cc1e828,0x88d513f2,0xf982d819,0x00764039,
    0xb80f80fa,0x903e2e69,0x2ba27007,0x16e19819,0x3d03b540,0x1ee98198,
    0x5b09d0d7,0x3aa01b20,0x1f016e02,0x0f9cba70,0xf31c01e4,0x07883037,
    0x16c0e7a0,0x8ae4082a,0x02d83c87,0xf9a980b5,0x7c00f980,0x215d5380,
    0x1c01e40f,0x3a0207ea,0x075c0442,0x8a21c3c8,0x47913659,0x816a03b0,
    0x0ba17238,0x74701f05,0x287903e4,0x206e0f4c,0x1aacd887,0xabd80b10,
    0x655ec41b,0x0ed4e641,0x3b220799,0x3ee2ea81,0xb555d90c,0x74c3fa89,
    0x98fea351,0x002dbbee,0x04004000,0x40080080,0x00001008,0x00000000,
    0x00000000,0x00000000,0x00000000,0x00000000,0x90cd9800,0x65eecc19,
    0xd9866c40,0x4287d50c,0x265bacd9,0x3660cbdd,0x6cc0bcbd,0x9b31daac,
    0x81c40597,0x3ae0c2c8,0xa885700c,0x4896c0c0,0x321ea5b0,0x983e16c3,
    0xd8516c1e,0x712d8d72,0xb0c3d81d,0x06b81ec5,0x4621b0f2,0x222d984c,
    0x360641d4,0x44b2048a,0x0b61e40f,0x360f4c1f,0x1e65b012,0x1e44e859,
    0x416e2c81,0x007702eb,0x88aee1a2,0x66c01d89,0x26cd6404,0x266f61e4,
    0x5ec340f9,0x8992d849,0x33235c2c,0x54de43a9,0x05a8a81e,0x70ea0077,
    0x039370ae,0x3202fcd8,0xd87904dc,0x340f999b,0x66c1cdec,0x3542c81a,
    0x790e6732,0x7c705d53,0x89003b80,0xc9dc5719,0x17cd6c01,0xc81e8ac8,
    0xd03e16c3,0x016c05b0,0x1e43d859,0x31e62c81,0x7709b557,0xb02e0fc4,
    0x3a65dddd,0x5b03a3cb,0x4cb60be6,0x0b61e40e,0x16c3e81f,0x316c05b0,
    0xb143c81f,0xf10e3d45,0x71443b81,0x0015c041,0x9fb0de98,0x75c37a61,
    0x3a61bd12,0x9807f50d,0x0de980de,0x0dcade98,0x96556f44,0x21dcade9,
    0x437e60ea,0xeb860cd8,0x005707ee,0x00000000,0x00000000,0x00000000,
    0x00000000,0x26330998,0x81a88331,0x26626619,0x804c0988,0x01505009,
    0x00661518,0x2662002a,0x4c618c19,0x20622660,0x53c5d40b,0x513c5a21,
    0x32c8c891,0x46449a6d,0x41645c4a,0xf5037502,0x01d55d55,0x2b881751,
    0xd52644d4,0x96ebea93,0x5442aae8,0x852c9d43,0x208d99e6,0xf86c1139,
    0x0e8ea188,0x22277573,0x573008b8,0x221c9a68,0xb77b00ab,0x4d0d0d30,
    0x99c174c7,0x0c6cc661,0x70fd479a,0x2eaaea07,0x2e5925c2,0xaacaa983,
    0xd3417500,0x403730e4,0x07441cca,0x9b0d3434,0x7410e0a8,0xd119e683,
    0x9741874c,0x21b2cc2e,0x205030e8,0x3a680bb8,0x05730390,0x12d87357,
    0x151a6868,0x5500043b,0x2a3f59b0,0x06fe439c,0x65c06432,0x406fe42a,
    0x3e602a82,0x03e8af89,0xb81302e2,0x87e64aae,0x951f99fa,0x000007ea,
    0x00000401,0x00020000,0x00000000,0x00000000,0x00000000,0x88000000,
    0x088888b5,0x1cb88074,0x2ee04411,0x00003bbb,0x00000000,0x80000000,
    0xa9ab10f9,0x220aaaaa,0x8b2619e1,0x00002eea,0x00000000,0x00000000,
    0x24a41300,0x00999998,0x00000000,0x00000000,0x00000000,0x41083100,
    0x00999999,0x00000000,0x00000000,0x00000000,0x00000000,0x00000000,
    0x00000000,
};

static signed short stb__times_13_usascii_x[95]={ 0,1,0,0,0,0,0,0,0,0,0,0,0,0,
0,0,0,1,0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
0,0,-1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,-1,0,0,-1,0,0,0,0,0,0,0,
-1,0,0,0,0,0,-1,0,0,0,0,0,0,0,0,0,0,1,0,1,0, };
static signed short stb__times_13_usascii_y[95]={ 10,2,2,2,1,2,2,2,1,1,1,3,8,6,
8,1,2,2,2,2,2,2,2,2,2,2,4,4,3,4,3,2,1,2,2,2,2,2,2,2,2,2,2,2,
2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,1,2,2,12,2,4,1,4,1,4,1,4,1,1,
1,1,1,4,4,4,4,4,4,4,3,4,4,4,4,4,4,1,1,1,6, };
static unsigned short stb__times_13_usascii_w[95]={ 0,2,5,6,6,10,9,2,4,4,6,7,3,4,
3,4,6,4,6,5,6,6,6,6,6,6,2,3,7,7,7,5,11,9,8,8,9,7,7,9,9,4,5,9,
7,11,10,9,7,9,8,6,7,9,9,11,9,9,7,4,4,3,6,7,3,6,7,5,6,5,6,6,6,3,
4,6,4,10,6,6,7,6,4,5,4,6,6,9,6,6,6,4,2,4,7, };
static unsigned short stb__times_13_usascii_h[95]={ 0,9,4,9,10,9,9,4,12,12,6,7,4,2,
3,10,9,8,8,9,8,9,9,9,9,9,7,8,6,4,6,9,12,8,8,9,8,8,8,9,8,8,9,8,
8,8,9,9,8,11,8,9,8,9,9,9,8,8,8,11,10,11,5,1,3,7,10,7,10,7,9,9,9,9,
12,9,9,6,6,7,9,9,6,7,8,7,7,7,6,9,6,12,12,12,2, };
static unsigned short stb__times_13_usascii_s[95]={ 126,36,62,39,67,46,57,125,31,13,85,
50,58,92,80,79,67,93,102,74,109,80,87,94,101,120,123,98,77,68,58,
12,1,83,74,18,56,66,40,54,25,20,64,1,118,106,1,1,48,41,11,
47,98,37,27,108,80,70,90,55,74,51,118,97,76,116,84,21,60,44,29,
22,15,11,36,119,114,66,104,37,99,107,99,15,35,8,1,27,111,92,92,
26,23,18,84, };
static unsigned short stb__times_13_usascii_t[95]={ 1,14,50,14,1,14,14,43,1,1,43,
43,50,50,50,1,14,34,34,14,34,14,14,14,14,14,34,34,43,50,43,
24,1,34,34,24,34,34,34,24,34,34,24,34,24,24,24,14,34,1,34,
24,24,24,24,14,24,24,24,1,1,1,43,50,50,34,1,43,1,43,14,
14,14,14,1,1,1,43,43,43,1,1,43,43,34,43,43,43,43,1,43,
1,1,1,50, };
static unsigned short stb__times_13_usascii_a[95]={ 47,63,77,94,94,156,146,34,
63,63,94,106,47,63,47,52,94,94,94,94,94,94,94,94,
94,94,52,52,106,106,106,83,173,136,125,125,136,115,104,136,
136,63,73,136,115,167,136,136,104,136,125,104,115,136,136,177,
136,136,115,63,52,63,88,94,63,83,94,83,94,83,63,94,
94,52,52,94,52,146,94,94,94,94,63,73,52,94,94,136,
94,94,83,90,38,90,102, };

// Call this function with
//    font: NULL or array length
//    data: NULL or specified size
//    height: STB_FONT_times_13_usascii_BITMAP_HEIGHT or STB_FONT_times_13_usascii_BITMAP_HEIGHT_POW2
//    return value: spacing between lines
static void stb_font_times_13_usascii(stb_fontchar font[STB_FONT_times_13_usascii_NUM_CHARS],
                unsigned char data[STB_FONT_times_13_usascii_BITMAP_HEIGHT][STB_FONT_times_13_usascii_BITMAP_WIDTH],
                int height)
{
    int i,j;
    if (data != 0) {
        unsigned int *bits = stb__times_13_usascii_pixels;
        unsigned int bitpack = *bits++, numbits = 32;
        for (i=0; i < STB_FONT_times_13_usascii_BITMAP_WIDTH*height; ++i)
            data[0][i] = 0;  // zero entire bitmap
        for (j=1; j < STB_FONT_times_13_usascii_BITMAP_HEIGHT-1; ++j) {
            for (i=1; i < STB_FONT_times_13_usascii_BITMAP_WIDTH-1; ++i) {
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
        float recip_width = 1.0f / STB_FONT_times_13_usascii_BITMAP_WIDTH;
        float recip_height = 1.0f / height;
        for (i=0; i < STB_FONT_times_13_usascii_NUM_CHARS; ++i) {
            // pad characters so they bilerp from empty space around each character
            font[i].s0 = (stb__times_13_usascii_s[i]) * recip_width;
            font[i].t0 = (stb__times_13_usascii_t[i]) * recip_height;
            font[i].s1 = (stb__times_13_usascii_s[i] + stb__times_13_usascii_w[i]) * recip_width;
            font[i].t1 = (stb__times_13_usascii_t[i] + stb__times_13_usascii_h[i]) * recip_height;
            font[i].x0 = stb__times_13_usascii_x[i];
            font[i].y0 = stb__times_13_usascii_y[i];
            font[i].x1 = stb__times_13_usascii_x[i] + stb__times_13_usascii_w[i];
            font[i].y1 = stb__times_13_usascii_y[i] + stb__times_13_usascii_h[i];
            font[i].advance_int = (stb__times_13_usascii_a[i]+8)>>4;
            font[i].s0f = (stb__times_13_usascii_s[i] - 0.5f) * recip_width;
            font[i].t0f = (stb__times_13_usascii_t[i] - 0.5f) * recip_height;
            font[i].s1f = (stb__times_13_usascii_s[i] + stb__times_13_usascii_w[i] + 0.5f) * recip_width;
            font[i].t1f = (stb__times_13_usascii_t[i] + stb__times_13_usascii_h[i] + 0.5f) * recip_height;
            font[i].x0f = stb__times_13_usascii_x[i] - 0.5f;
            font[i].y0f = stb__times_13_usascii_y[i] - 0.5f;
            font[i].x1f = stb__times_13_usascii_x[i] + stb__times_13_usascii_w[i] + 0.5f;
            font[i].y1f = stb__times_13_usascii_y[i] + stb__times_13_usascii_h[i] + 0.5f;
            font[i].advance = stb__times_13_usascii_a[i]/16.0f;
        }
    }
}

#ifndef STB_SOMEFONT_CREATE
#define STB_SOMEFONT_CREATE              stb_font_times_13_usascii
#define STB_SOMEFONT_BITMAP_WIDTH        STB_FONT_times_13_usascii_BITMAP_WIDTH
#define STB_SOMEFONT_BITMAP_HEIGHT       STB_FONT_times_13_usascii_BITMAP_HEIGHT
#define STB_SOMEFONT_BITMAP_HEIGHT_POW2  STB_FONT_times_13_usascii_BITMAP_HEIGHT_POW2
#define STB_SOMEFONT_FIRST_CHAR          STB_FONT_times_13_usascii_FIRST_CHAR
#define STB_SOMEFONT_NUM_CHARS           STB_FONT_times_13_usascii_NUM_CHARS
#define STB_SOMEFONT_LINE_SPACING        STB_FONT_times_13_usascii_LINE_SPACING
#endif

