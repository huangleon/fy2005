#include <ansi.h>
inherit ITEM;
void create()
{
    set_name(YEL"�����ռ�"NOR, ({ "afrji" }) );
    set_weight(1);
    if( clonep() )
        set_default_object(__FILE__);
    else {
        set("unit", "��");
        set("material", "paper");
        set("long", "һ��������ǰ���ռǣ�����Զ�һ��������䣩��\n");
    }

    ::init_item();
}
void init()
{
    if(environment(this_object())==this_player())
	add_action("do_read","read");
    add_action("do_go","go");
}

int do_read(string arg)
{
    object me;
    mapping exits;
    string *dirs;
    string thisdir;
    if(arg != "afrji" && arg != "�����ռ�") return 0;
    me=this_player();
    if(find_call_out("markit")== -1)
        call_out("markit",random(60)+20,me);
    if( !mapp(exits = environment(me)->query("exits")) ) 
    {
        tell_object(me,"��һ�����ؾ��ڸ�����\n");
        return 1;
    }
    dirs = keys(exits);
    thisdir = dirs[random(sizeof(dirs))];
    set("thisdir",thisdir);
    tell_object(me,"��һ�����ؾ���"+thisdir+"�ķ���\n");
    return 1;
}

int do_go(string arg)
{
    if(arg==query("thisdir"))
	this_player()->add_temp("going",1);
    return 0;
}
int markit(object me)
{
    object gold;
    if(me->query_temp("going") <= 20 || environment()!=me) return 1;
    if(!query("already"))
    {
        gold = new("/obj/money/gold");
        tell_object(me,
                    "\n\n��һ�������ӡ������ռǡ���ָʾ�ĵط��ڳ�Щ���ӣ�\n");
        gold->set_amount(10);
        gold->move(me);
        me->delete_temp("going");
        set("already",1);
    }
    return 1;
}

