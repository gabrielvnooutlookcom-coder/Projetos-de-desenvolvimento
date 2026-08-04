package Main;

import classes.Carro;

public class corpo {
    public static void main(String[] args) {

        Carro carro = new Carro(
                "Toyota",
                "Corolla",
                2022,
                "1.6",
                "ABS"
        );

        carro.status();

        carro.ligar();

        carro.ligar();

        carro.status();

        carro.acelerar();
        carro.acelerar();
        carro.acelerar();
        carro.acelerar();
        carro.acelerar();
        carro.acelerar();
        carro.acelerar();
        carro.acelerar();

        carro.acelerar();

        carro.status();

        carro.frear();
        carro.frear();
        carro.frear();
        carro.frear();
        carro.frear();
        carro.frear();
        carro.frear();
        carro.frear();

        carro.frear();

        carro.status();

        carro.desligar();

        carro.status();
    }
}
