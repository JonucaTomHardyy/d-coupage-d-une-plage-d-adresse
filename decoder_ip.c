void decoder_chaine(char *chaine){
    int nb = strlen(chaine);

    for(int i = 0; i <= nb - 1; i++){
        if(chaine[i] == '%' && chaine[i+1] == '2' && chaine[i+2] == 'F'){
            chaine[i] = '/';
            chaine[i+1] = '/';
            chaine[i+2] = '/';
            //printf("%d_chaine: %s\n", i, chaine);
        }
    }
    //printf("\nchaine: %s<br/>", chaine);
}