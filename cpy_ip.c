void cpy_ip(char *chaine, Ip *ip, Ip *net, int *nb_bits){
    int nb = 0;
    char add1[4], ne1[4],
         add2[4], ne2[4],
         add3[4], ne3[4],
         add4[4], ne4[4];

    nb = sscanf(chaine, "ip///netmask=%[^.].%[^.].%[^.].%[^///]///%[^.].%[^.].%[^.].%s",
                add1, add2, add3, add4, ne1, ne2, ne3, ne4);

    ip->ip1 = atoi(add1);
    net->ip1 = atoi(ne1);
    ip->ip2 = atoi(add2);
    net->ip2 = atoi(ne2);
    ip->ip3 = atoi(add3);
    net->ip3 = atoi(ne3);
    ip->ip4 = atoi(add4);
    net->ip4 = atoi(ne4);

    if(nb == 8){
        vailde_ip(ip, net);
    }
    else if(nb == 5){
        vailde_ip(ip, net);
        *nb_bits = net->ip1;
        //printf("nb_bits= %d<br/>", *nb_bits);


        if(0 < *nb_bits && *nb_bits <= 8){
            net->ip1 = 0;
            nb = *nb_bits;
            for(int i = 1; i <= 8; i++){
                if(i <= nb){
                    net->ip1 = net->ip1*10 + 1;
                }
                else{
                    net->ip1 = net->ip1*10;
                }
            }
            octet(&net->ip1);

            net->ip2 = 0;
            net->ip3 = 0;
            net->ip4 = 0;
        }

        else if(8 < *nb_bits && *nb_bits <= 16){
            net->ip1 = 255;

            nb = *nb_bits - 8;
            for(int i = 1; i <= 8; i++){
                if(i <= nb){
                    net->ip2 = net->ip2*10 + 1;
                }
                else{
                    net->ip2 = net->ip2*10;
                }
            }
            octet(&net->ip2);

            net->ip3 = 0;
            net->ip4 = 0;
        }

        else if(16 < *nb_bits && *nb_bits <= 24){
            net->ip1 = 255;
            net->ip2 = 255;

            nb = *nb_bits - 16;
            for(int i = 1; i <= 8; i++){
                if(i <= nb){
                    net->ip3 = net->ip3*10 + 1;
                }
                else{
                    net->ip3 = net->ip3*10;
                }
            }
            octet(&net->ip3);

            net->ip4 = 0;
        }

        else if(24 < *nb_bits && *nb_bits <= 32){
            net->ip1 = 255;
            net->ip2 = 255;
            net->ip3 = 255;

            nb = *nb_bits - 24;
            for(int i = 1; i <= 8; i++){
                if(i <= nb){
                    net->ip4 = net->ip4*10 + 1;
                }
                else{
                    net->ip4 = net->ip4*10;
                }
            }
            octet(&net->ip4);
        }
    }
    
    else{
        printf("<p>il y a une erreur lors de la copy</p>");
        printf("<a href=\"ip.html\">entrer un autre adresse ip</a>");
    }
    printf("ip / netmask = %ld.%ld.%ld.%ld/%ld.%ld.%ld.%ld<br/>", ip->ip1, ip->ip2, ip->ip3, ip->ip4, net->ip1, net->ip2, net->ip3, net->ip4);
}