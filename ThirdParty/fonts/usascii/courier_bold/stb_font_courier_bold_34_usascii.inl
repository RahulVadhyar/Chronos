// Font generated by stb_font_inl_generator.c (4/1 bpp)
//
// Following instructions show how to use the only included font, whatever it is, in
// a generic way so you can replace it with any other font by changing the include.
// To use multiple fonts, replace STB_SOMEFONT_* below with STB_FONT_courier_bold_34_usascii_*,
// and separately install each font. Note that the CREATE function call has a
// totally different name; it's just 'stb_font_courier_bold_34_usascii'.
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

#define STB_FONT_courier_bold_34_usascii_BITMAP_WIDTH         256
#define STB_FONT_courier_bold_34_usascii_BITMAP_HEIGHT        126
#define STB_FONT_courier_bold_34_usascii_BITMAP_HEIGHT_POW2   128

#define STB_FONT_courier_bold_34_usascii_FIRST_CHAR            32
#define STB_FONT_courier_bold_34_usascii_NUM_CHARS             95

#define STB_FONT_courier_bold_34_usascii_LINE_SPACING          16

static unsigned int stb__courier_bold_34_usascii_pixels[]={
    0x00000000,0x11020000,0x00099000,0xb80b9855,0x644effff,0x103ffffe,
    0x03b625d9,0xd7000440,0x5544003b,0x99751000,0x980d5545,0x99750aaa,
    0xa9880015,0x2a60009a,0x2a62001a,0x3ff20001,0x0007fc47,0x01ff8800,
    0x3fe25ff3,0x0bfea001,0x3e2ff980,0xffffb84f,0xffff10ff,0xfff507ff,
    0x980ffead,0x01dffffd,0x2017fffc,0x0effffe8,0x3ffffee0,0xfffffbff,
    0x33ffffa0,0x4ffffffe,0xffffc980,0x7fd403ff,0x2202ffff,0x02fffffd,
    0x547ffc80,0x000005ff,0x3fa07ffb,0x01dff53f,0x800ffee0,0xbff33ffb,
    0xbfffff70,0x3fffffd8,0xf73fffe8,0x3fff207f,0x204fffff,0x2207fffb,
    0xeffffffe,0xfffffd80,0xffffffff,0xfffff12f,0xffffffff,0x3fe201df,
    0x6fffffff,0xffffff90,0xffd10bff,0x009fffff,0x7c47ffc8,0x400001ff,
    0xfa80fff8,0x13ffe0ff,0x37fffee0,0x3fee00cb,0xf70bff33,0x3fee007f,
    0x706ffcc3,0xfffb07ff,0xbffffddf,0x80fff440,0x3faa2ffe,0x5efffe44,
    0xfffffeca,0x7ff6543c,0xfdbaceff,0xfffd06ff,0x9ffffb9b,0xddffffa8,
    0x7ec3ffff,0xffffdeff,0x06662003,0x00013ff2,0x3a0bff90,0x7ffdc5ff,
    0xfffff500,0x640bffff,0x09ff52ff,0x2e007ff7,0x1ffdc3ff,0xff70ffee,
    0x7fe4419f,0x0bff203f,0x3ee07fea,0x40fffe66,0x6c07fffc,0xff505fff,
    0x03dfd07f,0xffe8fff7,0x1fff220c,0x7ec45fff,0x2200006f,0x00000fff,
    0xf303fff1,0xfff883ff,0xffffff03,0x640dffff,0x09ff52ff,0x2e007ff7,
    0x1ffdc3ff,0xff98ffee,0x3ffea02f,0xd05ff901,0x43fe209f,0x7e405ffc,
    0x3ffec07f,0x221bfee0,0x887ff402,0xff880fff,0x10bff50f,0x2a605fff,
    0x2aaaaaaa,0x00027fec,0xfb05ffb8,0x1fff20bf,0x4c2bbfea,0x3f606ffc,
    0x707ff71f,0x3ee007ff,0x21ffdc3f,0x3ff63ffb,0x05ffd805,0x5ff05ff9,
    0xffd8ffc0,0x03ffcc02,0x3e013ff6,0xffd0007f,0xe81bfe21,0x05ff91ff,
    0xff113ff2,0xffffffff,0x00fff98d,0x81fff800,0xf101fff8,0x1ffd85ff,
    0xd7307fb0,0xbffd9bff,0x01ffdc17,0x7dc3ffb8,0xd1ffdc3f,0xff1001ff,
    0x10bff20f,0xffda83ff,0x803ffd1f,0x7ec07ff9,0x0fff803f,0x23ffe400,
    0xffa82fff,0x5407ff67,0x7ffc45ff,0x6fffffff,0x0003ffd8,0xfa837fdc,
    0x27fec07f,0x8080fff2,0xfffffffa,0x2e6fffff,0xff7003ff,0x5c3ffb87,
    0x0dff13ff,0x6407ff40,0x23fcc2ff,0x91fffffd,0xffd80bff,0x03ffec07,
    0x2a01bfee,0x43fffecc,0xc99bfffc,0x3ff25fff,0x50dffd04,0xfb999999,
    0x0fff50df,0x02ffe800,0xfc80bff7,0x77ffcc5f,0xfffa801b,0xffffffff,
    0x00ffee6f,0x3f21ffdc,0x99ffdc3f,0x3f6005ff,0x43ffb81f,0x37ff26fa,
    0xfff51ffa,0x1fffea07,0x019fffb0,0x9809fff3,0x04ffffff,0xfffffffd,
    0x37fdc1df,0x003fffe4,0x7f41bfe6,0xff50003f,0x027fec0d,0x3fa1ffea,
    0x03dfffff,0x2abffea6,0x2e0abffe,0xff7003ff,0x07fffaa7,0x3fea7ff7,
    0x0bff2004,0x547bffea,0xff8ffe6f,0x37ffff61,0x7fffffca,0x7ffffec0,
    0xeffffcbd,0x7fffc400,0xfff505ff,0xd07fffff,0xffb35dff,0x4c001fff,
    0xdff506ff,0x0bffa000,0x4c03ffe8,0xffc80fff,0x00efffff,0x7ff4fff1,
    0x003ffb80,0x3ffa7ff7,0x33ffb85f,0x7f400dff,0xbfffd01f,0x07fcdbea,
    0xfffe83ff,0xffffffff,0x7fffec07,0xffffffff,0xfd951000,0xfff98bff,
    0x1fffffff,0x7fffffd4,0x000fffff,0xfe81bfe6,0x7fd4002f,0x017ffc07,
    0x4407ffe2,0x6ffffeca,0x7f4dff10,0x03ffb80f,0x3f27ff70,0x7fdc0fff,
    0x400fff13,0xfff107ff,0xff9bea9f,0xf9107fe1,0xf9ffffff,0xcffd80ff,
    0xdffffffe,0x3fee0000,0x2ffffa2f,0x86ffeb88,0xcffffffa,0x7cc007ff,
    0x1bfee06f,0x807ffb00,0x7cc02fff,0xf71000ff,0xffa883ff,0x81fff99e,
    0xf7003ffb,0x17ff4c7f,0xffd8ffee,0x06ffb803,0x7d43bff7,0x3e6fbf26,
    0x9995101f,0x3603ffc5,0x599751ff,0x3f200003,0x03fff34f,0x7103fff1,
    0xbff539db,0x06ff9800,0x9800fffc,0x7ec00fff,0x3ffd403f,0xffc80bb1,
    0x3fffffa3,0x1fffffff,0x5c00ffee,0x1ffdc3ff,0xffa8ffee,0x3ffe601f,
    0x987ff702,0x3fffe27f,0xff0004ff,0x01ffd80f,0xff980000,0x6c0bff56,
    0x3fa003ff,0x7fcc003f,0x02ffdc06,0xc804ffd8,0x7fdc05ff,0xd80ffea6,
    0xffff12ff,0xffffffff,0x01ffdc5f,0x7dc3ffb8,0x21ffdc3f,0xfa82fffe,
    0x3ff205ff,0x2e20ff82,0x0004fffe,0xffd80fff,0xb8000001,0x0bff55ff,
    0xd8017fe4,0x4c000eff,0x7fc406ff,0x7ffc401f,0x06ffb800,0xff927fe4,
    0x7ffb987f,0x777ff6d4,0x5c3dfffe,0xff7003ff,0x5c3ffb87,0x7ff443ff,
    0xfffeddef,0x0bff200e,0x04c407fa,0x80fff000,0x20001ffd,0x3fe201c9,
    0x05fff12f,0xa801fff3,0x8001fffe,0xfc806ff9,0x27fe405f,0x00fff980,
    0xffc8fffa,0xfffeefff,0x27ff704f,0xff705ff9,0x0ffee007,0xffb87ff7,
    0xffffe883,0x400effff,0x4fd82ffc,0x36e20000,0x543dfffe,0x1ceefffd,
    0x6f7ff400,0xffffeccc,0x37ffffa0,0x2a6ffffd,0xfffedcef,0xff30002f,
    0x1fff100d,0x003ffe20,0xf504ffe8,0x7ffd41ff,0xefffffff,0x2a5ff900,
    0x7ff704ff,0x70ffee00,0x3ffb87ff,0x3ffffee0,0x5ff9003e,0x0001ff50,
    0x3fffff60,0xfff12fff,0x00ffffff,0xffffffc8,0x441effff,0xfffffffd,
    0x3fff60ef,0x002fffff,0x401bfe60,0xff904ffc,0xfffb800b,0x445ffe80,
    0xffffebdd,0x97fe403e,0xff704ffa,0x0ffee007,0xffb87ff7,0x3ffff603,
    0xff902a82,0x303bf205,0x7fdc00bd,0x20ffffff,0xfffffffe,0xfffc8005,
    0x00dfffff,0x3ffffff2,0xffffe984,0xf980003f,0xfff3005f,0x01fff881,
    0x21fffc40,0xb801fff9,0xffb004ff,0x5c0ffee3,0x5301adff,0xff987ffb,
    0x40ffee2e,0xfffffffd,0x541fffce,0x3fa00ffe,0x05ffeeef,0x4ccccc40,
    0x33333101,0xa9980001,0x5440009a,0x09a8800a,0x3fee0000,0x0fff6004,
    0x2000bff7,0x7fec7ffc,0x07ff7006,0x7dc7ff60,0xffff703f,0xfffff8ff,
    0x5fffe83f,0xff507ff7,0xffffffff,0x7fec1fff,0x7fecc04f,0x0000dfff,
    0x00000000,0x00000000,0x7fcc0000,0x3fe6002f,0x00bffe0f,0x997ffc40,
    0xf7001fff,0x3ff6007f,0x2e03ff70,0x10ffffff,0x07ffffff,0x3eadfff1,
    0xefff982f,0xdffffecd,0x00f7ff41,0x000aaa88,0x00000000,0x00000000,
    0x76dc0000,0x0effffee,0xa97ff400,0x540006ff,0x09ff33ff,0x800ffcc0,
    0x813223d9,0x42ccccca,0x02ccccca,0x01dc3971,0x02a60133,0x00000e4c,
    0x00000000,0x00000000,0xf3000000,0xdfffffff,0x5ff30001,0x0000bfe6,
    0x003b82ee,0x000003b8,0x00000000,0x00000000,0x00000000,0x00000000,
    0x00000000,0xffffff10,0x4c00019d,0x00000cc1,0x00000000,0x00000000,
    0x00000000,0x00000000,0x00000000,0x00000000,0x99998000,0x00000000,
    0x00000000,0x00000000,0x00000000,0x00000000,0x00000000,0x00000000,
    0x00000000,0x00000000,0x00000000,0x00000000,0x00000000,0x00000000,
    0x00000000,0x00000000,0x4c000000,0x2aa601aa,0x51003301,0x54400015,
    0x00000001,0x2639b973,0x00000aaa,0x00000000,0x00000000,0x00000000,
    0x04400000,0x10031000,0x41ffffff,0x0ffffff8,0x74413ffa,0x001dffff,
    0x9ffffd73,0x01ffffc8,0xfffc8800,0xfffeefff,0x7ec4003f,0x366006ff,
    0x00bdeffe,0x2007ffdc,0x006fffd8,0x7ffff540,0x13a6003f,0x7fffd500,
    0x3f660000,0xa801deff,0x02effffd,0x3ffffff3,0x7fffffcc,0x81ffff32,
    0xffffffe8,0x7ffd400e,0xf30fffff,0x0003ffff,0xffffff88,0xffffffff,
    0x7ffdc005,0xfff9006f,0x80ffffff,0x5c00fffb,0x0006ffff,0x7ffffff4,
    0x03ff2003,0x3ffffe80,0xfffc8000,0x904fffff,0xffffffff,0x3ffea0bf,
    0xfffea82e,0x07fffee3,0xffbdfffd,0x7ffdc0bf,0x645fccef,0x0001ffff,
    0x55ffffec,0xbdfffffe,0x7fec4000,0xfffb806f,0x07ffffff,0x2007ffdc,
    0x006fffd8,0x7ffff540,0x3ff6003f,0x3ffaa001,0x7ec0003f,0xfffeefff,
    0xfffff86f,0x04ffffef,0x7f40dff7,0x7fffd43f,0x987bfea1,0xffb83ffe,
    0x3f6000df,0x3ea0001f,0xffe982ff,0x7c40002f,0xcffe806f,0x80155311,
    0x22001998,0x400006ff,0x36003ffb,0xfb8001ff,0x3ee0003f,0x3f220cff,
    0x5fffc3ff,0x03fff221,0x7d417ff4,0xffff987f,0x2a0bffa0,0x7ffd45ff,
    0x1ffd8005,0x17ff6000,0x002fffb8,0x4037fc40,0x000007ff,0x00dff100,
    0x03ffb800,0xacffea88,0x2e00aaaa,0xf30003ff,0x7fd407ff,0xe81ff61f,
    0xdff702ff,0xf307ffd0,0x37fc4fff,0xffe8ffd0,0x3ffb0004,0x002b32ea,
    0x7c405ffd,0xba8802ff,0x0dff12bc,0x557ffd4c,0x54400aaa,0x1001aaaa,
    0x332e6dff,0xffb8000a,0x7fffdc03,0xffffffff,0x987ff703,0xffb00aaa,
    0x4bff900b,0x3ff203ea,0xa8bffa03,0xfff107ff,0x9027fd4f,0x3ffea3ff,
    0x9ffb0000,0x9ffffffd,0x2007ffc0,0x7dc02ffe,0xfbefffff,0xffff886f,
    0xffffffff,0xfffff901,0x3fe2007f,0xffffffef,0x1ffdc002,0x3fffff60,
    0x5fffffff,0x3e27ff70,0xe84fffff,0xff8800ff,0x0fffc007,0x7f4dff70,
    0x9bffe03f,0x3ee03ffb,0x919ff73f,0xfb007bfd,0xffffffff,0xffd01dff,
    0x17ffcc07,0xffffffd0,0x50dfffff,0xffffffff,0x3607ffff,0x03ffffff,
    0xffffff10,0x005fffff,0x2201ffdc,0xccdffecb,0xf700bccc,0x3fffea7f,
    0x37fc45ff,0x001ffd00,0xd00dffd3,0x0fff57ff,0x3ee5fff8,0x53fee03f,
    0xffffdffc,0x3f600eff,0xdbabefff,0xffc85fff,0x0bfff206,0x55efffe4,
    0x06ffffeb,0x99fff997,0x26017999,0x03ffeccb,0x9fffff10,0x00dffd75,
    0xb001ffdc,0xf70003ff,0x3fffee7f,0x2ffcc1bc,0x405ff900,0x03ffffea,
    0xffeeffa8,0x727ff403,0x7fdc07ff,0xffffffb4,0x6c0dffff,0xff504fff,
    0xcfff985f,0x3fffee21,0x02fffa82,0xf00dfff9,0xf70000ff,0x3fe2007f,
    0x0fff80ef,0x007ff700,0x4000ffec,0xfffccffb,0x13fea01e,0x702ffc80,
    0x005fffff,0x03fffff4,0xff727fec,0xda7fdc07,0xc8aeffff,0xffb03fff,
    0x85ffb80d,0xfdeffffc,0xc82fffff,0x7fec04ff,0x007ff806,0x003ffb80,
    0x7ec0fff1,0x7ff7001f,0x00ffec00,0x7ffffdc0,0x7fc400df,0x07ff6006,
    0x0067ffdc,0x0ffffea0,0xfb8fff20,0x4ffee03f,0xfb86fffc,0x07ffb06f,
    0x3f60fff0,0xffffffff,0x0ffe82ff,0x4037fd40,0xb80007ff,0xff1003ff,
    0x017fec0d,0x2003ffb8,0xb8001ffd,0x005fffff,0xff801ffe,0x00bfe607,
    0x007ffe80,0x7fcc3ff5,0x5cbff204,0xff881fff,0x003ffb07,0x3ea01ffd,
    0xfdcfffff,0x807ff82f,0xff806ff8,0xffb80007,0x0dff1003,0xb8017fec,
    0x3f6003ff,0xffb8001f,0xb002ffff,0xff7009ff,0x0003b80d,0x5001fffc,
    0x740dff03,0x0bff31ff,0x7ec0fff4,0x3ffc404f,0xd84d5440,0x1fff81ff,
    0x4037fdc0,0xb80007ff,0xff1003ff,0x017fec0d,0x2003ffb8,0xb8001ffd,
    0x3fffeeff,0x01fffa80,0x000bffe6,0x0fff7000,0x0bff6000,0xff89bfea,
    0x0fff881f,0x6407ffd8,0xf10006ff,0xbffb01ff,0x806ffe80,0xb80007ff,
    0xff1003ff,0x017fec0d,0x2003ffb8,0xca883ffd,0x45ffdc1d,0xc804fffd,
    0xffa82fff,0x8000005f,0x00003fff,0x74c3dff7,0x2ffec3ff,0xfd83ffe4,
    0xfff304ff,0xff910007,0x0bffea0d,0x4037ffdc,0xb80007ff,0xff1003ff,
    0x017fec0d,0x2003ffb8,0xedcefffb,0x7dc4ffff,0x17fff23f,0x37bfffa0,
    0x00ffffed,0x5400ddcc,0xdfffeeed,0x20771002,0xffeefffd,0xffff987f,
    0x43ffffdd,0xfffffffc,0x6fffeccd,0x777764c0,0x3603ffff,0xecccefff,
    0x25ffffff,0xffffffe9,0xd704ffff,0xffffffff,0xffc87dff,0x3faa3fff,
    0x7f5c5fff,0xffffffff,0xffd103ef,0xffffffff,0x0ffffaa3,0x09fffffd,
    0x3fffffa2,0xe800dfff,0x7fcc07ff,0xffffffff,0x84ffd800,0xffffffe8,
    0xffff900f,0xf98bffff,0xffffffff,0x00efffff,0x7fffffec,0x7f4403ff,
    0xffffffff,0xfb2fffff,0xffffffff,0xfff01fff,0xffffffff,0x7ffccfff,
    0x3ff67fff,0x3fe2ffff,0xffffffff,0x36207fff,0xbeffffff,0x8fffffa0,
    0xfffffff8,0x3fffee00,0x3fa003ef,0x7ffc406f,0x06ffffff,0x2607ff90,
    0x00effffd,0x7ffffed4,0x9ffff903,0x7ffffffd,0x3ffff200,0x2e002dff,
    0xbeffffff,0x3a65ffff,0xffffffff,0xffd704ff,0xffffffff,0xffffc87d,
    0x3fffaa3e,0x3ffae0df,0xffffffff,0xaaa8803e,0x3fffaa01,0x7ffffe43,
    0x01551004,0x98006600,0x00999999,0xa9800cc0,0x01a98000,0x06aaa200,
    0x06666200,0x35553000,0x00000000,0x00000000,0x00000000,0x00000000,
    0x00000000,0x00000000,0x00000000,0x00000000,0x00000000,0x00000000,
    0x00000000,0x00000000,0x32200000,0x0c40001c,0xffffffb0,0x83ffffff,
    0xfffffffb,0x0c000dff,0x00044000,0x20000980,0x2e200aa8,0x2a2deeed,
    0x00bdeeed,0x802fffe8,0xeeeeeec9,0x36e23dee,0xcdeeeeee,0x775c400a,
    0xedb83dee,0x36a0bdee,0xceeeeeee,0xd802001b,0x000effff,0x407ffb51,
    0xfffffffd,0x5c1fffff,0xffffffff,0x6dcc04ff,0x4c8bffff,0x7fffed40,
    0xc9804bad,0xbadffffe,0x3ffb200c,0xffb82eff,0xf88fffff,0x04ffffff,
    0x017fffd4,0x7ffffff4,0xf71fffff,0xffffffff,0x7e407fff,0x21ffffff,
    0xfffffff9,0xffffff14,0x1bffffff,0x2077f4c0,0x3fc99dfa,0x7ffff5c0,
    0x3fff603f,0xffffffff,0x7fffdc1f,0x01efffff,0x3fffffee,0xb02fffff,
    0xffffffff,0x7fdc05ff,0xffffffff,0xfffe882f,0x544fffff,0x26ffffff,
    0x2ffffffe,0x3ffffe20,0xffffc802,0x0fffffff,0xfffffff3,0x09ffffff,
    0x3fffffe6,0x7ffffc0f,0x3fffa1ff,0xffffffff,0xfffb00ef,0x3740fd87,
    0xffffff50,0x07fe407f,0x5c0fff88,0xf70003ff,0xfffdffff,0xff907fff,
    0xffffdfff,0x3fff207f,0xfffffeff,0xffffe84f,0x82ffffec,0x9880affe,
    0x7e400eff,0x1002ffff,0x3bff7333,0x27ffe603,0xfffeb999,0x1dff9102,
    0x067ff440,0x4cd7fec4,0x04fffdb9,0x5f85fff7,0xff301fc8,0x407ffbbf,
    0x3fea02b8,0x003ffb85,0x41dfffb8,0x443fffe9,0x3221cfff,0xffb84fff,
    0x7fdc41cf,0x17ffd44f,0x3a1bff62,0x3fe200ff,0x77ffcc06,0xf50002ff,
    0x6ff8809f,0x8813ff60,0x3e201fff,0x3ff600ff,0x40fff501,0x40fd82db,
    0xf70c406f,0xfd80007f,0x03ffb83f,0x027ffc40,0xff50fff6,0x21ffe40d,
    0x5c04fff8,0x1ffec3ff,0x740fff88,0x3fe200ff,0x66ffec06,0xf50002ff,
    0x6ff8809f,0x901bfe60,0x7fe409ff,0x00ffec05,0x50003ffd,0x07fb57df,
    0x003ffb80,0x203ffe20,0xdedcdffb,0x0bff500b,0xfa85ff50,0x07fe604f,
    0xf100bff7,0x405fa83f,0x7ff41ffe,0x81bfe200,0xffc8fffa,0x9ff50002,
    0x206ff880,0x7cc04ffb,0x07ffe07f,0x2203ffb0,0x90000fff,0x2619ffff,
    0x3fee03fc,0x3fea0003,0xfffff705,0xf907ffff,0x2132007f,0x2602fff8,
    0x003ffd82,0x7ff98000,0x2200ffe8,0x3ffa06ff,0x0005ff94,0xf1013fea,
    0xfffb30df,0x07ffd005,0xfb00dff5,0x1ffee03f,0x2a2ea000,0x202ffffc,
    0x20003ffb,0xff703ffd,0xffffffff,0x001ffe87,0xcefffe80,0x0ffe800a,
    0x74400000,0x0ffe85ff,0x5c1bfe20,0x5ff90fff,0x13fea000,0xdddfff10,
    0x00bfffff,0x3fa1bfea,0xaffd803f,0xfffdb999,0xfda80004,0xb802cfff,
    0xf10003ff,0x3fe601ff,0xffeb9adf,0x001ffe0f,0x7ffff440,0xff01ceff,
    0x8800000f,0xfe81fffe,0x1bfe200f,0xfc8bffe2,0x5402982f,0x7fc404ff,
    0xffffffff,0x0fffc003,0x3600fff3,0xffffffff,0x2aaa05ff,0xffffda81,
    0x7fdc001c,0xbff50003,0x3fa01980,0x001ffe3f,0xfffec880,0xff82ffff,
    0x99997307,0xfd100159,0x3ffa05ff,0x21bfe200,0x7fe46ffd,0x5017fc42,
    0xff8809ff,0x6fffffff,0x25ffc800,0xfb004ffc,0xffffffff,0x0fffcc09,
    0x2273fff2,0xf7002deb,0x3f60007f,0x7dc0003f,0x001ffe5f,0x7fedcc00,
    0x3ffc2fff,0x7fffffcc,0x7f4c04ff,0x3ffa03ff,0x31bfe200,0xb3337fff,
    0x4ffa87ff,0x1013fea0,0xfb333fff,0xf8800bff,0x0fff88ff,0xfffffb00,
    0xfc8039bd,0x261b985f,0x806fffff,0x88003ffb,0x40000fff,0x3ff66ff9,
    0x98000000,0x7ff45ffe,0x7ffffcc0,0x3e604fff,0x7e402fff,0x17fe602f,
    0xfffffffb,0x7d4dffff,0x13fea04f,0xf90dff10,0xfd800bff,0x005ffbbf,
    0x40007ff6,0xf9000ffe,0x700bf225,0xf50007ff,0xf30000bf,0x01ffdcdf,
    0x200bf200,0x0ffe47ff,0x7fee65cc,0x3fffea05,0x06ffb801,0xffb0fff2,
    0xffffffff,0x13fea1ff,0x4402ffc8,0xfff706ff,0x77fd4005,0x36002ffe,
    0xf98001ff,0x8bf1003f,0x7fdc06f8,0x3ffd8003,0x4ffc8000,0x2003ffe2,
    0x03ffc1da,0xfa83ffe2,0x4ffa806f,0x03dfff90,0x033ffe60,0xec83fff7,
    0xffeeeeee,0x3bfea2ef,0x01fffa81,0xf9037fc4,0x7f4001ff,0x6c007fff,
    0xfb8001ff,0x213e6006,0x1ffdc07e,0x03ffe200,0xf300beb8,0xfffe87ff,
    0x89bff203,0xd980dfff,0x7ff447ff,0x9ff9101d,0x0efffd88,0x7fffdc00,
    0x04ffffdd,0x542ffc80,0xecdfffff,0x36204fff,0x82efffff,0x800efffe,
    0x003ffffb,0xfffffff9,0x03fd009f,0x3e60fe80,0x01ffdc04,0xd01bfea0,
    0xd999dfff,0xfb10dfff,0xfd99bfff,0x7fc49fff,0xffddefff,0xff983fff,
    0xffdcdeff,0x3fa24fff,0x802605ff,0xfffffffc,0x3fa6005f,0x3a64ffff,
    0xffffffff,0x7ffdc04f,0xf986ffff,0xf8803fff,0xf8800fff,0xffffffff,
    0x001fc01f,0x7fee7fd4,0x3ffff620,0x0dffffff,0x500bff20,0xffffffff,
    0x7ec03fff,0xffffffff,0xfffff84f,0x5fffffff,0x3ffffee0,0x2fffffff,
    0x3fffffea,0x07ffffff,0x7fffffd4,0x7ffe4002,0x64c0ffff,0x03efffff,
    0xfffffd88,0x1bff702e,0x017ff200,0xffffffc8,0x000804ff,0x0b7ffae0,
    0xfffffff5,0x407fffff,0xfb5005e9,0x19ffffff,0xfffd9700,0x3ae05bff,
    0xffffffcb,0xfec8802e,0x83efffff,0xfffffffa,0x01ffffff,0x0000aa88,
    0x9fffffd3,0x000aa880,0x00000000,0x00000000,0x880cc000,0xfffffffd,
    0x0000dfff,0x19aa9880,0x02aa2000,0x04d54c00,0x13553000,0x7ffffd40,
    0xffffffff,0x00000001,0x00000000,0x00000000,0x00000000,0x00000000,
    0x00000000,0x00000000,0x00000000,0x00000000,0x00000000,0x00000000,
    0x20000000,0x0bdeeedb,0x37bbb6e2,0x3bbbbb23,0xeeeeeeee,0x3bbb264e,
    0x8803deee,0x1ceeeedb,0x07bddb71,0x707bddb7,0xdb87bddb,0xeeeeeeee,
    0x7775c43d,0x3bbb6a3d,0x6f76dc1c,0x3deedb83,0x777776dc,0xeeeeeeee,
    0xddddb713,0xdddddddd,0x7776dc4b,0x200aceee,0xeeeeeee8,0x711eeeee,
    0xdddddddb,0x0000037b,0xffffff88,0x3fffee4f,0xfffb1fff,0xffffffff,
    0x7ff4bfff,0x2fffffff,0x7ffffdc0,0xffff76ff,0x7ffcc5ff,0x3fe61fff,
    0xff51ffff,0xffffffff,0x7ffe45ff,0xfff89fff,0x3fe65fff,0x3e61ffff,
    0xf51fffff,0xffffffff,0x29ffffff,0xfffffffa,0x7fffffff,0x3fffffee,
    0x80cfffff,0xfffffff8,0xf71fffff,0xffffffff,0x4001bfff,0x7c400ee8,
    0x22ffffff,0xfffffff9,0xffffffb0,0xffffffff,0x7ffffe4b,0x4c00ffff,
    0x4fffffff,0x1ffffff5,0x2fffffc4,0x3fffffe2,0xffffff30,0x43ffffff,
    0x0ffffffa,0x47fffffd,0x0ffffff8,0x3fffffe2,0xffffff30,0xffffffff,
    0x3fffe69f,0xffffffff,0x3ffe67ff,0xffffffff,0x7ffc40ff,0xffffffff,
    0xfffff31f,0xffffffff,0x17fd400d,0x01affe80,0xfb1ffe66,0x9ff9335f,
    0x88bff533,0x019effa9,0x04f7fcc0,0x405ffff3,0xfa82fffa,0x933302ff,
    0x203339ff,0xd880eff9,0xfff702ff,0x07fff707,0x2667ffe6,0x4ffb9999,
    0x4ccfffcc,0x87ff9999,0xb999affd,0x7c46fffd,0xe99999ef,0x7fcc0eff,
    0xfdb9999e,0xff7003ff,0x87ff6007,0x3fe61aa9,0xf70ffec5,0x82ffcc7f,
    0x10005ff9,0xfffa8dff,0xfffc801e,0x013ffe20,0x4401ffdc,0x3ff606ff,
    0x87fff201,0x7c04fff9,0x27fd407f,0xff01bfe2,0x203ffb0f,0x3e23fffa,
    0x1fffc86f,0x2e06ff88,0xff7005ff,0x8bff2007,0x3fea6ffe,0xf70ffec5,
    0x82ffcc7f,0x10005ff9,0x7ffe4dff,0x3ffa000e,0x801bff65,0xf8803ffb,
    0x07ff606f,0xf11fffb0,0xfff00bff,0x0bfe6398,0x23a8dff1,0x1ffd85fe,
    0xf89bfee0,0x1fffd45f,0x2606ff88,0xff7006ff,0x4ffee007,0xf71ffff8,
    0x20ffd89f,0x3fe23ffb,0x00bff304,0x7edbfe20,0x4c000dff,0xfffaafff,
    0x0ffee001,0xd81bfe20,0x7f4401ff,0x00effeef,0x3fe67ff8,0xff103322,
    0xda97fccd,0x401ffd81,0x8ffa1ffe,0x2204fff8,0xffb106ff,0x0ffee009,
    0xfba7fd40,0x7ff93fff,0x7fdc5fa8,0xf980fec3,0xff10005f,0x009fffbf,
    0x7ffffe40,0x7fdc004f,0xafff8803,0xffeaaaaa,0xffff8801,0xfff001ff,
    0x009ff955,0xf955fff1,0x3ffb007f,0x222ffd80,0x01bffa21,0x7555fff1,
    0x003ffffb,0x5400ffee,0xffffd5ff,0x400bff6d,0x4c003ffb,0xf10005ff,
    0x0bffffff,0xffffe800,0x3ffb8006,0xfffff880,0x1fffffff,0x5ffff300,
    0x7ffffc00,0xf8804fff,0x4fffffff,0x401ffd80,0x3f603ffb,0x7fc400ff,
    0xffffffff,0xfffe984f,0xffffffff,0x77fcc1ef,0x9ffffff8,0xf7001ffd,
    0xff98007f,0xfff10005,0x00bfffff,0x0ffffcc0,0x01ffdc00,0x7fffffc4,
    0x01ffffff,0x07ffff50,0x7fffffc0,0xff8804ff,0x04ffffff,0x5401ffd8,
    0xfff704ff,0xffff1005,0xffffffff,0xfffffd83,0xffffffff,0x5fffc45f,
    0xebffcdff,0xff7000ff,0x5ff98007,0x3e20f620,0xfffcafff,0x3ff20006,
    0x7ff70004,0x99fff100,0x3ffd9999,0xfffff300,0x3ffe003f,0x804ffdcc,
    0xfdccfff8,0x1ffd803f,0x4c1ffdc0,0x88084fff,0xdccccfff,0x261fffff,
    0xfffffffd,0x81dfffff,0x9affefff,0x007ffeff,0x3000ffee,0x3fe40bff,
    0xf307ffc4,0x2e0007ff,0xf70003ff,0xdff1007f,0x200ffec0,0xffdeffe8,
    0x27ff800f,0xf8802ff9,0xa8ffe66f,0x401ffd83,0x7fc42ffd,0x443fd85f,
    0xfd5106ff,0x7ff700bf,0x7ffff400,0x1bffffe7,0x003ffb80,0xfb02ffcc,
    0x86ff883f,0x8000fffb,0x70003ffb,0xff1007ff,0x00ffec0d,0x3a23fffa,
    0x7ff806ff,0x7c40065c,0xf8865c6f,0x00ffec2f,0xffb03ffe,0x88dff01d,
    0x7fcc06ff,0x03ffb807,0x97ffff60,0x005ffffc,0x3000ffee,0x7fec0bff,
    0xd837fc41,0xfb8003ff,0xff70003f,0x0dff1007,0xf900ffec,0x7ffc43ff,
    0x003ffc05,0xa80dff10,0x0ffec4ff,0xfc8dffb0,0x6ff881ff,0x74037fc4,
    0x7fdc00ff,0x3fff2003,0x3fffe62f,0x0ffee004,0x40bff300,0x7fc41ffd,
    0x01fff306,0x003ffb80,0x1007ff70,0x7fec0dff,0x07fff701,0x7c09fff5,
    0x3e20007f,0x27fd406f,0xb5307ff6,0x7fd43fff,0x8dff103f,0x93106ff8,
    0xff700fff,0x7ffdc007,0x27fffc0f,0xfffffb10,0xd501bfff,0xffffffff,
    0x23ffffff,0xefffffd8,0x1f7ffec2,0xfffffd88,0xd880dfff,0xffffffff,
    0x3ff20dff,0x3fb24fff,0x3fa65fff,0x3621efff,0xb11effff,0xdfffffff,
    0xfffd8807,0xffffffff,0xffb14fff,0xffffffff,0xfffd87ff,0xffffffff,
    0xffffb16f,0xffffffff,0xff7009ff,0x7ffd4007,0x03fffc85,0x3fffffee,
    0xfe82ffff,0xffffffff,0x71ffffff,0xdfffffff,0x07ffff98,0xfffffff5,
    0xff707fff,0xffffffff,0x3ffe67ff,0xff89ffff,0xf92fffff,0x5c9fffff,
    0x54ffffff,0xffffffff,0xfffb80df,0xffffffff,0xff74ffff,0xffffffff,
    0xfffb07ff,0xffffffff,0x3fffeedf,0xffffffff,0xff5005ff,0x7ffcc005,
    0x02fff982,0x3fffff62,0xea80dfff,0xffffffff,0x11ffffff,0x5dfffffb,
    0x207dffd0,0xffffffd8,0xfd880dff,0xffffffff,0x3fff60df,0x3ffb25ff,
    0xffb30dff,0x7ec43bff,0xfb11efff,0x7dffffff,0xffffd880,0xffffffff,
    0xfffb14ff,0x179dffff,0x3fffff60,0x6fffffff,0xffffffb1,0x03bdffff,
    0x00076c40,0x00000000,0x00000000,0x00000000,0x00000000,0x00000000,
    0x00000000,0x00000000,0x40000000,0xeeeeeec8,0x3bb6a004,0x6f76c00e,
    0x17776d43,0x677776d4,0x88000000,0x000aaccb,0x20110000,0xaa882aaa,
    0x65cc00aa,0x88001bcc,0x4000acca,0x00abcba8,0x4b332ea0,0xccca8800,
    0x5544010b,0x072e60aa,0x3fff6000,0x800fffff,0x04fffff8,0x4bffffee,
    0x0ffffff8,0x7ffffffc,0x0003bf34,0x7ffff4c0,0x2600007f,0x93ff21fd,
    0x547ffff9,0x902fffff,0xffffffff,0xffd1001d,0x003dffff,0xfffffff5,
    0x7ff5401b,0x06ffffff,0xffffffb1,0xff50dfdf,0xffb15fff,0xffd03dff,
    0x3ffee01f,0x004fffff,0x01fffffd,0x83fffffa,0x45fffffe,0x2ffffffe,
    0x003bfffb,0xfffff880,0x40000fff,0xf15fffd8,0x3fea1fff,0x7ffe47ff,
    0xfff882ff,0xefffffff,0x3fffe600,0x01ffffff,0x3ffffff6,0xfb82ffff,
    0xffffffff,0x7ffcc0ff,0xffffffff,0x7fffe41f,0xffffffdf,0x1fffc46f,
    0x3ffe6620,0x3f6007ff,0xffa83fff,0xffd106ff,0xff9885ff,0x3fffe60f,
    0xf70000cf,0x03df75df,0x7ffe4400,0x1bffa1ff,0xb88fff97,0xf902ffec,
    0xff95579d,0x3ffe607f,0xfffcaacf,0xefffc81f,0xffffdbac,0x5677ffc0,
    0x41fffeba,0xcabcfffe,0x441ffffd,0xfffffecb,0x546febcf,0x3ea006ff,
    0x002ffeef,0xb0dffffb,0x6c0dffff,0xff06ffff,0xffff910f,0xffb0007f,
    0x2e000045,0x40cfffff,0xfff00bb8,0x0017fe40,0xfd04ffb8,0xffb101bf,
    0x04fffa8f,0x7c4bffd1,0x8ff900ff,0xf301effc,0x7fe403ff,0x204c0eff,
    0x36003ffd,0x05ffbbff,0x5fffffb0,0x37ffffcc,0x9fffffb0,0x6cc0fff0,
    0x002fffff,0x0000fff6,0x37ffffaa,0x1ffe0001,0x4c02ffc8,0xffcccdcb,
    0x00eff885,0xff90fffc,0x3333333d,0x7ec1fff5,0x2a0abdef,0x200fffc0,
    0x7fe407fc,0x1bfe004f,0x88fff880,0xfd800fff,0x3f26ffdf,0x3606ffdf,
    0x41fffcff,0xfe9807ff,0xa801efff,0x30000fff,0x05dffffd,0x40fff000,
    0xfd302ffc,0xffffffff,0x007ff50b,0x7ff47ff9,0xffffffff,0x3e62ffff,
    0xdfffffff,0x4037fc40,0x7fe402b8,0x0bfe6003,0x324ffc80,0xffd804ff,
    0xff89fffa,0x3606ffaf,0x46ffd9ff,0x3ea007ff,0x400dffff,0x44005ffe,
    0x02fffffd,0x81ffe000,0xffa82ffc,0xffffffff,0x02ffc85f,0x3fe5ff98,
    0xffffffff,0x543fffff,0xfffffffe,0x017fe62f,0x02ffc800,0xf001bee0,
    0x3ffcc3ff,0x7e4ffec0,0xf8dffbdf,0x27ff606f,0x3fe3fff8,0xfffb8007,
    0xffb80cff,0x837912ff,0x3fffffc8,0x7ff80000,0xf10bff20,0x7557dfff,
    0xff70bffb,0x47ff900b,0xeeeeeffe,0x2eeeeeee,0xffd97310,0x1bfe23ff,
    0x2ffc8000,0x800bf600,0xffe86ffa,0x44ffec02,0x89ffffff,0x3ff606ff,
    0x3e1fff71,0xff30007f,0x7dc1dfff,0xfa8fffff,0xfffd10ff,0x000005ff,
    0xffc81ffe,0x8077fdc2,0xff885ff9,0x3ffe201f,0x0017ff21,0x3f602fcc,
    0x003ffe4f,0x0bff2004,0x6c003b80,0xfeeeefff,0x7fec05ff,0x2dffffb1,
    0x3f606ff8,0x7d7ffa1f,0x7e44007f,0x7c43ffff,0xddffecff,0x7fdc1fff,
    0x4000cfff,0x07ffe019,0xc85fffb3,0xffb884ff,0x7dffd05f,0x3fff5441,
    0x8033ffe6,0x33ff22a9,0x6cdff700,0x36201eff,0x0bff204f,0xff880000,
    0xffffffff,0x3ff600ff,0x25ffff31,0x3f606ff8,0x2fffe61f,0x3ee007ff,
    0xa80cffff,0xffff34ff,0x3f2205ff,0xb003ffff,0x3ff60dff,0xffffeccf,
    0x3ffea4ff,0xffffecce,0x7fcc4fff,0xfffddfff,0xfffb81ff,0xffedccef,
    0xffffb2ff,0xffffd99b,0x77fff447,0xfffedccc,0x7ffffec6,0x01dfffff,
    0xffffc800,0xffffffff,0xd87ff604,0x1bfe27ff,0x7e41ffd8,0xa807ffff,
    0x00dfffff,0xffb8bff2,0xfd8805ff,0x2202ffff,0xf981ffff,0xffffffff,
    0x3f60ffff,0xffffffff,0x440fffff,0xfffffffe,0x3ff201ff,0xffffffff,
    0xffff92ff,0xbfffffff,0xffffff30,0x41ffffff,0xfffffff9,0x004fffff,
    0x99afff80,0x7ffa9999,0xe987ff60,0x81bfe23e,0xffe81ffd,0x3fa607ff,
    0xb801efff,0x7ffec4ff,0x3ffa6002,0xffd02eff,0x7fffcc0d,0x4fffdcff,
    0x7ffffe44,0x4ffffcdf,0xffffd910,0xfd30019d,0x9fffffff,0x7ff6f4c3,
    0x202effff,0xffffffc8,0xffd81cff,0xffffffff,0x7d40001d,0x2ffd806f,
    0x1003ffb0,0x7fec0dff,0x7ffff981,0xfffffd98,0x3ffe6002,0xfffffdce,
    0x7ff54005,0x02a81dff,0x00035530,0x00135551,0x000aa880,0x13555310,
    0x2aaaa200,0x2aa62001,0x000009aa,0xffd98000,0xffd85fff,0xfb10efff,
    0xf90bffff,0x443dffff,0x44fffffd,0x7d47fffc,0x0003ffff,0xfffffff9,
    0x0005ffff,0x05fffff7,0x00000000,0x00000000,0x00000000,0x00000000,
    0xfffff900,0x7ffcc3ff,0xff74ffff,0x443fffff,0x4fffffff,0x3fffffee,
    0x1fffe21f,0x0019fff9,0xfffffb80,0x0005ffee,0x817fff22,0xa8000dd8,
    0x20999801,0x55551998,0x77777764,0xeeeeeeee,0x00597104,0xeb829800,
    0xffffffff,0xffffffff,0x3bbba64f,0xeeeeeeee,0xffffb301,0xffffb0bf,
    0x3ff623bf,0xffc85fff,0x3621dfff,0xa84fffff,0x0e74c7ff,0x55310000,
    0x22000003,0x3fea01ec,0x07fcc002,0xfd93ffe0,0x26dffd6f,0xffffffff,
    0xffffffff,0x6ffffcc2,0x3d90e440,0xff1bff60,0xffffffff,0xffffffff,
    0x3ffe63ff,0xffffffff,0x0000001f,0x00000000,0x00000000,0x00000000,
    0x4007ff70,0x200effe8,0x3ff23ffe,0x3a2bffb5,0xffffffff,0x0effffff,
    0x3fffffe6,0x5cffd11e,0x7ffc42ff,0x3ffff20f,0xffffffff,0x24ffffff,
    0xeeeeeee9,0x401eeeee,0xa880aaa8,0x155300aa,0x5e543993,0x99554400,
    0x5400accb,0xaaaaaaaa,0x55440aaa,0x2aaa200a,0x0aaaa880,0x81aaaa88,
    0x88ffee08,0x3ffff600,0xb8bff605,0x89ff94ff,0x99999998,0xe8099999,
    0xffffbeff,0x7dc6ffeb,0x037fec3f,0x00000000,0xfffffb80,0x3fffff65,
    0x37fffe63,0xffecffff,0xfff905ff,0xffffff9f,0x3fffe207,0xffffffff,
    0x3fffff62,0xfffffb83,0x3fffff65,0x3ffff65f,0x3bfe66ff,0xfebcffcb,
    0xffffc81f,0x3ff904ff,0xffb9ffd4,0xff000003,0x3fffa21d,0xff981fff,
    0x000014c3,0x90000000,0x6cdfffff,0x2a4fffff,0xffffffff,0xffffffff,
    0xfffffd83,0x3fffffff,0xffffff88,0x22ffffff,0x84fffffe,0x27fffffc,
    0x6ffffffe,0x3ffffffa,0x3ffffee7,0x2fffffff,0x7ddfffdc,0x0ffb82ff,
    0x7fccbfe6,0x4ccccc42,0x09999999,0x7ec40b98,0x36201fff,0x00000003,
    0x64400000,0x3ea2ffff,0x75c0cfff,0xffdadfff,0x85ffcbef,0xcfffffc8,
    0x887ffdba,0xeccccfff,0x3660efff,0xaa88beff,0x1dffec88,0x33fffae6,
    0x3bffb261,0x7fffdc1c,0x43ffffff,0x3f64fff9,0x23fd41ff,0x3ff11ff8,
    0x3fffffa2,0xffffffff,0x2e6000ff,0x00000002,0x00000000,0xaaffffa8,
    0x3202ffff,0x3ffea5ff,0x7c0fff10,0xffe80eff,0x7d45ff81,0xff980eff,
    0xfd97ff26,0x1fff101f,0x803fff10,0x1dffffe9,0xe85fff88,0x1be20fff,
    0x30ff83fe,0xffffffff,0xffffffff,0x00000005,0x00000000,0x7f4c0000,
    0x01efffff,0xff517fe4,0x3e07ff89,0x5ff900ff,0x7fd45d70,0x3ffe00ef,
    0xf0ffff88,0x4ffd80ff,0x8805ffc8,0x80ffffff,0xe880effb,0x642743ff,
    0x3b6e3746,0xeeeeeeee,0x0003deee,0x00000000,0x00000000,0xeffffe88,
    0x22ffc800,0x3ffc4ffa,0x7e40fff0,0xfffa802f,0x57fec00e,0xf9bffffa,
    0x7ffcc06f,0x007ffe20,0x3ffbbff6,0x200ee885,0x20000ee8,0x00000019,
    0x00000000,0x00000000,0xffffd800,0x45ff9005,0x3ffc4ffa,0x7e40fff0,
    0x7ffd402f,0xcffb800e,0xfbeffffe,0x4ffd804f,0x2a017ff2,0xfff99fff,
    0x00000002,0x00000000,0x00000000,0x00000000,0x7ffff440,0x7e400eff,
    0xf13fea2f,0x03ffc0ff,0x7d405ff9,0xf3000eff,0xffffffff,0xf3005fff,
    0x3fff11ff,0x5c5ff700,0x000003ff,0x00000000,0x00000000,0x00000000,
    0x3ffa2000,0x0efffbbf,0xfa8bff20,0xf03ffc4f,0x17fe40ff,0x40efffa8,
    0x3fffe03a,0xfffffccf,0x79ffb000,0x15c00dff,0x000001d4,0x00000000,
    0x00000000,0x00000000,0xffff3000,0x0ffffd45,0x3ea2ffc8,0xf03ffc4f,
    0x17fe40ff,0x2077ffd4,0xffb02ff8,0xffff13ff,0x7ffcc00d,0x00002fff,
    0x00000000,0x00000000,0x00000000,0x00000000,0x1fffffec,0x1bfffff7,
    0x53ffff62,0xff0dfffa,0x7ffe43df,0x3ff623ff,0x3ffe64ff,0xffffffff,
    0xdfff704f,0x0027ffec,0x01bffff6,0x00000000,0x00000000,0x00000000,
    0x00000000,0xffff3000,0x7fff4fff,0xfff52fff,0xfff51fff,0x53fffe5f,
    0x7ffffff8,0x3fffffea,0xffffff50,0x09ffffff,0xfa8fffe6,0x7cc002ff,
    0x00002fff,0x00000000,0x00000000,0x00000000,0x00000000,0x3effffd8,
    0x37ffffaa,0x9ffffb10,0x7c37ffea,0x3ff21eff,0x3f624eff,0x3fea4fff,
    0xffffffff,0x3ffe04ff,0x0007ffc0,0x00037ff4,0x00000000,0x00000000,
    0x00000000,0x00000000,0x00000000,0x00000000,0x00000000,0x00000000,
    0x00000000,0x00000000,0x00000000,0x00000000,0x00000000,
};

static signed short stb__courier_bold_34_usascii_x[95]={ 0,6,3,1,2,2,3,7,7,3,2,1,6,2,
6,2,2,2,1,1,2,1,3,2,2,3,6,5,-1,0,1,3,2,-1,0,0,0,0,1,0,0,2,1,0,
0,-1,-1,0,1,0,0,1,1,0,-1,-1,0,0,2,7,2,3,2,-2,6,1,-1,1,0,0,2,0,0,1,
2,1,1,-1,0,1,-1,1,1,2,2,0,0,-1,0,0,2,5,7,4,1, };
static signed short stb__courier_bold_34_usascii_y[95]={ 24,4,5,3,3,5,7,5,4,4,5,6,19,14,
20,2,4,4,4,4,5,5,4,5,4,4,10,10,6,11,6,5,4,6,6,5,6,6,6,5,6,6,6,6,
6,6,6,5,6,5,6,5,6,6,6,6,6,6,6,5,2,5,4,30,3,10,4,10,4,10,4,10,4,4,
4,4,4,10,10,10,10,10,10,10,5,10,10,10,10,10,10,5,5,5,12, };
static unsigned short stb__courier_bold_34_usascii_w[95]={ 0,6,11,16,14,14,14,4,8,8,14,16,7,14,
6,14,14,14,15,15,14,15,14,14,14,14,6,8,18,18,18,13,13,20,18,18,17,17,17,18,18,14,18,19,
18,20,19,18,17,18,19,16,16,18,20,20,18,18,14,8,14,8,14,22,6,17,19,17,19,17,16,18,18,16,
12,17,16,20,18,16,19,18,17,14,16,18,19,20,18,18,14,8,4,9,16, };
static unsigned short stb__courier_bold_34_usascii_h[95]={ 0,21,10,24,25,20,18,10,25,25,13,18,10,3,
5,26,21,20,20,21,19,20,21,20,21,21,15,18,18,9,18,20,23,18,18,20,18,18,18,20,18,18,19,18,
18,18,18,20,18,24,18,20,18,19,18,18,18,18,18,24,26,24,11,4,6,15,21,15,21,15,20,21,20,20,
27,20,20,14,14,15,21,21,14,15,20,15,14,14,14,21,14,24,24,24,7, };
static unsigned short stb__courier_bold_34_usascii_s[95]={ 254,20,146,77,62,1,82,158,44,53,116,
238,246,236,206,29,27,16,117,208,152,46,42,31,224,239,116,245,97,163,63,
240,155,1,219,62,186,168,150,98,112,97,167,58,39,22,43,221,227,126,186,
81,22,133,206,1,131,78,204,94,14,103,131,213,199,142,57,210,96,177,116,
77,150,133,1,203,169,20,41,160,188,169,228,195,186,123,96,75,1,1,60,
112,121,145,182, };
static unsigned short stb__courier_bold_34_usascii_t[95]={ 1,29,107,1,1,51,91,107,1,1,107,
72,91,107,107,1,29,51,51,1,51,51,29,51,1,1,91,51,91,107,91,
29,1,91,72,51,72,72,72,51,72,72,51,72,72,91,91,29,51,1,51,
51,72,51,51,72,72,72,72,1,1,1,107,107,107,91,29,91,29,91,29,
29,29,29,1,29,29,110,110,91,1,1,91,91,29,91,110,110,110,29,110,
1,1,1,107, };
static unsigned short stb__courier_bold_34_usascii_a[95]={ 288,288,288,288,288,288,288,288,
288,288,288,288,288,288,288,288,288,288,288,288,288,288,288,288,
288,288,288,288,288,288,288,288,288,288,288,288,288,288,288,288,
288,288,288,288,288,288,288,288,288,288,288,288,288,288,288,288,
288,288,288,288,288,288,288,288,288,288,288,288,288,288,288,288,
288,288,288,288,288,288,288,288,288,288,288,288,288,288,288,288,
288,288,288,288,288,288,288, };

// Call this function with
//    font: NULL or array length
//    data: NULL or specified size
//    height: STB_FONT_courier_bold_34_usascii_BITMAP_HEIGHT or STB_FONT_courier_bold_34_usascii_BITMAP_HEIGHT_POW2
//    return value: spacing between lines
static void stb_font_courier_bold_34_usascii(stb_fontchar font[STB_FONT_courier_bold_34_usascii_NUM_CHARS],
                unsigned char data[STB_FONT_courier_bold_34_usascii_BITMAP_HEIGHT][STB_FONT_courier_bold_34_usascii_BITMAP_WIDTH],
                int height)
{
    int i,j;
    if (data != 0) {
        unsigned int *bits = stb__courier_bold_34_usascii_pixels;
        unsigned int bitpack = *bits++, numbits = 32;
        for (i=0; i < STB_FONT_courier_bold_34_usascii_BITMAP_WIDTH*height; ++i)
            data[0][i] = 0;  // zero entire bitmap
        for (j=1; j < STB_FONT_courier_bold_34_usascii_BITMAP_HEIGHT-1; ++j) {
            for (i=1; i < STB_FONT_courier_bold_34_usascii_BITMAP_WIDTH-1; ++i) {
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
        float recip_width = 1.0f / STB_FONT_courier_bold_34_usascii_BITMAP_WIDTH;
        float recip_height = 1.0f / height;
        for (i=0; i < STB_FONT_courier_bold_34_usascii_NUM_CHARS; ++i) {
            // pad characters so they bilerp from empty space around each character
            font[i].s0 = (stb__courier_bold_34_usascii_s[i]) * recip_width;
            font[i].t0 = (stb__courier_bold_34_usascii_t[i]) * recip_height;
            font[i].s1 = (stb__courier_bold_34_usascii_s[i] + stb__courier_bold_34_usascii_w[i]) * recip_width;
            font[i].t1 = (stb__courier_bold_34_usascii_t[i] + stb__courier_bold_34_usascii_h[i]) * recip_height;
            font[i].x0 = stb__courier_bold_34_usascii_x[i];
            font[i].y0 = stb__courier_bold_34_usascii_y[i];
            font[i].x1 = stb__courier_bold_34_usascii_x[i] + stb__courier_bold_34_usascii_w[i];
            font[i].y1 = stb__courier_bold_34_usascii_y[i] + stb__courier_bold_34_usascii_h[i];
            font[i].advance_int = (stb__courier_bold_34_usascii_a[i]+8)>>4;
            font[i].s0f = (stb__courier_bold_34_usascii_s[i] - 0.5f) * recip_width;
            font[i].t0f = (stb__courier_bold_34_usascii_t[i] - 0.5f) * recip_height;
            font[i].s1f = (stb__courier_bold_34_usascii_s[i] + stb__courier_bold_34_usascii_w[i] + 0.5f) * recip_width;
            font[i].t1f = (stb__courier_bold_34_usascii_t[i] + stb__courier_bold_34_usascii_h[i] + 0.5f) * recip_height;
            font[i].x0f = stb__courier_bold_34_usascii_x[i] - 0.5f;
            font[i].y0f = stb__courier_bold_34_usascii_y[i] - 0.5f;
            font[i].x1f = stb__courier_bold_34_usascii_x[i] + stb__courier_bold_34_usascii_w[i] + 0.5f;
            font[i].y1f = stb__courier_bold_34_usascii_y[i] + stb__courier_bold_34_usascii_h[i] + 0.5f;
            font[i].advance = stb__courier_bold_34_usascii_a[i]/16.0f;
        }
    }
}

#ifndef STB_SOMEFONT_CREATE
#define STB_SOMEFONT_CREATE              stb_font_courier_bold_34_usascii
#define STB_SOMEFONT_BITMAP_WIDTH        STB_FONT_courier_bold_34_usascii_BITMAP_WIDTH
#define STB_SOMEFONT_BITMAP_HEIGHT       STB_FONT_courier_bold_34_usascii_BITMAP_HEIGHT
#define STB_SOMEFONT_BITMAP_HEIGHT_POW2  STB_FONT_courier_bold_34_usascii_BITMAP_HEIGHT_POW2
#define STB_SOMEFONT_FIRST_CHAR          STB_FONT_courier_bold_34_usascii_FIRST_CHAR
#define STB_SOMEFONT_NUM_CHARS           STB_FONT_courier_bold_34_usascii_NUM_CHARS
#define STB_SOMEFONT_LINE_SPACING        STB_FONT_courier_bold_34_usascii_LINE_SPACING
#endif

