// Font generated by stb_font_inl_generator.c (4/1 bpp)
//
// Following instructions show how to use the only included font, whatever it is, in
// a generic way so you can replace it with any other font by changing the include.
// To use multiple fonts, replace STB_SOMEFONT_* below with STB_FONT_courier_bold_21_usascii_*,
// and separately install each font. Note that the CREATE function call has a
// totally different name; it's just 'stb_font_courier_bold_21_usascii'.
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

#define STB_FONT_courier_bold_21_usascii_BITMAP_WIDTH         256
#define STB_FONT_courier_bold_21_usascii_BITMAP_HEIGHT         58
#define STB_FONT_courier_bold_21_usascii_BITMAP_HEIGHT_POW2    64

#define STB_FONT_courier_bold_21_usascii_FIRST_CHAR            32
#define STB_FONT_courier_bold_21_usascii_NUM_CHARS             95

#define STB_FONT_courier_bold_21_usascii_LINE_SPACING          10

static unsigned int stb__courier_bold_21_usascii_pixels[]={
    0xd8800000,0x2a2ec800,0x0649300c,0x01911dc4,0x74c2dcb7,0x980002de,
    0x05ddb300,0x00000000,0x4c400000,0x88015511,0x001331aa,0x26204c40,
    0x31355101,0x73003003,0x25f10001,0x3ea001f9,0x3a2fd803,0xa9fc80ef,
    0x2a6fe83f,0xf937cc3f,0x44fffa87,0xb101efd9,0xfc81bfff,0x6fecc3ff,
    0xca81fdc2,0xdfc983ee,0x05bfb301,0x20b7f6a2,0xffffefff,0xffffb80d,
    0x3641fffe,0x4cfffee0,0x7fe44fff,0x886ffeff,0xc80dfffd,0x64002fce,
    0x100df32f,0x40ddfff7,0x417e4098,0x4c3fa9fc,0x361fd44f,0xf51fe23f,
    0xdbdf9819,0x6fffc41f,0x7dc41fff,0x3ffffe63,0x3f21ffa1,0x7fd46fff,
    0x7fcc4fff,0xffe83fff,0x7f5c4fff,0x44febcff,0xffdbdff9,0x007ec0bf,
    0x3621bfd1,0x33ff21ef,0x442dfffc,0x1fffdfff,0x002d43e2,0x01fd8df1,
    0x7ff6ffe4,0x26666621,0x3f60fea0,0x1fd42fb8,0x87f98fea,0x20fea3fd,
    0x3f62745c,0x50df910c,0xf997ec7f,0xdf91bfa7,0xe88ff403,0x744ff20f,
    0x4473a20f,0x077e40fe,0x41fd83fa,0x9fe886fc,0x46f98199,0x03fe22fd,
    0x19fb07ff,0x0f89bee2,0x1fe400b5,0x8df017e6,0x3fffe67b,0x30fea3ff,
    0x419fb7fd,0x91fd43fa,0x54df307f,0x3642e83f,0x0bfa0ff3,0x3637c7f5,
    0x7ccdfd1f,0x913e600e,0x3ee3f45f,0x642fb804,0xf33fa82f,0xfb8df109,
    0x84ffffff,0xa8df32fd,0x4c3fc84f,0x645fd07f,0x40332fce,0x01fd07f8,
    0x32e017f4,0x3ea3fdcc,0x3ffffea3,0x50fea6ff,0xf80fec7f,0x1f10fea7,
    0x4fb9bf66,0x3fa89f70,0xb3fb89f3,0x14cfdcbf,0x3fa21ff0,0x0bf31fa1,
    0x3207fd4c,0xf13fc84f,0xc88df50d,0x81ccccfe,0x985fb6f9,0x5c3fc85f,
    0x989f704f,0x203fecab,0x09f503fb,0x016fffd4,0x3bf51fd4,0x67f67fdc,
    0xfa85fb31,0x7f403fe3,0x37a87f50,0x0fe4dbbf,0x9fd45f88,0xca7cc2fb,
    0x3ff7fa4f,0xffffb83e,0xe897dc4f,0x7fffb06f,0x9339ff90,0x56ff41ff,
    0xfb06ffb8,0x3f3f6001,0x261ff886,0x817e43ff,0x3ff265f8,0x00ff801c,
    0xec8803fa,0x1fd406ff,0x36df1bfe,0x503ffa0f,0xfb03fc7f,0x2f50fea3,
    0x27d4d75d,0x9fd44fb8,0xba7cc2fb,0x33bffe4f,0x7ffd41ff,0x6ffc43ff,
    0xdb507fff,0xffff90df,0xfe885fff,0xb06fffff,0x3fe6001f,0xbdff702f,
    0x4fb87fff,0x33ae9f70,0x2a01ceba,0x827dc04f,0x500fec41,0x98efd47f,
    0x0afeaefa,0x3fa85fb3,0x8ff403fe,0x5cbd43fa,0xe83fc4d7,0xfa9fd42f,
    0x3fa9fd43,0x24f997fa,0xfea8bff8,0x7e7fecc1,0x643fd806,0x402ddbaf,
    0x06f9cdc9,0x7ec001fb,0x7fffdc06,0x83fcc3fd,0xc9ea82fe,0x2003fa06,
    0x217d40ff,0x8fea03fa,0x3fff63fa,0x3ea3ffff,0x3fb1fd43,0x43fa9fe0,
    0x7eff98f9,0xfb8867ec,0xdf13fa86,0x41711fc8,0xf53f41fd,0x2103fb89,
    0x5f8804fd,0x40000fe4,0x981fb06f,0x2005fb01,0xfb05f719,0x41bee219,
    0x3ea07a2d,0xb87f7004,0x0ffcabff,0x3fa8fea0,0x3feb7ee2,0xf50fea0a,
    0x7cc1fe47,0x5f10fea6,0xfd10f2e2,0x503fffbf,0xf887f47f,0xf127dc06,
    0x3ee27ccb,0x81ff7103,0x7e44fa80,0x06f80001,0xdffb9df5,0x3000df30,
    0xfff101fd,0x3203fffb,0x07fa0f34,0x3ea3fc40,0x403fffff,0x30fea3fa,
    0x3ea1be9f,0xff31fd43,0x1fd47fb0,0xffb002fc,0x8fea03df,0x23ffdffa,
    0x6f7f40b8,0x677f42ff,0x37720ffe,0x6fe41fff,0x3a1ffedc,0x4002ffff,
    0x81efffe8,0x51cffffc,0x809fffff,0x04ffffe9,0x03bfff62,0x982ffd88,
    0x1fe4005f,0x4013f226,0x50bee3fa,0xf50bf17f,0x7ec3fa89,0xfa83fe22,
    0x0aa2fb83,0x26b3ffa2,0x2e1fd42c,0x1fdc4fff,0x20fbff66,0x41efffd8,
    0x980bdffd,0x41effffd,0x001eeeed,0x06f776c4,0xddd30330,0xed9807dd,
    0x131002de,0x3fb00400,0x506f8800,0x3fd3007f,0x2fea1ff6,0x5ff884f8,
    0x4df30fea,0x7ffd43fc,0x17ff7ec3,0x7fffffec,0x07fff54f,0x02201806,
    0x011004c0,0x00000c40,0x00000000,0x00000000,0x000df300,0x0be60bf2,
    0x97ffffa6,0x90c881dc,0xe8936603,0x216e4b81,0xb983eee9,0x5379500a,
    0x77754599,0x00000002,0x00000000,0x00000000,0x00000000,0x07ea0000,
    0x181fc400,0x07bddb10,0x00000000,0x00000000,0x00000000,0x00000000,
    0x00000000,0x00000000,0x00000000,0x00000000,0x00000000,0x00000000,
    0x00000000,0x00000000,0x00000000,0x00000000,0x00000000,0x00000000,
    0x00000000,0x00000000,0x00000000,0x00000000,0x00000000,0x00000000,
    0xb3000000,0x01dd909d,0x00001880,0x3bbbae00,0x06202eee,0x76c01100,
    0x2203deee,0x03dd3000,0xa85e6dcc,0x76c003ed,0x95fffb80,0x3b229fff,
    0x7ff44006,0x9880efff,0x05ddd700,0x265fffd3,0x3fa2fffe,0xdfff53ff,
    0xf91fff41,0xffa809ff,0x00fffc46,0x1cfffda8,0x5c03db98,0x7fe41cfd,
    0x443fffff,0x06dffffc,0xd9dfff91,0x6fffffe8,0x777ff5c4,0x407ffa02,
    0x93fffffc,0xff8009ff,0x95effb81,0x3fe69ffd,0x776c4007,0x7e40deff,
    0xfffe84ff,0x1effe883,0x743dffb1,0xfdd32eef,0x87ffec1d,0x8804ffeb,
    0x003fb06f,0xdfd9dff1,0x01ffffcc,0x47fffffb,0xfd9999fb,0x377ffa21,
    0x7f441ffe,0x21fffdce,0xd81999fe,0x04ffecef,0xf103fff7,0x4c15333d,
    0x00cc004f,0xd0bf03f9,0x07e8000f,0x205fbbf5,0x3fa03fb8,0x4f987f80,
    0x20bee131,0x837c5ffc,0x20df1aa8,0x00aa89fc,0xd31fc8bf,0x3ea07f9b,
    0x808dd30d,0x6c27dc7f,0x2227ec1f,0x301fa1fe,0x884fb8bf,0x5c41fdff,
    0xf98099cf,0x2600aa8c,0x03f90099,0x4ccfd0bf,0x6c1fa001,0x07f5000f,
    0x13ea1fdc,0xcafe57e2,0x3fffc81f,0x3ffee1be,0xdf906fef,0xa819ffff,
    0x7d41fd41,0xfb81f503,0xdd13ea02,0x41be1260,0x6f6ff47b,0x0ec27d42,
    0x50fe5fe4,0x7fffffff,0xffffff98,0x03ffff83,0xd0bf03f9,0x017fff2f,
    0x04fb83f4,0x7c407f50,0x6f807f47,0x01fb1fff,0x3e1ff5f9,0x75e7fdc6,
    0xfff906ff,0xa80bff99,0x03fa81ff,0xf900ff40,0x30027cc5,0x7ff4009f,
    0x3fe25fff,0x5be601bd,0x3f6e21fc,0x7cc0ccce,0x40ffbbef,0xf903fdcb,
    0x2fd0bf03,0x8041cffd,0x23ff507e,0x807f5009,0x40bf32fc,0xebfff9fe,
    0xbf73f907,0x40ff89be,0x0df906fd,0xffd303fd,0x800fea07,0x23fc05fd,
    0x4cccc3fa,0xa800fea0,0x443fb11b,0xe83ffffe,0xf303f92f,0x20ef9807,
    0x07f502fb,0x217e07f2,0xd00efefe,0xff50fd0b,0x2a0ff5df,0xcb7cc03f,
    0x3f7f602f,0xf907fdfb,0xa9bebfa3,0x906f984f,0x307f707f,0x1fd401bf,
    0x2037ec40,0x91fd44fa,0x7d4dffff,0x27cc0003,0x51ffedc4,0x07fb55ff,
    0x4f9807f3,0x3fa81fd4,0x4f883f90,0x200fffe8,0xfd87e86f,0x504fffcb,
    0xf3fd007f,0xd7ffd80d,0x47f20dff,0x3ea6fff9,0xf906f984,0x3207f505,
    0x201fd400,0x6400dfe8,0x9337c42f,0x3fc47fd9,0x557e2000,0x3f26f883,
    0x42ffffff,0x27cc03f9,0x1fd40fea,0x0fe45fa8,0x8077f7f4,0x7437c46f,
    0xfa81ffa7,0x3fffa803,0xfba7fe40,0x643f905f,0x03fe26ff,0x1bf20df9,
    0xa8000bfa,0x17fe603f,0x2fe83fc0,0x67ec1fc8,0x8188f540,0x983fd4fb,
    0x2aaaa65f,0x03f983fd,0x0fea27cc,0xffd01fd4,0x5fa0dfd9,0xfff81ffc,
    0xfb82ffdd,0x505ffece,0x3ffe007f,0x897fdc00,0xeffa84ff,0xfc8dfd14,
    0xdffffddf,0x37ffff60,0x39305ffd,0xf503fa80,0x13ea009f,0x76efffcc,
    0x7ff441ff,0xf91ffecd,0x21ffdb9d,0xffeceffe,0x1dffb302,0x3bbbfba6,
    0x53ffa60d,0xdd73efea,0x887dddfd,0x440beffc,0x3bffa7fd,0x3bfff261,
    0xdfff9102,0x7f775cdf,0x3ee03eee,0x747fa805,0x6fffb83f,0x3fee1bea,
    0x20effdff,0xffffdffe,0x10bf900c,0x3bddfddb,0x77777ffc,0x201f981f,
    0x2effffd9,0xbfffd910,0x7fff6443,0x3ff7b21e,0x3fea02df,0xffff51ef,
    0x7fd43dff,0x27fff75f,0xfffffffc,0x74c03104,0x0bfff67f,0x0130004c,
    0x3ffffff2,0x0000004f,0x26600000,0x00cc4000,0xffff3018,0x7ffc5fff,
    0x003fffff,0x20009880,0x00988018,0x000000c4,0x00000000,0x00000000,
    0x00000000,0x00000000,0x00000000,0x00000000,0x00000000,0x00000000,
    0x00000000,0x00000000,0x00000000,0xd0000000,0xeff883ff,0xbffffd11,
    0x3ffffe60,0xff52ffff,0x4fffa65f,0xffffffe9,0x7e5bffa2,0x5fff51ef,
    0xfd8fffa6,0x6fffffff,0xfffffff7,0x7fffdcdf,0xfff982df,0xff72ffff,
    0x7fff53df,0x0bffff50,0x6fffffe4,0x7ffffdc2,0x003500ad,0x77ffffdc,
    0x000b800b,0x02040a20,0x53045544,0xf717ff63,0x3fb621df,0xdff305ef,
    0x25fdddfd,0xff31ffea,0x3fbb665f,0x3ff61eee,0x261dfd95,0xdff30ffe,
    0x7777f6c5,0xffd56fee,0x54dfdddd,0x5fffeeff,0x7f777fcc,0x3dffd52f,
    0xd507fff5,0x2e01fffd,0x5ffeeefe,0x3fbbffaa,0x0cff887f,0xeeffea80,
    0x3e600fff,0xffc88002,0x5fc9fec1,0x3fffffaa,0x3fe29f71,0x40bffe1f,
    0xaa7cc05f,0x7445f73f,0x203ff32f,0x89f303fa,0x8ffc43fa,0x1fc80ff8,
    0x213e66f8,0xd30fe46f,0xf727cc7f,0xfb14f98d,0xfefb801d,0xd88fea04,
    0xc893e61f,0xcffea82f,0x2e27cc00,0x00fea03f,0xb07fff70,0xff97f29f,
    0xf52febac,0x553ffe27,0x0bf02fff,0x27f54f98,0x57fcc2fb,0x0fea02ff,
    0x0fea27cc,0x81fedbea,0x936591fc,0x13a954f9,0x26f883f9,0x81ff33f8,
    0x05fe8cf9,0x40ff3fd0,0x327cc3fa,0x205f889f,0x2603fffb,0x502fcc4f,
    0x3faa007f,0x410600cf,0x1911aef8,0x76fc4be6,0x02fcfe8f,0x2a3b00bf,
    0xf501b33f,0x3fa807ff,0x9555bf30,0x3fbf207f,0x3eb3f205,0xfd5bf305,
    0x3607f201,0x3fa22a0f,0x4ffef982,0x3f2bf300,0xfd87f502,0x75453e63,
    0x7fe4403f,0xaadf982e,0x4cc42ffd,0x98099cfb,0x0000cffe,0x1dffffc8,
    0x5e7c47e2,0x02fbdfef,0x3fa800bf,0x500ffd00,0x3ffe607f,0xd103ffff,
    0x7fe401ff,0xfff305ff,0x07f201ff,0x13f607f2,0x077fffcc,0x5f997e40,
    0xffb9bf50,0x7fffcc1d,0x3a2004ff,0x3fe60dff,0x221fffff,0xffffffff,
    0x07fff21f,0xd9730000,0xf887c5ff,0xfb9fff8c,0x03b0bf02,0x3ee00fea,
    0x1fd405ff,0xcaaadf98,0x00fea03f,0x20bf59f9,0x00feadf9,0x81fb03f9,
    0xf98265fc,0x200efcaf,0xffeeeff8,0xfffffa80,0x777fcc0d,0xfb1000ff,
    0xadf983bf,0x2e0ffeba,0xbccdfdcc,0x07bff620,0x2e01bd10,0x882fcc0f,
    0x3eedf94f,0x4f88bf02,0xfa807f50,0x2a03fe8f,0xa89f303f,0x00fea03f,
    0x4c0b23f9,0x83ea934f,0x547f81fc,0xf997e0ff,0xfb813f24,0x84ffffff,
    0x26019cfa,0x803bf24f,0x302effc8,0x207f909f,0xfe9803fa,0x49f500df,
    0x9bff94fb,0x3e205ffb,0x0bee3514,0x413e62fc,0x3fe603fa,0x2a05ff11,
    0xa89f303f,0x00fea03f,0x9f3003f9,0x0fe43f90,0x7fc49fb1,0x89f337c1,
    0x01fd00fe,0x007f50ff,0x05fc89f3,0x9805fff7,0x503fb84f,0x7f54007f,
    0x3236c0cf,0xfffff56f,0x3ff6207b,0x3dfdb11d,0x3bbffb62,0x775c4fee,
    0x7fd43eef,0x29ffd32f,0xdeefeed9,0x2ebffd31,0x775c3efe,0xfec84eef,
    0xfea80dee,0x1ffeeeef,0xffdddff5,0x777fe41d,0xffd56fee,0x897bea3b,
    0xfb11dffd,0x3bfae3df,0xffea81de,0x447bfa1d,0xea803ffe,0xfffeeeff,
    0x0007f501,0x17c1fff7,0x4009980c,0xd12fffe8,0x3fa65fff,0x4fffffff,
    0x27ffffe4,0x7d4fffee,0xffff35ff,0x3fea5fff,0x87fff96f,0x85fffffc,
    0x81effffd,0xfffffffb,0xffff71ff,0xfff907bf,0x3eedffff,0x3bfa2fff,
    0x25fffd30,0xf92fffe9,0xf705ffff,0x7fc45fff,0x20019d11,0xfffffffb,
    0x007a201d,0x49876440,0x00000000,0x00000000,0x00000000,0x00000000,
    0x00000000,0x00000000,0x00000000,0x00000000,0x54400000,0x00351001,
    0x33023553,0x9804cc41,0x0cc400aa,0x33333053,0x20ccc133,0x0cc40999,
    0x06440266,0x02a88988,0x222a6262,0x2026601a,0x98800099,0x1bb81310,
    0xffffffd5,0x060007df,0x22222204,0x4ccccc08,0x00999999,0xffda8000,
    0xfff302ff,0xffd305ff,0x7fe4dfff,0x887fff14,0x81efffff,0xffebfffb,
    0xfffff31f,0x3fffa7ff,0x21ffffb6,0xffb6fff8,0x307f503f,0x7dfffdff,
    0xefffff88,0xffe85fff,0x41fffe0f,0x94fb80e8,0xa87fc47f,0xeeeeeeee,
    0x98ffee2e,0x53ee2742,0xfffffff9,0xffffff92,0x00bfffff,0xbcffb800,
    0x7fcc1ffc,0x222ffebe,0x7fecbeff,0xfdb93f26,0x6566ec43,0xffec885f,
    0xdf32fbdf,0x2a3ffd99,0xdfd32efd,0xf74ffc87,0x7d45419f,0x3ff20a8b,
    0x640febbe,0xdcffccff,0x45ffd41f,0xd03feb9a,0x73fa81df,0x001fd45f,
    0x59ffdf50,0x325e88df,0x9999915f,0x332e2399,0xcccccccc,0x3e200001,
    0x3637cc0f,0xf93fcc2f,0x4f88fd09,0x35101fd4,0x17fe40fd,0x07fea5f0,
    0x01fe8ff1,0x85ffbff3,0xfffffffa,0xfb83be23,0x4f9afc42,0x91fb07f5,
    0x7ec1febf,0xa97cc5fe,0x7511f61f,0x17777777,0x3ffa23b2,0x00c1701f,
    0x00000000,0x3ffffe60,0xdf10ffff,0x07f47f60,0x513e20c4,0xfffd707f,
    0x07f201ff,0xc80ffd40,0x980bf53f,0xfd701fff,0x4f887dff,0x57e21fd4,
    0x707f54f9,0xbf3fff5f,0x93f6bf70,0x7c1f31f8,0x7ffffdc3,0x2e04ffff,
    0x0000001c,0x20000000,0xeeeeeff9,0x20df10ee,0x001fd1fd,0x87f513e2,
    0xfecbcffb,0x5001f900,0xb7c403ff,0x7fec01fe,0xfff500df,0xfa89f105,
    0x4f9afc43,0xfdf507f5,0xf987fdff,0x0d8bfa0e,0xaa885896,0x0aaaaaaa,
    0x00000000,0x40000000,0xd8101ff8,0xf93fd43f,0x7c417107,0xdf11fe45,
    0xf900fe88,0x21ffa801,0x5fdfc82d,0x363bf620,0x57fc40ef,0x227c40ff,
    0x9afc43fa,0xf107f54f,0x83fff5ff,0x00ec41d9,0x00000000,0x00000000,
    0xff700000,0x41ffdb9d,0xffecfff9,0x337ffe22,0x6ffc2ffd,0x3a1efffd,
    0xefffecdf,0x3bbffb21,0x77ffcc4e,0xff884fee,0x9ffd301f,0xf88bffee,
    0x7f4c3f53,0x23dfd34f,0xff9bffd8,0xfe81efaa,0x0000ff96,0x00000000,
    0x00000000,0xf5000000,0x307dffff,0x303dfffb,0x07ffffd9,0xffdffff3,
    0x77ffecc5,0x3ff62ffe,0x7d45ffff,0x04ffffff,0x7fd40df9,0x07fff74f,
    0x35fffa80,0x3fa25fff,0xfabff9cf,0xf33fc82f,0x0000000b,0x00000000,
    0x00000000,0x00cc4000,0x26200130,0x10019801,0x00000013,0x00000000,
    0x00000000,0x00000000,0x00000000,0x00000000,0x00000000,0x00000000,
    0x00000000,0x00000000,0x00000000,0x00000000,0x00000000,0x00000000,
    0x00000000,0x00000000,0x00000000,0x00000000,0x00000000,0x00000000,
    0x00000000,0x00000000,0x00000000,
};

static signed short stb__courier_bold_21_usascii_x[95]={ 0,4,2,1,1,1,2,4,4,2,1,0,3,1,
4,1,1,1,0,1,1,1,1,1,1,1,4,3,-1,0,0,1,1,-1,0,0,0,0,0,0,0,1,0,0,
0,-1,-1,0,1,0,0,1,0,0,-1,-1,0,0,1,4,1,2,1,-1,3,0,-1,1,0,0,1,0,0,1,
1,0,1,-1,0,0,-1,0,0,1,1,0,0,-1,0,0,1,3,4,3,1, };
static signed short stb__courier_bold_21_usascii_y[95]={ 15,2,3,2,2,3,4,3,3,3,3,4,12,8,
12,1,2,2,2,2,3,3,2,3,2,2,6,6,4,7,4,3,2,4,4,3,4,4,4,3,4,4,4,4,
4,4,4,3,4,3,4,3,4,4,4,4,4,4,4,3,1,3,2,18,2,6,3,6,3,6,3,6,3,3,
3,3,3,6,6,6,6,6,6,6,3,6,6,6,6,6,6,3,3,3,7, };
static unsigned short stb__courier_bold_21_usascii_w[95]={ 0,3,7,9,9,9,9,3,6,5,9,11,5,9,
3,9,9,9,10,9,9,9,10,9,9,10,3,5,12,11,12,9,9,13,11,11,11,11,11,12,11,9,12,12,
11,13,12,11,10,11,12,10,11,11,13,13,11,11,9,5,9,5,9,13,5,11,12,10,12,11,10,12,11,9,
8,11,9,13,11,11,12,12,11,9,10,11,12,13,11,11,9,6,3,5,10, };
static unsigned short stb__courier_bold_21_usascii_h[95]={ 0,14,6,15,16,13,12,7,15,15,9,11,6,3,
4,17,14,13,13,14,12,13,14,13,14,14,10,11,11,6,11,13,15,11,11,13,11,11,11,13,11,11,12,11,
11,11,11,13,11,15,11,13,11,12,11,11,11,11,11,15,17,15,7,3,4,10,13,10,13,10,12,13,12,12,
16,12,12,9,9,10,13,13,9,10,13,10,9,9,9,13,9,15,15,15,5, };
static unsigned short stb__courier_bold_21_usascii_s[95]={ 254,124,167,46,21,244,194,252,67,74,107,
207,175,214,210,1,114,37,47,160,114,93,128,58,139,149,238,232,219,181,182,
27,86,144,195,81,109,97,85,68,61,51,181,131,15,1,242,232,158,96,169,
103,27,157,214,228,39,73,121,80,11,108,157,224,204,48,14,25,1,1,124,
219,135,147,31,169,204,129,117,13,170,183,60,242,196,36,82,143,95,207,72,
56,63,40,193, };
static unsigned short stb__courier_bold_21_usascii_t[95]={ 1,1,45,1,1,1,19,33,1,1,45,
33,45,45,45,1,1,19,19,1,19,19,1,19,1,1,33,33,33,45,33,
19,1,33,33,19,33,33,33,19,33,33,19,33,33,33,19,1,33,1,33,
19,33,19,19,19,33,33,33,1,1,1,45,45,45,45,19,45,19,45,19,
1,19,19,1,19,19,45,45,45,1,1,45,33,1,45,45,45,45,1,45,
1,1,1,45, };
static unsigned short stb__courier_bold_21_usascii_a[95]={ 178,178,178,178,178,178,178,178,
178,178,178,178,178,178,178,178,178,178,178,178,178,178,178,178,
178,178,178,178,178,178,178,178,178,178,178,178,178,178,178,178,
178,178,178,178,178,178,178,178,178,178,178,178,178,178,178,178,
178,178,178,178,178,178,178,178,178,178,178,178,178,178,178,178,
178,178,178,178,178,178,178,178,178,178,178,178,178,178,178,178,
178,178,178,178,178,178,178, };

// Call this function with
//    font: NULL or array length
//    data: NULL or specified size
//    height: STB_FONT_courier_bold_21_usascii_BITMAP_HEIGHT or STB_FONT_courier_bold_21_usascii_BITMAP_HEIGHT_POW2
//    return value: spacing between lines
static void stb_font_courier_bold_21_usascii(stb_fontchar font[STB_FONT_courier_bold_21_usascii_NUM_CHARS],
                unsigned char data[STB_FONT_courier_bold_21_usascii_BITMAP_HEIGHT][STB_FONT_courier_bold_21_usascii_BITMAP_WIDTH],
                int height)
{
    int i,j;
    if (data != 0) {
        unsigned int *bits = stb__courier_bold_21_usascii_pixels;
        unsigned int bitpack = *bits++, numbits = 32;
        for (i=0; i < STB_FONT_courier_bold_21_usascii_BITMAP_WIDTH*height; ++i)
            data[0][i] = 0;  // zero entire bitmap
        for (j=1; j < STB_FONT_courier_bold_21_usascii_BITMAP_HEIGHT-1; ++j) {
            for (i=1; i < STB_FONT_courier_bold_21_usascii_BITMAP_WIDTH-1; ++i) {
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
        float recip_width = 1.0f / STB_FONT_courier_bold_21_usascii_BITMAP_WIDTH;
        float recip_height = 1.0f / height;
        for (i=0; i < STB_FONT_courier_bold_21_usascii_NUM_CHARS; ++i) {
            // pad characters so they bilerp from empty space around each character
            font[i].s0 = (stb__courier_bold_21_usascii_s[i]) * recip_width;
            font[i].t0 = (stb__courier_bold_21_usascii_t[i]) * recip_height;
            font[i].s1 = (stb__courier_bold_21_usascii_s[i] + stb__courier_bold_21_usascii_w[i]) * recip_width;
            font[i].t1 = (stb__courier_bold_21_usascii_t[i] + stb__courier_bold_21_usascii_h[i]) * recip_height;
            font[i].x0 = stb__courier_bold_21_usascii_x[i];
            font[i].y0 = stb__courier_bold_21_usascii_y[i];
            font[i].x1 = stb__courier_bold_21_usascii_x[i] + stb__courier_bold_21_usascii_w[i];
            font[i].y1 = stb__courier_bold_21_usascii_y[i] + stb__courier_bold_21_usascii_h[i];
            font[i].advance_int = (stb__courier_bold_21_usascii_a[i]+8)>>4;
            font[i].s0f = (stb__courier_bold_21_usascii_s[i] - 0.5f) * recip_width;
            font[i].t0f = (stb__courier_bold_21_usascii_t[i] - 0.5f) * recip_height;
            font[i].s1f = (stb__courier_bold_21_usascii_s[i] + stb__courier_bold_21_usascii_w[i] + 0.5f) * recip_width;
            font[i].t1f = (stb__courier_bold_21_usascii_t[i] + stb__courier_bold_21_usascii_h[i] + 0.5f) * recip_height;
            font[i].x0f = stb__courier_bold_21_usascii_x[i] - 0.5f;
            font[i].y0f = stb__courier_bold_21_usascii_y[i] - 0.5f;
            font[i].x1f = stb__courier_bold_21_usascii_x[i] + stb__courier_bold_21_usascii_w[i] + 0.5f;
            font[i].y1f = stb__courier_bold_21_usascii_y[i] + stb__courier_bold_21_usascii_h[i] + 0.5f;
            font[i].advance = stb__courier_bold_21_usascii_a[i]/16.0f;
        }
    }
}

#ifndef STB_SOMEFONT_CREATE
#define STB_SOMEFONT_CREATE              stb_font_courier_bold_21_usascii
#define STB_SOMEFONT_BITMAP_WIDTH        STB_FONT_courier_bold_21_usascii_BITMAP_WIDTH
#define STB_SOMEFONT_BITMAP_HEIGHT       STB_FONT_courier_bold_21_usascii_BITMAP_HEIGHT
#define STB_SOMEFONT_BITMAP_HEIGHT_POW2  STB_FONT_courier_bold_21_usascii_BITMAP_HEIGHT_POW2
#define STB_SOMEFONT_FIRST_CHAR          STB_FONT_courier_bold_21_usascii_FIRST_CHAR
#define STB_SOMEFONT_NUM_CHARS           STB_FONT_courier_bold_21_usascii_NUM_CHARS
#define STB_SOMEFONT_LINE_SPACING        STB_FONT_courier_bold_21_usascii_LINE_SPACING
#endif

