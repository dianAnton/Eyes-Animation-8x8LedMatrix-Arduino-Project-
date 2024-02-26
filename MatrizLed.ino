
// Eye animation in 8x8 Red Led Matrix
// Animación de Ojo en Matriz de Led Rojo 8x8


// Define matrix for each frame ( represent as letters )
// Definir matriz para cada frame ( representado como letras )

byte R[] = { 0x00, 0x3C, 0x72, 0x72, 0x7E, 0x7E, 0x3C, 0x00 };
byte O[] = { 0x00, 0x3C, 0x7E, 0x72, 0x72, 0x7E, 0x3C, 0x00 };
byte B[]=  { 0x00, 0x3C, 0x7E, 0x7E, 0x72, 0x72, 0x3C, 0x00 };
byte A[] = { 0x00, 0x3C, 0x7E, 0x7E, 0x66, 0x66, 0x3C, 0x00 };
byte I[] = { 0x00, 0x3C, 0x7E, 0x7E, 0x4E, 0x4E, 0x3C, 0x00 };
byte W[] = { 0x00, 0x3C, 0x7E, 0x4E, 0x4E, 0x7E, 0x3C, 0x00 }; 
byte Z[]=  { 0x00, 0x3C, 0x4E, 0x4E, 0x7E, 0x7E, 0x3C, 0x00 };
byte N[]=  { 0x00, 0x3C, 0x66, 0x66, 0x7E, 0x7E, 0x3C, 0x00 };
byte T[] = { 0x00, 0x3C, 0x7E, 0x66, 0x66, 0x7E, 0x3C, 0x00 };
byte H[] = { 0x00, 0x00, 0x7E, 0x66, 0x66, 0x7E, 0x3C, 0x00 };
byte C[] = { 0x00, 0x00, 0x00, 0x66, 0x66, 0x7E, 0x3C, 0x00 };
byte D[] = { 0x00, 0x00, 0x00, 0x00, 0x66, 0x7E, 0x3C, 0x00 };
byte E[] = { 0x00, 0x00, 0x00, 0x00, 0x00, 0x7E, 0x3C, 0x00 };
byte F[] = { 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x3C, 0x00 };
byte X[] = { 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x3C, 0x00 };

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////


void setup() 				
    {   for (int j=2; j<19; j++)        //Define each arduino pin - Definimos todos los pines del arduino como salida
         	    pinMode(j, OUTPUT);         
       Serial.begin(9600);
    }

void SetChar(char p) 
{    
     Clear();
     for (int fil = 0; fil <8 ; fil++)
        {
            digitalWrite( fil + 10 , LOW) ; 
            //byte F = N[fil] ;
            byte F = Selecciona( p, fil);
                         
            for (int col =7; col >= 0 ; col--)
                {  
                    digitalWrite(8-col, LOW);     
                    bool b = GetBit(F, col)  ;
                    if (b)
                        digitalWrite( 9 - col  ,HIGH); 
                    else
                        digitalWrite( 9 - col  ,LOW); 

                 }                                    
            digitalWrite( fil + 10 , HIGH) ;             
          }
}

 
bool GetBit( byte N, int pos)
{                              
    int b = N >> pos ;         // Shift bits
    b = b & 1 ;                
    return b ;
}
void Clear()
{
   for (int j=2; j<10; j++)  
        digitalWrite(j, LOW); 
         
   for (int k= 10 ; k<18 ; k++)
        digitalWrite(k, HIGH);	
 }

 byte Selecciona( char c, byte fil)
{
  if (c == 'R')           return(R[fil]) ;
  if (c == 'O')           return( O[fil]);
  if (c == 'B')           return( B[fil]);
  if (c == 'O')           return( O[fil]);
  if (c == 'T')           return( T[fil]);
  if (c == 'R')           return( R[fil]);
  if (c == 'O')           return( O[fil]);
  if (c == 'N')           return( N[fil]);
  if (c == 'I')           return( I[fil]);
  if (c == 'A')           return( A[fil]);
  if (c == 'W')           return( W[fil]);
  if (c == 'Z')           return( Z[fil]);
  if (c == 'X')           return( X[fil]);
  if (c == 'H')           return( H[fil]);
  if (c == 'C')           return( C[fil]);
  if (c == 'D')           return( D[fil]);
  if (c == 'E')           return( E[fil]);
  if (c == 'F')           return( F[fil]);

     
}

////////////////////////////////////////////////////////////////////

void loop()
{
String s = "ROBAIWZNROBAIWZNTHCDEFXFEDCHTHCDEFXFEDCHTOOOOOOOOOOOOWWWWWWWWWWWWTTTTTTHCDEFXFEDCHTHCDEFXFEDCHT"; ///////////////////////////// This is the order in which the frames are going to be display - Orden en el que los frames se muestran
  int l = s.length();      
  for ( int n = 0; n< l; n++ )
    {
      long t = millis();
      char c = s[n];
      while ( millis()< t+ 100) 
            SetChar(c);

    }
   
  }
  
  
