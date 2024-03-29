// Font generated by stb_font_inl_generator.c (4/1 bpp)
//
// Following instructions show how to use the only included font, whatever it is, in
// a generic way so you can replace it with any other font by changing the include.
// To use multiple fonts, replace STB_SOMEFONT_* below with STB_FONT_times_bold_13_usascii_*,
// and separately install each font. Note that the CREATE function call has a
// totally different name; it's just 'stb_font_times_bold_13_usascii'.
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

#define STB_FONT_times_bold_13_usascii_BITMAP_WIDTH         128
#define STB_FONT_times_bold_13_usascii_BITMAP_HEIGHT         58
#define STB_FONT_times_bold_13_usascii_BITMAP_HEIGHT_POW2    64

#define STB_FONT_times_bold_13_usascii_FIRST_CHAR            32
#define STB_FONT_times_bold_13_usascii_NUM_CHARS             95

#define STB_FONT_times_bold_13_usascii_LINE_SPACING           8

static unsigned int stb__times_bold_13_usascii_pixels[]={
    0x220c98c4,0x89911d44,0xbaaa984c,0x83977101,0x504030cc,0x57106a55,
    0x862aa079,0x26c2a9a9,0x59730dd6,0x42daa82c,0x4912d448,0x1dc5c878,
    0xf706606e,0x43d93a23,0x7f31cc0c,0x3a1fa82e,0x127c5ec4,0x3747f5df,
    0x99e89691,0x9788171c,0x96e0ec1f,0xb903e248,0x54371544,0x646e8929,
    0x24a87b0f,0x15b62df9,0x2a1f91ba,0x9fc49f1f,0x6e55366e,0x137f71ea,
    0x3e4e0e61,0x2449903e,0x6d8b907e,0x156d9e92,0x27f713e6,0x9f33cc3d,
    0xf30dfd41,0x1f73fb89,0xfb3f893e,0xd9ac895c,0x0b09fd10,0x881f50f4,
    0x424c910d,0x929b6c5c,0x9f50d3ab,0x887b4fa8,0xdd07f11f,0xa7d44fa8,
    0x7c49f2f9,0x2b0d4bd3,0x237ec439,0x3d40a80c,0x0dc912b8,0x8d5b62e4,
    0x4432f9bf,0x3d8fe46f,0x83f897c4,0x2e37c43b,0x93efb21f,0x821fcdf8,
    0x4c3efefc,0x020e62fd,0x449703e2,0xb17207c4,0x32be266d,0x20fd8317,
    0x1f30f66e,0x6c04c1fc,0x7c21b60f,0x2a02fe24,0x31516912,0x1b8583d3,
    0x912e41e8,0x362e41f8,0x3a73a716,0x56d41899,0x16a1ec3c,0x80b321bb,
    0x200dcadc,0x740fe24f,0x7b516555,0x7c419097,0x135c3a83,0x17207c49,
    0x050054db,0x90f61be2,0x10028805,0x2a199500,0x010400bc,0x2000406a,
    0x4488f209,0xcd9aec1d,0x05310d44,0x9b0bed98,0x000000c4,0x00000000,
    0x13080000,0x04c43050,0x066a2055,0x02131000,0x00000000,0x00000000,
    0x00000000,0x00000000,0x00000000,0x00000000,0x47779930,0x21220cba,
    0x55442bba,0x221db309,0x01b7503c,0x50c83e98,0x05dcc05d,0xdd30776a,
    0x2215503d,0x2ea2eeee,0x0e5d42bb,0x3f3445f5,0x3e20647d,0x93f10f88,
    0x9877e43f,0x007b7881,0x1fc4b09f,0x226a9e88,0x77645fab,0x3ea0ec45,
    0x4cd10fee,0xf9ae3e63,0x7b3f1286,0x233ea0aa,0x1f51f70f,0x809afe54,
    0x7100c9fa,0x223889f3,0x47d429bf,0x6c3e80fa,0x44309d01,0x2e193e66,
    0x4fa9fa8f,0x2446de40,0x7445dfb0,0xbfd945c9,0x916fa809,0x27ddf445,
    0xf9df886e,0x0bea3ee3,0x77fd43f7,0x40fb3e22,0x20f7f43a,0xfbaf99fa,
    0x22320804,0x1bfae0bb,0x3a250357,0x7e55c0bf,0xf8fd41b3,0x6cfe22c4,
    0x0bea3ee6,0x75cc4ff7,0x1f73f70f,0xffc883b0,0x23f37623,0x4aa005f9,
    0x32f54cbc,0x8599f32f,0xf983fe62,0xfb839fd1,0x222449f0,0x47d4fb3f,
    0x80fb81fa,0xf33f72f8,0x3a618d05,0x3f66c887,0x7d244140,0x0fc5aed7,
    0x21c7fddd,0x457ea0fa,0x47e61aff,0x7f106e4f,0x7a9f8976,0x43124c26,
    0x3f15f30c,0xb51d43a8,0xbec81d30,0x2a0c80bb,0x8eeb62cc,0x0f4cae4b,
    0x59dfb032,0xfcec87fd,0x59d10b0d,0x22dcb81d,0x3ea0abfc,0x1dedc1ad,
    0x2b36a0ec,0x802ea21b,0x02206200,0x00d5d402,0x10081100,0x00010020,
    0x10000801,0x00000440,0x00000000,0x00000000,0x00000000,0x19800000,
    0x220ef5c4,0x260cccba,0x5c7913ed,0x12ed98de,0xb877aa39,0x267dd30d,
    0x37af6e3d,0x97db32db,0x303e9819,0xb88579db,0x2607d33c,0x8ef543ed,
    0x545f885e,0xfb03a21f,0xc9fe0d41,0x41fd0e2f,0x48a7e419,0x4516f85c,
    0xf81fb0fd,0x3ea3f204,0x4f867722,0xbf91fee0,0x22fc404c,0x7ec0985e,
    0x25f90260,0xfa8515f9,0x1d7f40e3,0xfb04df04,0x39f07f21,0xbf11f905,
    0x29f07ba6,0x997e5c2a,0x5f8805fa,0x7ec013e6,0x2bf10260,0xdf028feb,
    0x07fcc062,0x47ec1be0,0xfaef86e8,0x97dcfe43,0xca7c0ee8,0x8bb7c5c0,
    0x3e20b25f,0x99893ee5,0x01307ec1,0x77f553fb,0xb00ebf20,0xb06f809f,
    0x53e0df9f,0x055fe44f,0x0333e17a,0x7c54fece,0xf8889fe5,0x1fd17e64,
    0x202a0fd8,0x1ff88efa,0x4c05df10,0x1be02fe9,0x41fe47ec,0x0fc89f4f,
    0x9fdf0bd0,0x7c5be670,0x7f3bb1c5,0x03f60fd8,0x9f01c3f7,0x81f60364,
    0x201ff129,0x3a1fb06f,0x44fa7c1f,0xf0bd00fc,0x3a385f59,0x304cbf13,
    0x5b901d99,0x2fb60bd3,0x3987201b,0x2fa81cc0,0xfa81bfd1,0x997f441f,
    0xf3bf30ef,0x441ff44d,0x757e60ef,0x42a3d31f,0x00401efa,0x00080044,
    0x00000000,0x00000000,0x00000000,0x00000000,0x00000000,0x00000000,
    0xd9800000,0x3ed980be,0x545d0b6e,0x22fb662e,0x3dd51dea,0xbed9865c,
    0x77db34db,0x5e76cc9b,0x5ebace83,0x03333b66,0x07db3038,0x3f60012a,
    0x0c87f201,0x90fe21d8,0x3f637c3f,0x43f906a2,0x6c487f64,0x8e21bd0f,
    0x447ec2fd,0x6c0f506f,0xb04f881f,0xf9007ec0,0x86a60713,0xf0fe43f8,
    0x20e6f88d,0x7e4131fc,0x50fd8119,0x85fa829f,0x3a0df0fc,0x703f902f,
    0xfd81609d,0x03eff200,0x87f11fc4,0x86f99afc,0x5f903bfc,0x05afc857,
    0x11be61fb,0x97f901ff,0x0df3303b,0x9d1707f2,0x04ceccc4,0xcfc803f6,
    0x23f880ef,0x4d7e43f8,0x2ff886f9,0xc85b7f90,0x21fb06bf,0x81fe46f8,
    0x384fb9fc,0x43f903fb,0x55549d19,0x07ec1aae,0x5fb9fc86,0x0fe23f88,
    0xd837c3f9,0x513f900f,0xd8219fc8,0x7ccbf50f,0x361f90c6,0x3f2b221f,
    0x3f61fc85,0x20582fff,0xfc86a1fd,0x3f887fb1,0x43f90fe2,0x201fb06f,
    0x43fb01fc,0x7e43f60b,0x23987fa1,0x1c1fb0fd,0x43fb03fa,0x580de998,
    0xf959fd10,0x7d4ffa21,0xfa97ea4f,0x2a2ffa25,0x5ff4c1ff,0x205ff440,
    0x27dbcfe8,0x21ddbfe9,0x2fcbaefb,0x43999fd1,0x1bfb10ea,0x2740ffa2,
    0x00000008,0x00000000,0x00000000,0x00000000,0xea8b5000,0x3055440d,
    0x46a66a63,0x4663530a,0x980a88a8,0x83302982,0xa8cc01a9,0x8a26a200,
    0x173399a8,0x53155544,0x03261515,0x7e6c4df5,0xbd2eda25,0x1d3e2be6,
    0x7c42e7f3,0x4d9d87f3,0x93d16aba,0xda825665,0x205b930b,0x4f7c6cdf,
    0x22a5eadf,0x147744f9,0x04dd05f5,0x36c6c4bd,0x7ecef411,0x7c2b6c18,
    0x19bcc7f3,0x263f31f3,0x19f55c9f,0x71016e44,0xf82fc17b,0x3a1b6bd4,
    0x1984fa86,0xa87d06e8,0x2fee07dc,0x1bfa84f9,0x3ee3f9fc,0x97cc7dc0,
    0x3f2089fb,0x3002faa5,0xf827c3b9,0xf51b6bd4,0x0311ba05,0xf31661ba,
    0xf115cfb1,0x42f413a5,0x9fc47f3f,0x21f31f10,0x3dc613f9,0x36a0e6cc,
    0x9f04f80c,0xbf136d7a,0x007f710a,0xf30321ba,0xb17a3f99,0x415c06e1,
    0x7dc5fbed,0x70aeee1d,0x12f2a1bf,0x40592b88,0x6fc40df8,0x90fe8ef8,
    0x46ccb99f,0x46e801fe,0x0000dcdc,0x00020000,0x00008000,0x00000000,
    0x23ff3000,0x0007fffa,0x00000000,0x00000000,0x00000000,0x8a880000,
    0x2e0b1029,0x88f45ec2,0x3a099999,0x0c882001,0x4c666666,0x00000099,
    0x00000000,0x417d77c0,0x2aae23cc,0x54be33a3,0xf11bbbbb,0x262fb665,
    0x87e61f31,0xd93bbbbb,0x0000007d,0x00000000,0x4887f3f8,0x8ef2e21b,
    0x2aa61d2c,0x0c3a0aaa,0x002a87b5,0x00000000,0x00000000,0x0d89f3f8,
    0x50e65493,0xbbbba8e1,0x00000e1b,0x00000000,0x00000000,0x044f9fc0,
    0x00088982,0x00000000,0x00000000,0x00000000,0x017e77e6,0x00000000,
    0x00000000,0x00000000,0x00000000,0x00000000,0x00000000,0x00000000,
    0x00000000,
};

static signed short stb__times_bold_13_usascii_x[95]={ 0,1,1,0,0,0,0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,0,0,-1,0,0,0,0,0,0,0,0,0,0,
-1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0, };
static signed short stb__times_bold_13_usascii_y[95]={ 10,2,2,2,2,2,2,2,2,2,2,2,8,6,
8,2,2,2,2,2,2,2,2,2,2,2,4,4,3,4,3,2,2,2,2,2,2,2,2,2,2,2,2,2,
2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,11,1,4,2,4,2,4,2,4,2,2,
2,2,2,4,4,4,4,4,4,4,2,4,4,4,4,4,4,2,2,2,5, };
static unsigned short stb__times_bold_13_usascii_w[95]={ 0,2,5,6,6,11,10,3,4,4,6,7,3,4,
3,4,6,5,6,6,6,6,6,6,6,6,2,4,7,7,7,6,11,9,8,8,8,8,7,10,9,5,6,10,
8,11,9,9,7,9,9,7,8,9,9,12,9,9,8,3,4,3,6,7,3,6,7,5,7,5,5,6,7,4,
4,7,4,10,7,6,7,7,6,5,4,7,6,9,6,6,6,5,2,4,7, };
static unsigned short stb__times_bold_13_usascii_h[95]={ 0,9,4,9,9,9,9,4,11,11,5,8,5,2,
3,9,9,8,8,9,8,9,9,9,9,9,7,9,6,4,6,9,11,8,8,9,8,8,8,9,8,8,9,8,
8,8,9,9,8,11,8,9,8,9,9,9,8,8,8,11,9,11,5,2,3,7,9,7,9,7,8,9,8,8,
11,8,8,6,6,7,9,9,6,7,9,7,7,7,6,9,6,11,11,11,3, };
static unsigned short stb__times_bold_13_usascii_s[95]={ 127,98,36,101,108,10,46,50,1,55,29,
118,122,78,66,65,78,1,7,85,111,92,99,106,22,121,21,1,74,42,82,
120,29,95,86,1,68,59,51,13,31,105,6,10,1,116,36,72,94,41,76,
113,67,24,47,34,57,41,77,51,115,20,22,70,62,14,70,49,57,62,102,
29,86,21,24,108,26,97,14,55,90,82,90,68,60,41,34,24,115,65,108,
14,11,6,54, };
static unsigned short stb__times_bold_13_usascii_t[95]={ 1,1,50,1,1,13,13,50,1,1,50,
33,42,50,50,13,13,42,42,13,33,13,13,13,13,13,42,23,42,50,42,
1,1,33,33,13,33,33,33,23,33,33,23,33,33,23,13,1,23,1,23,
13,23,23,23,23,23,33,33,1,1,1,50,50,50,42,13,42,13,42,23,
13,23,33,1,23,33,42,50,42,1,1,42,42,1,42,42,42,42,1,42,
1,1,1,50, };
static unsigned short stb__times_bold_13_usascii_a[95]={ 47,63,104,94,94,188,156,52,
63,63,94,107,47,63,47,52,94,94,94,94,94,94,94,94,
94,94,63,63,107,107,107,94,175,136,125,136,136,125,115,146,
146,73,94,146,125,177,136,146,115,146,136,104,125,136,136,188,
136,136,125,63,52,63,109,94,63,94,104,83,104,83,63,94,
104,52,63,104,52,156,104,94,104,104,83,73,63,104,94,136,
94,94,83,74,41,74,98, };

// Call this function with
//    font: NULL or array length
//    data: NULL or specified size
//    height: STB_FONT_times_bold_13_usascii_BITMAP_HEIGHT or STB_FONT_times_bold_13_usascii_BITMAP_HEIGHT_POW2
//    return value: spacing between lines
static void stb_font_times_bold_13_usascii(stb_fontchar font[STB_FONT_times_bold_13_usascii_NUM_CHARS],
                unsigned char data[STB_FONT_times_bold_13_usascii_BITMAP_HEIGHT][STB_FONT_times_bold_13_usascii_BITMAP_WIDTH],
                int height)
{
    int i,j;
    if (data != 0) {
        unsigned int *bits = stb__times_bold_13_usascii_pixels;
        unsigned int bitpack = *bits++, numbits = 32;
        for (i=0; i < STB_FONT_times_bold_13_usascii_BITMAP_WIDTH*height; ++i)
            data[0][i] = 0;  // zero entire bitmap
        for (j=1; j < STB_FONT_times_bold_13_usascii_BITMAP_HEIGHT-1; ++j) {
            for (i=1; i < STB_FONT_times_bold_13_usascii_BITMAP_WIDTH-1; ++i) {
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
        float recip_width = 1.0f / STB_FONT_times_bold_13_usascii_BITMAP_WIDTH;
        float recip_height = 1.0f / height;
        for (i=0; i < STB_FONT_times_bold_13_usascii_NUM_CHARS; ++i) {
            // pad characters so they bilerp from empty space around each character
            font[i].s0 = (stb__times_bold_13_usascii_s[i]) * recip_width;
            font[i].t0 = (stb__times_bold_13_usascii_t[i]) * recip_height;
            font[i].s1 = (stb__times_bold_13_usascii_s[i] + stb__times_bold_13_usascii_w[i]) * recip_width;
            font[i].t1 = (stb__times_bold_13_usascii_t[i] + stb__times_bold_13_usascii_h[i]) * recip_height;
            font[i].x0 = stb__times_bold_13_usascii_x[i];
            font[i].y0 = stb__times_bold_13_usascii_y[i];
            font[i].x1 = stb__times_bold_13_usascii_x[i] + stb__times_bold_13_usascii_w[i];
            font[i].y1 = stb__times_bold_13_usascii_y[i] + stb__times_bold_13_usascii_h[i];
            font[i].advance_int = (stb__times_bold_13_usascii_a[i]+8)>>4;
            font[i].s0f = (stb__times_bold_13_usascii_s[i] - 0.5f) * recip_width;
            font[i].t0f = (stb__times_bold_13_usascii_t[i] - 0.5f) * recip_height;
            font[i].s1f = (stb__times_bold_13_usascii_s[i] + stb__times_bold_13_usascii_w[i] + 0.5f) * recip_width;
            font[i].t1f = (stb__times_bold_13_usascii_t[i] + stb__times_bold_13_usascii_h[i] + 0.5f) * recip_height;
            font[i].x0f = stb__times_bold_13_usascii_x[i] - 0.5f;
            font[i].y0f = stb__times_bold_13_usascii_y[i] - 0.5f;
            font[i].x1f = stb__times_bold_13_usascii_x[i] + stb__times_bold_13_usascii_w[i] + 0.5f;
            font[i].y1f = stb__times_bold_13_usascii_y[i] + stb__times_bold_13_usascii_h[i] + 0.5f;
            font[i].advance = stb__times_bold_13_usascii_a[i]/16.0f;
        }
    }
}

#ifndef STB_SOMEFONT_CREATE
#define STB_SOMEFONT_CREATE              stb_font_times_bold_13_usascii
#define STB_SOMEFONT_BITMAP_WIDTH        STB_FONT_times_bold_13_usascii_BITMAP_WIDTH
#define STB_SOMEFONT_BITMAP_HEIGHT       STB_FONT_times_bold_13_usascii_BITMAP_HEIGHT
#define STB_SOMEFONT_BITMAP_HEIGHT_POW2  STB_FONT_times_bold_13_usascii_BITMAP_HEIGHT_POW2
#define STB_SOMEFONT_FIRST_CHAR          STB_FONT_times_bold_13_usascii_FIRST_CHAR
#define STB_SOMEFONT_NUM_CHARS           STB_FONT_times_bold_13_usascii_NUM_CHARS
#define STB_SOMEFONT_LINE_SPACING        STB_FONT_times_bold_13_usascii_LINE_SPACING
#endif

