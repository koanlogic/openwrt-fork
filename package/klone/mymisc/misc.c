#include <time.h>
#include <klone/klone.h>
#include "misc.h"

/* misc functions called by dynamic .kl1 pages */
void print_date(io_t *out)
{
    time_t now;

    now = time(0);

    io_printf(out, "Time: %s", ctime(&now));

    return;
}

