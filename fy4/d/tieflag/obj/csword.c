#include <ansi.h>
#include <weapon.h>
inherit SWORD;
void create()
{
        set_name(HIG"������"NOR, ({ "longlife sword","sword" }) );
        set_weight(20000);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "��");
                set("long","����һ��������ˮ�ĳ�����\n");
                set("material", "steel");
                set("baiyujing", 1);
                set("rigidity", 1000);
                set("wield_msg", "$N�ӳ¾ɵĽ����аγ�һ��$n�������С�\n");
                set("unequip_msg", "$N�����е�$n��������Ľ��ʡ�\n");
                set("weapon_prop/agility", 0);
                set("weapon_prop/personality", 0);
        }

        ::init_sword(20);

}
 
void init()
{
	add_action("do_look","look");
	add_action("do_turn","turn");
}

int do_look(string arg)
{
	object me;
	object obj;
	me=this_player();
	if (!arg) return 0;
	if (arg[0..4] != "sword") return 0;
	if( (obj = present(arg, me)) || (obj = present(arg, environment(me))))
	{
		if (obj != this_object()) return 0;
		if ((random(me->query_int())<15) || (random(me->query_kar())<12))
		{
			obj->set("long","����һ��������ˮ�ĳ�����\n");
			obj->set_temp("can_turn",0);
			return 0;
		}
		else
		{
			obj->set("long","��ѽ��Ľ����ƺ�����������(turn)\n");
			obj->set_temp("can_turn",1);
			return 0;
		}
	}
	return 0;
}
    
int do_turn(string arg)
{
	object paper;
	if(!arg || arg != "sword") return 0;
	if(!query_temp("can_turn")) return 0;
	message_vision("$N����ת���������Ľ���...\n",this_player());
	if(query_temp("been_get"))
		return notify_fail("��ת��������������տ���Ҳ��ʲôҲû�С�\n");
	set_temp("been_get",1);
	tell_object(this_player(),"�㷢���������һ��ֽ�����ֽ�����˳�����\n");
	paper=new(__DIR__"fakedesign");
	paper->move(this_player());
	return 1;
}