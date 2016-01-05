// stormdance.c
// annie 07.2003
// dancing_faery@hotmail.com


#include <combat.h>
#include <ansi.h>
inherit SKILL;

void setup(){
        set("name","�������");
        set("usage/dodge",1);
        set("usage/move",1);
        set("type","step");
        set("difficulty",300);
        set("practice_limit",50);
        set("effective_level",230);
        set("skill_class","moon");
        set("dodge_msg", ({
                "ֻ��$nһ��ת����Ȼ����һЦ��$Nһ��֮�£����ﻹ�����ڡ�\n",
                "����$n���һЦ�����˷��������ξ���$NƮ����$Nֻ��һ����Ϯ����æ���ˡ�\n",
                "$n�����飬��Ȼ����һ����ã��ˮ�����ڷ���֮�䣬$n��ʧȥ��Ӱ��\n",
                "$n�Ų���ӯ��������Ȼ�����ӱ����ڸ�����Ʈ�ΰ��ӹ�������$N����Ϯ��������Ȼ��ȥ��\n",
                "$nϢ�����������������������Ӱ�ڲ�������ƮȻ����\n",
        }) );
}

mixed dodge_ob(object victim, object me,int attack_type)
{
        if (userp(me) && me->query("class")!="moon")            return 0;
        if (me->query_skill("stormdance",1)<100)        		return 0;
        if (me->query_skill_mapped("force") != "snowforce")     return 0;
        if (victim->query_busy())       return 0;
        if (attack_type != TYPE_PERFORM)        return 0;

		if (!userp(me))
		{
        	victim->perform_busy(1);
            if (me->query_busy() > 2 
            	&& victim->query("combat_exp") > me->query("combat_exp")/2 
            	&& me->query_skill("snowforce") >= 200 ) // �Է�����dummy
                        me->start_busy(2);      // ��ô�����������ʩչ��Busy���ܡ�
		}
		else
		{
			if (random(100)> 40+ (me->query_skill("stormdance",1)-100)/10)	return 0;
	        victim->perform_busy(1);
		}

        return WHT"$n����ƮŲ������ӵأ�$Nֻ����Ȼ�����ֻ�ʴ�ǣ�������ʱ���Ͳ��顣\n"NOR;
}       



string query_dodge_msg(object me)
{
        mapping msg;

        msg = skill_attr["dodge_msg"];

        if (me->query_temp("buffup/evade_amount") > 0)
                return CYN"$n��̨�羵���ľ��������·�����Ԥ֪$N�������ƣ��ܵ����֮�⡣\n"NOR;

        if(sizeof(msg) > 0)
                return msg[random(sizeof(msg))];
        
        return 0;
}

int help(object me)
{
	write(@HELP   
�����������������书��æ��״̬���и��ߵļ��ʱܿ����˵Ĺ�����
�ȼ�100����������ܳɹ�����һ�������ж϶��ֵ��ؼ�ʹ�ã�
�伸��Ϊrandom(100) < 40+�����ܵȼ�-100��/10
	
L30��˪��ѩ�衻��dodge.shuangtianxuewu��
������ͨ����ʱ�������еļ��ʣ���������
�ϲ�	����������
�в�	����������
�²�	����������

L150����ѩ��ᰡ���dodge.hanxueliulan��
�������˺��������֣�����ʱ�䣽�������ȼ�����
�ޣ�	15% ������Ѫ�˺�
���:	25% ������Ѫ�˺�
����:	25% �����������˺�
����:	35% �����������˺�
��Ҫ:	45% �����������˺�

HELP
    );
    return 1;
}
