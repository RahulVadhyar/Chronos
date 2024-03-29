// Font generated by stb_font_inl_generator.c (4/1 bpp)
//
// Following instructions show how to use the only included font, whatever it is, in
// a generic way so you can replace it with any other font by changing the include.
// To use multiple fonts, replace STB_SOMEFONT_* below with STB_FONT_times_10_usascii_*,
// and separately install each font. Note that the CREATE function call has a
// totally different name; it's just 'stb_font_times_10_usascii'.
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

#define STB_FONT_times_10_usascii_BITMAP_WIDTH         128
#define STB_FONT_times_10_usascii_BITMAP_HEIGHT         42
#define STB_FONT_times_10_usascii_BITMAP_HEIGHT_POW2    64

#define STB_FONT_times_10_usascii_FIRST_CHAR            32
#define STB_FONT_times_10_usascii_NUM_CHARS             95

#define STB_FONT_times_10_usascii_LINE_SPACING           6

static unsigned int stb__times_10_usascii_pixels[]={
    0x98040000,0x22130000,0x00800001,0x00002000,0x00808020,0x060a8220,
    0x311a8505,0x4c153550,0x0623710b,0x23415355,0x20cab852,0x2a23b9c9,
    0x028eaa3b,0xd1028357,0x8866e188,0xb0629873,0x86111c10,0x42992258,
    0x26588e1a,0x0b9b89a4,0x22cc2275,0x94826aa1,0x06722026,0x2a8a2c05,
    0x21a85309,0x8c526241,0x21dc358b,0x54350a66,0x89268772,0x19d10b9b,
    0x221331dc,0x0c5d543d,0x221915f0,0x451a6a21,0x50370b1c,0x54819861,
    0x0f21a46a,0x986a14cd,0x88a68774,0x875c0b9b,0x0f61623b,0x2ae23b94,
    0x2371419d,0x1b1c8625,0x45106f26,0x49520a21,0x32cc3155,0x986a14cb,
    0x4124cb13,0x54309baa,0x212c4b33,0xba989859,0x8a136570,0x4aa14b1c,
    0x8aa14d45,0xb89a42c1,0x5dc19b9a,0x350a60b9,0x15355054,0x3750a524,
    0x1d4ccc17,0x11885755,0x6d5ed497,0x56c4621c,0x4555050e,0x20c530e0,
    0x0220a384,0xa8530ba2,0x084000e1,0x03004010,0x01000081,0x20880008,
    0x554260c1,0x004cccc0,0x931c986a,0x00000023,0x00000000,0x00000000,
    0x00000000,0x00000000,0x00000000,0x00000000,0x04000000,0x20402020,
    0x02010100,0x20836e02,0x4325b8ea,0x2a1b10fa,0x3661b10e,0xa86e666d,
    0x1b913b9a,0x2aa894dc,0x40b20dc4,0x40ae4cbb,0x89260ea2,0x89c5459a,
    0x99260dab,0x3614d343,0x11458310,0x2693151c,0x9cc6a144,0x20912374,
    0x4365302a,0x09cc00a9,0x8b161524,0x2a498939,0x2762ae0c,0x582a4c09,
    0x85c14414,0x9b12202b,0x7952cae1,0x4c4cba85,0x32564c92,0x9214dcc9,
    0x20ec4b1c,0x5324c09b,0x02c9ac88,0x505160ad,0x5402b8a0,0x4e44f6a4,
    0x4aa346e5,0x98a7260d,0x0b6648b2,0x2c5ad992,0x4730f366,0x05d2d829,
    0x051a032e,0x04498107,0x2a8b1a9c,0x24aa24a6,0x22ca60a6,0x09036e64,
    0x988a8b16,0x06c41790,0x58805c2a,0x51073750,0x9aa98350,0x2e213550,
    0x26e0a629,0x2e14e4c2,0x30e8ca83,0x986ce54b,0x1d10d885,0x0000d654,
    0x00040000,0x00400000,0x00000000,0x00000000,0x00000000,0x00000000,
    0x00000000,0x00000000,0x00000000,0x00a75400,0x03226a80,0x986574c0,
    0x3e61d88f,0x3e20f981,0x2377b571,0x5f33aae9,0x25d74c75,0x1dd74c04,
    0x700395d3,0x970e24c5,0x40ee442e,0x40e20a4d,0xd03b4956,0x84d51ec0,
    0x3413410c,0x4a96a681,0xb41b3417,0x5711c459,0x5876e248,0xca848845,
    0x5a0d5053,0x34033a2c,0x64354d50,0x4f43ae80,0x2b1e341a,0x3a254f41,
    0x14d402c8,0x0ba92212,0x53b28298,0x13d05750,0x40d03ce8,0x190d2aba,
    0x316831d0,0x02ee3468,0x5741b31d,0x21dcd404,0x05058704,0x2aa1f44a,
    0x32d0685a,0x36504683,0x0d0190d2,0x8933411a,0x68b26848,0x95538859,
    0x15752419,0x4c0540c4,0x0e450e24,0xd0e981f3,0x92abe619,0x43f11749,
    0x2074c2d8,0x3a64aaf8,0x5d3002aa,0x6c3e6195,0x1b314c02,0x66dc1dc0,
    0xb71d4004,0x00000001,0x00000000,0x00000000,0x00000000,0x00000000,
    0x00000000,0x2e600000,0x54fa66ba,0x990f9803,0x10c987d4,0x400fcc04,
    0x10000800,0x01080000,0x04001040,0x9855881b,0x70ea680a,0x2b1770a5,
    0x46a21a0b,0x432a6399,0x26a258ab,0x95d44183,0x47772b98,0x2b2e29e9,
    0x36b6b2a4,0x5c190a60,0x54c0b503,0x20ee67a1,0x06b4819d,0x32a0d4cd,
    0x94c72620,0x7312c2e5,0x9b842e13,0x87705319,0x559ccb29,0x4c704d45,
    0x4c076605,0x0ee23a1a,0x5cd64166,0x88353340,0x4c6a6a59,0x2248dcb2,
    0x423709b9,0x2a0a611b,0x732ca60d,0x08a29556,0x22660836,0x534054c5,
    0x4a609107,0x72a88684,0x89de5c73,0x53910ead,0x10cd8830,0x3512a19d,
    0x3a32a1b3,0x771d1950,0x92ab7200,0x30037659,0x36a1321f,0x007c4000,
    0x02000000,0x00000000,0x00000000,0x00000000,0x00000000,0x00000000,
    0x00404400,0x35733a84,0x994c6a63,0x2aaa1aaa,0x0000001a,0x00000000,
    0x9a800000,0x2a57313b,0x0828e25a,0x2aaa06a6,0x0000002a,0x00000000,
    0x80000000,0x998e6458,0x00000844,0x00000000,0x00000000,0xd8000000,
    0x088ae620,0x00000000,0x00000000,0x00000000,0x53970000,0x00000008,
    0x00000000,0x00000000,0x00000000,0x00000000,0x00000000,0x00000000,
    0x00000000,
};

static signed short stb__times_10_usascii_x[95]={ 0,1,0,0,0,0,0,0,0,0,0,0,0,0,
0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
0,0,-1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,-1,0,0,-1,0,0,0,0,0,0,0,
-1,0,0,0,0,0,-1,0,0,0,0,0,0,0,0,0,0,1,0,0,0, };
static signed short stb__times_10_usascii_y[95]={ 8,1,1,1,1,1,1,1,1,1,1,2,7,5,
7,1,1,1,1,1,1,2,1,2,1,1,3,3,2,4,2,1,1,1,2,1,2,2,2,1,2,2,2,2,
2,2,2,1,2,1,2,1,2,2,2,2,2,2,2,1,1,1,1,9,1,3,1,3,1,3,1,3,1,1,
1,1,1,3,3,3,3,3,3,3,2,3,3,3,3,3,3,1,1,1,5, };
static unsigned short stb__times_10_usascii_w[95]={ 0,2,4,5,5,8,7,2,3,3,4,5,2,3,
2,3,5,3,5,4,5,4,5,5,4,5,2,2,5,5,5,4,9,7,6,6,7,6,5,7,7,3,4,7,
6,8,8,7,5,7,7,5,6,7,7,9,7,7,6,3,3,3,5,6,2,4,6,4,5,4,4,5,5,3,
3,5,3,7,5,5,6,5,4,4,3,5,5,7,5,5,4,3,2,4,5, };
static unsigned short stb__times_10_usascii_h[95]={ 0,8,4,8,8,8,8,4,9,9,5,6,3,2,
2,8,8,7,7,8,7,7,8,7,8,8,6,7,6,2,6,8,9,7,6,8,6,6,6,8,6,6,7,6,
6,6,7,8,6,9,6,8,6,7,7,7,6,6,6,9,8,9,5,1,3,6,8,6,8,6,7,7,7,7,
9,7,7,5,5,6,7,7,5,6,7,6,6,6,5,7,5,9,9,9,2, };
static unsigned short stb__times_10_usascii_s[95]={ 125,59,11,62,82,88,97,125,1,47,6,
78,19,28,32,115,119,7,22,13,1,11,29,121,18,23,124,125,50,35,16,
1,21,37,109,6,95,88,82,74,22,46,86,51,59,66,28,51,45,31,116,
68,75,113,105,95,8,30,1,39,105,43,119,41,16,61,35,84,109,89,75,
80,49,55,17,59,65,111,105,72,42,69,94,56,91,66,103,38,99,16,1,
13,10,5,22, };
static unsigned short stb__times_10_usascii_t[95]={ 9,1,35,1,1,1,1,28,1,1,35,
28,35,35,35,1,1,20,20,11,20,20,11,11,11,11,20,1,28,35,28,
11,1,20,20,11,20,20,20,1,28,28,11,20,20,20,20,1,20,1,20,
1,20,11,11,11,28,28,28,1,1,1,28,35,35,28,11,28,1,28,11,
11,11,11,1,11,11,28,28,28,11,11,28,28,11,28,20,28,28,20,35,
1,1,1,35, };
static unsigned short stb__times_10_usascii_a[95]={ 36,48,59,72,72,120,112,26,
48,48,72,81,36,48,36,40,72,72,72,72,72,72,72,72,
72,72,40,40,81,81,81,64,133,104,96,96,104,88,80,104,
104,48,56,104,88,128,104,104,80,104,96,80,88,104,104,136,
104,104,88,48,40,48,68,72,48,64,72,64,72,64,48,72,
72,40,40,72,40,112,72,72,72,72,48,56,40,72,72,104,
72,72,64,69,29,69,78, };

// Call this function with
//    font: NULL or array length
//    data: NULL or specified size
//    height: STB_FONT_times_10_usascii_BITMAP_HEIGHT or STB_FONT_times_10_usascii_BITMAP_HEIGHT_POW2
//    return value: spacing between lines
static void stb_font_times_10_usascii(stb_fontchar font[STB_FONT_times_10_usascii_NUM_CHARS],
                unsigned char data[STB_FONT_times_10_usascii_BITMAP_HEIGHT][STB_FONT_times_10_usascii_BITMAP_WIDTH],
                int height)
{
    int i,j;
    if (data != 0) {
        unsigned int *bits = stb__times_10_usascii_pixels;
        unsigned int bitpack = *bits++, numbits = 32;
        for (i=0; i < STB_FONT_times_10_usascii_BITMAP_WIDTH*height; ++i)
            data[0][i] = 0;  // zero entire bitmap
        for (j=1; j < STB_FONT_times_10_usascii_BITMAP_HEIGHT-1; ++j) {
            for (i=1; i < STB_FONT_times_10_usascii_BITMAP_WIDTH-1; ++i) {
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
        float recip_width = 1.0f / STB_FONT_times_10_usascii_BITMAP_WIDTH;
        float recip_height = 1.0f / height;
        for (i=0; i < STB_FONT_times_10_usascii_NUM_CHARS; ++i) {
            // pad characters so they bilerp from empty space around each character
            font[i].s0 = (stb__times_10_usascii_s[i]) * recip_width;
            font[i].t0 = (stb__times_10_usascii_t[i]) * recip_height;
            font[i].s1 = (stb__times_10_usascii_s[i] + stb__times_10_usascii_w[i]) * recip_width;
            font[i].t1 = (stb__times_10_usascii_t[i] + stb__times_10_usascii_h[i]) * recip_height;
            font[i].x0 = stb__times_10_usascii_x[i];
            font[i].y0 = stb__times_10_usascii_y[i];
            font[i].x1 = stb__times_10_usascii_x[i] + stb__times_10_usascii_w[i];
            font[i].y1 = stb__times_10_usascii_y[i] + stb__times_10_usascii_h[i];
            font[i].advance_int = (stb__times_10_usascii_a[i]+8)>>4;
            font[i].s0f = (stb__times_10_usascii_s[i] - 0.5f) * recip_width;
            font[i].t0f = (stb__times_10_usascii_t[i] - 0.5f) * recip_height;
            font[i].s1f = (stb__times_10_usascii_s[i] + stb__times_10_usascii_w[i] + 0.5f) * recip_width;
            font[i].t1f = (stb__times_10_usascii_t[i] + stb__times_10_usascii_h[i] + 0.5f) * recip_height;
            font[i].x0f = stb__times_10_usascii_x[i] - 0.5f;
            font[i].y0f = stb__times_10_usascii_y[i] - 0.5f;
            font[i].x1f = stb__times_10_usascii_x[i] + stb__times_10_usascii_w[i] + 0.5f;
            font[i].y1f = stb__times_10_usascii_y[i] + stb__times_10_usascii_h[i] + 0.5f;
            font[i].advance = stb__times_10_usascii_a[i]/16.0f;
        }
    }
}

#ifndef STB_SOMEFONT_CREATE
#define STB_SOMEFONT_CREATE              stb_font_times_10_usascii
#define STB_SOMEFONT_BITMAP_WIDTH        STB_FONT_times_10_usascii_BITMAP_WIDTH
#define STB_SOMEFONT_BITMAP_HEIGHT       STB_FONT_times_10_usascii_BITMAP_HEIGHT
#define STB_SOMEFONT_BITMAP_HEIGHT_POW2  STB_FONT_times_10_usascii_BITMAP_HEIGHT_POW2
#define STB_SOMEFONT_FIRST_CHAR          STB_FONT_times_10_usascii_FIRST_CHAR
#define STB_SOMEFONT_NUM_CHARS           STB_FONT_times_10_usascii_NUM_CHARS
#define STB_SOMEFONT_LINE_SPACING        STB_FONT_times_10_usascii_LINE_SPACING
#endif

