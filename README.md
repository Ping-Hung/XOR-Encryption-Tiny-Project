# XOR Encryption Tiny Project
Intended to encrypt a file with a user defined *key* XORed with *raw text*. Ideally the encrypted
text *E* can be decrypted by XORing again with *key*

## Short Proof (Just to Show Off)
From definition,
```math
    E \overset{\text{def}}{=} \text{raw} \bigoplus \text{key},
```

XORing $E$ (again) with *key* is thus

```math
    \begin{align*}
        E \bigoplus \text{key} &= (\text{raw} \bigoplus \text{key}) \bigoplus \text{key} \\
                               &= \text{raw} \bigoplus (\text{key} \bigoplus \text{key}) \\
                               &= \text{raw} \bigoplus 0   \\
                               &= \text{raw},
    \end{align*}
```

which (theoretically) transformed encrypted message back to its original form ($\text{raw}$ text).
