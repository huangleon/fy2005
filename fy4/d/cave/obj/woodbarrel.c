
#include <ansi.h>
inherit ITEM;
void decay();

void create()
{
        set_name("��ľͰ", ({ "woodbarrel"}) );
        set_weight(300000);
         set("no_get", 1);
        set_max_encumbrance(800);
	set("unit", "��");
    set("long", "һ��ɢ����Ѫ�������⼨�߰ߵĴ�ԲľͰ������ͭ����������\n��֪���Ƿ���԰�ͰӲ����������split��.\n");
	set("closed", 1);
	set("value", 200);
}

int is_container() {return 1;}

void init()
{
         add_action("do_split","split");
}

int do_split(string arg)
{
	object		me, ob, gold;
	int		kar;
	
        if( !arg || arg != "woodbarrel" )
                return notify_fail("��Ҫ����ʲô��\n");
	me = this_player();
	ob = this_object();
	if(!query("closed")){
        return notify_fail("��ľͰ�Ѿ��������ˡ�\n");
	}
    message_vision("$N����˫�ۣ�����һ������$n����\n", me, ob);
	kar = me->query("kar");
	if(  random(kar) >15 ) { 
		ob->set("closed",0);
        	message_vision("$N���ڰ�$n���ˡ�\n", me, ob);
        	seteuid(getuid());
        	gold = new("/obj/money/silver");
       		gold->set_amount(3+random(12));
        	gold->move(ob);
        	set("name", "�����Ĵ�ľͰ");
        	set("long", "һ��ɢ����Ѫ�������⼨�߰ߵĴ�ԲľͰ����Ͱ��ͭ���Ѿ��������ˡ�\n");
        	call_out("decay", 120);
	}
	else if (random(kar) >5) {
       		message_vision(RED"ֻ����һ������!!���䣢!!ľͰը����Ƭ��$Nȫ������������ͻ����С�\n"NOR, me);
        	me->unconcious();
        	destruct(ob);	
        }
	
	else {
        	message_vision(RED "ֻ�������ͣ���ˮ������$n���һ�ߺ�ɫ��ˮ�����ȳ��ޱȣ�������$N�����ϣ�\n"NOR, me, ob);
		me->apply_condition("no_shadow", 10);
        	message_vision(BLU "$N���˺�ˮ��������\n"NOR, me);
	}
        return 1;
}

void decay() {
	message_vision("$N�ζ��˼��£����һ����ľɢ���ڵء�\n", this_object());
	destruct(this_object());
}
		