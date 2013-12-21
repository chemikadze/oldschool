object Form1: TForm1
  Left = 192
  Top = 114
  Width = 493
  Height = 245
  Caption = 'Integral calculator'
  Color = clBtnFace
  Font.Charset = DEFAULT_CHARSET
  Font.Color = clWindowText
  Font.Height = -11
  Font.Name = 'MS Sans Serif'
  Font.Style = []
  OldCreateOrder = False
  OnCreate = FormCreate
  PixelsPerInch = 96
  TextHeight = 13
  object Label1: TLabel
    Left = 320
    Top = 40
    Width = 9
    Height = 13
    Caption = 'a:'
  end
  object Label2: TLabel
    Left = 320
    Top = 8
    Width = 9
    Height = 13
    Caption = 'b:'
  end
  object Label3: TLabel
    Left = 320
    Top = 24
    Width = 11
    Height = 16
    Caption = 'S'
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clWindowText
    Font.Height = -15
    Font.Name = 'MS Sans Serif'
    Font.Style = [fsBold]
    ParentFont = False
  end
  object Label4: TLabel
    Left = 320
    Top = 80
    Width = 46
    Height = 13
    Caption = 'Precision:'
  end
  object Label5: TLabel
    Left = 320
    Top = 112
    Width = 20
    Height = 13
    Caption = 'f(x)='
  end
  object Memo1: TMemo
    Left = 0
    Top = 0
    Width = 313
    Height = 209
    TabOrder = 0
  end
  object Edit1: TEdit
    Left = 336
    Top = 32
    Width = 33
    Height = 21
    TabOrder = 1
    Text = '0'
  end
  object Edit3: TEdit
    Left = 376
    Top = 72
    Width = 97
    Height = 21
    TabOrder = 2
    Text = '0,01'
  end
  object Edit4: TEdit
    Left = 336
    Top = 0
    Width = 33
    Height = 21
    TabOrder = 3
    Text = '2'
  end
  object Button1: TButton
    Left = 320
    Top = 128
    Width = 161
    Height = 81
    Caption = 'Calc!'
    TabOrder = 4
    OnClick = Button1Click
  end
  object Edit2: TEdit
    Left = 344
    Top = 104
    Width = 129
    Height = 21
    TabOrder = 5
    Text = '6*x-3*x^2'
  end
end
