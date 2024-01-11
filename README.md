# CornBurner Beta

Flexfuel adapter for 4 cylinder gasoline engine with indirect injection.

## Instructions

To change GPIO and peripheral parameters, open `stm_config.ioc` using STM32CubeMX.

You need stm32pio: 
```
pip install stm32pio
```

For more details about stm32pio follow: https://github.com/ussserrr/stm32pio

In PlatformIO CLI run:
```
./update_config.sh
```


## Calculation of extra injection time

### Ethanol AFR

Combustion equation is:

$$C_2H_6O + 3 O_2 \rightarrow 3 H_2O + 2 CO_2$$

Molar mass are:<br>

$M_{C_2H_6O} = 46.07g.mol^{-1}$<br>
$M_{O_2} = 32g.mol^{-1}$

Then for 1kg of $C_2H_6O$
$$m_{O_2} = \frac{3 * M_{O_2}}{M_{C_2H_6O}} = 2.08kg$$

Therefore for 1kg of ethanol we need 2.08kg of O<sub>2</sub>
<br>Ambient air composition is 21% of O<sub>2</sub> then

$$AFR_{eth} = \frac{1}{0.21} * 2.08  = 9.90$$

### Gasoline AFR

Avearage value for gasoline is 14.7

$$AFR_{gas} = 14.7$$

### Mix AFR

$P_{eth}$ is ethanol proportion in fuel from 0 to 1

Then

$$AFR_{mix} = AFR_{eth}*P_{eth} + AFR_{gas}*P_{gas}$$

Assuming ethanol and gasoline have the same density

$$P_{gas} = 1 - P_{eth}$$

Extra time coefficient is:

$${\alpha} = \frac{AFR_{gas}}{AFR_{mix}}$$

$T_{ECU}$ is injection time calculated by car ECU and $T_{applied}$ is real injection time provided by the adapter.<br>
Finaly injection time is:
$$T_{applied} = T_{ECU} *{\alpha}$$

### Example values

| Fuel | Ethanol Proportion | AFR | Extra time |
|---|---|---|---|
| SP95 | 0% | 14.7 | 0 |
| E10 | 10% | 14.22 | +3.4% |
| E100 | 100% | 9.9 | +48% |
| E85 | 85% | 10.62 | +38% |
| E65 | 65% | 11.58 | +27% |
| 50/50 | 47.5% | 12.42 | +18% |

50/50 is a mix than contain 50% of SP95E10 and 50% of E85

## Environmental aspect

Let the following gasoline reaction equation be:
$$2 C_8H_{18} + 25 O_2 \rightarrow 18 H_2O + 16 CO_2$$

Molar mass are:<br>

$M_{C_8H_{18}} = 114g.mol^{-1}$<br>
$M_{CO_2} = 44g.mol^{-1}$

Then for 1kg of $C_8H_{18}$<br>

$$m_{CO_2} = \frac{8 * M_{CO_2}}{M_{C_8H_{18}}} = 3.09kg$$

And for 1kg of $C_2H_6O$<br>

$$m_{CO_2} = \frac{2 * M_{CO_2}}{M_{C_2H_6O}} = 1.91kg$$

Gasoline consumption: 8L/100km<br>
Assuming ethanol and gasoline have the same density $\rho = 0.75$<br>

| E85 | Extra Consumption | C02/km | Fossil CO2/km | CO2 Reduction |
|---|---|---|---|---|
| 100% | 38%  | 173g | 38g | -79% |
| 80% | 29%| 176g | 76g | -59% |
| 60% | 20% | 178g | 109g | -41% |
| 40% | 12% | 181g | 137g | -26% |
| 20% | 6% | 183g | 162 | -12% |
| 0% | 0% | 185g | 185g | 0% |

(Many approximations were made during these calculations. They are presented for indicative purposes only and are quite optimistic)

## Economic aspect

Avearage price per liter for fuel in France are 1.75€ for E10, 0.92€ for E85 and Gasole (B7) cost 1.73€<br>
For comparison purposes we will consider also a Diesel car.<br>
Gasoline consumption: 8L/100km<br>
Diesel consumption: 6L/100km

| E85 | Extra Consumption | Gas Equivalent Price | Saving | Diesel |
|---|---|---|---|---|
| 100% | 38%  | 1.27€ | 0.48€ | -1.7% |
| 80% | 29%| 1.40€ | 0.35€ | +11% |
| 60% | 20% | 1.50€ | 0.25€ | +21% |
| 40% | 12% | 1.60€ | 0.15€ | +30% |
| 20% | 6% | 1.68€ | 0.07€ | +39% |
| 0% | 0% | 1.75€ | 0.00€ | +46% |
