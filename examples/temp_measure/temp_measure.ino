// измерение приблизительной температуры ядра

void setup() {
  uartBegin(9600);
  analogReference(INTERNAL);  // подключаем АЦП к опорному
  analogPrescaler(128);       // установить предделитель 128 (иначе некорректно измеряет)
  // в стандартном ядре делитель 129 является стандартным
  // в GyverCore по умполчанию 4 (быстрее измеряет)
}

void loop() {
  // analogRead(THERMOMETR) вернёт напряжение в мв
  // (val - 324.31 ) / 1.22 - примерное уравнение перевода в градусы по цельсию
  uartPrintln((float)(analogRead(THERMOMETR) - 324.31) / 1.22);
  delay(100);
}
