// Font generated by stb_font_inl_generator.c (4/1 bpp)
//
// Following instructions show how to use the only included font, whatever it is, in
// a generic way so you can replace it with any other font by changing the include.
// To use multiple fonts, replace STB_SOMEFONT_* below with STB_FONT_courier_27_usascii_*,
// and separately install each font. Note that the CREATE function call has a
// totally different name; it's just 'stb_font_courier_27_usascii'.
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

#define STB_FONT_courier_27_usascii_BITMAP_WIDTH         256
#define STB_FONT_courier_27_usascii_BITMAP_HEIGHT         78
#define STB_FONT_courier_27_usascii_BITMAP_HEIGHT_POW2   128

#define STB_FONT_courier_27_usascii_FIRST_CHAR            32
#define STB_FONT_courier_27_usascii_NUM_CHARS             95

#define STB_FONT_courier_27_usascii_LINE_SPACING          13

static unsigned int stb__courier_27_usascii_pixels[]={
    0x81b80000,0x20039818,0x4c079990,0x20999703,0x11880333,0x5c400005,
    0x53001ced,0x88000003,0xca80bedb,0xa83ccccc,0xdd7000bd,0x000b7019,
    0x20035100,0x64c000a9,0x776dc4ed,0x1d27400b,0x4a85d500,0x4b800edc,
    0x2540555f,0x5b87aaa8,0xb33b80f3,0x01dffc80,0x9d5137d5,0x7f6ff4c0,
    0x3fe2bff3,0x1fffc43f,0x5d7115d5,0xaaaaadb8,0x80599641,0x40eb89dd,
    0x409d00fd,0xdfe9bffa,0x9ff504fe,0x03ff91df,0x7c3115d9,0x02fb889c,
    0x3003b93a,0x00744a8b,0x2a01e1d0,0x8f03adfe,0xb80fa1f8,0x85f40953,
    0x8074c1ea,0x20be984d,0x0e887dd9,0x22070f20,0x24401dc6,0xb85a80aa,
    0x09d03ec5,0x4c17db70,0x2e17544d,0x809d02de,0x0d40d307,0x2a3c00f1,
    0x4b5003c4,0x544e7407,0x35c780fd,0x952c81ea,0xd12e12e0,0x1740e803,
    0x40ee0ff0,0x70ec0068,0x39871007,0x907c0ba0,0x5c00d40f,0x7c4be02f,
    0xb705f702,0x00f40500,0x51e00790,0x87a00789,0x07412a07,0x0be0fa3c,
    0x1d03b964,0x402d4d10,0xf901e64b,0x0f203a20,0x01dc1d00,0x1f006458,
    0x006c8b20,0xa6407b80,0x10be206a,0x2c80001f,0x3c01a200,0x2a00f12a,
    0x003b03c5,0x3203e678,0x20ee3b05,0x03b9e059,0x1012e688,0x1a21dc0f,
    0x8bb8d700,0xcc980aba,0x40d3042d,0x0001ae3b,0x2ed1012e,0x12a16403,
    0x3f2d3000,0x644fffff,0x22547802,0x0783b007,0x64f0012a,0x3221f506,
    0x4cdecdec,0x4fd9312a,0x354f001c,0x46881ea0,0xdfcb803c,0x75effdc0,
    0x6dc4102f,0x24a816a4,0x27ffe46b,0x56a035c0,0x2e17405a,0x10039932,
    0x44a803f7,0x2a0f8069,0x1a601a24,0x037db01e,0xf982ecf0,0x3aafeaa1,
    0xea8ee2ac,0x4007678a,0x7403f10e,0x0689dc07,0x3109d950,0xb7101f30,
    0x54095059,0x049816e4,0x4fa01fb8,0x85f300f8,0x5eabfb9d,0x2002fea0,
    0x6402d84a,0x0fa6951d,0x201e0b60,0xf00dfdb9,0x82f88274,0xe8ee0767,
    0xf002c9e0,0x7fb80db8,0x003bb440,0x99000eb8,0x500736e2,0x0b525409,
    0x6f5c024c,0x06e46a80,0xb9b0bb62,0x00ee0590,0x406984a8,0x3f6954f9,
    0x07834401,0x2780ea80,0xf05f104e,0x689dc074,0xb300773c,0xdf95bf90,
    0x1d9700f1,0x400ee000,0x2c983569,0x992e0598,0x2e012603,0xefbadfbb,
    0xfdacfd81,0x407dc2cb,0x40033059,0x7403d04a,0x405a92a1,0x2000f03c,
    0x417a783b,0x9f9951f9,0x1dc399f9,0x01d13c3d,0x9b7302d8,0x1fc403c5,
    0x200b3000,0x16679069,0x0016c0d1,0x26770093,0x64c02cdb,0x4a8591bd,
    0x200003a0,0x3c0b504a,0x3c40f12a,0xb80e60f0,0x541b6783,0x55d7530f,
    0x325c355f,0x2641f9bd,0x1e000d30,0x80003a20,0x20b9005a,0x403e1544,
    0x0126001f,0x900000ee,0x01a06885,0x3d025400,0x078951e0,0xf50780f2,
    0x4f01f101,0xb30d707b,0xa986a83c,0x7542ec0a,0x700f0001,0x33e80009,
    0x1cc17401,0xd30990e2,0xb8049800,0x0ec00003,0x5425416c,0x095002ff,
    0x25478254,0xf007c41e,0x2af77aa0,0x7c4f02ed,0x15983d81,0x0003e20d,
    0x01bdbbf9,0x07403c00,0xc982fb20,0xbb30bea6,0xf10322c0,0x3fa17443,
    0x77009301,0x835c0000,0x207a61e8,0x95003ffc,0x54780e80,0x404b83c4,
    0x3b663107,0x31723c02,0x1a29501f,0xeb8002d8,0x7550000a,0x6555455f,
    0x7f5401ae,0x6c40cfed,0x4c04fede,0xdd303dbd,0x2ff885fb,0x6d440930,
    0x2a000aad,0x200edbaa,0x202feee9,0x012a002a,0x25468897,0x1e00741e,
    0x23c02540,0x541720f9,0x074c0b34,0x37f62062,0x006b9bce,0x54555555,
    0x001aaaaa,0x26600266,0x4c002000,0xffc86201,0x0fffffff,0x01555551,
    0x01555540,0x00000310,0x20f88095,0x0f22544b,0x200f0095,0x3d87804a,
    0x4cee03f1,0x75efdc05,0x99bc982f,0x0000cdba,0x00000000,0x00000000,
    0x00000000,0x00000000,0x4f200b60,0x2224c0ce,0x3e007a5d,0x412a06ff,
    0x56887ffe,0x01884409,0x0001aa88,0x00000000,0x00000000,0x00000000,
    0x00000000,0x1f100000,0x0000d100,0x10000093,0x00000000,0x00000000,
    0x00000000,0x00000000,0x00000000,0x00000000,0x3f6aaaa0,0x00000001,
    0x00000000,0x00000000,0x00000000,0x00000000,0x00000000,0x00000000,
    0x54000000,0x0000aaaa,0x00000000,0x00000000,0x00000000,0x00000000,
    0x00000000,0x00000000,0x00000000,0x00000000,0x00000000,0x00000000,
    0x00000000,0x00000000,0x00000000,0x00000000,0x00000000,0x33332a00,
    0x7001cccc,0x176cc099,0x4000e64c,0x2001bedb,0x32e1abca,0x06654004,
    0x05999500,0x326000a0,0x64c00bde,0x991002de,0x9801dc40,0x3ccccccc,
    0x8ceeda88,0xbdb71019,0xcccc8267,0x03333263,0x315bdb51,0x6666664c,
    0x5972cccc,0x05b55555,0x6f41eaa0,0x2a21ec89,0x5764003d,0x75c00eb8,
    0x2aa3cbac,0x0754c007,0x09955300,0xeb8003a0,0x302ea88a,0x01d9337d,
    0xeeb87cd8,0x5551004d,0xe88355f5,0x3eeb989c,0xdb89be98,0x2b36a2de,
    0x30beea21,0x9dd7139d,0x6e5556d4,0x0354caaa,0x21e000ec,0x3b85a84a,
    0x03443400,0x003c00d1,0x950000e8,0x5c003a00,0x441e880d,0x2604a81f,
    0x951b88f6,0xe883c000,0xe887f102,0x2c85f500,0x40761a20,0x89512a4f,
    0x0068804a,0x1d00e878,0x12a003b8,0x003a8164,0x0074001e,0x1d004a80,
    0x4401d100,0x0e80ea0e,0x9501e3d0,0x3d83c000,0x00ba1540,0x2202c85b,
    0x49503446,0x12a2544a,0x1a8812a0,0x1e80743c,0x013511dc,0x5c12603b,
    0x1a89e003,0x50000e80,0x7fffc409,0x1dc6ffff,0x59000e40,0x2a03c970,
    0x341e0004,0x44034400,0x8d101640,0x89504058,0x6c02544a,0xfedfe882,
    0xd30990f2,0xdbfd1770,0xb303c87f,0x7fffffc4,0xdd1f03ff,0x07403fd9,
    0x5405fff9,0xb001d004,0x40075003,0x0f07440e,0x1e0004a8,0x12a00166,
    0xd1016400,0x06200790,0x78008895,0x36a0be88,0x99de887b,0xbecb81ec,
    0x05a93aa0,0x800ee0dd,0xd03cc2ef,0x5400f541,0xd001d004,0x200b1001,
    0x03c3c83d,0x8780012a,0x03b8003b,0x34405900,0x00de7644,0xb3000950,
    0x1fe207d0,0x81ffffc4,0x23f103fb,0x075ec2e8,0x03f001dc,0xeb874076,
    0x20095000,0x1007800e,0xd109900d,0x004a80f0,0x000ee1e0,0x164000ee,
    0xdb980d10,0x004a803e,0x007c42c8,0x117d30f9,0x01f705d5,0xd9dd1264,
    0x00ee03a7,0x740f2078,0x254005d9,0x0e800e80,0x2e404980,0x540782d8,
    0x70f01a04,0xfffff507,0x640012e5,0x8801a202,0x0025403d,0x3012a074,
    0x1f105d0f,0x434c05b8,0x03b83429,0xd03c81e0,0x4a8005dd,0x59001d00,
    0x2e405700,0xa80f0598,0x30f01e04,0x2cc7700b,0x2203b800,0x20344006,
    0x42cc004a,0x223cc04a,0x0b70f206,0x05980698,0x903c0077,0x0ba2ba07,
    0x1d004a80,0x3d00d300,0xffb81360,0x01ffffff,0xd103c095,0x3b801d10,
    0x34c00074,0x400d8b50,0x0012a00f,0x401f1077,0x7703447c,0x13200fb8,
    0x01dc0ba0,0xe81e40f0,0x2a005d10,0x2003b004,0x6c12e02d,0x501e0004,
    0x09703c09,0xa877012e,0x0fc25c06,0x502743d8,0x4004a80d,0x2207d00e,
    0x0d01d87f,0x07e207f7,0x01dc0b90,0xe81e40f0,0x2a00ba20,0x710b5004,
    0x2dc1f445,0x20001ec4,0xd9025407,0x3600e981,0xb83d880d,0xb80ec80e,
    0x7f43641e,0x2017540b,0x81a2004a,0x2faa0be8,0x3221e987,0x20cecb84,
    0x376204ea,0x7800ee00,0x20740f20,0x025402e8,0x9fdbbd90,0x9dbbfb01,
    0x02b80fa0,0x20254078,0x01eecee9,0xfecdefb8,0xb9dd500b,0xdefa809f,
    0xfd8d80df,0xf502efde,0x809fffff,0x6ff4403a,0x98bff2ff,0x7cc2eded,
    0xffdfd8bf,0x1f76ee42,0xffffffa8,0x7ffe41ff,0x43fffe23,0x7fec0ffc,
    0xfffff93f,0x3300ffff,0xf0066001,0xffffffff,0x3fffea07,0xffffff11,
    0x06a207ff,0x006a6200,0x4c001a88,0x3531000a,0x00000000,0x310002a2,
    0x201a8800,0x00000018,0x00000000,0x00000000,0x00000000,0x00000000,
    0x00000000,0x00000000,0x00000000,0x00000000,0x00000000,0x00000000,
    0x00000000,0x00000000,0x00000000,0x6665c000,0x65c01ccc,0xcccb84cc,
    0x2e1332e4,0x2665c4cc,0x9932665c,0x2e039999,0x32e1cccc,0x3333264c,
    0x89e66640,0xcccccccc,0x4c799912,0x332e2ccc,0xc80acccc,0xcccccccc,
    0x999970cc,0xc8999999,0x01bccccc,0x33333332,0x9999971c,0x0f326059,
    0x4c333326,0x332202cc,0x4cccc983,0x557d4c00,0x9302edaa,0xb953055d,
    0x4c1764c5,0x16ecc2ed,0x5511764c,0x260155bb,0x3660aafa,0x0ab7622e,
    0xaa87aeaa,0x20aaadca,0x36a21afa,0x2abea60d,0x5d43fdaa,0xaaaaaaae,
    0x555f531e,0xea8f5555,0x0debaaac,0x555557c4,0x55f532ea,0xa889d955,
    0x7d5442fd,0x01dd710a,0x2a207b72,0x8002deba,0x7401d107,0x1e80ec00,
    0x3d100e88,0x1dc03d10,0x036e0f00,0x8126012a,0x7703c04a,0x207441e0,
    0x1e0ec058,0x2e0390f0,0x86a83446,0x32e07607,0x9b30f00e,0x0095d107,
    0xf000b377,0x05902540,0x90d30344,0x6c0e9807,0xf001dc03,0x22540b90,
    0x9502544a,0x40ee0780,0x0b112a07,0x1e03c1d8,0x222d8072,0x0780e886,
    0x12eee166,0x4346cc3c,0x0e8049cb,0x2078001d,0xb81a2059,0x0d325c03,
    0x805b96a0,0x9b1e003b,0x077c5980,0x20254077,0x03c0ee07,0x204588d1,
    0x03044781,0x12344039,0xb303c0b6,0x1e07a770,0x23a16d66,0x772cc049,
    0x0b607800,0x003a03d0,0x9000f47a,0x0ee00d39,0x007d1780,0x91df4cd1,
    0x1e025405,0x540f03b8,0x00762c45,0x0e403b8f,0x05b803a0,0x5c17441e,
    0xb30f0b53,0x0935a966,0x001a22c8,0x803eb98f,0x3005984a,0xfd00079d,
    0x800ee001,0xf002fe8f,0x03b2cddc,0x333e0254,0xf03ecccc,0x9f107ea0,
    0xcf803d99,0x0e403ecc,0x07440760,0xfb9999f0,0x42d8ee05,0x6c7a5987,
    0x40e80931,0x3ffe001d,0x1a000eff,0x06c800b2,0x2001fd00,0x2bbe003b,
    0xb0e805e9,0x2a00e9e3,0x55557c04,0x99f03daa,0xd103dd99,0xf803d555,
    0x6403daaa,0x1e80ec01,0x655557c0,0x223b81ed,0x952cc3c6,0xb5024cd1,
    0x23c00950,0x0b2003e9,0x004a800f,0x7006acc8,0x907e1407,0x6cf1d809,
    0x404a80d1,0x57c0ee07,0x16201aaa,0x15c78039,0x01b00720,0x440f0099,
    0x8f21dc1e,0x16f45987,0x666ec093,0x1e007ccc,0x2cc00f62,0x04a80095,
    0x00993540,0x41e3c077,0x96a7201e,0x04a80f4a,0x1e07703c,0x8008b100,
    0x07204407,0x1a0d30d0,0x1dc4a80f,0x2cc3c3a2,0x220931ee,0xdaaaaaae,
    0x3a20f002,0x0761d001,0x44009500,0x2e016c0e,0x2a0f1e03,0x88b2ae05,
    0x0254068e,0x0f03b81e,0x78005880,0x80721dc0,0x440f445a,0x71a203c6,
    0x261eb507,0x95049805,0x07802cc0,0x45dc01aa,0x004a8006,0x807a20ba,
    0x40f1e03b,0x81d7500e,0x025405ae,0x0f03b81e,0x78005880,0x40721dc0,
    0x881ec0e9,0x712e03c6,0x261eb607,0x3b049805,0x07800e80,0x5f44016c,
    0x004a8003,0x8074c079,0x40f1e03b,0x70db304b,0x404a809b,0x03c0ee07,
    0x1e001620,0x4c1c8770,0x102d40eb,0x1d71078d,0x0fd303b8,0x109300b3,
    0x7407700d,0xf881ffff,0x000fd807,0xbffffff5,0xd03fffa0,0x3fea3fff,
    0xffffffff,0x83ffffb7,0x27cc3ff8,0x3fe21fcc,0x93ffffff,0x7fd4bfff,
    0xffffb0ff,0x7fffc0df,0x3ffa04ff,0xffffffff,0x3fffffe3,0xfffb80bd,
    0xfd6fffff,0x9dffffff,0x85fffe81,0x7fffdc7c,0x93fffe40,0xff90ffff,
    0x000000ff,0x00000000,0x00000000,0x00000000,0x00000000,0x00000000,
    0x00000000,0x00000000,0x19b88000,0x0000b200,0x39807220,0x8006a200,
    0x88009a98,0x220000aa,0x000000a9,0x00000198,0x80000000,0x001a8801,
    0x00019851,0x99303800,0xd9077225,0x3fa20bd7,0x0003bd32,0x9500fae0,
    0xdb9df900,0xecdeb809,0x7f4c0dbf,0x7440dfdd,0x66f6442f,0x7ffcc1ee,
    0x43fff983,0x2ddecdfd,0x7ffb0ffb,0xf31fffc4,0xffff87ff,0x3e62ffff,
    0x4bb7f27f,0xeced8ff9,0x6defe41f,0x86ded8ed,0x263ffff8,0x0f02ffff,
    0x7fdcffe6,0x7dc01a25,0x0067546f,0x800cea80,0xc809804a,0xfb109b02,
    0x71057cc3,0x237fdc1f,0x441ea83e,0x1e42c806,0xb81e17cc,0x74c1f443,
    0x40b70781,0xf0e24e8f,0xf987987d,0x02c93f24,0x202d4095,0x265ff107,
    0x400ee4ff,0x7d702fe8,0x006f4c00,0x44000950,0x3e206a86,0x25b80fa1,
    0x80f22fe8,0x0e60e869,0x3700f81d,0x6c0ee078,0x42c07a63,0x0bbe00ea,
    0x216c0be0,0x12a34c69,0xc83b00e8,0xf8ee2f0a,0x0d30621f,0x2ec88000,
    0x0007b620,0x1330012a,0x4300f61e,0x400e8069,0x1642c807,0x6e43c1fb,
    0x2e07800a,0x07a6f603,0x7c00e980,0x1dc0f001,0x4a8b3166,0x21a60ee0,
    0xcfdfdfc9,0x36003fa1,0xd8800002,0x00bb221e,0x9db99998,0x7f540999,
    0x0e87feee,0x3bbbae00,0x02feeeee,0x50ee0166,0x2ccb3a27,0x03deeda8,
    0x3601dc0f,0x03a2000f,0x207801e0,0x1662cc3b,0x64344095,0xd827e402,
    0x006e8807,0x21bd3000,0x322003fb,0xcccedccc,0x202baa2c,0x6d400787,
    0x99999999,0x20166009,0x9cbacc3b,0x95100755,0x0ee0781d,0x1004dea8,
    0x801e003d,0x8b30ee07,0x32025459,0x3d301a22,0x980d901d,0x717a3c9e,
    0xed880199,0x002ec881,0x00e80950,0x8800761e,0x0780000f,0x23b782d8,
    0x20041c8e,0x07703c4b,0x402643aa,0x801e002e,0x8b30ee07,0x26025459,
    0x25d00ee6,0x6c01886a,0xf11a63a1,0x176440bf,0x000f6c40,0x2059812a,
    0x4405a87a,0xc8801362,0x6981321d,0x75dcd3b0,0x8b301e40,0xa83d880e,
    0x7b02e40e,0x801e0930,0x8b30ee07,0x6c025459,0x21d401d1,0x5478001c,
    0x07fd42cd,0x98003eb8,0x095000de,0x07ec81d8,0x43f7019b,0x2ea81ce8,
    0x83e8dff7,0x47d701ea,0x81fc86e9,0x261dc1e8,0x807543ee,0xb304c85c,
    0x207801e0,0x1662cc3b,0x95b50095,0x64000000,0x1fe43ec1,0x00006754,
    0x950033aa,0xfeced980,0xbf70bff3,0x32017bd9,0x21dfdcef,0xdec84ffa,
    0x3ea00eec,0x6ddc2741,0x883ffdde,0xfb9efded,0x447fffb5,0x3fe67fff,
    0x25ffffff,0xfffffffe,0x227ffe46,0xfff95ffe,0x7d43fe61,0x001fe807,
    0x83660000,0x6c37c0fe,0x5c00001d,0x4012a01f,0xa98000a8,0x806a6000,
    0x02a62018,0x53100000,0x00151003,0x00000000,0x00000000,0x00000000,
    0x2afb7ae0,0x0103f35f,0x40040000,0x00000000,0x00000000,0x00000000,
    0x00000000,0x00000000,0x00000000,0x804c0000,0x00000028,0x32e00000,
    0x2a15550c,0x880a202a,0x88888888,0x00ea00c0,0x2eeeeeea,0x5ddd43bb,
    0xbbbbbbbb,0x0000003b,0x00000000,0x00000000,0x00000000,0x00000000,
    0x6ff88000,0x07fd9ff6,0x3ff207ba,0xffffffff,0x33603ae6,0xffb240ec,
    0x1fffffff,0x5ddddddc,0x03bbbbbb,0x00000000,0x00000000,0x00000000,
    0x00000000,0x00000000,0x3f21ffa8,0x5ec1bf27,0x200000e9,0xe98f20ea,
    0x00003e9a,0x00000000,0x00000000,0x00000000,0x00000000,0x00000000,
    0xbf900000,0x17ee5fb8,0x0005a96e,0xb10134c0,0x0000005d,0x00000000,
    0x00000000,0x00000000,0x00000000,0x00000000,0x20ff4000,0x313ea4fa,
    0x5dd4990d,0xbbbbbbbb,0x00000003,0x00000000,0x00000000,0x00000000,
    0x00000000,0x00000000,0x22000000,0x263f985f,0x7403a23f,0x55555532,
    0x00055555,0x00000000,0x00000000,0x00000000,0x00000000,0x00000000,
    0x00000000,0xf807dc00,0x40310fc1,0x00000008,0x00000000,0x00000000,
    0x00000000,0x00000000,0x00000000,0x00000000,0x0000c400,0x00000000,
    0x00000000,0x00000000,0x00000000,0x00000000,0x00000000,0x00000000,
    0x00000000,0x00000000,0x00000000,0x00000000,0x00000000,0x00000000,
    0x00000000,
};

static signed short stb__courier_27_usascii_x[95]={ 0,5,3,2,2,2,2,5,7,3,0,1,3,2,
5,2,2,2,1,2,2,2,3,2,2,3,5,3,0,1,0,0,2,0,1,1,1,1,1,1,1,2,1,1,
1,0,0,0,2,1,1,2,1,0,0,0,0,1,2,0,0,0,2,0,5,1,0,1,1,1,2,1,0,2,
2,2,2,0,1,1,0,1,1,2,1,1,0,0,1,1,2,0,6,0,2, };
static signed short stb__courier_27_usascii_y[95]={ 19,4,4,3,3,4,6,4,4,4,4,6,15,11,
16,2,4,4,4,4,4,4,4,4,4,4,8,8,6,9,6,5,3,5,5,5,5,5,5,5,5,5,5,5,
5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,4,2,4,4,24,3,8,4,8,4,8,4,8,4,3,
3,4,4,8,8,8,8,8,8,8,5,8,8,8,8,8,8,4,4,4,10, };
static unsigned short stb__courier_27_usascii_w[95]={ 0,4,9,11,10,11,10,4,4,5,9,12,6,11,
4,10,10,10,11,10,10,10,10,10,10,10,4,6,12,13,12,9,10,15,12,12,13,12,13,13,13,10,13,13,
12,15,14,12,11,13,14,11,12,14,15,14,14,13,10,5,9,5,10,16,5,12,13,12,13,12,11,13,14,11,
8,12,11,15,12,12,13,13,12,10,12,12,14,14,13,13,10,5,2,5,11, };
static unsigned short stb__courier_27_usascii_h[95]={ 0,16,8,18,19,16,14,8,19,19,9,13,8,2,
4,19,16,15,15,16,15,16,16,16,16,16,12,14,13,6,13,15,18,14,14,15,14,14,14,15,14,14,15,14,
14,14,14,15,14,17,14,15,14,15,14,14,14,14,14,19,20,19,7,2,5,12,16,12,16,12,15,16,15,16,
21,15,15,11,11,12,16,16,11,12,15,12,11,12,11,16,11,19,19,19,4, };
static unsigned short stb__courier_27_usascii_s[95]={ 246,190,65,80,52,167,1,246,69,74,236,
45,58,118,251,35,179,163,140,145,152,156,235,1,26,51,97,12,32,86,19,
246,92,236,192,202,167,154,140,188,114,103,174,74,61,220,205,127,128,103,1,
230,242,215,16,88,46,32,181,46,10,63,75,130,100,58,37,71,12,84,62,
221,74,195,1,89,102,205,192,102,207,117,179,130,114,141,221,115,154,131,168,
29,26,20,106, };
static unsigned short stb__courier_27_usascii_t[95]={ 17,1,68,1,1,1,55,55,1,1,55,
55,68,68,55,1,1,23,23,1,23,1,1,23,23,23,55,55,55,68,55,
1,1,40,40,23,40,40,40,23,40,40,23,40,40,40,40,23,40,1,40,
23,23,23,40,40,40,40,40,1,1,1,68,68,68,55,23,55,23,55,23,
1,23,1,1,23,23,55,55,55,1,1,55,55,23,55,55,55,55,1,55,
1,1,1,68, };
static unsigned short stb__courier_27_usascii_a[95]={ 229,229,229,229,229,229,229,229,
229,229,229,229,229,229,229,229,229,229,229,229,229,229,229,229,
229,229,229,229,229,229,229,229,229,229,229,229,229,229,229,229,
229,229,229,229,229,229,229,229,229,229,229,229,229,229,229,229,
229,229,229,229,229,229,229,229,229,229,229,229,229,229,229,229,
229,229,229,229,229,229,229,229,229,229,229,229,229,229,229,229,
229,229,229,229,229,229,229, };

// Call this function with
//    font: NULL or array length
//    data: NULL or specified size
//    height: STB_FONT_courier_27_usascii_BITMAP_HEIGHT or STB_FONT_courier_27_usascii_BITMAP_HEIGHT_POW2
//    return value: spacing between lines
static void stb_font_courier_27_usascii(stb_fontchar font[STB_FONT_courier_27_usascii_NUM_CHARS],
                unsigned char data[STB_FONT_courier_27_usascii_BITMAP_HEIGHT][STB_FONT_courier_27_usascii_BITMAP_WIDTH],
                int height)
{
    int i,j;
    if (data != 0) {
        unsigned int *bits = stb__courier_27_usascii_pixels;
        unsigned int bitpack = *bits++, numbits = 32;
        for (i=0; i < STB_FONT_courier_27_usascii_BITMAP_WIDTH*height; ++i)
            data[0][i] = 0;  // zero entire bitmap
        for (j=1; j < STB_FONT_courier_27_usascii_BITMAP_HEIGHT-1; ++j) {
            for (i=1; i < STB_FONT_courier_27_usascii_BITMAP_WIDTH-1; ++i) {
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
        float recip_width = 1.0f / STB_FONT_courier_27_usascii_BITMAP_WIDTH;
        float recip_height = 1.0f / height;
        for (i=0; i < STB_FONT_courier_27_usascii_NUM_CHARS; ++i) {
            // pad characters so they bilerp from empty space around each character
            font[i].s0 = (stb__courier_27_usascii_s[i]) * recip_width;
            font[i].t0 = (stb__courier_27_usascii_t[i]) * recip_height;
            font[i].s1 = (stb__courier_27_usascii_s[i] + stb__courier_27_usascii_w[i]) * recip_width;
            font[i].t1 = (stb__courier_27_usascii_t[i] + stb__courier_27_usascii_h[i]) * recip_height;
            font[i].x0 = stb__courier_27_usascii_x[i];
            font[i].y0 = stb__courier_27_usascii_y[i];
            font[i].x1 = stb__courier_27_usascii_x[i] + stb__courier_27_usascii_w[i];
            font[i].y1 = stb__courier_27_usascii_y[i] + stb__courier_27_usascii_h[i];
            font[i].advance_int = (stb__courier_27_usascii_a[i]+8)>>4;
            font[i].s0f = (stb__courier_27_usascii_s[i] - 0.5f) * recip_width;
            font[i].t0f = (stb__courier_27_usascii_t[i] - 0.5f) * recip_height;
            font[i].s1f = (stb__courier_27_usascii_s[i] + stb__courier_27_usascii_w[i] + 0.5f) * recip_width;
            font[i].t1f = (stb__courier_27_usascii_t[i] + stb__courier_27_usascii_h[i] + 0.5f) * recip_height;
            font[i].x0f = stb__courier_27_usascii_x[i] - 0.5f;
            font[i].y0f = stb__courier_27_usascii_y[i] - 0.5f;
            font[i].x1f = stb__courier_27_usascii_x[i] + stb__courier_27_usascii_w[i] + 0.5f;
            font[i].y1f = stb__courier_27_usascii_y[i] + stb__courier_27_usascii_h[i] + 0.5f;
            font[i].advance = stb__courier_27_usascii_a[i]/16.0f;
        }
    }
}

#ifndef STB_SOMEFONT_CREATE
#define STB_SOMEFONT_CREATE              stb_font_courier_27_usascii
#define STB_SOMEFONT_BITMAP_WIDTH        STB_FONT_courier_27_usascii_BITMAP_WIDTH
#define STB_SOMEFONT_BITMAP_HEIGHT       STB_FONT_courier_27_usascii_BITMAP_HEIGHT
#define STB_SOMEFONT_BITMAP_HEIGHT_POW2  STB_FONT_courier_27_usascii_BITMAP_HEIGHT_POW2
#define STB_SOMEFONT_FIRST_CHAR          STB_FONT_courier_27_usascii_FIRST_CHAR
#define STB_SOMEFONT_NUM_CHARS           STB_FONT_courier_27_usascii_NUM_CHARS
#define STB_SOMEFONT_LINE_SPACING        STB_FONT_courier_27_usascii_LINE_SPACING
#endif

