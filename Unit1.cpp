//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "Unit1.h"
#include "Unit2.h"
#include "Unit3.h"
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

int c_q = 0;
int c_a = 0;
int corr_counter = 0;
int c_ua = 0;

void SaveData();
//AnsiString Encoder(AnsiString);

void __fastcall TForm1::Timer1Timer(TObject *Sender)
{
    CGauge1->Progress++;
}
//---------------------------------------------------------------------------

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

    if(c_q < 15) {
        Label1->Caption = "Питання №" + IntToStr(c_q+1);
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
                if(c_a < 44)
                    c_a++;
            }
        }

    //
        if(c_q != 0 && c_q < 6) {
            for(int i = 0; i < 3; i++)
                if(radios[i]->Checked)
                    userans[c_q-1] = i+1;
        }
        else if(c_q < 11) {
            for(int i = 0; i < 3; i++)
                if(checks[i]->Checked)
                    userans[c_q-1] += IntToStr(i+1);
        }
        else if(c_q < 16) {
            for(int i = 0; i < 3; i++)
                userans[c_q-1] += edits[i]->Text;
        }
    //

    //Cleaning up
        for(int i = 0; i < 3; i++) {
            radios[i]->Checked = false;
            checks[i]->Checked = false;
            edits[i]->Text = "";
        }
    //Check correct

        if(c_q != 0 && userans[c_q-1] == correct[c_q])
            Label9->Caption = "Правильних відповідей: " + IntToStr(++corr_counter);
        if(c_q < 16)
            c_q++;
    }
    else if(c_q < 16) {

        for(int i = 0; i < 3; i++)
                userans[c_q-1] += edits[i]->Text;

        for(int i = 0; i < 3; i++) {
            radios[i]->Checked = false;
            checks[i]->Checked = false;
            edits[i]->Text = "";
        }

        if(c_q != 0 && userans[c_q-1] == correct[c_q])
            Label9->Caption = "Правильних відповідей: " + IntToStr(++corr_counter);
        if(c_q < 16)
            c_q++;

        Panel1->Visible = false;
        CGauge1->Visible = false;
        Label10->Visible = true;
        Button2->Visible = false;
        Button3->Visible = true;
        SaveData();
        Memo1->Visible = true;
    }
}
//---------------------------------------------------------------------------

void __fastcall TForm1::FormCreate(TObject *Sender)
{
    Panel1->Visible = false;
    Timer1->Enabled = false;
    Button2->Visible = false;

    c_q = 0;
    c_a = 0;
    corr_counter = 0;
    c_ua = 0;
}
//---------------------------------------------------------------------------

void __fastcall TForm1::Button3Click(TObject *Sender)
{
    Form1->Close();
}
//---------------------------------------------------------------------------

void SaveData() {
    AnsiString user, date, result;
    date = Now().DateString();
    user = Form2->Edit1->Text;
    result = corr_counter;

    AnsiString input[3], output1, output2, output3;
    input[0] = "Тест проходив: " + user;
    input[1] = "Дата проходження: " + date;
    input[2] = "Результат: " + result;

    output1 = Encoder(input[0]);
    output2 = Encoder(input[1]);
    output3 = Encoder(input[2]);

    Form1->Memo1->Lines->Add(output1);
    Form1->Memo1->Lines->Add(output2);
    Form1->Memo1->Lines->Add(output3);

    Form1->Memo2->Lines->LoadFromFile("result.txt");
    Form1->Memo2->Lines->AddStrings(Form1->Memo1->Lines);
    Form1->Memo2->Lines->Add("");


    Form1->Memo2->Lines->SaveToFile("result.txt");
}

AnsiString Encoder(AnsiString input) {
    char* key = "jghtyiopgsregegejohuhygbge";
    int length = input.Length() + 1;

    char* msg = new char[length];
    static AnsiString encoded;

    for(int i = 0; i < input.Length(); i++)
        msg[i] = input.c_str()[i] ^ key[i];

    msg[length - 1] = '\0';
    encoded = msg;
    return encoded;
}
