object Form1: TForm1
  Left = 408
  Top = 142
  Width = 754
  Height = 514
  Caption = 'Test'
  Color = clBtnFace
  Font.Charset = DEFAULT_CHARSET
  Font.Color = clWindowText
  Font.Height = -11
  Font.Name = 'MS Sans Serif'
  Font.Style = []
  OldCreateOrder = False
  Position = poScreenCenter
  OnCreate = FormCreate
  PixelsPerInch = 96
  TextHeight = 13
  object CGauge1: TCGauge
    Left = 696
    Top = 8
    Width = 36
    Height = 457
    Kind = gkVerticalBar
    ForeColor = clFuchsia
  end
  object Label10: TLabel
    Left = 272
    Top = 152
    Width = 142
    Height = 24
    Caption = #1058#1077#1089#1090' '#1087#1088#1086#1081#1076#1077#1085#1086'!'
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clWindowText
    Font.Height = -19
    Font.Name = 'MS Sans Serif'
    Font.Style = []
    ParentFont = False
    Visible = False
  end
  object Panel1: TPanel
    Left = 8
    Top = 8
    Width = 681
    Height = 257
    TabOrder = 0
    object Label1: TLabel
      Left = 16
      Top = 8
      Width = 32
      Height = 13
      Caption = 'Label1'
    end
    object Label2: TLabel
      Left = 16
      Top = 32
      Width = 32
      Height = 13
      Caption = 'Label2'
    end
    object Image1: TImage
      Left = 456
      Top = 8
      Width = 201
      Height = 217
      Center = True
      Proportional = True
    end
    object Label9: TLabel
      Left = 16
      Top = 232
      Width = 122
      Height = 13
      Caption = #1055#1088#1072#1074#1080#1083#1100#1085#1080#1093' '#1074#1110#1076#1087#1086#1074#1110#1076#1077#1081': '
    end
    object GroupBox1: TGroupBox
      Left = 16
      Top = 72
      Width = 409
      Height = 145
      Caption = #1042#1072#1088#1110#1072#1085#1090#1080' '#1074#1110#1076#1087#1086#1074#1110#1076#1077#1081
      TabOrder = 0
      object Label3: TLabel
        Left = 168
        Top = 24
        Width = 32
        Height = 13
        Caption = 'Label3'
      end
      object Label4: TLabel
        Left = 168
        Top = 64
        Width = 32
        Height = 13
        Caption = 'Label3'
      end
      object Label5: TLabel
        Left = 168
        Top = 104
        Width = 32
        Height = 13
        Caption = 'Label3'
      end
      object Label6: TLabel
        Left = 5
        Top = 29
        Width = 9
        Height = 13
        Caption = '1.'
      end
      object Label8: TLabel
        Left = 5
        Top = 110
        Width = 9
        Height = 13
        Caption = '3.'
      end
      object Label7: TLabel
        Left = 5
        Top = 71
        Width = 9
        Height = 13
        Caption = '2.'
      end
      object CheckBox1: TCheckBox
        Left = 8
        Top = 24
        Width = 153
        Height = 17
        Caption = 'CheckBox1'
        TabOrder = 0
      end
      object CheckBox3: TCheckBox
        Left = 8
        Top = 104
        Width = 153
        Height = 17
        Caption = 'CheckBox1'
        TabOrder = 1
      end
      object CheckBox2: TCheckBox
        Left = 8
        Top = 64
        Width = 153
        Height = 17
        Caption = 'CheckBox1'
        TabOrder = 2
      end
      object RadioButton1: TRadioButton
        Left = 8
        Top = 24
        Width = 153
        Height = 17
        Caption = 'Radio1'
        TabOrder = 3
      end
      object RadioButton2: TRadioButton
        Left = 8
        Top = 64
        Width = 153
        Height = 17
        Caption = 'Radio1'
        TabOrder = 4
      end
      object RadioButton3: TRadioButton
        Left = 8
        Top = 104
        Width = 153
        Height = 17
        Caption = 'Radio1'
        TabOrder = 5
      end
      object Edit1: TEdit
        Left = 16
        Top = 24
        Width = 25
        Height = 21
        TabOrder = 6
      end
      object Edit2: TEdit
        Left = 16
        Top = 64
        Width = 25
        Height = 21
        TabOrder = 7
      end
      object Edit3: TEdit
        Left = 16
        Top = 104
        Width = 25
        Height = 21
        TabOrder = 8
      end
    end
  end
  object Button1: TButton
    Left = 304
    Top = 440
    Width = 81
    Height = 25
    Caption = #1056#1086#1079#1087#1086#1095#1072#1090#1080
    TabOrder = 1
    OnClick = Button1Click
  end
  object Button2: TButton
    Left = 304
    Top = 440
    Width = 81
    Height = 25
    Caption = #1044#1072#1083#1110
    TabOrder = 2
    OnClick = Button2Click
  end
  object Button3: TButton
    Left = 304
    Top = 440
    Width = 81
    Height = 25
    Caption = #1042#1080#1081#1090#1080
    TabOrder = 3
    Visible = False
    OnClick = Button3Click
  end
  object Memo1: TMemo
    Left = 240
    Top = 272
    Width = 209
    Height = 145
    TabOrder = 4
    Visible = False
  end
  object Memo2: TMemo
    Left = 480
    Top = 288
    Width = 41
    Height = 33
    TabOrder = 5
    Visible = False
  end
  object Timer1: TTimer
    OnTimer = Timer1Timer
    Left = 704
    Top = 8
  end
end
