# Igor Dominiski RM562055, Murilo Reis RM564053, Murillo Akira RM561806.

---

#link projeto:

## https://wokwi.com/projects/441626798908635137

---

#link video:

##https://youtu.be/YJUlmUknEwM

---

# 🏐 Contador de Passes – ESP32 + LCD + LEDs + MQTT

## Descrição do Projeto
Este projeto é um contador de passes para jogos, que combina hardware e software para registrar e exibir os passes em tempo real. Ele integra:

- **Botão físico**: cada aperto representa um passe.  
- **LEDs**: piscam para indicar visualmente cada passe.  
- **LCD I2C**: mostra o total de passes atual.  
- **MQTT**: envia os dados para um broker, permitindo monitoramento remoto, como via Node-RED.  

O projeto é ideal para treinamento esportivo ou como experimento com IoT, mostrando a integração entre sensores físicos, microcontrolador e dashboard remoto.

---

## Componentes

| Componente         | Função                                        |
|-------------------|----------------------------------------------|
| ESP32 DevKit C     | Microcontrolador principal                   |
| Botão push-button  | Entrada para registrar os passes             |
| LEDs (5 cores)     | Indicadores visuais dos passes               |
| LCD I2C 16x2       | Exibe o total de passes                       |
| Resistor 220Ω      | Limitador de corrente para os LEDs           |
| Fios / Protoboard  | Conexões elétricas                            |

---

## Funcionalidades

- **Contador de passes**: incrementa a cada apertar do botão.  
- **LCD atualizado em tempo real**: mostra o total de passes.  
- **LEDs piscando**: indica o passe atual com cores diferentes.  
- **Publicação MQTT**: envia os dados para o tópico `jogo/passes/yan` no broker `test.mosquitto.org`.  
- **Debounce**: evita múltiplas contagens acidentais.

---

## Como Funciona

1. Aperte o botão conectado ao ESP32.  
2. O contador incrementa e o LED correspondente pisca.  
3. O LCD mostra o total atualizado.  
4. O valor também é enviado via MQTT para o broker.  
5. Node-RED (ou outro sistema IoT) pode receber os dados e mostrar gráficos em tempo real.
