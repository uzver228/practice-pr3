//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "Unit1.h"
#include "Unit2.h"
#include "Unit3.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TForm3 *Form3;
//---------------------------------------------------------------------------
__fastcall TForm3::TForm3(TComponent* Owner)
        : TForm(Owner)
{
}
//---------------------------------------------------------------------------

void __fastcall TForm3::Button1Click(TObject *Sender)
{
    Form3->Close();        
}
//---------------------------------------------------------------------------
void __fastcall TForm3::FormCreate(TObject *Sender)
{
    Memo1->Lines->LoadFromFile("result.txt");
    for(int i = 0; i < Memo1->Lines->Count; i++) {
        Memo2->Lines->Add(Encoder(Memo1->Lines->Strings[i]));
    }

}
//---------------------------------------------------------------------------
