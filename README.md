<h1 align="center">Simulação de Semáforo - Embarcatech 💻</h1>

<p>Este projeto implementa um sistema de semáforo utilizando um Raspberry Pi Pico W, três LEDs e um temporizador periódico. O código alterna as cores do semáforo a cada 3 segundos e exibe mensagens informando o estado atual do semáforo. 🚀</p> 

<h2>Requisitos</h2>

<ul>
  <li>Raspberry Pi Pico W.</li>
  <li>3 LEDs (vermelho, amarelo e verde).</li>
  <li>3 resistores de 330Ω.</li>
  <li>Software para desenvolvimento (VS Code integrado ao Wokwi e BitDogLab).</li>
  <li>SDK do Raspberry Pi Pico instalado.</li> 
</ul>

<h2>Funcionamento</h2>


  <p>1. O LED vermelho acende ao iniciar o programa.</p>
  <p>2. A cada 3 segundos, o estado do semáforo muda na seguinte sequência:</p>
  <ul>
	 <li>Vermelho → Amarelo → Verde → Vermelho</li>
  </ul>	  
  <p>3. O programa imprime uma mensagem na saída serial a cada 1 segundo informando o estado atual do semáforo.</p>
  <p>4. O temporizador é gerenciado pela função <strong>add_repeating_timer_ms()</strong>.</p>  


<h2>Código Principal</h2>

<p>O código completo está disponível no arquivo <strong>semaforo_pico.c</strong>. Ele utiliza a biblioteca <strong>hardware/timer.h</strong> para criar um temporizador periódico de 3 segundos.</p>

   <h1>Como Executar o Projeto</h1>

   <p>1. Clone este repositório ou copie o código para seu ambiente de desenvolvimento.</p>

   <p>2. Compile e carregue o código na Raspberry Pi Pico W.</p>   

   <p>3. Observe os LEDs alternando conforme a temporização definida.</p>        

<h4>Autor: <strong>Mariana Barretto</strong></h4>