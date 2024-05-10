#include <cmath>

class tween {
public:
    static constexpr float PI = 3.14159265358979323846f;
    static constexpr float PI_2 = PI / 2;

    static float linear(float t) {
        return t;
    }

    static float sine(float t) {
        return sin(t * PI_2);
    }

    static float back(float t) {
        const float c1 = 1.70158f;
        const float c3 = c1 + 1;
        return 1 + c3 * pow(t - 1, 3) + c1 * pow(t - 1, 2);
    }

    static float quad(float t) {
        return t * t;
    }

    static float quart(float t) {
        return pow(t, 4);
    }

    static float quint(float t) {
        return pow(t, 5);
    }

    static float bounce(float t) {
        if (t < 1 / 2.75)
            return 7.5625 * t * t;
        else if (t < 2 / 2.75)
            return 7.5625 * (t -= 1.5 / 2.75) * t + 0.75;
        else if (t < 2.5 / 2.75)
            return 7.5625 * (t -= 2.25 / 2.75) * t + 0.9375;
        else
            return 7.5625 * (t -= 2.625 / 2.75) * t + 0.984375;
    }

    static float elastic(float t) {
        const float c4 = (2 * PI) / 3;
        return t == 0 ? 0 : t == 1 ? 1 : -pow(2, 10 * t - 10) * sin((t * 10 - 10.75) * c4);
    }

    static float exponential(float t) {
        return t == 0 ? 0 : pow(2, 10 * (t - 1));
    }

    static float circular(float t) {
        return 1 - sqrt(1 - t * t);
    }

    static float cubic(float t) {
        return t * t * t;
    }

    static float in(float t, float (*func)(float)) {
        return func(t);
    }

    static float out(float t, float (*func)(float)) {
        return 1 - func(1 - t);
    }

    static float inout(float t, float (*func)(float)) {
        if (t < 0.5)
            return 0.5 * func(2 * t);
        else
            return 0.5 * (2 - func(2 * (1 - t)));
    }
};
