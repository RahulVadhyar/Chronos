// Font generated by stb_font_inl_generator.c (4/1 bpp)
//
// Following instructions show how to use the only included font, whatever it is, in
// a generic way so you can replace it with any other font by changing the include.
// To use multiple fonts, replace STB_SOMEFONT_* below with STB_FONT_consolas_34_usascii_*,
// and separately install each font. Note that the CREATE function call has a
// totally different name; it's just 'stb_font_consolas_34_usascii'.
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

#define STB_FONT_consolas_34_usascii_BITMAP_WIDTH         256
#define STB_FONT_consolas_34_usascii_BITMAP_HEIGHT        148
#define STB_FONT_consolas_34_usascii_BITMAP_HEIGHT_POW2   256

#define STB_FONT_consolas_34_usascii_FIRST_CHAR            32
#define STB_FONT_consolas_34_usascii_NUM_CHARS             95

#define STB_FONT_consolas_34_usascii_LINE_SPACING          22

static unsigned int stb__consolas_34_usascii_pixels[]={
    0x00000266,0x400002a0,0x00000019,0x00397000,0x000de544,0x0003ba20,
    0x059bfb95,0x22aa8000,0x88001aa8,0x2a0002aa,0x0035512a,0x00bcca80,
    0x9aa8554c,0x35ff8000,0x0003bdff,0x2001df50,0xff36fedb,0xffff9803,
    0xfff37fff,0x200dffff,0x4400fffd,0x3ffffffd,0x00ff5000,0x7ffffec4,
    0x80000eff,0x37f44ff8,0x03ffd400,0x3eafff00,0xfb10003f,0x2203dfff,
    0x3fffe5ff,0x57fe003e,0x05fffff9,0x03bfea00,0xdffffd10,0x9803ffe6,
    0x7fffffff,0xfffffff3,0x3fffe00d,0x37ffea02,0x004ffecb,0xf3007fb8,
    0xfffbdfff,0xb80003ff,0x0ffdc1ff,0x01ffea00,0xff57ff80,0x3ff20007,
    0xf906ffcc,0x7ffffc1f,0x5ff801ef,0x0bfffae6,0x03ffe600,0x2b7fff60,
    0x803bfee0,0x7fe99999,0x33339ff3,0x3fffa001,0x01bff501,0x31007ff7,
    0x0157ffd7,0x2606fff4,0x40007ffe,0x4ff886fe,0x03ffd400,0x3eafff00,
    0xff88003f,0xf507fea3,0xfca9987f,0x7fc02fff,0x00fff505,0x801fff88,
    0x3200eff9,0x7f4005ff,0x0007ff37,0xf88176c4,0x03fe404f,0xffffffb1,
    0xff501fff,0x17ff440b,0x02ffa800,0x54001ffb,0x3e0007ff,0x007ff57f,
    0x7c41ff30,0x402ff42f,0x201fffd8,0x3ffa05ff,0x0bff2000,0x4027fdc0,
    0x3a002ffd,0x007ff37f,0x06fe8000,0xff505ff0,0xffffffff,0x01ffd01f,
    0x0006ffa8,0x7fcc0ffb,0x1ffea003,0xf57ff800,0xff50007f,0x3f23ff81,
    0x3ff6000f,0xc817fe05,0xff3001ff,0x0ffe400d,0x007ffcc0,0x7ff37fe8,
    0x7d400000,0x8bfb001f,0xff2cfff8,0xff502a25,0x07ffe00b,0x807ff300,
    0x3e6006fe,0x3fe0006f,0x0007ff57,0x7fc45ff3,0x8007ff31,0xff00fff9,
    0x017fd40b,0x2001ffe8,0x3f2007fc,0x2ffd004f,0x32203ff9,0xcccccccc,
    0x005fd84c,0xbff91fea,0x2e00ffc4,0xffb003ff,0x0ffc8005,0x8017fd40,
    0x54406ff9,0x7ffcdeec,0x76547ff5,0x1bff02ce,0x37f43ff2,0x01fff800,
    0x7fd40bff,0x05ffa802,0x1003fe40,0xfd001fff,0x880ffe6f,0xffffffff,
    0x0ffcc7ff,0xf88984c4,0x987ffa0f,0x7fe400ff,0x07ff7001,0x802ffc40,
    0xff3005ff,0x7fffdc0d,0xf57fffff,0x3ffff67f,0xfffb84ff,0x3ff93fff,
    0x07ffa000,0xff502ffc,0x03ffb005,0x4007fc80,0xfe802ffc,0x4407ff37,
    0xeeeeeeee,0x237e47ff,0x8ffffff9,0x3ffa1ff8,0x3601fea2,0xff7000ff,
    0x0ffdc009,0x800ffc80,0xfe886ff9,0xffdccdff,0xfd7ff57f,0x7fffd9bf,
    0x25ffff70,0x10003ff9,0x2ffc0fff,0xf005ff50,0xff9000ff,0x05ff9800,
    0x7ff37fe8,0x47ff8000,0x3ffe64fe,0x87fe7ffe,0x1bee6ffc,0xa801ffe0,
    0x3fa005ff,0x13fe2006,0x321bfe60,0xfff00dff,0x07bfffea,0x0440dff7,
    0x44001bfa,0x3fe05ffd,0x00bfe605,0xb0009ff5,0xfff000df,0xf37fe801,
    0xff80007f,0xdfd17fc7,0x45ff37f4,0xfcaefff9,0x007ff805,0x4c017fea,
    0x7ec003ff,0x45ff8807,0x7fc06ff8,0x01dfff57,0x5c00bff6,0xdd3001ff,
    0x401ffffd,0x27fc05ff,0x000bff20,0x360013fa,0xbff401ff,0x40003ff9,
    0x43fe67ff,0x97fa1ffa,0x7ffdc2fe,0xff804fff,0x9ff5000f,0x003ff600,
    0x8805ff50,0x17fe45ff,0x7fd5ffe0,0x13fee00e,0x8013fe20,0x1dfffff9,
    0x3602ffc0,0x3ff603ff,0x17fe4001,0x017fdc00,0x1ffcdffa,0xb9ffe000,
    0xff1bf66f,0x74c17fc7,0x01cfffff,0x5c007ffa,0xff8803ff,0x0dfd0004,
    0x7ec5ff88,0xf57ff807,0x5ff9807f,0x4006fd80,0x000adff9,0xfc880bff,
    0x7ff46eff,0x7ff74c00,0xff70002e,0xf37fe807,0xff80007f,0x4ff97f27,
    0x1ff8bfe6,0x3ffff6a0,0x2ffd80cf,0x005ff900,0x20003ff9,0x3e201ffb,
    0x403ffc5f,0x07ff57ff,0x5c05ff88,0x599711ff,0x000ffe60,0x3ea00bff,
    0x03ffc7ff,0x0077ffcc,0x809ff500,0x07ff37fe,0x327ff800,0x547ff15f,
    0x007fe1ff,0xdffffff3,0x004ffc81,0xff003fff,0x7fc4000b,0x897fe205,
    0x7ff806ff,0xf8807ff5,0x53fe206f,0x85fffff9,0x7c002ff9,0x7fec405f,
    0x03ffc4ce,0x27ffee44,0x04ff9800,0x3ff9bff4,0xb3ffc000,0xb8bfe69f,
    0x01ff10ff,0xffb8ffa8,0x03ffcc6f,0x5402ffd4,0x640002ff,0x93fe00ff,
    0xff806ff8,0x8807ff57,0x3ff605ff,0xfebeff88,0x017fcc2f,0xf9017fe0,
    0x07ff403f,0x00bff200,0xd013fea0,0x00ffe6ff,0x7ecfff00,0x7e45ff34,
    0x2e01fea7,0x07ffe26f,0xfe807ffd,0x06fe802f,0x03ff9800,0x0dff0b32,
    0x3feafff0,0x827fd403,0x1ff72ffa,0x332237f4,0x02ffc001,0xffb013fe,
    0x09fd0003,0x807ff700,0x07ff37fe,0x3a7ff800,0x745ff33f,0x2013ee6f,
    0x1ffe45fc,0x6c0bffee,0xff9806ff,0xffd00003,0x80fff000,0x7ff57ffb,
    0x882ffb80,0x717f65ff,0x7c0000ff,0x0bfe605f,0x0003ff90,0xf9000ffb,
    0x37fe805f,0xf80007ff,0x7cd3f67f,0x74dff53f,0x44fd802f,0xffd83ffc,
    0xffecabdf,0x0ffc801f,0x5ff50000,0x02ffd800,0x3eaffff5,0x3ffe203f,
    0x360ffd80,0x003fd45f,0x540bff00,0x7fdc02ff,0x0ffc8003,0x007ff400,
    0x1ffcdffa,0xc9ffe000,0xd3dff15f,0x1ff95ffd,0x7c47fd00,0xfffb02ff,
    0x01dfffff,0x0009ff10,0xe985ff80,0x42ffd44f,0xf57ffff9,0x1ffe407f,
    0x3f217fd4,0x3ea37dc6,0x2ffc003f,0x8805ff50,0xfc8006ff,0x3fe2000f,
    0xf37fe806,0xff80007f,0xffc97ee7,0xffffd9ff,0x3fe05441,0x01fffb32,
    0x77fffed4,0x3ff7000b,0xffb80000,0x217ffec1,0xfdaadfff,0xff57fdcf,
    0xfd53337d,0x0bff10df,0x3fe27ff7,0x007fffc4,0x7d40bff0,0x1ffe802f,
    0x007fe400,0xd007ff70,0x00ffe6ff,0x7dcfff00,0xc98ef546,0xeff881ce,
    0xfffeffcd,0xff3001ff,0x0dfd000b,0x9ff10000,0x4c2fffe8,0x4fffffff,
    0x3ffeaffb,0xdfffffff,0xd00ffc80,0x81ffffff,0x2000ffff,0x3fea05ff,
    0x04ffb802,0x0007fe40,0xfd001ffd,0x000ffe6f,0x7fd4fff0,0xff880000,
    0xffffffff,0x7fc001df,0x3fea000f,0xfb000002,0x837fd41f,0x23dfffe9,
    0x3fae67fc,0x302defff,0x7ec407ff,0xffb80dff,0x02ffc005,0xf1005ff5,
    0x7e4001ff,0x9ff5000f,0x7cdffa00,0x7fc0003f,0x0001ffc6,0xfffedca8,
    0xb0001cde,0x82981bff,0x000007fd,0x0310ffe6,0x18800060,0x00600000,
    0x3fe00062,0x00bfea05,0x9002ffdc,0xff1001ff,0x5ffa001f,0x20003ff9,
    0x37e44ff9,0x6fb80000,0xfff10000,0x41ffd9df,0x00004ff8,0x00037f40,
    0x00000000,0x40000000,0x3ff205ff,0x07ffa001,0x4017fdc0,0x3a003ffc,
    0x007ff37f,0x261ffe40,0x800002ff,0x200005fd,0xfffffff9,0x003ff22f,
    0x3ff70000,0x80155550,0x55554c08,0x990aaaaa,0x99999999,0x99999999,
    0xf8000005,0x03ffe05f,0x00fff980,0x4c05ffa8,0x7f4006ff,0x5407ff37,
    0x01fff500,0x01805ffd,0x00027f40,0x37bb6e20,0x0003cc83,0x10599000,
    0x2e01dffb,0xfff90eff,0x23ffffff,0xffffffff,0xffffffff,0x000004ff,
    0x7dc42ffc,0xffb8006f,0x7ffc400e,0x01fff302,0xff37fe80,0x5e77f407,
    0x102fffec,0x5337bffd,0xff800fd7,0x00000003,0x00000000,0x2077fdc0,
    0xf95ffff9,0xffffffff,0x3bbbbba3,0xeeeeeeee,0x0003eeee,0xc8affc00,
    0x002ffffd,0x900bff90,0x227bffff,0x32201ffe,0x37ffcccc,0x79999bff,
    0x3ffffffa,0x7ec402ff,0x6fffffff,0x00000000,0x00000000,0x3fe60000,
    0x3fffee0e,0x55555536,0x00001555,0xf8000000,0xfffff35f,0xffd80007,
    0x7ffe4400,0x805ff56f,0xfffffff9,0xffffff37,0x3fb6e6df,0x26000bde,
    0x01bdeedb,0x00000000,0x00000000,0x3cc88000,0x017fffe6,0x00000000,
    0x2bff0000,0x000bcde8,0x4c001b00,0x00ae5ecb,0x3bbbbba2,0xddddd35e,
    0x00000bdd,0x00000000,0x00000000,0x00000000,0x000effc8,0x00000000,
    0x02ffc000,0x00000000,0x00000000,0x00000000,0x00000000,0x00000000,
    0x44000000,0x00000001,0xf0000000,0x000000bf,0x00000000,0x00000000,
    0x00000000,0x00000000,0x00000000,0x00000000,0x00000000,0x00004ee8,
    0x00000000,0x00000000,0x00000000,0x00000000,0x00000000,0x00000000,
    0x00000000,0x00000000,0x00000000,0x00000000,0x00000000,0x00000000,
    0x00000000,0x00000000,0x00000000,0xdfd91000,0x2aa60039,0x200aaaaa,
    0x2e0002aa,0x997002cc,0x401cb803,0x80001aa8,0xccefedb8,0x4001cccc,
    0x0aaccba8,0x37b72a20,0x19936cab,0x01677654,0x0001edc4,0x0b37f72a,
    0x99999950,0x30099999,0x0059bfb7,0x5c013f62,0x4fffffff,0xfffffc80,
    0x1bfe01ff,0x06ffb800,0x200fff88,0x2a01fffc,0x540003ff,0xffffffff,
    0x1002ffff,0xfffffff9,0x3ffff207,0xf57fffff,0x3ffff63f,0x7fcc04ff,
    0xffb10004,0x01dfffff,0x3ffffff2,0x6c07ffff,0x4fffffff,0x04fffe80,
    0x75efffcc,0x7e402fff,0x01ffffff,0x88001bfe,0x7dc01fff,0x7fff404f,
    0x00ffea04,0xacfff980,0xccefffb9,0xdfffd001,0xd887ffdd,0xfdccdfff,
    0xd7ff57ff,0xfffd9bff,0x027fcc07,0x77fffcc0,0x81ffffec,0xeeeeeffc,
    0xfb106eee,0xfffb9bff,0x3ffe201b,0x17fec06f,0x20017fee,0x3fe01ffc,
    0x7fe40006,0x00fff404,0xa80bfff6,0x3a0003ff,0xfff882ff,0x3bfee000,
    0x7fe40881,0x2afff00d,0x5c1effff,0x3fe606ff,0xdffe8004,0x43fff440,
    0x360007fc,0xffe885ff,0x13fffe03,0xff10fff0,0x3ff9000f,0x00037fc0,
    0xf881ffe6,0x3ed8806f,0x001ffd40,0x2e05ff88,0x3fe003ff,0xdff1001f,
    0xff57ff80,0x3ff601df,0x009ff302,0x2205ffb8,0x3fe42ffe,0x0eff8800,
    0x4c0dff30,0x3e200eff,0x00dff06f,0x7c03ff90,0xfe80006f,0x07ff702f,
    0x3ffa8000,0x09ff5000,0x88027fd4,0x3f2006ff,0xabffc02f,0x3ee00eff,
    0xfb99994f,0x999999df,0x801fff09,0x3fe46ffa,0x02ffb800,0x00017fec,
    0xff987ff8,0x1ffc8005,0x0001bfe0,0x7f417fee,0x5400000f,0xf50003ff,
    0x1ffd409f,0x005ff980,0x3fe01ffa,0x9807ff57,0xfffff5ff,0xffffffff,
    0x37fd41ff,0x321fff80,0xfff0007f,0x05ffd801,0x47ffd000,0x8001ffe8,
    0x3fe01ffc,0x81e65c06,0x7cc0fff8,0x9999505f,0x7d401999,0x37bf6e3f,
    0x40dff101,0xf3001ffd,0x3ffc009f,0xffabffc0,0xdaffc403,0xefffeeee,
    0x20eeeeee,0xfb003ffb,0x003fe45f,0xd102ffc4,0x0000dfff,0x3a63ffea,
    0xf90004ff,0x037fc03f,0x6401dffb,0x17fe43ff,0xffffffc8,0x2ffea01f,
    0xffffffe8,0x81bffb03,0x26006ffc,0xff1004ff,0x2afff00d,0x7fc403ff,
    0x009ff306,0xb800ffe4,0x01ff23ff,0x5413fe60,0x007fffff,0x3ffff600,
    0x320003ff,0x1bfe01ff,0x20077fec,0x3ff46ff9,0xffdddd70,0x67fd403f,
    0xfffccfff,0xffff981f,0x00fffedd,0xff733331,0x3333333b,0x7c037fc4,
    0x807ff57f,0xff305ff8,0x07ff4009,0x324ffb80,0xceffffff,0x907ff501,
    0x0ffd7fff,0x7ffcc000,0x640001ef,0x1bfe01ff,0x4003bff6,0x9ff31ffe,
    0x01ffc800,0x83bfffea,0xfe84ffd8,0xdfffffff,0x3ffff200,0xffffffff,
    0x037fc7ff,0x3ffabffc,0x981ffcc0,0x3fe004ff,0xbff5000f,0x7fffffe4,
    0x7dc0efff,0x3fffa23f,0x0001ffb1,0x7ffffd30,0x32005550,0x1bfe01ff,
    0x4001dffb,0x3ff94ffb,0x01ffc800,0x4c1bffea,0x4ffd46ff,0x8009baa8,
    0xfffffffc,0x7fffffff,0x3ee03ffc,0x807ff57f,0xff302ffb,0x03ffc009,
    0x54cbff50,0xffecbaaa,0x4bfee0ef,0x360dfffa,0x003100ff,0xfffdfff3,
    0x9006ff83,0x37fc03ff,0x8001dff9,0x6ff8fff8,0x01ffc800,0xf803bfea,
    0x003fe47f,0x2e666620,0x99999dff,0x817fec19,0xff57fffa,0x00fff807,
    0x74009ff3,0xff5000ff,0x7ffd4009,0x3f6ffea4,0x0ffe83ff,0x200effb8,
    0xfffb2fff,0x401bfe21,0x3fe01ffc,0x001dff96,0x3ff3ff60,0x1ffc8003,
    0xd00ffea0,0x0cffd8ff,0x3fe60000,0x1bfea004,0x55ffffe6,0x3ff203ff,
    0x013fe603,0x7001ffe8,0xfa8007ff,0x3fffe66f,0x0ffd01ff,0x5c17fffe,
    0x3ffa24ff,0x200bff56,0x3fe01ffc,0x000effce,0x3ffffe60,0x1ffc8000,
    0xd00ffea0,0xffffa8ff,0x0bceeeff,0x013fe600,0xb55bfff0,0x2affd9ff,
    0xb999beff,0x7cc06ffe,0x3ff6004f,0x03ff9002,0x227ff880,0x200dffff,
    0xfffd06ff,0x103ffa0f,0x9ff79fff,0x807ff200,0x05ffdfff,0x5fffe800,
    0x03ff9000,0x3a01ffd4,0xffffc87f,0x5fffffff,0x009ff300,0xffffff98,
    0x3eaffd4f,0xffffffff,0x7fcc00df,0x13ff2004,0x0007ffc0,0xfff07ffc,
    0x05ff9807,0xf01ffff5,0x3ffea0ff,0xf9001ffe,0xeb7fc03f,0x5c0005ff,
    0x90001fff,0x7fd403ff,0x6c3ff403,0xecccccff,0x9804ffff,0xe98004ff,
    0x3fa3dfff,0xffffff57,0x26005bdf,0x3e6005ff,0x6ffa807f,0x46ff8800,
    0x7e401ffe,0x1fff602f,0xfb807ffc,0x32006fff,0x5bfe01ff,0x0004ffe8,
    0x80017fee,0x3ea01ffc,0x23ff403f,0x32202ffd,0xff9807ff,0xf80c0004,
    0x267ff57f,0xff880009,0x3ffa000f,0x017ff402,0x2a27fe40,0x3fe205ff,
    0x837fdc07,0x3f602ffe,0x3f2003ff,0x89bfe01f,0x88004fff,0x20001fff,
    0x3ea01ffc,0x13ff403f,0x3fe00dff,0x27fcc01f,0x7ff80000,0x00007ff5,
    0xa800bffe,0xffb02fff,0xfff7000b,0x205ffd01,0x7ec03ffd,0x1dff903f,
    0x01bfff20,0x3e01ffc8,0x1fffcc6f,0x017ff600,0x403ff900,0x7f403ffa,
    0x4017fea7,0xff9807ff,0xff000004,0x000ffeaf,0x5efffe40,0xfd80ca99,
    0xfecabdff,0x99ac81ff,0x1fffeba9,0x359fff70,0x401dffd7,0x3e206ffc,
    0xebaabfff,0x005fffff,0x7fc03ff9,0x02fffa86,0x00effd88,0x00ffe400,
    0xfe807ff5,0x00bffe67,0xf300bff9,0x2000009f,0x07ff57ff,0x7fff4000,
    0xb00fffff,0xffffffff,0x3fffe01d,0x01efffff,0x7fffffd4,0xffb705ff,
    0xff9801df,0xdfffffff,0x5543fffb,0xacffdaaa,0x0dff0aaa,0x360bffee,
    0x01ffffec,0x6d555540,0x0aaaacff,0xfe807ff5,0x66ffff47,0xefffcbab,
    0x04ff9800,0x2fff0000,0x00003ffa,0x7fffffdc,0x3ff6e00e,0x7fc04eff,
    0x02dfffff,0x3ffff660,0x3fffa03d,0x3fb22004,0x3ee1dfff,0xffff11ff,
    0xffffffff,0xc81bfe3f,0x7ffc1fff,0x44000dff,0xffffffff,0xf51fffff,
    0x47fe807f,0xffffffe8,0x000dffff,0x00009ff3,0x7fd5ffe0,0x26000003,
    0x01880019,0x004cccc0,0xb800c400,0x4c00009b,0x7ffc4000,0xffffffff,
    0x80dff1ff,0x3ba1fffd,0xf10002cd,0xffffffff,0x3ea3ffff,0x83ff403f,
    0xceffedc9,0x7fcc000c,0xdb000004,0x000bba6b,0x00000000,0x00000000,
    0x00000000,0x00000000,0x00000000,0x00000000,0x00000000,0x00000000,
    0x00000000,0x00000000,0x53000000,0x44019997,0x0bdefedb,0x3fb2a600,
    0x65c01bee,0x0bceffed,0x3333332a,0x9912cccc,0x00f32007,0x9ddfd973,
    0xffedb883,0x32e00bde,0xcccccccc,0x32e2cccc,0x3997002c,0x2001e65c,
    0xcb981ccb,0x9700cdfe,0xcca80059,0x80059911,0x93f623ca,0xd700aaa9,
    0x03ffffff,0x3fffffee,0xfc803fff,0xffffffff,0xffffea83,0x360fffff,
    0xffffffff,0x0bff14ff,0x6c41bfe0,0xffffffff,0x3ffff65f,0xd03fffff,
    0xffffffff,0x549fffff,0x7d400fff,0x3ffea0ef,0x1fff5001,0xffffffc8,
    0x5ffb83ff,0x88fff400,0x7ec004ff,0x5d3fffa6,0x7fcc1fff,0x1eeeffff,
    0xbcefffb8,0x102ffffd,0xdbdffffd,0xffb87fff,0xfecccdff,0x3bbbb20f,
    0x14ffeeee,0x3fe00bff,0xfffffa86,0x25fffede,0xfecccefd,0xffe82fff,
    0xffffffff,0x7fec4fff,0x0bffe205,0x74017ff6,0x3ffa23ff,0xfffedcef,
    0x007ffcc1,0x3e26ff98,0xb7f4004f,0xf56ffff8,0x7ffcc1ff,0xff8801ae,
    0x0fff901f,0x205ffff1,0x3ffe63c8,0x2e000403,0x0bff14ff,0xff51bfe0,
    0x92e203df,0xdffb1009,0x7ffd4000,0x817ffc40,0xff305ffc,0x6ffa803f,
    0x6c06ff44,0x2ffe86ff,0xf87ff700,0x2ff4005f,0x3ea9ffff,0x0fffa0ff,
    0x40bff500,0x7e40fff8,0x7e4000ef,0xb800006f,0x0bff14ff,0xffd1bfe0,
    0x3e00000b,0xf88000ff,0xdff702ff,0x401fff30,0x7f406ffc,0x2203882f,
    0x7fdc1fff,0x83ffd005,0x7f4005ff,0x543bfe64,0x13fee7ff,0x00ffee00,
    0x7fc41ffd,0xffd8000f,0xfb800002,0x00bff14f,0x6ffb9bfe,0x3fa00000,
    0xffc8001f,0x21fff405,0x7c403ffe,0xbff502ff,0x17fec000,0x1003ffe6,
    0x0dfd0dff,0x9804ff80,0x01bfe7ff,0x102ffcc0,0x4ffc8bff,0x07ffb000,
    0x9ff70000,0x7c017fe2,0x03fff16f,0x3ff40000,0x07ffd400,0x5c3ffe60,
    0xff7005ff,0x007ffa0d,0xe83ffc80,0x7fdc02ff,0x4006fe83,0xff9803ff,
    0x0007ff36,0xfc81fff4,0x00fff43f,0x00effc80,0xa7fdc000,0xff005ff8,
    0x0017fe6d,0x04ff8800,0x017ff440,0xff8dffc8,0x3ffa001f,0x0027fdc3,
    0x2e0bff20,0x7ff405ff,0xa987fd81,0x401ffc40,0x3ff76ff8,0x5c00d4c4,
    0xfd30dfff,0x07ff81df,0x3fffe200,0x3ee00002,0x00bff14f,0x1ffddbfe,
    0xfe880000,0x7fe4001f,0x3ffe2005,0x54003ffe,0xfff10fff,0xffe80001,
    0x207ff981,0xffb06ff8,0xff889ff0,0x36555002,0xffffc9ff,0x3ea00dff,
    0x4fffdfff,0x0006ff88,0x5f7fffd4,0x7fdc0000,0x200bff14,0x05ff96ff,
    0x13333331,0xff975530,0xff98001d,0x7fd4000f,0xfd0006ff,0x00ffee7f,
    0x40dff300,0xff702ffe,0xf31ff207,0x02ff88ff,0xfffffd00,0x3fffffff,
    0x7ffff440,0x0bff504f,0xfffd3000,0x200039ff,0xbff14ffb,0x7edbfe00,
    0xffffc81f,0xfffc85ff,0x44001fff,0xb0002ffe,0x20003fff,0x6ff8fff9,
    0x7ff44000,0x413fee02,0xff700ffd,0x317ffe41,0x3a0003ff,0x310adfff,
    0x7d40dffd,0x84ffffff,0x00005ffa,0x3fffffaa,0x4ffb8004,0x3e00bff1,
    0x903ffd6f,0x0bffffff,0xfffffff9,0x3ff2001d,0x3ffa0005,0x3f60003f,
    0x0002ffef,0x26027fec,0x6ff887ff,0xff83fee0,0x07fe65ff,0x00fffc00,
    0x3f20fffa,0xfffeabff,0x01bfea0d,0x3ff26000,0x2e000eff,0x0bff14ff,
    0x7fedbfe0,0xfbaaa982,0xfea9805f,0x7fcc00ff,0xff70000f,0x20003fff,
    0x006ffff8,0x8037fe40,0x7fd41ffe,0x4c3fea03,0x3ea7fcff,0x00f7220f,
    0xfa801ffd,0x077fec5f,0xf997ffee,0x2000007f,0x005fffc8,0x7fc53fee,
    0x32dff005,0xff8802ff,0x37fe4005,0x000bffa0,0x7fe7ffc4,0x3ff20006,
    0x3f20001f,0xff7000ef,0x200ffd89,0x3bf91ffa,0x83fea5ff,0x3603fffd,
    0x7fc401ff,0xa81bfe66,0xfff11fff,0xf5000000,0x3ee001ff,0x00bff14f,
    0x1ffddbfe,0x002ffc40,0xfc807ffc,0x3fa0005f,0x007ffd3f,0x001bfe20,
    0x000effc8,0xdff1bfe6,0xfd1ff980,0x3fdd7fe5,0x40dffff1,0xff801ffc,
    0xb00bfee7,0x17ffc7ff,0x7f400000,0x7ff7002f,0x2201bfe2,0x0dff55ff,
    0x000bff10,0xff303ffb,0x3ee0001f,0x03ffea6f,0x01bfe200,0x0077fe40,
    0xfa8fff40,0x57fcc03f,0x1ff90ff9,0xffff8ff7,0x00ffee05,0x7ff4bff3,
    0x92ffdc00,0x00000dff,0x2007ff90,0x1ffe2ffd,0x7c53fe60,0x7fc402ff,
    0x0ffe8005,0x0002ffe8,0xfd85fff1,0xff88005f,0xeffc8006,0x9ff70000,
    0xf1003ff6,0x7ccbf97f,0x7d46fcbf,0x3fe600ef,0xd1ffdc06,0xffc803ff,
    0x00fffe23,0x3ffd0000,0x43fff100,0x7ec01ffe,0x03bfee2f,0x4005ff88,
    0xffc86ff9,0x3ff60005,0x02fff885,0x0037fc40,0x0003bff2,0xdff6ff98,
    0xfd7ff100,0x6fcefe87,0xfd800988,0x1fff103f,0xf102ffec,0xfffc83ff,
    0x0010cc04,0x01d9ffee,0xffb8dff7,0x0dff500e,0x2203fffd,0x3a2005ff,
    0x7ffcc2ff,0xfff50000,0x03fff201,0x006ff880,0x0003bff2,0x3fefffa0,
    0xffbff003,0x5fdffc81,0x7ffcc000,0xfffb989c,0x5f7ffcc2,0x5fffc999,
    0xdefffe88,0x13fecbab,0x555579df,0x7c5fffd7,0xfffcacdf,0xbeffe81f,
    0x1fffca9a,0xceffff98,0x15ffdaaa,0xb5533357,0xffd09fff,0xdddddddf,
    0x7fc49ddd,0x27ff403f,0x00dff100,0x3bbbffee,0x4eeeeeee,0x7ffffe40,
    0xbffff000,0x0bffff30,0xffff5000,0x207fffff,0xfffffffa,0x7e405fff,
    0xffffffff,0xfffff13f,0x5fffffff,0xfffffff8,0xffd303ff,0x7fffffff,
    0x7fffec40,0x35ffffff,0xffffffff,0xfff107ff,0xffffffff,0x7fecdfff,
    0x1fffa806,0x00dff100,0x3ffffff2,0x5fffffff,0x37fffcc0,0x07fffd00,
    0x0013fffa,0x7fffecc0,0x7e4400df,0x02dfffff,0xffffd930,0x3b62159b,
    0xefffffff,0xfffd980b,0xec800dff,0x00dfffff,0xffffdb50,0x3fe617bf,
    0x0cefffff,0xffffff10,0xffffffff,0x00bffead,0x88037fec,0xff9006ff,
    0xffffffff,0xfd00bfff,0x7f4007ff,0xfff700ff,0x31000009,0x26620001,
    0x00980000,0x00266660,0x40001310,0x44000099,0x26620199,0x00000099,
    0x00000000,0x00000000,0x00000000,0x00000000,0x00000000,0x00000000,
    0x00000000,0x00000000,0x00000000,0x00000000,0x00000000,0xdd700000,
    0x04ccc809,0x33223cc8,0x1e65c02c,0x33333332,0x2ccccccc,0xcb805993,
    0x33332a2c,0xcccccccc,0x99910ccc,0x99999999,0x00f32279,0xccc89e64,
    0x402bcccc,0xccccccca,0x9952cccc,0x99999999,0x33332259,0x0009abcc,
    0x64c0cc88,0xccccc984,0x8000abcc,0x8002cccb,0x405fffea,0x7c02ffff,
    0x1bffe25f,0x7c6fff98,0xffffffff,0xf54fffff,0x77fdc07f,0x3fffff20,
    0xffffffff,0xffff11ff,0xffffffff,0x2017fe2d,0xfff16ff8,0x7fffffff,
    0x3fffff20,0x94ffffff,0xffffffff,0x3fe29fff,0xffffffff,0x3fe6000c,
    0x7d437e40,0xffffffff,0x3fe000df,0x3aa006ff,0x405fffff,0x7c06ffff,
    0x3fffe65f,0x8ffff900,0xffffffff,0x54ffffff,0x3fe607ff,0x77775c1f,
    0xeeefffee,0xddd11eee,0xdddfffdd,0x017fe29d,0x7fc5bfe2,0xffffeeef,
    0xeeffc83f,0x3eeeeeee,0xdddddff9,0x3e27dddd,0xfffeeeff,0xf5002fff,
    0xf50bfb0f,0xffddddff,0xf5001dff,0x9801ffff,0xffeffffe,0x7ffffc05,
    0xf997fe01,0xdff03fef,0x7e4000ff,0x107ff52f,0x44005ffd,0xf10006ff,
    0x2ffc40df,0xf8b7fc40,0x7fed445f,0x017fe41f,0x4003ff90,0xea885ff8,
    0xfb801fff,0xfa84fd87,0x9fff504f,0xffbffb00,0xcfffb807,0x7c05ffb8,
    0x3e05ffef,0x3f3fea5f,0x7fcffa86,0x4dff1000,0xffd83ffa,0x37fc4003,
    0x06ff8800,0x22017fe2,0x0bff16ff,0x3f21ffec,0x3ff2002f,0x17fe2001,
    0x900dff90,0x509fd0df,0x7fd409ff,0xf9eff806,0x067c405f,0xff80bff7,
    0xff01ffdd,0x7fcffd4b,0x3fde7ec1,0x22ffc800,0x7fe43ffa,0x6ff88005,
    0x0dff1000,0x4402ffc4,0x0bff16ff,0x3f22ffd4,0x3ff2002f,0x17fe2001,
    0x310bffa0,0x333dfb33,0x23339ff3,0x7fc04ffa,0xf9ffd407,0x5c0400ff,
    0x6ffc05ff,0xbff05ff9,0x24ffbfd4,0x0ffb9ff8,0x237fc400,0x3fea3ffa,
    0xdff10006,0x1bfe2000,0x8805ff88,0x0bff16ff,0x3f22ffd4,0x3ff2002f,
    0x17fe2001,0xf71bfea0,0xffffffff,0x2fffffff,0x3e204ffa,0x8ffec06f,
    0xb8003ffc,0xaffc05ff,0x5ff80ffe,0x73fe5fee,0x003feedf,0xfa87ff90,
    0x01dff33f,0x01bfe200,0x1037fc40,0xff100bff,0xb817fe2d,0x17fe44ff,
    0x003ff900,0xf802ffc4,0x7fffdc7f,0xffffffff,0x9ff57fff,0x201ffd40,
    0x17fea6ff,0x017fee00,0x13feabff,0x37fb97fe,0x5cffa3ff,0x3e2001ff,
    0x8bffa87f,0x20001ffe,0x10006ff8,0x7fc40dff,0x16ff8805,0x3fe20bff,
    0x017fe41f,0x4003ff90,0xfd005ff8,0x21ffc01f,0xffa80ff9,0x03fff304,
    0x3fe27fd4,0x7fdc000f,0xff2ffc05,0x325ff81f,0x3e33fa7f,0x003ff50f,
    0x7d41ffdc,0x002ffdbf,0x0037fc40,0x2206ff88,0xcccccfff,0x16ffcccc,
    0x7dcc4bff,0xbffc84ff,0x19999999,0x2aab3ff2,0xf10aaaaa,0x3ffa00bf,
    0xa85ff101,0x5bff507f,0x1bffb955,0x6c1ffd80,0x7dc002ff,0x72ffc05f,
    0x25ff89ff,0x2ffee7fc,0x007fea6f,0x5407ffc4,0x004fffff,0x006ff880,
    0x440dff10,0xffffffff,0x16ffffff,0xffffffff,0x3ff207ff,0xffffffff,
    0xfffff90f,0x23ffffff,0xfb005ff8,0x07fe605f,0x3fea0ff7,0xefffffff,
    0xa87ff801,0x7dc005ff,0x12ffc05f,0x2ffc1fff,0x7ffc4df9,0x00bfea2f,
    0xfa81ffdc,0x000fffef,0x0037fc40,0x2206ff88,0xffffffff,0x16ffffff,
    0xffffffff,0x7ffe4019,0xffffffff,0xffffff90,0x223fffff,0xff9005ff,
    0x903fe605,0x3ffea0df,0xffffffff,0x09ff500d,0x4001fff1,0x7fc05ffb,
    0xff1ffe45,0x3f637ecb,0x0bfea0ff,0x403ffe20,0x6ffcbffa,0x37fc4000,
    0x06ff8800,0x22017fe2,0x5dff16ff,0x405fff95,0xaaaacffc,0xff90aaaa,
    0x2ffc4003,0x502ffd80,0x20bfb0ff,0x64c44ffa,0xffb06fff,0x00bff605,
    0x7c05ffb8,0xf3ffc45f,0x2a37ecbf,0x17fcc5ff,0x5027fdc0,0x17ffa7ff,
    0x06ff8800,0x40dff100,0xf8805ff8,0x98bff16f,0xff900fff,0x0ffe4005,
    0x00bff100,0x99987ffe,0xe9999ffc,0x3ea199df,0x3ffe604f,0x2e07ff82,
    0x3ee005ff,0x42ffc05f,0x4bff2ffc,0x17fc46fe,0x3e00ffe6,0x3fea00ff,
    0x007fff13,0x001bfe20,0xf1037fc4,0xdff100bf,0x3ee17fe2,0x05ff905f,
    0x000ffe40,0x3e00bff1,0xffff30ff,0xffffffff,0x3ea1ffff,0x2ffdc04f,
    0x2aabbfea,0x0fffbaaa,0x80bff700,0x6ff885ff,0x037f4bff,0xb807ff30,
    0x7fd404ff,0x007ffe63,0x001bfe20,0xf1037fc4,0xdff100bf,0x7f417fe2,
    0x02ffc82f,0x8007ff20,0xfb805ff8,0x3fffe65f,0xffffffff,0xff50ffff,
    0x46ffa809,0xfffffffc,0x02ffffff,0xf80bff70,0xf3ffb05f,0x002ff4bf,
    0xff807ff3,0x1ffd400f,0x0003ffee,0x2000dff1,0x3e206ff8,0x6ff8805f,
    0x3ee0bff1,0x02ffc85f,0x8007ff20,0x7c405ff8,0x13fa03ff,0x3ea05ff1,
    0x27fd404f,0x3ffffffe,0x5fffffff,0x80bff700,0xbff305ff,0x02ffcbff,
    0x5c09ff10,0xffa804ff,0x005ffd83,0x80037fc4,0x3e206ff8,0x6ff8805f,
    0x7fc0bff1,0x017fe41f,0x4003ff90,0x7ec05ff8,0x227f406f,0xff501ff9,
    0x22ffd809,0x9999dffa,0xfff99999,0x05ffb800,0xffb02ffc,0x02ffcbff,
    0x7c09ff10,0xffa801ff,0x04fff883,0x001bfe20,0xf1037fc4,0xdff100bf,
    0xfb817fe2,0x017fe45f,0x4003ff90,0xfd305ff8,0x3ff803ff,0xfa807fcc,
    0x3ffee04f,0x400bff20,0x66642ffe,0xcceffecc,0x817fe2cc,0x3e5ffffa,
    0x3fe2005f,0x00bff705,0x7cc0ffea,0xff1002ff,0x9999100d,0x9999fff9,
    0x2017fe27,0xbff16ff8,0x90fffc40,0x7e4005ff,0xccccccdf,0x9dff12cc,
    0xfffffd99,0x42ff8803,0x3fea07fa,0xffccbaad,0x03ffc1ff,0xff8bff70,
    0xffffffff,0x17fe4fff,0x22bfffd0,0x3e2005ff,0x03fff05f,0xb80ffea0,
    0xf8801fff,0xfff8806f,0xffffffff,0x00bff16f,0x3fe2dff1,0x92ffe405,
    0x7e4005ff,0xffffffff,0xffff14ff,0x1bffffff,0xb83ff300,0x3ffea07f,
    0xdfffffff,0x002ffd41,0xfff8fff1,0xffffffff,0x017fe4ff,0x3e2bfff5,
    0x2ffc004f,0x5002ffdc,0xffd807ff,0x37fc400e,0x7ffffc40,0x6fffffff,
    0xf100bff1,0x017fe2df,0x3f21fff1,0x3ff2002f,0xffffffff,0xfffff14f,
    0x40017bdd,0x37e40ff9,0xffffff50,0x3f2039bd,0x7ff4002f,0x00000002,
    0x00000000,0x00000000,0x00000000,0x00000000,0x00000000,0x00000000,
    0x00000000,0x4ccc8800,0x99999930,0x32201579,0x5c40003c,0x401cdfed,
    0x04000000,0x677edcc0,0x7f65c402,0x51003def,0x017bddd9,0x1677ee54,
    0xefedca80,0x0b3263ce,0x26549970,0x2073bb2a,0x3f6e0cc9,0x12c981de,
    0x775c17db,0x00019803,0x203ffff6,0xfffffffa,0x7c40cfff,0x3ea0006f,
    0x3fffffff,0x00005f90,0xfc807f20,0x0dffffff,0xffffffa8,0x2e01ffff,
    0xffffffff,0xffffe884,0xb101efff,0xffffffff,0x201ffd4b,0xd9ff27fe,
    0x43ffffff,0xffe99ffa,0x7dc3ffff,0x75fffe8d,0x6c07ffff,0xfb8005ff,
    0xfa80ffff,0xffeeeeff,0x3fe20eff,0xfff70006,0x9fff9779,0x003fff98,
    0x437fec00,0xcabeffe8,0x7d40fffe,0xffeccdef,0x7ff440ff,0x4fedcdef,
    0x66ffffcc,0xe81ffffd,0xccbbceff,0x00ffea5e,0x47fe4ffd,0xfffcdffe,
    0x3effea0f,0xffffccff,0x33f37ee1,0xfbef8ffd,0xffff106f,0x77fc4007,
    0xffa80ffe,0x4dffd504,0x98006ff8,0xff981fff,0x27ffd40f,0x7ff44000,
    0x04ffb80e,0x0a989ff9,0xc89ffd30,0x85302fff,0xfd884ffe,0x027fdc6f,
    0xe807ff50,0x3fbff27f,0x93ff620e,0x20dffffa,0x3ee5ffd8,0xfdff14ff,
    0x7c41ff21,0x36006fff,0x80ffe9ff,0x3e204ffa,0x0dff12ff,0x405ffb00,
    0xfe984ffa,0xf30000df,0x3fe20bff,0x007ff406,0xf997fee0,0x3ee000ff,
    0x17ff404f,0x54003ffb,0x3ff403ff,0x101bfff9,0x7ffd4dff,0x5cdff305,
    0x3ffe0fff,0x6403fee4,0xf5007fff,0x203ffa9f,0x7dc04ffa,0x00dff13f,
    0xff00fff0,0x3bffa20f,0x7ffd4001,0x00bfee04,0x88005ff7,0x0fff67ff,
    0x801fff00,0x3ff25ffa,0x0ffea003,0x7fe4ffd0,0xa9ffe00e,0xff100eff,
    0x3e1ffdcf,0x07fee0ff,0x8806fff8,0x03ffa6ff,0xf3013fea,0x01bfe2bf,
    0xb00bff30,0x7fe403ff,0xfff9002f,0x00ffd805,0x4001ffd4,0x01ffe7ff,
    0x100bff10,0x7ffd4dff,0x3ffa800c,0xff93ff40,0x2a4cc803,0x3ff403ff,
    0x4ff81ff7,0xfb00ffdc,0x3ff9009f,0x7d407ff4,0xaffcc04f,0x4c006ff8,
    0xffc805ff,0x1fffdc02,0x007bff60,0x33333ffa,0x5ffdcccc,0xeeecca88,
    0xdff17ffe,0x04ff9800,0xffc8fff0,0xf500beff,0x27fe807f,0xa8001ffc,
    0x3ff403ff,0x4ff81ff7,0xff00ffdc,0x4ff9803f,0x7d407ff4,0xa7fdc04f,
    0x44006ff8,0xffb806ff,0x4fffa803,0x00effe88,0xfffffff0,0xbfffffff,
    0xffffffc8,0xff57ffff,0x3ffa800b,0xb81ffd00,0x1dffffff,0x3a01ffd4,
    0x007ff27f,0xd00ffea0,0x207fdcff,0x0ffdc4ff,0x4027fec4,0x7ff40ffe,
    0x404ffa80,0xdff12ffe,0x03fff000,0x3004ffa8,0x3e61bffd,0x7fc004ff,
    0xcccccccf,0x3f22cccc,0xaaaabdff,0x0bff37ff,0x004ffa80,0x7ed40ffd,
    0x3ea4ffff,0x93ff403f,0xf50003ff,0x27fe807f,0x27fc0ffb,0xfdc87fee,
    0x7e400eff,0x80ffe82f,0xf9104ffa,0x037fc4bf,0x40f7fdc0,0x003fffb8,
    0x744bffd3,0x3a000dff,0xfa8000ff,0x5ffe00ff,0x4c006ff8,0xdff005ff,
    0xfffd5100,0xd00ffea5,0x00ffe4ff,0x201ffd40,0x03fee7fe,0x1ffb89ff,
    0x200ffffe,0xffd05ff9,0x55bff501,0x1ffff955,0x80037fc4,0xeddefffe,
    0x802fffff,0xd884fffa,0xfb001eff,0xff90003f,0x3e7ff807,0x3e2000ff,
    0x5ff9806f,0x9affe400,0x3fe204ff,0x0007ff27,0xfd00ffea,0x3e07fdcf,
    0x90ffdc4f,0x3fa00135,0x01ffd00f,0xfffffff5,0xf881bfff,0x3f20006f,
    0xcdffffff,0x7fdc01ff,0x7ffe402f,0x05ffb802,0x201ffd80,0x3ff67ff9,
    0x17ff4004,0x000bff60,0x3fe2dff3,0xc9fff606,0xfa8001ff,0x73ff403f,
    0x44ff81ff,0x20001ffb,0x3fa02ffb,0xffffa80f,0x102defff,0x88000dff,
    0xf91abcba,0x7ffec01f,0x7fff7001,0x007ffd00,0xf703ffc8,0x7ffccfff,
    0xdff50403,0x01bfee01,0xff93ff20,0x7fffd80f,0x20007ff2,0x7f403ffa,
    0xff03fee7,0x001ffb89,0x555fff10,0x7ffd5555,0x33fea555,0xff100199,
    0xe800000d,0xdffd107f,0xfffa8001,0x77ffd404,0x4ba9999a,0x266fffea,
    0x47ffffeb,0x9abefffc,0x7fec4eba,0xffda99bf,0x4d5e741f,0x1fffcb99,
    0x2a73fff6,0x327feffe,0xfa8001ff,0x73ff403f,0x44ff81ff,0x30001ffb,
    0xffffffff,0xffffffff,0x0013fead,0x0001bfe2,0x985ff880,0x20005fff,
    0x200dffe9,0xfffffffb,0x7fec6fff,0xdaffffff,0xffffc87f,0x444fffff,
    0xfffffffd,0xffff81ef,0x3fffffff,0x7fffffc4,0x327fc9ff,0xfa8001ff,
    0x73ff403f,0x44ff81ff,0x30001ffb,0xffffffff,0xffffffff,0x0013fead,
    0x0001bfe2,0x541ffd80,0x80004fff,0x201effd8,0xfffffed8,0xfffb83ef,
    0x0ff90cef,0x3ffffb62,0xffd701df,0x36019dff,0xffffffff,0xfffd101c,
    0xc9ff21bf,0xfa8001ff,0x73ff403f,0x44ff81ff,0x20001ffb,0x99999999,
    0x999ffe99,0x0009ff50,0x0000dff1,0xf313fee0,0x800005ff,0x26007ffc,
    0x13100199,0x01330000,0x44001980,0x20009999,0x00000998,0x00000000,
    0x00000000,0xff501ffd,0xdff10009,0xfea80000,0x01fb80ff,0x03f70000,
    0x00000000,0x00000000,0x00000000,0x00000000,0x00000000,0x5407ff40,
    0xf88004ff,0xccccccff,0x66641ccc,0x1dffffed,0x00000020,0x2e000001,
    0x997002cc,0x00073263,0xcccc8997,0xcccccccc,0x00733222,0xa8019993,
    0x6644001a,0x4cccc402,0x99999999,0x44555309,0x00000aaa,0xfa80ffe8,
    0xff88004f,0xffffffff,0x7fffc2ff,0x0002efff,0x20000000,0xfb805ff8,
    0x7ff8806f,0xd0013fe6,0xfffff8ff,0x4fffffff,0x3a037fec,0x3fd803ff,
    0x07ffe400,0xffffffb0,0x7fffffff,0xff99bff2,0xe800002f,0x4ffa80ff,
    0xffff8800,0xffffffff,0x5e777fc2,0x00000002,0x5ff88000,0x00fff880,
    0xff127fdc,0x45ff800b,0xeeeeeeee,0x7443fffe,0xbff904ff,0x800bf600,
    0x205feff8,0xfffffffd,0x93ffffff,0x7ffc4dff,0x00000001,0x00000000,
    0x00000000,0xff880000,0x07ff9005,0x7fc1ffe8,0x13fe2006,0x20dff700,
    0x7cc2fff9,0x643a80ff,0x6c03622f,0x102ffacf,0x33333333,0x2e133333,
    0x3ffe25ff,0x00000001,0x00000000,0x00000000,0xff880000,0x0dff3005,
    0x7ec37fcc,0x7cc1cb87,0x3fe6003f,0x3ffee00f,0x7407ffa0,0x2a3f90ef,
    0x0ffa84ff,0x00000dfb,0xfff17fee,0x00000001,0x00000000,0x00000000,
    0xff100000,0x0fff400b,0xfc83ffc8,0x2a2ffc47,0xfd1002ff,0xbffb005f,
    0xea80fff2,0xfd9fbbff,0x24fe82ef,0x00004ff8,0x7fc4ffa8,0x0000000f,
    0x00000000,0x00000000,0xf8800000,0x3fee005f,0x701fff04,0x7ffd41ff,
    0x4007fee0,0xd1004ffd,0x00bff9ff,0x3fffffaa,0x81ff702e,0x55540ffc,
    0xaaaaaaaa,0x9ff51aaa,0x00007fe8,0x00000000,0x00000000,0x4c000000,
    0xffbaaaaa,0x0aaaaaae,0x7d43ffc4,0x43ff504f,0x3f22fffd,0x5ffb800f,
    0x7fffcc00,0x7fe4000f,0x0ffe202f,0xffb17fe2,0xffffffff,0x3fe67fff,
    0x0003ff43,0x00000000,0x00000000,0x20000000,0xfffffffc,0xffffffff,
    0x6c2ffd81,0x5ff301ff,0xf92ff7fc,0x1fff300f,0x5fff9000,0x7ffecc00,
    0x6fc80cff,0xfd8bfee0,0xffffffff,0x5513ffff,0x0002aa83,0x00000000,
    0x00000000,0x40000000,0xfffffffc,0xffffffff,0x225ffa81,0x3fe206ff,
    0x1ff5ff53,0xff1017f6,0xff10003f,0xfb300bff,0xffd5f99f,0x00bfe219,
    0x00000dfd,0x00000000,0x00000000,0x00000000,0x99880000,0x9eff9999,
    0x3a019999,0x07ff50ff,0x19f95ff8,0x013fa7ff,0x20007ffd,0x04ffeffd,
    0x7e47bfe2,0x3f6bff71,0x04ff9806,0x0ab98000,0x00000000,0x00000000,
    0x00000000,0xff880000,0x3ffb8005,0xfe801ffb,0x5bf63ff6,0x3ff203ff,
    0xbff90005,0x5c05fff1,0x1b117e43,0x00000000,0x27ffff44,0x00005990,
    0x00000000,0x00000000,0x44000000,0xf88005ff,0x805ff8ef,0x2a7faffc,
    0x502ff9ff,0x50001dff,0x3fea1fff,0x0bf6000f,0x00000000,0xffffffd0,
    0x007ff30b,0x00000000,0x00000000,0x00000000,0x8002ffc4,0x02ffcffd,
    0x24fdffb8,0x81ffdff8,0x8001fff8,0x7e42fff8,0x0ff6006f,0x00000000,
    0xea9dffa8,0x3fea0dff,0x00000002,0x00000000,0x00000000,0x17fe2000,
    0x7fffd400,0xffff5007,0x0ffffd83,0xaaadffe8,0xe82aaaaa,0xbffd04ff,
    0x00072e00,0xd8000000,0x3ffa20ff,0x007ffcbe,0x00000000,0x00000000,
    0x00000000,0x0002ffc4,0x2009ffff,0xfa87fff9,0xfff987ff,0xffffffff,
    0x1bff20ff,0x003fff98,0x00000000,0xd10dfd00,0x07ffffff,0x00000000,
    0x00000000,0x00000000,0x005ff880,0x003fff20,0xf827ffc4,0xfff986ff,
    0xffffffff,0x3fff70ff,0x01fffb80,0x00000000,0x202aa800,0x002ffffb,
    0x00000000,0x00000000,0x00000000,0x00000000,0x00000000,0x00000000,
    0x00000000,0x00260000,0x00000000,0x00000000,0x00000000,0x00000000,
    0x00000000,0x00000000,0x00000000,0x00000000,
};

static signed short stb__consolas_34_usascii_x[95]={ 0,7,4,0,1,0,0,7,4,4,2,1,3,4,
6,1,1,2,2,2,0,2,2,1,1,1,6,4,2,2,3,5,0,0,2,1,1,3,3,1,1,2,3,2,
3,0,1,0,2,0,2,1,1,1,0,0,0,0,1,5,2,4,2,0,0,2,2,2,1,1,0,1,2,2,
2,3,2,1,2,1,2,1,3,3,1,2,1,0,1,0,2,2,7,3,1, };
static signed short stb__consolas_34_usascii_y[95]={ 25,1,1,3,0,1,2,1,0,0,1,7,19,14,
19,1,3,3,3,3,3,3,3,3,3,3,8,8,6,11,6,1,1,3,3,3,3,3,3,3,3,3,3,3,
3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,0,1,0,3,29,1,8,1,8,1,8,1,8,1,1,
1,1,1,8,8,8,8,8,8,8,3,8,8,8,8,8,8,0,-3,0,12, };
static unsigned short stb__consolas_34_usascii_w[95]={ 0,5,11,18,16,19,19,5,11,10,14,17,9,11,
6,16,17,15,15,15,18,15,15,16,16,16,6,9,14,15,14,11,19,19,15,16,17,13,13,16,16,14,12,16,
14,18,16,18,15,19,16,16,17,16,19,18,19,19,16,9,15,9,15,19,12,14,15,14,15,16,18,17,15,15,
13,15,15,17,15,17,15,15,15,13,16,15,17,19,17,18,15,13,4,14,17, };
static unsigned short stb__consolas_34_usascii_h[95]={ 0,25,9,22,29,25,24,9,32,32,15,17,12,4,
7,28,23,22,22,23,22,23,23,22,23,22,18,23,20,10,20,25,31,22,22,23,22,22,22,23,22,22,23,22,
22,22,22,23,22,28,22,23,22,23,22,22,22,22,22,32,28,32,11,3,8,18,25,18,25,18,24,24,24,24,
31,24,24,17,17,18,24,24,17,18,23,18,17,17,17,24,17,32,35,32,8, };
static unsigned short stb__consolas_34_usascii_s[95]={ 252,182,235,200,112,220,1,250,21,47,188,
98,243,202,195,149,225,1,188,115,1,209,1,53,17,51,243,243,83,219,68,
240,92,235,219,34,182,168,154,98,120,105,68,70,36,34,17,190,20,129,137,
51,87,81,204,224,148,168,131,68,166,58,203,214,182,115,204,130,188,98,122,
104,88,72,78,37,21,225,209,145,157,141,193,163,173,177,116,134,170,53,154,
33,1,6,235, };
static unsigned short stb__consolas_34_usascii_t[95]={ 1,1,128,86,1,1,37,62,1,1,128,
128,109,27,27,1,37,86,62,62,109,37,62,86,62,109,62,37,109,128,109,
1,1,86,86,62,86,86,86,62,86,86,62,86,109,86,86,37,109,1,86,
62,86,62,62,62,62,62,62,1,1,1,128,27,27,109,1,109,1,109,37,
37,37,37,1,37,37,109,109,109,37,37,109,109,37,109,128,128,128,37,128,
1,1,1,138, };
static unsigned short stb__consolas_34_usascii_a[95]={ 299,299,299,299,299,299,299,299,
299,299,299,299,299,299,299,299,299,299,299,299,299,299,299,299,
299,299,299,299,299,299,299,299,299,299,299,299,299,299,299,299,
299,299,299,299,299,299,299,299,299,299,299,299,299,299,299,299,
299,299,299,299,299,299,299,299,299,299,299,299,299,299,299,299,
299,299,299,299,299,299,299,299,299,299,299,299,299,299,299,299,
299,299,299,299,299,299,299, };

// Call this function with
//    font: NULL or array length
//    data: NULL or specified size
//    height: STB_FONT_consolas_34_usascii_BITMAP_HEIGHT or STB_FONT_consolas_34_usascii_BITMAP_HEIGHT_POW2
//    return value: spacing between lines
static void stb_font_consolas_34_usascii(stb_fontchar font[STB_FONT_consolas_34_usascii_NUM_CHARS],
                unsigned char data[STB_FONT_consolas_34_usascii_BITMAP_HEIGHT][STB_FONT_consolas_34_usascii_BITMAP_WIDTH],
                int height)
{
    int i,j;
    if (data != 0) {
        unsigned int *bits = stb__consolas_34_usascii_pixels;
        unsigned int bitpack = *bits++, numbits = 32;
        for (i=0; i < STB_FONT_consolas_34_usascii_BITMAP_WIDTH*height; ++i)
            data[0][i] = 0;  // zero entire bitmap
        for (j=1; j < STB_FONT_consolas_34_usascii_BITMAP_HEIGHT-1; ++j) {
            for (i=1; i < STB_FONT_consolas_34_usascii_BITMAP_WIDTH-1; ++i) {
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
        float recip_width = 1.0f / STB_FONT_consolas_34_usascii_BITMAP_WIDTH;
        float recip_height = 1.0f / height;
        for (i=0; i < STB_FONT_consolas_34_usascii_NUM_CHARS; ++i) {
            // pad characters so they bilerp from empty space around each character
            font[i].s0 = (stb__consolas_34_usascii_s[i]) * recip_width;
            font[i].t0 = (stb__consolas_34_usascii_t[i]) * recip_height;
            font[i].s1 = (stb__consolas_34_usascii_s[i] + stb__consolas_34_usascii_w[i]) * recip_width;
            font[i].t1 = (stb__consolas_34_usascii_t[i] + stb__consolas_34_usascii_h[i]) * recip_height;
            font[i].x0 = stb__consolas_34_usascii_x[i];
            font[i].y0 = stb__consolas_34_usascii_y[i];
            font[i].x1 = stb__consolas_34_usascii_x[i] + stb__consolas_34_usascii_w[i];
            font[i].y1 = stb__consolas_34_usascii_y[i] + stb__consolas_34_usascii_h[i];
            font[i].advance_int = (stb__consolas_34_usascii_a[i]+8)>>4;
            font[i].s0f = (stb__consolas_34_usascii_s[i] - 0.5f) * recip_width;
            font[i].t0f = (stb__consolas_34_usascii_t[i] - 0.5f) * recip_height;
            font[i].s1f = (stb__consolas_34_usascii_s[i] + stb__consolas_34_usascii_w[i] + 0.5f) * recip_width;
            font[i].t1f = (stb__consolas_34_usascii_t[i] + stb__consolas_34_usascii_h[i] + 0.5f) * recip_height;
            font[i].x0f = stb__consolas_34_usascii_x[i] - 0.5f;
            font[i].y0f = stb__consolas_34_usascii_y[i] - 0.5f;
            font[i].x1f = stb__consolas_34_usascii_x[i] + stb__consolas_34_usascii_w[i] + 0.5f;
            font[i].y1f = stb__consolas_34_usascii_y[i] + stb__consolas_34_usascii_h[i] + 0.5f;
            font[i].advance = stb__consolas_34_usascii_a[i]/16.0f;
        }
    }
}

#ifndef STB_SOMEFONT_CREATE
#define STB_SOMEFONT_CREATE              stb_font_consolas_34_usascii
#define STB_SOMEFONT_BITMAP_WIDTH        STB_FONT_consolas_34_usascii_BITMAP_WIDTH
#define STB_SOMEFONT_BITMAP_HEIGHT       STB_FONT_consolas_34_usascii_BITMAP_HEIGHT
#define STB_SOMEFONT_BITMAP_HEIGHT_POW2  STB_FONT_consolas_34_usascii_BITMAP_HEIGHT_POW2
#define STB_SOMEFONT_FIRST_CHAR          STB_FONT_consolas_34_usascii_FIRST_CHAR
#define STB_SOMEFONT_NUM_CHARS           STB_FONT_consolas_34_usascii_NUM_CHARS
#define STB_SOMEFONT_LINE_SPACING        STB_FONT_consolas_34_usascii_LINE_SPACING
#endif

