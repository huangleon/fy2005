// Copyright (C) 1995, by Tie Yu and Daniel Yu. All rights reserved.
// This software can not be used, copied, or modified in any form without
// the written permission from authors.
inherit ITEM;
void create()
{
	set_name("С���е���", ({ "statue", "little monk", "monk statue"}));
	set_weight(100);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("unit", "��");
		set("long",
"һ����֪��ʲô�������ɵ�С���У��ֽŶ��ܻ��ֻҪ��һ��
������Ļ��أ����ͻ��߳�һ�ײ�����\n");
		set("value", 5000);
		set("no_transfer",1);
		set("material", "steel");
		set("skill", ([
			"name": 	"dodge",	
			"exp_required":	0,		
			"sen_cost":	5,	
			"difficulty":	20,	
			"max_skill":	74		
		]) );
	}
	::init_item();
}
