#include <ansi.h>
inherit ITEM;

void create()
{
        set_name("��������", ({ "keychain" }));
        set_weight(1000);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "��");
                set("long","
����һ��ϸϸСС�����ӣ�է����ȥû��ʲôϡ��ĵط���
����˵�������ϵס��ණ�����á���������ʹ��֮ǰ��
��Ҫ���
");
                set("value", 300000);
				set("destination","none");
				set("material", "steel");
				set("desc_ext","���activate��");
        }
        ::init_item();
}


void init()
{
   	add_action("do_activate","activate");
}
    
    
int do_activate(string arg)
{
    	object me = this_player();

		if (!arg || arg!="keychain")	{
			tell_object(me,"��ʽ��activate keychain\n");
			return 1;
		}
		
		if (REWARD_D->check_m_success(me,"��������")) {
			tell_object(me,"���Ѿ�ӵ������Ϣ���ˣ�\n");
			return 1;
		}
					
		tell_object(me, "
�㼤�������������Ĺ��ܣ������ʹ�÷�������ο�����𡡣���������\n")	;	
		
        REWARD_D->riddle_done(me,"��������",10,1);
        destruct(this_object());
    	return 1;
}

