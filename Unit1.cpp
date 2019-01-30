//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "Unit1.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma link "pies"
#pragma link "CGAUGES"
#pragma resource "*.dfm"
TForm1 *Form1;
//---------------------------------------------------------------------------
__fastcall TForm1::TForm1(TComponent* Owner)
        : TForm(Owner)
{
}
//---------------------------------------------------------------------------


AnsiString questions[15], answers[45], userans[15], correct[16], images[15];


void __fastcall TForm1::Timer1Timer(TObject *Sender)
{
    CGauge1->Progress++;
}
//---------------------------------------------------------------------------

int c_q = 0;
int c_a = 0;
void __fastcall TForm1::Button1Click(TObject *Sender)
{
    FILE* f = fopen("task.txt", "rt");
    char buf[100];
    AnsiString pictr="";

    int count_q = 0, count_a = 0;
    while(!feof(f)){
        fgets(buf, 100, f);
        buf[strlen(buf) - 1] = '\0';

        if((buf[0]=='1'||buf[0]=='2'||buf[0]=='3')&&isdigit(buf[1])) {
            //gets question
            fgets(buf, 100, f);
            buf[strlen(buf) - 1] = '\0';
            questions[count_q] = buf;
            //gets picture
            fgets(buf, 100, f);
            buf[strlen(buf) - 1] = '\0';
            pictr = buf;
            pictr += ".bmp";
            images[count_q] = pictr;
            //gets answer
            for(int i = 0; i < 3; i++) {
                fgets(buf, 100, f);
                buf[strlen(buf) - 1] = '\0';
                answers[count_a++] = buf;
            }
            //gets correct
            fgets(buf, 100, f);
            buf[strlen(buf) - 1] = '\0';
            correct[1 + count_q++] = buf;
        }
    }
    fclose(f);

    Button2Click(Sender);
    Panel1->Visible = true;
    Timer1->Enabled = true;
    Button1->Visible = false;
    Button2->Visible = true;
}
//---------------------------------------------------------------------------

int corr_counter = 0;
int c_ua = 0;

void __fastcall TForm1::Button2Click(TObject *Sender)
{
    TRadioButton* radios[3];
    radios[0] = RadioButton1, radios[1] = RadioButton2, radios[2] = RadioButton3;

    TCheckBox* checks[3];
    checks[0] = CheckBox1, checks[1] = CheckBox2, checks[2] = CheckBox3;

    TEdit* edits[3];
    edits[0] = Edit1, edits[1] = Edit2, edits[2] = Edit3;

    TLabel* labels[3];
    labels[0] = Label3, labels[1] = Label4, labels[2] = Label5;

    TLabel* numerics[3];
    numerics[0] = Label6, numerics[1] = Label7, numerics[2] = Label8;

    Label1->Caption = "������� �" + IntToStr(c_q+1);
    Label2->Caption = questions[c_q];

    if(FileExists(images[c_q])) {
        Image1->Picture->LoadFromFile(images[c_q]);
        Image1->Visible = true;
    }
    else
        Image1->Visible = false;

    if(c_q < 5) {
        for(int i = 0; i < 3; i++) {
            radios[i]->Visible = true;
            checks[i]->Visible = false;
            edits[i]->Visible = false;
            labels[i]->Visible = false;
            numerics[i]->Visible = false;
        }

        for(int i = 0; i < 3; i++) {
            radios[i]->Caption = answers[c_a];

            if(radios[i]->Checked)
                userans[c_ua] = i+1;

            if(c_a < 44)
                c_a++;
        }
    }

    else if(c_q < 10) {
        for(int i = 0; i < 3; i++) {
            radios[i]->Visible = false;
            checks[i]->Visible = true;
            edits[i]->Visible = false;
            labels[i]->Visible = false;
            numerics[i]->Visible = false;
        }

        for(int i = 0; i < 3; i++) {
            checks[i]->Caption = answers[c_a];

            if(checks[i]->Checked)
                userans[c_ua] += IntToStr(i+1);

            if(c_a < 44)
                c_a++;
        }
    }

    else if(c_q < 15) {
        for(int i = 0; i < 3; i++) {
            radios[i]->Visible = false;
            checks[i]->Visible = false;
            edits[i]->Visible = true;
            labels[i]->Visible = true;
            numerics[i]->Visible = true;
        }

        for(int i = 0; i < 3; i++) {
            labels[i]->Caption = answers[c_a];

            userans[c_ua] += edits[i]->Text;

            if(c_a < 44)
                c_a++;
        }
    }

    //Cleaning up
    for(int i = 0; i < 3; i++) {
        radios[i]->Checked = false;
        checks[i]->Checked = false;
        edits[i]->Text = "";
    }
    //Check correct
    if(c_q != 0 && userans[c_ua] == correct[c_q])
        Caption = ++corr_counter;

    if(Sender != Button1)
        c_ua++;
    if(c_q < 14)
        c_q++;
}
//---------------------------------------------------------------------------

void __fastcall TForm1::FormCreate(TObject *Sender)
{
    Panel1->Visible = false;
    Timer1->Enabled = false;
    Button2->Visible = false;
}
//---------------------------------------------------------------------------

