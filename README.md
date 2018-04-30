# proof-of-work

A simple proof-of-work demo in C

## About

Two nodes (processes) will mine at the same time, and if one finds the hash value under the target, it sends the result to the other node.
After then, sender and receiver will begin mining to find the next block.
Mining will be continued until the 10th block is mined.

All knowledge to make this comes from [Bitcoin Wiki](https://en.bitcoin.it/wiki/Block_hashing_algorithm).

Merkle tree (and the list of transactions) is not implemented yet, but the hash value of merkle root node can be fed to the block manually.

The library for SHA256 algorithm is brought from B-Con/crypto-algorithms.
Execution of following line would be necessary before build.

```
$ git submodule update --init --recursive
```

## How to run

```
$ make
$ ./main
```

BITS (which determines the difficulty of mining) can be given by option -b.

```
$ ./main -b 0x1d00ffff
```
