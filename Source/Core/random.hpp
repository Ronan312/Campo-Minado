#pragma once
#include <cstdint>
#include <random>

class Random{

        public:

            static void Seed(uint_fast32_t seed = 0){
                Random::engine.seed(seed);
            };

            template<typename T>
            static T UniformInteger(T min, T max){
                std::uniform_int_distribution<T> number(min, max);
                return number(engine);
            };

            template<typename T>
            static T UniformReal(T min, T max){
                std::uniform_int_distribution<T> number(min, max);
                return number(engine);
            };

            static bool BernoulliBool(double p){
                std::bernoulli_distribution number(p);
                return number(engine);
            };

        private:
            static std::mt19937 engine;

    };