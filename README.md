# **rp2040_template**

Templete para desenvolvimento de firmware com o microcontrolador RP2040 (Raspberry Pi Pico), Em ambiente Linux em qualquer editor de texto.

<hr>
<br>

O templete usa 3 diretórios base: `includes` onde é estão os cabeçalhos como "config.h" ou "type.h";  `lib` onde é adicionado módulos ou bibliotecas que serão utilizadas no projeto;  `src` onde se encontram os códigos fontes da aplicação:

```
includes
 |
 |->config.h
 |->hardware.h
lib
 |
 |->simple_uart
     |
     |->simple_uart.c
     |->simple_uart.h
src
 |
 |->main.c

```

<br>

Há também alguns arquivos importantes: Como o `pico_sdk_import.cmake`  importado de acordo com a documentação do [SDK](https://datasheets.raspberrypi.com/pico/getting-started-with-pico.pdf); O `build.sh` que gera o `CMakeLists.txt` de acordo com os subdiretórios e arquivos e encontrados nos diretórios anteriormente citados.

<br>

## Configurações do Template

Algumas configurações **importantes** do template encontram se no arquivo [build.sh](./RPI_PICO_SDK/build.sh). Onde deve ser configurado as variáveis de ambiente onde os valores são definidas no processo de configuração so SDK por exemplo:

```
PICO_SDK_PATH="~/pico/pico-sdk"
PICO_EXAMPLES_PATH="~/pico/pico-examples"
PICO_PLATFORM="rp2040"
```

Atenção na seleção do modelo de placa utilizado:


```
# PICO_BOARD="pico_w"
PICO_BOARD="pico"
```

Para configurar o meio de comunicação da serial:
```
UART_ENABLE="1"
USB_CDC_ENABLE="0"
```

Além disso é importante "**incluir**" as **bibliotecas do SDK** que eventualmente serão utilizadas no projeto, pro exemplo incluindo uart e pwm:
```
LIBRARIES="

	# pico_cyw43_arch_none
	# pico_cyw43_arch_lwip_threadsafe_background

	pico_stdlib
	pico_multicore
	
	hardware_pwm
	hardware_uart
	hardware_adc

"
```

por fim basta dar permissão de execução e para o arquivo build.sh:

```
chmod +x build.sh  # necessário apenas uma vez 
./build.sh # executando e compilando

```

<hr>
<br>


## **Configurando SDK:**

Para criar esse template utilizei como base a documentação do SDK: "[Getting started with Raspberry Pi Pico](https://datasheets.raspberrypi.com/pico/getting-started-with-pico.pdf)", e é preciso seguir com os procedimentos de configurações do ambiente e instalação do SDK descritos nessa documentação. O precedimento que realizei está descrito a seguir porem pode conter divergências a depender de cada sistema operacional ou configurações desejadas.


<br>


```
sudo apt install cmake gcc-arm-none-eabi libnewlib-arm-none-eabi build-essential libstdc++-arm-none-eabi-newlib git code

code --install-extension marus25.cortex-debug
code --install-extension ms-vscode.cmake-tools
code --install-extension ms-vscode.cpptools

mkdir -p ~/.local/opt/pico
cd  ~/.local/opt/pico

git clone -b master https://github.com/raspberrypi/pico-sdk.git
cd pico-sdk
git submodule update --init
cd ..
git clone -b master https://github.com/raspberrypi/pico-examples.git

cd  ~/.local/opt/pico/pico-examples
mkdir build
cd build
export PICO_SDK_PATH=~/.local/opt/pico/pico-sdk
cmake ..
cd blink
make -j4
```
