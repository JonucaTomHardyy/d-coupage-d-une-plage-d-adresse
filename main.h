typedef struct {
    unsigned long ip1;
    unsigned long ip2;
    unsigned long ip3;
    unsigned long ip4;
}Ip;

/* ptototype */

void start(char titre[], char css[]);

void end();

void decoder_chaine(char *chaine);

void cpy_ip(char *chaine, Ip *ip, Ip *net, int *nb_bits);

int vailde_ip(Ip *ip, Ip *net);

void binaire_struct(Ip *bit_ip);

void octet(unsigned long *bit);

int nb_decoupe(int nb_bits, Ip ip, Ip net);

void decoupe_plage(Ip ip, Ip net, int nb_bits, int color);