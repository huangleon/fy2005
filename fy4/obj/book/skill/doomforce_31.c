// Copyright (C) 1995, by Tie Yu and Daniel Yu. All rights reserved.
// This software can not be used, copied, or modified in any form without
// the written permission from authors.
inherit ITEM;
void create()
{
	set_name("����", ({ "����","canqi", "һ��δ��Ĳ���" }));
	set_weight(600);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("unit", "��");
		set("value", 70);
		set("material", "wood");
		set("no_shown",1);
		set("no_get",1);
		set("skill", ([
			"name": 		"doomforce",	
			"exp_required":	0,		
			"sen_cost":		30,	
			"difficulty":	20,	
			"max_skill":	30		
		]) );
	}
    	::init_item();
}
