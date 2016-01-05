#include <ansi.h>
inherit ITEM;

string look_outside(object ob, object env);

void create()
{
    set_name("��", ({ "carriage", "mache"}) );
    set_weight(300000);
    set("no_get", 1);
    set("no_reset",1);
    set_max_encumbrance(80000000);
    set("unit", "��");
    set("short"," ��(Carriage)");
	set("long", "һ��Ư����������������ʡ���������޵��ӡ��������žͲ���������\n ");
    set("closed", 1);
    set("value", 2000);
    ::init_item();
}

int is_container() {return 1;}

void init()
{
    add_action("do_open","open");
    add_action("do_close","close");
	add_action("do_jump","jump");
	add_action("do_out","out");
	//add_action("do_enter","enter");
	//add_action("do_move","move");
}
int is_closed()
{
    return ((int) this_object()->query("closed"));
}

int do_close(string arg)
{
    object	me;
    me = this_player();
    if(arg != "mache" && arg != "carriage")
        return notify_fail("��Ҫ����ʲô��\n");
	if (is_closed())
	{
		return notify_fail("�����Ѿ������� \n");
	}
    message_vision("$N�ѳ��Ź����ˡ�\n", me);
    this_object()->set("closed",1);
    return 1;
}

/*
int do_enter(string arg)
{
	
	object me;
	if (arg !="carriage" || arg !="mache")
	{
		return notify_fail("��Ҫ����ʲô��\n");
	}
	me = this_player()
	message_vision("$N�����ţ���������",me);
}
*/

int do_open(string arg)
{
    object me, ob;
    me = this_player();
	if(arg != "mache" && arg != "carriage")
	    return notify_fail("��Ҫ��ʲô��\n");
	if (!is_closed())
	{
		return notify_fail("�����ǿ��ŵ� \n");
	}
    message_vision("$N�����Ŵ� \n", me);
	this_object()->set("closed",0);
	me->move(environment(this_object()));
    return 1;
}

int do_out(string arg)
{
	object me,ob;
	me = this_player();
	if (environment(me) != this_object())
		return 0;
	if(arg != "mache" && arg != "carriage")
	    return notify_fail("��Ҫ�߳�ʲô��\n");
	if (objectp(ob=present("chefu",environment())))
        return notify_fail(ob->name()+"˵���������ˣ���Ҫ�Ҷ���\n");
	if (is_closed())
	{
		message_vision("$N�����Ŵ� \n", me);
	}
	me->move(environment(this_object()));
	message_vision("$N�������������� \n", me);
	if (!is_closed())
	{
		message_vision("�����Զ������� \n", me);
		this_object()->set("closed",1);
	}
	return 1;
}

int do_jump(string arg)
{
	object me, ob;
	
	me = this_player();
	if (environment(me) != this_object())
		return 0;
	if(arg != "mache" && arg != "carriage")
        return notify_fail("��Ҫ����ʲô��\n");
    if(is_closed())
	{
		message_vision("$N�����Ŵ��ĺ������¿��˿� \n", me);
	}
    message_vision("$Nҧ��ҧ��������ȥ��\n", me);
	me->move(environment(this_object()));
	message_vision("$N�����Ϲ�������������һ���Ľų��� \n",me);
	me->unconcious();
	if (!is_closed())
	{
		message_vision("�����Զ������� \n", this_object());
		this_object()->set("closed", 1);
	}
    return 1;
}


int move(mixed dest, int silently)
{
	object *inv;
	int i;
	::move(dest, silently);
	inv=all_inventory(this_object());
    for(i=0;i<sizeof(inv);i++)
        if (userp(inv[i]))
		{	
			tell_object(inv[i],"͸���ʹ��ĳ������㿴�� \n");
			message_vision("���� \n",inv[i]);
			//copy whole base class function here isnot good. need think of a smart way:(.
			//call_other("/cmds/std/look"->look_room(inv[i],dest));
			message_vision((look_outside(inv[i],dest)),inv[i]);
			return 1;
		}
	return 1;
}


string look_outside(object me, object env) {
	int i;
	object *inv;
	mapping exits;
	string roomdesc, str, *dirs;

	if(!env) {
		return "������ܻ����ɵ�һƬ��ʲ��Ҳû�С�\n";
	}

	// room descriptions.
	str = sprintf( "%s \n    %s",
			env->query("short"),
			//wizardp(target)? file_name(env)+sprintf(" - (%d,%d,%d)",env->query("coor/x"),
			//		env->query("coor/y"),env->query("coor/z")): "",
			//env->long(),
			env->query("outdoors")? NATURE_D->outdoor_room_description() : "" );

	// exits.
	if(mapp(exits = env->query("exits"))) {
		dirs = keys(exits);
		for(i=0; i<sizeof(dirs); i++) {
			if((int)env->query_door(dirs[i], "status") & 1 ) {
				dirs[i] = 0;
			}
		}
		dirs -= ({ 0 });
		if(sizeof(dirs)==0) {
			str += "    ����û���κ����Եĳ�·��\n";
		} else if(sizeof(dirs)==1) {
			str += "    ����Ψһ�ĳ����� " + BOLD + dirs[0] +NOR + "��\n";
		} else {
			str += sprintf("    �������Եĳ����� " + BOLD + "%s" +NOR + 
					" �� " + BOLD + "%s" +NOR + "��\n",
					implode(dirs[0..sizeof(dirs)-2], "��"), dirs[sizeof(dirs)-1]);
		}
	} else {
		str += "    ����û���κ����Եĳ�·��\n";
	}
	
	// all things in the room.
	inv = all_inventory(env);
	for(i=0; i<sizeof(inv); i++) {
		if(inv[i]==me || inv[i]->query("no_shown") || !me->visible(inv[i])) {
			continue;
		}
		str += "  " + inv[i]->short() + "\n";
	}
	return str;
}
