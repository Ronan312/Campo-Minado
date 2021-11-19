#pragma once
#include <cstdint>
#include <random>

class Random{

        public:

            static void Seed(uint_fast32_t seed = 0){

                // Define a seed in random engine generator
                Random::engine.seed(seed);
            
            };

            template<typename T>
            static T UniformInteger(T min, T max){

                // Generate and return a int type random number between minimum and maximum values 
                std::uniform_int_distribution<T> number(min, max);
                return number(engine);

            };

        private:
            static std::mt19937 engine;         // Random Engine

    };