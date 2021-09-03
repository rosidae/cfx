#pragma once
#include <math.h>
#include <string>
#include <color.h>
#include <vector>
#include <iostream>
#define c_white &dye::white
#define c_info &dye::light_yellow
#define c_err &dye::red
#define cb_info &dye::on_light_yellow
#define cb_dark_grey &dye::white_on_grey
#define cb_err &dye::on_red

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
    class sec {
        private:
            int max_len = 0;
            std::vector<std::string> lines;
        public:
            sec() {}
            void body(std::string body) {
                if(max_len < body.length()) {
                    max_len = body.length();
                }
                lines.push_back(body);
            }
            void show(std::string title, dye::R<std::string> (*f)(std::string)) {
                std::cout << f("+- " + title + " " + std::string(max_len-title.length()-1, '-') + "+\n");
                for(std::string line: lines) {
                    std::cout << f("|");
                    stylify(' ' + line + std::string(max_len - line.length() + 1, ' '));
                    std::cout << f("|\n");
                }
                std::cout << f("+-" + std::string(max_len, '-') + "-+\n");
            }
    };
    class box {
        private:
            int max_len = 0;
            std::vector<std::string> lines;
        public:
            box() {}
            void body(std::string body) {
                if(max_len < body.length()) {
                    max_len = body.length();
                }
                lines.push_back(body);
            }
            void show(dye::R<std::string> (*f)(std::string)) {
                std::cout << f(std::string(max_len+4, ' ')) << "\n";
                for(std::string line: lines) {
                    std::cout << f("  " + line + std::string(max_len - line.length() + 2, ' '));
                    std::cout << "\n";
                }
                std::cout << f(std::string(max_len+4, ' '));
            }
    };
}