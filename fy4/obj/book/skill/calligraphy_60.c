// sinny@fengyun
#include <ansi.h>
inherit ITEM;
void create()
{
        string *names = ({
             HIC"����ͤ��"NOR, MAG"�����񸳡�"NOR, HIB"��ɥ������"NOR,
                             HIW"����ѩʱ������"NOR, HIY"����ͥ����"NOR
        });

        set_name( names[random(sizeof(names))], ({ "calligraphy book","book" }));
        set_weight(600);
        set("unit", "��");
        set("long", "��������ѧʿ��������Ĵ�������ĸ�����\n");
        set("value", 1);
        set("skill", ([
                "name":        "calligraphy",             // name of the skill
                "exp_required": 20000,
                "sen_cost":     25,
                "difficulty":   30,
                "max_skill":    60                              
        ]) );
}
