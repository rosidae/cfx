#pragma once
#include <math.h>
#include <string>
#include <color.h>
#include <iostream>
#define sc_white &dye::white
#define sc_info &dye::light_yellow
#define sc_err &dye::red

namespace cfx {
    // omg i hate this huge switch case statement but idk any other way to to it
    void stylify(std::string T) {
        for(size_t I = 0; I < T.size(); I++) {
            char F = T[I];
            switch(F) {
                case '0':
                    std::cout << dye::light_yellow(F);
                    break;
                case '1':
                    std::cout << dye::light_yellow(F);
                    break;
                case '2':
                    std::cout << dye::light_yellow(F);
                    break;
                case '3':
                    std::cout << dye::light_yellow(F);
                    break;
                case '4':
                    std::cout << dye::light_yellow(F);
                    break;
                case '5':
                    std::cout << dye::light_yellow(F);
                    break;
                case '6':
                    std::cout << dye::light_yellow(F);
                    break;
                case '7':
                    std::cout << dye::light_yellow(F);
                    break;
                case '8':
                    std::cout << dye::light_yellow(F);
                    break;
                case '9':
                    std::cout << dye::light_yellow(F);
                    break;
                case '-':
                    std::cout << dye::light_yellow(F);
                    break;
                case '|':
                    std::cout << dye::light_yellow(F);
                    break;
                case '[':
                    std::cout << dye::blue(F);
                    break;
                case ']':
                    std::cout << dye::blue(F);
                    break;
                case '(':
                    std::cout << dye::blue(F);
                    break;
                case ')':
                    std::cout << dye::blue(F);
                    break;
                case '{':
                    std::cout << dye::blue(F);
                    break;
                case '}':
                    std::cout << dye::blue(F);
                    break;
                case '"':
                    std::cout << dye::blue(F);
                    break;
                case '\'':
                    std::cout << dye::blue(F);
                    break;
                default:
                    std::cout << F;
                    break;
            }
        }
    }
    void sec(std::string body, std::string title, dye::R<std::string> (*f)(std::string)) {
        std::cout << f("+- " + title + " " + std::string(body.length()-title.length()-1, '-') + "+\n");
        std::cout << f("|");
        stylify(" " + body + " ");
        std::cout << f("|\n");
        std::cout << f("+-" + std::string(body.length(), '-') + "-+\n");
    }
    class area
}
