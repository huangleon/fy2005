// annie 07.2003
// dancing_faery@hotmail.com

#include <ansi.h>
inherit ROOM;
string look_stone();

void create()
{
	set("short", "�Ųt��̨��");
    set("long", @LONG
�t��̨��һ���Ѿ����������²���һƬƬ���ѵ�ʯ�ߣ��·�������������
����������������ɽ���ƺ���Զ���ᵹ�µĸ��ڣ�Ҳ�Ѱ뻯��������Ȼ�Ŀ���
���t��̨�������һ����ǿ���ɳ�δ�����м�ҡҡ��׹�İ�����ݰڷ��ڽ���
�У������ǵ������������Ĺ��
LONG
NOR
        );
	set("objects", ([
	__DIR__"obj/pot":2,
	]));
	set("item_desc", ([

	"ʯ��":"�����ʯ���������ƬƬ���ѣ�ɢ�����أ����òt��̨�ڵĵ���ߵͲ�ƽ��\n",
	"tile":"�����ʯ���������ƬƬ���ѣ�ɢ�����أ����òt��̨�ڵĵ���ߵͲ�ƽ��\n",
	"����":(: look_stone :),
	"ladder":(: look_stone :),

	]) );
	set("exits",([
  		"eastdown" : __DIR__"path6",
//  		"up" : __DIR__"peak4",		// Climb up,remove this later.
	]) );

	set("coor/x",-60);
	set("coor/y",30);
	set("coor/z",90);
	setup();
}


string look_stone()
{
	object me = this_player();
	if (!query("ladder"))
	{
		tell_object(me,"���ݶϳ��������ڵ��ϡ�\n");
		return " ";
	}
	if (me->query_temp("annie/cyan_ladder"))
		tell_object(me,"���಻���ķ����·��������������ã�������ȥɫ����չޡ�\n");
	else
		tell_object(me,"һ��ҡҡ��׹�����಻���ķ��ݣ����е㻳�������ܲ��ܾ���ס���������\n");
	me->set_temp("annie/cyan_ladder",1);
	return " ";
}


void init()
{
	add_action("do_climb","climb");
	add_action("do_search", ({"search"}));
}

int do_climb(string arg)
{
	object me,room;
	me=this_player();
	if (!arg || (arg!="ladder" && arg!="����") || !me->query_temp("annie/cyan_ladder"))

		return notify_fail("������ʲô��\n");;
	if (!query("ladder"))
		return notify_fail("����û��"+arg+"��\n");;
	
	if (me->query_encumbrance() > 10000 )
	{
		if (!me->query_temp("annie/cyan_ladder"))
		{
			me->set_temp("annie/cyan_ladder",1);
			return notify_fail("����ݿɲ�̫��ʵ�������÷���Щ��������������\n");
		}
		else
		{
			set("ladder",0);
			tell_object(me,CYN"\nֻ���ÿ���һ����������������Գ������������һ��������������\n��������������һ��ˤ�ڵ��ϣ���ͷײ��ǽ�ǣ�������һ��С��������\n\n���Ǽ����Ժ������ɡ�\n"NOR);

    set("long", @LONG
�t��̨��һ���Ѿ����������²���һƬƬ���ѵ�ʯ�ߣ��·�������������
����������������ɽ���ƺ���Զ���ᵹ�µĸ��ڣ�Ҳ�Ѱ뻯��������Ȼ�Ŀ���
���t��̨�������һ����ǿ���ɳ�δ���������жѻ���һ�����õ�ľͷ������
����Ƭ��
LONG
NOR
        );
		room=this_object();
		me=present("�չ�",room);
		if (me)
			destruct(me);
		me=present("�չ�",room);
		if (me)
			destruct(me);

			return 1;
		}
	}


	room=find_object(__DIR__"peak4");
	if (!objectp(room)) room=load_object(__DIR__"peak4");
	tell_object(me,"�����ŷ�����t��̨����ȥ��\n");
	tell_room(room, this_player()->name() + "�Ӳt��̨������������\n");
	this_player()->move(room);
	return 1;
}


int do_search(string arg)
{
	object me = this_player(),he;
	if (me->is_busy() || me->is_fighting())
	{
		write("��������æ��\n");
		return 1;
	}
	if (!query("ladder"))
	{
		write("���ݵĲ�ʬ�������˵����ڵ��ϡ�\n");
		return 1;
	}

	message_vision("$N�ڲ�ש�������Ĵ�������\n",me);
	if (query("get2") || random(3))
		tell_object(me,"Ȼ����ʲô��û���ҵ���\n");
	else
	{
		set("get2",1);
		message_vision("$N�ƺ�������ʲô���������ش������\n",me);
		he = new(__DIR__"obj/tile");
		he->move(me);
	}

	me->perform_busy(4);
	return 1;
}

void reset()
{
	object river,stone,*inv;
	
	::reset();
	set("ladder",1);
	    set("long", @LONG
�t��̨��һ���Ѿ����������²���һƬƬ���ѵ�ʯ�ߣ��·�������������
����������������ɽ���ƺ���Զ���ᵹ�µĸ��ڣ�Ҳ�Ѱ뻯��������Ȼ�Ŀ���
���t��̨�������һ����ǿ���ɳ�δ�����м�ҡҡ��׹�İ�����ݰڷ��ڽ���
�У������ǵ������������Ĺ��
LONG
NOR
        );


	river = present("�չ� 2", this_object());
	if (!river)
		return;
	inv = all_inventory(river);
	if (sizeof(inv) < 1 && !query("get"))
	{
		stone = new(__DIR__"obj/amulet7");
		if(stone)
			stone->move(river);
		set("get",1);
	}

	delete("get2");
	return;
}


/*

���������������X�Y
���������������U�t�r
���������������U���t�r
���������������U�����t�r
���������������U��������
���������������^�k�k�k�_

��������������- FengYun - ������
������������annie 08.2003
������dancing_faery@hotmail.com
*/


