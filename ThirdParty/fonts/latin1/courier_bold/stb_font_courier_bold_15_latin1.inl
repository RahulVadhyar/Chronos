// Font generated by stb_font_inl_generator.c (4/1 bpp)
//
// Following instructions show how to use the only included font, whatever it is, in
// a generic way so you can replace it with any other font by changing the include.
// To use multiple fonts, replace STB_SOMEFONT_* below with STB_FONT_courier_bold_15_latin1_*,
// and separately install each font. Note that the CREATE function call has a
// totally different name; it's just 'stb_font_courier_bold_15_latin1'.
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

#define STB_FONT_courier_bold_15_latin1_BITMAP_WIDTH         256
#define STB_FONT_courier_bold_15_latin1_BITMAP_HEIGHT         68
#define STB_FONT_courier_bold_15_latin1_BITMAP_HEIGHT_POW2   128

#define STB_FONT_courier_bold_15_latin1_FIRST_CHAR            32
#define STB_FONT_courier_bold_15_latin1_NUM_CHARS            224

#define STB_FONT_courier_bold_15_latin1_LINE_SPACING           7

static unsigned int stb__courier_bold_15_latin1_pixels[]={
    0x0a980884,0x54407200,0x26110880,0x2001aa80,0x088aa601,0x00186000,
    0x00910188,0x402b8032,0x26030c00,0x1c8024c0,0x20000ae0,0x00618001,
    0x80057001,0x5bbcc02b,0x7b002fe8,0x3e60fcc0,0x987f2994,0x3c6dc4ff,
    0x87fec13a,0x403c984c,0xfd90698f,0x407e61bb,0xb017406a,0x9dd10b99,
    0x0d31f01b,0x80b705f3,0x1773603d,0x11720264,0x34c7c079,0x00dcee88,
    0x826c00f6,0x017c005d,0x49900018,0x1321364c,0x0fa8f3b9,0x5c2644d8,
    0x76c00049,0x17a1fdab,0x86004008,0x0002a101,0x08010364,0xff7030c0,
    0xa85f105d,0x5080004a,0x02001001,0x88eebcc8,0x7fefc3ee,0x223bae1d,
    0xdddd93ee,0x6c992641,0x56644c84,0x44d83e87,0x3201504c,0x33eebaee,
    0x3ea0f81f,0x20bbae20,0xb882eeb8,0xeeb882ee,0x42eeb882,0x2bbb22f8,
    0x5dd93eeb,0x3bb27dd7,0x7f53eeba,0x20d707d7,0xeeeeb80a,0xea9f6c6e,
    0x02f76c4e,0x5dc17bb6,0xf07f65f9,0x261fb57f,0x54c7f65f,0xc9360fba,
    0xd9321364,0x3dc6ffff,0xdb13226c,0x273e60bd,0x00d71fc9,0x5dfec5f1,
    0x7ddfec5f,0x2fddfec5,0xb17eeff6,0x7ccbf77f,0x32673e60,0x9339f31f,
    0x2673e63f,0x221d71fc,0x7f5c3f80,0x556f4c4e,0x4c7fd47c,0x7fe541fc,
    0x07ff2a01,0x07f35c66,0x9ae3f87f,0x321f303f,0x3fb9322f,0xdbbd3264,
    0x26c2f883,0x3ff95022,0x327a87e0,0x3ea7f005,0x07d43e60,0x983ea1f3,
    0x7cc1f50f,0x87cc1f50,0x1ea1f87b,0x87e3d43f,0x0fbf627a,0x2aaea1ee,
    0x68ba6c1f,0x20f35ff8,0x6ec04ddd,0x5dfc404d,0x22f89f07,0x2607bbf8,
    0x2649d30f,0x224c83d9,0x8d706cce,0x6ec0cc4d,0x3d43f04d,0x25f001f5,
    0x0d93e86c,0x4fa1b27d,0x0d93e86c,0x3f03ea7d,0x7a87e3d4,0x730f50fc,
    0xb883e87d,0x6f6c3fed,0x37f7f00f,0x1f55f10f,0x03eabe20,0x3e07ff70,
    0xfb86ebdf,0xc83e603f,0xc84d9324,0xbfffff14,0x226c5f10,0x7d57c44c,
    0xd1ea1f80,0x4c5d535d,0x27b0b91f,0x0b93d85c,0x4f61727b,0x3f33d85c,
    0x3f1ea1f8,0x7a87e3d4,0x3ea5c8ba,0x3fcbee80,0xf807f7ec,0xfb87afba,
    0x5f703fba,0x0ff007f7,0x8056ee7c,0x907cc07f,0x909b2649,0x02edfc49,
    0x13226cd9,0xf07f75f7,0x3f623545,0xf73e44ff,0x0fb87c41,0x107dc3e2,
    0xf883ee1f,0x07c41f70,0x1aa2f89d,0x8be3545f,0x3fb7fa6a,0x27e613a2,
    0x5360cfb9,0xfd2f81b4,0xdddddd0f,0x1bbbbba0,0x17c07f10,0x2a01fc40,
    0x14c87647,0x224d987d,0x3e203d9f,0x22643bb1,0xd86eeeee,0xb503e9ae,
    0xaee87f10,0x557745ea,0x7557745e,0x2f557745,0x717aabba,0x74d76c1f,
    0x1f4d76c3,0xa8fa6bb6,0x03ea1eea,0x97ffffec,0x2faaade8,0x1fe633e2,
    0x217dc5f5,0x20bee2fa,0xf702fdc9,0x3f72605b,0x45ecca82,0x3b6994e8,
    0xf893fe60,0xdaec03e8,0x7d4990ff,0xfb10bee2,0x1fb1019f,0xffc886a8,
    0x5ffe440b,0x05ffe440,0x102fff22,0x5d017ff9,0x2067fec4,0x440cffd8,
    0x4d80cffd,0x4062026c,0x2ffffffc,0x13e4fff2,0xfff11fff,0x223ffe21,
    0x77540fff,0x09ddb04e,0x2e13bbaa,0x000003de,0x01880084,0xf11fff10,
    0x500101ff,0x00000005,0x00000000,0x04004004,0x001506a0,0x00000000,
    0x00000000,0x00000000,0x00000000,0x00000000,0x00000000,0x00000000,
    0x00000000,0x01900220,0x200c0190,0x00c88048,0x03620008,0x2a009844,
    0x0555300b,0x01b10091,0x2048815c,0x5550002b,0x03620003,0x2010c0c3,
    0x002a8021,0x48800062,0xea880ae0,0x0f7665ef,0x5d101e98,0x80bffe60,
    0x3afaa06a,0x0f3b6e01,0x52e02e88,0x6ccd882d,0x827f77d4,0x05d100ea,
    0xea82e66c,0x642ee6c0,0x8bb9bb03,0xe882eeb8,0xf8698f82,0xf31f0798,
    0x22137760,0x224ebeeb,0x885ecffb,0x40f6202e,0x90fdabfc,0x401101a1,
    0x02e57201,0x80220806,0x00100510,0x88ec9500,0x200ecaaf,0x18600400,
    0xc8186020,0xb1227884,0x010bf97f,0x18000000,0x3eeff606,0x3eefba0f,
    0x3000882f,0x6d490be0,0x77e4414c,0x84efc884,0xeb85eacd,0xbddb04ef,
    0x705eed80,0x87dd11bd,0x13905eed,0x2a7e23d7,0x3bbae0ec,0x3bbae6ee,
    0x3bbae6ee,0x3bbb26ee,0x9dddd94e,0xe8977fdc,0x20fa80de,0xdddd92f9,
    0x93bbbb29,0x5c0cfeb8,0xeb884efe,0x5c3ea0cf,0x7b8f32ff,0x40cfeb88,
    0x220cfeb8,0x7664c01f,0x17eefba3,0xd8bf77dd,0x5d40dfec,0xfca81faa,
    0x3ff2a01f,0xdf16e981,0x81ffca83,0x321dcc8e,0x3a60ecde,0x3a67caad,
    0x3a67caad,0x2a67caad,0xbd531ade,0x3aafee35,0x87f71d34,0xd534e86c,
    0x37aa635b,0x3aeb7a1a,0x0fd55d45,0xc97aeb7a,0x269b5f36,0x37a1ee0f,
    0x56f45eba,0x4d6e45eb,0x399d92c9,0x23f107cc,0xd87e20f9,0xdb889d34,
    0x9bbb03fe,0x304ddd80,0x3601f75f,0x968e84dd,0x40ecda83,0x4d8d174d,
    0x174d8d17,0x13609b0d,0x3d704c9b,0x6c2e4b91,0x44d826c3,0x0fdcccf9,
    0x98ffb6e2,0x90fdcccf,0xd9369f1b,0x7cc7fdce,0xf30fdccc,0x441fb999,
    0x210dfffd,0x41f52dad,0x441f52f8,0x47b9362f,0x883fcbee,0xf100faaf,
    0x3ee01f55,0xf55f103f,0x2feb9d81,0x76c0eca8,0xfded80fd,0x00fded80,
    0xb913609b,0x277a6044,0x7c41f51e,0x44d826c0,0x1eeeeefa,0xa8ff2fba,
    0x31eeeeef,0x88be2ddf,0x7d47cddb,0xf51eeeee,0x503ddddd,0x3e49b40b,
    0x6fc7d99d,0x37a27d99,0x27e65cbe,0x7dc0cfb9,0x5f703fba,0x037407f7,
    0xc87f75f7,0xd9501313,0x80fefd81,0xfd80fefd,0x209b00fe,0x7ef7cc4d,
    0xee89f703,0x04d86eaa,0x5339f09b,0x2e67e617,0x2673e0cf,0x2abfe0ba,
    0x7c3cc06e,0x3e0ba99c,0x440ba99c,0x1db700fd,0x2077ff44,0x320effe8,
    0x6c2ffcff,0x742fffff,0xdd06eeee,0x2640dddd,0x8dddddd0,0x32a050e9,
    0x1b4a6c0e,0x6c1b4a6c,0x09b03694,0x0bba2136,0x7ec43c1b,0x3609b03f,
    0xdfffd984,0x3fffff60,0x37fff662,0x19ffbf50,0x261fed40,0x260dfffd,
    0x980dfffd,0x01100401,0x20080088,0xb8bea018,0xf717d42f,0x505bd505,
    0x2e17dc5f,0xfded85ef,0x555bd10e,0x2ab7a25f,0x55bd12fa,0x37aa25f5,
    0x15bd510a,0xfeed84c8,0xcbdfe884,0x215bd512,0x880adea8,0x22006201,
    0x20013c81,0x03105eec,0x00000188,0x00000000,0xf88fff88,0x1fff10ff,
    0x7cc1fff1,0x3fe21fff,0x00fff88f,0xc8222620,0x92ffffff,0x25ffffff,
    0x2ffffffc,0x36bffffb,0x0445ffff,0xbd300cc4,0x3ff63bd9,0xffffb5ff,
    0x0000000b,0x00000000,0x00000000,0x00000000,0x00000000,0x00000000,
    0x00000000,0x00000000,0x70022000,0x05500001,0x10154000,0x19002180,
    0x21a806e0,0x815c00a9,0x880aa00c,0x00000801,0xa8044200,0x80ab880b,
    0x2602aaa8,0x5555542b,0x55000001,0xfb302e60,0x4413207d,0xfd902ece,
    0x4ddd81bb,0x01bdfd90,0x3ba21fe6,0x798f80db,0x6c405d10,0x3fa7f882,
    0x3a215401,0x41777202,0x7443effa,0x75c40dbe,0xffced82e,0x45bbcc0c,
    0x7dc6ffd8,0x7fdc0fee,0x77f441ff,0x2fffffc6,0x49dbff93,0x224dfeb8,
    0x3f60ffef,0x2efb20fe,0x1104d83e,0x6d5f6c0c,0xdb030c1f,0x4c03f957,
    0x0006a107,0x7c060030,0x40200fc6,0x2e030c01,0x35081fcd,0x8bf77fb0,
    0x06dacffa,0x4c7f35c0,0x80d71362,0x741700ee,0x3bf2b7a4,0x9baafae1,
    0x87d53a5c,0x25c8a65e,0x2e19dd99,0x7cc9d93e,0xdf9107c0,0x0640f889,
    0x10fbff91,0xf9109df9,0xd93eb89d,0x4ec9f5c9,0x3ff7e37c,0xfd726c0c,
    0x9dfd709d,0x7176ee20,0x0fa89dfd,0xe87f03e6,0x93b27d72,0x2621724d,
    0x05e75c4e,0x220067e6,0x45e8f51f,0x16c92a3e,0x87b9ae9d,0xfff53fc8,
    0x53a63fff,0x201ae5d9,0x2e5fbbee,0xfcade806,0x5fbbee87,0x32fddf74,
    0xe997669d,0x45e8bb34,0x746dacff,0x07eaaea5,0xc83f5575,0x5d47fedf,
    0x21b21faa,0x5f127c3e,0xd2ecd3a6,0x7ffc35c5,0x17ef7d40,0x403dfff7,
    0x8bb1aa6b,0x7c41bdfb,0x33f10fff,0x02fc81ff,0x5b93609b,0x41f30172,
    0x362b91f8,0x641f33ee,0x3f107cc7,0x21f883e6,0x49b16e4d,0x93e26c5b,
    0xb897e1f8,0x6dc43fed,0xd8be23fe,0x3fb6e20f,0xf0f61723,0x4d8dd9bf,
    0x1ae3e96e,0xc8213aa2,0x17237ee5,0x5ce7c4e8,0x4fec985f,0xc8ff33ee,
    0x0cc0feff,0xb93609b0,0xfa803ea5,0x87d4be20,0xb8d73fcb,0x5f107d47,
    0x22f883ea,0x49b16e4d,0x0fe0cc5b,0x7dd37c7d,0xcbee87f9,0x7b83e63f,
    0x71fe5f74,0x3e07c41f,0x26c0bddc,0x09b2ecb7,0xa9aa03d4,0xf101f30f,
    0x5effda83,0x24e9ea24,0x436cc45c,0xdc826400,0x3ba0eea9,0x37e2ea9a,
    0x37e27d99,0x9f11fa9a,0xdf83fd53,0x4efc7d99,0x54ee47d9,0x2a7720ee,
    0x3be600ee,0xff10fc9a,0x33ee67e6,0x9f733f30,0x2f4ce741,0x19f733f3,
    0x42f55774,0x54ee402f,0xf55f50ee,0x2ed4cdc3,0x893aa6b2,0xd706c9cf,
    0x3e25c840,0x3b66d99c,0xb5314e99,0x550dd03f,0xff985577,0x3f623fef,
    0x7ff444ff,0x7fff4c0e,0x3bff6a0d,0x77ff447f,0x077ff440,0x8ffbffe6,
    0x23fefff9,0x3ffbfe4d,0xffb15c2d,0x7fec5fff,0x3f662fff,0x7ffec0cf,
    0x3ff222ff,0x016fdc0b,0x47fdfff3,0x7fec2efc,0x7ff640ef,0x0f7fd40c,
    0xfb9703c8,0x6fff7445,0x43bffa21,0x1101cffb,0xffffffa8,0x80100181,
    0x44018008,0x44008800,0x00c00c00,0x10004401,0x08018803,0x20000c40,
    0x01804eed,0x02002004,0xed800020,0x8802202d,0x00000080,0x00000000,
    0x00000000,0x00000000,0x00000000,0x00000000,0x00000000,0x00000000,
    0x00000000,0x00000000,0x00000000,0x00000000,0x09d93ec8,0xdb80f76e,
    0x4403903d,0x00151010,0x82a80000,0x3ee88eeb,0x07700571,0x015440e2,
    0x26620770,0x1a881999,0x0ae60530,0x32f77744,0x01540035,0x1aa88351,
    0x3b202a88,0xa83eebae,0x27620000,0xb0bb34e9,0x9b0b5119,0x5d10b511,
    0x2e16d2e0,0x2eea801e,0x704bee98,0xfd97e60b,0xb8079351,0x40ecea83,
    0x132004c9,0x7fcc300c,0x213ff20f,0x440ffefa,0x3f22deaa,0x20df5004,
    0x3ee3fffe,0x206fa84f,0x1fc99cf9,0xfc881fc4,0x9b2e884e,0x3baf22dc,
    0x26f23a8d,0x0103abdd,0x8220e400,0x1086bbf8,0xd7006017,0x08bee1fc,
    0x98098600,0xeffd8084,0x3218065e,0x84daa835,0x3e80fa3f,0xdfd004d8,
    0x6c021f30,0x1f80d704,0x3ba001ea,0x26c05fbb,0xa8b8e8b7,0x252c74b3,
    0x540fbaa5,0x543903ee,0xea81e62f,0x7540cfed,0xf77f103e,0x20fdd6a0,
    0x03eea84c,0x5436c493,0x8061aade,0x4c803ee1,0x7d027408,0x01bffdb0,
    0xfec8d7f7,0x209b04ee,0x7c5ee8eb,0x7dd51ea1,0x0fc41f30,0x1dd53bb0,
    0x4b0fdbb4,0x7544b0b6,0x909d5104,0x217db59b,0xe883dfc9,0x5443eabf,
    0x0ffee04e,0x17bd7bbb,0x754427e4,0xfabdca84,0x304c80bd,0xb5bfb0c0,
    0x7ec04c81,0xd83e8910,0x7c44eabf,0x57e4c6ab,0x2e09b01a,0x0fc2dfbe,
    0x84ea88f5,0xc8be20fa,0x3fbfff66,0x36af6762,0x2af27649,0x404d848b,
    0x26fee04d,0x09dfb33f,0x9b05b936,0x3f207f80,0x05d92faa,0x3b6204d8,
    0x2641dae9,0x57d46018,0x104c86ff,0x3a3cc3fb,0xb1724d83,0x0f50f73f,
    0x3fee09b0,0x83545f04,0xb33bf04d,0x27362e8f,0x2a39b300,0x2a67660e,
    0x404d80d8,0x3a1b304d,0x9b01f43c,0x204d82dc,0x119503f8,0x2b8f659d,
    0x10f204d8,0xb99ec81d,0x9fa8c033,0x884c83fc,0x4dfcc1ee,0x324d81fb,
    0x27ffffc5,0x413601ea,0xed80eefb,0x09b03e9a,0x983bffa2,0x6cc026c5,
    0xed981dde,0x6f54c1dd,0x56f54c1a,0xa97bee01,0xb10eaacf,0xa983b21b,
    0x37261ade,0x4efc802f,0x4c9fbbf5,0xa801adea,0xeffe881e,0xffb0c032,
    0x37aa21ff,0x557ff10a,0x0bffae23,0x076c37a2,0x4c1fb533,0x54c0aafc,
    0x3b221ade,0x3620afd8,0x754c0cff,0x101101ad,0x02002a81,0xfff88040,
    0x3ffe26ff,0xaf4406ff,0x0efffff8,0x5ff35ff7,0x9bffffe2,0x1004eeea,
    0x85ee4c9d,0x06fffff8,0x880f77cc,0x4cccccc0,0x7ec04419,0xfff35fff,
    0x5c010bff,0x83ffaaff,0x3ffa4ffc,0x7fffc4ff,0x7ddbea6f,0xff10083f,
    0x0000dfff,0x00000000,0x00000000,0x00000000,0x00000000,0x00000000,
    0x00000000,0x00000000,0x20000000,0x004eeeec,0x1bbbbbae,0x5bddd700,
    0xdddb1000,0xed86a003,0x75c9dd53,0x77542dee,0x88deb85e,0x3bbb22ed,
    0x2237ae4e,0x11bd73ee,0x4f76c5db,0x3b625ee9,0x70ded88d,0x47dd39dd,
    0x2eeeeeea,0x3dd55dd3,0x00b7bbae,0xdddb1033,0x6c066039,0x0017aa2e,
    0xbddddd70,0x886b7aa6,0x3a60cfeb,0x5447caad,0x33e65efe,0x7f5c3fdb,
    0x0cdfb84e,0x2fdffd88,0x3f263fea,0x3f6f3e61,0x20b3ea23,0x1ef88fe9,
    0x993eeb76,0x263df16e,0x6c3df17e,0x44fa88ae,0x98fee3fc,0x21dfaade,
    0x2fadeaeb,0x1db33bd1,0x0ff2b7a6,0x77f704c8,0x205501fb,0x313fa6fc,
    0x01bd7bfd,0x8f95fbd3,0xebade84d,0x468ba6c5,0x20fdabfc,0xba83ee2f,
    0x7fc41faa,0x7dd10eff,0x2bff0ffb,0x3ee2f879,0x5f301740,0xdb3d81f5,
    0x81f75f30,0x540fccf8,0x3e0be9b7,0x2b361ae3,0x29b6b84f,0x45c9362f,
    0x4d81aa4d,0x01f43f10,0x3e67fea0,0x7f55c43f,0x1d7f04eb,0x7cc4d8d5,
    0x360fdccc,0x42f80fde,0x43f117c4,0x443fedb8,0x3ea7d11f,0x7c2fcfa8,
    0x7e479bfb,0x741f88cd,0x41ffdc02,0xf700fb88,0x07fe607f,0x3e7fe7e6,
    0x20fa6b81,0x25105fed,0x676c174d,0x5d6ec5ec,0x6f55444f,0xfa8fc42a,
    0x55555512,0x6eeef541,0x7ff6443e,0xfada87dc,0x2a26c0be,0x21eeeeef,
    0x7c40fefd,0x87e17c01,0x443fcbee,0x4f54fa1f,0x57c2f8cf,0x77e47afb,
    0x22e83f0c,0x33ff2209,0x2012fa80,0x07fe606e,0x3f3fb3e2,0x0fa9f880,
    0x403fdfd8,0xfddfb04d,0x86fffd8b,0x1eeffee9,0x993fffe2,0x21eeeeee,
    0x3eaff9ea,0x3bfb37e2,0x7e6e40ee,0xcf84d83f,0x5360ba99,0x4d6e41b4,
    0xf98be2c9,0x9f733f30,0x77f77c41,0x3f6b7fe0,0x87fe97c0,0x5d03e62f,
    0x5bd5126c,0x0f34f881,0x667c4132,0xfccff80f,0x41377607,0x6c01f54d,
    0x22e49b04,0x6c05f74d,0x0157f104,0xeb75aa00,0x3fa6be23,0xedcf8399,
    0x5bd51289,0x6fffecc1,0xf555bd10,0x6fffec45,0xbf759f10,0x2fffffd8,
    0xf306f7ea,0xf881dfff,0x7c47f98c,0x2a25fbac,0x5c4eaacf,0xaafe83ee,
    0x42dea87c,0x0ee88ee8,0x037ccffc,0xbd103ff3,0x3aa07763,0x446f442d,
    0x23bd10ed,0x209b02fb,0x04402bfa,0xf9889fb8,0x7f77fdc4,0x7e47d45f,
    0xfffd9fba,0xfc81885f,0x102fffff,0x09dfff90,0x7ffc4062,0x008a5c1f,
    0x91f27ff9,0xfa89dfff,0x224fffff,0xfff87fff,0x7ffcc7ff,0x267ff61f,
    0xbd3744ff,0xff906e80,0xff51be6b,0x5ffdc3ff,0xbff93ffb,0x41dc07ec,
    0x201ffff8,0x8fff883b,0x0440fff8,0xffdff101,0x00003fff,0x00000000,
    0x00000000,0x00000000,0x00000000,0x00000000,0x00000000,0x00000000,
    0x77744000,0x776c4eee,0x15000005,0x3bae00a2,0x40000bde,0xbbbae808,
    0xd74c8005,0x90013b27,0x1309dddd,0x364ed826,0xd55dd34e,0x2a7bb63d,
    0x0a2515ee,0x04c09822,0x857106a2,0x882b82b8,0x33332a2b,0x02ae62cc,
    0x555541d5,0x50220aaa,0x555fe445,0x0ffe545d,0x03dfec88,0xef98ff54,
    0x2eb7a602,0x3bbba24e,0x909905fc,0xed87ffff,0x5320efbc,0x4cbb34e9,
    0x360cfede,0xadc2febd,0x5557dc5a,0x75fb12fa,0x237a619f,0x6cf61ee8,
    0x1fccfdc3,0x16d41df1,0xbaa96aba,0x59137363,0x33332a77,0x0f2e61cc,
    0x777744b9,0xd12a2fee,0x9713798d,0x3209bbb0,0xd305eaae,0xdfc8819f,
    0x23dc9b01,0x2fafdbfc,0xb8f376ee,0xffb30be6,0x72640397,0x755ff44b,
    0x90fea263,0x2be03aeb,0xffb87aff,0x2f88fa83,0xfc8bb4d8,0x22f6f44f,
    0x20d9622b,0x1a23e2fb,0x99998762,0x226e6c19,0x225d001f,0x3e6020fd,
    0x55f103ec,0x59bf501f,0x801bfb10,0x76c0dfd9,0xcb544fdc,0x7ff545d5,
    0x83e9ae2e,0x499000ec,0x8b72645b,0x45fc42fa,0xdffdb04e,0x209ff90b,
    0x1d906cbe,0x0ffcc1d9,0x5c9f11d9,0x4c1eedc2,0xd30fb725,0x7ffffe43,
    0x43bb364f,0x98ba0049,0x3fef9801,0x07f75f70,0xc89fb711,0xff3001ef,
    0xefeefd89,0x2eae5aa0,0x3ee17fdc,0x04c82fee,0xea8dc866,0x25b9320e,
    0x225badfa,0xfc84d8bd,0x3f623fcc,0x7d40dfaa,0xdc8dc82f,0x47f33e60,
    0x6f5ca60a,0x42ddc803,0x23dee819,0x08088888,0x001d8000,0x3a035798,
    0xcf86eeee,0xfd886c99,0x1bfb300d,0x71fc49b0,0xf13ab91f,0xcccf8d75,
    0x0d6ecc6c,0xdfff3374,0x6437625f,0xdffffd0e,0xf502e170,0x7fdc3f33,
    0x6e83ffaa,0x97071388,0x00000164,0x00000000,0x5c000000,0x45f501bf,
    0x7fff42fb,0x93fa601d,0xd101efc8,0x227f755b,0xfeafccff,0x44000820,
    0x441fffff,0x5ff70080,0x00005ff3,0x00000000,0x7cc00000,0x00860fba,
    0x110910c8,0x4c111111,0x5511aaaa,0x01555555,0x3fffe600,0x447ffc40,
    0x00980fff,0x174c7aa0,0x3fffff20,0x00000004,0x00000000,0x00000000,
    0x50000000,0x7c4913df,0x34c7c799,0x2a174576,0x3ffffea5,0xddd92fff,
    0x3fffea9d,0x0002ffff,0x00000000,0x00000000,0x00000000,0x00000000,
    0x00000000,0x36be0000,0x068bc6ef,0x81008ee0,0x19999999,0x00000000,
    0x00000000,0x00000000,0x00000000,0x00000000,0x00000000,0x5d410000,
    0x00005140,0x00000000,0x00000000,0x00000000,0x00000000,0x00000000,
    0x00000000,0x00000000,0x00000000,0x00000000,0x00000000,
};

static signed short stb__courier_bold_15_latin1_x[224]={ 0,2,1,0,1,1,1,3,3,1,1,0,2,1,
2,1,1,1,0,0,0,0,1,0,1,1,2,2,-1,0,0,1,1,-1,0,0,0,0,0,0,0,1,0,0,
0,-1,-1,0,0,0,0,0,0,0,-1,-1,0,0,0,3,1,1,1,-1,2,0,-1,0,0,0,0,0,0,0,
1,0,0,-1,0,0,-1,0,0,0,0,0,0,-1,0,0,1,2,3,2,0,1,1,1,1,1,1,1,1,1,
1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,0,2,1,0,0,0,
3,0,1,-1,1,0,-1,1,-1,-1,1,0,1,2,2,0,0,2,2,2,1,0,0,-1,0,1,-1,-1,-1,-1,
-1,-1,-1,0,0,0,0,0,1,1,1,1,-1,-1,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,
0,0,0,0,-1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,-1,0,
 };
static signed short stb__courier_bold_15_latin1_y[224]={ 11,2,3,1,1,2,3,2,2,2,2,3,9,6,
9,1,2,2,2,2,2,2,2,2,2,2,5,5,3,5,3,2,2,3,3,2,3,3,3,2,3,3,3,3,
3,3,3,2,3,2,3,2,3,3,3,3,3,3,3,2,1,2,2,13,2,4,2,4,2,4,2,4,2,2,
2,2,2,4,4,4,4,4,4,4,3,5,5,5,5,5,5,2,2,2,5,2,2,2,2,2,2,2,2,2,
2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,11,5,1,2,4,3,
2,2,2,3,2,5,6,6,3,0,1,1,2,2,2,5,2,5,10,2,2,5,2,2,2,5,0,0,0,0,
0,-1,3,2,0,0,0,0,0,0,0,0,3,0,0,0,0,0,0,4,2,0,0,0,0,0,3,2,2,2,
2,2,2,1,4,4,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,3,4,2,2,2,2,2,2,2,
 };
static unsigned short stb__courier_bold_15_latin1_w[224]={ 0,3,6,8,6,6,7,2,4,4,6,8,4,6,
3,6,6,6,7,8,7,8,7,7,6,7,3,4,9,8,9,6,6,10,8,8,8,8,8,8,8,6,9,9,
8,10,9,8,8,8,9,8,8,8,10,10,8,8,8,4,6,4,6,10,4,8,9,8,9,8,8,8,8,8,
6,8,8,10,8,8,9,9,8,8,8,8,8,9,8,8,6,4,2,4,8,8,8,8,8,8,8,8,8,8,
8,8,8,8,8,8,8,8,8,8,8,8,8,8,8,8,8,8,8,8,8,8,8,8,0,3,6,8,8,8,
2,8,6,9,6,8,9,6,9,10,6,8,5,4,4,8,8,3,4,4,6,8,8,10,8,6,10,10,10,10,
10,10,10,8,8,8,8,8,6,6,6,6,9,9,8,8,8,8,8,6,8,8,8,8,8,8,8,8,8,8,
8,8,8,8,10,8,8,8,8,8,8,8,8,8,8,8,8,8,8,8,8,8,8,8,8,8,8,8,9,8,
 };
static unsigned short stb__courier_bold_15_latin1_h[224]={ 0,10,4,12,12,10,9,5,12,12,7,8,5,2,
3,12,10,9,9,10,9,10,10,10,10,10,7,8,8,5,8,10,11,8,8,10,8,8,8,10,8,8,9,8,
8,8,8,10,8,11,8,10,8,9,8,8,8,8,8,12,12,12,5,2,3,8,10,8,10,8,9,10,9,9,
12,9,9,7,7,8,10,10,7,8,9,7,6,6,6,9,6,12,12,12,4,9,9,9,9,9,9,9,9,9,
9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,0,9,11,9,7,8,
12,11,3,9,5,6,5,2,9,3,5,10,5,5,3,9,11,3,4,5,5,6,9,9,9,9,11,11,11,11,
11,12,8,12,11,11,11,11,11,11,11,11,8,11,12,12,12,12,12,6,10,12,12,12,12,11,8,10,10,10,
10,10,10,11,8,10,10,10,10,10,9,9,9,9,10,9,10,10,10,10,10,8,8,10,10,10,10,12,12,12,
 };
static unsigned short stb__courier_bold_15_latin1_s[224]={ 253,237,186,54,189,212,147,253,157,107,70,
196,230,225,250,196,65,155,162,72,189,81,90,98,124,131,95,251,30,214,40,
139,43,10,50,164,35,17,1,182,177,1,170,158,91,223,71,37,205,116,186,
115,168,224,147,136,127,118,109,70,63,49,177,232,209,44,241,26,191,8,197,
106,180,233,29,215,206,59,108,242,46,175,86,21,129,99,152,133,143,84,117,
36,41,44,177,138,138,138,138,138,138,138,138,138,138,138,138,138,138,138,138,
138,138,138,138,138,138,138,138,138,138,138,138,138,138,138,138,138,253,251,100,
57,77,100,75,107,193,20,223,124,235,225,10,214,201,146,208,196,204,1,50,
200,245,184,189,161,48,118,93,102,231,242,1,12,32,78,245,98,59,68,77,
212,86,125,93,132,81,221,112,121,130,139,148,170,166,162,171,180,89,23,53,
237,246,1,10,28,148,203,234,203,194,185,157,139,30,75,109,39,19,66,219,
228,173,201,210,214,62,228,219,155,56,20,10,1, };
static unsigned short stb__courier_bold_15_latin1_t[224]={ 7,25,62,1,1,13,37,1,1,1,56,
47,56,62,56,1,26,37,37,26,37,26,26,26,26,26,56,37,56,56,56,
25,14,56,56,25,47,47,56,25,47,47,37,47,47,47,47,26,47,14,47,
26,47,37,47,47,47,47,47,1,1,1,56,62,62,47,25,47,25,47,37,
26,37,37,1,37,37,56,56,37,26,14,56,56,37,56,56,56,56,37,56,
1,1,1,62,37,37,37,37,37,37,37,37,37,37,37,37,37,37,37,37,
37,37,37,37,37,37,37,37,37,37,37,37,37,37,37,37,37,7,25,14,
37,56,47,1,14,62,37,56,56,56,62,37,62,56,25,56,56,62,37,14,
62,56,56,56,56,37,37,37,37,1,1,14,14,14,1,47,1,14,14,14,
1,14,14,14,14,47,1,1,1,1,1,1,56,14,1,1,1,1,14,47,
13,13,26,26,26,14,1,47,13,14,14,14,14,37,37,37,37,26,37,13,
13,25,25,25,47,47,25,25,25,26,1,1,1, };
static unsigned short stb__courier_bold_15_latin1_a[224]={ 127,127,127,127,127,127,127,127,
127,127,127,127,127,127,127,127,127,127,127,127,127,127,127,127,
127,127,127,127,127,127,127,127,127,127,127,127,127,127,127,127,
127,127,127,127,127,127,127,127,127,127,127,127,127,127,127,127,
127,127,127,127,127,127,127,127,127,127,127,127,127,127,127,127,
127,127,127,127,127,127,127,127,127,127,127,127,127,127,127,127,
127,127,127,127,127,127,127,127,127,127,127,127,127,127,127,127,
127,127,127,127,127,127,127,127,127,127,127,127,127,127,127,127,
127,127,127,127,127,127,127,127,127,127,127,127,127,127,127,127,
127,127,127,127,127,127,127,127,127,127,127,127,127,127,127,127,
127,127,127,127,127,127,127,127,127,127,127,127,127,127,127,127,
127,127,127,127,127,127,127,127,127,127,127,127,127,127,127,127,
127,127,127,127,127,127,127,127,127,127,127,127,127,127,127,127,
127,127,127,127,127,127,127,127,127,127,127,127,127,127,127,127,
127,127,127,127,127,127,127,127, };

// Call this function with
//    font: NULL or array length
//    data: NULL or specified size
//    height: STB_FONT_courier_bold_15_latin1_BITMAP_HEIGHT or STB_FONT_courier_bold_15_latin1_BITMAP_HEIGHT_POW2
//    return value: spacing between lines
static void stb_font_courier_bold_15_latin1(stb_fontchar font[STB_FONT_courier_bold_15_latin1_NUM_CHARS],
                unsigned char data[STB_FONT_courier_bold_15_latin1_BITMAP_HEIGHT][STB_FONT_courier_bold_15_latin1_BITMAP_WIDTH],
                int height)
{
    int i,j;
    if (data != 0) {
        unsigned int *bits = stb__courier_bold_15_latin1_pixels;
        unsigned int bitpack = *bits++, numbits = 32;
        for (i=0; i < STB_FONT_courier_bold_15_latin1_BITMAP_WIDTH*height; ++i)
            data[0][i] = 0;  // zero entire bitmap
        for (j=1; j < STB_FONT_courier_bold_15_latin1_BITMAP_HEIGHT-1; ++j) {
            for (i=1; i < STB_FONT_courier_bold_15_latin1_BITMAP_WIDTH-1; ++i) {
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
        float recip_width = 1.0f / STB_FONT_courier_bold_15_latin1_BITMAP_WIDTH;
        float recip_height = 1.0f / height;
        for (i=0; i < STB_FONT_courier_bold_15_latin1_NUM_CHARS; ++i) {
            // pad characters so they bilerp from empty space around each character
            font[i].s0 = (stb__courier_bold_15_latin1_s[i]) * recip_width;
            font[i].t0 = (stb__courier_bold_15_latin1_t[i]) * recip_height;
            font[i].s1 = (stb__courier_bold_15_latin1_s[i] + stb__courier_bold_15_latin1_w[i]) * recip_width;
            font[i].t1 = (stb__courier_bold_15_latin1_t[i] + stb__courier_bold_15_latin1_h[i]) * recip_height;
            font[i].x0 = stb__courier_bold_15_latin1_x[i];
            font[i].y0 = stb__courier_bold_15_latin1_y[i];
            font[i].x1 = stb__courier_bold_15_latin1_x[i] + stb__courier_bold_15_latin1_w[i];
            font[i].y1 = stb__courier_bold_15_latin1_y[i] + stb__courier_bold_15_latin1_h[i];
            font[i].advance_int = (stb__courier_bold_15_latin1_a[i]+8)>>4;
            font[i].s0f = (stb__courier_bold_15_latin1_s[i] - 0.5f) * recip_width;
            font[i].t0f = (stb__courier_bold_15_latin1_t[i] - 0.5f) * recip_height;
            font[i].s1f = (stb__courier_bold_15_latin1_s[i] + stb__courier_bold_15_latin1_w[i] + 0.5f) * recip_width;
            font[i].t1f = (stb__courier_bold_15_latin1_t[i] + stb__courier_bold_15_latin1_h[i] + 0.5f) * recip_height;
            font[i].x0f = stb__courier_bold_15_latin1_x[i] - 0.5f;
            font[i].y0f = stb__courier_bold_15_latin1_y[i] - 0.5f;
            font[i].x1f = stb__courier_bold_15_latin1_x[i] + stb__courier_bold_15_latin1_w[i] + 0.5f;
            font[i].y1f = stb__courier_bold_15_latin1_y[i] + stb__courier_bold_15_latin1_h[i] + 0.5f;
            font[i].advance = stb__courier_bold_15_latin1_a[i]/16.0f;
        }
    }
}

#ifndef STB_SOMEFONT_CREATE
#define STB_SOMEFONT_CREATE              stb_font_courier_bold_15_latin1
#define STB_SOMEFONT_BITMAP_WIDTH        STB_FONT_courier_bold_15_latin1_BITMAP_WIDTH
#define STB_SOMEFONT_BITMAP_HEIGHT       STB_FONT_courier_bold_15_latin1_BITMAP_HEIGHT
#define STB_SOMEFONT_BITMAP_HEIGHT_POW2  STB_FONT_courier_bold_15_latin1_BITMAP_HEIGHT_POW2
#define STB_SOMEFONT_FIRST_CHAR          STB_FONT_courier_bold_15_latin1_FIRST_CHAR
#define STB_SOMEFONT_NUM_CHARS           STB_FONT_courier_bold_15_latin1_NUM_CHARS
#define STB_SOMEFONT_LINE_SPACING        STB_FONT_courier_bold_15_latin1_LINE_SPACING
#endif
