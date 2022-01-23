#pragma once
using namespace System;
#include "CJwwHeader.h"
#include "JwwUtility.h"
#include "CStringArray.h"
#include "WrapArray.h"

namespace JwwHelper {
	/// <summary>
	/// jwwファイルのヘッダー情報。メンバ詳細は本家のドキュメントを参照すること。
	/// </summary>
	public ref class JwwHeader
	{
	private:
		CJwwHeader* m_pHeader;
		array<CStringArray^>^ _m_aStrLayName = gcnew array<CStringArray^>(16);
		CStringArray^ _m_aStrGLayName;
		CStringArray^ _m_astrUDColorName_SXF;// = gcnew array<String^>(257);
		CStringArray^ _m_astrUDLTypeName_SXF;// = gcnew array<String^>(33);

		WrapArray<double>^ _m_adScale;
		WrapArray<DWORD>^ _m_anGLay;
		WrapArray<DWORD>^ _m_anWriteLay;
		WrapArray<DWORD>^ _m_anGLayProtect;
		array<WrapArray<DWORD>^>^ _m_aanLay = gcnew array<WrapArray<DWORD>^>(16);
		array<WrapArray<DWORD>^>^ _m_aanLayProtect = gcnew array<WrapArray<DWORD>^>(16);
		WrapArray<double>^ _m_dZoomJumpBairitsu;
		WrapArray<double>^ _m_DPZoomJumpGenten_x;
		WrapArray<double>^ _m_DPZoomJumpGenten_y;
		WrapArray<DWORD>^ _m_nZoomJumpGLay;
		WrapArray<double>^ _m_adFukusenSuuchi;
		WrapArray<DWORD>^ _m_aPenColor;
		WrapArray<DWORD>^ _m_anPenWidth;
		WrapArray<DWORD>^ _m_aPrtPenColor;
		WrapArray<DWORD>^ _m_anPrtPenWidth;
		WrapArray<double>^ _m_adPrtTenHankei;
		WrapArray<DWORD>^ _m_alLType;
		WrapArray<DWORD>^ _m_anTokushuSenUintDot;
		WrapArray<DWORD>^ _m_anTokushuSenPich;
		WrapArray<DWORD>^ _m_anPrtTokushuSenPich;
		WrapArray<DWORD>^ _m_alLType_Rnd;
		WrapArray<DWORD>^ _m_anRandSenWide_Rnd;
		WrapArray<DWORD>^ _m_anTokushuSenPich_Rnd;
		WrapArray<DWORD>^ _m_anPrtRandSenWide_Rnd;
		WrapArray<DWORD>^ _m_anPrtTokushuSenPich_Rnd;
		WrapArray<DWORD>^ _m_alLType_Double;
		WrapArray<DWORD>^ _m_anTokushuSenUintDot_Double;
		WrapArray<DWORD>^ _m_anTokushuSenPich_Double;
		WrapArray<DWORD>^ _m_anPrtTokushuSenPich_Double;
		WrapArray<DWORD>^ _m_aPenColor_SXF;
		WrapArray<DWORD>^ _m_anPenWidth_SXF;
		WrapArray<DWORD>^ _m_aPrtPenColor_SXF;
		WrapArray<DWORD>^ _m_anPrtPenWidth_SXF;
		WrapArray<double>^ _m_adPrtTenHankei_SXF;
		WrapArray<DWORD>^ _m_alLType_SXF;
		WrapArray<DWORD>^ _m_anTokushuSenUintDot_SXF;
		WrapArray<DWORD>^ _m_anTokushuSenPich_SXF;
		WrapArray<DWORD>^ _m_anPrtTokushuSenPich_SXF;
		WrapArray<DWORD>^ _m_anUDLTypeSegment_SXF;
		array<WrapArray<double>^>^ _m_aadUDLTypePitch_SXF = gcnew array<WrapArray<double>^>(33);
		WrapArray<double>^ _m_adMojiX;
		WrapArray<double>^ _m_adMojiY;
		WrapArray<double>^ _m_adMojiD;
		WrapArray<DWORD>^ _m_anMojiCol;
		WrapArray<double>^ _m_adMojiKijunZureX;
		WrapArray<double>^ _m_adMojiKijunZureY;

		void InitArrays() {
			for (int j = 0; j < 16; j++) {
				_m_aStrLayName[j] = gcnew CStringArray(m_pHeader->m_aStrLayName[j], 16);
				_m_aanLay[j] = gcnew WrapArray<DWORD>(m_pHeader->m_aanLay[j], 16);
				_m_aanLayProtect[j] = gcnew WrapArray<DWORD>(m_pHeader->m_aanLayProtect[j], 16);
			}
			_m_aStrGLayName = gcnew CStringArray(m_pHeader->m_aStrGLayName, 16);
			_m_astrUDColorName_SXF = gcnew CStringArray(m_pHeader->m_astrUDColorName_SXF, 257);
			_m_astrUDLTypeName_SXF = gcnew CStringArray(m_pHeader->m_astrUDLTypeName_SXF, 33);
			_m_adScale = gcnew WrapArray<double>(m_pHeader->m_adScale, 16);
			_m_anGLay = gcnew WrapArray<DWORD>(m_pHeader->m_anGLay, 16);
			_m_anWriteLay = gcnew WrapArray<DWORD>(m_pHeader->m_anWriteLay, 16);
			_m_anGLayProtect = gcnew WrapArray<DWORD>(m_pHeader->m_anGLayProtect, 16);
			_m_dZoomJumpBairitsu = gcnew WrapArray<double>(m_pHeader->m_dZoomJumpBairitsu, 8);
			_m_DPZoomJumpGenten_x = gcnew WrapArray<double>(m_pHeader->m_DPZoomJumpGenten_x, 8);
			_m_DPZoomJumpGenten_y = gcnew WrapArray<double>(m_pHeader->m_DPZoomJumpGenten_y, 8);
			_m_nZoomJumpGLay = gcnew WrapArray<DWORD>(m_pHeader->m_nZoomJumpGLay, 8);


			_m_adFukusenSuuchi = gcnew WrapArray<double>(m_pHeader->m_adFukusenSuuchi, 10);
			_m_aPenColor = gcnew WrapArray<DWORD>(m_pHeader->m_aPenColor, 10);
			_m_anPenWidth = gcnew WrapArray<DWORD>(m_pHeader->m_anPenWidth, 10);

			_m_aPrtPenColor = gcnew WrapArray<DWORD>(m_pHeader->m_aPrtPenColor, 10);
			_m_anPrtPenWidth = gcnew WrapArray<DWORD>(m_pHeader->m_anPrtPenWidth, 10);
			_m_adPrtTenHankei = gcnew WrapArray<double>(m_pHeader->m_adPrtTenHankei, 10);

			_m_alLType = gcnew WrapArray<DWORD>(m_pHeader->m_alLType, 8);
			_m_anTokushuSenUintDot = gcnew WrapArray<DWORD>(m_pHeader->m_anTokushuSenUintDot, 8);
			_m_anTokushuSenPich = gcnew WrapArray<DWORD>(m_pHeader->m_anTokushuSenPich, 8);
			_m_anPrtTokushuSenPich = gcnew WrapArray<DWORD>(m_pHeader->m_anPrtTokushuSenPich, 8);
			
			_m_alLType_Rnd = gcnew WrapArray<DWORD>(m_pHeader->m_alLType_Rnd, 5);
			_m_anRandSenWide_Rnd = gcnew WrapArray<DWORD>(m_pHeader->m_anRandSenWide_Rnd, 5);
			_m_anTokushuSenPich_Rnd = gcnew WrapArray<DWORD>(m_pHeader->m_anTokushuSenPich_Rnd, 5);
			_m_anPrtRandSenWide_Rnd = gcnew WrapArray<DWORD>(m_pHeader->m_anPrtRandSenWide_Rnd, 5);
			_m_anPrtTokushuSenPich_Rnd = gcnew WrapArray<DWORD>(m_pHeader->m_anPrtTokushuSenPich_Rnd, 5);

			_m_alLType_Double = gcnew WrapArray<DWORD>(m_pHeader->m_alLType_Double, 4);
			_m_anTokushuSenUintDot_Double = gcnew WrapArray<DWORD>(m_pHeader->m_anTokushuSenUintDot_Double, 4);
			_m_anTokushuSenPich_Double = gcnew WrapArray<DWORD>(m_pHeader->m_anTokushuSenPich_Double, 4);
			_m_anPrtTokushuSenPich_Double = gcnew WrapArray<DWORD>(m_pHeader->m_anPrtTokushuSenPich_Double, 4);

			_m_aPenColor_SXF = gcnew WrapArray<DWORD>(m_pHeader->m_aPenColor_SXF, 257);
			_m_anPenWidth_SXF = gcnew WrapArray<DWORD>(m_pHeader->m_anPenWidth_SXF, 257);
			_m_aPrtPenColor_SXF = gcnew WrapArray<DWORD>(m_pHeader->m_aPrtPenColor_SXF, 257);
			_m_anPrtPenWidth_SXF = gcnew WrapArray<DWORD>(m_pHeader->m_anPrtPenWidth_SXF, 257);
			_m_adPrtTenHankei_SXF = gcnew WrapArray<double>(m_pHeader->m_adPrtTenHankei_SXF, 257);

			_m_alLType_SXF = gcnew WrapArray<DWORD>(m_pHeader->m_alLType_SXF, 33);
			_m_anTokushuSenUintDot_SXF = gcnew WrapArray<DWORD>(m_pHeader->m_anTokushuSenUintDot_SXF, 33);
			_m_anTokushuSenPich_SXF = gcnew WrapArray<DWORD>(m_pHeader->m_anTokushuSenPich_SXF, 33);
			_m_anPrtTokushuSenPich_SXF = gcnew WrapArray<DWORD>(m_pHeader->m_anPrtTokushuSenPich_SXF, 33);
			_m_anUDLTypeSegment_SXF = gcnew WrapArray<DWORD>(m_pHeader->m_anUDLTypeSegment_SXF, 33);
			for (int i = 0; i < 33; i++) {
				_m_aadUDLTypePitch_SXF[i] = gcnew WrapArray<double>(m_pHeader->m_aadUDLTypePitch_SXF[i], 10);
			}
			_m_adMojiX = gcnew WrapArray<double>(m_pHeader->m_adMojiX, 10);
			_m_adMojiY = gcnew WrapArray<double>(m_pHeader->m_adMojiY, 10);
			_m_adMojiD = gcnew WrapArray<double>(m_pHeader->m_adMojiD, 10);
			_m_anMojiCol = gcnew WrapArray<DWORD>(m_pHeader->m_anMojiCol, 10);
			_m_adMojiKijunZureX = gcnew WrapArray<double>(m_pHeader->m_adMojiKijunZureX, 3);
			_m_adMojiKijunZureY = gcnew WrapArray<double>(m_pHeader->m_adMojiKijunZureY, 3);
		}


	internal:
		JwwHeader() {
			m_pHeader = new CJwwHeader(); 
			InitArrays();
		}
		JwwHeader(CJwwHeader* pHeader) { 
			m_pHeader = pHeader; 
			InitArrays();
		}
	public:
		~JwwHeader() { this->!JwwHeader(); }
		!JwwHeader() { delete m_pHeader; }

	public:

		/// <summary>
		/// バージョンNo 7.02の内部データ値は700
		/// </summary>
		property int m_jwwDataVersion {
			int get() { return m_pHeader->m_jwwDataVersion; }
		};

		/// <summary>
		/// ファイルメモ
		/// </summary>
		property String^ m_strMemo {
			String^ get() {
				return gcnew String(CA2W(m_pHeader->m_strMemo.GetString()));
			}
			void set(String^ value) { 
				pin_ptr<const WCHAR> str = PtrToStringChars(value);
				CW2A astr(str);
				m_pHeader->m_strMemo = astr;
			}
		};

		/// <summary>
		/// レイヤ名(size=16x16)
		/// </summary>
		property array<CStringArray^>^ m_aStrLayName {
			array<CStringArray^>^ get() {
				return _m_aStrLayName;
			}
		}

		/// <summary>
		/// レイヤグループ名(size=16)
		/// </summary>
		property CStringArray^ m_aStrGLayName {
			CStringArray^ get() {
				return _m_aStrGLayName;
			}
		}

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
		property int m_nZumen {
			int get() { return m_pHeader->m_nZumen; }
			void set(int value) { m_pHeader->m_nZumen = value; }
		};

		/// <summary>
		/// レイヤグループ・レイヤ状態 
		/// 書込レイヤグループ
		/// </summary>
		property int m_nWriteGLay {
			int get() { return m_pHeader->m_nWriteGLay; }
			void set(int value) { m_pHeader->m_nWriteGLay = value; }
		};

		/// <summary>
		/// レイヤグループ・レイヤ状態
		/// レイヤグループ状態(0︓非表⽰、1︓表⽰のみ、2︓編集可能、3︓書込)
		///  (size=16)
		/// </summary>
		property WrapArray<DWORD>^ m_anGLay {
			WrapArray<DWORD>^ get() {
				return _m_anGLay;
			}
		}

		/// <summary>
		/// レイヤグループ・レイヤ状態 
		/// レイヤグループの書込レイヤ
		///  (size=16)
		/// </summary>
		property WrapArray<DWORD>^ m_anWriteLay {
			WrapArray<DWORD>^ get() {
				return _m_anWriteLay;
			}
		}

		/// <summary>
		/// レイヤグループ・レイヤ状態 
		/// レイヤグループの縮尺(の分⺟)
		///  (size=16)
		/// </summary>
		property WrapArray<double>^ m_adScale {
			WrapArray<double>^ get() {
				return _m_adScale;
			}
		}

		/// <summary>
		/// レイヤグループ・レイヤ状態 
		/// レイヤグループのプロテクト指定
		/// (0︓無指定、1︓表⽰状態変更可能プロテクト指定、2︓表⽰状態固定プロテクト指定)
		///  (size=16)
		/// </summary>
		property WrapArray<DWORD>^ m_anGLayProtect {
			WrapArray<DWORD>^ get() {
				return _m_anGLayProtect;
			}
		}

		/// <summary>
		/// レイヤグループ・レイヤ状態 
		/// レイヤ状態(0︓非表⽰、1︓表⽰のみ、2︓編集可能、3︓書込)
		///  (size=16x16)
		/// </summary>
		property array<WrapArray<DWORD>^>^ m_aanLay {
			array<WrapArray<DWORD>^>^ get() {
				return _m_aanLay;
			}
		}

		/// <summary>
		/// レイヤグループ・レイヤ状態 
		/// レイヤのプロテクト指定
		/// (0︓無指定、1︓表⽰状態変更可能プロテクト指定、2︓表⽰状態固定プロテクト指定)
		///  (size=16x16)
		/// </summary>
		property array<WrapArray<DWORD>^>^ m_aanLayProtect {
			array<WrapArray<DWORD>^>^ get() {
				return _m_aanLayProtect;
			}
		}
		
		/// <summary>
		/// 寸法関係の設定
		/// 環境設定ファイルの「S_COMM_8」の③寸法設定が「10」または「11」になっていて、 
		/// ファイルへの保存ができる場合に有効になり、
		/// それ以外は「m_lnSunpou1」〜「m_lnSunpou5」は「0」になる。
		/// 詳細は本家の解説を見てください。
		/// </summary>
		property int m_lnSunpou1 {
			int get() { return m_pHeader->m_lnSunpou1; }
			void set(int value) { m_pHeader->m_lnSunpou1 = value; }
		};

		/// <summary>
		/// 寸法関係の設定
		/// 環境設定ファイルの「S_COMM_8」の③寸法設定が「10」または「11」になっていて、 
		/// ファイルへの保存ができる場合に有効になり、
		/// それ以外は「m_lnSunpou1」〜「m_lnSunpou5」は「0」になる。
		/// 詳細は本家の解説を見てください。
		/// </summary>
		property int m_lnSunpou2 {
			int get() { return m_pHeader->m_lnSunpou2; }
			void set(int value) { m_pHeader->m_lnSunpou2 = value; }
		};

		/// <summary>
		/// 寸法関係の設定
		/// 環境設定ファイルの「S_COMM_8」の③寸法設定が「10」または「11」になっていて、 
		/// ファイルへの保存ができる場合に有効になり、
		/// それ以外は「m_lnSunpou1」〜「m_lnSunpou5」は「0」になる。
		/// 詳細は本家の解説を見てください。
		/// </summary>
		property int m_lnSunpou3 {
			int get() { return m_pHeader->m_lnSunpou3; }
			void set(int value) { m_pHeader->m_lnSunpou3 = value; }
		};

		/// <summary>
		/// 寸法関係の設定
		/// 環境設定ファイルの「S_COMM_8」の③寸法設定が「10」または「11」になっていて、 
		/// ファイルへの保存ができる場合に有効になり、
		/// それ以外は「m_lnSunpou1」〜「m_lnSunpou5」は「0」になる。
		/// 詳細は本家の解説を見てください。
		/// </summary>
		property int m_lnSunpou4 {
			int get() { return m_pHeader->m_lnSunpou4; }
			void set(int value) { m_pHeader->m_lnSunpou4 = value; }
		};

		/// <summary>
		/// 寸法関係の設定
		/// 環境設定ファイルの「S_COMM_8」の③寸法設定が「10」または「11」になっていて、 
		/// ファイルへの保存ができる場合に有効になり、
		/// それ以外は「m_lnSunpou1」〜「m_lnSunpou5」は「0」になる。
		/// 詳細は本家の解説を見てください。
		/// </summary>
		property int m_lnSunpou5 {
			int get() { return m_pHeader->m_lnSunpou5; }
			void set(int value) { m_pHeader->m_lnSunpou5 = value; }
		}

		/// <summary>
		/// 線描画の最⼤幅
		/// ｢線幅を1 / 100mm単位とする｣が設定されている時は｢－101｣、Ver.6.00以降は線幅を1 / 100mm単位にする前の線描画の
		/// 最⼤幅を含め｢ - 201｣〜｢ - 300｣、｢ - 401｣〜｢ - 500｣。
		/// </summary>
		property int nWid {
			int get() { return m_pHeader->nWid; }
			void set(int value) { m_pHeader->nWid = value; }
		}

		/// <summary>
		/// プリンタ出⼒範囲の原点 X
		/// </summary>
		property double m_DPPrtGenten_x {
			double get() { return m_pHeader->m_DPPrtGenten_x; }
			void set(double value) { m_pHeader->m_DPPrtGenten_x = value; }
		}

		/// <summary>
		/// プリンタ出⼒範囲の原点 Y
		/// </summary>
		property double m_DPPrtGenten_y {
			double get() { return m_pHeader->m_DPPrtGenten_y; }
			void set(double value) { m_pHeader->m_DPPrtGenten_y = value; }
		}

		/// <summary>
		/// プリンタ出⼒倍率
		/// </summary>
		property double m_dPrtBairitsu {
			double get() { return m_pHeader->m_dPrtBairitsu; }
			void set(double value) { m_pHeader->m_dPrtBairitsu = value; }
		}

		/// <summary>
		/// プリンタ90°回転出⼒、プリンタ出⼒基準点位置
		/// ●⼀位︓プリンタ90°回転出⼒
		/// ●⼗位︓プリンタ出⼒基準点位置の指定（0 : 無指定）（Ver.3.00以降）
		/// 7 : 左上 8 : 中上 9 : 右上
		/// 4 : 左中 5 : 中中 6 : 右中
		/// 1 : 左下 2 : 中下 3 : 右下
		/// </summary>
		property int m_nPrtSet {
			int get() { return m_pHeader->m_nPrtSet; }
			void set(int value) { m_pHeader->m_nPrtSet = value; }
		}

		property int m_nMemoriMode {
			int get() { return m_pHeader->m_nMemoriMode; }
			void set(int value) { m_pHeader->m_nMemoriMode = value; }
		}
		property double m_dMemoriHyoujiMin {
			double get() { return m_pHeader->m_dMemoriHyoujiMin; }
			void set(double value) { m_pHeader->m_dMemoriHyoujiMin = value; }
		}
		property double m_dMemoriX {
			double get() { return m_pHeader->m_dMemoriX; }
			void set(double value) { m_pHeader->m_dMemoriX = value; }
		}
		property double m_dMemoriY {
			double get() { return m_pHeader->m_dMemoriY; }
			void set(double value) { m_pHeader->m_dMemoriY = value; }
		}
		property double m_DpMemoriKijunTen_x {
			double get() { return m_pHeader->m_DpMemoriKijunTen_x; }
			void set(double value) { m_pHeader->m_DpMemoriKijunTen_x = value; }
		}
		property double m_DpMemoriKijunTen_y {
			double get() { return m_pHeader->m_DpMemoriKijunTen_y; }
			void set(double value) { m_pHeader->m_DpMemoriKijunTen_y = value; }
		}
		property double m_dKageLevel {
			double get() { return m_pHeader->m_dKageLevel; }
			void set(double value) { m_pHeader->m_dKageLevel = value; }
		}
		property double m_dKageIdo {
			double get() { return m_pHeader->m_dKageIdo; }
			void set(double value) { m_pHeader->m_dKageIdo = value; }
		}
		property int m_nKage9_15JiFlg {
			int get() { return m_pHeader->m_nKage9_15JiFlg; }
			void set(int value) { m_pHeader->m_nKage9_15JiFlg = value; }
		}
		property double m_dKabeKageLevel {
			double get() { return m_pHeader->m_dKabeKageLevel; }
			void set(double value) { m_pHeader->m_dKabeKageLevel = value; }
		}
		property double m_dTenkuuZuLevel {
			double get() { return m_pHeader->m_dTenkuuZuLevel; }
			void set(double value) { m_pHeader->m_dTenkuuZuLevel = value; }
		}
		property double m_dTenkuuZuEnkoR {
			double get() { return m_pHeader->m_dTenkuuZuEnkoR; }
			void set(double value) { m_pHeader->m_dTenkuuZuEnkoR = value; }
		}
		property int m_nMMTani3D {
			int get() { return m_pHeader->m_nMMTani3D; }
			void set(int value) { m_pHeader->m_nMMTani3D = value; }
		}

		/// <summary>
		/// 保存時の画⾯倍率(読込むと前画⾯倍率になる)
		/// </summary>
		property double m_dBairitsu {
			double get() { return m_pHeader->m_dBairitsu; }
			void set(double value) { m_pHeader->m_dBairitsu = value; }
		}
		/// <summary>
		/// 保存時の画⾯倍率原点（X）？(読込むと前画⾯倍率になる)
		/// </summary>
		property double m_DPGenten_x {
			double get() { return m_pHeader->m_DPGenten_x; }
			void set(double value) { m_pHeader->m_DPGenten_x = value; }
		}
		/// <summary>
		/// 保存時の画⾯倍率原点（Y）？(読込むと前画⾯倍率になる)
		/// </summary>
		property double m_DPGenten_y {
			double get() { return m_pHeader->m_DPGenten_y; }
			void set(double value) { m_pHeader->m_DPGenten_y = value; }
		}

		property double m_dHanniBairitsu {
			double get() { return m_pHeader->m_dHanniBairitsu; }
			void set(double value) { m_pHeader->m_dHanniBairitsu = value; }
		}
		property double m_DPHanniGenten_x {
			double get() { return m_pHeader->m_DPHanniGenten_x; }
			void set(double value) { m_pHeader->m_DPHanniGenten_x = value; }
		}
		property double m_DPHanniGenten_y {
			double get() { return m_pHeader->m_DPHanniGenten_y; }
			void set(double value) { m_pHeader->m_DPHanniGenten_y = value; }
		};

		property WrapArray<double>^ m_dZoomJumpBairitsuint {
			WrapArray<double>^ get() {
				return _m_dZoomJumpBairitsu;
			}
		};

		property WrapArray<double>^ m_DPZoomJumpGenten_x {
			WrapArray<double>^ get() {
				return _m_DPZoomJumpGenten_x;
			}
		};

		property WrapArray<double>^ m_DPZoomJumpGenten_y {
			WrapArray<double>^ get() {
				return _m_DPZoomJumpGenten_y;
			}
		};

		property WrapArray<DWORD>^ m_nZoomJumpGLay {
			WrapArray<DWORD>^ get() {
				return _m_nZoomJumpGLay;
			}
		};


		/// <summary>
		/// (Ver.4.04以前はダミー）//⽂字列範囲を背景⾊で描画するときの範囲増寸法
		/// </summary>
		property double m_dMojiBG {
			double get() { return m_pHeader->m_dMojiBG; }
			void set(double value) { m_pHeader->m_dMojiBG = value; }
		}

		/// <summary>
		/// (Ver.4.04以前はダミー）
		/// ⼗位:⽂字（寸法図形､ブロック図形）を最後に描画
		/// ⼀位:1 : 輪郭・範囲を背景⾊で描画しない
		/// 2 : ⽂字の輪郭を背景⾊で描画する
		/// 3 : ⽂字列範囲を背景⾊で描画する
		/// </summary>
		property int m_nMojiBG {
			int get() { return m_pHeader->m_nMojiBG; }
			void set(int value) { m_pHeader->m_nMojiBG = value; }
		}

		/// <summary>
		/// 複線間隔 (size=10)
		/// </summary>
		property WrapArray<double>^ m_adFukusenSuuchi {
			WrapArray<double>^ get() {
				return _m_adFukusenSuuchi;
			}
		};
			
		/// <summary>
		/// 両側複線の留線出の寸法
		/// </summary>
		property double m_dRyoygawaFukusenTomeDe {
			double get() { return m_pHeader->m_dRyoygawaFukusenTomeDe; }
			void set(double value) { m_pHeader->m_dRyoygawaFukusenTomeDe = value; }
		}

		/// <summary>
		/// ⾊番号ごとの画⾯表⽰⾊
		/// 画⾯表⽰⾊(0︓背景⾊、1〜8︓線⾊、9︓グレー⾊)
		/// (size=10)
		/// </summary>
		property WrapArray<DWORD>^ m_aPenColor {
			WrapArray<DWORD>^ get() {
				return _m_aPenColor;
			}
		};

		/// <summary>
		/// ⾊番号ごとの画⾯表⽰線幅
		/// 線幅(1〜16)
		/// (size=10)
		/// </summary>
		property WrapArray<DWORD>^ m_anPenWidth {
			WrapArray<DWORD>^ get() {
				return _m_anPenWidth;
			}
		};

		/// <summary>
		/// ⾊番号ごとのプリンタ出⼒⾊
		/// プリンタ出⼒⾊(0︓背景⾊、1〜8︓線⾊、9︓グレー⾊)
		/// (size=10)
		/// </summary>
		property WrapArray<DWORD>^ m_aPrtPenColor {
			WrapArray<DWORD>^ get() {
				return _m_aPrtPenColor;
			}
		};

		/// <summary>
		/// ⾊番号ごとのプリンタ線幅
		/// 線幅(1〜500)
		/// (size=10)
		/// </summary>
		property WrapArray<DWORD>^ m_anPrtPenWidth {
			WrapArray<DWORD>^ get() {
				return _m_anPrtPenWidth;
			}
		};

		/// <summary>
		/// ⾊番号ごとのプリンタ実点半径
		/// 実点半径(0.1〜10)
		/// (size=10)
		/// </summary>
		property WrapArray<double>^ m_adPrtTenHankei {
			WrapArray<double>^ get() {
				return _m_adPrtTenHankei;
			}
		};

		/// <summary>
		/// 線種番号2から9までのパターン
		/// (size=8)
		/// </summary>
		property WrapArray<DWORD>^ m_alLType {
			WrapArray<DWORD>^ get() {
				return _m_alLType;
			}
		};

		/// <summary>
		/// 線種番号2から9までの1ユニットのドット数
		/// (size=8)
		/// </summary>
		property WrapArray<DWORD>^ m_anTokushuSenUintDot {
			WrapArray<DWORD>^ get() {
				return _m_anTokushuSenUintDot;
			}
		};

		/// <summary>
		/// 線種番号2から9までのピッチ
		/// (size=8)
		/// </summary>
		property WrapArray<DWORD>^ m_anTokushuSenPich {
			WrapArray<DWORD>^ get() {
				return _m_anTokushuSenPich;
			}
		};

		/// <summary>
		/// 線種番号2から9までのプリンタ出⼒ピッチ
		/// (size=8)
		/// </summary>
		property WrapArray<DWORD>^ m_anPrtTokushuSenPich {
			WrapArray<DWORD>^ get() {
				return _m_anPrtTokushuSenPich;
			}
		};

		/// <summary>
		/// ランダム線1から5までのパターン
		/// (size=5)
		/// </summary>
		property WrapArray<DWORD>^ m_alLType_Rnd {
			WrapArray<DWORD>^ get() {
				return _m_alLType_Rnd;
			}
		};

		/// <summary>
		/// ランダム線1から5までの画⾯表⽰振幅
		/// (size=5)
		/// </summary>
		property WrapArray<DWORD>^ m_anRandSenWide_Rnd {
			WrapArray<DWORD>^ get() {
				return _m_anRandSenWide_Rnd;
			}
		};

		/// <summary>
		/// ランダム線1から5までのピッチ
		/// (size=5)
		/// </summary>
		property WrapArray<DWORD>^ m_anTokushuSenPich_Rnd {
			WrapArray<DWORD>^ get() {
				return _m_anTokushuSenPich_Rnd;
			}
		};

		/// <summary>
		/// ランダム線1から5までのプリンタ出⼒振幅
		/// (size=5)
		/// </summary>
		property WrapArray<DWORD>^ m_anPrtRandSenWide_Rnd {
			WrapArray<DWORD>^ get() {
				return _m_anPrtRandSenWide_Rnd;
			}
		};

		/// <summary>
		/// ランダム線1から5までのプリンタ出⼒ピッチ
		/// (size=5)
		/// </summary>
		property WrapArray<DWORD>^ m_anPrtTokushuSenPich_Rnd {
			WrapArray<DWORD>^ get() {
				return _m_anPrtTokushuSenPich_Rnd;
			}
		};

		/// <summary>
		/// 倍⻑線種番号6から9までのパターン
		/// (size=4)
		/// </summary>
		property WrapArray<DWORD>^ m_alLType_Double {
			WrapArray<DWORD>^ get() {
				return _m_alLType_Double;
			}
		};

		/// <summary>
		/// 倍⻑線種番号6から9までの1ユニットのドット数
		/// (size=4)
		/// </summary>
		property WrapArray<DWORD>^ m_anTokushuSenUintDot_Double {
			WrapArray<DWORD>^ get() {
				return _m_anTokushuSenUintDot_Double;
			}
		};

		/// <summary>
		/// 倍⻑線種番号6から9までのピッチ
		/// (size=4)
		/// </summary>
		property WrapArray<DWORD>^ m_anTokushuSenPich_Double {
			WrapArray<DWORD>^ get() {
				return _m_anTokushuSenPich_Double;
			}
		};

		/// <summary>
		/// 倍⻑線種番号6から9までのプリンタ出⼒ピッチ
		/// (size=4)
		/// </summary>
		property WrapArray<DWORD>^ m_anPrtTokushuSenPich_Double {
			WrapArray<DWORD>^ get() {
				return _m_anPrtTokushuSenPich_Double;
			}
		};

		/// <summary>
		/// 実点を画⾯描画時の指定半径で描画
		/// </summary>
		property int m_nDrawGamenTen {
			int get() { return m_pHeader->m_nDrawGamenTen; }
			void set(int value) { m_pHeader->m_nDrawGamenTen = value; }
		};

		/// <summary>
		/// 実点をプリンタ出⼒時、指定半径で書く
		/// </summary>
		property int m_nDrawPrtTen {
			int get() { return m_pHeader->m_nDrawPrtTen; }
			void set(int value) { m_pHeader->m_nDrawPrtTen = value; }
		};

		/// <summary>
		/// BitMap・ソリッドを最初に描画する //⼗位︓ソリッド描画順
		/// </summary>
		property int m_nBitMapFirstDraw {
			int get() { return m_pHeader->m_nBitMapFirstDraw; }
			void set(int value) { m_pHeader->m_nBitMapFirstDraw = value; }
		};

		/// <summary>
		/// 逆描画
		/// </summary>
		property int m_nGyakuDraw {
			int get() { return m_pHeader->m_nGyakuDraw; }
			void set(int value) { m_pHeader->m_nGyakuDraw = value; }
		};

		/// <summary>
		/// 逆サーチ
		/// </summary>
		property int m_nGyakuSearch {
			int get() { return m_pHeader->m_nGyakuSearch; }
			void set(int value) { m_pHeader->m_nGyakuSearch = value; }
		};

		/// <summary>
		/// カラー印刷
		/// </summary>
		property int m_nColorPrint {
			int get() { return m_pHeader->m_nColorPrint; }
			void set(int value) { m_pHeader->m_nColorPrint = value; }
		}

		/// <summary>
		/// レイヤ順の印刷
		/// </summary>
		property int m_nLayJunPrint {
			int get() { return m_pHeader->m_nLayJunPrint; }
			void set(int value) { m_pHeader->m_nLayJunPrint = value; }
		}

		/// <summary>
		/// ⾊番号順の印刷
		/// </summary>
		property int m_nColJunPrint {
			int get() { return m_pHeader->m_nColJunPrint; }
			void set(int value) { m_pHeader->m_nColJunPrint = value; }
		}

		/// <summary>
		/// レイヤグループまたはレイヤごとのプリンタ連続出⼒指定
		/// </summary>
		property int m_nPrtRenzoku {
			int get() { return m_pHeader->m_nPrtRenzoku; }
			void set(int value) { m_pHeader->m_nPrtRenzoku = value; }
		}

		/// <summary>
		/// プリンタ共通レイヤ(表⽰のみレイヤ)のグレー出⼒指定
		/// </summary>
		property int m_nPrtKyoutsuuGray {
			int get() { return m_pHeader->m_nPrtKyoutsuuGray; }
			void set(int value) { m_pHeader->m_nPrtKyoutsuuGray = value; }
		}

		/// <summary>
		/// プリンタ出⼒時に表⽰のみレイヤは出⼒しない
		/// Ver.6.00以降は印刷時における既定線⾊の線幅の基準値の「dpi」。
		/// </summary>
		property int m_nPrtDispOnlyNonDraw {
			int get() { return m_pHeader->m_nPrtDispOnlyNonDraw; }
			void set(int value) { m_pHeader->m_nPrtDispOnlyNonDraw = value; }
		}

		/// <summary>
		/// 作図時間（Ver.2.23以降）
		/// </summary>
		property int m_lnDrawTime {
			int get() { return m_pHeader->m_lnDrawTime; }
			void set(int value) { m_pHeader->m_lnDrawTime = value; }
		}

		/// <summary>
		/// 2.5Dの始点位置が設定されている時のフラグ（Ver.2.23以降）
		/// ● ⼀位︓透視図の視点位置設定済みフラグ
		/// ● ⼗位︓⿃瞰図の視点位置設定済みフラグ
		/// ● 百位︓アイソメ図の視点位置設定済みフラグ
		/// </summary>
		property int nEyeInit {
			int get() { return m_pHeader->nEyeInit; }
			void set(int value) { m_pHeader->nEyeInit = value; }
		}

		/// <summary>
		/// 2.5Dの透視図の視点⽔平角（Ver.2.23以降）
		/// </summary>
		property int m_dEye_H_Ichi_1 {
			int get() { return m_pHeader->m_dEye_H_Ichi_1; }
			void set(int value) { m_pHeader->m_dEye_H_Ichi_1 = value; }
		}
		/// <summary>
		/// 2.5Dの⿃瞰図の視点⽔平角（Ver.2.23以降）
		/// </summary>
		property int m_dEye_H_Ichi_2 {
			int get() { return m_pHeader->m_dEye_H_Ichi_2; }
			void set(int value) { m_pHeader->m_dEye_H_Ichi_2 = value; }
		}
		/// <summary>
		/// 2.5Dのアイソメ図の視点⽔平角（Ver.2.23以降）
		/// </summary>
		property int m_dEye_H_Ichi_3 {
			int get() { return m_pHeader->m_dEye_H_Ichi_3; }
			void set(int value) { m_pHeader->m_dEye_H_Ichi_3 = value; }
		}

		/// <summary>
		/// 2.5Dの透視図の視点⾼さ（Ver.2.23以降）
		/// </summary>
		property double m_dEye_Z_Ichi_1 {
			double get() { return m_pHeader->m_dEye_Z_Ichi_1; }
			void set(double value) { m_pHeader->m_dEye_Z_Ichi_1 = value; }
		}
		/// <summary>
		/// 2.5Dの透視図の視点離れ（Ver.2.23以降）
		/// </summary>
		property double m_dEye_Y_Ichi_1 {
			double get() { return m_pHeader->m_dEye_Y_Ichi_1; }
			void set(double value) { m_pHeader->m_dEye_Y_Ichi_1 = value; }
		}

		/// <summary>
		/// 2.5Dの⿃瞰図の視点⾼さ（Ver.2.23以降）
		/// </summary>
		property double m_dEye_Z_Ichi_2 {
			double get() { return m_pHeader->m_dEye_Z_Ichi_2; }
			void set(double value) { m_pHeader->m_dEye_Z_Ichi_2 = value; }
		}
		/// <summary>
		/// 2.5Dの⿃瞰図の視点離れ（Ver.2.23以降）
		/// </summary>
		property double m_dEye_Y_Ichi_2 {
			double get() { return m_pHeader->m_dEye_Y_Ichi_2; }
			void set(double value) { m_pHeader->m_dEye_Y_Ichi_2 = value; }
		}

		/// <summary>
		/// 2.5Dのアイソメ図の視点垂直角（Ver.2.23以降）
		/// </summary>
		property double m_dEye_V_Ichi_3 {
			double get() { return m_pHeader->m_dEye_V_Ichi_3; }
			void set(double value) { m_pHeader->m_dEye_V_Ichi_3 = value; }
		}

		/// <summary>
		/// 線の⻑さ指定の最終値（Ver.2.25以降）
		/// </summary>
		property double m_dSenNagasaSnpou {
			double get() { return m_pHeader->m_dSenNagasaSnpou; }
			void set(double value) { m_pHeader->m_dSenNagasaSnpou = value; }
		}

		/// <summary>
		/// 矩形寸法 横寸法指定の最終値（Ver.2.25以降）
		/// </summary>
		property double m_dBoxSunpouX {
			double get() { return m_pHeader->m_dBoxSunpouX; }
			void set(double value) { m_pHeader->m_dBoxSunpouX = value; }
		}

		/// <summary>
		/// 矩形寸法 縦寸法指定の最終値（Ver.2.25以降）
		/// </summary>
		property double m_dBoxSunpouY {
			double get() { return m_pHeader->m_dBoxSunpouY; }
			void set(double value) { m_pHeader->m_dBoxSunpouY = value; }
		}
		
		/// <summary>
		/// 円の半径指定の最終値（Ver.2.25以降）
		/// </summary>
		property double m_dEnHankeiSnpou {
			double get() { return m_pHeader->m_dEnHankeiSnpou; }
			void set(double value) { m_pHeader->m_dEnHankeiSnpou = value; }
		}

		/// <summary>
		/// ソリッドを任意⾊で書くフラグ（Ver.2.30以降）
		/// </summary>
		property int m_nSolidNinniColor {
			int get() { return m_pHeader->m_nSolidNinniColor; }
			void set(int value) { m_pHeader->m_nSolidNinniColor = value; }
		}
		/// <summary>
		/// ソリッドの任意⾊の既定値（Ver.2.30以降）
		/// </summary>
		property int m_SolidColor {
			int get() { return m_pHeader->m_SolidColor; }
			void set(int value) { m_pHeader->m_SolidColor = value; }
		}

		/// <summary>
		/// SXF対応拡張線⾊定義（Ver.4.20以降）画⾯表⽰⾊
		/// (size=257)
		/// </summary>
		property WrapArray<DWORD>^ m_aPenColor_SXF {
			WrapArray<DWORD>^ get() {
				return _m_aPenColor_SXF;
			}
		};

		/// <summary>
		/// SXF対応拡張線⾊定義（Ver.4.20以降）画⾯表⽰線幅
		/// (size=257)
		/// </summary>
		property WrapArray<DWORD>^ m_anPenWidth_SXF {
			WrapArray<DWORD>^ get() {
				return _m_anPenWidth_SXF;
			}
		};

		/// <summary>
		/// SXF対応拡張線⾊定義（Ver.4.20以降）線⾊名
		/// (size=257)
		/// </summary>
		property CStringArray^ m_astrUDColorName_SXF {
			CStringArray^ get() {
				return _m_astrUDColorName_SXF;
			}
		}

		/// <summary>
		/// SXF対応拡張線⾊定義（Ver.4.20以降）プリンタ出⼒⾊
		/// (size=257)
		/// </summary>
		property WrapArray<DWORD>^ m_aPrtPenColor_SXF {
			WrapArray<DWORD>^ get() {
				return _m_aPrtPenColor_SXF;
			}
		};

		/// <summary>
		/// SXF対応拡張線⾊定義（Ver.4.20以降）プリンタ出⼒線幅
		/// (size=257)
		/// </summary>
		property WrapArray<DWORD>^ m_anPrtPenWidth_SXF {
			WrapArray<DWORD>^ get() {
				return _m_anPrtPenWidth_SXF;
			}
		};

		/// <summary>
		/// SXF対応拡張線⾊定義（Ver.4.20以降）点半径
		/// (size=257)
		/// </summary>
		property WrapArray<double>^ m_adPrtTenHankei_SXF {
			WrapArray<double>^ get() {
				return _m_adPrtTenHankei_SXF;
			}
		};

		/// <summary>
		/// SXF対応拡張線種定義（Ver.4.20以降）パターン
		/// (size=33)
		/// </summary>
		property WrapArray<DWORD>^ m_alLType_SXF {
			WrapArray<DWORD>^ get() {
				return _m_alLType_SXF;
			}
		};

		/// <summary>
		/// SXF対応拡張線種定義（Ver.4.20以降）1ユニットのドット数
		/// (size=33)
		/// </summary>
		property WrapArray<DWORD>^ m_anTokushuSenUintDot_SXF {
			WrapArray<DWORD>^ get() {
				return _m_anTokushuSenUintDot_SXF;
			}
		};

		/// <summary>
		/// SXF対応拡張線種定義（Ver.4.20以降）ピッチ
		/// (size=33)
		/// </summary>
		property WrapArray<DWORD>^ m_anTokushuSenPich_SXF {
			WrapArray<DWORD>^ get() {
				return _m_anTokushuSenPich_SXF;
			}
		};

		/// <summary>
		/// SXF対応拡張線種定義（Ver.4.20以降）プリンタ出⼒ピッチ
		/// (size=33)
		/// </summary>
		property WrapArray<DWORD>^ m_anPrtTokushuSenPich_SXF {
			WrapArray<DWORD>^ get() {
				return _m_anPrtTokushuSenPich_SXF;
			}
		};

		/// <summary>
		/// SXF対応拡張線種定義（Ver.4.20以降）線種名
		/// (size=33)
		/// </summary>
		property CStringArray^ m_astrUDLTypeName_SXF {
			CStringArray^ get() {
				return _m_astrUDLTypeName_SXF;
			}
		}

		/// <summary>
		/// SXF対応拡張線種定義（Ver.4.20以降）セグメント数
		/// (size=33)
		/// </summary>
		property WrapArray<DWORD>^ m_anUDLTypeSegment_SXF {
			WrapArray<DWORD>^ get() {
				return _m_anUDLTypeSegment_SXF;
			}
		};

		/// <summary>
		/// SXF対応拡張線種定義（Ver.4.20以降）ピッチ線分の⻑さ、空⽩⻑さの繰り返し
		/// (size=33x10)
		/// </summary>
		property array<WrapArray<double>^>^ m_aadUDLTypePitch_SXF {
			array<WrapArray<double>^>^ get() {
				return _m_aadUDLTypePitch_SXF;
			}
		};

		/// <summary>
		/// ⽂字種1から10までの⽂字幅
		/// (size=10)
		/// </summary>
		property WrapArray<double>^ m_adMojiX {
			WrapArray<double>^ get() {
				return _m_adMojiX;
			}
		};

		/// <summary>
		/// ⽂字種1から10までの⾼さ
		/// (size=10)
		/// </summary>
		property WrapArray<double>^ m_adMojiY {
			WrapArray<double>^ get() {
				return _m_adMojiY;
			}
		};

		/// <summary>
		/// ⽂字種1から10までの間隔
		/// (size=10)
		/// </summary>
		property WrapArray<double>^ m_adMojiD {
			WrapArray<double>^ get() {
				return _m_adMojiD;
			}
		};

		/// <summary>
		/// ⽂字種1から10までの⾊番号
		/// (size=10)
		/// </summary>
		property WrapArray<DWORD>^ m_anMojiCol {
			WrapArray<DWORD>^ get() {
				return _m_anMojiCol;
			}
		};

		/// <summary>
		/// 書込み⽂字の⽂字幅
		/// </summary>
		property double m_dMojiSizeX {
			double get() { return m_pHeader->m_dMojiSizeX; }
			void set(double value) { m_pHeader->m_dMojiSizeX = value; }
		};
		/// <summary>
		/// 書込み⽂字の⾼さ
		/// </summary>
		property double m_dMojiSizeY {
			double get() { return m_pHeader->m_dMojiSizeY; }
			void set(double value) { m_pHeader->m_dMojiSizeY = value; }
		};
		/// <summary>
		/// 書込み⽂字の間隔
		/// </summary>
		property double m_dMojiKankaku {
			double get() { return m_pHeader->m_dMojiKankaku; }
			void set(double value) { m_pHeader->m_dMojiKankaku = value; }
		};
		/// <summary>
		/// 書込み⽂字の⾊番号
		/// </summary>
		property int m_nMojiColor {
			int get() { return m_pHeader->m_nMojiColor; }
			void set(int value) { m_pHeader->m_nMojiColor = value; }
		};
		/// <summary>
		/// 書込み⽂字の⽂字番号
		/// </summary>
		property int m_nMojiShu {
			int get() { return m_pHeader->m_nMojiShu; }
			void set(int value) { m_pHeader->m_nMojiShu = value; }
		};

		/// <summary>
		/// ⽂字位置整理の⾏間
		/// </summary>
		property double m_dMojiSeiriGyouKan {
			double get() { return m_pHeader->m_dMojiSeiriGyouKan; }
			void set(double value) { m_pHeader->m_dMojiSeiriGyouKan = value; }
		};
		/// <summary>
		/// ⽂字位置整理の⽂字数
		/// </summary>
		property double m_dMojiSeiriSuu {
			double get() { return m_pHeader->m_dMojiSeiriSuu; }
			void set(double value) { m_pHeader->m_dMojiSeiriSuu = value; }
		};

		/// <summary>
		/// ⽂字基準点のずれ位置使⽤のフラグ
		/// </summary>
		property int m_nMojiKijunZureOn {
			int get() { return m_pHeader->m_nMojiKijunZureOn; }
			void set(int value) { m_pHeader->m_nMojiKijunZureOn = value; }
		};

		/// <summary>
		/// ⽂字基準点の横⽅向のずれ位置左、中、右
		/// (size=3)
		/// </summary>
		property WrapArray<double>^ m_adMojiKijunZureX {
			WrapArray<double>^ get() {
				return _m_adMojiKijunZureX;
			}
		};

		/// <summary>
		/// ⽂字基準点の縦⽅向のずれ位置下、中、上
		/// (size=3)
		/// </summary>
		property WrapArray<double>^ m_adMojiKijunZureY {
			WrapArray<double>^ get() {
				return _m_adMojiKijunZureY;
			}
		};

	internal:
		CJwwHeader* GetNativeHeader() {
			return m_pHeader;
		}

	};

}