// Copyright (C) 1995, by Tie Yu and Daniel Yu. All rights reserved.
// This software can not be used, copied, or modified in any form without
// the written permission from authors.
inherit ITEM;
void create()
{
	set_name("�ڻ�", ({ "bihua","�ڻ�"}));
	set_weight(600);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("unit", "��");
		set("long",	"һ����������ıڻ���\n");
		set("value", 70);
		set("material", "stone");
		set("no_shown",1);
		set("no_get",1);
		set("no_drop",1);
		set("skill", ([
			"name": 		"buddhism",	
			"exp_required":	0,		
			"sen_cost":		1,	
			"difficulty":	5,	
			"max_skill":	29,	
		]) );
	}
}


