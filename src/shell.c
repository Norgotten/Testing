#include "shell.h"
#include "kernel.h"
#include "std_lib.h"

void shell() {
  char buf[128];
  char username[32];
  
  // Inisialisasi username
  strcpy(username, "user");

  // Sambut user
  printString("Welcome to EorzeOS!\r\n");

  while (true) {
    // Bersihkan buffer input sebelum dipakai lagi
    clear((byte*)buf, 128);

    // Tampilkan prompt
    printString(username);
    printString("> ");

    // Baca input (readString() akan mencetak "\r\n" saat ENTER)
    readString(buf);

    // Proses perintah:
    if (strcmp(buf, "yo") == 1) {
      // Hanya mencetak sekali "\r\n", bukan "\n\n"
      printString("gurt\r\n");
    }
    else if (strcmp(buf, "gurt") == 1) {
      printString("yo\r\n");
    }
    else if (strncmp(buf, "user ", 5) == 1) {
      strcpy(username, buf + 5);
      printString("Username changed to ");
      printString(username);
      printString("\r\n");
    }
    else if (strcmp(buf, "user") == 1) {
      strcpy(username, "user");
      printString("Username changed to user\r\n");
    }
    else {
      // Kalau bukan command khusus, echo kembali:
      printString(buf);
      printString("\r\n");
    }

    // TIDAK perlu printString("\r\n") lagi di sini,
    // karena setiap blok 'printString(..."\r\n")' sudah
    // mengembalikan kursor ke kolom 0 pada baris baru.
  }
}

void parseCommand(char *buf, char *cmd, char arg[2][64]) {
  // Belum terpakai sekarang
}
