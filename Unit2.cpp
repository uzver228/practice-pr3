//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "Unit1.h"
#include "Unit2.h"
#include "Unit3.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TForm2 *Form2;
//---------------------------------------------------------------------------
__fastcall TForm2::TForm2(TComponent* Owner)
        : TForm(Owner)
{
}
//---------------------------------------------------------------------------

void __fastcall TForm2::Button1Click(TObject *Sender)
{
    MainMenu1->Items->Items[0]->Visible = false;
    if(Edit1->Text == "admin" && Edit2->Text == "admin")
        MainMenu1->Items->Items[0]->Visible = true;
    else {
        Form1 = new TForm1(this);
        Form1->ShowModal();
        delete Form1;
    }
}
//---------------------------------------------------------------------------
void __fastcall TForm2::N1Click(TObject *Sender)
{
    Form3 = new TForm3(this);
    Form3->ShowModal();
    delete Form3;
}
//---------------------------------------------------------------------------

void __fastcall TForm2::FormCreate(TObject *Sender)
{
    MainMenu1->Items->Items[0]->Visible = false;
}
//---------------------------------------------------------------------------

