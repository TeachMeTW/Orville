g++ -std=gnu++11 -o main       ../main.cpp ../species/eevak.cpp ../species/gelatin.cpp ../species/human.cpp ../species/humanoid.cpp ../species/kaylon.cpp ../species/moclan.cpp -Igoogletest/googletest/include -pthread -Lgoogletest/build/lib -lgtest
g++ -std=gnu++11 -o species_test       species_test.cpp    ../species/eevak.cpp ../species/gelatin.cpp ../species/human.cpp ../species/humanoid.cpp ../species/kaylon.cpp ../species/moclan.cpp -Igoogletest/googletest/include -pthread -Lgoogletest/build/lib -lgtest



