// Copyright (C) 1995, by Tie Yu and Daniel Yu. All rights reserved.
// This software can not be used, copied, or modified in any form without
// the written permission from authors.
inherit COMBINED_ITEM;
void create()
{
	set_name("ϴ�辭", ({ "xisui"}));
	set_weight(100);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("unit", "��");
		set("base_unit","��");
		set("long",
			"����������Ϊ������ϴ�辭.\n");
		set("base_value", 0);
		set("material", "paper");
		set("no_sell",1);
		set("no_get",1);
		set("no_drop",1); 
		set("skill", ([
			"name": 		"xisui",	
			"exp_required":	2000000,		
			"sen_cost":		10,	
			"difficulty":	20,	
			"max_skill":	99,
			"literate" : "fanwen",
			"liter_level":  50,
		]) );
	}
	set_amount(1);
}
