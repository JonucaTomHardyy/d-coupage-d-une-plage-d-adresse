void binaire_struct(Ip *bit_ip){
    Ip cpy_bit_ip;
    int pw = 1, rtmp1 = 0, rtmp2 = 0, rtmp3 = 0, rtmp4 = 0, k = 0;

    cpy_bit_ip.ip1 = bit_ip->ip1;
    cpy_bit_ip.ip2 = bit_ip->ip2;
    cpy_bit_ip.ip3 = bit_ip->ip3;
    cpy_bit_ip.ip4 = bit_ip->ip4;

    //printf("\n\tcpy: %ld.%ld.%ld.%ld\n", cpy_bit_ip.ip1, cpy_bit_ip.ip2, cpy_bit_ip.ip3, cpy_bit_ip.ip4);
    //printf("\tbit: %ld.%ld.%ld.%ld\n", bit_ip->ip1, bit_ip->ip2, bit_ip->ip3, bit_ip->ip4);

    while(cpy_bit_ip.ip1 != 0 || cpy_bit_ip.ip2 != 0 || cpy_bit_ip.ip3 != 0 || cpy_bit_ip.ip4 != 0){

        rtmp1 = cpy_bit_ip.ip1%2;
        rtmp2 = cpy_bit_ip.ip2%2;
        rtmp3 = cpy_bit_ip.ip3%2;
        rtmp4 = cpy_bit_ip.ip4%2;
        //printf("rtmp: %d.%d.%d.%d\n", rtmp1, rtmp2, rtmp3, rtmp4);
        pw = 1;
        if(k != 0){
            pw = pow(10, k);
            //printf("pw= %d\n", pw);

            bit_ip->ip1 = bit_ip->ip1 + rtmp1 * pw;
            bit_ip->ip2 = bit_ip->ip2 + rtmp2 * pw;
            bit_ip->ip3 = bit_ip->ip3 + rtmp3 * pw;
            bit_ip->ip4 = bit_ip->ip4 + rtmp4 * pw;
        }
        else{
            bit_ip->ip1 = rtmp1;
            bit_ip->ip2 = rtmp2;
            bit_ip->ip3 = rtmp3;
            bit_ip->ip4 = rtmp4;
        }
        
        //printf("bit: %ld.%ld.%ld.%ld\n", bit_ip->ip1, bit_ip->ip2, bit_ip->ip3, bit_ip->ip4);
        k++;
        //printf("k= %d\n", k);

        cpy_bit_ip.ip1 = cpy_bit_ip.ip1/2;
        cpy_bit_ip.ip2 = cpy_bit_ip.ip2/2;
        cpy_bit_ip.ip3 = cpy_bit_ip.ip3/2;
        cpy_bit_ip.ip4 = cpy_bit_ip.ip4/2;
        //printf("\ncpy: %ld.%ld.%ld.%ld\n", cpy_bit_ip.ip1, cpy_bit_ip.ip2, cpy_bit_ip.ip3, cpy_bit_ip.ip4);
    }
        //printf("bit: %ld.%ld.%ld.%ld\n", bit_ip->ip1, bit_ip->ip2, bit_ip->ip3, bit_ip->ip4);
}