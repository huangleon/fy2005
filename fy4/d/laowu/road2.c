inherit ROOM;
void create()
{
        set("short", "ÄÏ±±´óµÀ");
        set("long", @LONG
ÕâÊÇ·çÔÆ³ÇµÄÒ»ÌõÖ÷Òª´óµÀ¡£ËüÉÏ´©°×É½ºÚË®£¬Ö±´ïËÉ»¨½­¡£ÏÂ½Ó·çÔÆ¾©¶¼£¬
ÔÙÍ¨½­ÄÏº£¿Ú¡£¸ÉÏßÉÏÉÌÂÃ²»¾ø£¬ÕıÊÇ¶«Î÷ºÍÄÏ±±ÉÌµÀµÄ½»»ãÖ®´¦£¬Â·ÅÆÉÏĞ´×Å£º
    [33mÎ÷¡ºÈıÇåÉ½¡»  ¶«¡ºÇ§·ğÉ½¡»  ÄÏ¡º·çÔÆ³Ç¡»  ±±¡º±ù·âÖ®Õò¡»[32m
LONG
        );
        set("exits", ([ 
  "north" : __DIR__"road5",
  "south" : __DIR__"road1",
  "east" : AREA_JINAN"road1q",
 "westup" : AREA_DAOGUAN"sroad",
]));
        set("outdoors", "laowu");
	set("coor/x",0);
	set("coor/y",-10040);
	set("coor/z",0);
	setup();
        replace_program(ROOM);
}
