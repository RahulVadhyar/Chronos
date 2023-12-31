// Font generated by stb_font_inl_generator.c (4/1 bpp)
//
// Following instructions show how to use the only included font, whatever it is, in
// a generic way so you can replace it with any other font by changing the include.
// To use multiple fonts, replace STB_SOMEFONT_* below with STB_FONT_consolas_bold_17_usascii_*,
// and separately install each font. Note that the CREATE function call has a
// totally different name; it's just 'stb_font_consolas_bold_17_usascii'.
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

#define STB_FONT_consolas_bold_17_usascii_BITMAP_WIDTH         128
#define STB_FONT_consolas_bold_17_usascii_BITMAP_HEIGHT         96
#define STB_FONT_consolas_bold_17_usascii_BITMAP_HEIGHT_POW2   128

#define STB_FONT_consolas_bold_17_usascii_FIRST_CHAR            32
#define STB_FONT_consolas_bold_17_usascii_NUM_CHARS             95

#define STB_FONT_consolas_bold_17_usascii_LINE_SPACING          11

static unsigned int stb__consolas_bold_17_usascii_pixels[]={
    0x20004591,0x00266620,0x4ccc4001,0x0c880040,0x9db50000,0x0001db01,
    0xea8001d9,0x29f39b34,0xfb803df9,0x50dfff71,0x8ff407fd,0x1763fffe,
    0xd9807cc0,0xdf700cef,0x3fb81ff9,0x4437c400,0x2adf706d,0xd714f9df,
    0x877dc05f,0x7c42acfb,0x5ff101cf,0xfc8ff2aa,0x37fb2604,0x7ff7fd43,
    0x3e24f986,0x20037c44,0x06f982fc,0x273eabf5,0x9827c44f,0x40bee1ff,
    0x83a802fb,0x41ff43fa,0x25fffffc,0x7fd31ff8,0xc87d86e8,0x31fe002f,
    0x4555df75,0xf39f35fa,0x3f60df09,0xfb817dc2,0xaaaaa981,0x3e21fd40,
    0x367fe20f,0x2e2fd415,0x366fe66f,0x7cc0fbed,0xb89f5005,0x0fffffff,
    0x266a2bf5,0xf887e84f,0xf902fb87,0xfffffb03,0xfb83fa85,0x13a7fe22,
    0x4ff50fee,0xafeef9fb,0x800fd81f,0x7d4c40fe,0x13ea199e,0x03f613e6,
    0x05f70bf7,0x266207f6,0x1fd42fd9,0x3ffa27d4,0x443fc84f,0x27ebf67f,
    0xfa81faed,0x302fcc04,0x213e60df,0x4efa84f9,0x0bee0ff2,0x3600bf97,
    0x441fd42f,0x7ffec46f,0xf113ee2f,0x747e774f,0x0fd00fbe,0x3e601fc8,
    0xf309f306,0x21ffb109,0x42fb81fd,0xfb001ffd,0xfd03fa85,0x47fffea0,
    0xd2fd46f9,0x3ef7ef9b,0x2207f700,0x837cc06f,0x84f982c8,0x41fdc2fd,
    0x07f982fb,0x3fa85fb0,0x75ee0ff0,0x6c5ff13f,0x27f37a3f,0x3e206dcf,
    0x9807f706,0x2602a07f,0xf987e84f,0xf902fb85,0xa85fb003,0x226f983f,
    0xc8bfad90,0x6c6fedff,0x3ffeffae,0x3fc0fe40,0x24adff80,0x84f986fb,
    0xf70df06e,0x2007f205,0x41fd42fd,0x3fbe64fb,0xffa86fff,0x3bbec0df,
    0x8bf30057,0xff5004fa,0x217ea1ff,0xd06e84f9,0x702fb85f,0x85fb003f,
    0x20fe83fa,0x0beffed8,0x3ea0bf30,0x83fa0002,0x0c4000fe,0xf84f9804,
    0x5c1ff306,0x005f502f,0x43fa83ff,0x05f104fc,0x8dbbff10,0x001711ff,
    0x02744baa,0x27cc0000,0x7d409f93,0x2026fee6,0x26720aef,0x3ee626fc,
    0x4c03bee3,0xffd3001f,0x7fffcc1b,0x0000000f,0x34f98000,0xfb801dff,
    0x70dfff71,0x7fffc7fd,0x8ffffa1f,0x800000ee,0x02aaa200,0x00000000,
    0x01327cc0,0x133310c0,0x55530440,0x44133310,0x00000000,0x00000000,
    0x006a2000,0x00000000,0x00000000,0x00000000,0x00000000,0x00000000,
    0x00000000,0x00000000,0x2ea00000,0x2a550bac,0x540d4c2c,0x01db0002,
    0x00000000,0x4aaaf2a2,0x20001bcb,0x036a0bec,0x3fa21d90,0xbfd1ffff,
    0x2fdcbfff,0x3faa1bea,0x007f40ce,0x98277ecc,0x3ffaa05f,0x7f7fc43e,
    0xbfff96ff,0x43effea8,0x7f13fbfb,0x3f63fd00,0x3fa3fd0c,0xf12fe9af,
    0x2e17ec1f,0x746ffeff,0x6ffd400f,0x07fb86fe,0x89dddff7,0x44bf52fc,
    0x3b24ffb9,0x5b23ffdd,0x3a00db5d,0x7f47f89f,0x27dc5fd1,0x11fe27f9,
    0x8ffa63ff,0xe82ca8fe,0x2e0bfa1f,0xd803ff02,0x7d41be0f,0xfb9bea06,
    0x201face9,0xf99fecba,0x0fe8ff46,0x56f997ea,0x5c5fa89f,0x3ff7fa6f,
    0xd897e65f,0x0555534f,0x9f700ffe,0x3ea09f93,0xe893ea06,0xd104f9ef,
    0xf33fffff,0x1fd1fe8d,0x27fa27dc,0x21fdc1fd,0x2bffa7fa,0x29f52fe9,
    0xff75ffe9,0x3bff60ff,0xbffff502,0x43feba81,0x081efba9,0x867ec0db,
    0x2a7f89fe,0x741fd1ff,0x37efdc2f,0x9fe21fe4,0x5d3ee2fe,0x6faffbbf,
    0x220ff331,0x742ffffc,0x1fffc036,0x80efffdc,0x8ff101fa,0xfbbfd1fe,
    0x2f3fa3ff,0xfff886fd,0x7c44fc83,0x5fa83fa6,0xf31bfff7,0x4407f88b,
    0x3fa0fffb,0x3f40bccd,0x1ff93310,0x1deacf88,0x23fd1be6,0x1fdcffe8,
    0x019ffffd,0x3ee03ff2,0x1fd2fd46,0x3ffaa7dc,0x0ff113ea,0xfb8bfe20,
    0x2e2fffff,0xb0bf6004,0x4cbd9f3d,0x220ff46f,0x27fa3fd0,0x303fd800,
    0xd1fec3ff,0xf897f41f,0xf10bf60f,0x47fa020f,0x32fdc6f8,0x50ff4005,
    0x4f71f53f,0x07fea7f8,0x01fd1fe8,0x2037e4c4,0x46fedffd,0x46fdbcfe,
    0x86fdbefc,0xcef887f8,0x3be66fec,0x7fc4ff20,0xfecccc82,0x57c53a26,
    0x7eeff46d,0x47fa01ff,0x3fee00fe,0xfffc800e,0x7fffe40d,0x4fffc80c,
    0x667fe65c,0x9ffffd11,0xfffffd81,0x3a07fe25,0x320cffff,0x10bff20f,
    0x03f99ffd,0x980310c4,0x0008001a,0x7ec02001,0x442fffff,0x5554c009,
    0x06600880,0x01100200,0x00000000,0x00000000,0x00000000,0x00000000,
    0x00005971,0x3bb66000,0x9ddddd53,0xd93b7260,0x3bbaa00e,0xb70002ee,
    0x07b23dff,0x00bddd50,0xbffff300,0x77ff6440,0x0efff5c2,0x74eeff98,
    0x90bfffff,0x7f49dfff,0x3bbbaa00,0x0fbfae3f,0x97f77ff4,0x775401fd,
    0x3bfae07f,0x3fa3fb03,0xeefff980,0x373bee4f,0x705fb07f,0x1efa805f,
    0x64001fd0,0xffdffb3f,0x220efb89,0x22003fb0,0xfbff907f,0x7ecfd09f,
    0x0c45fd80,0x40fec1fd,0x02fb80fe,0x1fd00ff4,0x3fc80595,0x3e37d471,
    0xa87f602f,0x887f881a,0x81ff10ff,0x985fcbfc,0x97f400ff,0xd3310ff8,
    0x3ee1335f,0xbff81cde,0x37fa0cdd,0x3f205fff,0x7c4ff103,0xfc8fec07,
    0xa87f880e,0x220fec5f,0xbf504fff,0xff304ccc,0x7fd45fdb,0xf73fffff,
    0x7c49ffff,0xd0ffffff,0x01ff35ff,0x2fd40ff2,0x9fd80ff3,0xff100efa,
    0x7ec1ff30,0x447ffdc2,0x7cd3f22c,0x7ffdc4ff,0x3feaa20e,0xfb880aab,
    0x6c3ff10f,0x7f45fd3f,0xf107f901,0x203fcc3f,0x200ffbfd,0xdffd07f8,
    0x6fd45fff,0x2e3faefb,0x49f9514f,0x06febefa,0x3fe001fd,0x29f71fe1,
    0x407fa0fe,0x1ff443fc,0xfd807fe2,0x3fc403ff,0xfedeec88,0x7fe4bf22,
    0xf71bea2f,0x5fd07fc9,0xf3001fd0,0xf917f41f,0x1fe83fa7,0x3a22fe81,
    0x81bfb03f,0x03ff7fb0,0xff003fc4,0xffd17e41,0x3ee3ff88,0x2fc8ff14,
    0xccb80fe8,0x7fd44ffd,0x1fd0ffdc,0xdcec8ff4,0x07fd10ff,0x7f6fffcc,
    0x1df73fb2,0x6401fe20,0x5dffd45f,0x7fdc2ffe,0x3fa4fece,0xe80ffbbd,
    0xefffd80f,0x3dfff703,0x23fd07f4,0x3a1efffa,0x42eeeeff,0xb1efffd8,
    0x9717f63f,0x64399ff9,0xb80effee,0x1ffbefff,0x177fff54,0x03dfffb1,
    0x00c403fa,0xe83fa010,0xfff8041f,0x0203ffff,0x27f447f6,0x5ffffffb,
    0x005f7fec,0x00300022,0x00000013,0x00000000,0x00000000,0x00000000,
    0x00000000,0x00000000,0x00000000,0x261b8800,0xe99f544e,0x94eeeeee,
    0x76cd701d,0x176c2dee,0x45ea876c,0x8bba23eb,0x43dd13e8,0x409d32ee,
    0xd8bb60ed,0x7643deee,0x6c0eeeee,0xf517e67f,0x3ffbba69,0xb01f94ee,
    0x7fff7fcf,0xff317f24,0x3ff12ff8,0x9f337fcc,0x7fd53fe2,0x7fc0bf53,
    0xefe8df70,0x3bb26ffe,0x7e40eeff,0x9f517e67,0x1f90bf50,0xa87fcfb0,
    0xf71fe67f,0x9f96fa89,0xf32fff98,0x7e5ffe69,0x7c0bf53f,0x741ff88f,
    0xa85fd10f,0xf30d405f,0xfa84fa8b,0x2390fb85,0xff83fe6d,0x2fd87fe0,
    0x40ffbfe8,0x9f36fef9,0x33e7f3e6,0x7c0bf54f,0xfe83fd8f,0xbf513ee0,
    0x545f9800,0xb85fa84f,0x4dd5f99f,0x46fc98ff,0x20ff13fd,0xf984fffa,
    0x34f99fdc,0x9f3fbf5f,0xcff817ea,0x641fd05f,0x002fd43f,0x09f517e6,
    0x73f70bf5,0xfff97aff,0xb7d40cff,0x3ffe05fa,0xdfacf980,0xfb3f54f9,
    0x02fd57ed,0x3a05ffff,0x40ffb9af,0x97ea05fa,0x427d45f9,0xe9fa85fa,
    0x3fe5e9fe,0xff884fec,0xff502fc8,0x3a9f309f,0x73f54faf,0x2fd57e9f,
    0x01df7ff0,0x05fffffd,0x7fec0bf5,0x3fb8bf31,0xbfa85fa8,0x3e5fcfaf,
    0xd81ff88f,0xfd00feaf,0x4f983ff7,0x3ee9fdf7,0x2abf1e89,0x363fe05f,
    0xabdfe84f,0x440bf500,0xc8ff11ff,0x985fa82f,0x49fdb7ef,0x70bf90ff,
    0x3ee0dfdf,0x4f98df96,0x07dd3ffe,0x205fab74,0x42ff88ff,0x5fa800fe,
    0xdfb07f40,0x3ea0dfb9,0xf54ff985,0xf887fc9f,0x1fffc41f,0xff88ffc4,
    0xffb93e62,0x2dd01f74,0x1eeeeffa,0x83fee1ff,0x372e00fe,0x7ed44cef,
    0x6fffec43,0xf10bf500,0xf8ffe25f,0x3a17f60f,0x45fc81ff,0x893e66fc,
    0xd01f94ff,0x3ffffeaf,0x7f41ff1f,0xfd803fa5,0xd10fffff,0x0001803b,
    0x00000000,0x00000000,0x00000000,0x00000000,0x00000000,0x00000000,
    0x00000000,0x1f544e88,0x5ddddddb,0x4bd10fae,0x26eeeeea,0x41cdeee9,
    0xb5eeeeea,0x20159ddd,0x7dc00eed,0x7777440f,0x87542eee,0x7640004d,
    0xfb8df31e,0x3fffffe4,0xfc8ff32f,0x3bbbfee4,0x3ffbfe66,0x3bbfee4f,
    0xffddff5e,0x07fff109,0x103fffaa,0x5fffffff,0xd89f0fb8,0x5fff3005,
    0x09f71be6,0x4ff637dc,0x13ee0ff8,0x3fea5f98,0x3fe09f71,0xfb81ff10,
    0xf7fd05fd,0x5333301f,0x4fecc1ff,0xdfb11cf9,0x2fdfe801,0x04fb8df3,
    0x6f983ff1,0x04fb87f9,0x29f917e6,0x41ff04fb,0x7cfec0fe,0x1ff0980f,
    0x7cc9f900,0x47ffffff,0x7f701ffc,0x2bbe65f9,0xfd04fdaa,0x3feff609,
    0x5556fdc0,0xbf517e62,0x426677ee,0x84fdabff,0xf805fb7f,0x07fc400f,
    0x2fee7ba6,0x442ffb81,0x3e65f96f,0x84ffffff,0x3fe606fb,0xffffb83f,
    0xf517e66f,0x3ffffeed,0x5ffffff5,0x09f74fa8,0x7e400ff8,0x07eabf05,
    0x3f61ffc8,0x3be65f91,0x444fc999,0x7fec01ff,0x999dfb80,0xbf717e60,
    0x4b333bee,0x2ffb99ff,0x03fccbf2,0xff8803fe,0x6d6fd4c1,0x2ffb81bf,
    0x32fc93ea,0x744fb8df,0x05fa804f,0x2fcc09f7,0x827dd3fa,0xe93f20ff,
    0x01ffeeef,0x5fb803fe,0xffffffc8,0x20f7e44f,0xfffffffc,0x27dc6f9f,
    0x3ea00df7,0x4c09f704,0x21ff715f,0x41ff04fb,0xddff32fd,0x7fc07fdd,
    0x2207fe00,0x09fd9bfa,0xd701dfd1,0x3bdffddd,0xf14fb8df,0x05dddddf,
    0x3fee09f5,0x3fe66eee,0x3ee3fffe,0xfd99ff04,0x3ea1fdcd,0x77ff7646,
    0x502fdc2e,0x1761b63f,0x3e65f900,0xff8a7dc6,0xa83fffff,0xffff704f,
    0x77ffccff,0xf827dc1d,0x360bdfff,0xb07fc41f,0x87ffffff,0x43ee01ff,
    0xf900005e,0x00000005,0x00000000,0x00000000,0x00000000,0x54155000,
    0x9503710a,0x79750379,0x0af2a203,0xca806f2a,0x20b2201b,0x3154c2a8,
    0x4c179315,0x4c572c8a,0x8002a81a,0x741fd1fa,0x7c4ffb0f,0x7dc3ffff,
    0x7d44ffff,0x3fa67fff,0xffd84fff,0x09f303ff,0x21fe8ffa,0x0ffffdfb,
    0xff9ffbf7,0xdf517ee7,0xff902fdc,0x0fe83fa3,0x127e4ff9,0x9fe61981,
    0x2399bff9,0x1ffb9cfe,0x07f453ee,0xff9827cc,0x7fdc4fc9,0xbf73fd8c,
    0x22bf1ff3,0xe8bf60ff,0x0efd80ff,0x20fe83fa,0x00bbf21a,0xfc87f4c4,
    0xfd8df304,0x36667fe4,0xbf95512f,0xfefb8355,0x3aa5fb86,0x29f15f73,
    0x7c4ff26e,0x3a237e47,0x3a0fe85f,0x3ffa200f,0x7fe440cf,0x05fd0fff,
    0x2bf717ea,0xfffffff8,0xffffff53,0x03ffb0bf,0x4fdc09f7,0x7ccdd3f8,
    0xd0109f56,0xe83fa0df,0xffda800f,0x74d6fec6,0x2605fb0f,0xf8a7dc6f,
    0x1099999f,0x355bf955,0xb84fff88,0x227ee04f,0x9fe8dd3f,0xfd1001fd,
    0xf51fe81b,0x980f661f,0xf887fc7f,0x220df90f,0xe8bf61ff,0x09f3001f,
    0x20ffdff4,0x27ee04fb,0xfb8dd3f8,0xfd8006fd,0x3f7bf20e,0x21ffb0ff,
    0x46fdaacc,0x0ffebdff,0x4db9dff1,0x46fedffd,0x05bacffa,0x57f209f3,
    0x13ee0ffb,0xd3f89fb8,0x03fff88d,0x223ff700,0x70fccffe,0x7fffe4df,
    0x67ffd40d,0x3ff660fc,0x3fff226f,0xffffb80d,0xf5059106,0xf72fec1f,
    0x7c4fdc09,0x1ff90dd3,0x20f54000,0x26202008,0x10009801,0x13100180,
    0x00000000,0x00000000,0x00000000,0x00000000,0x00000000,0x00000000,
    0x00000000,0x00000000,0x00000000,0x2a800000,0x54aa1530,0x55554c2c,
    0x002e882a,0xaec0faa0,0xffffd1db,0x015443ff,0x5555136e,0x26666615,
    0x00001999,0x1f901fd0,0x97fff7fa,0x27fffffc,0x828af898,0x3fdd04fb,
    0x64bf2ff0,0x10cccccc,0x1761dffd,0x7fff4bf9,0xffffff1f,0x00003fff,
    0x6c263f90,0x3e6bffa7,0xff55530f,0x7e7dfe49,0x5c0ffd87,0x96f85e8f,
    0x5fd4003f,0x985fbefc,0x1555551b,0x2aaaaaaa,0x800000aa,0xdd5f9afb,
    0x03fd17f4,0xffd50df9,0x41ff3019,0xe85f53f8,0x37723f76,0x1b50dddd,
    0x0007ffee,0x00000000,0xfbfe5fd4,0x1fe83fa5,0x36607fd4,0xff02efff,
    0x507ec6c8,0x7ff42a65,0x2201ffff,0x00000009,0x3e600000,0x24fbfeec,
    0x887fa0fe,0xf9eb82ff,0x3f6e26db,0x06e20dc2,0x00000000,0x00000000,
    0x3ebfbe20,0xe83fa3fe,0x8813fa1f,0x674c13f8,0x00000001,0x00000000,
    0xff000000,0xfe8bff6f,0x7fe47fa0,0x1a80eeee,0x00000000,0x00000000,
    0xd0000000,0xe83feabf,0x7ec7fa0f,0x000fffff,0x00000000,0x00000000,
    0x00000000,0x00000000,0x00000000,0x00000000,0x00000000,
};

static signed short stb__consolas_bold_17_usascii_x[95]={ 0,3,1,0,0,0,0,3,2,1,1,0,1,2,
3,0,0,0,1,1,0,1,0,0,0,0,3,1,0,1,1,2,0,0,1,0,0,1,1,0,0,1,1,1,
1,0,0,0,1,0,1,0,0,0,0,0,0,0,0,2,0,2,0,0,0,0,1,1,0,0,0,0,1,1,
0,1,1,0,1,0,1,0,1,1,0,1,0,0,0,0,1,1,3,1,0, };
static signed short stb__consolas_bold_17_usascii_y[95]={ 12,0,0,1,-1,0,0,0,-1,-1,0,3,8,6,
8,0,0,1,0,0,1,1,1,1,0,0,3,3,2,5,2,0,0,1,1,1,1,1,1,0,1,1,1,1,
1,1,1,0,1,0,1,0,1,1,1,1,1,1,1,-1,0,-1,1,13,0,3,0,3,0,3,0,3,0,-1,
-1,0,0,3,3,3,3,3,3,3,0,3,3,3,3,3,3,-1,-2,-1,5, };
static unsigned short stb__consolas_bold_17_usascii_w[95]={ 0,3,7,9,9,10,10,3,6,7,8,9,6,6,
4,9,9,9,8,8,9,8,9,9,9,9,4,6,8,8,8,7,10,10,8,9,9,8,7,9,9,8,7,9,
8,9,9,10,8,10,8,9,9,9,10,10,10,10,9,5,9,5,9,10,6,9,8,7,9,9,9,9,8,8,
8,9,8,9,8,9,8,9,8,8,9,8,10,10,10,10,8,7,3,8,9, };
static unsigned short stb__consolas_bold_17_usascii_h[95]={ 0,13,5,11,16,13,13,5,17,17,8,9,7,3,
5,14,13,11,12,13,11,12,12,11,13,12,10,12,11,5,11,13,16,11,11,12,11,11,11,13,11,11,12,11,
11,11,11,13,11,16,11,13,11,12,11,11,11,11,11,17,14,17,6,3,4,10,13,10,13,10,12,13,12,13,
17,12,12,9,9,10,13,13,9,10,13,10,9,9,9,13,9,17,18,17,5, };
static unsigned short stb__consolas_bold_17_usascii_s[95]={ 124,120,56,99,58,107,1,124,14,50,30,
71,39,90,122,100,51,79,78,98,118,42,51,89,22,116,19,1,1,64,109,
90,79,68,59,87,41,32,51,12,1,118,70,99,90,80,70,31,109,68,39,
70,18,8,48,28,59,21,11,21,90,44,46,97,83,33,42,43,118,61,32,
80,61,61,35,97,107,101,12,51,11,1,92,24,110,10,111,1,81,20,21,
27,1,5,73, };
static unsigned short stb__consolas_bold_17_usascii_t[95]={ 7,1,85,61,1,20,34,1,1,1,85,
73,85,85,73,1,20,61,34,20,61,34,34,61,34,34,73,48,73,85,61,
20,1,61,61,34,61,61,61,34,61,48,34,48,48,48,48,20,48,1,48,
20,48,48,48,48,48,61,61,1,1,1,85,85,85,73,20,73,20,73,34,
20,34,20,1,34,34,73,85,73,20,20,73,73,1,73,73,85,73,20,85,
1,1,1,85, };
static unsigned short stb__consolas_bold_17_usascii_a[95]={ 150,150,150,150,150,150,150,150,
150,150,150,150,150,150,150,150,150,150,150,150,150,150,150,150,
150,150,150,150,150,150,150,150,150,150,150,150,150,150,150,150,
150,150,150,150,150,150,150,150,150,150,150,150,150,150,150,150,
150,150,150,150,150,150,150,150,150,150,150,150,150,150,150,150,
150,150,150,150,150,150,150,150,150,150,150,150,150,150,150,150,
150,150,150,150,150,150,150, };

// Call this function with
//    font: NULL or array length
//    data: NULL or specified size
//    height: STB_FONT_consolas_bold_17_usascii_BITMAP_HEIGHT or STB_FONT_consolas_bold_17_usascii_BITMAP_HEIGHT_POW2
//    return value: spacing between lines
static void stb_font_consolas_bold_17_usascii(stb_fontchar font[STB_FONT_consolas_bold_17_usascii_NUM_CHARS],
                unsigned char data[STB_FONT_consolas_bold_17_usascii_BITMAP_HEIGHT][STB_FONT_consolas_bold_17_usascii_BITMAP_WIDTH],
                int height)
{
    int i,j;
    if (data != 0) {
        unsigned int *bits = stb__consolas_bold_17_usascii_pixels;
        unsigned int bitpack = *bits++, numbits = 32;
        for (i=0; i < STB_FONT_consolas_bold_17_usascii_BITMAP_WIDTH*height; ++i)
            data[0][i] = 0;  // zero entire bitmap
        for (j=1; j < STB_FONT_consolas_bold_17_usascii_BITMAP_HEIGHT-1; ++j) {
            for (i=1; i < STB_FONT_consolas_bold_17_usascii_BITMAP_WIDTH-1; ++i) {
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
        float recip_width = 1.0f / STB_FONT_consolas_bold_17_usascii_BITMAP_WIDTH;
        float recip_height = 1.0f / height;
        for (i=0; i < STB_FONT_consolas_bold_17_usascii_NUM_CHARS; ++i) {
            // pad characters so they bilerp from empty space around each character
            font[i].s0 = (stb__consolas_bold_17_usascii_s[i]) * recip_width;
            font[i].t0 = (stb__consolas_bold_17_usascii_t[i]) * recip_height;
            font[i].s1 = (stb__consolas_bold_17_usascii_s[i] + stb__consolas_bold_17_usascii_w[i]) * recip_width;
            font[i].t1 = (stb__consolas_bold_17_usascii_t[i] + stb__consolas_bold_17_usascii_h[i]) * recip_height;
            font[i].x0 = stb__consolas_bold_17_usascii_x[i];
            font[i].y0 = stb__consolas_bold_17_usascii_y[i];
            font[i].x1 = stb__consolas_bold_17_usascii_x[i] + stb__consolas_bold_17_usascii_w[i];
            font[i].y1 = stb__consolas_bold_17_usascii_y[i] + stb__consolas_bold_17_usascii_h[i];
            font[i].advance_int = (stb__consolas_bold_17_usascii_a[i]+8)>>4;
            font[i].s0f = (stb__consolas_bold_17_usascii_s[i] - 0.5f) * recip_width;
            font[i].t0f = (stb__consolas_bold_17_usascii_t[i] - 0.5f) * recip_height;
            font[i].s1f = (stb__consolas_bold_17_usascii_s[i] + stb__consolas_bold_17_usascii_w[i] + 0.5f) * recip_width;
            font[i].t1f = (stb__consolas_bold_17_usascii_t[i] + stb__consolas_bold_17_usascii_h[i] + 0.5f) * recip_height;
            font[i].x0f = stb__consolas_bold_17_usascii_x[i] - 0.5f;
            font[i].y0f = stb__consolas_bold_17_usascii_y[i] - 0.5f;
            font[i].x1f = stb__consolas_bold_17_usascii_x[i] + stb__consolas_bold_17_usascii_w[i] + 0.5f;
            font[i].y1f = stb__consolas_bold_17_usascii_y[i] + stb__consolas_bold_17_usascii_h[i] + 0.5f;
            font[i].advance = stb__consolas_bold_17_usascii_a[i]/16.0f;
        }
    }
}

#ifndef STB_SOMEFONT_CREATE
#define STB_SOMEFONT_CREATE              stb_font_consolas_bold_17_usascii
#define STB_SOMEFONT_BITMAP_WIDTH        STB_FONT_consolas_bold_17_usascii_BITMAP_WIDTH
#define STB_SOMEFONT_BITMAP_HEIGHT       STB_FONT_consolas_bold_17_usascii_BITMAP_HEIGHT
#define STB_SOMEFONT_BITMAP_HEIGHT_POW2  STB_FONT_consolas_bold_17_usascii_BITMAP_HEIGHT_POW2
#define STB_SOMEFONT_FIRST_CHAR          STB_FONT_consolas_bold_17_usascii_FIRST_CHAR
#define STB_SOMEFONT_NUM_CHARS           STB_FONT_consolas_bold_17_usascii_NUM_CHARS
#define STB_SOMEFONT_LINE_SPACING        STB_FONT_consolas_bold_17_usascii_LINE_SPACING
#endif
