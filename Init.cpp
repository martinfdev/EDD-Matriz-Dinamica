#include <iostream>
#include "Init.h"

Init::Init(){
    file = new File();
    
    file->readJson(file->ReadFile("configGame.json"));

}
Init::~Init(){}