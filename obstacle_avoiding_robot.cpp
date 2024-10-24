const int trigPin = 8;
const int echoPin = 9;

const int relayPin = 7;
const int thresholdDistance = 20; // 20cm


void setup()
{
    Serial.begin(9600);
    pinMode(trigPin, OUTPUT);
    pinMode(echoPin, INPUT);
    pinMode(relayPin, OUTPUT);
    
    digitalWrite(relayPin, HIGH);// turn motor on
}

void loop()
{
    int distance = getDistance();
    Serial.print('Distance : ')
    Serial.print(distance);
    Serial.printIn(" cm");

    //check if an obstacle is detected in the distance
    if(distance < thresholdDistance)
    {
        digitalWrite(relayPin, LOW);
        Serial.printIn("An objected has been detected. Turn motor off");
    }
    else{
        digitalWrite(relayPin, HIGH);
        Serial.printIn("No object detected.");// motor moves
    }
    delay(100);
}
int getDistance()
{
    digitalWrite(trigPin, LOW); // clear the trigger pin
    delayMicroseconds(10);

    digitalWrite(trigPin, HIGH);
    delayMicroseconds(10);
    digitalWrite(trigPin, LOW);

    //READ echo pin abd claculte the duration
    long duration = pulseIn(echoPin, HIGH);
    int distance = duration * 0.034/2;
}