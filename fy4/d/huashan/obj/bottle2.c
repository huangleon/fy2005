// annie. 07.2003
// dancing_faery@hotmail.com

#include <ansi.h>
inherit ITEM;

void create()
{
    set_name("����ƿ", ({ "bottle"}) );
    set_weight(800);
    if (clonep())
    	set_default_object(__FILE__);
    else {
		set("unit", "��");
		set("long", "һ������͸����ɫ��С��ƿ��ƿ�ǽ��ա�\n�������������ƿ�ǣ�����һ��(smell)��\n");
		set("value", 1);
        	set("prep", "in");
    		set("value", 5000);
			set("owner","na da");
    }
	::init_item();
}

void init()
{
   	add_action("do_open","smell");
}

int do_open(string arg)
{
	object me, ob, item;
	
	me = this_player();
	ob = this_object();
	if( !arg || (arg != "bottle" && arg != "��ƿ") ) {
		return notify_fail("��Ҫ��ʲô��\n");
	}
	if (!query("value"))
		return notify_fail("ƿ�е������Ѿ���ɢһ���ˡ�\n");
	message_vision("$NС������ذ�$n����ת��������\n",me,ob);
	tell_object(me,"һ�����˵������߽���ıǶˡ�\n");
	if ( REWARD_D->riddle_check(me,"��������") == 2)
		REWARD_D->riddle_set(me,"��������",3);
	set("long", "һ������͸����ɫ��С��ƿ��ƿ���Ѿ����򿪡�\n");
	set("no_stack",1);
	set("value",0);
	return 1;
}

