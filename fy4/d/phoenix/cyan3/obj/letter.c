#include <ansi.h>

inherit ITEM;
void create()
{
        set_name("�ݲ���͵���", ({ "letter", "��"}) );
        set_weight(50);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "��");
                set("value", 0);
                set("long","
����һ��ݲ���͵��ź���������������ּ�д����ڣֱԭ������������
����Щ��Ҫ˺��(tear)������������\n\n"NOR);
        }
	::init_item();
}

void init()
{
  	if(this_player()==environment()){
		add_action("do_tear","tear");
	}
}

int do_tear(string arg)
{
	object	me, ob;
        if(arg != "letter" )    return 0;
	me = this_player();
	ob = this_object();
	message_vision("$N��$n�ķ��˺����ȡ�������е��ż㡣\n", me, ob);
	set_name("��˺������", ({ "letter", "��"}) );
	set("long","һ���Ѿ����˷���ŷ⣬������ż�����ϸ��������ԭ��������̵ļƻ���\n��Խ��Խ���ľ�����������䵽�����������\n");
	REWARD_D->riddle_done(me,"����",0,1);
	remove_action("do_tear","tear");
	return 1;
}
