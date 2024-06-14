---
pdf-engine: xelatex
header-includes:
- \input{$UNI/.templates/settings/preamble.tex}
- \input{$UNI/.templates/settings/minted_settings.tex}
- \newcommand\Type{\Lab}
- \Work{signals}
- \renewcommand\Variant{5}
- \newcommand\Date{14.\the\month.\the\year}
- \newcommand\Number{3}
- \newcommand\Topic{Дослідження спектрів шумів натурального походження}
---

\input{$UNI/.templates/parts/header.tex}
Дослiдити спектральнi характеристики шумiв натурального походження та порiвняти
Ёх з iдеалiзованими кольоровими шумами.

# Індивідуальне завдання

1. Ознайомтеся з матерiалами презентацiЁ `04_Шум` iз тематики роботи.
2. В робочому пакетi вiдкрийте блокнот `chap_04.ipynb`. Ознайомтеся з поясненнями
   та прикладами, що до нього входять.
3. Сформуйте новий блокнот для виконання робочого завдання. Завантажте .wav
   файл iз записом шуму вiдповiдно до варiанту завдання. Утворiть з нього вейв,
   прослухайте аудiо та побудуйте часову дiаграму.
4. Видiлiть 3-4 фрагменти вейву довжиною близько 0.5 с для рiзних моментiв
   часу. Побудуйте спектри сигналу для цих фрагментiв.
5. Порiвняйте отриманi спектральнi характеристики, дайте загальний опис
   характерних особливостей спектру дослiджуваного шуму.

# Виконання

## Завантаження запису шуму та підготовка до роботи

```python
import numpy as np
import matplotlib.pyplot as plt

from thinkdsp import decorate
from thinkdsp import read_wave
```

Завантажую шуми


```python
from thinkdsp import UncorrelatedUniformNoise

white_signal = UncorrelatedUniformNoise()
wave = read_wave("13793__soarer__north-sea.wav")
blue = read_wave("Noise/blue_noise.wav")
brown = read_wave("Noise/brown_noise.wav")
green = read_wave("Noise/green_noise.wav")
grey = read_wave("Noise/grey_noise.wav")
pink = read_wave("Noise/pink_noise.wav")
purple = read_wave("Noise/purple_noise.wav")
white = read_wave("Noise/white_noise.wav")

wave.make_audio()
```

## Розділення на фрагменти

Вигляд фрагментів


```python
s1 = wave.segment(duration=0.5)
s2 = wave.segment(start=0.5, duration=0.5)
s3 = wave.segment(start=1, duration=0.5)
s1.plot()
s2.plot()
s3.plot()

decorate(xlabel='Time (s)',
         ylabel='Amplitude')
```



![Амплітуди вибраних фрагментів](output_5_0.png)

## Порівняння спектральних характеристик


Творю спектри та будую їх усі разом:


```python
spectrum = wave.make_spectrum()
s1_sp = s1.make_spectrum()
s2_sp = s2.make_spectrum()
s3_sp = s3.make_spectrum()

s1_sp.plot(linewidth=0.5)
s2_sp.plot(linewidth=0.5)
s3_sp.plot(linewidth=0.5)

decorate(xlabel='Frequency (Hz)',
         ylabel='Amplitude')


```



![Спектральні характеристики фрагментів](output_7_0.png)



Спектр потужності:


```python
s1_sp.plot_power(linewidth=0.5)
s2_sp.plot_power(linewidth=0.5)
s3_sp.plot_power(linewidth=0.5)

decorate(xlabel='Frequency (Hz)',
         ylabel='Power')
```



![Візуально подані спектри потужності](output_9_0.png)



Графік потужності інтегрованого спектру (рис. 4):


```python
integ = spectrum.make_integrated_spectrum()

s1_isp = s1_sp.make_integrated_spectrum()
s2_isp = s2_sp.make_integrated_spectrum()
s3_isp = s3_sp.make_integrated_spectrum()

integ.plot_power()
s1_isp.plot_power()
s2_isp.plot_power()
s3_isp.plot_power()

decorate(xlabel='Frequency (Hz)',
         ylabel='Cumulative power')
```



![Інтегровані спектри наших фрагментів](output_11_0.png)


## Порівняння інтегрованих спектрів різних кольорових шумів


```python

blue_isp = blue.make_spectrum().make_integrated_spectrum()
brown_isp = brown.make_spectrum().make_integrated_spectrum()
green_isp = green.make_spectrum().make_integrated_spectrum()
grey_isp = grey.make_spectrum().make_integrated_spectrum()
pink_isp = pink.make_spectrum().make_integrated_spectrum()
purple_isp = purple.make_spectrum().make_integrated_spectrum()
white_isp = white.make_spectrum().make_integrated_spectrum()

blue_isp.plot_power(color="blue")
brown_isp.plot_power(color="brown")
green_isp.plot_power(color="green")
grey_isp.plot_power(color="grey")
pink_isp.plot_power(color="pink")
purple_isp.plot_power(color="purple")
white_isp.plot_power(color="lightgrey")

s1_isp.plot_power(linewidth=1.5, color="black")
```



![Інтегровані спектри різних кольорових шумів (відповідно забарвлені) та одного з сегментів із мого файлу (чорний, товщий за інших)](output_12_0.png)




```python
blue.plot(color="blue")
```



![Синій шум](output_13_0.png)




```python
from thinkdsp import BrownianNoise

signal = BrownianNoise()
wave = signal.make_wave(duration=10, framerate=11025)
wave.make_audio()
```

```python
green.plot()
pink.plot()
wave.plot(linewidth=1)
decorate(xlabel='Time (s)',
         ylabel='Amplitude')
```



![png](output_16_0.png)



Ось як виглядає спектр потужності в лінійному масштабі.


```python
spectrum = wave.make_spectrum()
spectrum.plot_power(linewidth=0.5)
decorate(xlabel='Frequency (Hz)',
         ylabel='Power')
```



![png](output_18_0.png)



Велика частина енергії знаходиться на низьких частотах, ми навіть не можемо побачити високі частоти.

Ми можемо отримати кращий огляд, побудувавши спектр потужності в логарифмічній шкалі.


```python
# The f=0 component is very small, so on a log scale
# it's very negative.  If we clobber it before plotting,
# we can see the rest of the spectrum more clearly.
spectrum.hs[0] = 0

white_wave = white_signal.make_wave(duration=0.5, framerate=11025)
white_spectrum = white_wave.make_spectrum()
white = read_wave("Noise/white_noise.wav")
white_sp = white.make_spectrum()

white_sp.plot_power()
white_spectrum.plot_power()
spectrum.plot_power(linewidth=0.5)

loglog = dict(xscale='log', yscale='log')
decorate(xlabel='Frequency (Hz)',
         ylabel='Power',
         **loglog)
```



![png](output_20_0.png)



Тепер зв'язок між потужністю і частотою більш зрозумілий. Нахил цієї лінії становить приблизно -2, що вказує на те, що $P = K / f^2$ для деякої константи $K$.


```python
signal =  BrownianNoise()
wave = signal.make_wave(duration=0.5, framerate=11025)
spectrum = wave.make_spectrum()
result = spectrum.estimate_slope()
result.slope
```




    -1.7923978860718588




```python
from thinkdsp import PinkNoise

signal = PinkNoise(beta=0)
wave = signal.make_wave(duration=0.5)
wave.make_audio()
```


З $\beta=1$ рожевий шум має співвідношення $P = K / f$, тому його ще називають шумом $1/f$.


```python
signal = PinkNoise(beta=1)
wave = signal.make_wave(duration=0.5)
wave.make_audio()
```

З $\beta=2$ ми отримуємо броунівський (він же червоний) шум.


```python
signal = PinkNoise(beta=2)
wave = signal.make_wave(duration=0.5)
wave.make_audio()
```

На наступному малюнку показано спектри потужності білого, рожевого та червоного шумів у логарифмічній шкалі.


```python
betas = [0, 1, 2]

for beta in betas:
    signal = PinkNoise(beta=beta)
    wave = signal.make_wave(duration=0.5, framerate=1024)
    spectrum = wave.make_spectrum()
    spectrum.hs[0] = 0
    label = f'beta={beta}'
    spectrum.plot_power(linewidth=1, alpha=0.7, label=label)

decorate(xlabel='Frequency (Hz)',
         ylabel='Power',
         **loglog)
```



![png](output_29_0.png)




```python
from thinkdsp import UncorrelatedGaussianNoise

signal = UncorrelatedGaussianNoise()
wave = signal.make_wave(duration=0.5, framerate=11025)
wave.plot(linewidth=0.5)
decorate(xlabel='Time (s)',
         ylabel='Amplitude')
```



![png](output_30_0.png)



Спектр UG шуму також є UG шумом.


```python
spectrum = wave.make_spectrum()
spectrum.plot_power(linewidth=1)
decorate(xlabel='Frequency (Hz)',
         ylabel='Power')
```



![png](output_32_0.png)



Ми можемо використати графік нормальної ймовірності, щоб перевірити розподіл спектра потужності.


```python
def normal_prob_plot(sample, fit_color='0.8', **options):
    """Makes a normal probability plot with a fitted line.

    sample: sequence of numbers
    fit_color: color string for the fitted line
    options: passed along to Plot
    """
    n = len(sample)
    xs = np.random.normal(0, 1, n)
    xs.sort()

    ys = np.sort(sample)

    mean, std = np.mean(sample), np.std(sample)
    fit_ys = mean + std * xs
    plt.plot(xs, fit_ys, color='gray', alpha=0.5, label='model')

    plt.plot(xs, ys, **options)
```


```python
normal_prob_plot(spectrum.real, color='C0', label='real part')
decorate(xlabel='Normal sample',
         ylabel='Power')
```



![png](output_35_0.png)



Пряма лінія на графіку нормальної ймовірності вказує на те, що розподіл дійсної частини спектра є Гаусовим.


```python
normal_prob_plot(spectrum.imag, color='C1', label='imag part')
decorate(xlabel='Normal sample',
         ylabel='Power')
```



![png](output_37_0.png)



І так само уявна частина.


```python

```

## Амплітуди кольорових шумів


```python
brown.plot(color="brown")
```



![Коричневий](output_40_0.png)




```python
green.plot(color="green")
```



![Зелений](output_41_0.png)




```python
grey.plot(color="grey")
```



![Сірий](output_42_0.png)




```python
pink.plot(color="pink")
```



![Рожевий](output_43_0.png)




```python
purple.plot(color="purple")
```



![Фіолетовий](output_44_0.png)




```python
white.plot(color="lightgrey")
```



![Білий](output_45_0.png)




```python
green.make_spectrum().plot(color="green")
brown.make_spectrum().plot(color="brown")
```



![Спектри зеленого й коричневого шумів](output_46_0.png)
