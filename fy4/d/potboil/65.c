#include <ansi.h>
inherit ROOM;

void create()
{
	set("short", MAG"��Ԩ��"NOR);
	set("long", @LONG
��Ԩ��ԭ������������ֻ����ǰħ�����ң���ɽ������ˮԴ�Ͼ�����˾��
�¶������֮��������˴�Ϊ����ˮ�����۶��������а����˿ڶɹ�һ�٣���
��������Ϊ��Ԩ֮����
LONG
        );
	set("exits",([
		"north" : __DIR__"66",
		"south" : __DIR__"64",
		"westup" : __DIR__"55",
	]) );

	set("objects", ([	
	__DIR__"npc/san3" : 1,
					]) );

  	set("coor/x",60);
	set("coor/y",50);
	set("coor/z",0);
	set("outdoors", "potboil");
	setup();
}


void init()
{
	add_action("do_fill", "fill");
}


int do_fill(string arg)
{
    string name, type, container;
	object me,skin,dew;
    int drunk_apply;
	me = this_player();
	if (!arg)
		return 0;
	skin = present(arg,me);
	if (!skin)	return 0;
    if( me->is_busy() )
	{
		write("����һ��������û����ɡ�\n");
		return 1;
	}

	if (!skin->query("liquid/name"))
	{
		write("��û��װˮ�Ķ�������\n");
		return 1;
	}

    if( skin->query("liquid/remaining") )
        message_vision("$N��" + skin->name() + "��ʣ�µ�" + 
                       skin->query("liquid/name") + "������\n", this_player());

    type="water";
    name="ɽ����ˮ";
    container="��Ԩˮ��";
    drunk_apply = 6;

    message_vision("$N��"+container+"�н�" + skin->name() + "װ��"+name+"��\n",me);

    if( me->is_fighting() ) me->start_busy(2);
    skin->set("liquid/type", type);
    skin->set("liquid/name", name);
    skin->set("liquid/remaining", skin->query("max_liquid"));
    if(drunk_apply) skin->set("liquid/drunk_apply",drunk_apply);
    
    return 1;
}


/*
�X[ ��- FengYun -�� ]���������[
��[dancing_faery@hotmail.com]�������[
��[ ��annie 09.2003�� ]�������a    ��
��[ ������������¶������ʱ������˪ ��
�^��������������������������������-�a
*/
