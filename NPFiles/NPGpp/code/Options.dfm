object OptionsForm: TOptionsForm
  Left = 244
  Top = 404
  BorderStyle = bsDialog
  Caption = #1054#1087#1094#1080#1080
  ClientHeight = 200
  ClientWidth = 320
  Color = clBtnFace
  Font.Charset = RUSSIAN_CHARSET
  Font.Color = clWindowText
  Font.Height = -11
  Font.Name = 'Tahoma'
  Font.Style = []
  OldCreateOrder = False
  Position = poMainFormCenter
  OnShow = FormShow
  PixelsPerInch = 96
  TextHeight = 13
  object Button1: TButton
    Left = 80
    Top = 168
    Width = 75
    Height = 25
    Caption = #1044#1072
    ModalResult = 1
    TabOrder = 0
    OnClick = Button1Click
  end
  object Button2: TButton
    Left = 168
    Top = 168
    Width = 75
    Height = 25
    Caption = #1054#1090#1084#1077#1085#1072
    ModalResult = 7
    TabOrder = 1
    OnClick = Button2Click
  end
  object PageControl1: TPageControl
    Left = 8
    Top = 8
    Width = 305
    Height = 153
    ActivePage = TabSheet1
    TabIndex = 0
    TabOrder = 2
    object TabSheet1: TTabSheet
      Caption = #1062#1074#1077#1090#1072
      object Image2: TImage
        Left = 184
        Top = 9
        Width = 81
        Height = 23
      end
      object Image3: TImage
        Left = 184
        Top = 41
        Width = 81
        Height = 23
      end
      object Image4: TImage
        Left = 184
        Top = 73
        Width = 81
        Height = 23
      end
      object Button5: TButton
        Left = 24
        Top = 40
        Width = 137
        Height = 25
        Caption = #1062#1074#1077#1090' '#1089#1077#1090#1082#1080
        TabOrder = 0
        OnClick = Button5Click
      end
      object Button3: TButton
        Left = 24
        Top = 8
        Width = 137
        Height = 25
        Caption = #1060#1086#1085#1086#1074#1099#1081' '#1094#1074#1077#1090' '#1075#1088#1072#1092#1080#1082#1072
        TabOrder = 1
        OnClick = Button3Click
      end
      object Button4: TButton
        Left = 24
        Top = 72
        Width = 137
        Height = 25
        Caption = #1062#1074#1077#1090' '#1086#1089#1077#1081
        TabOrder = 2
        OnClick = Button4Click
      end
      object CheckBox1: TCheckBox
        Left = 32
        Top = 102
        Width = 129
        Height = 17
        Caption = #1087#1086#1082#1072#1079#1099#1074#1072#1090#1100' '#1089#1077#1090#1082#1091
        TabOrder = 3
      end
    end
    object TabSheet2: TTabSheet
      Caption = #1043#1088#1072#1092#1080#1082' '#1087#1086' '#1091#1084#1086#1083#1095'.'
      ImageIndex = 1
      object Image1: TImage
        Left = 184
        Top = 9
        Width = 81
        Height = 23
      end
      object Button7: TButton
        Left = 24
        Top = 8
        Width = 137
        Height = 25
        Caption = #1062#1074#1077#1090' '#1075#1088#1072#1092#1080#1082#1072'...'
        TabOrder = 0
        OnClick = Button7Click
      end
      object CheckBox3: TCheckBox
        Left = 16
        Top = 44
        Width = 129
        Height = 17
        Caption = #1055#1086#1082#1072#1079#1099#1074#1072#1090#1100' '#1075#1088#1072#1092#1080#1082
        TabOrder = 1
      end
      object LineStyle: TRadioGroup
        Left = 8
        Top = 64
        Width = 281
        Height = 49
        Caption = #1057#1090#1080#1083#1100' '#1087#1086#1089#1090#1088#1086#1077#1085#1080#1103
        Columns = 2
        ItemIndex = 1
        Items.Strings = (
          #1058#1086#1095#1082#1080
          #1051#1080#1085#1080#1080)
        TabOrder = 2
      end
      object CheckBox2: TCheckBox
        Left = 160
        Top = 44
        Width = 113
        Height = 17
        Caption = #1057#1083#1091#1095#1072#1081#1085#1099#1081' '#1094#1074#1077#1090
        TabOrder = 3
      end
    end
  end
  object ColorDialog1: TColorDialog
    Ctl3D = True
    Top = 136
  end
end
