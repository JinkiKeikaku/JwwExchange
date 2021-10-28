#pragma once
#include "JwwCommon.h"

class CJwwHeader {
public:
	CJwwHeader();
	void Read(CArchive& ar);
	void Write(CArchive& ar);
	CJwwHeader* Clone();
public:
	//	static int s_jwwDataVersion;
	
	/// <summary>
	/// ファイルメモ
	/// </summary>
	CString m_strMemo;

	CString m_aStrLayName[16][16];
	CString m_aStrGLayName[16];
	CString m_astrUDColorName_SXF[257];
	CString m_astrUDLTypeName_SXF[33];

	/// <summary>
	/// バージョンNo 7.02の内部データ値は700
	/// </summary>
	DWORD m_jwwDataVersion = JWW_VERSION;

	/// <summary>
	/// 図⾯サイズ
	/// ● 0〜4 ︓A0〜A4
	/// ● 8 ︓2 A
	/// ● 9 ︓3 A
	/// ● 10 ︓4 A
	/// ● 11 ︓5 A
	/// ● 12 ︓10m
	/// ● 13 ︓50m
	/// ● 14 ︓100m
	/// </summary>
	DWORD m_nZumen;

	/// <summary>
	/// レイヤグループ・レイヤ状態 
	/// 書込レイヤグループ
	/// </summary>
	DWORD m_nWriteGLay;

	/// <summary>
	/// レイヤグループ・レイヤ状態 
	/// レイヤグループ状態(0︓非表⽰、1︓表⽰のみ、2︓編集可能、3︓書込)
	/// </summary>
	DWORD m_anGLay[16];

	/// <summary>
	/// レイヤグループ・レイヤ状態 
	/// レイヤグループの書込レイヤ
	/// </summary>
	DWORD m_anWriteLay[16];

	/// <summary>
	/// レイヤグループ・レイヤ状態 
	/// レイヤグループの縮尺(の分⺟)
	/// </summary>
	double m_adScale[16];

	/// <summary>
	/// レイヤグループ・レイヤ状態 
	/// レイヤグループのプロテクト指定
	/// (0︓無指定、1︓表⽰状態変更可能プロテクト指定、2︓表⽰状態固定プロテクト指定)
	/// </summary>
	DWORD m_anGLayProtect[16];

	/// <summary>
	/// レイヤグループ・レイヤ状態 
	/// レイヤ状態(0︓非表⽰、1︓表⽰のみ、2︓編集可能、3︓書込)
	/// </summary>
	DWORD m_aanLay[16][16];

	/// <summary>
	/// レイヤグループ・レイヤ状態 
	/// レイヤのプロテクト指定
	/// (0︓無指定、1︓表⽰状態変更可能プロテクト指定、2︓表⽰状態固定プロテクト指定)
	/// </summary>
	DWORD m_aanLayProtect[16][16];


	/// <summary>
	/// 寸法関係の設定
	/// 環境設定ファイルの「S_COMM_8」の③寸法設定が「10」または「11」になっていて、 
	/// ファイルへの保存ができる場合に有効になり、
	/// それ以外は「m_lnSunpou1」〜「m_lnSunpou5」は「0」になる。
	/// ⼀位︓寸法線⾊（1〜9）
	/// ⼗位︓引出線⾊（1〜9）
	/// 百位︓寸法点⾊（1〜9）
	/// 千位︓寸法値の少数点以下の桁数（0〜3）
	/// 万位︓寸法単位（0 : mm 、1 : ｍ）
	/// ⼗万位︓寸法線端部（0 : 点 、1 : ⽮印 、2 : 逆⽮印）
	/// 百万位︓寸法⽂字種（1〜10）
	/// </summary>
	DWORD m_lnSunpou1;

	/// <summary>
	/// 寸法関係の設定
	/// 環境設定ファイルの「S_COMM_8」の③寸法設定が「10」または「11」になっていて、 
	/// ファイルへの保存ができる場合に有効になり、
	/// それ以外は「m_lnSunpou1」〜「m_lnSunpou5」は「0」になる。
	/// ⼀位〜千位︓寸法値の寸法線との離れ
	/// 離れ（0〜99.9）×１０、マイナスの場合は1000をプラスして整数化する
	/// 万位〜千万位︓寸法線の突出⻑さ
	/// ⻑さ（0〜99.9）×１０、マイナスの場合は1000をプラスして整数化し、更に10000倍する。
	/// </summary>
	DWORD m_lnSunpou2;

	/// <summary>
	/// 寸法関係の設定
	/// 環境設定ファイルの「S_COMM_8」の③寸法設定が「10」または「11」になっていて、 
	/// ファイルへの保存ができる場合に有効になり、
	/// それ以外は「m_lnSunpou1」〜「m_lnSunpou5」は「0」になる。
	/// </summary>
	DWORD m_lnSunpou3;
	/// <summary>
	/// 寸法関係の設定
	/// 環境設定ファイルの「S_COMM_8」の③寸法設定が「10」または「11」になっていて、 
	/// ファイルへの保存ができる場合に有効になり、
	/// それ以外は「m_lnSunpou1」〜「m_lnSunpou5」は「0」になる。
	/// </summary>
	DWORD m_lnSunpou4;
	/// <summary>
	/// 寸法関係の設定
	/// 環境設定ファイルの「S_COMM_8」の③寸法設定が「10」または「11」になっていて、 
	/// ファイルへの保存ができる場合に有効になり、
	/// それ以外は「m_lnSunpou1」〜「m_lnSunpou5」は「0」になる。
	/// </summary>
	DWORD m_lnSunpou5;

	/// <summary>
	/// 線描画の最⼤幅
	/// ｢線幅を1 / 100mm単位とする｣が設定されている時は｢－101｣、Ver.6.00以降は線幅を1 / 100mm単位にする前の線描画の
	/// 最⼤幅を含め｢ - 201｣〜｢ - 300｣、｢ - 401｣〜｢ - 500｣。
	/// </summary>
	DWORD nWid;

	/// <summary>
	/// プリンタ出⼒範囲の原点 X
	/// </summary>
	double m_DPPrtGenten_x;

	/// <summary>
	/// プリンタ出⼒範囲の原点 Y
	/// </summary>
	double m_DPPrtGenten_y;

	/// <summary>
	/// プリンタ出⼒倍率
	/// </summary>
	double m_dPrtBairitsu;

	/// <summary>
	/// プリンタ90°回転出⼒、プリンタ出⼒基準点位置
	/// ●⼀位︓プリンタ90°回転出⼒
	/// ●⼗位︓プリンタ出⼒基準点位置の指定（0 : 無指定）（Ver.3.00以降）
	/// 7 : 左上 8 : 中上 9 : 右上
	/// 4 : 左中 5 : 中中 6 : 右中
	/// 1 : 左下 2 : 中下 3 : 右下
	/// </summary>
	DWORD m_nPrtSet;

	DWORD m_nMemoriMode;
	double m_dMemoriHyoujiMin;

	double m_dMemoriX;
	double m_dMemoriY;
	double m_DpMemoriKijunTen_x;
	double m_DpMemoriKijunTen_y;


	double m_dKageLevel;
	double m_dKageIdo;
	DWORD m_nKage9_15JiFlg;
	double m_dKabeKageLevel;

	double m_dTenkuuZuLevel;
	double m_dTenkuuZuEnkoR;

	DWORD m_nMMTani3D;

	/// <summary>
	/// 保存時の画⾯倍率(読込むと前画⾯倍率になる)
	/// </summary>
	double m_dBairitsu;
	double m_DPGenten_x;
	double m_DPGenten_y;

	/// <summary>
	/// 範囲記憶倍率
	/// </summary>
	double m_dHanniBairitsu;

	/// <summary>
	/// 範囲記憶基準点(X)
	/// </summary>
	double m_DPHanniGenten_x;

	/// <summary>
	/// 範囲記憶基準点(Y)
	/// </summary>
	double m_DPHanniGenten_y;

	/// <summary>
	/// マークジャンプ倍率
	/// </summary>
	double m_dZoomJumpBairitsu[8];
	/// <summary>
	/// マークジャンプ基準点(X)
	/// </summary>
	double m_DPZoomJumpGenten_x[8];
	/// <summary>
	/// マークジャンプ基準点(Y)
	/// </summary>
	double m_DPZoomJumpGenten_y[8];
	/// <summary>
	/// マークジャンプレイヤグループ
	/// </summary>
	DWORD m_nZoomJumpGLay[8];

	/// <summary>
	/// (Ver.4.04以前はダミー）//⽂字列範囲を背景⾊で描画するときの範囲増寸法
	/// </summary>
	double m_dMojiBG;

	/// <summary>
	/// (Ver.4.04以前はダミー）
	/// ⼗位:⽂字（寸法図形､ブロック図形）を最後に描画
	/// ⼀位:1 : 輪郭・範囲を背景⾊で描画しない
	/// 2 : ⽂字の輪郭を背景⾊で描画する
	/// 3 : ⽂字列範囲を背景⾊で描画する
	/// </summary>
	DWORD m_nMojiBG;

	/// <summary>
	/// 複線間隔
	/// </summary>
	double m_adFukusenSuuchi[10];

	/// <summary>
	/// 両側複線の留線出の寸法
	/// </summary>
	double m_dRyoygawaFukusenTomeDe;

	/// <summary>
	/// ⾊番号ごとの画⾯表⽰⾊
	/// 画⾯表⽰⾊(0︓背景⾊、1〜8︓線⾊、9︓グレー⾊)
	/// </summary>
	DWORD m_aPenColor[10];

	/// <summary>
	/// ⾊番号ごとの画⾯表⽰線幅
	/// 線幅(1〜16)
	/// </summary>
	DWORD m_anPenWidth[10];

	/// <summary>
	/// ⾊番号ごとのプリンタ出⼒⾊
	/// プリンタ出⼒⾊(0︓背景⾊、1〜8︓線⾊、9︓グレー⾊)
	/// </summary>
	DWORD m_aPrtPenColor[10];

	/// <summary>
	/// ⾊番号ごとのプリンタ線幅
	/// 線幅(1〜500)
	/// </summary>
	DWORD m_anPrtPenWidth[10];

	/// <summary>
	/// ⾊番号ごとのプリンタ実点半径
	/// 実点半径(0.1〜10)
	/// </summary>
	double m_adPrtTenHankei[10];


	/// <summary>
	/// 線種番号2から9までのパターン
	/// </summary>
	DWORD m_alLType[8];
	/// <summary>
	/// 線種番号2から9までの1ユニットのドット数
	/// </summary>
	DWORD m_anTokushuSenUintDot[8];
	/// <summary>
	/// 線種番号2から9までのピッチ
	/// </summary>
	DWORD m_anTokushuSenPich[8];
	/// <summary>
	/// 線種番号2から9までのプリンタ出⼒ピッチ
	/// </summary>
	DWORD m_anPrtTokushuSenPich[8];

	//◆ ランダム線1から5までのパターン、画⾯表⽰振幅・ピッチ、プリンタ出⼒振幅・ピッチ
	DWORD m_alLType_Rnd[5];
	DWORD m_anRandSenWide_Rnd[5];
	DWORD m_anTokushuSenPich_Rnd[5];
	DWORD m_anPrtRandSenWide_Rnd[5];
	DWORD m_anPrtTokushuSenPich_Rnd[5];
	//◆ 倍⻑線種番号6から9までのパターン、1ユニットのドット数、ピッチ、プリンタ出⼒ピッチ
	DWORD m_alLType_Double[4];
	DWORD m_anTokushuSenUintDot_Double[4];
	DWORD m_anTokushuSenPich_Double[4];
	DWORD m_anPrtTokushuSenPich_Double[4];

	//◆ 実点を画⾯描画時の指定半径で描画
	DWORD m_nDrawGamenTen;
	//◆ 実点をプリンタ出⼒時、指定半径で書く
	DWORD m_nDrawPrtTen;
	//◆ BitMap・ソリッドを最初に描画する
	DWORD m_nBitMapFirstDraw; //⼗位︓ソリッド描画順

	/// <summary>
	/// 逆描画
	/// </summary>
	DWORD m_nGyakuDraw;

	/// <summary>
	/// 逆サーチ
	/// </summary>
	DWORD m_nGyakuSearch;

	/// <summary>
	/// カラー印刷
	/// </summary>
	DWORD m_nColorPrint;

	/// <summary>
	/// レイヤ順の印刷
	/// </summary>
	DWORD m_nLayJunPrint;

	/// <summary>
	/// ⾊番号順の印刷
	/// </summary>
	DWORD m_nColJunPrint;

	/// <summary>
	/// レイヤグループまたはレイヤごとのプリンタ連続出⼒指定
	/// </summary>
	DWORD m_nPrtRenzoku;

	/// <summary>
	/// プリンタ共通レイヤ(表⽰のみレイヤ)のグレー出⼒指定
	/// </summary>
	DWORD m_nPrtKyoutsuuGray;

	/// <summary>
	/// プリンタ出⼒時に表⽰のみレイヤは出⼒しない
	/// Ver.6.00以降は印刷時における既定線⾊の線幅の基準値の「dpi」。
	/// </summary>
	DWORD m_nPrtDispOnlyNonDraw;

	/// <summary>
	/// 作図時間（Ver.2.23以降）
	/// </summary>
	DWORD m_lnDrawTime;

	/// <summary>
	/// 2.5Dの始点位置が設定されている時のフラグ（Ver.2.23以降）
	/// ⼀位︓透視図の視点位置設定済みフラグ
	/// ⼗位︓⿃瞰図の視点位置設定済みフラグ
	/// 百位︓アイソメ図の視点位置設定済みフラグ
	/// </summary>
	DWORD nEyeInit;

	/// <summary>
	/// 2.5Dの透視図の視点⽔平角（Ver.2.23以降）
	/// </summary>
	DWORD m_dEye_H_Ichi_1;
	/// <summary>
	/// 2.5Dの⿃瞰図の視点⽔平角（Ver.2.23以降）
	/// </summary>
	DWORD m_dEye_H_Ichi_2;
	/// <summary>
	/// 2.5Dのアイソメ図の視点⽔平角（Ver.2.23以降）
	/// </summary>
	DWORD m_dEye_H_Ichi_3;

	/// <summary>
	/// 2.5Dの透視図の視点⾼さ（Ver.2.23以降）
	/// </summary>
	double m_dEye_Z_Ichi_1;

	/// <summary>
	/// 2.5Dの透視図の視点離れ（Ver.2.23以降）
	/// </summary>
	double m_dEye_Y_Ichi_1;

	//◆ 2.5Dの⿃瞰図の視点⾼さ・視点離れ（Ver.2.23以降）
	double m_dEye_Z_Ichi_2;
	double m_dEye_Y_Ichi_2;
	//◆ 2.5Dのアイソメ図の視点垂直角（Ver.2.23以降）
	double m_dEye_V_Ichi_3;
	//◆ 線の⻑さ指定の最終値（Ver.2.25以降）
	double m_dSenNagasaSnpou;
	//◆ 矩形寸法横寸法・縦寸法指定の最終値（Ver.2.25以降）
	double m_dBoxSunpouX;
	double m_dBoxSunpouY;
	//◆ 円の半径指定の最終値（Ver.2.25以降）
	double m_dEnHankeiSnpou;
	//◆ ソリッドを任意⾊で書くフラグ、ソリッドの任意⾊の既定値（Ver.2.30以降）
	DWORD m_nSolidNinniColor;
	DWORD m_SolidColor; //RGB
	//◆ SXF対応拡張線⾊定義（Ver.4.20以降）
		//● 画⾯表⽰⾊
		//● 画⾯表⽰線幅
		//● 線⾊名
		//● プリンタ出⼒⾊
		//● プリンタ出⼒線幅
		//● 点半径

	/// <summary>
	/// SXF対応拡張線⾊定義（Ver.4.20以降）
	/// 画⾯表⽰⾊
	/// </summary>
	DWORD m_aPenColor_SXF[257];
	/// <summary>
	/// SXF対応拡張線⾊定義（Ver.4.20以降）
	/// 画⾯表⽰線幅
	/// </summary>
	DWORD m_anPenWidth_SXF[257];
	/// <summary>
	/// SXF対応拡張線⾊定義（Ver.4.20以降）
	/// プリンタ出⼒⾊
	/// </summary>
	DWORD m_aPrtPenColor_SXF[257];
	/// <summary>
	/// SXF対応拡張線⾊定義（Ver.4.20以降）
	/// プリンタ出⼒線幅
	/// </summary>
	DWORD m_anPrtPenWidth_SXF[257];
	/// <summary>
	/// SXF対応拡張線⾊定義（Ver.4.20以降）
	/// 点半径
	/// </summary>
	double m_adPrtTenHankei_SXF[257];
	//◆ SXF対応拡張線種定義（Ver.4.20以降）
	//● パターン
	//● 1ユニットのドット数
	//● ピッチ
	//● プリンタ出⼒ピッチ
	//● 線種名
	//● セグメント数
	//● ピッチ線分の⻑さ、空⽩⻑さの繰り返し
	DWORD m_alLType_SXF[33];
	DWORD m_anTokushuSenUintDot_SXF[33];
	DWORD m_anTokushuSenPich_SXF[33];
	DWORD m_anPrtTokushuSenPich_SXF[33];
	DWORD m_anUDLTypeSegment_SXF[33];
	double m_aadUDLTypePitch_SXF[33][10];
	//◆ ⽂字種1から10までの⽂字幅、⾼さ、間隔、⾊番号
	double m_adMojiX[10];
	double m_adMojiY[10];
	double m_adMojiD[10];
	DWORD m_anMojiCol[10];
	//◆ 書込み⽂字の⽂字幅、⾼さ、間隔、⾊番号、⽂字番号
	double m_dMojiSizeX;
	double m_dMojiSizeY;
	double m_dMojiKankaku;
	DWORD m_nMojiColor;
	DWORD m_nMojiShu;
	//◆ ⽂字位置整理の⾏間、⽂字数
	double m_dMojiSeiriGyouKan;
	double m_dMojiSeiriSuu;
	//◆ ⽂字基準点のずれ位置使⽤のフラグ
	DWORD m_nMojiKijunZureOn;
	//◆ ⽂字基準点の横⽅向のずれ位置左、中、右
	double m_adMojiKijunZureX[3];
	//◆ ⽂字基準点の縦⽅向のずれ位置下、中、上
	double m_adMojiKijunZureY[3];

};

