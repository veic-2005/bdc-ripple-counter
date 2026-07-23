An3048 - register
---

## CLC1

### CLC1GLS0
- LC1G1D1T enabled

### CLC1POL
- LC1G2POL inverted; 
- LC1G3POL inverted; 
- LC1G4POL inverted;

## EUSART1
- CREN disabled;
- SP1BRGL : 0x40
- SP1BRGH : 0x03

## ADCC
- ADPRE ： 0
```
New version of mcc, added.
```
### ADCON2
- ADCRS ： 0x0


## osc

### OSCCON1
- NDIV : 1
```
OSCCON1 = 0x60;
```

## pins
```
    /**
    ANSELx registers
    */
    ANSELD = 0xF1;
    ANSELC = 0x9F;
    ANSELB = 0xE8;
    ANSELE = 0x07;
    ANSELA = 0x0B;
```