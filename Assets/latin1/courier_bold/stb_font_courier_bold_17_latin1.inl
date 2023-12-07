// Font generated by stb_font_inl_generator.c (4/1 bpp)
//
// Following instructions show how to use the only included font, whatever it is, in
// a generic way so you can replace it with any other font by changing the include.
// To use multiple fonts, replace STB_SOMEFONT_* below with STB_FONT_courier_bold_17_latin1_*,
// and separately install each font. Note that the CREATE function call has a
// totally different name; it's just 'stb_font_courier_bold_17_latin1'.
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

#define STB_FONT_courier_bold_17_latin1_BITMAP_WIDTH         256
#define STB_FONT_courier_bold_17_latin1_BITMAP_HEIGHT         86
#define STB_FONT_courier_bold_17_latin1_BITMAP_HEIGHT_POW2   128

#define STB_FONT_courier_bold_17_latin1_FIRST_CHAR            32
#define STB_FONT_courier_bold_17_latin1_NUM_CHARS            224

#define STB_FONT_courier_bold_17_latin1_LINE_SPACING           8

static unsigned int stb__courier_bold_17_latin1_pixels[]={
    0x404c3000,0x12e002ca,0x0000c000,0x200c0018,0x29800001,0x50000000,
    0x50151141,0x88066155,0x000142aa,0x3001802e,0x28022303,0x00c00080,
    0x74be0698,0x2004fe83,0x007f707d,0x03fb80b9,0x06c801f4,0x1fdc02ec,
    0x200af220,0x7dc00de9,0x3e65fd03,0xffd0df51,0xff981f23,0xfb307e66,
    0x403ee03b,0x989f004d,0x3f306b9f,0xd8017440,0x201ea804,0x004e8020,
    0x05d8dd80,0xb1bb0132,0x6403d80b,0x6c0b9005,0x36205d8d,0x5cf5401c,
    0xbb1bb00f,0x87e62f98,0x31f980fa,0x307e607f,0x75f7e43f,0xd82fc44f,
    0x983f5003,0xfea86c9f,0x03d101ef,0x013003d8,0x664c7326,0x1ef5ef41,
    0x10f33326,0x20400008,0x00000000,0x11002040,0x20401000,0x3f30fcc0,
    0x0fcc0fcc,0x307e60db,0xf913e63f,0x0000fdc3,0x6c7d42f4,0x7edefc45,
    0x4c000003,0x239931cc,0x7ff52ffa,0x5fedffe8,0x65bfbbaa,0x4eed8dee,
    0x980e7ecc,0x77641cfd,0xd94eed8d,0x89ddb1bd,0x75c1cfd9,0xc85eeeee,
    0x76402eee,0xddd702ee,0x30fcc7dd,0x4c0fcc3f,0x260be61f,0xfb8fcc1f,
    0x8fb1fc40,0x7dd72eeb,0xfea83f50,0x83ea4ffe,0x1777640b,0x3eeeeeb8,
    0xffa97fd4,0x27c43f23,0x03f707f4,0xb9f7d5b2,0x2fbf22fe,0x5f7e44fe,
    0x4fbea4fe,0x7df52feb,0xefc8bfae,0x3fa64feb,0xca87eccc,0x7e5406ff,
    0xbfb9306f,0x983f2239,0x2613e61f,0x7cc3741f,0x06c86441,0x3a62f49d,
    0xd03df51f,0xffdfd50d,0x502dff89,0x3260dff9,0xfc81cdfd,0x4f889f10,
    0xf0bd01f9,0x44e9b207,0xf913e67c,0x3f913e63,0x9d1f2274,0x913e67c8,
    0xb88bdc3f,0x03f9f306,0x201fcf98,0x23fd41f9,0x217fc1f9,0x20fd41f9,
    0x07dc01f9,0x885f8be2,0xf301fb5f,0x427df205,0x980ffec8,0x3e601fcf,
    0x7e53e201,0x04f9fc80,0x807d43fd,0x4f913a6c,0xb9fc41fb,0x9d1fc41f,
    0x322747c8,0x7f107ee7,0x0c6ecfdc,0xd809d6d8,0x0fcc09d6,0x43f30fd4,
    0x81f982f9,0x220fcc5e,0x7b87f10d,0xfcfb8374,0x3ae0db03,0x8661efcf,
    0x9d6d84e8,0x3200fcc0,0xff104f9f,0x37ffa01f,0xe9b205fe,0x20d93e44,
    0x93a0d94e,0x13a3e44e,0x4e8364f9,0x8817ffee,0x2201f73f,0x2601f73f,
    0x261f981f,0x2607e61f,0x261fa81f,0xf90fcc1f,0x7d89fb5b,0x7cc17f60,
    0xdfdffb03,0x4f8876c7,0x00fb9fc4,0xff8803f3,0x813f200f,0x401cebde,
    0x4f913a6c,0xba7c40fb,0x9d27c40f,0x322747c8,0x9f103ee7,0x81aecfdc,
    0x03fffffb,0x07fffff7,0x87e607e6,0x207e61f9,0x4cbd01f9,0x2e0fcc1f,
    0x2fa82eff,0x1f203f30,0xd85f1bb0,0x5c0fffff,0x303fffff,0x09f9003f,
    0x13a00fc8,0x236cdb00,0xf70fe64d,0x3f70fe63,0xdb13636c,0x70fe64d8,
    0x888bdc3f,0x6667741f,0x999dd06e,0x207e60dd,0xb87e63f9,0x80fd440f,
    0x415f30fb,0x67fe41f9,0x983742ca,0x403f881f,0x4cc1f9ce,0x99dd03fc,
    0x07e60dd9,0x2a203f20,0xbf300efa,0x32aa2015,0x32b7ee4f,0x6d6fe41f,
    0x6d6fe45f,0x656fdc5f,0x656fdc1f,0x6d6fe41f,0x333f665f,0x37ee1fdc,
    0xfb87fb11,0x4c7fb11d,0x6c1cdfdc,0x3ea3f32f,0x101fff85,0x99ffe69f,
    0x3fbfe21f,0x20fd42ff,0x7e43dfdb,0x0fce7400,0xdfb81f98,0x64c7fb11,
    0x5441cdfd,0xffc80efa,0xffff03ff,0x13fff205,0x540bbfee,0xfd502dfe,
    0x3bfee05b,0x05dff702,0xf90b7faa,0x23ffffff,0xff73fff9,0x4fffe63f,
    0xff91fffb,0x18309fff,0x0554c062,0x06aa2550,0x06008103,0x41fffff1,
    0x0509802a,0x3fe606c4,0x23fff73f,0x44fffffc,0x103ffffc,0x09980133,
    0x00400c40,0x20010008,0x02001000,0x00000000,0x00000000,0x00000000,
    0x00000000,0x80000000,0x00000998,0x00000000,0x00000000,0x00000000,
    0x00000000,0x00000000,0x00000000,0x00000000,0x00000000,0x00000000,
    0x00000000,0x00000000,0x00000000,0x00000000,0x00000000,0x00000000,
    0xb8801000,0x1d4ae011,0x5c01805c,0x40000752,0x00000c01,0x10298000,
    0x00000000,0x23710000,0x54ae0000,0x45260003,0xb81e4c04,0x66540752,
    0x5c00102c,0x37afa00e,0x10ea5705,0xb817209f,0x3faa0752,0x09b00ddf,
    0x04b805c8,0x7ecc02d8,0x2cd85fbd,0xb5003660,0x2016a001,0x6f5f404b,
    0x2b82d405,0x302d4075,0x7640362b,0x752b84eb,0x13733ae0,0x36a003e2,
    0x00006000,0x016e01f9,0xfcbdfb80,0x7003d81f,0x880d900b,0xb7df703e,
    0x093901ff,0x75c00ea8,0x20075c00,0x006000dc,0xb80001d7,0xe880000e,
    0x74000f10,0x07e612a2,0xcfd98000,0x6c6f7641,0x013e24ee,0x1073f660,
    0x001f989f,0x00260000,0xfd93e60a,0x800b981f,0x40098009,0xed805002,
    0x0a13bb65,0x3eeeeeb8,0xeeec8028,0x87d49502,0x5eeeeeeb,0xb100f7e4,
    0xdd901bff,0x5f7e405d,0x4fbea4fe,0x73742feb,0x647ddddd,0x2a4febef,
    0x3bae180f,0x3ae5eeee,0x985eeeee,0xdc881cec,0xb8fdc1bd,0x37224fbf,
    0x9d7101bd,0x9914ca83,0xcc8a6545,0x81ceb882,0x5fd73ffb,0x4c1cec98,
    0x221cdfdc,0x9501bddc,0x22f20dff,0x9fd30fde,0x4fc4fd99,0xcff884fb,
    0xffca83fd,0xfc89f306,0x90f913a1,0x66fee4cf,0x1fc89f31,0x9fd300f7,
    0x7f4cfd99,0x7d47eccc,0x7dc2ffdf,0x9b646ede,0x77dcbd4f,0xdefb86ed,
    0x45fae2ff,0x45fae5fd,0x6f7dc5fd,0x0ffe82ff,0xfdffa8f7,0xb81f982f,
    0x2606edef,0xbac81fcf,0x88bdc1f4,0x6c46f46b,0x1d83ee1e,0x703f9f30,
    0x3a3f883f,0x07e43e44,0x83f707e6,0x001f73f8,0x71ae22f7,0xbf1ae22f,
    0x5441f621,0x3e3ea2fa,0x55107f16,0x3ec4f85f,0x7b8bd1ee,0xfb13e2f4,
    0x1eebfbd0,0x21f621bf,0x2aa201f9,0x13adb02f,0x83e36ab2,0x818dd9fb,
    0x364f53fd,0x213adb00,0x2749d06c,0x261f61f2,0x4e83641f,0xfb8307f1,
    0x7dc18dd9,0x3e618dd9,0xfd50fcc1,0x7fc45fff,0x7543f70f,0x3ea2ffff,
    0x21ffffff,0x1ee2f47b,0x7fffd4bd,0x56741fff,0x07e67baf,0x81f983f3,
    0x82ffffea,0xc81f73f8,0x7dc5ff94,0x6f4c05ff,0x267f50fb,0xf73f881c,
    0x7c40fb81,0xd0f913a4,0xfb83f30b,0xbf927c40,0x7dc5f957,0xfff705ff,
    0xfb87f10b,0x3ea6b7a1,0x7ed6ff42,0x7d4d6f44,0x2aab3e22,0xbd1ee0aa,
    0xf12f47b8,0x81555559,0x44f9fb4e,0x260fdc3f,0xa9ade81f,0xffffb82f,
    0x2e03543f,0x08835d9f,0xfff90bf6,0xffff703f,0x5c3f987f,0x89b1b61f,
    0x41f983f9,0x20fdc3f9,0x5c3fffec,0xfb835d9f,0xcfd835d9,0x33e26fca,
    0xf50cfeb9,0xf885dffb,0x20cfeb9c,0x0dcaabed,0x3bf6afea,0x3f6afea0,
    0x2aafb60e,0xf8a740dc,0x6567ec7f,0x441f986f,0x0cfeb9cf,0x37666774,
    0x2e144ba2,0x643f1117,0x1fd41aa3,0xdd999dd0,0xbfb5bf90,0x1fcadfb8,
    0x0fcc07ec,0x2fed6fe4,0x45ee03d0,0x45ee1f88,0x7fe41f88,0xefffb85f,
    0x004bb2ff,0x5ffdfff7,0x6ffff5c4,0x3fbffa20,0x3bffa22f,0x3fae22ff,
    0x3be60dff,0xff90ff72,0xdfdc98bf,0x3bffee1c,0x477ee2ff,0x77cc3fd8,
    0x333f664f,0x3bb21fdc,0x03f302fe,0x7ec477ee,0x02dfea83,0xf885dff7,
    0x66fee4c3,0x016ff541,0x9fb30db5,0x3663fb99,0x01fdcccf,0x00013003,
    0x098004c0,0x0c400c40,0xff900980,0x20303f4d,0x84fffffc,0x7fff3009,
    0x0607ffee,0x3ffffff2,0x0266621f,0x3ffe6050,0x203fff73,0x40c01000,
    0x04fffffc,0x905b5001,0x3fffffff,0x3ffffff2,0x0000001f,0x00000000,
    0x00000000,0x00000000,0x00000000,0x00000000,0x00000000,0x00000000,
    0x00000000,0x00000000,0x00000000,0x00000000,0x00000000,0x2aa60000,
    0x0025502a,0x440280aa,0x264cbcec,0x01884c0c,0x0c426002,0x36200a88,
    0xd9800401,0x65c03800,0x81597103,0x302aaaa8,0x03660597,0x1664532a,
    0x83555555,0x159702ca,0x00002540,0xcbbec980,0xfff98512,0xedcb84fd,
    0x3bffe00f,0x203b3a20,0xdfffdffb,0x94d89fb0,0x16fbb60b,0xf505ca6c,
    0x0fafea05,0xb82df76c,0x3e603fbe,0x8bfdfb01,0x4c7feff9,0x5c1fffff,
    0xbeb87eff,0xd8bf5c3f,0x3ffffa5f,0x1bfbfa4f,0x360dfdf9,0x7e441ecd,
    0xffda83ef,0x7f77e43d,0x743f34ff,0x1300d5f5,0x1fc47dc0,0x93e0ea77,
    0x027e47f8,0x00393180,0x510a8000,0xa80e4c60,0x0fcc0510,0x21fa97c4,
    0x4c5f10c9,0x013ee01f,0x1ee0a215,0x7f1164bd,0x897cc7ea,0x4507f33f,
    0x6defdc19,0x36b7e61f,0x9f51fc5f,0x6af9fc40,0x405ddd90,0x6cc9f37c,
    0x207d42d9,0x261fe47c,0xdc881cec,0xddc881bd,0x6440e01b,0xd9301bdd,
    0x33b26039,0x2e07e601,0x7f101fc7,0x740557cc,0x1ceb8804,0x702f47b8,
    0x7c43ee1f,0x536c1f54,0x98b32299,0xd8d92746,0x89f03ea5,0x357cf743,
    0x206ffca8,0x542ffcfc,0x93e5dabd,0x517dc7f8,0xb85ffbff,0xfb86edef,
    0x3f506ede,0x0ddbdf70,0x85ffbff5,0x22ffdffa,0xfffffff9,0xa85d8bb1,
    0x3fe60ffe,0xd9f10dff,0xfbdf705d,0x2f47b85f,0x677c4db0,0x225f10fe,
    0x6c5fae7f,0xb8fe605f,0x7c4111bf,0x1fa93e62,0x81abff62,0xf901fcf9,
    0x2e23fd71,0x7fdc1ced,0x0fd47ffd,0x41f621bf,0x5102faa8,0x0ffc85f5,
    0xf0beaa20,0xbf1f621b,0x7551f621,0x22ec557f,0x1ffd985d,0xa97d4564,
    0x7c3fddff,0x2bee3ec4,0xf880efda,0x237fff43,0x20fffdfd,0x7442f47b,
    0x7ffe40df,0x75dfec0d,0x7c0bee4f,0x275b606a,0x657e27c8,0xc984fc9b,
    0x87cc7cce,0x50fcc1f9,0xa85ffffd,0x2e2ffffe,0x3ffaa03f,0x307e62ff,
    0xf307e63f,0xd903f303,0x17a204e8,0xc97e6db0,0x3ffffea6,0x3ffee1ff,
    0x0fb82fff,0x0fea2bee,0x7b8ddbd7,0x01fc42f4,0xf9117f2a,0x1fdc9fdf,
    0x7f106af8,0x8df203ee,0x01c9dc6c,0x7f1043dc,0x2b7a1fb8,0x56f42fa9,
    0x91b22fa9,0x7d4d6f43,0x3f70fe22,0x03f70fe2,0x21f503f3,0x036402f8,
    0xf71fc576,0x555567c4,0x0067ee0a,0x5e8db1b6,0x47b89f30,0x0ba0305e,
    0x24f840f7,0x0d5f03fc,0x0fffffee,0x9d5f9fb3,0x540572b8,0x3f60c1fd,
    0x3e26fcac,0x10cfeb9c,0x19fd739f,0x4ff2b3e6,0xcfeb9cf8,0x3f2b3f60,
    0x7e567ec6,0xf101d106,0xabc8fd5d,0x2b3a4fca,0x2ff22fca,0x55f6c4eb,
    0x01ee0dca,0x33ee1fc4,0xb5713fba,0xb57f50df,0xf01301df,0x30bf757f,
    0x7ec5fb55,0x3a0d5f04,0x646eccce,0x41efebff,0x3e605ee8,0x83f50fff,
    0xfb85fffc,0x2e2ffeff,0x22ffefff,0x2e0cffeb,0x42ffefff,0xf905fffc,
    0xcca88bff,0x3e60accc,0x7ff5c2ff,0x77ff544f,0x06ffec43,0x37fffae2,
    0x7cc01aa0,0x24fffc80,0x880beff9,0x42ffeffe,0xffde83fa,0xfffe80cf,
    0x3ae17d43,0x6fdc5fdf,0x0807fb11,0x4cc40040,0x30030040,0x10013001,
    0x03000980,0x7ffcc060,0x0181ffff,0x20040044,0x00098008,0x04030000,
    0x00801880,0x004c00c4,0x86a2aa20,0xff73fff9,0x0000003f,0x00000000,
    0x00000000,0x00000000,0x00000000,0x00000000,0x00000000,0x00000000,
    0x00000000,0x00000000,0x00000000,0x00000000,0x00000000,0x00000000,
    0x00000000,0x00000000,0x264c0000,0x0e75de5c,0x06213000,0x54400000,
    0x98130c01,0x439931cc,0x32a002ca,0x028602ce,0x20167654,0x400ae600,
    0x440002c8,0x0980003b,0x223bdda8,0x839801cb,0x40ddffea,0x40ddffea,
    0xc801cfd9,0xefffd87f,0x4034c4fe,0x16a0b94d,0xb1007440,0x25f05fdf,
    0xa97fd43e,0x013fa3ff,0x1ecc575c,0x700f9bd4,0x107b315d,0xda8979dd,
    0x4ecf9804,0x5077f660,0xec9800d9,0x3fe63fbc,0x3550ffed,0x5c3fd00f,
    0x21ffcbdf,0x1febbdfb,0x13fafbf2,0x0ff41f20,0x007d41f7,0x401d7000,
    0x6fcc02e9,0xc804106e,0x9d09f10f,0x5bd9b500,0x500820b2,0x0b2736ab,
    0x25c05dc6,0x6c050cc0,0x06985ebe,0x3ff7fee0,0x1f707646,0x0c403754,
    0x21f989f1,0xf987c44f,0x3220fe44,0x0bd07cce,0x333f6a7f,0x1ceb882c,
    0x013004c0,0xa93e6620,0x8859914c,0xbd01f94f,0x35b039d7,0x88b11b19,
    0x55b00ccc,0x44b15719,0xb81cebcc,0x99117544,0x011fc019,0xf88f90d3,
    0x7c1fff34,0x50f98183,0x80fa803f,0xf7003e61,0x3ee3f883,0xfd07ffdf,
    0xfec87dc3,0x77dc4eee,0x66442ffd,0x1999100c,0x3ffff620,0x7ec5fae6,
    0x04f9fc85,0x89fddffd,0x1a1d9d36,0x5a03fdd3,0x3fa6680d,0x3ae1fedf,
    0x4c3fd8ae,0x9f301fee,0x233f6603,0x47d41eea,0x3e2f8df9,0x4f5ddc04,
    0x2e0982fd,0x2627b807,0x3a0d9099,0x07f993e4,0x89fdbffd,0xb13e00fa,
    0x01fee98f,0x3603fdd3,0x5c7fb8af,0x7fc42f47,0x5c3fd00f,0x2b663a0f,
    0x80fcc1a6,0x23421c8e,0xa993a1fb,0x83fadfca,0xfffb81f9,0xdbaa884f,
    0xf30dedcf,0x43f51df7,0x2fbaacfd,0xf59f9551,0x1f71fcc5,0xff90fb80,
    0xf103eedf,0x0fb03ea9,0x20b3af7a,0xfff500fa,0xf303ffff,0x881f9803,
    0x1ee3ec3f,0x813f20bd,0x991fc45e,0x095b73f9,0x466407e6,0x5c4aadcd,
    0x97ec2f47,0x01f983ee,0x4c013f93,0x459298df,0x86fcaffe,0x444effec,
    0x5c5dd2ee,0x30c1fc46,0x4bea627f,0x98fdc3f9,0x4e83f41f,0xf100fa80,
    0x01555559,0x1f9803f3,0x236c3f88,0xfc82f47b,0x5f11ba00,0x1b505ec4,
    0x6c407e60,0xb81b508b,0x43222f47,0x1f983cdb,0x55011f20,0x3be61d70,
    0x17405fff,0x8b732388,0xabdfc81e,0x2b7fa2fc,0x37f21fda,0x5f745fda,
    0x7cc2ffda,0x33e600ad,0x2fb64dba,0xf980dcaa,0xc80fcc01,0x543fc9bf,
    0x10efdabf,0x2a01df55,0x86ebadff,0x80cedfc8,0x82cdfdca,0x40cedfc8,
    0x1dd32fd8,0x952fffc0,0xfb859bfb,0x401fccce,0x1875c5d8,0x8806db80,
    0xc80a5fff,0x6443fffe,0x540cffff,0xfc982dfe,0x3e0ffeff,0x7e402fff,
    0x3ae22eff,0x32a0dfff,0x6542cdfd,0x6442cdfd,0xfe883eff,0xff92ffef,
    0x3bfa07ff,0x0401cfff,0x3fffffa0,0xff500406,0x500bfeed,0x7ffff4bf,
    0x3fffe26f,0xefc806ff,0x32a0003e,0x017ea001,0x03100110,0x20060010,
    0x00600099,0x7fff4026,0x7fff46ff,0x200206ff,0x02662018,0x00000180,
    0x00000000,0x00000000,0x00000000,0x00000000,0x00000000,0x00000000,
    0x00000000,0x00000000,0x00000000,0x00000000,0x00000000,0x26666600,
    0x00998099,0x32e20173,0x6c06a202,0x880deeee,0x032e22aa,0xed8deec8,
    0x9304b84e,0x19971009,0x7ddddd70,0x37ae276c,0x07dddd30,0xdd500151,
    0x203ddddd,0x2a7dd502,0x0a8803ee,0x2017bbb6,0x9dddd702,0xddddd703,
    0x75cbbae7,0x2e7dd73e,0x06008bee,0xffb8fffb,0xfeff981f,0x2e0bfd06,
    0xfa83dfcc,0x3ff53fff,0xeb9f7d40,0xf907d82f,0x3fff300f,0x39bfb930,
    0xff887fe4,0x073fb225,0xf500ffe6,0x05f9bfb9,0x5fd301d1,0xf7007bea,
    0x1e77dc3f,0x3aa07e60,0x642feccf,0xd34fdccf,0x4c7bea3f,0x13df52fe,
    0x55f30c01,0x81fbca83,0xb85f30ed,0x17c405ff,0xf9830de8,0x1f227401,
    0x3003e400,0x40fcc03f,0x5ff74ffa,0xfd880d90,0xf31f502e,0x10005f13,
    0xa803f2bf,0xffe81dfe,0x03f303ef,0x6c8bb1f2,0xb5f88dd1,0xd8ef881f,
    0x30c0110f,0x81f9805f,0xbf11fc1a,0x42f880bb,0x42ccefc9,0x43cc99f9,
    0x3223e44e,0xd7f900cc,0x00fcc05b,0xfbf503f3,0xd905fbd1,0x077fa600,
    0x0fc7e6f3,0x3fcfb800,0x403dfb30,0x82fca9de,0x4cf901f9,0x0fd9cc5e,
    0x303fcfb8,0x00443fff,0x0447fc43,0x7ec00fcc,0x11763f21,0x7f5c2f88,
    0x4fcc3eee,0x22744efd,0x0ff74c7c,0x1fedffc8,0x7cc03f30,0xfdfafa81,
    0x006c82fa,0xf9827fdc,0xfffff981,0x77f4c1ff,0x803ffc81,0xff9a7c4e,
    0x321fffff,0x700effef,0x02fec05f,0x401117f2,0x3f77ffa1,0x3600fcc0,
    0x2ed3e62f,0x817c43f1,0x3fbe603f,0x07c89d05,0x87f203f3,0x403f304f,
    0xd8fa81f9,0x8d905f6f,0x19fd502c,0x2a207e60,0x40aaaaaa,0xc882cfba,
    0x4ef402ff,0x75512fb9,0x7e41557f,0x9f504fdc,0x807e60a2,0x0222fef9,
    0xff55f318,0x2203f307,0x667ec2fe,0x4c3f11ef,0x4c07f01f,0x8db00fff,
    0x203f304d,0xf982747c,0x2a07e601,0x05f2e98f,0x74c4e8d9,0x0fcc01df,
    0x6fee4000,0x07bf6604,0x81f7fff4,0x5cf901f9,0xf72fc43f,0x3e203f30,
    0x80223fb6,0x7ff59f11,0xfd303f30,0xffdddb03,0x3aaf7e25,0xf980fe06,
    0xdfb80efc,0x3f301fca,0x209d1f20,0xfdc981f9,0x473f21cd,0x3ae24fc8,
    0xb14fcccf,0xfb7005df,0x4c03807b,0xea802dfd,0x33bea0df,0x4c0fcc02,
    0x47f90bfd,0x47eccdfd,0x74c3dfdb,0x113df52f,0xfffd70c0,0x37f7261f,
    0x99bff11c,0x0efb8839,0x203bff6e,0x20bcefc9,0xbff89fc8,0x4177fdc0,
    0x22cdfdca,0x3dd32fd8,0x166fee54,0x29fffff9,0xff53fff8,0x3fffea3f,
    0x07d34fff,0x3ffffe20,0x6c01d100,0x2e005fff,0x1bfffa1e,0xff901d10,
    0xfe87f45f,0x3e27ffff,0x3f20ffff,0x31bff94f,0x03333333,0xffff7013,
    0x3fffe29f,0x7ffcc4ff,0x3f600882,0x3ea2ffff,0x205ffd1f,0x3ffffa00,
    0x6dbfee6f,0x3fffa4ff,0x000006ff,0x00000000,0x00000000,0x00000000,
    0x00000000,0x00000000,0x00000000,0x00000000,0x00000000,0x00000000,
    0x00000000,0x00000000,0xdb000000,0x897bae9d,0xddd53eee,0x3bbbb621,
    0x3bbb64ee,0xeeea80bd,0xeec86eee,0x1bdd102e,0x3bae3ddb,0x775c2dee,
    0x5c3eeb9e,0xd81ceeee,0x5d3bb65e,0x5c0ceeee,0x45eeeeee,0x791cdeb9,
    0xb5097353,0xddb8877b,0xdc883da9,0x9d7101bd,0x9914ca83,0x32606445,
    0xebcc81ce,0x66442dcb,0x32219973,0x7ec1cdbc,0x44bf952c,0xbfb31dfd,
    0x6666fe41,0x373bee6e,0xefee987f,0xffca87dc,0x2e7fd106,0x99fd50ef,
    0x67f545fb,0x7cc1efc8,0x5c1ffdce,0x25fd73ff,0x1ffdcefa,0x3b333fa6,
    0x3fb7be67,0x9fffff94,0x7ff6ffcc,0x3ffb7e60,0x6f7dc3fd,0xfdefb86e,
    0x6c5fae2f,0xfa8fee5f,0x3a22ffdf,0x0fdffdff,0x77ed7fa2,0xfdbffd30,
    0x4e4c7d43,0x6c5e82f8,0x2e427f06,0xd83f893a,0x260f74fc,0x8f901fcf,
    0x1b63e44e,0xe817eef9,0x3fa1ba24,0x24e8f70f,0x88bdc6e8,0x5c6bee6b,
    0x1f919f11,0x81f70764,0x0fb4fb98,0x9f0beaa2,0x3a3dc7d8,0x4437e0c5,
    0x7c4fcc7d,0xcfd885f2,0xd0fdc0df,0x6fe4fcc9,0x10fb81f9,0x3eb3e07f,
    0xf1274089,0x5fbf3f07,0x8275b607,0x44e999fc,0x45fb99fc,0x2204fcfc,
    0x81f509de,0xe8f75fde,0x3f707d44,0xffd831bb,0x221f50cf,0x7060fe2f,
    0xffffffff,0x7ffff541,0x3ffffea2,0xbd1ee1ff,0x3e60fcc0,0x47e23e61,
    0x20dfd02f,0x5f126c7b,0x101f5fff,0x7c03ee7f,0x9dd01fff,0xf7981ffb,
    0x4fe205ff,0xfffc80fb,0x7ffe44ff,0x7ffe43ff,0xdffff104,0xf59d07e6,
    0x4c4e8f75,0x17ffee1f,0x9afdcc26,0x3e1fc8cf,0x54e7cc04,0x3a0aaadf,
    0x222fa9ad,0x0aaaaacf,0x440bd1ee,0xf30fdc3f,0x20be3f11,0x7b85fdfc,
    0x2ffbe26c,0x75f607ef,0x07eb3e05,0x406f7ff4,0x01fdfffc,0x07fffff7,
    0x89d555f9,0x1febaafc,0x413eebf2,0x3f309de9,0x8f9fb4e8,0xf70fd44e,
    0xbee86bb3,0xfff75eb9,0x567ec7ff,0x5bf12fba,0x44b75dfb,0x0cfeb9cf,
    0x372aafb6,0x3f6afea0,0x7ec3930e,0x7e46fcac,0x219f4f8b,0x3bf95fd8,
    0x774cbf62,0x3ff5ffa0,0x403fbf30,0x0274033f,0x1b27d674,0x6ecccee8,
    0x322747c8,0x4f91fc47,0xc89d00fc,0xfff14e87,0x2e3ec4e8,0x363f1117,
    0x9b0dfffe,0xec8b9373,0x7fd44eff,0x5c5ffeef,0x22ffefff,0x0dfffeb8,
    0x3ffbffa2,0xffc87f72,0x477fc45f,0xf71ff8ff,0x54fff6bf,0x45ff76ff,
    0x80df94fd,0x37ee06fe,0x59df502c,0x3beafee0,0x37ee2fcc,0x6c47fb11,
    0x263bf52f,0x2fdcccfd,0x3be17fb3,0x6e6774c2,0xb977cc3f,0x333ba67f,
    0x33f663fe,0x0c41fdcc,0x20044000,0x002600c1,0x8062004c,0x00000601,
    0x1fc80000,0x3fb80bf3,0x0dffff10,0x221bfffa,0xfffffeff,0x27fff32f,
    0xff71fffb,0x327ffd1d,0x23efffff,0xdf71fffc,0x2dffffc8,0x9fa6ffc8,
    0x42dffffc,0xfffffffc,0x00000001,0x00000000,0x00000000,0x00000000,
    0x00000000,0x00000000,0x00000000,0x00000000,0x00000000,0x00000000,
    0x00000000,0x99500000,0x65c17b71,0x4079910c,0xcccca820,0x2e79973c,
    0x020503cc,0xcb806081,0x848165c2,0x800004a8,0x5c098840,0x5dddc42c,
    0x59910bbb,0xb7007d70,0x930140c3,0xc88c4263,0x77777710,0x3fea1777,
    0x3fffffff,0x09fffff9,0x75c00000,0x363fdfff,0x5fe999ef,0x5c3a6990,
    0xf94ffeef,0x217ff29f,0xa97d41f9,0x06dcba2f,0x65c766e2,0x227e41e9,
    0x7ffc47b9,0x3e2fffff,0xf56eafc6,0x7264e645,0x7fffffff,0xeb87aaa2,
    0xfd96a2ea,0x1f87dafe,0x4d9fdc5b,0x7d4feeb9,0xffffffff,0x77777713,
    0x2aa61777,0x00001aaa,0x08f7cc00,0xfbafabf8,0x1faaec40,0x2e2fd56a,
    0xba87f10f,0x3f62bafa,0xc9f445fb,0x207ec40e,0x3f7ee0e9,0xbbba8783,
    0x5f32fbbb,0x3e6bb4e8,0x888683a1,0x76f5c088,0xebadcf62,0x17fe4720,
    0x11f4576e,0x22220600,0x00000888,0x00000000,0xddd803f3,0xaf446cef,
    0x0bf501fb,0x7dc3e53e,0x7f43ffff,0x3f29f106,0x1d71ec41,0x41fca7cc,
    0x6b97c007,0x3e2993d8,0x98f6f6e0,0x1ccccccc,0x7549d77d,0x130052ec,
    0x00283950,0x00000000,0x00000000,0xffc801f3,0x9fc84ffd,0x14fa84f9,
    0x03f9fb81,0xfa81dff1,0x99ec82ff,0x4baeea4f,0x8b91ccfc,0x037f734d,
    0x5c0f4be0,0x5c43c752,0x77777541,0x557713ee,0x00002ca8,0x00000000,
    0x00000000,0xcfda8000,0xf1ff503b,0x227aa05f,0x2effea4d,0x00fff85d,
    0x7cc7f7f7,0x3721fd8d,0x0a982e98,0x4002aaa6,0xd000aaa8,0x00200063,
    0x00000000,0x00000000,0x00000000,0xe8800000,0x880fffff,0x4c01f94f,
    0x7ffe42e3,0x03fb86ff,0x8931dcee,0x000a8e0c,0x00000000,0x00000000,
    0x00000000,0x00000000,0x00000000,0x00000000,0x00000000,0x00000000,
    0x00000000,0x00000000,0x00000000,0x00000000,0x00000000,0x00000000,
};

static signed short stb__courier_bold_17_latin1_x[224]={ 0,3,1,0,1,1,1,3,3,1,1,0,3,1,
3,1,1,1,0,0,1,0,1,1,1,1,3,2,-1,0,0,1,1,-1,0,0,0,0,0,0,0,1,0,0,
0,-1,-1,0,0,0,0,0,0,0,-1,-1,0,0,1,3,1,1,1,-1,3,0,-1,0,0,0,1,0,0,0,
1,0,0,-1,0,0,-1,0,0,1,1,0,0,-1,0,0,1,2,3,2,0,1,1,1,1,1,1,1,1,1,
1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,0,3,1,0,1,0,
3,0,2,-1,2,0,-1,1,-1,-1,2,0,2,2,3,0,0,3,2,2,1,0,0,-1,0,1,-1,-1,-1,-1,
-1,-1,-1,0,0,0,0,0,1,1,1,1,-1,-1,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,
0,0,0,0,-1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,-1,0,
 };
static signed short stb__courier_bold_17_latin1_y[224]={ 12,2,2,1,1,2,3,2,2,2,2,3,9,7,
10,1,2,2,2,2,2,2,2,2,2,2,5,5,3,5,3,2,2,3,3,2,3,3,3,2,3,3,3,3,
3,3,3,2,3,2,3,2,3,3,3,3,3,3,3,2,1,2,2,15,1,5,2,5,2,5,2,5,2,2,
2,2,2,5,5,5,5,5,5,5,2,5,5,5,5,5,5,2,2,2,6,2,2,2,2,2,2,2,2,2,
2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,12,5,1,2,4,3,
2,2,2,3,2,5,6,7,3,0,1,1,2,2,1,5,2,6,11,2,2,5,2,2,2,5,-1,-1,-1,0,
0,-1,3,2,-1,-1,-1,0,-1,-1,-1,0,3,0,-1,-1,-1,0,0,4,2,-1,-1,-1,0,-1,3,2,1,1,
2,2,2,1,5,5,1,1,2,2,1,1,2,2,2,2,1,1,2,2,2,3,4,1,1,2,2,1,2,2,
 };
static unsigned short stb__courier_bold_17_latin1_w[224]={ 0,3,6,9,7,7,8,3,5,5,7,9,4,7,
3,7,7,7,8,8,7,8,8,7,7,8,3,5,10,9,10,7,7,11,9,9,9,9,9,9,9,7,10,10,
9,11,10,9,9,9,10,9,9,9,11,11,9,9,7,5,7,5,7,11,3,9,10,9,10,9,8,9,9,9,
6,9,9,11,9,9,10,10,9,7,8,9,10,11,9,9,7,5,3,5,9,9,9,9,9,9,9,9,9,9,
9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,0,3,7,9,7,9,
3,9,5,11,6,9,10,7,11,11,5,9,5,5,3,9,9,3,4,5,7,9,9,11,9,7,11,11,11,11,
11,11,11,9,9,9,9,9,7,7,7,7,10,10,9,9,9,9,9,7,9,9,9,9,9,9,9,8,9,9,
9,9,9,9,11,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,10,9,
 };
static unsigned short stb__courier_bold_17_latin1_h[224]={ 0,11,6,13,13,11,10,6,13,13,7,9,6,2,
3,13,11,10,10,11,10,11,11,11,11,11,8,9,9,5,9,11,12,9,9,11,9,9,9,11,9,9,10,9,
9,9,9,11,9,13,9,11,9,10,9,9,9,9,9,13,13,13,6,2,4,8,11,8,11,8,10,11,10,10,
14,10,10,7,7,8,11,11,7,8,11,8,7,7,7,11,7,13,13,13,4,10,10,10,10,10,10,10,10,10,
10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,0,11,12,10,8,9,
13,12,3,10,5,7,6,2,10,3,5,11,6,6,4,11,12,3,4,6,5,7,10,10,10,11,13,13,13,12,
12,13,9,13,13,13,13,12,13,13,13,12,9,12,14,14,14,13,13,7,12,14,14,14,13,13,9,11,12,12,
11,11,11,12,8,10,12,12,11,11,11,11,10,10,11,10,12,12,11,11,11,9,10,12,12,11,11,15,14,14,
 };
static unsigned short stb__courier_bold_17_latin1_s[224]={ 253,51,120,215,225,32,11,127,191,33,52,
207,115,223,185,207,133,20,28,141,37,150,159,188,196,204,210,249,186,139,145,
223,218,57,79,1,122,132,25,11,69,115,45,89,135,123,111,21,35,181,217,
231,156,75,13,1,246,236,228,171,163,157,90,211,181,180,122,158,31,190,56,
241,95,85,32,65,105,224,246,214,42,40,1,142,53,200,41,11,236,112,33,
141,147,151,166,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,
1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,253,251,246,
197,150,176,177,236,189,155,149,23,104,223,133,199,156,123,84,78,162,178,1,
195,176,98,131,68,177,207,239,85,233,1,121,11,206,109,45,57,77,67,99,
226,39,245,133,188,100,167,89,49,59,13,47,60,107,69,79,39,23,197,197,
23,97,196,93,65,75,117,168,229,127,157,168,62,72,82,187,145,92,167,87,
178,113,103,55,166,219,137,147,213,102,1,21,11, };
static unsigned short stb__courier_bold_17_latin1_t[224]={ 1,31,77,1,1,31,56,77,1,17,77,
56,77,77,77,1,31,56,56,31,56,31,31,31,31,31,67,44,56,77,56,
31,17,67,67,44,67,67,67,44,67,56,56,67,56,56,67,44,67,1,56,
31,56,56,67,67,56,56,56,1,1,1,77,77,77,67,44,67,44,67,56,
31,56,56,1,56,56,67,67,67,44,31,77,67,44,67,77,77,67,44,77,
1,1,1,77,56,56,56,56,56,56,56,56,56,56,56,56,56,56,56,56,
56,56,56,56,56,56,56,56,56,56,56,56,56,56,56,56,56,1,31,17,
44,67,56,1,17,77,44,77,77,77,77,44,77,77,31,77,77,77,31,31,
77,77,77,77,77,44,44,44,31,1,17,1,31,17,1,67,17,17,17,1,
17,17,1,1,17,67,17,1,1,1,17,17,77,17,1,1,1,17,1,56,
31,17,17,31,31,31,17,67,44,17,17,31,44,44,44,44,44,44,44,17,
17,31,31,31,56,44,17,17,31,44,1,1,1, };
static unsigned short stb__courier_bold_17_latin1_a[224]={ 144,144,144,144,144,144,144,144,
144,144,144,144,144,144,144,144,144,144,144,144,144,144,144,144,
144,144,144,144,144,144,144,144,144,144,144,144,144,144,144,144,
144,144,144,144,144,144,144,144,144,144,144,144,144,144,144,144,
144,144,144,144,144,144,144,144,144,144,144,144,144,144,144,144,
144,144,144,144,144,144,144,144,144,144,144,144,144,144,144,144,
144,144,144,144,144,144,144,144,144,144,144,144,144,144,144,144,
144,144,144,144,144,144,144,144,144,144,144,144,144,144,144,144,
144,144,144,144,144,144,144,144,144,144,144,144,144,144,144,144,
144,144,144,144,144,144,144,144,144,144,144,144,144,144,144,144,
144,144,144,144,144,144,144,144,144,144,144,144,144,144,144,144,
144,144,144,144,144,144,144,144,144,144,144,144,144,144,144,144,
144,144,144,144,144,144,144,144,144,144,144,144,144,144,144,144,
144,144,144,144,144,144,144,144,144,144,144,144,144,144,144,144,
144,144,144,144,144,144,144,144, };

// Call this function with
//    font: NULL or array length
//    data: NULL or specified size
//    height: STB_FONT_courier_bold_17_latin1_BITMAP_HEIGHT or STB_FONT_courier_bold_17_latin1_BITMAP_HEIGHT_POW2
//    return value: spacing between lines
static void stb_font_courier_bold_17_latin1(stb_fontchar font[STB_FONT_courier_bold_17_latin1_NUM_CHARS],
                unsigned char data[STB_FONT_courier_bold_17_latin1_BITMAP_HEIGHT][STB_FONT_courier_bold_17_latin1_BITMAP_WIDTH],
                int height)
{
    int i,j;
    if (data != 0) {
        unsigned int *bits = stb__courier_bold_17_latin1_pixels;
        unsigned int bitpack = *bits++, numbits = 32;
        for (i=0; i < STB_FONT_courier_bold_17_latin1_BITMAP_WIDTH*height; ++i)
            data[0][i] = 0;  // zero entire bitmap
        for (j=1; j < STB_FONT_courier_bold_17_latin1_BITMAP_HEIGHT-1; ++j) {
            for (i=1; i < STB_FONT_courier_bold_17_latin1_BITMAP_WIDTH-1; ++i) {
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
        float recip_width = 1.0f / STB_FONT_courier_bold_17_latin1_BITMAP_WIDTH;
        float recip_height = 1.0f / height;
        for (i=0; i < STB_FONT_courier_bold_17_latin1_NUM_CHARS; ++i) {
            // pad characters so they bilerp from empty space around each character
            font[i].s0 = (stb__courier_bold_17_latin1_s[i]) * recip_width;
            font[i].t0 = (stb__courier_bold_17_latin1_t[i]) * recip_height;
            font[i].s1 = (stb__courier_bold_17_latin1_s[i] + stb__courier_bold_17_latin1_w[i]) * recip_width;
            font[i].t1 = (stb__courier_bold_17_latin1_t[i] + stb__courier_bold_17_latin1_h[i]) * recip_height;
            font[i].x0 = stb__courier_bold_17_latin1_x[i];
            font[i].y0 = stb__courier_bold_17_latin1_y[i];
            font[i].x1 = stb__courier_bold_17_latin1_x[i] + stb__courier_bold_17_latin1_w[i];
            font[i].y1 = stb__courier_bold_17_latin1_y[i] + stb__courier_bold_17_latin1_h[i];
            font[i].advance_int = (stb__courier_bold_17_latin1_a[i]+8)>>4;
            font[i].s0f = (stb__courier_bold_17_latin1_s[i] - 0.5f) * recip_width;
            font[i].t0f = (stb__courier_bold_17_latin1_t[i] - 0.5f) * recip_height;
            font[i].s1f = (stb__courier_bold_17_latin1_s[i] + stb__courier_bold_17_latin1_w[i] + 0.5f) * recip_width;
            font[i].t1f = (stb__courier_bold_17_latin1_t[i] + stb__courier_bold_17_latin1_h[i] + 0.5f) * recip_height;
            font[i].x0f = stb__courier_bold_17_latin1_x[i] - 0.5f;
            font[i].y0f = stb__courier_bold_17_latin1_y[i] - 0.5f;
            font[i].x1f = stb__courier_bold_17_latin1_x[i] + stb__courier_bold_17_latin1_w[i] + 0.5f;
            font[i].y1f = stb__courier_bold_17_latin1_y[i] + stb__courier_bold_17_latin1_h[i] + 0.5f;
            font[i].advance = stb__courier_bold_17_latin1_a[i]/16.0f;
        }
    }
}

#ifndef STB_SOMEFONT_CREATE
#define STB_SOMEFONT_CREATE              stb_font_courier_bold_17_latin1
#define STB_SOMEFONT_BITMAP_WIDTH        STB_FONT_courier_bold_17_latin1_BITMAP_WIDTH
#define STB_SOMEFONT_BITMAP_HEIGHT       STB_FONT_courier_bold_17_latin1_BITMAP_HEIGHT
#define STB_SOMEFONT_BITMAP_HEIGHT_POW2  STB_FONT_courier_bold_17_latin1_BITMAP_HEIGHT_POW2
#define STB_SOMEFONT_FIRST_CHAR          STB_FONT_courier_bold_17_latin1_FIRST_CHAR
#define STB_SOMEFONT_NUM_CHARS           STB_FONT_courier_bold_17_latin1_NUM_CHARS
#define STB_SOMEFONT_LINE_SPACING        STB_FONT_courier_bold_17_latin1_LINE_SPACING
#endif

