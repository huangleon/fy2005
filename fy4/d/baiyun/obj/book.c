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
        set("value", 150);
        set("skill", ([
                "name":                 "calligraphy",             // name of the skill
                "exp_required": 20000,                              // minimum combat experience required
                                                                                // to learn this skill.
                "sen_cost":             25,                             // gin cost every time study this
                "difficulty":   30,                             // the base int to learn this skill
                                                                                // modify is gin_cost's (difficulty - int)*5%
                "max_skill":    60                              // the maximum level you can learn
                                                                                // from this object.
        ]) );
}
