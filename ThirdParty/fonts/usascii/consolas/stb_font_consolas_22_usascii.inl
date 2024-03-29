// Font generated by stb_font_inl_generator.c (4/1 bpp)
//
// Following instructions show how to use the only included font, whatever it is, in
// a generic way so you can replace it with any other font by changing the include.
// To use multiple fonts, replace STB_SOMEFONT_* below with STB_FONT_consolas_22_usascii_*,
// and separately install each font. Note that the CREATE function call has a
// totally different name; it's just 'stb_font_consolas_22_usascii'.
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

#define STB_FONT_consolas_22_usascii_BITMAP_WIDTH         256
#define STB_FONT_consolas_22_usascii_BITMAP_HEIGHT         72
#define STB_FONT_consolas_22_usascii_BITMAP_HEIGHT_POW2   128

#define STB_FONT_consolas_22_usascii_FIRST_CHAR            32
#define STB_FONT_consolas_22_usascii_NUM_CHARS             95

#define STB_FONT_consolas_22_usascii_LINE_SPACING          14

static unsigned int stb__consolas_22_usascii_pixels[]={
    0x002aea97,0x00880039,0xcc895d44,0x3332e4cc,0x8004c01c,0x88000049,
    0x20022009,0x00330009,0x01310262,0x04c00426,0x01999880,0x00800026,
    0x974c0220,0xda80ceec,0x00eeeeff,0x5fa09988,0x3a02fffb,0x1ff5000f,
    0x4d3ffe60,0x3fa7ffff,0xff702fff,0x7fcc07ff,0xb001b600,0xfffd501f,
    0x4402fc09,0x2fc800ff,0xf50bfff2,0x3033ff67,0x3ff6009f,0x00df01ff,
    0x26009f30,0xecf981ff,0x7dc6fedf,0x0eeffbbe,0x3ffffa60,0x3fd44fd1,
    0x2e00df30,0x17fd01ff,0x7d401fcc,0xc88bfd82,0x01fe883f,0xbf1002f4,
    0xfd99df90,0x803f901d,0xfc800ff8,0x4dd17f32,0x3fb2a5f8,0x4013e62f,
    0xf01fdaaa,0x09f3000d,0x260bfea0,0x4bf60eff,0x037c46f8,0x2eab7fe2,
    0x03fb0fd0,0x3b8027dc,0x7f30df10,0xfc85f500,0x4fc87c81,0x9dffdb50,
    0xf983f700,0x441fec0e,0x00ff804f,0x5cf72fc8,0x2a01f90f,0x009f31ff,
    0x1be03f90,0x8013e600,0x81df303b,0xd09f35f9,0x027dc01f,0x805f70fd,
    0x4c0002fd,0x803f983f,0x40fe22fa,0x41be62f8,0x5ddfdffd,0x1fd86e80,
    0x1fb07f88,0xf9007f80,0x9bdc3ee5,0x9afdc03f,0x1fc8004f,0x3a600df0,
    0xeeeeefee,0x04f98002,0x3e17e6df,0xd017e407,0x8805f70f,0x3bbba25f,
    0x07f306ee,0x5f5007f3,0xd93a03e4,0xf35fa81f,0x20bea005,0x207f606f,
    0x43fc03fa,0x2feeedc8,0x3abf5bf3,0xf36f9806,0x8033bb29,0x90df01fc,
    0x7f774c9d,0x322eeeee,0xf981eeee,0x1ff4df04,0x1fc809f9,0x0bee1fa0,
    0xeee89fa0,0x7f307fee,0xf5007f30,0xdec8a7c5,0x0ff15d8d,0x007d4bf2,
    0x05f887d8,0x03740bf2,0x9fff31fe,0x7fdc5ffd,0x9801fc8d,0xbfd9f34f,
    0x0fe40dfd,0x02fe46f8,0xeec809f3,0x84f981ff,0x3fff65f9,0xb33304ff,
    0x7433335f,0xc803f987,0xa83f401f,0x803f982f,0x363f32fa,0x2ad97ebf,
    0x2ebf705f,0x309f3007,0x81fdc09f,0xd1fe01fb,0x202fc85f,0x2a6203f9,
    0x1dff31fe,0x1fc817ec,0x02fe4df0,0xfc8013e6,0xfb84f981,0x15535f54,
    0x3ffffe20,0x1fa7ffff,0x3ee0077c,0x6c43f403,0x803f980f,0x3eaf72fa,
    0x7e5b2dd2,0xdbdff103,0x2a03f200,0x40bee04f,0xb9fe05f8,0x202fc83f,
    0x6ffe406e,0xf303be62,0x7c07f20b,0xf300bf96,0x40fe4009,0x87f444f9,
    0x2aa003fb,0x2aaabfea,0x7fec41fa,0xe80bf302,0x4037fe67,0x2fa803f9,
    0x95f9f2db,0xd8807f6d,0x2200bfff,0x40bf305f,0x03f201fc,0x903f93f4,
    0x4c7ee05f,0xf981fc80,0x3f20df04,0x0bf7df01,0xc8013e60,0xacff981f,
    0x3fe63ffd,0x402ceeef,0x41fa01fc,0xf101cdfb,0x3227e80d,0x07f304fd,
    0x75765f50,0x6d729f16,0xfff9801f,0x205f702f,0x03fa06f8,0x4dd04f98,
    0x82fc80fd,0x5ffe8cf9,0x27cc07e4,0x03f906f8,0x400bfbbe,0x3f2004f9,
    0xfffff981,0xeeefe81d,0x3f204fff,0x3e21fa01,0x405f9804,0x301f907e,
    0x25f5007f,0x4be6bf5e,0x2005f75e,0xe81ffbcf,0x440ff406,0xb07d806f,
    0x7e40fecb,0x73db6e82,0xf9835c5f,0xf905f884,0x3fe3be03,0x004f9801,
    0x53e607f2,0x260bf200,0x807f207f,0x802fa87e,0x83f404fb,0x03f983f9,
    0x3a9d2fa8,0x4cbe3f75,0x72f8804f,0x403f989f,0x17f40efb,0x64017d40,
    0x217f442f,0x27c9f1fb,0xf984f980,0x3e03f904,0xd003ff36,0x40fe400f,
    0x0fe804f9,0x0fe40fd0,0x05f50fd0,0x7e805fb0,0x7f307f30,0x5765f500,
    0xfbbfe9ed,0x3e601be0,0x0fd8bf51,0xeccefd80,0x21be004f,0xfb17ea3b,
    0x9f27c45f,0x3019527c,0x201fd09f,0x54df01fc,0x77e400ff,0x3f901cac,
    0xfb009f30,0x027e4c3b,0x43f403f9,0x07f802fa,0x07f307e8,0x5f5007f3,
    0x65ffd5b6,0x407f42ff,0x3fa23ea0,0xc8013e23,0x4003efff,0x8bfea1fb,
    0xfbeebeff,0xafd83f62,0x09ff11fb,0xfd759ff3,0x7f666447,0x71be1ccd,
    0x6dc401df,0x99912fff,0x26399bfd,0xffe8804f,0x6404ffff,0x2a1fa01f,
    0x027d402f,0x83f983f4,0x2fa803f9,0x013044f9,0xddfd07f9,0xfc8bffdf,
    0x007e8001,0x7fc49f10,0x237ffa21,0x885f52fa,0x17f43ffe,0x6ffff644,
    0x7ffffc41,0x21be3fff,0x08800efc,0x7fffffc4,0x003513ff,0x00555d4c,
    0x0fd00fe4,0x7fc405f7,0x9837c400,0x803f984f,0x005f32fa,0xedb83fd0,
    0x6f82deff,0x447f9000,0x441fb001,0x08000100,0x00040020,0x00000000,
    0x00000000,0x6c3f4000,0x00ffa01f,0x37c417ea,0x7d401fcc,0x220017a2,
    0x40bd00ef,0xf10002fa,0x200dfdff,0x000003f9,0x00000000,0x00000000,
    0x00000000,0x733f4000,0x427dc0df,0x1feb89aa,0xf9873fa0,0x2a2fa803,
    0x802e20df,0x409f05fa,0x64400029,0x2a000cee,0x00000002,0x00000000,
    0x00000000,0x00000000,0xeffbbf40,0x7e417e01,0x4403ffff,0xfff34ffe,
    0x7ffff4ff,0x7ff7fd42,0xc80fc806,0x00000001,0x00000000,0x00000000,
    0x00000000,0x00000000,0x537e8000,0xa9801003,0x2a6000ab,0x45555511,
    0x300aaaaa,0x00c00155,0x00000000,0x00000000,0x00000000,0x00000000,
    0x00000000,0x001fa000,0x00000000,0x00000000,0x00000000,0x00000000,
    0x00000000,0x00000000,0x00000000,0x00aa0000,0x00000000,0x00000000,
    0x00000000,0x00000000,0x00000000,0x00000000,0x00000000,0x00000000,
    0x00000000,0x00000000,0x00000000,0x00000000,0x00000000,0x00000000,
    0x00000000,0x5e880000,0x00983b60,0x33bb6e20,0x4002202d,0x4002ded9,
    0x01330008,0x88000000,0x98800001,0x00262001,0x00026000,0x00000000,
    0x00000000,0xf305fb00,0x98027ccd,0x2ffdcffe,0x04fffea8,0x0fffbfea,
    0x0ffffaa0,0x177fffec,0x7ffffff4,0xdffd7105,0xdffffc88,0x3fc03fa1,
    0x17ffffee,0x3ffffec8,0x3ffffffa,0xdfffd902,0xf880bee7,0x7c405fb4,
    0x7fffffc6,0xff90ffff,0x2bffffff,0x2dfffff8,0x3ea04fd8,0xf70bf505,
    0xe8027cc7,0x3217e42f,0x0efebcef,0x0ff10ff8,0xfebbefb8,0xfdbacd85,
    0x6667f42f,0xeffa82cc,0x5efec3cd,0x1fd0ffdb,0xcefd9fe0,0xfe984cbb,
    0x2e6eccce,0x42fecccc,0xecccefe8,0x7c405f55,0x7dc0bf73,0x7fe66643,
    0xdd70cccc,0x29ffdddd,0xffeccef8,0xe807fc43,0xd03fe01f,0x4027cc1f,
    0x22fc85fa,0x1fec0ef9,0x40fd1be2,0x0ff40ef8,0x1ba2fdc0,0x300f7cc0,
    0x3a5fb0df,0x3eaff00f,0x413fa006,0x3617dc00,0x0bea105f,0x0ff13f98,
    0x1fa00fec,0x443fe200,0x643fd45f,0x404fb85f,0x317e63fc,0x05f9009f,
    0x40fec5f9,0x227f87f8,0x20fee06f,0x5f8804fa,0x0fe80374,0x7dc27d40,
    0x5fe01fd2,0x9f7003fc,0x317dc000,0x07f300df,0x05fb17cc,0x0fd00df1,
    0x7c45fb00,0x7c40fe85,0x2007f41f,0x30bf26f9,0x85bf919f,0x22fc80fd,
    0xb07f606f,0x403fd37f,0x37f4c0fd,0x1ba1fcc0,0x7c013e60,0x743fa20f,
    0x3eeff00f,0x001fd005,0x5f917dc0,0x0cc7f300,0x427dc5f5,0x07e803fa,
    0x3e22fdc0,0xfb80fe85,0x7400fee5,0xbf30ff1f,0x6c9ffbfd,0xf12fc80f,
    0x2217e40b,0x7401efff,0x03fffdc7,0x5fd03baa,0x35f70155,0xff705797,
    0x7f45ff57,0x3fa2ff00,0x0037c02e,0x1fd8bee0,0x9fa4f880,0x21fe21fa,
    0x07e800fd,0xf103fe20,0x3a05fc8b,0x2007f89f,0x984facfa,0xc9fa0dff,
    0x997f441f,0x50fee04f,0x41541fff,0xb1dfb16f,0xefffb81f,0xfffffe80,
    0x3ffff20d,0xff985ffe,0x807f41ff,0x3fff627f,0x362fc40b,0x7dc05eee,
    0x7c003fa2,0x3ee5ff34,0xdf10fec1,0xd801fa00,0xeeff882f,0x3ea00dff,
    0x7c002fbd,0xef981fdf,0x4fa8fe40,0x4fa97fec,0xdfb8bee0,0x3e1be6fc,
    0x3f64fe9e,0x7fee6540,0x75cccc43,0x8877f26f,0x777e43fd,0x403fa1ff,
    0xfffd987f,0xddb17e62,0x22fb80df,0x2bf000ff,0x81f74ffb,0x00fea4fb,
    0x5fa803f4,0x9fddff10,0x01bff600,0x4c1bff20,0x3e2fb84f,0x2fceebcf,
    0x8fe40bf3,0x19fb0ff8,0x5fffd0df,0xfe8807e8,0xc8ffc401,0x3a6f881f,
    0x747fee3f,0x440ff00f,0x0df11ffc,0x8bee037c,0x2bf000fe,0x10f77dce,
    0x8007ecdf,0x0ff8807e,0x1fe4bf10,0x000ffcc0,0xf9817fcc,0x3a22fb84,
    0x12fb8dff,0x987f40df,0x3f7fa24f,0xf80efd84,0x007f7006,0x40bee5f9,
    0xf709f57f,0x37c03fa9,0x1ff1fe40,0x5f701be0,0xee8017ec,0x7cafaaf8,
    0x0df13fb0,0x7ec03f40,0xff17e202,0x000fd001,0x4f981be6,0x5c082fb8,
    0x2207fa2f,0xf313ea6f,0x05f903ff,0x3ee009f5,0xf51fd802,0x3f2df109,
    0x3fb5f982,0xf500bf50,0x6f81fec9,0xdf70fec0,0xf9efb600,0x59f707cd,
    0x03f4007f,0xbf1017ea,0x7e804fb8,0x405fd000,0x02fb84f9,0x3bee2fc8,
    0xff117f40,0x880ffd81,0x03fa20ef,0x5003fe20,0x5c0ff8df,0xf709f73f,
    0x3f613ee9,0x222fd802,0x066f82ff,0x4fe81ff1,0xb2f7ec10,0x3be20dbf,
    0x1fa000fd,0x4400ff88,0x007fc45f,0x54c401fa,0x27cc04fe,0x7e4017dc,
    0x76677ec2,0xccffc85f,0xf906ffff,0x887fd77d,0x2ffcbaac,0x7fedd5e4,
    0x655f7dc0,0x2f7fe26f,0x3fa0ffda,0x3a6ffcbd,0x5feccccd,0xccceffa8,
    0x3f73be6f,0xdeff983f,0x3ff25ecc,0xd81bfea2,0x3f4006ff,0xddddff90,
    0x217e2bdd,0x03f404fc,0x803fffa8,0x02fb84f9,0xfec82fc8,0x3fee03ef,
    0x20bfb3ef,0x982effeb,0x40cfffff,0x0cfffff8,0x09fffd50,0x19ffffb3,
    0x4ffffc88,0x77ffffe4,0x3fff6203,0x3fff23ef,0x3fb2202e,0x1ff22def,
    0xffb817fe,0xd03f4003,0xffffffff,0x3e217e2d,0x401fa00f,0xf3000aa8,
    0x3005f709,0x00044015,0x00440001,0x0cc00662,0x44002200,0x88011000,
    0x01880019,0x00080004,0x00000000,0x00000000,0x00000000,0x00000000,
    0x00000000,0x00000000,0x00000000,0x00000000,0x00000000,0x00000000,
    0x00000000,0x00000000,0x00000000,0x00000000,0x00000000,0x10000026,
    0x00022001,0x007ba200,0x0000c880,0x30f74432,0x3ffffe63,0x407fc42d,
    0x0ffb0ff8,0xc84fe9be,0x500fee6f,0x407fb09f,0xff104ffa,0x23ffffff,
    0x36df00fe,0xffffffff,0xffffffb5,0x3ffffa1f,0xfffd0fff,0xea8019df,
    0xffff984f,0xfff903ef,0xfffb105f,0x3ffa005f,0x309ff700,0x3ea27c3f,
    0x7f44000e,0x3e29ff73,0xeccef99f,0x42fdc5ff,0x0fff63fc,0xf87fe9be,
    0x500fee7f,0x405fb89f,0x99106ffd,0x21999ff9,0x32df00fe,0xfeeeeeee,
    0x99999fb5,0x3333fa19,0x99fd0ccc,0xd305ffdb,0xdf309fff,0xe8bff999,
    0x23feaacf,0xffcbdff8,0x07ffdc02,0xfa82ff98,0x3fea0fe1,0x45ff3001,
    0x23fe2ff9,0x1ff444f9,0x46f98bfa,0x26f86ffd,0x37ea2fde,0xf500fee7,
    0x22037cc9,0xe801fddf,0x3e01fd07,0xfb2fc806,0xe807e801,0x507fd40f,
    0x309f99ff,0x71fe889f,0x5c1fd09f,0xf3037d41,0x0c401fbb,0x07f10fb8,
    0xf500ffa6,0xff83103f,0x5fb84f98,0x1fe877cc,0x3e17dfec,0xdd97b3e6,
    0x500fee7c,0x003fe29f,0x007f77f5,0x403fa0fd,0xb37c406f,0x807e801f,
    0x45fb80fe,0xf309f70c,0x3f65f909,0xf802fb80,0x3f63fa07,0x7ed54000,
    0x81acfbaa,0xdf704fe8,0xf9bfc001,0xfc86f884,0x8fd84fbc,0x99f37c6f,
    0x1f95f11f,0x9f500fee,0x3f6007fa,0x7e806f88,0x1be01fd0,0x07ec5f70,
    0x3fa01fa0,0x7dc0ff00,0xfd84f984,0x7f501fd0,0x3ee0ff00,0xf8001fb3,
    0xffffffff,0x837f604f,0x6d8005fd,0x0bf709f3,0xbec1bffa,0xcf9be2fc,
    0x1f97bbf9,0x9f500fee,0xdf1005f9,0x1fa00ff4,0x06f807f4,0x01fb1be2,
    0x0fe807e8,0x3ee01fd0,0x3264f984,0x2607f63f,0x42fcc04f,0x003f65f8,
    0x01f72ec0,0x3a23ff50,0x7cc0003f,0xa80ffcc4,0x22fb02ff,0x9fc5be6f,
    0x21f74ede,0x77d403fb,0x47f5005f,0x83f403fb,0xfffffffe,0xb0fee06f,
    0x49dddddf,0x6ffffffe,0x0fec03fa,0xff984fb8,0x7d44ffff,0x017f660e,
    0x41fb03fd,0x40aa00fd,0x2e01f25e,0x27f440ef,0x77cc6600,0x203fffdc,
    0x4fb04ffc,0x3e2df1fd,0x3ee3ff73,0xfa807f71,0xfd800ffd,0xfd01be21,
    0x33333fa0,0xff106fcc,0xdddddfb0,0x66667f49,0x6c03fa3c,0x309f701f,
    0xdff999df,0x7ffffe41,0x13f204ff,0x01fb0fea,0x93e0ffea,0x06fec07c,
    0xf981bf90,0xf35ff71f,0x4019dfff,0xd81feef9,0x9b7d7e67,0x7dcdf13f,
    0xfa807f71,0x7c406fac,0x3a00fe86,0x3e01fd07,0xfb07f706,0xe807e801,
    0x201fd00f,0x84f984fb,0x5e5cc4fd,0xbf903f99,0x1fb0df10,0x54d7fea0,
    0xaeeaadfb,0x8027f442,0x3fee0efb,0x9f39ffb4,0xf99fe800,0x47ec7d86,
    0x0d47f36f,0x00fee3f7,0x817f29f5,0xfeeeeffa,0x741fa03f,0x3e0df00f,
    0x400fd80f,0x80fe807e,0x13ee07f8,0x1be613e6,0x3f207ee0,0xddddf705,
    0xb05ddffd,0x3fffeebf,0x267fffff,0x7d4002fe,0x2a5ff31f,0x004f99ff,
    0x44fd97ee,0xb7e7d47d,0x4bea03f9,0x27d403fb,0x3ff607fd,0x06ffffff,
    0x807f41fa,0xb03fb86f,0x807e801f,0x04fc80fe,0x13e613ee,0xbf1017ea,
    0x7540bf90,0xeffeeeee,0x4c4fb82e,0x3a613e1f,0x45d30001,0x4f984408,
    0x441ff100,0x3a1f61ff,0x405f56ff,0x807f72fa,0x07fe24fa,0x07f40df1,
    0x01fd07e8,0x403fe1be,0x03f400fd,0x3ff207f4,0x2613ee00,0x01ff444f,
    0x5fc83fd5,0x403f6000,0x0fd40fe9,0x0000007f,0x4013e600,0x26fb83fe,
    0x56ffa87d,0xb9fd405f,0x2cccccdf,0x0ff989f5,0x3fc813ea,0x99ff9991,
    0x7c03fa19,0xfb027dc6,0xcccfe801,0x99fd0ccc,0xe881dffd,0x4eeffeee,
    0xffd99df3,0xefeecc8b,0x7777fd42,0xfd804eee,0x40f7f4c0,0x005f10fb,
    0x26000000,0x06fb804f,0xe83ecffa,0x5405f76f,0xfffff73f,0x213ea9ff,
    0x807f65fb,0xffff16f9,0x3fa3ffff,0x0ff8df00,0xfd003f60,0x21ffffff,
    0x02defffe,0xfffffff1,0x3fffe6bf,0xceff82de,0xfffff503,0xfb00dfff,
    0x3202b981,0x0000be67,0x00000000,0x00000000,0x00000000,0x00000000,
    0x00000000,0x00000000,0x00000000,0x00000000,0xec980000,0x3b2202df,
    0xd9302eff,0xfd9109df,0xffd9305b,0xa83e987d,0x7640001e,0x5725e983,
    0x74c1cec9,0xe82dfc8a,0xde98deaa,0xe8807ae1,0x76c0bd13,0xdddddd10,
    0x002201dd,0x0000006a,0x4c0cc330,0xbbbb9809,0xbb12bbbb,0x8001bbbb,
    0x5ffddffb,0xecccff98,0xeddffb83,0x333fe60f,0x677e44fe,0x13e64ffd,
    0x07e80bee,0x3fa0ffc4,0x37bebba1,0x3f3e62ff,0x67c4ffdf,0x5fdebfcf,
    0x3f980bea,0x9be607f6,0xfeeeeee8,0xf7017207,0x01ff105f,0x710fff62,
    0x7fc3fe21,0x2e0ffcc1,0xffffffff,0xffffff14,0x077c4003,0x0fd85fb1,
    0x040efa80,0x43fb03fa,0xf30ff881,0x7405f709,0x326fa807,0x31fff44f,
    0x06ffccdf,0xfd3ff8fd,0x03f99f2b,0x84fa8bea,0x3fd802fc,0x5c0cb90c,
    0x5fec84ff,0x49fdbfb0,0x7cff11fb,0x41fd881f,0x08888888,0x2fc80000,
    0x0ff46f98,0x2a00ff40,0x804f983f,0x709f31fc,0x803f405f,0xe85f9cfc,
    0x3e67f83f,0x9fe1fc86,0x221f90fe,0x1fb9ba4f,0x403fc3fc,0x4f7c45fb,
    0xe80fe8cb,0x7dd7cc4f,0xbfb27c41,0x3a7f8fd7,0x000aa00f,0x0fd00000,
    0x33fee3fc,0x900df101,0xf533335f,0xfb55310b,0x3ee13e65,0xe801fa02,
    0x07e80fef,0x5c27cc55,0x26e93e2f,0x7c57e0fc,0xfc81f91f,0xf3013e62,
    0x3bbf220d,0x87fb00cf,0x5911ba5d,0x7c2fffc8,0xa8003fa6,0xeeeeeeee,
    0x3fc00003,0xfff50fd0,0x805f987d,0xfffffffd,0x3fffa66f,0x09f32fff,
    0x666645f7,0x00ccccff,0x1fa05ff3,0x7dc27cc0,0x326e93e2,0x7fddba0f,
    0x4bf30fb4,0x3fa201fc,0x027fdc00,0x0fd41df3,0x262007f5,0x01b25e80,
    0xdddddd50,0x800007dd,0x981fa07e,0x1be25ffc,0x2666ff20,0x2bfa0999,
    0x27ccbf21,0xfff897dc,0x0fffffff,0x3a0dffb0,0x709f3007,0x4dd27c5f,
    0x675f60fc,0x3fa0dd7c,0x7ec06f88,0x377baa02,0x3bfaa2ee,0x07ec2f41,
    0x00000000,0xd8000000,0x806f881f,0x07fe0fe8,0xf3009f70,0x3e65f907,
    0x3a02fc85,0xf79f7007,0x2600fd09,0x3e2fb84f,0x20fc9ba4,0x9faaf9fc,
    0xf57f704f,0x2027e407,0x43ee994e,0x80ea82b9,0x111113e8,0x01111111,
    0x00000000,0xb0bf5000,0x83fa005f,0x3e200dfd,0x21fdc00f,0x71fe2ffa,
    0x03f405ff,0x87fb37d4,0x09f3007e,0xdd27c5f7,0xfbf507e4,0xf881fefc,
    0xdf500fde,0x012e4100,0xffff0000,0xffffffff,0x00000000,0x3bfa0000,
    0xce85fdbb,0x445fdbab,0x0ecbdfff,0x2eaf7ff2,0xb77ff31c,0x77e45fdf,
    0x202fdfdb,0x0ffc407e,0x03f43ff1,0x2fb84f98,0x3f26e93e,0xfc93fe60,
    0x13ff202f,0x6666ffc4,0x00bb01cc,0xaaaa8000,0x2aaaaaaa,0x00000000,
    0x3ff20000,0xfffd03ef,0x3f2209ff,0xfea85fff,0x3ee1efff,0x22faaeff,
    0xf9aeffc8,0xfd01fa02,0x3a1ff507,0x709f3007,0x4dd27c5f,0x8bfe20fc,
    0x3e601ff9,0xffff301f,0x0007ffff,0x00000000,0x00000000,0x00440000,
    0x22000998,0x88033000,0x50006000,0x00000005,0x00000000,0x00000000,
    0x00000000,0x00000000,0x00000000,0x00000000,0x00000000,0x00000000,
    0x00000000,0x00000000,0x00000000,0x00000000,0x00000000,
};

static signed short stb__consolas_22_usascii_x[95]={ 0,4,2,0,1,0,0,4,3,2,1,0,2,2,
4,1,0,1,1,1,0,1,1,1,1,1,4,2,1,1,2,3,0,0,1,0,1,2,2,0,1,1,1,1,
2,0,1,0,1,0,1,1,0,1,0,0,0,0,1,3,1,3,1,0,0,1,1,1,1,1,0,1,1,1,
1,1,1,0,1,0,1,1,2,1,0,1,0,0,0,0,1,1,5,2,0, };
static signed short stb__consolas_22_usascii_y[95]={ 16,0,0,1,-1,0,1,0,0,0,0,4,12,9,
12,0,1,1,1,1,1,1,1,1,1,1,5,5,4,7,4,0,0,1,1,1,1,1,1,1,1,1,1,1,
1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,0,0,0,1,18,0,5,0,5,0,5,0,5,0,0,
0,0,0,5,5,5,5,5,5,5,1,5,5,5,5,5,5,0,-2,0,7, };
static unsigned short stb__consolas_22_usascii_w[95]={ 0,4,8,12,10,12,13,4,7,7,10,12,6,8,
4,10,12,10,10,10,12,10,10,10,10,10,4,6,9,10,9,7,12,12,10,11,11,9,9,11,10,10,9,11,
9,12,10,12,10,13,11,10,12,10,13,12,12,13,10,7,10,6,10,13,8,10,10,10,10,10,12,11,10,10,
9,11,10,12,10,12,10,10,10,10,11,10,12,12,12,12,10,9,2,9,12, };
static unsigned short stb__consolas_22_usascii_h[95]={ 0,17,6,15,20,17,16,6,21,21,10,12,8,3,
5,19,16,15,15,16,15,16,16,15,16,15,12,15,13,6,13,17,21,15,15,16,15,15,15,16,15,15,16,15,
15,15,15,16,15,19,15,16,15,16,15,15,15,15,15,21,19,21,8,3,6,12,17,12,17,12,16,16,16,16,
21,16,16,11,11,12,16,16,11,12,16,12,11,11,11,16,11,21,23,21,6, };
static unsigned short stb__consolas_22_usascii_s[95]={ 255,125,209,213,78,141,49,251,70,14,167,
69,178,238,251,89,63,149,182,76,193,87,98,106,109,171,246,206,236,227,226,
154,57,71,160,164,137,127,117,142,95,84,154,59,49,36,25,36,1,100,227,
131,203,120,189,176,12,239,216,42,114,50,185,196,218,47,162,25,130,36,242,
230,14,208,22,184,173,117,106,1,219,25,95,14,196,58,143,130,82,1,156,
32,1,4,196, };
static unsigned short stb__consolas_22_usascii_t[95]={ 1,1,58,42,1,1,25,42,1,1,58,
58,58,58,49,1,25,42,42,25,42,25,25,42,25,42,42,42,42,58,42,
1,1,42,42,25,42,42,42,25,42,42,25,42,42,42,42,25,42,1,25,
25,25,25,25,25,42,25,25,1,1,1,58,65,58,58,1,58,1,58,1,
1,25,1,1,1,1,58,58,58,1,25,58,58,1,58,58,58,58,25,58,
1,1,1,58, };
static unsigned short stb__consolas_22_usascii_a[95]={ 194,194,194,194,194,194,194,194,
194,194,194,194,194,194,194,194,194,194,194,194,194,194,194,194,
194,194,194,194,194,194,194,194,194,194,194,194,194,194,194,194,
194,194,194,194,194,194,194,194,194,194,194,194,194,194,194,194,
194,194,194,194,194,194,194,194,194,194,194,194,194,194,194,194,
194,194,194,194,194,194,194,194,194,194,194,194,194,194,194,194,
194,194,194,194,194,194,194, };

// Call this function with
//    font: NULL or array length
//    data: NULL or specified size
//    height: STB_FONT_consolas_22_usascii_BITMAP_HEIGHT or STB_FONT_consolas_22_usascii_BITMAP_HEIGHT_POW2
//    return value: spacing between lines
static void stb_font_consolas_22_usascii(stb_fontchar font[STB_FONT_consolas_22_usascii_NUM_CHARS],
                unsigned char data[STB_FONT_consolas_22_usascii_BITMAP_HEIGHT][STB_FONT_consolas_22_usascii_BITMAP_WIDTH],
                int height)
{
    int i,j;
    if (data != 0) {
        unsigned int *bits = stb__consolas_22_usascii_pixels;
        unsigned int bitpack = *bits++, numbits = 32;
        for (i=0; i < STB_FONT_consolas_22_usascii_BITMAP_WIDTH*height; ++i)
            data[0][i] = 0;  // zero entire bitmap
        for (j=1; j < STB_FONT_consolas_22_usascii_BITMAP_HEIGHT-1; ++j) {
            for (i=1; i < STB_FONT_consolas_22_usascii_BITMAP_WIDTH-1; ++i) {
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
        float recip_width = 1.0f / STB_FONT_consolas_22_usascii_BITMAP_WIDTH;
        float recip_height = 1.0f / height;
        for (i=0; i < STB_FONT_consolas_22_usascii_NUM_CHARS; ++i) {
            // pad characters so they bilerp from empty space around each character
            font[i].s0 = (stb__consolas_22_usascii_s[i]) * recip_width;
            font[i].t0 = (stb__consolas_22_usascii_t[i]) * recip_height;
            font[i].s1 = (stb__consolas_22_usascii_s[i] + stb__consolas_22_usascii_w[i]) * recip_width;
            font[i].t1 = (stb__consolas_22_usascii_t[i] + stb__consolas_22_usascii_h[i]) * recip_height;
            font[i].x0 = stb__consolas_22_usascii_x[i];
            font[i].y0 = stb__consolas_22_usascii_y[i];
            font[i].x1 = stb__consolas_22_usascii_x[i] + stb__consolas_22_usascii_w[i];
            font[i].y1 = stb__consolas_22_usascii_y[i] + stb__consolas_22_usascii_h[i];
            font[i].advance_int = (stb__consolas_22_usascii_a[i]+8)>>4;
            font[i].s0f = (stb__consolas_22_usascii_s[i] - 0.5f) * recip_width;
            font[i].t0f = (stb__consolas_22_usascii_t[i] - 0.5f) * recip_height;
            font[i].s1f = (stb__consolas_22_usascii_s[i] + stb__consolas_22_usascii_w[i] + 0.5f) * recip_width;
            font[i].t1f = (stb__consolas_22_usascii_t[i] + stb__consolas_22_usascii_h[i] + 0.5f) * recip_height;
            font[i].x0f = stb__consolas_22_usascii_x[i] - 0.5f;
            font[i].y0f = stb__consolas_22_usascii_y[i] - 0.5f;
            font[i].x1f = stb__consolas_22_usascii_x[i] + stb__consolas_22_usascii_w[i] + 0.5f;
            font[i].y1f = stb__consolas_22_usascii_y[i] + stb__consolas_22_usascii_h[i] + 0.5f;
            font[i].advance = stb__consolas_22_usascii_a[i]/16.0f;
        }
    }
}

#ifndef STB_SOMEFONT_CREATE
#define STB_SOMEFONT_CREATE              stb_font_consolas_22_usascii
#define STB_SOMEFONT_BITMAP_WIDTH        STB_FONT_consolas_22_usascii_BITMAP_WIDTH
#define STB_SOMEFONT_BITMAP_HEIGHT       STB_FONT_consolas_22_usascii_BITMAP_HEIGHT
#define STB_SOMEFONT_BITMAP_HEIGHT_POW2  STB_FONT_consolas_22_usascii_BITMAP_HEIGHT_POW2
#define STB_SOMEFONT_FIRST_CHAR          STB_FONT_consolas_22_usascii_FIRST_CHAR
#define STB_SOMEFONT_NUM_CHARS           STB_FONT_consolas_22_usascii_NUM_CHARS
#define STB_SOMEFONT_LINE_SPACING        STB_FONT_consolas_22_usascii_LINE_SPACING
#endif

