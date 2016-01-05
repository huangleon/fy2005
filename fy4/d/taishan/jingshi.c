// Copyright (C) 1995, by Tie Yu and Daniel Yu. All rights reserved.
inherit ROOM;
void create()
{
  set("short","¾­Ê¯Óø");
  set("long",@LONG
ÕâÀïÓë´ó¹Û·åÒ£ÏàºôÓ¦£¬ÊÇÒ»´¦¹æÄ£¸ü´óµÄÄ¦ÑÂÊ¯¿Ì£¬Äê´úÔ¶Ëİµ½±±Æë£¬¾à½ñ
ÒÑÈ»ÓĞÉÏÇ§ÄêÀúÊ·ÁË£¬ÔÚÕâÌìÈ»Ê¯ÆºÖ®ÉÏ£¬ÃÜÃÜÂéÂéµÄ¿Ì×Å¡¶½ğ¸Õ°ãÈô²¨ÂŞÃÛ¾­¡·¡£
¾­ÎÄ×Ö´óÈç¶·£¬×­Á¥¼æ±¸£¬Êé·¨åÙ¾¢£¬Àú´ú×ğÎª¡°´ó×Ö±Ç×æ¡±£¬¡°°ñÊéÖ®×Ú¡±£¬Ç§
Äê·çÓê£¬ÏÖÔÚ[33m¾­ÎÄ[32mÖ»ÓĞÒ»Ç§¶à×ÖÁË£¬µ«È´ÒÀÈ»ÎŞ¿É±ÈÄâ¡£
LONG
  );
  	set("exits",([
	"westdown" : __DIR__"doumu",
	"southup" : __DIR__"luohan",
               ]));
        set("objects", ([
        	BOOKS"skill/bolomiduo_50": 1,
                        ]) );
        set("outdoors", "taishan");
	set("coor/x",10);
	set("coor/y",10);
	set("coor/z",40);
	setup();
  	replace_program(ROOM);
}
