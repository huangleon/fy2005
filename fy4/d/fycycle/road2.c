#include <ansi.h>
inherit ROOM;
string jinqi();
void remove_flag();
void create()
{
        set("short", "╡Хм╓до");
        set("long", @LONG
п║б╥╣╫╢кр╩мД║ёб╥╣дет╠ъйг╥ГтфЁг╣д╩╓Ёг╨сё╛╨с╣даМмБр╩╠ъ╬мйг╦ъ╢С╣д╥ГтфЁг
Ёгг╫ак║ё╨с╣лиоЁ╓бЗакбл╡щ║ён╒╥Г╥Вю╢р╩╧идЮма╣дфЬо╒║ё╠╠╠ъйгр╩вЫ╡Хм╓ё╛р╩╦Жюо
хк╨мр╩╦Жп║╧цдОтзц╕веуп╨Т©мхкё╛©╢фПю╢иЗрБ╡╩╢М║ёб╥╣др╩етн╖акр╩╢Сх╨хкё╛юОцФ
╟зак╦ЖЁ║всё╛╣ьоб╡Еакр╩цФ[33m╫УфЛ[32m║ё
LONG
        );
    	set("exits", ([ /* sizeof() == 4 */
  		"north":__DIR__"tea_ting",
  		"northeast" : __DIR__"road3",
		"southwest" : __DIR__"road1",
	]));
	set("objects", ([
	    __DIR__"npc/badkid" : 1,
	    __DIR__"npc/laotou" : 1,
	    __DIR__"npc/thinmonk":1,
	    __DIR__"npc/qiuranke":1,
	    __DIR__"npc/hongfunv":1,
	]) );
    	set("item_desc", ([
		"jinqi" : (: jinqi :),
		"╫УфЛ" : (: jinqi :),
		"flag" : (: jinqi :), 
    	]) );
	set("have_flag", 1);
        set("outdoors", "fengyun");
	set("coor/x",-200);
	set("coor/y",200);
	set("coor/z",0);

        setup();

}

string jinqi(){
	object me;
	me = this_player();
	if(!query("have_flag")){
		tell_object(me, "ц╩спфЛвсак║ё\n");
		return "";
	}
	tell_object(me, HIY"                      ╠х нД уп гв\n"NOR);
    	tell_object(me, "            рв╣цнч╪ш╠╕║║     ║║║║дягСспгИюи\n");
	tell_object(me, "\n╥╡дЙтзхЩй╝кЙртобё╛ипн╢х╒гвё╛дэй╓╣цп║е╝р╩х╜р╩╫е╣дё╛тзоб╪╢╫╚п║е╝пМеДсз\n");
	tell_object(me, "кШ║ё╥ГтфЁгдкнт╩╒╡ьаЗж╝╣ьё╛╦ъхкоюй©╠ь╤Юё╛╡╩н╙╦╩╧Схы╩╙ё╛╣╚гСс╒пш╨юою║ё\n");        
	tell_object(me, "хГспрБуъё╛╡╩╥ар╩у╙(ёЗёХёАёИё╘╣ьиокЫ╡Е╫УфЛё║\n");
	return "";
}

void init(){
	add_action("do_zhai", "zhai");
}

int do_zhai(string arg){
	object me, qiu, hong, qi;
	me = this_player();
	if(!arg || (arg != "flag" && arg != "jinqi" && arg != "╫УфЛ")) {
		return 0;
	}
	if (!query("have_flag")){
		tell_object(me,"ря╬╜╠╩у╙мЙак║ё\n");
		return 1;
	}
		
	message_vision("$NиЛйжйтвех╔у╙фЛ║ё\n", me);
	qiu = present("qiuran han", this_object());
	hong = present("redcloth girl", this_object());
	if(objectp(qiu) && objectp(hong)){
		qiu->zhaoqin(me);
	} else {
		message_vision("$Nу╙обр╩цФп║╫УфЛ╥ехК╩Ёжп║ё\n", me);
		remove_flag();
		qi = new(__DIR__"obj/qi");
		qi->move(me);
	}
	return 1;
}

void remove_flag(){
	set("have_flag", 0);
	set("long", @LONG
п║б╥╣╫╢кр╩мД║ёб╥╣дет╠ъйг╥ГтфЁг╣д╩╓Ёг╨сё╛╨с╣даМмБр╩╠ъ╬мйг╦ъ╢С╣д╥ГтфЁг
Ёгг╫ак║ё╨с╣лиоЁ╓бЗакбл╡щ║ён╒╥Г╥Вю╢р╩╧идЮма╣дфЬо╒║ё╠╠╠ъйгр╩вЫ╡Хм╓ё╛р╩╦Жюо
хк╨мр╩╦Жп║╧цдОтзц╕веуп╨Т©мхкё╛©╢фПю╢иЗрБ╡╩╢М║ё
LONG);
}

void reset(){
	::reset();
    set("long", @LONG
п║б╥╣╫╢кр╩мД║ёб╥╣дет╠ъйг╥ГтфЁг╣д╩╓Ёг╨сё╛╨с╣даМмБр╩╠ъ╬мйг╦ъ╢С╣д╥ГтфЁг
Ёгг╫ак║ё╨с╣лиоЁ╓бЗакбл╡щ║ён╒╥Г╥Вю╢р╩╧идЮма╣дфЬо╒║ё╠╠╠ъйгр╩вЫ╡Хм╓ё╛р╩╦Жюо
хк╨мр╩╦Жп║╧цдОтзц╕веуп╨Т©мхкё╛©╢фПю╢иЗрБ╡╩╢М║ёб╥╣др╩етн╖акр╩╢Сх╨хкё╛юОцФ
╟зак╦ЖЁ║всё╛╣ьоб╡Еакр╩цФ[33m╫УфЛ[32m║ё
LONG
        );	
	set("have_flag", 1);
}