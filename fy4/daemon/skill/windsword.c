#include <ansi.h>
inherit SKILL;
void setup(){
        set("name","�ط罣��");
        set("damage_level",200);
        set("usage/sword",1);
        set("usage/parry",1);
        set("effective_level",200);
        set("type","sword");
        set("difficulty",200);
        set("skill_class","npc");
        set("parry_msg", ({
        "$n���μ��ˣ�����$v���·��裬һ�С������������󡹣���ס$N����ʽ��\n",
        "$nʹ��һ�С�˪���Ҷ����������е�$v����������$N�Ĺ����沨��ɢ��\n",
        "$n���е�$v�����䵶����һ�С�������Ӱ���������������ࡣ\n",
        }) );
        set("unarmed_parry_msg", ({
        "$n���μ��ˣ�����$v���·��裬һ�С������������󡹣���ס$N����ʽ��\n",
        "$nʹ��һ�С�˪���Ҷ����������е�$v����������$N�Ĺ����沨��ɢ��\n",
        "$n���е�$v�����䵶����һ�С�������Ӱ���������������ࡣ\n",
        }) );   
        action = ({
                ([      "action":               
                "$N����$w����������ˮ��һ�С�˥��б�������֡���бб����$n��$l",
                        "damage_type":  "����"
                ]),
                ([      "action":               
                "$N����$w���⼤����һ�С�����Ӱ�հ����̡���ն��$n��",
                        "damage_type":  "����"
                ]),
                ([      "action":               
                "$N����$w����ɭȻ��һ�С���Ƽ��Զ��������ֱ��$n$l",
                        "damage_type":  "����"
                ]),
                ([      "action":               
                "$N����$w���裬�������Ŵشأ�һ�С����ܻ���֪��ɫ����ƮƮ������$n��ȥ",
                        "damage_type":  "����"
                ]),
        });
}

mixed hit_ob(object me, object victim, int damage_bonus)
{
    object ob;
    int extra;
    if(ob=victim->query_temp("weapon")) return 0;
    message_vision(HIW"\n$N�������࣬����ָ��$n�Ʒ�����֮����$n����ʧ�룬�������С�\n" NOR,me,victim);
    extra = COMBAT_D->magic_modifier(me, victim, "kee", me->query_skill("sword")* random(10));    
    return extra;
}

int help(object me)
{
	write(@HELP   
�ý���ר�˸���ȭ�ţ�
�����˺�=random(��Ч����*10)

���������㡻��luoxiang��
����������æ������
���⹥����=��Ч����*2
�����˺���=��Ч����*4
HELP
    );
    return 1;
}

