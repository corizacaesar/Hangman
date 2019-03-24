#include<iostream>
#include<cstdlib>
#include<iomanip>
#include <ctime>
#include<conio.h>
using namespace std;

typedef char infotype;
typedef struct TElmt *address;
typedef struct TElmt{
	infotype info;
	address next;
} Elmt;

struct List{
	address first;
};
#define First(L) (L).first
#define Next(P) (P)->next
#define Info(P)(P)->info
#define Nil NULL

void CreateEmpty(List *L){
	(*L).first=NULL;
}
bool IsEmpty(List L){
	return ((L).first==NULL);
}
address Allocation(infotype x){
	address NewElmt;
	
	NewElmt = (Elmt*) malloc(sizeof(Elmt));
	NewElmt->info = x;
	NewElmt->next = NULL;
	
	return NewElmt;
}
void Deallocation(address hapus){
	free(hapus);
}
void InsertFirst(List *L, infotype x){
	address NewElmt;
	NewElmt = Allocation(x);
	
	if(NewElmt != NULL){
		if(IsEmpty(*L)){
			(*L).first = NewElmt;
		}
		else{
			NewElmt->next = (*L).first;
			(*L).first = NewElmt;
		}
	}
}
void InsertAfter(address *PredElmt, infotype x){
	address NewElmt;
	NewElmt = Allocation(x);
	
	if(NewElmt != NULL){
		NewElmt->next = (*PredElmt)->next;
		(*PredElmt)->next=NewElmt;
	}
}
void InsertLast(List *L, infotype x){
	if (IsEmpty(*L)) InsertFirst(&(*L), x);
	else {
		address temp;
		temp = (*L).first;
		
		while(temp->next!=NULL) temp = temp->next;
		
		InsertAfter(&temp, x);
	}
}

void DeleteFirst(List *L, infotype *hapus){
	if(!IsEmpty(*L)){
		address temp;
		temp = (*L).first;
		*hapus = temp->info;
		(*L).first = (*L).first->next;
		temp->next = NULL;
		Deallocation(temp);
	}
}

void DeleteAfter(address pred, infotype *hapus){
	if(pred->next != NULL){
		address temp;
		temp = pred->next;
		*hapus = temp->info;
		pred->next = temp->next;
		temp->next = NULL;
		Deallocation(temp);
	}
}

void DeleteLast(List (*L), infotype *hapus){
	if(!IsEmpty(*L)){
		address temp, predTemp;
		predTemp = NULL;
		temp = (*L).first;
		while(temp->next != (*L).first){
			predTemp = temp;
			temp = temp->next;
		}
		
		if(temp == (*L).first) DeleteFirst(&(*L), &(*hapus));
		else DeleteAfter(predTemp, &(*hapus));
	}
}

//Menampilkan Isi List
void Output(List L){
	

	if(!IsEmpty(L)){
		address temp =First(L);
		while(Next(temp)!=NULL){
			cout<<Info(temp) <<" ";
			temp = Next(temp);
		}
		cout<<Info(temp);
	}
}

//Tempat Menaruh Huruf tebakan yang salah
void cek(List *L3, char x){
     bool bantu=0;
     if(!IsEmpty(*L3)){
		address P =First(*L3);
		while(P!=NULL){
           if(Info(P)==x){
                 bantu=1;
                 break;
            }  
            P=Next(P);    
		}
        if(bantu==0){
           InsertLast(L3,x);
        } 
    }else{
          InsertFirst(L3,x);
    }
}

//Cek Jika yang dimasukkan satu huruf
void CekMasuk(List L1, List *L2, string x, int *m){
	char a=x[0];
	address P1=First(L1), P2=First(*L2);
	while(Next(P1)!=NULL){
			if(Info(P1)==a){
				Info(P2)=a;
				*m=1;
			}
			P1 = Next(P1);
			P2 = Next(P2);
		}
		if(Info(P1)==a){
		Info(P2)=a;
		*m=1;
		}
}

//Cek yang dimasukkan sesuai dengan jumlah Hurud?
void CekMasukTotal(List L1, List *L2, string x, int *z,int m){
	address P1=First(L1), P2=First(*L2);
	int i=0,j=0;
	*z=1;
	do{
		if(Info(P1)==x[i]){
			j++;
		}
		
	P1=Next(P1);
	i++;	
	}while(i<x.length());
	if(j!=i){
		*z=0;
	}else{	
		*z=1;
	}
}

//Cek Apakah Tertebak Semua?
bool cekmenang(List L1,List L2){
	address P1=First(L1), P2=First(L2);
	while(Next(P1)!=NULL){
			if(Info(P1)!=Info(P2)){
				return false;
			}
			P1 = Next(P1);
			P2 = Next(P2);
		}
		if(Info(P1)!=Info(P2)){
				return false;
		}return true;
}

//Menghapus Semua Isis List
void DeleteAll(List *L1, List *L2, List *L3){
    char temp; 
    while(!IsEmpty(*L1)){
         DeleteFirst(L1,&temp);
    } 
    while(!IsEmpty(*L2)){
         DeleteFirst(L2,&temp);
    }
    while(!IsEmpty(*L3)){
         DeleteFirst(L3,&temp);
    }       
               
}

//Untuk Delay
void delay(){
     int delay=1;
     while(delay<100000000){
     delay++;
     }
}

//Part Bentuk Orang
void orang(int k){
     if(k==3){
              cout<<"\t\t\t\t\t           _____         \n";
              cout<<"\t\t\t\t\t         ( *   * )       \n";
              cout<<"\t\t\t\t\t         |   ^   |       \n";
              cout<<"\t\t\t\t\t         (  ___  )       \n";
              cout<<"\t\t\t\t\t          (_____)        \n";
     }
     if(k==2){
              orang(3);
              cout<<"\t\t\t\t\t        ____| |____         \n";
              cout<<"\t\t\t\t\t      /|           |\\      \n";
              cout<<"\t\t\t\t\t     / /           \\ \\    \n";
              cout<<"\t\t\t\t\t   _/ /|           |\\ \\_  \n";
              cout<<"\t\t\t\t\t  {__/ |___________| \\__}  \n";
     }
     if(k==1){
              orang(2);
              cout<<"\t\t\t\t\t       _|####@####|_       \n";
              cout<<"\t\t\t\t\t      |             |      \n";
              cout<<"\t\t\t\t\t      |  _________  |      \n";
              cout<<"\t\t\t\t\t     /  /         \\ \\    \n";
              cout<<"\t\t\t\t\t    |  |          |  |     \n";
              cout<<"\t\t\t\t\t    |  |          |  |     \n";
              cout<<"\t\t\t\t\t   {___|          |___}    \n";
     }
     if(k==0){
              cout<<"\t\t\t\t\t   ___________        \n";
              cout<<"\t\t\t\t\t  |  _______  |       \n";
              cout<<"\t\t\t\t\t  | |       | |       \n";
              cout<<"\t\t\t\t\t  | |       | /       \n";
              cout<<"\t\t\t\t\t  | |       |/        \n";
              orang(1);
     }
     if(k==-1){
               system("COLOR 04");
              cout<<"\t\t\t\t\t         ___________      \n";
              cout<<"\t\t\t\t\t        (           )     \n";
              cout<<"\t\t\t\t\t       (   ##   ##   )       \n";
              cout<<"\t\t\t\t\t      (               )      \n";
              cout<<"\t\t\t\t\t      (               )      \n";
              cout<<"\t\t\t\t\t      (       ^       )       \n";
              cout<<"\t\t\t\t\t      (               )        \n";
              cout<<"\t\t\t\t\t       (     ___     )       \n";
              cout<<"\t\t\t\t\t        (           )       \n";
              cout<<"\t\t\t\t\t         (_________)        \n";
     }
}

//Tulisan Hangman for Opening
void hangman(){
     cout<<"    ______________________________________________________________________________________________________   \n";
     cout<<"   | ___________________________________________________________________________________________________  |  \n";
     cout<<"  |  |__      __      _____      __       ___  ____________  __         __      _____      __       ___ |  |  \n"; 
     cout<<" |  ||  |    |  |    |  _  |    |  |     /   ||    ________||  \\       /  |    |  _  |    |  |     /   | |  |  \n"; 
     cout<<" |  ||  |    |  |   |  | |  |   |  |    / /  ||   |         |   \\     /   |   |  | |  |   |  |    / /  | |  |  \n"; 
     cout<<" |  ||  |____|  |  |  |___|  |  |  |   / /   ||   |  ______ |  \\ \\   / /  |  |  |___|  |  |  |   / /|  | |  |  \n"; 
     cout<<" |  ||   ____   | |  _______  | |  |  / /|   ||   | |___   ||  |\\ \\_/ /|  | |  _______  | |  |  / / |  | |  |  \n"; 
     cout<<" |  ||  |    |  ||  |       |  ||  | / / |   ||   |_____|  ||  | \\___/ |  ||  |       |  ||  | / /  |  | |  |  \n"; 
     cout<<" |  ||  |    |  ||  |       |  ||  |/ /  |   ||            ||  |       |  ||  |       |  ||  |/ /   |  | |  |  \n"; 
     cout<<" |  ||__|    |__||__|       |__||____/   |___||____________||__|       |__||__|       |__||____/    |__| |  |  \n"; 
     cout<<"  |  |__________________________________________________________________________________________________|  |  \n";
     cout<<"   |______________________________________________________________________________________________________|  \n";
}

//Opening
void opening(){
     for(int j=3; j>=1; j--){
             orang(j);
             delay();
             system("cls");
     }
	 for(int i=0; i>=-1; i--){
	 orang(i);
     delay();delay();delay(); system("cls");
 	}
     for(int i=0; i<3; i++){
     if(i==0){
              system("COLOR 9");
     }
     if(i==1){
              system("COLOR A");
     }
     if(i==2){
              system("COLOR B");
     }
     hangman();
     delay();
     system("cls");
     }
}
//Start Game Custom
void player(){
	system("COLOR 7");
     List L1,L2,L3;
    CreateEmpty(&L1);
	CreateEmpty(&L2);
	CreateEmpty(&L3);
     string hangman, masuk,a[2],main;
     int sum=0, x=rand(),scoreA=0,scoreB=0,round=0;
     system("cls");
 
     cout<<"Masukkan Nama Player 1\n"; cin>>a[0];
     cout<<"Masukkan Nama Player 2\n"; cin>>a[1];
     system("cls");
     while((scoreA-scoreB)!=2 && (scoreB-scoreA)!=2){
     	system("COLOR 7");
                     round++;//Agar Yang Memberi Soal dan yang Menjawab Bergantian
                     
                     //Merandom yang menebak dahulu
                     if(round%2==1){
                          cout<<a[0]<<" Memasukkan kata yang akan ditebak oleh "<<a[1]<<endl;
                     }else{
                          cout<<a[1]<<" Memasukkan kata yang akan ditebak oleh "<<a[0]<<endl;
                    }
                    cin>>hangman;
                    getch();
                    system("cls");
                    for (int l=0; l< hangman.length(); l++){
           					hangman[l] = toupper(hangman[l]);		
					}
                    sum++;
                    int z=0;
					int k=4;
					for(int i=0; i<hangman.length(); i++){
						InsertLast(&L1,hangman[i]);
					}
					for(int i=0; i<hangman.length(); i++){
						InsertLast(&L2,'#');
					}
					
					while(k>0){
						printx :
                               cout<<"Anda Berada Di Permainan Ke-"<<sum<<endl<<endl;
						cout<<"\t\t\tHuruf yang salah : ";Output(L3);
						cout<<endl<<endl;
					Output(L2);cout<<"\t\tKesempatan : "<<k<<endl;
                    orang(k);
					int m=0;
					cin>>masuk;
					for (int l=0; l< masuk.length(); l++){
                        	 masuk[l] = toupper(masuk[l]);
					}
					if(k==1){
						while(masuk.length()!=hangman.length()){
						m=1;
						system("cls");
						goto printx;
						cin>>masuk;
						}CekMasukTotal(L1,&L2,masuk,&z,m);
					
					}else{
					if(masuk.length()==1){
						CekMasuk(L1,&L2,masuk,&m);
					}else if(masuk.length()==hangman.length()){
						m=1;
						CekMasukTotal(L1,&L2,masuk,&z,m);
					}else{
                          k++;
						m=1;
					}
					}
					if(cekmenang(L1,L2)==true){
						z=1;
					}
					k--;
					system("cls");
					if(m==0){
						cek(&L3,masuk[0]);
					}
					if(z==1){
					break;
					getch();
					system ("cls"); 
					}
					}
					if(z==1){
						cout<<hangman;
					}else{
						Output(L2);
					}
					cout<<"\nJawaban yang benar adalah : ";
					cout<<hangman;
					DeleteAll(&L1,&L2,&L3);
					if(z==1){
					cout<<"\n\nANDA BENAR\n";
					orang(1);
					if(round%2!=1){
                          scoreA++;
                     }else{
                          scoreB++;
                    }getch();
					system("cls");
					}else{
						cout<<endl;
						orang(0);
						delay();delay();delay(); system("cls");
					cout<<"ANDA SALAH\n";
					orang(-1);
					if(round%2==1){
                          scoreA++;
                     }else{
                          scoreB++;
                    }getch();
					system("cls");
					}
					cout<<"score "<<a[0]<<" "<<scoreA<<endl;
					cout<<"score "<<a[1]<<" "<<scoreB<<endl;
					system("PAUSE");
					system("cls");
					
     }
     if(scoreA-scoreB==2){
     	cout<<"Pemenangnya adalah "<<a[0]<<endl<<endl;
	 }else{
	 	cout<<"Pemenangnya adalah "<<a[1]<<endl<<endl;
	 }
	 cout<<"Main lagi? (Y/N)"<<endl;
	 cin>>main;
	 if(main=="y" || main=="Y"){
	 	player();
	 }
	 getch();
	 system("cls");
}

//Start Game Classic
void startgame(int *sum){
     List L1,L2,L3,L4;
    CreateEmpty(&L1);
	CreateEmpty(&L2);
	CreateEmpty(&L3);
	CreateEmpty(&L4);
     string hangman, masuk;
     string A[20]={"IKANCUPANG","KUCING","KALAJENGKING","KAMBING","ANJING","DUGONG","DINOSAURUS","IKANBETOK","PAUS","BERUANG","PLATIPUS","TRENGGILING","TOKEK","KURA-KURA","KERA","PENYU","UBUR-UBUR","KATAK","AYAM","MONYET"};
     int testcase=20;
			system("cls");
                    int x=rand();
					hangman = A[x%testcase];
					*sum=*sum+1;
					int z=0;
					int k=4;
					for(int i=0; i<hangman.length(); i++){
						InsertLast(&L1,hangman[i]);
					}
					for(int i=0; i<hangman.length(); i++){
						InsertLast(&L2,'#');
					}
					
					while(k>0){
						print:
                               cout<<"Anda Berada Di Permainan Ke-"<<*sum<<endl<<endl;
						cout<<"\t\t\tHuruf yang salah : ";Output(L3);
						cout<<endl<<endl;
					Output(L2);cout<<"\t\tKesempatan : "<<k<<endl;
                    orang(k);
					int m=0;
					cin>>masuk;
					for (int l=0; l< masuk.length(); l++){
                        	 masuk[l] = toupper(masuk[l]);
					}
					if(k==1){
						while(masuk.length()!=hangman.length()){
						m=1;
						system("cls");
						goto print;
						cin>>masuk;
						}CekMasukTotal(L1,&L2,masuk,&z,m);
					
					}else{
					if(masuk.length()==1){
						CekMasuk(L1,&L2,masuk,&m);
					}else if(masuk.length()==hangman.length()){
						m=1;
						CekMasukTotal(L1,&L2,masuk,&z,m);
					}else{
                          k++;
						m=1;
					}
					}
					if(cekmenang(L1,L2)==true){
						z=1;
					}
					k--;
					system("cls");
					if(m==0){
						cek(&L3,masuk[0]);
					}
					
					if(z==1){
					break;
					getch();
					system ("cls"); 
					}
					
					}
					if(z==1){
						cout<<hangman;
					}else{
						Output(L2);
					}
					cout<<"\nJawaban yang benar adalah : ";
					cout<<hangman;;
					DeleteAll(&L1,&L2,&L3);
					if(z==1){
					cout<<"\n\nANDA MENANG\n";
					orang(1);
					getch();
					startgame(sum);
					}else{
						cout<<endl;
						orang(0);
						delay();delay();delay(); system("cls");
					cout<<"ANDA KALAH\n\n";
					cout<<"Score Anda Adalah "<<(*sum-1)*100<<endl;
                    orang(-1);
					system("PAUSE");
					}
					system ("cls"); 
}

//Tampilan Menu
void menu(string *n){
     while(*n!="4"){
     system("COLOR F0");
		cout<<"1. Petunjuk Permainan\n2. Start Game\n3. Custom\n4. Exit\n\nMasukkan Pilihan"<<endl;
		cin>>*n;
			if(*n=="1"){
					cout << "                                                                              \n";
					cout << "                          Tata Cara Bermain HangMan                            \n";
					cout << "                                                                               \n";
					cout << "   1. Menebak sebuah kata yang dipilih program                                 \n";
					cout << "   2. Kesempatan menebak sebanyak 4 kali                                       \n";
					cout << "   3. Pemain dapat langsung menebak kata yang dipilih                          \n";
					cout << "   4. Jika pemain gagal menebak dalam 4 kesempatan,permainan akan berakhir     \n";
					cout << "                                                                              \n";
					getch();
					system ("cls"); 
			}
			else if(*n=="2"){
                  int sum=0;
                  cout<<sum;
                  startgame(&sum);
			}else if(*n=="3"){
                  player();
            }else if(*n!="4"){
					cout<<"Menu Salah"<<endl;
					getch();
					system("cls");
					
			}
	
	}
}

//Program Utama
int main(){
    string n;
	srand((unsigned)time(0));//Random Picker
    opening();	
	while(n!="4"){
	menu(&n);
}
	return 0;
}
