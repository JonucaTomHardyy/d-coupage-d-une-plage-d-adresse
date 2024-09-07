void decoupe_plage(Ip ip, Ip net, int nb_bits, int color){
    Ip R = ip, B = net;
    int nb = 0;

        if(0 <= nb_bits && nb_bits < 8){
            /* reseau */
                R.ip1 = 0;
                nb = nb_bits;
                for(int i = 1; i <= 8; i++){
                    if(i <= nb){
                        R.ip1 = R.ip1*10 + 1;
                    }
                    else{
                        R.ip1 = R.ip1*10;
                    }
                }
                octet(&R.ip1);
                
                R.ip2 = 0;
                R.ip3 = 0;
                R.ip4 = 0;

            /* broadcast */
                B.ip1 = R.ip1;
                B.ip2 = 255;
                B.ip3 = 255;
                B.ip4 = 255;
        }

        else if(8 <= nb_bits && nb_bits < 16){
            R.ip2 = 0;
            /* reseau */
                nb = nb_bits - 8;
                for(int i = 1; i <= 8; i++){
                    if(i <= nb){
                        R.ip2 = R.ip2*10 + 1;
                    }
                    else{
                        R.ip2 = R.ip2*10;
                    }
                }
                octet(&R.ip2);

                B.ip3 = 0;
                B.ip4 = 0;

            /* broadcast */
                B.ip1 = R.ip1;
                B.ip2 = R.ip2;
                B.ip3 = 255;
                B.ip4 = 255;
        }

        else if(16 <= nb_bits && nb_bits < 24){
            R.ip3 = 0;
            /* reseau */
                nb = nb_bits - 16;
                for(int i = 1; i <= 8; i++){
                    if(i <= nb){
                        R.ip3 = R.ip3*10 + 1;
                    }
                    else{
                        R.ip3 = R.ip3*10;
                    }
                }
                octet(&R.ip3);

                R.ip4 = 0;


            /* broadcast */

                B.ip1 = R.ip1;
                B.ip2 = R.ip2;
                B.ip3 = R.ip3;
                B.ip4 = 255;
        }

        else if(24 <= nb_bits && nb_bits < 32){
            R.ip4 = 0;
            /* reseau */
                nb = nb_bits - 24;
                for(int i = 1; i <= 8; i++){
                    if(i <= nb){
                        R.ip4 = R.ip4*10 + 1;
                    }
                    else{
                        R.ip4 = R.ip4*10;
                    }
                }
                octet(&R.ip4);


            /* broadcast */

                B.ip1 = R.ip1;
                B.ip2 = R.ip2;
                B.ip3 = R.ip3;
                B.ip4 = 255;
        }

        printf("<div style=\"padding: 3px; background-color: rgba(%d, 0, 0, 0.7); border-radius: 5px; width: 400px; margin: 10px;\">", color);
        printf("<p>Adresse réseau : %ld.%ld.%ld.%ld</p>", R.ip1, R.ip2, R.ip3, R.ip4);
        printf("<p>Adresse de broadcast : %ld.%ld.%ld.%ld</p>", B.ip1, B.ip2, B.ip3, B.ip4);
        printf("</div>");

}