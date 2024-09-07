void nb_bit(Ip netmask, Ip bit_net, int *nb_bits){
    int pw = 0, nb = 0;
    if(netmask.ip1 == 255 && netmask.ip2 == 255 && netmask.ip3 == 255 && netmask.ip4 == 255){
        *nb_bits = 0;
    }

    else if(netmask.ip1 != 255 && netmask.ip2 == 0 && netmask.ip3 == 0 && netmask.ip4 == 0){
        while(nb == 0){
            nb = bit_net.ip1 % (unsigned long) pow(10, pw);
            //printf("1_pw = %d\n", pw);
            //printf("nb = %d\n", nb);
            pw++;
            //printf("2_pw = %d\n", pw);
        }
        *nb_bits = pw - 2;
    }

    else if(netmask.ip2 != 255 && netmask.ip1 == 255 && netmask.ip3 == 0 && netmask.ip4 == 0){
        while(nb == 0){
            nb = bit_net.ip1 % (unsigned long) pow(10, pw);
            //printf("1_pw = %d\n", pw);
            //printf("nb = %d\n", nb);
            pw++;
            //printf("2_pw = %d\n", pw);
        }
        *nb_bits = pw - 2;
    }

    else if(netmask.ip3 != 255 && netmask.ip1 == 255 && netmask.ip2 == 255 && netmask.ip4 == 0){
        while(nb == 0){
            nb = bit_net.ip1 % (unsigned long) pow(10, pw);
            //printf("1_pw = %d\n", pw);
            //printf("nb = %d\n", nb);
            pw++;
            //printf("2_pw = %d\n", pw);
        }
        *nb_bits = pw - 2;
    }

    else if(netmask.ip4 != 255 && netmask.ip1 == 255 && netmask.ip2 == 255 && netmask.ip3 == 255){
        while(nb == 0){
            nb = bit_net.ip4 % (unsigned long) pow(10, pw);
            //printf("1_pw = %d\n", pw);
            //printf("nb = %d\n", nb);
            pw++;
            //printf("2_pw = %d\n", pw);
        }
        *nb_bits = pw - 2;
    }
}