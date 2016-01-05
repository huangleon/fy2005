#include <ansi.h>
inherit F_CLEAN_UP;
#define MAX_GUARD 1

int scribe(object me, object sheet)
{
	object newsheet;
	string err;

	if( me->query("class") != "taoist" ) {
		return notify_fail("ֻ�����幬���Ӳſ��Ի�����\n");
	}
	if( (int)me->query_skill("scratmancy",1) < 30 ) {
		return notify_fail("�ٹ����Ҫ30�������������\n");
	}
	if( sheet->name() != "�ҷ�ֽ" ) {
		return notify_fail("�ٹ��Ҫ�����ҷ�ֽ�ϣ�\n");
	}
	if( (int)me->query("mana") < 75 ) {
		return notify_fail("���ٹ��������Ҫ75��ķ�����\n");
	}
	sheet->set_amount((int)sheet->query_amount() - 1);
	seteuid( geteuid(me));
	newsheet = new("/obj/item/magic_seal");
	newsheet->set_name(YEL "�ٹ��" NOR, ({ "zhaogui sheet", "sheet"}));
	newsheet->set("burn_func", (: call_other, __FILE__, "do_burn" :));
	newsheet->move(me);
	newsheet->set("burn_person", me);
	me->add("mana", -50);
	me->force_status_msg("mana");

	me->save();
	message_vision("$Nд��һ���ٹ����\n" NOR, me);
	return 1;
}

int do_burn(object sheet)
{ 
	object obj, soldier, soldier2, me;
	int spells;

	me = this_player();
	if( !me->is_fighting() ) {
		return notify_fail("û����Ҫɱ�㣡\n");
	}
	if( me->query_temp("max_guard") >= MAX_GUARD ) {
		return notify_fail("���Ѿ��ٻ�̫����������ˣ�\n");
	}
	message_vision("$N���о��񣬼�����ζ�������һ��" + sheet->name() + "����������\n", this_player());
	me->start_busy(1);
	if( sheet->query("burn_person") !=me || random(me->query("mana")) < 10 ) {
		message("vision", "����ʲ��Ҳû�з�����\n", environment(me));
		return 1;
	}
	spells = me->query_skill("scratching");
	seteuid(getuid());
	soldier = new("/obj/npc/hell_guard");
	if( soldier ) {
		soldier->set("no_purge", 1);
		soldier->move(environment(me));
		soldier->invocation(me, spells);
		me->add_temp("max_guard",1);
		message_vision(HIB "\n$N"HIB"����$n"HIB"�ı��󺰵�������ɱ��\n" NOR, me, soldier);
		soldier->set("no_purge", 0);
	}
	return 1;
}


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
