// Font generated by stb_font_inl_generator.c (4/1 bpp)
//
// Following instructions show how to use the only included font, whatever it is, in
// a generic way so you can replace it with any other font by changing the include.
// To use multiple fonts, replace STB_SOMEFONT_* below with STB_FONT_courier_38_usascii_*,
// and separately install each font. Note that the CREATE function call has a
// totally different name; it's just 'stb_font_courier_38_usascii'.
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

#define STB_FONT_courier_38_usascii_BITMAP_WIDTH         256
#define STB_FONT_courier_38_usascii_BITMAP_HEIGHT        132
#define STB_FONT_courier_38_usascii_BITMAP_HEIGHT_POW2   256

#define STB_FONT_courier_38_usascii_FIRST_CHAR            32
#define STB_FONT_courier_38_usascii_NUM_CHARS             95

#define STB_FONT_courier_38_usascii_LINE_SPACING          18

static unsigned int stb__courier_38_usascii_pixels[]={
    0x22003300,0x3300d400,0x000014c0,0x32000150,0x25999950,0x2e1ccccc,
    0x00001700,0x73000044,0x00000137,0x00000000,0x00000000,0x20000000,
    0x8099007f,0x85c80efc,0x83e04fe9,0x03f5004b,0x3b23f300,0xdddf4fee,
    0x5e82f45d,0xffeb8000,0x3fee004f,0x7405ffee,0x3ff6a00e,0xfec8803d,
    0x22000cef,0x203dfeca,0x802dffda,0x001cfec9,0x0b7ff6e2,0x9007f800,
    0x907d100b,0x4401b90b,0x7401761f,0x40bb0006,0x7dc05f4d,0x0000fa81,
    0x3f66b3f6,0x05fec405,0xf301dd51,0x79fb105f,0x2e01df95,0xfecabcef,
    0xbdffa801,0x7bf705ca,0x7d40bfb7,0x806febbe,0xfcbbdff9,0x07f8000d,
    0x00df7544,0xf11721aa,0x360f9803,0x003fb804,0x53601f98,0x41be202f,
    0x3d90004e,0x77409f10,0x303fa201,0x03db05ff,0x07f90dd1,0xfd8807ec,
    0x20fea004,0x84f984f9,0x33ea04d9,0x8005e980,0x3bfee02a,0x984ddffe,
    0x3e62e40f,0x9d07cc00,0x0001fd00,0x5f4d80db,0xfb81fc80,0x017c4000,
    0x003ee0f9,0x07fe22f4,0x1fc407f5,0x0bf1006a,0x9d000bf6,0x17607dc0,
    0x0dd02f88,0x00003f88,0xea8873ea,0x640f984f,0x2a007cc5,0x3e601f47,
    0x02f88004,0x4c02fa6c,0x8007f04f,0x20fcc06d,0x3ea003f8,0xf907fe21,
    0x2000b900,0x001fb86d,0x7f1007dc,0x1ee00fc4,0x1b2003ea,0x204e8000,
    0x40f984f8,0x2007cc5c,0x36017c7b,0x06c8001f,0xd005f4d8,0x800f701f,
    0x642f802f,0x7c6e8006,0x5c026c0f,0x98f70007,0x05d8004f,0x201ea6c8,
    0x8014c2f8,0x9999887a,0x26099999,0x4c15400f,0x3e62e40f,0x0be35c00,
    0x88005f88,0x5f4d803f,0xf107f500,0x007e2007,0x003e87f1,0x207fc7a8,
    0x005d806c,0x006c89d0,0x1f5005d0,0x026c01ee,0xffd0f700,0x7fffffff,
    0xf30003dc,0x07cc5c81,0x01f89b20,0x320013ee,0x0be9b007,0x3641be60,
    0xd880f980,0x017c3fff,0x1ff07cc0,0x3e602f98,0x42fa8002,0x05f0003e,
    0x01e63f30,0xbb000374,0x33333310,0x1fd47d33,0x640f9800,0x55407cc5,
    0xbfbaaeda,0x01fec2aa,0x6c00fe20,0xff1005f4,0x2a00be20,0xf9aefb87,
    0x40007e23,0x7741fa2f,0x000ed981,0x3f07fd71,0x3e200a88,0x3e2f8801,
    0x003fd401,0xd0001fa8,0x000bfd87,0x717217c4,0xffddd10f,0xbdddfddd,
    0x5c002fe8,0x3e9b000f,0x201ff002,0x4c6b806c,0x1f31fc4f,0x7e8fe000,
    0x3af3bf60,0xffb800df,0x50f982ff,0x303ffffb,0xe8be001f,0x01fbe205,
    0x8000fe60,0xceffb83e,0x20de800a,0x2017a65c,0xff01e64e,0x004e8001,
    0xe8017d36,0x805f301f,0x3e07e46b,0x20007e23,0x881b62f8,0x01ffffff,
    0x0bfd9510,0x4cfbead5,0x007cc3fc,0x20fe62f8,0x000f9de8,0xd00013e6,
    0x7fedcc07,0x53fe201e,0x001dfb5c,0x3e03d47d,0x007d4007,0x400be9b0,
    0x017602fc,0x3f84e8d7,0x7cc0017c,0x6f4c1b60,0x01fc9889,0x2a0ee980,
    0x1f703f9e,0x2f8007cc,0x7e4d6fd4,0x26001f35,0x3e80004f,0x40bf6600,
    0x2ab92efa,0x23f801fe,0x007fc07b,0x4d8009d0,0x0bf6005f,0x1ae01f98,
    0x3e87f0d9,0x3647a800,0x5f501fcc,0x4cdb1000,0x32f403ff,0x20be001f,
    0x2e2dffd9,0x009f5006,0x2000fa00,0x5c89f06c,0x717c036c,0x001fe80d,
    0x4d8003f5,0x07fa005f,0x235c0bd0,0x321fc1f8,0x545e8006,0x5c805c83,
    0x7c3f1000,0x3e27a806,0x401f8801,0xfa805c80,0x0fa00004,0xf103e200,
    0x43d45c83,0xeeefeeec,0x6c0deefe,0x00bd002f,0x400be9b0,0x07d400ff,
    0xbefd87b8,0x01fc43fa,0x3a003f50,0x000f9802,0x401747d0,0x200fe0f9,
    0x3e8000f9,0x00027d40,0x80244fa0,0x207cc1f8,0x2a07cc5c,0xeccdfccc,
    0x7e40ccce,0x001f9803,0x1005f4d8,0x413a00ff,0xfffd707a,0x1001f90f,
    0x07e2009d,0xc8000fc0,0x3e601365,0x1ee013a0,0xb807ea00,0xe800003f,
    0xfb005f33,0x2e40f981,0x0f9803e6,0x09f50136,0x36000db0,0xbf3005f4,
    0x2603ea00,0x7ec0000f,0x003fa201,0x0f9802f8,0x35c7d000,0x01f23d40,
    0xbd10017a,0x0001fdc0,0x3ff33e80,0x7cc27cc0,0x03e62e40,0x01360f98,
    0x05f301be,0x017d3600,0x9f0017dc,0x00005f10,0x754437fb,0x02ec000e,
    0xfa8003e4,0xbb00be21,0x3e602f98,0x807ec001,0x000002fc,0x77f7ccfa,
    0x05fca9ac,0x4c5c81f3,0x7d1ea00f,0x6403f900,0x7d360006,0x4007e802,
    0x006c80fb,0xfffff700,0x1774c09f,0x2f980be6,0x9f300772,0x3ea01d50,
    0xe880ed80,0x07fa6005,0x2c4017e4,0x2b13e800,0x2dffffda,0x8b903e60,
    0xf1ea00f9,0x20bf3007,0x360002f8,0x4fa805f4,0x4c1fc400,0xf100002f,
    0xffd0037f,0x4419f70f,0x67f4c4fc,0x817f2609,0x7f711cfc,0x4c2bbe20,
    0x2a2181fd,0x9f300efb,0x55555555,0xd0001f95,0x3005d807,0x7cc5c81f,
    0x05f1ae00,0x1b203f60,0x0be9b000,0x90001fb0,0x440bf20f,0xaaefa804,
    0x3ff21501,0xffffd305,0x7ff5405f,0xb802ffff,0x402ffffe,0x0effffd8,
    0xdfffff98,0x7fffcc03,0xffffffff,0x03e8000f,0x86b802e4,0x3202e85c,
    0x4c007e26,0x001fc44f,0x3017d360,0x3e20009f,0x9bdfd882,0x7dc05fca,
    0xceffffff,0x02aa1ffc,0x80035530,0x98001aa9,0x5544001a,0x001a9800,
    0x88000000,0x402e402f,0xb85c83fb,0x7c4b902e,0xf71f6001,0x3a666000,
    0xc81337f4,0x1b20000f,0x2bdffeb8,0x319bdd80,0x0019bd95,0x00000000,
    0x00000000,0x00000000,0xb9003ee0,0xb903fe80,0x990bf910,0xf10007c4,
    0x74001fc5,0xfff4ffff,0x001fc7ff,0x0000be20,0x77700000,0x77777777,
    0x99998777,0x99999999,0x00999999,0x00000000,0x00000000,0x02640374,
    0x08802002,0x88200000,0x33310004,0x06666613,0x0ae00001,0x00000000,
    0xffffffff,0x64ffffff,0xffffffff,0xffffffff,0x00001fff,0x00000000,
    0x7e440000,0x0000001e,0x00000000,0x00000000,0x00000000,0x77000000,
    0x77777777,0x99987777,0x99999999,0x09999999,0x00000000,0x40000000,
    0xdffffffe,0x00000000,0x00000000,0x00000000,0x00000000,0x00000000,
    0x00000000,0x00000000,0x53000000,0x00003555,0x00000000,0x00000000,
    0x00000000,0x00000000,0x00000000,0x00000000,0x00000000,0x00000000,
    0x00000000,0x00000000,0x00000000,0x00000000,0x00000000,0x00000000,
    0x00000000,0x0039b300,0x33000980,0x4cc40133,0x2f2a2009,0x100ccc0a,
    0x98837975,0xcb880019,0xcccca83c,0x4ccccccc,0x0001e65c,0x2a204cc4,
    0x999001bc,0x17999999,0x2aeea200,0x3332209a,0x332a0002,0x3220000c,
    0x2003cccc,0xa9de8808,0xbf30006d,0xfffff700,0x3ffffe60,0xfeeffb80,
    0x0bfff34f,0xfffddff7,0x00ffff23,0x70dfdb10,0xdddddddf,0x3621fddd,
    0x440006ee,0xffd16fff,0x440bffdd,0xeeeeeeef,0xffb801ee,0x50ffffef,
    0x40007fdd,0x0001feec,0x17fbbba6,0x2e2ffe40,0x98002c83,0x39f3005f,
    0x06f4c401,0x6fd41ff4,0xcfd819fa,0x765fe440,0x36400019,0x07a8035c,
    0x310000d7,0x503df3d9,0x007e20bf,0x2073ea00,0x0007d019,0x00003f10,
    0xff9805c8,0x2203a2ff,0x05f98005,0x7cc01b20,0x2200fc81,0x03f707fe,
    0x0005ffa8,0x00950d90,0x0035c1b2,0x809ff700,0x01f885e8,0x0005f800,
    0xf100007d,0x5c800003,0x2ffff980,0x400340d1,0x3e2001a8,0xf985d802,
    0x987f9802,0x0bf9003f,0x001b2000,0x01ae07f0,0x006fb800,0x01f885f3,
    0x000fc400,0x880003e8,0x6400001f,0x8dffb005,0x0005981d,0x101b2000,
    0x400d903f,0x4006b87d,0xd900005f,0x807cc000,0x2e00006b,0x1132001f,
    0xf980003f,0x007d0000,0x0003f100,0x22005c80,0x0ec44a80,0xf1000000,
    0x4d836405,0x1361ee00,0x2200bb00,0x03640acb,0x35c0d700,0x002b32a2,
    0xd50007dc,0x88001f88,0x999afa99,0x11f40099,0x10013795,0x3333103f,
    0x0002e400,0x03eccec8,0x02666620,0x7c41b200,0x54007d02,0x64003e87,
    0x777f5405,0x00d90eff,0x4d702740,0x3ffeeffd,0x4c007b80,0x4c47e20f,
    0x3ffe009a,0xffffffff,0x7e4fa02f,0x401effef,0x7ffd41f8,0x0b9004ff,
    0x302a8000,0xffffa8b9,0x2f88005f,0x013606c8,0x004d87b8,0x19f502ec,
    0x06c9fd88,0x5c03f100,0xfb82ee8e,0x003ee00e,0x767c47a8,0x80dfffff,
    0x99afa998,0x67401999,0x0fed42ee,0xbf703f10,0x02e40033,0x3b260000,
    0x999980be,0x8d90005c,0x01b202f8,0x006b87d8,0x02fa82fc,0x800377dc,
    0x2f7dc07b,0xfb817a20,0xf11b2001,0x3aa237bf,0x003e600e,0x88077f40,
    0x507e204f,0x1720009f,0x3f260000,0x2e4000bd,0x322f8800,0x4017cc06,
    0x03f987f9,0x13e0bf90,0x80037ec0,0x07fdc04d,0xfb817d40,0x307f3006,
    0x2605e880,0x1dd0000f,0x3e206c80,0x8000ff21,0x9500005c,0x400017bf,
    0x5b20005c,0x0fc802f8,0x5c1ffa20,0x2ffd401f,0xdf10034c,0x805f1000,
    0x176002fb,0x22027fdc,0x3e60005e,0x0001f301,0x03e600fa,0x02fd8fc4,
    0xa802e400,0x2b7f23ee,0x0b900000,0x3657c400,0xf507fd00,0x67ec0f5b,
    0x2e57e440,0x1ba002e4,0x2e01ea00,0x41ee000f,0xa81ee9eb,0x740000ef,
    0x0001f303,0x03e600fa,0x00ff57c4,0x4402e400,0x0131ffff,0x80033faa,
    0x7640005c,0x7fdc002f,0x0f34ffee,0xffeeffa8,0x07d0b91f,0xd8006c80,
    0x4007b805,0xd16b80f9,0x09ffddff,0x4c136000,0x07d0000f,0x3e201f30,
    0x80004fef,0xfffa805c,0x4467403f,0x0b9001eb,0x006f8800,0x41379510,
    0xcb988079,0x1ec2e40a,0x2001b600,0x007b802f,0x235c07cc,0x000abca8,
    0x7cc17200,0x007d0000,0x57e201f3,0x640004f9,0x1fffd005,0x02cc2540,
    0x440005c8,0x3000002f,0x1720000f,0x0dd0016e,0xb800fa80,0x41ae000f,
    0x0000006b,0x00f98274,0xf3007d00,0xf987e201,0x01720004,0x0ec00aa8,
    0x05c800e8,0x00036400,0x0000f700,0x003e6172,0x320037c4,0x007f7005,
    0x006b82ec,0x817c0000,0x7d0000f9,0x2201f300,0x0027cc1f,0x800005c8,
    0x9003b00e,0x1fc4000b,0x0bb00000,0x7c172000,0x00dfb004,0xff7003f8,
    0x203f5001,0x04c0006b,0xf300fc80,0x00fa0001,0x0fc403e6,0x640027d4,
    0x3b800005,0x0b900688,0x0003e400,0x0005f900,0x1fcc1720,0x801b7f20,
    0xdd7000f9,0x01fcc01d,0xfc8000d7,0x3017d403,0x0fa0001f,0x7c403e60,
    0x8007f501,0x8800005c,0x400b621e,0x7f10005c,0xf9500000,0x2e400007,
    0xe983bf30,0x00aaec8e,0x6d54035c,0x64415fb6,0x0035c05f,0x30577dc0,
    0x755509f9,0x3555557f,0x06b7aaa0,0x42aff2a2,0xb301fba8,0x554c359f,
    0xaaaedaaa,0x4c0001aa,0xa983eded,0xaaedaaaa,0x3fea1aaa,0x0fffffff,
    0x7fffcc00,0x40002fff,0xfffffffd,0xfeffd982,0x5fff90df,0x7c403d80,
    0x3bff26ff,0xff102fff,0x00ffffff,0x3ffff660,0xfffa82ff,0xffffffff,
    0xfffff886,0xfffffc86,0x203fffb2,0xb0fffffe,0xffffffff,0x000dffff,
    0xffd80620,0xffffffff,0x555546ff,0x0001aaaa,0x00155553,0x2aaaa200,
    0x5d400aaa,0x00000001,0x2006ae60,0x1aaaaaa9,0x1aa88000,0x00000000,
    0x00000000,0x00000000,0x00000000,0x00000000,0x00000000,0x00000000,
    0x00000000,0x00000000,0x00000000,0x00000000,0x001ba880,0x2004cc80,
    0x1001aca8,0x00159975,0x1055e544,0x26666200,0x4c199999,0x98809999,
    0x5c401999,0x5dd44003,0x2666200a,0x99999999,0x26620999,0x00199999,
    0x004cccc4,0x98133331,0x22009999,0x32099999,0x0f880ccc,0x7ffd4000,
    0x8001cffe,0xeb807efb,0xd2effeff,0x777fe4c5,0x75c03ffe,0x8cfffeff,
    0x7ffc403d,0xffffffff,0xffffff73,0xffffff81,0x2fff5c45,0xeeffc880,
    0x321f8dff,0xffffffff,0x75ffffff,0xffffffff,0xf9807dff,0xa83fffff,
    0x92ffffff,0x01ffffff,0x97fffffe,0xf880ffff,0x33ee0001,0x000fecc1,
    0xd80f57f1,0x6fe441bf,0x202fbe3f,0x37f904fc,0x03ffdb98,0xf9999988,
    0x764c199b,0xd9988099,0x9ffd109d,0xdd100bb5,0x2ffeb985,0x26666772,
    0xd99999dd,0x2673a665,0x0efeb999,0x06673e20,0x21fb9998,0x0099ed98,
    0x827b6662,0x3f107ffe,0x00bf2000,0x5b2001f9,0x003b207a,0x017c7ff3,
    0x03d907ee,0x40007f90,0x0036403f,0x5c8370b9,0x2200ed80,0x641722ff,
    0x09b0b905,0x27405f98,0xf9835c00,0x6c17c000,0x03f106ff,0x2005f300,
    0x97cc00ec,0x001f707a,0x801f8ff2,0x8007ee4e,0x0fe0003f,0x2e400d90,
    0x2f805c80,0x1722fb80,0xd85c82e4,0x202fb804,0x05c8004d,0x07a8013a,
    0xa998bff9,0x999999af,0x4400bd01,0xf52ec04f,0xf8800fe0,0xf3640023,
    0x001b8007,0x0d900fe0,0x5c802e40,0xf8007cc0,0x82e41721,0xd004d85c,
    0x7c42e409,0x2e04c80f,0x5c136006,0x3ffee4ff,0xffffffff,0x000fd43f,
    0x21fa81ae,0x8007987a,0x35c80009,0x0000001f,0x036403f8,0x17200b90,
    0x02003f10,0x641720b9,0x9b004d85,0x7fdc35c0,0x3e204d83,0x501f8802,
    0xfa9985ff,0x1999999a,0xf88006b8,0x87a89d00,0x0000005b,0x00035cbe,
    0x201fc000,0x0172006c,0x02f402e4,0x0b903b80,0x201360ea,0x21ea01f8,
    0x03e85cdd,0x036402ec,0x3e203ff3,0x002ec001,0x40fb82f8,0x0004d87a,
    0xb0fd8800,0x00000009,0x006c807f,0x02e40172,0x0000efcc,0x4d800b90,
    0x260374c0,0x43d5fc0f,0x007d402f,0x01ff00fa,0x7d0007e2,0xf10f6000,
    0x07d0f507,0x7dc40000,0x0000fa1e,0x900fe000,0x802e400d,0xdfb1005c,
    0x2000137b,0x426c005c,0x400efca8,0x223e61f8,0x2007e22f,0x003ea03f,
    0x00fc40dd,0x64000be0,0x87a83645,0x9000003e,0x03e817ff,0x3f800000,
    0xb9003640,0x10017200,0x05dffd95,0x6c005c80,0xefffffff,0x6b87e003,
    0x800f9936,0x2017606c,0x007e2008,0x360007d0,0x3d40be63,0x400001f4,
    0x80fa04f8,0xaaaaaab8,0x03f800a1,0x0b900364,0x20001720,0x32003fc9,
    0x556ec005,0x4003feaa,0x26b93a2f,0x03f1007a,0x100005f1,0x05d8003f,
    0x02ec5f00,0x0009d0f5,0x6c03f100,0x3bbbaa04,0x01f14efe,0x0d900fe0,
    0x5c802e40,0x0bea0000,0x36002e40,0x4009f904,0x7cc5f13e,0x26c00d50,
    0x00ea03dc,0xd70007e2,0x2a1f1000,0x999999af,0x003641fb,0x3200d800,
    0x263e8005,0x807f000f,0x0172006b,0x200002e4,0x00b9005c,0x13ea04d8,
    0x40faa6c0,0x5400d73f,0x7d404e87,0x000fc404,0xd70007ea,0x7fffffdc,
    0x2a7fffff,0x0000000f,0x3e8007a8,0x17c003e6,0x4e801ea0,0x0b80b900,
    0x6401ea00,0x2026c005,0x95c802fa,0x0172b90b,0x00fcc5f0,0x3f102fd4,
    0x400bb000,0x266624f8,0x9fb99999,0x04002f40,0x00fe2000,0x007cc7d0,
    0x3e200fcc,0x002f8800,0x003f80b9,0x02e401ea,0x3f201360,0x83fb5c00,
    0xc8009b7a,0xf9801b25,0x002f880e,0xd9002f98,0x260f5000,0x01b6002f,
    0x8003ee00,0x2007e63e,0x009b007c,0x172001f7,0x2ec00df0,0x6c005c80,
    0xa809d004,0x9f881f9f,0x87cc003e,0x2f44003f,0x408805e8,0x07e403fc,
    0xf703d400,0x01fe8807,0xe803dfb1,0x447d001e,0x0bea01ee,0xf5017d40,
    0x202e4007,0x1fb804ff,0xd800b900,0x403f5004,0x33a07cf9,0xace8002f,
    0x2010000f,0x754c1cfb,0x21dfb84f,0x0001fda8,0xaefb80f5,0x803bae60,
    0x4406fffc,0x54409dfc,0x67ec43fd,0x0017ee21,0x7dcc19f5,0x202e4005,
    0xd982efdf,0x2aaa603f,0x882aaaed,0x01aadeaa,0x7c40d76c,0x07fee04f,
    0x017bee00,0x7ffdc000,0x202dfffe,0xcefeffe9,0x65544001,0x3f6601af,
    0x804fffef,0x5005fffb,0xfffdfffd,0x7ffdc039,0x50003fff,0x07fffffd,
    0xedaaaaa8,0x2762aaaa,0xffefffd8,0x7fff401e,0x40ffffff,0x6ffffffa,
    0xf82ffcc0,0x03fe602f,0x00bfe200,0xbba88000,0x5d44000a,0x3ff60001,
    0x98806fff,0x554000ab,0xba988002,0x2a20009a,0x8800009b,0x7c4009ba,
    0xffffffff,0x53101fff,0x00000357,0x00000000,0x00000000,0x00000000,
    0x00000000,0x00000000,0x00000000,0x00000000,0x00000000,0x00000000,
    0x00000000,0x00199880,0x33306662,0x40033333,0x80999998,0x98809998,
    0x01999999,0x33333310,0x31013333,0x33310133,0x01333103,0x2204ccc4,
    0x99999999,0x20999999,0x99999998,0x40999999,0x22009998,0x4cc40999,
    0x4cccc401,0x4ccccc41,0x98000999,0x00199999,0xfff30220,0x3ffe003f,
    0xfffffd3f,0xf700bfff,0x98ffffff,0x7c3fffff,0xffffffff,0xff880cef,
    0xffffffff,0x3ffee1ff,0x7fffc1ff,0x3fffe66f,0xfffff00f,0x3ffffe65,
    0xffffffff,0xffff74ff,0xffffffff,0x7ffccdff,0xffff00ff,0x3fffe25f,
    0x3ffffe04,0xfffff75f,0x19ffffff,0xfffff700,0xf90007ff,0x5dec88bf,
    0x21ecfa80,0x99dd9998,0xbd330009,0xbf710133,0x33f73103,0x5fd73333,
    0xdb333310,0xd3013333,0xf531013b,0x09fd8813,0x1077e620,0x33333db3,
    0x49b33333,0x9999ce99,0x46c99999,0x2200afb8,0x64c41cf9,0x933101ff,
    0x674cc13d,0xfda99999,0x9999801f,0x4c006cde,0x75c2ffff,0x5e7400fa,
    0x00026c06,0x09f50136,0x3f900f30,0x6c00b900,0x100f9804,0x01f900bd,
    0x09b002e4,0x41b2009b,0x406d805d,0x6c806deb,0xfb1013a0,0x4cfc4001,
    0x3fe6001f,0x4eb5c2ff,0x01ae3e60,0x4d80009b,0x4c00fee0,0x900db007,
    0x4026c00b,0x0fe600f9,0x2e401fb8,0x09b09b00,0x1fc41b20,0xeb803f50,
    0x036403f8,0x07f3009d,0x009d35c0,0x6b86ffd8,0x6baec0f7,0x200026c0,
    0x005f904d,0x07a803cc,0x136005c8,0xf5003e60,0x9007f303,0x6c26c00b,
    0x5c0b7004,0x804e880f,0x6401f76b,0x6c013a06,0x7b8fa005,0xd7008800,
    0xb97c41fc,0x00026c06,0x00bf2136,0x3e200f30,0xb002e401,0x001f3009,
    0x02f441f9,0x066005c8,0x00c40136,0x401b217a,0x6c813a6b,0x274013a0,
    0x3e21f980,0x9ae00002,0x1ae6b86c,0xd80009b0,0x4000fec4,0x00f70079,
    0x026c00b9,0x5e8007cc,0x2e4003b6,0x09b003cc,0x7f1000d5,0x6b800fcc,
    0x036407ea,0x03f3009d,0x01761b20,0x3e26b800,0x80d71fc1,0xa6c0004d,
    0x30000ee8,0x00bd100f,0x026c00b9,0xf88007cc,0x32001fbc,0x36007a85,
    0x70006b84,0xb8013a1f,0x06c82ec6,0x09f5013a,0x07d41fc0,0x6c6b8000,
    0x06b83ea5,0x3600026c,0x002ffe8c,0xfe880f30,0x2005c800,0xcccccced,
    0x2000fdcc,0x64002ffa,0x07dcccce,0x33333b60,0x37a0006d,0x1ae000fc,
    0x40d905f1,0xecccccee,0x3ea003ff,0x00007f00,0x3a1f31ae,0x136035c4,
    0x3bfbb000,0x98001dfb,0xdb99999f,0x0b9001ef,0x77777ec0,0x00feeeee,
    0x0003fe20,0xfdddddf9,0x7777ec00,0x260006ee,0x35c002ff,0x81b207e4,
    0xeeeeeeee,0xbb001eff,0x7ec03640,0xe86b82ff,0x035c0f9c,0xfb000136,
    0x4006fa8b,0xfffffff9,0x02e4002e,0x1f3009b0,0x036f6c00,0x01ea1720,
    0x006b84d8,0x5c003640,0x3644f886,0xfc9809d0,0x3017c403,0x7ffc403f,
    0xbf50d706,0x4d80d70b,0x41760900,0x3e6004e8,0x00009999,0x04d80172,
    0xf9000f98,0x64009f11,0x36007985,0x40006a84,0x06b8005c,0xd03641f5,
    0x80be6009,0xeeeeeefa,0x3ea04fee,0x20d701ff,0x406b82fe,0x81f8804d,
    0x00be604d,0x200003cc,0x0136005c,0x3ea003e6,0x6400fe62,0x26c00105,
    0x90008808,0x40d7000b,0x4e81b25e,0xdd817200,0xcccccccc,0x13ff207d,
    0x203106b8,0x4026c06b,0x404d81f8,0x00f3006d,0x2005c800,0x00f9804d,
    0x0fdc27c4,0x40002e40,0x00f6004d,0x35c002e4,0x81b25f30,0x03e6004e,
    0x3e2007e2,0x401fff02,0x06b8006b,0x0fc4026c,0x0be2026c,0x00001e60,
    0x026c00b9,0x1ba007cc,0x2e400ed8,0x0026c000,0x0172007d,0x2d901ae0,
    0x8013a06c,0x400d707a,0x02ff985d,0x35c0035c,0x3e201360,0x5d804d81,
    0x00007980,0x09b002e4,0x7e401f30,0x9017a200,0x09b0000b,0x5c801f40,
    0x4406b800,0x13a06cbf,0x07d05d80,0x3f207d40,0x8006b805,0x4026c06b,
    0x804d81f8,0x03cc00fa,0x80172000,0x00f9804d,0x7f3003f5,0x40002e40,
    0x00fa004d,0x35c002e4,0xd036fdc0,0x20bf2009,0x1fc000f9,0xda8803fa,
    0x2a602aae,0x5531aeda,0x55555dd5,0x223f7555,0x01aadeaa,0x9530ab7a,
    0x0155557f,0xdb555550,0xaa855555,0xca982ade,0xdf710abf,0x36aa0155,
    0x3b6aa0bf,0x8802aaaa,0xaaaadeaa,0x3eaaaaaa,0x5db55530,0x6d440555,
    0x3fa02aaf,0x56f55446,0xecaaaaaa,0x576d442f,0x36aa602a,0xa80331ae,
    0x00ffffff,0x2bfffffd,0xfffffffd,0xffffffff,0xffffff51,0x07ffdc0d,
    0xfffffffd,0xfff8807f,0xffffffff,0xfffff11f,0xffffe83f,0xfffff72f,
    0xfffff305,0x3ffffe6b,0x5401ffff,0xffffffff,0x3fffffff,0xffffffd0,
    0x3ea01fff,0x301fffff,0xffffa8df,0xdfffffff,0xffffb80b,0xfffd00ff,
    0x00000bff,0x00000000,0x00000000,0x00000000,0x00000000,0x00000000,
    0x00000000,0x00000000,0x26200000,0x00199999,0x26666662,0x4c019999,
    0x000018bc,0x00000000,0x02666200,0x80266620,0x01bccca8,0x0accb980,
    0x5e5d4400,0x2e60020a,0x331022bc,0x00cccc01,0x01acca88,0x2cb884cc,
    0x6c005dc4,0xfff9cfff,0xceffffff,0x3ffffa00,0x07ffffff,0x1fffdfd5,
    0x00000de8,0x006c8800,0x3ffe0097,0x3fea02ff,0x7f5c0fff,0x04ffeeef,
    0xfddffd30,0xff7001bf,0xf19ffddd,0xddffb501,0x7d4f9dff,0xfff904ff,
    0x7fec401f,0xb80dffee,0xfeffadff,0x09fdff34,0x987fffc4,0xa99999fb,
    0x39d02fec,0x93333333,0x0b833a0f,0x000cfe98,0x5df70000,0x44017200,
    0x988019fb,0x0acc80ce,0x32027dc4,0x1fea80cf,0x2a05fd10,0x6fd41ffe,
    0x1ff6a20a,0x4cc09b33,0x5df300fa,0x9305fd30,0x7e7d49ff,0x7d403e64,
    0x403d43ff,0x403e82fc,0x00fa83f9,0x001ffdc0,0x07fd5000,0x26005c80,
    0x017c000f,0x2a01f700,0x80ed802f,0x7fcc00ec,0x3f4036c1,0x0f9804d8,
    0xfc805f88,0xfe85fc80,0xff904d85,0x2e00f50d,0x3a01f40f,0x2000b905,
    0x0002efc8,0x0033fa60,0x5f001720,0x01f30970,0xf882f800,0xf513a003,
    0xb07ee003,0x360d300b,0xd80f9804,0x321ba006,0x1b20d906,0x3d417ff4,
    0x03e89d00,0x035c03f2,0x077f2200,0x0dfd8800,0x00172000,0x41ff889b,
    0x2f80006b,0x3d4007b8,0x70b00176,0x26c0005f,0x3e207cc0,0x907e2001,
    0x3641b20b,0x7a837fc4,0x2e83ea00,0x7c405f30,0xfd980002,0x3f22000c,
    0x5c80001e,0x3ee35c00,0x5402e44e,0xfabcdecb,0x9999dc82,0x99999999,
    0x0000fa1f,0x0d5e77e4,0xf9804d80,0x74003d40,0x06c82e43,0x05ff70d9,
    0x45f001ea,0x7009f100,0x7540000d,0x7fdc00cf,0x17200002,0xbcd8f500,
    0xfd501f47,0xffdb99dd,0xfffffd05,0xffffffff,0x0007e25f,0xffedb980,
    0x013600df,0x00d703e6,0x905c89b0,0x3f61b20d,0xb001ea06,0x200db007,
    0x400003fb,0xfea83ffb,0x33310003,0x333db333,0x3f101333,0x447e27e2,
    0x039f701f,0x99dd82f8,0x99999999,0x03f10999,0x65440000,0x009b03fe,
    0x006b81f3,0xc82e44d8,0x3ff0d906,0x36003d40,0x200fd405,0x4c0fdfd8,
    0xff30001a,0x000ffdc9,0xffffff70,0xffffffff,0xb3dcfa09,0x2fcc1e69,
    0x06b82f80,0x0003f800,0x203ea000,0x40f9804d,0x43f8007a,0x320d905c,
    0x3d403d86,0xf8817200,0xbb0df803,0xb8003fe8,0xcfe982ef,0x33310000,
    0x3333db33,0x4dae4013,0xfb835dee,0xf505f000,0x05d80003,0xb0014c00,
    0xf3009b07,0x2002f881,0xc82e41f9,0x2000d906,0x026c007a,0x41f300bd,
    0x003f32f8,0xa803ffa8,0x200003ff,0x8eb8005c,0x1367e21f,0x2fb80364,
    0xa8000db0,0xc8e2001f,0x3213a006,0xc80fd805,0x90bd000f,0x3641b20b,
    0x7a81f754,0xfb81f400,0xfb85c800,0x3aa006c8,0x7dc000cf,0x5c80002e,
    0x87cf9800,0x5f502fcd,0x817fec40,0xd9800df8,0x5c00f6c2,0x200ff25f,
    0x00fb82fb,0x3a01ffd1,0x407ec00d,0x320d905c,0x0ffffc46,0x3f1003d4,
    0xa5c05f30,0x07f9d04d,0x001bfb30,0x00f7e440,0x2000b900,0x0ffa84ff,
    0xb982fba0,0x81acfaee,0x54c0afe9,0x7ec40dfd,0x27f54c1b,0x10277ff2,
    0x37e209f9,0x3ebbee61,0x0afe982b,0x5107baa2,0xaec815db,0xf98d7641,
    0x07a83fff,0x17a21ea0,0x4c1f2b90,0x3f2200ff,0x2600001e,0xc8000dfd,
    0x03fb0005,0xfd880ff1,0x3e4fffef,0xff900fff,0x03bfffdf,0xffefffb8,
    0xd9cb80cf,0x3effefff,0x7ff7fcc0,0x01fff33f,0x3ffffff2,0xffffb80c,
    0x322ffe45,0x3fffa5ff,0xd1007a80,0xc801d909,0xdf305f35,0x00177dc0,
    0x19fd5000,0x0002e400,0x5d440000,0xa980001a,0xa98001ab,0x220009ab,
    0x2001abba,0x0000aba8,0x0004ddcc,0x02a80000,0x42f401ea,0x25c801fa,
    0xfbf50cfc,0x0ffea159,0xfa800000,0x00b9002f,0x00000000,0x00000000,
    0x00000000,0x00000000,0x50000000,0x40ed980f,0x8b9004f8,0xf55ffffc,
    0x0003369f,0x035c0000,0x266003a8,0x006f2a20,0x4404ccc4,0x2666601a,
    0x10333300,0x33333333,0x99988333,0x33330099,0x40288013,0x26209998,
    0x014c0099,0x3bbbbb62,0xeeeeeeee,0x57e541de,0xefebaaaa,0xaaabfb80,
    0x5daaaaaa,0x0000ba88,0x00000000,0x9ffb0000,0x3fffbff2,0x3fffe601,
    0x3ffffa62,0x37fffdc2,0x227fffec,0xfffffffe,0x3fe0ffff,0xfd86ffff,
    0x5407ffff,0x27ffdc07,0x4409fff7,0x332201ff,0xcccccccc,0x20cccccc,
    0xfffffff9,0x3ee01bef,0xffffffff,0x00005fff,0x00000000,0x3a600000,
    0x7ed42fdd,0x4be66201,0x03f22dfb,0x26013df3,0x4e740afd,0xfa999999,
    0x4cfe4c44,0x9de99880,0x2a03d400,0x3fea3fff,0x3b7ba03f,0x00000000,
    0x00000000,0x00000000,0x00000000,0x3e00efd8,0x7f97f004,0x02fcc020,
    0x813a03f9,0x0be205e8,0x54007e60,0x17ffcc07,0x3205fff3,0x0005e88f,
    0x00000000,0x00000000,0x00000000,0x0fd80000,0xff803e40,0xbd10002f,
    0x16403f90,0x5d801dd0,0x83506c80,0xf885447a,0x3ffe20ff,0x3e21fb81,
    0x00000004,0x00000000,0x00000000,0x00000000,0x07cc026c,0x0000f7c0,
    0x01fc97a2,0x2003b600,0x0be201f9,0x7d4e7fec,0x3e2ffda8,0x40fff87f,
    0x42fa83f9,0xeeeeeed8,0xeeeeeeee,0x0000001d,0x00000000,0x00000000,
    0x009b0000,0x05f001f3,0x37ba2000,0x3f20001f,0xb813a000,0x7ff5cc07,
    0x740adfff,0x447fe86f,0x887f205f,0xbbbbbbbb,0xbbbbbbbb,0x00000000,
    0x00000000,0x00000000,0x3009b000,0x005f001f,0x00ffc400,0x8003f700,
    0x007d00fa,0xb006ffcc,0xe8bf90bf,0x000ed806,0x00000000,0x00000000,
    0x00000000,0x04d80000,0x2f800f98,0x3bb60000,0x2fa8000e,0xf507d000,
    0x7e7e4001,0x2e13ee01,0x2003a24f,0x000001d8,0x00000000,0x00000000,
    0x00000000,0xf9804d80,0x0002f800,0xee88ed88,0x00fea000,0x05d87b80,
    0x036cbea0,0x03b103b1,0x4feb8000,0x00000000,0x00000000,0x00000000,
    0x09b00000,0x5f001f30,0x0ee88000,0x7cc0076c,0x3e200204,0x44007e62,
    0x0013e24f,0x7e400000,0x6980eebb,0x00000000,0x00000000,0x00000000,
    0x3009b000,0x005f001f,0xd8077440,0x013e200e,0x64d9005d,0x2a1b6006,
    0x0000001f,0xfd10fdc0,0x00027cc3,0x00000000,0x00000000,0x80000000,
    0x00f9804d,0xd10002f8,0x81fd801d,0x03e805e8,0x02f89f88,0x004c0260,
    0x32000000,0x9f99f901,0x00000000,0x00000000,0x00000000,0x5bd55000,
    0x0aff2a03,0x559f5553,0x75405555,0xba881abf,0x2ffa0bff,0xaaaaaaaa,
    0xd9bb003f,0x00000000,0xa8000000,0x000000dd,0x00000000,0x00000000,
    0xf8800000,0xf986ffff,0xff10ffff,0xffffffff,0xfff303ff,0xfff90bff,
    0x3ffe25ff,0xffffffff,0x7ff3003f,0x00000000,0x00000000,0x00000000,
    0x00000000,0x00000000,0x00000000,0x00000000,0x00000000,0x00000000,
    0x00000000,0x00000000,0x00000000,0x00000000,0x00000000,0x00000000,
    0x00000000,0x00000000,0x00000000,0x00000000,
};

static signed short stb__courier_38_usascii_x[95]={ 0,8,4,3,3,3,4,7,9,4,0,2,4,3,
7,3,3,3,2,3,3,3,4,3,3,4,7,5,0,1,0,0,3,0,1,2,2,1,2,2,1,3,2,1,
2,0,0,0,2,1,1,3,2,1,0,0,1,1,3,0,0,0,3,1,7,2,0,2,2,2,3,2,1,3,
2,3,3,0,1,2,0,2,2,3,2,1,0,0,1,2,3,0,9,0,3, };
static signed short stb__courier_38_usascii_y[95]={ 27,5,6,4,4,6,9,6,6,6,6,8,22,16,
23,4,5,6,5,5,6,6,5,6,5,5,12,12,8,14,8,7,5,7,7,7,7,7,7,7,7,7,7,7,
7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,6,4,6,6,34,5,12,6,12,6,12,6,12,6,5,
5,6,6,12,12,12,12,12,12,12,7,12,12,12,12,12,12,6,6,6,14, };
static unsigned short stb__courier_38_usascii_w[95]={ 0,5,12,15,14,15,13,6,7,7,13,16,8,15,
6,14,14,14,15,14,14,14,14,14,14,14,6,8,17,18,17,12,14,20,18,17,17,17,17,17,18,14,18,19,
17,20,19,17,17,18,19,15,16,18,20,20,18,18,14,6,13,6,14,21,6,17,19,17,18,16,16,17,18,15,
12,17,15,20,18,16,19,18,17,14,16,18,20,20,18,18,14,7,2,7,15, };
static unsigned short stb__courier_38_usascii_h[95]={ 0,23,10,26,27,22,19,11,26,26,13,18,10,3,
5,26,23,21,22,23,21,22,23,22,23,23,16,19,18,7,18,21,25,20,20,21,20,20,20,21,20,20,21,20,
20,20,20,21,20,24,20,21,20,21,20,20,20,20,20,26,26,26,9,3,6,16,22,16,22,16,21,22,21,22,
29,21,21,15,15,16,22,22,15,16,21,16,15,16,15,22,15,26,26,26,6, };
static unsigned short stb__courier_38_usascii_s[95]={ 254,157,207,48,14,1,34,248,64,101,193,
84,247,157,247,72,208,138,238,178,36,163,193,108,163,223,248,246,66,235,48,
69,123,225,206,51,1,149,131,82,93,78,100,40,22,1,186,18,60,138,186,
153,169,119,227,206,112,167,19,94,109,87,220,173,248,122,123,157,89,140,178,
52,195,17,1,214,232,226,101,209,143,70,120,175,1,190,172,101,138,33,157,
40,37,29,235, };
static unsigned short stb__courier_38_usascii_t[95]={ 1,1,114,1,1,31,97,54,1,1,114,
97,97,25,108,1,1,54,1,1,54,31,1,31,1,1,31,76,97,114,97,
54,1,76,76,54,97,76,76,54,76,76,54,76,76,76,76,54,76,1,54,
54,54,54,54,54,76,76,97,1,1,1,114,25,66,97,31,97,31,97,31,
31,31,31,1,31,31,97,114,97,31,31,114,97,54,97,114,97,114,31,114,
1,1,1,122, };
static unsigned short stb__courier_38_usascii_a[95]={ 322,322,322,322,322,322,322,322,
322,322,322,322,322,322,322,322,322,322,322,322,322,322,322,322,
322,322,322,322,322,322,322,322,322,322,322,322,322,322,322,322,
322,322,322,322,322,322,322,322,322,322,322,322,322,322,322,322,
322,322,322,322,322,322,322,322,322,322,322,322,322,322,322,322,
322,322,322,322,322,322,322,322,322,322,322,322,322,322,322,322,
322,322,322,322,322,322,322, };

// Call this function with
//    font: NULL or array length
//    data: NULL or specified size
//    height: STB_FONT_courier_38_usascii_BITMAP_HEIGHT or STB_FONT_courier_38_usascii_BITMAP_HEIGHT_POW2
//    return value: spacing between lines
static void stb_font_courier_38_usascii(stb_fontchar font[STB_FONT_courier_38_usascii_NUM_CHARS],
                unsigned char data[STB_FONT_courier_38_usascii_BITMAP_HEIGHT][STB_FONT_courier_38_usascii_BITMAP_WIDTH],
                int height)
{
    int i,j;
    if (data != 0) {
        unsigned int *bits = stb__courier_38_usascii_pixels;
        unsigned int bitpack = *bits++, numbits = 32;
        for (i=0; i < STB_FONT_courier_38_usascii_BITMAP_WIDTH*height; ++i)
            data[0][i] = 0;  // zero entire bitmap
        for (j=1; j < STB_FONT_courier_38_usascii_BITMAP_HEIGHT-1; ++j) {
            for (i=1; i < STB_FONT_courier_38_usascii_BITMAP_WIDTH-1; ++i) {
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
        float recip_width = 1.0f / STB_FONT_courier_38_usascii_BITMAP_WIDTH;
        float recip_height = 1.0f / height;
        for (i=0; i < STB_FONT_courier_38_usascii_NUM_CHARS; ++i) {
            // pad characters so they bilerp from empty space around each character
            font[i].s0 = (stb__courier_38_usascii_s[i]) * recip_width;
            font[i].t0 = (stb__courier_38_usascii_t[i]) * recip_height;
            font[i].s1 = (stb__courier_38_usascii_s[i] + stb__courier_38_usascii_w[i]) * recip_width;
            font[i].t1 = (stb__courier_38_usascii_t[i] + stb__courier_38_usascii_h[i]) * recip_height;
            font[i].x0 = stb__courier_38_usascii_x[i];
            font[i].y0 = stb__courier_38_usascii_y[i];
            font[i].x1 = stb__courier_38_usascii_x[i] + stb__courier_38_usascii_w[i];
            font[i].y1 = stb__courier_38_usascii_y[i] + stb__courier_38_usascii_h[i];
            font[i].advance_int = (stb__courier_38_usascii_a[i]+8)>>4;
            font[i].s0f = (stb__courier_38_usascii_s[i] - 0.5f) * recip_width;
            font[i].t0f = (stb__courier_38_usascii_t[i] - 0.5f) * recip_height;
            font[i].s1f = (stb__courier_38_usascii_s[i] + stb__courier_38_usascii_w[i] + 0.5f) * recip_width;
            font[i].t1f = (stb__courier_38_usascii_t[i] + stb__courier_38_usascii_h[i] + 0.5f) * recip_height;
            font[i].x0f = stb__courier_38_usascii_x[i] - 0.5f;
            font[i].y0f = stb__courier_38_usascii_y[i] - 0.5f;
            font[i].x1f = stb__courier_38_usascii_x[i] + stb__courier_38_usascii_w[i] + 0.5f;
            font[i].y1f = stb__courier_38_usascii_y[i] + stb__courier_38_usascii_h[i] + 0.5f;
            font[i].advance = stb__courier_38_usascii_a[i]/16.0f;
        }
    }
}

#ifndef STB_SOMEFONT_CREATE
#define STB_SOMEFONT_CREATE              stb_font_courier_38_usascii
#define STB_SOMEFONT_BITMAP_WIDTH        STB_FONT_courier_38_usascii_BITMAP_WIDTH
#define STB_SOMEFONT_BITMAP_HEIGHT       STB_FONT_courier_38_usascii_BITMAP_HEIGHT
#define STB_SOMEFONT_BITMAP_HEIGHT_POW2  STB_FONT_courier_38_usascii_BITMAP_HEIGHT_POW2
#define STB_SOMEFONT_FIRST_CHAR          STB_FONT_courier_38_usascii_FIRST_CHAR
#define STB_SOMEFONT_NUM_CHARS           STB_FONT_courier_38_usascii_NUM_CHARS
#define STB_SOMEFONT_LINE_SPACING        STB_FONT_courier_38_usascii_LINE_SPACING
#endif

