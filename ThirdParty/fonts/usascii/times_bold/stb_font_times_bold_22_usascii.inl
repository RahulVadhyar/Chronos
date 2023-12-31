// Font generated by stb_font_inl_generator.c (4/1 bpp)
//
// Following instructions show how to use the only included font, whatever it is, in
// a generic way so you can replace it with any other font by changing the include.
// To use multiple fonts, replace STB_SOMEFONT_* below with STB_FONT_times_bold_22_usascii_*,
// and separately install each font. Note that the CREATE function call has a
// totally different name; it's just 'stb_font_times_bold_22_usascii'.
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

#define STB_FONT_times_bold_22_usascii_BITMAP_WIDTH         256
#define STB_FONT_times_bold_22_usascii_BITMAP_HEIGHT         72
#define STB_FONT_times_bold_22_usascii_BITMAP_HEIGHT_POW2   128

#define STB_FONT_times_bold_22_usascii_FIRST_CHAR            32
#define STB_FONT_times_bold_22_usascii_NUM_CHARS             95

#define STB_FONT_times_bold_22_usascii_LINE_SPACING          14

static unsigned int stb__times_bold_22_usascii_pixels[]={
    0x54c00288,0x22015000,0x10805302,0x984ccc40,0x554c0199,0x00066000,
    0x00998800,0x80082620,0x22051009,0x00540a22,0x800540a2,0x0a880018,
    0x41551000,0x99999808,0x74033009,0x376e605f,0x201cba9a,0xd85b84e9,
    0x6cc9501d,0xf3fea880,0xbf91039f,0x4405fd75,0x2e0bdedb,0x5f913fff,
    0x3aeb7f20,0x2bba602e,0x3fa63ebe,0x444ffeaf,0x2a5c84ff,0x0274fdc6,
    0x700f609b,0x5009d57d,0x4007fd7b,0xdfdbdfeb,0xfffd981d,0x7403f00b,
    0x803d505f,0x70fea01b,0xd701fc8b,0x3f201f30,0xfd303ff3,0xa84fe889,
    0x46e8ba9f,0x212a2ffd,0x7fc44fe9,0xf70fe884,0x35ffc87f,0x37fcc5ff,
    0x6f8991ec,0x40d505f9,0xc93ea06a,0xf9a7c03f,0x81ff9007,0xff301fd8,
    0x2203cc0f,0x000ea80a,0x71bea017,0xfa80ff8b,0xf901db02,0x3fa07fe7,
    0xe87ff507,0xf11a2757,0x7f4064bf,0xd87ff507,0x70ffea5f,0x137f43ff,
    0x745f0bff,0x2fe5bea3,0x0f8807e2,0x37d4bfd0,0x037cbf50,0xf880ffe4,
    0x40fff301,0x1d50004c,0x20710130,0x3a2dc5fb,0x2a06e82f,0xff3fc83f,
    0x104ffc83,0x3fe21fff,0x3f60a3ac,0x9ff9090f,0xff07ffc0,0x2e1ffcc9,
    0xf1ff60ff,0x2bea627f,0xdf70af99,0x009b17ee,0x47ffe07b,0x5ff205fa,
    0x7fd402f8,0xf980dc05,0xb80ba07f,0x2207c6ff,0x0e4fdcce,0xb16e27e4,
    0x205fa87f,0xf3fc87f8,0x02ffe83f,0xffe8bffa,0x5ffcc03f,0x02ffe829,
    0x7fc4bffa,0xf70ffe64,0xb07fec1f,0x3ffff23f,0xdf13ffff,0x00ea8bf2,
    0xfff905a8,0x7dc03f95,0xfc801ddf,0x3e60004f,0xd00f307f,0x3e234cdf,
    0x05c5ff56,0x716e1fe4,0x403fe87f,0xf9fe42ff,0x017ffc1f,0x7fd49ffd,
    0x7ff402ff,0x405fff05,0xbff14ffe,0x3ee1ffcc,0xf71ff60f,0x21aa5c81,
    0x3e26e8fc,0x201f1001,0x400ffffd,0x36a0fffa,0x0bffa0ce,0x07ff9800,
    0x4dfd00b7,0xfb8ff44b,0x3e602a0f,0x03f62dc3,0x4ff807ff,0x21ff9fe4,
    0x3601fff8,0x7ff4c5ff,0x13fea05f,0xd807ffe2,0x99ffa5ff,0x07fdc3ff,
    0xd8698dfd,0x0dc41323,0x74053132,0x17fffa02,0x37fe6644,0x5fff11b2,
    0x3ffcc000,0x6fe802e8,0x367fb8b6,0x5d301c5f,0x883d72dc,0x2ff403ff,
    0x20ffcff2,0x3fa02fff,0xfffd884f,0x7c07fe04,0x3ffa02ff,0x7e47fee4,
    0x46ffdc3f,0x12c42ff8,0x39d337f3,0x221d5001,0x5b82f9dd,0xfffbdd88,
    0xffd2fc44,0x7ffc0749,0x3fe60003,0xe800f887,0x5fe83e6f,0x40387ff1,
    0x366b70ea,0x402ff881,0xf9fe45fd,0x01fff41f,0x3aa05fff,0x81ae07ff,
    0x3fe03ffe,0x5f7fe42f,0x5ffdc3ff,0x64503ffe,0xffffffff,0xf70fc403,
    0x21e21be7,0x8fff52fe,0x3ffe65fc,0x9ffb03aa,0x3ffcc000,0x6fe802dc,
    0xf93ff89e,0xbb01443f,0x213a25b8,0x27f403ff,0x20ffcff2,0xff104ffb,
    0x3eaea18d,0x5c07301f,0xdff104ff,0x1ffcc620,0x000c3fee,0x3f533f71,
    0x744c8013,0x5d03ff2f,0xffb0ffc4,0x3ee3ffc1,0x3fee05ff,0x4d3ea006,
    0x003d86ff,0xf9874dfd,0x227fd99f,0xb70fea04,0x27f41fc8,0x7f90ffa0,
    0x3ffa07fe,0x2c2ffb80,0x2371be75,0x80ffe804,0xf9802ffb,0x007fdc3f,
    0x5cb90edc,0xe81d5006,0x9903ff3f,0xbf70ffc4,0x7ec4ffe8,0xfd8312ff,
    0x7fd9202f,0x0f88bff3,0x964dfd00,0x5fbcfff8,0x1fe41471,0xc87f916e,
    0x20ffc05f,0x103ff3fc,0x7fcc19fd,0xf1752f83,0x0246fd47,0xf1067ec4,
    0x3fe6005f,0x200ffe43,0xc8f65ff8,0xb82e8804,0x1e60df3f,0x217e47f9,
    0xdaadfffb,0x80eefffe,0x1ec41ffd,0x0bfea9f3,0x37f400d5,0xd89fe493,
    0x70510abf,0x7ec5b89f,0xf1037c42,0x3fe7f90d,0x373fae01,0xbbfb02df,
    0xcff885bb,0x33fb2000,0x71001dec,0x3fa21bff,0x1ff400bf,0x6401f43f,
    0x5f3bd104,0x7d710fc0,0xfd710599,0x3ff21bff,0x3ff6e01f,0xcdb81dec,
    0x003d83ee,0x003917fa,0x717ea090,0xfd81ff8b,0xf905f700,0x32007fe7,
    0x773005ff,0x4c000080,0x99988000,0x13333109,0x04c18100,0x53003220,
    0x00203300,0x00310188,0x01100198,0xfe940054,0x32000d85,0x5b8bf300,
    0x274407f4,0x27f904e8,0xffb001ff,0x00062007,0x00000000,0x00000000,
    0x00000000,0x00000000,0x7dc00000,0x3c883fd9,0xf70064c0,0x17d45b83,
    0x02641e88,0x00bfe7fb,0x15effec4,0x00000000,0x00000000,0x00000000,
    0x00000000,0x00000000,0x05ecf880,0x654d5e54,0x40eec02c,0x204da85b,
    0x2a20351b,0x057992cc,0x00d65440,0x00000000,0x00000000,0x00000000,
    0x00000000,0x00000000,0x31000220,0x02200001,0x00000000,0x00000000,
    0x00000000,0x00000000,0x00000000,0x00000000,0x00000000,0x00000000,
    0x00000000,0x00000000,0x00000000,0x00000000,0x00000000,0x00000000,
    0x13000000,0x20666620,0x22009998,0x06600999,0x4000ccc4,0x4cccc019,
    0x88260019,0x09999999,0x30555440,0x19999988,0x4c066662,0x0d44021a,
    0x4cc40cc0,0x4ccc0999,0x42666621,0x20999998,0x00d40998,0x33333011,
    0x21333333,0x21999998,0x21809999,0xfffdbec8,0x87fffb33,0x2201dfb8,
    0xbe983ffc,0x7fec41ec,0xdffd5000,0xfffff303,0x0de5c40d,0x3fffffee,
    0x59ff701f,0xa88b9bf9,0x2e21dfff,0x55ed41df,0xaeb82ded,0xeabc81ee,
    0x3fffaa4f,0x527f540a,0x3663dfff,0x3660bfff,0x403fea1e,0x66ffcc1c,
    0x3fecdfff,0x43dfffb1,0x7f41cfe9,0x3fe2bf94,0x0ffff40a,0x7fcc00ec,
    0x21be6e83,0xd9800ffb,0xfb85ffec,0xd103ffff,0x3fff601d,0xfe886fff,
    0x3a0bf706,0x883b02ff,0x2e17cc2f,0x541ff34f,0x543ff71f,0x09700fff,
    0xff88dff7,0x7dc2b81f,0x4c1fa80f,0xd83ffe0f,0x6c37ff43,0xf8eff884,
    0x3613fe4f,0x0640fffe,0x2e1ffcc0,0xf70ffa5f,0xfe87001f,0x5555740f,
    0x00fe880a,0x3eaab37e,0x201ffd84,0x05ffd05d,0xb03f9032,0x3fe3ff85,
    0x7fccff25,0xd81fff45,0x41fff880,0x50584ffd,0x983ff703,0x7107ffc3,
    0x2a3fff98,0x3e276e05,0x3613fe3f,0x0646fff8,0x87ff3130,0x717f65fe,
    0x400261ff,0x00ecc6fc,0x5301ff44,0xffa83f30,0xfe82c405,0xfe81902f,
    0xff114c0e,0x3b337f47,0xff513fe6,0x7e40730d,0x23ffcc4f,0x3faa0048,
    0xf8112eef,0x7e4040ff,0x400589ff,0x03ff15fd,0xc93ffeab,0xfcdefb80,
    0xfb27fc3f,0xfdbffb8d,0x40ed804f,0x502efffc,0x400153ff,0x04ffd87c,
    0x05ffd008,0x9fff9032,0xd8ffe601,0x1df700ff,0x0c83fff0,0xf51ffe60,
    0x260dc5ff,0x7fdc1ffe,0x00fff801,0x01bdffd0,0x3db7f700,0x2fffb960,
    0x90ffa819,0x27fc47ff,0x4ffb8ffb,0x32207ff3,0x7fffc1ef,0xdffc85ff,
    0x4e800cff,0x0003fff8,0x0640bffa,0x0fffffe2,0x1ffb2ffc,0x7e403ba0,
    0x3a01225f,0x3fef62ff,0x0ffe4165,0x3e007fee,0xff3000ff,0x2ae0009f,
    0x3f62c009,0x7f40c9ff,0xf98ffe65,0xb83ff64f,0x41bfa0ff,0x711ffffd,
    0x89fffffb,0x09ff15fe,0x7fc41f98,0x3fa0002f,0xd301902f,0xc81dffff,
    0x20dfd1ff,0x3fe200da,0xf700190f,0x3fe2e6df,0xff70398f,0x801ffb83,
    0x2e000fff,0x76401fff,0x16001f92,0xf033bffa,0x11ffcc9f,0x23fec9ff,
    0x3ff60ffb,0x07ffd300,0xf89ffee6,0x901bf65f,0x20fffe0f,0x40cccccb,
    0x01902ffe,0x227fffdc,0x4ffeffc8,0x3ff60090,0xff10058c,0x3ff6193f,
    0x3ff700cb,0xf801ffb8,0x3ea000ff,0x3fe606ff,0xbdffffb6,0xfff10b05,
    0x327fc41f,0x24ff87ff,0x07fdc6fd,0x7c401ffb,0x87fcc05f,0x3ff25ff8,
    0x7ec13a01,0x0dff904f,0x42c0bffa,0x03ffe442,0x0a05ff33,0x0dfffcc0,
    0x4bbff900,0x2e05fffa,0x0ffdc1ff,0x8007ffc0,0x04fff8d9,0x7ffc4ffa,
    0x82c0ffff,0x7fc0fff9,0xfd0ffe65,0x3ee2fecb,0x201bf60f,0x46d804fd,
    0x03fee6ff,0xffb80fcc,0x20bff705,0xd0d02ffc,0xc803fee0,0xfd00005f,
    0xff9800df,0x017ffc1f,0xffa83ff7,0x00fff801,0x3ffee588,0xaaeb8201,
    0x02c3fdaa,0x6fd81ff7,0xbf70ffe6,0x3fee1ff4,0x70313fa1,0x26404c3f,
    0x06fb9ff6,0x3ffb01ee,0x2e0bff70,0xf85883ff,0x7cc0bf03,0x400b6605,
    0xe8002ffa,0x407fc86f,0x7fcc1ffb,0x3ffe00aa,0x3606c400,0x3f8806ff,
    0x007c0f98,0x9ffb81f9,0x7444ffe9,0xff70df16,0xfb83be25,0xff88fa0d,
    0xfd10b10c,0x4e80bf65,0x5c37f440,0xdfd105ff,0x7fc06c41,0xf980fd41,
    0x007ff405,0xf70006f8,0xc809f307,0x3ffc81ff,0x200fffc0,0x4fff884d,
    0xcbbdfb80,0x0bbf6a1d,0xeffc80e8,0x7441dffa,0xbeb80edc,0x74c1ddbe,
    0xfc82ddff,0x36604dff,0x3e602ebe,0x7bfd5002,0x44039dd7,0x01ddeffd,
    0x3997dd9d,0x90037750,0x01e400df,0x3d00f880,0x06fff4c0,0x7ffe5400,
    0xbefeb82d,0x9ffff910,0x00333001,0x10c40100,0x20401100,0x004c4009,
    0x01100044,0x26000310,0x19800099,0x08062080,0x88001000,0x18060000,
    0x00000000,0x00000000,0x00000000,0x00000000,0x00000000,0x00000000,
    0x00000000,0x00000000,0x00000000,0x26200000,0x10019999,0x98801333,
    0x40009999,0x04ccc41a,0x04cccc40,0x42666660,0x09999998,0x26666620,
    0x10ccccc1,0x26660333,0x21999999,0x11999998,0x44333333,0x44099999,
    0x26662199,0x09999999,0x33333331,0x4cc41333,0x98800999,0x26219999,
    0x00019999,0xb8854002,0xeffcdfff,0x05ffb103,0xedfffa88,0xdd880bff,
    0x3ff626fa,0xfffa8802,0xdfff300f,0x3ffea215,0x3ea2009d,0x7f4c1eff,
    0x07ffa22d,0xf999bff5,0x7fd44bff,0xfff711ef,0x7fff4c3b,0x11fecc0b,
    0xb99bfff5,0x3fea27ff,0x2ffeccdf,0x377ffee2,0xfa880cde,0x3ea21eff,
    0x1effddff,0xf500b300,0x2e1ffe8f,0x5ff505ff,0x54bff600,0x8cfb84ff,
    0x017fd45f,0x207ffdb0,0xfd04ffdc,0x7fec007f,0xf703f883,0x5c0ea83f,
    0xffd80fff,0x881fff83,0x05b03fff,0x7b10fff6,0x74c2ffd8,0x361fff82,
    0x7ffd00ef,0x7447ffa0,0x0fd802ff,0xfd07fdc0,0x80fff83f,0xf9002ffa,
    0x207ffc5f,0x3fea04fe,0x3feb6002,0x3ffcd886,0x4005ffb0,0x0f443ffd,
    0x1b83ff70,0xd81fffc4,0x1fff83ff,0xb10fff70,0x4c1ffec0,0x2117fec3,
    0x41ffe82b,0xffd81ffe,0x5c3ffb02,0x7fc405ff,0x3a3fd404,0x17fec1ff,
    0x00997fd4,0xffd8bff2,0xf5027fc2,0xffac005f,0x7fe55c2f,0x005ffb03,
    0x1b31ffec,0x0c1ffb80,0xfb037fec,0x03fff07f,0x0761fff4,0x18a3ffd8,
    0x22717fec,0x641ffe82,0x2ffd85ff,0x7d43ffb0,0x7ffe406f,0xfd13e200,
    0x80fff83f,0x5ffdbffa,0x7fc5ff90,0xbfffd30f,0x74cbfea0,0xff9580cf,
    0x07ff958b,0xd800bff6,0x200b73ff,0x7d401ffb,0x3ff601ff,0x201fff83,
    0x0930fffa,0x8163ffd8,0x80932ffd,0x7fd41ffe,0xb02ffd87,0x17fec3ff,
    0x07ffdb10,0x0fff42e8,0x3ea09ff7,0x81ffa8ef,0x9ff72ffc,0x7d409ff0,
    0x1580b62f,0x64e61fff,0x5ffb03ff,0x65ffec00,0x3ff7005f,0x027ffc40,
    0x2666fff6,0x7401fff9,0xd801b4ff,0x207b8bff,0x04eabffd,0x3e60fff4,
    0x17fec1ff,0xfdabffd8,0x7d4dc01d,0x3a06406f,0x2efeedff,0x7ccbfea0,
    0xfeffc82f,0x09ff01de,0x01c97fd4,0x329ffb2c,0x3607ff90,0x3f6002ff,
    0x804fffff,0x3f201ffb,0x7fec00ff,0xfffccccd,0x67ffd401,0xfeffd802,
    0x3bff607f,0x7ff404fe,0x6c3fff81,0xbffb02ff,0x5803bfd9,0xd000bffe,
    0x1fff73ff,0xf997fd40,0x02ffc83f,0x7d409ff0,0x2c00fcaf,0x6491fff3,
    0x5ffb03ff,0x5dffec00,0x7dc02fff,0x5fff301f,0xf07ffb00,0xffb003ff,
    0x4fff600d,0x4bff607a,0x0fff404c,0xfb0bffe2,0x87ff605f,0x45504ffc,
    0x74006ffb,0x0bffb1ff,0xff997fd4,0x002ffc83,0x7fd409ff,0x22c05ffe,
    0x3f21effe,0x05ffb03f,0x64fff60c,0x3ee00fff,0x0bffd01f,0xf07ffb0a,
    0xff5003ff,0x8fff600b,0x44bff604,0x07ffa044,0xfd81fff1,0x43ffb02f,
    0xbe80fff8,0x01fffbaa,0x7c47ffa0,0x5ff503ff,0x3f20ffe6,0x09ff002f,
    0x7fe5ffd4,0xdff51602,0xfb03ffc8,0xfb0aa05f,0x077ff47f,0xfb81ffb8,
    0x6c5880ff,0x1fff83ff,0x005ffa80,0xb00c7ffb,0x835145ff,0x7fd41ffe,
    0xb02ffd85,0x2fff83ff,0x64ccce4c,0x3fa005ff,0x07ffea1f,0x7fccbfea,
    0x002ffd83,0x7fd409ff,0x1601ffd2,0x7ff90bfe,0x6c0bff60,0xf11ffec2,
    0x3fee0bff,0x81fffc41,0x41ffec4b,0xfa801fff,0x7ffb005f,0x20bff600,
    0x0fff40f8,0x3f607ffa,0x43ffb02f,0x80d87ff8,0xd000fff9,0xeffd85ff,
    0xf997fd40,0x03ffd84f,0x2a05ff88,0x0bff32ff,0xfb0f703a,0x0fffa09f,
    0x7ffb07f2,0xc85fffb8,0x37fec1ff,0x3f61fec4,0x01fff83f,0xb006ffb8,
    0x3fa007ff,0x7c3ed43f,0x3dfb32ff,0x740fffa0,0x0fff62ff,0x2fff40d5,
    0x3bfff260,0x47bffa22,0xfd8effe8,0xfff731ef,0x3f22015d,0xffe883ff,
    0x0dfff88e,0x1c45bf93,0x17ffff73,0x3bfffee6,0x730fffee,0x3227dfff,
    0xd31dffff,0x3fea1bff,0xffeeeeef,0xdfff733f,0xdfff9517,0x3ffae605,
    0xff7302bf,0x2e6017df,0xffeeffff,0x3fff266f,0x980adfef,0x30befffb,
    0xdfdffff7,0x1cffb83b,0x13fffee2,0x00000000,0x00000000,0x00000000,
    0x00000000,0x00000000,0x00000000,0x00000000,0x00000000,0x200c0220,
    0x10a2001a,0x00200000,0x06600000,0x09800ec0,0x33000000,0x13002600,
    0x31062002,0x22000001,0x00062001,0x01300330,0x4c02a0c4,0x84ff83fc,
    0x400efffb,0x017647e8,0xf57c9800,0x4bf229ff,0xfd89ffe8,0xeebfa82f,
    0x2a017c01,0x7dc2eccf,0xcffe89ff,0xbdc84e98,0xb7f503fe,0xedbea819,
    0x36fff623,0xfffb8eff,0x477ff4c2,0xffb10bfb,0xd88bffb7,0x12ff9bff,
    0x3fff99bf,0x5f880df0,0x3ea5ff10,0x3fff260f,0x262ffc43,0x406fffff,
    0x7fdc47fd,0xfea8001c,0xa8bff61d,0xfa8ffdc4,0xfbafcc2f,0xf3017c06,
    0x3f60ff4d,0x6c9ff30f,0xffa97e40,0x4f9afcc1,0xfa879374,0x2eff88ef,
    0xdff10dfd,0x3ffea0ae,0x7cc1ffb9,0x912fedcf,0x2112ffd4,0xfdb0115d,
    0x2e7ff303,0x3ffb80ff,0xa8641db8,0xff501fff,0x16fed40f,0x02fff220,
    0x40c93fe2,0x5ff31ffa,0x0df13fc8,0x93f202f8,0x9ffcc5fd,0xb0917ffa,
    0xd0bfeabf,0x443fe27f,0xf9850dff,0xfd97fe3f,0x099ff707,0x7fccbfea,
    0x4137fcc2,0x41fff108,0x5fbaabfd,0xf836cfcc,0x2a0ff51f,0xb02003ff,
    0xfbb101ff,0x9ff9100f,0x016fed41,0xa8487fec,0x85ff31ff,0x266203fe,
    0x1999bf99,0x87fc93fe,0x3ff796fe,0xb1171035,0xcdff85ff,0x3ffa1ffc,
    0x23ff981e,0x81ff25ff,0xff500ffe,0xf30ffe65,0x7ff9009f,0xcccccc98,
    0x82f8a741,0x5417e27d,0x2e0003ff,0xffb1b06f,0xcbff4400,0x3ea002ff,
    0xffa81bbf,0x7c45ff31,0x3fff204f,0x37ffffff,0x07fe49ff,0x3e2ebfee,
    0x3b2204cf,0x3fe22ffb,0x2609999c,0x7cc1ffff,0xfc97fe3f,0x413fea07,
    0x7ff32ffa,0x4c03ff98,0x332a06ff,0x1b20fa81,0x2a07d16e,0x360003ff,
    0xffb2c83f,0x17dfb300,0x80177ed4,0xff504ffe,0xff0bfe63,0x202f800d,
    0x21bf24ff,0xffb0fff8,0x2a3be607,0x037fc2ff,0x262fff44,0xc97fe3ff,
    0x3ffe207f,0xf32ffa80,0x03ff987f,0xfb80ffec,0x21f43faa,0x321cc3f8,
    0x887ff501,0x437c01ed,0xb81ff64a,0x64401dfe,0x3ee00cff,0x25ff502f,
    0x7fe42ff9,0x405f0042,0x413f64fc,0x07fea5fd,0x2ffaa7ec,0x41307fec,
    0xff31ff24,0xff92ffc7,0x427fd6c0,0x7ff32ffa,0x2a03ff98,0x6b8a65ff,
    0xa824c7f1,0x7fd40004,0x7037fd43,0x7ec5881f,0x05ffe447,0x16fed400,
    0xff303fc4,0x987ffd19,0x404abfff,0xe9be602f,0xf85f501f,0x3b3ffe06,
    0x3fea0bff,0x88fc3aae,0xf1ffd45f,0x407fecdf,0xa83ffd1c,0x87ff33ff,
    0xff103ffa,0x0007a21f,0xfa800000,0x83ffc43f,0xfffb81f8,0xb90fffff,
    0x32600005,0xfc807907,0x40effaef,0x400dfffb,0x667d402f,0x903e202f,
    0xe9f7dc07,0x7ffdc0df,0x0edcef85,0x2e3bff62,0xfffaafff,0x362ff664,
    0xffd11eff,0x23dffb1d,0xc81effd8,0x0ffedeff,0x00000000,0x2c40ffea,
    0xffb941e8,0x00ffffff,0x01000000,0x13000220,0x44007200,0x00101000,
    0x10806000,0x00000001,0x00000000,0x00000000,0xb81ffd40,0xccccec83,
    0x001ff605,0x00000000,0x00000000,0x00000000,0xec800000,0x3bbbbae2,
    0x3ae6eeee,0xb3073263,0x3267017d,0xff10cccc,0xffffffff,0x00000000,
    0x0aa0ffee,0x3fffffee,0x001ff603,0x00000000,0x00000000,0x00000000,
    0x7cc00000,0x2eeee67f,0x3e3bbbbb,0x3a27e47f,0xb8adffdc,0x1fffff73,
    0x4ccccccc,0x00000199,0x7ff5cc00,0xf30110bf,0x05ffffff,0x00003fec,
    0x00000000,0x00000000,0x00000000,0x3ffd0000,0x427ec000,0xea886a7c,
    0x77730dff,0x00000077,0x00000000,0x00000000,0x00000000,0x00000000,
    0x00000000,0x9a000000,0xccccccca,0x190044cc,0x00008802,0x00000000,
    0x00000000,0x00000000,0x00000000,0x00000000,0x00000000,0x65493000,
    0xcccccccc,0x00000004,0x00000000,0x00000000,0x00000000,0x00000000,
    0x00000000,0x00000000,0x00e60000,0x00000000,0x00000000,0x00000000,
    0x00000000,0x00000000,0x00000000,0x00000000,0x00200000,0x00000000,
    0x00000000,0x00000000,0x00000000,0x00000000,0x00000000,0x00000000,
    0x00000000,0x00000000,0x00000000,0x00000000,
};

static signed short stb__times_bold_22_usascii_x[95]={ 0,1,1,0,0,1,0,1,0,0,1,0,0,0,
0,0,0,1,0,0,0,0,0,0,0,0,1,1,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,2,0,0,1,-1,0,0,0,0,0,0,0,0,0,0,
-1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,1,0,0, };
static signed short stb__times_bold_22_usascii_y[95]={ 17,3,3,3,3,3,3,3,3,3,3,5,14,11,
14,3,3,3,3,3,3,3,3,3,3,3,7,7,5,8,5,3,3,3,3,3,3,3,3,3,3,3,3,3,
3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,20,3,7,3,7,3,7,3,7,3,3,
3,3,3,7,7,7,7,7,7,7,4,7,7,7,7,7,7,3,3,3,10, };
static unsigned short stb__times_bold_22_usascii_w[95]={ 0,4,9,10,10,18,16,4,7,6,8,11,5,7,
5,6,10,8,9,9,10,10,10,10,10,10,4,5,11,11,11,8,19,15,13,14,14,13,12,16,16,8,10,16,
13,19,14,15,12,15,15,10,13,15,15,20,15,15,13,4,6,5,10,12,5,10,11,9,11,9,9,10,11,6,
6,12,6,17,11,10,11,11,9,8,7,11,10,15,10,10,9,6,2,7,11, };
static unsigned short stb__times_bold_22_usascii_h[95]={ 0,15,8,15,16,15,15,7,18,18,9,11,7,3,
4,15,15,14,14,15,14,15,15,15,15,15,11,14,11,5,11,15,19,14,14,15,14,14,14,15,14,14,15,14,
14,14,15,15,14,18,14,15,14,15,15,15,14,14,14,18,15,18,8,2,4,11,15,11,15,11,14,15,14,14,
19,14,14,10,10,11,15,15,10,11,14,11,11,11,10,15,10,19,19,19,4, };
static unsigned short stb__times_bold_22_usascii_s[95]={ 253,150,244,155,88,166,203,251,46,54,224,
94,163,205,181,246,39,1,16,62,26,72,83,94,192,149,251,10,49,169,37,
160,8,235,221,220,197,183,170,105,137,212,235,99,85,65,12,110,29,72,1,
138,221,122,169,185,235,154,123,67,185,61,233,213,187,133,50,84,27,144,42,
1,17,206,1,52,116,163,192,106,138,126,204,154,213,72,61,117,181,99,214,
39,36,28,193, };
static unsigned short stb__times_bold_22_usascii_t[95]={ 1,1,52,1,1,1,1,37,1,1,52,
52,63,63,63,1,21,52,52,21,52,21,21,21,1,21,21,52,52,63,52,
21,1,37,37,1,37,37,37,21,37,37,1,37,37,37,21,1,37,1,37,
21,21,21,21,21,21,37,37,1,1,1,52,63,63,52,21,52,21,52,37,
21,37,21,1,37,37,52,52,52,1,1,52,52,21,52,52,52,52,1,52,
1,1,1,63, };
static unsigned short stb__times_bold_22_usascii_a[95]={ 79,106,176,159,159,318,265,88,
106,106,159,181,79,106,79,88,159,159,159,159,159,159,159,159,
159,159,106,106,181,181,181,159,296,230,212,230,230,212,194,247,
247,124,159,247,212,300,230,247,194,247,230,177,212,230,230,318,
230,230,212,106,88,106,185,159,106,159,177,141,177,141,106,159,
177,88,106,177,88,265,177,159,177,177,141,124,106,177,159,230,
159,159,141,125,70,125,165, };

// Call this function with
//    font: NULL or array length
//    data: NULL or specified size
//    height: STB_FONT_times_bold_22_usascii_BITMAP_HEIGHT or STB_FONT_times_bold_22_usascii_BITMAP_HEIGHT_POW2
//    return value: spacing between lines
static void stb_font_times_bold_22_usascii(stb_fontchar font[STB_FONT_times_bold_22_usascii_NUM_CHARS],
                unsigned char data[STB_FONT_times_bold_22_usascii_BITMAP_HEIGHT][STB_FONT_times_bold_22_usascii_BITMAP_WIDTH],
                int height)
{
    int i,j;
    if (data != 0) {
        unsigned int *bits = stb__times_bold_22_usascii_pixels;
        unsigned int bitpack = *bits++, numbits = 32;
        for (i=0; i < STB_FONT_times_bold_22_usascii_BITMAP_WIDTH*height; ++i)
            data[0][i] = 0;  // zero entire bitmap
        for (j=1; j < STB_FONT_times_bold_22_usascii_BITMAP_HEIGHT-1; ++j) {
            for (i=1; i < STB_FONT_times_bold_22_usascii_BITMAP_WIDTH-1; ++i) {
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
        float recip_width = 1.0f / STB_FONT_times_bold_22_usascii_BITMAP_WIDTH;
        float recip_height = 1.0f / height;
        for (i=0; i < STB_FONT_times_bold_22_usascii_NUM_CHARS; ++i) {
            // pad characters so they bilerp from empty space around each character
            font[i].s0 = (stb__times_bold_22_usascii_s[i]) * recip_width;
            font[i].t0 = (stb__times_bold_22_usascii_t[i]) * recip_height;
            font[i].s1 = (stb__times_bold_22_usascii_s[i] + stb__times_bold_22_usascii_w[i]) * recip_width;
            font[i].t1 = (stb__times_bold_22_usascii_t[i] + stb__times_bold_22_usascii_h[i]) * recip_height;
            font[i].x0 = stb__times_bold_22_usascii_x[i];
            font[i].y0 = stb__times_bold_22_usascii_y[i];
            font[i].x1 = stb__times_bold_22_usascii_x[i] + stb__times_bold_22_usascii_w[i];
            font[i].y1 = stb__times_bold_22_usascii_y[i] + stb__times_bold_22_usascii_h[i];
            font[i].advance_int = (stb__times_bold_22_usascii_a[i]+8)>>4;
            font[i].s0f = (stb__times_bold_22_usascii_s[i] - 0.5f) * recip_width;
            font[i].t0f = (stb__times_bold_22_usascii_t[i] - 0.5f) * recip_height;
            font[i].s1f = (stb__times_bold_22_usascii_s[i] + stb__times_bold_22_usascii_w[i] + 0.5f) * recip_width;
            font[i].t1f = (stb__times_bold_22_usascii_t[i] + stb__times_bold_22_usascii_h[i] + 0.5f) * recip_height;
            font[i].x0f = stb__times_bold_22_usascii_x[i] - 0.5f;
            font[i].y0f = stb__times_bold_22_usascii_y[i] - 0.5f;
            font[i].x1f = stb__times_bold_22_usascii_x[i] + stb__times_bold_22_usascii_w[i] + 0.5f;
            font[i].y1f = stb__times_bold_22_usascii_y[i] + stb__times_bold_22_usascii_h[i] + 0.5f;
            font[i].advance = stb__times_bold_22_usascii_a[i]/16.0f;
        }
    }
}

#ifndef STB_SOMEFONT_CREATE
#define STB_SOMEFONT_CREATE              stb_font_times_bold_22_usascii
#define STB_SOMEFONT_BITMAP_WIDTH        STB_FONT_times_bold_22_usascii_BITMAP_WIDTH
#define STB_SOMEFONT_BITMAP_HEIGHT       STB_FONT_times_bold_22_usascii_BITMAP_HEIGHT
#define STB_SOMEFONT_BITMAP_HEIGHT_POW2  STB_FONT_times_bold_22_usascii_BITMAP_HEIGHT_POW2
#define STB_SOMEFONT_FIRST_CHAR          STB_FONT_times_bold_22_usascii_FIRST_CHAR
#define STB_SOMEFONT_NUM_CHARS           STB_FONT_times_bold_22_usascii_NUM_CHARS
#define STB_SOMEFONT_LINE_SPACING        STB_FONT_times_bold_22_usascii_LINE_SPACING
#endif
