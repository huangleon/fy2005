// nine-moon-steps.c
#include <ansi.h>
inherit SKILL;
void setup(){
	set("name","������");
	set("type","step");
	set("usage/dodge",1);
	set("usage/move",1);
	set("skill_class","shenshui");
	set("effective_level",150);
	set("practice_limit",100);
	set("difficulty",200);
	set("dodge_msg", ({
		"$nһ�С����������������ɵر��˿�ȥ��\n",
		"ֻ��$n��Ӱһ�Σ�һʽ��������桹���ѱ����߳�֮�⡣\n",
		"$nʹ�����������桹���������ɵ�������\n",
		"$n����һ�㣬һ�С��������졹�ڿն��𣬱��˿�ȥ��\n",
		"����$nʹһ�С�������������������Ʈ�˿�ȥ��\n",
		"$n��Ӱ΢�����Ѿ���һ�С��������֡�����������\n",
		"����$nһ�С�����ɭɭ��ʹ���������Ƶ�$N���ᣡ\n"
	}) );
}

int valid_learn(object me)
{
        if( (string)me->query("gender") != "Ů��" )
        	return notify_fail("��������ֻ��Ů�Ӳ��������书��\n");
	if (me->query_skill("nine-moon-steps",1)>= me->query_skill("nine-moon-force",1)){
			return notify_fail("��ľ����ľ���򲻹���\n");
	}	
	return ::valid_learn(me);
}


//	Let chaos-steps add to nine-moon-steps.

int effective_level(object me)
{
	
	int skill,n;
	
	if (me) {
/*		skill = me->query("pfm/chaos-9moon");
		if (skill == 20 || skill == 10 || skill == 30)
			return 150 + skill;	
		else 
			return 150;*/
		skill = me->query_skill("chaos-steps",1);
		if (skill >= 150)	return 180;
		if (skill >= 100)	return 170;
		if (skill >= 50)	return 160;
		return 150;	
	}
	return 180;
}


int help(object me)
{
	write(@HELP   
������������dodge.lianhuabu��
��Ҫ30�����������������æ�����֣�120�������м��������æ�����֣�
��Ȼ�ɹ��ʲ��ߣ�����ʹʧ������æ��Ҳֻ��һ�֡�
ˮ�켧�����ŵ��ӣ�����ȼ�25���£�ÿ�Σ����ߣ�����ʦ������ؼ���
�ɹ��ʻ���һ����ߡ�

������ʽ����dodge.feiyanshi��
��Ҫ150������������100���������ǲ�����ʽ�Ǵӵ������ǲ��ġ�����
ʽ������������ս�����������ܶ�����ͨ��ÿ����һ�ε����ƣ�ÿ�κ�
��150������������æ��һ�֡�

��׷��ʽ����dodge.zhuiming��
��Ҫ180������������200�������׹�ץ��200���Ů��
����֮�ʣ����Ծ�������ס���֣������԰׹�ץȡ�䶥��Ҫ��������
����Ѫ����20%���Լ�<=5000��ʱ�м������һ��������
�����ֲ���æ��״̬�����ͼ����æ��һ���ٹ���
�ڶ�������������ȴ�����ӷ������ã�����æ�����֡�

�Ӱ����մ�ѧϰ�������ǲ�����߾��������ȼ���������Ҫ160���Ů��
�������ǲ�L50  ����������Чϵ�������160
�������ǲ�L100 ����������Чϵ�������170
�������ǲ�L150 ����������Чϵ�������180

HELP
    );
    return 1;
}

