// annie 07.04.2003
// dancing_faery@hotmail.com
// �ο�ģ��
// �������� 40 gold,70%
// ��ˮ�������ݣ�[ʮʥ��]��[���⾵��]�����»�ʯ

inherit SSERVER;
#include <ansi.h>

int exert(object me, object target, int amount)
{
	int lvl,duration,exp_recovered;
	object obj;
	object drug1,drug2;
	string n1="��������",n2="ʮʥ��",n3="���⾵��";

	amount = 70;	  // 70%
	duration = 7200;  // 120 min

	lvl = me->query_skill("divineforce",1);	
	if( lvl < 150) 	return notify_fail("��"+n1+"����Ҫ150������а�ľ���\n");

	if (me->query("class")!="demon")
		return notify_fail("ֻ��ħ�̵��Ӳ�����ת��"+n1+"����\n");
	
	if (!(drug1 = present("jindan",me)) || !(drug2 = present("jingyu",me)) )
		return notify_fail("ʹ�á�"+n1+"������"+n2+"��"+n3+"����Ϊ����\n");

	if (!drug1->query("is_drug") || !drug2->query("is_drug"))	// �ٻ�?
		return notify_fail("ʹ�á�"+n1+"������"+n2+"��"+n3+"����Ϊ����\n");
	
	if (me->query("force") < 1300)	// 100,400,800,1300,1900.
		return notify_fail("����������㡣\n");
	
	if (!target) target=me;
	
	if(!objectp(obj = present(target, environment(me))))
			return notify_fail("����û������ˡ�\n");
	if (!obj->is_character() || obj->is_corpse() )
			return notify_fail("�����һ�㣬�ǲ����ǻ��\n");
	if( !obj->is_ghost())
		return notify_fail(n1+"�������ڻ������ϡ�\n");
	if( !userp(obj))
		return notify_fail(n1+"ֻ������������ϡ�\n");		
	if( (int)target->query("death/time")+ duration  < time())
		return notify_fail("̫���ˣ����������Ѿ���ʧ���Ȳ����ˡ�������ʱ������"+(duration/60)+"�����ڣ�\n");
    if (!obj->query("env/revive"))
      	return notify_fail("���˲�Ը�ⱻ�˸���������Ҫ�Է�Set revive 1��\n"); 

	exp_recovered=obj->query("death/exp_lost");
	exp_recovered=exp_recovered/100*amount;

    drug1->add_amount(-1);
    drug2->add_amount(-1);

	message_vision(HIW"$N�������˿��������������������ڻ���ʩ��"+n1+"����\n"NOR, me);	
	me->add("force", -1300 );

	if (target!= me) 
		message_vision(HIW"$Nһ������$n���ģ�������������$N�������𣮣���\n"NOR, me,target);

	target->add("combat_exp", exp_recovered);
	target->set("death/time",0);
	target->set("death/exp_lost",0);
	target->reincarnate();
	message_vision( HIW "$N������ҵز����ţ���Ȼ��һ����âע��$N�Ķ��š�\n",target);
	message_vision( HIR "$N�����ˣ���\n"NOR,target);
	me->start_busy(3);
	return 1;
}
 