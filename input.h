//
// Created by peter on 06/02/19.
//

#ifndef JUNG_INPUTREDIRECTION_INPUT_H
#define JUNG_INPUTREDIRECTION_INPUT_H

#include <string>
#include <iostream>
#include <fstream>
#include <unistd.h>

#include <linux/limits.h>

namespace jung {
    std::string getPath(const std::string &path) {
        char buf[PATH_MAX + 1];

        if (readlink("/proc/self/exe", buf, sizeof(buf) - 1) == -1)
            throw std::string("readlink() failed");

        std::string str(buf);
        return str.substr(0, str.rfind('/')) + "/" + path;
    }

    std::string getPath() {
        return getPath("");
    }

    std::ifstream getIfStream(const std::string &file) {
        return std::ifstream (file);
    }
}


#endif //JUNG_INPUTREDIRECTION_INPUT_H
