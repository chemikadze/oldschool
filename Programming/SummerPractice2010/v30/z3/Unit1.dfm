object Form1: TForm1
  Left = 266
  Top = 162
  Width = 364
  Height = 264
  Caption = 'Form1'
  Color = clBtnFace
  Font.Charset = DEFAULT_CHARSET
  Font.Color = clWindowText
  Font.Height = -11
  Font.Name = 'MS Sans Serif'
  Font.Style = []
  Menu = MainMenu1
  OldCreateOrder = False
  ShowHint = True
  OnCreate = FormCreate
  DesignSize = (
    356
    218)
  PixelsPerInch = 96
  TextHeight = 13
  object Label1: TLabel
    Left = 256
    Top = 8
    Width = 77
    Height = 13
    Caption = #1058#1077#1082#1089#1090' '#1080#1079#1084#1077#1085#1077#1085
  end
  object Memo1: TMemo
    Left = 8
    Top = 32
    Width = 337
    Height = 177
    Anchors = [akLeft, akTop, akRight, akBottom]
    TabOrder = 0
    OnKeyPress = Memo1KeyPress
  end
  object Button1: TButton
    Left = 8
    Top = 0
    Width = 75
    Height = 25
    Caption = #1054#1073#1088#1072#1073#1086#1090#1072#1090#1100
    TabOrder = 1
    OnClick = Button1Click
  end
  object CheckBox1: TCheckBox
    Left = 104
    Top = 8
    Width = 97
    Height = 17
    Caption = #1087#1086#1089#1080#1084#1074#1086#1083#1100#1085#1086
    Checked = True
    State = cbChecked
    TabOrder = 2
  end
  object MainMenu1: TMainMenu
    Left = 248
    Top = 184
    object F1: TMenuItem
      Caption = #1060#1072#1081#1083
      object N1: TMenuItem
        Caption = #1054#1090#1082#1088#1099#1090#1100
        OnClick = N1Click
      end
      object N2: TMenuItem
        Caption = #1057#1086#1093#1088#1072#1085#1080#1090#1100
        OnClick = N2Click
      end
      object N3: TMenuItem
        Caption = #1042#1099#1093#1086#1076
        OnClick = N3Click
      end
    end
  end
  object OpenDialog1: TOpenDialog
    Filter = #1058#1077#1082#1089#1090'|*.txt|'#1051#1102#1073#1086#1081' '#1092#1072#1081#1083'|*.*'
    InitialDir = '.'
    Left = 280
    Top = 184
  end
  object SaveDialog1: TSaveDialog
    Filter = #1058#1077#1082#1089#1090'|*.txt'
    InitialDir = '.'
    Left = 312
    Top = 184
  end
end
