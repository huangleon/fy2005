// Copyright (C) 1995, by Tie Yu and Daniel Yu. All rights reserved.
inherit ROOM;
void create()
{
  set("short","»¢É½");
  set("long",@LONG
É½ÊÆÈç»¢£¬ĞÛ°ÔÒ»·½£¬µØ´¦Ì©É½¶«²à£¬Î÷ÁÙÍõÄ¸³Ø£¬¾İ´«ÄËµ±ÄêÊØ»¤ÍõÄ¸µÄÁé
»¢Ëù»¯£¬Ô¶¿´[33mÉ½ÂÍ[32m£¬ÕÅÑÀÎè×¦£¬×÷ÊÆÓûÆË£¬Áé¶¯È÷ÍÑ£¬½Ã½İÎŞÂ×£¬¿ÉÓëÎäºº¹ê£¬Éß
¶şÉ½Ïà±È¼ç£¬×ÔÈ»Ö®µÀ£¬Íò·¨Ö®¶ËÒ²¡£
LONG
  );
  	set("exits",([
	"west" : __DIR__"wangmu",
               ]));
        set("objects", ([
        	BOOKS"skill/tigerstrike_100" : 1,
                        ]) );
        set("outdoors", "fengyun");
	set("coor/x",20);
	set("coor/y",10);
	set("coor/z",0);
	setup();
	replace_program(ROOM);

}
