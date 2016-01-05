#include <ansi.h>
inherit ITEM;
void create()
{
    set_name( MAG"��"NOR, ({ "ding","��" }) );
    set("unit", "��");
	set("long","һ��Ϳд�ڵ��ϵĴ��֣�������ɢ�����Ϲ⡣\n");
    set("value",0);
    set("no_get",1);
	set("no_clean_up",1);
    set_weight(150000);
    ::init_item();
}

int heal_ob(object enemy,int count)
{
	object * friends;
	int i,mod;
	if (!enemy)
	{
		message_vision(MAG"\n���ϵĹ⻪������ɢ�ˡ�\n"NOR,this_object());
		destruct(this_object());
		return 1;
	}
	friends = enemy->query_enemy();
	if (environment() != environment(enemy))
	{
		message_vision(MAG"\n���ϵĹ⻪������ɢ�ˡ�\n"NOR,this_object());
		destruct(this_object());
		return 1;
	}
	if (!enemy->is_fighting())
	{
		message_vision(MAG"\n���ϵĹ⻪������ɢ�ˡ�\n"NOR,this_object());
		destruct(this_object());
		return 1;
	}
	message_vision(CYN"\n���ϵĹ⻪������һЩ����Χ������ͷһ�������ܾ޴���ײ��\n\n"NOR,enemy);
	for (i=0;i<sizeof(friends) ; i++)
	{
		mod = COMBAT_D->can_busy(enemy, friends[i], "fall-steps");	
		if (COMBAT_D->do_busy_attack(enemy, friends[i], "fall-steps/luoyeqiufeng", "step", 200, mod))
		{
			message_vision(MAG"$N����һ�ң����´��˸����ġ�\n"NOR,friends[i]);			
//			friends[i]->set_temp("busy_timer/fall-steps",time());
			friends[i]->force_busy(friends[i]->query_busy()+1);
		}
//		message_vision("test:$N",friends[i]);
	}
	count --;
	if (count < 1)
	{
		message_vision(MAG"\n���ϵĹ⻪������ɢ�ˡ�\n"NOR,enemy);
		destruct(this_object());
		return 1;
	}
	call_out("heal_ob",10,enemy,count);
}
