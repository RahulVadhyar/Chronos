// Font generated by stb_font_inl_generator.c (4/1 bpp)
//
// Following instructions show how to use the only included font, whatever it is, in
// a generic way so you can replace it with any other font by changing the include.
// To use multiple fonts, replace STB_SOMEFONT_* below with STB_FONT_times_bold_12_usascii_*,
// and separately install each font. Note that the CREATE function call has a
// totally different name; it's just 'stb_font_times_bold_12_usascii'.
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

#define STB_FONT_times_bold_12_usascii_BITMAP_WIDTH         128
#define STB_FONT_times_bold_12_usascii_BITMAP_HEIGHT         54
#define STB_FONT_times_bold_12_usascii_BITMAP_HEIGHT_POW2    64

#define STB_FONT_times_bold_12_usascii_FIRST_CHAR            32
#define STB_FONT_times_bold_12_usascii_NUM_CHARS             95

#define STB_FONT_times_bold_12_usascii_LINE_SPACING           8

static unsigned int stb__times_bold_12_usascii_pixels[]={
    0x81881108,0x09880441,0x880c4008,0x00402621,0x04c13331,0x30318000,
    0x4c04c0c0,0x1d850199,0x740e88e2,0x0b995cc4,0x26f26062,0x8f61743d,
    0x703b8bc9,0x2ee4f87f,0xbbbf70dc,0x65c4b388,0x1234ec3b,0x321fffe6,
    0x54712641,0x40e60886,0x897a0e43,0x47b07a1f,0x2a07e24e,0x8f99f42f,
    0xf35f30fa,0xb7244d45,0x1f8f88a7,0x95355019,0x1c47b0f0,0x524f88f1,
    0x219aebd8,0x9f0fe64a,0x7ccf60f4,0x17d427c3,0x0f9bdcb6,0x75cfe3f3,
    0x1ff30ddc,0x00e6f3d0,0x750f306e,0x9d0b31c4,0x87cdeca6,0x42fb9aa1,
    0x27b07a7e,0x543f42fb,0x8fa85c2f,0xf13f30f9,0x7d40bac5,0x3484c41f,
    0x1ae1a015,0x032388e4,0x4fc45d3a,0x87cc116c,0xe93e24f9,0x44f99ec1,
    0x217d424f,0x43f33621,0x3f25cdf9,0x375c0efe,0x0b3d1190,0x770f3093,
    0x9d0b11c4,0x4fa3ea6a,0xa9ba3542,0x47b07a1f,0xcd8be66e,0x4c0541fa,
    0x8813f30f,0x0d3728b3,0x43cf54e6,0x47b0f01b,0x53a1e638,0x2ccaf9c8,
    0x566425c3,0x8f60f41d,0x542dacd8,0xa83e85db,0x3505f31f,0x2bcca891,
    0x42574490,0x4970ae06,0x93a1aa38,0x01c8500b,0xd83d07f5,0x00080103,
    0x82a99554,0x1101c020,0x13002010,0x6c388762,0xcb85b911,0x0260a989,
    0x1f439b50,0x000007d1,0x00000000,0x80800000,0x80260818,0x00000019,
    0x00000000,0x00000000,0x00000000,0x00000000,0x00000000,0x00000000,
    0x01801100,0x10004c03,0x0604c413,0x0c40c0cc,0x33310260,0x02150040,
    0x8804c066,0x9e862109,0x86ac883c,0x21e8e884,0xd10bead8,0x4121623f,
    0x836760fa,0x1ffb01f9,0x5dc2ffe4,0x6d45e440,0xb0754ec3,0x4e6c45f1,
    0xf53f31ea,0xd1b70d51,0xbb6b8350,0x7dc4dbdc,0x3039850f,0x12e5e61f,
    0x8be2103f,0x8264099b,0x1d31cc5d,0x25eb4c2a,0x9f88d45e,0xfb81def8,
    0x8710988b,0xdbccf97b,0x42afd543,0x87ee6c0b,0x67c4d97b,0x3e66985d,
    0x21e7c42d,0x7fcc03f8,0x3e63f102,0x7dc7e203,0xab7dd41f,0x36fe6243,
    0xb940d5c6,0x5ea242cf,0x9f2f90fa,0x222f89f8,0x7fd933fe,0xf72f47d4,
    0x1bff5005,0x80bee1a8,0x6f9e99f8,0x41e7d5e6,0x31f5440b,0x3628379d,
    0x2f70e24f,0x9b2f70f9,0xbd07f1f8,0x7cbdcd90,0x0cfb8fea,0x810bf223,
    0x27e203fa,0x97dcd95b,0x41c414fc,0x7f77445a,0x0dc9d0a0,0x4c3ea3ea,
    0x44fc4997,0x0895c11f,0x46b8f996,0x1b8fe65e,0x6e8170b6,0x3b13f104,
    0x5efec439,0x51240efc,0x4b117707,0x849220e9,0x322fddc8,0x2f3a20da,
    0xfa8abb24,0x0e6640ac,0x87ae7362,0x7cc49bda,0x15d6ec41,0x102007f5,
    0x1a880020,0x10000800,0x00008080,0x00803001,0x00000200,0x00000000,
    0x00000000,0x00000000,0x8cc40000,0x22130999,0x22131199,0x88131099,
    0x4cc26621,0x26213310,0x13333310,0x22026662,0x01331009,0x98860131,
    0x26219881,0xbe831019,0x5cbf35fa,0x26589fa0,0xd7706c5f,0x1dc3fe23,
    0x790d8ff3,0x774b59f5,0x0be61ec9,0x263eafe8,0x3a1f882f,0xd03fe22f,
    0x370b601f,0xd0a7e9fa,0x507ec38d,0x75fa83e8,0x18665f70,0x26e867f3,
    0xd80be25f,0x0be21f97,0xda9baa04,0xbf707d87,0x7ecbee03,0x0e37428a,
    0xdf50a7f3,0x7409f901,0x20fe6076,0x7c47f16e,0xcbec1e8a,0xb9b73e27,
    0x547eea1f,0xf107d87d,0x3bf11b85,0x8dd05bf3,0x7f056e83,0x5403fe20,
    0x07f300df,0xf889f9fd,0xcbfd80ba,0x43eabe20,0x37e2a1f8,0x20fb0fb2,
    0xc97e22f8,0xdb07f93f,0x80cfb838,0x0bf7303f,0x07f302fc,0xf88df1dd,
    0x107d81fd,0x3e21f35f,0x7d9fe4a1,0x2f8847d8,0x7ccbe638,0xf8147c81,
    0x25307f04,0x40bf02fc,0xf56e83f9,0x436d7c47,0xf35f107d,0xf3287e21,
    0x71f61f61,0x8b0305f4,0x075bd105,0x22fc4064,0x83ff31ea,0x9f701ef9,
    0xfd8ffc41,0x49f39f32,0xcf981fe8,0x267f52fb,0x87fa290d,0x04dabfe8,
    0x00080000,0x00000000,0x00000000,0x00000000,0x00000000,0x00000000,
    0x00000000,0x00000000,0x33109988,0x20999998,0x19989998,0x4cc46662,
    0x26662199,0x00266219,0xc8199882,0x04c0d8bf,0x00011000,0x20fe8000,
    0x3a67a21e,0xfc87f41f,0x3fd07f42,0x54ff43b3,0x136bba1d,0xb5dd0fee,
    0x742a7c1d,0x402b80ff,0x8803972e,0xeac8fa4b,0x40b8bec1,0xfb09f509,
    0xb1f60fdc,0x17d8622f,0x0bf37431,0x5f56d87f,0x262617dc,0x2e05e83f,
    0x30b6e22f,0xd31b8399,0x091fb0fa,0x4fb06f88,0x363ec1fb,0x20efb077,
    0x7f03f66e,0x441d96d8,0x9507e04f,0x05f3503f,0x007b2bb1,0x3f61f5cc,
    0x0bf201fe,0x0ff667ec,0x0d9fb1f6,0x4dd099fb,0x361fc2fc,0x0e40becf,
    0x5f8b85a8,0x9317c544,0x42dc8839,0xb0faf31b,0xf301ff1f,0xfb9f604b,
    0x1df63ec1,0x26e82bec,0x361fc0fd,0x01429f16,0xfeac9819,0x65bfbb60,
    0x3a5a800b,0xd8bb7f33,0x1fd0df37,0x1fb9f624,0xd81f63ec,0x2fcdd1c7,
    0x7c5b61fc,0x2f203994,0x24f98e3a,0x0004fba9,0x47fa2000,0x5bf70dfd,
    0x4ff44db7,0x3fa23fd8,0xd103fd11,0x3e67d77f,0xdfa83dbf,0x1797fd10,
    0x7ffd4062,0x3fe21b54,0x00017c41,0x00000000,0x00000000,0x00000000,
    0x00000000,0x00000000,0x70000310,0x2553f73f,0xf70fb9f9,0x98001915,
    0x30102acf,0x2eaa040c,0x2638862f,0x1d570442,0x4ab8ef22,0x14c06d5c,
    0x7ccfafe6,0x2afe25dc,0x267e22af,0xf314fe0f,0xc8db5db9,0x5f0b702f,
    0xe841b0f5,0x8fdc7e26,0x33ffb0e8,0x8cf5c72d,0x65e63b68,0x8cf82985,
    0xc83e6be0,0x3e22dd9e,0x0bee0f99,0x3e6be2fe,0x3220fe20,0x334cf42b,
    0x0fd4999d,0x8220a83e,0xfd10f708,0x5c2abee5,0x76e5cf77,0x2be0fe4c,
    0x2a7e60f9,0x3eabe20f,0x2be0fe20,0x220f99f8,0x458640fc,0x447730e4,
    0x0312434f,0x2260fcc0,0x4c23f55d,0xf0530b97,0x81f35f05,0x3f37a165,
    0x457c06c2,0x3b30f99f,0x082628bf,0x32171702,0x00023cbf,0x2ea19f90,
    0x590ff22b,0xf9853039,0x17ddfcc4,0x7cc00000,0x02fbbfac,0x00000000,
    0x00200000,0x00004400,0x00000000,0x00000000,0x00000000,0x23880000,
    0x915ddddc,0xaaaa8617,0x0000000a,0x00000000,0x00000000,0x441f5000,
    0xb5150888,0x5555545b,0x00000000,0x00000000,0x00000000,0x99997000,
    0x00000009,0x00000000,0x00000000,0x00000000,0x00000000,0x00000000,
    0x00000000,
};

static signed short stb__times_bold_12_usascii_x[95]={ 0,0,0,0,0,0,0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,0,0,-1,0,0,0,0,0,0,0,0,0,0,
-1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0, };
static signed short stb__times_bold_12_usascii_y[95]={ 9,1,1,1,1,1,1,1,1,1,1,2,7,5,
7,1,1,1,1,1,1,1,1,1,1,1,3,3,2,4,2,1,1,1,1,1,1,1,1,1,1,1,1,1,
1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,10,1,3,1,3,1,3,1,3,1,1,
1,1,1,3,3,3,3,3,3,3,2,4,4,4,4,4,4,1,1,1,5, };
static unsigned short stb__times_bold_12_usascii_w[95]={ 0,3,6,6,6,11,9,3,4,4,5,6,3,4,
3,4,6,5,5,5,5,6,6,6,6,6,3,3,6,6,6,5,10,8,7,8,8,7,7,9,9,4,6,9,
7,11,8,9,7,9,8,6,7,8,8,11,8,8,8,3,4,3,6,7,3,6,6,5,6,5,5,6,6,3,
4,7,3,9,6,6,6,6,5,4,4,6,6,8,6,6,5,4,2,4,6, };
static unsigned short stb__times_bold_12_usascii_h[95]={ 0,9,5,9,9,9,9,5,11,11,5,7,4,3,
3,9,9,8,8,9,8,9,9,9,9,9,7,8,7,3,7,9,11,8,8,9,8,8,8,9,8,8,9,8,
8,8,9,9,8,10,8,9,8,9,9,9,8,8,8,10,9,10,5,2,3,7,9,7,9,7,8,9,8,8,
11,8,8,6,6,7,9,9,6,7,8,6,6,6,5,8,5,11,11,11,2, };
static unsigned short stb__times_bold_12_usascii_s[95]={ 126,75,92,93,100,107,8,111,1,35,99,
25,115,123,32,46,58,60,81,72,96,78,85,119,1,23,116,124,109,36,102,
109,24,87,66,115,51,43,35,92,20,30,68,1,111,99,37,58,80,40,63,
102,55,13,22,1,37,46,11,50,18,54,85,50,119,120,65,1,51,12,31,
30,88,95,19,72,124,68,38,18,86,79,32,7,119,54,61,45,78,74,105,
14,11,6,43, };
static unsigned short stb__times_bold_12_usascii_t[95]={ 1,1,42,1,1,1,13,42,1,1,42,
42,42,42,49,13,13,33,33,13,33,13,13,1,13,13,33,22,33,49,33,
13,1,33,33,13,33,33,33,13,33,33,1,33,23,23,13,1,23,1,23,
13,23,23,23,23,23,23,33,1,13,1,42,49,42,33,13,42,13,42,23,
13,23,23,1,23,13,42,42,42,1,1,42,42,23,42,42,42,42,33,42,
1,1,1,49, };
static unsigned short stb__times_bold_12_usascii_a[95]={ 43,58,96,87,87,173,144,48,
58,58,87,99,43,58,43,48,87,87,87,87,87,87,87,87,
87,87,58,58,99,99,99,87,161,125,116,125,125,116,106,135,
135,67,87,135,116,164,125,135,106,135,125,96,116,125,125,173,
125,125,116,58,48,58,101,87,58,87,96,77,96,77,58,87,
96,48,58,96,48,144,96,87,96,96,77,67,58,96,87,125,
87,87,77,68,38,68,90, };

// Call this function with
//    font: NULL or array length
//    data: NULL or specified size
//    height: STB_FONT_times_bold_12_usascii_BITMAP_HEIGHT or STB_FONT_times_bold_12_usascii_BITMAP_HEIGHT_POW2
//    return value: spacing between lines
static void stb_font_times_bold_12_usascii(stb_fontchar font[STB_FONT_times_bold_12_usascii_NUM_CHARS],
                unsigned char data[STB_FONT_times_bold_12_usascii_BITMAP_HEIGHT][STB_FONT_times_bold_12_usascii_BITMAP_WIDTH],
                int height)
{
    int i,j;
    if (data != 0) {
        unsigned int *bits = stb__times_bold_12_usascii_pixels;
        unsigned int bitpack = *bits++, numbits = 32;
        for (i=0; i < STB_FONT_times_bold_12_usascii_BITMAP_WIDTH*height; ++i)
            data[0][i] = 0;  // zero entire bitmap
        for (j=1; j < STB_FONT_times_bold_12_usascii_BITMAP_HEIGHT-1; ++j) {
            for (i=1; i < STB_FONT_times_bold_12_usascii_BITMAP_WIDTH-1; ++i) {
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
        float recip_width = 1.0f / STB_FONT_times_bold_12_usascii_BITMAP_WIDTH;
        float recip_height = 1.0f / height;
        for (i=0; i < STB_FONT_times_bold_12_usascii_NUM_CHARS; ++i) {
            // pad characters so they bilerp from empty space around each character
            font[i].s0 = (stb__times_bold_12_usascii_s[i]) * recip_width;
            font[i].t0 = (stb__times_bold_12_usascii_t[i]) * recip_height;
            font[i].s1 = (stb__times_bold_12_usascii_s[i] + stb__times_bold_12_usascii_w[i]) * recip_width;
            font[i].t1 = (stb__times_bold_12_usascii_t[i] + stb__times_bold_12_usascii_h[i]) * recip_height;
            font[i].x0 = stb__times_bold_12_usascii_x[i];
            font[i].y0 = stb__times_bold_12_usascii_y[i];
            font[i].x1 = stb__times_bold_12_usascii_x[i] + stb__times_bold_12_usascii_w[i];
            font[i].y1 = stb__times_bold_12_usascii_y[i] + stb__times_bold_12_usascii_h[i];
            font[i].advance_int = (stb__times_bold_12_usascii_a[i]+8)>>4;
            font[i].s0f = (stb__times_bold_12_usascii_s[i] - 0.5f) * recip_width;
            font[i].t0f = (stb__times_bold_12_usascii_t[i] - 0.5f) * recip_height;
            font[i].s1f = (stb__times_bold_12_usascii_s[i] + stb__times_bold_12_usascii_w[i] + 0.5f) * recip_width;
            font[i].t1f = (stb__times_bold_12_usascii_t[i] + stb__times_bold_12_usascii_h[i] + 0.5f) * recip_height;
            font[i].x0f = stb__times_bold_12_usascii_x[i] - 0.5f;
            font[i].y0f = stb__times_bold_12_usascii_y[i] - 0.5f;
            font[i].x1f = stb__times_bold_12_usascii_x[i] + stb__times_bold_12_usascii_w[i] + 0.5f;
            font[i].y1f = stb__times_bold_12_usascii_y[i] + stb__times_bold_12_usascii_h[i] + 0.5f;
            font[i].advance = stb__times_bold_12_usascii_a[i]/16.0f;
        }
    }
}

#ifndef STB_SOMEFONT_CREATE
#define STB_SOMEFONT_CREATE              stb_font_times_bold_12_usascii
#define STB_SOMEFONT_BITMAP_WIDTH        STB_FONT_times_bold_12_usascii_BITMAP_WIDTH
#define STB_SOMEFONT_BITMAP_HEIGHT       STB_FONT_times_bold_12_usascii_BITMAP_HEIGHT
#define STB_SOMEFONT_BITMAP_HEIGHT_POW2  STB_FONT_times_bold_12_usascii_BITMAP_HEIGHT_POW2
#define STB_SOMEFONT_FIRST_CHAR          STB_FONT_times_bold_12_usascii_FIRST_CHAR
#define STB_SOMEFONT_NUM_CHARS           STB_FONT_times_bold_12_usascii_NUM_CHARS
#define STB_SOMEFONT_LINE_SPACING        STB_FONT_times_bold_12_usascii_LINE_SPACING
#endif

