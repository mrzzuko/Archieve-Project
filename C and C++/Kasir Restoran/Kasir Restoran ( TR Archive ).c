#include <stdio.h>
#include <conio.h>
#include <windows.h>
#include <time.h>


void gotoxy(int x,int y) {
    COORD coord;
    coord.X = x;
    coord.Y = y;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
}

int main() {
    int menu,menu2,banyak,nmenu,jumlah,ketik=0,ketik2=0,dibayar=0,total,kembalian=0,n=0,c=0,i,x,y,j,p=0,s=0,jpembeli=0,pilihan,pilihan2,menu_resto,sensor,v=0,discounti=0,jmember=0,ulang,vmember=0,m=0;
    float discount;
    char huruf,pembeli[32][32],user[12],pw[12],hurufa[100],dc;
    char nmember[32][32][32][32];
    char garis[46]={"=========================================="};
    int npembeli[32][14][2]={{0},{0},{0},{0},{0},{0},{0},{0},{0},{0},{0},{0}};
    time_t t;
    time(&t);
    system ("color f0");

    //LOGIN//
    login:
        menu=0;
        system("cls");
        gotoxy(60,3);
        printf("==========================================");
        gotoxy(72,5);
        printf("HALAMAN LOGIN KASIR");
        gotoxy(60,7);
        printf("==========================================");
        gotoxy(65,9);
        printf("Username :");
        gotoxy(65,10);
        printf("Password :");
        gotoxy(75,9);
        scanf("%[^\n]s",&user);
        gotoxy(75,10);
        for (i = 0; i < 32; i++) {
            pw[i] = getch();
            if(pw[i]==13 && i>0){
                i=32;
            }
            else if(pw[i]==13){
                i=-1;
                printf("");
            }else{
                printf("*");
            }
        }

        //MENU UTAMA//
        do {
            system("cls");
            gotoxy(60,3);
            printf("==========================================");
            gotoxy(69,5);
            printf("SELAMAT DATANG DI GUSTEAU");
            gotoxy(60,7);
            printf("==========================================");
            if(menu==1) {
                gotoxy(65,9);
                printf(">>MENU RESTO");
            }else {
                gotoxy(65,9);
                printf("MENU RESTO");
            }
            if(menu==2) {
                gotoxy(65,10);
                printf(">>LIST NAMA PEMBELI");
            }else {
                gotoxy(65,10);
                printf("LIST NAMA PEMBELI");
            }
            if(menu==3) {
                gotoxy(65,11);
                printf(">>DATA PEMBELI");
            }else {
                gotoxy(65,11);
                printf("DATA PEMBELI");
            }
            if(menu==4) {
                gotoxy(65,12);
                printf(">>PEMBAYARAN");
            }else {
                gotoxy(65,12);
                printf("PEMBAYARAN");
            }
            if(menu==5) {
                gotoxy(65,13);
                printf(">>MEMBERSHIP");
            }else {
                gotoxy(65,13);
                printf("MEMBERSHIP");
            }
            if(menu==6) {
                gotoxy(65,14);
                printf(">>CLEAR DATA");
            }else {
                gotoxy(65,14);
                printf("CLEAR DATA");
            }
            if(menu==7) {
                gotoxy(65,15);
                printf(">>LOGOUT");
            }else {
                gotoxy(65,15);
                printf("LOGOUT");
            }
            if(menu==8) {
                gotoxy(65,16);
                printf(">>KATA KATA MUTIARA");
            }else {
                gotoxy(65,16);
                printf("KATA KATA MUTIARA");
            }
            if(menu==9) {
                gotoxy(65,17);
                printf(">>KELUAR");
            }else {
                gotoxy(65,17);
                printf("KELUAR");
            }
            gotoxy(60,19);
            printf("==========================================");
            pilihan=getch();
            if(pilihan==80){
                menu++;
                if(menu>9)
                menu=1;
            }
            if(pilihan==72){
                menu--;
                if(menu<1)
                menu=9;
            }
            //SEMUA MENU//
            do {
                //MENU RESTO//
                if(menu==1 && pilihan==13) {
                    pilihan=0;
                    ketik2=0;
                    menu=0;
                    v=0;
                    system("cls");
                    system ("color f0");
                    gotoxy(58,3);
                    printf("===================================================");
                    gotoxy(79,5);
                    printf("MENU RESTO");
                    gotoxy(68,6);
                    printf("KETIK 0 UNTUK MENGAKHIRI PESANAN");
                    gotoxy(58,8);
                    printf("===================================================");
                    gotoxy(60,10);
                    printf("BEST SELLER");
                    gotoxy(62,11);
                    printf("1. NASI GORENG KAVIAR............Rp. 1.000.000");
                    gotoxy(62,12);
                    printf("2. WAGYU PENYET..................Rp. 500.000");
                    gotoxy(62,13);
                    printf("3. GEPREK TUNA SIRIP BIRU........Rp. 350.000");
                    gotoxy(60,15);
                    printf("MAKANAN");
                    gotoxy(62,16);
                    printf("4. RENDANG BAKAR.................Rp. 70.000");
                    gotoxy(62,17);
                    printf("5. AYAM CERMANI..................Rp. 45.000");
                    gotoxy(62,18);
                    printf("6. SOTO DAGING WAGYU.............Rp. 100.000");
                    gotoxy(62,19);
                    printf("7. SUSHI JAWA....................Rp. 65.000");
                    gotoxy(62,20);
                    printf("8. TOMAHAWK......................Rp. 80.000");
                    gotoxy(60,22);
                    printf("MINUMAN");
                    gotoxy(62,23);
                    printf("9.  DAWET IRENG..................Rp. 25.000");
                    gotoxy(62,24);
                    printf("10. LYCHEE TEA...................Rp. 10.000");
                    gotoxy(62,25);
                    printf("11. CIU CANGKOL..................Rp. 60.000");
                    gotoxy(62,26);
                    printf("12. ICELAND......................Rp. 100.000");
                    gotoxy(58,28);
                    printf("===================================================");
                    y=31;
                    c=0;
                    do{
                        vmember=-1;
                        gotoxy(63,y-1);
                        printf("KETIK 1 UNTUK NON-MEMBER,2 UNTUK MEMBER");
                        gotoxy(63,y);
                        printf("KETIK :");
                        scanf("%i",&vmember);
                        scanf("%c",&huruf);
                        if(vmember>2 || vmember<0){
                            gotoxy(63,y);
                            printf("MEMBER/NON-MEMBER :INVALID");
                            sleep(1);
                            gotoxy(63,y);
                            printf("MEMBER/NON-MEMBER :       ");
                        }
                    }while(vmember>2 || vmember<0);
                    gotoxy(63,y-1);
                    printf("                                           ");
                    gotoxy(63,y);
                    printf("                                           ");


                    if(vmember==2){
                        do{
                            m=-1;
                            gotoxy(71,y);
                            printf("NOMER MEMBER :");
                            scanf("%i",&m);
                            scanf("%c",&huruf);
                            if(strcmp(nmember[m], "") == 0 && m>0 || m<0){
                                gotoxy(71,y);
                                printf("NOMER MEMBER :DATA TIDAK ADA");
                                sleep(1);
                                gotoxy(71,y);
                                printf("NOMER MEMBER :              ");
                            }
                        }while(strcmp(nmember[m], "") == 0 && m>0 || m<0);
                        if(m>0){
                            jpembeli++;
                            do {
                                y=y+2;
                                do{
                                    nmenu=-1;
                                    gotoxy(71,y);
                                    printf("NOMER MENU :");
                                    scanf("%i",&nmenu);
                                    scanf("%c",&huruf);
                                    if(nmenu>12 || nmenu<0) {
                                        gotoxy(71,y);
                                        printf("NOMER MENU :INVALID");
                                        sleep(1);
                                        gotoxy(71,y);
                                        printf("NOMER MENU :        ");
                                    }
                                }while(nmenu>12 || nmenu<0);
                                y=y+1;
                                if (nmenu>0) {
                                    do {
                                        jumlah=0;
                                        gotoxy(71,y);
                                        printf("JUMLAH     :");
                                        scanf("%i",&jumlah);
                                        scanf("%c",&huruf);
                                        if(jumlah<=0) {
                                            gotoxy(71,y);
                                            printf("JUMLAH     :INVALID");
                                            sleep(1);
                                            gotoxy(71,y);
                                            printf("JUMLAH     :            ");
                                        }
                                        npembeli[jpembeli][nmenu][0]=jumlah;
                                        npembeli[jpembeli][13][1]=1;
                                        strcpy(pembeli[jpembeli],nmember[m]);
                                    }while (jumlah<=0);
                                }
                            }while(nmenu>0);
                        }
                    }


                    if(vmember==1){
                        do {
                            banyak=-1;
                            gotoxy(71,y+1);
                            printf("BERAPA BANYAK PEMBELI :");
                            scanf("%i",&banyak);
                            scanf("%c",&huruf);
                            if(banyak<=-1) {
                                gotoxy(71,y+1);
                                printf("BERAPA BANYAK PEMBELI :INVALID");
                                sleep(1);
                                gotoxy(71,y+1);
                                printf("BERAPA BANYAK PEMBELI :         ");
                            }
                        }while(banyak<=-1);
                        if(banyak>0) {
                            do{
                                y=y+2;
                                nmenu=0;
                                jpembeli++;
                                do{
                                    gotoxy(71,y);
                                    printf("NAMA PEMBELI :");
                                    scanf(" %[^\n]s",&pembeli[jpembeli]);
                                    if(strcmp(pembeli[jpembeli], "A") < 0){
                                        gotoxy(71,y);
                                        printf("NAMA PEMBELI :INVALID");
                                        sleep(1);
                                        gotoxy(71,y);
                                        printf("NAMA PEMBELI :       ");
                                    }
                                }while(strcmp(pembeli[jpembeli], "A") < 0);
                                do {
                                    y=y+2;
                                    do{
                                        nmenu=-1;
                                        gotoxy(71,y);
                                        printf("NOMER MENU :");
                                        scanf("%i",&nmenu);
                                        scanf("%c",&huruf);
                                        if(nmenu>12 || nmenu<0) {
                                            gotoxy(71,y);
                                            printf("NOMER MENU :INVALID");
                                            sleep(1);
                                            gotoxy(71,y);
                                            printf("NOMER MENU :        ");
                                        }
                                    }while(nmenu>12 || nmenu<0);
                                    y=y+1;
                                    if (nmenu>0) {
                                        do {
                                            jumlah=0;
                                            gotoxy(71,y);
                                            printf("JUMLAH     :");
                                            scanf("%i",&jumlah);
                                            scanf("%c",&huruf);
                                            if(jumlah<=0) {
                                                gotoxy(71,y);
                                                printf("JUMLAH     :INVALID");
                                                sleep(1);
                                                gotoxy(71,y);
                                                printf("JUMLAH     :            ");
                                            }
                                            npembeli[jpembeli][nmenu][0]=jumlah;
                                            npembeli[jpembeli][13][1]=0;
                                        }while (jumlah<=0);
                                    }
                                    if (nmenu<=0) {
                                        c++;
                                    }
                                }while(nmenu>0);
                            }while(c<banyak);
                        }
                    }
                    y=y+3;
                    do{
                        gotoxy(71,y);
                        printf("KETIK 1 JIKA INGIN KEMBALI KE MENU");
                        y=y+2;
                        gotoxy(71,y);
                        printf("KETIK :");
                        ketik=0;
                        scanf("%i",&ketik);
                        scanf("%c",&huruf);
                        if(ketik<1 || ketik>1) {
                            gotoxy(71,y);
                            printf("KETIK :INVALID");
                            sleep(1);
                            gotoxy(71,y);
                            printf("KETIK :         ");
                            y=y-2;
                        }
                    }while(ketik<1 || ketik>1);
                }
                //LIST NAMA PEMBELI//
                if(menu==2 && pilihan==13) {
                    system("cls");
                    gotoxy(60,3);
                    printf("==========================================");
                    gotoxy(73,5);
                    printf("LIST NAMA PEMBELI");
                    gotoxy(60,7);
                    printf("==========================================");
                    y=8;
                    for(n=1; n<=jpembeli; n++) {
                        y++;
                        gotoxy(65,y);
                        printf("%i. %s",n,pembeli[n]);

                    }
                    if(jpembeli==0) {
                        gotoxy(70,y+1);
                        printf("TIDAK ADA DATA PEMBELI");
                    }
                    gotoxy(60,3+y);
                    printf("==========================================");
                    gotoxy(61,y+5);
                    printf("TEKAN APAPUN UNTUK KEMBALI KE MENU UTAMA");
                    pilihan=getch();
                }
                //DATA PEMBELI//
                if(menu==3 && pilihan==13) {
                    p=-1;
                    system("cls");
                    gotoxy(60,3);
                    printf("==========================================");
                    gotoxy(74,5);
                    printf("DATA PEMBELI");
                    gotoxy(60,7);
                    printf("==========================================");
                    y=8;
                    for(n=1; n<=jpembeli; n++) {
                        y++;
                        gotoxy(65,y);
                        printf("%i. %s",n,pembeli[n]);
                    }
                    if(jpembeli==0) {
                        gotoxy(70,y+1);
                        printf("TIDAK ADA DATA PEMBELI");
                    }
                    gotoxy(60,3+y);
                    printf("==========================================");
                    gotoxy(60,y+5);
                    printf("Pilih 0 untuk kembali ke menu");
                    do{
                    gotoxy(60,y+6);
                    printf("Pilih Pembeli :             ");
                    gotoxy(60,y+6);
                    printf("Pilih Pembeli :");
                    scanf("%i",&p);
                    scanf("%c",&huruf);
                        if(p>jpembeli || p<0) {
                            gotoxy(60,y+6);
                            printf("Pilih Pembeli :INVALID");
                            sleep(1);
                            gotoxy(60,y+6);
                            printf("Pilih Pembeli :         ");
                        }
                    }while(p>jpembeli || p<0);

                    if(p>0) {
                    v=0;
                    system("cls");
                    gotoxy(53,3);
                    printf("=====================================================");
                    gotoxy(61,5);
                    printf("NAMA PEMBELI        : %s",pembeli[p]);
                    gotoxy(61,6);
                    printf("DITANGAI OLEH KASIR : %s",user);
                    if(npembeli[p][13][1]==1){
                        gotoxy(61,7);
                        printf("STATUS MEMBER       : TERDAFTAR");
                    }else{
                        gotoxy(61,7);
                        printf("STATUS MEMBER       : TIDAK TERDAFTAR");
                    }
                    gotoxy(53,9);
                    printf("=====================================================");
                    y=10;
                    for(nmenu=1; nmenu<=12; nmenu++){
                        if(npembeli[p][nmenu][0]>0) {
                            gotoxy(56,10);
                            printf("MENU");
                            gotoxy(94,10);
                            printf("JUMLAH");
                            v=1;
                            y=y+1;
                            if(nmenu==1) {
                                gotoxy(56,y);
                                printf("NASI GORENG KAVIAR");
                                gotoxy(96,y);
                                printf("%i",npembeli[p][nmenu][0]);
                            }
                            if(nmenu==2) {
                                gotoxy(56,y);
                                printf("WAGYU PENYET");
                                gotoxy(96,y);
                                printf("%i",npembeli[p][nmenu][0]);
                            }
                            if(nmenu==3) {
                                gotoxy(56,y);
                                printf("GEPREK TUNA SIRIP BIRU");
                                gotoxy(96,y);
                                printf("%i",npembeli[p][nmenu][0]);
                            }
                            if(nmenu==4) {
                                gotoxy(56,y);
                                printf("RENDANG BAKAR");
                                gotoxy(96,y);
                                printf("%i",npembeli[p][nmenu][0]);
                            }
                            if(nmenu==5) {
                                gotoxy(56,y);
                                printf("AYAM CERMANI");
                                gotoxy(96,y);
                                printf("%i",npembeli[p][nmenu][0]);
                            }
                            if(nmenu==6) {
                                gotoxy(56,y);
                                printf("SOTO DAGING WAGYU");
                                gotoxy(96,y);
                                printf("%i",npembeli[p][nmenu][0]);
                            }
                            if(nmenu==7) {
                                gotoxy(56,y);
                                printf("SUSHI JAWA");
                                gotoxy(96,y);
                                printf("%i",npembeli[p][nmenu][0]);
                            }
                            if(nmenu==8) {
                                gotoxy(56,y);
                                printf("TOMAHAWK");
                                gotoxy(96,y);
                                printf("%i",npembeli[p][nmenu][0]);
                            }
                            if(nmenu==9) {
                                gotoxy(56,y);
                                printf("DAWET IRENG");
                                gotoxy(96,y);
                                printf("%i",npembeli[p][nmenu][0]);
                            }
                            if(nmenu==10) {
                                gotoxy(56,y);
                                printf("LYCHEE TEA");
                                gotoxy(96,y);
                                printf("%i",npembeli[p][nmenu][0]);
                            }
                            if(nmenu==11) {
                                gotoxy(56,y);
                                printf("CIU CANGKOL");
                                gotoxy(96,y);
                                printf("%i",npembeli[p][nmenu][0]);
                            }
                            if(nmenu==12) {
                                gotoxy(56,y);
                                printf("ICELAND");
                                gotoxy(96,y);
                                printf("%i",npembeli[p][nmenu][0]);
                            }
                        }
                    }
                    if(v==0){
                        gotoxy(72,y);
                        printf("TIDAK ADA DATA");
                    }
                    gotoxy(53,y+2);
                    printf("=====================================================");
                    y=y+3;
                    gotoxy(60,y);
                    printf("TEKAN APAPUN UNTUK KEMBALI KE MENU UTAMA");
                    pilihan=getch();
                    }
                }
                //PEMBAYARAN//
                if(menu==4 && pilihan==13) {
                    discount=0;
                    ketik2=0;
                    p=-1;
                    system("cls");
                    gotoxy(60,3);
                    printf("==========================================");
                    gotoxy(60,5);
                    printf("                PEMBAYARAN");
                    gotoxy(60,7);
                    printf("==========================================");
                    y=8;
                    for(n=1; n<=jpembeli; n++) {
                        y++;
                        gotoxy(65,y);
                        printf("%i. %s",n,pembeli[n]);
                    }
                    if(jpembeli==0) {
                        gotoxy(70,y+1);
                        printf("TIDAK ADA DATA PEMBELI");
                    }
                    gotoxy(60,3+y);
                    printf("==========================================");
                    gotoxy(60,y+5);
                    printf("Pilih 0 untuk kembali ke menu");
                    do{
                    gotoxy(60,y+6);
                    printf("Pilih Pembeli :             ");
                    gotoxy(60,y+6);
                    printf("Pilih Pembeli :");
                    scanf("%i",&p);
                    scanf("%c",&huruf);
                        if(p>jpembeli || p<0) {
                            gotoxy(60,y+6);
                            printf("Pilih Pembeli :INVALID");
                            sleep(1);
                            gotoxy(60,y+6);
                            printf("Pilih Pembeli :         ");
                        }
                    }while(p>jpembeli || p<0);

                    if(p>0) {
                    v=0;
                    total=0;
                    system("cls");
                    gotoxy(53,3);
                    printf("=====================================================");
                    gotoxy(57,5);
                    printf("TANGGAL        : %s",ctime(&t));
                    gotoxy(57,6);
                    printf("NAMA PEMBELI   : %s",pembeli[p]);
                    gotoxy(53,8);
                    printf("=====================================================");
                    y=11;
                    gotoxy(56,y);
                    for(nmenu=1; nmenu<=12; nmenu++){


                        if(npembeli[p][nmenu][0]>0) {
                            v=1;
                            y++;
                            gotoxy(56,10);
                            printf("NAMA MENU");
                            gotoxy(83,10);
                            printf("JUMLAH");
                            gotoxy(92,10);
                            printf("SUB TOTAL");
                            if(nmenu==1) {
                                gotoxy(56,y);
                                printf("NASI GORENG KAVIAR");
                                gotoxy(86,y);
                                printf("%i",npembeli[p][nmenu][0]);
                                gotoxy(92,y);
                                printf("Rp. %i",npembeli[p][nmenu][0]*1000000);
                                total=total+(1000000*npembeli[p][nmenu][0]);
                            }
                            if(nmenu==2) {
                                gotoxy(56,y);
                                printf("WAGYU PENYET");
                                gotoxy(86,y);
                                printf("%i",npembeli[p][nmenu][0]);
                                gotoxy(92,y);
                                printf("Rp. %i",npembeli[p][nmenu][0]*500000);
                                total=total+(500000*npembeli[p][nmenu][0]);
                            }
                            if(nmenu==3) {
                                gotoxy(56,y);
                                printf("GEPREK TUNA SIRIP BIRU");
                                gotoxy(86,y);
                                printf("%i",npembeli[p][nmenu][0]);
                                gotoxy(92,y);
                                printf("Rp. %i",npembeli[p][nmenu][0]*350000);
                                total=total+(3500000*npembeli[p][nmenu][0]);
                            }
                            if(nmenu==4) {
                                gotoxy(56,y);
                                printf("RENDANG BAKAR");
                                gotoxy(86,y);
                                printf("%i",npembeli[p][nmenu][0]);
                                gotoxy(92,y);
                                printf("Rp. %i",npembeli[p][nmenu][0]*70000);
                                total=total+(70000*npembeli[p][nmenu][0]);
                            }
                            if(nmenu==5) {
                                gotoxy(56,y);
                                printf("AYAM CERMANI");
                                gotoxy(86,y);
                                printf("%i",npembeli[p][nmenu][0]);
                                gotoxy(92,y);
                                printf("Rp. %i",npembeli[p][nmenu][0]*45000);
                                total=total+(45000*npembeli[p][nmenu][0]);
                            }
                            if(nmenu==6) {
                                gotoxy(56,y);
                                printf("SOTO DAGING WAGYU");
                                gotoxy(86,y);
                                printf("%i",npembeli[p][nmenu][0]);
                                gotoxy(92,y);
                                printf("Rp. %i",npembeli[p][nmenu][0]*100000);
                                total=total+(100000*npembeli[p][nmenu][0]);
                            }
                            if(nmenu==7) {
                                gotoxy(56,y);
                                printf("SUSHI JAWA");
                                gotoxy(86,y);
                                printf("%i",npembeli[p][nmenu][0]);
                                gotoxy(92,y);
                                printf("Rp. %i",npembeli[p][nmenu][0]*65000);
                                total=total+(65000*npembeli[p][nmenu][0]);
                            }
                            if(nmenu==8) {
                                gotoxy(56,y);
                                printf("TOMAHAWK");
                                gotoxy(86,y);
                                printf("%i",npembeli[p][nmenu][0]);
                                gotoxy(92,y);
                                printf("Rp. %i",npembeli[p][nmenu][0]*80000);
                                total=total+(80000*npembeli[p][nmenu][0]);
                            }
                            if(nmenu==9) {
                                gotoxy(56,y);
                                printf("DAWET IRENG");
                                gotoxy(86,y);
                                printf("%i",npembeli[p][nmenu][0]);
                                gotoxy(92,y);
                                printf("Rp. %i",npembeli[p][nmenu][0]*25000);
                                total=total+(25000*npembeli[p][nmenu][0]);
                            }
                            if(nmenu==10) {
                                gotoxy(56,y);
                                printf("LYCHEE TEA");
                                gotoxy(86,y);
                                printf("%i",npembeli[p][nmenu][0]);
                                gotoxy(92,y);
                                printf("Rp. %i",npembeli[p][nmenu][0]*10000);
                                total=total+(10000*npembeli[p][nmenu][0]);
                            }
                            if(nmenu==11) {
                                gotoxy(56,y);
                                printf("CIU CANGKOL");
                                gotoxy(86,y);
                                printf("%i",npembeli[p][nmenu][0]);
                                gotoxy(92,y);
                                printf("Rp. %i",npembeli[p][nmenu][0]*60000);
                                total=total+(60000*npembeli[p][nmenu][0]);
                            }
                            if(nmenu==12) {
                                gotoxy(56,y);
                                printf("ICELAND");
                                gotoxy(86,y);
                                printf("%i",npembeli[p][nmenu][0]);
                                gotoxy(92,y);
                                printf("Rp. %i",npembeli[p][nmenu][0]*100000);
                                total=total+(1000000*npembeli[p][nmenu][0]);
                            }
                        }
                    }
                    if(v==0){
                        gotoxy(72,y);
                        printf("TIDAK ADA DATA");
                    }
                    if(v==1){
                        y=22;
                        gotoxy(53,y);
                        printf("=====================================================");
                        gotoxy(80,y+2);
                        printf("TOTAL HARGA : Rp. %i",total);
                        do{
                            dibayar=-1;
                            gotoxy(80,y+3);
                            printf("DIBAYAR     : Rp. ");
                            scanf("%i",&dibayar);
                            scanf("%c",&huruf);
                            if(dibayar<0){
                                gotoxy(80,y+3);
                                printf("DIBAYAR     : Rp. INVALID");
                                sleep(1);
                                gotoxy(80,y+3);
                                printf("DIBAYAR     : Rp.          ");
                            }
                        }while(dibayar<0);
                        if(npembeli[p][13][1]==1 ) {
                            if(total>=10000000){
                                discounti=10;
                                discount=0.1;
                            }else if(total>=1000000){
                                discounti=5;
                                discount=0.05;
                            }else {
                                discounti=0;
                                discount=0;
                            }
                            gotoxy(80,y+4);
                            printf("DISCOUNT    : %i%c",discounti,dc='%');
                            y++;
                        }
                        kembalian=dibayar-(total-(total*discount));
                        gotoxy(80,y+4);
                        printf("KEMBALIAN   : Rp. %i",kembalian);
                        if(kembalian<0) {
                            gotoxy(80,y+4);
                            printf("Maaf uang anda tidak mencukupi");
                        }
                    }
                    gotoxy(53,y+6);
                    printf("=====================================================");

                    gotoxy(53,y+9);
                    printf("KETIK 1 JIKA INGIN MEMESAN LAGI");
                    gotoxy(53,y+10);
                    printf("KETIK 2 JIKA INGIN KEMBALI KE MENU");
                    do{
                        ketik2=0;
                        gotoxy(53,y+12);
                        printf("KETIK : ");
                        scanf("%i",&ketik2);
                        scanf("%c",&huruf);
                        if(ketik2<1 || ketik2>2){
                            gotoxy(53,y+12);
                            printf("KETIK :INVALID ");
                            sleep(1);
                            gotoxy(53,y+12);
                            printf("KETIK :             ");
                            }
                        }while(ketik2<1 || ketik2>2);
                        if(ketik2==1) {
                            menu=1;
                            pilihan=13;
                        }
                    }
                }
                //MEMBERSHIP//
                if(menu==5 && pilihan==13) {
                    menu2=0;
                    do{
                        p=-1;
                        ulang=0;
                        system("cls");
                        gotoxy(60,3);
                        printf("==========================================");
                        gotoxy(76,5);
                        printf("MEMBERSHIP");
                        gotoxy(60,7);
                        printf("==========================================");
                        if(menu2==1) {
                            gotoxy(65,9);
                            printf(">>PENDAFTARAN");
                        }else {
                            gotoxy(65,9);
                            printf("PENDAFTARAN");
                        }
                        if(menu2==2) {
                            gotoxy(65,10);
                            printf(">>DAFTAR MEMBER");
                        }else {
                            gotoxy(65,10);
                            printf("DAFTAR MEMBER");
                        }
                        if(menu2==3) {
                            gotoxy(65,11);
                            printf(">>KEMBALI");
                        }else {
                            gotoxy(65,11);
                            printf("KEMBALI");
                        }
                        gotoxy(60,14);
                        printf("==========================================");
                        pilihan2=getch();
                        if(pilihan2==80){
                            menu2++;
                            if(menu2>3)
                            menu2=1;
                        }
                        if(pilihan2==72){
                            menu2--;
                            if(menu2<1)
                            menu2=3;
                        }
                        if(menu2==1 && pilihan2==13){
                            jmember++;
                            system("cls");
                            gotoxy(60,3);
                            printf("==========================================");
                            gotoxy(74,5);
                            printf("PENDAFTARAN");
                            gotoxy(60,7);
                            printf("==========================================");
                            gotoxy(60,13);
                            printf("==========================================");
                            gotoxy(65,9);
                            printf("NAMA     :");
                            gotoxy(65,10);
                            printf("NOMER HP :");
                            gotoxy(65,11);
                            printf("EMAIL    :");
                            do{
                                gotoxy(75,9);
                                scanf(" %[^\n]s",&nmember[jmember]);
                                if(strcmp(nmember[jmember], "A") < 0){
                                    gotoxy(65,9);
                                    printf("NAMA     :INVALID");
                                    sleep(1);
                                    gotoxy(65,9);
                                    printf("NAMA     :          ");
                                }
                            }while(strcmp(nmember[jmember], "A") < 0);
                            do{
                                gotoxy(75,10);
                                scanf(" %[^\n]s",&nmember[jmember][1]);
                                if(strcmp(nmember[jmember][1], "9") > 0){
                                    gotoxy(65,10);
                                    printf("NOMER HP :INVALID");
                                    sleep(1);
                                    gotoxy(65,10);
                                    printf("NOMER HP :          ");
                                }
                            }while(strcmp(nmember[jmember][1], "9") > 0);
                            gotoxy(75,11);
                            scanf(" %[^\n]s",&nmember[jmember][1][1]);
                            system("cls");
                            for(i=0; i<=42; i++){
                                gotoxy(60+i,3);
                                printf("%c",garis[i]);
                                gotoxy(76,5);
                                printf("LOADING");
                                gotoxy(60+i,7);
                                printf("%c",garis[i]);
                                Sleep(55);
                            }
                            sleep(1);
                            gotoxy(60,3);
                            printf("==========================================");
                            gotoxy(66,5);
                            printf("PENDAFTARAN AKUN MEMBER SUKSES");
                            gotoxy(60,7);
                            printf("==========================================");
                            gotoxy(61,9);
                            printf("TEKAN APAPUN UNTUK KEMBALI KE MENU UTAMA");
                            pilihan2=getch();
                            ulang=1;
                        }
                        if(menu2==2 && pilihan2==13){
                            system("cls");
                            gotoxy(60,3);
                            printf("==========================================");
                            gotoxy(74,5);
                            printf("DAFTAR MEMBER");
                            gotoxy(60,7);
                            printf("==========================================");
                            y=8;
                            for(n=1; n<=jmember; n++) {
                                y++;
                                    for(p=1; p<=n; p++){
                                        gotoxy(65,y);
                                        printf("%i. %s",n,nmember[p]);
                                    }
                            }
                            if(jmember==0) {
                                gotoxy(70,y+1);
                                printf("TIDAK ADA DATA MEMBER");
                            }
                            gotoxy(60,y+3);
                            printf("==========================================");
                            gotoxy(60,y+5);
                            printf("Pilih 0 untuk kembali ke menu");
                            do{
                            gotoxy(60,y+6);
                            printf("Pilih Member :             ");
                            gotoxy(60,y+6);
                            printf("Pilih Member :");
                            scanf("%i",&p);
                            scanf("%c",&huruf);
                                if(p>jmember || p<0) {
                                    gotoxy(60,y+6);
                                    printf("Pilih Member :INVALID");
                                    sleep(1);
                                    gotoxy(60,y+6);
                                    printf("Pilih Member :         ");
                                }
                            }while(p>jmember || p<0);

                             if(p>0) {
                                system("cls");
                                gotoxy(53,3);
                                printf("=====================================================");
                                gotoxy(61,5);
                                printf("NAMA        : %s",nmember[p]);
                                gotoxy(61,6);
                                printf("NOMER HP    : %s",nmember[p][1]);
                                gotoxy(61,7);
                                printf("EMAIL       : %s",nmember[p][1][1]);
                                gotoxy(53,9);
                                printf("=====================================================");
                                gotoxy(60,11);
                                printf("TEKAN APAPUN UNTUK KEMBALI KE MENU MEMBER");
                                pilihan=getch();
                                ulang=1;
                             }
                        }
                    }while(pilihan2!='\r' || ulang==1 || p==0);
                }
                //CLEAR DATA//
                if(menu==6 && pilihan==13) {
                    jpembeli=0;
                    for(i=1; i<=20; i++){
                        for(j=0; j<=32; j++){
                            pembeli[i][j]=0;
                        }
                    }
                    for(i=1; i<=30; i++){
                        for(j=0; j<=12; j++){
                            npembeli[i][j][0]=0;
                            npembeli[i][13][1]=0;
                        }
                    }
                    system("cls");
                    for(i=0; i<=42; i++){
                        gotoxy(60+i,3);
                        printf("%c",garis[i]);
                        gotoxy(76,5);
                        printf("LOADING");
                        gotoxy(60+i,7);
                        printf("%c",garis[i]);
                        Sleep(55);
                    }
                    sleep(1);
                    gotoxy(60,3);
                    printf("==========================================");
                    gotoxy(70,5);
                    printf("DATA TELAH DIBERSIHKAN");
                    gotoxy(60,7);
                    printf("==========================================");
                    gotoxy(61,9);
                    printf("TEKAN APAPUN UNTUK KEMBALI KE MENU UTAMA");
                    pilihan=getch();
                }
                //LOGOUT//
                if(menu==7 && pilihan==13) {
                    goto login;
                }
                //KATA KATA MUTIARA//
                if(menu==8 && pilihan==13) {
                    char dear[2000]={"Dear kaka asdos Cornelius Yoga dan Raffles Supit...\nPertama tama kami mengucapkan terima kasih atas usaha dan kerja kerasnya selama membimbing kelas asistensi ini, kami sangat terbimbing penjelasanya lengkap,\ndari kita boleh bertanya ketika kesulitan, boleh memfoto coding materi jika memerlukan, dalam perhial nilai kaka kaka ini sangat adil misal kalo ada yang nyontek \nlangsung dikasih nilai rendah,kemudahan dalam perizinan semisal kita tidak tadang ke kelas atau kita terlambat. itu saja sisi positifnya dari kaka kaka ini selebihnya.\n\nUntuk Negatifnya sih menurut kami, yaitu materi yang diberikan kurang lengkap, terus soal sistem nilai ketentuan/aspek-aspek dalma suatu tugas kodingan itu kurang \ntepat salah satu contohnya adalah kerapian coding, nah kerapian itu dinilai dari apasih? kita kan sebagai backend developer berusaha agar apa yg ditampilkan/diciptakanitu bisa layak digunakan untuk pengguna, sementara itu yang namanya juga backend pasti berantakan, dan kita pasti lebih mengutamakan fungsi dan mekanikal dalam suatu  program tersebut. nah sebaiknya fungsi dan mekanikal beserta kretivitas tersebut yang harus di nilai daripada kerapian codingannya. lebih baiknya sih ya mungkin \nmenilai sesuatu bisa lebih detail lagi dan mungkin menurut saya kakaknya bisa lebih banyak interaksi dengan semua mahasiswa dalam matkul tersebut\nBaiklah itu semua curhatan kami selama ada di kelas asistensi kami terutama kepada kaka asdos \nMohon maaf jika kita salah dalam menjalani hari hari bersama kaka asdos di matkul ddp ini, dan juga kita meminta maaf jika ada perkataan kami yang membuat kakak tidak nyaman, kami tidak bermaksud untuk menjelek jelekan dan menghina ataupun menghujat kaka asdos.\nCukup materi koding dari kami kalo ada yang membingungkan dan tidak dimengerti, kami harap kalian belajar lebih giat lagi.\n\nSekian dari kelompok kami..\nJika ada yang ingin bertanya..\nPasti kami jawab kamu nanya?"};
                    system("cls");
                    gotoxy(60,3);
                    printf("==================================================");
                    gotoxy(80,5);
                    printf("DEAR ASDOS");
                    gotoxy(60,7);
                    printf("==================================================");
                    gotoxy(0,9);
                    for(i=0; i<=1930; i++){
                        printf("%c",dear[i]);
                        Sleep(10);
                    }
                    sleep(3);
                    gotoxy(65,28);
                    printf("TEKAN APAPUN UNTUK KEMBALI KE MENU UTAMA");
                    pilihan=getch();
                }
                //EXIT//
                if(menu==9 && pilihan==13) {
                    int huruf_T[16][141] = {
                        {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
                        {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
                        {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
                        {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
                        {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
                        {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
                        {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,1,1,1,1,1,1,1,1,0,0,1,1,1,1,1,1,1,0,0,1,1,1,1,1,1,1,0,0,0,0,0,1,1,1,0,0,1,1,0,0,0,0,0,0,0,1,1,0,0,0,0,1,1,1,1,1,0,0,0,0,0,0,0,0,0,0,1,1,1,0,0,0,1,1,1,1,0,0,0,0,1,1,1,1,1,0,0,0,0,0,1,1,1,1,1,1,1,0,0,1,1,1,0,0,1,1,1,0,0,0,1,1,1},
                        {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,1,1,1,1,1,1,1,1,0,0,1,1,1,1,1,1,1,0,0,1,1,1,1,1,1,1,1,1,0,0,0,1,1,1,0,0,1,1,1,0,0,0,0,0,1,1,1,0,0,0,1,1,1,1,1,1,1,0,0,0,0,0,0,0,0,0,1,1,1,0,0,1,1,1,1,0,0,0,0,1,1,1,1,1,1,1,0,0,0,1,1,1,1,1,1,1,1,0,0,1,1,1,0,0,1,1,1,0,0,0,1,1,1},
                        {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,1,1,0,0,0,0,0,1,1,1,0,0,0,0,0,0,1,1,1,0,0,0,1,1,1,1,0,0,1,1,1,0,0,1,1,1,1,0,0,0,1,1,1,1,0,0,1,1,1,0,0,0,1,1,1,0,0,0,0,0,0,0,0,1,1,1,0,1,1,1,1,0,0,0,0,1,1,1,0,0,0,1,1,1,0,0,1,1,0,0,0,0,0,0,0,0,1,1,1,0,0,1,1,1,0,0,0,1,1,1},
                        {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,1,1,0,0,0,0,0,1,1,1,1,1,1,1,0,0,1,1,1,0,0,1,1,1,1,1,0,0,1,1,1,0,0,1,1,1,1,1,1,1,1,1,1,1,0,0,1,1,1,0,0,0,1,1,1,0,0,0,0,0,0,0,0,1,1,1,1,1,1,1,0,0,0,0,0,1,1,1,0,0,0,1,1,1,0,0,1,1,1,1,1,1,1,0,0,0,1,1,1,0,0,1,1,1,1,1,1,1,1,1},
                        {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,1,1,0,0,0,0,0,1,1,1,1,1,1,1,0,0,1,1,1,1,1,1,1,1,1,0,0,0,1,1,1,0,0,1,1,1,1,1,1,1,1,1,1,1,0,0,1,1,1,1,1,1,1,1,1,0,0,0,0,0,0,0,0,1,1,1,1,1,1,1,0,0,0,0,0,1,1,1,1,1,1,1,1,1,0,0,0,1,1,1,1,1,1,1,0,0,1,1,1,0,0,1,1,1,1,1,1,1,1,1},
                        {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,1,1,0,0,0,0,0,1,1,1,0,0,0,0,0,0,1,1,1,1,1,1,1,0,0,0,0,0,1,1,1,0,0,1,1,1,0,1,1,1,0,1,1,1,0,0,1,1,1,1,1,1,1,1,1,0,0,0,0,0,0,0,0,1,1,1,0,1,1,1,1,0,0,0,0,1,1,1,1,1,1,1,1,1,0,0,0,0,0,0,0,0,1,1,0,0,1,1,1,0,0,1,1,1,0,0,0,1,1,1},
                        {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,1,1,0,0,0,0,0,1,1,1,1,1,1,1,0,0,1,1,1,0,0,1,1,1,0,0,0,0,1,1,1,0,0,1,1,1,0,0,1,0,0,1,1,1,0,0,1,1,1,0,0,0,1,1,1,0,0,0,0,0,0,0,0,1,1,1,0,0,1,1,1,1,0,0,0,1,1,1,0,0,0,1,1,1,0,0,1,1,1,1,1,1,1,1,0,0,1,1,1,0,0,1,1,1,0,0,0,1,1,1},
                        {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,1,1,0,0,0,0,0,1,1,1,1,1,1,1,0,0,1,1,1,0,0,0,1,1,1,0,0,0,1,1,1,0,0,1,1,1,0,0,0,0,0,1,1,1,0,0,1,1,1,0,0,0,1,1,1,0,0,0,0,0,0,0,0,1,1,1,0,0,0,1,1,1,1,0,0,1,1,1,0,0,0,1,1,1,0,0,1,1,1,1,1,1,1,0,0,0,1,1,1,0,0,1,1,1,0,0,0,1,1,1},
                    };
                    system("cls");
                    for(i=0; i<16; i++){
                        system ("color f0");

                        for(j=0; j<141; j++)
                            if(huruf_T[i][j] !=0)
                                putchar('\xDB');
                                else
                                putchar(' ');
                                putchar('\n');
                        system ("color f");
                    }
                    Sleep(200);
                    int emot[20][136] = {
                        {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
                        {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
                        {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
                        {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,1,0,0,0,0,0,0,0,0,1,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,1,0,0,0,0,0,0,0,0,1,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
                        {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,1,0,0,0,0,0,0,1,1,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,1,1,0,0,0,0,0,0,1,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
                        {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,1,0,0,0,0,0,1,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,1,0,0,0,0,0,1,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
                        {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,1,0,0,0,0,1,1,0,0,0,0,1,1,1,1,1,0,0,0,0,0,0,0,0,0,0,1,1,1,1,1,0,0,0,0,1,1,0,0,0,0,1,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
                        {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,1,0,0,0,0,0,0,0,0,0,0,1,1,1,1,1,1,1,0,0,0,0,0,0,0,0,1,1,1,1,1,1,1,0,0,0,0,0,0,0,0,0,0,1,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
                        {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,1,0,0,0,0,0,0,0,0,0,0,1,1,0,0,0,0,0,1,1,0,0,0,0,0,0,1,1,0,0,0,0,0,1,1,0,0,0,0,0,0,0,0,0,0,1,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
                        {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,1,0,0,0,0,0,0,0,0,0,1,1,0,0,0,0,0,1,1,1,1,0,0,0,0,1,1,0,0,0,0,0,1,1,1,1,0,0,0,0,0,0,0,0,0,1,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
                        {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,1,0,0,0,0,0,0,0,0,1,1,0,0,0,0,1,1,0,1,1,0,0,0,0,1,1,0,0,0,0,1,1,0,1,1,0,0,0,0,0,0,0,0,1,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
                        {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,1,0,0,0,0,0,0,0,0,1,1,0,0,1,1,0,1,1,0,0,0,0,0,0,1,1,0,0,1,1,0,1,1,0,0,0,0,0,0,0,0,1,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
                        {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,1,0,0,0,0,0,0,0,0,1,1,1,1,1,1,1,0,0,0,0,0,0,0,0,1,1,1,1,1,1,1,0,0,0,0,0,0,0,0,1,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
                        {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,1,0,0,0,0,0,0,0,0,1,1,1,1,1,0,0,0,1,1,1,1,0,0,0,1,1,1,1,1,0,0,0,0,0,0,0,0,1,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
                        {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,1,0,0,1,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
                        {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,1,0,0,0,0,0,0,0,0,0,0,0,0,1,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
                        {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
                        {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
                    };
                    for(i=0; i<20; i++){
                        system ("color f0");
                        for(j=0; j<136; j++)
                            if(emot[i][j] !=0)
                                putchar('\xDB');
                                else
                                putchar(' ');
                                putchar('\n');
                        system ("color f");
                    }
                    system ("color f0");
                    sleep(5);
                    exit(0);
                }
            }while(ketik2==1);
        }
        while(ketik==1 || p==0 || banyak==0 || pilihan!='\r' || pilihan==27 || pilihan==13 ||ketik2==2);
    return(0);
}
