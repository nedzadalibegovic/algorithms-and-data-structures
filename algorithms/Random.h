#pragma once
#include <random>
#include <chrono>

class Random {
    unsigned seed;
    std::default_random_engine engine;

public:
    Random() {
        seed = std::chrono::steady_clock::now().time_since_epoch().count();
        engine = std::default_random_engine(seed);
    }

    int integer_default_random() {
        return engine();
    }

    int integer_uniform_distribution(int min = 0, int max = 100) {
        std::uniform_int_distribution<int> distr(min, max);
        return distr(engine);
    }

    int integer_normal_distribution(double mean = 50.0, double deviation = 20.0) {
        std::normal_distribution<double> distr(mean, deviation);
        return distr(engine);
    }

    std::vector<int> integer_vector_uniform(int size, int min = 0, int max = 100) {
        std::vector<int> vctr(size);
        std::generate(vctr.begin(), vctr.end(), [&]() { return integer_uniform_distribution(min, max); });
        return vctr;
    }

    std::vector<int> integer_vector_normal(int size, double mean = 50.0, double deviation = 20.0) {
        std::vector<int> vctr(size);
        std::generate(vctr.begin(), vctr.end(), [&]() { return integer_normal_distribution(mean, deviation); });
        return vctr;
    }
};