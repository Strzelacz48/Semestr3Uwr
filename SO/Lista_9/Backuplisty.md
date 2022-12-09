# Systemy operacyjne lista 9
## Zadanie 1 kasia
![](https://i.imgur.com/JdKBXXW.png)

_Wyjaśnij zadania pełnione przez protokoły warstwy: łącza, sieciowej i transportowej._
- Transportowa:
W środku aplikacji.
    - TCP - gwarantuje dostarczenie wiadomości i kontroluje dopasowanie predkosci nadawca/odbiorca. rozbija tez dlugie wiadomosci na krotsze segmenty i kontoluje zatory.
    - UDP - bezpolaczeniowa obsluga, bez fajerwerkow: bez gwarancji, kontroli predkosci ani zatorow.
- Sieciowa:
Przemieszcza datagramy od jednego hosta do drugiego. 
    - IP - definiuje pola datagramu i jak końcowe systemy i routery działają na tych polach. Jest tylko jeden taki protokół. 
    - routing protocols - determinuja trasy wysylania. (duzo ich)
- Łącza:
(we’ll refer to the linklayer packets as frames.)
Przemieszcza datagramy przez serię routerów między źródłem a przeznaczeniem <3. Niektóre są niezawodne, inne mogą gubić dane. Podróżujące datagramy często będą trawersować różnymi łączmi, z różnymi protokołami.   Np.:
    - Ethernet,
    - Wifi,
    - cable access network’s DOCSIS protocol.

:::spoiler ksiązka
**Transport Layer**
The Internet’s transport layer transports application-layer messages between application endpoints. In the Internet there are two transport protocols, TCP and UDP, either of which can transport application-layer messages. TCP provides a connection-oriented service to its applications. This service includes guaranteed delivery of application-layer messages to the destination and flow control (that is, sender/receiver speed matching). TCP also breaks long messages into shorter segments and provides a congestion-control mechanism, so that a source throttles its transmission rate when the network is congested. The UDP protocol provides a connectionless service to its applications. This is a no-frills service that provides no reliability, no flow control, and no congestion control. In this book, we’ll refer to a transport-layer packet as a segment.


**Network Layer**
The Internet’s network layer is responsible for moving network-layer packets known as datagrams from one host to another. The Internet transport-layer protocol (TCP or UDP) in a source host passes a transport-layer segment and a destination address to the network layer, just as you would give the postal service a letter with a destination address. The network layer then provides the service of delivering the segment to the transport layer in the destination host.
The Internet’s network layer includes the celebrated IP Protocol, which defines the fields in the datagram as well as how the end systems and routers act on these fields. There is only one IP protocol, and all Internet components that have a network layer must run the IP protocol. The Internet’s network layer also contains routing protocols that determine the routes that datagrams take between sources and work layer must run the IP protocol. The Internet’s network layer also contains routing protocols that determine the routes that datagrams take between sources and destinations. The Internet has many routing protocols. As we saw in Section 1.3, the Internet is a network of networks, and within a network, the network administrator can run any routing protocol desired. Although the network layer contains both the IP protocol and numerous routing protocols, it is often simply referred to as the IP layer, reflecting the fact that IP is the glue that binds the Internet together.

**Link Layer**
The Internet’s network layer routes a datagram through a series of routers between the source and destination. To move a packet from one node (host or router) to the next node in the route, the network layer relies on the services of the link layer. In particular, at each node, the network layer passes the datagram down to the link layer, which delivers the datagram to the next node along the route. At this next node, the link layer passes the datagram up to the network layer.
The services provided by the link layer depend on the specific link-layer protocol that is employed over the link. For example, some link-layer protocols provide reliable delivery, from transmitting node, over one link, to receiving node. Note that this reliable delivery service is different from the reliable delivery service of TCP, which provides reliable delivery from one end system to another. Examples of linklayer protocols include Ethernet, WiFi, and the cable access network’s DOCSIS protocol. As datagrams typically need to traverse several links to travel from source to destination, a datagram may be handled by different link-layer protocols at different links along its route. For example, a datagram may be handled by Ethernet on one link and by PPP on the next link. The network layer will receive a different service from each of the different link-layer protocols. In this book, we’ll refer to the linklayer packets as frames.
:::


_Zainstaluj i uruchom program wireshark._
``sudo apt-get install wireshark``
``wireshark``
::: spoiler jeśli wrzeszczy 
**Couldn't run /usr/bin/dumpcap in child process: Permission denied**
``sudo dpkg-reconfigure wireshark-common``
``sudo chmod +x /usr/bin/dumpcap``
:::

_Przechwyć kilka pakietów protokołów UDP i TCP,_
::: spoiler obrazkowo
![](https://imgur.com/4VVV3ZL.png)
![](https://imgur.com/vlYHTKu.png)
:::

_a następnie wytłumacz do czego służy kapsułkowanie (ang. encapsulation)_
encapsulation is a method of designing modular communication protocols in which logically separate functions in the network are abstracted from their underlying structures by inclusion or information hiding within higher-level objects.

_i wyświetl (tj. kliknij dwukrotnie na pakiet) nagłówki ramki, datagramu i segmentu._
![](https://imgur.com/OgZP1rc.png)

_Zidentyfikuj adres źródłowy i docelowy pakietu._
![](https://imgur.com/sbXiOkl.png)

_Czemu protokoły warstwy łącza i sieciowej nie są używane do komunikacji między procesami użytkownika?_
Służą do komunikacji między hostami.
## Zadanie 2 Olek
![](https://i.imgur.com/t128EzV.png)
:::info
**Datagramowy protokół UDP** jest prostym, bezpołączeniowym protokołem, którego największą zaletą jest niewielki narzut danych sterujących, dodawanych w procesie enkapsulacji. Bezpołączeniowość protokołu UDP polega na tym, iż przed rozpoczęciem procesu komunikacji host źródłowy nie wysyła do hosta docelowego żadnych informacji zestawiających to połączenie. Zasada jest taka, jeśli urządzenie źródłowe chce rozpocząć transmisję, chce wysłać dane po prostu to robi, bez wcześniejszego ustalenia.

UDP w datagramie dodaje tylko 8 bajtów danych sterujących. Nagłówek datagramu UDP wygląda tak:
![](https://i.imgur.com/fs1ORmA.png)


**datagram** jest podstawową jednostką transferową związaną z siecią z komutacją pakietów. Datagramy są zwykle zbudowane z sekcji nagłówka i ładunku.

---

**Połączeniowy protokół TCP** to złożony protokół, którego użycie ma gwarantować niezawodne dostarczenie danych oraz kontrolę przepływu. W procesie enkapsulacji, do nagłówka TCP dodawanych jest aż 20 bajtów danych sterujących, ale tego wymaga niezawodność TCP. Klient TCP nawiązuje połączenie z danym serwerem, wymienia dane z tym serwerem, a następnie kończy połączenie. Aplikacje korzystające z tego protokołu to przeglądarki internetowe, programy pocztowe czy programy do przesyłania plików.

TCP zapewnia niezawodne dostarczenie danych lub niezawodne powiadomienie o niepowodzeniu.

**segment** to pojedyncza paczka danych o pojemności 1024. Składa się z nagłówka i z danych

**sterowanie przepływem** mówi nam ile danych może zostać odebranych w jednym czasie.
:::

> Różnice między protokołami warstwy transportowej:
> * datagramowym UDP
> * połączeniowym TCP

**Większość w definicjach**.
TCP - w przypadku komunikacji ludzkiej rozmowa rozpoczęłaby się od słów jednej osoby: “Zacznijmy rozmowę”, po czym druga odpowiedziałaby “Zaczynam słuchać!”. Podobnie w przypadku dzwonienia przez telefon, jedna osoba dzwoni (informuje o chęci nawiązania połączenia), a druga dopiero po odebraniu może otrzymać informacje.
UDP - w przypadku komunikacji ludzkiej rozmowa rozpoczęłaby się natychmiastowo, bez wcześniejszego uprzedzenia o chęci przekazania informacji.


> Czym różni się komunikacja półdupleksowa od dupleksowej?

Połączenie TCP jest dupleksowe, oznacza to, że aplikacja może wysyłać i odbierać dane w obu kierunkach w połączeniu o dowolnej porze. Komunikacja półdupleksowa jest ograniczona względem komunikacji dupleksowej, a więc wysyłanie i odbieranie informacji odbywa się naprzemiennie.

> Jak TCP radzi sobie z zagubieniem segmentu lub faktem, że segmenty mogą przyjść do odbiorcy w innej kolejności niż zostały wysłane?

TCP uporządkowuje dane poprzez dołączenie numeru każdego bajtu, który wysła. Załóżmy, że aplikacja pisze 2048 bajtów do gniazda TCP, powodując wysłanie dwóch segmentów (pojedyncza paczka danych o pojemności 1024 bajtów) danych przez TCP: pierwszy zawiera dane z numerami 1-1024, a drugi z 1025-2048. Gdy segment zostanie dostarczony w złej kolejności, TCP przestawi je na podstawie wysyłanych numerów, a gdy segment zostanie zagubiony, to zostaje wysłany ponownie.

> Skąd protokół TCP wie kiedy połączenie zostało zerwane?

Połączenie TCP zostaje zerwane po wysłaniu przez jedną ze stron pakietu z ustawioną flagą FIN (od finished), wymaga on potwierdzenia flagą ACK. Dopuszcza się też awaryjne przerwanie połączenia pakietem z flagą RST (reset), taki pakiet nie wymaga potwierdzenia.

> Jaki problem rozwiązuje sterowanie przepływem implementowane przez TCP?

Wykorzystywane przez TCP sterowanie przepływem (ang. flow control) mówi o tym, ile danych może zostać odebranych w jednym czasie. Gwarantuje to, że nadający nie może przepełnić bufora. Rozmiar ten zmienia się jednak dynamicznie, więc gdy aplikacja czyta dane z bufora, ten rozmiar może zostać powiększony. Istnieje również możliwość taka, że bufor gniazda TCP zostanie zapełniony, przez co aplikacja zostanie tymczasowo wstrzymana, aby mogła odczytać dane z bufora, a następnie odebrała kolejne dane.

## Zadanie 3 Marcin
![](https://i.imgur.com/dA4XL21.png)
**klient-serwer** - architektura systemu komputerowego, w szczególności oprogramowania, umożliwiająca podział zadań (ról). Polega na ustaleniu, że serwer zapewnia usługi dla klientów, zgłaszających do serwera żądania obsługi (ang. service request). Podstawowe, najczęściej spotykane serwery działające w oparciu o architekturę klient-serwer to: serwer poczty elektronicznej, serwer WWW, serwer plików, serwer aplikacji. Z usług jednego serwera może zazwyczaj korzystać wiele klientów. Jeden klient, w ogólności, może korzystać jednocześnie z usług wielu serwerów. Według schematu klient-serwer działa też większość, obecnie spotykanych, systemów zarządzania bazą danych.
**gniazdo strumieniowe** - to gniazda oparte na połączeniach, umożliwiają one sekwencyjny przepływ danych z gwarancją przesłania pakietu i zachowania kolejności.
**port ulotny** - jest to tymczasowy port, zwykle po stronie klienta w komunikacji klient-serwer, używany przez krótki czas w czasie sesji komunikacyjnej. 
::: spoiler ang Wikipedia
is a communications endpoint (port) of a transport layer protocol of the Internet protocol suite that is used for only a short period of time for the duration of a communication session. Such short-lived ports are allocated automatically within a predefined range of port numbers by the IP stack software of a computer operating system. The Transmission Control Protocol (TCP), the User Datagram Protocol (UDP), and the Stream Control Transmission Protocol (SCTP) typically use an ephemeral port for the client-end of a client–server communication. At the server end of the communication session, ephemeral ports may also be used for continuation of communications with a client that initially connected to one of the services listening with a well-known port.The allocation of an ephemeral port is temporary and only valid for the duration of the communication session. After completion of the session, the port is destroyed and the port number becomes available for reuse, but many implementations simply increment the last used port number until the ephemeral port range is exhausted, when the numbers roll over. Ephemeral ports are also called dynamic ports, because they are used on a per request basis, and are only known by number once allocated.
:::
:::spoiler Wykres
![](https://i.imgur.com/YtqUGGK.png)
:::
::: spoiler Wykres po polsku
![](https://i.imgur.com/FR7WhIQ.png)
:::
Timeline typowego scenariusza TCP klient/serwer:     
1. Uruchomiony zostaje serwer.
2. Trochę później uruchomiony zostaje klient i łączy się z serwerem.
3. Zakładamy że klient wysyła zapytanie do serwera, który to zapytanie przetwarza i wysyła informację zwrotną którą klient odczytuje.
4. Powtarzamy krok 3 dopóki klient nie zamknie połączenia co wysyła end-of-file do serwera. 
5. Wtedy serwer zamyka swoją stronę połączenia i albo się zamyka albo czeka na nowego klienta. 

W którym momencie następuje związanie gniazda z adresem lokalnym i zdalnym?

- lokalny bind(), connect() zdalny.

Co specyfikuje 2-gi argument polecenia listen()?

- Polecenie `int listen(int sockfd, int backlog)` służy do nasłuchiwania (oczekiwania) na połączenia. Pierwszy argument mówi który socket ma sie przygotować, a drugi mówi jak długa może się do niego ustawić kolejka zanim wystąpi błąd `ECONNREFUSED` lub klient zostanie zignorowany.

Z jakim numerem numerem portu jest związane gniazdo przekazywane i zwracane przez `accept()`?

- Polecenie (serwera) `int accept(int sockfd, struct sockaddr *addr, socklen_t *addrlen)` wykorzystywane jest do zaakceptowania połączenia z gniazdem o danym `sockfd`. *("The argument `sockfd` is a socket that has been created with `socket(2)`, bound to a local address with `bind(2)`, and is listening for connections after a `listen(2)`."")* `addr` jest wskaźnikiem na strukturę trzymającą sockety klienta. Funkcja zwraca podłączony deskryptor, który może być wykorzystany do komunikacji z klientem, używając uniksowych operacji I/O.

Załóżmy, że mamy serwer `192.168.1.1:80` oraz dwóch klientów: `10.0.0.1` i `10.0.0.2`. Klient `10.0.0.1` chce nawiązać połączenie z serwerem na lokalnym porcie `1234` i łączy się. Wtedy serwer ma jedno gniazdo zidentyfikowane jako `10.0.0.1:1234 - 192.168.1.1:80`. Następnie łączy się drugi klient `10.0.0.2` z lokalnym portem `4321`, wtedy serwer ma ma dwa gniazda:

```
10.0.0.1:1234 -> 192.168.1.1:80 - protocol
10.0.0.2:4321 -> 192.168.1.1:80 - protocol
```
## Zadanie 4 Kronelia
![](https://i.imgur.com/Waduyx0.png)

datagram = nagłówek + dane
**Gniazda datagramowe** - gniazda bezpołączeniowe - przed rozpoczęciem wymiany danych nie łączymy się z konkretnym klientem (jak w przypadku TCP przez `connect`, `listen` i `accept`); każdy pakiet jest przetwarzany i adresowany osobno. Jest określona maksymalna wielkość wiadomości. Nie mamy gwarancji co do kolejności otrzymanych wiadomości (mogą się też zdarzyć duplikaty).

:::spoiler
Diagram z internetu, bo w książce była słaba jakość. Jedyna różńica to że w książce był jeszcze komentarz 'well know port' obok `bind()` 
:::
![](https://i.imgur.com/jN1ky59.jpg)

1. Zostają utworzone gniazda (`socket()` i `bind()` jak w poprzednim zadaniu).
2. Klient nie musi tworzyć połączenia z serwerem przez `connect()` jak poprzednio - od razu może wysłać żądanie do serwera funkcją `sendto()` z adresem serwera jako parametr `dest_addr` (o długości `addr_len`)
```cpp
ssize_t sendto(int sockfd, const void *buf, size_t len, int flags,
               const struct sockaddr *dest_addr, socklen_t addrlen)
```
sockfd - deskryptor wysyłającego gniazda
buf - bufor z wiadomością
len - długość wiadomości
Funkcja zwraca liczbę wysłanych bajtów, -1 gdy błąd.

3. Analogicznie serwer nie musi akceptować połączenia z klientem, zamiast tego woła funkcję `recvfrom()`, która odbiera dane od klienta. Domyślnie jest blokująca - jeśli nie ma dostępnego pakietu, proces będzie uśpiony w oczekiwaniu na otrzymanie pakietu.

```cpp
ssize_t recvfrom(int sockfd, void *buf, size_t len, int flags,
                 struct sockaddr *src_addr, socklen_t *addrlen)
```
Czyta wiadomość do bufora `buf` o rozmiarze `len`, umieszcza adres wysyłającego w `src_addr` i rozmiar adresu w `addrlen` (żeby serwer mógł wysłać odpowiedź). Zwraca liczbę otrzymanych bajtów, -1 gdy błąd.

4. Po otrzymaniu żądania, serwer może na nie odpowiedzieć przez `sendto()` - zapamiętał adres klienta w `src_addr`.
5. Klient po otrzymaniu odpowiedzi od serwera może zakończyć swoje działanie albo wysłać kolejne żądania. 

_Czemu, w przeciwieństwie do TCP, serwer może rozpocząć pracę zaraz po wykonaniu funkcji bind(2)?_
Protokół UDP jest bezpołączeniowy, więc serwer nie musi czekać na klienta.

_Z jakiej przyczyny interfejs read(2) i write(2) po stronie serwera może być niewystarczający?_
Chcemy wiedzieć od kogo otrzymaliśmy żądanie (żeby móc na nie odpowiedzieć) i musimy podać, do kogo chcemy odesłać odpowiedź (nie mamy stałego połączenia z jednym klientem jak w TCP). Funkcje `read` i `write` nam tego nie umożliwiają - działają na deskryptorach plików a nie adresach gniazd, w `read` musimy też z góry wiedzieć skąd chcemy czytać.

_Przedstaw semantykę operacji recvfrom(2) i sendto(2)._
Podane przy opisie diagramu.

_Kiedy po stronie klienta następuje związanie gniazda UDP z adresem lokalnym?_
Przy pierwszym wywołaniu `sendto`, jeśli gniazdo jeszcze nie ma powiązanego portu lokalnego, to jądro automatycznie przydzieli mu jakiś port efemeryczny.

_Na podstawie [ 7, 8.11] zreferuj efekt jaki przynosi
wykonanie connect(2) na gnieździe klienta._
Jądro sprawdza jakieś błędy (np. czy adres serwera jest osiągalny) oraz zapamiętuje IP i port serwera w strukturze przekazanej jako argument funkcji `connect`. Po wywołaniu `connect` nie mamy już wyboru do kogo wysyłamy żądanie - komunikujemy się tylko z tym jednym serwerem, używając `write` lub `send` zamiast `sendto` i `read`, `recv` lub `recvmsg` zamiast `recvfrom`. Asynchroniczne błędy są zwracane do gniazda (przed zrobieniem `connect` nie były).

:::spoiler uwaga
Teoretycznie dalej można używać `sendto` i `recvfrom` ale z dest_addr/src_addr = NULL i socklen = 0. Raczej się tego nie robi.
:::

_Jakie ograniczenia poprzednio wymienionych funkcji zostały
poprawione przez wywołania recvmsg(2) i sendmsg(2)?_
```cpp
ssize_t sendmsg(int sockfd, const struct msghdr *msg, int flags)
    
ssize_t recvmsg(int sockfd, struct msghdr *msg, int flags)
```

```
struct msghdr {
               void         *msg_name;       /* Optional address */
               socklen_t     msg_namelen;    /* Size of address */
               struct iovec *msg_iov;        /* Scatter/gather array */
               size_t        msg_iovlen;     /* # elements in msg_iov */
               void         *msg_control;    /* Ancillary data, see below */
               size_t        msg_controllen; /* Ancillary data buffer len */
               int           msg_flags;      /* Flags (unused) */
           };
```

Użycie struktury msghdr pozwala zmniejszyć liczbę argumentów przekazywanych do funkcji. Oprócz tego przez msg_flags mogą być zwracane niektóre błędy.


## Zadanie 5 Kuba
![](https://i.imgur.com/kDOVTjw.png)

write(2) robi *short count* w sytuacji, gdy w buforze socet-u nie ma dostatecznie dużo miejsce na wysłanie całej wiadomości, oznacza to że kernel nie był w stanie skopiować wsyzstkich danych. Gdy wcale nie ma miejsca w buforze jest wysyłany wtedy błąd EWOULDBLOCK. read(2) zwraca *short count* wtedy gdy ilość odczytywanych danych z buffora jest mniejsza od wymaganej. Oba mogą również zwrócić *short count* w sytuacji gdy jesy wewnętrznie ograniczenie buffera lub gdy jest "zbyt duże" opóźnienie sieci.

Datagramy IP, UDP, TCP posiadają w nagłówku informacje na temat tego jak dużo informacji jest w nich przesyłanych. Na podstawie tego można dowiedzieć się czy otrzymany datagram dotarł w pełni, czy został pocięty. Inną możliwością jest obliczenie sumy kontrolnej (checksum), a więc pewnej liczby uzyskiwanej za pomocą odpowiedniego algorytmu do zapewnienia integralności danych.

Many system calls will report the EINTR error code if a signal occurred while the system call was in progress. No error actually occurred, it's just reported that way because the system isn't able to resume the system call automatically. This coding pattern simply retries the system call when this happens, to ignore the interrupt.

W idealnej sytuacji powinniśmy za każdym razem sprawdzać, czy nie został zwrócony błąd EINTR w trakcie jakiejś operacji na gniazdach, gdyż może on zostać dostarczony w trakcie wywoływania systemowego. Część syscall’i może być bardzo długo, potencjalnie w nieskończoność w przypadku accept(2). Jeżeli takie polecenie zostanie przerwane, to w zależności od ustawionych flag i systemu operacyjnego, może zostać ono uruchomione ponownie lub zakończone z błędem - zwrócona wartość w takim przypadku będzie -1 i errno zostanie ustawione na EINTR.

Może się zdarzyć taka sytuacja, że klient spróbuje coś zapisać do gniazda powiązanego z połączeniem, które serwer już zamknął. W takim przypadku klient będzie kilkukrotnie automatycznie ponawiał próby wysłania segmentu. Jeżeli w tym czasie serwer nie zostanie uruchomiony ponownie i wysłanie danych przez klienta nie powiedzie się, to zostanie zwrócony błąd. Jeżeli nie było żadnych odpowiedzi od serwera (a więc potencjalnie scrashował), to błędem będzie ETIMEDOUT. Gdy jakiś pośredni router ustalił, że serwer był nieosiągalny i przez ICMP zwrócił mówiącą o tym wiadomość, to błędem będzie EHOSTUNREACH lub ENETUNREACH.

Czym jest ICMP: ICMP (ang. Internet Control Message Protocol) to protokół sieciowy służący do diagnostyki sieci i trasowania. Jeżeli coś nie działa poprawnie w TCP/IP, to ICMP przejmuje rolę narzędzia do rozwiązywania problemów i zgłasza błędy łączności między hostami.

W kodzie funkcji open_listenfd użyto wywołania setsockopt(2) (służy ono do ustawiania opcji gniazda) z flagą SO_REUSEADDR. Opcja ta służy do zezwolenia na ponowne użycie adresu przez inny proces, bez konieczności oczekiwania na jego zwolnienie. Gdyby flaga ta nie była ustawiona, oczekiwanie na zwolnienie adresu mogłoby trwać nawet kilkadziesiąt sekund.

---
![](https://i.imgur.com/xZf0g9u.png)

## Zadanie 6
![](https://i.imgur.com/Z38BMMQ.png)

## Zadanie 7
![](https://i.imgur.com/uTq4KOG.png)

## Zadanie 8
![](https://i.imgur.com/BhU1CD1.png)

## Zadanie 9(bonus)
![](https://i.imgur.com/LsM06WO.png)

