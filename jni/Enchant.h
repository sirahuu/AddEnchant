#pragma once

#include <vector>
#include <memory>

class Entity;
class Mob;
class EntityDamageSource;
class ItemInstance;

class Enchant{
public:
 int enchantId; //4
 int idk1; //8
 int toolId; //12
 int idk2;//16
 int frequency;//20
 std::string category;//24
 std::string name;//28
 
 static std::vector<std::unique_ptr<Enchant>> mEnchants;

 Enchant(int,int,std::string const&,const std::string&,int,int);
 virtual ~Enchant();

 virtual bool canEnchant(ItemInstance const&) const;
 virtual bool canEnchant(int) const;
 virtual bool canPrimaryEnchant(ItemInstance const&) const;
 virtual bool canPrimaryEnchant(int) const;
 virtual bool canSecondaryEnchant(ItemInstance const&) const;
 virtual bool canSecondaryEnchant(int) const;
 virtual void doPostAttack(Mob &,Mob &,int) const;
 virtual void doPostHurt(ItemInstance &,Mob &,Mob &,int) const;
 virtual int getDamageBonus(int,Entity const&) const;
 virtual int getDamageProtection(int,EntityDamageSource const&) const;
 virtual std::string& getDescription() const;
 virtual int getFrequency() const;
 virtual int getMaxCost(int) const;
 virtual int getMaxLevel() const;
 virtual int getMinCost(int) const;
 virtual int getMinLevel() const;
 virtual bool isCompatibleWith(int) const;
 virtual bool isMeleeDamageEnchant() const;
 virtual bool isProtectionEnchant() const;
 
 std::string& getStringId() const;
 
 void teardownEnchants();

 static void initEnchants();
};