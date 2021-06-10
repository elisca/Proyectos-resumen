VERSION 5.00
Begin VB.Form Form1 
   BackColor       =   &H00000000&
   Caption         =   "Regulador de tensión variable LM317"
   ClientHeight    =   4545
   ClientLeft      =   120
   ClientTop       =   450
   ClientWidth     =   7080
   Icon            =   "Form1.frx":0000
   LinkTopic       =   "Form1"
   MaxButton       =   0   'False
   ScaleHeight     =   4545
   ScaleWidth      =   7080
   StartUpPosition =   2  'CenterScreen
   Begin VB.TextBox Text1 
      BeginProperty Font 
         Name            =   "MS Sans Serif"
         Size            =   8.25
         Charset         =   0
         Weight          =   700
         Underline       =   0   'False
         Italic          =   0   'False
         Strikethrough   =   0   'False
      EndProperty
      ForeColor       =   &H00FF0000&
      Height          =   285
      Index           =   3
      Left            =   3600
      Locked          =   -1  'True
      TabIndex        =   14
      Top             =   2280
      Width           =   1575
   End
   Begin VB.CommandButton Command1 
      Caption         =   "Calcular"
      Default         =   -1  'True
      Height          =   375
      Left            =   3960
      TabIndex        =   9
      Top             =   3720
      Width           =   1095
   End
   Begin VB.OptionButton Option1 
      BackColor       =   &H00000000&
      Caption         =   "Resistencia R2"
      ForeColor       =   &H0080FF80&
      Height          =   255
      Index           =   2
      Left            =   3600
      TabIndex        =   8
      Top             =   3240
      Width           =   1575
   End
   Begin VB.OptionButton Option1 
      BackColor       =   &H00000000&
      Caption         =   "Resistencia R1"
      ForeColor       =   &H0080FF80&
      Height          =   255
      Index           =   1
      Left            =   3600
      TabIndex        =   7
      Top             =   3000
      Width           =   1575
   End
   Begin VB.OptionButton Option1 
      BackColor       =   &H00000000&
      Caption         =   "Voltaje de salida"
      ForeColor       =   &H0080FF80&
      Height          =   255
      Index           =   0
      Left            =   3600
      TabIndex        =   6
      Top             =   2760
      Value           =   -1  'True
      Width           =   1575
   End
   Begin VB.TextBox Text1 
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
      Index           =   2
      Left            =   3600
      TabIndex        =   5
      Text            =   "0"
      Top             =   1920
      Width           =   1575
   End
   Begin VB.TextBox Text1 
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
      Left            =   3600
      TabIndex        =   4
      Text            =   "220"
      Top             =   1560
      Width           =   1575
   End
   Begin VB.TextBox Text1 
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
      Left            =   3600
      TabIndex        =   3
      Text            =   "1,25"
      Top             =   1200
      Width           =   1575
   End
   Begin VB.Label Label1 
      AutoSize        =   -1  'True
      BackStyle       =   0  'Transparent
      Caption         =   "Voltaje entrada:"
      BeginProperty Font 
         Name            =   "MS Sans Serif"
         Size            =   8.25
         Charset         =   0
         Weight          =   700
         Underline       =   0   'False
         Italic          =   0   'False
         Strikethrough   =   0   'False
      EndProperty
      ForeColor       =   &H8000000D&
      Height          =   195
      Index           =   3
      Left            =   1920
      TabIndex        =   13
      Top             =   2280
      Width           =   1365
   End
   Begin VB.Line Line3 
      BorderWidth     =   2
      X1              =   0
      X2              =   7080
      Y1              =   960
      Y2              =   960
   End
   Begin VB.Line Line2 
      BorderColor     =   &H8000000D&
      BorderWidth     =   2
      X1              =   1800
      X2              =   5400
      Y1              =   3600
      Y2              =   3600
   End
   Begin VB.Line Line1 
      BorderColor     =   &H8000000D&
      BorderWidth     =   2
      X1              =   1800
      X2              =   5400
      Y1              =   2640
      Y2              =   2640
   End
   Begin VB.Image Image2 
      Height          =   780
      Left            =   120
      Top             =   1560
      Width           =   1440
   End
   Begin VB.Label Label3 
      AutoSize        =   -1  'True
      BackStyle       =   0  'Transparent
      Caption         =   "Calculadora para chip LM317"
      BeginProperty Font 
         Name            =   "MS Sans Serif"
         Size            =   18
         Charset         =   0
         Weight          =   700
         Underline       =   0   'False
         Italic          =   0   'False
         Strikethrough   =   0   'False
      EndProperty
      ForeColor       =   &H00FFFFFF&
      Height          =   435
      Left            =   1080
      TabIndex        =   12
      Top             =   240
      Width           =   5100
   End
   Begin VB.Label Label2 
      BackColor       =   &H8000000D&
      Height          =   975
      Left            =   0
      TabIndex        =   11
      Top             =   0
      Width           =   7215
   End
   Begin VB.Label Label1 
      AutoSize        =   -1  'True
      BackStyle       =   0  'Transparent
      Caption         =   "Deseo despejar:"
      BeginProperty Font 
         Name            =   "MS Sans Serif"
         Size            =   8.25
         Charset         =   0
         Weight          =   700
         Underline       =   0   'False
         Italic          =   0   'False
         Strikethrough   =   0   'False
      EndProperty
      ForeColor       =   &H8000000D&
      Height          =   195
      Index           =   4
      Left            =   1920
      TabIndex        =   10
      Top             =   2760
      Width           =   1395
   End
   Begin VB.Label Label1 
      AutoSize        =   -1  'True
      BackStyle       =   0  'Transparent
      Caption         =   "Resistencia R2:"
      BeginProperty Font 
         Name            =   "MS Sans Serif"
         Size            =   8.25
         Charset         =   0
         Weight          =   700
         Underline       =   0   'False
         Italic          =   0   'False
         Strikethrough   =   0   'False
      EndProperty
      ForeColor       =   &H8000000D&
      Height          =   195
      Index           =   2
      Left            =   1920
      TabIndex        =   2
      Top             =   1920
      Width           =   1365
   End
   Begin VB.Label Label1 
      AutoSize        =   -1  'True
      BackStyle       =   0  'Transparent
      Caption         =   "Resistencia R1:"
      BeginProperty Font 
         Name            =   "MS Sans Serif"
         Size            =   8.25
         Charset         =   0
         Weight          =   700
         Underline       =   0   'False
         Italic          =   0   'False
         Strikethrough   =   0   'False
      EndProperty
      ForeColor       =   &H8000000D&
      Height          =   195
      Index           =   1
      Left            =   1920
      TabIndex        =   1
      Top             =   1560
      Width           =   1365
   End
   Begin VB.Label Label1 
      AutoSize        =   -1  'True
      BackStyle       =   0  'Transparent
      Caption         =   "Voltaje de salida:"
      BeginProperty Font 
         Name            =   "MS Sans Serif"
         Size            =   8.25
         Charset         =   0
         Weight          =   700
         Underline       =   0   'False
         Italic          =   0   'False
         Strikethrough   =   0   'False
      EndProperty
      ForeColor       =   &H8000000D&
      Height          =   195
      Index           =   0
      Left            =   1920
      TabIndex        =   0
      Top             =   1200
      Width           =   1485
   End
   Begin VB.Image Image1 
      Height          =   3840
      Left            =   0
      Picture         =   "Form1.frx":000C
      Top             =   960
      Width           =   1440
   End
End
Attribute VB_Name = "Form1"
Attribute VB_GlobalNameSpace = False
Attribute VB_Creatable = False
Attribute VB_PredeclaredId = True
Attribute VB_Exposed = False
        'Vout = 1.25 * (1 + R2 / R1)
        'Resist_1 = R2 / (Vout / 1.25 - 1)
        'Resist_2 = (Vout / 1.25 - 1) * R1

Option Explicit

Dim Opcion As Byte

Private Sub Command1_Click()
    Select Case Opcion
        Case 0:
            Text1(0).Text = Dominio_Definicion(0, CDbl(Text1(1).Text), CDbl(Text1(2).Text), 0)
        Case 1:
            Text1(1).Text = Dominio_Definicion(CDbl(Text1(0).Text), 0, CDbl(Text1(2).Text), 1)
        Case 2:
            Text1(2).Text = Dominio_Definicion(CDbl(Text1(0).Text), CDbl(Text1(1).Text), 0, 2)
        Case 3:
            Text1(3).Text = "Desde " & CDbl(Text1(0).Text) + 3 & " a 37V"
        Case Else
            Call Error_Interno_Programa
    End Select
End Sub

Private Sub Form_Load()
    'Procedimiento de inicialización obligatorio
    Option1_Click (0)
    Text1_Change (0)
End Sub

Private Sub Form_Resize()
    If Me.WindowState <> 1 Then
        Me.Height = 5115
        Me.Width = 7320
    End If
End Sub

Private Sub Option1_Click(Index As Integer)
    'NOTA: bloquear textbox del resultado segun opcion elegida
    
    Dim x As Byte
    
    For x = 0 To 2
        If Index = x Then
            Text1(x).Locked = True
        Else
            Text1(x).Locked = False
        End If
    Next x
    
    Opcion = Index
    
    Text1_Change (0)
End Sub

Private Sub Text1_Change(Index As Integer)
    Select Case Opcion
        Case 0:
            If Len(Text1(1).Text) > 0 And Len(Text1(2).Text) > 0 Then
                Command1.Enabled = True
            Else
                Command1.Enabled = False
            End If
        Case 1:
            If Len(Text1(0).Text) > 0 And Len(Text1(2).Text) > 0 Then
                Command1.Enabled = True
            Else
                Command1.Enabled = False
            End If
        Case 2:
            If Len(Text1(0).Text) > 0 And Len(Text1(1).Text) > 0 Then
                Command1.Enabled = True
            Else
                Command1.Enabled = False
            End If
        Case Else
            Call Error_Interno_Programa
    End Select
End Sub
