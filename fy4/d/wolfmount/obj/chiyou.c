// Copyright (C) 1995, by Tie Yu and Daniel Yu. All rights reserved.
// This software can not be used, copied, or modified in any form without
// the written permission from authors.
inherit ITEM;
void create()
{
    set_name("����", ({ "����","���","chiyou","juxiang","�������"}));
	set_weight(500000);
	if( clonep() )
		set_default_object(__FILE__);
	else {
        set("unit", "��");
		set("long",
            "\n                   �           ��           ��           \n\n����˴����а����֮�ף�ͳ�ʾŴ��壺�����ġ��֡��ҡ��ڡ��ݡ�а���ޡ���\n����ÿ�����ʹ�ٸ�С�壬��������������֮�ࡣ����ȱ�նɱ�󣬸�����󶼳�\n���ڻƵۣ�Ψ����һ���Ȼ������ɽ�����������ΰ������ؿ��Լ����񡣡�\n");
		set("value", 70);
		set("material", "stone");
		set("no_shown",1);
		set("no_get",1);
		set("no_drop",1);
	}
    ::init_item();
}
