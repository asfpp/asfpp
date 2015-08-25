/* <M.T.> This module is currently not used by the attack simuulator */

#ifndef _ADVERSARY_H_
#define _ADVERSARY_H_

#include "CastaliaModule.h"
#include "Entry.h"

using namespace std;

class Adversary: public CastaliaModule {
 
 private:
   
  /* Evaluation of attacks is enabled if TRUE */
  bool attacksEvaluation;
  
  /* List of attacks performed by the adversary */
  vector<Entry*> adversaryAttacks;
  
 protected:
  virtual void initialize();
  virtual void handleMessage(cMessage* msg);
  virtual void finishSpecific();
  void readIniFileParameters(void);
  
  bool activeAttacks() const { return !adversaryAttacks.empty(); }
  void insertAdversaryAttack(Entry* attack) { adversaryAttacks.push_back(attack); }
  vector<Entry*>::const_iterator getAdversaryAttacksIterator() const { return adversaryAttacks.begin(); }
  
 public:
  virtual ~Adversary();
  
};

#endif
