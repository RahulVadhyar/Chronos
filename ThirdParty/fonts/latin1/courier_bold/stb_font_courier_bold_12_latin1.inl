// Font generated by stb_font_inl_generator.c (4/1 bpp)
//
// Following instructions show how to use the only included font, whatever it is, in
// a generic way so you can replace it with any other font by changing the include.
// To use multiple fonts, replace STB_SOMEFONT_* below with STB_FONT_courier_bold_12_latin1_*,
// and separately install each font. Note that the CREATE function call has a
// totally different name; it's just 'stb_font_courier_bold_12_latin1'.
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

#define STB_FONT_courier_bold_12_latin1_BITMAP_WIDTH         256
#define STB_FONT_courier_bold_12_latin1_BITMAP_HEIGHT         52
#define STB_FONT_courier_bold_12_latin1_BITMAP_HEIGHT_POW2    64

#define STB_FONT_courier_bold_12_latin1_FIRST_CHAR            32
#define STB_FONT_courier_bold_12_latin1_NUM_CHARS            224

#define STB_FONT_courier_bold_12_latin1_LINE_SPACING           6

static unsigned int stb__courier_bold_12_latin1_pixels[]={
    0x20a66a00,0x9801405c,0x00100a80,0x1100b83d,0x2a014402,0x01c05100,
    0x00084404,0x4c000000,0x0005108a,0x00842ca8,0x06403801,0x00000054,
    0x91264c02,0x8980d881,0x7c06a818,0x15c2e801,0x2a04dca8,0x8a982c40,
    0x704bc984,0x412f2607,0x307ae059,0x01b10915,0x00d88254,0xdf9db0b1,
    0x360b116a,0x23e2e440,0x25404c86,0x1dbc86a8,0x01640b10,0x1ea859bb,
    0x2a02a264,0x74c4c8ac,0x404b84ec,0x22018869,0x88799902,0x19889881,
    0x88988188,0x26226219,0x06622621,0x1883fbd7,0x03300a20,0x2a054015,
    0x2e2d5665,0x4b507100,0x03a859f8,0x41740266,0x002a0099,0x540ccc07,
    0x15954a85,0x4e8fcc99,0x22ed67cc,0x90b600f8,0xdfc83dbf,0x935d541e,
    0x67e43dbf,0x37f20eea,0x3ab3f21e,0xdd59f90e,0x3bab3f21,0x3f20cba0,
    0x6552e1ed,0x971ee4c1,0x7b93072a,0x265a81e4,0x1ee4c3dc,0x2fefd96a,
    0x3620b76e,0x440f80ff,0xddb80ffd,0x882ddb82,0x42d40ffd,0x13a3f35a,
    0x7981f179,0x4c1321e2,0x4c972cc6,0x9b4412e5,0x2e6992e5,0x264b9664,
    0x2e6992e6,0x4c4b9a64,0x4b9664fe,0x88b623e6,0x1f33eabf,0x55fc45b1,
    0x56a0793e,0xf13eaaf8,0x52d47d55,0x4d541b7d,0x43df880f,0x07bf1078,
    0xaa81f355,0x3df880f9,0xc97cc2d4,0x6fc40f8b,0x4c9cf983,0x43d80f88,
    0x22c9e22c,0x8b2d1078,0x24b9a678,0x2699e22c,0x24b9a64b,0x22512e69,
    0x23c4592d,0x325c590f,0x2e2c87cd,0x88f4da64,0x3bbaeb53,0xbdddd75e,
    0xeded8ad4,0x203fff20,0x80f869cb,0xffc869cb,0x07ffe40f,0x16a34e5c,
    0x03df896a,0xbbd301f9,0xf10f2017,0x77344770,0x77688344,0x25cd3344,
    0x4d334477,0x24b9a64b,0xbf892e69,0x344771eb,0xea8b623e,0x6c47cb90,
    0x72e43aa2,0x4d6a7fff,0x3d31999e,0xd8ad4333,0x11b50dee,0x3fddd01f,
    0xfeee83d8,0x83e236a1,0xe80f88da,0x216a1fee,0xd807e44a,0x2200d303,
    0x4f441e47,0x227a23c8,0x3a2d503c,0x47e23c89,0x3227a21d,0x10ec7e23,
    0x1f88763f,0x22edb83b,0x643c89e8,0x7fdc7fff,0x1ffff20e,0x6881dff7,
    0x9fff92d4,0xc9a7ffe4,0xe88f32e5,0x4f547fff,0x2a3544b9,0x3a24b99e,
    0x3fa27fff,0x4cf547ff,0x990baa4b,0x5feb83d8,0xb001dfd0,0xfea807c5,
    0x067f540c,0xfea8bfb6,0x427fd40c,0x7d40cfea,0x84ffa84f,0x0b504ffa,
    0x01019fd5,0x02002010,0x020a235c,0x77165408,0x3e201059,0x1c3ff8bf,
    0x7ff17ff1,0xf8804008,0x933ff8bf,0xfeb85c49,0x10099885,0x01020033,
    0x00c40000,0x08000100,0x10020040,0x00000000,0x00000000,0x00000000,
    0x00000000,0x02662000,0x00000000,0x00000000,0x00000000,0x00000000,
    0x00000000,0x00000000,0x00000000,0x00000000,0xb8062004,0x14404221,
    0x5c3806a0,0x05c01081,0x42880844,0x07005c28,0x0002015c,0x26f2036e,
    0x5c0c9440,0x1e44000d,0x54c045c4,0x36e25438,0x8b882980,0x0666ecc0,
    0x0b987153,0xa8838a98,0x32a03809,0x0edfc84d,0x9153074c,0x7504bc98,
    0x21aa1640,0x1b101b8c,0x64c48a98,0x1b116a4b,0x01e40590,0x260ee0b5,
    0x46ee838a,0x54c6fdfc,0xe80d8838,0x1e4d43db,0x9f20c4c4,0x829838a9,
    0x2ba23c99,0x0c4c44fb,0x22621232,0x23767641,0x2623302c,0x544b9661,
    0x304cccc5,0x09981333,0x7c133330,0x99804cc1,0x33331099,0x42666621,
    0x1333315a,0x30266662,0x21f64013,0x07b93028,0x55661d55,0x816edc6f,
    0x44c9f828,0xddb82ddb,0x7b933642,0x7b930310,0xc985b1dc,0x20a5643d,
    0x89663dc9,0xb0661314,0x321dd55f,0xd8b71e22,0x3fb61efe,0x03ff621e,
    0x3d87bfb6,0x3603ff62,0xddf91efe,0x3bbbf29d,0x3bbf2934,0x9dddf94e,
    0x6407fec4,0x0b2e1fbd,0x747d55f1,0xf1593fcd,0x7cd541f3,0x5fc165c0,
    0x07cd545f,0x5b83e6aa,0xc87d57f1,0x9f55fc45,0x222f88da,0x3223eabf,
    0xd55f11cd,0x57dc0f27,0x477cc6f8,0x2688f24b,0x505a83f8,0x40f7e20b,
    0x7c44c85a,0x1f0b503d,0x5547c755,0x47551f03,0x7c43aa8f,0x9306783d,
    0x5eeeeb8b,0xebca64b5,0x7ffe468b,0x87c2e4c0,0x03fff23e,0xa541fff9,
    0x0ce9a64b,0x7e4d325c,0x6992e2ff,0xeeb8f2f2,0x3fa795ee,0x81d3990f,
    0x264bcce9,0x2d44c89e,0x705a82d4,0x216a0d39,0x834e5c3d,0x40fcf85a,
    0xf9260fcf,0x07e7c0fc,0x5f434e5c,0x262d40b9,0x1d31999e,0x646fcc76,
    0x03e236a3,0x2e6be16a,0x41f11b53,0x500f88da,0x90f9721d,0x82e43aa1,
    0x2e43aa2d,0x4f4c6e2e,0x261d5199,0x74c0ff46,0x7fd44cf8,0x2d42d40c,
    0xfddd05a8,0x1f88b503,0x540ff774,0x218fbf85,0x4b518fbf,0x2fe18fbf,
    0x7f77418f,0x5427ec41,0x24fffc85,0x3fee4ffc,0x3ffa20cf,0x7ec5a87f,
    0xffd10efd,0x7fff44ff,0xeffb92a7,0xb83bfee0,0x3baa0eff,0x40effb86,
    0x7ffe45c9,0x513fff24,0x27d5a60b,0xd3173bee,0x0b505a81,0x509733d5,
    0x4f545b8b,0xf85a84b9,0x6887cd10,0x26887cb5,0x4f54d10f,0x4c5a84b9,
    0x0083ffff,0x01004320,0x20ffffe6,0x20080100,0x08060080,0x00080130,
    0x5a804010,0x5136dfb0,0x43703755,0x3fe2ffff,0x17ff12ff,0x7fffc7ff,
    0x5ffc4152,0x3ffe3ff8,0xdffffb2f,0x45bffff6,0x2dffffb2,0xf16ffffd,
    0x107ff17f,0x00000000,0x00000000,0x00000000,0x00000000,0x0007ffc8,
    0x00000000,0x00000000,0x00000000,0x00000000,0x00000000,0x00000000,
    0x00000000,0x6dc00000,0xb9665cc1,0xdd983954,0x222665c2,0x220c42ec,
    0x3221cccc,0x2e01102d,0xdb81542d,0x54c01101,0x41775c08,0x5ee4c3d8,
    0x0b73321c,0x44060136,0x204ccc42,0x85335018,0x98198898,0x9159508a,
    0x54199889,0x5102002c,0x44066602,0x1f59904c,0xf9972be2,0x4dec2d88,
    0x88ab360e,0x22d419ce,0x362eaad8,0x5e640f9b,0x43e7721c,0x2720fdee,
    0x1cbcc868,0x7537e76c,0xf12640aa,0x7dc1bf57,0x035c4dad,0x320c41a2,
    0x37f21efe,0x20c44c1e,0x20eeacfc,0x3f33fdec,0xdddf913a,0xbb302dc1,
    0x42daa8d9,0x9a80dee8,0x25b0f829,0x87c5c8ea,0x6c3d302c,0x4072e0bc,
    0x3f1e205a,0x8cdbc87a,0x249e47a4,0x3235562d,0x96a4acb9,0x301dd159,
    0x71dc9bb9,0x31e27989,0xfc885b9d,0x740621cc,0x2e4b9660,0x734c3954,
    0xbc8ae789,0x993440f8,0x3a64bac4,0x332a4fcb,0x3eefb83d,0xf10e552e,
    0x8b9bb1e4,0xfb82d88f,0xd87e6e46,0xfff50efe,0xfb8b70bf,0xaabcac6f,
    0x44bf7b71,0x172b60fc,0x646a633b,0x47b39503,0x224fbae8,0x7cc4eaae,
    0x67cc4c9c,0x557dc3da,0x907416e0,0x11f33c45,0x89734c5b,0x6fc42cec,
    0x699dfd83,0x5c79b997,0x3e26afab,0x89dc1e9c,0x0b623e67,0x1726164f,
    0x6c0fffff,0x65767903,0x85b02d43,0x6d61e9bf,0x3b6e1a8d,0x77b03a64,
    0x35119d8b,0xb9db80f2,0x2a264774,0x6f4c4ddd,0xf13cc0be,0x2ad70688,
    0x223b83a3,0x262c87c6,0x3ae612e6,0x75c07e43,0x276e598a,0x2e7faa6c,
    0xcb8593c5,0x2c87c6b9,0x2207c574,0x0804fc5c,0x64b618f2,0x105a8974,
    0xb8b61f0f,0xfa85b8cb,0x41976801,0x2659bb9b,0xed88711e,0x81362b54,
    0x26034c4a,0x2788b51f,0xf8addf21,0x0f227a20,0x7c45b11f,0xc874c3b1,
    0x8e881ec4,0x76d463d8,0x81bfff30,0xdeb8590f,0x16c47c0b,0x3220bfe6,
    0xfe8807c5,0xbffd10ef,0x22077f44,0xff709501,0x0ccdc81b,0x0b5077f6,
    0x33720659,0x1fffdc0c,0x3fff2349,0x22feb82f,0xfff00efe,0xbff903bf,
    0x7fecdb21,0x40cfea82,0x7d47fffc,0x6fff4c4f,0x320bfd70,0xf7104eff,
    0x7e4046e1,0x3fe66f8d,0x7fffc81f,0x8fb7a600,0x10000800,0x06ffffb8,
    0x04020040,0x07bb1010,0x33602004,0x9880102d,0x0800cc41,0x00408040,
    0x00200200,0x00099881,0x00000000,0x00000020,0x00000000,0x00000000,
    0x00000000,0x00000000,0x00000000,0x00000000,0x00000000,0x336e2000,
    0x09999982,0x0b66054e,0x98310097,0x21edc01d,0x111101da,0x2dc2b811,
    0x81333310,0x26623db8,0x0cc5ea81,0x2e60c833,0x0004cc43,0x80666200,
    0x3bb30199,0x31099998,0x30988661,0x83309983,0x00133099,0x4c666662,
    0xd0661313,0xfdb0bb37,0x409945fd,0x202c0b8b,0x00d45de9,0x03d116e6,
    0x98330202,0x3bbbee07,0xf91d6644,0x419f8ddd,0x20ee99fd,0xf717761c,
    0x09301ddd,0xddf95c88,0x0ffd881d,0xf07557c4,0x2bee5fdd,0x22fee6f8,
    0x6c57746f,0xd15fd11f,0x5c076a5f,0x2736efee,0x266f8bfb,0x476540c5,
    0x2e0f2e2c,0x916a583c,0x1e435025,0x664ec2cc,0x3cb82022,0x3783dcf8,
    0x0e6fe475,0x05f1e4d1,0x2012adf1,0x20f27859,0x833ee059,0x37e20f27,
    0x7787a183,0xc869cc8b,0xcabb86ad,0x87934c68,0x55dc0cfa,0xd399068c,
    0x90507441,0x4c983ff3,0x5edc4c98,0x13baa3cd,0x17bd7bb3,0xbfcd8598,
    0x4c982020,0x7c1e9cf8,0x0aaf987d,0xdd7599a2,0x56674499,0x21660e24,
    0x2e61fcbf,0x37aa2bed,0x81fddf81,0x172069cb,0x3fd01d31,0x32a03f60,
    0xf2d85afd,0x4c33ee01,0x3a0454a8,0x4fffb81f,0xa80dfef8,0x3d509504,
    0x8175c4d9,0x4c49b8dc,0x8084fd85,0x593c2540,0x0e837bf8,0x56d66688,
    0x3e3a20fc,0x1660ee4c,0xb7317b3e,0x0ef5457d,0x742eddfc,0x85d81fee,
    0x2d4189f8,0xe982ee88,0xada85ecf,0x507f9105,0x3b266b89,0x4e4c1a02,
    0x06d43a8e,0x6cc606d4,0x0a236e0e,0x36a06c43,0x021f5ec0,0x0f81b502,
    0x6988f859,0x44744074,0x49fff53d,0x8249f569,0x07d0f85a,0x067dc0b3,
    0xe98f311f,0x37a24c99,0x25c5f408,0x7c5f416a,0x27ce7c41,0xcfb82ef8,
    0x4c10b500,0x10b702ec,0x29fffdff,0xf33ffff9,0xf7107fff,0x13fffe61,
    0xff89e7c4,0xf53f73ff,0x844444cd,0xf93ffff9,0x7fe4ff3b,0xffff16ff,
    0x4277fe43,0x09b5fd80,0xf92ffff8,0x0930be2f,0xfffb5c88,0x45ffc47f,
    0xffff52ff,0x93fffe25,0x5fec7ffc,0xf97c0ff8,0x3b50d703,0x503ffe40,
    0x00000bff,0x00000000,0x00000000,0x00000000,0x00000000,0x00000000,
    0x00000000,0x00000000,0x0cccc000,0x44131131,0x19983319,0x33311e40,
    0x2e188660,0xdb883954,0x2004882c,0x3261998a,0x2b7660cd,0x416edc2d,
    0x6e4c3dc9,0x98e66642,0x0883c9bc,0x0cc86643,0x00b6f732,0x323dacc8,
    0x950cc9bc,0x030887b9,0x90654144,0x5ddddc19,0x5dd43323,0x4cccc3bb,
    0xa8eff6c1,0x3f25f9cf,0x3ba26f9d,0x25fa83fe,0x1fd05fea,0xd8bcc7f6,
    0x02ecdf42,0x3a0e8ad8,0x26fa1fff,0x2bf2a61d,0x83aaaa0f,0xf12eaae8,
    0x6d747d57,0x3f7bb10e,0x2e2c8d88,0x6e46bbad,0x83986aeb,0x3e63aefa,
    0x9f10ce89,0x5cec43d3,0x309cba83,0x71644959,0x222d9777,0x7777732a,
    0x07f7774c,0x42c9e166,0x13b84e8f,0x598b9d0f,0x1fe2fee0,0x18b3164f,
    0x44aeeee6,0x0f96c2fe,0xfc833bae,0x3f23feff,0x3bbee0ff,0x134c975f,
    0x83fd01d5,0x7443d8e9,0x4ddc3cfd,0x82ee88f5,0x21a73207,0x93d10b27,
    0x31effd89,0x203a897b,0xbba8f268,0x445643bb,0x6fc2cc0d,0x8377c2ec,
    0x65c6c9cb,0x9702cc59,0x88f8f99f,0x2283a22d,0xd12bbbb9,0x0f9bd85f,
    0x7c4f6291,0xb50a9fb8,0x4f4c3f11,0x321d5199,0xc8667ea5,0x55e40ebd,
    0x0fe7f40d,0x3a3d66ee,0x03e21f8b,0x87c1efc4,0x06ce642c,0x4730bbe2,
    0x9ac01cc8,0x777732cd,0x302eec87,0x85b57f0b,0xefb84dbf,0x3b73e20c,
    0x5dc49660,0x7fe478fd,0x27ffdc6f,0x10e8ae80,0x3e25dddf,0x3ff20eff,
    0xffd11ffe,0x4ffec8df,0xff837fee,0xf39f93ff,0xd871350f,0xfaff879c,
    0x3098a3fa,0x1f20ffff,0x99be37f2,0x0e2a6072,0x80000000,0x0b502dcc,
    0x11f0b21f,0x7104b81d,0x46d41db7,0x454ddc78,0x20080087,0x08820038,
    0x40208044,0x00200800,0x00000000,0x00000000,0x00000000,0x05e40000,
    0xf92ffff8,0xbfecff5b,0x3fff31fb,0x7dc7fe60,0x3fe27fff,0x0003ff8b,
    0x00000000,0x00000000,0x00000000,0x00000000,0x00000000,0xff980000,
    0x0000000f,0x00000000,0x02983322,0x7911cc88,0x051330a8,0x3a610200,
    0x444eeeee,0x5ddc0888,0x0051330b,0x00000000,0x00000000,0x00000000,
    0x00000000,0x00000000,0x2d47b910,0x46e535fb,0x2e698e64,0x962b759c,
    0x26b9622b,0x30999999,0x49ffffff,0x2310bbbb,0x00000001,0x00000000,
    0x00000000,0x00000000,0x00000000,0x5dca8000,0x7f45c526,0x1c479911,
    0x8a45d439,0x16e38171,0x00000001,0x00000000,0x00000000,0x00000000,
    0x00000000,0x00000000,0x03008000,0x14772200,0x00000c22,0x00000000,
    0x00000000,0x00000000,0x00000000,0x00000000,0x00000000,0x00000000,
    0x00000000,0x00000000,0x00000000,0x00000000,0x00000000,0x00000000,
};

static signed short stb__courier_bold_12_latin1_x[224]={ 0,2,1,0,0,0,1,2,2,1,0,0,2,0,
2,0,0,0,0,0,0,0,1,0,0,1,2,2,-1,0,0,1,0,-1,0,0,0,0,0,0,0,0,0,0,
0,-1,-1,0,0,0,0,0,0,0,-1,-1,0,0,0,2,0,1,0,-1,2,0,-1,0,0,0,0,0,0,0,
0,0,0,-1,0,0,-1,0,0,0,0,0,0,-1,0,0,0,1,2,1,0,1,1,1,1,1,1,1,1,1,
1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,0,2,0,0,0,0,
2,0,1,-1,1,0,-1,0,-1,-1,1,0,1,1,2,0,0,2,2,1,1,0,0,-1,0,0,-1,-1,-1,-1,
-1,-1,-1,0,0,0,0,0,0,0,0,0,-1,-1,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,
0,0,0,0,-1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,-1,0,
 };
static signed short stb__courier_bold_12_latin1_y[224]={ 8,1,1,0,0,1,2,1,1,1,1,1,6,4,
6,0,1,1,1,1,1,1,1,1,1,1,3,3,1,3,1,1,1,1,1,1,1,1,1,1,1,1,1,1,
1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,0,1,0,10,0,3,1,3,1,3,1,3,1,1,
1,1,1,3,3,3,3,3,3,3,1,3,3,3,3,3,3,1,1,1,3,1,1,1,1,1,1,1,1,1,
1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,8,3,0,1,2,1,
1,1,1,1,1,3,4,4,1,-1,0,0,1,1,0,3,1,3,7,1,1,3,1,1,1,3,-1,-1,-1,-1,
-1,-1,1,1,-1,-1,-1,-1,-1,-1,-1,-1,1,-1,-1,-1,-1,-1,-1,2,1,-1,-1,-1,-1,-1,1,1,0,0,
1,1,1,0,3,3,0,0,1,1,0,0,1,1,1,1,0,0,1,1,1,2,2,0,0,1,1,0,1,1,
 };
static unsigned short stb__courier_bold_12_latin1_w[224]={ 0,2,4,6,6,6,5,2,4,3,6,6,3,6,
2,6,6,6,6,6,6,6,5,6,6,5,2,3,7,7,7,5,6,8,7,6,6,6,7,7,7,6,7,7,
7,8,8,7,7,7,7,6,6,7,8,8,7,7,6,4,6,3,6,8,3,7,8,7,7,6,7,7,7,6,
5,7,6,8,7,6,8,7,7,6,7,7,7,8,7,7,6,4,2,4,6,6,6,6,6,6,6,6,6,6,
6,6,6,6,6,6,6,6,6,6,6,6,6,6,6,6,6,6,6,6,6,6,6,6,0,2,6,6,6,7,
2,6,4,8,5,6,7,6,8,8,4,6,4,4,3,7,6,2,3,4,4,7,7,8,7,6,8,8,8,8,
8,8,8,6,6,6,6,6,6,6,6,6,7,8,7,7,7,7,7,5,7,7,7,7,7,7,7,6,7,7,
7,7,7,7,8,7,6,6,6,6,6,6,6,6,6,7,6,6,6,6,6,6,7,7,7,7,7,7,8,7,
 };
static unsigned short stb__courier_bold_12_latin1_h[224]={ 0,8,4,9,10,8,7,4,9,9,5,7,4,2,
3,10,8,7,7,8,7,8,8,8,8,8,6,7,7,4,7,8,8,7,7,8,7,7,7,8,7,7,8,7,
7,7,7,8,7,9,7,8,7,8,7,7,7,7,7,9,10,9,5,2,3,6,8,6,8,6,7,8,7,7,
10,7,7,5,5,6,8,8,5,6,8,6,5,5,5,8,5,9,9,9,4,7,7,7,7,7,7,7,7,7,
7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,0,8,9,7,6,7,
9,8,2,8,4,5,4,2,8,2,4,8,4,4,3,8,8,3,3,4,4,5,7,7,7,8,9,9,9,9,
9,9,7,9,9,9,9,9,9,9,9,9,7,9,10,10,10,10,10,6,8,10,10,10,10,9,7,8,9,9,
8,8,8,9,6,7,9,9,8,8,8,8,7,7,8,7,9,9,8,8,8,6,7,9,9,8,8,11,10,10,
 };
static unsigned short stb__courier_bold_12_latin1_s[224]={ 125,195,94,183,110,234,123,70,207,61,217,
157,90,135,114,33,9,142,189,31,40,38,45,58,65,81,252,138,164,247,237,
87,93,180,172,109,116,101,1,248,16,9,168,24,47,55,129,176,32,18,149,
200,245,192,228,219,211,203,196,246,26,179,178,117,106,116,148,72,123,124,108,
219,93,86,56,71,64,169,201,131,139,131,185,100,157,64,193,160,145,207,138,
26,162,251,73,79,79,79,79,79,79,79,79,79,79,79,79,79,79,79,79,
79,79,79,79,79,79,79,79,79,79,79,79,79,79,79,79,79,125,165,121,
48,93,1,95,116,142,100,64,153,234,135,72,126,224,51,242,229,102,23,16,
99,110,85,80,209,40,55,223,205,198,45,212,237,65,112,17,155,98,105,88,
81,74,54,38,31,215,9,62,40,78,48,117,87,149,102,86,94,70,1,247,
172,229,221,157,179,187,190,107,9,172,165,135,241,165,128,33,26,142,239,133,
148,198,212,227,80,231,125,140,1,184,1,17,9, };
static unsigned short stb__courier_bold_12_latin1_t[224]={ 11,12,46,1,1,12,31,46,1,12,39,
31,46,46,46,1,22,31,31,22,39,22,22,22,22,22,31,31,31,39,31,
22,22,31,31,22,31,31,40,12,39,39,22,39,39,39,31,22,39,12,31,
22,31,22,31,31,31,31,31,1,1,1,39,46,46,39,22,39,22,39,31,
12,31,31,1,31,31,39,39,39,22,22,39,39,22,39,39,39,39,22,39,
12,1,1,46,31,31,31,31,31,31,31,31,31,31,31,31,31,31,31,31,
31,31,31,31,31,31,31,31,31,31,31,31,31,31,31,31,31,11,22,12,
31,39,32,12,22,46,22,46,39,39,46,22,46,39,22,39,39,46,22,22,
46,46,46,46,39,31,31,22,12,1,12,1,1,12,12,31,1,12,12,12,
12,12,12,12,12,22,12,1,1,1,1,1,39,12,1,1,1,1,13,22,
12,1,1,12,12,12,1,39,31,1,1,12,12,12,12,31,31,12,22,1,
1,12,12,12,39,22,1,1,23,22,1,1,1, };
static unsigned short stb__courier_bold_12_latin1_a[224]={ 102,102,102,102,102,102,102,102,
102,102,102,102,102,102,102,102,102,102,102,102,102,102,102,102,
102,102,102,102,102,102,102,102,102,102,102,102,102,102,102,102,
102,102,102,102,102,102,102,102,102,102,102,102,102,102,102,102,
102,102,102,102,102,102,102,102,102,102,102,102,102,102,102,102,
102,102,102,102,102,102,102,102,102,102,102,102,102,102,102,102,
102,102,102,102,102,102,102,102,102,102,102,102,102,102,102,102,
102,102,102,102,102,102,102,102,102,102,102,102,102,102,102,102,
102,102,102,102,102,102,102,102,102,102,102,102,102,102,102,102,
102,102,102,102,102,102,102,102,102,102,102,102,102,102,102,102,
102,102,102,102,102,102,102,102,102,102,102,102,102,102,102,102,
102,102,102,102,102,102,102,102,102,102,102,102,102,102,102,102,
102,102,102,102,102,102,102,102,102,102,102,102,102,102,102,102,
102,102,102,102,102,102,102,102,102,102,102,102,102,102,102,102,
102,102,102,102,102,102,102,102, };

// Call this function with
//    font: NULL or array length
//    data: NULL or specified size
//    height: STB_FONT_courier_bold_12_latin1_BITMAP_HEIGHT or STB_FONT_courier_bold_12_latin1_BITMAP_HEIGHT_POW2
//    return value: spacing between lines
static void stb_font_courier_bold_12_latin1(stb_fontchar font[STB_FONT_courier_bold_12_latin1_NUM_CHARS],
                unsigned char data[STB_FONT_courier_bold_12_latin1_BITMAP_HEIGHT][STB_FONT_courier_bold_12_latin1_BITMAP_WIDTH],
                int height)
{
    int i,j;
    if (data != 0) {
        unsigned int *bits = stb__courier_bold_12_latin1_pixels;
        unsigned int bitpack = *bits++, numbits = 32;
        for (i=0; i < STB_FONT_courier_bold_12_latin1_BITMAP_WIDTH*height; ++i)
            data[0][i] = 0;  // zero entire bitmap
        for (j=1; j < STB_FONT_courier_bold_12_latin1_BITMAP_HEIGHT-1; ++j) {
            for (i=1; i < STB_FONT_courier_bold_12_latin1_BITMAP_WIDTH-1; ++i) {
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
        float recip_width = 1.0f / STB_FONT_courier_bold_12_latin1_BITMAP_WIDTH;
        float recip_height = 1.0f / height;
        for (i=0; i < STB_FONT_courier_bold_12_latin1_NUM_CHARS; ++i) {
            // pad characters so they bilerp from empty space around each character
            font[i].s0 = (stb__courier_bold_12_latin1_s[i]) * recip_width;
            font[i].t0 = (stb__courier_bold_12_latin1_t[i]) * recip_height;
            font[i].s1 = (stb__courier_bold_12_latin1_s[i] + stb__courier_bold_12_latin1_w[i]) * recip_width;
            font[i].t1 = (stb__courier_bold_12_latin1_t[i] + stb__courier_bold_12_latin1_h[i]) * recip_height;
            font[i].x0 = stb__courier_bold_12_latin1_x[i];
            font[i].y0 = stb__courier_bold_12_latin1_y[i];
            font[i].x1 = stb__courier_bold_12_latin1_x[i] + stb__courier_bold_12_latin1_w[i];
            font[i].y1 = stb__courier_bold_12_latin1_y[i] + stb__courier_bold_12_latin1_h[i];
            font[i].advance_int = (stb__courier_bold_12_latin1_a[i]+8)>>4;
            font[i].s0f = (stb__courier_bold_12_latin1_s[i] - 0.5f) * recip_width;
            font[i].t0f = (stb__courier_bold_12_latin1_t[i] - 0.5f) * recip_height;
            font[i].s1f = (stb__courier_bold_12_latin1_s[i] + stb__courier_bold_12_latin1_w[i] + 0.5f) * recip_width;
            font[i].t1f = (stb__courier_bold_12_latin1_t[i] + stb__courier_bold_12_latin1_h[i] + 0.5f) * recip_height;
            font[i].x0f = stb__courier_bold_12_latin1_x[i] - 0.5f;
            font[i].y0f = stb__courier_bold_12_latin1_y[i] - 0.5f;
            font[i].x1f = stb__courier_bold_12_latin1_x[i] + stb__courier_bold_12_latin1_w[i] + 0.5f;
            font[i].y1f = stb__courier_bold_12_latin1_y[i] + stb__courier_bold_12_latin1_h[i] + 0.5f;
            font[i].advance = stb__courier_bold_12_latin1_a[i]/16.0f;
        }
    }
}

#ifndef STB_SOMEFONT_CREATE
#define STB_SOMEFONT_CREATE              stb_font_courier_bold_12_latin1
#define STB_SOMEFONT_BITMAP_WIDTH        STB_FONT_courier_bold_12_latin1_BITMAP_WIDTH
#define STB_SOMEFONT_BITMAP_HEIGHT       STB_FONT_courier_bold_12_latin1_BITMAP_HEIGHT
#define STB_SOMEFONT_BITMAP_HEIGHT_POW2  STB_FONT_courier_bold_12_latin1_BITMAP_HEIGHT_POW2
#define STB_SOMEFONT_FIRST_CHAR          STB_FONT_courier_bold_12_latin1_FIRST_CHAR
#define STB_SOMEFONT_NUM_CHARS           STB_FONT_courier_bold_12_latin1_NUM_CHARS
#define STB_SOMEFONT_LINE_SPACING        STB_FONT_courier_bold_12_latin1_LINE_SPACING
#endif
