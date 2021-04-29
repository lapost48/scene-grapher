#ifndef FILEOPENER_H
#define FILEOPENER_H

#include <shlwapi.h>
#include <string>

class FileOpener
{
public:
    FileOpener();
    void openFile(std::string filename);
};

#endif // FILEOPENER_H
