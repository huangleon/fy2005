#include <ansi.h>

inherit SKILL;
void setup(){
        set("name","��ɽ��ȭ");
        set("damage_level",200);
        set("type","unarmed");
        set("usage/unarmed",1);
        set("effective_level",300);
        set("difficulty",500);
        set("skill_class","npc");
        set("parry_msg", ({
                "$n��ȭ���£���ȭ�Ա���һ�С����ų�塹����$N���ڳ��⡣\n",
        }) );

        set("unarmed_parry_msg", ({
                "$n��ȭ���£���ȭ�Ա���һ�С����ų�塹����$N���ڳ��⡣\n",
        }) );
        action = ({
        ([      "action":               
"$N��ָ��ȭ��һ�С�̩ɽѹ������$n�����Ļ���",
                "damage_type":  "����"
        ]),
        ([      "action":               
"$N������Σ���ȭ���й�ֱ����Ѹ���ޱȵ���$n����",
                "damage_type":  "����"
        ]),
        ([      "action":               
"$N����һ������ȭ��������ȭʹ�����Ϻ��Ƴ�������һ�󾢷����$n",
                "damage_type":  "����"
        ]),
        ([      "action":               
"$N��ȭ�»��⿪$n����һʽ���׺����᡹��$n��ȥ",
                "damage_type":  "����"
        ]),
        });
}

int valid_learn(object me)
{
        if( me->query("class") || me->query("once_menpai"))
        {
                return notify_fail("��������ţ�����ƽ�������ȭ������ܿ������ۣ�\n");
        }
        return ::valid_learn(me);
}




/* Dancing_Faery @ Hotmail.com */
