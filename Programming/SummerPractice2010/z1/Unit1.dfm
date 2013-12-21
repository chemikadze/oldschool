object Form1: TForm1
  Left = 318
  Top = 223
  Width = 388
  Height = 256
  Caption = 'Form1'
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
  object Image1: TImage
    Left = 8
    Top = 8
    Width = 209
    Height = 209
  end
  object Label1: TLabel
    Left = 224
    Top = 8
    Width = 7
    Height = 13
    Caption = 'X'
  end
  object Label2: TLabel
    Left = 224
    Top = 56
    Width = 7
    Height = 13
    Caption = 'Y'
  end
  object Edit1: TEdit
    Left = 224
    Top = 24
    Width = 121
    Height = 21
    TabOrder = 0
    Text = '4'
    OnKeyPress = Edit1KeyPress
  end
  object Edit2: TEdit
    Left = 224
    Top = 72
    Width = 121
    Height = 21
    TabOrder = 1
    Text = '4'
    OnKeyPress = Edit2KeyPress
  end
  object UpDown1: TUpDown
    Left = 344
    Top = 24
    Width = 16
    Height = 24
    Position = 40
    TabOrder = 2
    OnChangingEx = UpDown1ChangingEx
  end
  object UpDown2: TUpDown
    Left = 344
    Top = 72
    Width = 16
    Height = 24
    Position = 40
    TabOrder = 3
    OnChangingEx = UpDown2ChangingEx
  end
  object Button1: TButton
    Left = 256
    Top = 104
    Width = 75
    Height = 25
    Caption = #1042#1099#1093#1086#1076
    TabOrder = 4
    OnClick = Button1Click
  end
end
