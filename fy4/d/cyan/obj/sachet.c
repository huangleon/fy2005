// annie 07.2003
// dancing_faery@hotmail.com

#include <armor.h>
#include <ansi.h>
inherit NECK;

void create()
{
	set_name(HIR"С����"NOR, ({ "sachet" }) );
	set_weight(5000);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("unit", "��");
		set("value", 0);
		set("material", "jade");
		set("long", "һ��ɢ��һ��������ʴ��������СС���ҡ�\n");
	}
	::init_neck();
}

void init()
{
	if (environment(this_object()) == this_player())
	{
		remove_call_out("greeting");
		call_out("greeting", 60, this_player());
	}
}

void greeting(object me)
{
	int i;
	object env, *inv, obj,victim;

	if (!me)	return;
		
	if (!me->is_fighting() || me->query_temp("armor/neck") != this_object())
	{
		call_out("greeting", 60, this_player());
		return;
	}
	message_vision(HIC"$N"HIC"����ɢ����һ��������ʴ�ǵ����㣮����\n",me);
        
    env = environment(me);
	inv = all_inventory(env);
	           
	for(i=0; i<sizeof(inv); i++)
	{
		victim=inv[i];
		if (victim == me)	continue;
		if (victim->is_corpse() || !victim->is_character()) continue;
		if (!me->is_fighting(victim) && !userp(victim)) continue;	// ����ս����NPC������
		if (!victim->query("can_speak")) continue;	// ����˵���ģ�����
//		if (me->query("gender") == victim->query("gender"))	continue;	// ͬ�Եģ�����

		victim->apply_condition("sachet",5);
		tell_object(victim,HIW"����һ��һ��ؽ�����ı��У�Ѭ����������������ҡ������\n"NOR);
	}
	call_out("greeting", 60, this_player());
	return;
}


