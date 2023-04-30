Bu projedeki amacım script keyboard yapmak. Windows ve MacOs için ayrı scriptler çalışıyor. Ben en sık kullandığım uygulamalar için katmanlar oluşturdum. 

* Projede işlemci olarak Stm32f103 Bleupill kullandım.
* 10 Adet Cherry Mx tuş kullandım.
* 1 Adet 1.3 inc SH1106 oled kullandım. 
* 1 Adet KY-040 Rotary Encoder kullandım.
 
![The-Generic-STM32F103-Pinout-Diagram](https://user-images.githubusercontent.com/45915186/235376189-7f1069e6-999c-43a2-83a8-78a738596fb1.jpg)

Yapılması Gerekenler
* Stm32f103 Bleupill kartına STM32duino-bootloader yükleme işlemi .
* https://www.youtube.com/playlist?list=PL7P-uMneXeHNekSL0c-k0c-mqa73Jahf-
* https://github.com/rogerclarkmelbourne/STM32duino-bootloader

Devre Bağlantı Şeması:
![Ekran görüntüsü 2023-05-01 000951](https://user-images.githubusercontent.com/45915186/235377664-d0c00ef3-77f7-4819-a639-9df0a0ae2cc8.png)

Devrenin 3d Tasarım Hali
![ayasardeck](https://user-images.githubusercontent.com/45915186/235376107-9c35b5c9-6a7c-4af4-b591-2600f453b340.PNG)


Özel Teşekkürler:

Stm32f103 Bleupill kartına STM32duino-bootloader yükleme işlemi için Türkçe anlatım.
* https://www.youtube.com/@PratikBilgi


Daha önce qmk hakkında pek birşey bilmiyordum ama aşağıdaki linkte Türkçe harika bir anlatım var.
* https://www.youtube.com/@mechmehmet
* https://www.youtube.com/watch?v=34DJOao9IB4&list=PLGFfVgNo8MoSoSerg_Wg6QnK7lStRSxfl

Tuş Tasarımları için: 
* https://www.thingiverse.com/thing:3791028 
