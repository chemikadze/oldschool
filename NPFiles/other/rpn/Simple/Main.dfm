object Form1: TForm1
  Left = 192
  Top = 111
  Width = 364
  Height = 137
  Caption = 'Simple'
  Color = clBtnFace
  Font.Charset = DEFAULT_CHARSET
  Font.Color = clWindowText
  Font.Height = -11
  Font.Name = 'MS Sans Serif'
  Font.Style = []
  OldCreateOrder = False
  OnCreate = FormCreate
  OnDestroy = FormDestroy
  PixelsPerInch = 96
  TextHeight = 13
  object Label1: TLabel
    Left = 8
    Top = 16
    Width = 27
    Height = 13
    Caption = 'Input:'
  end
  object Label2: TLabel
    Left = 8
    Top = 40
    Width = 26
    Height = 13
    Caption = 'RPN:'
  end
  object Label3: TLabel
    Left = 8
    Top = 64
    Width = 33
    Height = 13
    Caption = 'Result:'
  end
  object Edit1: TEdit
    Left = 48
    Top = 8
    Width = 217
    Height = 21
    TabOrder = 0
    Text = '((12+5+7)*(-3))/2'
  end
  object Button1: TButton
    Left = 272
    Top = 8
    Width = 75
    Height = 49
    Caption = 'Calc'
    TabOrder = 1
    OnClick = Button1Click
  end
  object Edit2: TEdit
    Left = 48
    Top = 32
    Width = 217
    Height = 21
    TabOrder = 2
  end
  object Edit3: TEdit
    Left = 48
    Top = 56
    Width = 217
    Height = 21
    TabOrder = 3
  end
end
