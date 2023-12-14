#include <Servo.h>

class Servomotor {
private:
    Servo monServo;

public:
    Servomotor(int brocheServo) {
        monServo.attach(brocheServo);
        initialiser();
    }

    void initialiser() {
        monServo.write(0);
    }

    void tourner(int angle) {
        monServo.write(angle);
    }
};

