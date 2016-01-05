
inherit ROOM;

void create()
{
        set("short", "ÈûÍâ·ç¹â");
        set("long", @LONG
µØÊÆµ½Õâ»íÈ»¿ªÀÊ£¬ÄãµÄÎ÷±ßÊÇÒ»ÍûÎŞ¼ÊµÄÉ³Ä®¡£¿ñ·çÔÚºôÏø£¬ÂşÌì»ÆÉ³ÔÚ·É
Îè£¬·ÉÉ³¹ö¹ö¡£É³Àù´òÔÚÄãµÄÉíÉÏ£¬¾ÍÏñÊÇ²Ôñ·Å­Í¶ÏÂµÄ±ù±¢¡£Ú¤Ú¤ÖĞ·Â·ğÒÑÓĞÖÖ
Ğ°¶ñµÄÁ¦Á¿£¬ÈÎºÎÈËËæÊ±¶¼ÓĞ¿ÉÄÜÍ»È»ÏñÒ°¹·°ãËÀÔÚÉ³ÀùÉÏ¡£Â·ÅÆÉÏÖ¸×Å£º
    [33m  ¡º´óÉ³Ä®ÏòÎ÷£¬ĞĞÉÌĞè±¸×ãË®Ô´£¬½á¶Ó¶øĞĞ¡»[32m
LONG
        );
        set("exits", ([ 
  "east" : __DIR__"saiwai",
  "west" : __DIR__"desert_entrance",
]));
        set("outdoors", "quicksand");
	set("coor/x",-1060);
	set("coor/y",0);
	set("coor/z",0);
	setup();
        replace_program(ROOM);

}

