#include <ansi.h>
inherit ITEM;
void create()
{
        set_name("ţƤ�޹�", ({ "gu"}) );
        set_weight(300);
        set_max_encumbrance(80000);
	set("unit", "��");
	set("long", "�����»���¥�еľ޹ģ��ഫ��ӡ����ţƤ���ơ�\n");
	set("closed", 1);
	set("value", 2000);
}

int is_container() {return 1;}


void init()
{
	if(this_player()==environment())
		 add_action("do_open","cut");
}


int do_open(string arg)
{
	object	skin,me, ob;
	seteuid(getuid());
	
        me = this_player();
	ob = this_object();
        
        if( !arg || arg != "gu" ) {
                tell_object(me,"��Ҫ�ʲô��\n");
                return 1;
        }
	
	if (!ob->query("closed")) {
		tell_object(me,"�����Ѿ����˰����ˡ�\n");
		return 1;
	}
		
	message_vision("$N��������һ������$n���м仮����������\n",me,ob);
	if (ob->query("closed")) {
		skin = new (__DIR__"skin");
		skin->move(ob);
	}
	
	ob->set("closed",0);
        ob->set("value",1);
        set("long", "�����»���¥�еľ޹ģ��ഫ��ӡ����ţƤ���ơ�
��ϧ���ǹ����Ѿ����˰����ˡ�����\n");
        return 1;
}


int is_closed()
{
	return ((int) this_object()->query("closed"));
}

