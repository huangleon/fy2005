#include <ansi.h>
inherit ITEM;
void create()
{
        object book;
        set_name("����", ({ "xisuihe"}) );
        set_weight(300);
        set_max_encumbrance(80000);
	set("unit", "��");
	set("long", "һ�����Ϻú�ľ����ľ�У�����������д��[ϴ��]���ӡ�\n");
	set("closed", 1);
	set("value", 0);
	set("xisui", 1);
}

int is_container() {return 1;}

void init()
{
	if(this_player()==environment())
		 add_action("do_open","open");
}

int do_open(string arg)
{
	object	book, me, ob;
     if( !arg || arg != query("id") )
                return notify_fail("��Ҫ��ʲô��\n");
	me = this_player();
	ob = this_object();
	if (me->query("force_factor")<60)
		return notify_fail("��Ѿ���ţ����֮�����и���˿������\n");
	message_vision("$N����֨��һ������$n�򿪡�����\n", me, ob);
	if (ob->query("xisui")) {
		message_vision(HIR"ϴ�辭������$N���۾�һ���Ӻ���.\n"NOR,me);
		message_vision("$Nһ����,С������ؽ�ϴ�辭ȡ�����ڻ���.\n"NOR,me);
		seteuid(getuid());
		book=new(BOOKS"skill/xisui_100");
		book->move(me);	
		ob->set("xisui",0);    
	} else
		message_vision("������տյ�ʲôҲû��,��,��æ����.\n",me);
	ob->set("closed",0);
	me->perform_busy(1);
        return 1;
}

int is_closed()
{
	return ((int) this_object()->query("closed"));
}
