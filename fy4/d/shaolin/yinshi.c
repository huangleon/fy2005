// TIE@FY3 ALL RIGHTS RESERVED
inherit ROOM;
void create()
{
        set("short", "����¥");
        set("long", @LONG
û�뵽��������������֮������������֮���Ȼ������㾰ɫ���������ɰ�
��ӳ�£���Ȼ�������һ�Ƿ��ܣ���ȥ��Ȼ��һ��¥��¥�������������ݴ�������
�µ�һ���ִ������ֺ�Ϊ����ǧ��������Ȼ�����Ը����������֣��Ӵ˲���������
�ѵ���¥����Ϊ��������
LONG
        );
        set("exits", ([ 
  "east" : __DIR__"zhulin",
]));
        set("objects", ([
                __DIR__"npc/master_xie" : 1,
       ]) );
	set("coor/x",-40);
	set("coor/y",120);
	set("coor/z",20);
	setup();
    //replace_program(ROOM);
}
int invalid_leave(object me)
{
	me->delete_temp("xieask");
	return 0;
}


