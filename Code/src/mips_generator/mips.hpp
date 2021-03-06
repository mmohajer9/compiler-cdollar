#ifndef MIPS_H
#define MIPS_H

#include <stdio.h>
#include <iostream>
#include <string>
#include <fstream>

using namespace std;

class MIPSCodeGenerator
{

public:

    ofstream *fp;

    MIPSCodeGenerator()
    {
        fp = NULL;
    }
    ~MIPSCodeGenerator()
    {
        (*fp).close();
    }
	MIPSCodeGenerator(ofstream *fp)
	{
        this->fp = fp;
	}

    //* initialize
    void init(ofstream *fp)
    {
        this->fp = fp;
        *(this->fp) << ".data" << endl << "backn: .asciiz \"\\n\"" << endl << ".text" << endl << ".globl main\n" << endl;
    }


    //* arithmetics
    void add(string dst_reg , string left_src_reg , string right_src_reg);
    void sub(string dst_reg , string left_src_reg , string right_src_reg);
    void addi(string dst_reg , string left_src_reg , int immediate);
    void mul(string dst_reg , string left_src_reg , string right_src_reg);
    void div(string left_src_reg , string right_src_reg);
    void divQ(string dst_reg);
    void divR(string dst_reg);

    //* logical
    void _and(string dst_reg , string left_src_reg , string right_src_reg);
    void _or(string dst_reg , string left_src_reg , string right_src_reg);
    void _xor(string dst_reg , string left_src_reg , string right_src_reg);
    void andi(string dst_reg , string left_src_reg , int immediate);
    void ori(string dst_reg , string left_src_reg , int immediate);

    void neg(string dst_reg , string src_reg);

    //* data transfer
    void lw(string dst_reg , string src_base_reg , int offset);
    void sw(string src_base_reg , string dst_reg , int offset);
    void la(string dst_reg , string label);
    void li(string dst_reg , int immediate);
    void move(string dst_reg , string src_reg);

    //* branch
    void beq(string left_reg , string right_reg , string label);
    void bne(string left_reg , string right_reg , string label);
    void bgt(string left_reg , string right_reg , string label);
    void bge(string left_reg , string right_reg , string label);
    void blt(string left_reg , string right_reg , string label);
    void ble(string left_reg , string right_reg , string label);

    //* comparison
    void slt(string dst_reg , string left_src_reg , string right_src_reg);
    void slti(string dst_reg , string left_src_reg , int immediate);

    void sle(string dst_reg , string left_src_reg , string right_src_reg);
    void seq(string dst_reg , string left_src_reg , string right_src_reg);
    void sne(string dst_reg , string left_src_reg , string right_src_reg);
    void sgt(string dst_reg , string left_src_reg , string right_src_reg);
    void sge(string dst_reg , string left_src_reg , string right_src_reg);

    //* unconditional jump
    void j(int address);
    void j(string label);

    void jr(string reg);

    void jal(int address);
    void jal(string label);

    //* utility
    void add_label(string label);



};


#endif