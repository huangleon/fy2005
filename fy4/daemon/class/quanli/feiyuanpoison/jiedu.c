// recover.c

inherit SSERVER;

int curse(object me, object target, int amount)
{
	int force, lvl;
        if( target != me ) return 
	notify_fail("��ֻ�����������Լ����ڶ��رƳ���\n");
        force =(int) me->query("force") - (int) me->query("max_force");
	if( force <=100) return notify_fail("����������㡣\n");
	lvl = me->query_skill("herb",1);
	if (random(lvl) < 20)
	{
	me->add("force", -100  );
	message_vision("$N�˹�������׼���Ѷ��Ƴ����⣮����\n", me);
		return notify_fail("��ʧ���ˡ�\n");
	}
	else
	{
	me->clear_condition();	
		write("��ɹ��رƳ����ڵľ޶���\n");
        return 1;
	}
}
 
