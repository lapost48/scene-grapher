#include "fileopener.h"


FileOpener::FileOpener()
{

}

void FileOpener::openFile(std::string filename)
{
    std::wstring temp;
    temp.resize(filename.length());
    std::copy(filename.begin(), filename.end(), temp.begin());
    ShellExecute(0, 0, temp.data(), 0, 0, SW_SHOW);
}
