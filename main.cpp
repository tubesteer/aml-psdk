#include <mod/amlmod.h>
#include <mod/logger.h>

// Informasi Mod kamu (Ganti sesuai keinginan)
MYMOD(com.dimas.visual64, VisualSADox64, 1.0, Dimas)

// Alamat dasar dari library game
uintptr_t pGameAddress = 0;

extern "C" void OnModLoad()
{
    logger->Info("--- Memulai Pemasangan VisualSADox 64-bit ---");

    // 1. Mengunci library utama GTA SA 2.10 (arm64-v8a)
    pGameAddress = aml->GetLib("libGTASA.so");

    if (pGameAddress)
    {
        logger->Info("libGTASA.so terdeteksi di memori.");

        /* 
           2. MODIFIKASI JARAK PANDANG & KABUT (FOG)
           Di versi 2.10 64-bit, variabel global untuk mengatur jarak kabut 
           dan draw distance berada di sekitar offset ini.
           Kita overwrite nilainya dengan angka float yang lebih besar.
        */
        
        // Contoh memasukkan nilai Jarak Jauh (Draw Distance) sebesar 2000.0f
        // (Default game biasanya hanya sekitar 800.0f - 1200.0f)
        uintptr_t offsetDrawDist = pGameAddress + 0x9B4D20; // Offset ilustrasi v2.10 arm64
        aml->WriteFloat(offsetDrawDist, 2000.0f);
        
        // Memaksa nilai ketebalan kabut (Fog) menjadi sangat tipis / 0
        uintptr_t offsetFogDensity = pGameAddress + 0x9B4D24; 
        aml->WriteFloat(offsetFogDensity, 0.0f);

        logger->Info("Fitur No-Fog & Max Draw Distance berhasil diterapkan!");
    }
    else
    {
        logger->Error("Gagal memuat libGTASA.so! Pastikan game berjalan.");
    }
}
