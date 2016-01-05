
inherit ROOM;

void create()
{
        set("short", "Èû¿Ú");
        set("long", @LONG
ÕâÀïÊÇÖĞÔ­ÈëÎ÷ÓòµÄ±Ø¾­Ö®Â·£¬ÏòÎ÷¿ÉÒÔ¿´µ½Ò»¶ÎÆÆ¾ÉµÄ³¤³Ç£¬ÉÏÃæºÃÏó»¹ÓĞ
±»ÍÁÅÚºä¹ıµÄºÛ¼£¡£´óÅúµÄÉÌÈËÂæÍÕ¶Ó´ÓÕâÀï¾­¹ı£¬ĞÎ³ÉÁËÒ»¸öĞ¡Ğ¡µÄ[33m¼¯ÊĞ[32m¡£²»Öª
ÎªÊ²Ã´£¬×î½üÕâÀïÈ´·±»ªÆğÀ´£¬ĞĞÉÌ¶¼°®Í£ÏÂÀ´ĞªĞª½Å£¬»¹°áÀ´ÁË¼¸»§ÈË¼Ò¡£
LONG
        );
        set("exits", ([ 
  		"east" : __DIR__"sandroad",
  		"west" : __DIR__"oldgreatwall",
 		"south": __DIR__"fair",

]));
        set("outdoors", "quicksand");
        set("objects", ([
                
        ]) );

	set("coor/x",-1030);
	set("coor/y",0);
	set("coor/z",0);
	setup();

}

