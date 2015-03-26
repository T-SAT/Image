/*
  名前 : ppmimage.h
  概要 : PPM形式画像処理ライブラリ
  引数 : なし
  返値 : なし
  履歴 : 2006/10/30 ver. 1.0 笹間 作成
*/

#ifndef __PPM_IMAGE_H__
#define __PPM_IMAGE_H__

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_PPM_STR_LENGTH 128
#define MAX_PPM_COMMENT_LENGTH 128

typedef struct { // 画素 構造体
  int r; // Red   赤
  int g; // Green 緑
  int b; // Blue  青 の3原色 それぞれ 0〜255
} PpmPixel;

typedef struct { // 画像 構造体
  char type[MAX_PPM_STR_LENGTH];        // 型 P6 想定
  char comment[MAX_PPM_COMMENT_LENGTH]; // コメント
  int x;             // 画像Xサイズ
  int y;             // 画像Yサイズ
  int z;             // 画像Zサイズ (色深度 255 想定)
  PpmPixel **pixels; // 画素の2次元配列を持つ(予定)
} PpmImage;

// 画像のファイルからの読書
PpmImage *ppm_half(PpmImage *);
PpmImage *ppm_read(char *);
int ppm_write(char *, PpmImage *);

// 画像領域確保と開放
PpmImage *ppm_alloc(int, int);
int ppm_free(PpmImage *);

// 他
PpmImage *ppm_copy(PpmImage *);
PpmImage *ppm_glassmerge(PpmImage *, PpmImage *, PpmPixel);
#endif
