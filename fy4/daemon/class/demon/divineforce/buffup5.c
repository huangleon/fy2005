// annie 07.04.2003
// dancing_faery@hotmail.com
// buffup�ģ��ο�ģ��
// �커���� 50 gold,120min,4k buffup.
// ����ݣ������꣬��¶ˮ��[���൤]��[˫����ʯ]

inherit SSERVER;
#include <ansi.h>

int exert(object me, object target, int amount)
{
	int lvl,duration;
	object obj;
	object drug1,drug2;

	amount = 4000;	// 4k.
	duration = 7200;// 120 min

	lvl = me->query_skill("divineforce",1);	// RESEARCH: 180 -> 200
	if( lvl < 200) 	return notify_fail("���커���ǡ���Ҫ200������а�ľ���\n");

	if (me->query("class")!="demon")
		return notify_fail("ֻ��ħ�̵��Ӳ�����ת���커���ǡ���\n");
	
	if (!(drug1 = present("yushu",me)) || !(drug2 = present("nishi",me)) )
		return notify_fail("ʹ�á��커���ǡ��������൤��˫����ʯ����Ϊ����\n");

	if (!drug1->query("is_drug") || !drug2->query("is_drug"))	// �ٻ�?
		return notify_fail("ʹ�á��커���ǡ��������൤��˫����ʯ����Ϊ����\n");
	
	if (me->query("force") < 1900)	// 100,400,800,1300,1900.
		return notify_fail("����������㡣\n");
	
	if (!target) target=me;
	
	if(!objectp(obj = present(target, environment(me))))
			return notify_fail("����û������ˡ�\n");
	if (!obj->is_character() || obj->is_corpse() )
			return notify_fail("�����һ�㣬�ǲ����ǻ��\n");

	/*
	if (target->query_temp("buffup/buffed_kee"))
			return notify_fail("�����Ѿ����������Ƶ��湦��\n");	
	if (target->query_temp("buffup/buffed_gin"))
			return notify_fail("�����Ѿ����������Ƶ��湦��\n");	
	if (target->query_temp("buffup/buffed_sen"))
			return notify_fail("�����Ѿ����������Ƶ��湦��\n");	

	*/
    if( ANNIE_D->check_buff(target,"gks")) 
       	return notify_fail("�����Ѿ����������Ƶ��湦��\n");
	
/*	my_exp=me->query("combat_exp");
	your_exp=target->query("combat_exp");
	if (my_exp>your_exp*3 || my_exp<your_exp/3
		|| my_exp> your_exp+3000000 || my_exp < your_exp- 3000000)
		return notify_fail("����֮�书�����̫Զ��,�����޷�����.\n");	
*/	// hmm...��Ǯ�ľ��Ǵ�ү�...50gold,��Ҫ������

    if (target != me || random(2)) drug1->add_amount(-1);
    if (target != me || random(2)) drug2->add_amount(-1);
	// ���Լ�ʩչ�ĺô�����ʡ$$..

	message_vision(HIW"$N�������˿��������������������ڻ���ʩ���커���ǡ���\n"NOR, me);	
	me->add("force", -1900 );

	if (target!= me) 
		message_vision(HIW"$Nһ������$n���ģ�������������$N�������𣮣���\n"NOR, me,target);
	
//	if (me->query("fy41/dwg_ih_buffup")|| me->query("fy41/all"))
//		amount = amount * 2;

	target->set_temp("buffup/buffed_kee",1);
	target->set_temp("buffup/buffed_gin",1);
	target->set_temp("buffup/buffed_sen",1);

	call_out("apply_effect",2, me,target,duration, amount);
	me->start_busy(3);
	return 1;
}
 
	
void apply_effect(object me,object target, int duration,int amount)
{
	int gin,kee,sen;
	mapping buff;

		buff =
			([
				"caster":me,
				"who":target,
				"type":"gks",
				"att":"bless",
				"name":"���ľ����커����",
				"buff1":"gin",
				"buff1_c":amount,
				"buff2":"kee",
				"buff2_c":amount,
				"buff3":"sen",
				"buff3_c":amount,
				"time":duration,
				"buff_msg":HIW"һƬǳɫϼ����$Nͷ���վۣ�һ����ɽ�$N���ţ�����\n"NOR,
				"warn_msg":WHT"����������еĳ�ʵ֮����һ��һ�����ʧ������\n"NOR,
				"disa_msg":HIR BLK"���������ֻ��������һ������������࣡\n"NOR,
				"special_func":1,
			]);
		ANNIE_D->buffup(buff);

	/*
	message_vision(HIW"һƬǳɫϼ����$Nͷ���վۣ�һ����ɽ�$N���ţ�����\n"NOR,target);

	gin = (int)target->query("max_gin");
	target->set("max_gin",gin+amount);
	target->set("eff_gin",target->query("eff_gin")+amount);

	kee = (int)target->query("max_kee");
	target->set("max_kee",kee+amount);
	target->set("eff_kee",target->query("eff_kee")+amount);

	sen = (int)target->query("max_sen");
	target->set("max_sen",sen+amount);
	target->set("eff_sen",target->query("eff_sen")+amount);
	
	call_out("warning",duration-180, target,amount);
	*/
	return;
}
/*
void warning(object target,int amount)
{
	tell_object(target, WHT"����������еĳ�ʵ֮����һ��һ�����ʧ������\n"NOR );
	call_out("remove_effect",180, target,amount);
	return;
}

void remove_effect(object target, int amount)
{
	tell_object(target, HIR BLK"���������ֻ��������һ������������࣡\n"NOR );

	target->set("max_gin",(int)target->query("max_gin")-amount);
	if (target->query("eff_gin")>target->query("max_gin"))
			target->set("eff_gin",target->query("max_gin"));
	if (target->query("gin")>target->query("max_gin"))
			target->set("gin",target->query("max_gin"));

	target->set("max_kee",(int)target->query("max_kee")-amount);
	if (target->query("eff_kee")>target->query("max_kee"))
			target->set("eff_kee",target->query("max_kee"));
	if (target->query("kee")>target->query("max_kee"))
			target->set("kee",target->query("max_kee"));

	target->set("max_sen",(int)target->query("max_sen")-amount);
	if (target->query("eff_sen")>target->query("max_sen"))
			target->set("eff_sen",target->query("max_sen"));
	if (target->query("sen")>target->query("max_sen"))
			target->set("sen",target->query("max_sen"));

	target->delete_temp("buffup/buffed_kee");
	target->delete_temp("buffup/buffed_kee");
	target->delete_temp("buffup/buffed_sen");
	return;
}
*/