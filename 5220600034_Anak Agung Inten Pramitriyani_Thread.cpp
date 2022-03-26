#include <iostream> 
//untuk mengimpor fungsi-fungsi input/output stream
#include <thread>
//untuk pemrograman multrithreading
#include <condition_variable>
//variabel khusus digunakan untuk menentukan kondisi tertentu sudah penuh/tidak
#include <chrono>
//library untuk memastikan tanggal dan waktu 
using namespace std;

mutex Mutex;
/* mutex berfungsi untuk melindungi variabel/data tidak diakses bersamaan oleh
banyak thread, deklarasi variabel yang akan dibawa ke void */

condition_variable kondisi;
//deklarasi variabel yang akan dibawa ke void

int angka = 1;
/* deklarasi variabel angka dan inisialisasi variabel dengan input 1*/

void oddThread () { 
	for (; angka < 10;) // perulangan angka kurang dari 10
	{
		unique_lock <mutex> manageObj (Mutex);
		// unique_lock sebuah objek yang mengelola object atau data dari mutex
		
	}
}
