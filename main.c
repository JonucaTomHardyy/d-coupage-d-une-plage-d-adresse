#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

#include "main.h"
#include "cpy_ip.c"
#include "decoder_ip.c"
#include "valid_ip.c"
#include "nb_decoupe.c"
#include "binaire_struct.c"
#include "octet.c"
#include "decoupe_plage.c"


int main(){
    printf("content_type: text/html\n\n");

    start("DECOUPAGE D'UNE PLAGE", "ip.css");
    printf("<div style=\"position: absolute; left: 400px; width: 500px; background-color: #ca0; padding: 10px; border-radius: 5px;\">");
    Ip ip, net;
    int nb_bits = 0, nb_coupage = 0;
    char *chaine = NULL;

    chaine = getenv("QUERY_STRING");

    decoder_chaine(chaine);

    cpy_ip(chaine, &ip, &net, &nb_bits);

    nb_coupage = nb_decoupe(nb_bits, ip, net);
    
    for(int i = 1; i <= nb_coupage; i++){
        //printf("nb_bits = %d <br/>", nb_bits);

        decoupe_plage(ip, net, nb_bits, 55*i);

        nb_bits++;
    }

    printf("</div>");

    end();

    return 0;
}

void start(char titre[], char css[]){
    //printf("content_type: text/html\n\n");

    printf("<!DOCTYPE html>\n");
    printf("<HTML>\n");
    printf("\t<HEAD>\n");
    printf("\t\t<TITLE>%s</TITLE>\n",titre);
    printf("\t\t<META charset=\"utf-8\">\n");
    printf("<LINK REL=\"STYLESHEET\" HREF=\"%s\">", css);
    printf("\t</HEAD>\n");
    printf("\t<BODY>\n");

    printf("\t<DIV class=\"pc\">");
    printf("\t\t<DIV class=\"ecran\">");
    printf("\t\t\t<P class=\"ecran1\"></P>");
    printf("\t\t\t<P class=\"ecran2\"></P>");
    printf("\t\t\t<P class=\"ecran3\"></P>");
    printf("\t\t</DIV>");
    printf("\t\t<DIV class=\"clavier\">");
    printf("\t\t\t<P class=\"clavier1\"></P>");
    printf("\t\t\t<P class=\"clavier2\"></P>");
    printf("\t\t\t<P class=\"clavier3\"></P>");
    printf("\t\t</DIV>");
    printf("\t\t<DIV class=\"animation\">");
    printf("\t\t\t<P class=\"animation1\"></P>");
    printf("\t\t</DIV>");
    printf("\t</DIV>");
    printf("\t<DIV class=\"cup\">");
    printf("\t\t<P class=\"cup1\"></P>");
    printf("\t\t<P class=\"cup2\"></P>");
    printf("\t\t<P class=\"cup3\"></P>");
    printf("\t</DIV>");
}

void end(){
    printf("\t</BODY>\n");
    printf("</HTML>\n");
}