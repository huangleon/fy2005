// Copyright (C) 1995, by Tie Yu and Daniel Yu. All rights reserved.
// This software can not be used, copied, or modified in any form without
// the written permission from authors.
inherit ITEM;
void create()
{
	set_name("����ͼ", ({ "shuaiyi picture","picture"}));
	set_weight(600);
	if( clonep() )
		set_default_object(__FILE__);
	else {
        set("unit", "��");
		set("long",
            "\n��   ��   ͼ\n\n��ɽɽ����������ʱ�����緢��߳�彭��������ɽ�����ǳ۳Ҵ��ϱ����������\nĳ�գ�������ƺ�ң�뵱�겫��ɳ����ʿ����ʼ��֮��٣�һʱ����һ���ǳ�\n���˴˻�����֮���⣬���ñ��ǲ���ɳ֮�٣�ͼ�о����������Ա��裬������ɱ\n֮�⡣\n");
		set("value", 70);
		set("material", "stone");
		set("skill", ([
            		"name":         "assassin-hammer",    
            		"exp_required":	100000,      
			"sen_cost":	50,	
			"difficulty":	50,	
            		"max_skill": 	30      
		]) );
	}
    ::init_item();
}
