/* Shad Aziz, Phillip Domann, Melanie Reed, Matt Walther
   masc0832
   Team Idaho
   prog3
   CS530, Spring 2016
*/

#ifndef SICXE_ASM_H
#define SICXE_ASM_H

#include <map>
#include "file_parser.h"
#include "opcodetab.h"
#include "symtab.h"

using namespace std;

class sicxe_asm {
    typedef void (sicxe_asm::*sym_handler)();
    
    struct symbol {
        bool isaddress;
        int value;
    };
    
    struct hpair {
        sym_handler pass1;
        sym_handler pass2;
    };
    
    struct dhpair {
        string directive;
        struct hpair handlers;
    };
    
    static const struct dhpair dhpairs[9];
    
    file_parser* parser;
    opcodetab optab;
    symtab symbols;
    map<string, struct sicxe_asm::hpair> hmap;
    vector<unsigned int> line_addrs;
    unsigned int index;
    unsigned int locctr;
    unsigned int base_addr;
    bool noBase;
    int nixbpe;
    string label;
    string opcode;
    string operand;
<<<<<<< HEAD
    string objCode;
    stringstream listing;
=======
    ofstream listing;
    int nixbpe;
    
   string format_1(string);
   string format_2(string, string);
   string get_reg_val(string);
   int str_toint(string);
   string int_tohex_tostr(int);


    
    struct dhpair {
        string directive;
        sym_handler handler;
    };
    
    static const struct dhpair dhpairs[9];
>>>>>>> 14ce097d950495ea044a4bcb6b64682b1e6d23b4
    
    // Retrives the line tokens from the file parser
    void get_tokens();
    // Setups the listing file with the program name and column headers
    void listing_head(string filename);
    // Writes a line to the listing file
    void listing_lnout();
    // Creates the map for looking up handlers for instructions and directives
    void setup_handler_map();
    // Retreives the symbol handler for the symbol
    sym_handler handler_for_symbol(bool pass);
    sym_handler pass1_handler();
    sym_handler pass2_handler();
    // Symbol handelers for instructions and directives
    void handle_instruction();
    void handle_start();
    void handle_end();
    void handle_byte();
    void handle_word();
    void handle_resb();
    void handle_resw();
    void handle_equ();
    void handle_base();
    void handle_nobase();
    void handle_empty();
    
    void format1_objcode();
    void format2_objcode();
    void format3_objcode();
    void format4_objcode();
    void byte_objcode();
    void word_objcode();
    void set_base_address();
    void set_nobase();
    void empty_objcode();
    
    // Adds the label address to the symbol table if it has one
    void add_symbol_for_label();
    // Throws an error string
    void error_str(string msg);
    // Throws an error string also printing the line contents
    void error_ln_str(string msg);
    
    struct symbol symtoval(string& symbol);
    bool islabel(string&);
    int hextoi(string str);
    bool isdecimal(string& str, size_t start, size_t end);
    int ctoi(string& str);
    bool isconstant(string& str);
    int getDisplacement( int addr1, int addr2 );
    string get_reg_val(string);
    int str_toint(string);
    string int_tohex_tostr(int);
    void format3();
    
    void format4();
    
    int getDisplacement( int, int );
    
public:
    // Sets up the handler map and listing file
    sicxe_asm(string file);
    ~sicxe_asm();
    
    // Assigns addresses to each line, adds labels and directives to the symbol
    // table
    void pass1();
    void pass2();
    
    void write_listing(string file);
    void print_listing(); // remove before submission
    
    void pass2();
    
};

#endif
