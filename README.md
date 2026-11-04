# XOR Encryption Tiny Project
Intended to encrypt a file with a user defined *key* XORed with *raw text*. Ideally the encrypted
text *E* can be decrypted by XORing again with *key*

## Short Proof (Just to Show Off)
From definition,
```math
    E \overset{\text{def}}{=} \text{raw} \oplus \text{key},
```

XORing $E$ (again) with *key* is thus

```math
    \begin{align*}
        E \oplus \text{key} &= (\text{raw} \oplus \text{key}) \oplus \text{key} \\
                               &= \text{raw} \oplus (\text{key} \oplus \text{key}) \\
                               &= \text{raw} \oplus 0   \\
                               &= \text{raw},
    \end{align*}
```

which (theoretically) transformed encrypted message back to its original form ($\text{raw}$ text).
