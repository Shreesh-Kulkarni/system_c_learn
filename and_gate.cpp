#include <systemc.h>
SC_MODULE(and_gate){
    sc_in<sc_uint<2>> a;
    sc_in<sc_uint<2>> b;
    sc_out<sc_uint<2>> o;
    
    void func() {
        o.write(a.read() & b.read());
    }
    SC_CTOR(and_gate){
        SC_METHOD(func);
        sensitive << a << b;
    }

};
int sc_main(int argc, char* argv[]) {
    sc_signal<sc_uint<2>> a_sig, b_sig, o_sig;

    and_gate and1("and_gate_instance");
    and1.a(a_sig);
    and1.b(b_sig);
    and1.o(o_sig);

    sc_start(SC_ZERO_TIME);

    std::cout << "Time\tA\tB\tO" << std::endl;

    for (int i = 0; i < 4; ++i) {
        a_sig.write(i / 2);
        b_sig.write(i % 2);
        sc_start(1, SC_NS);
        std::cout << sc_time_stamp() << "\t" << a_sig.read() << "\t" << b_sig.read() << "\t" << o_sig.read() << std::endl;
    }

    return 0;
}




