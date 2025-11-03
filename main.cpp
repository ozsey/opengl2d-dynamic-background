#include <GL/glut.h>
#include <cstdlib>
#include <ctime>

// Inisialisasi variabel untuk menyimpan warna background
float backgroundRed = 1.0f;
float backgroundGreen = 0.41f;
float backgroundBlue = 0.89f;

    // Fungsi untuk mengubah warna background setiap detik
    void changeBackgroundColor(int value) {
        // Menghasilkan angka acak (0-2)
        int colorChoice = rand() % 3;

        // Memilih warna baru berdasarkan angka acak
        switch(colorChoice) {
            case 0:
                backgroundRed = 1.0f;
                backgroundGreen = 0.41f;
                backgroundBlue = 0.89f; // Pink (kode hex: #ff69b4)
                break;
            case 1:
                backgroundRed = 0.0f;
                backgroundGreen = 1.0f;
                backgroundBlue = 1.0f; // Biru Muda (kode hex: #00FFFF)
                break;
            case 2:
                backgroundRed = 0.6f;
                backgroundGreen = 0.98f;
                backgroundBlue = 0.6f; // Hijau Muda (kode hex: #98fb98)
                break;
        }

        // Memanggil fungsi untuk menggambar ulang layar
        glutPostRedisplay();

        // Menjadwalkan ulang panggilan fungsi ini setelah 1000 milidetik (1 detik)
        glutTimerFunc(1000, changeBackgroundColor, 0);
    }

// Fungsi untuk menggambar
void display() {
    // Mengatur warna background sesuai variabel yang disimpan
    glClearColor(backgroundRed, backgroundGreen, backgroundBlue, 1.0f);
    glClear(GL_COLOR_BUFFER_BIT);
    glFlush();
}

int main(int argc, char** argv) {
    // Inisialisasi GLUT
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutInitWindowSize(400, 300);
    glutCreateWindow("BelajarOpenGL-672021159"); // Mengatur nama window
    glutDisplayFunc(display);

    // Memanggil fungsi untuk mengubah warna background setiap detik
    srand(time(NULL)); // Mengatur seed untuk menghasilkan angka acak yang berbeda setiap kali program dijalankan
    glutTimerFunc(1000, changeBackgroundColor, 0);

    // Memulai event loop GLUT
    glutMainLoop();

    return 0;
}
