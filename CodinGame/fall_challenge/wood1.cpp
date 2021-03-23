#include <bits/stdc++.h>

using namespace std;

struct Potion {
  int id;
  vector<int> d;
  int price;
};

struct Spell {
  int id;
  vector<int> d;
  bool castable;
};

struct Agent {
  vector<int> inv;
  int score;
};

bool brewable(Potion& r, Agent& a) {
  for (int i = 0; i < 4; i++) {
    if (r.d[i] + a.inv[i] < 0) {
      return false;
    }
  }
  return true;
}

bool min_inc(Agent& a, Spell& s) {
  int m = *min_element(a.inv.begin(), a.inv.end());
  for (int i = 0; i < 4; i++) {
    if (a.inv[i] == m && s.d[i] > 0) {
      return true;
    }
  }
  return false;
}

bool can_cast(Spell& s, Agent& a) {
  cerr << s.castable << endl;
  if (!s.castable) {
    return false;
  }
  int sum = 0;
  for (int i = 0; i < 4; i++) {
    if (s.d[i] + a.inv[i] < 0) {
      return false;
    } else {
      sum += s.d[i] + a.inv[i];
    }
  }
  return sum <= 10;
}

int main()
{
  // game loop
  while (1) {
    vector<Potion> potions;
    vector<Spell> spells;

    int actionCount; // the number of spells and recipes in play
    cin >> actionCount; cin.ignore();
    for (int i = 0; i < actionCount; i++) {
      int actionId; // the unique ID of this spell or recipe
      string actionType; // in the first league: BREW; later: CAST, OPPONENT_CAST, LEARN, BREW
      int d0; // tier-0 ingredient change
      int d1; // tier-1 ingredient change
      int d2; // tier-2 ingredient change
      int d3; // tier-3 ingredient change
      int price; // the price in rupees if this is a potion
      int tomeIndex; // in the first two leagues: always 0; later: the index in the tome if this is a tome spell, equal to the read-ahead tax
      int taxCount; // in the first two leagues: always 0; later: the amount of taxed tier-0 ingredients you gain from learning this spell
      bool castable; // in the first league: always 0; later: 1 if this is a castable player spell
      bool repeatable; // for the first two leagues: always 0; later: 1 if this is a repeatable player spell
      cin >> actionId >> actionType >> d0 >> d1 >> d2 >> d3 >> price >> tomeIndex >> taxCount >> castable >> repeatable; cin.ignore();
      if (actionType == "BREW") {
        potions.push_back(Potion{actionId, vector<int>{d0, d1, d2, d3}, price});
      } else if (actionType == "CAST") {
        spells.push_back(Spell{actionId, vector<int>{d0, d1, d2, d3}, castable});
      }
    }

    vector<Agent> agents; // my agent, oppenent's agent

    for (int i = 0; i < 2; i++) {
      int inv0; // tier-0 ingredients in inventory
      int inv1;
      int inv2;
      int inv3;
      int score; // amount of rupees
      cin >> inv0 >> inv1 >> inv2 >> inv3 >> score; cin.ignore();

      agents.push_back(Agent{vector<int>{inv0, inv1, inv2, inv3}, score});
    }

    Agent me = agents[0];

    int id = 0, best = 0;
    for (Potion p : potions) {
      if (brewable(p, me)) {
        if (p.price > best) {
          id = p.id;
          best = p.price;
        }
      }
    }
    if (id) {
      cout << "BREW " << id << endl;
      continue;
    }

    bool already_done = false;
    for (Spell s : spells) {
      if (can_cast(s, me) && min_inc(me, s)) {
        cout << "CAST " << s.id << endl;
        already_done = true;
        break;
      }
    }

    if (!already_done) {
      cout << "REST" << endl;
    }

    // Write an action using cout. DON'T FORGET THE "<< endl"
    // To debug: cerr << "Debug messages..." << endl;

    // in the first league: BREW <id> | WAIT; later: BREW <id> | CAST <id> [<times>] | LEARN <id> | REST | WAIT
    // cout << "BREW 0" << endl;
  }
}
