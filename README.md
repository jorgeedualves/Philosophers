# Philosophers

Thread is the keyword of this project!
Philosophres dynamics are resolved using threads and mutex. A separate thread has been implemented for monitoring Philosophers, to check if any philosophers have died and warn others that they need to stop immediately.

Thread é a palavra chave desse projeto!
A dinamica dos Philosophres é resolvida usando threads e mutex. Uma thread separada foi implementada para o monitoramento do Philosophers,para verificar se algum filósofo morreu e avisa os outros que precisam parar imediatamente.

## Problem to solve
There are five philosophers sitting around a circular dining table!
To eat, they need 2 forks, but there is only one fork for each Philosopher. Then the philosophers will try to take the fork to the right and to the left, one at a time. If he manages to get both forks, he will eat the food at a certain time and put the forks on the table, go to sleep and then think again.
All Philosophers have three actions: eat, think, or sleep. When a philosopher gets hungry, he will try to eat!

Há cinco filósofos sentados ao redor de uma mesa de jantar circular!
Para comer, eles precisam de 2 garfos, mas há apenas um garfo para cada Philosopher. Então os philosophers tentarão pegar o garfo à direita e à esquerda, um de cada vez.  Se ele conseguir pegar os dois garfos, ele comerá a comida em um determinado momento e colocará os garfos na mesa, vai dormir e depois vai pensar novamente.
Todos os Philosophers tem três ações: comer, pensar ou dormir. Quando um filósofo fica com fome, ele tentará comer!

## Skills
- Unix
- Imperative programming
- Rigor

## Demo
<img src="img/philosopherse.gif">

## My grade
<img src="img/score.png">

## Flowchat:
<img src="img/philo.png">


🚧 project:<br/>

## Access the folder philo for the program that uses threads and mutex
cd philo

## Compile the program with
make

## Run the program
./philo 5 800 200 200 7 

## Clean output objects with
philo$ make fclean

:shower: Clean Obj files:<br/>

philo$ make clean

:shower: :shower: Clean All (obj files + binary):<br/>

philo$ make fclean

:shower: :shower: 🚧 Clean All + build:<br/>

philo$ make re 

<br/>See Makefile<br/>

### Made with: <br/>
### Jorge Alves
<div style="display: inline_block">
 <a href="https://github.com/jorgeedualves/jorgeedualves" target="_blank"><img align="center" alt="Github_Jorge" height="30" width="30" src="https://cdn-icons-png.flaticon.com/128/1051/1051275.png" target="_blank"></a>
 <a href="https://www.linkedin.com/in/jorge-eduardo-alves-094b4331/" target="_blank"><img align="center"src="https://img.shields.io/badge/-LinkedIn-%230077B5?style=for-the-badge&logo=linkedin&logoColor=white" target="_blank"></a> 
</div>

### Alexandre Zamarion
<div style="display: inline_block">
 <a href="https://github.com/alezamarion" target="_blank"><img align="center" alt="Github_Jorge" height="30" width="30" src="https://cdn-icons-png.flaticon.com/128/1051/1051275.png" target="_blank"></a>
 <a href="https://www.linkedin.com/in/alexandre-zamarion-cepeda-a3766323a/" target="_blank"><img align="center"src="https://img.shields.io/badge/-LinkedIn-%230077B5?style=for-the-badge&logo=linkedin&logoColor=white" target="_blank"></a> 
</div>
