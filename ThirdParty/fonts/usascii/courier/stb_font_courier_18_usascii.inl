// Font generated by stb_font_inl_generator.c (4/1 bpp)
//
// Following instructions show how to use the only included font, whatever it is, in
// a generic way so you can replace it with any other font by changing the include.
// To use multiple fonts, replace STB_SOMEFONT_* below with STB_FONT_courier_18_usascii_*,
// and separately install each font. Note that the CREATE function call has a
// totally different name; it's just 'stb_font_courier_18_usascii'.
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

#define STB_FONT_courier_18_usascii_BITMAP_WIDTH         128
#define STB_FONT_courier_18_usascii_BITMAP_HEIGHT         76
#define STB_FONT_courier_18_usascii_BITMAP_HEIGHT_POW2   128

#define STB_FONT_courier_18_usascii_FIRST_CHAR            32
#define STB_FONT_courier_18_usascii_NUM_CHARS             95

#define STB_FONT_courier_18_usascii_LINE_SPACING           8

static unsigned int stb__courier_18_usascii_pixels[]={
    0x32042200,0x20322141,0x00142601,0x0a7d9380,0x00102ee8,0x22002200,
    0x664c3b00,0x1530b301,0x2e0c8907,0x99603900,0x401dca84,0x900ca42a,
    0x20f2f260,0x66644029,0xbbbd980e,0x91ccba1d,0x33505101,0x120c8905,
    0xa8baef26,0x2c370743,0x82452160,0x1660c984,0x106c4053,0x0e42cc19,
    0x0091123b,0x224154dc,0x3312120c,0x428ee06c,0x4907301a,0x80e8480c,
    0xddddd72b,0x91d40e41,0xa42c7600,0x512eeee9,0x4485997b,0x4032120c,
    0x45159868,0x920b02da,0x30584839,0x40b014c9,0xb8e40125,0x314c1aa1,
    0x3b835939,0x6442cc32,0x221660ac,0x0aab2556,0x212240e6,0x4c901c44,
    0x12581602,0x797b0640,0x74853019,0x4321b301,0x98e4c04b,0x52556885,
    0x8900c82a,0x982c2429,0x20580a62,0x49b99165,0x260d0882,0x59d9d932,
    0x10906448,0x5661a290,0x8855392a,0x09161204,0x14c17019,0x6c750590,
    0x95001a80,0x41290a60,0x49890644,0x2750d1cc,0xc8597139,0x48aa1200,
    0x11260c98,0x9306c407,0x86a064c1,0x300d980a,0x91209485,0x33322241,
    0x43615c3c,0x20244058,0xd8824b04,0x959702db,0x6e65c41b,0xcbade980,
    0x3aee9f10,0x290a600d,0x120c8904,0x225880c8,0x1b811645,0x091a8240,
    0x060106dc,0x13100110,0x55001810,0x38590948,0x806406c4,0xbb90171b,
    0x13320489,0xcb859d48,0x0001ccbb,0x80000000,0x0000000d,0x08000006,
    0x00004000,0x00000000,0x05b99500,0x00000000,0x00000000,0x00000000,
    0x00000000,0x00000000,0x00000000,0x00000000,0x97100000,0x00bb9839,
    0x3ae00800,0x66dc0dee,0x804dd981,0x77774c5c,0x0003d53e,0x001dda80,
    0xc8700880,0x074028a0,0x44ccbca8,0x4190dc04,0x224001da,0x0351c419,
    0x33773220,0xb10d8ea0,0x50fb227b,0x40377779,0x201c5138,0x48b31203,
    0x2c4e6240,0x1b804800,0x0aa0006a,0x40d47312,0x00ec1cc4,0x005dd439,
    0x64183880,0x95c58198,0xddd9802b,0x4d448048,0x2a802dda,0x206a4848,
    0xc8098244,0x90eea03e,0x02ae01dd,0x20cbadc8,0x2364cbd9,0x10c982cc,
    0xea8900d9,0x85501663,0x206a4839,0x64c00244,0x80177510,0x132e200b,
    0xbad98e20,0x21cc7724,0x2a03c40d,0x005c2d41,0x24829855,0x0024481a,
    0x1dcc2690,0x12200170,0xc9cc5920,0x02c16241,0x4e20ea12,0x41c42a84,
    0x0b1206a4,0x051c2400,0x0240a02e,0x374848a4,0x40682c48,0x91a84a84,
    0x19890350,0x03b120e6,0x2214c088,0x6405c0e2,0xa8532443,0x12235121,
    0x035c2b89,0x481f5053,0x83209032,0x2214c584,0xec895c0d,0x175503cb,
    0x2eae02e0,0x5f5c0ccb,0x1e5e443c,0x2e032f6a,0x80cdaebd,0x66d6d40b,
    0x5de641cb,0x05b7b101,0x260777d3,0x0302dbce,0x9d993010,0x02002099,
    0x18008010,0x80220000,0x10010008,0x00002200,0x00000000,0x00000000,
    0x00000000,0x13100000,0x70e6dc40,0x05d301dd,0x2e7aa000,0x40000cdd,
    0x14e8cdc9,0x8800007d,0x7d700009,0x56642f4c,0xc801904c,0xd8807300,
    0xea8bae1e,0x1cea9662,0x0c983b32,0xd80909b3,0x42dccecc,0x3b222bbb,
    0x70b03ccc,0x4c1a8903,0x7300c802,0xa8551600,0x4c122b85,0x24254243,
    0x8530c920,0x20e62404,0x3880241b,0x40fbbbb6,0x3a67300c,0x0914880e,
    0xd2471055,0x91090a65,0x487bb590,0x01614c32,0x1b920909,0x1541c880,
    0x73980640,0x80c9b807,0x4d20b85a,0x40c8354b,0x8ae2f84b,0x1e408320,
    0x3703a890,0x2032a012,0x300c802a,0x0b600597,0x44a85ed4,0x302e9374,
    0x12136a19,0x9c806412,0x777c4a8c,0x00de401e,0x90055024,0x0037a601,
    0xda9a805c,0x3548b81c,0x22f6e209,0x19048484,0x24264520,0x005b8077,
    0x0c802a80,0x20036730,0x5003500b,0x4012e293,0x90484848,0x484b9201,
    0x0037015c,0x4015402a,0x06c7300c,0x00d402e0,0x0099164c,0x412120ae,
    0x9999300c,0x16058487,0x32227d40,0x3262ccdd,0x3664ccec,0x32a13b23,
    0x376a0cce,0xb83e200c,0x87b99104,0x7d913ec8,0x80667654,0x20cec880,
    0x7bb971d9,0x00000600,0x00000000,0x00000000,0x00000000,0x00000000,
    0x00000000,0x00000000,0x00000000,0x37220000,0x0000dc9d,0x00000000,
    0x22000000,0x000000da,0x99bb5000,0x910c9859,0x3226da8d,0xbd09d53e,
    0x41676641,0x5f90cec8,0x14cccce8,0x5c599d99,0x223d913e,0x6ed40cac,
    0xd915cccc,0x754d9999,0x5300cccc,0xf10320b8,0x64485950,0x240eea0c,
    0x901b1240,0x900c80c8,0x2e032090,0x22424481,0x88530584,0x5542c123,
    0x4739120c,0x9009039c,0x551c0362,0x24240320,0x411b80c8,0x090a1242,
    0x2a853071,0x550f102e,0x9a522491,0x9009039a,0x812200b3,0x2090900c,
    0x0171b80c,0x12090492,0x1132ab26,0x2a1b663b,0x2a912372,0x0120734a,
    0x3601333a,0x67403200,0x01904ccc,0x3a01b9b7,0x120904cc,0x440266e6,
    0x2a848cdb,0x33d92256,0x4b0a1207,0x8086e039,0x2090900c,0x0151b80c,
    0x12090392,0x424000a6,0x4912aa2a,0x24240e60,0x87301912,0x90900c84,
    0x006e0320,0x98486a12,0x90002983,0x245d8550,0x89090398,0x242c1c44,
    0x04848064,0x90037019,0x12224350,0x4013376a,0xbb10ceca,0x39d73cc7,
    0xd990eedc,0x32299999,0xda9360ce,0x9916cccc,0x9f64599d,0xd9913ec8,
    0x3376a599,0xcccec883,0x999d51dc,0x00000019,0x00000000,0x00000000,
    0x00000000,0x00000000,0x0e6ec400,0x303d8000,0x188000a0,0xcdc88b22,
    0x6dc5912b,0x599501cd,0x36209815,0x644bee1d,0x4c0cccce,0x83603ecc,
    0x5c39d70c,0x049a81dd,0x005b3019,0xdf306644,0x37cd2a24,0x10e40c81,
    0x0d81981f,0x091120ae,0x20c4166a,0x02e03239,0x00c82522,0x1970076a,
    0x041d82a0,0x43511015,0x2af21828,0x24d224ba,0x2a904848,0x1c473001,
    0x2090c824,0x40cb800c,0xca8001da,0x666e404d,0x26002e1e,0x05c981ee,
    0x3880b892,0x12162012,0x72491055,0x03999d99,0x805c8f4c,0x412600a9,
    0x0350d40b,0x3a039730,0x37733a02,0x10120b81,0x8243501b,0x0064120c,
    0x0b6a065c,0x90550fd8,0x36224f62,0x490cc241,0x900d9b84,0xccce8370,
    0x401b102d,0x55b30914,0x401903b5,0x0ed401da,0xabca8be2,0x26df30cc,
    0x22dbabbc,0x003bbcc9,0x8482c4e6,0x2120a648,0x1ba400d8,0x0d999988,
    0x02d980c8,0x06a865c0,0x00202022,0x12200044,0x45709093,0x1220b80c,
    0x8012a602,0x000a0304,0x00015188,0x98000000,0x453b21de,0x23ccccec,
    0x376e1ceb,0x99999991,0x32a00f60,0x0000002e,0x00000000,0x00000000,
    0x00000000,0x00000000,0x00000000,0x39971000,0x0faa3d88,0xbd30736a,
    0x37665ea8,0xbc89b912,0x3db83dca,0x57223b91,0x95970cc9,0x99b09b55,
    0x8854c5b9,0x072a973d,0x227b102e,0x2120ae0c,0x48770ec4,0x48388350,
    0x641547d0,0x8ef206e1,0x1aa647a1,0x0fd83224,0x7ddf69f1,0x3e625d41,
    0x09070175,0x2e240d49,0x224125b0,0x2090b01a,0x05901c9c,0x10a21724,
    0x7f13e0e4,0x9107cdb2,0x666c1122,0x4240dccc,0x530d4124,0x14c12991,
    0xd024240b,0xb9202407,0x30ae0510,0x2b72e81f,0x40ea2c78,0x4909000b,
    0x5e40c80b,0x4d2048c9,0x64121203,0x480901c9,0x1541442e,0x298641e4,
    0x2201010e,0x2e240884,0x90911224,0x9a80b269,0x2121200c,0x0120ae1c,
    0x542885c9,0x00000a43,0xcbbc9800,0xe9bbca84,0x02f2f262,0x6c00f8f2,
    0xec8fb204,0x3225db12,0x999d953f,0x14b9f5c1,0x3337e23d,0x0000005c,
    0x04400880,0x00000040,0x00000000,0x00000000,0x00000000,0x44000000,
    0x40208888,0x333100ca,0x5c333333,0x007fffff,0x00000000,0x00000000,
    0x66664400,0x98932ccc,0x54493593,0x2aaaaaaa,0x00000000,0x00000000,
    0x00000000,0x07502c40,0x00000000,0x00000000,0x00000000,0x33333220,
    0x000002cc,0x00000000,0x00000000,0x00000000,0x00000000,0x00000000,
    0x00000000,
};

static signed short stb__courier_18_usascii_x[95]={ 0,3,2,1,1,1,1,3,4,2,0,1,2,1,
3,1,1,1,1,1,1,1,2,1,1,2,3,2,0,0,0,0,1,0,0,0,1,0,1,0,0,1,1,0,
0,0,0,0,1,0,0,1,1,0,0,0,0,0,1,0,0,0,1,0,3,1,0,1,0,0,1,0,0,1,
1,1,1,0,0,1,0,0,1,1,1,0,0,0,0,1,1,0,4,0,1, };
static signed short stb__courier_18_usascii_y[95]={ 13,3,3,2,2,3,4,3,3,3,3,4,10,8,
11,2,3,3,3,3,3,3,3,3,3,3,6,6,4,6,4,3,2,3,3,3,3,3,3,3,3,3,3,3,
3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,2,3,3,16,2,6,3,6,3,6,3,6,3,2,
2,3,3,6,6,6,6,6,6,6,3,6,6,6,6,6,6,3,3,3,7, };
static unsigned short stb__courier_18_usascii_w[95]={ 0,3,6,8,7,8,7,3,4,3,6,8,4,8,
3,7,7,7,7,7,7,7,7,7,7,7,3,4,8,9,8,6,7,10,9,9,8,9,8,9,9,7,9,10,
9,10,9,8,8,9,10,8,8,9,10,10,9,9,7,3,6,3,7,11,4,8,9,8,10,9,8,9,9,8,
6,9,8,10,9,8,9,10,8,7,8,9,10,10,9,9,7,4,2,4,8, };
static unsigned short stb__courier_18_usascii_h[95]={ 0,11,5,13,13,11,10,5,13,13,6,9,6,1,
3,13,11,10,10,11,10,11,11,11,11,11,8,9,9,4,9,11,13,10,10,11,10,10,10,11,10,10,11,10,
10,10,10,11,10,12,10,11,10,11,10,10,10,10,10,13,13,13,5,2,4,8,11,8,11,8,10,10,10,11,
14,10,10,7,7,8,10,10,7,8,11,8,7,8,7,10,7,13,13,13,3, };
static unsigned short stb__courier_18_usascii_s[95]={ 88,116,109,8,30,9,96,105,38,43,121,
59,100,77,124,55,99,89,32,1,51,36,52,71,44,120,99,86,77,41,68,
1,47,21,11,117,116,106,97,106,79,71,89,52,42,31,21,97,1,78,104,
27,87,107,40,56,1,36,63,74,67,63,116,65,51,103,79,112,60,1,8,
67,77,18,1,26,17,81,52,21,46,10,72,91,88,11,41,30,62,115,92,
25,22,17,56, };
static unsigned short stb__courier_18_usascii_t[95]={ 13,1,62,1,1,16,28,62,1,1,51,
51,62,70,62,1,16,40,51,16,51,16,16,16,16,1,51,51,51,70,51,
28,1,51,51,16,40,40,40,1,40,40,16,40,40,40,40,1,40,1,28,
16,28,16,51,28,51,28,40,1,1,1,62,70,70,51,16,51,16,62,28,
28,28,16,1,28,28,62,62,62,28,40,62,51,1,62,62,62,62,28,62,
1,1,1,70, };
static unsigned short stb__courier_18_usascii_a[95]={ 153,153,153,153,153,153,153,153,
153,153,153,153,153,153,153,153,153,153,153,153,153,153,153,153,
153,153,153,153,153,153,153,153,153,153,153,153,153,153,153,153,
153,153,153,153,153,153,153,153,153,153,153,153,153,153,153,153,
153,153,153,153,153,153,153,153,153,153,153,153,153,153,153,153,
153,153,153,153,153,153,153,153,153,153,153,153,153,153,153,153,
153,153,153,153,153,153,153, };

// Call this function with
//    font: NULL or array length
//    data: NULL or specified size
//    height: STB_FONT_courier_18_usascii_BITMAP_HEIGHT or STB_FONT_courier_18_usascii_BITMAP_HEIGHT_POW2
//    return value: spacing between lines
static void stb_font_courier_18_usascii(stb_fontchar font[STB_FONT_courier_18_usascii_NUM_CHARS],
                unsigned char data[STB_FONT_courier_18_usascii_BITMAP_HEIGHT][STB_FONT_courier_18_usascii_BITMAP_WIDTH],
                int height)
{
    int i,j;
    if (data != 0) {
        unsigned int *bits = stb__courier_18_usascii_pixels;
        unsigned int bitpack = *bits++, numbits = 32;
        for (i=0; i < STB_FONT_courier_18_usascii_BITMAP_WIDTH*height; ++i)
            data[0][i] = 0;  // zero entire bitmap
        for (j=1; j < STB_FONT_courier_18_usascii_BITMAP_HEIGHT-1; ++j) {
            for (i=1; i < STB_FONT_courier_18_usascii_BITMAP_WIDTH-1; ++i) {
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
        float recip_width = 1.0f / STB_FONT_courier_18_usascii_BITMAP_WIDTH;
        float recip_height = 1.0f / height;
        for (i=0; i < STB_FONT_courier_18_usascii_NUM_CHARS; ++i) {
            // pad characters so they bilerp from empty space around each character
            font[i].s0 = (stb__courier_18_usascii_s[i]) * recip_width;
            font[i].t0 = (stb__courier_18_usascii_t[i]) * recip_height;
            font[i].s1 = (stb__courier_18_usascii_s[i] + stb__courier_18_usascii_w[i]) * recip_width;
            font[i].t1 = (stb__courier_18_usascii_t[i] + stb__courier_18_usascii_h[i]) * recip_height;
            font[i].x0 = stb__courier_18_usascii_x[i];
            font[i].y0 = stb__courier_18_usascii_y[i];
            font[i].x1 = stb__courier_18_usascii_x[i] + stb__courier_18_usascii_w[i];
            font[i].y1 = stb__courier_18_usascii_y[i] + stb__courier_18_usascii_h[i];
            font[i].advance_int = (stb__courier_18_usascii_a[i]+8)>>4;
            font[i].s0f = (stb__courier_18_usascii_s[i] - 0.5f) * recip_width;
            font[i].t0f = (stb__courier_18_usascii_t[i] - 0.5f) * recip_height;
            font[i].s1f = (stb__courier_18_usascii_s[i] + stb__courier_18_usascii_w[i] + 0.5f) * recip_width;
            font[i].t1f = (stb__courier_18_usascii_t[i] + stb__courier_18_usascii_h[i] + 0.5f) * recip_height;
            font[i].x0f = stb__courier_18_usascii_x[i] - 0.5f;
            font[i].y0f = stb__courier_18_usascii_y[i] - 0.5f;
            font[i].x1f = stb__courier_18_usascii_x[i] + stb__courier_18_usascii_w[i] + 0.5f;
            font[i].y1f = stb__courier_18_usascii_y[i] + stb__courier_18_usascii_h[i] + 0.5f;
            font[i].advance = stb__courier_18_usascii_a[i]/16.0f;
        }
    }
}

#ifndef STB_SOMEFONT_CREATE
#define STB_SOMEFONT_CREATE              stb_font_courier_18_usascii
#define STB_SOMEFONT_BITMAP_WIDTH        STB_FONT_courier_18_usascii_BITMAP_WIDTH
#define STB_SOMEFONT_BITMAP_HEIGHT       STB_FONT_courier_18_usascii_BITMAP_HEIGHT
#define STB_SOMEFONT_BITMAP_HEIGHT_POW2  STB_FONT_courier_18_usascii_BITMAP_HEIGHT_POW2
#define STB_SOMEFONT_FIRST_CHAR          STB_FONT_courier_18_usascii_FIRST_CHAR
#define STB_SOMEFONT_NUM_CHARS           STB_FONT_courier_18_usascii_NUM_CHARS
#define STB_SOMEFONT_LINE_SPACING        STB_FONT_courier_18_usascii_LINE_SPACING
#endif

