#include <ansi.h>
#include <armor.h>

inherit BOOTS;

void create()
{
	set_name(HIW"��ط���"NOR, ({ "qingci" }) );
	set_weight(500);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("unit", "��");
		set("material", "cloth");
		set("armor_prop/agility", 3);
		set("armor_prop/dodge", 30);
		set("value", 0);
		set("no_get",1);
	}
	::init_boots();
}

int init()
{
	function f;
	set("armor_worn","��̤");
//	f = (: call_other, __FILE__, "dodge",attacker, victim :);
	f = (: call_other, __FILE__, "dodge" :);
	set_temp("dodge_ob",bind(f, this_object()));
}

void dodge(object attacker,object victim)
{
	if (!attacker->query_temp("annie/7sense_poison"))
	{
		attacker->set_temp("annie/7sense_poison",1);
		message_vision(MAG"\n$n"MAG"����Ʈ�Ƽ���縡����$N"MAG"�����븹�������������\n"NOR,attacker,victim);
		call_out("do_chilling",6,victim,attacker,2+random(2));
	}
}


void do_chilling(object me,object target,int count)
{
	if (!target)	// Ƶ�ʱ�����condition�죬���ɽ����
		return ;
	if (!me)
	{
		target->set_temp("annie/7sense_poison",0);
		tell_object(target,HIW"���еġ�"HIC"����ƶ�"HIW"�����ڷ������ˡ�\n"NOR);
		return;
	}
	if (!me->is_fighting(target))
	{
		target->set_temp("annie/7sense_poison",0);
		tell_object(target,HIW"���еġ�"HIC"����ƶ�"HIW"�����ڷ������ˡ�\n"NOR);
		return;
	}
	if (count > 0)
	{
		count = count - 1;
		tell_object(target,HIW"���еġ�"HIC"����ƶ�"HIW"�������ˣ�\n"NOR);
		switch (random(3))
		{
		case 0:
			target->receive_damage("kee",target->query("combat_exp") / 5000, me);
			break;
		case 1:
			target->receive_damage("gin",target->query("combat_exp") / 8000, me);
			break;
		case 2:
			target->receive_damage("sen",target->query("combat_exp") / 8000, me);
			break;
		}
		call_out("do_chilling",12,me,target,count);

	}
	else
	{
		target->set_temp("annie/7sense_poison",0);
		tell_object(target,HIW"���еġ�"HIC"����ƶ�"HIW"�����ڷ������ˡ�\n"NOR);
	}
	return;
}
