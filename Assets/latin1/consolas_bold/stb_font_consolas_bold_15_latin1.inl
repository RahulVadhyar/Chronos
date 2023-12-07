// Font generated by stb_font_inl_generator.c (4/1 bpp)
//
// Following instructions show how to use the only included font, whatever it is, in
// a generic way so you can replace it with any other font by changing the include.
// To use multiple fonts, replace STB_SOMEFONT_* below with STB_FONT_consolas_bold_15_latin1_*,
// and separately install each font. Note that the CREATE function call has a
// totally different name; it's just 'stb_font_consolas_bold_15_latin1'.
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

#define STB_FONT_consolas_bold_15_latin1_BITMAP_WIDTH         256
#define STB_FONT_consolas_bold_15_latin1_BITMAP_HEIGHT         86
#define STB_FONT_consolas_bold_15_latin1_BITMAP_HEIGHT_POW2   128

#define STB_FONT_consolas_bold_15_latin1_FIRST_CHAR            32
#define STB_FONT_consolas_bold_15_latin1_NUM_CHARS            224

#define STB_FONT_consolas_bold_15_latin1_LINE_SPACING          10

static unsigned int stb__consolas_bold_15_latin1_pixels[]={
    0x2151f6fb,0x00aa800a,0x800c8326,0x00ab980c,0x80e4cb2a,0x1e66402a,
    0x5c026200,0x403104cc,0x0a8a0229,0x02620440,0x03101980,0x19801514,
    0x4c00dc88,0x01981aaa,0x545008a6,0x2a806200,0xbfa9f6fb,0x1fec04f9,
    0x37c53f20,0xdf707f60,0x5df701df,0x1be13fa6,0x360bfdd0,0xd81fe883,
    0x7fd40eef,0x4efffa84,0x02fc5fd4,0x03fd1136,0xfa82fe88,0xf8bfa84f,
    0x705fd105,0x3fa60b79,0x77544fff,0x4efffa84,0x05f8bfa8,0x3fa09ff5,
    0x0b8fb7d8,0x00e4c017,0x0bf3064c,0x25f50fee,0x906e84e8,0x3a00df0f,
    0x80e7dcc5,0x2a06d82a,0x77080a89,0x0370c881,0x2a05fb93,0xa8054c02,
    0x86440a89,0x2015301b,0xff883ee9,0x6644f8ff,0x02ee106a,0xa80dc322,
    0x8fe80a89,0x02a6fb7d,0x2a054c55,0x05555542,0x0bf10bee,0x4f86b89d,
    0x8df83f50,0x64bd00bb,0xc986ffff,0x93036c3d,0x0f72607b,0x7dc1ee4c,
    0x87265fef,0x443932c8,0x6443932c,0x16443932,0x6c40f726,0xffffa81d,
    0x0f7444f8,0x2201cc88,0x332201cc,0x6df6fd01,0x2fc47f77,0x22fc47f7,
    0xf83ffffe,0x3ea17dc5,0xf87ceed9,0xef83f504,0x5e80efff,0x702f5bf3,
    0x36cdffff,0x46ffffb8,0x5c6ffffb,0x3e26ffff,0x3ea7ffb5,0x1fd53e23,
    0x88fea9f1,0x7c47f54f,0x1bfffee4,0x3ea17fee,0x224f8fff,0xff702cca,
    0x02ffdc0b,0x5f60bff7,0x9be2fb7d,0xb9be22fb,0x20fea02f,0x3207f46e,
    0x0fafcfbe,0x27c40fe6,0x41fe4ffe,0x0d7df35e,0x7fb11df1,0x23be21b6,
    0x1df13fd8,0x3be27fb1,0x5f73fd88,0x3eabf7f1,0x1fd53e23,0x88fea9f1,
    0x7c47f54f,0xfb11df14,0x887efd87,0x24f8ffff,0xd85feefc,0x3bf607ef,
    0x41fbf607,0x3f20fb7d,0x23f90fd1,0x41fd407e,0x361be0fc,0x0fafbddc,
    0x7dc01bfb,0x27ccdf0f,0x5fffd2f4,0x57e62fb8,0x262fb86d,0x7cc5f75f,
    0xafcc5f75,0x6f8fa8fc,0xaa7c47f5,0x7d53e23f,0x1fd53e23,0x98bee9f1,
    0x0fe6fc5f,0x27c7ff4c,0x6fc0fd81,0xf9bf01fc,0x07f37e03,0xf983edf6,
    0xcf984f9c,0x1fd404f9,0xd0dd0fdc,0x4f5f79d9,0xdd101feb,0x09f337c7,
    0x5fffb8bd,0xb6f887f2,0x7c43f90d,0xb7c43f96,0x6dbe21fc,0x2afd5d8f,
    0x7d53e23f,0x1fd53e23,0x88fea9f1,0x7c43f94f,0x13e6bea6,0x4c4f8988,
    0x3ea1feca,0xafa84f9a,0x9afa84f9,0x2fb7c84f,0x07e7f418,0x400fcfe8,
    0x20fd83fa,0x675f40fd,0x1fc46bec,0x537c1fa8,0x9d0bd07f,0xf07f65fd,
    0x07f61b6f,0xff07f6ff,0x2eff07f6,0x2abf3f9f,0x7d53e23f,0x1fd53e23,
    0x88fea9f1,0x7f83fb4f,0x4037c3f2,0x3bbf24f8,0x7c3f21ff,0x0df0fc86,
    0xb01be1f9,0xbff71f6f,0x402ffdc0,0x5c6f83fa,0x7fee741f,0x504f83ff,
    0xfaaef83f,0x9f85e80f,0xf85f93fb,0x85f90db5,0x5f85f95f,0xf55f85f9,
    0x2a9f31fb,0x7d53e63f,0x1fd53e63,0x98fea9f3,0x5f85f94f,0x03faabfa,
    0x97e29f10,0x2abfa1fc,0x557f40fe,0x557f40fe,0x6c7f40fe,0x2ff88fb7,
    0x200bfe20,0x21fd43fa,0x64eec5f9,0x209f03a8,0x7fffc1fa,0x3aabd01e,
    0xf50ffdfc,0x86da7d49,0x553ea4fa,0x7d53ea4f,0xffe93ea4,0x49f30feb,
    0x549f33fa,0x7d49f33f,0x9fd49f33,0x4d3ea4fa,0x83ffffff,0x7fc4fee1,
    0xff31ffca,0x7cc7ffff,0x263fffff,0x43ffffff,0x8fb7d8fe,0x37c406f8,
    0x3e22fb80,0x7dc7f906,0x2e0bb000,0x40077c0f,0xbdffd35e,0xffbeff81,
    0x3bfe0db0,0x3bfe0ffb,0x3bfe0ffb,0x3fe20ffb,0x55ffc1ef,0x2affe0fe,
    0x2affe0fe,0x2affe0fe,0x2fbfe0fe,0x335f70ff,0xeef88bf5,0x3bfee0ff,
    0x335f71fb,0x4d7dcbf5,0x2bee5fa9,0xb085fa99,0x7f5cdf6f,0x03fd7301,
    0x83feeb62,0x47f601fe,0x01b9aef8,0x3ee239f7,0x55406f86,0xd103545f,
    0x57ec3dff,0x0f7ff442,0x107bffa2,0xf983dffd,0xdffd3009,0x1effe983,
    0x20f7ff4c,0x441effe9,0x1f61effe,0x2f7261fa,0x21f60100,0x9fa1f67e,
    0x3607e87d,0x07bf2fb7,0x2201efc8,0x3621effe,0xb106c402,0x6d403bff,
    0xdf01bd54,0x5c5fff80,0xffb01004,0x0200201f,0x80254020,0x20044008,
    0x40044008,0x00000000,0x00000000,0x003edf60,0x00000000,0x00000000,
    0x00000000,0x00000000,0x00000000,0x00000000,0x00000000,0x00000000,
    0x00000000,0x00000000,0x00000000,0x00000000,0x00000000,0x00000000,
    0x00000000,0x00000000,0x00000000,0x00000000,0x00000000,0x00000000,
    0x00000000,0x00000000,0x00000000,0x40330000,0x2620ccca,0x30006a00,
    0x88033003,0x3015140a,0x1f100799,0x554004c4,0x4c03102a,0x20330022,
    0x40a8a018,0x55440098,0x81442981,0x0542a029,0x0aa82aa0,0xa8002aa0,
    0x2a02980a,0x5fd1010a,0x5ffffd10,0x7d80ff44,0x405fd100,0x3ec02fe8,
    0x717e2fea,0x980dffff,0xb00ff447,0xff50ffff,0x9dfff509,0x2a0bfa20,
    0x8bfa84ff,0x80ff445f,0x2a4ffff9,0x2a1766ef,0x9bfa84ef,0x30ff604f,
    0x3be601df,0xa83fd800,0xfffa84ef,0xb00a984e,0x1540449f,0xa9802fa8,
    0x20054c00,0xb86444f8,0x3623be21,0x03fb503f,0x093e6055,0x080a89a8,
    0x02a60177,0x220544d4,0x0aa0370c,0x367e87ec,0x40fa8f8d,0xb81c89c8,
    0x07260170,0x79101e44,0xc881c980,0x77081c89,0x881cc881,0x6665406f,
    0x9706e84c,0x66544b81,0x03f204cc,0x5c999995,0xd117e62f,0x665cbfff,
    0x3fe20ccc,0x99999502,0xb8b22644,0x2e0ccccc,0x2e0ccccc,0x440ccccc,
    0xf16f81cc,0x7cfe6dcd,0x20597102,0x97102cb8,0x20b2e605,0xa882cca8,
    0xcca882cc,0x82cca882,0x4f985ffb,0x7ffffe40,0x7d40fdc0,0xff913e64,
    0x17e01fff,0x43fffff2,0x3637c1fc,0x3b61cdbf,0x3f60eeff,0x7fe40dff,
    0x5ff30fff,0xdffdb27c,0x77ff6c1d,0x3bffb60e,0x42ffdc0e,0x6c43fd6f,
    0xff305dbf,0xeff98bfd,0x7f7fcc5f,0x2ffffd45,0x917fbbf2,0xfc8bfddf,
    0x77e45fee,0x3f7ec5fe,0x3f2027d4,0xe827c400,0xfc81fd0f,0xc82fa800,
    0xf83f900f,0xb03eb7c7,0xfb1bf30f,0x9807e41f,0x3613e6ff,0x3603ec07,
    0x21fbf607,0x2a04f9ef,0x321fd00f,0x7e43fa1f,0x8fe43fa1,0x2fd88ef8,
    0x2041fb02,0x1fb020fd,0xdf83f604,0x02fcc1fc,0x3f2003f2,0x4f9bfa80,
    0x6e800fc8,0x3ee01f90,0x2bf137c2,0xf30fb01f,0x1f91fe4d,0x7c7f7e60,
    0x3ec07d84,0xcdf81f60,0x7fc77c1f,0x409af882,0x3fdccef8,0x7fb99df1,
    0x3f733be2,0x27d47f53,0x307fb2a6,0xa983fd95,0x654c1fec,0xf35f51fe,
    0x200ff889,0x304ccdfc,0x3f7fa07f,0x4ccdfc80,0xbf903f98,0x527cc999,
    0x0f9fd89f,0x3bfa0fb0,0x37f24fa9,0x3ebe64cc,0x80fb09f5,0xa83ec07d,
    0xb7c4f9af,0x5eec2ffa,0x3bfe63ff,0xdff32eee,0x3fe65ddd,0x7f52eeee,
    0xddf927c4,0x777e43ff,0x3bbf21ff,0x3bbf21ff,0x3e1f91ff,0xdccffb86,
    0x17bbbf22,0x9ff506d8,0x17bbbf20,0x77e403f6,0x5f7f45ee,0x7ffd40ff,
    0xb107d85e,0x7e43ffff,0x2be65eee,0x7d84f9fc,0x1f603ec0,0x7c6f87e4,
    0x8fa97e66,0x17e26ace,0x3e205f88,0xfa97e605,0x8fe4bf13,0x447f25f8,
    0x7c47f25f,0x57f47f25,0xffb80fea,0x003f21ef,0x0fe817d4,0x7c401f90,
    0x9003f204,0x36203dff,0x407d82df,0x07e44fe9,0xfcf8af98,0x3ec07d84,
    0x57f41f60,0x23be0fea,0x27f15faa,0x67ec6cbe,0x4e7ec3a9,0x54e7ec3a,
    0x7fde7f43,0xff95ff10,0x3f2bfe23,0xf95ff11f,0x32bfe23f,0xffff99ff,
    0x01f703ff,0x2f4001f9,0x03f207e8,0x3f201fb8,0x010fd800,0x807d816e,
    0x807e44fa,0x09ffb2f9,0x407d80fb,0xffff987d,0x3e7be3ff,0x7d4b90ef,
    0x7ffec42f,0x3fff620f,0x3fff620f,0x3bffa60f,0x7df7fdc1,0x3efbfee1,
    0x3efbfee1,0x3efbfee1,0xfa99afb9,0x3f20b905,0x7dc04ccd,0x3f207e81,
    0x02fc4ccd,0x413337f2,0xc80eeffa,0x2afeaa84,0x07fb37e2,0x4c999bf9,
    0x549ff32f,0x5542afea,0x75542afe,0x26bee2af,0x00105fa9,0x26004c00,
    0x11004c00,0x80080080,0x87d80800,0x3201107e,0x200fffff,0x207e82c8,
    0x10fffffc,0xfffc8039,0x7bb500ff,0x3ffa0b20,0xb9910fff,0xffff9039,
    0xfe8be61f,0x3fffffa4,0x3fffffa0,0x3fffffa0,0x00fd0fb0,0x00000000,
    0x00000000,0x00000000,0x00000000,0x00000000,0x00000000,0x00000000,
    0x00000000,0x00000000,0x00000000,0x50a80000,0x5400aa81,0x80a6010a,
    0x9730150a,0x8026a555,0x054c10aa,0x801550aa,0x2aa00098,0x2602aa00,
    0x0a802a82,0x00a98015,0x54150a80,0x32a3cccc,0x262a82ce,0x203cc982,
    0x0aa63ca8,0x9b971051,0xa82cc983,0x14c2cccc,0x989f37f5,0xff9100ef,
    0x09df50df,0xa89f37f5,0xff4ffeef,0xdfff509f,0xbf11fdc9,0xf300ef98,
    0x7fb00bff,0x7d41fec0,0x2a037c4e,0x5c04f9bf,0xf30fe01f,0x7fe4bf1b,
    0x3fbb66ff,0x1f92fc4f,0x42ff77d4,0x32a6fffd,0xff31763f,0x67dc7fff,
    0x7ffe45eb,0xb8bfe24f,0x07910170,0x103bfbee,0x17039139,0x374dd02e,
    0x2109fd75,0xb9be20bb,0xd03c882f,0x4c03f93d,0x2072601c,0x3e1c89c8,
    0x0170b806,0x6dcc1fb8,0x4370b80f,0x100999fc,0x3f25f8df,0x17e4df10,
    0xfd1019f9,0x5fd03ea3,0x988f98c4,0x89f303e9,0x599511fe,0x220b2e20,
    0xb982ffb8,0x0597302c,0x7c4374dd,0xc82cb987,0x4550fd1f,0x7d57e0a9,
    0x50597301,0x455054c5,0x771bf0a9,0x02a62a81,0x5c3fb951,0x54c5ffff,
    0x803e40aa,0xf92fc5f8,0x4fc8bea1,0x1bb301be,0x204fa85f,0x6acfe8cc,
    0xfc809f30,0x7fcc5fee,0x77fd45fe,0x7fffd46f,0x2ffffd45,0x20bfbbee,
    0x7ffd47f8,0x7ce7cc5f,0x87f25f84,0xf506fbfd,0x25f8bfff,0xfc97e1fc,
    0x1dfffdf1,0x543f92fc,0xf11ffeff,0x645fdf1d,0x7fe41fff,0x77e5c0ce,
    0x21f92fc0,0x5ffe99fb,0x45dfbdf1,0xb85d9dfc,0x3659972f,0x4c1e67bb,
    0x3f60404f,0x8fe43fa0,0x23fb0ef8,0x2fd88ef8,0x5fb11df1,0x260ddef4,
    0x3be23fee,0x7f42fd88,0x325f80fc,0x413fe61f,0x2fd88ef8,0x3e1fc97e,
    0x9ffc7f25,0xfc97e3fc,0x3ee1df11,0xf3f55f51,0xca83f909,0x77646fec,
    0x1fd37c4f,0x3e3bf3f2,0xfd99ff36,0xf901f505,0x5753ffa3,0x2603e26c,
    0x2a625c4f,0x9df11fec,0x8fe67fb9,0x547f53fb,0x7d47f54f,0x82aabbe4,
    0x1fd41df9,0x5ffb89f5,0x88fe4bf0,0x549f5fef,0x5f93ea3f,0x325f87f2,
    0x27ccdf1f,0xf98fe4bf,0x57d47ee3,0xfc85f8dc,0xd80ff401,0x3faffe2f,
    0x229ff73f,0x7cc9f35f,0x20c57c44,0x6d3e62fb,0x079acfab,0x9ffc49f3,
    0x31ffeefc,0x25ddddff,0x54fea3fa,0x7d53e23f,0xffc93e23,0x05f31fff,
    0x227c47f5,0x4bf02ff8,0xf73f91fc,0x11fd47fb,0x3f92fc9f,0x3e3f92fc,
    0x25f93e66,0x5c7f51fc,0x35f7f31f,0x803f907f,0x45f701fd,0x37f9cfff,
    0xf89fd4bf,0x1bb13e66,0x32fcc3fd,0x56ddae9f,0xc89f504c,0x3f25f8bf,
    0x7d40bf11,0x2fccbf25,0xa97e67f5,0x7cc9f33f,0x52fcc024,0x206f887f,
    0x3ec7f66f,0x2fcc1ffb,0xfb37c7f5,0x23fb37c3,0x6f8fea6f,0xb27d47f6,
    0x75fff43f,0x5c1fc80f,0x2ae6fdba,0x37e0ffba,0xabfe8220,0x7567ec7f,
    0x3323ea1f,0x65f7ec1f,0x2e233a4f,0x3faaf20f,0x7fc57d41,0x3f61ffca,
    0x67fc3a9c,0x33fa0ffb,0x33fa0ffb,0x3bf50ffb,0x13ea5f93,0x87fde7f4,
    0x3a01feb9,0xf71ffdbf,0xe83ff959,0x3a0ffbcf,0x3a1ffdbf,0xdf1ffdbf,
    0x7f41ff55,0xff11ffdb,0x7c43ffb7,0x6d541eff,0xfffd0abf,0x6ffffc19,
    0x3a202fc1,0x75c40eff,0x22fe22ff,0xffc85fef,0x3ff622ef,0x1fffe41e,
    0x7fdc9f93,0x3f621fbe,0x3fa60fff,0x7ff4c1ef,0x77ff4c1e,0x1f7ffdc1,
    0x3fa609f5,0x07bf21ef,0x3f7dff50,0x7fe7ffe4,0x07bffa60,0x43f7dff5,
    0xd1fbeffa,0xfa83dfff,0x3ea1fbef,0x3e21fbef,0xfffff00b,0x1300445f,
    0x08802fc0,0x265c8080,0x002202f9,0x1b980801,0x80260010,0x20044008,
    0x00200008,0x04000022,0x00880040,0x02004004,0x98020020,0x0000000c,
    0x00000000,0x00000000,0x00000000,0x00000000,0x00000000,0x00000000,
    0x00000000,0x00000000,0x00000000,0x00000000,0x55014c00,0x165d4021,
    0x2005ee54,0x260ea1aa,0x00aa83dc,0x298510a6,0x40e44144,0x9502cdca,
    0x88726199,0x4d42542c,0xca880bc8,0x40e4c0bb,0x800aa02a,0x55531aa9,
    0x3cccb801,0xccc88606,0x0790001a,0xca8b32e0,0x77d41e41,0x4efffa84,
    0x647fffd8,0x3206fddf,0xf70ffc3f,0xee98dfff,0x2ec7fb80,0xb85d8ff7,
    0x777fe46f,0x7ffff445,0x27c47f52,0xffdf0bfa,0x77fd41df,0x40fe41ff,
    0x401be06e,0xff95fffb,0x7ffc403f,0x7cc7f75e,0x9fffff35,0x4f7c1f20,
    0x3fbbf601,0x17dcdf11,0x20722722,0xcfc81770,0x3ee6f830,0x3a81c981,
    0x3f623be2,0x7a883b83,0x27a883ea,0x22d880fa,0x3f6046f8,0x11fd4224,
    0xff84a89f,0x3be27f93,0x36a63f70,0x81ba2acf,0x06f8806f,0xdfa807f2,
    0xfffffe86,0x3fa69f30,0xfff07c81,0x25f887ff,0x2fc57dc1,0x5405554c,
    0x3f40bc89,0x07ec7fa0,0x53015553,0x4bf317dc,0x7a80aaa9,0x22f505f1,
    0xf882a02f,0x40df101f,0x4d3e23fa,0x337c0aaa,0xfb8fe69f,0xffffff91,
    0xf1a99ba1,0xf301791b,0xd00fe407,0x99f50dbb,0xf527ccbf,0x2bfaaa29,
    0x3ae7be1a,0xd00fe61f,0xff903f9d,0xfffdf03f,0x7d407f8d,0x7fe42fef,
    0x3f27c81f,0xffc9be21,0x0bb6981f,0xf102eda6,0x42effd87,0x8fea04f9,
    0x3fff94f8,0x553e66f8,0xf907ee3f,0x9be6dd03,0x226fffef,0x41aadfba,
    0xb5f101fc,0xfb3e479f,0x7c4677ec,0xffffff35,0x29f537c7,0x80aadfc8,
    0x7e404ffa,0x1fb3ff81,0xfd100fec,0x07f207ff,0x7c1fd9f6,0x2a01fc87,
    0x807d400f,0xfeb83ffc,0xa813ea5f,0xf913e23f,0x4fea6f83,0x907f64fa,
    0xdf1dd03f,0x0fd9ffc1,0x7ffffff5,0x2f901fc8,0xc9f64efd,0x227bffa7,
    0xdf07c86f,0xfffb9fd4,0x7f4c43ff,0x207f2019,0xfa87ee6f,0x47f45bbf,
    0x1fc81fe8,0xf0bf27d8,0x2203f90b,0x5f1018af,0x09dfb833,0x7ccbfa60,
    0xf98fea05,0x3be0fe44,0xff10ffaa,0xfc83ffb7,0x40feee81,0xf307ee6f,
    0xf80fe407,0xbfb86d9d,0xa93e65f9,0xdf07c84f,0x7cc1fd53,0x3bffb603,
    0xf03f900e,0x3aa0fdcd,0xa93e66ff,0xd81fc83f,0x4fa93ea7,0x1bb01fc8,
    0xd3bb03fd,0x800fec9f,0x01ff12fc,0x43fa93e6,0x7fffc1fc,0x677fd41e,
    0x740fdc1f,0x737c0fee,0x203f983f,0xfffa81fc,0xffffc86f,0x2fd93e65,
    0xffff04a8,0x203f985d,0x2019fe98,0x2e6f81fc,0x440fb81f,0x81fd9aff,
    0x7c7e81fc,0xc80ffbef,0xcc8fa81f,0xbb07d41f,0x5ecc27e4,0x3ee0ffca,
    0x3fe2dccf,0x7e40feab,0x840077c1,0x4efd41fb,0x83be7ba2,0xf307ee6f,
    0x6c0fe407,0x7d4abf66,0xf34fb99d,0xaa8bff9d,0x3be0aaaa,0xcdfd9809,
    0x3fffa1cc,0x7ed540ff,0xfb9be0ab,0xff504d81,0xfdaa85ff,0x883fa0ab,
    0x5541effe,0x7f10abfd,0x7c4bfdf1,0x7c41bb13,0xfff30eef,0xffd703df,
    0x77ff4c3d,0x2aff6aa1,0xfb800df0,0xd0fffd81,0x26f97eed,0x41fcc1fb,
    0x10abfdaa,0x8bffec7f,0xff98e40c,0xffff83df,0xb81be1ff,0x82ffffff,
    0x3fffe07d,0xfb9be2ff,0x04400881,0x2ffffff8,0xf80403fa,0xb92fffff,
    0x4b917ccc,0x6dc47ffb,0x0800c41e,0x7ffc0440,0x00df2fff,0xd0601fb8,
    0x26f9fecd,0x41fcc1fb,0x02ffffff,0x00000000,0x00000000,0x00000000,
    0x00000000,0x00000000,0x00000000,0x00000000,0x00000000,0x00000000,
    0x98000000,0x32cccccc,0x2a035999,0xcc8002cc,0x399102bc,0x49999950,
    0x2cccccc9,0x32e3a95c,0xca80cccc,0x5910e441,0x83cca800,0x71cccccc,
    0x32a4b819,0x83b8f261,0x97032e4a,0x33333221,0x06f3321c,0x6641cc88,
    0x226441bc,0x2ca8f22c,0x54999995,0x5479100c,0x2f6a531c,0xff54caac,
    0xffd89fff,0x8ba604ff,0xb85fffff,0xfffc85ff,0x3fffea7f,0x5ca744ff,
    0x83bbffb6,0x7cc2ffea,0x17453e63,0x49fddfb0,0x2ffffff8,0x127cc9f5,
    0xdb0fecdf,0x217e4f70,0x3fffe66f,0x3fbfe2ff,0x87ff905f,0x264fffff,
    0x5f93e2ff,0x3ff21ff1,0x03f90fff,0x9ffc3fe6,0x3df7957e,0x74cfea95,
    0x3fc46a1f,0x9be1ff98,0x3f7ec2fd,0x3ec007e4,0x1de9cf98,0xfcef83ec,
    0x9f31fcc2,0x3e60ffa2,0x7c403fa4,0x7f43fa0f,0x2fcd7e40,0xfa9b21b2,
    0x33313e64,0xb2fc1fd3,0x3fdf981f,0x30ff8afc,0xbf27cdff,0x00fc8bf6,
    0x3fe603f9,0x2fb3ff9b,0x552bee4a,0xe813ea3f,0x7c0efb87,0x9bf13e66,
    0x800fc83f,0xffff987d,0x183ec7ff,0x23f985f7,0x227ec4f9,0x40bee3fa,
    0x4dfd42fd,0xfdef884f,0xd939be41,0x05f737c4,0xd97e2fcc,0x1fcf740f,
    0xf30fd97e,0xdf93e3fb,0x807e44fa,0xb9f501fc,0x55f69db9,0x2a95d934,
    0x4c17e23f,0x406fe45f,0xfa8fee6f,0x5fe44f9a,0x20fb02aa,0xfb07f2f8,
    0x7cc2fb80,0xc84feeee,0x13df30df,0x09f707f9,0x5c03f7fa,0xfb7b84ff,
    0xd0fd8b91,0x7c1fd80f,0x7dc3fdce,0x577c3f99,0x3ebe65fc,0x37f7c9f5,
    0x92666fe4,0x3ebea03f,0x2a314eae,0x54a8cf8c,0x4437c47f,0x06fe41fe,
    0x237ee7fc,0xfc8df0fc,0x0fb05fff,0x20be27e6,0x217dc07d,0x4feeeef9,
    0x3f60efb8,0x7c42ffff,0x09ff500e,0x7dc27fd4,0x5c5daff8,0x2605f8bf,
    0xffeff85f,0x3e69f10e,0x227fffc3,0x4f9fcaf9,0x3f21bfbe,0x07f25eee,
    0x5e8ffbdc,0x52a58ca8,0x113ea3fa,0x3bee05fd,0x0677ffc0,0x83faabfa,
    0x87d800fc,0x2efeefec,0x0bee03ec,0x227cc7f3,0x935305fd,0x401fd83f,
    0x3bfa00fe,0x6f57d40f,0x56fc45dd,0x207f602f,0x7e53ee5f,0x3e4dfdcd,
    0x3e60fe8d,0x3e4fcf8a,0x07e44fbd,0x2f701fc8,0x55f2bb5d,0x2a950d9c,
    0xe88bf63f,0x0ffd402f,0x7ffcc0df,0x03f23fff,0x3f6a1f60,0x3ec2cfdc,
    0x7f30bee0,0x3fe8a7cc,0x7dc7e880,0x2e07e804,0x7d45fabf,0xe84efbcd,
    0xbf300fdf,0xb3fa97e0,0x4fffffff,0x7ccbf55f,0xafc9ffb2,0x403f21fe,
    0x22f701fc,0x65536bb0,0x6fd52a48,0x77f45ffc,0x5d301ccc,0x35f7037c,
    0x07e4bf53,0x56b83ec0,0x2afeaa8f,0x8e6fee5c,0x453e63f9,0x3f32e02e,
    0x333fe22f,0x107e81cc,0xa87fa1ff,0x84ff89ff,0x3f606ffc,0xff95df01,
    0xbf0fe601,0x32f987f4,0xf9afc9ff,0x93337f26,0x91cccdfc,0xfa82db0d,
    0xf54fffff,0xfff07bff,0x7c007fff,0x9fa1f606,0x07d800fc,0xffd1eed9,
    0x7ff41fff,0x47f33fff,0x3fa004f9,0x7ffcc1df,0x07e83fff,0x337d47f9,
    0x4c1ff4ff,0x0df103ff,0x00e77ffc,0x2e5f87f3,0x7f45f34f,0x94fc97e4,
    0x321fffff,0xd92fffff,0x00000db0,0x00000000,0x00000000,0x00000000,
    0x00000000,0x00000000,0x00000000,0x00000000,0x59730000,0x442a62a8,
    0x203b8acb,0x65442cba,0x1ccb982c,0x2982cb88,0x330e5ca6,0x4d475173,
    0x2aaa0bc8,0x260aa2aa,0x4c1ba882,0x36e1540a,0xa886a22c,0x01b20001,
    0x816e4c08,0x54c0004a,0x9805d440,0x88157501,0x444440ba,0x54077008,
    0x97e5ffff,0xffbd51fc,0xfffb09fd,0x5feefc8f,0x313bbbea,0x7c4bfdff,
    0xfffdf92f,0x3f7ffb21,0xdfffdf3f,0x87fffff4,0x7547b86e,0x8fee3ebc,
    0x7e55c5f8,0x0fec7fa0,0xe80c9a5c,0x3ee5d80f,0x07fbbf10,0x2dcf20fb,
    0xf883ffa2,0xadc20fff,0xd137ef40,0x7ffc5fdd,0x7fcc1fff,0xd88ef882,
    0x8fe4bf2f,0x323ddf20,0x6c0830cf,0x7401fd0f,0x7f43f90f,0x7f51bf91,
    0x367f27f2,0x03f67ff5,0x537c93f2,0xefae89b2,0x5cdf12ea,0x0fee4c2f,
    0x107f7df3,0x220bd19f,0x9f7bf700,0xfb0bd3dc,0x0fea7ee0,0xf9081f97,
    0x3e6e76c3,0x21f73744,0x2666665e,0x07de6c09,0xf4fa8fea,0xb530fe4b,
    0x07e8f95d,0x91feca98,0xef8837df,0x3203fdcc,0x5f23510f,0xb9bedb6c,
    0x2e2fd41f,0x25d8fe8f,0x4abcd9ca,0x263f47f2,0x7dc1fabf,0x3f2db06f,
    0x3bbbbaa0,0x227fdc3e,0x3aa9d0fb,0x6c3eeffe,0x0fb81f96,0x7e445fa8,
    0x27fdc1df,0x3332ecf7,0x87d41333,0xf11fd44e,0x51fc97e9,0x8999fdbf,
    0x777e407f,0x3ffae1ff,0x3bbbfe64,0x403f202e,0x7db6d97c,0xff887ee6,
    0x5ffd7d40,0x3ba72a4e,0x273e64a8,0x7f6fcc4f,0xe81ffcc1,0x77541fb6,
    0x7dc3eeee,0x7f7fc45f,0xddffdd51,0x81f96d87,0x06fdc0fb,0x413fffae,
    0xfbdf32fb,0x7fffffc5,0x21fa8fa1,0x7cfea5f9,0xcaec7f66,0x4407fa06,
    0x2607f25f,0x80bf10ff,0x6403f229,0x37db6d97,0x40ff43f7,0x3fedeef9,
    0x372b67a2,0x407e7f42,0x7f40a8aa,0x8cf981fe,0x2a01105f,0x5445fbcf,
    0x2e0fb00b,0x3e22fa9f,0xfff33fff,0x4edddc7f,0x31bf7a65,0x88888399,
    0x20440408,0xd0ffbcfe,0x363ffb7f,0x429bff9e,0x225bbffb,0x71ffcaff,
    0xfd8ff535,0x3fe23a9c,0x5f201f92,0xb9bedb6c,0x999df91f,0x3eb3fe21,
    0x64d75c2f,0xa85ffb85,0x3f23eeee,0x5c80ef9a,0x01fd01b5,0xea875c9b,
    0x07d83eee,0x2aa16e79,0x555511aa,0x5710d903,0x00000003,0x50f7ff4c,
    0x263f7dff,0x85ffdaff,0x7dc6fffb,0xffd1fbef,0xffd883df,0x647fa0ff,
    0x5b2f900f,0x8fdcdf6d,0x20fffffe,0x303ff1ff,0x3fe205b9,0x2cccc982,
    0x027dcbf5,0x0400db00,0x50599993,0x00000009,0x00000000,0x04011000,
    0x00801100,0x00131004,0x00002013,0x00000000,0x00000000,0x00000000,
    0x00000000,0x00000000,0x00000000,0x00000000,0x00000000,0x00000000,
    0x00000000,0x00000000,0x00000000,0x00000000,0x511e4000,0x11101511,
    0x80223ca8,0x0a8540aa,0x1bbbbbb1,0x5512e1d4,0xaaaaaa81,0xdddd10aa,
    0x00000003,0x00000000,0x00000000,0x00000000,0x00000000,0x997fc400,
    0x7f43f9bf,0xbfff30ff,0x217e41b6,0xb14f9bfa,0x223fdbbb,0x47ff33ff,
    0x3ffe0ef9,0xd11fffff,0x00003ddd,0x00000000,0x00000000,0x00000000,
    0x00000000,0xfd800000,0x87f37f33,0x55f21998,0x1c983fff,0x9802e170,
    0x225ff11f,0x016441ff,0x00000000,0x00000000,0x00000000,0x00000000,
    0x00000000,0x1fb80000,0x005f15f1,0x002c9822,0x21e98000,0x00000818,
    0x00000000,0x00000000,0x00000000,0x00000000,0x00000000,0x0ff66000,
    0x00002613,0x00000000,0x00000000,0x00000000,0x00000000,0x00000000,
    0x00000000,0x00000000,0x00000b98,0x00000000,0x00000000,0x00000000,
    0x00000000,0x00000000,0x00000000,0x00000000,0x00000000,0x00000000,
    0x00000000,0x00000000,0x00000000,0x00000000,0x00000000,0x00000000,
    0x00000000,
};

static signed short stb__consolas_bold_15_latin1_x[224]={ 0,2,1,0,0,0,0,3,1,1,0,0,1,1,
2,0,0,0,0,1,0,1,0,0,0,0,2,1,0,0,1,2,0,0,0,0,0,1,1,0,0,1,1,0,
1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,2,0,1,0,0,0,0,1,0,0,0,0,0,1,1,
0,1,1,0,1,0,1,0,1,1,0,1,0,0,0,0,1,1,3,1,0,0,0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,2,0,0,0,0,
3,0,0,0,1,0,0,1,0,0,1,0,1,1,0,0,0,2,3,1,1,0,0,0,0,1,0,0,0,0,
0,0,-1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,0,
0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,
 };
static signed short stb__consolas_bold_15_latin1_y[224]={ 11,0,0,1,-1,0,0,0,0,0,0,3,8,6,
8,0,1,1,1,1,1,1,1,1,1,1,3,3,2,4,2,0,0,1,1,1,1,1,1,1,1,1,1,1,
1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,0,0,0,1,12,0,3,0,3,0,3,0,3,0,0,
0,0,0,3,3,3,3,3,3,3,1,3,3,3,3,3,3,0,-1,0,5,1,1,1,1,1,1,1,1,1,
1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,11,3,0,1,1,1,
-1,0,0,1,1,3,6,6,0,0,0,1,0,0,0,3,0,5,11,0,1,3,0,0,0,3,-2,-2,-2,-2,
-2,-2,1,1,-2,-2,-2,-2,-2,-2,-2,-2,1,-2,-2,-2,-2,-2,-2,3,-1,-2,-2,-2,-2,-2,1,0,0,0,
0,0,0,-1,3,3,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,3,1,0,0,0,0,0,0,0,
 };
static unsigned short stb__consolas_bold_15_latin1_w[224]={ 0,4,6,8,8,9,9,3,6,6,8,8,5,6,
4,8,8,8,8,7,8,7,8,8,8,8,4,5,7,8,7,6,9,9,8,8,8,7,7,8,8,7,6,8,
7,8,8,8,8,9,8,8,8,8,9,9,9,9,8,5,8,5,8,9,6,8,7,8,8,8,8,8,7,7,
7,7,7,8,7,8,7,8,7,7,8,7,9,9,9,9,7,6,2,7,8,8,8,8,8,8,8,8,8,8,
8,8,8,8,8,8,8,8,8,8,8,8,8,8,8,8,8,8,8,8,8,8,8,8,0,4,7,8,8,8,
2,8,7,9,6,8,8,6,8,7,6,8,6,6,8,8,8,4,3,6,6,8,9,9,9,6,9,9,9,9,
9,9,9,8,8,8,8,8,8,8,8,8,8,8,8,8,8,8,8,8,8,8,8,8,8,9,8,7,8,8,
8,8,8,8,9,8,8,8,8,8,8,8,8,8,8,8,8,8,8,8,8,8,8,8,8,8,8,9,7,9,
 };
static unsigned short stb__consolas_bold_15_latin1_h[224]={ 0,12,5,10,14,12,12,5,15,15,7,8,6,2,
4,13,11,10,10,11,10,11,11,10,11,10,9,11,10,6,10,12,15,10,10,11,10,10,10,11,10,10,11,10,
10,10,10,11,10,13,10,11,10,11,10,10,10,10,10,14,13,14,6,3,4,9,12,9,12,9,11,12,11,11,
15,11,11,8,8,9,11,11,8,9,11,9,8,8,8,12,8,14,16,14,4,10,10,10,10,10,10,10,10,10,
10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,0,11,13,10,10,10,
16,13,4,11,8,8,4,2,8,4,6,10,7,7,4,11,13,4,3,7,8,8,11,11,11,11,13,13,13,13,
13,13,10,13,13,13,13,13,13,13,13,13,10,13,14,14,14,14,14,8,14,14,14,14,14,13,10,12,12,12,
12,12,12,13,9,11,12,12,12,12,11,11,11,11,12,11,12,12,12,12,12,8,12,12,12,12,12,15,14,15,
 };
static unsigned short stb__consolas_bold_15_latin1_s[224]={ 251,251,7,72,88,174,90,252,42,35,213,
181,1,84,62,57,196,89,19,179,191,171,205,173,28,115,63,250,28,236,107,
55,49,45,182,105,10,227,55,224,98,81,243,218,235,243,209,51,36,75,200,
96,63,114,163,153,143,133,124,106,29,82,245,74,67,37,127,28,144,54,173,
46,165,123,27,157,182,76,85,1,131,139,68,46,148,10,120,101,137,71,93,
59,1,66,22,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,
1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,251,46,85,
236,200,245,4,102,40,233,130,147,48,84,111,14,229,218,206,222,31,187,203,
57,252,199,174,190,69,79,214,89,156,1,241,221,231,193,190,11,20,48,111,
66,93,129,138,147,209,120,97,184,112,121,130,165,139,148,157,166,175,38,227,
166,220,229,238,247,1,212,18,19,10,202,184,193,60,37,1,162,19,10,211,
100,28,62,37,156,153,81,109,118,135,17,74,7, };
static unsigned short stb__consolas_bold_15_latin1_t[224]={ 14,1,78,57,1,18,32,57,1,1,68,
68,78,78,78,18,32,57,57,32,57,32,32,57,45,57,68,32,57,68,57,
32,1,57,57,45,57,57,57,32,57,57,32,57,57,57,57,45,57,18,57,
45,57,45,57,57,57,57,57,1,18,1,68,78,78,68,32,68,32,68,45,
32,45,45,1,45,45,68,68,68,45,45,68,68,45,68,68,68,68,32,68,
1,1,1,78,57,57,57,57,57,57,57,57,57,57,57,57,57,57,57,57,
57,57,57,57,57,57,57,57,57,57,57,57,57,57,57,57,57,14,45,18,
45,45,45,1,18,78,32,68,68,78,78,68,78,68,45,68,68,78,32,1,
78,63,68,68,68,45,45,32,45,18,18,1,1,1,1,45,18,18,18,18,
18,18,18,18,18,45,18,1,1,1,1,1,68,1,1,1,1,1,18,45,
18,18,18,18,18,32,1,68,45,32,18,18,18,45,45,45,32,32,45,18,
32,32,32,32,68,32,32,32,32,32,1,1,1, };
static unsigned short stb__consolas_bold_15_latin1_a[224]={ 132,132,132,132,132,132,132,132,
132,132,132,132,132,132,132,132,132,132,132,132,132,132,132,132,
132,132,132,132,132,132,132,132,132,132,132,132,132,132,132,132,
132,132,132,132,132,132,132,132,132,132,132,132,132,132,132,132,
132,132,132,132,132,132,132,132,132,132,132,132,132,132,132,132,
132,132,132,132,132,132,132,132,132,132,132,132,132,132,132,132,
132,132,132,132,132,132,132,132,132,132,132,132,132,132,132,132,
132,132,132,132,132,132,132,132,132,132,132,132,132,132,132,132,
132,132,132,132,132,132,132,132,132,132,132,132,132,132,132,132,
132,132,132,132,132,132,132,132,132,132,132,132,132,132,132,132,
132,132,132,132,132,132,132,132,132,132,132,132,132,132,132,132,
132,132,132,132,132,132,132,132,132,132,132,132,132,132,132,132,
132,132,132,132,132,132,132,132,132,132,132,132,132,132,132,132,
132,132,132,132,132,132,132,132,132,132,132,132,132,132,132,132,
132,132,132,132,132,132,132,132, };

// Call this function with
//    font: NULL or array length
//    data: NULL or specified size
//    height: STB_FONT_consolas_bold_15_latin1_BITMAP_HEIGHT or STB_FONT_consolas_bold_15_latin1_BITMAP_HEIGHT_POW2
//    return value: spacing between lines
static void stb_font_consolas_bold_15_latin1(stb_fontchar font[STB_FONT_consolas_bold_15_latin1_NUM_CHARS],
                unsigned char data[STB_FONT_consolas_bold_15_latin1_BITMAP_HEIGHT][STB_FONT_consolas_bold_15_latin1_BITMAP_WIDTH],
                int height)
{
    int i,j;
    if (data != 0) {
        unsigned int *bits = stb__consolas_bold_15_latin1_pixels;
        unsigned int bitpack = *bits++, numbits = 32;
        for (i=0; i < STB_FONT_consolas_bold_15_latin1_BITMAP_WIDTH*height; ++i)
            data[0][i] = 0;  // zero entire bitmap
        for (j=1; j < STB_FONT_consolas_bold_15_latin1_BITMAP_HEIGHT-1; ++j) {
            for (i=1; i < STB_FONT_consolas_bold_15_latin1_BITMAP_WIDTH-1; ++i) {
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
        float recip_width = 1.0f / STB_FONT_consolas_bold_15_latin1_BITMAP_WIDTH;
        float recip_height = 1.0f / height;
        for (i=0; i < STB_FONT_consolas_bold_15_latin1_NUM_CHARS; ++i) {
            // pad characters so they bilerp from empty space around each character
            font[i].s0 = (stb__consolas_bold_15_latin1_s[i]) * recip_width;
            font[i].t0 = (stb__consolas_bold_15_latin1_t[i]) * recip_height;
            font[i].s1 = (stb__consolas_bold_15_latin1_s[i] + stb__consolas_bold_15_latin1_w[i]) * recip_width;
            font[i].t1 = (stb__consolas_bold_15_latin1_t[i] + stb__consolas_bold_15_latin1_h[i]) * recip_height;
            font[i].x0 = stb__consolas_bold_15_latin1_x[i];
            font[i].y0 = stb__consolas_bold_15_latin1_y[i];
            font[i].x1 = stb__consolas_bold_15_latin1_x[i] + stb__consolas_bold_15_latin1_w[i];
            font[i].y1 = stb__consolas_bold_15_latin1_y[i] + stb__consolas_bold_15_latin1_h[i];
            font[i].advance_int = (stb__consolas_bold_15_latin1_a[i]+8)>>4;
            font[i].s0f = (stb__consolas_bold_15_latin1_s[i] - 0.5f) * recip_width;
            font[i].t0f = (stb__consolas_bold_15_latin1_t[i] - 0.5f) * recip_height;
            font[i].s1f = (stb__consolas_bold_15_latin1_s[i] + stb__consolas_bold_15_latin1_w[i] + 0.5f) * recip_width;
            font[i].t1f = (stb__consolas_bold_15_latin1_t[i] + stb__consolas_bold_15_latin1_h[i] + 0.5f) * recip_height;
            font[i].x0f = stb__consolas_bold_15_latin1_x[i] - 0.5f;
            font[i].y0f = stb__consolas_bold_15_latin1_y[i] - 0.5f;
            font[i].x1f = stb__consolas_bold_15_latin1_x[i] + stb__consolas_bold_15_latin1_w[i] + 0.5f;
            font[i].y1f = stb__consolas_bold_15_latin1_y[i] + stb__consolas_bold_15_latin1_h[i] + 0.5f;
            font[i].advance = stb__consolas_bold_15_latin1_a[i]/16.0f;
        }
    }
}

#ifndef STB_SOMEFONT_CREATE
#define STB_SOMEFONT_CREATE              stb_font_consolas_bold_15_latin1
#define STB_SOMEFONT_BITMAP_WIDTH        STB_FONT_consolas_bold_15_latin1_BITMAP_WIDTH
#define STB_SOMEFONT_BITMAP_HEIGHT       STB_FONT_consolas_bold_15_latin1_BITMAP_HEIGHT
#define STB_SOMEFONT_BITMAP_HEIGHT_POW2  STB_FONT_consolas_bold_15_latin1_BITMAP_HEIGHT_POW2
#define STB_SOMEFONT_FIRST_CHAR          STB_FONT_consolas_bold_15_latin1_FIRST_CHAR
#define STB_SOMEFONT_NUM_CHARS           STB_FONT_consolas_bold_15_latin1_NUM_CHARS
#define STB_SOMEFONT_LINE_SPACING        STB_FONT_consolas_bold_15_latin1_LINE_SPACING
#endif

