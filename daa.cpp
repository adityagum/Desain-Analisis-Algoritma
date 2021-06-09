#include<iostream>
#include<algorithm>
using namespace std;

struct Activitiy {
   int start, end; //pendeklarasian variabel
};

bool perbandingan(Activitiy A, Activitiy A2) {
   return (A.end < A2.end); //perbandingan antara aktifitas pertama dan aktifitas selanjutnya
}

void maxActivity(Activitiy act[], int n) {
   sort(act, act+n, perbandingan); //urutkan aktifitas menggunakan fungsi perbandingan

   cout << "Jumlah maksimum aktifitas adalah : " << endl;
   int i = 0; //aktifitas keberapa yang akan kita eksekusi terlebih dahulu
   cout << "Activity: " << i << " , Start: " <<act[i].start << " End: " << act[i].end <<endl;

   for (int j = 1; j < n; j++) { //J sebagai aktifitas selanjutnya setelah aktifitas I
      if (act[j].start >= act[i].end) { //melakukan perbandingan apakah waktu selesai J >= dari waktu mulai I
         cout << "Activity: " << j << " , Start: " <<act[j].start << " End: " << act[j].end <<endl;
         i = j; //jika true, maka I akan di gantikan oleh J
      }
   }
}

int main() {
   Activitiy actArr[] = {{1,3},{2,5},{1,6},{3,7},{5,8},{4,9},{6,13},{5,12},{7,13},{13,15}}; //jumlah aktifitas dan waktunya
   int n = 10; //jumlah aktifitas keseluruhan
   maxActivity(actArr,n); //mengurutkan aktfitas array berdasarkan n.
   return 0;
}