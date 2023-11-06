// Font generated by stb_font_inl_generator.c (4/1 bpp)
//
// Following instructions show how to use the only included font, whatever it is, in
// a generic way so you can replace it with any other font by changing the include.
// To use multiple fonts, replace STB_SOMEFONT_* below with STB_FONT_courier_bold_19_usascii_*,
// and separately install each font. Note that the CREATE function call has a
// totally different name; it's just 'stb_font_courier_bold_19_usascii'.
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

#define STB_FONT_courier_bold_19_usascii_BITMAP_WIDTH         128
#define STB_FONT_courier_bold_19_usascii_BITMAP_HEIGHT         94
#define STB_FONT_courier_bold_19_usascii_BITMAP_HEIGHT_POW2   128

#define STB_FONT_courier_bold_19_usascii_FIRST_CHAR            32
#define STB_FONT_courier_bold_19_usascii_NUM_CHARS             95

#define STB_FONT_courier_bold_19_usascii_LINE_SPACING           9

static unsigned int stb__courier_bold_19_usascii_pixels[]={
    0x05502c88,0x29813198,0x3015c398,0x59002c89,0x02d4f32a,0x8000b32e,
    0x55442dda,0x0002aa61,0x0db05f98,0x6d8bf5e8,0xff887fd4,0x7f41fd02,
    0xfd9fcc00,0x7405f56f,0x7fe446ff,0xfbcfb80c,0xff9ffee2,0x3001744f,
    0xdeffd881,0xd89f5f80,0x3e207ec6,0x7d44fa85,0x3607ec04,0x86e81be6,
    0x2ffddff9,0xfd8d7174,0x13e17e61,0x43555550,0x82ffcdfe,0x36c4f8cf,
    0x743741b6,0x300fe80f,0x7dcdb09f,0xff88dd02,0x3c43fa61,0x64bf11ea,
    0x2b7ee21f,0x3ffea0aa,0x447f15ff,0x33bf220d,0xdb1b62ef,0x0bf11ba0,
    0x07ec0bee,0x20bf136c,0x5c27d46e,0x3fa6d53f,0x5f89fc87,0x7fffffe4,
    0x2fccccc5,0x3ee037fd,0x366fffff,0x46e83746,0x07f503fa,0x91b60bf1,
    0xfc8dd03f,0x2b74f881,0xdf8879be,0x9df981fc,0x265f8019,0xfa83effe,
    0xd36c3fbb,0x43bf209f,0x09f302fb,0x11b603f9,0xfb8dd0bf,0x1b74f880,
    0x3f20f31f,0x0013e05f,0x3fd730bf,0x41faaf98,0x6417f66d,0x4c0bee5f,
    0xb02fc44f,0x6e81f90d,0x9fdc1fcc,0x20f9bd5b,0x13e01ff8,0x116abf00,
    0x7ffff49f,0xdd1b63ff,0x07f51ba0,0x03f70fea,0x227cc36c,0x220ef86e,
    0x322f50fe,0x05f880ee,0x57e0027c,0x2fc99cfc,0x33fb7f6a,0x20db1b61,
    0xc82fc46e,0x36037c2f,0x3741fb06,0x7fe6ffd4,0x31007e23,0xbfd805fb,
    0x57e05fdb,0x85fffffc,0x6c0fc8fb,0x86e836c6,0x5c7f80fd,0x9836c02f,
    0x74c1ba4f,0x0dd80cff,0x7fffdc53,0x3ffa600f,0x453e01df,0xf901fea9,
    0xd8db0f91,0x542fc40f,0x3a1fdc4f,0x3a06d806,0x3ea0dd0f,0x222c9bef,
    0x2e23feff,0x31002ccc,0x0ff26620,0xfb7c81ba,0x0ffa8db0,0x3f605ff1,
    0x2fa83fa0,0xa81bff60,0xf8dffd3f,0x83ffffff,0x00000019,0x20bffff7,
    0x14ca605c,0x2e1d4154,0x8370e201,0x1e65405a,0x1665cf60,0x0054c2a6,
    0x44000000,0x00001bcb,0x00000000,0x00000000,0x00000000,0x00000000,
    0x00000000,0x00000000,0x00000000,0xcb8aa980,0x4ce5c401,0x0800402a,
    0x00441360,0x64c05b93,0x0601aa9b,0xcb800350,0x666665c3,0x3fe04c2c,
    0x41efffff,0xffffffd8,0x77fe441f,0xdeffc981,0xeb87fe62,0x7fe41dff,
    0x7ff4c5ff,0x6cc6ffff,0x3a0edfff,0xff1005dd,0xfffffd8d,0xb11fea3f,
    0x8df517ff,0xffd98cfc,0x7eeffcc0,0x7e67fc2f,0x4c7fe65f,0x10ffccef,
    0xfb0fe49f,0x419fd515,0xffdcdff9,0x00074b31,0x7d45b8db,0x3f60f622,
    0x4f88fcc1,0x0ffc47f8,0x87ee1fd3,0x43fe64f8,0x54fe61f8,0x7c4fe62f,
    0x3f627dc3,0x1688fd40,0x4ddc401d,0x00fd806d,0x3f981fb0,0xa8fd07f5,
    0xf73fb84f,0x1fe21a87,0xdf13f981,0x3ea3fd55,0x7f127cc2,0x17dd9060,
    0x7ffec477,0x2fc406ff,0x261bfb00,0x23df11fe,0x0fe47fc8,0xffe8a7c4,
    0x107f80bd,0x7fdc1ff9,0x322fc4ff,0x8007ea4f,0x321cfec9,0x06fea8bf,
    0x02a617d4,0x3ffffff6,0x7ffffd43,0x4407e47f,0x7ffedc4f,0xdfd83742,
    0x3f77fe20,0x3afbf20f,0xc87ee4ff,0x9dd53eee,0x4c4f8857,0x207ec06f,
    0xdafd80fe,0xbb5100bd,0x83fa8fb5,0xf98133fb,0x85c82646,0x88fea2fb,
    0x24fdffeb,0xfffd13fa,0x36eec66b,0x40dd03f5,0x817c45f8,0x3ec0007d,
    0xfe883be2,0x00fb0bd0,0x7c43f700,0x47f31104,0x41fa86f8,0x27c47668,
    0x2fa81be6,0x03fb02dc,0x503fa600,0x47ff9bff,0x3febceff,0x982a80cc,
    0x82febcef,0x641fd998,0x1fecbdff,0x321e8744,0x4fffdbdf,0x00b81fb0,
    0x800fffff,0x4c1ffffd,0x6ec2fffc,0x6e83efff,0xff501ff0,0xfff905ff,
    0x3ffae09f,0x9dd703ff,0xfeffeb88,0x004d80ef,0x00166654,0x880f3326,
    0x22009800,0x08801100,0x002f2e20,0x4008004c,0x00000018,0x00000000,
    0x00000000,0x00000000,0xb8000000,0x376e003c,0x02dda883,0xa8805bb5,
    0x900403dd,0x64c79999,0x0454000c,0x402b3260,0x0b3221cb,0x0dff0660,
    0x8ffffee0,0x46fffff8,0x105ffffa,0xb30ddffd,0xff8d9fff,0xff90ffff,
    0x3ffe6003,0x3ffffe06,0x263ffa83,0x7fc404ff,0xef8036c0,0x5b10fd88,
    0x21dd0fdc,0x17f442fc,0xfd99ff30,0x2a027c3f,0xb5db001f,0x262bee05,
    0x83ffe809,0xd84c804f,0xf981cb8e,0xf980bea3,0x2fc49f13,0x1df007f2,
    0x233e1fc8,0x7975f500,0xa8817e01,0xb80aaafd,0x54f83fcf,0x3f600355,
    0x2e1effff,0x2e13e20f,0x993e0ffc,0x1656f46f,0x22441fc4,0x541dffff,
    0x80efffff,0xfff701fd,0xef889fff,0xf8cf83f9,0xdfb005ff,0x3e4bf715,
    0x3ffe22fc,0x7f4d7e44,0x3ffffe27,0x4007ea0e,0x20ffcdff,0x2fb89efa,
    0x26c77fcc,0x20667f66,0xf83f89fd,0x0009efcd,0x91fb85fb,0xa884f81f,
    0x3ffa62fe,0x37fe27ff,0x07ee3fa8,0xa8fe2040,0xfd0fe22f,0xf90dfbf9,
    0x3f8a7cc0,0x3605fff8,0x3f887d85,0x017cc5f5,0x3eae617e,0x99b637c5,
    0x9ba0003f,0x893e21fa,0x903ff94f,0x7fffec0f,0x77ffc2ff,0x6c0ff880,
    0xf887dc2f,0xf8803f24,0xe85fb105,0x1ff1ba0f,0xf1010c88,0x9f10fd49,
    0x3ffcbfd8,0x332e07c8,0x6fc0efdc,0x40881efa,0xfdbdffeb,0x37e6fec5,
    0x7fd977db,0x427fede4,0x43fdbef9,0xfecbdffa,0xfd959fb2,0x6437f661,
    0x3ff662ef,0x3fb2a6fe,0xfb500ccc,0x5d3f221d,0x7f401cff,0x40beffef,
    0x2a0effd8,0x223ffffe,0x2e01cffe,0xd980cffe,0x3662efff,0x3ea3ffff,
    0x3fff8aff,0xfff70188,0x3f605fff,0x29ff32ff,0x4002fffa,0x40088008,
    0x10002009,0x04400c00,0x00000000,0x00000000,0x00000000,0x00000000,
    0x00000000,0x4c000000,0x66dc402c,0xf7097301,0x9ffd55ff,0x5401e65c,
    0x70efffff,0x017dffff,0x2b7ffff6,0x4477ff40,0xfd30effe,0x0f7fecbf,
    0x1dfd0ffd,0xe8813ea0,0x3ea5ffff,0xdffa86ff,0xf13ffd99,0xdb300dff,
    0x3aa1bdfd,0x80ffeeef,0x6feeeffb,0xec86f7ec,0x93ff626f,0x3f60dffc,
    0x037fe63f,0x5f9004c4,0xebd987e4,0x0dd0db06,0x1f7001ba,0x27c43f50,
    0x517d47c8,0x17ccaa5f,0x4c3f4374,0x0bff66ff,0x95015554,0x06d83f98,
    0x3a0dd0db,0x407dc006,0x417e21fa,0xf327c47c,0x3f53ff17,0x27cc5f70,
    0x7c57f7cc,0xfff882fe,0x40fec006,0xdd0db06d,0xf7001ba0,0xf979f501,
    0x545f205f,0x2f3e22fd,0x880fbcff,0x2603f65f,0xfbfcdfbf,0x00dd3102,
    0x06d827ec,0x3a0dd0db,0x1f707206,0x5fffff50,0x7ffffe40,0xeefedf84,
    0x223f207c,0xf95f305f,0xe805f3bf,0x04fd8806,0x7436c1b6,0x3e20dd06,
    0x7d407dc4,0x3205fc9b,0xfd01bccf,0x40fff79f,0x302fbcf9,0xf35ff15f,
    0x4406e805,0x836c04fe,0x40fe21fc,0xc89f106e,0x7dc3f507,0x3600f904,
    0x06ff99ff,0xf30377f4,0x017cd2e5,0x2ff981ba,0xff106d80,0x3a01fd79,
    0xb7bff106,0x7bfb309f,0xfd7067ec,0x3fe40599,0xffa80bfd,0x47bfb103,
    0x6540dfdb,0x223ccffc,0x1dccceff,0x399ff993,0x41cffe98,0x3ccffcca,
    0x827ffed4,0x3e25fffb,0x3ffff61f,0xfb93ee04,0x100ff804,0x7fecdffd,
    0x7fffec1f,0x3ffe25ff,0xff53ffff,0x2207ffff,0xfffffb00,0x000620bf,
    0x00000000,0x00000000,0x00000000,0x00000000,0x00000000,0x5c000000,
    0x7ffd5fff,0xfd31ffd8,0x3fffea9f,0xfd12ffff,0x23dfd35f,0x3ff65ffa,
    0x3dfffd33,0xffffff70,0x7fffdcdf,0x2ffd40be,0x3fee7ffb,0xf701cfff,
    0x75401fff,0x85dff3ef,0xffb36ffc,0x3ffbbea7,0xdfb12fee,0x261dfb33,
    0x4bbf66fe,0x80defed8,0xfeeeefea,0x3fbbfea6,0x97fa60ef,0xdfd52efd,
    0xb503ffdd,0xfa807fff,0x3601bf91,0xfa9b63ff,0xa8be6dd2,0xf113e21f,
    0x501fd11f,0x41fa805f,0x3ee3ec6d,0x1fd37c44,0x02fc1fa8,0xfa80ddfd,
    0x7ec04fda,0x7ccdb0fe,0xa87e6dd1,0x2613e21f,0xf502feef,0xf89fa805,
    0x6c3ec3a9,0x7e67d40f,0x3e61fa83,0x5f77f305,0x03fffd40,0x6dafcfec,
    0x2a14dd14,0x04feeeef,0x7d407ff5,0x7f77d402,0x3f70fb03,0x2a0bffb0,
    0x01ffeeef,0x40bf11f9,0x00dfdffa,0x36d7e5f6,0x77d40dd0,0xf704feee,
    0x217d409f,0x3fbbea09,0x3f70fb03,0x2a01ff10,0x85ffeeef,0x0feaaef8,
    0x13ee5f50,0xddff17d8,0x3f503740,0x77d427c4,0x85f502fd,0x3e27ea3f,
    0x643ec489,0x540db00f,0x70bf221f,0x07ffffff,0x00fd87ea,0x037fd4fb,
    0x10fd40dd,0xd0ff889f,0xf85f503f,0x3f507ea4,0x81be63ec,0x307ea06d,
    0x999ee87f,0xdfd986e9,0xea87df33,0x70dfb1cf,0xd9879ff9,0x2efc89df,
    0x3f61bfd5,0x9bfb912f,0x3f669f99,0x51fdcccd,0x3ffd99fd,0x879ff970,
    0xfdccdfd9,0x47df911f,0x3ee0dfeb,0x71bf65ff,0x1be27fff,0x51bffffa,
    0xfff57fff,0x223bff27,0xfff35ffe,0x2e9fffff,0xffffffff,0xbdffff71,
    0x3ffffa01,0x7ffffdc6,0x3ffe62df,0x007fffa6,0x00000000,0x00000000,
    0x00000000,0x2a000000,0x53ffffff,0x47ffffff,0x3ffa000a,0x306fffff,
    0x88a20003,0x035510aa,0x54057973,0xcb9819bc,0x0ddcc01b,0x55555544,
    0xffdddf51,0x3bffb667,0x019ff32d,0xddddff90,0x001b60df,0x7fe47fee,
    0xfe89ffb2,0x7e43ffff,0x7d47ffff,0xfb04ffff,0x7d41bfff,0xf54fffff,
    0x3741be63,0x803ffe98,0xdd06e86d,0x177f5400,0x24f98bee,0x2fa88cf9,
    0x3ea277e6,0x6c44d40f,0x4ce7ec0f,0x26bea5fc,0x11f30efc,0x01ba01fd,
    0x6c05dfd5,0x740aad76,0x2ffe9806,0x27c45f50,0x8159bff1,0xb985a87c,
    0x37c1feed,0x3ea507e4,0x405fb00e,0xbff7006e,0x0ffdfb03,0x333ff32e,
    0x0fff620b,0x27c45f50,0x87bffae6,0xdff7005f,0x1fcc3ffd,0x3bea17d4,
    0xe809f900,0x9ffb1006,0x10ffdfb0,0xffffffff,0x006ffe43,0x24f88bea,
    0xe97e623a,0x37e2180f,0x0df07ee0,0x877d41fd,0x4c97ea1a,0xffb806e8,
    0x1aedb01d,0xfb101ba0,0x5f7cc07f,0xbfb1effc,0x7d49fb77,0x22fdbbde,
    0xdffdbbef,0x3f33fee1,0x337fea4f,0x41ff15fc,0x2a06e86e,0x36c02efe,
    0x4c01ba00,0xff903ffe,0x3ae5ffbf,0x540cefff,0x543efffd,0x2ffefffe,
    0x21ffff54,0x5ffffffc,0xdf999bfb,0x333ff326,0x007ffd11,0x00399ff7,
    0xfea800dd,0x4009880e,0x00300098,0x00440031,0xfffffb00,0x3fffeadf,
    0x019d13ff,0x0fffffa0,0x5c001320,0x0000001e,0x00000000,0x00000000,
    0x00000000,0x00000000,0x00000000,0x502bb880,0x37717935,0x03971550,
    0x0e546aa2,0x55545553,0x55515541,0x2a20aa98,0x0005301a,0x33310cc4,
    0x01981333,0xeffffd98,0x3ffffe20,0x7fcc7fff,0xfc86ffff,0xd2fffeef,
    0xfff35fff,0x4d7ffccf,0x3ffe1fff,0x6c1fff24,0xfc81dc06,0xffffff73,
    0xd53fc9ff,0xc88bfe81,0x7477d44f,0x7dc2faaf,0x982fb89f,0x11b8bfff,
    0x067dc7f9,0x3feaffe6,0x8ddafc41,0x3a2e21fd,0x7fcc1b8e,0x2ee26e81,
    0x20bbbbbb,0xf98fdc6e,0x0ffcccce,0xf9becfe6,0x9f117d43,0xf8807be0,
    0x74403f66,0x3db00eff,0xfb8dd3ff,0x223fffff,0x3e20feff,0x08888882,
    0xf51985c8,0x3fffffff,0xf37d9fcc,0x3e22fa87,0xf7009f04,0xfc809f35,
    0x3f7ee05f,0xfd984fdf,0x4cff41df,0xfb8d50ef,0x3fffffff,0x27be012e,
    0x7cc19999,0x50fe6fb3,0xf827c45f,0xfdef8804,0x3f37f600,0xdeff980d,
    0xffe883ff,0xfa8bee0e,0xccc98334,0x261ccccc,0xbbefb801,0x37f20fec,
    0x0df9bfd8,0x3f21bfb3,0x33bf2e1e,0x13ff203c,0x7c47ff4c,0x5ffc41ef,
    0xafb81ffa,0x260623fa,0x00000000,0x49ffffb5,0xdfd9ffe8,0xfff51ff9,
    0xfe8bffa5,0x100effff,0x3fea01ff,0x83fff99f,0x220fd0fe,0x000002a2,
    0x4c400000,0x00000000,0x00000000,0x00000000,0x00000000,0x54088220,
    0x33332601,0x31cccccc,0x43777777,0x0000005d,0x00000000,0xd8000000,
    0xff35f99f,0xffb96e5f,0xffffffff,0xffffff54,0x0003fe27,0x00000000,
    0x00000000,0x9f11f900,0x3fbfabb6,0x88888885,0x01100008,0x00000000,
    0x00000000,0x7cf70000,0x02764133,0x00000000,0x00000000,0x00000000,
    0x05d35400,0x00000000,0x00000000,0x00000000,0x18600000,0x00000000,
    0x00000000,0x00000000,0x00000000,0x00000000,0x00000000,0x00000000,
    0x00000000,
};

static signed short stb__courier_bold_19_usascii_x[95]={ 0,3,2,0,1,1,1,3,4,1,1,0,3,1,
3,1,1,1,0,1,1,1,1,1,1,1,3,3,-1,0,0,1,1,-1,0,0,0,0,0,0,0,1,0,0,
0,-1,-1,0,0,0,0,1,0,0,-1,-1,0,0,1,4,1,2,1,-1,3,0,-1,0,0,0,1,0,0,1,
1,0,1,-1,0,0,-1,0,0,1,1,0,0,-1,0,0,1,2,4,2,1, };
static signed short stb__courier_bold_19_usascii_y[95]={ 13,2,2,1,1,2,3,2,2,2,2,3,10,7,
11,1,2,2,2,2,2,2,2,2,2,2,5,5,3,5,3,2,2,3,3,2,3,3,3,2,3,3,3,3,
3,3,3,2,3,2,3,2,3,3,3,3,3,3,3,2,1,2,1,16,1,5,2,5,2,5,2,5,2,2,
2,2,2,5,5,5,5,5,5,5,2,5,5,5,5,5,5,2,2,2,6, };
static unsigned short stb__courier_bold_19_usascii_w[95]={ 0,4,6,10,8,8,9,4,5,5,8,10,4,8,
4,8,8,8,9,8,8,8,9,8,8,9,4,5,11,10,11,8,8,12,10,10,10,10,10,10,10,8,11,11,
10,12,11,10,10,10,11,9,10,10,12,12,10,10,8,4,8,4,8,12,4,10,11,10,11,10,9,10,10,9,
7,10,9,12,10,10,11,11,10,8,9,10,11,12,10,10,8,6,2,6,9, };
static unsigned short stb__courier_bold_19_usascii_h[95]={ 0,12,6,14,15,12,11,6,14,14,8,10,6,3,
3,14,12,11,11,12,11,12,12,12,12,12,9,10,10,6,10,12,13,10,10,12,10,10,10,12,10,10,11,10,
10,10,10,12,10,14,10,12,10,11,10,10,10,10,10,14,14,14,7,3,4,9,12,9,12,9,11,12,11,11,
15,11,11,8,8,9,12,12,8,9,12,9,8,8,8,12,8,14,14,14,4, };
static unsigned short stb__courier_bold_19_usascii_s[95]={ 127,46,12,18,9,91,82,117,46,52,83,
42,101,42,51,58,13,21,11,22,102,62,41,112,60,31,122,121,53,106,19,
51,97,113,102,51,80,69,31,80,36,10,51,1,58,112,13,25,75,86,63,
36,25,30,99,86,47,91,1,81,72,67,92,29,122,96,1,85,100,1,92,
69,71,1,1,111,41,12,25,107,1,13,36,76,117,65,47,70,59,106,118,
32,29,39,19, };
static unsigned short stb__courier_bold_19_usascii_t[95]={ 1,17,86,1,1,17,30,77,1,1,77,
66,77,86,86,1,30,43,43,30,30,30,30,17,17,30,30,17,66,77,66,
17,1,55,55,30,55,55,66,17,55,66,43,55,55,43,55,17,43,1,43,
17,55,43,43,43,55,55,66,1,1,1,77,86,77,66,30,66,17,77,30,
17,30,43,1,30,43,77,77,66,17,17,77,66,1,66,77,77,77,1,66,
1,1,1,86, };
static unsigned short stb__courier_bold_19_usascii_a[95]={ 161,161,161,161,161,161,161,161,
161,161,161,161,161,161,161,161,161,161,161,161,161,161,161,161,
161,161,161,161,161,161,161,161,161,161,161,161,161,161,161,161,
161,161,161,161,161,161,161,161,161,161,161,161,161,161,161,161,
161,161,161,161,161,161,161,161,161,161,161,161,161,161,161,161,
161,161,161,161,161,161,161,161,161,161,161,161,161,161,161,161,
161,161,161,161,161,161,161, };

// Call this function with
//    font: NULL or array length
//    data: NULL or specified size
//    height: STB_FONT_courier_bold_19_usascii_BITMAP_HEIGHT or STB_FONT_courier_bold_19_usascii_BITMAP_HEIGHT_POW2
//    return value: spacing between lines
static void stb_font_courier_bold_19_usascii(stb_fontchar font[STB_FONT_courier_bold_19_usascii_NUM_CHARS],
                unsigned char data[STB_FONT_courier_bold_19_usascii_BITMAP_HEIGHT][STB_FONT_courier_bold_19_usascii_BITMAP_WIDTH],
                int height)
{
    int i,j;
    if (data != 0) {
        unsigned int *bits = stb__courier_bold_19_usascii_pixels;
        unsigned int bitpack = *bits++, numbits = 32;
        for (i=0; i < STB_FONT_courier_bold_19_usascii_BITMAP_WIDTH*height; ++i)
            data[0][i] = 0;  // zero entire bitmap
        for (j=1; j < STB_FONT_courier_bold_19_usascii_BITMAP_HEIGHT-1; ++j) {
            for (i=1; i < STB_FONT_courier_bold_19_usascii_BITMAP_WIDTH-1; ++i) {
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
        float recip_width = 1.0f / STB_FONT_courier_bold_19_usascii_BITMAP_WIDTH;
        float recip_height = 1.0f / height;
        for (i=0; i < STB_FONT_courier_bold_19_usascii_NUM_CHARS; ++i) {
            // pad characters so they bilerp from empty space around each character
            font[i].s0 = (stb__courier_bold_19_usascii_s[i]) * recip_width;
            font[i].t0 = (stb__courier_bold_19_usascii_t[i]) * recip_height;
            font[i].s1 = (stb__courier_bold_19_usascii_s[i] + stb__courier_bold_19_usascii_w[i]) * recip_width;
            font[i].t1 = (stb__courier_bold_19_usascii_t[i] + stb__courier_bold_19_usascii_h[i]) * recip_height;
            font[i].x0 = stb__courier_bold_19_usascii_x[i];
            font[i].y0 = stb__courier_bold_19_usascii_y[i];
            font[i].x1 = stb__courier_bold_19_usascii_x[i] + stb__courier_bold_19_usascii_w[i];
            font[i].y1 = stb__courier_bold_19_usascii_y[i] + stb__courier_bold_19_usascii_h[i];
            font[i].advance_int = (stb__courier_bold_19_usascii_a[i]+8)>>4;
            font[i].s0f = (stb__courier_bold_19_usascii_s[i] - 0.5f) * recip_width;
            font[i].t0f = (stb__courier_bold_19_usascii_t[i] - 0.5f) * recip_height;
            font[i].s1f = (stb__courier_bold_19_usascii_s[i] + stb__courier_bold_19_usascii_w[i] + 0.5f) * recip_width;
            font[i].t1f = (stb__courier_bold_19_usascii_t[i] + stb__courier_bold_19_usascii_h[i] + 0.5f) * recip_height;
            font[i].x0f = stb__courier_bold_19_usascii_x[i] - 0.5f;
            font[i].y0f = stb__courier_bold_19_usascii_y[i] - 0.5f;
            font[i].x1f = stb__courier_bold_19_usascii_x[i] + stb__courier_bold_19_usascii_w[i] + 0.5f;
            font[i].y1f = stb__courier_bold_19_usascii_y[i] + stb__courier_bold_19_usascii_h[i] + 0.5f;
            font[i].advance = stb__courier_bold_19_usascii_a[i]/16.0f;
        }
    }
}

#ifndef STB_SOMEFONT_CREATE
#define STB_SOMEFONT_CREATE              stb_font_courier_bold_19_usascii
#define STB_SOMEFONT_BITMAP_WIDTH        STB_FONT_courier_bold_19_usascii_BITMAP_WIDTH
#define STB_SOMEFONT_BITMAP_HEIGHT       STB_FONT_courier_bold_19_usascii_BITMAP_HEIGHT
#define STB_SOMEFONT_BITMAP_HEIGHT_POW2  STB_FONT_courier_bold_19_usascii_BITMAP_HEIGHT_POW2
#define STB_SOMEFONT_FIRST_CHAR          STB_FONT_courier_bold_19_usascii_FIRST_CHAR
#define STB_SOMEFONT_NUM_CHARS           STB_FONT_courier_bold_19_usascii_NUM_CHARS
#define STB_SOMEFONT_LINE_SPACING        STB_FONT_courier_bold_19_usascii_LINE_SPACING
#endif

