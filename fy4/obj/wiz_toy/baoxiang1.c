#include <ansi.h>
inherit ITEM;
void create()
{
    set_name( HIR "������" NOR, ({ "baoxiang" }) );
    set_weight(1);
    if( clonep() )
            set_default_object(__FILE__);
    else {
            set("unit", "��");
            set("material", "cloth");
            set("long", "һ����ɫ�ı��䣬������ż����֣��������������\n");
        

          }
    ::init_item();
} 
void init()
{ 
        if(environment()==this_player())
                add_action("do_open","open");
} 
int do_open(string arg,int expnum)
{
        object gold, me,ob;
		me = this_player();
        if(arg != "baoxiang" && arg != "������") return 0;
        if(query("opened"))
                return notify_fail("��������䣬�������ǿյģ�\n");
 //       gold = new("/obj/money/gold");
 //       gold->set_amount(666);
 //       gold->set("name","����Ҷ��");
 //       gold->set("base_unit","��");
 //       gold->move(this_player());
 //       ob=new("/d/wolfmount/npc/obj/zhuguo");
 //       ob->move(this_player());
        expnum=random(3000);
        me->add("combat_exp",expnum);
        me->add("potential",expnum/5);
        me->add("score",1);
		message_vision(HIR "\n$N���Ĵ������䣬���۷��⣬һ����ϲ��\n" NOR,me);
		tell_object(me,WHT"\n��ϲ��ϲ���㱻�����ˣ�\n" + chinese_number(expnum) + "��ʵս����\n" + chinese_number(expnum/5) + "��Ǳ��\n" + chinese_number(1)+"���ۺ�����\n"NOR);
        set("opened",1);
        message_vision("�򿪵ı��仯��һ��������ʧ�ˡ�\n"NOR,me);
	    CHANNEL_D->do_sys_channel(
		"info",sprintf("%s�������䣬�õ���" + expnum + "��ʵս���飬" + expnum/5 + "��Ǳ�ܡ�\n"NOR,me->name(1)));
		destruct(this_object());
        return 1;
}