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
		
		kondisi.wait (manageObj, []() {return (angka % 2 == 1);});
		/* ketika variabel kondisi memeriksa penuh atau tidaknya, maka akan ada jeda/menunggu
		untuk manageObject mengelola data, jika sudah maka akan return hasil loopingan dari inputan variabel
		angka yaitu 1 mod 2 sama dengan 1 */
		this_thread::sleep_for(chrono::seconds(1));
		//untuk memberikan efek delay 1 detik
		cout << "Odd Thread: " << angka << endl;
		//untuk outputan Odd Thread sesuai angka yang telah dilooping
		angka++;
		//terus bertambah apabila outputan nilai sesuai dengan aturan looping
		manageObj.unlock ();
		//pengelolaan data akan terbuka, siap menjadi output
		kondisi.notify_all();
		/* variabel yang mengecek penuh atau tidak, juga dipakai untuk melancarkan output dari 
		mengecek yang telah ter-unlock sehingga seluruh output dapat tertampilkan*/
	}
}
