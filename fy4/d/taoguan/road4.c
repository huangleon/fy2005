#include <ansi.h>
inherit ROOM;

void create()
{
	set("short", "ɽ��");
	set("long", @LONG
ʯӢ���̳ɵ�ɽ·Խ��Խ����Խ��Խխ��ɽ��ҲԽ��Խ�ߣ�ǰ���ãã��һƬ��
��֪����ɽ������������Ǹߴ��ĸ��ơ�������ï�ܵ����֣�����������Լ��Щ
��ֵ����죬�����ס��ͣ��������
LONG
	);
	set("exits", ([ /* sizeof() == 2 */
  		"northup" : __DIR__"road5",
  		"southdown" : __DIR__"road3",
	]));
	set("outdoors", "taoguan");
	set("coor/x",0);
	set("coor/y",-80);
	set("coor/z",-30);
	setup();

}

void init(){
        add_action("do_listen","listen");
}



int do_listen(){
        tell_object(this_player(),"
��е����ӷ������ڰ���������˫�۾������㣡
����ϸ�ؿ���һ�����ܣ�ȴʲôҲû�У�\n");
        this_player()->set_temp("sq_listen",1);
        return 1;
}
