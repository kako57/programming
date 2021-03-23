#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

struct Action {
  int id, delta0, delta1, delta2, delta3, price, tome_idx, tax_count;
  string type;
  bool castable, repeatable;
  Action(int i, string t, int d0, int d1, int d2, int d3, int p, int ti, int tc, bool c, bool r) {
    id = i;
    type = t;
    delta0 = d0;
    delta1 = d1;
    delta2 = d2;
    delta3 = d3;
    price = p;
    tome_idx = ti;
    tax_count = tc;
    castable = c;
    repeatable = r;
  }
};

struct Agent {
  int inv0, inv1, inv2, inv3, score;
  Agent(int i0, int i1, int i2, int i3, int sc) {
    inv0 = i0;
    inv1 = i1;
    inv2 = i2;
    inv3 = i3;
    score = sc;
  }
};

bool brewable(Action& a, Agent& i) {
  if (a.type != "BREW") return false;
  return a.delta0 + i.inv0 >= 0 && a.delta1 + i.inv1 >= 0 && a.delta2 + i.inv2 >= 0 && a.delta3 + i.inv3 >= 0;
}

int main()
{
  // game loop
  while (1) {
    vector<Action> actions;

    int actionCount; // the number of spells and recipes in play
    cin >> actionCount; cin.ignore();
    for (int i = 0; i < actionCount; i++) {
      int actionId; // the unique ID of this spell or recipe
      string actionType; // in the first league: BREW; later: CAST, OPPONENT_CAST, LEARN, BREW
      int delta0; // tier-0 ingredient change
      int delta1; // tier-1 ingredient change
      int delta2; // tier-2 ingredient change
      int delta3; // tier-3 ingredient change
      int price; // the price in rupees if this is a potion
      int tomeIndex; // in the first two leagues: always 0; later: the index in the tome if this is a tome spell, equal to the read-ahead tax
      int taxCount; // in the first two leagues: always 0; later: the amount of taxed tier-0 ingredients you gain from learning this spell
      bool castable; // in the first league: always 0; later: 1 if this is a castable player spell
      bool repeatable; // for the first two leagues: always 0; later: 1 if this is a repeatable player spell
      cin >> actionId >> actionType >> delta0 >> delta1 >> delta2 >> delta3 >> price >> tomeIndex >> taxCount >> castable >> repeatable; cin.ignore();
      actions.push_back(Action(actionId, actionType, delta0, delta1, delta2, delta3, price, tomeIndex, taxCount, castable, repeatable));
    }

    vector<Agent> agents; // my agent, oppenent's agent

    for (int i = 0; i < 2; i++) {
      int inv0; // tier-0 ingredients in inventory
      int inv1;
      int inv2;
      int inv3;
      int score; // amount of rupees
      cin >> inv0 >> inv1 >> inv2 >> inv3 >> score; cin.ignore();
      agents.push_back(Agent(inv0, inv1, inv2, inv3, score));
    }

    bool ok = false;
    int ans = 0, mx = 0;
    for (Action a : actions) {
      if (a.type == "BREW") {
        if (brewable(a, agents[0]) && a.price >= mx) {
          ans = a.id;
          mx = a.price;
        }
      }
    }

    if (ok) {
      cout << "BREW " << ans << endl;
    } else {
      // TODO some consideration for casting spells and resting for next division
      cout << "WAIT" << endl;
    }

    // Write an action using cout. DON'T FORGET THE "<< endl"
    // To debug: cerr << "Debug messages..." << endl;

    // in the first league: BREW <id> | WAIT; later: BREW <id> | CAST <id> [<times>] | LEARN <id> | REST | WAIT
    // cout << "BREW 0" << endl;
  }
}
