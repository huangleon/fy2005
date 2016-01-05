#include <ansi.h>
#include <room.h>
inherit DOOR_ROOM;
void create()
{
        set("short", "�߷�");
        set("long", @LONG
�߷��⾫���Ѽ������в��õø��Ǿ�Ȼ������ǽ�Ϲ���һ��÷����ѩͼ����ֻ
���������ʣ�ȴ��÷���������ǣ���¶���ţ����Ͻ�ӡ��һö�ʺ��ͼ�£�����
�������--÷����ֵ���ŵ��ļ������ӣ����տ���û��������������һ�Ȱ���ɫ
�Ĵ��š�
LONG
        );
    set("exits", ([ /* sizeof() == 4 */
		"south" : __DIR__"meilin",
		"west" : __DIR__"studyroom",
	]));
        set("objects", ([
        __DIR__"npc/hou" : 1,
                        ]) );

    set("indoors", "fengyun");
	set("coor/x",-320);
	set("coor/y",100);
	set("coor/z",0);
    setup();
	create_door("south", "door","����ɫ�Ĵ���", "north", DOOR_CLOSED);
}

/*
void init(){
	if(!doors["south"]["status"]) {
		this_player()->ccommand("close door");
	}
}*/

int answer_door(){
	object hou;
	
	if(hou = present("hou", this_object())){
		hou->ccommand("open door");
	}
	 else {
		hou = new(__DIR__"npc/hou");
		hou->move(this_object());
		hou->ccommand("open door");
	}
	return 1;
}

int valid_leave(object player, string dir)
{
	object hou;
	if (dir == "west" && !player->query("marks/÷ɽ��") && hou = present("hou",this_object()))
	{
		message_vision("$N��������λ"+RANK_D->query_respect(player)+"��������˽�˵ĵط������������� \n",hou);
		return notify_fail("���꺺�ӵ�ס��ȥ��������·\n");
	}
	if (dir == "west" && player->query("marks/÷ɽ��") && hou = present("hou",this_object()))
	if(!player->query("m_killer/����") || !player->query("m_killer/��������")
		|| !player->query("m_killer/��������") || !player->query("marks/л����"))
	{
		message_vision("$N��������λ"+RANK_D->query_respect(player)+"��÷��类������Ű��㣬�������Ҿ�����ǿ�л��ţ��˻���������������������ڡ��� \n",hou);
		return notify_fail("���꺺�ӵ�ס��ȥ��������·\n");
	}
	return ::valid_leave(player,dir);
}
