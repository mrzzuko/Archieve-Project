#include <stdio.h>
#include <conio.h>
#include <windows.h>
#include <time.h>

#define MAX_PANJANG 8
#define totalSKS 30
#define maxMatkul 20


void gotoxy(int x,int y) {
    COORD coord;
    coord.X = x;
    coord.Y = y;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
}

typedef struct matkul {
  char kodematkul[10];
  char namamatkul[50];
  char jadwalmatkul[20];
  int jadwaldikodein; //untuk sorting itunganny 1 = senin, 13 = waktu kelar, 10 = waktu mulai = 11310
  int hargapersks; //hargany
  int sksA;
  int sksB;
  char namadosen[25];
  char kodedosen[20];
} matkul;

typedef struct mahasiswa {
  char nama[32];
  char nim[14];
  char pw[8]; //gegara pass asliny cuma bisa nampung 8 :moyai:
  int sks;
  int banyakMatkul;
  int maxSKS;
  int total_tagihan;
  matkul dataKST[maxMatkul];
} mahasiswa;


//GLOBAL DECLARATION//
int kuliah=0;
int ke;
int countmahasiswa=5;
mahasiswa siDia[10] = {{"Daniro Prasetyo","672023210","123",0,0},{"Andreonie Anugerah","672023173","456",0,0}
    ,{"Junus Brendisjawara T.","672023273","123",0,0},{"Ferdinand Putra Nugroho","672023020","123",0,0}
    ,{"Kornelius Candra Kurniawan","672023241","123",0,0}};

void FormatIDRcoi(int n) {
    printf("Rp.");
    int n2 = 0;
    int scale = 1;
    if (n < 0) {
        printf ("-");
        n = -n;
    }
    while (n >= 1000) {
        n2 = n2 + scale * (n % 1000);
        n /= 1000;
        scale *= 1000;
    }
    printf ("%d", n);
    while (scale != 1) {
        scale /= 1000;
        n = n2 / scale;
        n2 = n2  % scale;
        printf (",%03d", n);
    }
}

void registrasiulang(){
    int menu=1,pilihan;
    header(3);
    gotoxy(60,5);
    printf("REGISTRASI ULANG");
    gotoxy(42,9);
    printf("LAKUKAN REGISTRASI ULANG SEBELUM REGISTRASI MATKUL!");
    gotoxy(42,11);
    printf("TENTUKAN PILIHAN ANDA !");
    do {
        if(menu == 1) {
            gotoxy(40,13);
            printf(">>  LANJUT KULIAH");
        } else {
            gotoxy(40,13);
            printf("    LANJUT KULIAH");
        }
        if(menu == 2) {
            gotoxy(40,14);
            printf(">>  CUTI KULIAH");
        } else {
            gotoxy(40,14);
            printf("    CUTI KULIAH");
        }
        if(menu == 3) {
            gotoxy(82,23);
            printf(">>  KEMBALI  <<\n");
        } else {
            gotoxy(82,23);
            printf("    KEMBALI    \n");
        }

        pilihan = getch();
        if(pilihan == 80) {
            menu++;
            if(menu > 3)
                menu = 1;
        }
        if(pilihan == 72) {
            menu--;
            if(menu < 1)
                menu = 3;
        }
    }while(pilihan != 27 && pilihan != 13);
    if(menu==1){
        kuliah=1;
    }
    if(menu==2){
        kuliah=2;
    }
}

void jadwal(matkul a[]){
    system("cls");
    header(2);
    gotoxy(61, 6);
    printf("PILIH JADWAL");
    gotoxy(44-8, 10);
    printf("KODE");
    gotoxy(56-4, 10);
    printf("MATA KULIAH");
    gotoxy(88-10, 10);
    printf("SKS A");
    gotoxy(94-10, 10);
    printf("SKS B");
    gotoxy(106-10, 10);
    printf("JADWAL");

 for(int i=0;i<3;i++){ /*banya matkul, klo mau tambah bikin param int banya matkul*/
            gotoxy(42-7, 11+i);
                printf("%s",a[i].kodematkul);
            gotoxy(50-6, 11+i);
               printf("%s",a[i].namamatkul);
            gotoxy(88-8, 11+i);
               printf("%i",a[i].sksA);
            gotoxy(94-8, 11+i);
               printf("%i",a[i].sksB);
            gotoxy(101-10, 11+i);
               printf("%s",a[i].jadwalmatkul);
  }
}

void regismatkul(){
  int exits=0;
    matkul TBO[4]={
    {"TC531A","Teori Bahasa dan Automata A","Senin 10 - 13",11310,255000,3,3,"Marques","67001"},
    {"TC531B","Teori Bahasa dan Automata B","Senin 7 - 9",10907,255000,3,3,"Komeng","67002"},
    {"TC531C","Teori Bahasa dan Automata C","Selasa 13-15",21513,255000,3,3,"Sukiem","67003"},
    };
    matkul ASD[4]={
    {"TC534A","Algoritma dan Struktur Data  A","Senin 13 - 15",11513,255000,3,4,"Hamilton","67004"},
    {"TC534B","Algoritma dan Struktur Data  B","Senin 15 - 17",11715,255000,3,4,"Martin G","67005"},
    {"TC534C","Algoritma dan Struktur Data  C","Rabu 13 - 15",31513,255000,3,4,"Carl J","67006"},
    };
    matkul IMK[4]={
    {"TC535A","Interaksi Manusia & Komputer A","Kamis 7 - 9",40907,255000,3,4,"Gatau","67007"},
    {"TC535B","Interaksi Manusia & Komputer B","Kamis 9 - 11",41109,255000,3,4,"Big Smoke","67008"},
    {"TC535C","Interaksi Manusia & Komputer C","Kamis 13 - 15",41513,255000,3,4,"Maha Tau","67009"},
    };
    matkul SDP[4]={
    {"TC532A","Statistika dan Probabilitas A","Jumat 7 - 9",50907,255000,3,3,"Bang Joni","67010"},
    {"TC532B","Statistika dan Probabilitas B","Senin 7 - 9",10907,255000,3,3,"Budi Torpedo","67011"},
    {"TC532C","Statistika dan Probabilitas C","Selasa 10 - 12",21210,255000,3,3,"Jono Galon","67012"},
    };

  int pilihan=0;
  while(exits!=1){
  int j,matkulchecker=0;
  int pilihanmatkul = 0;

    int menu=1,pilihan;
    header(2);
    gotoxy(59,6);
    printf("REGISTRASI MATA KULIAH");
    do {
        if(menu == 1) {
            gotoxy(40,13);
            printf(">>  TC531 - TBO");
        } else {
            gotoxy(40,13);
            printf("    TC531 - TBO");
        }
        if(menu == 2) {
            gotoxy(40,14);
            printf(">>  TC532 - SDP");
        } else {
            gotoxy(40,14);
            printf("    TC532 - SDP");
        }
        if(menu == 3) {
            gotoxy(40,15);
            printf(">>  TC534 - ASD");
        } else {
            gotoxy(40,15);
            printf("    TC534 - ASD");
        }
        if(menu == 4) {
            gotoxy(40,16);
            printf(">>  TC534 - IMK");
        } else {
            gotoxy(40,16);
            printf("    TC534 - IMK");
        }
        if(menu == 5) {
            gotoxy(82,23);
            printf(">>  KEMBALI  <<\n");
        } else {
            gotoxy(82,23);
            printf("    KEMBALI    \n");
        }

        pilihan = getch();
        if(pilihan == 80) {
            menu++;
            if(menu > 5)
                menu = 1;
        }
        if(pilihan == 72) {
            menu--;
            if(menu < 1)
                menu = 5;
        }
    }while(pilihan != 27 && pilihan != 13);
    if(menu==5){
        exits=1;
    }
    if(siDia[ke].maxSKS<=21 && exit!=1){
      switch(menu){
        case 1:
          for(j=0;j<siDia[ke].banyakMatkul;j++){
            if((strncmp(siDia[ke].dataKST[j].kodematkul,TBO->kodematkul,5))==0){
              matkulchecker=1;
            }
            }
            if(matkulchecker!=1){
            jadwal(TBO);
            do {
                if(pilihanmatkul == 1) {
                    gotoxy(42-9, 11);
                    printf(">>");
                    gotoxy(106-2,11);
                    printf("<<");
                } else {
                    gotoxy(42-9, 11);
                    printf("  ");
                    gotoxy(106-2,11);
                    printf("  ");
                }
                if(pilihanmatkul == 2) {
                    gotoxy(42-9, 12);
                    printf(">>");
                    gotoxy(106-2,12);
                    printf("<<");
                } else {
                    gotoxy(42-9, 12);
                    printf("  ");
                    gotoxy(106-2,12);
                    printf("  ");
                }
                if(pilihanmatkul == 3) {
                    gotoxy(42-9, 13);
                    printf(">>");
                    gotoxy(106-2,13);
                    printf("<<");
                } else {
                    gotoxy(42-9, 13);
                    printf("  ");
                    gotoxy(106-2,13);
                    printf("  ");
                }
                if(pilihanmatkul == 4) {
                    gotoxy(82,23);
                    printf(">>  KEMBALI  <<\n");
                } else {
                    gotoxy(82,23);
                    printf("    KEMBALI    \n");
                }


                pilihan = getch();
                if(pilihan == 80) {
                    pilihanmatkul++;
                    if(pilihanmatkul > 4)
                        pilihanmatkul = 1;
                }
                if(pilihan == 72) {
                    pilihanmatkul--;
                    if(pilihanmatkul < 1)
                        pilihanmatkul = 4;
                }
            }while(pilihan != 27 && pilihan != 13);

          if(pilihanmatkul<4&&pilihanmatkul>0){
            siDia[ke].dataKST[siDia[ke].banyakMatkul]=TBO[pilihanmatkul-1];
            header(2);
            gotoxy(52,14);
            printf("MATA KULIAH BERHASIL DI AMBIL");
            getch();
            siDia[ke].banyakMatkul+=1;
            siDia[ke].maxSKS+=TBO->sksA;
            }
            }else{
                header(2);
                gotoxy(54,14);
                printf("MATA KULIAH SUDAH DI AMBIL");
                getch();
            }
          break;
        case 2:
          for(j=0;j<siDia[ke].banyakMatkul;j++){
            if((strncmp(siDia[ke].dataKST[j].kodematkul,SDP->kodematkul,5))==0){
              matkulchecker=1;
            }
            }
            if(matkulchecker!=1){
                jadwal(SDP);
            do {
                if(pilihanmatkul == 1) {
                    gotoxy(42-9, 11);
                    printf(">>");
                    gotoxy(106-2,11);
                    printf("<<");
                } else {
                    gotoxy(42-9, 11);
                    printf("  ");
                    gotoxy(106-2,11);
                    printf("  ");
                }
                if(pilihanmatkul == 2) {
                    gotoxy(42-9, 12);
                    printf(">>");
                    gotoxy(106-2,12);
                    printf("<<");
                } else {
                    gotoxy(42-9, 12);
                    printf("  ");
                    gotoxy(106-2,12);
                    printf("  ");
                }
                if(pilihanmatkul == 3) {
                    gotoxy(42-9, 13);
                    printf(">>");
                    gotoxy(106-2,13);
                    printf("<<");
                } else {
                    gotoxy(42-9, 13);
                    printf("  ");
                    gotoxy(106-2,13);
                    printf("  ");
                }
                if(pilihanmatkul == 4) {
                    gotoxy(82,23);
                    printf(">>  KEMBALI  <<\n");
                } else {
                    gotoxy(82,23);
                    printf("    KEMBALI    \n");
                }


                pilihan = getch();
                if(pilihan == 80) {
                    pilihanmatkul++;
                    if(pilihanmatkul > 4)
                        pilihanmatkul = 1;
                }
                if(pilihan == 72) {
                    pilihanmatkul--;
                    if(pilihanmatkul < 1)
                        pilihanmatkul = 4;
                }
            }while(pilihan != 27 && pilihan != 13);

          if(pilihanmatkul<4&&pilihanmatkul>0){
            siDia[ke].dataKST[siDia[ke].banyakMatkul]=SDP[pilihanmatkul-1];
            header(2);
            gotoxy(52,14);
            printf("MATA KULIAH BERHASIL DI AMBIL");
            getch();
            siDia[ke].banyakMatkul+=1;
            siDia[ke].maxSKS+=SDP->sksA;
            }
            } else {
                header(2);
                gotoxy(54,14);
                printf("MATA KULIAH SUDAH DI AMBIL");
                getch();
            }

          break;
        case 3:
          for(j=0;j<siDia[ke].banyakMatkul;j++){
            if((strncmp(siDia[ke].dataKST[j].kodematkul,ASD->kodematkul,5))==0){
              matkulchecker=1;
            }
            }
            if(matkulchecker!=1){
                jadwal(ASD);
            do {
                if(pilihanmatkul == 1) {
                    gotoxy(42-9, 11);
                    printf(">>");
                    gotoxy(106-2,11);
                    printf("<<");
                } else {
                    gotoxy(42-9, 11);
                    printf("  ");
                    gotoxy(106-2,11);
                    printf("  ");
                }
                if(pilihanmatkul == 2) {
                    gotoxy(42-9, 12);
                    printf(">>");
                    gotoxy(106-2,12);
                    printf("<<");
                } else {
                    gotoxy(42-9, 12);
                    printf("  ");
                    gotoxy(106-2,12);
                    printf("  ");
                }
                if(pilihanmatkul == 3) {
                    gotoxy(42-9, 13);
                    printf(">>");
                    gotoxy(106-2,13);
                    printf("<<");
                } else {
                    gotoxy(42-9, 13);
                    printf("  ");
                    gotoxy(106-2,13);
                    printf("  ");
                }
                if(pilihanmatkul == 4) {
                    gotoxy(82,23);
                    printf(">>  KEMBALI  <<\n");
                } else {
                    gotoxy(82,23);
                    printf("    KEMBALI    \n");
                }


                pilihan = getch();
                if(pilihan == 80) {
                    pilihanmatkul++;
                    if(pilihanmatkul > 4)
                        pilihanmatkul = 1;
                }
                if(pilihan == 72) {
                    pilihanmatkul--;
                    if(pilihanmatkul < 1)
                        pilihanmatkul = 4;
                }
            }while(pilihan != 27 && pilihan != 13);

          if(pilihanmatkul<4&&pilihanmatkul>0){
            siDia[ke].dataKST[siDia[ke].banyakMatkul]=ASD[pilihanmatkul-1];
            header(2);
            gotoxy(52,14);
            printf("MATA KULIAH BERHASIL DI AMBIL");
            getch();
            siDia[ke].banyakMatkul+=1;
            siDia[ke].maxSKS+=ASD->sksA;
          }
            } else {
                header(2);
                gotoxy(54,14);
                printf("MATA KULIAH SUDAH DI AMBIL");
                getch();
            }
          break;
        case 4:
          for(j=0;j<siDia[ke].banyakMatkul;j++){
            if((strncmp(siDia[ke].dataKST[j].kodematkul,IMK->kodematkul,5))==0){
              matkulchecker=1;
            }
            }
            if(matkulchecker!=1){
                jadwal(IMK);
            do {
                if(pilihanmatkul == 1) {
                    gotoxy(42-9, 11);
                    printf(">>");
                    gotoxy(106-2,11);
                    printf("<<");
                } else {
                    gotoxy(42-9, 11);
                    printf("  ");
                    gotoxy(106-2,11);
                    printf("  ");
                }
                if(pilihanmatkul == 2) {
                    gotoxy(42-9, 12);
                    printf(">>");
                    gotoxy(106-2,12);
                    printf("<<");
                } else {
                    gotoxy(42-9, 12);
                    printf("  ");
                    gotoxy(106-2,12);
                    printf("  ");
                }
                if(pilihanmatkul == 3) {
                    gotoxy(42-9, 13);
                    printf(">>");
                    gotoxy(106-2,13);
                    printf("<<");
                } else {
                    gotoxy(42-9, 13);
                    printf("  ");
                    gotoxy(106-2,13);
                    printf("  ");
                }
                if(pilihanmatkul == 4) {
                    gotoxy(82,23);
                    printf(">>  KEMBALI  <<\n");
                } else {
                    gotoxy(82,23);
                    printf("    KEMBALI    \n");
                }


                pilihan = getch();
                if(pilihan == 80) {
                    pilihanmatkul++;
                    if(pilihanmatkul > 4)
                        pilihanmatkul = 1;
                }
                if(pilihan == 72) {
                    pilihanmatkul--;
                    if(pilihanmatkul < 1)
                        pilihanmatkul = 4;
                }
            }while(pilihan != 27 && pilihan != 13);

          if(pilihanmatkul<4&&pilihanmatkul>0){
            siDia[ke].dataKST[siDia[ke].banyakMatkul]=IMK[pilihanmatkul-1];
            header(2);
            gotoxy(52,14);
            printf("MATA KULIAH BERHASIL DI AMBIL");
            getch();
            siDia[ke].banyakMatkul+=1;
            siDia[ke].maxSKS+=IMK->sksA;
          }
            } else {
                header(2);
                gotoxy(54,14);
                printf("MATA KULIAH SUDAH DI AMBIL");
                getch();
            }
        default:
          printf("gaad");
          break;
          }
    }
    else {
      printf("SKS TELAH MENCAPAI BATAS MAKSIMAL");
      getch();
    }
  }
}

void keaktifanMahasiswa() {
    char kegiatan[10][50];
    int points[10];
    int n = 0;
    int choice, menu = 1;
    do {
        system("cls");
        gotoxy(38, 2);
        printf("SIASAT UKSW");
        time_t t;
        time(&t);
        gotoxy(74, 2);
        printf("%s", ctime(&t));
        gotoxy(38, 3);
        for (int j = 0; j < 60; j++) {
            printf("%c", 205);
        }
        gotoxy(57, 5);
        printf("KEAKTIFAN MAHASISWA");
        gotoxy(38, 7);
        for (int j = 0; j < 60; j++) {
            printf("%c", 205);
        }
        gotoxy(38, 20);
        for (int j = 0; j < 60; j++) {
            printf("%c", 205);
        }

        if (menu == 1) {
            gotoxy(40, 10);
            printf(">> Input Kegiatan");
        } else {
            gotoxy(40, 10);
            printf("   Input Kegiatan");
        }
        if (menu == 2) {
            gotoxy(40, 11);
            printf(">> Lihat Point");
        } else {
            gotoxy(40, 11);
            printf("   Lihat Point");
        }
        if (menu == 3) {
            gotoxy(40, 12);
            printf(">> Kembali");
        } else {
            gotoxy(40, 12);
            printf("   Kembali");
        }

        choice = getch();
        if (choice == 80) {
            menu++;
            if (menu > 3)
                menu = 1;
        }
        if (choice == 72) {
            menu--;
            if (menu < 1)
                menu = 3;
        }
        if (choice == 13) {
            if (menu == 1) {
                if (n < 10) {
                    gotoxy(40, 15);
                    printf("Masukkan Nama Kegiatan: ");
                    gotoxy(40, 16);
                    scanf(" %[^\n]s", kegiatan[n]);
                    gotoxy(40, 17);
                    printf("Masukkan Point: ");
                    gotoxy(40, 18);
                    scanf("%d", &points[n]);
                    n++;
                } else {
                    gotoxy(40, 15);
                    printf("Maksimal 10 kegiatan tercapai!");
                    getch();
                }
            } else if (menu == 2) {
                for (int i = 0; i < n - 1; i++) {
                    for (int j = 0; j < n - i - 1; j++) {
                        if (points[j] < points[j + 1]) {
                            int tempPoint = points[j];
                            points[j] = points[j + 1];
                            points[j + 1] = tempPoint;
                            char tempKegiatan[50];
                            strcpy(tempKegiatan, kegiatan[j]);
                            strcpy(kegiatan[j], kegiatan[j + 1]);
                            strcpy(kegiatan[j + 1], tempKegiatan);
                        }
                    }
                }
                system("cls");
                gotoxy(38, 2);
                printf("SIASAT UKSW");
                time_t t;
                time(&t);
                gotoxy(74, 2);
                printf("%s", ctime(&t));
                gotoxy(38, 3);
                for (int j = 0; j < 60; j++) {
                    printf("%c", 205);
                }
                gotoxy(50, 5);
                printf("DAFTAR KEGIATAN DAN POINT");
                gotoxy(38, 7);
                for (int j = 0; j < 60; j++) {
                    printf("%c", 205);
                }
                gotoxy(38, 20);
                for (int j = 0; j < 60; j++) {
                    printf("%c", 205);
                }
                for (int i = 0; i < n; i++) {
                    gotoxy(40, 10 + i);
                    printf("%d. %s - %d point", i + 1, kegiatan[i], points[i]);
                }
                getch();
            }
        }
    } while (!(menu == 3 && choice == 13));
}

void kst() {
    int v=1;
        if(siDia[ke].banyakMatkul>0){
            header(2);
            gotoxy(62, 6);
            printf("KARTU STUDI");
            gotoxy(40-10, 10);
            printf("NO");
            gotoxy(44-8, 10);
            printf("KODE");
            gotoxy(56-4, 10);
            printf("MATA KULIAH");
            gotoxy(88-10, 10);
            printf("SKS A");
            gotoxy(94-10, 10);
            printf("SKS B");
            gotoxy(106-10, 10);
            printf("KETERANGAN");

            for (int i = 0; i < siDia[ke].banyakMatkul; i++) {
                    gotoxy(40-10, 11+i);
                    printf("0%i",i+1);
                    gotoxy(42-7, 11+i);
                        printf("%s",siDia[ke].dataKST[i].kodematkul);
                    gotoxy(50-6, 11+i);
                       printf("%s",siDia[ke].dataKST[i].namamatkul);
                    gotoxy(88-8, 11+i);
                       printf("%i",siDia[ke].dataKST[i].sksA);
                    gotoxy(94-8, 11+i);
                       printf("%i",siDia[ke].dataKST[i].sksB);
                    gotoxy(101-6, 11+i);
                       printf("%s",siDia[ke].dataKST[i].jadwalmatkul);
            }
        }else{
            header(2);
            gotoxy(62, 6);
            printf("KARTU STUDI");
            gotoxy(44,14);
            printf("SILAHKAN REGISTRASI MATA KULIAH TERLEBIH DAHULU!");
            getch();
            v=0;
        }

        int menu=1;
        int pilihan;
        if(v!=0){
            do {
                if(menu==1) {
                    gotoxy(82, 23);
                    printf(">>  KEMBALI  <<");
                }else {
                        gotoxy(82,23);
                        printf("    KEMBALI    ");
                }
                if(menu==2) {
                    gotoxy(40, 23);
                    printf(">>  HAPUS  <<\n");
                }else {
                        gotoxy(40,23);
                        printf("    HAPUS    \n");
                }

                    pilihan=getch();
                    if(pilihan==80){
                        menu++;
                        if(menu>2)
                        menu=1;
                    }
                    if(pilihan==72){
                        menu--;
                        if(menu<1)
                        menu=2;
                    }
                if (pilihan == 13 && menu == 2) {
                    int pilih;
                    if (siDia[ke].banyakMatkul > 0) {
                        gotoxy(45, 25);
                        printf("Pilih nomor mata kuliah yang ingin dihapus: ");
                        scanf("%d", &pilih);

                        if (pilih >= 1 && pilih<= siDia[ke].banyakMatkul) {
                            for (int j = pilih - 1; j < siDia[ke].banyakMatkul - 1; j++) {
                                siDia[ke].dataKST[j] = siDia[ke].dataKST[j + 1];
                            }
                            siDia[ke].banyakMatkul--;
                        }
                    }
                gotoxy(40, 25);
                printf("                                                  ");
                }
            }while (pilihan != 27 && pilihan != 13 );
        }
}

void header(int y){
    time_t t;
    time(&t);

    system("cls");
    gotoxy(38,2);
    printf("SIASAT UKSW");
    gotoxy(74,2);
    printf("%s",ctime(&t));
    gotoxy(38,3);
    for (int j = 0; j < 60; j++) {
        printf("%c", 205);
    }
    gotoxy(38,7+y);
    for (int j = 0; j < 60; j++) {
        printf("%c", 205);
    }
    gotoxy(38,19+y);
    for (int j = 0; j < 60; j++) {
        printf("%c", 205);
    }
}

int login (){
    char user[32];
    char pw[32];
    char ch;
    int valid=0;


    header(0);
    gotoxy(53,5);
    printf("SELAMAT DATANG DI SIASAT UKSW");
    gotoxy(53,10);
    printf("NIM :");
    gotoxy(53,12);
    for (int j = 0; j < 12; j++) {
        printf("%c", 238);
    }
    gotoxy(53,14);
    printf("PASSWORD :");
    gotoxy(53,16);
    for (int j = 0; j < 22; j++) {
        printf("%c", 238);
    }
    do{
        gotoxy(53,11);
        scanf(" %[^\n]s",&user);
        for (int i = 0; i < 6; i++) {
            if (strcmp(siDia[i].nim, user) == 0) {
                ke=i;
                valid=1;
            }
        }
            if(valid==0){
                gotoxy(53,11);
                printf("                            ");
                gotoxy(58,8);
                printf("NIM TIDAK TERDAFTAR");
            }
    }while(valid==0);
    gotoxy(58,8);
    printf("                                ");
    do{
        int i=0;
        gotoxy(53,15);
        valid=0;
        while (1) {
            ch = getch();

            if (ch == 13 || ch == 10) {
                pw[i] = '\0';
                break;
            } else if (ch == 8 && i > 0) {
                printf("\b \b");
                i--;
            } else if (i < MAX_PANJANG - 1) {
                pw[i] = ch;
                printf("*");
                i++;
            }
        }
        if (strcmp(siDia[ke].pw, pw) == 0) {
                valid=1;
        }
        if(valid==0){
            gotoxy(53,15);
            printf("                            ");
            gotoxy(58,8);
            printf("PASSWORD ANDA SALAH");
        }
    }while(valid==0);
    return;
}

void gantipw (){
    char pwscan[32];
    char pwbaru[32];
    int v=0;

    header(0);
    gotoxy(56,5);
    printf("GANTI PASSWORD SIASAT");
    do{
        gotoxy(54,10);
        printf("PASSWORD LAMA :");
        gotoxy(54,11);
        for (int j = 0; j < 22; j++) {
            printf(" ");
            }
        gotoxy(54,12);
        for (int j = 0; j < 22; j++) {
            printf("%c", 238);
        }
        gotoxy(54,14);
        printf("PASSWORD BARU :");
            gotoxy(54,15);
        for (int j = 0; j < 22; j++) {
            printf(" ");
        }
        gotoxy(54,16);
        for (int j = 0; j < 22; j++) {
            printf("%c", 238);
        }
        gotoxy(54,11);
        scanf(" %[^\n]s",&pwscan);
        gotoxy(54,15);
        scanf(" %[^\n]s",&pwbaru);
        if(strcmp(pwscan,siDia[ke].pw)!= 0){
            gotoxy(57,8);
            printf("PASSWORD ANDA SALAH");
        } else {
            strcpy(siDia[ke].pw,pwbaru);
            v=1;
        }
    }while(v==0);
}

void loading(){
    system("cls");
    for(int i=0; i<=60; i++){
        gotoxy(38+i,3);
        printf("%c",205);
        gotoxy(62,5);
        printf("TUNGGU SEK COY...");
        gotoxy(38+i,7);
        printf("%c",205);
        Sleep(10);
    }
    Sleep(1000);
}

void cuti(){
    int menu=1,pilihan;
    header(3);
    gotoxy(40,5);
    printf("%s - %s",siDia[ke].nim,siDia[ke].nama);
    gotoxy(40,6);
    printf("FAKULTAS TEKNOLOGI INFORMASI - S1 TEKNIK INFORMATIKA");
    gotoxy(40,7);
    printf("SEMESTER 3 TA 2023 - 2024");
    gotoxy(40,8);
    printf("SKS TERSEDIA %i/20 SKS",siDia[ke].maxSKS);
    gotoxy(50,15);
    printf("ANDA BELUM MELAKUKAN REGISTRASI ULANG");
    do {
        if(menu == 1) {
            gotoxy(82,23);
            printf(">>  KEMBALI  <<\n");
        } else {
            gotoxy(82,23);
            printf("    KEMBALI    \n");
        }

        pilihan = getch();
        if(pilihan == 80) {
            menu++;
            if(menu > 2)
                menu = 1;
        }
        if(pilihan == 72) {
            menu--;
            if(menu < 1)
                menu = 2;
        }
    }while(pilihan != 27 && pilihan != 13);
}

void tagihan(){
    siDia[ke].total_tagihan=siDia[ke].maxSKS*250000;
    time_t t;
    time(&t);
    int exit=0,btnpos=0;
    char key;
    system("cls");
    while(exit!=1){
    gotoxy(38,2);
    printf("SIASAT UKSW");
    gotoxy(74,2);
    printf("%s",ctime(&t));
    gotoxy(38,3);
    for (int j = 0; j < 60; j++) {
        printf("%c", 205);
    }
    gotoxy(40,5);
    printf("%s - %s",siDia[ke].nim,siDia[ke].nama);
    gotoxy(40,6);
    printf("FAKULTAS TEKNOLOGI INFORMASI - S1 TEKNIK INFORMATIKA");
    gotoxy(40,7);
    printf("SEMESTER 3 TA 2023 - 2024");
    gotoxy(40,8);
    printf("SKS TERSEDIA %i/20 SKS",siDia[ke].maxSKS);
    gotoxy(38,10);
    for (int j = 0; j < 60; j++) {
        printf("%c", 205);
    }
    gotoxy(54,11);
    printf("TAGIHAN KEWAJIBAN PEMBAYARAN");
    gotoxy(40,13);
    printf("NO");
    gotoxy(40,14);
    printf("1. UANG KULIAH");

    gotoxy(40,15);
    printf("2. DENDA");
    gotoxy(40,16);
    printf("3. SPP / BPP");
    gotoxy(43,17);
    printf("TOTAL UTANG");
    gotoxy(43,18);
    printf("TERBAYAR");
    gotoxy(43,19);
    printf("YANG HARUS DI BAYAR");
    gotoxy(63,13);
    printf("ITEMS");
    gotoxy(86,13);
    printf("JUMLAH");
    gotoxy(86,14);
    FormatIDRcoi(siDia[ke].total_tagihan);
    gotoxy(86,15);
    printf("Rp.0");
    gotoxy(86,16);
    printf("Rp.1,500,000");
    gotoxy(86,17);
    FormatIDRcoi(siDia[ke].total_tagihan+1500000);
    gotoxy(86,18);
    printf("Rp.0");
    gotoxy(86,19);
    FormatIDRcoi(siDia[ke].total_tagihan+1500000);
    gotoxy(38,28);

    for (int j = 0; j < 60; j++) {
        printf("%c", 205);
    }
    gotoxy(42,26);
    printf("CETAK TAGIHAN");
    gotoxy(40,29);
    printf("KEMBALI");
    gotoxy(86,29);
    printf("MENU UTAMA");
    do{
        if(btnpos==0){
            gotoxy(38,29);
            printf(">>");
            gotoxy(47,29);
            printf("<<");
        } else {
            gotoxy(38,29);
            printf("  ");
            gotoxy(47,29);
            printf("  ");
        }
        if(btnpos==1){
            gotoxy(40,26);
            printf(">>");
            gotoxy(55,26);
            printf("<<");
        } else {
            gotoxy(40,26);
            printf("  ");
            gotoxy(55,26);
            printf("  ");
        }
        if(btnpos==2){
            gotoxy(84,29);
            printf(">>\n");
            gotoxy(96,29);
            printf("<<\n");
        } else {
            gotoxy(84,29);
            printf("  \n");
            gotoxy(96,29);
            printf("  \n");
        }
        key=getch();
        if(key==72){
            btnpos+=1;
            if(btnpos>2){
                btnpos=0;
            }
        }
        if(key==80){
            btnpos-=1;
            if(btnpos<0){
                btnpos=2;
            }
        }
    }while(key != 27 && key != 13);
    if(btnpos==2){
        exit=1;
    }
    if(btnpos==1&&key=='\r'&&exit!=1){
        loading();
        char nama_kst[20];
        sprintf(nama_kst,"KST_%s.txt",siDia[ke].nim);
        FILE *fp = fopen(nama_kst,"w");
        fprintf(fp,"===============================\n"
                   "=      TAGIHAN - %s      =\n"
                   "===============================\n"
                   " 1. Uang Kuliah :   Rp.%d\n"
                   " 2. Denda       :   Rp.0\n"
                   " 3. SPP         :   Rp.1500000\n"
                   " 4. Total       :   Rp.%d\n"
                   "===============================",siDia[ke].nim,siDia[ke].total_tagihan,siDia[ke].total_tagihan+1500000);
        fclose(fp);
        header(2);
        gotoxy(54,14);
        printf("TAGIHAN BERHASIL DI CETAK");
        getch();
        exit=1;
    }
    system("cls");
    }
}

int main(){
    int menu=0,pilihan;
    int tempSKS;
    int exit=0;

    loading();
    login();
    do{
        header(3);
        gotoxy(40,5);
        printf("%s - %s",siDia[ke].nim,siDia[ke].nama);
        gotoxy(40,6);
        printf("FAKULTAS TEKNOLOGI INFORMASI - S1 TEKNIK INFORMATIKA");
        gotoxy(40,7);
        printf("SEMESTER 3 TA 2023 - 2024");
        gotoxy(40,8);
        printf("SKS TERSEDIA %i/20 SKS",siDia[ke].maxSKS);
        do{
            if(menu==1) {
                gotoxy(40,12);
                printf(">>  REGISTRASI ULANG");
            }else {
                gotoxy(40,12);
                printf("    REGISTRASI ULANG");
            }
            if(menu==2) {
                gotoxy(40,13);
                printf(">>  REGISTRASI MATA KULIAH");
            }else {
                gotoxy(40,13);
                printf("    REGISTRASI MATA KULIAH");
            }
            if(menu==3) {
                gotoxy(40,14);
                printf(">>  KARTU STUDI");
            }else {
                gotoxy(40,14);
                printf("    KARTU STUDI");
            }
            if(menu==4) {
                gotoxy(40,15);
                printf(">>  TAGIHAN");
            }else {
                gotoxy(40,15);
                printf("    TAGIHAN");
            }
            if(menu==5) {
                gotoxy(40,16);
                printf(">>  KEAKTIFAN MAHASISWA");
            }else {
                gotoxy(40,16);
                printf("    KEAKTIFAN MAHASISWA");
            }
            if(menu==6) {
                gotoxy(40,17);
                printf(">>  GANTI PASSWORD");
            }else {
                gotoxy(40,17);
                printf("    GANTI PASSWORD");
            }
            if(menu==7) {
                gotoxy(82,23);
                printf(">>  LOGOUT  <<\n");
            }else {
                gotoxy(82,23);
                printf("    LOGOUT    \n");
            }

            pilihan=getch();
            if(pilihan==80){
                menu++;
                if(menu>7)
                menu=1;
            }
            if(pilihan==72){
                menu--;
                if(menu<1)
                menu=7;
            }
        }while(pilihan==27 || pilihan!='\r' );

        switch(menu) {
            case 1:
                registrasiulang();
                break;
            case 2:
                if(kuliah==1){
                regismatkul();
                }else{
                    cuti();
                }
                break;
            case 3:
                if(kuliah==1){
                    kst();
                }else{
                    cuti();
                }
                break;
            case 4:
                if(kuliah==1){
                    tagihan();
                }else{
                    cuti();
                }
                break;
            case 5:
                if(kuliah==1){
                    keaktifanMahasiswa();
                }else{
                    cuti();
                }
                break;
            case 6:
                gantipw();
                loading();
                break;
            case 7:
                main();
                break;
            default:
        }
    }while(exit==0);
}

