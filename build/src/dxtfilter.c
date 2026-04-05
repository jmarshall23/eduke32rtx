#ifdef USE_OPENGL

/*
Description of Ken's filter to improve LZW compression of DXT1 format by ~15%: (as tested with the HRP)

 To increase LZW patterns, I store each field of the DXT block structure separately.
 Here are the 3 DXT fields:
 1.  __int64 alpha_4x4; //DXT3 only (16 byte structure size when included)
 2.  short rgb0, rgb1;
 3.  int32_t index_4x4;

 Each field is then stored with its own specialized algorithm.
 1. I haven't done much testing with this field - I just copy it raw without any transform for now.

 2. For rgb0 and rgb1, I use a "green" filter like this:
 g = g;
 r = r-g;
 b = b-g;
 For grayscale, this makes the stream: x,0,0,x,0,0,x,0,0,... instead of x,x,x,x,x,x,x,x,...
 Q:what was the significance of choosing green? A:largest/most dominant component
 Believe it or not, this gave 1% better compression :P
 I tried subtracting each componenet with the previous pixel, but strangely it hurt compression.
 Oh, the joy of trial & error. :)

 3. For index_4x4, I transform the ordering of 2-bit indices in the DXT blocks from this:
 0123 0123 0123  ---- ---- ----
 4567 4567 4567  ---- ---- ----
 89ab 89ab 89ab  ---- ---- ----
 cdef cdef cdef  ---- ---- ----
 To this: (I swap x & y axes)
 048c 048c 048c  |||| |||| ||||
 159d 159d 159d  |||| |||| ||||
 26ae 26ae 26ae  |||| |||| ||||
 37bf 37bf 37bf  |||| |||| ||||
 The trick is: going from the bottom of the 4th line to the top of the 5th line
 is the exact same jump (geometrically) as from 5th to 6th, etc.. This is not true in the top case.
 These silly tricks will increase patterns and therefore make LZW compress better.
 I think this improved compression by a few % :)
 */

#include "compat.h"
#include "build.h"
#include "texcache.h"
#include "lz4.h"

#ifndef EDUKE32_GLES
static uint16_t dxt_hicosub(uint16_t c)
{
    int32_t r, g, b;
    g = ((c>> 5)&63);
    r = ((c>>11)-(g>>1))&31;
    b = ((c>> 0)-(g>>1))&31;
    return ((r<<11)+(g<<5)+b);
}

static uint16_t dedxt_hicoadd(uint16_t c)
{
    int32_t r, g, b;
    g = ((c>> 5)&63);
    r = ((c>>11)+(g>>1))&31;
    b = ((c>> 0)+(g>>1))&31;
    return ((r<<11)+(g<<5)+b);
}
#endif

void dxt_handle_io(int32_t fil, int32_t len, void *midbuf, char *packbuf)
{
    void *writebuf;
    int32_t j, cleng;

    if (glusetexcache == 2)
    {
        cleng = LZ4_compress_limitedOutput((const char*)midbuf, packbuf, len, len);

        if (cleng <= 0 || cleng > len-1)
        {
            cleng = len;
            writebuf = midbuf;
        }
        else writebuf = packbuf;
    }
    else
    {
        cleng = len;
        writebuf = midbuf;
    }

    // native -> external (little endian)
    j = B_LITTLE32(cleng);
    Bwrite(fil, &j, sizeof(j));
    Bwrite(fil, writebuf, cleng);
}

int32_t dedxt_handle_io(int32_t fil, int32_t j /* TODO: better name */,
                               void *midbuf, int32_t mbufsiz, char *packbuf, int32_t ispacked)
{
    void *inbuf;
    int32_t cleng;

    if (texcache_readdata(&cleng, sizeof(int32_t)))
        return -1;

    // external (little endian) -> native
    cleng = B_LITTLE32(cleng);

    inbuf = (ispacked && cleng < j) ? packbuf : midbuf;

    if (texcache.memcache.ptr && texcache.memcache.size >= texcache.filepos + cleng)
    {
        if (ispacked && cleng < j)
        {
            if (LZ4_decompress_safe((const char *)texcache.memcache.ptr + texcache.filepos, (char*)midbuf, cleng, mbufsiz) <= 0)
            {
                texcache.filepos += cleng;
                return -1;
            }
        }
        else Bmemcpy(inbuf, texcache.memcache.ptr + texcache.filepos, cleng);

        texcache.filepos += cleng;
    }
    else
    {
        Blseek(fil, texcache.filepos, BSEEK_SET);
        texcache.filepos += cleng;

        if (Bread(fil, inbuf, cleng) < cleng)
            return -1;

        if (ispacked && cleng < j)
            if (LZ4_decompress_safe(packbuf, (char*)midbuf, cleng, mbufsiz) <= 0)
                return -1;
    }

    return 0;
}

#endif
