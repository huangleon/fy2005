// Copyright (C) 1995, by Tie Yu and Daniel Yu. All rights reserved.
// This software can not be used, copied, or modified in any form without
// the written permission from authors.
#include <ansi.h>
inherit ROOM;

void midnight_event();
void sunrise_event();

void create() {
	set("short",HIR"ÀÏ³Ç¹ã³¡"NOR);
	set("long", @long
³ÁÏãÕòµÄÖÐÐÄ¹ã³¡µÄ±±ÃæÊÇÒ»ÌõÐ¡ºÓÁ÷£¬ºÓÁ÷µÄÅÔ±ßÓÐÒ»¿é´óÇàÊ¯£¬¾Íµ±×ö´¬
·òµÄÉÏ°¶µÄÐ¡ÂëÍ·£¬À´À´ÍùÍùµÄ²µ´¬¶¼ÔÚÕâÀïÐ¶»õ£¬ÈÕ¾Ã¾Í³ÉÁË¸öÈÈÄÖµÄÐ¡ÊÐ³¡¡£
¹ã³¡ÖÐÐÄÓÐÒ»Æ½Ì¨£¬µÇ¸ßÒ»Íû£¬Î÷ÄÏÈºÉ½Æð·ü£¬ÓÐÖøÃûµÄ[33m»ÆÉ½[32mºÍ[33mÀÇÉ½[32m£¬¶«ÄÏÊýÊ®Àï
ÍâÊÇÁ¬ÃàµÄ[33mÃ§ÁÖ[32mºÍ[33mÕÓÔó[32m£¬±±ÃæÐÐÉÌÖ®Â·Ò»Ö±Í¨Ïò[33mÈûÍâ[32m¡£
long);
	set("exits", ([
			"north" : __DIR__"cx4",
			"south" : __DIR__"cxs1",
			"east" : __DIR__"cxe1",
			"west" : __DIR__"nanbank",
			]));
	set("objects", ([
			__DIR__"npc/fishseller": 1,
			__DIR__"npc/fishbuyer": 1,
			]) );
	set("outdoors", "chenxiang");
	set("coor/x",0);
	set("coor/y",0);
	set("coor/z",0);
	setup();
	NATURE_D->add_day_event(0, 2, this_object(), (: midnight_event :)); 
}


void midnight_event() {
	object badguy;
	object room = this_object();
	int i, bandit_no = 2 + random(5);
	
	if(!random(20)) {
		for(i=0; i<bandit_no; i++) {
			if(objectp(badguy = new("/obj/npc/bandit"))) {
				badguy->setup_bandit("ÃÉÃæÍÁ·Ë", "/obj/armor/cloth", "/obj/weapon/blade_guitou", "cx");
				badguy->move(room);
				badguy->ccommand("chat ÔÂºÚÉ±ÈË£¬·ç¸ß·Å»ð£¡");
			}
		}
		NATURE_D->add_day_event(3, 1, this_object(), (: sunrise_event :));
	} else {
		NATURE_D->add_day_event(0, 2, this_object(), (: midnight_event :));
	}
}

void sunrise_event() {
	object *ob_list;
	int i;
	
	ob_list = children("/obj/npc/bandit");
	for(i=0; i<sizeof(ob_list); i++) {
		if(ob_list[i]->query("area_mark") == "cx") {
			if(environment(ob_list[i])) {
				message_vision("$N½ÐµÀ£ºÌìÏþÒ²£¬³¶ºõ£¡\n",ob_list[i]);
			}
			destruct(ob_list[i]);
		}
	}
	NATURE_D->add_day_event(0, 2, this_object(), (: midnight_event :));
}
