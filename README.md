# MEET.ONE sidechain airgrab contract


Contract Account Name.

```
airgrab.m
```

Send Airgrab action.

```
cleos -u https://fullnode.meet.one push action airgrab.m open '["ACCOUNT_NAME","4,MEETONE","ACCOUNT_NAME"]' -p ACCOUNT_NAME
```

Query current accounts.

```
cleos -u https://fullnode.meet.one get table airgrab.m airgrab.m accounts
```
