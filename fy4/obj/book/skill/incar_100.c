// Copyright (C) 1995, by Tie Yu and Daniel Yu. All rights reserved.
// This software can not be used, copied, or modified in any form without
// the written permission from authors.
inherit ITEM;
void create()
{
	set_name("�������", ({ "yufo","yu fo"}));
	set_weight(600);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("unit", "��");
		set("long",
			"һ�����Ժ������������������������\n");
		set("value", 70000);
		set("material", "stone");
		set("skill", ([
			"name": 		"incarnation",	
			"exp_required":	0,		
			"sen_cost":		10,	
			"difficulty":	10,	
			"max_skill":	99		
		]) );
	}
}
