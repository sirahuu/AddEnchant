#include <jni.h>
#include <dlfcn.h>
#include <Substrate.h>

#include "Enchant.h"

void (*_Enchant$initEnchants)();
void Enchant$initEnchants(){
_Enchant$initEnchants();
Enchant::mEnchants.push_back(std::unique_ptr<Enchant>(new Enchant(25,1,"release_Recollection","enchant.releaseRecollection",16,0)));
};

JNIEXPORT jint JNI_OnLoad(JavaVM* vm, void* reserved){
 MSHookFunction((void*)&Enchant::initEnchants,(void*)&Enchant$initEnchants,(void**)&_Enchant$initEnchants);
	return JNI_VERSION_1_2;
}
