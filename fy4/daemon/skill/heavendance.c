// �纳��ͩ��į������ͩҶ��д�볦���̶�һҹ��ͩ�꣬է�����������ԡ�
// �콵������ͩ�磬��Ȼ��ˮ�����ѡ��������跢�峪��ѩ����ɽ�ǹ��硣
// annie.6.28.03

#include <ansi.h>
inherit SKILL;
void setup() {
	set("name","�����ֻص���");
	set("practice_limit",100);
	set("type","blade");
	set("difficulty",230);
	set("usage/blade",1);
	set("usage/parry",1);
	set("effective_level",230);
	set("skill_class","demon");
        set("parry_msg", ({
        "$n������ת��һʽ��ѩ����ɽ�ǹ��硹�۳�һƬѩҲ�ƵĹ⻪��סȫ��\n",
                })
        );
        set("unarmed_parry_msg", ({
        "$n�յ���ü����̤���ѣ�һʽ����Ȼ��ˮ�����ѡ�����$N��\n",
                })
        );
        action = ({
        ([      "action":               "$N��Ӱ����ȥ��էȻ��ü���ף��ӳ�һ�����纳��ͩ��į������",
                "dodge":                60,
                "damage":               200,
                "damage_type":  "����"
        ]),
        ([      "action":               "$N����ü�ģ�����$w����ߵͻΣ��·�����һ��Ů��ִ���ú�С�ʣ�\n���ڡ���ͩҶ��д�볦����",
                "dodge":                40,
                "damage":               320,
                "damage_type":  "����"
        ]),
        ([      "action":               "$Nʩ�����̶�һҹ��ͩ�꡹�����ܵĵ�������Ļ�����£�����ҹ�붬�꣬\n�εδ��ᣬ���ϳ���",
                "dodge":                240,
                "damage":               280,
                "damage_type":  "����"
        ]),
        ([      "action":               "$NüĿ�����ӯȻ������$wһʽ��է�����������ԡ�����$n����������\n�˳��ѵ���ૡ�",
                "dodge":                160,
                "damage":               360,
                "damage_type":  "����"
        ]),
        ([      "action":               "$N��ȹ����Ծ�ڿ��е���������������$w�ƿ�����$n�����ǡ��콵��\n����ͩ�硹��",
                "dodge":                100,
                "damage":               420,
                "damage_type":  "����"
        ]),
        ([      "action":               "$N�������裬��Ц��Ȼ��ͻչ���������跢�峪����$nͷ���ӹ���ȹ��\n�縡��Ʈ��$n��ͷ����˭Ҳû�п���ȹ��һĨ���⡣",
                "dodge":                200,
                "damage":               480,
                "damage_type":  "����"
        ]),
        });
}
int valid_learn(object me)
{
        if(!::valid_learn(me))
                return 0;
        if (me->query("gender") != "Ů��")
                return notify_fail("һ�������ˣ�Ҳ����˼ѧ��ŤŤ����ĵ�����\n");
        if( me->query_skill("move", 1) < me->query_skill("heavendance",1) )
                return notify_fail("��������׻���㣬������ϰ�����ֻص�����\n");
        return 1;
}

mixed hit_ob(object me, object victim, int damage_bonus)
{
        int skill;
        skill = me->query_skill("heavendance",1);
        if (me->query("age") < 16 || me->query("age") > 36)     return 0;
        if (victim->query("gender") != "����")  return 0;
        if (victim->query("age") < 16)  return 0;
        if (!userp(me))
                skill += 100;
        if ((random(skill) > 100 || me->query_temp("annie/perform_heavendance")) && random(me->query_per()) > random(victim->query_cps()))
        {
                victim->perform_busy(1);
                return CYN"$n�ճյ�����$N�������������Ϳ������µ�һ˿������˵����һ�С�\n"NOR;
        }
        return 0;

}

int help(object me)
{
	write(@HELP   
Ů�Ӷ����书������ʱ��������������ߣ���һ����
����Է�æ��һ��

����б�˾�����yuexierenjing��
һ����ʱ�������������ԼΪ1-2�֣���ʹ���ڼ����һ����
������ܵ�ס���з�ħ����Ѫ�˺���
�޹����ӳɣ�
�����˺���=�����ֻص���*i

HELP
    );
    return 1;
}
