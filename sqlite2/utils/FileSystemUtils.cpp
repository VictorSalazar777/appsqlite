//
//  FileSystemUtils.cpp
//  sqlite1
//
//  Created by manuel on 7/30/18.
//  Copyright © 2018 manuel. All rights reserved.
//

#include "FileSystemUtils.hpp"

// 201703: <filesystem> not supported
#if __cplusplus < 201703
#include <unistd.h>

string FileSystemUtils::getCurrentDirectory() {
    string pathName = getcwd(nullptr, 0);
    return pathName;
}

#else

#include <filesystem>
string FileSystemUtils::getCurrentDirectory() {
    return std::filesystem::currentpath() << endl;
}
#endif
