#include <eosiolib/eosio.hpp>

CONTRACT airgrabacnts : public eosio::contract {
 public:
  using eosio::contract::contract;

  ACTION open(eosio::name owner, const eosio::symbol& symbol, eosio::name ram_payer) {
    require_auth(ram_payer);

    accounts_table acnts(get_self(), get_self().value);
    auto by_owenr_name = acnts.get_index<"owner"_n>();
    auto owner_it = by_owenr_name.find(owner.value);
    eosio_assert(owner_it == by_owenr_name.cend(), "account already exists.");
    acnts.emplace(ram_payer, [&](auto& a) {
      a.id = acnts.available_primary_key();
      a.owner = owner;
    });
  }
  ACTION deleteacnt(uint64_t id) {
    require_auth(get_self());

    accounts_table acnts(get_self(), get_self().value);
    auto it = acnts.require_find(id, "id not exists.");
    acnts.erase(it);
  }

 private:
  TABLE accounts {
    uint64_t id;
    eosio::name owner;

    uint64_t primary_key() const { return id; }
    uint64_t by_owner_name() const { return owner.value; }

    EOSLIB_SERIALIZE(accounts, (id)(owner))
  };

  typedef eosio::multi_index<
      "accounts"_n, accounts,
      eosio::indexed_by<
          "owner"_n,
          eosio::const_mem_fun<accounts, uint64_t, &accounts::by_owner_name>>>
      accounts_table;
};

EOSIO_DISPATCH(airgrabacnts, (open)(deleteacnt))
