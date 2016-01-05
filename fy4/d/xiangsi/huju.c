// annie 07.2003
// dancingfaery@hotmail.com

#include <ansi.h>
inherit ROOM;
string tree();

void create()
{
    set("short", "����ʯ");
    set("long", @LONG
�ߵ���������ɽ�ڽ�����£����·������᫡������д���Щ�볱����
ɽ����������ϲʪ������ʯ̦��̧ͷ������ֻ��ʮ���ɸߴ�һ��ʯ���ɿ���ɽ
���ң�����һ�������ͻ��Ĵ�ʯ�̾ᣬ������ʯ���������ˡ�(������ ����) 
LONG
    );
    set("objects", ([
	__DIR__"obj/rock2" : 1,
	__DIR__"obj/stone" : 1,
      ]));
    set("exits",([
	"north" : __DIR__"qingxi",
	"south" : __DIR__"shuangtian",
      ]) );



    set("item_desc", ([
		"cliff" : (: tree :),
		"ɽ��" : (: tree :),
		"����ʯ̦":	(: tree :),
		"ʯ̦":		(: tree :),
		"����":		(: tree :),	
		"lichen":	(: tree :),
      ]) );   


    set("outdoors", "xiangsi");

    set("coor/x",0);
    set("coor/y",0);
    set("coor/z",-10);
    setup();
}


void init()
{
    add_action("do_jump", ({"jump","dash"}));
    add_action("do_pick", ({"cut","pick"}));
    add_action("do_search", ({"search"}));
}


int do_jump(string arg)
{

    object me, room;
    int m;

    me = this_player();
    m = me->query_skill("move",1);

    if(!arg || (arg != "up" && arg != "��" && arg!= "bridge" && arg!="ʯ��" && arg!="ridge")) {
	write("��û��������������\n");
	return 1;
    }

    if (m >= 70)
    {  
	if (me->query("force") >= me->query("max_force")){
	    message_vision(CYN"$N��һ������������ʯ����Ծȥ��\n"NOR,me);
	    room = load_object(__DIR__"liangjie");
	    me->move(room);
	    message("vision", me->name()+"�ӻ���ʯ������������\n", environment(me), me);
	    return 1;
	}else {
	    tell_object(me, "��������������»�������ȥ��\n");
	    return 1;
	}
    }else {
	tell_object(me, "������������»�������ȥ����Ҫ��������\n");
	return 1;
    }
    return 1;
}


string tree()
{
    object me;
    int i;
    me = this_player();
    if (query("opened"))
    {
		tell_object(me, "ɽ����������ϲʪ������ʯ̦��\n");
		return "";
    }
    tell_object(me, "ɽ����������ϲʪ������ʯ̦����ע�⵽��һ��ط���ʯ̦������ء�\n");
    me->set_temp("annie/xiangsi_huju",1);
    return "";
}

void reset(){
    ::reset();
    set("opened", 0);
}




int do_pick(string arg)
{

    object me, tea;

    me = this_player();

    if (query("opened") || !me->query_temp("annie/xiangsi_huju"))
    {
		write("�����ץ��ץ��ץ��һ����͡�\n");
		return 1;
    }

    if(!arg || (arg != "��̦" && arg != "lichen" && arg!= "ʯ̦"))
    {
		write("��Ҫ��ʲô��\n");
		return 1;
    }

    set("opened",1);

    tea = new(__DIR__"obj/lichen");
    tea->move(me);
    message_vision(CYN"$NС���������ɽ��������һЩ��̦��\n"NOR,me);
    tell_object(me, "��ȥ�˸���������̦���������һ��ԼĪ���ƴ�С�Ŀռ�����̦�¡�\n");
    me->set_temp("annie/xiangsi_huju",2);
    return 1;
}


int do_search(string arg)
{
    object me = this_player();
    if (me->query_temp("annie/xiangsi_huju") != 2)
    {
		write("����������ң�ʲôҲû�ҵ���\n");
		return 1;
    }

    if (me->is_busy())
    {
		write("��������æ��\n");
		return 1;
    }

    tell_object(me,"������С���������̦�µĿն���������\n");
    tell_object(me,"��ʲôҲû��������\n");

    me->perform_busy(1);
    return 1;
}
