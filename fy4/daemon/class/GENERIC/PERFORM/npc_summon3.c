
inherit SSERVER;

int perform(object me, object target)
{
	object soldier;
	int	spells,lvl;

	if(userp(me))
		return notify_fail("����ѡ�õ��书��û�����ֱ�ɱ������\n");

        spells = me->query_skill("spells");
        if(me->query_skill("sheolmagic",1) < 125 )
                return notify_fail("��ҹ���ٻ�����Ҫ125����ҹ��ͨ�鷨��\n");

	if( !me->is_fighting() )
		return notify_fail("ֻ��ս���в����ٻ����ݣ�\n");

	message_vision("$N�૵����˼������˫��һ�ӣ�һ�������Եص�����\n", me);
	me->set("timer/demon_guardian3",time());
	seteuid(getuid());
	soldier = new("/obj/npc/guardian3");
	soldier->move(environment(me));
	soldier->invocation(me, spells);
	soldier->set("possessed", me);
	me->perform_busy(2);
	return 1;
}



/*

���������������X�Y
���������������U�t�r
���������������U���t�r
���������������U�����t�r
���������������U��������
���������������^�k�k�k�_

��������������- FengYun - ������
������������annie 08.2003
������dancing_faery@hotmail.com
*/
