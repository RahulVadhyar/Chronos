// Font generated by stb_font_inl_generator.c (4/1 bpp)
//
// Following instructions show how to use the only included font, whatever it is, in
// a generic way so you can replace it with any other font by changing the include.
// To use multiple fonts, replace STB_SOMEFONT_* below with STB_FONT_consolas_bold_9_latin1_*,
// and separately install each font. Note that the CREATE function call has a
// totally different name; it's just 'stb_font_consolas_bold_9_latin1'.
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

#define STB_FONT_consolas_bold_9_latin1_BITMAP_WIDTH         256
#define STB_FONT_consolas_bold_9_latin1_BITMAP_HEIGHT         40
#define STB_FONT_consolas_bold_9_latin1_BITMAP_HEIGHT_POW2    64

#define STB_FONT_consolas_bold_9_latin1_FIRST_CHAR            32
#define STB_FONT_consolas_bold_9_latin1_NUM_CHARS            224

#define STB_FONT_consolas_bold_9_latin1_LINE_SPACING           6

static unsigned int stb__consolas_bold_9_latin1_pixels[]={
    0x98042186,0x250c0110,0x26031882,0x54402a21,0x826a04c0,0x5314a0aa,
    0x14142883,0x80980544,0x99815102,0x4c130280,0x0620841c,0x0c40c418,
    0x21510108,0x04206018,0x01838022,0x26008826,0x74f3c0c0,0x12a4c859,
    0x50b1b264,0x19bd0f6d,0x6c1a8154,0xa932e1dc,0xcc96363d,0x85551f41,
    0xeb82a86b,0x0d415545,0x4989bfd1,0x2165c4c8,0x6426459e,0x2642643c,
    0x20d42cf4,0x743cc84c,0x7077ec59,0xc83cc8dd,0x2642ee44,0xabcf0f32,
    0x8c42a310,0xb9a62ada,0x8aaa2752,0x37213e1e,0x19516e42,0x2e16e4b3,
    0x42c8b723,0x7416e468,0xdb9d4ae0,0xb9d4ae1e,0x2fff2752,0x3731ff64,
    0x4c622db8,0x31886e60,0x2e6165c1,0x2590dcc1,0x9826314a,0x2e0dcc1b,
    0x8ff36e6e,0x2165c2cb,0x20dcc1b9,0x2ef3c1b9,0x9e52e794,0x4792ebfa,
    0x2ea2973c,0x76edcee6,0x2e5d3b70,0xbd7b2e9d,0xb8ba76ed,0x325d3b73,
    0xd3b72cc2,0x5cf21d85,0x9e41df54,0x5d2e794b,0x37d54bff,0xa88f4f4c,
    0x4b6951e9,0x2951e9e9,0x23d3512d,0x7d52ebea,0xa8f5aa5d,0x3a7a65b4,
    0x263d3d31,0x7b5b1eae,0x447a6a2b,0xd7d51e9a,0x54bafaa5,0x129e2ebe,
    0x23e21f1f,0x6d2eb50f,0x2625cf21,0x6c75d6a6,0x96d2e5b4,0x2d97bd4b,
    0xd9dc972d,0xf98b2972,0x2a25cb62,0x992e791f,0x52e791ff,0x5edc973c,
    0x7dc19b54,0x4bf6e3fe,0x3bee5b4a,0xb8b6953f,0x532792fd,0x2e74993c,
    0x77dcb695,0x27fdf73f,0x36b6793c,0xb8bf6e5a,0x532792fd,0x64f2993c,
    0x22eec1e4,0x9e52a5dd,0x225cf23c,0xefc92e69,0x96d6a5b1,0x2b97bd5a,
    0xd9dcb52d,0xb30b2b52,0x0f45a96c,0x64452e79,0x652e793d,0x22970973,
    0x2e12e5fe,0x9756a5d5,0x25d5a84b,0x65325d5b,0xfa8f2993,0x4b9756a1,
    0x5b4c84b8,0xadcf2fb2,0x64bab72e,0x9e532794,0x4f3c794c,0x50fd41fa,
    0x792d4bdf,0x16cd30f2,0x2794b9ea,0x32fa794b,0xb8f2971c,0x164f2973,
    0x8794b962,0xb9e4f20e,0x32790dff,0x908f2793,0x3ba20e87,0x25ddf31e,
    0xdd12eef8,0x4bbbe23d,0xdd12eef9,0x83bba21d,0x9777c478,0xdd11eee8,
    0x89bba23d,0xddf30eef,0x44bbbe65,0xddd10eee,0x783bba21,0x45b85b9e,
    0x3a25b04a,0x556e10ee,0xd88fbae6,0x1bfb10df,0xbfb104b2,0xdfd89dc1,
    0x221d0590,0x11e20dfd,0x20dc1ddd,0xdd10eee8,0x20776c1d,0x00000005,
    0x78800000,0x68000000,0x00000000,0x90372f3c,0x7103981b,0x190dea80,
    0xd9100000,0x805d9007,0x402d43eb,0x0000002d,0x00000000,0x00000000,
    0x00000000,0x00000000,0x00000596,0x00000000,0x00000000,0x00000000,
    0x00000000,0x00000000,0x00000000,0x00000000,0x4409a800,0x20505280,
    0x501510a8,0x85440a0a,0x1eda80a8,0x52819106,0x802209a8,0x401510a8,
    0x0a026209,0x04082088,0x5c044220,0x8620222d,0x88540860,0x177623ed,
    0x27641b93,0xb8702a31,0xb977623d,0x90eecc3d,0x970210bd,0x46c5dc89,
    0x0d415545,0x516360aa,0x2a835055,0xf884cfcc,0xb1b0b2a0,0x812a4cb8,
    0x4c81541a,0xaa83f3a2,0x2b761d02,0x409bd13a,0x6dc9f92d,0xd50d12e9,
    0x43aadcea,0x21f1111c,0x2ba219e8,0x4a8ed6a0,0xda87cc3b,0x5de622d8,
    0x33f33baa,0x3a0636a1,0x71d56e59,0x8f774c59,0xdd31eee9,0x47bba63d,
    0xdd11eee8,0x47bba23d,0x0971eee8,0x541ea8f1,0xb50f541e,0x541ea855,
    0xa84c621e,0x07aa0e8d,0x25bcd96a,0xeb9859ca,0xb96c3e22,0xb3d30764,
    0x20b858d8,0x86fa25b9,0x33a22bdb,0x8076950e,0xbc44faac,0x09758cad,
    0x597019f3,0xa8a54fe4,0x43f311e9,0x3e621f98,0xf887e621,0x8867e219,
    0x867e219f,0x4ec8f04c,0x93b22764,0x3b22ebfa,0x29527644,0xc87b952d,
    0x2a21d84e,0x303be21d,0x3ee25d5d,0x5a96a5b0,0x3260e4cc,0xd730fdc1,
    0xdb8fdd43,0x1d9d12ea,0x4910f56a,0xbc44aced,0x4132b3bd,0x26a21fd9,
    0x495bb91e,0x783c2fdb,0x5f11e0f0,0x42abe215,0x5f10aaf8,0xf043aa15,
    0x35746ae8,0x975a9aba,0x9aba3574,0x2f2a5b4a,0xd31aba0e,0x36e39950,
    0x96cf23be,0x1e52e0da,0x4377303a,0x40f31bb9,0x2b32e82d,0x54f2973c,
    0x47e24ddf,0x9698795b,0x03aa9593,0x97edc2d8,0x2b74ceac,0xf0783c2e,
    0x155f11e0,0x7c42abe2,0x155f10aa,0x4c517fec,0x87da61f6,0x652a1f69,
    0xb4c3ed33,0x54bab50f,0x07da6994,0x5bbd8859,0xa643f53d,0xfd88312e,
    0x2b625c0d,0x44b6b62d,0x4bdd51bf,0x776c4fe9,0x2a1dbd30,0x3a21d304,
    0x44ffa65e,0x3ff20dcd,0x5c1bdf72,0x3eab25d5,0x785ddf34,0x23c1e0f0,
    0x68868868,0xf11a0688,0x5cffbae1,0xfdd73fee,0xeb97be67,0x7fdd73fe,
    0x654bbbe2,0x7fdd72ec,0x3aa721a2,0x4c9ddd53,0x20b72eef,0x393441af,
    0x36a727b5,0x1008f263,0x03981000,0x00000017,0x25ddf300,0xe9809f2c,
    0x3dfd31ef,0x74c7bfa6,0x3fff11ef,0x7c47ffe2,0x3fff11ff,0x5a8f4008,
    0xa8f56a3d,0xd5a8f405,0x740016a3,0x0012eb51,0x2c980000,0x000002c8,
    0x00000000,0x00000000,0x00000000,0x00000000,0x00000000,0x00000000,
    0x00000000,0x85cdcc00,0x42dda839,0x3dd881b9,0xa8c42ee2,0xccb8aee0,
    0xb5122e3c,0xb129a541,0x2eea00e0,0x44140111,0xbb50e0bb,0x006210c5,
    0x2db81811,0x4141442a,0x42ee6098,0x41d42b98,0x06101100,0x54773033,
    0x98828331,0x7306ecc0,0x332a95c3,0x37beab5f,0x225d3970,0x675c1eae,
    0x2a177d10,0x3a6a23b4,0x2293b591,0x1db31eae,0x789d4fdc,0x551b8f98,
    0x2547e766,0x2fa20f88,0x4f54b10b,0xb8eab719,0x3cb89704,0xa5cba76e,
    0xd117263c,0x47aba659,0xbb52ebfa,0x6e416617,0xf91346c5,0xd314fcc1,
    0x6c4783db,0xa82ba0cd,0xd1d11ebe,0x55b7f261,0x2e7767b4,0xe87dbd74,
    0x950b51db,0x91fdb876,0x75f4d2ea,0x5b970742,0x25901e27,0x54d3d33b,
    0x50ee22bc,0xa8bc920b,0x3b896360,0x0ee21dc4,0x47c52e5b,0x43fbd50f,
    0x51d9e459,0x56ecd2e9,0x4c46ab30,0x7c0ee22b,0xe88b7a20,0x5dfd50f9,
    0x7c4e72b2,0x725cf21a,0x2a34747d,0x2e7765b4,0xd9811b54,0xb50d31da,
    0x91dad47a,0x74f4d293,0x9d570740,0x2c941e27,0xa86f6677,0x1f511fbf,
    0x2b67834c,0x887263d9,0x83ea20fa,0x54b60fa8,0xdac97765,0x25dfd73b,
    0x652a3d3c,0xb7b30ee3,0xa88fdfd4,0xf980f80f,0x8f03ab11,0x9f53abab,
    0x913ca647,0x3777219f,0x5dc9df53,0x3ddb12e8,0x3f21ff64,0x23ddf10e,
    0x3391edf9,0x20f675d2,0x4feaae0e,0x2c8f9878,0x477be677,0x40f83b4a,
    0x5b9e0efc,0x20de4c77,0x0f80f80f,0x3f31e52e,0xb31e665c,0xf51eef88,
    0x74c4b8bd,0x20ed2a0f,0x3a60f80f,0x03ffe26d,0x3c4cc887,0xa886f744,
    0x425400af,0x2d003efb,0x400004fa,0x3b14cccc,0xb9fffcc9,0x3ffe27f2,
    0x32793b82,0x0ed2a793,0x89e1a03e,0x1d563ffd,0x3e03e03e,0xb837f620,
    0x306f7445,0x04a8ec0b,0x37663bf3,0x3e0ed2a3,0x54080f80,0x3bbaa552,
    0x17ffe402,0x002bea20,0x00000000,0x00000000,0x1ddd1000,0xa5433766,
    0x85dfd51d,0x89c80581,0x25dfd53f,0xfd52efea,0x80cc805d,0x8dc0b305,
    0x23660039,0x5476952e,0xdfd52efe,0x00000005,0x00000000,0x00000000,
    0x00000000,0x00000000,0x00000000,0x00000000,0x00000000,0x00000000,
    0x00000000,0x00000000,0x00000000,0x5c777660,0x95cee731,0x498e5224,
    0x3667bbb7,0x47bb30dd,0x3766552a,0x44884c83,0x86eec40c,0x3b223939,
    0x54377623,0x0fb21ddd,0x1eecc3b3,0x994c5bb7,0x75512851,0x2005ddc4,
    0x2e62510a,0xb82e6aa2,0x43db802c,0x20e01010,0x98b10621,0x06c40c41,
    0x312ca546,0x8f5aa3f5,0x21b0f9f8,0x452e7958,0x83e608f9,0x2771f9da,
    0x45d3b53b,0x20f4c6ea,0x867a21ea,0x26a25aca,0x4433d10f,0xd1971f99,
    0x19527643,0x4ba6f23d,0x11d0eaf8,0x4b73e2b1,0x2760fcb8,0x54f2970d,
    0x9f9b1fbf,0x9d8ae549,0x27a66b45,0xf05b310e,0x713727d8,0x1afa3da8,
    0x3f778979,0x6743d87d,0xd1b1fe45,0x20f5aab1,0xe9da8f07,0x2a7b7b70,
    0x334f4794,0x443e603f,0x03b6a19f,0x157c43e2,0x5b199354,0xd5b534f4,
    0xf525cb21,0x8a57d6c5,0x31744116,0x7c7c495b,0x46c76950,0xc96fa49e,
    0x516fa1da,0x927e445f,0x36347dfd,0x2a7ddd92,0x4cd1d13e,0xdccbc3b4,
    0x3ea1aa3c,0xd7b17dc1,0x3c3cfc97,0x71f75478,0x37aa7b7b,0x41d3970e,
    0x117440eb,0x07f5499f,0x077f11ec,0x976ec45d,0x2f6a1f59,0xd92e592e,
    0x4fb7ae5e,0x3d07b068,0x952eec1d,0x24f46c76,0x1a7a2555,0x75f44373,
    0x441bb910,0x76d3ee0f,0x4cb82a23,0x59000b6e,0x403a293f,0xc87d7c47,
    0x13764eae,0x232a3c1e,0xda9dcee7,0x227f7640,0x1a20ec5a,0x89b16f2a,
    0x220d3068,0x27fdf70e,0x22b2794a,0x54fab72e,0x30d12f8f,0x04443fff,
    0x3b4a8be6,0xbb927a36,0x77702223,0xb03818c4,0x41330988,0x00004c68,
    0xf74998d8,0xa64787ff,0xb8fed94d,0x7f4c782f,0x5cf6951e,0x8812a773,
    0x21a20006,0x3fea5d4a,0x43fff12f,0xb177cc2d,0x6f7d56a3,0x0007df90,
    0x00000000,0x00000000,0x00000000,0x04986c00,0x00000000,0x00000000,
    0x00000000,0x00000000,0x410a88e2,0x47bbaa31,0x20811818,0x4061ccc9,
    0x22687109,0x0bdb0888,0x00000000,0x00000000,0x00000000,0x00000000,
    0x00000000,0x3e200000,0x7c97d991,0xc8722269,0x7b72c743,0x83f30444,
    0x2087e64b,0x0025eeee,0x00000000,0x00000000,0x00000000,0x00000000,
    0x00000000,0x0e980000,0x68e82e63,0xa8000088,0x000a1eee,0x00000000,
    0x00000000,0x00000000,0x00000000,0x00000000,0x00000000,0x00000b80,
    0x00000000,0x00000000,0x00000000,0x00000000,0x00000000,0x00000000,
    0x00000000,0x00000000,0x00000000,0x00000000,0x00000000,
};

static signed short stb__consolas_bold_9_latin1_x[224]={ 0,1,0,0,0,0,0,1,1,1,0,0,0,1,
1,0,0,0,0,0,0,0,0,0,0,0,1,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,1,0,0,0,0,0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,0,0,0,
1,0,0,0,0,0,0,1,0,0,0,0,1,1,0,0,0,1,1,1,0,0,0,0,0,0,0,0,0,0,
0,0,-1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
 };
static signed short stb__consolas_bold_9_latin1_y[224]={ 6,-1,-1,0,-1,-1,-1,-1,-1,-1,-1,1,4,3,
4,-1,0,0,0,0,0,0,0,0,0,0,1,1,1,2,1,-1,-1,0,0,0,0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,-1,-1,-1,0,6,-1,1,-1,1,-1,1,-1,1,-1,-1,
-1,-1,-1,1,1,1,1,1,1,1,0,1,1,1,1,1,1,-1,-2,-1,2,0,0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,6,1,-1,0,0,0,
-2,-1,-1,0,0,1,3,3,-1,-1,-1,0,-1,-1,-1,1,-1,2,6,-1,0,1,-1,-1,-1,1,-2,-2,-2,-2,
-2,-2,0,0,-2,-2,-2,-2,-2,-2,-2,-2,0,-2,-2,-2,-2,-2,-2,1,-1,-2,-2,-2,-2,-2,0,-1,-1,-1,
-1,-1,-1,-1,1,1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,1,0,-1,-1,-1,-1,-1,-1,-1,
 };
static unsigned short stb__consolas_bold_9_latin1_w[224]={ 0,3,4,5,5,5,6,3,3,3,5,5,4,3,
3,5,5,5,5,5,5,5,5,5,5,5,3,4,5,5,5,4,5,5,5,5,5,5,5,5,5,5,4,5,
5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,3,5,3,5,5,4,5,5,5,5,5,5,5,5,5,
4,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,4,2,5,5,5,5,5,5,5,5,5,5,5,
5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,0,3,5,5,5,5,
2,5,4,5,4,5,5,3,5,4,5,5,3,3,5,5,5,3,3,3,5,5,5,5,5,4,5,5,5,5,
5,5,6,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,
5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,
 };
static unsigned short stb__consolas_bold_9_latin1_h[224]={ 0,8,3,6,9,8,8,3,9,9,5,5,4,2,
3,8,7,6,6,7,6,7,7,6,7,6,6,7,6,3,6,8,9,6,6,7,6,6,6,7,6,6,7,6,
6,6,6,7,6,8,6,7,6,7,6,6,6,6,6,9,8,9,4,2,3,6,8,6,8,6,7,7,7,7,
9,7,7,5,5,6,7,7,5,6,7,6,5,5,5,7,5,9,10,9,3,6,6,6,6,6,6,6,6,6,
6,6,6,6,6,6,6,6,6,6,6,6,6,6,6,6,6,6,6,6,6,6,6,6,0,7,9,6,6,6,
10,9,3,7,5,5,3,2,6,3,4,6,5,5,3,7,9,3,2,5,5,5,7,7,7,7,8,8,8,8,
8,8,6,8,8,8,8,8,8,8,8,8,6,8,9,9,9,9,9,5,8,9,9,9,9,8,6,8,8,8,
8,8,8,8,6,7,8,8,8,8,7,7,7,7,8,7,8,8,8,8,8,5,7,8,8,8,8,9,9,9,
 };
static unsigned short stb__consolas_bold_9_latin1_s[224]={ 255,73,150,228,111,137,143,252,25,40,210,
216,139,206,192,131,225,234,97,190,67,196,202,109,208,115,252,220,73,176,79,
156,62,121,127,242,133,103,85,35,55,43,231,91,246,1,240,65,61,161,49,
248,37,1,31,25,19,13,7,84,167,74,246,200,161,216,95,204,150,191,83,
7,13,19,35,107,125,181,175,161,95,89,151,131,101,210,169,145,139,71,157,
88,1,99,144,222,222,222,222,222,222,222,222,222,222,222,222,222,222,222,222,
222,222,222,222,222,222,222,222,222,222,222,222,222,222,222,222,222,255,31,135,
155,137,167,4,44,166,236,187,163,155,206,149,171,240,143,226,236,186,214,129,
182,196,222,198,192,179,41,173,185,107,101,125,89,83,77,197,67,61,55,49,
43,37,31,25,19,185,7,50,56,93,68,78,204,219,105,123,117,29,189,179,
119,171,231,225,13,1,147,173,25,159,141,201,207,47,53,59,119,213,113,177,
243,249,237,183,230,77,195,113,165,153,13,19,7, };
static unsigned short stb__consolas_bold_9_latin1_t[224]={ 1,11,34,19,1,11,11,28,1,1,28,
28,34,34,34,11,11,19,28,11,28,11,11,28,11,28,19,11,28,34,28,
11,1,28,28,11,28,28,28,20,28,28,11,28,19,29,19,20,28,11,28,
11,28,21,28,28,28,28,28,1,11,1,28,34,34,19,11,19,11,19,20,
20,20,20,1,20,20,28,28,20,20,20,28,20,20,19,28,28,28,20,28,
1,1,1,34,19,19,19,19,19,19,19,19,19,19,19,19,19,19,19,19,
19,19,19,19,19,19,19,19,19,19,19,19,19,19,19,19,19,1,20,1,
20,20,20,1,1,34,11,28,28,34,34,20,34,28,20,28,28,34,11,1,
34,34,28,28,28,11,20,11,11,11,11,11,11,11,11,19,11,11,11,11,
11,11,11,11,11,19,11,1,1,1,1,1,28,1,1,1,1,1,1,19,
11,1,1,1,11,12,1,19,20,1,1,1,1,20,20,20,20,1,20,1,
1,1,1,1,28,20,1,11,1,1,1,1,1, };
static unsigned short stb__consolas_bold_9_latin1_a[224]={ 79,79,79,79,79,79,79,79,
79,79,79,79,79,79,79,79,79,79,79,79,79,79,79,79,
79,79,79,79,79,79,79,79,79,79,79,79,79,79,79,79,
79,79,79,79,79,79,79,79,79,79,79,79,79,79,79,79,
79,79,79,79,79,79,79,79,79,79,79,79,79,79,79,79,
79,79,79,79,79,79,79,79,79,79,79,79,79,79,79,79,
79,79,79,79,79,79,79,79,79,79,79,79,79,79,79,79,
79,79,79,79,79,79,79,79,79,79,79,79,79,79,79,79,
79,79,79,79,79,79,79,79,79,79,79,79,79,79,79,79,
79,79,79,79,79,79,79,79,79,79,79,79,79,79,79,79,
79,79,79,79,79,79,79,79,79,79,79,79,79,79,79,79,
79,79,79,79,79,79,79,79,79,79,79,79,79,79,79,79,
79,79,79,79,79,79,79,79,79,79,79,79,79,79,79,79,
79,79,79,79,79,79,79,79,79,79,79,79,79,79,79,79,
79,79,79,79,79,79,79,79, };

// Call this function with
//    font: NULL or array length
//    data: NULL or specified size
//    height: STB_FONT_consolas_bold_9_latin1_BITMAP_HEIGHT or STB_FONT_consolas_bold_9_latin1_BITMAP_HEIGHT_POW2
//    return value: spacing between lines
static void stb_font_consolas_bold_9_latin1(stb_fontchar font[STB_FONT_consolas_bold_9_latin1_NUM_CHARS],
                unsigned char data[STB_FONT_consolas_bold_9_latin1_BITMAP_HEIGHT][STB_FONT_consolas_bold_9_latin1_BITMAP_WIDTH],
                int height)
{
    int i,j;
    if (data != 0) {
        unsigned int *bits = stb__consolas_bold_9_latin1_pixels;
        unsigned int bitpack = *bits++, numbits = 32;
        for (i=0; i < STB_FONT_consolas_bold_9_latin1_BITMAP_WIDTH*height; ++i)
            data[0][i] = 0;  // zero entire bitmap
        for (j=1; j < STB_FONT_consolas_bold_9_latin1_BITMAP_HEIGHT-1; ++j) {
            for (i=1; i < STB_FONT_consolas_bold_9_latin1_BITMAP_WIDTH-1; ++i) {
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
        float recip_width = 1.0f / STB_FONT_consolas_bold_9_latin1_BITMAP_WIDTH;
        float recip_height = 1.0f / height;
        for (i=0; i < STB_FONT_consolas_bold_9_latin1_NUM_CHARS; ++i) {
            // pad characters so they bilerp from empty space around each character
            font[i].s0 = (stb__consolas_bold_9_latin1_s[i]) * recip_width;
            font[i].t0 = (stb__consolas_bold_9_latin1_t[i]) * recip_height;
            font[i].s1 = (stb__consolas_bold_9_latin1_s[i] + stb__consolas_bold_9_latin1_w[i]) * recip_width;
            font[i].t1 = (stb__consolas_bold_9_latin1_t[i] + stb__consolas_bold_9_latin1_h[i]) * recip_height;
            font[i].x0 = stb__consolas_bold_9_latin1_x[i];
            font[i].y0 = stb__consolas_bold_9_latin1_y[i];
            font[i].x1 = stb__consolas_bold_9_latin1_x[i] + stb__consolas_bold_9_latin1_w[i];
            font[i].y1 = stb__consolas_bold_9_latin1_y[i] + stb__consolas_bold_9_latin1_h[i];
            font[i].advance_int = (stb__consolas_bold_9_latin1_a[i]+8)>>4;
            font[i].s0f = (stb__consolas_bold_9_latin1_s[i] - 0.5f) * recip_width;
            font[i].t0f = (stb__consolas_bold_9_latin1_t[i] - 0.5f) * recip_height;
            font[i].s1f = (stb__consolas_bold_9_latin1_s[i] + stb__consolas_bold_9_latin1_w[i] + 0.5f) * recip_width;
            font[i].t1f = (stb__consolas_bold_9_latin1_t[i] + stb__consolas_bold_9_latin1_h[i] + 0.5f) * recip_height;
            font[i].x0f = stb__consolas_bold_9_latin1_x[i] - 0.5f;
            font[i].y0f = stb__consolas_bold_9_latin1_y[i] - 0.5f;
            font[i].x1f = stb__consolas_bold_9_latin1_x[i] + stb__consolas_bold_9_latin1_w[i] + 0.5f;
            font[i].y1f = stb__consolas_bold_9_latin1_y[i] + stb__consolas_bold_9_latin1_h[i] + 0.5f;
            font[i].advance = stb__consolas_bold_9_latin1_a[i]/16.0f;
        }
    }
}

#ifndef STB_SOMEFONT_CREATE
#define STB_SOMEFONT_CREATE              stb_font_consolas_bold_9_latin1
#define STB_SOMEFONT_BITMAP_WIDTH        STB_FONT_consolas_bold_9_latin1_BITMAP_WIDTH
#define STB_SOMEFONT_BITMAP_HEIGHT       STB_FONT_consolas_bold_9_latin1_BITMAP_HEIGHT
#define STB_SOMEFONT_BITMAP_HEIGHT_POW2  STB_FONT_consolas_bold_9_latin1_BITMAP_HEIGHT_POW2
#define STB_SOMEFONT_FIRST_CHAR          STB_FONT_consolas_bold_9_latin1_FIRST_CHAR
#define STB_SOMEFONT_NUM_CHARS           STB_FONT_consolas_bold_9_latin1_NUM_CHARS
#define STB_SOMEFONT_LINE_SPACING        STB_FONT_consolas_bold_9_latin1_LINE_SPACING
#endif
