#include <ansi.h>
inherit ITEM;
void create()
{
    set_name( HIG"����֮��"NOR, ({ "ward" }) );
    set("unit", "��");
    set("value",0);
    set("no_get",1);
        set("no_clean_up",1);
    set_weight(150000);
    ::init_item();
}

int heal_ob(object enemy,int count)
{
        object * friends;
        int i;
        if (!enemy)
        {
                message_vision(HIG"\nǳ�̵Ĺ⻪������ɢ�ˡ�\n"NOR,this_object());
                destruct(this_object());
                return 1;
        }
        friends = enemy->query_enemy();
        if (environment() != environment(enemy))
        {
                message_vision(HIG"\nǳ�̵Ĺ⻪������ɢ�ˡ�\n"NOR,this_object());
                destruct(this_object());
                return 1;
        }
        if (!enemy->is_fighting())
        {
                message_vision(HIG"\nǳ�̵Ĺ⻪������ɢ�ˡ�\n"NOR,this_object());
                destruct(this_object());
                return 1;
        }
        message_vision(CYN"\nǳ�̵Ĺ⻪������һЩ����Χ�������ϵ��˿ڽ������ϡ�\n\n"NOR,enemy);
        for (i=0;i<sizeof(friends) ; i++)
        {
                friends[i]->receive_curing("kee",500);
                friends[i]->receive_curing("gin",500);
                friends[i]->receive_curing("sen",500);
                friends[i]->receive_heal("kee",500);
                friends[i]->receive_heal("gin",500);
                friends[i]->receive_heal("sen",500);
//              message_vision("test:$N",friends[i]);
        }
        count --;
        if (count < 1)
        {
                message_vision(HIG"\nǳ�̵Ĺ⻪������ɢ�ˡ�\n"NOR,enemy);
                destruct(this_object());
                return 1;
        }
        call_out("heal_ob",6,enemy,count);
}

