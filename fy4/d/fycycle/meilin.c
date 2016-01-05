#include <ansi.h>
inherit DOOR_ROOM;
#include <room.h>
mapping door;

void create()
{
        set("short", "÷��");
        set("long", @LONG
��ǰ��һƬ����ʮ��Ũ�ܵ����֣���ϸ��ȴ��һƬ÷�֣��м���һ���������
������������÷������ܾ��µ�����������䣬������һ�Ȱ���ɫ�Ĵ��š�÷��
����һƬ���̵����֡�ÿ������÷�ֿ��ðٻ����ޣ�����ŭ�ţ������ӳ��ѩ��
�ϣ�ε����Ȥ��
LONG
        );
    set("exits", ([ /* sizeof() == 4 */
		"southwest" : __DIR__"bomboo1",
		"north" : __DIR__"meihouse",
	]));

    set("outdoors", "fengyun");
	set("coor/x",-320);
	set("coor/y",100);
	set("coor/z",0);
    setup();
	create_door("north", "door","����ɫ�Ĵ���", "south", DOOR_CLOSED);
}

void init(){
	add_action("do_knock", "knock");
	if(!doors["north"]["status"]) {
		this_player()->ccommand("close door");
	}
}

int do_knock(string arg){
	object room, hou;

	if(!arg || (arg != "door" && arg != "����ɫ�Ĵ���")) {
		return 0;
	}
	if (!doors["north"]["status"]){
		return notify_fail("���ǿ��ŵġ�\n");
	}
	if(arg == "door" || arg == "����ɫ�Ĵ���") {
		message_vision("$N�ߵ���ǰ����������˼����š�\n", this_player());
		room = find_object(__DIR__"meihouse");
		if(!objectp(room)){
			room = load_object(__DIR__"meihouse");
		}
		if(this_player()->query("marks/÷ɽ��")){
			room->answer_door();
		} else {
			message_vision("���ھ����ĵ�û��������\n", this_player());
		}
	}
	return 1;
}
