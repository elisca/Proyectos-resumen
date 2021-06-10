VERSION 5.00
Begin VB.Form Form1 
   BackColor       =   &H00C0FFFF&
   Caption         =   "Conversor de unidades (Temperatura)"
   ClientHeight    =   2010
   ClientLeft      =   120
   ClientTop       =   450
   ClientWidth     =   3135
   Icon            =   "Form1.frx":0000
   LinkTopic       =   "Form1"
   MaxButton       =   0   'False
   ScaleHeight     =   2010
   ScaleWidth      =   3135
   StartUpPosition =   3  'Windows Default
   Begin VB.Frame Frame1 
      BackColor       =   &H00C0FFFF&
      Height          =   1935
      Left            =   120
      TabIndex        =   0
      Top             =   0
      Width           =   2895
      Begin VB.TextBox Txt_Temp 
         Alignment       =   2  'Center
         BeginProperty Font 
            Name            =   "MS Sans Serif"
            Size            =   8.25
            Charset         =   0
            Weight          =   700
            Underline       =   0   'False
            Italic          =   0   'False
            Strikethrough   =   0   'False
         EndProperty
         Height          =   285
         Index           =   0
         Left            =   1680
         TabIndex        =   3
         Text            =   "0"
         Top             =   360
         Width           =   975
      End
      Begin VB.TextBox Txt_Temp 
         Alignment       =   2  'Center
         BeginProperty Font 
            Name            =   "MS Sans Serif"
            Size            =   8.25
            Charset         =   0
            Weight          =   700
            Underline       =   0   'False
            Italic          =   0   'False
            Strikethrough   =   0   'False
         EndProperty
         Height          =   285
         Index           =   1
         Left            =   1680
         TabIndex        =   2
         Text            =   "0"
         Top             =   720
         Width           =   975
      End
      Begin VB.ComboBox Cmb_Conversion 
         Appearance      =   0  'Flat
         Height          =   315
         ItemData        =   "Form1.frx":000C
         Left            =   1680
         List            =   "Form1.frx":0022
         TabIndex        =   1
         Text            =   "[Selecc]"
         Top             =   1200
         Width           =   975
      End
      Begin VB.Label Label1 
         AutoSize        =   -1  'True
         BackStyle       =   0  'Transparent
         Caption         =   "Paulo_17"
         BeginProperty Font 
            Name            =   "MS Sans Serif"
            Size            =   8.25
            Charset         =   0
            Weight          =   700
            Underline       =   -1  'True
            Italic          =   0   'False
            Strikethrough   =   0   'False
         EndProperty
         ForeColor       =   &H00FF0000&
         Height          =   195
         Left            =   120
         TabIndex        =   7
         Top             =   1650
         Width           =   810
      End
      Begin VB.Line Line1 
         X1              =   120
         X2              =   2760
         Y1              =   1080
         Y2              =   1080
      End
      Begin VB.Label Etiqueta 
         AutoSize        =   -1  'True
         BackStyle       =   0  'Transparent
         Caption         =   "Celsius (°C):"
         BeginProperty Font 
            Name            =   "MS Sans Serif"
            Size            =   8.25
            Charset         =   0
            Weight          =   700
            Underline       =   0   'False
            Italic          =   0   'False
            Strikethrough   =   0   'False
         EndProperty
         Height          =   195
         Index           =   0
         Left            =   240
         TabIndex        =   6
         Top             =   360
         Width           =   1035
      End
      Begin VB.Label Etiqueta 
         AutoSize        =   -1  'True
         BackStyle       =   0  'Transparent
         Caption         =   "Fahrenheit (°F):"
         BeginProperty Font 
            Name            =   "MS Sans Serif"
            Size            =   8.25
            Charset         =   0
            Weight          =   700
            Underline       =   0   'False
            Italic          =   0   'False
            Strikethrough   =   0   'False
         EndProperty
         Height          =   195
         Index           =   1
         Left            =   240
         TabIndex        =   5
         Top             =   720
         Width           =   1320
      End
      Begin VB.Label Etiqueta 
         AutoSize        =   -1  'True
         BackStyle       =   0  'Transparent
         Caption         =   "Conversión:"
         BeginProperty Font 
            Name            =   "MS Sans Serif"
            Size            =   8.25
            Charset         =   0
            Weight          =   700
            Underline       =   0   'False
            Italic          =   0   'False
            Strikethrough   =   0   'False
         EndProperty
         Height          =   195
         Index           =   2
         Left            =   240
         TabIndex        =   4
         Top             =   1200
         Width           =   1005
      End
   End
End
Attribute VB_Name = "Form1"
Attribute VB_GlobalNameSpace = False
Attribute VB_Creatable = False
Attribute VB_PredeclaredId = True
Attribute VB_Exposed = False
Private Declare Function ShellExecute Lib "shell32.dll" Alias "ShellExecuteA" (ByVal hwnd As Long, ByVal lpOperation As String, ByVal lpFile As String, ByVal lpParameters As String, ByVal lpDirectory As String, ByVal nShowCmd As Long) As Long
Dim Etiqueta_Temperatura(2) As String, Form_Ancho As Integer, Form_Alto As Integer

Private Sub Inicializacion()
    Etiqueta_Temperatura(0) = "Celsius (°C):"
    Etiqueta_Temperatura(1) = "Fahrenheit (°F):"
    Etiqueta_Temperatura(2) = "Kelvin (°K):"
    Txt_Temp(1).Locked = True
    Cmb_Conversion.ListIndex = 0
    Form_Ancho = Me.Width
    Form_Alto = Me.Height
End Sub

Private Sub Cmb_Conversion_Click()
    'Cambia las etiquetas de los campos
    Select Case Cmb_Conversion.ListIndex
        Case 0:
            Etiqueta(0).Caption = Etiqueta_Temperatura(0)
            Etiqueta(1).Caption = Etiqueta_Temperatura(1)
        Case 1:
            Etiqueta(0).Caption = Etiqueta_Temperatura(0)
            Etiqueta(1).Caption = Etiqueta_Temperatura(2)
        Case 2:
            Etiqueta(0).Caption = Etiqueta_Temperatura(1)
            Etiqueta(1).Caption = Etiqueta_Temperatura(0)
        Case 3:
            Etiqueta(0).Caption = Etiqueta_Temperatura(1)
            Etiqueta(1).Caption = Etiqueta_Temperatura(2)
        Case 4:
            Etiqueta(0).Caption = Etiqueta_Temperatura(2)
            Etiqueta(1).Caption = Etiqueta_Temperatura(0)
        Case 5:
            Etiqueta(0).Caption = Etiqueta_Temperatura(2)
            Etiqueta(1).Caption = Etiqueta_Temperatura(1)
    End Select

    Call Txt_Temp_Change(0)
End Sub

Private Sub Form_Load()
    Call Inicializacion
End Sub

Private Sub Form_Resize()
    If Me.WindowState <> 1 Then
        Me.Width = Form_Ancho
        Me.Height = Form_Alto
    End If
End Sub

Private Sub Image1_Click(Index As Integer)
    If Index = 3 Then MsgBox "Programa de distribución gratuita. Programado en Septiembre de 2011 por Paulo_17 (VB 6.0)."
End Sub

Private Sub Label1_Click()
    Call ShellExecute(Me.hwnd, "Open", "http://paulo17.webcindario.com/", "", "", 1)
End Sub

Private Sub Txt_Temp_Change(Index As Integer)
    'Comprueba dominio
        'Si eligio como entrada (°C)
    If Cmb_Conversion.ListIndex = 0 Or Cmb_Conversion.ListIndex = 1 Then
        If Val(Txt_Temp(0).Text) >= -273.15 Then
            Txt_Temp(0).BackColor = RGB(255, 255, 255)
        
            If Cmb_Conversion.ListIndex = 0 Then
                '(°C) a (°F)
                Txt_Temp(1).Text = 32 + Val(Txt_Temp(0)) * 1.8
            Else
                '(°C) a (°K)
                Txt_Temp(1).Text = 273.15 + Val(Txt_Temp(0))
            End If
        Else
            Txt_Temp(0).BackColor = RGB(255, 0, 0)
            Txt_Temp(1).Text = "Error!"
        End If
        Exit Sub
    End If

        'Si eligio como entrada (°F)
    If Cmb_Conversion.ListIndex = 2 Or Cmb_Conversion.ListIndex = 3 Then
        If Val(Txt_Temp(0).Text) >= -459.67 Then
            Txt_Temp(0).BackColor = RGB(255, 255, 255)
        
            If Cmb_Conversion.ListIndex = 2 Then
                '(°F) a (°C)
                Txt_Temp(1).Text = (Val(Txt_Temp(0)) - 32) / 1.8
            Else
                '(°F) a (°K)
                Txt_Temp(1).Text = 273.15 + (Val(Txt_Temp(0)) - 32) / 1.8
            End If
        Else
            Txt_Temp(0).BackColor = RGB(255, 0, 0)
            Txt_Temp(1).Text = "Error!"
        End If
        Exit Sub
    End If

        'Si eligio como entrada (°K)
    If Cmb_Conversion.ListIndex = 4 Or Cmb_Conversion.ListIndex = 5 Then
        If Val(Txt_Temp(0).Text) >= 0 Then
            Txt_Temp(0).BackColor = RGB(255, 255, 255)
        
            If Cmb_Conversion.ListIndex = 4 Then
                '(°K) a (°C)
                Txt_Temp(1).Text = Val(Txt_Temp(0)) - 273.15
            Else
                '(°K) a (°F)
                Txt_Temp(1).Text = 32 + (Val(Txt_Temp(0)) - 273.15) * 1.8
            End If
        Else
            Txt_Temp(0).BackColor = RGB(255, 0, 0)
            Txt_Temp(1).Text = "Error!"
        End If
        Exit Sub
    End If
End Sub

Private Sub Txt_Temp_KeyPress(Index As Integer, KeyAscii As Integer)
    'Comprueba si el juego de caracteres
    'No permite ingresar caracteres distintos a números
    If KeyAscii < 48 Or KeyAscii > 57 Then
        If KeyAscii <> 46 Then
            If KeyAscii <> 45 Then
                If KeyAscii <> 43 Then
                    KeyAscii = 0
                End If
            End If
        End If
    End If
End Sub
