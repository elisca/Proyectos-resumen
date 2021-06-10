USE[correo-sp-2017]
GO
SET ANSI_NULLS ON
GO
SET QUOTED_IDENTIFIER ON
GO
SET ANSI_PADDING ON
GO
CREATE TABLE[dbo].[Paquetes](
	[id] [int] IDENTITY(1,1)NOT NULL,
	[direccionEntrega] [varchar](500)NOT NULL,
	[trackingID] [varchar](50)NOT NULL,
	[alumno] [varchar](50)NOT NULL,
CONSTRAINT[PK_Paquetes] PRIMARY KEY CLUSTERED
(
	[id] ASC
)WITH (PAD_INDEX = OFF,STATISTICS_NORECOMPUTE = OFF,IGNORE_DUP_KEY = OFF,ALLOW_ROW_LOCKS = ON,ALLOW_PAGE_LOCKS = ON) ON [PRIMARY]) ON [PRIMARY]
GO
SET ANSI_PADDING OFF
GO