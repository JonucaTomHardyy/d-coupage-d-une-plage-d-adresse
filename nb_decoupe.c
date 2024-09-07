int nb_decoupe(int nb_bits, Ip ip, Ip net){
    Ip *R = NULL, *B = NULL;
    int tmp = nb_bits, nb = nb_bits;

    if(0 < nb_bits && nb_bits <= 8){
        tmp = nb_bits - 0*8;
        printf("<p style=\"padding: 3px; background-color: rgba(150, 0, 0, 0.2); border-radius: 5px; width: 400px; margin: 10px;\">l'adresee ip a été coupé %d fois</p><br/>", tmp);

    }
    if(8 < nb_bits && nb_bits <= 16){
        tmp = nb_bits - 1*8;
        printf("<p style=\"padding: 3px; background-color: rgba(150, 0, 0, 0.2); border-radius: 5px; width: 400px; margin: 10px;\">l'adresee ip a été coupé %d fois</p><br/>", tmp);

    }
    if(16 < nb_bits && nb_bits <= 24){
        tmp = nb_bits - 2*8;
        printf("<p style=\"padding: 3px; background-color: rgba(150, 0, 0, 0.2); border-radius: 5px; width: 400px; margin: 10px;\">l'adresee ip a été coupé %d fois</p><br/>", tmp);

    }
    if(24 < nb_bits && nb_bits <= 32){
        tmp = nb_bits - 3*8;
        printf("<p style=\"padding: 3px; background-color: rgba(150, 0, 0, 0.2); border-radius: 5px; width: 400px; margin: 10px;\">l'adresee ip a été coupé %d fois</p><br/>", tmp);
    }

    //binaire_struct(&ip);
    //binaire_struct(&net);
    //printf("<p>%ld.%ld.%ld.%ld</p>", ip.ip1, ip.ip2, ip.ip3, ip.ip4);
    //printf("<p>%ld.%ld.%ld.%ld</p>", net.ip1, net.ip2, net.ip3, net.ip4);

/* allocation dynamique */
    R = malloc(tmp*sizeof(Ip));
    B = malloc(tmp*sizeof(Ip));

    return tmp;
}