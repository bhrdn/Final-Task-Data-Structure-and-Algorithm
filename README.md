# Final Task Data Structure and Algorithm
* Habib Bahruddin (1301174412)
* Husna Assabiila Yassarah (1301174079)

## Screenshot
<img src="https://user-images.githubusercontent.com/13828056/39257531-f8017da2-48db-11e8-996d-978cfed52ba7.png" width="60%"></img>

## Spesifikasi
* **Judul:** Data Alat Transport
* **Deskripsi:** Implementasikan multi linked-list yang memodelkan data angkutan dan data daerah beserta relasi keduanya. Suatu alat angkutan bisa digunakan untuk transportasi ke beberapa daerah, dan sebaliknya suatu daerah bisa di capai dengan menggunakan beberapa jenis alat angkutan.

* **Fungsionalitas:** 
	* [x] Penambahan data alat angkutan.
	* [x] Penambahan data daerah.
	* [x] Penentuan relasi alat angkutan dan daerah (dan sebalikknya).
	* [x] Menghapus data alat angkutan tertentu.
	* [x] Manghapus data daerah tertentu.
	* [x] Menampilkan data keseluruhan alat angkutan beserta daerah yang bisa dikujunginya.
	* [x] Menampilkan data daerah yang bisa dilaui oleh alat angkutan tertentu.
	* [x] Menampilkan data alat angkutan yang bisa mengunjungi suatu daerah tertentu.
	* [x] Menampilkan data daerah yang paling mudah dan yang paling sulit sarana transportasinya.
* **Model:** Multi-Linked List M to N
![01](https://user-images.githubusercontent.com/13241336/36650941-b240fd3c-1ad8-11e8-98ac-3b67ff175467.png)

## Configuration for sublime-build
```json
{
	"shell_cmd": "g++ \"${file}\" -std=c++11 -o \"${file_path}/${file_base_name}\"",
	"file_regex": "^(..[^:]*):([0-9]+):?([0-9]+)?:? (.*)$",
	"working_dir": "${file_path}",
	"selector": "source.c, source.c++",

	"variants":
	[
		{
			"name": "Run",
			"shell_cmd": "g++ \"${file}\" -std=c++11 -o \"${file_path}/${file_base_name}\" && \"${file_path}/${file_base_name}\""
		}
	]
}
```
