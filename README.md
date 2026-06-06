# FireWatch — Edge Computing

## Descrição do projeto
Sistema de monitoramento de risco de queimadas desenvolvido com Arduino Uno no simulador Tinkercad. O projeto utiliza um sensor de temperatura TMP36(como substituto ao DHT22) e um potenciômetro para simular o índice de seca, calculando um score de risco e classificando em três níveis: controlado, moderado e crítico. A solução demonstra como uma estação local pode processar dados ambientais e emitir alertas sem depender de conectividade externa.

## Objetivo da solução
Aplicar Edge Computing para classificar o risco de queimadas em tempo real com base em temperatura e índice de seca, acionando alertas visuais (LEDs) e sonoros (buzzer) conforme o nível de risco identificado, sem depender de infraestrutura de nuvem ou internet.

## Componentes utilizados
- Arduino Uno
- Sensor de temperatura TMP36 (pino A1)
- Potenciômetro 100kΩ — simula índice de seca de 0 a 10 (pino A0)
- LED azul — risco controlado (pino 13)
- LED verde — risco moderado (pino 12)
- LED vermelho — risco crítico (pino 11)
- Buzzer — alarme sonoro nível crítico (pino 8)
- Resistores 220Ω (um por LED)
- Protoboard e fios

## Explicação do funcionamento
O sensor TMP36 lê a temperatura ambiente. O potenciômetro simula o índice de seca de 0 a 10. O Arduino calcula um score somando os pesos de cada variável:

**Temperatura:**
- >= 40°C → +3 pontos
- >= 35°C → +2 pontos
- >= 30°C → +1 ponto

**Índice de seca:**
- >= 8 → +3 pontos
- >= 5 → +2 pontos
- >= 3 → +1 ponto

**Classificação pelo score:**
- Score < 4 → Nível CONTROLADO → LED azul acende
- Score >= 4 → Nível MODERADO → LED verde acende
- Score >= 6 → Nível CRÍTICO → LED vermelho acende + buzzer dispara

**Ao iniciar**, o sistema realiza um teste automático acendendo cada LED por 1 segundo em sequência para confirmar o funcionamento do circuito.

## Estrutura do circuito

| Componente | Pino Arduino |
|---|---|
| TMP36 (sinal) | Analógico A1 |
| Potenciômetro (sinal) | Analógico A0 |
| LED azul | Digital 13 |
| LED verde | Digital 12 |
| LED vermelho | Digital 11 |
| Buzzer | Digital 8 |

## Instruções de execução
1. Acesse o link da simulação Tinkercad abaixo
2. Clique em **"Iniciar Simulação"**
3. Aguarde o teste inicial dos LEDs
4. Gire o potenciômetro para variar o índice de seca
5. Clique no sensor TMP36 para alterar a temperatura
6. Observe os LEDs e o Serial Monitor
7. Para atingir nível crítico: temperatura >= 40°C e seca >= 8

## Link da simulação Tinkercad
https://www.tinkercad.com/things/3TVbYff7rol/editel?returnTo=%2Fdashboard%2Fdesigns%2Fcircuits&sharecode=ZajQgYBF_Ta8leDs0OY8NHsSS3Yc5ADyRvF_LL2J0CI

## Integrantes

| Nome | RM |
|---|---|
| Fernando Lima | 570847 |
| Enzo Gabriel | 571357 |
| Cesar Duarte | 570108 |
| Enzo Castilho | 569791 |
| Wesley Ferreira | 573479 |
