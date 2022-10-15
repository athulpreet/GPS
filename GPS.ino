#define RESET A3
#define FORCE_ON A2
#define VBACKP 11

int i=0;
int k=0;
int flag=0;

int doller_flag=0;
int g_flag=0;
int n_flag=0;
int r_flag=0;
int m_flag=0;
int c_flag=0;

char ch[800];
char str[800];
char alt[10];
char A[10];
char loni[10];
char dir1[10];
char lati[10];
int hh=0;
int hh1=0;
int hh2=0;
int hh3=0;
int hh4=0;

char data[60]={0};
void setup() {

// put your setup code here, to run once:*

//Initialize serial and wait for port to open:*

// Initialize serial devices at 9600 bauds*

Serial.begin(9600);


// Wait for the serial device to be ready

while (!Serial);



//$GNRMC,072658.000,A,1304.6715,N,07733.5600,E,0.00,10.93,280922,,,D*43
//$GNRMC,060624.000,A,1304.6318,N,07733.5747,E,0.00,259.83,290922,,,A*7A





}
void loop()
{



int bb;
int j=0;

for(i=0;i<=799;i++){
while(Serial.available()==0);
ch[i]=Serial.read();



}
flag=1;

for(j=0;j<=799;j++){
  str[j]=ch[j];
  }
if(flag==1){
  flag=0;

//93231.000,A,1304.6651,N,07733.5559,E,0.00,63.01,141022,,,A*0
//93231.000,A,1304.6651,N,07733.5559,E,0.00,63.01,141022,,,A*0
//93231.000,A,1304.6651,N,07733.5559,E,0.00,63.01,141022,,,A*0

  //linear search algorithm begins***************************************************
  
for(k=0;k<=799;k++){//

//Serial.print(str[k]);

/*

*/

  if(str[k]=='$'){
    doller_flag=1;
k++;
    if((str[k]=='G')&&(doller_flag==1)){
    doller_flag=0;
    g_flag=1;
k++;

     if((str[k]=='N')&&(g_flag==1)){
      g_flag=0;
      n_flag=1;

k++;


      if((str[k]=='R')&&(n_flag==1)){
        
        n_flag=0;
        r_flag=1;
 k++;
 if((str[k]=='M')&&(r_flag==1)){
  r_flag=0;
  m_flag=1;

k++;
if((str[k]=='C')&&(m_flag==1)){
 m_flag=0;
 c_flag=1;

k++;



if(c_flag==0){data[60]={0};}
if(c_flag==1){
c_flag=0;
for(bb=0;bb<60;bb++){
k++;
data[bb]=str[k];
}}}}}}}}}}



hh=0;
hh1=0;
hh2=0;
hh3=0;
hh4=0;
  while(data[hh]!=','){
    hh++;
  alt[hh]=data[hh];
  }
  hh++;
  while(data[hh]!=','){
    hh1++;
    hh++;
    A[hh1]=data[hh];
    }
    hh++;
 while(data[hh]!=','){
  hh2++;
  hh++;
    loni[hh2]=data[hh];
    }
    hh++;
     while(data[hh]!=','){
      hh3++;
      hh++;
    dir1[hh3]=data[hh];
    }
    hh++;
     while(data[hh]!=','){
      hh4++;
      hh++;
    lati[hh4]=data[hh];
    }
  
  
  
for(int dd=1;dd<9;dd++){
 
Serial.print(loni[dd]);

//Serial.print(c_flag);
//Serial.print(str[dd]);
//if(dd==00)Serial.println(" ");
}



Serial.print(" ");


for(int dd=0;dd<9;dd++){
 
Serial.print(lati[dd]);

//Serial.print(c_flag);
//Serial.print(str[dd]);
//if(dd==00)Serial.println(" ");
}



Serial.println("");
}








