#include <ansi.h>

int exert(object me, object target, int amount)
{
        int ammount;
		object *team, *team1;
		int lvl, num, i,teampf;

		if(me->query("class")!="beggar")
    		return notify_fail("ֻ��ؤ����Ӳ���������¶�޵İ��\n");

        if( target && target!=me )
            return notify_fail("����¶����ֻ�������Լ����ϡ�\n");

        if( (int)me->query("force") < 300 )
                return notify_fail("��¶����Ҫ300��������\n");
        me->add("force", -300);
        
        message_vision(BGRN + HIW "$N��Ŀ���񣬹�����򣬽������ķ��еĲ�¶����תһ�ܡ�\n"NOR,me);

	
		team1 = me->query_team();
		if (team1 && me->query_skill("huntunforce",1)>=150)
		{
			team = filter_array(team1,(: present($1,environment($2)) :),me);
			num = sizeof(team);	
			for (i=0; i<num; i++)
			{
				if (team[i]->query("food")<100) team[i]->set("food",100);
		        if (team[i]->query("water")<100) team[i]->set("water",100);
		        tell_object( team[i], "�㸹�пտյĸо���ʧ�ˡ�\n" NOR,team[i]);
				tell_object( team[i], "��ڸ�����ĸо�Ҳ��ʧ�ˡ�\n" NOR,team[i]);
			}
			        me->perform_busy(1);
		}

		if ( (int)me->query_skill("huntunforce",1)<100) 
		{
			if (me->query("food")<100) me->set("food",100);
			tell_object( me, "�㸹�пտյĸо���ʧ�ˡ�\n" NOR,me);
		}	else {
				if (me->query("food")<100) me->set("food",100);
        		if (me->query("water")<100) me->set("water",100);
             	tell_object( me, "�㸹�пտյĸо���ʧ�ˡ�\n" NOR,me);
				tell_object( me, "��ڸ�����ĸо�Ҳ��ʧ�ˡ�\n" NOR,me);
             }	
        me->perform_busy(1);
        return 1;
}
