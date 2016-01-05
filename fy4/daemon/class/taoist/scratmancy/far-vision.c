#include <ansi.h>

inherit F_CLEAN_UP;

int scribe(object me, object sheet)
{
	object newsheet;
	string err;

	if(me->query("class")!="taoist")
		return notify_fail("ֻ�����幬���Ӳſ��Ի�����\n");
		
	if((int)me->query_skill("scratmancy",1) < 35 )
		return notify_fail("���۷���Ҫ35����Ч��֮����\n");

	if( sheet->name() != "�ҷ�ֽ" ) 
		return notify_fail("���۷�Ҫ�����ҷ�ֽ�ϣ�\n");

    if( (int)me->query("mana") < 20 ) 
		return notify_fail("���۷���Ҫ20�㷨����\n");
	me->add("mana", -20);
	me->force_status_msg("mana");
	
	sheet->set_amount((int)sheet->query_amount() - 1);
	seteuid( geteuid(me));
	newsheet = new("/obj/item/magic_seal");
	newsheet->set_name(YEL "���۷�" NOR, 
			({ "far-vision sheet", "sheet"}));      
	newsheet->set("burn_func", (: call_other, __FILE__, "do_burn" :));
	newsheet->move(me);
	newsheet->set("burn_person",me);

	me->save();
	message_vision("$Nд��һ�����۷���\n" NOR, me);
	return 1;
}

int do_burn(object sheet) { 
	string target;
	object obj;

	if (sheet->query("targetname")=="monster nian")
		return notify_fail("�޷����������Ѱ�һNPC��\n");
	
	if(!(sheet->query("targetname"))) {
		return notify_fail("�����������" NOR "��˭��\n");
	}
	message_vision("$N���о��񣬼�����ζ�������һ��" + sheet->name() + "����������\n", this_player());
	this_player()->receive_damage("sen", 5);
	target = sheet->query("targetname");
	obj = find_player(target);
	if(!obj) obj = find_real_living(target);
	if(!objectp(obj) || !objectp(environment(obj)) 
			|| sheet->query("burn_person") != this_player()
			|| environment(obj)->query("no_magic")
			|| environment(obj)->is_character() 
			|| userp(obj)) {
		message("vision", "��е��۾�����ģ�ȴʲôҲû������\n", this_player());
	} else {
		message("vision", "����˸�Ļ���У��㿴����\n", this_player());
				"/cmds/std/look"->look_room(this_player(), environment(obj));
		message("vision", "��е����ӷ������ڰ���������˫�۾������㣡\n", obj);
		message("vision", "����ϸ�ؿ���һ�����ܣ�ȴʲôҲû�У�\n", obj);
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
