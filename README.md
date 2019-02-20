# MEET.ONE sidechain airgrab contract


Contract Account Name.

```
airgrab.m
```

Send Airgrab action on testnet.

```
cleos -u http://sidechain-test.meet.one:8888 push action airgrab.m open '["ACCOUNT_NAME","4,MEETONE","ACCOUNT_NAME"]' -p ACCOUNT_NAME
```

Query current accounts.

```
cleos -u http://sidechain-test.meet.one:8888 get table airgrab.m airgrab.m accounts
```
