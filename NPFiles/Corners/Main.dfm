object MainForm: TMainForm
  Left = 362
  Top = 134
  BorderStyle = bsSingle
  Caption = #1059#1075#1086#1083#1082#1080'-'#1083#1086#1075#1080#1095#1077#1089#1082#1072#1103' '#1080#1075#1088#1072
  ClientHeight = 434
  ClientWidth = 606
  Color = clBtnFace
  TransparentColorValue = clWhite
  Font.Charset = DEFAULT_CHARSET
  Font.Color = clWindowText
  Font.Height = -11
  Font.Name = 'MS Sans Serif'
  Font.Style = []
  Menu = MainMenu1
  OldCreateOrder = False
  Position = poScreenCenter
  OnCreate = FormCreate
  DesignSize = (
    606
    434)
  PixelsPerInch = 96
  TextHeight = 13
  object A: TLabel
    Left = 37
    Top = 0
    Width = 11
    Height = 16
    Caption = 'A'
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clWindowText
    Font.Height = -13
    Font.Name = 'MS Sans Serif'
    Font.Style = [fsBold]
    ParentFont = False
  end
  object B: TLabel
    Left = 85
    Top = 0
    Width = 11
    Height = 16
    Caption = 'B'
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clWindowText
    Font.Height = -13
    Font.Name = 'MS Sans Serif'
    Font.Style = [fsBold]
    ParentFont = False
  end
  object C: TLabel
    Left = 141
    Top = 0
    Width = 11
    Height = 16
    Caption = 'C'
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clWindowText
    Font.Height = -13
    Font.Name = 'MS Sans Serif'
    Font.Style = [fsBold]
    ParentFont = False
  end
  object D: TLabel
    Left = 189
    Top = 0
    Width = 12
    Height = 16
    Caption = 'D'
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clWindowText
    Font.Height = -13
    Font.Name = 'MS Sans Serif'
    Font.Style = [fsBold]
    ParentFont = False
  end
  object E: TLabel
    Left = 237
    Top = 0
    Width = 11
    Height = 16
    Caption = 'E'
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clWindowText
    Font.Height = -13
    Font.Name = 'MS Sans Serif'
    Font.Style = [fsBold]
    ParentFont = False
  end
  object F: TLabel
    Left = 293
    Top = 0
    Width = 10
    Height = 16
    Caption = 'F'
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clWindowText
    Font.Height = -13
    Font.Name = 'MS Sans Serif'
    Font.Style = [fsBold]
    ParentFont = False
  end
  object G: TLabel
    Left = 341
    Top = 0
    Width = 12
    Height = 16
    Caption = 'G'
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clWindowText
    Font.Height = -13
    Font.Name = 'MS Sans Serif'
    Font.Style = [fsBold]
    ParentFont = False
  end
  object H: TLabel
    Left = 389
    Top = 0
    Width = 12
    Height = 16
    Caption = 'H'
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clWindowText
    Font.Height = -13
    Font.Name = 'MS Sans Serif'
    Font.Style = [fsBold]
    ParentFont = False
  end
  object L1: TLabel
    Left = 8
    Top = 32
    Width = 9
    Height = 16
    Caption = '1'
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clWindowText
    Font.Height = -13
    Font.Name = 'MS Sans Serif'
    Font.Style = [fsBold]
    ParentFont = False
  end
  object L2: TLabel
    Left = 8
    Top = 80
    Width = 9
    Height = 16
    Caption = '2'
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clWindowText
    Font.Height = -13
    Font.Name = 'MS Sans Serif'
    Font.Style = [fsBold]
    ParentFont = False
  end
  object L3: TLabel
    Left = 8
    Top = 136
    Width = 9
    Height = 16
    Caption = '3'
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clWindowText
    Font.Height = -13
    Font.Name = 'MS Sans Serif'
    Font.Style = [fsBold]
    ParentFont = False
  end
  object L4: TLabel
    Left = 8
    Top = 184
    Width = 9
    Height = 16
    Caption = '4'
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clWindowText
    Font.Height = -13
    Font.Name = 'MS Sans Serif'
    Font.Style = [fsBold]
    ParentFont = False
  end
  object L5: TLabel
    Left = 8
    Top = 240
    Width = 9
    Height = 16
    Caption = '5'
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clWindowText
    Font.Height = -13
    Font.Name = 'MS Sans Serif'
    Font.Style = [fsBold]
    ParentFont = False
  end
  object L6: TLabel
    Left = 8
    Top = 288
    Width = 9
    Height = 16
    Caption = '6'
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clWindowText
    Font.Height = -13
    Font.Name = 'MS Sans Serif'
    Font.Style = [fsBold]
    ParentFont = False
  end
  object L7: TLabel
    Left = 8
    Top = 336
    Width = 9
    Height = 16
    Caption = '7'
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clWindowText
    Font.Height = -13
    Font.Name = 'MS Sans Serif'
    Font.Style = [fsBold]
    ParentFont = False
  end
  object L8: TLabel
    Left = 8
    Top = 392
    Width = 9
    Height = 16
    Caption = '8'
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clWindowText
    Font.Height = -13
    Font.Name = 'MS Sans Serif'
    Font.Style = [fsBold]
    ParentFont = False
  end
  object Memo1: TMemo
    Left = 432
    Top = 120
    Width = 167
    Height = 307
    Anchors = [akTop, akRight, akBottom]
    ReadOnly = True
    ScrollBars = ssVertical
    TabOrder = 0
  end
  object Board: TDrawGrid
    Left = 16
    Top = 16
    Width = 414
    Height = 412
    Anchors = [akLeft, akTop, akRight, akBottom]
    Color = clWhite
    ColCount = 8
    DefaultColWidth = 50
    DefaultRowHeight = 50
    DefaultDrawing = False
    FixedCols = 0
    RowCount = 8
    FixedRows = 0
    ParentShowHint = False
    ScrollBars = ssNone
    ShowHint = False
    TabOrder = 1
    OnDrawCell = BoardDrawCell
    OnSelectCell = BoardSelectCell
  end
  object GroupBox1: TGroupBox
    Left = 432
    Top = 8
    Width = 172
    Height = 105
    Anchors = [akTop, akRight]
    Caption = #1057#1090#1072#1090#1091#1089' '#1080#1075#1088#1099':'
    TabOrder = 2
    object Label1: TLabel
      Left = 8
      Top = 16
      Width = 22
      Height = 13
      Caption = #1061#1086#1076':'
    end
    object LabelHod: TLabel
      Left = 88
      Top = 16
      Width = 66
      Height = 13
      Caption = #1062#1074#1077#1090'_'#1080#1075#1088#1086#1082#1072
    end
    object GroupBox2: TGroupBox
      Left = 8
      Top = 32
      Width = 153
      Height = 65
      Caption = #1054#1089#1090#1072#1083#1086#1089#1100' '#1074#1088#1077#1084#1077#1085#1080':'
      TabOrder = 0
      object Label3: TLabel
        Left = 8
        Top = 16
        Width = 45
        Height = 13
        Caption = #1063#1077#1088#1085#1099#1084':'
      end
      object Label4: TLabel
        Left = 8
        Top = 40
        Width = 38
        Height = 13
        Caption = #1041#1077#1083#1099#1084':'
      end
      object Label5: TLabel
        Left = 88
        Top = 16
        Width = 42
        Height = 13
        Caption = '00:30:00'
      end
      object Label6: TLabel
        Left = 88
        Top = 40
        Width = 42
        Height = 13
        Caption = '00:30:00'
      end
    end
  end
  object MainMenu1: TMainMenu
    Left = 120
    Top = 200
    object N1: TMenuItem
      Caption = #1060#1072#1081#1083
      object N3: TMenuItem
        Caption = #1053#1086#1074#1072#1103' '#1080#1075#1088#1072
        OnClick = N3Click
      end
      object N4: TMenuItem
        Caption = #1057#1086#1093#1088#1072#1085#1080#1090#1100' '#1087#1088#1086#1090#1086#1082#1086#1083'...'
        OnClick = N4Click
      end
      object N5: TMenuItem
        Caption = '-'
      end
      object N2: TMenuItem
        Caption = #1042#1099#1093#1086#1076
        OnClick = N2Click
      end
    end
    object Gjvjom1: TMenuItem
      Caption = #1055#1086#1084#1086#1097#1100
      object N6: TMenuItem
        Caption = #1054' '#1087#1088#1086#1075#1088#1072#1084#1084#1077
        OnClick = N6Click
      end
    end
  end
  object Timer1: TTimer
    OnTimer = Timer1Timer
    Left = 192
    Top = 176
  end
  object SaveDialog1: TSaveDialog
    Filter = #1058#1077#1082#1089#1090#1086#1074#1099#1081' '#1092#1072#1081#1083'|*.txt|'#1051#1102#1073#1086#1081' '#1092#1072#1081#1083'|*.*'
    Left = 192
    Top = 112
  end
end
