// Font generated by stb_font_inl_generator.c (4/1 bpp)
//
// Following instructions show how to use the only included font, whatever it is, in
// a generic way so you can replace it with any other font by changing the include.
// To use multiple fonts, replace STB_SOMEFONT_* below with STB_FONT_courier_bold_18_usascii_*,
// and separately install each font. Note that the CREATE function call has a
// totally different name; it's just 'stb_font_courier_bold_18_usascii'.
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

#define STB_FONT_courier_bold_18_usascii_BITMAP_WIDTH         128
#define STB_FONT_courier_bold_18_usascii_BITMAP_HEIGHT         86
#define STB_FONT_courier_bold_18_usascii_BITMAP_HEIGHT_POW2   128

#define STB_FONT_courier_bold_18_usascii_FIRST_CHAR            32
#define STB_FONT_courier_bold_18_usascii_NUM_CHARS             95

#define STB_FONT_courier_bold_18_usascii_LINE_SPACING           8

static unsigned int stb__courier_bold_18_usascii_pixels[]={
    0x02000000,0x80000000,0x04c02000,0x201d13b0,0x000002b8,0x45f70011,
    0x4c2e84f9,0xfd00d95e,0x417ffc9f,0x3f93a02e,0x3a60fa80,0xabf884ff,
    0x7ffec41f,0x9affdc3f,0x3ffa0fff,0x2a02dffe,0xf0bf221c,0x5f52ed89,
    0x3e4fca80,0x56fcc0be,0x1fb17dc1,0x8a746e80,0x7d5fc41f,0x6cc67ec1,
    0x447fa62f,0x7ffd44fd,0x4001fdbc,0x3e27c3f8,0x4f803744,0x3fff60fe,
    0x3e63746f,0x788bea04,0x2efea1e4,0x3e13ea1f,0x0dd17d46,0x54bd07f6,
    0x7c1fffff,0x513e27c3,0x7c9f005f,0x6c467c43,0x1fa0fea6,0xc8ad46d8,
    0x3ffff24f,0x903f72ff,0x5f56e81f,0x89f21b60,0x7c1fdccb,0x213e27c3,
    0x3e4f806e,0x41067c43,0x80fc81fb,0xcfa643f9,0x36ff224d,0x2e0f90af,
    0x3757d40f,0x37cc7fb0,0x2ff83f30,0x417ec53e,0xf27c01fb,0x17dff907,
    0x17dc07ec,0x2b3207ec,0xc8fb8996,0x37417d47,0x3602ffe8,0x01ffefff,
    0x49fd07e6,0x203ff14f,0x7f27c05f,0xd97fb260,0xf885f507,0xdbf8cc84,
    0x3ffbfb24,0x7f317e25,0xdb01bea0,0x98015bb7,0x13e27c1f,0x807ee07f,
    0x8530fe4f,0x701f90fb,0xb80fc83f,0x7e4bfd56,0x7dc5ffef,0x500efdbf,
    0x005d805f,0x21fc1f98,0xf8827c4f,0x43f93e04,0x54fb32fd,0x7c47d82f,
    0xc801f304,0x3fea0bd7,0x1fd3303f,0x004f7440,0x43f83f30,0xf9027c4f,
    0x43f93e01,0x23fffffc,0x22fc45f8,0xa93a00fc,0x704fb6c0,0x64955bff,
    0x3e06ffff,0x2a005fff,0x9f0fe61f,0x13e205f8,0x20cf93e6,0xc80dfa98,
    0xf887f21f,0x77ffc405,0xf04faec0,0x44dfffff,0x2600aaaa,0x4cc00aaa,
    0x03fe67ea,0x205fc87f,0x93ffa0fd,0x04f83fff,0x2e2fc9f1,0x2013001f,
    0x86601519,0x00000019,0x507fffee,0x03501501,0x355306c4,0x17405554,
    0x2a054330,0x00000004,0x40000000,0x00001aa8,0x00000000,0x00000000,
    0x00000000,0x00000000,0x00000000,0x00000000,0x00000000,0x30000000,
    0x01008801,0x01300044,0x4000004c,0x00004009,0xfff10000,0x7fff49ff,
    0x3fe60fff,0xdffec84f,0xfd717ea0,0xf909ffbf,0x7fdc45ff,0x3fe1ffef,
    0xbffd1005,0x019ffd50,0x3f22ffa8,0x467cc00f,0x361cccdf,0x747eccce,
    0x3ea3fcbe,0x3ee4fbad,0x3f2fbf27,0x567ec1df,0x3af3f20b,0x17ea0cff,
    0x27ddff40,0x013eeb7e,0x7ecc5f91,0x7c6fcc00,0x4bd02602,0x811ba2f9,
    0x7c5bee7c,0x3f21fdc4,0xfe87f102,0x20115e80,0x543f23f8,0x8981f20f,
    0x447dc2f8,0xcddf8801,0xf71fcc01,0x4c407dc1,0x7d57ea6e,0x37a1fcc1,
    0x641fa818,0xffeee80f,0xf517cc1d,0x3744fea5,0x3f7ffae2,0x7fff7dc2,
    0x3fbfe201,0xd83f204f,0x3ea0fd46,0x457e61ff,0x47fb10df,0x22effef8,
    0x407f43f8,0x1febcffe,0x23ff8af4,0x642ffffd,0x42ffdbdf,0x06ebbffb,
    0x740f90d4,0x07ea36c5,0x4f897f6e,0x3fffbfee,0x3ab7fe63,0x7f5efe47,
    0x7c1fe80f,0x7ffffd44,0x7ffdfd13,0x0bf227c4,0x107dc3f7,0x20be607b,
    0x907dc3f9,0x3e1fb80f,0x7d6edc42,0x2f99be23,0x3fbffae2,0x87c86e80,
    0xf72fccc8,0x81f53ec5,0x707dc2f9,0xa837cc1f,0x4c0fc80f,0xf5017a2f,
    0x43f88005,0x8c0fe25f,0xe81fd07c,0x643fe205,0x2f887dc7,0x83ee17dc,
    0xaee840fb,0x0bf05fca,0xd8bf6ffa,0x20fecaac,0x33e6200a,0x3faf3ee0,
    0x37dccc40,0x6ddf7fdc,0x3f6b222f,0x2ef7ea1f,0x6d67ec6f,0x9fb11dff,
    0x6d413f66,0x5d01ceff,0x713ffa20,0x443dfffd,0x3fffe04f,0x4177fe45,
    0xe80efffd,0x42dffeef,0xb80beff8,0x5c40efff,0x53ffeffe,0xfff51fff,
    0x00000801,0x02018011,0x20155530,0x006aa200,0x80040098,0x00098008,
    0x00000000,0x00000000,0x00000000,0x00000000,0x00000000,0x00001700,
    0xd701bb88,0x00030019,0x2aa20040,0xcba80aaa,0x75c0009a,0x0ffe65ff,
    0x209fff30,0x5f9002f8,0x3ffff620,0x025c7443,0x2019fff7,0x36e20ffa,
    0x7ffec04f,0x3ff624ff,0x17d45fff,0x12666fdc,0xcb8807f7,0x005f304f,
    0x67ec072a,0x52a2fd98,0x95bf7068,0x83ffa07f,0x9804fefc,0x57ec1ee9,
    0x3fb8bf30,0x1fc405e8,0xff909f00,0x0003ffff,0xe8df09f5,0x45d833ec,
    0x0fefb86c,0x3a004f84,0x02a83f85,0xffffffb8,0x7fd5fc40,0xb309f01f,
    0x981799bf,0x1fb84fff,0x65d40fc8,0x23f400df,0xf00fbdf8,0x2a2f4009,
    0x3260001f,0xf883ccef,0xf00befcb,0x100be609,0x0f909f97,0x6fe4c3ee,
    0x42fd800b,0xf00fb9fc,0x8bd02a09,0x799710fb,0x2f405541,0x017ffe20,
    0x017cc13e,0x05f709f0,0x76c554fb,0x87fb101e,0x201f74f9,0x742f884f,
    0xffa8fd45,0x7417e2ff,0x1fffc405,0x2f9827c0,0x3e213e00,0xacc2fcc5,
    0x83fe8858,0x05feeefd,0xe87f109f,0x2f427c44,0x017a01f5,0x809fb9f1,
    0x2ebbe04f,0x209f01fd,0x0ffdbffb,0xf98b3598,0xdddd902f,0x2213e09f,
    0x82fdacef,0x5fcabefd,0x3bf260f2,0x9fe443cc,0x332a3dfd,0x7540ccef,
    0x66544fff,0x6d40ccef,0x3b600eff,0x33bfe21e,0x7fd705cc,0x1e77e64c,
    0x80bbff6a,0x21dffffc,0xfffff903,0xf93ff98d,0x7fffecdf,0x201102ff,
    0x2ffffffd,0x20200110,0xfffffff8,0x2e6ffe80,0x00efffff,0x004c4001,
    0x00000000,0x00000000,0x00000000,0x00000000,0x426b2e60,0x55512aa8,
    0x200bca88,0x2a219cb9,0x12aaaaaa,0x54035555,0x42aaa0aa,0x8aaa0aa8,
    0x0aaa0aa8,0x22035555,0x45550aaa,0x82aaaaa8,0xb5fffffe,0xfffb3fff,
    0x3ffffe63,0xfffffe82,0xffffff50,0x3ffff2df,0x7ffcc2ef,0x32bfff35,
    0x1fff35ff,0x7fcdbff2,0xfffff50f,0x2b3fff60,0xfff90fff,0x17ec1fff,
    0x50774bf7,0xd897d47f,0xfd897d46,0x39f35f51,0x54cfe4db,0x4c5f987d,
    0xdf1fdc5f,0xff14fb81,0x009fc881,0x06fdc7f2,0x88273e66,0x17a4d83f,
    0x2e1c45f1,0xe883f20f,0x6cfe3f50,0x2f983ee6,0x40fdc7d8,0x901fc8fd,
    0x2e03fd5f,0x647dc00f,0x5427c05f,0x445e801f,0x31bea02f,0x488159ff,
    0x3f71d4fe,0xf301fd73,0xef883745,0x17fec04f,0xfb801f70,0x84f805fe,
    0x45e800fb,0x1bff02f8,0x09fffb30,0xfffb81fc,0x4dba01ff,0x01bea02f,
    0xfb803fee,0x7fffdc00,0x7d427c01,0x7c45e802,0x30209d02,0x40fe03fb,
    0x01ffbbfb,0x201f67ee,0x7efd404f,0x7a83ee06,0x07f457dc,0x0bf109f0,
    0xf507ec51,0x44e80201,0x207f03f8,0x01fd10fb,0x2013f7e2,0x23be204f,
    0x41f705fa,0x443ee0fb,0x5c13e04f,0x26fcacff,0x04fcbef9,0x56ffc02a,
    0x7e5c0feb,0x33f661ce,0x3205df31,0x3f2e00ff,0xa7f4c1ce,0xb710cfe8,
    0x21fb999f,0x9f91cfd9,0x33bf3261,0xdfffea83,0x05fffd40,0xfbb05f98,
    0xffd05bff,0x7ffe47ff,0x7cc13ee3,0x7ffff405,0xfab7fe43,0xffff31ff,
    0x3f21ffff,0x25ff13ff,0x0efffffb,0x00300310,0x0004c002,0x00000000,
    0x00000000,0x00000000,0x00000000,0x00000000,0x00000000,0x1aa98000,
    0x2aa82aaa,0xaa983551,0x555500aa,0x2a215555,0x10aaaaaa,0x53035555,
    0x54455555,0x54402aaa,0x8aa601aa,0x0d4c2aa8,0x44110554,0xfff57fff,
    0x367ffe69,0x7fffc6ff,0x3fe21dff,0x92ffffff,0x7fffffff,0x3bfffff2,
    0x3ffffee1,0x3fffff67,0xffffb03f,0xfd97ffc0,0x83ffe1ff,0x83f64ffb,
    0x1f620afa,0x207e43f7,0x4fb99ed8,0x54ccefc4,0x2667f22f,0x267ba3fa,
    0x267ee6fb,0x4cfe45fb,0xff300fd9,0x3bfa205f,0xffa87f50,0x89f1ffa3,
    0xdb5f9af9,0x03ee0fb8,0xe81f71b6,0x5c1f1354,0x6c3f388f,0x17b9fd45,
    0x20fb81fd,0xd7f302fa,0x8a7ff40d,0xabffcc3f,0x103ea7ff,0xbd1ff97f,
    0xfdaabfb8,0x1fa26d80,0x5c13f3ba,0x5d80fdcf,0x0fec65f8,0x7fee67dc,
    0x3f71fb00,0x227f37a0,0x57e7cc3f,0x41327dfd,0x4fbfeecf,0x7fffffdc,
    0xffeefd80,0x04fffe82,0xb01ffff7,0x3fb8bd0b,0xdfffff70,0xf33bf101,
    0x3be37a09,0x74fcc3f9,0x02a7cbff,0x7f75ff7c,0x64ccfdc3,0xcdefd80f,
    0x413a9d01,0x4337a8fb,0x3ea4f85d,0x10fb8365,0xfff70df7,0x557a0fff,
    0x4fcc3fdf,0x007c8ffb,0x5ff71ffd,0x03ee0fb8,0x0a7401b6,0x5d843ee0,
    0x225f7176,0xfb8be26f,0x57743e40,0x5e82fbaa,0x3f30fff6,0x7b13e4f6,
    0x3fe6dfb0,0x2633f621,0x67f544fe,0x79df700c,0x999fb301,0x33fe6bf9,
    0x37f66fdc,0xfb32fdcc,0x44dfb999,0xdf712efc,0x445f7cc5,0x16fe43ff,
    0x1be65fd7,0x20fe8ff2,0xffc9fffb,0x3ffffa0f,0xffffe882,0xfffffb81,
    0xffff95ff,0xffffe89d,0xffff92ff,0x7fcc1bff,0x49fff35f,0x7f71fffc,
    0xf8afffc4,0x000025ff,0x00000000,0x00000000,0x00000000,0x00000000,
    0x073b2200,0x800c4000,0x22000008,0x44008801,0x40088001,0x19f30309,
    0x3602e800,0xb3002fef,0xefffda8b,0x1effeb82,0x7ff43ff2,0x37fff5c0,
    0x2077ffdc,0x905ffff9,0x49ffb9ff,0xfeffeff8,0x0fff622f,0x7f104f80,
    0x3ff62002,0x36efbe62,0x5d67e44f,0x21fb30ff,0x33e60fda,0x77dc7eba,
    0x3260ffcb,0xc983fbab,0x645ccfff,0x5ebffaef,0x802efe98,0x201be04f,
    0x640cffc8,0x56fc3e87,0x3ee3fcaa,0xdf983ee0,0x22fc299b,0xecca84f8,
    0x403df105,0x1f29f2f9,0x4c1dfea8,0x20aadfaa,0x40b8bff8,0x9f00dffb,
    0xfffff500,0x707dcbff,0xfffdb81f,0x9ba0be63,0x05fffffa,0x1f9807f1,
    0xd101f29f,0x3ffe65ff,0x3fa5ffff,0x3f64fcfe,0x0837c03f,0x266673e2,
    0xfb83ee09,0x7e4c4aa0,0x4f88bf11,0x105e877e,0xf1f9807f,0xffb81f29,
    0x67cccc0d,0xf17f1099,0x3bff50df,0x2eaf7ee0,0x5d67e46e,0x2b3e63dc,
    0x33fa3ffd,0x3f20fdba,0xf11ffcbd,0x87ffd75b,0x81ccdfcb,0xf91df4fc,
    0x01efea85,0xb5dd04f8,0x3fee03df,0xfffeb80c,0x7ff5c41d,0x7ffec2ef,
    0x3ffb26fe,0xfffc82df,0x77ff5c1e,0x7fff46ff,0x7ffc43ff,0x15fcaff8,
    0x7c005dfb,0xffffd504,0x1ffe4407,0x03100088,0x09880188,0x04c00880,
    0x98000000,0x02e8003e,0x36600044,0x00000005,0x00000000,0x00000000,
    0x00000000,0x00000000,0x00000000,0x00000000,0x00000000,0x80088000,
    0x072a9701,0xb53d8802,0x4bdddddd,0x4cccc40a,0x7ff40019,0x3a0bffa2,
    0xb8fff982,0x3fffa5ff,0xf72fffb8,0x261fffff,0x01dffeff,0x2efb09f1,
    0xb97f621f,0x3b6a9f11,0x265eeeee,0x3fffee2e,0x6fd4007f,0x80efaac8,
    0x8ffc883f,0x3faa2efb,0x2e19fd13,0x226feccf,0x05ebbffd,0x55c85ffd,
    0x77e7ec1f,0x000fe2fd,0x99988744,0xdf800199,0x323f8efa,0x40feefdf,
    0x980efefa,0x2911be3f,0x0fdc0dfa,0xdafd81f7,0x23cd2e1f,0xe87fd31b,
    0xdddddb52,0x000000bd,0x7e7fefec,0x3bfff621,0x403ffb03,0x2a05f77d,
    0x5c1f705f,0x744fee0f,0x001c530f,0xbbbb51c8,0x00009bbb,0x7effdc00,
    0x05ffd07f,0x40bfb3f6,0xf506ebf9,0xb83ee14b,0x0910ea0f,0x00000000,
    0x7c400000,0xfb85fc9f,0x3fa60fea,0x3609ff56,0xcffa82ff,0x9fb11fdc,
    0x5000ff62,0xdddddddb,0x000000bd,0xb7c00000,0x712984f9,0xfb8effb8,
    0x06fa80ef,0x3ffffff9,0x3e63ffea,0x76cc006f,0x5eeeeeee,0x00000000,
    0x00000000,0x00000000,0x00000000,0x00000000,0x00000000,
};

static signed short stb__courier_bold_18_usascii_x[95]={ 0,3,2,0,1,1,1,3,4,1,1,0,3,1,
3,1,1,1,0,1,1,1,1,1,1,1,3,3,-1,0,0,1,1,-1,0,0,0,0,0,0,0,1,0,0,
0,-1,-1,0,0,0,0,0,0,0,-1,-1,0,0,1,3,1,1,1,-1,3,0,-1,0,0,0,1,0,0,0,
1,0,1,-1,0,0,-1,0,0,1,1,0,0,-1,0,0,1,2,3,2,0, };
static signed short stb__courier_bold_18_usascii_y[95]={ 13,2,3,2,1,3,4,3,2,2,2,3,10,7,
11,1,2,2,2,2,2,2,2,2,2,2,5,5,3,6,3,3,2,3,3,3,3,3,3,3,3,3,3,3,
3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,2,1,2,2,16,2,5,2,5,2,5,2,5,2,2,
2,2,2,5,5,5,5,5,5,5,3,5,5,5,5,5,5,2,2,2,6, };
static unsigned short stb__courier_bold_18_usascii_w[95]={ 0,3,6,9,8,8,8,3,4,5,8,9,4,8,
3,8,8,8,9,8,8,8,8,8,8,8,3,4,10,10,10,8,7,11,10,9,9,9,10,10,10,8,10,10,
10,11,11,10,10,10,10,9,9,10,11,11,10,10,8,5,8,5,8,12,4,10,11,10,10,9,9,10,10,9,
7,10,8,11,10,9,11,10,10,8,9,10,10,11,10,10,8,5,3,5,9, };
static unsigned short stb__courier_bold_18_usascii_h[95]={ 0,12,5,13,14,11,10,5,14,14,8,10,6,3,
3,14,12,11,11,12,11,12,12,12,12,12,9,10,10,5,10,11,13,10,10,11,10,10,10,11,10,10,11,10,
10,10,10,11,10,13,10,11,10,11,10,10,10,10,10,14,14,14,6,2,4,9,12,9,12,9,11,12,11,11,
15,11,11,8,8,9,12,12,8,9,11,9,8,8,8,12,8,14,14,14,5, };
static unsigned short stb__courier_bold_18_usascii_s[95]={ 127,37,73,83,46,62,22,90,55,60,13,
12,122,110,122,66,19,90,71,28,81,1,52,10,93,84,124,121,31,94,1,
22,75,86,75,1,56,46,35,110,13,118,99,107,96,110,98,51,24,93,51,
31,41,11,62,1,85,74,66,40,25,34,64,73,105,93,72,42,102,53,1,
61,113,41,1,11,22,115,53,83,115,41,104,74,31,63,33,1,22,104,44,
19,15,9,80, };
static unsigned short stb__courier_bold_18_usascii_t[95]={ 1,17,76,1,1,30,65,76,1,1,76,
65,54,76,61,1,17,30,30,17,30,17,17,17,17,17,17,30,65,76,65,
42,1,54,54,42,54,54,54,30,54,42,30,42,42,54,54,30,54,1,42,
42,42,42,42,54,42,42,54,1,1,1,76,82,76,65,17,65,17,65,30,
17,17,30,1,30,30,65,76,65,1,17,65,65,30,65,76,76,76,1,76,
1,1,1,76, };
static unsigned short stb__courier_bold_18_usascii_a[95]={ 153,153,153,153,153,153,153,153,
153,153,153,153,153,153,153,153,153,153,153,153,153,153,153,153,
153,153,153,153,153,153,153,153,153,153,153,153,153,153,153,153,
153,153,153,153,153,153,153,153,153,153,153,153,153,153,153,153,
153,153,153,153,153,153,153,153,153,153,153,153,153,153,153,153,
153,153,153,153,153,153,153,153,153,153,153,153,153,153,153,153,
153,153,153,153,153,153,153, };

// Call this function with
//    font: NULL or array length
//    data: NULL or specified size
//    height: STB_FONT_courier_bold_18_usascii_BITMAP_HEIGHT or STB_FONT_courier_bold_18_usascii_BITMAP_HEIGHT_POW2
//    return value: spacing between lines
static void stb_font_courier_bold_18_usascii(stb_fontchar font[STB_FONT_courier_bold_18_usascii_NUM_CHARS],
                unsigned char data[STB_FONT_courier_bold_18_usascii_BITMAP_HEIGHT][STB_FONT_courier_bold_18_usascii_BITMAP_WIDTH],
                int height)
{
    int i,j;
    if (data != 0) {
        unsigned int *bits = stb__courier_bold_18_usascii_pixels;
        unsigned int bitpack = *bits++, numbits = 32;
        for (i=0; i < STB_FONT_courier_bold_18_usascii_BITMAP_WIDTH*height; ++i)
            data[0][i] = 0;  // zero entire bitmap
        for (j=1; j < STB_FONT_courier_bold_18_usascii_BITMAP_HEIGHT-1; ++j) {
            for (i=1; i < STB_FONT_courier_bold_18_usascii_BITMAP_WIDTH-1; ++i) {
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
        float recip_width = 1.0f / STB_FONT_courier_bold_18_usascii_BITMAP_WIDTH;
        float recip_height = 1.0f / height;
        for (i=0; i < STB_FONT_courier_bold_18_usascii_NUM_CHARS; ++i) {
            // pad characters so they bilerp from empty space around each character
            font[i].s0 = (stb__courier_bold_18_usascii_s[i]) * recip_width;
            font[i].t0 = (stb__courier_bold_18_usascii_t[i]) * recip_height;
            font[i].s1 = (stb__courier_bold_18_usascii_s[i] + stb__courier_bold_18_usascii_w[i]) * recip_width;
            font[i].t1 = (stb__courier_bold_18_usascii_t[i] + stb__courier_bold_18_usascii_h[i]) * recip_height;
            font[i].x0 = stb__courier_bold_18_usascii_x[i];
            font[i].y0 = stb__courier_bold_18_usascii_y[i];
            font[i].x1 = stb__courier_bold_18_usascii_x[i] + stb__courier_bold_18_usascii_w[i];
            font[i].y1 = stb__courier_bold_18_usascii_y[i] + stb__courier_bold_18_usascii_h[i];
            font[i].advance_int = (stb__courier_bold_18_usascii_a[i]+8)>>4;
            font[i].s0f = (stb__courier_bold_18_usascii_s[i] - 0.5f) * recip_width;
            font[i].t0f = (stb__courier_bold_18_usascii_t[i] - 0.5f) * recip_height;
            font[i].s1f = (stb__courier_bold_18_usascii_s[i] + stb__courier_bold_18_usascii_w[i] + 0.5f) * recip_width;
            font[i].t1f = (stb__courier_bold_18_usascii_t[i] + stb__courier_bold_18_usascii_h[i] + 0.5f) * recip_height;
            font[i].x0f = stb__courier_bold_18_usascii_x[i] - 0.5f;
            font[i].y0f = stb__courier_bold_18_usascii_y[i] - 0.5f;
            font[i].x1f = stb__courier_bold_18_usascii_x[i] + stb__courier_bold_18_usascii_w[i] + 0.5f;
            font[i].y1f = stb__courier_bold_18_usascii_y[i] + stb__courier_bold_18_usascii_h[i] + 0.5f;
            font[i].advance = stb__courier_bold_18_usascii_a[i]/16.0f;
        }
    }
}

#ifndef STB_SOMEFONT_CREATE
#define STB_SOMEFONT_CREATE              stb_font_courier_bold_18_usascii
#define STB_SOMEFONT_BITMAP_WIDTH        STB_FONT_courier_bold_18_usascii_BITMAP_WIDTH
#define STB_SOMEFONT_BITMAP_HEIGHT       STB_FONT_courier_bold_18_usascii_BITMAP_HEIGHT
#define STB_SOMEFONT_BITMAP_HEIGHT_POW2  STB_FONT_courier_bold_18_usascii_BITMAP_HEIGHT_POW2
#define STB_SOMEFONT_FIRST_CHAR          STB_FONT_courier_bold_18_usascii_FIRST_CHAR
#define STB_SOMEFONT_NUM_CHARS           STB_FONT_courier_bold_18_usascii_NUM_CHARS
#define STB_SOMEFONT_LINE_SPACING        STB_FONT_courier_bold_18_usascii_LINE_SPACING
#endif

