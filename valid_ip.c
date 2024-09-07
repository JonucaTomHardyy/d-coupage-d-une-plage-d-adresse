int vailde_ip(Ip *ip, Ip *net){
    //printf("validation ip/net : %ld.%ld.%ld.%ld/%ld.%ld.%ld.%ld\n", ip->ip1, ip->ip2, ip->ip3, ip->ip4, net->ip1, net->ip2, net->ip3, net->ip4);

    if(0 <= ip->ip1 && ip->ip1 <= 255       &&       0 <= net->ip1 && net->ip1 <= 255 && 
       0 <= ip->ip2 && ip->ip2 <= 255       &&       0 <= net->ip2 && net->ip2 <= 255 && 
       0 <= ip->ip3 && ip->ip3 <= 255       &&       0 <= net->ip3 && net->ip3 <= 255 && 
       0 <= ip->ip4 && ip->ip4 <= 255       &&       0 <= net->ip4 && net->ip4 <= 255
    ){
        //printf("<p>ip valide</p><br/>");
        
        if(net->ip1 <= 255 && net->ip2 <= 255 && net->ip3 <= 255){
            for(int i = 0; i <= 8; i++){
                if(net->ip4 == (254 + 2*i)){
                    printf("<p>ip et nemask valide</p><br/>");
                    break;
                }
            }
        }

        else if(net->ip1 <= 255 && net->ip2 <= 255 && net->ip4 <= 255){
            for(int i = 0; i <= 8; i++){
                if(net->ip3 == (254 + 2*i)){
                    printf("<p>ip et nemask valide</p><br/>");
                    break;
                }
            }
        }

        else if(net->ip1 <= 255 && net->ip3 <= 255 && net->ip4 <= 255){
            for(int i = 0; i <= 8; i++){
                if(net->ip2 == (254 + 2*i)){
                    printf("<p>ip et nemask valide</p><br/>");
                    break;
                }
            }
        }

        else if(net->ip2 <= 255 && net->ip3 <= 255 && net->ip4 <= 255){
            for(int i = 0; i <= 8; i++){
                if(net->ip1 == (254 + 2*i)){
                    printf("<p>ip et nemask valide</p><br/>");
                    break;
                }
            }
        }

         else{
            printf("<p>net non valide</p><br/>");
            printf("<a href=\"ip->html\"></a>");
        }
    }
    else{
        printf("<p>ip ou net non valide</p><br/>");
        printf("<a href=\"ip->html\">réentrer une nouvelle net</a><br/>");
    }
}
