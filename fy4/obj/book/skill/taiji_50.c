// Copyright (C) 1995, by Tie Yu and Daniel Yu. All rights reserved.
// This software can not be used, copied, or modified in any form without
// the written permission from authors.
inherit ITEM;
void create()
{
	set_name("̫��ȭ����ͼ", ({ "taijibook","̫��ȭ����ͼ" }));
	set_weight(600);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("unit", "��");
		set("long",
			"һ��̫��ȭ����ͼ��\n");
		set("value", 70);
		set("material", "paper");
		set("no_shown",1);
		set("no_get",1);
		set("skill", ([
			"name": 		"taiji",	
			"exp_required":		2000,		
			"sen_cost":		20,	
			"difficulty":	20,	
			"max_skill":	50		
		]) );
	}
	::init_item();
}
