#pragma once

#include "quantum.h"

// üst kısım görsel amaç, tuş düzeni (layout) yerleşiminde kullanılacak, satır sütun nasıl görünüyorsa o şekilde düzenleyebilirsin
// alt kısım da satır sütun yerleşimini gösterecek. yani 8 satır 6 sütun
//  harflendirme önemli değil
//  satırları belirlerkken;
//  1                       8
//  2                       7
//  3                       6
//  4                       5

// sütunları bu şekilde bağladım;
// 1 2 3 4 5 6 - 6 5 4 3 2 1
// kabloları nasıl bağladıysam, tuşları nasıl yerleştirdiysem ona uygun olarak üstü düzenledim.

#define LAYOUT_numpad_4x3(K000, K001, K002, K003, K100, K101, K102, K103, K200, K201, K202, K203) \
    { {K000, K001, K002, K003}, {K100, K101, K102, K103}, {K200, K201, K202, K203}, }
