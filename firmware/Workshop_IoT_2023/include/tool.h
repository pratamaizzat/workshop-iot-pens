#ifndef tool_h
#define tool_h

#include <WString.h>
#include <stdio.h>
#define VAR_BUFFER_SIZE (50)

class TOOL
{
public:
    /**
     * @brief funbsi untuk mengkonvert string ke char*
     *
     * @param mess data string message yang mau dikonvert
     * @param variable nama variable tempat menyimpan hasil konvert
     */
    void convert_string_to_char(String mess, char *variable);
};

#endif