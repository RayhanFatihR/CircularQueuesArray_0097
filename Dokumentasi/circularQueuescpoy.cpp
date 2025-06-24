/**
 * @mainpage Documentation Circular Queues
 * 
 * @section Intruduction
 * Project ini merupakan projek struktur data menggunakan struktur data queues dengan pendekatan circular arrays.alignas
 * 
 * @section Operations
 * Project ini memiliki beberapa operasi antara lain:
 * 1. Insert
 * 2. Delete
 * 3. Display
 * 
 * @section Cara Pengunaan 
 * Berikut beberapa menu bisa digunakan:
 * 1. En queue
 * 2. De queue
 * 3. Display
 * 4. Exit
 * 
 * @author Profil
 * - nama   : {Rayhan Fatih Ramadhani}
 * - nim    : {20240140097}
 * - kelas  : {B}
 * 
 * @brief
 * @version 1.0
 * @date 2025-06-24
 * 
 * @copyright {Rayhan Fatih Ramadhani}@umy.ac.id (c) 2025
 */
#include <iostream>
using namespace std;
/** 
 * @class Queues
 * @brief class ini untuk operasi lengkap queus
 * 
 * 
 */
class Queues{
    private:
        int FRONT;          ///< variable private front untuk menyimpan posisi depan antrian
        int REAR;           ///< variable private rear untuk menyimpan posisi belakang antrian  
        int max = 5;        ///< variable private max untuk menyimpan kapasitas maximum antrian
        int queue_array[5]; ///< varianle private queue_array untuk menyimpan elemen antrian
    
    public:
    /**
     * @brief Construct a new Queues object
     * set default queues null 
     * with front = -1 and rear = -1
     */
     Queues(){
        FRONT = -1;  ///< set default front antrian
        REAR = -1;   ///< set default rear antrian
    }
    
    /**
     * @brief method untuk memasukkan data dalam antrian
     * data dimasukkan dalam variable queue_array
     */
    void insert(){
        int num; ///< variable num untuk menyimpan nilai
        cout << "Enter a number: ";
        cin >> num;
        cout << endl;

        // Cek apakah antrian penuh
        if ((FRONT == 0 && REAR == max - 1) || (FRONT == REAR + 1)) {
            cout << "\nQueue overflow\n"; 
            return;                       
        }

        // Cek apakah antrian kosong
        if (FRONT == -1) {
            FRONT = 0;
            REAR  = 0;
        }
        else{
            // Jika REAR berada diposisi terakhir array, kembali ke awal array
            if (REAR == max - 1)
                REAR = 0;
            else
                REAR = REAR + 1;
        }
        queue_array[REAR] = num;
    }

    /**
     * @brief method untuk menghapus data dalam antrian
     * data dihapus dari dalam variable queue_array
     */
    void remove()
    {
        //Cek apakah antrian kosong
        if (FRONT == -1) 
        {
            cout << "Queue underflow\n";
            return;
        }
         cout << "\nThe element deleted from the queue is: " << queue_array[FRONT] << "\n";

        // Cek jika antrian hanya memiliki satu elemen
        if (FRONT == REAR)
        {
            FRONT = -1;
            REAR = -1;
        }
        else
        {
            // jika elemen yang dihapus berada di posisi terakhir array, kembali ke awal array
            if (FRONT == max - 1)
                FRONT = 0;
            else
                FRONT = FRONT + 1;
        }
    }
        /**
         * @brief method untuk menampilkan elemen dalam antrian
         * data ditampilkan yang berada di dalam variable queue_array
         */
         void display()
         {
            int FRONT_position = FRONT; ///< variable front_position untuk menandakan posisi elemen
            int REAR_position = REAR;   ///< variable rear_position untuk menandakan posisi elemen

             // Cek apakah antrian kosong
            if (FRONT == -1)
            {
                cout << "Queue is empty\n";
                return;
            }

            cout << "\nElements in the queue are ....\n";

            // Jika FRONT_position <= REAR_position, interasi dari FRONT hingga REAR
            if (FRONT_position <= REAR_position){
                while (FRONT_position <= REAR_position)
                {
                    cout << queue_array[FRONT_position] << " ";
                    FRONT_position++;
                }
                cout << endl;
            }
            else
            {
                // Jika FRONT_position > REAR_position, interasi dari FRONT hingga akhir array
                while (FRONT_position <= max - 1)
                {
                    cout << queue_array[FRONT_position] << " ";
                    FRONT_position++;
                }

                cout << endl;
            }
            

     
        }
    
};

/**
 * @brief method utama untuk melanjutkan program
 * 
 * @return int 
 */
int main()
{
    Queues q;///< objek untuk menggunakan member yang ada pada class queues
    char ch;///< variable ch untuk menyimpan pilihan pada menu yang diberikan

    while(true)
    {
        try
        {
            cout << "Menu" << endl;
            cout << "1. Implement insert operation" << endl;
            cout << "2. Implement delete operation" << endl;
            cout << "3. Display the queue" << endl;
            cout << "4. Exit" << endl;
            cout << "Enter your choice(1-4): ";
            cin >> ch;
            cout << endl;

            switch(ch)
            {
                case '1':
                {
                    q.insert();
                    break;
                }
                case '2':
                {
                    q.remove();
                    break;
                }
                case '3':
                {
                    q.display();
                    break;
                }
                case '4':
                {
                    return 0;
                }
                default:
                {
                    cout << "Invalid option!!" << endl;
                    break;
                }
            }
        }   
        catch (exception& e)
        {
            cout << "Check for the values entered." << endl;
        }
    }
    return 0;
}