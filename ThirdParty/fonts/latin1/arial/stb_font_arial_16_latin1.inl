// Font generated by stb_font_inl_generator.c (4/1 bpp)
//
// Following instructions show how to use the only included font, whatever it is, in
// a generic way so you can replace it with any other font by changing the include.
// To use multiple fonts, replace STB_SOMEFONT_* below with STB_FONT_arial_16_latin1_*,
// and separately install each font. Note that the CREATE function call has a
// totally different name; it's just 'stb_font_arial_16_latin1'.
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

#define STB_FONT_arial_16_latin1_BITMAP_WIDTH         256
#define STB_FONT_arial_16_latin1_BITMAP_HEIGHT         86
#define STB_FONT_arial_16_latin1_BITMAP_HEIGHT_POW2   128

#define STB_FONT_arial_16_latin1_FIRST_CHAR            32
#define STB_FONT_arial_16_latin1_NUM_CHARS            224

#define STB_FONT_arial_16_latin1_LINE_SPACING          10

static unsigned int stb__arial_16_latin1_pixels[]={
    0x1500cca2,0x40981510,0x03500a61,0x5000d440,0x0060504c,0x51350331,
    0x00802660,0x00544002,0x16e001e4,0xa801f540,0x35288051,0xd80074c0,
    0x2006ec02,0x2a009999,0x221e980d,0x6c136f30,0x2c86b81e,0x883eb87c,
    0x32206edf,0x00dfdcee,0x0722c962,0x87ec807e,0xef80f9be,0x36603604,
    0xfdfd300c,0x007c403d,0x5f3003d0,0xfdcb803f,0x03dbd403,0x03540264,
    0x3621af72,0x205fffff,0x5c96e02e,0x07c40446,0x0c2c80b8,0x3e9321aa,
    0x1d7019d0,0x222c8760,0x3cc01f85,0x20c61111,0x7dc3401f,0x1fcc1fdd,
    0x01b981b2,0x51003930,0xa9980155,0x0aaa8801,0x22186088,0x3110c110,
    0xffb86261,0x05440b77,0x0cee4510,0x198f10a2,0x0a859144,0x043b21a6,
    0x317513d8,0xc8d30d53,0x2e7e16c2,0x0fa7981b,0x881f83e2,0x9b9e84cb,
    0x6c42ec6b,0x7ff7f4c1,0xffdfd302,0x3fbfa605,0xfdfd302f,0x3bfa605f,
    0x441f42ff,0x1f107d0f,0x743e20fa,0x540b77ff,0xdc97205f,0x1e22e46a,
    0x0b25c8d5,0x7c43cc1f,0x3a29701e,0x83b3eecd,0x16a1643c,0x985f9bff,
    0x83e20fa7,0x7ee7cc1f,0x406e3e63,0x19f3002f,0x33e617d4,0x9f30bea0,
    0x3e617d41,0xf30bea0c,0x7d17d419,0x20fa1f10,0xf107d0f8,0x2ddfff61,
    0x3201f9b0,0xe87e3725,0x87e234c2,0x81f0b22e,0x67dcf447,0x2e4e96c0,
    0x42e8771f,0x93e3cc2c,0x07d3cc7a,0x3a0fc1f1,0xcde8b5d3,0xd000f981,
    0x09d1ee09,0x2e09d1ee,0x47b82747,0x1f4f704e,0x883e87c4,0x1f107d0f,
    0x82ddffe6,0xb903e8f8,0x8f34cae4,0xf34c83e9,0x3207c2c8,0x2f4cd50d,
    0xf983e63e,0x801f8970,0xf88be0f8,0x883e9e61,0x8f887e0f,0x7dfb1058,
    0xf8801f88,0x3e21f101,0x3e21f101,0x3e21f101,0x3e21f101,0x0fa1f101,
    0x441f43e2,0x1f107d0f,0x2e0b77b8,0xc9720d75,0xd9132f35,0x32265e60,
    0x4be607c2,0x447e23f8,0x366a8d76,0x22007e22,0x45f03e0f,0x3e20fa79,
    0xa8f887e0,0x22fe5c02,0x3e63502f,0x07ccbe00,0x803e65f0,0x7c01f32f,
    0x97c01f32,0x7d0f883e,0x20fa1f10,0x5bbc40f8,0x207e25d0,0xfae9725c,
    0xf5d05b81,0x207c2c83,0x446fd41e,0x3a355e27,0xa85d0d34,0x98be3cc1,
    0x83e9e60f,0x3f07e0f8,0x26e0911b,0x221b60f9,0x2203f32f,0x2203f32f,
    0x2203f32f,0x2203f32f,0x2203f32f,0x1f107d2f,0x743e20fa,0xbc40f883,
    0x999f985b,0x9725c85d,0x20d306eb,0x7c2c86eb,0x7ec41e20,0x5fc4f41e,
    0x81facfc8,0x1aa1643d,0x98bb11bf,0x83e61367,0x4caeec1f,0x07c4ddea,
    0x17aa3bd1,0xf83ea09f,0x27c1f504,0x413e0fa8,0x5413e0fa,0x1f309b0f,
    0x6c3e6136,0xbc40f984,0xeeeec85b,0xb92e40fe,0x07881fc4,0xf85907f1,
    0x5f501e60,0x95dd54c8,0x897063bf,0x33e25c2c,0x93cc0dff,0x81f8f70b,
    0x3e20dffd,0xd985cabb,0x3640beff,0xd83646d8,0x46d83646,0x6c8db06c,
    0x5c2e4db0,0xc9ee1727,0x77887b85,0x87d05f0b,0x0f89725c,0x03e20f10,
    0x260f88b2,0x116e1b86,0x43e8809d,0x3d0b20f8,0x9e6011f8,0x3fb88cf9,
    0x805640fc,0x200dfff9,0x45f7404b,0xbee80fea,0xee80fea8,0xe80fea8b,
    0x80fea8be,0x0fea8bee,0x3ee233e6,0x2e233e63,0x2233e63f,0xb77883fb,
    0xc8d907a8,0x404d9885,0x4136622f,0x644f512c,0x4e99eb85,0x889bde88,
    0x47703fca,0x07e12a2c,0x7f547a88,0x40af83ef,0x10057006,0x7f64407b,
    0xfd9101df,0x3b2203bf,0xd9101dff,0x32203bff,0xea81dffe,0xfea83eff,
    0xffea83ef,0x16ef103e,0xc8be209b,0x400df885,0x01bf13fb,0xf91fdcb2,
    0x013fae03,0x19bffdb5,0x0e8b2680,0x1bb200e8,0x893ba008,0x98011003,
    0x001000df,0x00040008,0x40010002,0x02001000,0x0012ab10,0x00000000,
    0x00000000,0x00000000,0x00000000,0x00000000,0x00000000,0x00000000,
    0x00000000,0x00000000,0x00000000,0x00000000,0x00000000,0x00000000,
    0x00000000,0x00000000,0x00000000,0x9801d300,0x40bb100d,0x2d40288a,
    0x2601b500,0x5017620e,0x0a22a07d,0x44031151,0x23500332,0x20015002,
    0x201309a8,0x00cc01a9,0x029828a2,0x00a602a8,0x1a805115,0x004006a0,
    0x99028035,0x33603d80,0x0d53f04d,0x0ba007b0,0x2e66c3d8,0xf82eaf88,
    0x7f66c7aa,0x026dea01,0x2017f76a,0x7f4c039b,0x4c0ebfee,0x442ffefe,
    0xb300fdef,0x807e61e2,0x7d100aa9,0x30354fc0,0x07baa03f,0x203b3ba2,
    0x4b301eea,0x099a9998,0x13335331,0x26a66a62,0x35335310,0x0880cc01,
    0x20541306,0x33101989,0x23333013,0x31018188,0x98880133,0x40775000,
    0x0fee1cf9,0x17d419f3,0x3b81ecbb,0x900a60b3,0x46038807,0xc80aa008,
    0x35188399,0x640e6720,0x3fffffa3,0xfffffd3f,0x3ffffa7f,0xffffd3ff,
    0x17ea07ff,0x23640fdc,0x5405c85c,0xee97205f,0xfa807c40,0x00bf5005,
    0x84d817ea,0xb82747de,0x542e8fa7,0x82dcacea,0x0aeea02a,0x55015dd4,
    0xa815dd40,0x577502bb,0x41d01540,0x201f403e,0x001f403e,0x36c03f36,
    0x90b907e6,0x00fcd80b,0x2227f4b9,0x01f9b00f,0xb001f9b0,0xb07e01f9,
    0x07e23f37,0xd52f87c4,0xbd99f970,0x17e67547,0x913f2fb2,0xea89f97d,
    0x5f642fcc,0x65f644fc,0x7e5f644f,0x17e67544,0xe807d1a2,0x3a01f403,
    0x3a3e2003,0x1f47f103,0x102e42e4,0x97207d1f,0x03e22fce,0x100fa3e2,
    0xf8807d1f,0x20f983e8,0x07ccbe4c,0x264be5f0,0x5d03a788,0x5c1d12d4,
    0x46b83a26,0x0e896a2e,0x2e0e89ae,0x46b83a26,0x89516a2e,0x201f403e,
    0x001f403e,0xfb81aeb7,0x90b906c8,0x06badc0b,0x876574b9,0xd75b80f8,
    0x80d75b80,0x1f30d75b,0xf32f892e,0x97cbe203,0xf15a83f9,0xfbaaaf88,
    0x43edcc40,0x3e27db98,0x440fbaaa,0xb9887db9,0x7db9887d,0x3eeaabe2,
    0xfffd0b20,0x3ffa1fff,0xffd0ffff,0x3fa1ffff,0xe80fffff,0x76c03f12,
    0xb90b900f,0x81f89740,0x8a74ba5c,0x3f12e80f,0x01f89740,0x220fc4ba,
    0x07dc5a9f,0x7c3ea09f,0xfed97a62,0x9f54efee,0x7e439999,0x6fe47cbd,
    0x333ea7cb,0x37f21ccc,0x5efe47cb,0x65efe47c,0x33333ea7,0x2b7a1e1c,
    0x5bd0aaaa,0x37a15555,0xbd0aaaaa,0x98155555,0x205d999f,0x217203f8,
    0x333f305c,0x974b90bb,0x4c0f8af9,0x305d999f,0x20bb333f,0x85d999f9,
    0x646d86ed,0x217cdb06,0x937d10f8,0x503e2139,0x54f707d4,0x0f89ee0f,
    0x3dc1f514,0xf53dc1f5,0x81f13dc1,0x00fa1662,0x403e807d,0xddd9003e,
    0x17c01fdd,0x20b90b90,0x0feeeeec,0x7e45d2e4,0x777640f9,0xeec80fee,
    0xec80feee,0x540feeee,0x01dd51df,0x1fd517dd,0x479add7c,0x19b05b0f,
    0xd10f99b2,0x7e887ccf,0x266c866c,0x7ccfd10f,0x87ccfd10,0xc866c7e8,
    0x00fa0ee6,0x403e807d,0xd05f003e,0xb9017c07,0x20be0b90,0x85d2e43e,
    0x417c0fde,0x3e82f83e,0x223e82f8,0x0dfffd9e,0x3bffd910,0x2efd8af8,
    0xc880e9a2,0x77e41dff,0x3bf20fae,0x3f220fae,0x777e41df,0x3bbf20fa,
    0x3bbf20fa,0x3ff220fa,0x33a0761d,0x9d099999,0x3a133333,0xd099999c,
    0x41333339,0x7c0d907a,0x17217202,0x323641ea,0x1ff30ba5,0x546c83d4,
    0x07a8d907,0x000408d9,0x41008002,0x80080001,0x00100000,0x40001001,
    0xfffffd01,0x3ffffabf,0xffffd5ff,0x3fffabff,0x41365fff,0x405f02f8,
    0x4d85c85c,0xd2e45f10,0x26c1f905,0x41362f88,0x441362f8,0x0000002f,
    0x00000000,0x00000000,0x00000000,0x00000000,0x00000000,0x00000000,
    0x00000000,0x00000000,0x00000000,0x00000000,0x00000000,0x801100d4,
    0x5014c008,0x21880511,0x05544001,0x06a006a0,0x404c02a2,0x13015009,
    0x81a80260,0x22019819,0x4004400a,0x9805301a,0x5115051b,0x00a88028,
    0x80088020,0x3f3000a9,0x81bffd10,0x440dfed8,0x9f82fdee,0x1f3d406a,
    0xfddfd100,0x807baa09,0x7df541f9,0x17dc34c0,0x417dc2d4,0x703e6069,
    0x500e89bb,0x6c403fbf,0x1eea80ed,0x9f701f98,0xd53f0fbd,0xdfd301d8,
    0x9dd105df,0x5fee981d,0x3db79d70,0x29b02a80,0x7b2644d8,0x461aa5b8,
    0x1f3d4008,0x7444e880,0x20399c84,0xd03aa02a,0x442da883,0x416d440e,
    0x3e06a01e,0x5d0254f0,0x3edc8172,0x26073390,0x1f61f882,0x20ee0446,
    0x07ee0cf9,0x8fa06a31,0x74425c4e,0x3e20aa01,0x5c5f1e60,0x150a1746,
    0x2aae6144,0x206e63e7,0x710b505d,0x7015c405,0x5901e41b,0x90b202d8,
    0x12882a07,0x200e87cf,0x54c09b3f,0x510540fa,0x47a82b88,0x42bba87a,
    0xd904e868,0x17105710,0x3beb52e4,0x9d50d14d,0x223cc5f9,0x3a67b20f,
    0x1f102743,0xdd9f73d4,0x1fe6f7cf,0xcfb800ba,0x6e7dc2fd,0xa96c6a2f,
    0x09716405,0x441662c8,0x99d9ea0f,0xefa80956,0xfdbd500d,0x4f507c4b,
    0x2e2fdcfb,0x2fb23cc6,0xf10744fc,0xfb83e603,0x3e602fdc,0x23b34722,
    0x4b51741c,0x7f41f87a,0x2677545f,0x22f507c4,0x24f9f61f,0x983f10fa,
    0xa87e2199,0x26a87e26,0x01d14ed8,0x700d31b8,0x7c403a23,0x1dd99ea0,
    0x0ffb801d,0x227b8ba0,0x0fc5ea0f,0xf707c4d5,0xc8d70744,0x2f803e62,
    0xe83543f1,0xd75f345f,0x555f11d4,0x3e1ea1f7,0x976633a1,0xf882afc9,
    0x2e3d5ea0,0x11f887e7,0x7fffc43f,0x50f88f51,0x3600f88f,0x23d01ea2,
    0x8b601eed,0x7a83e279,0x0675d2a0,0x876dd3db,0xf88fc479,0x223d5ea0,
    0x3aa77a0f,0x47db9887,0x4407e64a,0x0f88f51f,0xf86cdb30,0xfa8ae1ea,
    0xf31ccccc,0x41f30f88,0x881e60f8,0x235dea0f,0x43f03e79,0x2a3f103e,
    0xf0d52f86,0x7e992e05,0x3b94cf20,0x13f4c970,0x1d03d41f,0x87c4eed3,
    0x1aa0fdf8,0xf507c47e,0xd70be1aa,0xbdfc8f79,0x0fe3c47c,0xf86a87cc,
    0x95c3e602,0xf106cd16,0xa83e2281,0x41f11e67,0xf70fc04b,0x3e7b83e6,
    0x01d91e62,0x983e23f1,0x7cc1f10f,0x27a26880,0x3d30b507,0x3cf44d10,
    0x9707b87e,0x0f9acd2e,0x41f317e6,0x2f70fc79,0x443e60f8,0x41f52d41,
    0x9b61d87b,0x3e25d8b9,0x06cc3e60,0x963a61f3,0x0cd85aab,0xe98dc8d9,
    0x25c89f43,0x0989abfa,0x9d3f453e,0x4f7cfd31,0x8aed84d8,0x3360fea8,
    0x466c6d88,0x643d06d8,0x07443fce,0x90f403aa,0x8a7c7f9d,0x5661d07e,
    0x36237a4a,0x446743ff,0x7e8a7c4d,0xd1b62336,0x7cc7d317,0x4770fd10,
    0xffd8aee8,0x36c466c0,0x2626c53a,0x4416a21e,0x5c41dffc,0xffc984fe,
    0x3b33b20c,0x3bfea2ff,0x2f7fa27a,0x033fabe7,0x0677ff64,0x1037ff22,
    0x7901bff9,0x6c0f9988,0x2166fcc2,0x07ccc43c,0x70f5dff5,0x221ece89,
    0x46a8dffc,0x540bffe8,0x3227aeff,0x7ecc0dff,0xaeefc83e,0x3222cc0f,
    0x20dedffe,0x4c0dffc8,0xc980cffd,0x00003eee,0x01100000,0x00001002,
    0x00000044,0x0a20c028,0x05026662,0x0a801018,0x08002018,0x00000080,
    0x04030010,0x0040006a,0x00000000,0x00000000,0x00000000,0x00000000,
    0x00000000,0x00000000,0x00000000,0x00000000,0x26660000,0x26002009,
    0x0601100a,0x05440044,0x22a01510,0x0a20cc28,0x026a6030,0x44080220,
    0x06601440,0x4cc4a22a,0x26009999,0x01333300,0x11011033,0x11730510,
    0x20ddc545,0x4ccc4008,0x99998809,0x51986099,0x6ffff985,0x40f775c4,
    0x41edbceb,0x260f883e,0xfd305ffd,0x0fa03dfd,0x1aa354fc,0x223cc0b9,
    0xd82ffefe,0x8d901ede,0x5407cc5d,0x2be1eedf,0xfffff57a,0x417ea05f,
    0x22ffffff,0xd317c45d,0x07d43bfd,0x7cfbb7f7,0x0fa2fcde,0x9fffffd0,
    0xffffffe8,0x75761f13,0x97202dc2,0x74425c5c,0x83e20fa1,0x7f31364d,
    0x207106c8,0x21f88111,0xbb1e602e,0x4ca07dc1,0x5d8df501,0x26b8fa00,
    0x1b201889,0x2f80fcd8,0x5fd503dc,0x440b91ec,0x24f9f61f,0x06673a7a,
    0x749f50fa,0x2607c403,0x880f21ce,0x55a8a20f,0x74d11bbd,0x1f10f883,
    0x221763cc,0x42882a1d,0x269902b8,0x0fa3cc07,0x05952876,0x45d8d7d1,
    0x7c448879,0x0f980660,0xf07d1f10,0xfa81f885,0x4c1d12fa,0x5c7a920f,
    0xd1f88be7,0x74bfffff,0x07d0fa83,0x6fdc0f88,0x30772fa2,0x9c81771f,
    0x472530e8,0xf30f883e,0x00be0f98,0x2e7a83e2,0xbcc2fdcf,0x323cc04c,
    0x377e00bf,0x3556c4fc,0x200d5172,0x7d02646b,0xf86badc0,0xf08835c2,
    0x4d13dc05,0x81f3cc6a,0x4fa87d2f,0x3a5f107d,0x7407c403,0x27e5f7c2,
    0x45f9bdd5,0x74ea0956,0x8ba0f883,0x001f31fc,0xf8bd41f1,0x3eba1aa1,
    0x7e43cc01,0x727c0bef,0x646aadcd,0x2e00be64,0x7a82641f,0x41f89740,
    0x01ffffff,0x47f302f8,0x7b83e278,0x7d0f98be,0x740fad90,0xffffffd3,
    0x0ba03e21,0x8bea7a83,0x1126366a,0x7c41f4ae,0x3f7b7ee0,0xf1003f11,
    0x447abd41,0x40375c0f,0x3fae6079,0xd3798be1,0x26971aa1,0x81f9802f,
    0x4c09b04c,0x7c5d999f,0x31fca99b,0x9f305f03,0x4c66c798,0x36237e7e,
    0x75360fa5,0x2b7a7d03,0x1f10aaaa,0x7c017466,0x8fc41f51,0x6cf23d2b,
    0x81f309b0,0x17c1f1a8,0x541f11a8,0x885f0d57,0x2279803f,0x30fc9b02,
    0x3f733b6f,0x0136770c,0x884c8264,0x3bbb200f,0x20be0fee,0x85f0bb4d,
    0x20f983f9,0x3e7cffc8,0x33a0dffc,0x7d1fca99,0x201f4be0,0x8babb0f8,
    0x443e60e8,0x74c3e60f,0x4b53dc88,0x2147b85c,0x7c436c79,0xf17b87e2,
    0x3e207cc1,0x89ea5b80,0x87e4c81f,0xfb999779,0x226c2219,0x9901983e,
    0x82f80d70,0x5760be3e,0x3ea2f848,0x2101f502,0x74047e7a,0x3a2defff,
    0x07d0fb83,0x0cd80f88,0x362ec53a,0x1e98bb15,0x19f316a2,0x13d87f71,
    0x51de885d,0xfd14f8bd,0x136c466c,0x2be209b3,0x4576c5d8,0x987e2fa8,
    0x5198d507,0x501f715f,0x13213203,0x7cd907a8,0x72fb999b,0x33e25f03,
    0x03ea1999,0xe807e7a8,0x54ce7403,0x2673a3fc,0x21f10999,0x6ccbf729,
    0xfeb80dff,0xeeec980d,0x7dffd503,0x207dfb30,0x40beffd9,0x227aeffa,
    0x3e20dffc,0x3bfae00d,0x2efffc80,0x2a0f30fc,0x9fb52ec6,0x26413603,
    0x209b01f4,0xfffff2f8,0x2e5f005b,0x31ffffff,0x1d2cc01d,0x3fa01f40,
    0x7f42dfff,0xf15fffff,0x00201721,0x04000004,0x00100040,0x20000001,
    0x00008800,0x00000000,0x00000000,0x00000000,0x00000000,0x00000000,
    0x00000000,0x00000000,0x00000000,0x00000000,0x00000000,0x00000000,
    0x00000000,0x80980180,0xa8030608,0x2e6054c2,0x14c14c0a,0x00999988,
    0x33333330,0x26666213,0x44502a19,0x4ccc4300,0x01309999,0x26004c31,
    0x22199999,0x80c42600,0x02602218,0x13004426,0x31098066,0x00881333,
    0x04cccc43,0x26059710,0x85c803f0,0x01f87e3f,0x0f7dc3f1,0x443f99f5,
    0x20bbe62f,0x04fffffe,0x7fffffd4,0xffffd2ff,0xf88ba1ff,0x21f107d0,
    0xfffffffc,0x23f985f3,0x3ffe202f,0x3f71ffff,0xe84e8d90,0x8df31724,
    0x260d90f8,0xf305ff0f,0x3fffffad,0xf881dd0d,0xffddddd0,0x6dbde885,
    0x401f8fdc,0x831ae2f8,0x4d85301f,0x989717c4,0x3a126ae2,0x9d027543,
    0x01f401f1,0x7d0f88ba,0x0f301f10,0x7c3f98be,0x6c5e8002,0x3e60fcc6,
    0xb8f51b22,0xf99ae0fd,0x17be5c80,0x221f5bf2,0xf889fd4e,0x47c887d0,
    0xca886479,0x5c0d43f1,0x20a85f16,0x8662b89f,0x03e62dea,0xd0198330,
    0xf501f507,0x1f401f11,0xd0f88ba0,0xf301f107,0x41fccbe0,0x076c002f,
    0x703e8fe2,0xf881f51f,0x4d8bab61,0x9f17c1f4,0x0fad9d0f,0x117e75b2,
    0x3e20fa1f,0x406fba21,0x03b63f1c,0x0fc2e5f4,0x327f9bdf,0x7a93bae4,
    0x82644c80,0x9d05f03e,0x03e803e2,0x3a1f1174,0x7980f883,0x207f35f0,
    0x07ee002f,0x203647dc,0x25d02fdd,0x0be4c8f8,0x57c7a8d7,0x75afa62e,
    0xd95d4d83,0x41f43e21,0xefeb887b,0x5d9f8e40,0x35ff7310,0x5c7f0fc1,
    0x443d8996,0x8990e60f,0xccdfc84c,0x21f50fa0,0x25eeeef8,0x21eeeeee,
    0x7f43e63e,0x80ffffff,0x7ff9f079,0x7d400be0,0x007f6c02,0x54c817e2,
    0x443c5e6d,0x75f1361f,0xdeb5de4b,0x5d1fdbaa,0xee87c53a,0x442eeeee,
    0x2390fa22,0xdd700fef,0x0fc5ddff,0x44cbcc3f,0xd88cd83d,0x21322643,
    0x3a0aadfa,0x7d4cef43,0x37a2aaab,0x3ba0aaaa,0x39d0fd88,0x301f5333,
    0x3eabfe0f,0xf8802f81,0x803f8804,0x2d301ffc,0x416a7e3c,0xaf81f14d,
    0x75ae3e79,0x3a1ceeee,0x21f15f32,0x106ebade,0xf80ba23f,0xb33105dd,
    0xf0fc133b,0x6c4cbcc3,0x84ffc883,0x3e82644c,0x7ffcc3f0,0x0fa00fff,
    0x1f9ffbd0,0x203e20fa,0x36c7f079,0x02f4017c,0x9fa805f0,0x87a3e06d,
    0x2f503cad,0x35d2f85b,0x201f5aeb,0x43e7f22e,0xeb82f43e,0x3f0ee4ff,
    0xfdd705f1,0xf0fc5ddf,0x6c4cbcc3,0x2640be03,0x5c1f4132,0x1f11360f,
    0x4ba01f40,0x0f883e80,0x445f0798,0x36017c4f,0x80be000e,0x209d13f8,
    0x0f65c7bd,0x5f05d3f0,0xeb5cb36e,0x37a17403,0x4f887d0f,0x3f0ee020,
    0x04c803ea,0x2f30fc3f,0xf501ec4c,0x20991320,0x2fca99ce,0x35f103e6,
    0x00fa1333,0x441f405d,0x5f07980f,0x26fe2fa8,0x35f70999,0x3e013333,
    0x5f317602,0x7e98bf70,0x2f83ee40,0x75ae1ff3,0x3e617403,0x3f707d0f,
    0x361f8000,0x0fc13205,0x44cbcc3f,0x205bb03d,0xfe82644c,0x2ec2dfff,
    0x7fffffc4,0x01d807d3,0x203e20fa,0xf905f079,0x3fffffe1,0xffffffb3,
    0x5c0be05f,0x4c0fc80f,0x4405e82f,0x2f45f04f,0x5d00fad7,0x40fa1f90,
    0x0000006e,0x00000000,0x00000000,0x00000000,0x00000000,0x00000000,
    0x00000000,0x00000000,0x15400000,0x5d405710,0x4015731b,0x02ae602a,
    0x93015dd4,0x51054735,0x26666666,0x42980312,0x31ba941a,0x0b2a5037,
    0x10665715,0x142982a5,0xaaa88288,0x30c401aa,0x01b1c830,0x58809880,
    0x33028895,0x54413333,0x99999981,0x03c80540,0xd85fb9f7,0xdcfefcbe,
    0x7e67540f,0x0fe67d42,0x113f2fb2,0x223fd7dd,0x300dea0f,0x7c40bbe2,
    0xcdf83f33,0x44ececfd,0x3e4fcddf,0x4c8d74ee,0x7987ec99,0x99930b50,
    0x3f2607fb,0xf9dd9f33,0x725c74c1,0xf7b334c9,0x40e8ad81,0x7ffc41fb,
    0xb7d13fff,0x7ffffc45,0x03d9d13f,0x543f1079,0x1fc83a26,0x2d45d172,
    0xd125c5f1,0xd97635c1,0xbd41f13f,0x7fd70601,0x83f9fa81,0x46a9fa3f,
    0x43f9ae4f,0x3547e1f8,0x541325df,0xea85d805,0x54f640cf,0x25d4c83e,
    0xa83f9cf8,0x41edae0e,0x530005bf,0x2a7900b9,0x3fbaa933,0x88f51eee,
    0xafdb980f,0x2be27baa,0x1f30fbaa,0x8fb73100,0x22b7973f,0x300dea0f,
    0xf90ff260,0x25c87e0b,0x4f317c79,0x4d53d81f,0xd4ce98f8,0x676e6445,
    0x7c46d82c,0x5a87a02e,0x7c4b97a8,0x741b703f,0xfad41f8b,0x04444440,
    0x900b77d5,0xa8accae7,0xd50aadda,0x5efe45f0,0x0cccccfc,0x399999f5,
    0x37f201ea,0xaccfc7cb,0xbd41f16b,0x7ed40601,0x1f827dc2,0x0fc79932,
    0xb5407cf3,0x565d6c3d,0x6e64478e,0x07642cce,0x7402ffa2,0x22ba16e2,
    0x513fe60f,0xb8f98b63,0x223c9745,0x73ffffff,0x7900bb19,0x320f2766,
    0x3e60f883,0x23e41f50,0x4503e228,0xfa8e60f8,0x1d7d1ee0,0x5ee1f936,
    0xefb88601,0x81fbf882,0x4799321f,0x00f9e61f,0xddb81f5f,0x2a05bf89,
    0x4c03f505,0x5f641dfd,0x3cad44fb,0x893e2fe6,0x5d4b84ed,0x444799e6,
    0x33220888,0x3da80049,0x23360790,0x4c3ea6d8,0xd89b13ff,0x8cd8d90c,
    0x443e63d8,0xfa97e47e,0x1bf453e1,0x00efc460,0x3f03ae9d,0x1f8f3264,
    0xd900f9e6,0x7f4ff10b,0x3e616a02,0x27f71001,0x0fbddbf9,0x88ee142a,
    0x1289c005,0x00000181,0x35331000,0x7fe44133,0x4f77e40d,0xc884ffe9,
    0x7e441dff,0xaeefc84f,0x37ff720f,0xbd77fd42,0x20044601,0x3f17a0eb,
    0x1f8f3264,0xf300f9e6,0x0fb97a05,0x3ff60a20,0x20806fff,0x00000080,
    0x00000000,0x7fdc0000,0x0002ffff,0x00000101,0x00450040,0x26666602,
    0x00000299,0x00000000,0x00000000,0x00000000,0x00000000,0x00000000,
    0x00000000,0x00000000,0x440f2000,0x0980980a,0x426310c4,0x1004042a,
    0x222882a3,0x3bbba20a,0x5510eeee,0x44444415,0x00000088,0x00000000,
    0x00000000,0x00000000,0x00000000,0xe982a800,0x4b2f21eb,0x9ea08c88,
    0x99765f79,0x2b3ff625,0xe87eb74a,0x222226c3,0x3ee08888,0xdddd11ff,
    0x0001dddd,0x00000000,0x00000000,0x00000000,0x00000000,0x99930000,
    0x6c223999,0xee9a4562,0xf799ea5e,0x2a991225,0x12ffdb9b,0x09048821,
    0x00000000,0x00000000,0x00000000,0x00000000,0x00000000,0x2e600000,
    0x640bbbbb,0xb3165e44,0x75a2688b,0x077a2371,0x00000000,0x00000000,
    0x00000000,0x00000000,0x00000000,0x00000000,0x20ae0000,0xc81303d8,
    0x0ca0c1b8,0x00000000,0x00000000,0x00000000,0x00000000,0x00000000,
    0x00000000,0xc8000000,0x03eeeb83,0x00000000,0x00000000,0x00000000,
    0x00000000,0x00000000,0x00000000,0x00000000,0x00000000,0x00000000,
    0x00000000,0x00000000,0x00000000,0x00000000,
};

static signed short stb__arial_16_latin1_x[224]={ 0,1,0,0,0,0,0,0,0,0,0,0,1,0,
1,0,0,1,0,0,0,0,0,0,0,0,1,1,0,0,0,0,0,-1,1,0,1,1,1,0,1,1,0,1,
1,1,1,0,1,0,1,0,0,1,0,0,0,0,0,0,0,0,0,-1,0,0,0,0,0,0,0,0,0,0,
-1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,0,1,1,1,1,1,1,1,1,1,
1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,0,1,0,0,0,-1,
1,0,0,0,0,0,0,0,0,-1,0,0,0,0,1,1,0,1,0,0,0,0,0,0,0,1,-1,-1,-1,-1,
-1,-1,0,0,1,1,1,1,0,0,-1,0,-1,1,0,0,0,0,0,1,0,1,1,1,1,0,1,1,0,0,
0,0,0,0,0,0,0,0,0,0,0,1,-1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
 };
static signed short stb__arial_16_latin1_y[224]={ 12,1,1,1,0,1,1,1,1,1,1,3,10,7,
10,1,1,1,1,1,1,1,1,1,1,1,4,4,3,4,3,1,1,1,1,1,1,1,1,1,1,1,1,1,
1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,13,1,4,1,4,1,4,1,4,1,1,
1,1,1,4,4,4,4,4,4,4,1,4,4,4,4,4,4,1,1,1,5,3,3,3,3,3,3,3,3,3,
3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,12,4,1,1,3,1,
1,1,1,1,1,5,4,7,1,0,1,3,1,1,1,4,1,6,11,1,1,5,1,1,1,4,-1,-1,-1,-1,
-1,-1,1,1,-1,-1,-1,-1,-1,-1,-1,-1,1,-1,-1,-1,-1,-1,-1,3,1,-1,-1,-1,-1,-1,1,1,1,1,
1,1,1,1,4,4,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,4,4,1,1,1,1,1,1,1,
 };
static unsigned short stb__arial_16_latin1_w[224]={ 0,2,5,8,8,12,10,3,5,5,6,8,2,5,
2,4,8,5,8,8,8,8,8,8,8,8,2,2,8,8,8,8,15,11,8,10,9,8,8,11,9,2,7,9,
7,10,9,11,8,11,10,9,9,9,10,14,10,10,9,4,4,4,7,10,4,8,8,8,7,8,5,8,7,3,
4,8,3,12,7,8,8,7,5,7,4,7,7,11,8,8,7,5,2,5,8,8,8,8,8,8,8,8,8,8,
8,8,8,8,8,8,8,8,8,8,8,8,8,8,8,8,8,8,8,8,8,8,8,8,0,3,8,8,8,9,
2,8,5,11,6,7,8,5,11,10,5,8,5,5,4,7,8,2,4,4,5,7,12,12,12,7,11,11,11,11,
11,11,14,10,8,8,8,8,4,4,6,4,11,9,11,11,11,11,11,7,11,9,9,9,9,10,8,8,8,8,
8,8,8,8,13,8,8,8,8,8,3,3,6,4,8,7,8,8,8,8,8,8,8,7,7,7,7,8,8,8,
 };
static unsigned short stb__arial_16_latin1_h[224]={ 0,11,5,12,14,12,12,5,15,15,5,8,5,2,
2,12,12,11,11,12,11,12,12,11,12,12,8,11,8,6,8,11,15,11,11,12,11,11,11,12,11,11,12,11,
11,11,11,12,11,12,11,12,11,12,11,11,11,11,11,14,12,14,7,2,3,9,12,9,12,9,11,12,11,11,
15,11,11,8,8,9,11,11,8,9,12,9,8,8,8,12,8,15,15,15,4,9,9,9,9,9,9,9,9,9,
9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,0,11,14,12,8,11,
15,15,3,12,6,7,6,2,12,2,5,9,6,7,3,11,14,2,4,6,6,7,12,12,12,11,13,13,13,13,
13,13,11,14,13,13,13,13,13,13,13,13,11,13,14,14,14,14,14,7,12,14,14,14,14,13,11,12,12,12,
12,12,12,12,9,11,12,12,12,12,11,11,11,11,12,11,12,12,12,12,12,6,9,12,12,12,12,15,14,15,
 };
static unsigned short stb__arial_16_latin1_s[224]={ 253,127,118,168,117,139,152,114,64,73,107,
151,124,168,253,249,10,185,191,233,118,6,15,152,19,46,253,182,168,224,86,
138,48,161,173,55,230,240,89,62,106,253,92,126,136,202,222,147,213,212,232,
100,116,36,191,176,165,154,144,103,207,88,216,174,152,51,53,42,45,33,36,
189,24,20,28,1,249,104,117,10,212,204,125,243,1,69,131,139,95,83,160,
10,25,33,132,77,77,77,77,77,77,77,77,77,77,77,77,77,77,77,77,
77,77,77,77,77,77,77,77,77,77,77,77,77,77,77,77,77,253,200,108,
28,177,10,70,39,141,24,233,208,240,168,242,157,101,1,95,202,147,98,227,
251,127,251,249,186,118,105,92,130,37,236,72,111,99,123,74,126,1,10,19,
28,248,60,65,84,62,89,137,149,161,173,185,194,135,197,207,217,93,49,221,
159,195,213,222,231,198,186,19,42,177,1,240,204,51,32,55,147,163,110,180,
83,74,224,74,86,60,66,131,172,37,16,79,1, };
static unsigned short stb__arial_16_latin1_t[224]={ 13,44,78,17,1,31,31,78,1,1,78,
69,78,78,53,17,31,44,44,31,44,44,44,44,31,44,44,44,69,69,69,
44,1,44,44,44,44,44,57,31,57,1,44,57,57,57,57,17,57,31,57,
44,57,44,57,57,57,57,57,1,31,1,69,78,78,69,31,69,31,69,57,
31,57,57,1,57,44,69,69,69,44,44,69,57,44,69,69,69,69,44,69,
1,1,1,78,69,69,69,69,69,69,69,69,69,69,69,69,69,69,69,69,
69,69,69,69,69,69,69,69,69,69,69,69,69,69,69,69,69,13,44,1,
31,69,57,1,1,78,44,69,69,69,78,31,78,78,69,78,69,78,57,1,
64,78,57,69,69,31,31,31,44,17,1,17,17,17,17,57,1,17,17,17,
17,1,17,17,17,57,17,1,1,1,1,1,69,17,1,1,1,1,17,44,
17,17,17,17,17,31,17,69,57,17,31,17,17,57,57,57,44,31,44,31,
31,31,31,44,78,69,44,31,31,31,1,1,1, };
static unsigned short stb__arial_16_latin1_a[224]={ 64,64,81,127,127,204,153,44,
76,76,89,134,64,76,64,64,127,127,127,127,127,127,127,127,
127,127,64,64,134,134,134,127,233,153,153,165,165,153,140,178,
165,64,115,153,127,191,165,178,153,178,165,153,140,165,153,216,
153,153,140,64,64,64,108,127,76,127,127,115,127,127,64,127,
127,51,51,115,51,191,127,127,127,127,76,115,64,127,115,165,
115,115,115,77,60,77,134,172,172,172,172,172,172,172,172,172,
172,172,172,172,172,172,172,172,172,172,172,172,172,172,172,172,
172,172,172,172,172,172,172,172,64,76,127,127,127,127,60,127,
76,169,85,127,134,76,169,127,92,126,76,76,76,132,123,64,
76,76,84,127,191,191,191,140,153,153,153,153,153,153,229,165,
153,153,153,153,64,64,64,64,165,165,178,178,178,178,178,134,
178,165,165,165,165,153,153,140,127,127,127,127,127,127,204,115,
127,127,127,127,64,64,64,64,127,127,127,127,127,127,127,126,
140,127,127,127,127,115,127,115, };

// Call this function with
//    font: NULL or array length
//    data: NULL or specified size
//    height: STB_FONT_arial_16_latin1_BITMAP_HEIGHT or STB_FONT_arial_16_latin1_BITMAP_HEIGHT_POW2
//    return value: spacing between lines
static void stb_font_arial_16_latin1(stb_fontchar font[STB_FONT_arial_16_latin1_NUM_CHARS],
                unsigned char data[STB_FONT_arial_16_latin1_BITMAP_HEIGHT][STB_FONT_arial_16_latin1_BITMAP_WIDTH],
                int height)
{
    int i,j;
    if (data != 0) {
        unsigned int *bits = stb__arial_16_latin1_pixels;
        unsigned int bitpack = *bits++, numbits = 32;
        for (i=0; i < STB_FONT_arial_16_latin1_BITMAP_WIDTH*height; ++i)
            data[0][i] = 0;  // zero entire bitmap
        for (j=1; j < STB_FONT_arial_16_latin1_BITMAP_HEIGHT-1; ++j) {
            for (i=1; i < STB_FONT_arial_16_latin1_BITMAP_WIDTH-1; ++i) {
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
        float recip_width = 1.0f / STB_FONT_arial_16_latin1_BITMAP_WIDTH;
        float recip_height = 1.0f / height;
        for (i=0; i < STB_FONT_arial_16_latin1_NUM_CHARS; ++i) {
            // pad characters so they bilerp from empty space around each character
            font[i].s0 = (stb__arial_16_latin1_s[i]) * recip_width;
            font[i].t0 = (stb__arial_16_latin1_t[i]) * recip_height;
            font[i].s1 = (stb__arial_16_latin1_s[i] + stb__arial_16_latin1_w[i]) * recip_width;
            font[i].t1 = (stb__arial_16_latin1_t[i] + stb__arial_16_latin1_h[i]) * recip_height;
            font[i].x0 = stb__arial_16_latin1_x[i];
            font[i].y0 = stb__arial_16_latin1_y[i];
            font[i].x1 = stb__arial_16_latin1_x[i] + stb__arial_16_latin1_w[i];
            font[i].y1 = stb__arial_16_latin1_y[i] + stb__arial_16_latin1_h[i];
            font[i].advance_int = (stb__arial_16_latin1_a[i]+8)>>4;
            font[i].s0f = (stb__arial_16_latin1_s[i] - 0.5f) * recip_width;
            font[i].t0f = (stb__arial_16_latin1_t[i] - 0.5f) * recip_height;
            font[i].s1f = (stb__arial_16_latin1_s[i] + stb__arial_16_latin1_w[i] + 0.5f) * recip_width;
            font[i].t1f = (stb__arial_16_latin1_t[i] + stb__arial_16_latin1_h[i] + 0.5f) * recip_height;
            font[i].x0f = stb__arial_16_latin1_x[i] - 0.5f;
            font[i].y0f = stb__arial_16_latin1_y[i] - 0.5f;
            font[i].x1f = stb__arial_16_latin1_x[i] + stb__arial_16_latin1_w[i] + 0.5f;
            font[i].y1f = stb__arial_16_latin1_y[i] + stb__arial_16_latin1_h[i] + 0.5f;
            font[i].advance = stb__arial_16_latin1_a[i]/16.0f;
        }
    }
}

#ifndef STB_SOMEFONT_CREATE
#define STB_SOMEFONT_CREATE              stb_font_arial_16_latin1
#define STB_SOMEFONT_BITMAP_WIDTH        STB_FONT_arial_16_latin1_BITMAP_WIDTH
#define STB_SOMEFONT_BITMAP_HEIGHT       STB_FONT_arial_16_latin1_BITMAP_HEIGHT
#define STB_SOMEFONT_BITMAP_HEIGHT_POW2  STB_FONT_arial_16_latin1_BITMAP_HEIGHT_POW2
#define STB_SOMEFONT_FIRST_CHAR          STB_FONT_arial_16_latin1_FIRST_CHAR
#define STB_SOMEFONT_NUM_CHARS           STB_FONT_arial_16_latin1_NUM_CHARS
#define STB_SOMEFONT_LINE_SPACING        STB_FONT_arial_16_latin1_LINE_SPACING
#endif
