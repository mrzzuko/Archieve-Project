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

typedef struct cashier{
    char username[32];
    char pw[32];
}cashier;

typedef struct menu{
    int jumlah;
}menu;

typedef struct buyer{
    char nama[32];
    menu Menu[11];
    struct buyer *next;
}buyer;


//GLOBAL DECLARATION//
cashier kasir;
//Deklarasi Node
buyer *head = NULL;
buyer *temp, *last;

int pilih=0;
int countpembeli=0;
int y;


int login(){
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
    do{
        gotoxy(75,9);
        scanf(" %[^\n]s",&kasir.username);
        if(strcmp(&kasir.username, "Hasdan123")){
                gotoxy(65,9);
                printf("Username :INVALID");
                sleep(1);
                gotoxy(65,9);
                printf("Username :                             ");
        }
    }while(strcmp(&kasir.username, "Hasdan123"));
    do{
    gotoxy(75,10);
        for (int i = 0; i < 32; i++) {
            kasir.pw[i] = getch();
            if(kasir.pw[i]==13 && i>0){
                i=32;
            }
            else if(kasir.pw[i]==13){
                i=-1;
                printf("");
            }else{
                printf("*");
            }
        }
        if(strcmp(&kasir.pw, "123") < 0){
                gotoxy(65,10);
                printf("Password :INVALID");
                sleep(1);
                gotoxy(65,10);
                printf("Password :                             ");
        }
    }while(strcmp(&kasir.pw, "123") < 0);
}

int menuutama(){

        system("cls");
        gotoxy(60,3);
        printf("==========================================");
        gotoxy(75,5);
        printf("BURJO HASDAN");
        gotoxy(60,7);
        printf("==========================================");
        gotoxy(63,9);
        printf("1. MENU RESTO");
        gotoxy(63,10);
        printf("2. PEMBAYARAN");
        gotoxy(63,11);
        printf("3. CLEAR DATA");
        gotoxy(63,12);
        printf("4. LOGOUT");
        gotoxy(60,14);
        printf("==========================================");
        gotoxy(63,16);
        printf("PILIH MENU :");
        scanf("%i",&pilih);
        fflush(stdin);
}

int menuresto(){

    do{
        char namapembeli[32];
        int menuke;
        int jumlah;
        system("cls");
        gotoxy(58,3);
        printf("===================================================");
        gotoxy(79,5);
        printf("MENU RESTO");
        gotoxy(68,6);
        printf("KETIK 0 UNTUK MENGAKHIRI PESANAN");
        gotoxy(58,8);
        printf("===================================================");
        gotoxy(60,10);
        printf("MAKANAN");
        gotoxy(62,11);
        printf("1. NASI GORENG...............Rp. 10.000");
        gotoxy(62,12);
        printf("2. KWETIAW...................Rp. 15.000");
        gotoxy(62,13);
        printf("3. SOTO AYAM.................Rp. 5.000");
        gotoxy(62,14);
        printf("4. INDOMIE TANTE.............Rp. 7.000");
        gotoxy(62,15);
        printf("5. INDOMIE KORNET............Rp. 9.000");
        gotoxy(62,16);
        printf("6. INDOMIE GONGSO............Rp. 15.000");
        gotoxy(60,18);
        printf("MINUMAN");
        gotoxy(62,19);
        printf("7. ES/PANAS TEH..............Rp. 3.000");
        gotoxy(62,20);
        printf("8. ES/PANAS JERUK............Rp. 5.000");
        gotoxy(62,21);
        printf("9. GOODDAY...................Rp. 5.000");
        gotoxy(62,22);
        printf("10. NUTRISARI................Rp. 3.000");
        gotoxy(58,24);
        printf("===================================================");


        countpembeli++;
        gotoxy(79,28);
        printf("NON-MEMBER");
        gotoxy(63,30);
        printf("NAMA PEMBELI :");
        scanf(" %[^\n]s",&namapembeli);
        fflush(stdin);
        y=31;
        //Buat Node Sementara
        temp = (struct buyer*)malloc(sizeof(struct buyer));
            for(int i=0; i<12; i++){
                temp->Menu[i].jumlah=0;
            }
            do{
                y++;
                gotoxy(63,y);
                printf("PILIH MENU MAKANAN :");
                scanf("%i",&menuke);
                fflush(stdin);
                    if(menuke>0){
                        y++;
                        gotoxy(63,y);
                        printf("JUMLAH :");
                        scanf("%i",&jumlah);
                        fflush(stdin);
                        y++;
                    }
            //Memasukan Value ke dalam node temporary/sementara
            strcpy(temp->nama, namapembeli);
            temp->Menu[menuke].jumlah = jumlah;
            }while(menuke!=0 && menuke!=0);
            temp->next = NULL;

            // Memasukkan Node ke Linked list
            if (head == NULL) {
                head = temp;
            } else {
                last->next = temp;
            }
            last = temp;

        gotoxy(54,y+2);
        printf("KETIK 0 JIKA INGIN KEMBALI KE MENU ATAU 1 UNTUK MENGULANGI");
        gotoxy(54,y+4);
        printf("KETIK :");
        scanf("%i",&pilih);
        fflush(stdin);
    }while(pilih==1);
}

int pembayaran(){
    time_t t;
    time(&t);
        //Deklarasi node sebagai pointer p// (Searching And Select Purpose)
        buyer *p;
        int n=0;
        int total=0;
        int dibayar;
        int kembalian=0;
        system("cls");
        gotoxy(60,3);
        printf("==========================================");
        gotoxy(60,5);
        printf("                PEMBAYARAN");
        gotoxy(60,7);
        printf("==========================================");
                    y=8;
                    //Mendeteksi Node yang tersedia// (Searching)
                    if(head!=NULL){
                        p=head;
                        while(p!=NULL){
                            y++;
                            n++;
                            gotoxy(65,y);
                            printf("%i. %s",n,p->nama);
                            p = p->next;
                        }
                    }else{
                        gotoxy(70,y+1);
                        printf("TIDAK ADA DATA PEMBELI");
                    }

                    gotoxy(60,3+y);
                    printf("==========================================");
                    gotoxy(60,y+5);
                    printf("Pilih 0 untuk kembali ke menu");
                    do{
                    gotoxy(60,y+6);
                    printf("Pilih Pembeli :                 ");
                    gotoxy(75,y+6);
                    scanf("%i",&pilih);
                    fflush(stdin);
                }while(pilih>countpembeli || pilih<0);
        //Memilih Node yang di inginkan// (Select)
        if(head!=NULL){
            p=head;
            for(int i=1; i<pilih; i++){
                p=p->next;
            }
        }
        //
        if(pilih>0) {
        int total=0;
        system("cls");
        gotoxy(53,3);
        printf("=====================================================");
        gotoxy(57,5);
        printf("TANGGAL        : %s",ctime(&t));
        gotoxy(57,6);
        printf("NAMA PEMBELI   : %s",p->nama);
        gotoxy(53,8);
        printf("=====================================================");
        y=11;
        gotoxy(56,10);
        printf("NAMA MENU");
        gotoxy(83,10);
        printf("JUMLAH");
        gotoxy(92,10);
        printf("SUB TOTAL");
        gotoxy(56,y);
        int menuke;
        for(menuke=1; menuke<=12; menuke++){
            if(p->Menu[menuke].jumlah>0) {
                y++;
                if(menuke==1) {
                    gotoxy(56,y);
                    printf("NASI GORENG");
                    gotoxy(86,y);
                    printf("%i",p->Menu[1].jumlah);
                    gotoxy(92,y);
                    printf("Rp. %i",p->Menu[1].jumlah*10000);
                    total=total+(p->Menu[1].jumlah*10000);
                }
                if(menuke==2) {
                    gotoxy(56,y);
                    printf("KWETIAU");
                    gotoxy(86,y);
                    printf("%i",p->Menu[2].jumlah);
                    gotoxy(92,y);
                    printf("Rp. %i",p->Menu[2].jumlah*15000);
                    total=total+(p->Menu[2].jumlah*15000);
                }
                if(menuke==3) {
                    gotoxy(56,y);
                    printf("SOTOAYAM");
                    gotoxy(86,y);
                    printf("%i",p->Menu[3].jumlah);
                    gotoxy(92,y);
                    printf("Rp. %i",p->Menu[3].jumlah*5000);
                    total=total+(p->Menu[3].jumlah*5000);
                }
                if(menuke==4) {
                    gotoxy(56,y);
                    printf("INDOMIE TANTE");
                    gotoxy(86,y);
                    printf("%i",p->Menu[4].jumlah);
                    gotoxy(92,y);
                    printf("Rp. %i",p->Menu[4].jumlah*7000);
                    total=total+(p->Menu[4].jumlah*7000);
                }
                if(menuke==5) {
                    gotoxy(56,y);
                    printf("INDOMIE KORNET");
                    gotoxy(86,y);
                    printf("%i",p->Menu[5].jumlah);
                    gotoxy(92,y);
                    printf("Rp. %i",p->Menu[5].jumlah*9000);
                    total=total+(p->Menu[5].jumlah*9000);
                }
                if(menuke==6) {
                    gotoxy(56,y);
                    printf("INDOMIE GONGSO");
                    gotoxy(86,y);
                    printf("%i",p->Menu[6].jumlah);
                    gotoxy(92,y);
                    printf("Rp. %i",p->Menu[6].jumlah*15000);
                    total=total+(p->Menu[6].jumlah*15000);
                }
                if(menuke==7) {
                    gotoxy(56,y);
                    printf("ES/TEH PANAS");
                    gotoxy(86,y);
                    printf("%i",p->Menu[7].jumlah);
                    gotoxy(92,y);
                    printf("Rp. %i",p->Menu[7].jumlah*3000);
                    total=total+(p->Menu[7].jumlah*3000);
                }
                if(menuke==8) {
                    gotoxy(56,y);
                    printf("GOODDAY");
                    gotoxy(86,y);
                    printf("%i",p->Menu[8].jumlah);
                    gotoxy(92,y);
                    printf("Rp. %i",p->Menu[8].jumlah*5000);
                    total=total+(p->Menu[8].jumlah*5000);
                }
                if(menuke==9) {
                    gotoxy(56,y);
                    printf("NUTRISARI");
                    gotoxy(86,y);
                    printf("%i",p->Menu[9].jumlah);
                    gotoxy(92,y);
                    printf("Rp. %i",p->Menu[9].jumlah*3000);
                    total=total+(p->Menu[9].jumlah*3000);
                }
                    if(menuke==10) {
                    gotoxy(56,y);
                    printf("SUSU");
                    gotoxy(86,y);
                    printf("%i",p->Menu[10].jumlah);
                    gotoxy(92,y);
                    printf("Rp. %i",p->Menu[10].jumlah*5000);
                    total=total+(p->Menu[10].jumlah*5000);
                }
            }
        }
        y=22;
        gotoxy(53,y);
        printf("=====================================================");
        gotoxy(80,y+2);
        printf("TOTAL HARGA : Rp. %i",total);
        do{
            gotoxy(80,y+3);
            printf("DIBAYAR     : Rp. ");
            scanf("%i",&dibayar);
        }while(dibayar<0);
        kembalian=dibayar-total;
        gotoxy(80,y+4);
        printf("KEMBALIAN   : Rp. %i",kembalian);
        if(kembalian<0) {
            gotoxy(80,y+4);
            printf("Maaf uang anda tidak mencukupi");
        }
        gotoxy(53,y+6);
        printf("=====================================================");
        gotoxy(59,y+9);
        printf("TEKAN APAPUN UNTUK KEMBALI KE MENU UTAMA");
        int pilihan=getch();
    }
}

int clearnode(){
    system("cls");
    int c=1;

    buyer *p = head;
    while(p!=NULL){
        p = p->next;
        free(head);
        head=p;

    }


    countpembeli=0;
    char *garis = "==========================================";
    int len1 = strlen(garis);

    for(int i=0; i<=len1; i++){
        gotoxy(60+i,3);
        printf("%c",garis[i]);
        gotoxy(76,5);
        printf("LOADING");
        gotoxy(60+i,7);
        printf("%c",garis[i]);
        Sleep(55);
    }
    system("cls");
    gotoxy(60,3);
    printf("==========================================");
    gotoxy(70,5);
    printf("DATA TELAH DIBERSIHKAN");
    gotoxy(60,7);
    printf("==========================================");
    gotoxy(61,9);
    printf("TEKAN APAPUN UNTUK KEMBALI KE MENU UTAMA");
    int pilihan=getch();
}

int main(){
    int exits=0;
    login();
    while(exits==0){
        menuutama();
        switch(pilih) {
            case 1:
                menuresto();
                break;
            case 2:
                pembayaran();
                break;
            case 3:
                clearnode();
                break;
            case 4:
                login();
            default:
                break;
        }
    }
}


