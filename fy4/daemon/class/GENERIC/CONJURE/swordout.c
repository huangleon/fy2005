// silencer@fy4

#include <ansi.h>
inherit SSERVER;

int conjure(object me, object target)
{
	object sword;	
	int skill;
	object *inv, ob;
	int i;
	
	seteuid(getuid());
	        
	if( me->is_fighting() )
		return notify_fail("�㻹���Ȱѵ��˴�����˵�ɣ�\n");
	
	if (me->query("class")!="wudang")
		return notify_fail("��Ԧ���������䵱������\n");
	
	if (me->query_skill("sword",1)<100)
		return notify_fail("��Ԧ������������Ҫ100���Ļ���������\n");
		
	if (me->query_skill("incarnation",1)<100)
		return notify_fail("��Ԧ������������Ҫ100������������\n");
		
	if (me->query("atman")<110)
		return notify_fail("��Ԧ������������Ҫ100��������\n");
	
	if (me->query("gin")<110)
		return notify_fail("��Ԧ������������Ҫ100�㾫����\n");
			
	inv = all_inventory(me);
	for(i=0;i<sizeof(inv);i++){
		ob = inv[i];
		if(ob->query("name")== HIY"��"NOR
			||ob->query("name")== HIG"ľ��"NOR
			||ob->query("name")== HIW"ֽ��"NOR 
			||ob->query("id") == "forcesword") {
			return notify_fail("���Ѿ���һ�����ƵĽ��ˡ�\n");
		}
	}

	skill=(me->query_skill("incarnation",1) + me->query_skill("sword",1))/ 150;
	
	me->add("atman", -100);
	me->receive_damage("gin", 100);

	message_vision(WHT"һ���׹��糤������������Ȧ������$N���С�\n"NOR,me);
	switch( skill ){	
		case 0: 
		case 1:
			sword = new("/obj/weapon/sword_gold");
	        	break;
		case 2:	
			sword = new("/obj/weapon/sword_wood");
	               	break;
		default: sword =  new("/obj/weapon/sword_paper");
	               	break;
        }
	
	if (!sword->move(me)) destruct(sword);
	else
		tell_object(me,"�������һ��"+sword->name()+"��\n");
	me->start_busy(2);
	return 1;
}

