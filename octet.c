void octet(unsigned long *bit){
    unsigned long pw = 0, tmp = 0, nb = 0;
    tmp = *bit;
    *bit = 0;

    while(tmp != 0){
        nb = tmp % 10;
        *bit = *bit + nb * pow(2, pw);
        //printf("pw= %ld, nb= %ld, bit= %ld\n", pw, nb, *bit);
        pw++;
        tmp = tmp/10;
    }
}