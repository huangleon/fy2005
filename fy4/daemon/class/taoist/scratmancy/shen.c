
#include <ansi.h>

inherit F_CLEAN_UP;


string typ = "sen";
string clr = "��";
int cost;

int scribe(object me, object sheet)
{
	object newsheet;
	string err;
	int skill;
	string name;
	int amn;
	
		if(me->query("class")!="taoist")
			return notify_fail("ֻ�����幬���Ӳſ��Ի�����\n");
		
		skill = me->query_skill("scratmancy",1);
		if( skill < 65 )
				return notify_fail("�˷�������Ҫ65�����������\n");

		if (skill < 130) {
			name="���ķ�";
			amn = 200;
			cost = 100;
		} else if (skill < 180) {
			name="�����";
			amn = 400;
			cost = 200;
		} else {
			name="�����";
			amn = 600;
			cost = 300;
		}		

		if( sheet->name() != "�ҷ�ֽ" ) 
				return notify_fail(name+"Ҫ�����ҷ�ֽ�ϣ�\n");

		sheet->set_amount((int)sheet->query_amount() - 1);
		seteuid( geteuid(me));
		newsheet = new("/obj/item/magic_seal");
		newsheet->set_name(CYN +name+ NOR, ({ "toshen sheet" }));      

		newsheet->set("burn_func", (: call_other, __FILE__, "do_burn" :));
		newsheet->move(me);
		newsheet->set("burn_person",me);
		
		
		newsheet->set("s_name",name);
		newsheet->set("s_amn", amn);
		newsheet->set("s_cost",cost);
		
		me->save();
		message_vision("$N����һ��"CYN+name+ NOR"��\n" NOR, me);
		return 1;
}

int do_burn(object sheet)
{ 
	string target;
	object obj,me=this_player();
	int ap,dp;

	string name;
	int amn, cost;
	name = sheet->query("s_name");
	amn = sheet->query("s_amn");
	cost = sheet->query("s_cost");
	
	if (!me->is_fighting())
		return notify_fail(CYN+name+ NOR "ֻ����ս����ʹ�á�\n");

	if (me->query("mana") < cost)
		return notify_fail("����" CYN+name+  NOR "��Ҫ����"+cost+"�㷨����\n");
	
	me->add("mana",-cost);
	me->force_status_msg("mana");

    if( sheet->query("burn_person")!=me )
	{
		message("vision", "����ʲ��Ҳû�з�����\n", environment(me));
		return 1;
	}
	
	obj=me->select_opponent();
	if (!obj)	
		return notify_fail(CYN+name+ NOR "ֻ����ս����ʹ�á�\n");
		
	message_vision(CYN"\n$N����һ��"+name+" ��һ���������������������ڿ�������һ�ܣ���$nֱ���ȥ��\n\n"NOR, me,obj);

	ap = me->query_skill("scratching");
	ap = ( ap * ap / 50 ) * (int)me->query("sen") ;
	dp = obj->query("combat_exp");

	if( random(ap + dp) > dp )
	{
		message_vision(WHT"��������$n���壬תΪǳǳ��"+clr+"ɫ���ɻ�$N����������Ρ�\n\n"NOR, me,obj);
		obj->receive_damage(typ,amn/10,me);
		obj->receive_wound(typ,amn/10,me);
		obj->set_temp("damaged_during_attack", 2);
		COMBAT_D->report_status(obj);
		COMBAT_D->win_lose_check(me,obj,amn/10);
		if (!present("shen sheet",me))
		{
			seteuid( geteuid(me));
			obj = new("/obj/item/magic_seal");
			obj->set_name(YEL+name+  NOR, ({ "shen sheet" }));  			
			obj->set("desc_ext","�ָ�"+amn+"������");
			obj->set("burn_func", (: call_other, __FILE__, "do_heal" :));
			obj->move(me);
			obj->set("burn_person",me);
			obj->set("lore",1);
			obj->set("s_name",name);
			obj->set("s_amn", amn);
		}
		else
			message_vision(HIB"��ȻŨ�����𣬷��侹�Ի��ɻҡ�\n\n"NOR, me,obj);
	}
	else
		message_vision(YEL"���Ǳ�$n�㿪�ˡ�\n\n"NOR, me,obj);
	me->perform_busy(2);	
	return 1;
}

int do_heal(object sheet)
{ 
	string target;
	object obj,me=this_player();
	int ap,dp;
	string name;
	int amn;
	name = sheet->query("s_name");
	amn  = sheet->query("s_amn");
	
	if (sheet->query("burn_person")!= me) {
		message_vision(CYN"$N����һ��"+name+ "��һ����"+clr+"ɫ�������������𣬺ܿ����ʧ�ˡ�\n\n"NOR, me);
		return 1;
	}
		
	message_vision(CYN"\n$N����һ��"+name+ "��һ����"+clr+"ɫ����������������$N��߻��Ʋ�ȥ��\n\n"NOR, me);
	me->receive_fulling(typ,amn,me);
	return 1;
}
