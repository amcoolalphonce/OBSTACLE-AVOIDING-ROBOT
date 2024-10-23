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
}