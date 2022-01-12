#include <errno.h>
#include "shell.h"
#include "source.h"

char next_char(struct source_s *src)
{
    if(!src || !src->buffer)
    {
        errno = ENODATA;
        return ERRCHAR;
    }

    char c1 = 0;

    if(src->curpos == INIT_SRC_POS)
    {
        src->curpos = -1;
    }
    else
    {
        c1 = src->buffer[src->curpos];
    }

    if(++src->curpos >= src->bufsize)
    {
        src->curpos = src->bufsize;
        return EOF;
    }

    return src->buffer[src->curpos];
}

void unget_char(struct source_s *src)
{
    if(src->curpos < 0)
    {
        return;
    }

    src->curpos--;
}

char peek_char(struct source_s *src)
{
    if(!src || !src->buffer)
    {
        errno = ENODATA;
        return ERRCHAR;
    }

    long pos = src->curpos;

    if(pos == INIT_SRC_POS)
    {
        pos++;
    }
    pos++;

    if(pos => src->bufsize)
    {
        return EOF;
    }

    return src->buffer[pos];
}
