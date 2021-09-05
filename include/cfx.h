#pragma once
#include <math.h>
#include <string>
#include <color.h>
#include <vector>
#include <iostream>
#define c_white &dye::white
#define c_info &dye::light_yellow
#define c_err &dye::red
#define c_blue &dye::blue
#define cb_blue &dye::on_blue
#define cb_info &dye::on_light_yellow
#define cb_dark_grey &dye::white_on_grey
#define cb_err &dye::on_red
#define underline "\033[4m"
#define blink "\033[5m"
#define italicize "\033[3m"
#define reset "\033[0m"
#define memorize "\033[7"
#define goto "\033[8"
#define bell "\a"

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
    void gotoxy(int x,int y)    
    {
        printf("%c[%d;%df",0x1B,y,x);
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
            void show(dye::R<std::string> (*f)(std::string), int hpadding = 2) {
                std::cout << f(std::string(max_len+(hpadding*4), ' ')) << "\n";
                for(std::string line: lines) {
                    std::cout << f(std::string(hpadding*2, ' ') + line + std::string(max_len - line.length() + (hpadding*2), ' '));
                    std::cout << "\n";
                }
                std::cout << f(std::string(max_len+(hpadding*4), ' '));
            }
    };
    class info_sec {
        private:
            int max_len = 0;
            std::vector<std::string> lines;
        public:
            info_sec() {};
            void body(std::string body) {
                if(max_len < body.length()) {
                    max_len = body.length();
                }
                lines.push_back(body);
            }
            void show(std::string title, dye::R<std::string> (*f)(std::string)) {
                std::cout << f("+" + std::string(max_len+2, '-') + "+\n");
                std::cout << f("|");
                stylify(' ' + title + std::string(max_len - title.length() + 1, ' '));
                std::cout << f("|\n");
                std::cout << f("+-" + std::string(max_len, '-') + "-+");
                std::cout << "\n";
                for(std::string line: lines) {
                    std::cout << f("|");
                    stylify(' ' + line + std::string(max_len - line.length() + 1, ' '));
                    std::cout << f("|\n");
                }
                std::cout << f("+-" + std::string(max_len, '-') + "-+\n");
            }
    };
    class info_box {
        private:
            int max_len = 0;
            std::vector<std::string> lines;
        public:
            void body(std::string body) {
                if(max_len < body.length()) {
                    max_len = body.length();
                }
                lines.push_back(body);
            }
            void show(std::string title, dye::R<std::string> (*f)(std::string), int hpadding = 2) {
                std::cout << f(std::string(max_len+(hpadding*4), ' ')) << "\n";
                std::cout << f(std::string(hpadding*2, ' ') + title + std::string(max_len - title.length() + (hpadding*2), ' '));
                std::cout << "\n";
                std::cout << f(std::string(max_len+(hpadding*4), ' ') + "\n");
                for(std::string line: lines) {
                    std::cout << line;
                    std::cout << "\n";
                }
            }
    };
    class input {
        public:
            input() {};
            std::string get(std::string m, std::string sep = "|>") {
                std::string in;
                std::cout << m << blink << " "+sep+" " << reset;
                std::getline(std::cin, in);
                return in;
            }
    };
    class list {
        private:
            std::vector<std::string> selection_list;
            std::string s_selected_index;
            int selected_index;
        public:
            list(std::vector<std::string> l) {
                selection_list = l;
            };
            int show(std::string message, std::string seporator = "|>") {
                for(std::string item: selection_list) {
                    std::cout << item << "\n";
                }
                std::cout << message << blink << " " << seporator << " " << reset;
                std::getline(std::cin, s_selected_index);
                try {
                    selected_index = std::stoi(s_selected_index);
                } catch(std::invalid_argument) {
                    return -1;
                }
                if(selected_index > selection_list.size()) {
                    return -1;
                }
                if(selected_index < 1) {
                    return -1;
                }
                return selected_index-1;
            }
    };
}