// Ascii mice from http://www.geocities.com/SouthBeach/Marina/4942/ascii.htm

inherit ROOM;
void create()
{
        set("short", "ÀÏÊó¶´");
        set("long", @LONG
    
[37m     
	         ,;;;.;,;;;;,,   _
	      .;'             ''( );.
	    .;'                    o,'.
	    ;     )       .  .  ;      :;
	   ::       ~     ~( ~'';,,;\~~
	  : '. ,,, \'....; ',
	 '        ;..     ',,,'
	;           ;,,
	,;;;'
[0m
LONG
        );
        set("exits", ([ /* sizeof() == 4 */
		  "down" : __DIR__"mice_room3",
	]));
        
        set("objects", ([
        	__DIR__"npc/m_mice" : 1,
         ]) );
         
	set("item_desc",([
        	"down":	"¶´ÏÂÃæºÚ¹¾Â¡ßËÊ²Ã´Ò²¿´²»Çå£¬Ö»ÓĞĞ©Ï¤Ï¤Ë÷Ë÷µÄ¶¯¾²¡£\n",
        ]));
	set("coor/x",200);
	set("coor/y",-60);
	set("coor/z",-15);
	setup();
}


int valid_leave(object me, string arg){
	object roach;
	
	if (arg == "down") {
		if (roach = present("mouse",this_object()))
			return notify_fail(roach->name()+"¶ñºİºİµØÆËÁËÉÏÀ´¡£\n");
		else
			message_vision("$NÙéÙëÔÚµØÉÏÏòÏÂ×êÈ¥¡£¡£¡£¡£\n",me);
			return 1;
	}
	return ::valid_leave(me,arg);
}
