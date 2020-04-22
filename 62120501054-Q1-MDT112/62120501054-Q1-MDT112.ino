void setup(){
   
    Serial.begin(9600); 
    pinMode(2,INPUT_PULLUP); 


    for(int led = 3 ; led <= 13 ;led++){
        pinMode(led,OUTPUT);
    }
    tone(8,200,500); 
    delay(250); 
    tone(8,400,100); 
    
}

int L = 3 , T = 100, C = 1;

void loop()
{
    for(L = 3 ; L <= 13 ; L ++){ 
        if(L == 8){
            digitalWrite(L,0);
            continue;
        }
        digitalWrite(L,1); 
        delay(T);
        digitalWrite(L,0); 

        if ( digitalRead(2) == 0 ){
            
            
            C = C * 2;
            T = T / 2;
            Serial.println("Faster X 2 (Current Speed : X" + String(C) + ")");
            tone(8,400,100);
            
            delay(700);
        }
        else  {
        }

    }
    for(L = 13 ; L >= 3 ; L--) 
    {
        if(L == 8){
            digitalWrite(L,0); 
            continue;
        }
        digitalWrite(L,1); 
        delay(T);
        digitalWrite(L,0); 

        if ( digitalRead(2) == 0 ){
            
            
            
            C = C * 2;
            Serial.println("Faster X 2 (Current Speed : X" + String(C) + ")");
            tone(8,400,100);
            T = T / 2;
            delay(700);
            
            
        }
        else  
        {
            
        }
    }
}