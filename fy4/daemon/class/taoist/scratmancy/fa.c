
#include <ansi.h>

inherit F_CLEAN_UP;


string clr = "��";


int scribe(object me, object sheet)
{
	object newsheet;
	string err;
	int skill;
	string name;
	int amn,cost;

		if(me->query("class")!="taoist")
			return notify_fail("ֻ�����幬���Ӳſ��Ի�����\n");
		
		skill = me->query_skill("scratmancy",1);
		
		if(skill < 70 )
			return notify_fail("�˷�������Ҫ70�����������\n");

		if (skill < 140) {
			name="������";
			amn = 200;
			cost = 50;
		} else if (skill < 200) {
			name="�����";
			amn = 400;
			cost = 100;
		} else {
			name="������";
			amn = 600;
			cost = 150;
		}	
		
		if( sheet->name() != "�ҷ�ֽ" ) 
				return notify_fail(name+"Ҫ�����ҷ�ֽ�ϣ�\n");

		sheet->set_amount((int)sheet->query_amount() - 1);
		seteuid( geteuid(me));
		newsheet = new("/obj/item/magic_seal");
		newsheet->set_name(CYN +name+ NOR, ({ "tomana sheet" }));      


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
		return notify_fail("����" CYN+name+  NOR "��Ҫ����"+cost+"������\n");
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
		if (userp(obj))
		{
			obj->add("mana",-amn/2);
			if (obj->query("mana")<0)
				obj->set("mana",0);
		}
		obj->set_temp("damaged_during_attack", 1);
		COMBAT_D->report_status(obj);
		if (!present("mana sheet",me))
		{
			seteuid( geteuid(me));
			obj = new("/obj/item/magic_seal");
			obj->set_name(YEL+name+  NOR, ({ "mana sheet"}));  
			
			obj->set("desc_ext","�ָ�"+amn+"�㷨��");

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
	me->add("mana",amn,me);
	if (me->query("mana") > me->query("max_mana")*2)
		me->set("mana",me->query("max_mana")*2);
	me->force_status_msg("mana");
	return 1;
}

/*
�X[ ��- FengYun -�� ]���������[
��[dancing_faery@hotmail.com]�������[
��[ ��annie 09.2003�� ]�������a    ��
��[ ������������¶������ʱ������˪ ��
�^��������������������������������-�a
*/


/*

������     /��              ��\      
������   ��   �ܣߣߡ�������  ��       
������   �� ����    ���������v��       
������    �M                  ��       
������    ��   /��\    /��\   ��      
������    ��   ����    ��  �� ��       
������   ��    \ /    \��/    ��      
������    ����      ��      ���M         
������    ���v��    ��   ������         
������    �q������������������           
������   ��   ��           /���\����    
������  ��____��  �� ��  �� .. ����     
������        \���/ ����ܡ�         
                       ��             
����������������- FengYun - ������
 ��������������annie 06.2005
 ��������dancing_faery@hotmail.com

*/
