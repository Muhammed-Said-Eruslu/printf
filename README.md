# ft_printf - 42 İstanbul Printf Uygulaması

_Bu proje, 42 Okulu müfredatının bir parçası olarak mueruslu tarafından oluşturulmuştur._

## Açıklama

ft_printf, C programlama dilinin standart `printf()` işlevinin sadık bir replicasıdır. Bu proje, değişken sayıda argüman alan işlevlerin, format dizelerinin ve veri türü dönüştürmelerinin nasıl çalıştığını anlamak amacıyla oluşturulmuştur.

### Proje Hedefi

Bu proje aşağıdaki hedefleri gerçekleştirmeyi amaçlamaktadır:

- Belirtilen format dizesine göre çeşitli veri türlerini yazdırmak
- Standart `printf()` ile uyumlu davranış sağlamak
- Değişken uzunluklu argümanları (`va_list`) işlemek
- Farklı format tanımlarını (specifier) desteklemek
- Yazdırılan toplam karakter sayısını döndürmek

### Desteklenen Format Tanımları

- `%c` - Tek karakter
- `%s` - Metin dizesi (string)
- `%d` veya `%i` - İmzalı tam sayı
- `%x` - Onaltılık (hexadecimal) sayı, küçük harf
- `%X` - Onaltılık sayı, büyük harf
- `%p` - İşaretçi adresi
- `%%` - Yüzde işareti

## Kurulum ve Derleme

### Gereksinimler

- GCC veya eşdeğer C derleyicisi
- GNU Make
- Linux/Unix ortamı

### Derleme

Projeyi derlemek için aşağıdaki komutu çalıştırın:

```bash
make
```

Bu komut `libftprintf.a` statik kütüphanesini oluşturacaktır.

### Temizleme

Derlenmiş dosyaları temizlemek için:

```bash
make clean        # Sadece .o dosyalarını siler
make fclean       # .o ve .a dosyalarını siler
make re           # Yeniden derle
```

### Kullanım

Programınızda kullanmak için:

```c
#include "print.h"

int main(void)
{
    ft_printf("Merhaba %s!\n", "Dünya");
    ft_printf("Sayı: %d\n", 42);
    ft_printf("Hex: %x\n", 255);
    ft_printf("Pointer: %p\n", (void *)&main);
    return (0);
}
```

Derle:

```bash
gcc -Wall -Wextra -Werror main.c libftprintf.a -o program
./program
```

## Kullanım Örnekleri

```c
ft_printf("Basit metin\n");
// Çıkış: Basit metin

ft_printf("Karakter: %c\n", 'A');
// Çıkış: Karakter: A

ft_printf("String: %s\n", "hello");
// Çıkış: String: hello

ft_printf("Tam sayı: %d\n", -42);
// Çıkış: Tam sayı: -42

ft_printf("Hex (küçük): %x\n", 255);
// Çıkış: Hex (küçük): ff

ft_printf("Hex (büyük): %X\n", 255);
// Çıkış: Hex (büyük): FF

ft_printf("Pointer: %p\n", (void *)0x7fff);
// Çıkış: Pointer: 0x7fff

ft_printf("Yüzde: %%\n");
// Çıkış: Yüzde: %

int bytes = ft_printf("Yazılan byte: %d\n", 123);
// bytes değeri: toplam yazdırılan karakter sayısı
```

## Algoritma ve Veri Yapısı Açıklaması

### Algoritma Tasarımı

ft_printf iki ana işleme aşamasından oluşur:

#### 1. Format Dizesi Taraması
Algoritma format dizesini karakter karakter tarar:
- Normal karakterleri direkt olarak yazdırır
- `%` işaretine rastladığında sonraki karakteri format tanımı olarak değerlendirir
- Format tanımına göre uygun işlevi çağırır

```
Format: "Sayı: %d\n"
- 'S', 'a', 'y', 'ı', ':', ' ' → ft_putchar() ile yazdır
- '%' → sonraki karakter '%d' mi kontrol et
- 'd' → ft_check_format() ile ft_putnbr() çağrı
- '\n' → ft_putchar() ile yazdır
```

#### 2. Format Tanımlarının İşlenmesi
`ft_check_format()` işlevi, tanımlanan tür göre değişkenleri işler:
- Değişken sayıda argümanları `va_list` ile yönetir
- Her format tanımı için uygun dönüştürme işlevini çağırır
- İşlenen karakter sayısını döndürür

### Veri Yapısı ve Yapı

Proje, her bir format tanımı için ayrı işlevler kullanır:

| İşlev | Görev | Geri Dönüş |
|-------|-------|-----------|
| `ft_putchar(char c)` | Tek karakteri yazdır | Yazılan byte sayısı (1) |
| `ft_putstr(const char *str)` | Stringi yazdır | Yazılan byte sayısı |
| `ft_putnbr(int n)` | İmzalı tam sayıyı yazdır | Yazılan byte sayısı |
| `ft_puthex(unsigned int n, char format)` | Onaltılık sayı | Yazılan byte sayısı |
| `ft_putptr(unsigned long long ptr)` | İşaretçi adresini yazdır | Yazılan byte sayısı |

### Rekürsyon Kullanımı

Sayıları yazdırırken rekürsyon kullanılır:
- `ft_putnbr()`: İmzalı tam sayılar için
- `ft_puthex_long()`: Onaltılık sayılar için

Bu yaklaşım, sayı değerlerini sağdan sola yazdırmayı kolaylaştırır.

**Örnek (ft_putnbr ile 123 yazdırma):**
```
ft_putnbr(123)
  → ft_putnbr(12) + putchar('3')
    → ft_putnbr(1) + putchar('2')
      → putchar('1')
```

### Bellek ve Performans

- **Statik Kütüphane**: `libftprintf.a` olarak derlenir
- **Stack Kullanımı**: Rekürsif işlevler maksimum 10 seviye derinlik (32-bit int) kullanır
- **Yazma Operasyonu**: Her `write()` çağrısı sistem çağrısı yapar (optimizasyon yapılmamış)

## Kaynaklar ve Referanslar

### Resmi Belgeler
- [C89/C90 Standard - stdarg.h](https://en.wikipedia.org/wiki/Stdarg.h)
- [Linux man page - printf](https://man7.org/linux/man-pages/man3/printf.3.html)
- [Linux man page - write](https://man7.org/linux/man-pages/man2/write.2.html)
- [POSIX Specification](https://pubs.opengroup.org/onlinepubs/9699919799/)

### Eğitim Kaynakları
- [42 School - Piscine C](https://www.42.fr/)
- [Variadic Functions in C](https://www.cprogramming.com/tutorial/c/lesson17.html)
- [Printf Format Specifiers Reference](https://www.cplusplus.com/reference/cstdio/printf/)

### Teknoloji Seçimleri
- **C Dili**: Düşük seviye sistem programlamayı anlamak
- **Make Build System**: Derlenmiş diller için standart yöntem
- **Statik Kütüphane (.a)**: Taşınabilirlik ve bağlantı kolaylığı

### Yapay Zeka Kullanımı

Bu proje geliştirme sürecinde yapay zeka asistanı (GitHub Copilot) aşağıdaki görevler için kullanılmıştır:

#### 1. **Kod Yapısı ve Tasarım**
   - İşlev prototiplerinin ve kütüphane yapısının tasarlanması
   - Modüler kod organizasyonu önerileri

#### 2. **Rekürsif Algoritmaların Geliştirilmesi**
   - `ft_putnbr()` ve `ft_puthex_long()` rekürsif işlevlerinin optimizasyonu
   - İnsan-okunur kod örnekleri

#### 3. **Hata Yönetimi**
   - NULL pointer kontrolleri ve edge case'ler (örneğin -2147483648)
   - Format tanımlarında hatalı karakterlerin işlenmesi

#### 4. **Belgelendirme ve Yorumlar**
   - Kod yorumlarının ve işlev açıklamalarının yazılması
   - README dosyasının yapılandırılması

#### 5. **Debugging ve Test**
   - Segmentation fault hataları çözümü
   - Format specifier uyumsuzlukları düzeltme

**AI'nin Kullanılmadığı Kısımlar:**
- Temel algoritmanın konsepti (standart printf mantığı)
- Makefile yazımı (42 okulu standartları)
- Projenin temel gereksinimleri ve spesifikasyonları

## Dosya Yapısı

```
.
├── ft_printf.c      # Ana printf işlevi ve format kontrol
├── ft_utils.c       # Yardımcı işlevler
├── print.h          # Başlık dosyası
├── main.c           # Test programı (opsiyonel)
├── Makefile         # Derleme konfigürasyonu
└── README.md        # Bu dosya
```

## Notlar

- Proje 42 İstanbul okulunun müfredatı standardında yazılmıştır
- `-Wall -Wextra -Werror` derleyici bayraklarıyla hatasız derlenir
- Norm uygunluğu kontrol edilmiştir

## İletişim

Sorular veya öneriler için: mueruslu@student.42istanbul.com.tr
