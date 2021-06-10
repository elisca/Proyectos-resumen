VERSION 5.00
Object = "{F9043C88-F6F2-101A-A3C9-08002B2F49FB}#1.2#0"; "COMDLG32.OCX"
Begin VB.Form Form1 
   BorderStyle     =   1  'Fixed Single
   Caption         =   "Ejecutar"
   ClientHeight    =   2070
   ClientLeft      =   45
   ClientTop       =   330
   ClientWidth     =   5130
   LinkTopic       =   "Form1"
   MaxButton       =   0   'False
   MinButton       =   0   'False
   ScaleHeight     =   2070
   ScaleWidth      =   5130
   StartUpPosition =   3  'Windows Default
   Begin MSComDlg.CommonDialog CommonDialog1 
      Left            =   480
      Top             =   1440
      _ExtentX        =   847
      _ExtentY        =   847
      _Version        =   393216
   End
   Begin VB.CommandButton aceptar 
      Caption         =   "Aceptar"
      Default         =   -1  'True
      Height          =   360
      Left            =   1400
      TabIndex        =   4
      Top             =   1530
      Width           =   1130
   End
   Begin VB.CommandButton cancelar 
      Caption         =   "Cancelar"
      Height          =   360
      Left            =   2610
      TabIndex        =   3
      Top             =   1530
      Width           =   1130
   End
   Begin VB.CommandButton examinar 
      Caption         =   "E&xaminar..."
      Height          =   360
      Left            =   3820
      TabIndex        =   2
      Top             =   1530
      Width           =   1130
   End
   Begin VB.ComboBox ruta 
      Height          =   315
      Left            =   810
      TabIndex        =   1
      Top             =   900
      Width           =   4125
   End
   Begin VB.Label Label1 
      BackStyle       =   0  'Transparent
      Caption         =   "&Abrir:"
      ForeColor       =   &H00000000&
      Height          =   255
      Left            =   120
      TabIndex        =   0
      Top             =   960
      Width           =   495
   End
   Begin VB.Label Label3 
      BackColor       =   &H8000000B&
      BackStyle       =   0  'Transparent
      Caption         =   "Escriba el nombre de un programa, carpeta, documento o recurso de Internet y Windows lo abrirá."
      ForeColor       =   &H00000000&
      Height          =   390
      Left            =   830
      TabIndex        =   5
      Top             =   300
      Width           =   4100
   End
   Begin VB.Image plantilla 
      Height          =   2205
      Left            =   0
      Top             =   0
      Width           =   5325
   End
End
Attribute VB_Name = "Form1"
Attribute VB_GlobalNameSpace = False
Attribute VB_Creatable = False
Attribute VB_PredeclaredId = True
Attribute VB_Exposed = False
'falta agregar un commondialog y el codigo para que ejecute el programa que abre
Dim programa As String
Dim direct As Boolean

Private Sub aceptar_Click()
If ruta.Text = "" Then Exit Sub
programa = ruta.Text
If direct = False Then
    Shell "C:\windows\" & programa & ".exe"
Else
    Shell ruta.Text
End If
End Sub

Private Sub cancelar_Click()
Unload Me
End Sub

Private Sub examinar_Click()
With CommonDialog1
    .DialogTitle = "Ejecutar programa"
    .Filter = "Archivos ejecutables (*.exe) | *.exe"
    .ShowOpen
End With
ruta.Text = CommonDialog1.FileName
direct = True
End Sub
