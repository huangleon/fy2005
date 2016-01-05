// Ascii mice from http://www.geocities.com/SouthBeach/Marina/4942/ascii.htm


inherit ROOM;
void create()
{
        set("short", "ÀÏÊó¶´");
        set("long", @LONG
    
[37m     
               _                       __
              /   \                  /      \
             '      \              /          \
            |       |Oo          o|            |
            `    \  |OOOo......oOO|   /        |
             `    \\OOOOOOOOOOOOOOO\//        /
               \ _o\OOOOOOOOOOOOOOOO//. ___ /
           ______OOOOOOOOOOOOOOOOOOOOOOOo.___
            --- OO'* `OOOOOOOOOO'*  `OOOOO--
                OO.   OOOOOOOOO'    .OOOOO o
                `OOOooOOOOOOOOOooooOOOOOO'OOOo
              .OO "OOOOOOOOOOOOOOOOOOOO"OOOOOOOo
          __ OOOOOO`OOOOOOOOOOOOOOOO"OOOOOOOOOOOOo
         ___OOOOOOOO_"OOOOOOOOOOO"_OOOOOOOOOOOOOOOO
           OOOOO^OOOO0`(____)/"OOOOOOOOOOOOO^OOOOOO
           OOOOO OO000/00||00\000000OOOOOOOO OOOOOO
           OOOOO O0000000000000000 ppppoooooOOOOOO
           `OOOOO 0000000000000000 QQQQ "OOOOOOO"
            o"OOOO 000000000000000oooooOOoooooooO'
            OOo"OOOO.00000000000000000000OOOOOOOO'
           OOOOOO QQQQ 0000000000000000000OOOOOOO
          OOOOOO00eeee00000000000000000000OOOOOOOO.
         OOOOOOOO000000000000000000000000OOOOOOOOOO
         OOOOOOOOO00000000000000000000000OOOOOOOOOO
         `OOOOOOOOO000000000000000000000OOOOOOOOOOO
           "OOOOOOOO0000000000000000000OOOOOOOOOOO'
             "OOOOOOO00000000000000000OOOOOOOOOO"
  .ooooOOOOOOOo"OOOOOOO000000000000OOOOOOOOOOO"
.OOO"""""""""".oOOOOOOOOOOOOOOOOOOOOOOOOOOOOo
OOO         QQQQO"'                     `"QQQQ
OOO
`OOo.
  `"OOOOOOOOOOOOoooooooo....

[0m

LONG
        );
        set("exits", ([ /* sizeof() == 4 */
		  "down" : __DIR__"secret_room",
	]));
        set("item_desc",([
        	"down":	"¶´ÏÂÃæºÚ¹¾Â¡ßËÊ²Ã´Ò²¿´²»Çå£¬Ö»ÓĞĞ©Ï¤Ï¤Ë÷Ë÷µÄ¶¯¾²¡£\n",
        ]));
        
        set("objects", ([
        	__DIR__"npc/b_mice" : 1,
         ]) );

	set("coor/x",200);
	set("coor/y",-60);
	set("coor/z",-20);
	setup();
}

int valid_leave(object me, string arg){
	object roach;
	
	if (arg == "down") {
		if (roach = present("mouse",this_object()))
			return notify_fail(roach->name()+"¶ñºİºİµØÆËÁËÉÏÀ´¡£\n");
		else
			message_vision("$NÙéÙëÔÚµØÉÏÏòÏÂ×êÈ¥¡£¡£¡£¡£\n",me);
			tell_object(me,"ÆËÍ¨Ò»Éù£¬Äã´ÓÀÏÊó¶´ÀïµôÁË³öÀ´¡£\n\n\n");
			return 1;
	}
	return ::valid_leave(me,arg);
}
