#include <ansi.h>
inherit ITEM;
void create()
{
    set_name( HIR "�´����" NOR, ({ "hong bao" }) );
    set_weight(1);
    if( clonep() )
            set_default_object(__FILE__);
    else {
            set("unit", "��");
            set("material", "cloth");
            set("long", "һ��СС�ĺ�����������ţ���ϲ���ơ�\n");
        

          }
    ::init_item();
} 
void init()
{ 
        if(environment()==this_player())
                add_action("do_open","open");
} 
int do_open(string arg)
{
        object gold, me,ob;
        me = this_player();
        if(arg != "hong bao" && arg != "�´����") return 0;
        if(query("opened"))
                return notify_fail("���С������������ǿյģ�\n");
        gold = new("/obj/money/gold");
        gold->set_amount(666);
        gold->set("name","����Ҷ��");
        gold->set("base_unit","��");
        gold->move(this_player());
        ob=new("/d/wolfmount/npc/obj/zhuguo");
        ob->move(this_player());
        me->add("combat_exp",10000);
        me->add("potential",20000);
        me->add("score",2005);
        message_vision(HIR "\n$N���Ĵ򿪺�������۷��⣬һ����ϲ��\n\n" NOR,me);
        tell_object(me,HIC"\n��ϲ��ϲ���㱻�����ˣ�\n" + chinese_number(10000) + "��ʵս����\n" + chinese_number(20000) + "��Ǳ��\n" + chinese_number(2005)+"���ۺ�����\n"NOR);
        message_vision(WHT"һ����ɫ�ģ�ɢ����������ζ��"+ob->query("name")+WHT"�Ӻ�������$N���С�\n"NOR,me);
        set("opened",1);
        return 1;
}
