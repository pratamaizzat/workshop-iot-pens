#include "../include/tool.h"

void TOOL::convert_string_to_char(String mess, char *variable)
{
    static char dt[VAR_BUFFER_SIZE];
    mess.toCharArray(dt, (mess.length() + 1));
    snprintf(variable, VAR_BUFFER_SIZE, "%s", dt);
}
