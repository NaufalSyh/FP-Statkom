#include <stdio.h>

int main() {
    int pekerjaan, usia, status, penghasilan, kendaraan, rumah, atap;

    // Input data dari pengguna
    printf("Masukkan nilai pekerjaan (1/0): ");
    scanf("%d", &pekerjaan);

    printf("Masukkan nilai usia (1/0): ");
    scanf("%d", &usia);

    printf("Masukkan nilai status (1/0): ");
    scanf("%d", &status);

    printf("Masukkan nilai penghasilan (1/2/3): ");
    scanf("%d", &penghasilan);

    printf("Masukkan nilai kendaraan (1/2/3): ");
    scanf("%d", &kendaraan);

    printf("Masukkan nilai rumah (1/2/3): ");
    scanf("%d", &rumah);

    printf("Masukkan nilai atap (1/0): ");
    scanf("%d", &atap);

    // Probabilitas awal kelas
    double prob_layak = 0.4;
    double prob_tidak_layak = 0.6;

    // Probabilitas atribut
    double prob_pekerjaan_layak = (pekerjaan == 1) ? 0.57 : 0.43;
    double prob_pekerjaan_tidak_layak = (pekerjaan == 1) ? 0.71 : 0.29;

    double prob_usia_layak = (usia == 1) ? 0.57 : 0.43;
    double prob_usia_tidak_layak = (usia == 1) ? 0.9 : 0.1;

    double prob_status_layak = (status == 1) ? 0.36 : 0.64;
    double prob_status_tidak_layak = (status == 1) ? 0.95 : 0.05;

    double prob_penghasilan_layak = (penghasilan == 1) ? 0.57 : (penghasilan == 2) ? 0.43 : 0;
    double prob_penghasilan_tidak_layak = (penghasilan == 1) ? 0.95 : (penghasilan == 2) ? 0.24 : 0.19;

    double prob_kendaraan_layak = (kendaraan == 1) ? 0.86 : (kendaraan == 3) ? 0.14 : 0;
    double prob_kendaraan_tidak_layak = (kendaraan == 1) ? 0.57 : (kendaraan == 2) ? 0.24 : 0.19;

    double prob_rumah_layak = (rumah == 1 || rumah == 2) ? 0.5 : 0;
    double prob_rumah_tidak_layak = (rumah == 1) ? 0.43 : (rumah == 2) ? 0.38 : 0.19;

    double prob_atap_layak = (atap == 1) ? 0.64 : 0.36;
    double prob_atap_tidak_layak = (atap == 1) ? 0.43 : 0.57;

    // Menghitung probabilitas total untuk layak dan tidak layak
    double total_prob_layak = prob_layak * prob_pekerjaan_layak * prob_usia_layak * prob_status_layak *
                              prob_penghasilan_layak * prob_kendaraan_layak * prob_rumah_layak * prob_atap_layak;

    double total_prob_tidak_layak = prob_tidak_layak * prob_pekerjaan_tidak_layak * prob_usia_tidak_layak *
                                    prob_status_tidak_layak * prob_penghasilan_tidak_layak * prob_kendaraan_tidak_layak *
                                    prob_rumah_tidak_layak * prob_atap_tidak_layak;

    // Menampilkan hasil
    if (total_prob_layak > total_prob_tidak_layak) {
        printf("Anda dinyatakan LAYAK menerima bantuan.\n");
    } else {
        printf("Anda dinyatakan TIDAK LAYAK menerima bantuan.\n");
    }

    printf("Probabilitas Layak: %.5f\n", total_prob_layak);
    printf("Probabilitas Tidak Layak: %.5f\n", total_prob_tidak_layak);

    return 0;
}
