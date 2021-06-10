VERSION 5.00
Begin VB.Form Form1 
   BackColor       =   &H00FFFFFF&
   Caption         =   "Generador de frecuencias"
   ClientHeight    =   2145
   ClientLeft      =   120
   ClientTop       =   450
   ClientWidth     =   3000
   Icon            =   "Form1.frx":0000
   LinkTopic       =   "Form1"
   MaxButton       =   0   'False
   ScaleHeight     =   143
   ScaleMode       =   3  'Pixel
   ScaleWidth      =   200
   StartUpPosition =   2  'CenterScreen
   Begin VB.CommandButton Command2 
      Caption         =   "Info"
      Height          =   255
      Left            =   1200
      TabIndex        =   5
      Top             =   1080
      Width           =   735
   End
   Begin VB.Timer Timer1 
      Interval        =   1000
      Left            =   120
      Top             =   960
   End
   Begin VB.CommandButton Command1 
      Caption         =   "Activar"
      Default         =   -1  'True
      Height          =   255
      Left            =   2160
      TabIndex        =   4
      Top             =   1080
      Width           =   735
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
      ForeColor       =   &H00FF0000&
      Height          =   285
      Index           =   1
      Left            =   1800
      TabIndex        =   3
      Text            =   "0"
      Top             =   600
      Width           =   1095
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
      ForeColor       =   &H00FF0000&
      Height          =   285
      Index           =   0
      Left            =   1800
      TabIndex        =   2
      Text            =   "0"
      Top             =   210
      Width           =   1095
   End
   Begin VB.Label Label2 
      Alignment       =   2  'Center
      BackColor       =   &H00FFFFFF&
      BackStyle       =   0  'Transparent
      Caption         =   "No use auriculares ni volúmen de reproducción alto para cuidar su salud auditiva."
      BeginProperty Font 
         Name            =   "MS Sans Serif"
         Size            =   8.25
         Charset         =   0
         Weight          =   700
         Underline       =   0   'False
         Italic          =   0   'False
         Strikethrough   =   0   'False
      EndProperty
      ForeColor       =   &H000000FF&
      Height          =   615
      Left            =   0
      TabIndex        =   6
      Top             =   1560
      Width           =   3015
   End
   Begin VB.Line Line2 
      X1              =   136
      X2              =   136
      Y1              =   72
      Y2              =   88
   End
   Begin VB.Line Line1 
      X1              =   0
      X2              =   200
      Y1              =   104
      Y2              =   104
   End
   Begin VB.Label Label1 
      AutoSize        =   -1  'True
      BackStyle       =   0  'Transparent
      Caption         =   "Duración(ms):"
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
      TabIndex        =   1
      Top             =   600
      Width           =   1170
   End
   Begin VB.Label Label1 
      AutoSize        =   -1  'True
      BackStyle       =   0  'Transparent
      Caption         =   "Frecuencia (Hz):"
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
      TabIndex        =   0
      Top             =   240
      Width           =   1425
   End
   Begin VB.Image Image2 
      Height          =   645
      Left            =   0
      Top             =   1560
      Width           =   8460
   End
End
Attribute VB_Name = "Form1"
Attribute VB_GlobalNameSpace = False
Attribute VB_Creatable = False
Attribute VB_PredeclaredId = True
Attribute VB_Exposed = False
Private Declare Function Beep Lib "kernel32" (ByVal soundFrequency As Long, ByVal soundDuration As Long) As Long

Private Sub Command1_Click()
    Dim A As Long
    
    On Error Resume Next
    
    Command1.Enabled = False
    
    A = Beep(CLng(Text1(0).Text), CLng(Text1(1).Text))
    
    If A = 0 Then
        MsgBox "Error al invocar a la función ""Beep"" de Windows.", vbCritical, "Error"
    End If
    
    Timer1.Interval = CInt(Text1(1).Text)
End Sub

Private Sub Command2_Click()
    MsgBox "Utilice este programa para simular los tonos de frecuencia fija que haría un buzzer. Puede generar frecuencias desde 37 Hz hasta 32767 Hz con este programa." & Chr(13) & Chr(13) & "ADVERTENCIA!!! Utilice un volumen moderado del altavoz de su computadora, y bajo ningun concepto utilice auriculares, para evitar daños a su sistema auditivo. Algunas frecuencias pueden resultar nocivas." & Chr(13) & Chr(13) & Chr(13) & "Versión del programa: " & App.Major & "." & App.Minor & "." & App.Revision & Chr(13) & Chr(13) & "Autor: Ezequiel Lisca", vbInformation, "Generador de frecuencias: Información"
End Sub

Private Sub Form_Load()
    Call Text1_Change(0)
End Sub

Private Sub Form_Resize()
    If Me.WindowState <> 1 Then
        Me.Width = 3240
        Me.Height = 2730
    End If
End Sub

Private Sub Text1_Change(Index As Integer)
    Call Activar_Controles
End Sub

Private Sub Activar_Controles()
    Dim Habilitar_Boton As Boolean
    
    Habilitar_Boton = True

    If Val(Text1(0).Text) >= 37 And Val(Text1(0).Text) <= 32767 Then
        'Dominio de frecuencia respetado
        Text1(0).BackColor = RGB(255, 255, 255)
    Else
        'Dominio de frecuencia sin respetar
        Text1(0).BackColor = RGB(255, 0, 0)
        Habilitar_Boton = False
    End If

    If Val(Text1(1).Text) > 0 Then
        'Dominio de frecuencia respetado
        Text1(1).BackColor = RGB(255, 255, 255)
    Else
        'Dominio de frecuencia sin respetar
        Text1(1).BackColor = RGB(255, 0, 0)
        Habilitar_Boton = False
    End If

    If Habilitar_Boton = True Then
        Command1.Enabled = True
    Else
        Command1.Enabled = False
    End If
End Sub

Private Sub Text1_KeyPress(Index As Integer, KeyAscii As Integer)
    'No permite ingresar caracteres distintos a números
    If KeyAscii < 48 Or KeyAscii > 57 Then
        If KeyAscii <> 46 Then KeyAscii = 0
    End If
End Sub

Private Sub Timer1_Timer()
    Command1.Enabled = True
End Sub
