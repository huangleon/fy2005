// ���ѩ��˪����divine����
//	Team average HP��better immediatly followed by a team heal 

#include <ansi.h>
#include <combat.h>
inherit SSERVER;

int exert(object me, object target, int amount1)
{
	int level,i, skill, amount, duration, num, total;
	object *enemy, *mem, *team1, *team;
	
	if(me->query("class")!="huashan")
		return notify_fail("ֻ�л�ɽ���Ӳ���ʹ�á��ѩ��˪����\n");

	level=me->query_skill("hanmei-force",1);
	if (level < 200 || me->query_skill("cloud-dance",1) < 200) 
		return notify_fail("���ѩ��˪����Ҫ200���ĺ�÷�ķ��ͻ÷�Ʈ���衣\n");
		
	duration = me->query("timer/pfm/hs_divine")-time() + 900;
    if (duration>0)
    	return notify_fail("�㻹��Ҫ�ȴ�"+(duration/60)+"�������Ҳ����ٴ�ʹ�á��ѩ��˪��\n");
       		
	team1 = me->query_team();
	if (!(team1)|| sizeof(team1)<2)	
		return notify_fail("���ؼ�����ʹ��û��ʲô���塣\n");

	message_vision(HIW"$N"HIW"��ɫѩ����ֽ��˫�����գ���߳һ��������͸��һ˿��죬�����˵������µĲкۡ�\n"NOR,me);
	
	me->set("timer/pfm/hs_divine",time());
			    
	team = filter_array(team1,(: present($1,environment($2)) :),me);
	num = sizeof(team);	 
	
	amount = 0;
	for (i=0; i<num; i++) 
		amount = team[i]->query("kee") + amount;	
	
	amount = COMBAT_D->magic_modifier(me, me, "kee",amount);
	
	for (i=0;i<num;i++) {
		team[i]->set("kee",amount/num);
		if (team[i]->query("eff_kee") <amount/num)
			team[i]->set("eff_kee",amount/num);
		team[i]->status_msg("kee");
	}
			
	return 1;

}
