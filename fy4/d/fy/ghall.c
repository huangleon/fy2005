inherit DOOR_ROOM;
#include <room.h>

void create()
{
    set("short", "��ʨ�ھִ���");
    set("long", @LONG
���[33m��̺[32m���ɣ�������棬�����ֻ���������������˲��������ˬ���㽻��
�ѣ��ҷǴ��ֲ�ʶ��Ŀ������֮��������һʨƤ���Σ����Ҹ�������˸��һ��ɫ��
ľ�鰸������ǰ����������Ķ���һ����ھ�Ѻ�ڵĻ�Ʊ����һ�����š�
LONG
    );
    set("exits", ([ /* sizeof() == 4 */
	"west" : __DIR__"goldlion",
	"east" : __DIR__"ginhall",
	"north" : __DIR__"gmoney",
      ]));
    set("objects", ([
	__DIR__"npc/gmaster" : 1,
      ]) );

    set("item_desc", ([
	"�ֻ�":		"���ֻ��������������ɣ��󲿷�����ġ�ġ�\n",
	"ʨƤ����":	"�����ھ�����ͷ������������ӣ���ɨ�øɸɾ�����\n",
	"�������":	"���ǲ��Ͷ�ʮ������������ġ�\n",
	"�鰸":		"�鰸������ǰ����������Ķ���һ����ھ�Ѻ�ڵĻ�Ʊ��\n",
      ]));

    set("coor/x",180);
    set("coor/y",-60);
    set("coor/z",0);
    set("map","fyeast");
    setup();
    create_door("north", "door","����", "south", DOOR_CLOSED);

}

void init(){
    add_action("do_look","look");
}


int do_look(string arg){
    object me;

    me = this_player();


    if (arg == "��̺" || arg == "rag" || arg == "carpet" || arg == "����̺") {
	if (this_player()->query_temp("marks/js_cook_mice") < 3) {
	    tell_object(this_player(),"�����ĵ��������Ŵ���̺��������������պ��е�ů����ġ�\n");
	    return 1;
	}
	tell_object(this_player(),"�����ĵ��������Ŵ���̺��������������պ��е�ů����ġ�\n");
	tell_object(this_player(),"��ֵ��ǣ��ɸɾ�����̺���ϵ��˼����׷���\n");
	this_player()->set_temp("marks/js_cook_mice",4);
	return 1;
    }

    return 0;
}
