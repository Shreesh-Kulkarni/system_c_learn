#include <systemc.h>
SC_MODULE(or_gate){
    sc_in<sc_uint<2>> a;
    sc_in<sc_uint<2>> b;
    sc_out<sc_uint<2>> c;

    void func(){
        c.write(a.read() | b.read());
    }

    SC_CTOR(or_gate){
        SC_METHOD(func);
        sensitive << a << b;
    }
};

int sc_main(int argc, char* argv[]){
    sc_signal<sc_uint<2>> a_sig,b_sig,c_sig;
    or_gate or1("or_gate_instance");
    or1.a(a_sig);
    or1.b(b_sig);
    or1.c(c_sig);    
    a_sig.write(1);
    b_sig.write(0);
    sc_start(SC_ZERO_TIME);
    std::cout << "A=" << a_sig.read() << " B=" << b_sig.read() << " O=" << c_sig.read() << std::endl;
    return 0;
}
