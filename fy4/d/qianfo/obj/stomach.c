// Copyright (C) 1995, by Tie Yu and Daniel Yu. All rights reserved.
// This software can not be used, copied, or modified in any form without
// the written permission from authors.
inherit ITEM;
void create()
{
	set_name("ͭ�˵�θ", ({ "stomach" , "θ", "ͭ�˵�θ"}) );
	set_weight(500);
	set_max_encumbrance(1);
	set("no_get", 1);
	set("no_shown", 1);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("unit", "��");
		set("long", "����һ����ͭ��θ�Ĳ�λ�����۴�С���һ���ס�\n");
		set("value", 1);
	}
	::init_item();
}
int is_container() { return 1; }
