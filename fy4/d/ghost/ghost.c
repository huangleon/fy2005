
inherit ROOM;

void create()
{
	set("short", "����ɽׯ");
	set("long", @LONG
������һ�����˵����硣����������һƬ���ɣ�ʲô����������������ۺ�ɢ��
����������Ѳ��ô�����治Զ����һ��Ұ�ɫ��Сľ�ݣ����������İ����һ
��Ҫ��ע��ſ��õ���
LONG
	);
	set("exits", ([
                "north" : __DIR__"house",
                "west" : __DIR__"bridge",
                "east" : __DIR__"groad1",
	]));
	set("coor/x",-70);
	set("coor/y",-10);
	set("coor/z",0);
	setup();
}

int valid_leave(object me, string dir){
	me->set_temp("marks/know_ghost", 1);
	return 1;
}